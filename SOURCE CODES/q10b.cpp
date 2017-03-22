#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

node* front;
node* rear;
node* temp;
node* front1;

int counte = 0;

void create()
{
    front = rear = NULL;
}

void queuesize()
{
    cout<<"Queue Size : "<<counte<<endl;
}

void enq(int data)
{
    if (rear == NULL)
    {
        rear = new node();
        rear->next = NULL;
        rear->data = data;
        front = rear;
    }
    else
    {
        temp = new node();
        rear->next = temp;
        temp->data = data;
        temp->next = NULL;
        rear = temp;
    }
    counte++;
}

void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        cout<<"Queue Is Empty"<<endl;
        return;
    }
    while (front1 != rear)
    {
        cout<<front1->data<<endl;
        front1 = front1->next;
    }
    if (front1 == rear)
        cout<<front1->data<<endl;
}

void deq()
{
    front1 = front;

    if (front1 == NULL)
    {
        cout<<"Queue Is Empty"<<endl;
        return;
    }
    else
    {
        if (front1->next != NULL)
        {
            front1 = front1->next;
            cout<<"Dequeued Value : "<<front->data;
            delete front;
            front = front1;
        }
        else
        {
            cout<<"Dequeued Value : "<<front->data;
            delete front;
            front = NULL;
            rear = NULL;
        }
        counte--;
    }
}

int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->data);
    else
        return 0;
}

void empty()
{
     if ((front == NULL) && (rear == NULL))
        cout<<"\n Queue empty";
    else
       cout<<"\n Queue not empty";
}

int main()
{
    int no, ch, e;

    cout<<"\n 1. Enque";
    cout<<"\n 2. Deque";
    cout<<"\n 3. Front element";
    cout<<"\n 4. Empty";
    cout<<"\n 5. Exit";
    cout<<"\n 6. Display";
    cout<<"\n 7. Queue size";
    create();
    while (1)
    {
        cout<<"\nEnter choice : ";
        cin>>ch;
        switch (ch)
        {
        case 1: cout<<"Enter data : ";
                cin>>no;
                enq(no);
                break;
        case 2: deq();
                break;
        case 3: e = frontelement();
                if (e != 0)
                    cout<<"Front Element : "<<e<<endl;
                else
                    cout<<"Queue Is Empty"<<endl;
                break;
        case 4: empty();
                break;
        case 5: exit(0);
        case 6: display();
                break;
        case 7: queuesize();
                break;
        default:cout<<"Invalid Choice"<<endl;
                break;
        }
    }
    return 0;
}
