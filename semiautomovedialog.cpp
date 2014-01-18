#include "semiautomovedialog.h"
#include "ui_semiautomovedialog.h"
#include <QMessageBox>
#include <QListWidgetItem>
#include <QTime>

SemiAutoMoveDialog::SemiAutoMoveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SemiAutoMoveDialog)
{
    this->subs = NULL;
    ui->setupUi(this);
    connect(this, SIGNAL(accepted()), this, SLOT(doMoveStretch()));
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

bool SemiAutoMoveDialog::doMoveStretch() {
    if (this->ui->listWidget1->selectedItems().count() == 0 ||
            this->ui->listWidget2->selectedItems().count() == 0) {
        QMessageBox::critical(0, "Error", "You need to select subtitle line anchors!");
        return false;
    }
    QString selected1 = this->ui->listWidget1->selectedItems().at(0)->text();
    QString selected2 = this->ui->listWidget2->selectedItems().at(0)->text();
    int hours1 = this->ui->hours1->value();
    int hours2 = this->ui->hours2->value();
    int minutes1 = this->ui->minutes1->value();
    int minutes2 = this->ui->minutes2->value();
    int seconds1 = this->ui->seconds1->value();
    int seconds2 = this->ui->seconds2->value();
    int ms1 = this->ui->milliseconds1->value();
    int ms2 = this->ui->milliseconds2->value();
    QTime time1;
    QTime time2;
    time1.setHMS(hours1,minutes1,seconds1,ms1);
    time2.setHMS(hours2,minutes2,seconds2,ms2);
    int dif1 = time2.msecsSinceStartOfDay() - time1.msecsSinceStartOfDay();

    SubtitleLine* line1 = this->subs->getLineByText(selected1);
    SubtitleLine* line2 = this->subs->getLineByText(selected2);
    int dif2 = line2->getMsecStart() - line1->getMsecStart();
    int top = dif1;
    int bot = dif2;
    int move = time1.msecsSinceStartOfDay() - line1->getMsecStart();
    int balance = ((line1->getMsecStart() + move)*top)/bot - time1.msecsSinceStartOfDay();

    for (SubtitleLine &line : *(this->subs->getLines())) {
        line.move(move);
        line.stretch(top, bot);
        line.move(-balance);
    }
    return true;
}
