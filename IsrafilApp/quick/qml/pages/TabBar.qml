import QtQuick 2.6
import QtQuick.Controls 2.0

Page {
    id: page
    header:TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: "歌单"
        }
        TabButton {
            text: "搜索"
        }
        TabButton {
            text: "播放列表"
        }
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex


        Pane {
            width: swipeView.width
            height: swipeView.height

            StackView {
                id: songListStack
                anchors.fill: parent

                initialItem: Qt.resolvedUrl("qrc:/pages/SongListUI.qml")
            }

        }
        Pane {
            width: swipeView.width
            height: swipeView.height

            StackView {
                id: searchStack
                anchors.fill: parent

                initialItem: Qt.resolvedUrl("qrc:/pages/SearchPageUI.qml")
            }
            /*
            Column {
                spacing: 40
                width: parent.width

                Label {
                    width: parent.width
                    wrapMode: Label.Wrap
                    horizontalAlignment: Qt.AlignHCenter
                    text: "TabBar 2 is a bar with icons or text which allows the user"
                          + "to switch between different subtasks, views, or modes."
                }

                Image {
                    source: "qrc:/images/arrows.png"
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }*/
        }
        Pane {
            width: swipeView.width
            height: swipeView.height

            StackView {
                id: playListStack
                anchors.fill: parent

                initialItem: Qt.resolvedUrl("qrc:/pages/PlayListUI.qml")
            }
        }

    }


}
