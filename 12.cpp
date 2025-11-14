#include <iostream>
using namespace std;

int main()
{
    int pages[50], frames[50], n, f;
    int counter = 0, fault = 0;
    int time[10];

    cout << "\nEnter the no pages ";
    cin >> n;

    cout << "\nEnter the page reference string ";
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    cout << "\nEnter the number of frames ";
    cin >> f;

    for (int i = 0; i < f; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    cout << "\nPage \t Frames \t Page Fault \n";
    for (int i = 0; i < n; i++)
    {
        // Checks if page exist in frame
        int page = pages[i];
        int found = 0;

        // if page in memeory
        for(int j=0;j<f;j++)
        {
            if(frames[j]== page)
            {
                found = 1;
                counter++;
                time[j] = counter;
                break;
            }
        }
        // if page not in memory
        if(!found)
        {
            int pos =-1 , min =9999;
            for(int j=0;j<f;j++)
            {
                if(frames[j]==-1)
                {
                    pos = j;
                    break;
                }
                if(time[j] < min)
                {
                    min =time[j];
                    pos = j;
                }
            }
            frames[pos] = page;
            counter++;
            time[pos] = counter;
            fault++;
        }

            cout<<page <<"\t";
            for(int j=0;j<f;j++)
            {
                if(frames[j]==-1)
                {
                    cout<<" _ ";
                }
                else
                {
                    cout<<frames[j] <<" ";
                }
            }
            cout<<"\t\t "<<(found? "No" : "Yes") <<endl;
        }
   cout << "\nTotal Page Faults = " << fault << endl;
   cout << "Total Page Hits = " << n - fault << endl;
      
    }



    // Enter number of pages: 8
    // Enter page reference string: 1 2 3 2 4 1 5 2
    // Enter number of frames: 3

    // Page    Frames          Page Fault
    // 1       1 - -           Yes
    // 2       1 2 -           Yes
    // 3       1 2 3           Yes
    // 2       1 2 3           No
    // 4       4 2 3           Yes
    // 1       4 1 3           Yes
    // 5       4 1 5           Yes
    // 2       2 1 5           Yes

    // Total Page Faults = 7
    // Total Page Hits = 1
