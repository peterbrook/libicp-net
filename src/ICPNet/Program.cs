using System;
using icp_net;

namespace ICPTest
{
    class Program
    {
        static void Main(string[] args)
        {
            int dim = 3;
            int M_num = 10000;
            int T_num = 10000;

            double[,] M = new double[M_num, 3];
            double[,] T = new double[T_num, 3];
            int k = 0;
            for (double x = -2; x < 2; x += 0.04)
            {
                for (double y = -2; y < 2; y += 0.04)
                {
                    double z = 5 * x * Math.Exp(-x * x - y * y);
                    M[k, 0] = x;
                    M[k, 1] = y;
                    M[k, 2] = z;
                    T[k, 0] = x - 1;
                    T[k, 1] = y - 1;
                    T[k, 2] = z - 1;
                    k++;
                }

            }
            icp_net.ManagedICP m = new ManagedICP(M, M_num, dim);

            double[,] R = new double[3, 3];
            R[0, 0] = 1.0;
            R[1, 1] = 1.0;
            R[2, 2] = 1.0;

            double[] t = new double[3];

            m.fit(T, T_num, R, t, -1);

            Console.WriteLine("Transformation Results:");
            Console.WriteLine("R:" + R);
            Console.WriteLine("T:" + t[0] + " " + t[1] + " " + t[2]);
            Console.Read();
        }
    }
}
