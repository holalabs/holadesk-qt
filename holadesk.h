#ifndef HOLADESK_H
#define HOLADESK_H

#include <QMainWindow>
#include <QWebFrame>
#include <QDesktopServices>
#include <QSettings>
#include <QFileInfo>
#include "WebView.h"

namespace Ui {
    class Holadesk;
}

class HolaDesk : public QMainWindow
{
    Q_OBJECT

public:
    explicit HolaDesk(QWidget *parent = 0);
    ~HolaDesk();

private:
    Ui::Holadesk *ui;
};

#endif // HOLADESK_H
