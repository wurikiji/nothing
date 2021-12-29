package main

import (
	"fmt"
	"strings"
)

func main() {
	var char = '한'
	fmt.Printf("%T\n", char)
	fmt.Println(char)
	fmt.Printf("%c\n", char)

	var ss = `하이하이 \n 하이`
	fmt.Println(ss)

	kor := "가나다라마바"
	eng := "abcdef"
	fmt.Printf("len(kor) = %d\n", len(kor))
	fmt.Printf("len(eng) = %d\n", len(eng))

	str := "Hello World"
	runes := []rune(str)
	fmt.Println(str, runes, string(runes))

	korStr := "안녕 친구들"
	korRunes := []rune(korStr)
	fmt.Printf("len(korStr) = %d\n", len(korStr))
	fmt.Printf("len(korRunes) = %d\n", len(korRunes))

	// io.Writer 같은 바이트 단위 인터페이스 사용을 위해서 []byte 변환도 지원한다.
	var slice = []byte(str)
	fmt.Println(slice)

	for i := 0; i < len(korStr); i++ {
		// byte 단위 순회라서 utf-8 의 기타 문자들은 깨진다.
		fmt.Printf(" 타입: %T 값: %d 문자: %c\n", korStr[i], korStr[i], korStr[i])
	}

	for i := 0; i < len(korRunes); i++ {
		// rune 단위 순회 (4바이트) 라서 깨지지 않는다.
		fmt.Printf(" 타입: %T 값: %d 문자: %c\n", korRunes[i], korRunes[i], korRunes[i])
	}

	for _, val := range korStr {
		// range 는 정확한 단위로 순회한다.
		fmt.Printf(" 타입: %T 값: %d 문자: %c\n", val, val, val)
	}

	immutable := "hello world"

	// 아래와 같이 일부를 변경할 순 없다.
	// immutable[1] = 'j'

	// 하지만 전체 변경은 가능하다
	// 왜냐면 데이터를 새로운 메모리에 만드는 것이기 때문이다.
	immutable = "hello ddd"

	slice2 := []byte(immutable)
	slice2[1] = 'j' // 슬라이스는 데이터를 mutable한 메모리 공간으로 복제한다.

	// 이미 생성한 string 을 변경하고자 할 때는
	// 메모리 낭비를 줄이고 성능을 향상시키기 위해
	// strings 패키지의 Builder를 사용하는것이 좋다.
	fmt.Println(toUpper(str))
}

func toUpper(str string) string {
	var builder strings.Builder
	for _, c := range str {
		if c >= 'a' && c <= 'z' {
			builder.WriteRune('A' + (c - 'a'))
		} else {
			builder.WriteRune(c)
		}
	}
	return builder.String()
}

// StringHeader 대충 가늠하는 string 의 구조
// string 끼리 대입하면 실제 데이터를 복사하는 것이 아니라
// Data 와 Len 만 복사한다.
// String 은 불변이기 때문에
// Data 포인터를 그대로 모두가 공유해도 괜찮다
// 이로 인해서 string 대입연산의 속도가 매우 빠르다
type StringHeader struct {
	Data uintptr
	Len  int
}
