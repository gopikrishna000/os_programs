#include<iostream>
using namespace std;
void findWaitingTime(int processes[], int n,
                          int bt[], int wt[])
{
    wt[0] = 0;
    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}
void findTurnAroundTime( int processes[], int n,
                  int bt[], int wt[], int tat[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

int main()
{
    int processes[] = { 1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    int  burst_time[] = {10, 5, 8};
    
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, burst_time, wt);
    findTurnAroundTime(processes, n, burst_time, wt, tat);
    cout << "Processes  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n";
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" <<burst_time[i];
        cout<<"\t    "<< wt[i] <<"\t\t  " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "
         << (double)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (double)total_tat / (float)n;

    return 0;

}
