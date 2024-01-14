#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QPixmap"
QFile file("/home/sabellus/qt project/L2/test1.txt"); //подключение файла

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->hide(); //скрытие рабочих объектов
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
    ui->label->hide();
    ui->tableWidget->hide();

    QPixmap pix,pix1,pix2; //добавление изображений x^3..
    pix.load("/home/sabellus/qt project/L2/1.png");
    pix1.load("/home/sabellus/qt project/L2/2.png"); //чтение файлов изображений
    pix2.load("/home/sabellus/qt project/L2/3.png");
    ui->label_2->setPixmap(pix);
    ui->label_3->setPixmap(pix1);
    ui->label_4->setPixmap(pix2);
    ui->label_10->setPixmap(pix1);
    ui->label_11->setPixmap(pix2); //вывод изображений
    ui->label_13->setPixmap(pix2);
    ui->label_2->hide(); //скрытие рабочих объектов
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
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int n = 0; //счетчик
    if(!file.exists()){ //проверка существования файла
        qDebug() << "Файл не существует";
        return;
    }
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){ //проверка открытия файла
        qDebug() << "Файл не открыт";
        return;
    }
    file.seek(0); //установка курсора в начало файла
    while(!file.atEnd()){ //считываем размер файла
        QByteArray line = file.readLine();
        qDebug() << QString::fromUtf8(line);
        n++;
    }
    file.seek(0); //установка курсора в начало
    double a[n]; //массив ввода
    n = 0;
    while(!file.atEnd()){ //заполняем массив ввода
        QByteArray line = file.readLine();
        a[n] = line.toDouble();
        n++;
    }
    ui->lineEdit->setText(QString::number(a[0])); //вывод из файла на рабочие
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
    ui->lineEdit->show(); //показ рабочих объектов
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_5->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->label_9->show();
    ui->label_10->show();
    ui->label_11->show();
    ui->label_12->show();
    ui->label_13->show();
    ui->lineEdit_5->show();
    ui->lineEdit_6->show();
    ui->lineEdit_7->show();
    ui->lineEdit_8->show();
    ui->lineEdit_9->show();
    ui->lineEdit_10->show();
    ui->lineEdit_11->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    ui->pushButton_6->show();
    file.close();
}

double f[4];
double df[3];
double ddf[2];
double a,b;
double eps = pow(10,-6); //точность

double func (double x){
    double rez = f[0]*pow(x,3)+f[1]*pow(x,2)+f[2]*x+f[3];
    return rez;
}

double dfunc (double x){
    double rez = df[0]*pow(x,2)+df[1]*x+df[2];
    return rez;
}

double ddfunc (double x){
    double rez = ddf[0]*x + ddf[1];
    return rez;
}

double ddsign(double x){
    double rez = ddfunc(x)/abs(ddfunc(x));
    return rez;
}

double dsign(double x){
    double rez = dfunc(x)/abs(dfunc(x));
    return rez;
}

double ifunc (double x){
    double rez = 1/f[0]*cbrt(-f[1]*pow(x,2)-f[2]*x-f[3]);
    return rez;
}


void MainWindow::on_pushButton_2_clicked()
{
   QString str;
   str = ui->lineEdit_5->text();
   a = str.toDouble();
   str = ui->lineEdit_6->text();
   b = str.toDouble();
   str = ui->lineEdit->text();
   f[0] = str.toDouble();
   str = ui->lineEdit_2->text();
   f[1] = str.toDouble();
   str = ui->lineEdit_3->text();
   f[2] = str.toDouble();
   str = ui->lineEdit_4->text();
   f[3] = str.toDouble();
   str = ui->lineEdit_7->text();
   df[0] = str.toDouble();
   str = ui->lineEdit_8->text();
   df[1] = str.toDouble();
   str = ui->lineEdit_9->text();
   df[2] = str.toDouble();
   str = ui->lineEdit_10->text();
   ddf[0] = str.toDouble();
   str = ui->lineEdit_11->text();
   ddf[1] = str.toDouble();

   double x;
   double n[150][2];
   int c = 0;//флаг конца цикла
   int i = 0; //счетчик иттераций
   int k;
   if(func(a)*func(b) < 0){
       while(c != 1){
           if(func((a+b)/2) == 0){
               x = (a+b)/2;
               c = 1;
               break;
           }

           if(func(a)*func((a+b)/2) < 0){
               b = (a+b)/2;
           }
           else{
               a = (a+b)/2;
           }

           if(abs(a-b) < eps){
               c = 1;
           }
           n[i][0] = a;
           n[i][1] = b;
           i++;
       }
       x = (a+b)/2;
       ui->tableWidget->setRowCount(i);
       ui->tableWidget->setColumnCount(2);
       QStringList l;
       l << "a" << "b";
       ui->tableWidget->setHorizontalHeaderLabels(l);
       ui->tableWidget->show();
       ui->lineEdit_12->show();
       ui->label_14->show();
       ui->lineEdit_12->setText("x = "+QString::number(x));
       for(c = 0; c < i; c++){ //заполнение таблицы
               for(k = 0; k < 2; k++){
                       QTableWidgetItem *it = new QTableWidgetItem(QString::number(n[c][k]));
                       ui->tableWidget->setItem(c,k,it);
               }
           }
   }
   else{
       ui->label->setText("Не выполняется условие для a и b" );
   }
   ui->label_15->show();
   ui->label_15->setText("Метод дихотомий");
}



