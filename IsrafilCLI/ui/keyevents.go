package ui

import (
	"github.com/gizak/termui"
)

func InitKeyEvents() {
	termui.Handle("/sys/kbd/q", func(termui.Event) {
		termui.StopLoop()
	})
	termui.Handle("/sys/kbd/h", func(termui.Event) {
		ShowHelpUI()
	})
	termui.Handle("/sys/kbd/e", func(termui.Event) {
		GetInput()
		InitUI()
		InitTimerEvents()
		InitWindowEvents()
		InitKeyEvents()
		termui.Loop()
	})
}

func PauseKeyEvents() {
	termui.Handle("/sys/kbd/q", func(termui.Event) {})
	termui.Handle("/sys/kbd/h", func(termui.Event) {})
	termui.Handle("/sys/kbd/e", func(termui.Event) {})
}
