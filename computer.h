#ifndef COMPUTER_H
#define COMPUTER_H

#include <kio/global.h>
#include <kio/workerbase.h>

// Qt stuff
#include <QObject>

/*
 *   This class implements the computer KIO slave
 */
class Computer : public QObject, public KIO::WorkerBase {
    Q_OBJECT

public:
    Computer(const QByteArray &pool, const QByteArray &app);
    ~Computer() override;
    KIO::WorkerResult get(const QUrl &url) override;
    KIO::WorkerResult stat(const QUrl &url) override;
    KIO::WorkerResult listDir(const QUrl &url) override;
};

#endif

