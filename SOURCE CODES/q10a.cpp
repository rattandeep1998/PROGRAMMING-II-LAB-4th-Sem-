#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};

node* top;
node* top1;
node* temp;
int counte = 0;

void create()
{
    top = NULL;
}

void stack_count()
{
    cout<<"Number Of Elements In Stack : "<<counte<<endl;
}

void push(int ele)
{
    if(top == NULL)
    {
        top =new node();
        top->next = NULL;
        top->data = ele;
    }
    else
    {
        temp = new node();
        temp->next = top;
        temp->data = ele;
        top = temp;
    }
    counte++;
}

void display()
{
    top1 = top;

    if (top1 == NULL)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }

    while (top1 != NULL)
    {
        cout<<top1->data<<" ";
        top1 = top1->next;
    }
}

void destroy()
{
    top1 = top;

    while (top1 != NULL)
    {
        top1 = top->next;
        delete top;
        top = top1;
        top1 = top1->next;
    }
    delete top1;
    top = NULL;
    cout<<"\n All stack elements destroyed";
    counte = 0;
}

void empty()
{
    if (top == NULL)
        cout<<"\n Stack is empty";
    else
        cout<<"\n Stack is not empty with "<<counte<<" elements.";
}

int topelement()
{
    return(top->data);
}

void pop()
{
    top1 = top;
    if (top1 == NULL)
    {
        cout<<"\n Stack Is Empty";
        return;
    }
    else
        top1 = top1->next;
    cout<<"Popped Value : "<<top->data<<endl;
    delete top;
    top=top1;
    counte--;
}

int main()
{
    int no, ch, e;

    cout<<"1. Push"<<endl;
    cout<<"2. Pop"<<endl;
    cout<<"3. Top"<<endl;
    cout<<"4.Empty"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"6. Display"<<endl;
    cout<<"7.Stack Count"<<endl;
    cout<<"8.Destroy Stack"<<endl;
    cout<<endl;
    create();

    while (1)
    {
        cout<<"Enter Choice : ";
        cin>>ch;

        switch (ch)
        {
        case 1: cout<<"Enter data : ";
                cin>>no;
                push(no);
                break;
        case 2: pop();
                break;
        case 3: if(top==NULL)
                    cout<<"No Elements In Stack"<<endl;
                else
                {
                    e = topelement();
                    cout<<"Top Element : "<<e<<endl;
                }
                break;
        case 4: empty();
                break;
        case 5: exit(0);
        case 6: display();
                break;
        case 7: stack_count();
                break;
        case 8: destroy();
                break;
        default:printf(" Wrong choice, Please enter correct choice  ");
                break;
        }
    }
    return 0;
}
