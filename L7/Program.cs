using System;

namespace L7
{
    class Program
    {
        static double Func(double x, double s) //оператор
        {
            return  s*Math.Sin(x);
        }

        static void Main(string[] args)
        {
            double[,] a = new double[12, 12];
            double[] x = new double[12];
            double[] y = new double[12];
            //double aa, bb, b, c, h;
            int n, p;
            n = 10;
            double b = 0; //начало отрезка

            double c = Math.PI; //конец отрезка
            double h = (c - b) / n;
            double alfa = -0.5 * Math.PI; //альфа
            for (int i = 0; i <= n; i++) //заполняем последний столбец матрицы(находим свободные коэф.)
            {
                x[i] = b + i * h;
                a[i, n + 1] = Math.Cos(x[i]);

            }

            for (int i = 0; i <= n; i++) //находим элементы матрицы(коэф. перед неизвеными) 
            {
                for (int j = 0; j <= n; j++)
                {
                    a[i, j] = -1 * alfa * h * (Func(x[i], x[j]));
                }
            }

            //выводим матрицу
            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= n + 1; j++)
                {
                    UI.Write("{0:F3}    ", a[i, j]);
                }
                UI.WriteLine();
            }

            for (int i = 0; i <= n; i++)
            {
                a[i, 0] = a[i, 0] / 2;
                a[i, n] = a[i, n] / 2;
                a[i, i] = a[i, i] + 1;
            };

            //выводим матрицу
            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= n + 1; j++)
                {
                    UI.Write("{0:F3}    ", a[i, j]);
                }
                UI.WriteLine();
            }

            
            int size = n + 1;
            double[] w = new double[size];
            for (int j = 0; j <= n; j++)
            {
                w[j] = a[j, n + 1];
            }

            //находим решения системы с помощью метода Гаусса
            int[] nomerKorni = new int[size]; //массив для корекции корней 
            for (int j = 0; j < size; j++)
            {
                nomerKorni[j] = j + 1;
            }
            //главный элемент(находм главный элемент и перемещаем 
            //его в левый верхний угол соотвествующего минора

            double max = a[1, 1];
            //Находим главный элемент и его координаты
            for (int k = 0; k < size; k++)
            {
                int indexX = 0;
                int indexY = 0;
                max = a[k, k];

                for (int i = k; i < size; i++)
                {
                    for (int j = k; j < size; j++)
                    {
                        if (Math.Abs(a[i, j]) > Math.Abs(max))
                        {
                            max = a[i, j];
                            indexX = i;
                            indexY = j;

                        }
                    }
                }
                if (a[k, k] != max)
                {
                    double[,] vspomogMatrix = new double[2, size];
                    //перемещение столбца
                    for (int i = 0; i < size; i++)
                    {
                        vspomogMatrix[0, i] = a[i, indexY];
                        a[i, indexY] = a[i, k];
                        a[i, k] = vspomogMatrix[0, i];
                        //
                    }
                    //корекция корней
                    p = nomerKorni[k];
                    nomerKorni[k] = nomerKorni[indexY];
                    nomerKorni[indexY] = p;

            double[] xx = new double[size]; //массив для значений
            for (int i = size - 1; i >= 0; i--)
            {

                double Sum = 0;
                for (int j = i + 1; j < size; j++)
                {
                    if (i > j)
                    {
                        Sum = Sum + a[i, j] * a[j, j];
                    }
                    else
                    {
                        Sum = Sum + a[i, j] * xx[j];
                    }

                };
                xx[i] = w[i] - Sum;
            }
            UI.WriteLine();

            //вывод корней
            for (int i = 0; i < size; i++)
            {
                UI.WriteLine("y[" + (nomerKorni[i]-1) + "] = " + xx[i]);
            }

            UI.WriteLine();
            UI.WriteLine("После сортировки");
            for (int i = 0; i <= size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (i== nomerKorni[j])
                    {
                        UI.WriteLine("y[" + (nomerKorni[j]-1) + "] = " + xx[j]);
                    }
                    
                }
            }
            
            UI.ReadLine();



            
        }
    }
}
