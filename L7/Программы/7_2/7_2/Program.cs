using System;

namespace _7_2
{
    class Program
    {
        const int n = 10;
        static double Func(double x, double s)
        {
            return Math.Cos(x + s) + Math.Cos(x - s);
        }

        static void Main(string[] args)
        {
            double[] y = new double[n + 1];
            double[] x = new double[n + 1];
            double a = 0, b = Math.PI; //отрезок
            double h=(b-a)/n, sum=0; //находим шаг
            double alfa = -1 * 0.5 * Math.PI;
            for (int i = 0; i <= n; i++)
            {
                x[i] = Math.Cos((a + i * h));
            }  
            y[0] = x[0]; //нулевое значение
            y[1] = (x[1] + (alfa * h * Func(x[1], x[0]) * y[0]) / 2) / (1 - (alfa * h * Func(x[1], x[1])) / 2); //первое значение

            for (int i = 2; i <= n; i++)
            {
                for (int j = 0; j <= i - 1; j++)
                {
                    sum = sum + Func(x[i], x[j]) * y[j];
                }

            y[i] = (x[i] + (alfa * h * (Func(x[i], x[0]) * y[0] + 2 * sum)) / 2) / (1 - (alfa * h * Func(x[i], x[i])) / 2); //2,3,...n-значение
            };
            //вывод знаений
            Console.WriteLine("Решение уравнения Вольтерра второго рода:");
            Console.WriteLine("Значения yi:");
            for (int i = 0; i <= n; i++)
            {
                Console.WriteLine("y[" + i + "] : " + y[i]);
            };

            Console.ReadKey();
        }
    }
}
