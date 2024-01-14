using System;

namespace Koshi
{
    class Program
    {
        static double f(double x, double y) //функция f
        {
            return (y - 1) * x;
        }

        static double Vishiclenia(double h, double x, double y, double b, double[] y2) //Метод Эйлера (ломанных)
        {
            int i = 0;
            Console.WriteLine("X[{0}] = {1:f3} Y[{0}] = {2,3:f6}", i, x, y);
            int n = (int)Math.Round((b - x) / h); //нагодим число разбиений
            double[] y1 = new double[(n+1)];
            while (x <= b)
            {
                y+=  h * f(x, y);
                x +=  h;
                i++;
                y1[i] = y;
                Console.WriteLine("X[{0}] = {1:f3} Y[{0}] = {2,3:f6}", i, x, y);
            }
            return y1[i];
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Решение задачи Коши методом Эйлера");
            //нач. условия
            double x0 = 1; 
            double y0 = 1.5;

            double x = x0;
            double b = x + 1;
            double y = y0;
            double h = 0.1; //шаг
            Console.WriteLine();
            Console.WriteLine("h = {0}", h);
            int n = (int)Math.Round((b - x) / h);
            double[] y1 = new double[(n+1)];
            int i = 0;
            y1[0] = y;

            while (x <= b)
            {
                y = y + h * f(x, y);
                x = x + h;
                i++;
                y1[i] = y;
                Console.WriteLine("X[{0}] = {1:f2} Y[{0}] = {2,3:f6}", i, x, y);
            }

            //Вычисления с шагом 0.05
            h = h / 2;
            Console.WriteLine();
            Console.WriteLine("h = {0}", h);
            double x1 = x0;
            n = (int)Math.Round((b - x1) / h);
            double[] y2 = new double[(n+1)];
            i = 0;
            double yy = y0;
            y2[0] = y;
            while (x1 <= b)
            {
                yy = yy + h * f(x1, yy);
                x1 = x1 + h;
                i++;
                y2[i] = yy;
                Console.WriteLine("X[{0}] = {1:f2} Y[{0}] = {2,3:f6}", i, x1, yy);
            }

            Console.WriteLine();
            Console.WriteLine("Оценка по правилу Рунге: ");
            x = x0;
            h = 0.1;
            for (i = 1; i <= 10; i++)
            {
                x = x + h;
                y = y2[2 * i] + (y2[2 * i] - y1[i])/(Math.Pow(2,2)-1);
                Console.WriteLine("X[{0}] = {1:f2} Y[{0}] = {2,3:f6}", i, x, y);
            }



            /*
            //double[] y1 = new double[21], y2 = new double[21];
            //Вычисления с шагом 0.1
            Console.WriteLine("h = {0}", h);
            Vishiclenia(h, x0, y0, b,y1);
            //Вычисления с шагом 0.05
            Console.WriteLine();
            h = h / 2;
            Console.WriteLine("h = {0}", h);
            Vishiclenia(h, x0, y0, b,y2);
            */

            Console.ReadKey();
            
        }
    }
}
