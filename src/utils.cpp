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
