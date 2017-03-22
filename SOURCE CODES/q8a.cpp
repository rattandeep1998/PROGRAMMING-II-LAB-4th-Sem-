#include<bits/stdc++.h>
#define SIZE 10
using namespace std;

class myQueue
{
    int queue[SIZE];
    int rear,front;
    public:
        myQueue()
        {
            rear=-1;
            front=-1;
        }

        void enqueue(int ele)
        {
            if(rear==SIZE)
            {
                cout<<"Queue Overflow"<<endl;
                return;
            }
            rear++;
            queue[rear]=ele;
            cout<<"Element Inserted : "<<ele<<endl;
        }

        int dequeue()
        {
            if(front==rear)
            {
                return -1;
            }
            front++;
            return queue[front];
        }

        void print()
        {
            if(rear==front)
            {
                cout<<"Queue is empty"<<endl;
                return;
            }

            for(int i=front+1;i<=rear;i++)
            {
                cout<<queue[i]<<" ";
            }
        }
};

int main()
{
    int choice;
    int x;
    myQueue Q;
    while(1)
    {
        cout<<"MENU"<<endl;
        cout<<"1. Insert Element In Queue"<<endl;
        cout<<"2. Delete Element From Queue"<<endl;
        cout<<"3. Display Queue"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter element : ";
                    int ele;
                    cin>>ele;
                    Q.enqueue(ele);
                    break;
            case 2: x = Q.dequeue();
                    if(x!=-1)
                        cout<<"Element Deleted: "<<x<<endl;
                    else
                        cout<<"Queue Underflow"<<endl;
                    break;
            case 3: Q.print();
                    cout<<endl;
                    break;
            case 4: exit(0);
                    break;
            default: cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}
