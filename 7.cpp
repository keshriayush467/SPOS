#include <iostream>
using namespace std;

class Synchronization
{
    int a[10];
    int mutex;
    int full;
    int in;
    int out;
    int empty;

public:
    void wait(int &x)
    {
        if (x > 0)
        {
            x--;
        }
    }

    void signal(int &x)
    {
        x++;
    }

    Synchronization() : mutex(1), empty(10), full(0), in(0), out(0) {}

    void producer()
    {
        if (empty > 0 && mutex == 1)
        {
            wait(empty);
            wait(mutex);
            cout<<"\nEnter data to be produced ";
            int data;
            cin >> data;
            a[in] = data;
            in = (in + 1) % 10;
            signal(mutex);
            signal(full);
        }
        else
        {
            cout << "\nBuffer is full not able to execute ";
        }
    }

    void consumer()
    {
        if (full > 0 && mutex == 1)
        {
            wait(full);
            wait(mutex);
            cout << "\nData Consumed is " << a[out];
            out = (out + 1) % 10;
            signal(mutex);
            signal(empty);
        }
        else 
        {
            cout <<"\nBuffer is empty, cannot consume!";
        }   
    }
};

int main()
{
    int choice;
    Synchronization s;
    while(choice!= 3)
    {
        cout<<"\n1. Producer \n2. Consumer \n3. Exit";
        cout<<"\nEnter your choice ";
        cin>>choice;

        switch(choice)
        {
            case 1: s.producer();
                    break;
            
            case 2: s.consumer();
                    break;
            
            case 3: cout<<"\n Exited ";
        }
    }
    return 0;
}