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
#include<QDebug>
#include<QTableWidget>
#include<QMap>
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


 QVector<QString>names(0);


 QVector<int>sizes(0);
 QString parent;
// int ki=0;

void output::on_add_seg_clicked()
{
    int iterator=ui->seg_number->text().split(" ")[0].toInt();
ui->seg_number->setEnabled(false);
ui->add_process->setEnabled(true);
    //int k=ki;
    if(iterator--){
    names.push_back(ui->segment_name->text());
    sizes.push_back(ui->seg_size->text().split(" ")[0].toInt());

   // ki++;
    ui->seg_number->setText(QString::number(iterator));
    ui->segment_name->clear();
    ui->seg_size->clear();


    }

   if(iterator==0){
       //law 5alas 3add el segments 5eles e2fel button el add w makan el ketaba kaman
       ui->add_seg->setEnabled(false);
       ui->segment_name->setEnabled(false);
       ui->seg_size->setEnabled(false);
       ui->add_process->setEnabled(true);

   }




}

void output::on_first_fit_clicked()
{
    first=1;
    best=0;
}
int space=0;
int factor=0;
QMap<QString,int>Map;
void output::on_add_process_clicked()
{   //raga3t el button w el text active tany
    ui->add_seg->setEnabled(true);
    ui->segment_name->setEnabled(true);
    ui->seg_size->setEnabled(true);
 ui->seg_number->setEnabled(true);
 ui->add_process->setEnabled(false);
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
           to_draw->move(650 , 70+((down*500)/total_size));
           to_draw->setFixedHeight((height*500)/total_size);
           to_draw->setFixedWidth(200);
           if (v[i_seg].hole == true) to_draw->setStyleSheet("QPushButton {text-align: center;background-color :black;color :white;}");
           else to_draw->setStyleSheet("QPushButton {text-align: center;background-color :rgb(148, 200, 190);color :white;}");

           to_draw->show();

           QLabel* base = new QLabel (this);
           base->setText(QString::number(v[i_seg].address));
           base ->move(625, 70+((down*500)/total_size));
           base->setFixedHeight(20);
           base->setFixedWidth(25);
           base->show();

           down += height;


        }
           //el table hena
           QTableWidget *table=new  QTableWidget(1,4,this);
                         table->move(900,space);
                         table->setFixedHeight(150);
                         table->setFixedWidth(535);
                        QTableWidgetItem *process=new QTableWidgetItem(parent);
                         table->setItem(0,0,process);

                         QTableWidgetItem *segments=new QTableWidgetItem("Segment");
                          table->setItem(0,1,segments);
                          QTableWidgetItem *Address=new QTableWidgetItem("Address");
                           table->setItem(0,2,Address);
                           QTableWidgetItem *Size=new QTableWidgetItem("Size");
                            table->setItem(0,3,Size);

                            int row=1;
                            QVector<segment>seg= seg_table(v,parent);

                              for(int j=0;j<seg.size();j++){
                                  if(seg[j].name==""){
                                      continue;
                                  }
                             // QTableWidgetItem *processname=new QTableWidgetItem(seg[j].parent);
                              QTableWidgetItem *Segm=new QTableWidgetItem(seg[j].name);
                              QTableWidgetItem *add=new QTableWidgetItem(QString::number(seg[j].address));
                              QTableWidgetItem *si=new QTableWidgetItem(QString::number(seg[j].size));
                               table->insertRow(row);
                             // table->setItem(row,0,processname);
                             table->setItem(row,1,Segm);
                             table->setItem(row,2,add);
                             table->setItem(row,3,si);
                              row++;

                              }
                              factor++;
                              Map[parent]=space;
                              space=factor*(table->height());
                              table->show();




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
            to_draw->move(650 , 70+ ((down*500)/total_size) );
            to_draw->setFixedHeight((height*500)/total_size);
            to_draw->setFixedWidth(200);
            if (v[i_seg].hole == true) to_draw->setStyleSheet("QPushButton {text-align: center;background-color :black;color :white;}");
            else to_draw->setStyleSheet("QPushButton {text-align: center;background-color :rgb(148, 200, 190);color :white;}");

            to_draw->show();

            QLabel* base = new QLabel (this);
            base->setText(QString::number(v[i_seg].address));
            base ->move(625, 70+ ((down*500)/total_size) );
            base->setFixedHeight(20);
            base->setFixedWidth(25);
            base->show();

            down += height;



        }
            //el table hena
            QTableWidget *table=new  QTableWidget(1,4,this);
                          table->move(900,space);
                          table->setFixedHeight(150);
                          table->setFixedWidth(535);
                         QTableWidgetItem *process=new QTableWidgetItem(parent);
                          table->setItem(0,0,process);

                          QTableWidgetItem *segments=new QTableWidgetItem("Segment");
                           table->setItem(0,1,segments);
                           QTableWidgetItem *Address=new QTableWidgetItem("Address");
                            table->setItem(0,2,Address);
                            QTableWidgetItem *Size=new QTableWidgetItem("Size");
                             table->setItem(0,3,Size);

                             int row=1;
                             QVector<segment>seg= seg_table(v,parent);

                               for(int j=0;j<seg.size();j++){
                                   if(seg[j].name==""){
                                       continue;
                                   }
                             //  QTableWidgetItem *processname=new QTableWidgetItem(seg[j].parent);
                               QTableWidgetItem *Segm=new QTableWidgetItem(seg[j].name);
                               QTableWidgetItem *add=new QTableWidgetItem(QString::number(seg[j].address));
                               QTableWidgetItem *si=new QTableWidgetItem(QString::number(seg[j].size));
                                table->insertRow(row);
                            //   table->setItem(row,0,processname);
                              table->setItem(row,1,Segm);
                              table->setItem(row,2,add);
                              table->setItem(row,3,si);
                               row++;

                               }
                               factor++;
                               Map[parent]=space;
                               space=factor*(table->height());
                               table->show();


        }

        else{
            QMessageBox::warning(this,"NO","You can't enter this process in best fit");
        }

    }

 ui->seg_number->clear();
 ui->segment_name->clear();
 ui->seg_size->clear();
 ui->process_name->clear();
names.resize(0);
sizes.resize(0);

// ki=0;

}







void output::on_Best_Fit_clicked()
{
    best=1;
    first=0;
}


void output::on_pushButton_clicked()
{
    QString pr_deallocat = ui->lineEdit->text();
        space=(space<Map[pr_deallocat])?space:Map[pr_deallocat];
        factor--;
      de_alloc(v, pr_deallocat);

      ui->lineEdit->clear();
      QPushButton *memory = new QPushButton("Memory", this);
      memory->move (650,10);
      memory->setFixedWidth(200);
      memory->setFixedHeight(40);
      memory->setStyleSheet("QPushButton {text-align: center;background-color :rgb(148, 200, 190);color :white;}");
      memory->show();


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



      QPushButton *to_draw = new QPushButton( name_to_draw , this);
      to_draw->move(650 , 70+((down*500)/total_size));
      to_draw->setFixedHeight((height*500)/total_size);
      to_draw->setFixedWidth(200);
      if (v[i_segment].hole == true) to_draw->setStyleSheet("QPushButton {text-align: center;background-color :black;color :white;}");
      else to_draw->setStyleSheet("QPushButton {text-align: center;background-color :rgb(148, 200, 190);color :white;}");

      to_draw->show();

      QLabel* base = new QLabel (this);
      base->setText(QString::number(v[i_segment].address));
      base ->move(625, 70+((down*500)/total_size));
      base->setFixedHeight(20);
      base->setFixedWidth(25);
      base->show();

      down += height;


      } 

}
