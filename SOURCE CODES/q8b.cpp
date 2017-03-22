#include<bits/stdc++.h>
#define SIZE 10
using namespace std;

class deQueue
{
    int A[SIZE];
    int front,rear;

    public:
        deQueue()
        {
            front=-1;
            rear=-1;
        }

        void addAtBeg(int ele)
        {
            if(rear==-1 && front==-1)
            {
                addAtEnd(ele);
            }
            else if(front==0)
            {
                cout<<"Dequeue is full from left."<<endl;
            }
            else
            {
                A[--front]=ele;
            }
        }

        void addAtEnd(int ele)
        {
            if(rear==SIZE)
            {
                cout<<"Dequeue is Full From Right."<<endl;
            }
            else
            {
                A[++rear]=ele;
                if(front==-1)
                {
                    front=0;
                }
            }
        }

        void print()
        {
            if(front==-1 && rear==-1)
            {
                cout<<"Dequeue Is Empty"<<endl;
            }
            else
            {
                for(int i=front;i<=rear;i++)
                {
                    cout<<A[i]<<" ";
                }
            }
        }

        int deleteFromFront()
        {
            if(rear==-1 && front==-1)
            {
                cout<<"Dequeue is Empty.";
            }
            else if(front==rear)
            {
                int x = A[front];
                front=rear=-1;
                return x;
            }
            else
            {
                return A[front++];
            }
        }

        int deleteFromRear()
        {
            if(rear==-1 && front==-1)
            {
                cout<<"Dequeue Empty.";
            }
            else if(front==rear)
            {
                int x=A[front];
                front=rear=-1;
                return x;
            }
            else
            {
                return A[rear--];
            }
        }
};

int main()
{
    deQueue Q;
    int ch,x,flag=1,c2;
    cout<<"\n1. Input Restricted Deque\n2. Output Restricted Deque\n";
    cout<<"\nEnter your Choice: ";
    cin>>c2;
    if(c2==1)
    {
        while(flag)
        {
            cout<<"\n\n1. Enqueue\n2. Dequeue Right\n3. Dequeue Left\n4. Display\n5. Exit\n\n";
            cin>>ch;
            switch(ch)
            {
                case 1: cout<<"\nEnter the Element: ";
                        cin>>x;
                        Q.addAtEnd(x);
                        break;
                case 2: x=Q.deleteFromRear();
                        cout<<"\nRemoved "<<x<<" from the Dequeue\n";
                        break;
                case 3: x=Q.deleteFromFront();
                        cout<<"\nRemoved "<<x<<" form the Dequeue\n";
                        break;
                case 4: Q.print();
                        break;
                case 5: flag=0;
                        break;
                default:cout<<"\nWrong choice!!! Try Again.\n";
            }
        }
    }
    else if (c2==2)
    {
        while(flag)
        {
            cout<<"\n\n1. Enqueue Left\n2. Enqueue Right\n3. Dequeue\n4. Display\n5. Exit\n\n";
            cin>>ch;
            switch(ch)
            {
                case 1: cout<<"\nEnter the Element: ";
                        cin>>x;
                        Q.addAtBeg(x);
                        break;
                case 2: cout<<"\nEnter the Element: ";
                        cin>>x;
                        Q.addAtEnd(x);
                        break;
                case 3: x=Q.deleteFromFront();
                        cout<<"\nRemoved "<<x<<" from the Dequeue\n";
                        break;
                case 4: Q.print();
                        break;
                case 5: flag=0;
                        break;
                default:cout<<"\nWrong Choice!!! Try Again.\n";
            }
        }
    }
    else
    {
        cout<<"\nWrong Choice!!!\n";
    }
    return 0;
}
