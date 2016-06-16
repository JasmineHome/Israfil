import QtQuick 2.4
import QtQuick.Layouts 1.1
import Material 0.2

Item {
    //implicitHeight: column.height
    TextField {
        placeholderText: "Search..."
        floatingLabel: true
        font.pixelSize: dp(32)
        width: parent.width>dp(450)? dp(400): parent.width-dp(50)
        anchors.centerIn: parent
        helperText: "Search Universal Songs here."
        onAccepted: {
            helperText = "Searching ... "
        }
    }

}
