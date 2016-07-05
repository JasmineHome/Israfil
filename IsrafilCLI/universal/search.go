package universal

import (
	"log"

	"github.com/LER0ever/Israfil/IsrafilCLI/base"
	"github.com/LER0ever/Israfil/IsrafilCLI/services/Netease"
	"github.com/LER0ever/Israfil/IsrafilCLI/services/QQMusic"
)

func Search(name string, opt uint) base.SearchRet {
	var srqq base.SearchRet
	qqmusic.InitHTTPClient()
	err := qqmusic.Search(name, &srqq)
	if err != nil {
		log.Fatalf("qqmusic search err: %s", err)
	}
	var srne base.SearchRet
	netease.InitHTTPClient()
	err = netease.Search(name, &srne)
	if err != nil {
		log.Fatalf("netease search err: %s", err)
	}
	var sr base.SearchRet
	sr.NumOfRes = srqq.NumOfRes + srne.NumOfRes
	sr.Songs = append(srqq.Songs, srne.Songs...)
	return sr
}
