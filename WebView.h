#ifndef WEBVIEW_H
#define WEBVIEW_H
#include <QWebView>
#include "WebPage.h"

class WebView : public QWebView
{
    Q_OBJECT
public:
    explicit WebView(QWidget *parent = 0);
private:
    WebPage *webPage;
protected:
    QWebView *createWindow ( QWebPage::WebWindowType type );
public Q_SLOTS:
    void linkClickedSlot(QUrl);
};
#endif // WEBVIEW_H
