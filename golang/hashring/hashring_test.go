package hashring

import (
	"fmt"
	"testing"
)

func TestHashRing(t *testing.T) {
	realNodeWeights := make(map[string]int)
	realNodeWeights["node1"] = 1
	realNodeWeights["node2"] = 2
	realNodeWeights["node3"] = 3

	totalVirualSpots := 100

	ring := NewHashRing(totalVirualSpots)
	ring.AddNodes(realNodeWeights)
	fmt.Println(ring.virtualNodes, len(ring.virtualNodes))
	fmt.Println(ring.GetNode("1845"))  //node3
	fmt.Println(ring.GetNode("994"))   //node1
	fmt.Println(ring.GetNode("hello")) //node3

	//remove node
	ring.RemoveNode("node3")
	fmt.Println(ring.GetNode("1845"))  //node2
	fmt.Println(ring.GetNode("994"))   //node1
	fmt.Println(ring.GetNode("hello")) //node2

	//add node
	ring.AddNode("node4", 2)
	fmt.Println(ring.GetNode("1845"))  //node4
	fmt.Println(ring.GetNode("994"))   //node1
	fmt.Println(ring.GetNode("hello")) //node4

	//update the weight of node
	ring.UpdateNode("node1", 3)
	fmt.Println(ring.GetNode("1845"))  //node4
	fmt.Println(ring.GetNode("994"))   //node1
	fmt.Println(ring.GetNode("hello")) //node1
	fmt.Println(ring.realNodeWeights)
}
