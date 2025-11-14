// First Fit

#include <iostream>
using namespace std;

int main()
{
    int blocksize[10], processsize[10], blockcount, processcount;
    int allocation[10];

    cout << "\nEnter the blockcount: ";
    cin >> blockcount;

    cout << "\nEnter the size of each block:\n";
    for (int i = 0; i < blockcount; i++)
    {
        cout << "Block " << i + 1 << ": ";
        cin >> blocksize[i];
    }

    cout << "\nEnter the processcount: ";
    cin >> processcount;

    cout << "\nEnter the size of each process:\n";
    for (int i = 0; i < processcount; i++)
    {
        cout << "Process " << i + 1 << ": ";
        cin >> processsize[i];
        allocation[i] = -1; // initialize as not allocated
    }

    // First Fit Allocation
    for (int i = 0; i < processcount; i++)
    {
        for (int j = 0; j < blockcount; j++)
        {
            if (blocksize[j] >= processsize[i])
            {
                allocation[i] = j;
                blocksize[j] -= processsize[i];
                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < processcount; i++)
    {
        cout << " " << i + 1 << "\t\t" << processsize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }

    return 0;
}



  // Enter number of memory blocks: 3
  // Enter size of each block:
  // Block 1: 100
  // Block 2: 500
  // Block 3: 200

  // Enter number of processes: 4
  // Enter size of each process:
  // Process 1: 120
  // Process 2: 200
  // Process 3: 300
  // Process 4: 50

  // Process No.	Process Size	Block No.
  // 1		120		2
  // 2		200		2
  // 3		300		Not Allocated
  // 4		50		1
