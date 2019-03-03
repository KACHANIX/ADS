using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace _4
{
    class Program
    {
        public static void Quicksort(int[] elements, int left, int right, int k1, int k2)
        {
            if (left > k2 || right < k1) return;
            int i = left, j = right;
            int pivot = elements[(left + right) / 2];

            while (i <= j)
            {
                while (elements[i].CompareTo(pivot) < 0)
                {
                    i++;
                }

                while (elements[j].CompareTo(pivot) > 0)
                {
                    j--;
                }

                if (i <= j)
                {
                    int tmp = elements[i];
                    elements[i] = elements[j];
                    elements[j] = tmp;

                    i++;
                    j--;
                }
            }

            if (left < j)
            {
                Quicksort(elements, left, j, k1, k2);
            }

            if (i < right)
            {
                Quicksort(elements, i, right, k1, k2);
            }
        }


        static void Main(string[] args)
        {
            int n, k1, k2;
            int A, B, C;
            int[] a;
            using (StreamReader sr = new StreamReader("input.txt"))
            {
                string[] FirstLine = sr.ReadLine().Split();
                n = int.Parse(FirstLine[0]);
                k1 = int.Parse(FirstLine[1]) - 1;
                k2 = int.Parse(FirstLine[2]) - 1;
                string[] SecondLine = sr.ReadLine().Split();
                A = int.Parse(SecondLine[0]);
                B = int.Parse(SecondLine[1]);
                C = int.Parse(SecondLine[2]);
                a = new int[n];
                a[0] = (int.Parse(SecondLine[3]));
                a[1] = (int.Parse(SecondLine[4]));
            }
            for (int i = 2; i < n; i++)
            {
                a[i] = (A * a[i - 2] + B * a[i - 1] + C);
            }


            using (StreamWriter sw = new StreamWriter("output.txt"))
            {
                Quicksort(a, 0, n - 1, k1, k2);
                for (int i = k1; i <= k2; i++)
                {
                    sw.Write($"{a[i]} ");
                }
            }
        }
    }
}
