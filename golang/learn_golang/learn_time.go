package main

import (
	"fmt"
	"time"
)

func Unix2LocalTIme(t int64) time.Time {
	loc, _ := time.LoadLocation("Asia/Shanghai") //设置时区
	tstr := time.Unix(t, 0).Format("2006-01-02 15:04:05")
	tt, _ := time.ParseInLocation("2006-01-02 15:04:05", tstr, loc)
	return tt
}

func main() {
	t := time.Now().Unix()
	tt := Unix2LocalTIme(t)
	fmt.Println(tt.Day(), tt.Year())
	fmt.Printf("%+v", tt)
}
