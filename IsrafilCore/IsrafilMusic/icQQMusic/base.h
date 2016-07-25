#ifndef BASE_H
#define BASE_H
#include <string>

namespace Israfil {
namespace QQMusic {
using std::string;

const string QMBase          = "music.qq.com";
const string QMSearchBase    = "http://s." + QMBase;
const string QMSearchURL     = QMSearchBase + "/fcgi-bin/music_search_new_platform?t=0&n={0}&aggr=1&cr=1&loginUin=0&format=json&inCharset=GB2312&outCharset=utf-8&notice=0&platform=jqminiframe.json&needNewCode=0&p=1&catZhida=0&remoteplace=sizer.newclient.next_song&w={1}";
const string QMStreamURL     = "http://stream.qqmusic.tc.qq.com";
const string QMM4aURL        = QMStreamURL + "/{0}.m4a";      // sid
const string QMLowMp3URL     = QMStreamURL + "/{0}.mp3";      // sid + 30000000
const string QMHighMp3URL    = QMStreamURL + "/{0}.mp3";      // sid
const string QMFlacURL       = QMStreamURL + "/F000{0}.flac"; // mid
const string QMApeURL        = QMStreamURL + "/A000{0}.ape";  // mid
const string QMSongURL       = "http://y.qq.com/#type=song&mid={0}&tpl=yqq_song_detail";
const string QMSongDetailURL = "http://s.plcloud.music.qq.com/fcgi-bin/fcg_list_songinfo.fcg?idlist={0}&callback=jsonCallback&url=1";
const string QMSongPicURL    = "http://i.gtimg.cn/music/photo/mid_album_300/{0}/{1}/{2}.jpg";
const string QMAlbumPicURL   = "http://imgcache.qq.com/music/photo/album/{0}/albumpic_{1}_0.jpg";
const string QMLyricsURL     = "http://music.qq.com/miniportal/static/lyric/{0}/{1}.xml";
const string QMSongListURL   = "http://i.y.qq.com/qzone-music/fcg-bin/fcg_ucc_getcdinfo_byids_cp.fcg?type=1&json=1&utf8=1&onlysong=0&nosign=1&disstid={0}&g_tk=938407465&loginUin=0&hostUin=0&format=jsonp&inCharset=GB2312&outCharset=utf-8&notice=0&needNewCode=0"

#define FSongID 0
#define FSongName 1
#define FSingerID 2
#define FSingerName 3
#define FAlbumID 4
#define FAlbumName 5
#define FMusicID 20
#define FSongPicID 22
#define DEBUG 1
}
}
#endif // ifndef BASE_H
