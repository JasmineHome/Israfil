package main

//TODO: to be continued
import (
	//"fmt"
	"log"
	"net/rpc/jsonrpc"

	"github.com/LER0ever/Israfil/IsrafilCLI/base"
	//"github.com/natefinch/pie"
)

func main() {
	log.SetPrefix("IsrafilCore::Plugin::Xiami:: ")
	initHTTPClient()
    if DEBUG == 1 {
        debugTest()
    }
	p := base.NewProvider()
	if err := p.RegisterName("Xiami", api{}); err != nil {
		log.Fatalf("failed to register Plugin: %s", err)
	}
	p.ServeCodec(jsonrpc.NewServerCodec)
}

type api struct{}

func (api) Ping(msg string, response *string) error {
	if msg != "ping" {
		*response = "Plugin Failed"
		return nil
	}
	log.Printf("Successfully Connected to host IsrafilCore::Main")

	*response = "IsrafilCore::Plugin::Xiami Plugged"
	return nil
}

func (api) Search(Name string, retSR *base.SearchRet) error{
    var Xmsr XiamiSongSearchRet
    searchByName(Name, &Xmsr)
    retSR.NumOfRes = int64(len(Xmsr.Songs))
    for i, song := range Xmsr.Songs {
        var tempS base.Song
		retSR.Songs = append(retSR.Songs, tempS)
        retSR.Songs[i].ID = song.ID
        retSR.Songs[i].Name = song.Name
        retSR.Songs[i].Author.Name = song.Author
        retSR.Songs[i].PicURL = song.PicURL
        retSR.Songs[i].MusicURL = append(retSR.Songs[i].MusicURL, song.Mp3URL)
    }
    return nil
}

func debugTest() {
    log.Printf("Running DEBUG Test")
    log.Printf("XiamiToken: %s", getXiamiToken())
}
