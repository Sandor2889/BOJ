using System;

namespace Question
{
    class Program
    {
        static void Main()
        {
            int answer = 0;
            string[] inputs = Console.ReadLine().Split(' ');
            int[] dices = Array.ConvertAll(inputs, int.Parse);

            if (dices[0] == dices[1] && dices[1] == dices[2])
            {
                answer = 10000 + (dices[0] * 1000);
                Console.Write(answer);
            }
            else if (dices[0] == dices[1] || dices[0] == dices[2])
            {
                answer = 1000 + (dices[0] * 100);
                Console.Write(answer);
            }
            else if (dices[1] == dices[2])
            {
                answer = 1000 + (dices[1] * 100);
                Console.Write(answer);
            }
            else
            {
                if (dices[0] > dices[1] && dices[0] > dices[2])
                {
                    answer = dices[0] * 100;
                }
                else if (dices[1] > dices[0] && dices[1] > dices[2])
                {
                    answer = dices[1] * 100;
                }
                else if (dices[2] > dices[0] && dices[2] > dices[1])
                {
                    answer = dices[2] * 100;
                }
                Console.Write(answer);
            }
        }
    }
}