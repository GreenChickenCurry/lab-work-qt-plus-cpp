#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
QFile file("/home/sabellus/qt project/L4/init.txt"); //подключение файла

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->hide(); //скрытие рабочих элементов
    ui->label_2->hide();
    ui->label_3->hide();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->tableWidget->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit_6->hide();
    ui->tableWidget_2->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

double a[21];
double eps = pow(10,-5);
int j = 0;
double func(double x){
    double res = sqrt(pow(x,2)+1)/(x+2);
    return res;

}
double in[150][3][5];
double rung(double i1, double n1, double i2, double n2, double m){
    double res = i2 + (pow(n1,m))/(pow(n2,m) - pow(n1,m))*(i2-i1);
    return res;
}
double xi(double a, double b, double t){
    double res = (a+b)/2 + (t*(b-a))/2;
    return res;
}
void MainWindow::on_pushButton_clicked()
{
    ui->label->show(); //показ рабочих элементов
    ui->label_2->show();
    ui->label_3->show();
    ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    int n1 = 0; //счетчик
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
                 a[n1] = line.toDouble();
                 n1++;
             }
     ui->lineEdit->setText(QString::number(a[0]));
     ui->lineEdit_2->setText(QString::number(a[1]));
     ui->lineEdit_3->setText(QString::number(a[2]));
     //qDebug() << QString("%1").arg(func(12), 0, 'g', 30);
     file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    double h; //шаг
    QString cl;
    cl = ui->lineEdit->text();
    a[0] = cl.toDouble();
    cl = ui->lineEdit_2->text();
    a[1] = cl.toDouble();
    cl = ui->lineEdit_3->text();
    a[2] = cl.toDouble();
    double c = a[0]; //буфер для начала цикла
    int k = 0; //счетчик побочного цикла
    double sum[2]; //массив интегралов
    int z = 0; //флаг конца цикла
    sum[0] = 0;
    sum[1] = 0;
    int n = 0; //счетчик итераций
    while(z != 1){
    h = (a[1] - a[0])/a[2]; //задание шага
    while(c < a[1]){
            if(k == 0){
                sum[0] = sum[0] + func(c)/2; //первый элемент суммы
                c = c + h;
                k++;
            }
            if(k != 0 && k != a[2]){
                sum[0] = sum[0] + func(c);
                c = c+h;
                k++;
            }
            if(k == a[2]){
                sum[0] = sum[0] + func(c)/2; //последний элемент суммы
                break;
            }
    }
    sum[0] = h*sum[0];
    in[n][0][0] = sum[1]; //заполнение массива вывода
    in[n][1][0] = sum[0];
    in[n][2][0] = a[2];
    if(abs(sum[1] - sum[0]) < eps){ //проверка на достижение точности
        z = 1;
        n++;
        break;
    }
    sum[1] = sum[0];
    k = 0;
    n++;
    a[2] = a[2]*2; //увеличение разбиения
    c = a[0];
    sum[0] = 0;
    }
    ui->tableWidget->show(); //показ рабочих элементов и настройка таблицы
    ui->tableWidget->setRowCount(n);
    ui->tableWidget->setColumnCount(3);
    QStringList l;
    l << "I1" << "I2" << "Шаги";
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
    ui->label_4->show();
    ui->label_5->show();
    ui->lineEdit_4->setText(QString::number(sum[0])); //вывод ответа
    ui->lineEdit_5->setText(QString::number(rung(sum[0],in[n-1][2][0],sum[1],in[n-2][2][0],2),'g',6)); //вывод оценки Рунге
    ui->tableWidget->setHorizontalHeaderLabels(l);
    for(k = 0; k < n; k++){ //заполнение таблицы
                       for(j = 0; j < 3; j++){
                               QTableWidgetItem *it = new QTableWidgetItem(QString::number(in[k][j][0]));
                               ui->tableWidget->setItem(k,j,it);
                       }
     }
}

