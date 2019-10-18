package main

import (
	"fmt"
	"path"
	// "path/filepath"
)

func main() {
	fmt.Println(path.Ext("/a/b/c/bar.css"))
	fmt.Println(path.Base("/a/b/c/"))
	fmt.Println(path.Dir("/a/b/c"))
	fmt.Println(path.Clean("/a/b/.."))
	fmt.Println(path.Join("a/b", "c"))
	fmt.Println(path.Match("a*/b", "a/c/b"))
	fmt.Println(path.Split("static/myfile.css"))
}
