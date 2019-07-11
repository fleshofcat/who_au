import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.0
import who_au.presenter 1.0

ApplicationWindow {
    id: rootWindow
    visible: true
    Material.theme: Material.Dark
    Material.accent: Material.Blue

    title: qsTr("Main Window")

    height: 200
    width: 400

    Loader {
        id: loader
        anchors.fill: parent
    }

    Presenter {
        id: presenter

        onShowAuth: loader.setSource("auth_view.qml", { "presenter": presenter })
        onShowApp: loader.source = "main_view.qml"
    }


    onVisibleChanged: presenter.uiIsReady()
}
