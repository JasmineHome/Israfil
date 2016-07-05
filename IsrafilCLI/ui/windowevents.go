package ui

import (
	"fmt"

	clui "github.com/gizak/termui"
)

func InitWindowEvents() {
	clui.Handle("/sys/wnd/resize", func(e clui.Event) {
		clui.Body.Width = clui.TermWidth()
		clui.Body.Align()
		clui.Render(clui.Body)
		//RefreshPar3()
		par3.Text = fmt.Sprintf("%d", clui.TermWidth())
	})
}
