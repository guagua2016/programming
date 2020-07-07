package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"os"
)

func main() {
	type UserInfo struct {
		UseId    int    `json:"user_id"`
		UserName string `json:"user_name"`
	}

	// type UserInfo struct {
	// 	UseId    int
	// 	UserName string
	// }

	u := &UserInfo{UseId: 1, UserName: "Terse"}
	j, _ := json.Marshal(u)
	fmt.Println(string(j))
	ioutil.WriteFile("./placement.json", []byte(j), 0644)

	file, err := os.Open("./placement.json")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()
	b, err := ioutil.ReadAll(file)
	var r interface{}
	_ = json.Unmarshal(b, &r)
	fmt.Println(r)
}
