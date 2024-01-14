#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
QFile file("/home/sabellus/qt project/L6/init.txt"); //подключение файла
QFile file1("/home/sabellus/qt project/L6/file1.txt"); //подключение файла


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();

    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit_6->hide();

    ui->tableWidget->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}

double a[6];
int i = 0;
double psi1(double t){
    double res = 2*t;
    return res;
}
double psi2(double t){
    double res = 0;
    return res;
}
double fx(double x){
    double res = x*sin(M_PI*x);
    return res;
}
double Fx(double x){
    double res = pow(x+1,2);
    return res;
}
void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
    ui->lineEdit_6->show();

    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_5->show();
    ui->label_6->show();
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
              file.close();
        ui->lineEdit->setText(QString::number(a[0]));
        ui->lineEdit_2->setText(QString::number(a[1]));
        ui->lineEdit_3->setText(QString::number(a[2]));
        ui->lineEdit_4->setText(QString::number(a[3]));
        ui->lineEdit_5->setText(QString::number(a[4]));
        ui->lineEdit_6->setText(QString::number(a[5]));
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->show();
    ui->label_7->show();
    QString xl = ui->lineEdit->text(); //считывание с рабочих элементов
    a[0] = xl.toDouble();
    xl = ui->lineEdit_2->text();
    a[1] = xl.toDouble();
    xl = ui->lineEdit_3->text();
    a[2] = xl.toDouble();
    xl = ui->lineEdit_4->text();
    a[3] = xl.toDouble();
    xl = ui->lineEdit_5->text();
    a[4] = xl.toDouble();
    xl = ui->lineEdit_6->text();
    a[5] = xl.toDouble();
    double u[100][100];
    double h = a[4];
    double tau = a[5];
    double x0 = a[0];
    double t0 = a[2];
    double al = tau/h;
    int n1 = (a[1]-a[0])/h;
    qDebug() << n1;
    for(i = 0; i <= n1; i++){
        u[i][0] = fx(x0);
        x0 = x0+h;
    }
    x0 = a[0]+h;
    u[0][1] = psi1(tau);
    for(i = 1; i < n1; i++){
        u[i][1] = (1-pow(al,2))*fx(x0)+(pow(al,2)/2)*(fx(x0+h)+fx(x0-h))+tau*Fx(x0);
        x0 = x0+h;
    }
    u[40][1] = psi2(tau);
    int j = 0;
    t0 = 2*tau;
    for(j = 2; j <= n1; j++){
    for(i = 1; i < n1; i++){
        if(i == 1){
            u[i-1][j] = psi1(t0);
        }
        if(i == n1-1){
            u[i+1][j] = psi2(t0);
        }
        u[i][j] = 2*u[i][j-1]-u[i][j-2]+pow(al,2)*(u[i+1][j-1]-2*u[i][j-1]+u[i-1][j-1]);
        }
        t0 = tau +t0;
    }

    ui->tableWidget->setColumnCount(n1+1);
    ui->tableWidget->setRowCount(n1+1);
    if(!file1.open(QIODevice::WriteOnly | QIODevice::Text)){ //проверка открытия файла
            qDebug() << "Файл не открыт";
            return;
    }
    QTextStream stream(&file1);
    x0 = 0;
    for(i = 0; i < n1+1; i++){
        for(j = 0; j < n1+1; j++){
                QTableWidgetItem *it = new QTableWidgetItem(QString::number(u[i][j]));
                ui->tableWidget->setItem(i,j,it);
                stream << QString::number(x0) << " " << QString::number(u[j][i]) << "\n";
                x0 = x0+h;
        }
        stream << "\n";
        x0 = 0;
    }
    QStringList l;
    l << "t0 = 0" << "t1 = 0.05" << "t2 = 0.1" << "t3 = 0.15" << "t4 = 0.2" << "t5 = 0.25" << "t6 = 0.3" << "t7 = 0.35" << "t8 = 0.4" << "t9 = 0.45" << "t10 = 0.5";
    ui->tableWidget->setHorizontalHeaderLabels(l);
    file1.close();
}

