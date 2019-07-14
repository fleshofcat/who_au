import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Flickable {
    id: root

    clip: true // mayby to rm

    anchors.fill: parent

    property alias source: image.source
    property alias faceReport: faceReport.text

    onWidthChanged: canvas.requestPaint()

    onHeightChanged: canvas.requestPaint()
    onSourceChanged: {

//        root.contentHeight = image.sourceSize.height
//        root.contentWidth = image.sourceSize.width

        canvas.requestPaint()
    }

    Image {
        id: image

        anchors.centerIn: parent
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        antialiasing: true

        onHeightChanged: root.contentHeight = height
        onWidthChanged: root.contentWidth = width
    }

    PinchArea {
        anchors.fill: parent
//        pinch.target: image

        pinch.minimumScale: 0.1
        pinch.maximumScale: 10
        pinch.dragAxis: Pinch.XAndYAxis

        MouseArea {
            anchors.fill: parent
//            drag.target: image
            onWheel: {
                image.anchors.fill = undefined

                if (wheel.angleDelta.y > 0)
                {
                    image.height *= 1.2
                    image.width *= 1.2
                }
                else
                {
                    image.height /= 1.2
                    image.width /= 1.2
                }
            }

            onPressAndHold: {

            }
        }

    }

    Canvas {
        id: canvas
        //        anchors.fill: image
        anchors.centerIn: image
        width: image.paintedWidth
        height: image.paintedHeight

        onScaleChanged: requestPaint()

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

    function signFace(signData) {
        var ctx = canvas.getContext("2d");

        ctx.lineWidth = 3
        //        ctx.lineWidth = 3 / canvas.scale
        //        console.log(ctx.lineWidth)
        //        console.log(canvas.scale)

        ctx.strokeStyle = "black" //"#00264d"

        ctx.beginPath();
        ctx.moveTo(getRelX(signData.bbox.x), getRelY(signData.bbox.y))

        ctx.lineTo(getRelX(signData.bbox.x + signData.bbox.width), getRelY(signData.bbox.y))
        ctx.lineTo(getRelX(signData.bbox.x + signData.bbox.width), getRelY(signData.bbox.y + signData.bbox.height))
        ctx.lineTo(getRelX(signData.bbox.x), getRelY(signData.bbox.y + signData.bbox.height))
        ctx.lineTo(getRelX(signData.bbox.x), getRelY(signData.bbox.y))

        ctx.stroke();

        ctx.fillStyle = "White";
        ctx.font = "bold 21px sans-serif";
        ctx.fillText(parseFloat(signData.demographics.age.mean.toFixed(0)),
                     getRelX(signData.bbox.x),
                     getRelY(signData.bbox.y) - 5); //
        ctx.fillText(signData.demographics.gender, getRelX(signData.bbox.x), getRelY(signData.bbox.y) - 28);
    }


    /* it scales canvas for image.
    * Get relative x and y from absolute
    */
    function getRelX(x) {
        return (x * image.paintedWidth) / image.sourceSize.width
    }
    function getRelY(y) {
        return (y * image.paintedHeight) / image.sourceSize.height
    }

    Text {
        id: faceReport
        visible: false
    }
}




















