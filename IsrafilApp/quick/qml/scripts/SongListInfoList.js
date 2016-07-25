function GetSLILNames(strJson) {
    var jsonobj = JSON.parse(strJson);
    var retarr= [];
    retarr.push(jsonobj[0].slName);
    console.log(retarr);
    return retarr;
}

function setListModel(strJson) {
    var jsonobj = JSON.parse(strJson);
    //console.log(strJson)
    var SLILRoot = jsonobj["SongListInfoList"];
    //console.log(SLILRoot[0].slName)
    //songListModel.append({"type":"RadioDelegate", "text":SLILRoot[0].slName,"spec":"网易云音乐"});
    //songListModel.append({"type":"RadioDelegate", "text":"SLILRoot[0].slName","spec":"网易云音乐"});
    for (var i=0; i<SLILRoot.length; i++) {
        songListModel.append({"type":"RadioDelegate", "text":SLILRoot[i].slName,"spec":"网易云音乐"});
    }

    /*for (var SongListRoot in jsonobj){
        console.log(strJson);
        for (var i=0; i<SongListRoot.length; i++){
            console.log(SongListRoot[i].slName)
            songListModel.append({"type":"RadioDelegate", "text":SongList.slName,"spec":"网易云音乐"});
        }
    }*/
}
