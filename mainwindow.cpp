#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QIntValidator>
#include <output.h>
#include <QTextEdit>
#include <QLabel>
#include "functions.h"
#include<functions.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

       QPixmap bkgnd(":/Resource/img/watercolour-texture-background-vector.jpg");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);

}

MainWindow::~MainWindow()
{
    delete ui;
}

 //vector of segments

 QVector<segment> v;
    int total_size;
//total size of memory

void MainWindow::on_add_total_size_clicked()  //to take the total size of memory and error checking
{
     int pos = 0;
     QString size =ui->holes_starting_address->text();
     QIntValidator v( 0, 10000, this );

      if(v.validate(size , pos)==QValidator::Invalid )
             QMessageBox::warning(this, "Wrong input", "Please enter a number");

      else
      {
          total_size = ui->total_size->text().split(" ")[0].toInt();
          //QMessageBox::about(this, "Total Memory Size", QString::number(total_size));
          ui->add_total_size->setEnabled(false);
      }
}

//initial given holes (address and size)
int i = 0;
QVector <int> holes_starting_address(10);
QVector <int> holes_size(10);

void MainWindow::on_pushButton_4_clicked()
{
    int pos = 0;
    QString address =ui->holes_starting_address->text();
    QString size=ui->holes_size->text();
    QIntValidator v( 0, 10000, this );

     if(v.validate(address , pos)==QValidator::Invalid ||v.validate(size , pos)==QValidator::Invalid  )
            QMessageBox::warning(this, "Wrong input", "Please enter a number");

     else
     {
         holes_starting_address[i] = ui->holes_starting_address->text().split(" ")[0].toInt();
         holes_size[i] = ui->holes_size->text().split(" ")[0].toInt();
         i++;
         ui->holes_starting_address->clear();
         ui->holes_size->clear();
     }
}


void MainWindow::on_submit_clicked()
{

    holes_starting_address.resize(i);
    holes_size.resize(i);

    add_holes(v, holes_starting_address , holes_size , total_size);

    output output;
    output.setModal(true);
    this->hide();

    //draw initial memory

    QPushButton *memory = new QPushButton("Memory", &output);
    memory->move (650,10);
    memory->setFixedWidth(200);
    memory->setFixedHeight(40);
    memory->setStyleSheet("QPushButton {text-align: center;background-color :rgb(148, 200, 190);color :white;}");
    memory->show();

    /*for (int i_segment = 0 ; i_segment < v.size() ; i_segment++)
    {
         QMessageBox::warning(this,"test",v[i_segment].name);
    }*/

    int down=0;

    for (int i_segment = 0 ; i_segment < v.size() ; i_segment++)
    {
       QString name_to_draw;
       int height;
       height = v[i_segment].size ;

       if (v[i_segment].hole == true) //hole
       {
           name_to_draw = "HOLE";

       }

       else //segment
       {
             name_to_draw = v[i_segment].parent + "\n"  +v[i_segment].name ;
       }



    QPushButton *to_draw = new QPushButton( name_to_draw , &output);
    to_draw->move(650 , 70+((down*500)/total_size));
    to_draw->setFixedHeight((height*500)/total_size);
    to_draw->setFixedWidth(200);
    if (v[i_segment].hole == true) to_draw->setStyleSheet("QPushButton {text-align: center;background-color :black;color :white;}");
    else to_draw->setStyleSheet("QPushButton {text-align: center;background-color :rgb(148, 200, 190);color :white;}");

    to_draw->show();

    QLabel* base = new QLabel (&output);
    base->setText(QString::number(v[i_segment].address));
    base ->move(625, 70+((down*500)/total_size));
    base->setFixedHeight(20);
    base->setFixedWidth(25);
    base->show();

    down += height;


    }

    output.exec();

}



