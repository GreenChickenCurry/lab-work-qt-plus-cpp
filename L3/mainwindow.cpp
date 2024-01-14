#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); //скрытие рабочих элементов
    ui->tableWidget->hide();
    ui->tableWidget_2->hide();
    ui->tableWidget_3->hide();
    ui->tableWidget_4->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
}

QFile file("/home/sabellus/qt project/L3/tes.txt"); //подключение файла

MainWindow::~MainWindow()
{
    delete ui;
}
int n1 = 0;
int n2 = 0; //счетчики
int n;
double XX;
double xy[150][2];
double h[150];
double a[150][150];
double k[150];
QString xl; //буфер
int i;
void MainWindow::on_pushButton_clicked()
{
    n1 = 0;
    ui->tableWidget->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->lineEdit->show();
    ui->tableWidget->setColumnCount(2);
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
    QByteArray line;
    QByteArray line1;
    QByteArray line2;
    QByteArray line3;
    file.seek(0); //установка курсора в начало файла
    while(line != "\n"){ //считываем размер файла для x
            line = file.readLine();
            if (line == "\n"){
                break;
            }
            qDebug() << QString::fromUtf8(line);
            n1++;
        }
    n = n1;
    file.seek(0); //установка курсора в начало
        double xy[n1][2]; //массивы ввода x
        n1 = 0;
    while(line1 != "\n"){ //заполняем массив ввода x
            line1 = file.readLine();
            if (line1 == "\n"){
                break;
            }
            xy[n1][0] = line1.toDouble();
            n1++;
        }
    n1 = file.pos(); //сохранение текущей позиции
    file.seek(file.pos());
    while(line2 != "\n"){ //считываем размер файла для y
            line2 = file.readLine();
            if (line2 == "\n"){
                break;
            }
            qDebug() << QString::fromUtf8(line2);
            n2++;
        }
    file.seek(n1);
    ui->tableWidget->setRowCount(n); //задание размера таблицы
    n2 = 0;
    while(line3 != "\n"){ //заполняем массив ввода y
            line3 = file.readLine();
            if (line3 == "\n"){
                break;
            }
            xy[n2][1] = line3.toDouble();
            n2++;
        }
    xl = file.readLine();; //буфер для X большего
    XX = xl.toDouble();
    file.close(); //отчистка файла из оперативной памяти
    QStringList l; //запись легенды
    l << "X" << "Y";
    int c;
    ui->tableWidget->setHorizontalHeaderLabels(l);
    for(n1 = 0; n1 < n2; n1++){ //заполнение таблицы
                   for(c = 0; c < 2; c++){
                           QTableWidgetItem *it = new QTableWidgetItem(QString::number(xy[n1][c]));
                           ui->tableWidget->setItem(n1,c,it);
                   }
    }

    ui->lineEdit->setText(QString::number(XX));
}


