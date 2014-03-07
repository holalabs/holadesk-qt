#ifndef NATIVE_H
#define NATIVE_H

#include <QWebView>
#include <QWebFrame>
#include <QDir>
#include <QApplication>
#include <QMainWindow>

#ifdef Q_WS_X11
    // This is because GLib defines "signals" keyword
    #undef signals
    //#include <libnotify/notify.h>
#endif

#ifdef Q_WS_WIN
    #include <QSystemTrayIcon>
#endif

class Native : public QObject
{
    Q_OBJECT
public:
    Native(QWebPage *webPage);
private:
    QWebPage *webPage;
    #ifdef Q_WS_WIN
        QSystemTrayIcon *tray;
    #endif
private slots:
    void showWindow();
public slots:
    void setNative();
    Q_INVOKABLE void notify(const QString &title, const QString &msg, const QString &icon, int duration);
Q_SIGNALS:

};

#endif // NATIVE_H
