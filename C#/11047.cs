using System;

class Program
{
    static void Main()
    {
        int answer = 0;
        string[] input = Console.ReadLine().Split(' ');
        int coins = int.Parse(input[0]);
        int goal = int.Parse(input[1]);
        int[] coinsValue = new int[coins];

        for (int idx = 0; idx < coins; idx++)
        {
            coinsValue[idx] = int.Parse(Console.ReadLine());
        }

        Array.Reverse(coinsValue);

        while (goal != 0)
        {
            for (int idx = 0; idx < coinsValue.Length; idx++)
            {
                if (coinsValue[idx] <= goal)
                {
                    goal -= coinsValue[idx];
                    answer++;
                    idx--;
                }
            }
        }
        Console.WriteLine(answer);
    }
}