package ui

import (
	clui "github.com/gizak/termui"
)

func InitUI() {
	err := clui.Init()
	if err != nil {
		panic(err)
	}
	//defer termui.Close()
	InitTimerEvents()
	InitWindowEvents()
	InitKeyEvents()
	clui.Loop()
}

func ClearUI() {
	clui.Clear()
	clui.Render()
	PauseRenderTimers()
}
