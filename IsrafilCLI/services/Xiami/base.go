package main

const (
	XiamiSongSearchURLOld = "http://www.xiami.com/web/search-songs?spm=0.0.0.0.pAhr1p&key=%s"
    XiamiSongSearchURL = "http://www.xiami.com/web/search-songs?key=%s&limit=50&page=0"
	XiamiSongDetailURL = "http://www.xiami.com/song/playlist/id/%d/object_name/default/object_id/0"
    DEBUG = 1
)

type XiamiSongSearchSubRet struct {
    ID int64 `json:"id"`
    Name string `json:"title"`
    Author string `json:"author"`
    PicURL string `json:"cover"`
    Mp3URL string `json:"src"`
}

type XiamiSongSearchRet struct {
    Songs []XiamiSongSearchSubRet
}
