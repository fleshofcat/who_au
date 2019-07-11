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

void Presenter::requireAuth()
{
    emit showAuth();
}

void Presenter::errWhenAuth(string authErrMsg)
{
    emit showAuthErr(QString::fromStdString(authErrMsg));
}

void Presenter::requireUserWork()
{
    emit showApp();
}

void Presenter::userNeedAuth(QString email, QString pass)
{
    app.authentication(email.toStdString(), pass.toStdString());
}
