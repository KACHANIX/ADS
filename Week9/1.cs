using System;
using System.Collections.Generic;
using System.IO;

namespace PlayZoneADS
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> occuranceList = new List<int>();
            int counter = 0;

            using (StreamWriter sw = new StreamWriter("output.txt"))
            {
                string[] input = File.ReadAllLines("input.txt");

                string pattern = input[0];
                string searchString = input[1];


                int M = pattern.Length;
                int N = searchString.Length;

                for (int i = 0; i <= N - M; i++)
                {
                    int j;
                    for (j = 0; j < M; j++)
                        if (searchString[i + j] != pattern[j])
                            break;
                    if (j == M)
                    {
                        counter++;
                        occuranceList.Add(i);
                    }
                }

                sw.WriteLine(counter);
                foreach (int a in occuranceList)
                {
                    sw.Write($"{a + 1} ");
                }
            }
        }
    }
}
