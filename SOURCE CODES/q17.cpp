#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int info;
    struct node *next;
    struct node *prev;
}*start, *last;

int counter = 0;

class double_clist
{
    public:
        double_clist()
        {
            start = NULL;
            last = NULL;
        }

        node* create_node(int value)
        {
            counter++;
            node *temp = new node;
            temp->info = value;
            temp->next = NULL;
            temp->prev = NULL;
            return temp;
        }

        void insert_begin()
        {
            int value;
            cout<<endl<<"Enter the element to be inserted: ";
            cin>>value;
            node *temp;
            temp = create_node(value);
            if (start == last && start == NULL)
            {
                cout<<"Element inserted in empty list"<<endl;
                start = last = temp;
                start->next = last->next = NULL;
                start->prev = last->prev = NULL;
            }
            else
            {
                temp->next = start;
                start->prev = temp;
                start = temp;
                start->prev = last;
                last->next = start;
                cout<<"Element inserted"<<endl;
            }
        }

        void insert_last()
        {
            int value;
            cout<<endl<<"Enter the element to be inserted: ";
            cin>>value;
            node *temp;
            temp = create_node(value);
            if (start == last && start == NULL)
            {
                cout<<"Element inserted in empty list"<<endl;
                start = last = temp;
                start->next = last->next = NULL;
                start->prev = last->prev = NULL;
            }
            else
            {
                last->next = temp;
                temp->prev = last;
                last = temp;
                start->prev = last;
                last->next = start;
            }
        }

        void insert_pos()
        {
            int value, pos, i;
            cout<<endl<<"Enter the element to be inserted: ";
            cin>>value;
            cout<<endl<<"Enter the postion of element inserted: ";
            cin>>pos;
            node *temp, *s, *ptr;
            temp = create_node(value);
            if (start == last && start == NULL)
            {
                if (pos == 1)
                {
                    start = last = temp;
                    start->next = last->next = NULL;
                    start->prev = last->prev = NULL;
                }
                else
                {
                    cout<<"Position out of range"<<endl;
                    counter--;
                    return;
                }
            }
            else
            {
                if (counter < pos)
                {
                     cout<<"Position out of range"<<endl;
                     counter--;
                     return;
                }
                s = start;
                for (i = 1;i <= counter;i++)
                {
                    ptr = s;
                    s = s->next;
                    if (i == pos - 1)
                    {
                        ptr->next = temp;
                        temp->prev = ptr;
                        temp->next = s;
                        s->prev = temp;
                        cout<<"Element inserted"<<endl;
                        break;
                    }
                }
            }
        }

        void delete_pos()
        {
            int pos, i;
            node *ptr, *s;
            if (start == last && start == NULL)
            {
                cout<<"List is empty, nothing to delete"<<endl;
                return;
            }
            cout<<endl<<"Enter the postion of element to be deleted: ";
            cin>>pos;
            if (counter < pos)
            {
                cout<<"Position out of range"<<endl;
                return;
            }
            s = start;
            if(pos == 1)
            {
                counter--;
                last->next = s->next;
                s->next->prev = last;
                start = s->next;
                delete s;
                cout<<"Element Deleted"<<endl;
                return;
            }
            for (i = 0;i < pos - 1;i++ )
            {
                s = s->next;
                ptr = s->prev;
            }
            ptr->next = s->next;
            s->next->prev = ptr;
            if (pos == counter)
            {
                last = ptr;
            }
            counter--;
            delete s;
            cout<<"Element Deleted"<<endl;
        }

        void update()
        {
            int value, i, pos;
            if (start == last && start == NULL)
            {
                cout<<"The List is empty, nothing to update"<<endl;
                return;
            }
            cout<<endl<<"Enter the postion of node to be updated: ";
            cin>>pos;
            cout<<"Enter the new value: ";
            cin>>value;
            node *s;
            if (counter < pos)
            {
                cout<<"Position out of range"<<endl;
                return;
            }
            s = start;
            if (pos == 1)
            {
               s->info = value;
               cout<<"Node Updated"<<endl;
               return;
            }
            for (i=0;i < pos - 1;i++)
            {
                s = s->next;
            }
            s->info = value;
            cout<<"Node Updated"<<endl;
        }

        void search()
        {
            int pos = 0, value, i;
            bool flag = false;
            node *s;
            if (start == last && start == NULL)
            {
                cout<<"The List is empty, nothing to search"<<endl;
                return;
            }
            cout<<endl<<"Enter the value to be searched: ";
            cin>>value;
            s = start;
            for (i = 0;i < counter;i++)
            {
                pos++;
                if (s->info == value)
                {
                    cout<<"Element "<<value<<" found at position: "<<pos<<endl;
                    flag = true;
                }
                s = s->next;
            }
            if (!flag)
                cout<<"Element not found in the list"<<endl;
        }

        void sort()
        {
            node *temp, *s;
            int value, i;
            if (start == last && start == NULL)
            {
                cout<<"The List is empty, nothing to sort"<<endl;
                return;
            }
            s = start;
            for (i = 0;i < counter;i++)
            {
                temp = s->next;
                while (temp != start)
                {
                    if (s->info > temp->info)
                    {
                        value = s->info;
                        s->info = temp->info;
                        temp->info = value;
                    }
                    temp = temp->next;
                }
                s = s->next;
            }
        }

        void display()
        {
            int i;
            node *s;
            if (start == last && start == NULL)
            {
                cout<<"The List is empty, nothing to display"<<endl;
                return;
            }
            s = start;
            for (i = 0;i < counter-1;i++)
            {
                cout<<s->info<<"<->";
                s = s->next;
            }
            cout<<s->info<<endl;
        }

        void reverse()
        {
            if (start == last && start == NULL)
            {
                cout<<"The List is empty, nothing to reverse"<<endl;
                return;
            }
            node *p1, *p2;
            p1 = start;
            p2 = p1->next;
            p1->next = NULL;
            p1->prev = p2;
            while (p2 != start)
            {
                p2->prev = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = p2->prev;
            }
            last = start;
            start = p1;
            cout<<"List Reversed"<<endl;
        }

};

int main()
{
    int choice;
    double_clist cdl;
    while (1)
    {
        //cout<<"\n-------------------------------"<<endl;
        cout<<"\nOperations on Doubly Circular linked list"<<endl;
        //cout<<"\n-------------------------------"<<endl;
        cout<<"1.Insert at Beginning"<<endl;
        cout<<"2.Insert at Last"<<endl;
        cout<<"3.Insert at Position"<<endl;
        cout<<"4.Delete at Position"<<endl;
        cout<<"5.Update Node"<<endl;
        cout<<"6.Search Element"<<endl;
        cout<<"7.Sort"<<endl;
        cout<<"8.Display List"<<endl;
        cout<<"9.Reverse List"<<endl;
        cout<<"10.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cdl.insert_begin();
            break;
        case 2:
            cdl.insert_last();
            break;
        case 3:
            cdl.insert_pos();
            break;
        case 4:
            cdl.delete_pos();
            break;
        case 5:
            cdl.update();
            break;
        case 6:
            cdl.search();
            break;
        case 7:
            cdl.sort();
            break;
        case 8:
            cdl.display();
            break;
        case 9:
            cdl.reverse();
            break;
        case 10:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}
