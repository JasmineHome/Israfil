package netease

import (
	"fmt"
	"log"
	//  "net/rpc/jsonrpc"
	//	"github.com/ddliu/go-httpclient"

	"github.com/LER0ever/Israfil/IsrafilCLI/base"
	//"github.com/natefinch/pie"
)

func Search(name string, retSR *base.SearchRet) error {
	var Nesr NeteaseSearchRet
	searchByName(name, &Nesr)
	log.Printf("Nesr.Result.SongNum: %d", Nesr.Result.SongNum)
	retSR.NumOfRes = Nesr.Result.SongNum
	for i, song := range Nesr.Result.Songs {
		var tempS base.Song
		retSR.Songs = append(retSR.Songs, tempS)
		retSR.Songs[i].UID = fmt.Sprintf("%d%d", base.SrcNetease, song.ID)
		retSR.Songs[i].SName = song.Name
		retSR.Songs[i].SID = fmt.Sprintf("%d", song.ID)
		retSR.Songs[i].SSource = base.SrcNetease
		retSR.Songs[i].SURL = fmt.Sprintf(NESongURL, song.ID)
		//	retSR.Songs[i].MusicURL
		var tempNeslr NeteaseSongListRet
		getInfoByID(song.ID, &tempNeslr)
		retSR.Songs[i].SMp3URLs = append(retSR.Songs[i].SMp3URLs, downloadURLByID(tempNeslr.Songs[0].HMusic.DfsID))
		//strings.Join(retSR.Songs[i].MusicURL, downloadURLByID(tempNeslr.Songs[0].HMusic.DfsID))
		//strings.Join(retSR.Songs[i].MusicURL, sep string)
	}
	return nil
}

func debugTest() {
	log.Print("DEBUG option on, running debug test")
	//log.Print(testRequests())
	var tempNesr NeteaseSearchRet
	errSr := searchByName("victory", &tempNesr)
	if errSr != nil {
		log.Fatalf("SR ERROR: %s", errSr)
	}
	//log.Printf(format string, v ...interface{})
	//log.Printf("%s", getInfoById(28732677))

	//log.Printf("%s", downloadUrlById(2080275999766815))
	var tempNeslr NeteaseSongListRet
	errSlr := getInfoByID(16343629, &tempNeslr)
	if errSlr != nil {
		log.Fatalf("SLR ERROR: %s", errSlr)
	}
	log.Printf("%d :: %s", tempNeslr.Songs[0].HMusic.DfsID, downloadURLByID(tempNeslr.Songs[0].HMusic.DfsID))
	log.Printf("%d :: %s", tempNeslr.Songs[0].MMusic.DfsID, downloadURLByID(tempNeslr.Songs[0].MMusic.DfsID))
	log.Printf("%d :: %s", tempNeslr.Songs[0].LMusic.DfsID, downloadURLByID(tempNeslr.Songs[0].LMusic.DfsID))
	//log.Printf("%s", downloadURLByID(7864806673850166))
}
