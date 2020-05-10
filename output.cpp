#include "output.h"
#include "ui_output.h"
#include <mainwindow.h>

output::output(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::output)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/Resource/img/watercolour-texture-background-vector.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

output::~output()
{
    delete ui;
}
