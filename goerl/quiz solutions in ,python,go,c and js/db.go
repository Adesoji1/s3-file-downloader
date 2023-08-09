package main

import (
	"database/sql"
	"encoding/json"
	"fmt"
	"log"

	_ "github.com/lib/pq"
)

type User struct {
	UserID int    `json:"user_id"`
	Name   string `json:"name"`
	Age    int    `json:"age"`
	Phone  string `json:"phone"`
}

func fetch_data_as_json() string {
	connStr := "user=your_username password=your_password dbname=your_database sslmode=disable"
	db, err := sql.Open("postgres", connStr)
	if err != nil {
		log.Fatal(err)
	}

	rows, err := db.Query("SELECT user_id, name, age, phone FROM user_table")
	if err != nil {
		log.Fatal(err)
	}
	defer rows.Close()

	users := []User{}
	for rows.Next() {
		var user User
		err = rows.Scan(&user.UserID, &user.Name, &user.Age, &user.Phone)
		if err != nil {
			log.Fatal(err)
		}
		users = append(users, user)
	}
	if err = rows.Err(); err != nil {
		log.Fatal(err)
	}

	jsonData, err := json.Marshal(map[string]interface{}{"status_code": 200, "data": users})
	if err != nil {
		log.Fatal(err)
	}
	return string(jsonData)
}

func main() {
	fmt.Println(fetch_data_as_json())
}
