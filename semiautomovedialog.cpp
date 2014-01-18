#include "semiautomovedialog.h"
#include "ui_semiautomovedialog.h"
#include <QMessageBox>
#include <QListWidgetItem>

SemiAutoMoveDialog::SemiAutoMoveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SemiAutoMoveDialog)
{
    this->subs = NULL;
    ui->setupUi(this);
}

SemiAutoMoveDialog::SemiAutoMoveDialog(Subtitles *subs, QWidget *parent) : SemiAutoMoveDialog(parent) {
    this->subs = subs;
}

SemiAutoMoveDialog::~SemiAutoMoveDialog()
{
    delete ui;
}

int SemiAutoMoveDialog::exec() {
    if (NULL == this->subs) {
        QMessageBox::critical(0, "Error", "Please open subtitles first!");
        this->reject();
        return Rejected;
    } else {
        for (SubtitleLine line : *(this->subs->getLines())) {
            this->ui->listWidget1->addItem(line.getOneLine());
            this->ui->listWidget2->addItem(line.getOneLine());
        }
        return QDialog::exec();
    }
}
