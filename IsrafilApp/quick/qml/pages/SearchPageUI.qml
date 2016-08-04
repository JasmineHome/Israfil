import QtQuick 2.6
import QtQuick.Controls 2.0

Item {
    TextField {
        id: searchField
        placeholderText: "输入歌名或歌手"
        width: parent.width*3/4
        //anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        onTextChanged: {

        }
    }

}
