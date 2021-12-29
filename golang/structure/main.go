package main

type Person struct {
	ID   int64
	Name string
}
type Student struct {
	Person
	Class int
	No    int
	Score float64
}

func main() {
	// default constructor
	var a Student
	a.Name = "hi"
	a.No = 10
	a.ID = 20
	a.Score = 70.8

	// Parameterized constructor
	var b = Student{
		Person{123, "wurikiji"}, 7, 8, 90.2,
	}
	b.No = 10

	// Named constructor
	var c = Student{Score: 20.8, Person: Person{ID: 90}}
	c.Name = "sjsj"
}
