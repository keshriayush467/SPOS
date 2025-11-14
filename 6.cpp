
// Round Robin 

#include <iostream>
using namespace std;

int main() 
{
    int n, timeQuantum;
    int bt[20], rem_bt[20], wt[20], tat[20];
    int time = 0;

    cout << "Enter total number of processes: ";
    cin >> n;

    cout << "Enter burst time for each process:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << "P" << i + 1 << ": ";
        cin >> bt[i];
        rem_bt[i] = bt[i];  
    }

    cout << "Enter Time Quantum: ";
    cin >> timeQuantum;

    bool done;

  
    
    do 
    {
        done = true;
        for (int i = 0; i < n; i++) 
        {
            if (rem_bt[i] > 0) 
            {
                done = false; 
                if (rem_bt[i] > timeQuantum) 
                {
                    time += timeQuantum;
                    rem_bt[i] -= timeQuantum;
                    cout << "P" << i + 1 << " executed till time " << time << endl;
                } 
                else 
                {
                    time += rem_bt[i];
                    wt[i] = time - bt[i]; 
                    rem_bt[i] = 0;
                    tat[i] = time;       
                    cout << "P" << i + 1 << " completed at time " << time << endl;
                }
            }
        }
    } while (!done);


    float totalWT = 0, totalTAT = 0;
    cout << "\nProcess\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) 
    {
        cout << "P" << i + 1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    cout << "\nAverage Waiting Time = " << totalWT / n;
    cout << "\nAverage Turnaround Time = " << totalTAT / n << endl;

    return 0;
}

  // Enter total number of processes: 3
  // Enter burst time for each process:
  // P1: 5
  // P2: 3
  // P3: 1
  // Enter Time Quantum: 2


  // P1 executed till time 2
  //  P2 executed till time 4
  //  P3 completed at time 5
  //  P1 executed till time 7
  //  P2 completed at time 8
  //  P1 completed at time 10

  //  Process BT  WT  TAT
  //  P1      5   5   10
  //  P2      3   5   8
  //  P3      1   4   5

  //  Average Waiting Time = 4.67
  //  Average Turnaround Time = 7.67


