using System;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main()
        {
            int answer = 0;
            int rooms = int.Parse(Console.ReadLine());

            int currentTime = 0;

            (int start, int end)[] meetingTime = new (int, int)[rooms];

            for (int idx = 0; idx < rooms; idx++)
            {
                string timeString = Console.ReadLine();
                string[] InputTimes = timeString.Split();

                meetingTime[idx].start = int.Parse(InputTimes[0]);
                meetingTime[idx].end = int.Parse(InputTimes[1]);
            }

            meetingTime = meetingTime.OrderBy(x => x.end).ThenBy(x => x.start).ToArray();

            for (int idx = 0; idx < rooms; idx++)
            {
                if (meetingTime[idx].start >= currentTime)
                {
                    currentTime = meetingTime[idx].end;
                    answer++;
                }
            }

            Console.WriteLine(answer);
        }
    }
}