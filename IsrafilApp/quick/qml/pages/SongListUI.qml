//import QtQuick 2.0
import QtQuick 2.6
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.0
import IsrafilCore 1.0
import "../scripts/json.js" as Json
import "../scripts/SongListInfoList.js" as SLIL

Item {
    property var delegateComponentMap: {
        "ItemDelegate": itemDelegateComponent,
                "RadioDelegate": radioDelegateComponent,
    }
    IsrafilCoreQt {
        id: isrc
    }

    //property var uslObject : Json.JsonToObject(IsrafilCoreQt.getUserSongList("46123345"))
    //property var uslNames : SLIL.GetSLILNames(IsrafilCoreQt.getUserSongList("46123345"))
    //property var asdf: SLIL.SetListModel(isrc.getUserSongList("46123345"));
    Component {
        id: itemDelegateComponent

        ItemDelegate {
            text: labelText
            width: parent.width
        }
    }


    ButtonGroup {
        id: radioButtonGroup
    }

    Component {
        id: radioDelegateComponent

        RadioDelegate {
            text: labelText
            ButtonGroup.group: radioButtonGroup
        }
    }

    ColumnLayout {
        id: column
        spacing: 20
        anchors.fill: parent
        anchors.topMargin: 20
        anchors.rightMargin: parent.width/3*2

        Label {
            Layout.fillWidth: true
            wrapMode: Label.Wrap
            horizontalAlignment: Qt.AlignHCenter
            text: "测试免登陆获取所有歌单"
        }

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            model: ListModel {
                id: songListModel
                Component.onCompleted: {
                    SLIL.setListModel(isrc.getUserSongList("46123345"));
                    /*songListModel.append({"type":"RadioDelegate", "text":"SLILRooslName","spec":"网易云音乐"});
                    var jsonobj = JSON.parse(isrc.getUserSongList("46123345"));
                    //console.log(strJson)
                    var SLILRoot = jsonobj["SongListInfoList"];
                    console.log(SLILRoot[0].slName)
                    //songListModel.append({"type":"RadioDelegate", "text":SLILRoot[0].slName,"spec":"网易云音乐"});
                    songListModel.append({"type":"RadioDelegate", "text":"SLILRoot[0].slName","spec":"网易云音乐"});*/
                    /*for (var i=0; i<SLILRoot.length; i++) {
                        songListModel.append({"type":"RadioDelegate", "text":SLILRoot[i].slName,"spec":"网易云音乐"});
                    }*/


                    //songListModel.append({"type":"RadioDelegate","text":"RadioDelegadte","spec":"Universal"});
                }

                //ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "Universal" }
                //ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "Universal" }
                //ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "Universal" }
                //ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "Universal" }
                //Repeater{
                //    model: uslNames
                //   ListElement { type: "RadioDelegate"; text: uslNames[index] ; spec: "网易云音乐" }
                //}

                //ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "网易云音乐" }
                //ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "网易云音乐" }
                //ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "网易云音乐" }
                //ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "网易云音乐" }

            }

            section.property: "spec"
            section.delegate: Pane {
                width: listView.width
                height: sectionLabel.implicitHeight + 20

                Label {
                    id: sectionLabel
                    text: section
                    anchors.centerIn: parent
                }
            }

            delegate: Loader {
                id: delegateLoader
                width: listView.width
                sourceComponent: delegateComponentMap[type]

                property string labelText: text
                property ListView view: listView
                property int ourIndex: index
            }
        }
    }

}