void MainWindow::on_pushButton_3_clicked() //метод хорд
{
    ui->tableWidget->hide(); //скрытие элементов
    ui->label_15->hide();
    ui->tableWidget->setColumnCount(0); //обнуление содержимого таблицы
    ui->tableWidget->setRowCount(0);
    QString str = ui->lineEdit_5->text();
    a = str.toDouble();
    str = ui->lineEdit_6->text();
    b = str.toDouble();
    int c = 0;
    int z,k;
    double ch;
    double x, x0;
    double n[150][2]; //массивы вывода
    double sign = ddsign(a); //сигнум в точке a
    int i = 0; //счетчик итераций
    for(z = a+10; z <= b+10; z++){ //проверка сохранения знака второй производной
        ch = z/10;
        if(sign + ddsign(ch) == 0){
            c = 1;
        }
    }

    if(c == 0){
        if(sign*func(b) >= 0){
            x0 = a;
            ch = 0;
        }
        else{
            x0 = b;
            ch = 1;
        }
        z = 0;
        while(z != 1){
            if(ch == 0){
                x = x0 - func(x0)/(func(b)-func(x0))*(b-x0);
            }
            else{
                x = a - func(a)/(func(x0)-func(a))*(x0-a);
            }
            if(abs(x - x0) < eps){
                z = 1;
            }
            n[i][0] = x0;
            n[i][1] = x;
            x0 = x;
            i++;
        }
    }
    else{
        ui->label->setText("Не выполняется условие для f''(x)" );
    }


    QStringList l;
    l << "Xn" << "Xn+1";
    ui->tableWidget->setRowCount(i);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(l);
    for(c = 0; c < i; c++){ //заполнение таблицы
            for(k = 0; k < 2; k++){
                    QTableWidgetItem *it = new QTableWidgetItem(QString::number(n[c][k]));
                    ui->tableWidget->setItem(c,k,it);
            }
        }
    ui->label_15->show();
    ui->label_15->setText("Метод хорд");
    ui->lineEdit_12->show();
    ui->tableWidget->show();
    ui->lineEdit_12->setText("x = "+QString::number(x));

}
void MainWindow::on_pushButton_4_clicked() //метод Ньютона
{
    ui->tableWidget->hide(); //скрытие элементов
    ui->label_15->hide();
    ui->tableWidget->setColumnCount(0); //обнуление таблицы
    ui->tableWidget->setRowCount(0);
    QString str = ui->lineEdit_5->text();
    a = str.toDouble();
    str = ui->lineEdit_6->text();
    b = str.toDouble();
    int z,i,c; //флаги и счетчики
    int c1 = 0; //флаг проверки знака первой производной
    int c2 = 0; //флаг проверки знака первой производной
    double ch; //буфер проверки знака производных
    double n1[150][2];
    double x,x0;

    double ds = dsign(a); //сигнум первой производной в точке а
    double dds = ddsign(a); //сигнум второй производной в точке а

    for(z = a+10; z <= b+10; z++){ //проверка сохранения знака первой производной
        ch = z/10;
        if(ds + dsign(ch) == 0){
            c1 = 1;
        }
    }
    for(z = a+10; z <= b+10; z++){ //проверка сохранения знака второй производной
        ch = z/10;
        if(dds + ddsign(ch) == 0){
            c2 = 1;
        }
    }

    if(c1+c2 == 0){
        if(func(a)*ds > 0){
            x0 = a;
        }
        else{
            x0 = b;
        }
        z = 0;
        i = 0;
        while(z != 1){
            x = x0 - func(x0)/dfunc(x0);
            if(abs(x0-x) < eps){
                z = 1;
            }
            n1[i][0] = x0;
            x0 = x;
            n1[i][1] = x;
            i++;
        }
    }
    else{
        ui->label->setText("Не выполняется условие на f'(x) или на f''(x)");
    }
    QStringList l;
    l << "Xn" << "Xn+1";
    ui->tableWidget->setRowCount(i);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(l);
    for(c = 0; c < i; c++){ //заполнение таблицы
            for(z = 0; z < 2; z++){
                    QTableWidgetItem *it = new QTableWidgetItem(QString::number(n1[c][z]));
                    ui->tableWidget->setItem(c,z,it);
            }
        }
    ui->label_15->show();
    ui->label_15->setText("Метод Ньютона");
    ui->lineEdit_12->show();
    ui->tableWidget->show();
    ui->lineEdit_12->setText("x = "+QString::number(x));



}


