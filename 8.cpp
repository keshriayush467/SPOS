#include<iostream>
using namespace std;

int main()
{
    int blocksize[10], processsize[10], blockcount , processcount;
    int allocation[10];

    cout<<"\nEnter the no of memory blocks ";
    cin>>blockcount;

    cout<<"\nEnter the size of the each block";
    for(int i=0; i<blockcount;i++)
    {
        cout<<" Block " <<i+1 <<" : ";
        cin>>blocksize[i];

    }

    cout<<"\nEnter the no of processes ";
    cin>>processcount;

    cout<<"\nEnter the size of the each process ";
    for(int i =0;i<processcount;i++)
    {
        cout<<"Process " <<i+1 <<":";
        cin>>processsize[i];
        allocation[i] = -1;
    }

    for(int i=0; i<processcount;i++)
    {
       int bestidx = -1;
       for(int j=0;j<blockcount;j++)
       {
        if(blocksize[j] >= processsize[i])
        {
            if(bestidx ==-1 || blocksize[j] < blocksize[bestidx])
            {
                bestidx =j;
            }
        }
       }
       if(bestidx !=-1)
       {
        allocation[i] = bestidx;
        blocksize[bestidx] -= processsize[i];
       }

    }

   cout << "\nProcess No\tProcess Size\tBlock No\n";
for (int i = 0; i < processcount; i++)
{
    cout << " " << i + 1 << "\t\t" << processsize[i] << "\t\t";
    if (allocation[i] != -1)
        cout << allocation[i] + 1; 
    else
        cout << "Not Allocated";
    cout << endl;
}

}