import QtQuick 2.3
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Page {
    id: authView

    Connections{
        target: presenter
        onShowAuthErr: errLabel.text = authErrMsg
    }

    GridLayout {
        columns: 2
        anchors.centerIn: parent


        Text {
            id: errLabel
            color: "white"

            Layout.columnSpan: 2
            Layout.leftMargin: 10
        }

        Text {
            text: qsTr("Enter your email")
            color: "white"
        }

        TextField {
            id: emailField
            Layout.fillHeight: true
            Layout.preferredWidth: 200
        }

        Text {
            text: qsTr("Enter your password")
            color: "white"
        }

        TextField {
            id: passwordField
            Layout.preferredWidth: 200
            onAccepted: sendAuthData()
        }

        Button {
            id: nextButton
            text: qsTr("Continue")


            Layout.column: 1
            Layout.row: 3
            Layout.alignment: Qt.AlignRight

            onPressed: sendAuthData()

        }
    }

    function sendAuthData() {
        if (emailField.text !== "" && passwordField.text !== ""){
            presenter.userNeedAuth(emailField.text, passwordField.text)
        } else {
            errLabel.text = "please enter both fields"
        }
    }
}
