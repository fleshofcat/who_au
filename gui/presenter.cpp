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
    QVariantMap model;

    for (auto pair : loadedFilesInfo)
    {
        model.insert(QString::fromStdString(pair.first),
                     QString::fromStdString(pair.second));
    }

    emit showImagesInfo(model);
}

void Presenter::showDetectionError(string msg)
{
    // TODO
}

void Presenter::userNeedAuth(QString email, QString pass)
{
    app.authentication(email.toStdString(), pass.toStdString());
}

void Presenter::userPickedFiles(QList<QUrl> pickedFiles)
{
    std::list<std::string> selectedFiles;

    for (auto url : pickedFiles)
    {
        selectedFiles.push_back(url.toString().toStdString().erase(0, 7));
    }

    app.detectFace(selectedFiles);
}
