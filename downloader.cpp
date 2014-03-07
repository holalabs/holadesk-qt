#include "downloader.h"

DownloadManager::DownloadManager()
{
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
            SLOT(downloadFinished(QNetworkReply*)));
}

void DownloadManager::doDownload(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);
    currentDownloads.append(reply);
}

QString DownloadManager::saveFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QDesktopServices::storageLocation(QDesktopServices::TempLocation) + "/" + QFileInfo(path).fileName();
    if (basename.isEmpty())
        basename = "download";
    if (QFile::exists(basename)) {
        // already exists, don't overwrite
        int i = 0;
        basename += '.';
        while (QFile::exists(basename + QString::number(i)))
            ++i;

        basename += QString::number(i);
    }
    return basename;
}

bool DownloadManager::saveToDisk(const QString &filename, QIODevice *data)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly))
        return false;
    file.write(data->readAll());
    file.close();
    return true;
}

void DownloadManager::downloadFinished(QNetworkReply *reply)
{
    QUrl url = reply->url();
    QString id = QFileInfo(url.path()).baseName();
    qDebug(id.toAscii());
    if (reply->error()) {
        emit downloaded(id, true);
    } else {
        QString filename = saveFileName(url);
        if (saveToDisk(filename, reply))
            emit downloaded(id, false);
    }
    currentDownloads.removeAll(reply);
    reply->deleteLater();
}
