#ifndef JSON_HANDLER_H
#define JSON_HANDLER_H

#include <qthread.h>
#include <qobject.h>
#include "crow_all.h"


class JSON_handler : public QThread
{
    Q_OBJECT
    public:
        JSON_handler();
        void run();

    signals:
        void bomb();
        void win_team();

    private:
        crow::SimpleApp *p_app;
};

#endif // JSON_HANDLER_H
