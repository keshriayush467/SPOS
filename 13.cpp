#include <iostream>
using namespace std;

int main()
{
    int pages[50], frames[10], n, f;
    int fault = 0;

    cout << "\nEnter the no of pages: ";
    cin >> n;

    cout << "\nEnter the page reference string: ";
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    cout << "\nEnter the no of frames: ";
    cin >> f;

    // Initialize frames
    for (int i = 0; i < f; i++)
        frames[i] = -1;

    cout << "\nPage\tFrames\t\tPage Fault\n";

    for (int i = 0; i < n; i++)
    {
        int page = pages[i];
        int found = 0;

        // Check if page is already in frames
        for (int j = 0; j < f; j++)
        {
            if (frames[j] == page)
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            int pos = -1;
            // Check for empty frame first
            for (int j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            // If no empty frame, find page to replace
            if (pos == -1)
            {
                int farthest = -1;
                for (int j = 0; j < f; j++)
                {
                    int k;
                    for (k = i + 1; k < n; k++)
                    {
                        if (frames[j] == pages[k])
                            break;
                    }
                    if (k > farthest)
                    {
                        farthest = k;
                        pos = j;
                    }
                }
            }

            frames[pos] = page;
            fault++;
        }

        // Print current frames
        cout << page << "\t";
        for (int j = 0; j < f; j++)
        {
            if (frames[j] == -1)
                cout << " _ ";
            else
                cout << frames[j] << " ";
        }
        cout << "\t\t" << (found ? "No" : "Yes") << endl;
    }

    cout << "\nTotal Page Faults = " << fault << endl;
    cout << "Total Page Hits = " << n - fault << endl;

    return 0;
}



  //  Enter the no of pages: 4

  //  Enter the page reference string: 7 4 5 2 1

  //  Enter the no of frames: 
  //  Page    Frames          Page Fault
  //  7       7               Yes
  //  4       4               Yes
  //  5       5               Yes
  //  2       2               Yes

  //Total Page Faults = 4
  //Total Page Hits = 0