void MainWindow::on_pushButton_5_clicked()
{
    ui->tableWidget->hide(); //скрытие элементов
    ui->label_15->hide();
    ui->tableWidget->setColumnCount(0); //обнуление таблицы
    ui->tableWidget->setRowCount(0);
    QString str = ui->lineEdit_5->text();
    a = str.toDouble();
    str = ui->lineEdit_6->text();
    b = str.toDouble();
    int z,i,c; //флаги и счетчики
    int c1 = 0; //флаг проверки знака первой производной
    int c2 = 0; //флаг проверки знака первой производной
    double ch; //буфер проверки знака производных
    double n1[150][4]; //массивы вывода
    double x_,x0_,x,x0;

    double ds = dsign(a); //сигнум первой производной в точке а
    double dds = ddsign(a); //сигнум второй производной в точке а

    for(z = a+10; z <= b+10; z++){ //проверка сохранения знака первой производной
        ch = z/10;
        if(ds + dsign(ch) == 0){
            c1 = 1;
        }
    }
    for(z = a+10; z <= b+10; z++){ //проверка сохранения знака второй производной
        ch = z/10;
        if(dds + ddsign(ch) == 0){
            c2 = 1;
        }
    }
    if(c1+c2 == 0){
        if(func(a)*dds > 0){
            x0 = a;
            x0_ = b;
            z = 0;
            i = 0;
            while(z != 1){
                x = x0-func(x0)/dfunc(x0);
                x_ = x0 - func(x0)/(func(x0_)-func(x0))*(x0_-x0);

                if(abs(x-x_) < eps){
                    z = 1;
                }
                n1[i][0] = x0;
                n1[i][1] = x;
                n1[i][2] = x0_;
                n1[i][3] = x_;
                x0 = x;
                x0_ = x_;
                i++;
            }
        }
        else{
            x0 = a;
            x0_ = b;
            z = 0;
            i = 0;
            while(z != 1){
                x = x0 - func(x0)/(func(x0_)-func(x0))*(x0_-x0);
                x_ = x0_ - func(x0_)/dfunc(x0_);
                if(abs(x-x_) < eps){
                    z = 1;
                }
                n1[i][0] = x0;
                n1[i][1] = x;
                n1[i][2] = x0_;
                n1[i][3] = x_;
                x0 = x;
                x0_ = x_;
                i++;
            }
        }
    }
    else{
        ui->label->setText("Не выполняется условие на f'(x) или на f''(x)");
    }
    QStringList l;
    l << "Xn" << "Xn+1" << "_Xn" << "_Xn+1";
    ui->tableWidget->setRowCount(i);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(l);
    for(c = 0; c < i; c++){ //заполнение таблицы
            for(z = 0; z < 4; z++){
                QTableWidgetItem *it = new QTableWidgetItem(QString::number(n1[c][z]));
                ui->tableWidget->setItem(c,z,it);
            }
        }
    ui->label_15->show();
    ui->label_15->setText("Комбинирвоанный метод");
    ui->lineEdit_12->show();
    ui->tableWidget->show();
    ui->lineEdit_12->setText("x = "+QString::number(x_));
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->tableWidget->hide(); //скрытие элементов
    ui->label_15->hide();
    ui->tableWidget->setColumnCount(0); //обнуление таблицы
    ui->tableWidget->setRowCount(0);
    QString str = ui->lineEdit_5->text();
    a = str.toDouble();
    str = ui->lineEdit_6->text();
    b = str.toDouble();
    int z = 0; //флаг конца
    int i = 0; //счетчик
    double x0 = a;
    double x; //корень
    double n[150][2]; //массив вывода
    while(z != 1){
        x = ifunc(x0);
        if(abs(x - x0) < eps){
            z = 1;
        }
        n[i][0] = x0;
        n[i][1] = x;
        i++;
        x0 = x;
    }

    QStringList l;
    l << "Xn" << "Xn+1";
    ui->tableWidget->setRowCount(i);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(l);
    for(int c = 0; c < i; c++){ //заполнение таблицы
            for(z = 0; z < 2; z++){
                QTableWidgetItem *it = new QTableWidgetItem(QString::number(n[c][z]));
                ui->tableWidget->setItem(c,z,it);
            }
        }
    ui->label_15->show();
    ui->label_15->setText("Метод итераций");
    ui->lineEdit_12->show();
    ui->tableWidget->show();
    ui->lineEdit_12->setText("x = "+QString::number(x));

}

