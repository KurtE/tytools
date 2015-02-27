/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef SELECTOR_DIALOG_HH
#define SELECTOR_DIALOG_HH

#include <memory>

#include "board_proxy.hh"
#include "ui_selector_dialog.h"

class SelectorDialog : public QDialog, private Ui::SelectorDialog {
    Q_OBJECT

    BoardManagerProxy *manager_;
    std::shared_ptr<BoardProxy> current_board_;

public:
    SelectorDialog(BoardManagerProxy *manager, QWidget *parent = nullptr);

    std::shared_ptr<BoardProxy> currentBoard() const;
    std::shared_ptr<BoardProxy> selectedBoard() const;

    static std::shared_ptr<BoardProxy> getBoard(BoardManagerProxy *manager, QWidget *parent = nullptr);

protected slots:
    void selectionChanged(const QItemSelection &selected, const QItemSelection &previous);
    void done(int result) override;

signals:
    void currentChanged(std::shared_ptr<BoardProxy> board);
    void boardSelected(std::shared_ptr<BoardProxy> board);
};

#endif
