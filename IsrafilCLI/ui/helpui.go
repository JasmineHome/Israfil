package ui

import (
	"fmt"

	clui "github.com/gizak/termui"
)

var (
	par0 *clui.Par
	par1 *clui.Par
	par2 *clui.Par
	par3 *clui.Par
)

func ShowHelpUI() {
	par0 = clui.NewPar("LER0ever Project Israfil")
	par0.Height = 3
	/*par0.Width = 20
	par0.Y = 1*/
	par0.Border = false

	par1 = clui.NewPar("你好，世界。")
	par1.Height = 3
	/*par1.Width = 17
	par1.X = 20*/
	par1.BorderLabel = "标签"

	par2 = clui.NewPar("Simple colored text\nwith label. It [can be](fg-red) multilined with \\n or [break automatically](fg-red,fg-bold)")
	par2.Height = 5
	/*par2.Width = 37
	par2.Y = 4*/
	par2.BorderLabel = "Multiline"
	par2.BorderFg = clui.ColorYellow

	par3 = clui.NewPar(fmt.Sprintf("%d", clui.TermWidth()))
	par3.Height = 5
	/*par3.Width = 37
	par3.Y = 9*/
	par3.BorderLabel = "Auto Trim"
	clui.Body.AddRows(
		clui.NewRow(
			clui.NewCol(5, 0, par0),
			clui.NewCol(7, 0, par1),
		),
		clui.NewRow(
			clui.NewCol(6, 0, par2),
			clui.NewCol(6, 0, par3),
		),
	)

	clui.Body.Align()

	clui.Render(clui.Body)

}
