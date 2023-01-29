#include "utils.h"

void SetStyleSheet(QWidget* widget, QString fileDir) {
    QFile file = QFile(fileDir);
    file.open(QIODevice::ReadOnly);
    widget->setStyleSheet(file.readAll());
}

void LoadPixmap(QLabel* label, QPixmap pixmap) {
    pixmap.scaled(label->size(), Qt::KeepAspectRatio);
    label->setScaledContents(true);
    label->setPixmap(pixmap);
}

void SetKeepAlive(QTcpSocket* socket) {
    socket->setSocketOption(QAbstractSocket::KeepAliveOption, 3000);
    int fd = socket->socketDescriptor();
    int keepAlive = 1;                          // Start "keep alive" mode
    int keepIdle = 5;                           // Time idle without alive heartbeat package
    int keepInterval = 2;                       // Time interval for detecting packages
    int keepCount = 2;                          // Detecting the trial number
    setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, (void *)&keepAlive, sizeof(keepAlive));
    setsockopt(fd, IPPROTO_TCP, TCP_KEEPALIVE, (void *)&keepIdle, sizeof(keepIdle));
    setsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL, (void *)&keepInterval, sizeof(keepInterval));
    setsockopt(fd, IPPROTO_TCP, TCP_KEEPCNT, (void *)&keepCount, sizeof(keepCount));
}
