#pragma once


int turnaround_time(int processes[], int processes_num, int burst_time[], int waiting_time[],int turnaround_time[]);
int waiting_time(int processes[], int processes_num, int burst_time[], int waiting_time[], int quantum);
int find_avg_time(int processes[], int processes_num, int burst_time[], int quantum);