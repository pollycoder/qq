#ifndef UTILS_H
#define UTILS_H

#include "QtCore/qstring.h"
#include <QWidget>
#include <QFile>
#include <QPixmap>
#include <QLabel>

void SetStyleSheet(QWidget* widget, QString fileDir);
void LoadPixmap(QLabel* label, QPixmap pixmap);



#endif // UTILS_H
