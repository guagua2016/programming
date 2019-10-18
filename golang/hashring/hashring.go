package hashring

import (
	"crypto/sha1"
	"sync"
	//  "hash"
	"fmt"
	"math"
	"sort"
	"strconv"
)

/*
	https://github.com/g4zhuj/hashring
	https://blog.csdn.net/u010511236/article/details/52216059
	https://segmentfault.com/a/1190000013533592
*/

const (
	//DefaultVirualSpots default virual spots
	DefaultTotalVirualSpots = 1000
)

type virtualNode struct {
	nodeKey   string
	nodeValue uint32
}
type nodesArray []virtualNode

func (p nodesArray) Len() int           { return len(p) }
func (p nodesArray) Less(i, j int) bool { return p[i].nodeValue < p[j].nodeValue }
func (p nodesArray) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }
func (p nodesArray) Sort()              { sort.Sort(p) }

//HashRing store nodes and weigths
type HashRing struct {
	total           int            //total number of virtual node
	virtualNodes    nodesArray     //array of virtual nodes sorted by value
	realNodeWeights map[string]int //Node:weight
	mu              sync.RWMutex
}

//NewHashRing create a hash ring with virual spots
func NewHashRing(total int) *HashRing {
	if total == 0 {
		total = DefaultTotalVirualSpots
	}

	h := &HashRing{
		total:           total,
		virtualNodes:    nodesArray{},
		realNodeWeights: make(map[string]int),
	}
	h.buildHashRing()
	return h
}

//AddNodes add nodes to hash ring
func (h *HashRing) AddNodes(nodeWeight map[string]int) {
	h.mu.Lock()
	defer h.mu.Unlock()
	for nodeKey, weight := range nodeWeight {
		h.realNodeWeights[nodeKey] = weight
	}
	h.buildHashRing()
}

//AddNode add node to hash ring
func (h *HashRing) AddNode(nodeKey string, weight int) {
	h.mu.Lock()
	defer h.mu.Unlock()
	h.realNodeWeights[nodeKey] = weight
	h.buildHashRing()
}

//RemoveNode remove node
func (h *HashRing) RemoveNode(nodeKey string) {
	h.mu.Lock()
	defer h.mu.Unlock()
	delete(h.realNodeWeights, nodeKey)
	h.buildHashRing()
}

//UpdateNode update node with weight
func (h *HashRing) UpdateNode(nodeKey string, weight int) {
	h.mu.Lock()
	defer h.mu.Unlock()
	h.realNodeWeights[nodeKey] = weight
	h.buildHashRing()
}

func (h *HashRing) buildHashRing() {
	var totalW int
	for _, w := range h.realNodeWeights {
		totalW += w
	}
	h.virtualNodes = nodesArray{}
	for nodeKey, w := range h.realNodeWeights {
		spots := int(math.Floor(float64(w) / float64(totalW) * float64(h.total)))
		for i := 1; i <= spots; i++ {
			hash := sha1.New()
			hash.Write([]byte(nodeKey + ":" + strconv.Itoa(i)))
			hashBytes := hash.Sum(nil)

			oneVirtualNode := virtualNode{
				nodeKey:   nodeKey,
				nodeValue: genValue(hashBytes[6:10]),
			}
			h.virtualNodes = append(h.virtualNodes, oneVirtualNode)

			hash.Reset()
		}
	}
	// sort virtual nodes for quick searching
	h.virtualNodes.Sort()
}

func genValue(bs []byte) uint32 {
	if len(bs) < 4 {
		return 0
	}
	v := (uint32(bs[3]) << 24) | (uint32(bs[2]) << 16) | (uint32(bs[1]) << 8) | (uint32(bs[0]))
	return v
}

//GetNode get node with key
func (h *HashRing) GetNode(s string) string {
	h.mu.RLock()
	defer h.mu.RUnlock()
	if len(h.virtualNodes) == 0 {
		fmt.Println("no valid node in the hashring")
		return ""
	}
	hash := sha1.New()
	hash.Write([]byte(s))
	hashBytes := hash.Sum(nil)
	v := genValue(hashBytes[6:10])
	i := sort.Search(len(h.virtualNodes), func(i int) bool { return h.virtualNodes[i].nodeValue >= v })
	//ring
	if i == len(h.virtualNodes) {
		i = 0
	}
	return h.virtualNodes[i].nodeKey
}
