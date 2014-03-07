#include "holadesk.h"
#include "ui_holadesk.h"

HolaDesk::HolaDesk(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Holadesk)
{
    ui->setupUi(this);

    //#ifdef DEBUG
        ui->webView->load(QUrl("../desk/index.html"));
    //#endif
    QSettings *settings = new QSettings(QSettings::IniFormat, QSettings::UserScope, "holalabs", "holadesk");
}

HolaDesk::~HolaDesk()
{
    delete ui;
}
