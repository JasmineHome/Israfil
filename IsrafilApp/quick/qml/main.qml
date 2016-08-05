import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import Qt.labs.settings 1.0

import IsrafilCore 1.0
import "scripts/const.js" as CONST

ApplicationWindow {
    id: mainwindow
    width: 720
    height: 480
    visible: true
    title: "Israfil"
    property int bottomHeight: 60
    function dp(a) {return a;}

    property int isrpProgress: isrp.progress
    property int isrpDuration: isrp.duration
    property int isrpMinute: isrp.minute
    property int isrpSecond: isrp.second

    Settings {
        id: settings
        property string style: "Universal"
    }

    header: ToolBar {
        Material.foreground: "white"
        Material.primary: "#03A9F4"
        Material.accent: "#4CAF50"

        RowLayout {
            spacing: 20
            anchors.fill: parent

            ToolButton {
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "qrc:/images/drawer.png"
                }
                onClicked: drawer.open()
            }

            Label {
                id: titleLabel
                text: "Project Israfil"
                font.pixelSize: 20
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }

            ToolButton {
                contentItem: Image {
                    fillMode: Image.Pad
                    horizontalAlignment: Image.AlignHCenter
                    verticalAlignment: Image.AlignVCenter
                    source: "qrc:/images/menu.png"
                }
                onClicked: optionsMenu.open()

                Menu {
                    id: optionsMenu
                    x: parent.width - width
                    transformOrigin: Menu.TopRight

                    MenuItem {
                        text: "Settings"
                        onTriggered: {
                            titleLabel.text = "Settings"
                            listView.currentIndex = listView.count -1
                            stackView.replace("qrc:/pages/SettingsUI.qml")
                        }
                    }

                    MenuItem {
                        text: "Style"
                        onTriggered: stylesPopup.open()
                    }
                    MenuItem {
                        text: "About"
                        onTriggered: aboutDialog.open()
                    }
                }
            }
        }
    }

    Drawer {
        id: drawer
        width: Math.min(mainwindow.width, mainwindow.height) / 3 * 2
        height: mainwindow.height// - bottomHeight ///fix for bottom

        ListView {
            id: listView
            currentIndex: -1
            anchors.fill: parent

            delegate: ItemDelegate {
                width: parent.width
                text: model.title
                highlighted: ListView.isCurrentItem
                onClicked: {
                    if (listView.currentIndex != index) {
                        listView.currentIndex = index
                        titleLabel.text = model.title
                        stackView.replace(model.source)
                    }
                    drawer.close()
                }
            }

            model: ListModel {
                ListElement { title: "Israfil Main"; source: "qrc:/pages/TabBar.qml" }
                ListElement { title: "Downloads"; source: "qrc:/pages/DownloadsUI.qml"}
                ListElement { title: "Settings"; source: "qrc:/pages/SettingsUI.qml"}
            }

            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }
    StackView {
        id: stackView
        anchors.fill: parent
        //anchors.bottomMargin: bottomHeight

        initialItem: Pane {
            id: pane

            Image {
                id: logo
                width: pane.availableWidth / 2
                height: pane.availableHeight / 2
                anchors.centerIn: parent
                anchors.verticalCenterOffset: -50
                fillMode: Image.PreserveAspectFit
                source: "qrc:/images/qt-logo.png"
            }

            Label {
                text: "Hi, you are using the demo version of Project Israfil and thus there maybe some bugs"
                anchors.margins: 20
                anchors.top: logo.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: arrow.top
                horizontalAlignment: Label.AlignHCenter
                verticalAlignment: Label.AlignVCenter
                wrapMode: Label.Wrap
            }

            Image {
                id: arrow
                source: "qrc:/images/arrow.png"
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        drawer.open();
                    }
                }
            }
        }
    }

    Popup {
        id: stylesPopup
        x: (mainwindow.width - width) / 2
        y: mainwindow.height / 6
        width: Math.min(mainwindow.width, mainwindow.height) / 3 * 2
        height: settingsColumn.implicitHeight + topPadding + bottomPadding
        modal: true
        focus: true
        contentItem:
            ColumnLayout {
            id: settingsColumn
            spacing: 20

            Label {
                text: "Styles"
                font.bold: true
            }

            RowLayout {
                spacing: 10

                Label {
                    text: "Theme:"
                }

                ComboBox {
                    id: styleBox
                    property int styleIndex: -1
                    model: ["Default", "Material", "Universal"]
                    Component.onCompleted: {
                        styleIndex = find(settings.style, Qt.MatchFixedString)
                        if (styleIndex !== -1)
                            currentIndex = styleIndex
                    }
                    Layout.fillWidth: true
                }
            }

            Label {
                text: "Restart required"
                color: "#e41e25"
                opacity: styleBox.currentIndex !== styleBox.styleIndex ? 1.0 : 0.0
                horizontalAlignment: Label.AlignHCenter
                verticalAlignment: Label.AlignVCenter
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            RowLayout {
                spacing: 10

                Button {
                    id: okButton
                    text: "Ok"
                    onClicked: {
                        settings.style = styleBox.displayText
                        stylesPopup.close()
                    }

                    Material.foreground: Material.primary
                    Material.background: "transparent"
                    Material.elevation: 0

                    Layout.preferredWidth: 0
                    Layout.fillWidth: true
                }

                Button {
                    id: cancelButton
                    text: "Cancel"
                    onClicked: {
                        styleBox.currentIndex = styleBox.styleIndex
                        stylesPopup.close()
                    }

                    Material.background: "transparent"
                    Material.elevation: 0

                    Layout.preferredWidth: 0
                    Layout.fillWidth: true
                }
            }
        }

    }

    Popup {
        id: aboutDialog
        modal: true
        focus: true
        x: (mainwindow.width - width) / 2
        y: mainwindow.height / 6
        width: Math.min(mainwindow.width, mainwindow.height) / 3 * 2
        contentHeight: aboutColumn.height

        Column {
            id: aboutColumn
            spacing: 20

            Label {
                text: "About Israfil"
                font.bold: true
            }

            Label {
                width: aboutDialog.availableWidth
                text: CONST.ABOUT_TEXT_1
                wrapMode: Label.Wrap
                font.pixelSize: 12
            }

            Label {
                width: aboutDialog.availableWidth
                text: CONST.ABOUT_TEXT_2
                wrapMode: Label.Wrap
                font.pixelSize: 12
            }
        }
    }
    footer: ToolBar {
        Material.foreground: "#424242"
        Material.primary: "white"
        Material.accent: "#4CAF50"
        height: bottomHeight -10
        Label {
            id: songPlaying
            text: "没有正在播放的歌曲"
            //anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            height:dp(bottomHeight - 40) //40
            anchors.left: sliderProgress.left
            width:dp(100)
        }

        Slider {
            id: sliderProgress
            width: parent.width - dp(50)

            anchors.horizontalCenter: parent.horizontalCenter
            //height:30
            value: isrpProgress
            from: 0
            to: isrpDuration
            //maximumValue: isrpDuration
            //minimumValue: 0
            anchors.rightMargin: dp(50)
            anchors.leftMargin:dp(50)
            //anchors.bottom: songPlaying.top
            anchors.bottom: songPlaying.top//Margin:dp(290)
            anchors.bottomMargin: -5

        }

        Image {
            id: previousArrow
            source: "qrc:/images/av_skip_previous.svg"
            height: 30
            anchors.right: playArrow.left
            anchors.bottom: parent.bottom
            width: 70
            fillMode: Image.PreserveAspectFit
            Button {
                id: previousButton
                text: ""
                onClicked: {
                    isrp.mediaPrevious()
                }
                anchors.fill: parent
                Material.background: "transparent"
                Material.elevation: 1
                Universal.background: "transparent"

                //Layout.preferredWidth: 0
                //Layout.fillWidth: true
            }
        }

        Image {
            id: playArrow
            source: "qrc:/images/av_play_arrow.svg"
            height: 30
            //anchors.left: previousArrow.right
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            width: 70
            fillMode: Image.PreserveAspectFit
            Button {
                id: playButton
                text: ""
                onClicked: {
                    if (isrp.state === 1){
                        isrp.mediaPause();
                        playArrow.source = "qrc:/images/av_play_arrow.svg"
                    } else {
                        isrp.mediaPlay();
                        playArrow.source = "qrc:/images/av_pause.svg"
                    }
                }
                anchors.fill: parent
                Material.background: "transparent"
                Material.elevation: 1
                Universal.background: "transparent"


                //Layout.preferredWidth: 0
                //Layout.fillWidth: true
            }
        }

        Image {
            id: nextArrow
            source: "qrc:/images/av_skip_next.svg"
            height: 30
            anchors.left: playArrow.right
            anchors.bottom: parent.bottom
            width: 70
            fillMode: Image.PreserveAspectFit
            Button {
                id: nextButton
                text: ""
                onClicked: {
                    isrp.mediaNext()
                }
                anchors.fill: parent
                Material.background: "transparent"
                Material.elevation: 1
                Universal.background: "transparent"


                //Layout.preferredWidth: 0
                //Layout.fillWidth: true
            }
        }
    }

}
