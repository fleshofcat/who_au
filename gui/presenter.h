#pragma once

#include <QObject>
#include <QtDebug>

#include <who_au.h>

class Presenter : public QObject, IUserInterface
{
    Q_OBJECT

    Q_PROPERTY(NOTIFY showAuth)
    Q_PROPERTY(NOTIFY showApp)

    WhoAU app;

public:
    explicit Presenter(QObject *parent = nullptr);


    void requireAuth() override;
    void errWhenAuth(std::string) override;
    void requireUserWork() override;

signals:
    Q_INVOKABLE void showAuth();
    Q_INVOKABLE void showAuthErr(QString authErrMsg);
    Q_INVOKABLE void showApp();

public slots:
    Q_INVOKABLE void uiIsReady();
    Q_INVOKABLE void userNeedAuth(QString email, QString pass);
};











