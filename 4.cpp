#include <iostream>
using namespace std;

int main() {

    int n, i, j;
    
    int bt[10], wt[10], tat[10], p[10];
    int temp;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter Burst Time:\n";
    for(i = 0; i < n; i++) {
        cout << "P" << i+1 << ": ";
        cin >> bt[i];
        p[i] = i + 1;   // process ID
    }

    // SJF Sorting (based on Burst Time)
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(bt[i] > bt[j]) {
                
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

            }
        }
    }

    // Waiting time
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Turnaround time
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    // Gantt Chart using Burst Time
    cout << "\nGantt Chart:\n|";
    for(i = 0; i < n; i++) {
        cout << " P" << p[i] << " |";
    }

    cout << "\n0";
    int current = 0;

    for(i = 0; i < n; i++) {
        current += bt[i];
        cout << "\t" << current;
    }

    cout << endl;
    return 0;
}




 // Enter number of processes: 4
 // Enter Burst Time:
 // P1: 6
 // P2: 8
 // P3: 7
 // P4: 3


// Process Burst Time      Waiting Time    Turnaround Time
 //   P4      3               0               3
  //  P1      6               3               9
 //   P3      7               9               16
 //   P2      8               16              24


 // Gantt Chart:
 // | P4 | P1 | P3 | P2 |
 //  0    3    9    16   24


