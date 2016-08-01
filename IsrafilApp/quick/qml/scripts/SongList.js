function GetSLILNames(strJson) {
    var jsonobj = JSON.parse(strJson);
    var retarr= [];
    retarr.push(jsonobj[0].slName);
    console.log(retarr);
    return retarr;
}

function fillSongListJson(userid) {
    userSongListInfo = isrc.getUserSongList(userid);
}

function fillCurSongs(slid) {
    curSongListSongs = isrc.getSongsInSLD(slid)
    console.log("Double Clicked" + curSongListSongs)

}

function setSongListModel(userid) {
    if (userSongListInfo == "") fillSongListJson(userid);
    var jsonobj = JSON.parse(userSongListInfo);
    //console.log(strJson)
    var SLILRoot = jsonobj["SongListInfoList"];
    for (var i=0; i<SLILRoot.length; i++) {
        songListModel.append({"type":"RadioDelegate", "text":SLILRoot[i].slName,"spec":"网易云音乐", "id":SLILRoot[i].slID});
    }
}

function setSongsModel(slid) {
    fillCurSongs(slid);
    songModel.clear();
    var jsonobj = JSON.parse(curSongListSongs);
    //console.log(curSongListSongs)
    var SLRoot = jsonobj["SongList"];
    for (var i=0; i<SLRoot.length; i++) {
        console.log(SLRoot[i].sName);
        songModel.append({"type":"ItemDelegate", "text":SLRoot[i].sName,"spec":"网易云音乐"});
    }
}

function getSongURLInSongList(ind) {
    var jsonobj = JSON.parse(curSongListSongs);
    var SLRoot = jsonobj["SongList"];
    return SLRoot[ind].sMp3URLs[0].AudioURL;
}
