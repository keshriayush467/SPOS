
// Priority Scheduling

#include <iostream>
using namespace std;

int main() 
{
    int n;
    int bt[10], priority[10], wt[10], tat[10], p[10];

    cout << "Enter the number of processes : ";
    cin >> n;

     for (int i = 0; i < n; i++) 
     {
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> bt[i];
        cout << "Enter priority for process " << i + 1 << ": ";
        cin >> priority[i];
        p[i] = i + 1;
    }

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (priority[i] > priority[j]) 
            {
                swap(priority[i], priority[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++) 
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++) 
    {
        tat[i] = bt[i] + wt[i];
    }

    cout << "\nProcess\tBurst Time\tPriority\tWait Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) 
    {
        cout << p[i] << "\t" << bt[i] << "\t\t" << priority[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }


    cout<<"\nGantt Chart " <<endl;
    for(int i=0; i<n;i++)
    {
        cout<<" P " <<p[i] <<" | " ;
    }

    cout<<"\n0";
    for(int i=0;i<n;i++)
    {
       cout<<"\t" <<tat[i];
 

    }
    cout<<endl;
}



//Enter number of processes: 4
// Enter Burst Time for Process 1: 6
// Enter Priority for Process 1: 2
// Enter Burst Time for Process 2: 8
// Enter Priority for Process 2: 1
// Enter Burst Time for Process 3: 7
// Enter Priority for Process 3: 3
// Enter Burst Time for Process 4: 3
// Enter Priority for Process 4: 2

// Process    Burst Time    Priority    Waiting Time    Turnaround Time
// 2          8             1           0               8
// 1          6             2           8               14
// 4          3             2           14              17
// 3          7             3           17              24

