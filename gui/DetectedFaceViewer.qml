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

    function signFace(signData) {
        var ctx = canvas.getContext("2d");

        ctx.lineWidth = 3
        ctx.strokeStyle = "black"

        // draw frame
        ctx.beginPath();
        ctx.moveTo(relX(signData.bbox.x), relY(signData.bbox.y))

        ctx.lineTo(relX(signData.bbox.x + signData.bbox.width), relY(signData.bbox.y))
        ctx.lineTo(relX(signData.bbox.x + signData.bbox.width), relY(signData.bbox.y + signData.bbox.height))
        ctx.lineTo(relX(signData.bbox.x), relY(signData.bbox.y + signData.bbox.height))
        ctx.lineTo(relX(signData.bbox.x), relY(signData.bbox.y))

        ctx.stroke();

        // sign gender and age
        var fontSize = 21
        var roundedAge = parseFloat(signData.demographics.age.mean.toFixed(0))
        var shiftFromFrame = -5;

        ctx.fillStyle = "White";
        ctx.font = "bold " + fontSize + "px sans-serif";
        ctx.fillText(roundedAge, relX(signData.bbox.x),
                     relY(signData.bbox.y) + shiftFromFrame);

        ctx.fillText(signData.demographics.gender,
                     relX(signData.bbox.x),
                     relY(signData.bbox.y) - 28);
    }


    /* it scales canvas for image.
    * Get relative x and y from absolute
    */
    function relX(x) {
        return (x * image.paintedWidth) / image.sourceSize.width
    }
    function relY(y) {
        return (y * image.paintedHeight) / image.sourceSize.height
    }

    Text {
        id: faceReport
        visible: false
    }

//    Component.onCompleted: {
//        presenter.userPickedFiles(["file:///home/kat/Test Images Folder/face.jpg",
//                                   "file:///home/kat/Test Images Folder/smiling_woman.jpg",
//                                   "file:///home/kat/Test Images Folder/father daughter.jpg",
//                                   "file:///home/kat/Test Images Folder/mister-n.jpg",
//                                   "file:///home/kat/Test Images Folder/people.jpg"])

//    }
}




















