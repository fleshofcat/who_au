#include "presenter.h"

Presenter::Presenter(QObject *parent)
    : QObject(parent)
{
    app.setUi(this);
}

void Presenter::uiIsReady()
{
    app.start();
}

void Presenter::showAuth()
{
    emit showAuthView();
}

void Presenter::showAuthError(string errMsg)
{
    emit showAuthErr(QString::fromStdString(errMsg));
}

void Presenter::showUserWorkspace()
{
    emit showAppView();
}

void Presenter::showCurrentResult(
        std::map<string, string> loadedFilesInfo)
{
    QCoreApplication::processEvents();
    QVariantMap model;

    int filesToHandleCount = 0;

    for (auto pair : loadedFilesInfo)
    {
        model.insert(QString::fromStdString("file://" + pair.first),
                     QString::fromStdString(pair.second));

        if (pair.second == "")
            filesToHandleCount++;
    }

    if (choosenFilesCount == 0)
        choosenFilesCount = filesToHandleCount;


    QCoreApplication::processEvents();
    emit showImagesInfo(model);
    auto leftToWork = double(filesToHandleCount) / double(choosenFilesCount);
    emit showStatus(1.0 - leftToWork);
    QCoreApplication::processEvents();

    if (filesToHandleCount == 0)
    {
        choosenFilesCount = 0;
    }
}

void Presenter::userNeedAuth(QString email, QString pass)
{
    app.authentication(email.toStdString(), pass.toStdString());
}

void Presenter::userPickedFiles(QList<QUrl> pickedFiles)
{
//    choosenFilesCount = pickedFiles.count();

    std::list<std::string> selectedFiles;

    for (auto url : pickedFiles)
    {
        selectedFiles.push_back(url.toString().toStdString().erase(0, 7));
    }

    app.detectFace(selectedFiles);
}
