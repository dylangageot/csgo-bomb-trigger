#include "window.h"
#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    QCommandLineParser parser;
    QCommandLineOption o_hide("h", "Hide or not window");
    QCommandLineOption o_port(QStringList() << "p" << "port","Connect to the <port>.","port");
    parser.addOption(o_port);
    parser.addOption(o_hide);
    parser.process(application);
    bool hide = parser.isSet(o_hide);
    QString port = parser.value(o_port);
    Window bomb_trigger(0, port);
    if (hide)
        bomb_trigger.hide();
    else
        bomb_trigger.show();
    return application.exec();
}
