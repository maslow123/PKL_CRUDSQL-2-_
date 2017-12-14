#ifndef HEADER_H
#define HEADER_H

#include <QString>
#include <QStringList>

#include "client.h"

class redis
{
public:
    redis();

    QStringList reqRedis(QString command, QString address, int port);
    Client client;
};

#endif HEADER_H
