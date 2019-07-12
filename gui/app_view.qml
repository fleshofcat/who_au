import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls 2.5
import QtQuick 2.3
import QtQuick.Dialogs 1.2

Page {
    id: appView

    Connections{
        target: presenter
        onShowImagesInfo: { // imagesInfo
            // TODO to load images from input with additional info

            photoMenuModel.clear()

            for (var imageData in imagesInfo)
            {
//                console.log("Object item:", imageData,
//                            "=", imagesInfo[imageData])


            }

        }
    }

    SplitView {
        id: splitView
        anchors.fill: parent

        Item {
            id: sideBarRect

            width: 150
            Layout.minimumWidth: 7

            ProgressBar {
                id: progressBar

                width: 10

                anchors {
                    top: parent.top
                    right: parent.right
                    bottom: parent.bottom
                }
            }


            ListView {
                id: listView

//                anchors.fill: parent
                anchors {
                    top: parent.top
                    bottom: parent.bottom
                    left: parent.left
                    right: progressBar.left
                }


                spacing: 30
                header: Item { height: 65 }

                delegate: Button {
                    id: photoButton

                    height: width * 0.6

                    anchors.right: parent.right
                    anchors.left: parent.left

                    anchors.margins: 20

                    Image {
                        id: imageItem
                        anchors.fill: parent
                        source: imagePath
                    }

                    Text {
                        text: photoName

                        color: "#ddd"
                        font.bold: true

                        anchors.top: imageItem.bottom
                        anchors.horizontalCenter: imageItem.horizontalCenter
                        anchors.topMargin: 7

                    }
                }
                model: ListModel {
                    id: photoMenuModel

                    ListElement {
                        photoName: "the face on top"
                        imagePath: "res/face.jpg"
                    }
                    ListElement {
                        photoName: "the people"
                        imagePath: "res/people.jpg"
                    }
                    ListElement {
                        photoName: "the face"
                        imagePath: "res/face.jpg"
                    }
                    ListElement {
                        photoName: "the people"
                        imagePath: "res/people.jpg"
                    }
                    ListElement {
                        photoName: "the face"
                        imagePath: "res/face.jpg"
                    }
                    ListElement {
                        photoName: "the people"
                        imagePath: "res/people.jpg"
                    }
                    ListElement {
                        photoName: "the face"
                        imagePath: "res/face.jpg"
                    }
                    ListElement {
                        photoName: "the people"
                        imagePath: "res/people.jpg"
                    }
                }}

            Rectangle {
                id: sideBarHeader

                color: "#333"
                opacity: 0.8

                width: parent.width
                height: 65

                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter

                Text {
                    id: photoMenuTitle
                    text: qsTr("Photo menu")

                    color: "white"
                    font.bold: true
                    font.pointSize: 14

                    anchors.top: parent.top
                    anchors.topMargin: 4
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Row {
                    id: sideBarButtons
                    anchors.top: photoMenuTitle.bottom
                    anchors.left: parent.left
                    anchors.topMargin: 3
                    anchors.leftMargin: 3

                    Button {
                        id: uploadButon
                        height: 35
                        width: 30

                        background: Rectangle {
                            color: "#555"
                            opacity: 0.5
                        }

                        Image {
                            source: "res/upload_icon.png"

                            anchors.fill: parent

                            anchors.bottomMargin: 8
                            anchors.topMargin: 8
                            anchors.leftMargin: 4
                            anchors.rightMargin: 4
                        }

                        onClicked: {
                            fileDialog.open()
                        }
                    }
                }
            }
        }
        Item {
            id: centerItem
            Layout.minimumWidth: 50
            Layout.fillWidth: true

            Text {
                text: "View 2"
                anchors.centerIn: parent
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a jpeg image" // TODO jpeg

        folder: shortcuts.home
        selectMultiple: true
        nameFilters: [ "Image files (*.jpg)" ]

        onAccepted: {
            presenter.userPickedFiles(fileDialog.fileUrls)
            console.log(fileDialog.fileUrls)
        }
        onRejected: { }
    }
}



























