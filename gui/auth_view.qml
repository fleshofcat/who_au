import QtQuick 2.3
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Page {
    id: authView


    GridLayout {
        columns: 2
        anchors.centerIn: parent


        Text {
            id: errLabel
            color: "white"

            Layout.row: 0
            Layout.columnSpan: 2
            Layout.leftMargin: 10
        }

        Text {
            text: qsTr("Enter your email")
            color: "white"
        }

        TextField {
            id: emailField
//            onAccepted: passwordField.focus = true
        }

        Text {
            text: qsTr("Enter your password")
            color: "white"
        }

        TextField {
            id: passwordField
//            onAccepted:
        }

        Button {
            id: nextButton
            text: qsTr("Continue")


            Layout.column: 1
            Layout.row: 3
            Layout.alignment: Qt.AlignRight

            onPressed: {
                if (emailField.text !== "" && passwordField.text !== ""){
                    presenter.userNeedAuth(emailField.text, passwordField.text)
                } else {
                    errLabel.text = "please enter both fields"
                }
            }

            Connections{
                target: presenter
                onShowAuthErr: errLabel.text = authErrMsg
            }
        }
    }


}