double func(double a, double b, double c, double d, double x1, double x2){
    double res = a+b*(x1-x2)+c*pow(x1-x2,2)+d*pow(x1-x2,3);
    return res;
}
void MainWindow::on_pushButton_2_clicked()
{
    double e[n2-2][n2-2]; //буфер для построения перегонки
    double cof[n2-1][4]; //массив коэффициентов
    xl = ui->lineEdit->text();
    ui->tableWidget_2->show(); //показ рабочих элементов
    ui->tableWidget_3->show();
    ui->tableWidget_4->show();
    ui->label_4->show();
    ui->label_5->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->lineEdit_2->show();
    ui->tableWidget_2->setColumnCount(n2-2);
    ui->tableWidget_2->setRowCount(n2-3);
    ui->tableWidget_3->setColumnCount(n2-2);
    ui->tableWidget_3->setRowCount(n2-3);
    ui->tableWidget_4->setColumnCount(4);
    ui->tableWidget_4->setRowCount(n2-1);
    QStringList l; //массив легенды
    QStringList l1;
    for(i = 1; i < n2-2; i++){
        l << "C" + QString::number(i);
    }
    l << "b";
    l1 << "a" << "b" << "c" << "d";
    ui->tableWidget_2->setHorizontalHeaderLabels(l);
    ui->tableWidget_3->setHorizontalHeaderLabels(l);
    ui->tableWidget_4->setHorizontalHeaderLabels(l1);
    XX = xl.toDouble(); //считывание с окна ввода
    xl = " ";
    for(n1 = 0; n1 < n2; n1++){ //считывание из таблицы
        for(i = 0; i < 2; i++){
            xl = ui->tableWidget->item(n1,i)->text();
            xy[n1][i] = xl.toDouble();
        }
    }
    for(n1 = 0; n1 < n2-1; n1++){ //вычисление промежутков
        h[n1] = abs(xy[n1+1][0] - xy[n1][0]);
    }
    for(n1 = 0; n1 < n2-3; n1++){ //зануление всех компонент
        for(i = 0; i < n2 - 2; i++){
            a[n1][i] = 0;
        }
    }
    i = 0;
    for(n1 = 1; n1 < n2-2; n1++){ //заполнение коэффициентов свободного члена
        a[i][n2-3] = 3*((xy[n1+1][1]-xy[n1][1])/h[i]-(xy[n1][1]-xy[n1-1][1])/h[n1-1]);
        i++;
    }
    i = 0;

    for(n1 = 0; n1 < n2-2; n1++){ //построение за счет буфера основных элементов
            e[n1][i] = h[n1];
            e[n1][i+1] = 2*(h[n1] + h[n1+1]);
            e[n1][i+2] = h[n1+1];
            i++;
    }
    for(n1 = 0; n1 < n2-3; n1++){ //добавление нулей
        for(i = 0; i < n2-3; i++){
            if(QString::number(e[n1][i+1]).size() > 10){
            a[n1][i] = 0;
            }
            else{
                a[n1][i] = e[n1][i+1];
            }
        }
    }
    for(n1 = 0; n1 < n2-3; n1++){ //заполнение таблицы
                   for(i= 0; i <= n2-3; i++){
                           QTableWidgetItem *it = new QTableWidgetItem(QString::number(a[n1][i]));
                           ui->tableWidget_2->setItem(n1,i,it);
                    }
    }


    for(n1 = 0; n1 < n2 - 4; n1++){ //метод прогонки
         for(i = 0; i < n2-4; i++){
             if(n1 == i){
                a[n1+1][n2-3] = a[n1+1][n2-3]-a[n1+1][i]/a[n1][i]*a[n1][n2-3];
                a[n1+1][i+1] = a[n1+1][i+1] - a[n1+1][i]/a[n1][i]*a[n1][i+1];
                a[n1+1][i] = 0;
             }
         }
    }
    a[n2-4][n2-3] =  a[n2-4][n2-3]/a[n2-4][n2-4]; //нормирование последнего столбца
    a[n2-4][n2-4] =  a[n2-4][n2-4]/a[n2-4][n2-4];
    k[n2-4] = a[n2-4][n2-3];
    for(n1 = n2-5; n1 >= 0; n1--){ //обратный ход
                a[n1][n2-3] = a[n1][n2-3]-k[n1+1]*a[n1][n1+1];
                a[n1][n2-3] = a[n1][n2-3]/a[n1][n1];
                k[n1] = a[n1][n2-3];
        }
    for(n1 = 0; n1 < n2-3; n1++){ //заполнение таблицы
                   for(i= 0; i <= n2-3; i++){
                       QTableWidgetItem *it = new QTableWidgetItem(QString::number(a[n1][i]));
                       ui->tableWidget_3->setItem(n1,i,it);
                   }
    }
    cof[0][2] = 0;
    cof[n2-2][2] = 0;
    for(n1 = 0; n1 < n2 - 3; n1++){ //заполнение компонент c
        cof[n1+1][2] = k[n1];
    }
    for(n1 = 0; n1 < n2 - 1; n1++){ //заполнение компонент a
           cof[n1][0] = xy[n1][1];
    }
    for(n1 = 0; n1 < n2 - 2; n1++){ //заполнение компонент d
           cof[n1][3] = (cof[n1+1][2] - cof[n1][2])/(3*h[n1]);
    }
    cof[n2-2][3] = -cof[n2-2][2]/(3*h[n2-2]); //значение последней компоненты d
    for(n1 = 0; n1 < n2 - 2; n1++){ //заполнение компонент b
           cof[n1][1] = (xy[n1+1][1]-xy[n1][1])/h[n1] - (cof[n1+1][2]+2*cof[n1][2])*h[n1]/3;
    }
    cof[n2-2][1] = (xy[n2-1][1]-xy[n2-2][1])/h[n2-2] - 2*cof[n2-2][2]*h[n2-2]/3;
    for(n1 = 0; n1 < n2-1; n1++){ //заполнение таблицы
                   for(i= 0; i <= 3; i++){
                       QTableWidgetItem *it = new QTableWidgetItem(QString::number(cof[n1][i]));
                       ui->tableWidget_4->setItem(n1,i,it);
                   }
    }
    for(n1 = 0; n1 < n2-1;n1++){
        if(xy[n1][0] <= XX && xy[n1+1][0] >= XX){
           ui->lineEdit_2 ->setText(QString::number(func(cof[n1][0],cof[n1][1],cof[n1][2],cof[n1][3],XX,xy[n1][0])));
        }
    }
}
