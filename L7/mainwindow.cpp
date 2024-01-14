#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
QFile file("/home/sabellus/qt project/L7/init.txt"); //подключение файла
QFile file1("/home/sabellus/qt project/L7/init1.txt"); //подключение файла
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->hide();
    ui->label->hide();
    ui->label_2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

double a[11][2];
double b[11][2];
int j = 0;
int i = 0;
double h = 0.314;
void MainWindow::on_pushButton_clicked()
{
    ui->label->show();
    if(!file.exists()){ //проверка существования файла
                     qDebug() << "Файл не существует";
                     return;
                   }
                   else{
                       qDebug() << "Файл существует";
                   }
                   if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){ //проверка открытия файла
                           qDebug() << "Файл не открыт";
                           return;
                   }
                   else{
                       qDebug() << "Файл открыт";
                   }
                file.seek(0);
                QByteArray line;
                     while(!file.atEnd()){ //заполняем массив ввода
                                 line = file.readLine();
                                 a[i][1] = line.toDouble();
                                 i++;
                                 j++;
                             }
                  file.close();
                  for(int k = 0; k < j; k++){
                      a[k][0] = k;
                  }

}


void MainWindow::on_pushButton_2_clicked()
{
    i = 0;
    if(!file1.exists()){ //проверка существования файла
                     qDebug() << "Файл не существует";
                     return;
                   }
                   else{
                       qDebug() << "Файл существует";
                   }
                   if(!file1.open(QIODevice::ReadOnly | QIODevice::Text)){ //проверка открытия файла
                           qDebug() << "Файл не открыт";
                           return;
                   }
                   else{
                       qDebug() << "Файл открыт";
                   }
                file.seek(0);
                QByteArray line;
                while(!file1.atEnd()){ //заполняем массив ввода
                                 line = file1.readLine();
                                 b[i][1] = line.toDouble();
                                 qDebug() << i;
                                 i++;
                                 j++;
                             }
               file1.close();
               for(int k = 0; k < j; k++){
                   b[k][0] = k;
               }
    ui->tableWidget->show();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(11);
    ui->label_2->show();
    for(i = 0; i < 12; i++){
            for(int k = 0; k < 2; k++){
                    QTableWidgetItem *it = new QTableWidgetItem(QString::number(a[i][k]));
                    ui->tableWidget->setItem(i,k,it);
            }
     }
    QStringList l;
    l << "x" << "y";
    ui->tableWidget->setHorizontalHeaderLabels(l);
    ui->tableWidget_2->setColumnCount(2);
    ui->tableWidget_2->setRowCount(11);
               for(i = 0; i < 12; i++){
                       for(int k = 0; k < 2; k++){
                               QTableWidgetItem *it = new QTableWidgetItem(QString::number(b[i][k]));
                               ui->tableWidget_2->setItem(i,k,it);
                       }
                }
}



