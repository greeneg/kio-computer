#include "computer.h"

#include <QCoreApplication>
#include <QDebug>

class KIOPluginForMetaData : public QObject
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.kde.kio.worker.computer" FILE "computer.json")
};

extern "C" {
    Q_DECL_EXPORT int kdemain(int argc, char **argv) {
        qDebug() << "Launching Computer IO Worker";
        QCoreApplication app(argc, argv);
        app.setApplicationName("kio_computer");

        Computer worker(argv[2], argv[3]);
        worker.dispatchLoop();
        return 0;
    }
}

KIO::WorkerResult Computer::get(const QUrl &url) {
    qDebug() << "Entering GET function";
    qDebug() << "Leaving GET function";

    return KIO::WorkerResult::pass();
}

KIO::WorkerResult Computer::listDir(const QUrl &url) {
    return KIO::WorkerResult::pass();
}

KIO::WorkerResult Computer::stat(const QUrl &url) {
    return KIO::WorkerResult::pass();
}

Computer::~Computer() {}

Computer::Computer(const QByteArray& pool, const QByteArray& app) :
    WorkerBase("computer", pool, app) {}

#include "computer.moc"
