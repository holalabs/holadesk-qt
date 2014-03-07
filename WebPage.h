#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <QWebPage>
#include <QWebFrame>
#include <QDesktopServices>
#include <QNetworkRequest>
#include "cookiejar.h"
#include "Native.h"

class WebPage : public QWebPage
{
public:
    explicit WebPage(QObject *parent = 0);
    QUrl tempUrl;
private:
    CookieJar *cookieJar;
    Native *native;
protected:
    bool acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest
&request, NavigationType type);
};

#endif // WEBPAGE_H
