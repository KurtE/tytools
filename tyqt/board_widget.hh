/*
 * ty, a collection of GUI and command-line tools to manage Teensy devices
 *
 * Distributed under the MIT license (see LICENSE.txt or http://opensource.org/licenses/MIT)
 * Copyright (c) 2015 Niels Martignène <niels.martignene@gmail.com>
 */

#ifndef BOARD_WIDGET_HH
#define BOARD_WIDGET_HH

#include <QItemDelegate>

#include "board.hh"
#include "ui_board_widget.h"

class BoardWidget : public QWidget, private Ui::BoardWidget {
    Q_OBJECT

public:
    BoardWidget(QWidget *parent = nullptr);

    void setIcon(const QPixmap &pixmap) { boardIcon->setPixmap(pixmap); }
    void setModel(const QString &model) { modelLabel->setText(model); }
    void setTag(const QString &tag) { tagLabel->setText(tag); }
    void setStatus(const QString &status) { statusLabel->setText(status); }

    void setProgress(unsigned int progress, unsigned int total);
};

class BoardItemDelegate : public QItemDelegate {
    Q_OBJECT

    Manager *model_;

    mutable BoardWidget widget_;

public:
    BoardItemDelegate(Manager *model)
        : QItemDelegate(model), model_(model) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif
