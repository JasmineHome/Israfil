package qqmusic

//QMBase QQ Music Basic URL
const (
	QMBase          = "music.qq.com"
	QMSearchBase    = "http://s." + QMBase
	QMSearchURL     = QMSearchBase + "/fcgi-bin/music_search_new_platform?t=0&n=%d&aggr=1&cr=1&loginUin=0&format=json&inCharset=GB2312&outCharset=utf-8&notice=0&platform=jqminiframe.json&needNewCode=0&p=1&catZhida=0&remoteplace=sizer.newclient.next_song&w=%s"
	QMStreamURL     = "http://stream.qqmusic.tc.qq.com"
	QMM4aURL        = QMStreamURL + "/%d.m4a"      //sid
	QMLowMp3URL     = QMStreamURL + "/%d.mp3"      //sid + 30000000
	QMHighMp3URL    = QMStreamURL + "/%d.mp3"      //sid
	QMFlacURL       = QMStreamURL + "/F000%d.flac" //mid
	QMApeURL        = QMStreamURL + "/A000%d.ape"  //mid
	QMSongURL       = "http://y.qq.com/#type=song&mid=%s&tpl=yqq_song_detail"
	QMSongDetailURL = "http://s.plcloud.music.qq.com/fcgi-bin/fcg_list_songinfo.fcg?idlist=%s&callback=jsonCallback&url=1"
	QMAlbumPicURL   = "http://i.gtimg.cn/music/photo/mid_album_300/%d/%d/%d.jpg"
	QMLyricsURL     = "http://music.qq.com/miniportal/static/lyric/<0>/<1>.xml"

	//The F elements contains most information of a QQMusic Song
	FSongID     = 0
	FSongName   = 1
	FSingerID   = 2
	FSingerName = 3
	FAlbumID    = 4
	FAlbumName  = 5
	FMusicID    = 20
	FAlbumPicID = 22
	DEBUG       = 1
)

type QMSearchDataSubRet struct {
	Song QMSearchSongSubRet `json:"song"`
}

type QMSearchSongSubRet struct {
	Curnum    uint                 `json:"curnum"`
	SongLists []QMSearchListSubRet `json:"list"`
}

type QMSearchListSubRet struct {
	FString string `json:"f"`
}

//QMSearchRet Main return structure of QQMusic song search
type QMSearchRet struct {
	Code uint               `json:"code"`
	Data QMSearchDataSubRet `json:"data"`
	//TODO
}
