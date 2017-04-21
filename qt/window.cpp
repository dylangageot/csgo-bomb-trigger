#include "configuration.h"
#include "window.h"
#include "ui_window.h"
#include "json_handler.h"
#include <QIODevice>
#include <QtSerialPort/QtSerialPort>
#include <QDate>
#include <QTime>

#define TIME_PRINT "<b>[" + QTime::currentTime().toString("hh:mm:ss") + "]</b> "

Window::Window(QWidget *parent, QString port) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    s_app = new JSON_handler();
    s_app->start();
    serial = new QSerialPort(this);
    serial->setBaudRate(BAUDRATE);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    ui->setupUi(this);
    ui->label->setText("<p align='center'>Disconnected</p>");
    ui->label->setStyleSheet("QLabel { color : red; }");
    ui->console->appendHtml("Visit <a href='https://github.com/naipsys/csgo-bomb-trigger'>https://github.com/naipsys/csgo-bomb-trigger</a> for more information <br>");
    if(port != "") {
        ui->port_name->setText(port);
        connection();
    }
    connect(ui->connect_bp, SIGNAL(clicked()), this, SLOT(connection()));
    connect(s_app, SIGNAL(bomb()), this, SLOT(bomb()));
    connect(s_app, SIGNAL(win_team()), this, SLOT(win_team()));
}

Window::~Window()
{
    delete ui;
    s_app->deleteLater();
    delete serial;
}

void Window::connection() {
    if (serial->isOpen())
        ui->console->appendHtml(TIME_PRINT + "Disconnected from " + serial->portName().toUpper());
    serial->close();
    serial->setPortName(ui->port_name->text());
    if(serial->open(QIODevice::WriteOnly)) {
        ui->console->appendHtml(TIME_PRINT + "Connect to " + ui->port_name->text().toUpper() + ".");
        ui->label->setText("<p align='center'>Connected to " + ui->port_name->text().toUpper() + "</p>");
        ui->label->setStyleSheet("QLabel { color : green; }");
    }
    else {
        if(ui->port_name->text() == "")
            ui->console->appendHtml(TIME_PRINT + "Cannot connect.");
        else
            ui->console->appendHtml(TIME_PRINT + "Cannot connect to " + ui->port_name->text().toUpper() + ".");
        ui->label->setText("<p align='center'>Disconnected</p>");
        ui->label->setStyleSheet("QLabel { color : red; }");
    }
}

void Window::bomb() {
    ui->console->appendHtml(TIME_PRINT + "The bomb has been planted.");
    serial->write(PLANTED_CHAR, 1);
}

void Window::win_team() {
    ui->console->appendHtml(TIME_PRINT + "The match is over.");
    serial->write(WIN_TEAM_CHAR, 1);
}
