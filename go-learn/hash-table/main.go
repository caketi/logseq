package main

import "fmt"

const ArraySize = 7

type HashTable struct {

	array [ArraySize] *bucket 
}

// bucket is a linked list in each slot of the hash table array
type bucket struct {
	head *bucketNode
}

// bucketNode is a linked list node that holds the key
type bucketNode struct{
	key string
	next *bucketNode
}

func (h *HashTable) Insert(key string){
	index := hash(key)
	h.array[index].insert(key)
}

func (h *HashTable) Search(key string) bool{
	index := hash(key)
	x0 := h.array[index].search(key)
	return x0
}

func (h *HashTable) Delete(key string){
	index := hash(key)
	h.array[index].delete(key)
}

func (b *bucket) insert(k string){
	if  !b.search(k){
		newNode := &bucketNode{key:k}
		newNode.next = b.head
		b.head = newNode
	} else {
		fmt.Println(k, "already exists")
	}
}

func (h *bucket) search(k string) bool{
	currentNode := h.head
	for currentNode != nil{
		if currentNode.key == k{
			return true
		}
		currentNode = currentNode.next
	}
	return false
}

func (b *bucket) delete(k string){
	if b.head.key == k {
		b.head = b.head.next
		return 
	}

	previousNode := b.head
	for previousNode.next != nil{
		if previousNode.next.key == k{
			previousNode.next = previousNode.next.next
			return 
		}
		previousNode = previousNode.next
	}
}

func hash(key string) int {
	sum := 0
	for _, v := range key{
		sum += int(v)
	}
	return sum % ArraySize
}

func Init() *HashTable{
	result := &HashTable{}
	for i := range result.array{
		result.array[i] = &bucket{}
	}
	return result
}

func main(){
	hashTable := Init()
	list := []string{
		"ERIC", 
		"STAN",
		"RANDY",
		"KYLE",
	}

	for _, v := range list{
		hashTable.Insert(v)
	}

	hashTable.Delete("ERIC")
	fmt.Print(hashTable)
}