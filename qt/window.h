#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include "json_handler.h"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
        Q_OBJECT

    public:
        explicit Window(QWidget *parent = 0, QString port = 0);
        ~Window();

    public slots:
        void connection();
        void bomb();
        void win_team();

    private:
        Ui::Window *ui;
        JSON_handler *s_app;
        QSerialPort *serial;
};

#endif // WINDOW_H
