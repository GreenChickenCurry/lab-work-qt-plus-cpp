using System;

namespace Neyavnaicxema
{
    class Program
    {
        static double Ksi1(double x)
        {
            return 0;
        }
        static double Ksi2(double x)
        {
            return 1/5;
        }
        static double Fi(double x)
        {
            return (x+1)*Math.Sin(Math.PI*x);
        }

        static double Maximum(double[] u0, double[] u1, int N)
        {
            double max = Math.Abs(u1[0] - u0[0]);
            for (int i = 1; i < N; i++)
            {
                if (Math.Abs(u1[i] - u0[i]) > max)
                {
                    max = Math.Abs(u1[i] - u0[i]);
                }
            }
            return max;
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Неявная схема для уравнения теплопроводности");
            double a = 1, c = 1, coef_a=1, E=0.0001, h=0.1;
            int N_max = 10;
            double tau = h *h;
            double s = (double)(h * h) / (coef_a * tau);
            int N = (Convert.ToInt32(1 / h))+1;
            //Console.WriteLine(Convert.ToInt32(1 / h));
           
            double xi = 0, bi = -1 * (2 + s), t = 0;
            double[] u1 = new double[(N_max + 1)]; //массив для новый значений
            double[] u0 = new double[(N_max + 1)]; //массив для предыдущих значений
            double[] p = new double[(N_max + 1)]; //массивы для прогононых коэф.
            double[] q = new double[(N_max + 1)];
            int k=0; //кол-во шагов
            //вычисляем значения на нулевом слое
            for (int i = 0; i < N; i++)
            {
                xi = i * h;
                u1[i]= Fi(xi);
            }

            Console.WriteLine("n= " + k);
            for (int i = 0; i < N; i++)
            {
                Console.WriteLine("u[" + i + "]=" + u1[i]);
            }
            //p[0] = 0;
            //u1[0] = Ksi1(t);
            //u1[N-1] = Ksi2(t);
            //p[0] = 0;
            while (Maximum(u0,u1,N) > E)
            {
                //передача знаений найденых значений предыдущим
                for (int i = 0; i < N; i++)
                {
                    u0[i] = u1[i];
                }

                k = k + 1;
                t = k * tau;
                //s = (double)(h * h) / (coef_a * tau);
                //bi = -2 + s;
                p[0] = 0;
                //u1[0] = Ksi1(t);
                u1[N-1] = Ksi2(t);
                //нач.прогоночные коэф.
                //p[0] = 1 / bi;
                
                //q[0] = s*u0[0]/ bi;
                q[0] = Ksi1(t);

                //прогоночные коэф.
                for (int i = 1; i < N; i++)
                {
                    double d = -s * u0[i];
                    q[i] = (d - a * q[i - 1]) / (a * p[i - 1] + bi);
                    p[i] = -c / (a * p[i - 1] + bi);
                    //p[i] = -1 / (p[i - 1] - bi);
                    //q[i] = (-s*u0[i] - q[i - 1]) / (p[i - 1] - bi);
                }


                for (int i = 0; i < N ; i++)
                {
                    //Console.WriteLine(i+" "+p[i] + "  " + q[i]);
                }

                //u1[N-1] = (-s * u0[N -2] - q[N - 2]) / (p[N - 2] - bi);
                //Console.WriteLine(u1[N-2]);
                //нахождение неизвестных
                u1[N - 1] = q[N-1];
                for (int i = N-2; i <= 1; i--)
                {
                    u1[i] = p[i] * u1[i + 1] + q[i];
                    
                }
                /*
                for (int i = 0; i < N; i++)
                {
                    Console.WriteLine(u1[i]);
                }
                */
                if (k>300)
                {
                    Console.WriteLine("No");
                    break;
                }

                Console.WriteLine();
                Console.WriteLine("n= " + k);
                for (int i = 0; i < N; i++)
                {
                    Console.WriteLine("u["+i+"]="+u1[i]);
                }
                Console.WriteLine("Погрешность (E): "+Math.Round(Maximum(u0, u1, N),7));
            }


            Console.WriteLine("------------");
            Console.WriteLine("Приближенное значение решения функции для уравнения теплопроводности");
           /*
            for (int i = 0; i < N; i++)
            {
                Console.WriteLine(i+"  "+u0[i]);
            }
           */
            for (int i = 0; i < N ; i++)
            {
                Console.WriteLine("u[" + i + "]=" + u1[i]);
            }
            Console.WriteLine("Кол-во шагов n: "+k);
            Console.WriteLine(Maximum(u0, u1, N));
            Console.ReadKey();
        }
    }
}
