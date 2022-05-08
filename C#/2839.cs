using System;

class Program
{
    static void Main()
    {
        int input = int.Parse(Console.ReadLine());
        int result = 0;

        while (input > 0)
        {
            if (input % 5 == 0)
            {
                input -= 5;
                result++;
            }
            else if (input % 3 == 0)
            {
                input -= 3;
                result++;
            }
            else if (input > 5)
            {
                input -= 5;
                result++;
            }
            else
            {
                result = -1;
                break;
            }
        }

        Console.WriteLine(result);
    }
}
