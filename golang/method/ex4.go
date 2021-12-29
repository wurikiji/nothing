package main

import "time"

type Courier struct {
	Name string
}

type Product struct {
	Name  string
	Price int
	ID    int
}

type Parcel struct {
	Pdt           *Product
	ShippedTime   time.Time
	DeliveredTime time.Time
}

func (courier *Courier) SendProduct(pdt *Product) *Parcel {
	retParcel := &Parcel{ShippedTime: time.Now(), Pdt: pdt}

	return retParcel
}

func (parcel *Parcel) Delivered() *Product {
	parcel.DeliveredTime = time.Now()
	return parcel.Pdt
}

func main() {

}
