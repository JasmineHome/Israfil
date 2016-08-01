//import QtQuick 2.0
import QtQuick 2.6
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.0
import IsrafilCore 1.0
import "../scripts/json.js" as Json
import "../scripts/SongList.js" as SLIL

Item {
    property var delegateComponentMap: {
        "ItemDelegate": itemDelegateComponent,
                "RadioDelegate": radioDelegateComponent,
    }

    property string userSongListInfo: "";
    property string curSongListSongs: "";
    property string userid: "46123345";

    Component {
        id: itemDelegateComponent

        ItemDelegate {
            text: labelText
            width: parent.width
            onDoubleClicked: {
                console.log("Double Clicked: "+ curSongIndex)
                isrp.fileUrl = SLIL.getSongURLInSongList(curSongIndex)
                isrp.mediaPlay()
            }
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
            onClicked: {
                console.log("Clicked: " + curListIndex)
                //SLIL.
                console.log(songListModel.get(curListIndex).id)
                lbSongsTitle.text = songListModel.get(curListIndex).text
                SLIL.setSongsModel(songListModel.get(curListIndex).id)
                console.log("setSongsModel complete")
            }
        }
    }

    ColumnLayout {
        id: columnLeft
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
                    SLIL.setSongListModel(userid);
                }
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
                width: columnLeft.width
                sourceComponent: delegateComponentMap[type]

                property string labelText: text
                property ListView view: listView
                property int curListIndex: index

            }
        }
    }

    ColumnLayout {
        id: columnRight
        spacing: 20
        anchors.fill: parent
        anchors.topMargin: 20
        anchors.leftMargin: parent.width/3
        anchors.rightMargin: 0

        Label {
            id: lbSongsTitle
            Layout.fillWidth: true
            wrapMode: Label.Wrap
            horizontalAlignment: Qt.AlignHCenter
            text: "请选择一个左边的歌单"
        }

        ListView {
            id: listViewSong
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            model: ListModel {
                id: songModel
                Component.onCompleted: {
                    //SLIL.setListModel(isrc.getUserSongList("46123345"));
                    //SLIL.setSongsModel()
                }
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
                id: delegateSongLoader
                width: columnRight.width
                sourceComponent: delegateComponentMap[type]

                property string labelText: text
                property ListView view: listView
                property int curSongIndex: index

            }
        }
    }

}
