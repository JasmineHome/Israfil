import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import Qt.labs.settings 1.0

import IsrafilCore 1.0

ApplicationWindow {
    id: mainwindow
    width: 720
    height: 480
    visible: true
    title: "Israfil"
    property int bottomHeight: 80
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
                        onTriggered: settingsPopup.open()
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
            }

            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }
    StackView {
        id: stackView
        anchors.fill: parent
        anchors.bottomMargin: bottomHeight

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
            /*
            Image {
                id: arrowtest
                source: "qrc:/images/arrow.png"
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.bottom: parent.bottom
                Button {
                    id: testButton
                    text: ""
                    onClicked: {
                        styleBox.currentIndex = styleBox.styleIndex
                        settingsPopup.close()
                    }
                    anchors.fill: parent
                    Material.background: "transparent"
                    Material.elevation: 1

                    //Layout.preferredWidth: 0
                    //Layout.fillWidth: true
                }
            }
            */
        }
    }

    Popup {
        id: settingsPopup
        x: (mainwindow.width - width) / 2
        y: mainwindow.height / 6
        width: Math.min(mainwindow.width, mainwindow.height) / 3 * 2
        height: settingsColumn.implicitHeight + topPadding + bottomPadding
        modal: true
        focus: true

        contentItem: ColumnLayout {
            id: settingsColumn
            spacing: 20

            Label {
                text: "Settings"
                font.bold: true
            }

            RowLayout {
                spacing: 10

                Label {
                    text: "Style:"
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
                        settingsPopup.close()
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
                        settingsPopup.close()
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
                text: "About"
                font.bold: true
            }

            Label {
                width: aboutDialog.availableWidth
                text: "From QtQuick Demo: The Qt Quick Controls 2 module delivers the next generation user interface controls based on Qt Quick."
                wrapMode: Label.Wrap
                font.pixelSize: 12
            }

            Label {
                width: aboutDialog.availableWidth
                text: "In comparison to the desktop-oriented Qt Quick Controls 1, Qt Quick Controls 2 "
                    + "are an order of magnitude simpler, lighter and faster, and are primarily targeted "
                    + "towards embedded and mobile platforms."
                wrapMode: Label.Wrap
                font.pixelSize: 12
            }
        }
    }

    Rectangle {
        id: rectControls
        color:'#fff'
        z: 1
        height:dp(bottomHeight)
        width:parent.width
        anchors.bottom: parent.bottom
        //border.width:  dp(1)
        //border.color: Theme.alpha("#aaa", 0.26)

        Rectangle {
            color:'#fff'
            height:dp(bottomHeight -30) //50
        }

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
            height:50
            value: isrpProgress
            from: 0
            to: isrpDuration
            //maximumValue: isrpDuration
            //minimumValue: 0
            anchors.rightMargin: dp(50)
            anchors.leftMargin:dp(50)
            anchors.bottomMargin:dp(190)

            onValueChanged: {
                isrp.progress = value
            }
        }
    }
    Rectangle {
        z:1
        anchors.bottomMargin: dp(0)
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        height:dp(bottomHeight - 40) //40
        width:dp(210)

        Image {
            id: previousArrow
            source: "qrc:/images/av_skip_previous.svg"
            height: 35
            anchors.left: parent.left
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

                //Layout.preferredWidth: 0
                //Layout.fillWidth: true
            }
        }

        Image {
            id: playArrow
            source: "qrc:/images/av_play_arrow.svg"
            height: 35
            anchors.left: previousArrow.right
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

                //Layout.preferredWidth: 0
                //Layout.fillWidth: true
            }
        }

        Image {
            id: nextArrow
            source: "qrc:/images/av_skip_next.svg"
            height: 35
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

                //Layout.preferredWidth: 0
                //Layout.fillWidth: true
            }
        }
    }


}
