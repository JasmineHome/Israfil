package ui

import (
	"bufio"
	"fmt"
	"os"

	clui "github.com/gizak/termui"
)

func GetInput(Hint string) string {
	clui.Clear()
	clui.Render()
	PauseKeyEvents()
	PauseRenderTimers()
	//clui.StopLoop()
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter text: ")
	text, _ := reader.ReadString('\n')
	fmt.Println(text)
	//defer InitUI()
	return text
}
