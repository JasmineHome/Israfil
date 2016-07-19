//import QtQuick 2.0
import QtQuick 2.6
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.0

Item {
    property var delegateComponentMap: {
        "ItemDelegate": itemDelegateComponent,
                "RadioDelegate": radioDelegateComponent,
    }

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
            text: "这里有您登陆后的所有歌单"
        }

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            model: ListModel {

                ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "Universal" }
                ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "Universal" }
                ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "Universal" }
                ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "Universal" }
                ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "网易云音乐" }
                ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "网易云音乐" }
                ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "网易云音乐" }
                ListElement { type: "RadioDelegate"; text: "RadioDelegate"; spec: "网易云音乐" }

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
                sourceComponent: delegateComponentMap[text]

                property string labelText: text
                property ListView view: listView
                property int ourIndex: index
            }
        }
    }

}
