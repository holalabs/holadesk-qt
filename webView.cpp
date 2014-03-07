#include "WebView.h"

WebView::WebView (QWidget *parent) {

    webPage = new WebPage();
    this->setPage(webPage);

    connect(this->page(), SIGNAL(windowCloseRequested()), this, SLOT(close()));
    /*page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    connect(this, SIGNAL(linkClicked(QUrl)), this, SLOT(linkClickedSlot(QUrl)));*/
}

QWebView* WebView::createWindow ( QWebPage::WebWindowType type ) {
    WebView *webview = new WebView();
    // You insert it somehow in another window if necessary
    // or just show it as a standalone window
    webview->show();
    webview->load(webPage->tempUrl);
    return webview;

}

void WebView::linkClickedSlot(QUrl url) {
    QWebView *webview = new QWebView();
    qDebug(url.toString().toAscii());
    webview->load(url);
    webview->show();
    //QDesktopServices::openUrl(url);
}
