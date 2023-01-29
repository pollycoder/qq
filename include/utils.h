#ifndef UTILS_H
#define UTILS_H

#include "QtCore/qstring.h"
#include <QWidget>
#include <QFile>
#include <QPixmap>
#include <QLabel>
#include <QTcpSocket>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/tcp.h>

void SetStyleSheet(QWidget* widget, QString fileDir);
void LoadPixmap(QLabel* label, QPixmap pixmap);
void SetKeepAlive(QTcpSocket* socket);


#endif // UTILS_H
