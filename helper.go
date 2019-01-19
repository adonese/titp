package main

import (
	"fmt"
	//	"io"
)

func main() {
	msg := "080020380000004000009900000000011050290114313930303030313920202020202020"
	fmt.Println(addHeader(msg))
}

func addHeader(req string) string {

	tpdu := "6000190000"
	msg := tpdu + req
	lenHex := fmt.Sprintf("00%x", len(msg))
	fmt.Println(lenHex)
	return lenHex + msg
}
