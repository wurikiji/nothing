package main

import (
	"fmt"
	"sort"
)

func main() {
	var array [10]int // 배열은 길이가 고정이다 .
	array[0] = 10

	var slice []int // 슬라이스는 개수를 적지 않고 선언한다.
	// [...]int 는 뒤에 나오는 초기화 인자의 갯수로 고정되는 배열이다. 슬라이스가 아니다!

	if len(slice) == 0 {
		fmt.Println("slice is empty ->", slice)
	}

	var slice1 = []int{1, 2, 3}        // 길이 3인 {1,2,3}
	var slice2 = []int{1, 5: 2, 10: 3} // 길이 11 인 {1, 0..., 2, 0, ... , 3}
	var slice3 = make([]int, 3)
	slice1[1] = 1
	slice2[1] = 1
	slice3[1] = 1

	for i, v := range slice {
		slice1[i] = v * 2
	}

	slice = append(slice, 10)             // slice 슬라이스의 제일 뒤에 10을 추가
	slice = append(slice, 11, 12, 12, 13) // 여러개도 동시에 추가 가능
	fmt.Println(cap(slice))               // slice의 실제 capacity 를 알 수 있다.o

	// slicing 기법으로 배열의 일부분을 슬라이스로 생성해낸다
	// [start:end) 이다
	// ** 주의 ** 복사하는게 아니라 시작 지점의 포인터를 반환한다.
	// 이로인해서 slice 나 source array 의 요소를 변경할 경우 서로 영향을 줄 수 잇다.
	slicing := array[0:2]
	fmt.Println(slicing)
	slicing = array[:2]    // from the beginning
	slicing = array[2:]    // to the end
	slicing = array[:]     // everything but immutable
	slicing = array[1:2:3] // start, end + 1, cap end, cap = cap end - start, len = end - start
	fmt.Println(len(slicing), cap(slicing))

	// 빈 슬라이스를 만들고, 거기에 기존 슬라이스를 집어 넣어서 복제한다.
	// 이러면 서로 다른 메모리 주소를 갖기 때문에
	// 원본과 복사본이 마음껏 작업할 수 있다.
	cloning := append([]int{}, array[:]...)
	// copy 내장 함수를 사용하면 더 편하게 쓸 수 있다.
	numElements := copy(cloning, array[:])
	fmt.Println(numElements, len(cloning))

	// sort 패키지를 사용해서 슬라이스를 정렬 할 수 있다.
	sort.Ints(cloning)

	sortStudents()
}

// 구조체 배열/슬라이스 도 정렬이 가능하다
type Student struct {
	Name string
	Age  int
}

type Students []Student

func (s Students) Len() int           { return len(s) }
func (s Students) Less(i, j int) bool { return s[i].Age < s[j].Age }
func (s Students) Swap(i, j int)      { s[i], s[j] = s[j], s[i] }

func sortStudents() {
	s := Students{
		{"하이", 33}, {"호이", 32}, {"두이", 11},
	}
	sort.Sort(s)
	fmt.Println(s)
}
