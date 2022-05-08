using System;

namespace Question
{
    class Program
    {
        static void Main()
        {
            string first = Console.ReadLine();
            int fNum = int.Parse(first);

            string second = Console.ReadLine();
            int sNum = int.Parse(second);

            Console.WriteLine(fNum * (sNum % 10));
            Console.WriteLine(fNum * ((sNum % 100) / 10));
            Console.WriteLine(fNum * (sNum / 100));
            Console.WriteLine(fNum * sNum);
        }
    }
}