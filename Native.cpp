#include "Native.h"

Native::Native(QWebPage *web)
{
    webPage = web;
    setNative();
    connect(webPage->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(setNative()));

    #ifdef Q_WS_X11
        //notify_init("holadesk");
    #endif

    #ifdef Q_WS_WIN
        // NOTE: This doesn't support custom icons in notifs
        tray = new QSystemTrayIcon(this);
        tray->setIcon(QIcon(":/icon.png"));
        tray->show();
        connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), SLOT(showWindow()));
    #endif
}

void Native::showWindow() {
    QWidget *win = (QWidget *) qApp->topLevelWidgets()[0];
    win->activateWindow();
}

// Add this to the Javascript window object so this can be accessed from web code
void Native::setNative() {
    webPage->mainFrame()->addToJavaScriptWindowObject("Native", this);
}

/*QString On::lang() {
    QString lang = QLocale::system().name().split("_").first();
    if (lang == "C") {
        lang = "en";
    }
    return lang;
}*/

void Native::notify(const QString &title, const QString &msg, const QString &icon, int duration) {
    #ifdef Q_WS_X11
        /*QDir dir(QCoreApplication::applicationDirPath() + "/../desk/");
        NotifyNotification *notif = notify_notification_new(title.toUtf8(), msg.toUtf8(), QString(dir.absolutePath() + "/" + icon).toUtf8());
        notify_notification_set_timeout(notif, duration);
        notify_notification_show(notif, NULL);
        g_object_unref(notif);*/
    #endif

    #ifdef Q_WS_MAC
    #endif

    #ifdef Q_WS_WIN
        tray->showMessage(title, msg, QSystemTrayIcon::Information, 1000);
    #endif
}
