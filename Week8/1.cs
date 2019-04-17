using System.Collections.Generic;
using System.Collections.Generic;
using System.IO;

namespace PlayZoneADS
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamWriter sw = new StreamWriter("output.txt"))
            {
                string[] input = File.ReadAllLines("input.txt");
                var ts = new SortedSet<long>();

                for (int i = 1; i < input.Length; i++)
                {
                    long number = long.Parse(input[i].Split(' ')[1]);
                    switch (input[i][0])
                    {
                        case 'A':
                            ts.Add(number);
                            break;
                        case 'D':
                            ts.Remove(number);
                            break;
                        case '?':
                            if (ts.Contains(number))
                                sw.WriteLine("Y");
                            else
                                sw.WriteLine("N");
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
}
