package main

import (
	"fmt"
	"log"
	//	"os"

	"github.com/LER0ever/Israfil/IsrafilCLI/base"
)

//InitialVersionPrint Print startup info
func InitialVersionPrint() {
	fmt.Print(
		base.AppName,
		"\nVersion: ",
		float64(base.AppVersion)/100.0,
		"\nApiLevel: ",
		float64(base.APILevel)/100.0,
		"\n\n")
}

func InitLogPrefix() {
	log.SetPrefix("IsrafilCLI::Main:: ")
}
