#include <stdio.h>  
struct Process
{
     int pid;
     int arival_time;
     int burst_time;
     int waiting_time;
     int turn_around_time;
};

struct Process process_list[10];
// Function to calculate waiting time  
void findWaitingTime( int processes[ ], int n, int bt[ ], int wt[ ])  
{  
    // waiting time for first process is 0  
    wt[ 0 ] = 0;  
  
    // calculating waiting time  
    for ( int i = 1 ; i < n ; i++ )  
        wt[ i ] = bt[ i - 1 ] + wt[ i - 1 ] ;  
}  

// Function to calculate turn around time  
void findTurnAroundTime ( int processes[ ], int n, int bt[ ] , int wt [ ] , int tat[ ] )  
{  
    // calculating turnaround time by adding  
    // bt [ i ] + wt [ i ]  
    for ( int i = 0 ; i < n ; i++ )  
        tat[i] = bt[i] + wt[i];  
}  
  
// Function to calculate average time  
void findavgTime(int processes[], int n, int bt[])  
{  
    int wt[n], tat[n], total_wt = 0, total_tat = 0;  
  
    findWaitingTime(processes, n, bt, wt);              // Function to find waiting time of all processes  
  
    findTurnAroundTime(processes, n, bt, wt, tat);      // Function to find turn around time for all processes
  
    // Display processes along with all details  
    printf("\n\n%10s %20s %20s %20s","Processes", "Burst time", "Waiting time", "Turn around time");  
    printf("\n=================================================================================");
    
    for (int i = 0; i < n; i++)     // Calculate total waiting time and total turn  around time
    {  
        total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i];  
        printf("\n%10d", (i + 1));  
        printf("%20d ", bt[i]);  
        printf("%20d", wt[i]);  
        printf("%20d", tat[i]);  
    }  
    int s = (float)total_wt / n;  
    int t = (float)total_tat / n;  
    printf("\n=================================================================================");
    printf("\n\nAverage waiting time = %d", s);  
    printf("\n\nAverage turn around time = %d ", t);  
}  
 
int main()  
{    
    int processes[] = {1, 2, 3, 4, 5};    // process id's
    int n = 5;  
   
    int burst_time[] = {20, 15, 28, 50, 30};  // Burst time of all processesN 
  
    findavgTime(processes, n, burst_time);  
    return 0;  
}  
