package ui

import (
	"github.com/gizak/termui"
)

func InitUI() {
	err := termui.Init()
	if err != nil {
		panic(err)
	}
	//defer termui.Close()
	InitTimerEvents()
	InitWindowEvents()
	InitKeyEvents()
	termui.Loop()
}
