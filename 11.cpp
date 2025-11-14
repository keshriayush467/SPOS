// Worst Fit

#include <iostream>
using namespace std;

int main()
{
    int blocksize[10], processsize[10], blockcount, processcount;
    int allocation[10];

    cout << "\nEnter the block count ";
    cin >> blockcount;

    cout << "\nEnter the block size ";
    for (int i = 0; i < blockcount; i++)
    {
        cout << "Block " << i + 1 << " : ";
        cin >> blocksize[i];
    }

    cout << "\nEnter the process count ";
    cin >> processcount;

    cout << "\nEnter the process size ";
    for (int i = 0; i < processcount; i++)
    {
        cout << "Process " << i + 1 << " : ";
        cin >> processsize[i];
        allocation[i] = -1;
    }

    for (int i = 0; i < processcount; i++)
    {
        int worstidx = -1;
        for (int j = 0; j < blockcount; j++)
        {
            if (blocksize[j] >= processsize[i])
            {
                if (worstidx == -1 || blocksize[j] > blocksize[worstidx])
                {
                    worstidx = j;
                }
            }
        }
        if (worstidx != -1)
        {
            allocation[i] = worstidx;
            blocksize[worstidx] -= processsize[i];
        }
    }

   cout << "\nProcess No\tProcess Size\tBlock No\n";
   for (int i = 0; i < processcount; i++)
{
    cout << " " << i + 1 << "\t\t" << processsize[i] << "\t\t";
    if (allocation[i] != -1)
    {
        cout << allocation[i] + 1; 
    }
    else
    {
        cout << "Not Allocated";
    }
    cout << endl;
}
}


 // Enter number of memory blocks: 5
 // Enter size of each block:
 // Block 1: 100
 // Block 2: 500
 // Block 3: 200
 // Block 4: 300
 // Block 5: 600

 // Enter number of processes: 4
 // Enter size of each process:
 // Process 1: 212
 // Process 2: 417
 // Process 3: 112
 // Process 4: 426

 // Process No.    Process Size    Block No.
 // 1              212             5
 // 2              417             2
 // 3              112             5
 // 4              426             Not Allocated
