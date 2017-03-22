#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

class circular_llist
{
    public:
    node* last;
    circular_llist()
    {
        last = NULL;
    }

    void create_node(int value)
    {
        node *temp = new node();
        temp->data = value;
        if (last == NULL)
        {
            last = temp;
            temp->next = last;
        }
        else
        {
            temp->next = last->next;
            last->next = temp;
            last = temp;
        }
    }

    void add_after(int value, int pos)
    {
        if (last == NULL)
        {
            cout<<"First Create the list."<<endl;
            return;
        }
        node *temp, *s;
        s = last->next;
        for (int i = 0;i < pos-1;i++)
        {
            s = s->next;
            if (s == last->next)
            {
                cout<<"There are less than ";
                cout<<pos<<" in the list"<<endl;
                return;
            }
        }
        temp = new node();
        temp->next = s->next;
        temp->data = value;
        s->next = temp;
        /*Element inserted at the end*/
        if (s == last)
        {
            last=temp;
        }
    }

    void delete_element(int value)
    {
            node *temp, *s;
            s = last->next;

            if (last->next == last && last->data == value)
            {
                temp = last;
                last = NULL;
                delete temp;
                return;
            }
            if (s->data == value)
            {
                temp = s;
                last->next = s->next;
                delete temp;
                return;
            }
            while (s->next != last)
            {
                if (s->next->data == value)
                {
                    temp = s->next;
                    s->next = temp->next;
                    delete temp;
                    cout<<"Element "<<value;
                    cout<<" deleted from the list"<<endl;
                    return;
                }
                s = s->next;
            }

            if (s->next->data == value)
            {
                temp = s->next;
                s->next = last->next;
                delete temp;
                last = s;
                return;
            }
            cout<<"Element "<<value<<" not found in the list"<<endl;
        }

        void display_list()
        {
            node *s;
            if (last == NULL)
            {
                cout<<"List is empty, nothing to display"<<endl;
                return;
            }
            s = last->next;
            cout<<"Circular Link List: "<<endl;
            while (s != last)
            {
                cout<<s->data<<"->";
                s = s->next;
            }
            cout<<s->data<<endl;
        }

        int count_nodes()
        {
            int count=1;
            if(last==NULL)
            {
                return 0;
            }
            node* s = last->next;

            while(s!=last)
            {
                count++;
                s = s->next;
            }
            return count;
        }

        void reverse_list_helper(node* head)
        {
            if(head==NULL || head->next==NULL)
            {
                return;
            }
            if(head==last)
            {
                return;
            }

            reverse_list_helper(head->next);
            head->next->next=head;

        }
        void reverse_list()
        {
            node* temp=last->next;
            reverse_list_helper(last->next);
            temp->next=last;
            last=temp;
        }
};

int main()
{
    int choice, element, position;
    circular_llist cl;
    while (1)
    {
        //cout<<endl<<"---------------------------"<<endl;
        cout<<endl<<"CIRCULAR SINGLY LINKED LIST"<<endl;
        //cout<<endl<<"---------------------------"<<endl;
        cout<<"1.Create Node"<<endl;
        cout<<"2.Insert In Linked List"<<endl;
        cout<<"3.Delete From Linked List"<<endl;
        cout<<"4.Display Linked List"<<endl;
        cout<<"5.Count Nodes In Linked List"<<endl;
        cout<<"6.Reverse A Linked List"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            cl.create_node(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert element after position: ";
            cin>>position;
            cl.add_after(element, position);
            cout<<endl;
            break;
        case 3:
            if (cl.last == NULL)
            {
                cout<<"List is empty, nothing to delete"<<endl;
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            cl.delete_element(element);
            cout<<endl;
            break;
        case 4:
            cl.display_list();
            break;
        case 5:
            cout<<"Total nodes are : "<<cl.count_nodes();
            break;
        case 6:
            cl.reverse_list();
            break;
        case 7:
            exit(0);
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}
