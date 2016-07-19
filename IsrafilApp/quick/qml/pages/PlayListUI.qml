import QtQuick 2.6
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.0

Item {
    property var delegateComponentMap: {
        "SwipeDelegate": swipeDelegateComponent,
    }


    Component {
        id: swipeDelegateComponent

        SwipeDelegate {
            id: swipeDelegate
            text: labelText
            width: parent.width

            onClicked: if (swipe.complete) view.model.remove(ourIndex)

            Component {
                id: removeComponent

                Rectangle {
                    color: swipeDelegate.swipe.complete && swipeDelegate.pressed ? "#333" : "#444"
                    width: parent.width
                    height: parent.height
                    clip: true

                    Label {
                        font.pixelSize: swipeDelegate.font.pixelSize
                        text: "Remove"
                        color: "white"
                        anchors.centerIn: parent
                    }
                }
            }

            swipe.left: removeComponent
            swipe.right: removeComponent
        }
    }

    ColumnLayout {
        id: column
        spacing: 40
        anchors.fill: parent
        anchors.topMargin: 20

        Label {
            Layout.fillWidth: true
            wrapMode: Label.Wrap
            horizontalAlignment: Qt.AlignHCenter
            text: "当前播放列表，向左滑动删除制定歌曲"
        }

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            model: ListModel {
                ListElement { type: "SwipeDelegate"; text: "Some Song" }
                ListElement { type: "SwipeDelegate"; text: "Some Song" }
                ListElement { type: "SwipeDelegate"; text: "Some Song" }
                ListElement { type: "SwipeDelegate"; text: "asd" }
                ListElement { type: "SwipeDelegate"; text: "Some Song" }
                ListElement { type: "SwipeDelegate"; text: "Some Song" }
            }


            delegate: Loader {
                id: delegateLoader
                width: listView.width
                sourceComponent: delegateComponentMap[type]

                property string labelText: text
                property ListView view: listView
                property int ourIndex: index

                ListView.onRemove: SequentialAnimation {
                    PropertyAction {
                        target: delegateLoader
                        property: "ListView.delayRemove"
                        value: true
                    }
                    NumberAnimation {
                        target: item
                        property: "height"
                        to: 0
                        easing.type: Easing.InOutQuad
                    }
                    PropertyAction {
                        target: delegateLoader
                        property: "ListView.delayRemove"
                        value: false
                    }
                }
            }
        }
    }
}