void MainWindow::on_pushButton_3_clicked()
{
    double h; //шаг
    ui->tableWidget->setRowCount(0);
    double c = a[0]; //буфер для начала цикла
    int k = 0; //счетчик побочного цикла
    double sum[2]; //массив интегралов
    int z = 0; //флаг конца цикла
    sum[0] = 0;
    sum[1] = 0;
    QString cl;
    cl = ui->lineEdit->text();
    a[0] = cl.toDouble();
    cl = ui->lineEdit_2->text();
    a[1] = cl.toDouble();
    cl = ui->lineEdit_3->text();
    a[2] = cl.toDouble();
    int n = 0; //счетчик итераций
    while(z != 1){
        h = (a[1] - a[0])/a[2]; //задание шага
    while(c <= a[1]){
        if(k == 0){
            sum[0] = sum[0] + func(c);
            c = c + h;
            k++;
        }
        if(k != 0 && k % 2 == 0 && k != a[2]){
            sum[0] = sum[0] + 2*func(c);
            c = c + h;
            k++;
        }
        if(k != 0 && k % 2 == 1){
            sum[0] = sum[0] + 4*func(c);
            c = c + h;
            k++;
        }
        if(k == a[2]){
           sum[0] = sum[0] + func(c);
           c = c+h;
        }
    }
    sum[0] = (sum[0]/3)*h;
    in[n][0][1] = sum[0]; //заполнение массива вывода
    in[n][1][1] = sum[1];
    in[n][2][1] = a[2];
    if(abs(sum[1] - sum[0]) < eps){ //проверка на достижение точности
        z = 1;
        n++;
        break;
    }
    sum[1] = sum[0];
    k = 0;
    n++;
    a[2] = a[2]*2;
    c = a[0];
    sum[0] = 0;
    }

    ui->tableWidget->setRowCount(n);
    ui->lineEdit_4->setText(QString::number(sum[0])); //вывод ответа
    ui->lineEdit_5->setText(QString::number(rung(sum[0],in[n-1][2][1],sum[1],in[n-2][2][1],4),'g',6)); //вывод оценки Рунге
    for(k = 0; k < n; k++){ //заполнение таблицы
                       for(j = 0; j < 3; j++){
                               QTableWidgetItem *it = new QTableWidgetItem(QString::number(in[k][j][1]));
                               ui->tableWidget->setItem(k,j,it);
                       }
     }
}


void MainWindow::on_pushButton_4_clicked()
{
    double cof[5][5][2]; //массив коэффициентов сi и ti
    int i = 0; //индекс для переноса
    ui->tableWidget_2->show(); //показ и скрытие рабочих элементов
    ui->lineEdit_4->show();
    ui->label_4->show();
    ui->label_5->hide();
    ui->lineEdit_5->hide();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->lineEdit_6->show();
    ui->tableWidget->show();
    ui->tableWidget->setRowCount(0); //перезагрузка таблицы
    QString cl;
    cl = ui->lineEdit->text(); //считывание с рабочих элементов
    a[0] = cl.toDouble();
    cl = ui->lineEdit_2->text();
    a[1] = cl.toDouble();
    cl = ui->lineEdit_3->text();
    a[2] = cl.toDouble();
    for(j = 3; j < 7; j++){ //заполнение массивов коэффициентов из файла
        cof[i][0][0] = a[j];
        i++;
    }
    i = 0;
    for(j = 7; j < 11; j++){
        cof[i][1][0] = a[j];
        i++;
    }
    i = 0;
    for(j = 11; j < 16; j++){
        cof[i][0][1] = a[j];
        i++;
    }
    i = 0;
    for(j = 16; j < 21; j++){
        cof[i][1][1] = a[j];
        i++;
    }
    ui->tableWidget->setRowCount(4); //задание размерности таблицы
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget_2->setRowCount(5);
    ui->tableWidget_2->setColumnCount(4);
    double sum[2];
    sum[0] = 0;
    sum[1] = 0;
    for(j = 0; j < 4; j++){ //вычисление по алгоритму Гаусса для n=4
        cof[j][2][0] = xi(a[0],a[1],cof[j][1][0]);
        cof[j][3][0] = func(cof[j][2][0]);
        cof[j][4][0] = cof[j][0][0]*cof[j][3][0];
        sum[0] = sum[0] + cof[j][4][0];
    }
    sum[0] = (sum[0]/2)*(a[1]-a[0]); //результат n = 4
    for(j = 0; j < 5; j++){ //вычисление по алгоритму Гаусса для n=5
        cof[j][2][1] = xi(a[0],a[1],cof[j][1][1]);
        cof[j][3][1] = func(cof[j][2][1]);
        cof[j][4][1] = cof[j][0][1]*cof[j][3][1];
        sum[1] = sum[1] + cof[j][4][1];
    }
    sum[1] = (sum[1]/2)*(a[1]-a[0]); //результат n = 5
    for(j = 0; j < 4; j++){ //заполнение таблицы 1
                       for(i = 0; i < 4; i++){
                               QTableWidgetItem *it = new QTableWidgetItem(QString::number(cof[j][i][0]));
                               ui->tableWidget->setItem(j,i,it);
                       }
    }
    for(j = 0; j < 5; j++){ //заполнение таблицы 2
                       for(i = 0; i < 4; i++){
                               QTableWidgetItem *it = new QTableWidgetItem(QString::number(cof[j][i][1]));
                               ui->tableWidget_2->setItem(j,i,it);
                       }
    }
    QStringList l; //переменная легенды
    l << "Ci" << "Ti" << "xi" << "f(xi)"; //заполнение легенды
    ui->tableWidget->setHorizontalHeaderLabels(l);
    ui->tableWidget_2->setHorizontalHeaderLabels(l);
    ui->lineEdit_4->setText(QString::number((sum[0]),'g',8)); //вывод
    ui->lineEdit_6->setText(QString::number((sum[1]),'g',8));
}

