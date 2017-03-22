#include <bits/stdc++.h>

using namespace std;
bool arr[100001]={false};

class node
{
    public:
    int coeff;
    int power;
    node * next;
};

node *head1=NULL,*head2=NULL,*head3=NULL;

node * allocate(int p,int c)
{
    node* newnode = new node();
    if(newnode==NULL)
    {
        cout<<"No Memory"<<endl;
    }
    else
    {
        newnode->coeff=c;
        newnode->power=p;
        newnode->next=NULL;
    }
    return newnode;
}

void add1(int p,int c)
{
    node *temp;
    temp = allocate(p,c);
    if(temp==NULL)
    {
        cout<<"No Memory"<<endl;
    }
    else
    {
        temp->next=head1;
        head1=temp;
    }
}

void add2(int p,int c)
{
    node *temp;
    temp = allocate(p,c);
    if(temp==NULL)
    {
        cout<<"No Memory"<<endl;
    }
    else
    {
        temp->next=head2;
        head2=temp;
    }
}

void multiadd(int p,int c)
{
    node *nn;
    nn=allocate(p,c);
    if(head3==NULL)
    {
        head3=nn;
    }
    else
    {
        node *re = head3;
        if(arr[p]==true)
        {
            while(re->power!=p)
            {
                re=re->next;
            }
            re->coeff+=c;
            //cout<<"Modified coefficient is "<<re->coeff<<endl;
        }
        else if(arr[p]==false)
        {
            //cout<<"found false"<<endl;
            arr[p]=true;
            if(re->power<p)
            {
                nn->next=re;
                re=nn;
            }
            else if(re->next==NULL)
            {
                re->next=nn;
            }
            else
            {
                //cout<<"final else"<<endl;
                while(re->power>p && re->next!=NULL)
                {
                    //cout<<re->power<<endl;
                    re=re->next;
                }
                //cout<<"out"<<endl;
                nn->next=re->next;
                re->next=nn;
            }
        }
    }
}

void multiply()
{
    int np,c;
    while(head1!=NULL)
    {
        node *r = head2;
        while(r!=NULL)
        {
            c=r->coeff*head1->coeff;
            np=r->power+head1->power;
            //cout<<"Power and Coefficient are "<<np<<"  "<<c<<endl;
            multiadd(np,c);
            //cout<<"returned from multiadd"<<endl;
            r=r->next;
        }
        head1=head1->next;
    }
    //cout<<"* done"<<endl;
}

void display()
{
    cout<<"The Multiplied polynomial is "<<endl;
    while(head3!=NULL)
    {
        cout<<head3->coeff<<"x^"<<head3->power<<" + ";
        head3=head3->next;
    }
}

int main()
{
    cout<<"Enter the maximum power of the first polynomial "<<endl;
    int p1,element,p2;
    cin>>p1;
    for(int i=0;i<=p1;i++)
    {
        cout<<"Enter the coefficient of x^"<<i<<" ";
        cin>>element;
        cout<<endl;
        add1(i,element);
    }
    cout<<endl;
    cout<<"Enter maximum power of the second polynomial "<<endl;
    cin>>p2;
   for(int i=0;i<=p2;i++)
    {
        cout<<"Enter the coefficient of x^"<<i<<" ";
        cin>>element;
        cout<<endl;
        add2(i,element);
    }
    multiply();
    display();
    return 0;
}
