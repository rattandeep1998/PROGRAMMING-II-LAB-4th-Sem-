#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    string data;
    node* next;
    /*node(string data)
    {
        this->data=data;
        this->next=NULL;
    }*/
};

node* inputLL()
{
    string x="-1";
    string element;
    cout<<"Enter Element(-1 to end) : ";
    cin>>element;

    if(element.compare(x)==0)
    {
        return NULL;
    }

    node* head=new node();
    head->data=element;
    head->next = inputLL();

    return head;
}

void traverseLL(node* head)
{
    cout<<"Linked List Is : "<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<"--->";
        head=head->next;
    }
    cout<<endl;
}

int noOfNodes(node* head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}

node* insertNode(node* head,int position,string element,int startIndex)
{
    if(position==0)
    {
        node* newNode=new node();
        newNode->data=element;
        newNode->next=NULL;
        newNode->next=head;
        return newNode;
    }

    if(startIndex==position)
    {
        node* newNode=new node();
        newNode->data=element;
        newNode->next=NULL;
        newNode->next=head->next;
        head->next=newNode;
        return head;
    }

    head->next=insertNode(head->next,position,element,startIndex+1);
    return head;
}

node* deleteNode(node* head,int position,int startIndex)
{
    if(position==1)
    {
        node *temp=head->next;
        head->next=NULL;
        delete head;
        return temp;
    }

    if(startIndex==position)
    {
        node *temp=head->next;
        head->next=temp->next;
        temp->next=NULL;
        delete temp;
        return head;
    }

    head->next=deleteNode(head->next,position,startIndex+1);
    return head;
}

node* reverseLL(node* head)
{
	if(head==NULL || head->next==NULL)
		return head;
	node* nxtcall=reverseLL(head->next);
	head->next->next=head;
	head->next=NULL;
	return nxtcall;
}


node* getMid(node* head)
{
    if(head==NULL)
        return NULL;
    node* slow = head;
    node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node* Merge(node* head1,node* head2)
{
    node* head = NULL;
    node* tail = NULL;

    if(head1->data.compare(head2->data) <= 0)
    {
        head=head1;
        tail=head1;
        head1=head1->next;
        head->next=NULL;
    }
    else
    {
        head=head2;
        tail=head2;
        head2=head2->next;
        head->next=NULL;
    }

    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data.compare(head2->data) <= 0)
        {
            tail->next=head1;
            tail=head1;
            head1=head1->next;
            tail->next=NULL;
        }
        else
        {
            tail->next=head2;
            tail=head2;
            head2=head2->next;
            tail->next=NULL;
        }
    }

    if(head1!=NULL)
    {
        tail->next=head1;
    }

    if(head2!=NULL)
    {
        tail->next=head2;
    }

    return head;
}

node* mergeSort(node* head)
{
    if(head==NULL || head->next==NULL)
        return head;

    node* mid=getMid(head);
    node* part2=mid->next;
    mid->next=NULL;

    node* head1=mergeSort(head);
    node* head2=mergeSort(part2);
    head=Merge(head1,head2);

    return head;
}


node* mergeTwoLL(node* head1 , node* head2)
{
    node* head = NULL;
    if(head1 == NULL)
    {
        return head2;
    }
    else if(head2 == NULL)
    {
        return head1;
    }
    if(head1->data.compare(head2->data) <= 0)
    {
        head = head1;
        head->next = mergeTwoLL(head1->next,head2);
    }
    else
    {
        head = head2;
        head->next = mergeTwoLL(head1,head2->next);
    }
    return head;
}

int main()
{
    string element;
    int choice;
    node* head=new node();
    head=NULL;
    node* head1=new node();
    head1=NULL;
    node* head2=new node();
    head2=NULL;
    int pos;
    while(1)
    {
        cout<<"MENU"<<endl;
        cout<<"1. Traverse Linked List"<<endl;
        cout<<"2. Counting Number of Nodes"<<endl;
        cout<<"3. Inserting New Node In Linked List"<<endl;
        cout<<"4. Deleting New Node In Linked List"<<endl;
        cout<<"5. Reverse Linked List"<<endl;
        cout<<"6. Sorting Words In Linked List"<<endl;
        cout<<"7. Combining Two Linked List"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1: traverseLL(head);
                    break;
            case 2: cout<<"Total Nodes Are : "<<noOfNodes(head)<<endl;
                    break;
            case 3: cout<<"Enter Word To Be Inserted : ";
                    cin>>element;
                    cout<<"Enter position In Linked List : ";
                    cin>>pos;
                    head=insertNode(head,pos,element,1);
                    break;
            case 4: cout<<"Enter position of element to be deleted : ";
                    cin>>pos;
                    head=deleteNode(head,pos+1,2);
                    break;
            case 5: head=reverseLL(head);
                    break;
            case 6: head=mergeSort(head);
                    break;
            case 7: cout<<"Enter Linked List 1 : ";
                    head1=inputLL();
                    cout<<"Enter Linked List 2 : ";
                    head2=inputLL();
                    head=mergeTwoLL(head1,head2);
                    break;
            case 8: exit(0);
                    break;
            default: cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}
