package main

import "fmt"

type Stack struct {
	items []int
}

func (s *Stack) Push(i int) *Stack{
	s.items = append(s.items, i)
	return s
}
func (s *Stack) Pop() int{
	l := len(s.items) -1
	toRemove := s.items[l]
	s.items = s.items[:l]
	return toRemove
}
func  main() {
	s := Stack{}
	s.Push(1)
	s.Pop()
	fmt.Print(s)

}