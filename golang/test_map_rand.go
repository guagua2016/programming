package main

import (
	"fmt"
	"sort"
)

func main() {

	m := make(map[string]string, 4)
	m["cba"] = "echo cba"
	m["hello"] = "echo hello"
	m["abc"] = "echo abc"
	m["bac"] = "echo bac"

	m["hello"] = "echo hello1"
	m["world"] = "echo world"
	m["go"] = "echo go"
	m["is"] = "echo is"
	m["cool"] = "echo cool"

	for k, v := range m {
		fmt.Println(k, v)
	}

	fmt.Println(len(m))
	fmt.Println("after sorted........")

	sortedKeys := make([]string, 0)
	for k, _ := range m {
		sortedKeys = append(sortedKeys, k)
	}

	sort.Strings(sortedKeys)

	for _, k := range sortedKeys {
		fmt.Println(k, m[k])
	}
}
