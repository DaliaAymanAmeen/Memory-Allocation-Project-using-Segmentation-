#include "output.h"
#include "ui_output.h"
#include <mainwindow.h>

output::output(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::output)
{
    ui->setupUi(this);
}

output::~output()
{
    delete ui;
}
