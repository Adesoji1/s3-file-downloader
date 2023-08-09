package main

import (
	"fmt"
	"os"

	"github.com/aws/aws-sdk-go/aws"
	"github.com/aws/aws-sdk-go/aws/session"
	"github.com/aws/aws-sdk-go/service/s3"
	"github.com/aws/aws-sdk-go/service/s3/s3manager"
)

func main() {
	// Create a session using shared credentials or environment variables
	sess, err := session.NewSession(&aws.Config{
		Region: aws.String("us-central-1"), // Set your desired AWS region
	})
	if err != nil {
		fmt.Println("Failed to create AWS session:", err)
		return
	}

	// Create an S3 client and downloader
	
	downloader := s3manager.NewDownloader(sess)

	// Specify the bucket name
	bucketName := "d2b-internal-assessment-bucket"

	// List of files to download
	files := []string{"orders.csv", "reviews.csv", "shipment_deliveries.csv"}

	// Download each file
	for _, file := range files {
		// Create a file to write the downloaded data
		f, err := os.Create(file)
		if err != nil {
			fmt.Println("Failed to create file:", err)
			return
		}

		// Download the file
		_, err = downloader.Download(f, &s3.GetObjectInput{
			Bucket: aws.String(bucketName),
			Key:    aws.String("orders_data/" + file),
		})
		if err != nil {
			fmt.Println("Failed to download file:", err)
			return
		}

		fmt.Printf("Downloaded %s\n", file)
		f.Close()
	}
}
