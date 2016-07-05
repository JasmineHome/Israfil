package ui

import (
	clui "github.com/gizak/termui"
)

func InitTimerEvents() {
	clui.Handle("/timer/1s", func(e clui.Event) {
		t := e.Data.(clui.EvtTimer)
		// t is a EvtTimer
		if t.Count%2 == 0 {
			// do something
		}
		clui.Render(clui.Body)
	})
}

func PauseRenderTimers() {
	clui.Handle("/timer/1s", func(e clui.Event) {})
}
