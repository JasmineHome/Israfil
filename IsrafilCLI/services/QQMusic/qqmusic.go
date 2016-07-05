package qqmusic

import (
	"fmt"
	"log"
	// "strconv"

	//	"github.com/ddliu/go-httpclient"
	"github.com/LER0ever/Israfil/IsrafilCLI/base"
	//"github.com/natefinch/pie"
)

/*
func main() {
	log.SetPrefix("IsrafilCore::Plugin::QQMusic:: ")
	initHTTPClient()

	//if DEBUG == 1 {
	//	debugTest()
	//}

	p := base.NewProvider()
	if err := p.RegisterName("QQMusic", api{}); err != nil {
		log.Fatalf("failed to register Plugin: %s", err)
	}
	p.ServeCodec(jsonrpc.NewServerCodec)

}
*/

func Search(name string, retSR *base.SearchRet) error {
	var Qmsr QMSearchRet
	searchByName(name, &Qmsr)
	log.Printf("Qmsr.Data.Song.Curnum: %d", Qmsr.Data.Song.Curnum)
	log.Print("QMSR::\n", Qmsr)
	log.Print("QMSR List Count", len(Qmsr.Data.Song.SongLists))
	retSR.NumOfRes = Qmsr.Data.Song.Curnum
	for i, song := range Qmsr.Data.Song.SongLists {
		log.Printf("DEBUG: Qmsr num %d", i)
		var tempS base.Song
		FArray := splitF(song.FString)
		retSR.Songs = append(retSR.Songs, tempS)
		retSR.Songs[i].UID = fmt.Sprintf("%d%s", base.SrcQQMusic, FArray[FSongID])
		retSR.Songs[i].SName = FArray[FSongName]
		retSR.Songs[i].SID = FArray[FMusicID]
		retSR.Songs[i].SSource = base.SrcQQMusic
		retSR.Songs[i].SURL = fmt.Sprintf(QMSongURL, FArray[FMusicID])
	}
	return nil
}
