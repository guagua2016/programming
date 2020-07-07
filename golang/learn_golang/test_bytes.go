package main

import (
	"bytes"
	"fmt"
)

func main() {
	b := []byte("mchenys")
	fmt.Println(bytes.Contains(b, []byte("m")))
	fmt.Println(string(b))

	s := []byte("你好世界")
	r := bytes.Runes(s)
	fmt.Println("转换前字符串的长度: ", len(s)) //12
	fmt.Println("转换后字符串的长度: ", len(r)) //4

	s = []byte("mChenys")
	prefix := []byte("m")
	fmt.Println(bytes.HasPrefix(s, prefix)) //true
	prefix = []byte("men")
	fmt.Println(bytes.HasPrefix(s, prefix)) //false
}
