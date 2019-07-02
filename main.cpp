#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include <cstdlib>
#include <fstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
//#include <curlpp/Exception.hpp>
//#include <curlpp/Infos.hpp>

//using namespace curlpp::options;

int main(int argc, char *argv[])
{
    try
    {
        curlpp::Cleanup cleaner;

        QString fileName = "wiki_1.html";

        std::ofstream file;
        file.open(fileName.toStdString());

        if (!file.is_open())
        {
            qWarning() << "file " << fileName << " doesn't exist";
            return -1;
        }

        file << curlpp::options::Url("https://en.wikipedia.org/wiki/1");

        file.close();

//        request.setOpt<curlpp::options::Url>("https://en.wikipedia.org/wiki/1");

//        request.perform();

//        qDebug() <<
//        std::ostringstream osq;
        curlpp::options::Url(std::string("https://en.wikipedia.org/wiki/1"));

    }
    catch (curlpp::RuntimeError & e)
    {
        qDebug() << e.what();
    }
    catch (curlpp::LogicError & e)
    {
        qDebug() << e.what();
    }

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
