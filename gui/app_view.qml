import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls 2.5
import QtQuick 2.5
import QtQuick.Dialogs 1.2

Item {
    id: appView

    Connections{
        target: presenter
        onShowImagesInfo: {

            photoMenuModel.clear()

            for (var imageData in imagesInfo)
            {
                var imageIsDone = imagesInfo[imageData] === "" ? false : true
                photoMenuModel.append(
                            {"photoName": imageData.replace(/^.*(\\|\/|\:)/, ''),
                                "imagePath": imageData,
                                "reportText": imagesInfo[imageData],
                                "isPhotoHandled": imageIsDone})
            }
        }

        onShowStatus: {
             progressBar.value = percentage
        }
    }

    SplitView {
        id: splitView
        anchors.fill: parent

        Item {
            id: sideBarRect

            z: 1

            width: 150
            Layout.minimumWidth: 7

            ListView {
                id: listView

                anchors.fill: parent

                spacing: 30
                header: Item { height: 65 }

                highlightFollowsCurrentItem: false
                highlightMoveDuration: 100

                delegate: Button {
                    id: photoButton

                    height: imageItem.height + 40

                    anchors.right: parent.right
                    anchors.left: parent.left
                    anchors.margins: 20

                    Image {
                        id: imageItem
                        source: imagePath
                        fillMode: Image.PreserveAspectFit
                        anchors.top: parent.top
                        anchors.right: parent.right
                        anchors.left: parent.left

                        anchors.topMargin: 7
                        anchors.margins: 1
                    }

                    Text {
                        id: photoNameLabel
                        text: photoName

                        color: "#ddd"
                        font.bold: true

                        anchors {
                            top: imageItem.bottom
                            bottom: parent.bottom
                            left: parent.left
                            right: parent.right
                        }

                        anchors.topMargin: -10
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter

                    }

                    Text {
                        id: reportLabel
                        text: reportText
                        visible: false
                    }

                    BusyIndicator {
                        id: busyIndicatro

                        anchors.fill: parent

                        running: !isPhotoHandled
                    }

                    onClicked: {
                        listView.highlightFollowsCurrentItem = true
                        listView.currentIndex = index

                        faceDetector.faceReport = reportLabel.text
                        faceDetector.source = imageItem.source
                    }
                }

                model: ListModel {
                    id: photoMenuModel
                }


                highlight: Rectangle {
                    anchors.right: parent.right
                    anchors.left: parent.left
                    color: "#809170ff"
                }
            }

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

                        Rectangle {
                            color: "#555"
                            opacity: 0.5
                            anchors.fill: parent
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

            DetectedFaceViewer {
                id: faceDetector
            }

            ProgressBar {
                id: progressBar

                from: 0.1
                to: 1.0

                width: 10
                anchors {
                    top: parent.top
                    right: parent.right
                    left: parent.left
                }
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
            fileDialog.setVisible(false)
            presenter.userPickedFiles(fileDialog.fileUrls)
        }
        onRejected: { }
    }
}



























