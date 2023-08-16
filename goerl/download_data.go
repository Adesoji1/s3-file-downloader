package main

import (
	"fmt"
	"os"
	"sync"
	"sync/atomic"

	"github.com/aws/aws-sdk-go/aws"
	"github.com/aws/aws-sdk-go/aws/session"
	"github.com/aws/aws-sdk-go/service/s3"
	"github.com/aws/aws-sdk-go/service/s3/s3manager"
)

func DownloadFromS3(aws_credentials *aws.Config, s3_getObject *s3.GetObjectInput, bucket_name string, filenames ...string) error {

	session, err := createSession(aws_credentials)
	if err != nil {
		return fmt.Errorf("could not create AWS sessison: %v", err)
	}

	var wg sync.WaitGroup
	totalFiles := len(filenames)
	wg.Add(totalFiles)
	downloader := s3manager.NewDownloader(session)

	var failedcount uint64
	for _, file := range filenames {
		go download(&wg, file, s3_getObject, downloader, &failedcount)
	}
	wg.Wait()

	fmt.Println("----------------------------------------------------------------")
	fmt.Printf("Total downloads: %d, Sucessful downloads: %d, failed downloads: %d", totalFiles, totalFiles-int(failedcount), int(failedcount))
	fmt.Println("----------------------------------------------------------------")

	return nil
}

func createSession(aws_credentials *aws.Config) (*session.Session, error) {
	return session.NewSession(aws_credentials)
}

func download(wg *sync.WaitGroup, filename string, s3_getObject *s3.GetObjectInput, downloader *s3manager.Downloader, failedCount *uint64) {

	defer wg.Done()
	f, err := os.Create(filename)
	if err != nil {
		fmt.Fprintf(os.Stderr, "skipped %s, could not create file: %v\n", filename, err)
		atomic.AddUint64(failedCount, 1)
		return
	}
	defer f.Close()
	_, err = downloader.Download(f, s3_getObject)
	if err != nil {
		fmt.Fprintf(os.Stderr, "skipped %s, could not download file: %v\n", filename, err)
		atomic.AddUint64(failedCount, 1)
		return
	}

}
