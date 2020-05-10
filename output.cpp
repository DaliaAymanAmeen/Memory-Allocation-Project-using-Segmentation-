#include "output.h"
#include "ui_output.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QIntValidator>
#include <output.h>
#include <QTextEdit>
#include <QLabel>
#include<QPlainTextEdit>
#include"functions.h"
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


int first=0;
int best=0;


 QVector<QString>names(1000);


 QVector<int>sizes(1000);
 QString parent;
 int ki=0;

void output::on_add_seg_clicked()
{
    int iterator=ui->seg_number->text().split(" ")[0].toInt();

    int k=ki;
    if(iterator--){
    names[k]=ui->segment_name->text();
    sizes[k]=ui->seg_size->text().split(" ")[0].toInt();

    ki++;
    ui->seg_number->setText(QString::number(iterator));
    ui->segment_name->clear();
    ui->seg_size->clear();


    }

   if(iterator==0){
       //law 5alas 3add el segments 5eles e2fel button el add w makan el ketaba kaman
       ui->add_seg->setEnabled(false);
       ui->segment_name->setEnabled(false);
       ui->seg_size->setEnabled(false);
   }




}

void output::on_first_fit_clicked()
{
    first=1;
    best=0;
}

void output::on_add_process_clicked()
{   //raga3t el button w el text active tany
    ui->add_seg->setEnabled(true);
    ui->segment_name->setEnabled(true);
    ui->seg_size->setEnabled(true);

    if(first){
        QString parent=ui->process_name->text();
       if( first_fit_alloc(v,names, sizes,parent)){


           int down=0;

           for (int i_seg = 0 ; i_seg < v.size() ; i_seg++)
           {
              QString name_to_draw;
              int height;
              height = v[i_seg].size ;

              if (v[i_seg].hole == true) //hole
              {
                  name_to_draw = "HOLE";

              }

              else //segment
              {
                    name_to_draw = v[i_seg].parent + "\n"  +v[i_seg].name ;
              }



           QPushButton *to_draw = new QPushButton( name_to_draw ,this);
           to_draw->move(650 , 70+ (down*3));
           to_draw->setFixedHeight(height*3);
           to_draw->setFixedWidth(200);
           if (v[i_seg].hole == true) to_draw->setStyleSheet("QPushButton {text-align: center;background-color :black;color :white;}");
           else to_draw->setStyleSheet("QPushButton {text-align: center;background-color :rgb(148, 200, 190);color :white;}");

           to_draw->show();

           QLabel* base = new QLabel (this);
           base->setText(QString::number(v[i_seg].address));
           base ->move(625, 70+ (down*3));
           base->setFixedHeight(20);
           base->setFixedWidth(25);
           base->show();

           down += height;


        }





       }
       else{
           QMessageBox::warning(this,"NO","You can't enter this process in first fit");

       }
    }
 else if(best){
        QString parent=ui->process_name->text();
        if(best_fit_alloc(v,names, sizes, parent)){

            int down=0;

            for (int i_seg = 0 ; i_seg < v.size() ; i_seg++)
            {
               QString name_to_draw;
               int height;
               height = v[i_seg].size ;

               if (v[i_seg].hole == true) //hole
               {
                   name_to_draw = "HOLE";

               }

               else //segment
               {
                     name_to_draw = v[i_seg].parent + "\n"  +v[i_seg].name ;
               }



            QPushButton *to_draw = new QPushButton( name_to_draw ,this);
            to_draw->move(650 , 70+ (down*3));
            to_draw->setFixedHeight(height*3);
            to_draw->setFixedWidth(200);
            if (v[i_seg].hole == true) to_draw->setStyleSheet("QPushButton {text-align: center;background-color :black;color :white;}");
            else to_draw->setStyleSheet("QPushButton {text-align: center;background-color :rgb(148, 200, 190);color :white;}");

            to_draw->show();

            QLabel* base = new QLabel (this);
            base->setText(QString::number(v[i_seg].address));
            base ->move(625, 70+ (down*3));
            base->setFixedHeight(20);
            base->setFixedWidth(25);
            base->show();

            down += height;



        }
        }

        else{
            QMessageBox::warning(this,"NO","You can't enter this process in best fit");
        }

    }

 ui->seg_number->clear();
 ui->segment_name->clear();
 ui->seg_size->clear();
 ui->process_name->clear();
ki=0;
}







void output::on_Best_Fit_clicked()
{
    best=1;
    first=0;
}
