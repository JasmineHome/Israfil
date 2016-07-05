package netease

//NEBase Netease basic URL
//NEApiBase Netease Api basic URL
const (
	magicKey          = "3go8&$8*3*3h0k(2)2"
	NEBase            = "http://music.163.com"
	NEApiBase         = NEBase + "/api"
	NESongInfo        = NEApiBase + "/song/detail?ids=[%d]"
	NESongCDN         = "http://m%d.music.126.net/%s/%d.mp3"
	NESongURL         = "http://music.163.com/#/song?id=%d"
	NESearchApiParams = "s=%s&limit=20&type=1&offset=0"
	NERetOK           = 200
	DEBUG             = 1
)

//NeteaseMusicInfo defines an mp3 file
type NeteaseMusicInfo struct {
	DfsID   int64 `json:"dfsId"`
	BitRate int64 `json:"bitrate"`
}

//NeteaseArtistSubRet defines a artist structure for main ret
type NeteaseArtistSubRet struct {
	Name     string `json:"name"`
	ID       int64  `json:"id"`
	PicURL   string `json:"picUrl"`
	Songnum  int64  `json:"musicSize"`
	Albumnum int64  `json:"albumSize"`
}

//NeteaseSongSubRet defines a single song return structure
type NeteaseSongSubRet struct {
	Stared   bool                  `json:"starred"`
	Mp3URL   string                `json:"mp3Url"`
	Name     string                `json:"name"`
	ID       int64                 `json:"id"`
	Duration int64                 `json:"duration"`
	Artists  []NeteaseArtistSubRet `json:"artists"`
	HMusic   NeteaseMusicInfo      `json:"hMusic"`
	MMusic   NeteaseMusicInfo      `json:"mMusic"`
	LMusic   NeteaseMusicInfo      `json:"lMusic"`
	Album    NeteaseAlbumSubRet    `json:"album"`
}

//NeteaseAlbumSubRet defines a album return structure
type NeteaseAlbumSubRet struct {
	Name   string `json:"name"`
	ID     int64  `json:"id"`
	PicURL string `json:"picUrl"`
}

//NeteaseSongListRet Main return result for json, only Code 200 is OK
type NeteaseSongListRet struct {
	Songs []NeteaseSongSubRet `json:"songs"`
	Code  uint                `json:"code"`
}

type NeteaseSearchSongResSubRet struct {
	SongNum uint                `json:"songCount"`
	Songs   []NeteaseSongSubRet `json:"songs"`
}

//NeteaseSearchRet a structure to receive the search result json
type NeteaseSearchRet struct {
	Result NeteaseSearchSongResSubRet `json:"result"`
	Code   uint                       `json:"code"`
}
