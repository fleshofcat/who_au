import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Item {
    id: root

    anchors.fill: parent

    property alias source: image.source
    property alias faceReport: faceReport.text

    Image {
        id: image
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit

        onSourceChanged: canvas.requestPaint()
        onWidthChanged: canvas.requestPaint()
        onHeightChanged: canvas.requestPaint()
    }

    Canvas {
        id: canvas
//        anchors.fill: image
//        anchors.top: image.top
//        anchors.bottom: image.bottom
//        anchors.right: image.right
//        anchors.left: image.left

        anchors.centerIn: image
        width: image.paintedWidth
        height: image.paintedHeight

        onPaint: {
            var ctx = getContext("2d");
            ctx.reset();

            if (faceReport.text !== "")
            {
                var fullReport = JSON.parse(faceReport.text)

                fullReport.data.
                forEach(function(report) {
                    signFace(report)
                });
            }
        }
    }

    function signFace(signData)
    {
        var ctx = canvas.getContext("2d");
        ctx.lineWidth = 5
        ctx.strokeStyle = "#00264d"

        ctx.beginPath();
        ctx.moveTo(getRelX(signData.bbox.x), getRelY(signData.bbox.y))

        ctx.lineTo(getRelX(signData.bbox.x + signData.bbox.width), getRelY(signData.bbox.y))
        ctx.lineTo(getRelX(signData.bbox.x + signData.bbox.width), getRelY(signData.bbox.y + signData.bbox.height))
        ctx.lineTo(getRelX(signData.bbox.x), getRelY(signData.bbox.y + signData.bbox.height))
        ctx.lineTo(getRelX(signData.bbox.x), getRelY(signData.bbox.y))

        ctx.stroke();
    }

    function getRelX(x)
    {
        return (x * image.paintedWidth) / image.sourceSize.width
    }
    function getRelY(y)
    {
        return (y * image.paintedHeight) / image.sourceSize.height
    }

    Text {
        id: faceReport
        visible: false
    }
}




















