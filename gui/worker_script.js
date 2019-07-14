WorkerScript.onMessage = function (message) { // TODO delete
//    console.log("qqqqqqq");
    message.presenter.userPickedFiles(message.files)
}



