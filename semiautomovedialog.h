#ifndef SEMIAUTOMOVEDIALOG_H
#define SEMIAUTOMOVEDIALOG_H

#include <QDialog>
#include "subtitles.h"

namespace Ui {
class SemiAutoMoveDialog;
}

class SemiAutoMoveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SemiAutoMoveDialog(QWidget *parent = 0);
    SemiAutoMoveDialog(Subtitles *subs, QWidget *parent = 0);
    ~SemiAutoMoveDialog();
    int exec();

public slots:
    bool doMoveStretch();

private:
    Ui::SemiAutoMoveDialog *ui;
    Subtitles *subs;
};

#endif // SEMIAUTOMOVEDIALOG_H
