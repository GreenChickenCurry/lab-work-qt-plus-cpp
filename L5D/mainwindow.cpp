#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
QFile file("/home/sabellus/qt project/L5D/init.txt"); //подключение файла
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->hide(); //скрытие рабочих элементов
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit_6->hide();
    ui->lineEdit_7->hide();
    ui->lineEdit_8->hide();
    ui->lineEdit_9->hide();
    ui->lineEdit_10->hide();
    ui->lineEdit_11->hide();
    ui->lineEdit_12->hide();
    ui->lineEdit_13->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->label_10->hide();
    ui->label_11->hide();
    ui->label_12->hide();
    ui->label_13->hide();
    ui->label_14->hide();
    ui->label_15->hide();
    ui->label_16->hide();
    ui->label_17->hide();
    ui->label_18->hide();
    ui->tableWidget->hide();
    ui->tableWidget_2->hide();
    ui->tableWidget_3->hide();
    ui->tableWidget_4->hide();
    ui->tableWidget_5->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

double a[13]; //массив ввода
int i = 0; //индекс
int c1 = 0; //буфер
double func(double x, double y){ //интегрируемая функция
    double res = (2*x)/(3*y);
    return res;
}
double ph0(double h, double f){ //компонент метода Рунге-Кутта
    double res = h*f;
    return res;
}
double ph1(double h, double ph0, double x, double y){ //компонент метода Рунге-Кутта
    double res = h*func(x+h/2,y+ph0/2);
    return res;
}
double ph2(double h, double ph1, double x, double y){ //компонент метода Рунге-Кутта
    double res = h*func(x+h/2,y+ph1/2);
    return res;
}
double ph3(double h, double ph2, double x, double y){ //компонент метода Рунге-Кутта
    double res = h*func(x+h,y+ph2);
    return res;
}
double rfunc(double y1, double y2, double k){//функция уточнения решения правилом Рунге
    double res = y2 + (y2-y1)/(pow(2,k)-1);
    return res;
}
double px(double x){ //функця при коэффициенте дифференциального уравнения
    double res = -x;
    return  res;
}
double fx(double x){ //функця при коэффициенте дифференциального уравнения
    double res = x+1;
    return res;
}
double ai(double px, double h){ //компонент для поиска прогонночных коэффциентов
    double res = (1-0.5*px*h)/(1+0.5*px*h);
    return res;
}
double bi(double px, double qx, double h){ //компонент для поиска прогонночных коэффциентов
    double res = (2-qx*pow(h,2))/(1+0.5*px*h);
    return res;
}
double di(double px, double fx, double h){ //компонент для поиска прогонночных коэффциентов
    double res = (pow(h,2)*fx)/(1+0.5*px*h);
    return res;
}
double ish(double x){
    double res = -sqrt(2*x*x+19)/sqrt(3);
    return res;
}
void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->show(); //показ рабочих элементов
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
    ui->lineEdit_6->show();
    ui->lineEdit_7->show();
    ui->lineEdit_8->show();
    ui->lineEdit_9->show();
    ui->lineEdit_10->show();
    ui->lineEdit_11->show();
    ui->lineEdit_12->show();
    ui->lineEdit_13->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_8->show();
    ui->label_9->show();
    ui->label_10->show();
    ui->label_11->show();
    ui->label_12->show();
    ui->label_13->show();
    ui->label_14->show();
    ui->label_15->show();
    ui->label_16->show();
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
                         a[i] = line.toDouble();
                         i++;
                     }
             ui->lineEdit->setText(QString::number(a[0])); //запись в рабочие элементы
             ui->lineEdit_2->setText(QString::number(a[1]));
             ui->lineEdit_3->setText(QString::number(a[2]));
             ui->lineEdit_4->setText(QString::number(a[3]));
             ui->lineEdit_5->setText(QString::number(a[4]));
             ui->lineEdit_6->setText(QString::number(a[5]));
             ui->lineEdit_7->setText(QString::number(a[6]));
             ui->lineEdit_8->setText(QString::number(a[7]));
             ui->lineEdit_9->setText(QString::number(a[8]));
             ui->lineEdit_10->setText(QString::number(a[9]));
             ui->lineEdit_11->setText(QString::number(a[10]));
             ui->lineEdit_12->setText(QString::number(a[11]));
             ui->lineEdit_13->setText(QString::number(a[12]));
             file.close();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->show(); //показ рабочих элементов
    ui->tableWidget_2->show();
    ui->tableWidget_3->show();
    ui->label_5->show();
    ui->label_6->show();
    ui->label_7->show();
    QString xl; //буфер считывания с рабочих элементов
    int n = 0; //счетчик числа строк
    xl = ui->lineEdit->text(); //считывание с рабочих элементов
    a[0] = xl.toDouble();
    xl = ui->lineEdit_2->text();
    a[1] = xl.toDouble();
    xl = ui->lineEdit_3->text();
    a[2] = xl.toDouble();
    xl = ui->lineEdit_4->text();
    a[3] = xl.toDouble();
    double xn = a[0]; //переменная х
    double y0 = a[1]; //переменная y
    double h = a[2]; //шаг
    double yn = 0;
    int n1 = 1/h; //число разбиения
    c1 = n1;
    double sh[7][150][2]; //инициализация массива
    for(i = 0; i < n1; i++){ //метод Рунге-Кутта
        yn = (ph0(h,func(xn,y0))+2*ph1(h,ph0(h,func(xn,y0)),xn,y0)+2*ph2(h,ph1(h,ph0(h,func(xn,y0)),xn,y0),xn,y0)+ph3(h,ph2(h,ph1(h,ph0(h,func(xn,y0)),xn,y0),xn,y0),xn,y0))/6;
        y0 = yn+y0;
        sh[0][i][0] = xn+h;
        sh[1][i][0] = y0;
        sh[2][i][0] = ph0(h,func(xn,y0));
        sh[3][i][0] = ph1(h,ph0(h,func(xn,y0)),xn,y0);
        sh[4][i][0] = ph2(h,ph1(h,ph0(h,func(xn,y0)),xn,y0),xn,y0);
        sh[5][i][0] = ph3(h,ph2(h,ph1(h,ph0(h,func(xn,y0)),xn,y0),xn,y0),xn,y0);
        sh[6][i][0] = ish(sh[0][i][0]);
        xn = xn+h;
    }
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setRowCount(i);
    QStringList l;
    l << "x" << "y" << "φ0" << "φ1" << "φ2" << "φ3" << "y^*";
    ui->tableWidget->setHorizontalHeaderLabels(l);
    for(int k = 0; k < n1; k++){ //заполнение таблицы
                           for(i = 0; i < 7; i++){
                                   QTableWidgetItem *it = new QTableWidgetItem(QString::number(sh[i][k][0]));
                                   ui->tableWidget->setItem(k,i,it);
                            }
    }
    xn = a[0];
    y0 = a[1];
    h = a[3];
    yn = 0;
    n1 = 1/h;
    for(i = 0; i < n1; i++){
        yn = (ph0(h,func(xn,y0))+2*ph1(h,ph0(h,func(xn,y0)),xn,y0)+2*ph2(h,ph1(h,ph0(h,func(xn,y0)),xn,y0),xn,y0)+ph3(h,ph2(h,ph1(h,ph0(h,func(xn,y0)),xn,y0),xn,y0),xn,y0))/6;
        y0 = yn+y0;
        sh[0][i][1] = xn+h;
        sh[1][i][1] = y0;
        sh[2][i][1] = ph0(h,func(xn,y0));
        sh[3][i][1] = ph1(h,ph0(h,func(xn,y0)),xn,y0);
        sh[4][i][1] = ph2(h,ph1(h,ph0(h,func(xn,y0)),xn,y0),xn,y0);
        sh[5][i][1] = ph3(h,ph2(h,ph1(h,ph0(h,func(xn,y0)),xn,y0),xn,y0),xn,y0);
        sh[6][i][1] = ish(sh[0][i][1]);
        xn = xn+h;
    }
    ui->tableWidget_2->setColumnCount(7);
    ui->tableWidget_2->setRowCount(i);
    ui->tableWidget_2->setHorizontalHeaderLabels(l);
    for(int k = 0; k < n1; k++){ //заполнение таблицы
                           for(i = 0; i < 7; i++){
                                   QTableWidgetItem *it = new QTableWidgetItem(QString::number(sh[i][k][1]));
                                   ui->tableWidget_2->setItem(k,i,it);
                            }
    }
    ui->tableWidget_3->setColumnCount(2);
    ui->tableWidget_3->setRowCount(c1);
    double rung[c1][2];
    for(i = 0; i <= c1; i++){
        rung[i][1] = rfunc(sh[1][i][0], sh[1][2*i+1][1], 4);
        rung[i][0] = sh[0][i][0];
        for(int k = 0; k < 2; k++){
            QTableWidgetItem *it = new QTableWidgetItem(QString::number(rung[i][k]));
            ui->tableWidget_3->setItem(i,k,it);
        }
    }
    QStringList l3;
    l3 << "x" << "y";
    ui->tableWidget_3->setHorizontalHeaderLabels(l3);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tableWidget_4->show();
    ui->tableWidget_5->show();
    ui->tableWidget->hide();
    //ui->label_20->show();
    ui->tableWidget_2->hide();
    ui->tableWidget_3->hide();
    //ui->tableWidget_4->show();
    ui->label_17->show();
    ui->label_18->show();
    //ui->tableWidget_5->show();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    double qx = 2;

    //ui->label_18->show();
    QString xl = ui->lineEdit_5->text();
    a[4] = xl.toDouble();
    xl = ui->lineEdit_6->text();
    a[5] = xl.toDouble();
    xl = ui->lineEdit_7->text();
    a[6] = xl.toDouble();
    xl = ui->lineEdit_8->text();
    a[7] = xl.toDouble();
    xl = ui->lineEdit_9->text();
    a[8] = xl.toDouble();
    xl = ui->lineEdit_10->text();
    a[9] = xl.toDouble();
    xl = ui->lineEdit_11->text();
    a[10] = xl.toDouble();
    xl = ui->lineEdit_12->text();
    a[11] = xl.toDouble();
    xl = ui->lineEdit_13->text();
    a[12] = xl.toDouble();
    double h = a[12];
    double n = (a[5]-a[4])/h;
    double xn = a[4];
    xl = QString::number(n);
    int n1 = xl.toInt()+1;
    ui->tableWidget_4->setRowCount(n1-1);
    ui->tableWidget_4->setColumnCount(n1+1);
    QStringList l;
    double b[n1][n1+1];
    l << "y_0" << "y_1" << "y_2" << "y_3" << "y_4" << "y_5" << "y_6" << "b";
    ui->tableWidget_4->setHorizontalHeaderLabels(l);
    for(i = 0; i < n1; i++){ //зануление всех элементов
        for(int k = 0; k <= n1+1; k++){
            QTableWidgetItem *it = new QTableWidgetItem(QString::number(0));
            ui->tableWidget_4->setItem(i,k,it);
            b[i][k] = 0;
        }
    }
    double q0 = (a[10]*h)/(a[6]*h-a[7]);
    double p0 = -(a[7])/(a[6]*h-a[7]);
    for(i = 0; i < n1-1; i++){
        b[i][i] = 1;
        if(i != n1-1){
            b[i][i+1] = p0;
        }
        b[i][n1] = q0;
        q0 = (di(px(xn),fx(xn),h) - ai(px(xn),h)*q0)/(ai(px(xn),h)*p0-bi(px(xn),qx,h));
        p0 = -(1)/(ai(px(xn),h)*p0-bi(px(xn),qx,h));
        xn = xn+h;
    }
    for(i = 0; i < n1; i++){
        for(int k = 0; k <= n1+1; k++){
            QTableWidgetItem *it = new QTableWidgetItem(QString::number(b[i][k]));
            ui->tableWidget_4->setItem(i,k,it);
        }
    }
    int j = 0;
    double yn[150][2];
    yn[0][1] =(a[11]*h+a[9]*b[n1-2][n1])/(a[8]*h+a[9]*(1-b[n1-2][n1-1]));
    yn[0][0] = a[5];
    for(i = n1-1; i > 0; i--){
        yn[j+1][1] = b[i-1][n1]+b[i-1][i]*yn[j][1];
        yn[j+1][0] = yn[j][0] - h;
        j++;
    }
    ui->tableWidget_5->setRowCount(j+1);
    ui->tableWidget_5->setColumnCount(2);
    for(i = 0; i < j+1; i++){
        for(int k = 0; k < 2; k++){
            QTableWidgetItem *it = new QTableWidgetItem(QString::number(yn[i][k]));
            ui->tableWidget_5->setItem(i,k,it);
        }
    }
    QStringList l2;
    l2 << "x" << "y";
    double z;
    ui->tableWidget_5->setHorizontalHeaderLabels(l2);
    for(i = 0; i < n1-2; i++){ //исправление ошибки и добавление там, где он должен быть
            QString l = ui->tableWidget_4->item(i,i+1)->text();
            z = -l.toDouble();
            QTableWidgetItem *it = new QTableWidgetItem(QString::number(z));
            ui->tableWidget_4->setItem(i,i+1,it);
    }
    QString kl = ui->tableWidget_4->item(n1-2,n1-1)->text();
    qDebug() << kl;
    double m = -kl.toDouble();
    QTableWidgetItem *it = new QTableWidgetItem(QString::number(m));
    ui->tableWidget_4->setItem(n1-2,n1-1,it);
}

