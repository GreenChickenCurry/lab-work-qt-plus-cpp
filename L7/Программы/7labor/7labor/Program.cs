using System;

namespace _7labor
{
    class Program
    {
        static double Func(double x, double s) //функуия f
        {
            return Math.Cos(x + s) + Math.Cos(x - s);
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
                    Console.Write("{0:F3}    ", a[i, j]);
                }
                Console.WriteLine();
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
                    Console.Write("{0:F3}    ", a[i, j]);
                }
                Console.WriteLine();
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
                //Console.WriteLine("max = " + Math.Abs(max));
                //перемеotybt главного элемента и корекция корней
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
                    /*
                    //вывод после перемещения столбца
                    Console.WriteLine("После перемещения столбца");
                    for (int i = 0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            Console.Write(Math.Round(a[i, j], 6) + "\t");
                        }
                        Console.Write(" | " + Math.Round(w[i], 6));
                        Console.WriteLine();
                    }

                    */

                    //перемещение строки
                    for (int i = 0; i < size; i++)
                    {
                        vspomogMatrix[1, i] = a[indexX, i];
                        a[indexX, i] = a[k, i];
                        a[k, i] = vspomogMatrix[1, i];

                    }
                    //перемещение строки для свободных коэф.
                    vspomogMatrix[0, size - 1] = w[indexX];
                    w[indexX] = w[k];
                    w[k] = vspomogMatrix[0, size - 1];
                    /*
                    //вывод после перемещения строки
                    Console.WriteLine("После перемещения строки");
                    for (int i = 0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            Console.Write(Math.Round(a[i, j], 6) + "\t");
                        }
                        Console.Write(" | " + Math.Round(w[i], 6));
                        Console.WriteLine();
                    }
                    */
                };

                //нормирование k-ой строки
                w[k] = (double)w[k] / a[k, k];
                for (int j = size - 1; j >= 0; j--)
                {
                    a[k, j] = (double)a[k, j] / a[k, k];

                }

                //вычитание к-ой строки по всей матрице
                for (int i = k + 1; i < size; i++)
                {
                    w[i] = w[i] - w[k] * a[i, k];
                    for (int j = size - 1; j >= 0; j--)
                    {

                        // myMatrix[i, j] = myMatrix[i, j] - myMatrix[k, j] * (myMatrix[i, k] / myMatrix[k, k]);
                        a[i, j] = a[i, j] - (a[k, j] * a[i, k]);
                    }
                }

                /*
                //вывод расширеной матрицы
                Console.WriteLine("Вывод после нормирование главной строки и вычета ее из других строк");
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        Console.Write(Math.Round(myMatrix[i, j], 6) + "\t");
                    }
                    Console.Write(" | " + Math.Round(b[i], 6));
                    Console.WriteLine();
                }
                Console.WriteLine();
                */
            }
            /*
            Console.WriteLine();
            Console.WriteLine("Обратных ход. Получили треугольную матрицу:");
            Console.WriteLine();
            */
           /*
            //вывод получивщейся матрицы
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    Console.Write(Math.Round(a[i, j], 6) + "\t");
                }
                Console.Write(" | " + Math.Round(w[i], 6));
                Console.WriteLine();
            }
           */
            //обратных ход
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
            Console.WriteLine();

            //вывод корней
            Console.WriteLine("Решение уравнения Фредгольма второго рода:");
            Console.WriteLine("Значения yi:");
            for (int i = 0; i < size; i++)
            {
                Console.WriteLine("y[" + (nomerKorni[i]-1) + "] = " + xx[i]);
            }

            Console.WriteLine();
            Console.WriteLine("После сортировки");
            for (int i = 0; i <= size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (i== nomerKorni[j])
                    {
                        Console.WriteLine("y[" + (nomerKorni[j]-1) + "] = " + xx[j]);
                    }
                    
                }
            }
            
            Console.ReadLine();



            
        }
    }
}
