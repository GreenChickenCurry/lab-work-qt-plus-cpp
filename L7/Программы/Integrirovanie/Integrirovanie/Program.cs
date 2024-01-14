using System;

namespace Integrirovanie
{
    class Program
    {
        const double a = 1.2;
        const double b = 2;

        static double F(double x) //функция
        {
            return (x - 0.5) / Math.Sqrt(Math.Pow(x, 2) - 1);
        }

        static double Trapecia(int n) //по формуле трапеции
        {
            double h = (b - a) / n;
            double res = 0;
            double x = a;
            res = (F(a) + F(b)) / 2;
            for (int i = 1; i < n; i++)
            {
                x = x + h;
                res = res + F(x);
            }
            //x = x + h;
            return h * res;
        }

        static double Simpson(int n) //по формуле Симпсона
        {
            double h = (b - a) / n;
            double res = 0;
            double x = a;
            res = F(a) + F(b);
            for (int i = 1; i <= n - 1; i = i + 2)
            {
                x = x + h;
                res = res + 4 * F(x);
                if (i <= n - 2)
                {
                    x = x + h;
                    res = res + 2 * F(x);
                }

            }
            /*x = a - h;
            for (int i = 2; i < n-2; i = i + 2)
            {
                x = x + 2 * h;
                res = res + 4 * F(x);
            }
            */
            return res * (h / 3);
        }

        static double Gauss(int n)
        {
            double res = 0;
            double[] t = new double[5];
            double[] C = new double[5];
            double x = 0;
            if (n == 4)
            {
                C[0] = 0.34785;
                C[1] = 0.65215;
                C[2] = C[1];
                C[3] = C[0];
                t[0] = -0.86114;
                t[1] = -0.33998;
                t[2] = -t[1];
                t[3] = -t[0];
            }
            else
            {
                C[0] = 0.23693;
                C[1] = 0.47863;
                C[2] = 0.56889;
                C[3] = C[1];
                C[4] = C[0];
                t[0] = -0.90618;
                t[1] = -0.53847;
                t[2] = 0;
                t[3] = -t[1];
                t[4] = -t[0];
            }
            Console.WriteLine("i" + "\t" + "Ci" + "\t" + "ti" + "\t" + "  xi" + "\t" + " f(xi)" + "\t" + " Ci*f(xi)");
            for (int i = 0; i < n; i++)
            {
                x = (b + a) / 2 + ((b - a) / 2) * t[i];
                /*
                Console.WriteLine("C[{0}]={1}, t[{0}]={2,0:f5}, x[{0}]={3,0:f5}, f(x[{0}])={4,0:f5}, C[{0}]f(x[{0}])={5,0:f5}",
                    i + 1, C[i], t[i], x, F(x), C[i] * F(x));
                */
                Console.WriteLine("{0}:  {1}  {2,0:f5}  {3,0:f5}  {4,0:f5}  {5,0:f5}",
                    i + 1, C[i], t[i], x, F(x), (C[i] * F(x)));
                res = res + C[i] * F(x);
            }
            Console.WriteLine("Ответ:");
            Console.WriteLine("I = "+ Math.Round(res * (b - a) / 2, 9));
            return res * (b - a) / 2;
        }

        static double Runge(int m, int n2, double I1, double I2) //Рунге
        {
            int n1 = n2 / 2;
            return I2 + (Math.Pow(n1, m) / (Math.Pow(n2, m) - Math.Pow(n1, m))) * (I2 - I1);
        }


        static void Main(string[] args)
        {
            //Задание 1
            int n1 = 10;//начальное число шагов
            double E = 0.00001; //точность
            Console.WriteLine("Значение интеграла по формуле трапеций:");
            int k1 = 1; //число шагов
            double RI = 0;
            double I1 = 0;
            double I2 = Trapecia(n1);


            while (Math.Abs(I1 - I2) > E) //выполняем пока не достигнем требуемая точность
            {
                n1 = n1 * 2; //удвоение разбиения отрезка
                I1 = I2;
                I2 = Trapecia(n1);
                k1++;
                Console.WriteLine(" n1=" + n1 / 2 + ":I1 = " + Math.Round(I1, 9)+ "; n2=" + n1 + ":  I2 = " + Math.Round(I2, 9));
            }
            //вывод ответа
            Console.WriteLine("Ответ:");
            Console.WriteLine("I2 = " + Math.Round(I2, 9));
            Console.WriteLine("Число шагов: " + k1);
            RI = Runge(2, k1, I1, I2);
            Console.WriteLine("I(по Рунге) = " + Math.Round(RI, 9));
            Console.WriteLine();

            //Задание 2
            Console.WriteLine("Значение интеграла по формуле Симпсона:");
            int n2 = 10;//начальное число шагов
            int k2 = 1; //число шагов
            I1 = 0;
            I2 = Simpson(n2);
            while (Math.Abs(I1 - I2) > E) //выполняем пока не достигнем требуемая точность
            {
                n2 = n2 * 2; //удвоение разбиения отрезка
                I1 = I2;
                I2 = Simpson(n2);
                k2++;
                Console.WriteLine(" n1=" + n2 / 2 + ":I1 = " + Math.Round(I1, 9) + "; n2=" + n2 + ":  I2 = " + Math.Round(I2, 9));
                //Console.WriteLine("I1 = " + Math.Round(I1, 9) + ";  I2 = " + Math.Round(I2, 9));
            }
            //вывод ответа
            Console.WriteLine("Ответ:");
            Console.WriteLine("I2 = " + Math.Round(I2, 9));
            Console.WriteLine("Число шагов: " + k2);
            RI = 0;
            RI = Runge(4, k1, I1, I2);
            Console.WriteLine("I(по Рунге) = " + Math.Round(RI, 9));
            Console.WriteLine();

            //Задание 3
            Console.WriteLine("Значение интеграла по формуле Гаусса:");
            Console.WriteLine("При n = 4:");
            Gauss(4);
            Console.WriteLine();
            Console.WriteLine("При n = 5:");
            Gauss(5);
            Console.ReadLine();



        }
    }
}
