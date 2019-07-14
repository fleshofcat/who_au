#pragma once

#include <QUrl>
#include <QObject>
#include <QVariantMap>

#include <QCoreApplication>

#include <who_au.h>
#include <string>

class Presenter : public QObject, IUserInterface
{
    Q_OBJECT

    Q_PROPERTY(NOTIFY showAuthView)
    Q_PROPERTY(NOTIFY showAuthErr)
    Q_PROPERTY(NOTIFY showAppView)
    Q_PROPERTY(NOTIFY showImagesInfo)
    Q_PROPERTY(NOTIFY showStatus)

    WhoAU app;

    int choosenFilesCount = 0;

public:
    explicit Presenter(QObject *parent = nullptr);


    void showAuth() override;
    void showAuthError(std::string errMsg) override;
    void showUserWorkspace() override;
    void showCurrentResult(
            std::map<std::string,   // file name
            std::string>            // json report
            loadedFilesInfo) override;

signals:
    Q_INVOKABLE void showAuthView();
    Q_INVOKABLE void showAuthErr(QString errMsg);
    Q_INVOKABLE void showAppView();
    Q_INVOKABLE void showImagesInfo(QVariantMap imagesInfo);
    Q_INVOKABLE void showStatus(double percentage);

public slots:
    Q_INVOKABLE void uiIsReady();
    Q_INVOKABLE void userNeedAuth(QString email, QString pass);
    Q_INVOKABLE void userPickedFiles(QList<QUrl> pickedFiles);

};











