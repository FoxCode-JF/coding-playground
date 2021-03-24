#include "round_robin.h"
#include "stdbool.h"
#include "stdio.h"


int turnaround_time(int processes[], int processes_num, int burst_time[], int waiting_time[],int turnaround_time[])
{
	for (int i = 0; i < processes_num; ++i)
	{
		turnaround_time[i] = burst_time[i] + waiting_time[i];	
	}
	return 1;
}

int waiting_time(int processes[], int processes_num, int burst_time[], int waiting_time[], int quantum)
{
	int remaining_burst_time[processes_num];

	for (int i = 0; i < processes_num; ++i)
	{
		remaining_burst_time[i] = burst_time[i];
	}

	int current_time = 0;


	while(1)
	{
		bool all_processes_done = true;

		for (int i = 0; i < processes_num; ++i)
		{

			if (remaining_burst_time[i] > 0)
			{
				all_processes_done = false;

				if (remaining_burst_time[i] > quantum)
				{
					current_time = current_time + quantum;
					remaining_burst_time[i] = remaining_burst_time[i] - quantum;
				} else
				{
					current_time = current_time + remaining_burst_time[i];
					waiting_time[i] = current_time = burst_time[i];
					remaining_burst_time[i] = 0;
				}
			}
		}
		
		if (all_processes_done == true) {break;};
	}
	return 1;
}

int find_avg_time(int processes[], int processes_num, int burst_time[], int quantum)
{
	int waiting_time_arr[processes_num];
	int turnaround_time_arr[processes_num];
	int total_wait_time = 0;
	int total_turnaround_time = 0;

	waiting_time(processes, processes_num, burst_time, waiting_time_arr, quantum);
	turnaround_time(processes, processes_num, burst_time, waiting_time_arr, turnaround_time_arr);
	 printf("Processes Burst Time Waiting Time turnaround time\n");
   // Calculate total waiting time and total turn
   // around time
   for (int i=0; i<processes_num; i++) {
      total_wait_time = total_wait_time + waiting_time_arr[i];
      total_turnaround_time = total_turnaround_time + turnaround_time_arr[i];
      printf("\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1, burst_time[i], waiting_time_arr[i], turnaround_time_arr[i]);
   }
   printf("Average waiting time = %f", (float)total_wait_time / (float)processes_num);
   printf("\nAverage turnaround time = %f\n", (float)total_turnaround_time / (float)processes_num);
   return 1;
}
