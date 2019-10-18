package main

import (
	"fmt"
)

func quicksort(a []int, start, end int) {

	if start >= end {
		return
	}

	left := start
	right := end
	pivot := a[start]

	for left < right {
		for left < right && a[right] >= pivot {
			right--
		}
		a[left] = a[right]

		for left < right && a[left] <= pivot {
			left++
		}
		a[right] = a[left]
	}

	a[left] = pivot
	quicksort(a, start, left-1)
	quicksort(a, left+1, end)
}

func main() {

	a := []int{5, 4, 2, 10, 7, 1}
	quicksort(a, 0, 5)
	fmt.Println(a)
}
