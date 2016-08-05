import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

Flickable {
    id: flickable

    contentHeight: pane.height
    contentWidth: parent.width
    Pane {
        id: pane
        width: parent.width
        //height: flickable.height * 1.25

        Column {
            id: column
            spacing: 40
            width: parent.width
            GroupBox {
                id: gboxGeneral
                title: "通用"
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
            }

            GroupBox {
                id: gboxServices
                title: "音乐服务"
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                Column {
                    id: columnServices
                    spacing: 40
                    width: parent.width
                    RowLayout {
                        spacing: 40
                        width: parent.width
                        anchors.horizontalCenter: parent.horizontalCenter
                        Label {
                            id: neidLabel
                            text: "网易云音乐ID:  "
                            width: 70
                            height: 20
                        }
                        TextField {
                            id: neidField
                            placeholderText: "如48353"
                            width: parent.width
                            height: 20
                            //anchors.verticalCenter: parent.verticalCenter
                            anchors.left: neidLabel.right
                            onTextChanged: {

                            }
                        }
                    }
                }
            }

        }
    }

    ScrollIndicator.vertical: ScrollIndicator { }
}
