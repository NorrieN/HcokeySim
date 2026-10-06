#include <list>
#include <QApplication>
#include <QLabel>
#include <iostream>
#include "player.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    player suzuki("Nick Suzkuki", 14);

    QString text = QString::fromStdString(suzuki.getName())
                   + " #" + QString::number(suzuki.getNumber());

    QLabel label(text);
    label.resize(250, 80);
    label.setAlignment(Qt::AlignCenter);
    label.show();

    return app.exec();
}
