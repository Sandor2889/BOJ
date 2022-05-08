using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main()
        {
            int answer = 0;
            string input = Console.ReadLine();
            string[] nums;

            if (input.Contains('-'))
            {
                nums = input.Split('-');

                for (int idx = 0; idx < nums.Length; idx++)
                {
                    if (nums[idx].Contains('+'))
                    {
                        string[] strPlusNums = nums[idx].Split('+');
                        int[] plusNumss = Array.ConvertAll(strPlusNums, int.Parse);
                        foreach (int num in plusNumss)
                        {
                            if (idx != 0)
                            {
                                answer -= num;
                            }
                            else
                            {
                                answer += num;
                            }
                        }
                    }
                    else
                    {
                        if (idx != 0)
                        {
                            answer -= int.Parse(nums[idx]);
                        }
                        else
                        {
                            answer += int.Parse(nums[idx]);
                        }
                    }
                }
            }
            else
            {
                nums = input.Split('+');
                for (int idx = 0; idx < nums.Length; idx++)
                {
                    answer += int.Parse(nums[idx]);
                }
            }
            Console.WriteLine(answer);
        }
    }
}
