import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.0
import who_au.presenter 1.0

ApplicationWindow {
    id: root
    visible: false
    Material.theme: Material.Dark
    Material.accent: Material.Blue

    title: qsTr("Main Window")

    Loader {
        id: loader
        anchors.fill: parent
    }

    Presenter {
        id: presenter

        onShowAuthView: {
            root.height = 200; root.width = 400
            loader.setSource("AuthView.qml", { "presenter": presenter })
        }

        onShowAppView: {
            root.height = 550; root.width = 800
            loader.setSource("AppView.qml",  { "presenter": presenter })
        }
    }

    Component.onCompleted: {
        presenter.uiIsReady()
        root.visible = true
    }
}
