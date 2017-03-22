#include<bits/stdc++.h>
using namespace std;

void movediskFunct(stack<int>* src , stack<int>* dest , string first , string second)
{
    //int top1=src->pop();
    //int top2=dest->pop();

    if(src->empty())
    {
        int temp=dest->top();
        dest->pop();
        src->push(temp);
        cout<<"Move Disk "<<temp<<" from "<<second<<" to "<<first<<endl;
    }
    else if(dest->empty())
    {
        int temp=src->top();
        src->pop();
        dest->push(temp);
        cout<<"Move Disk "<<temp<<" from "<<first<<" to "<<second<<endl;
    }
    else if(src->top()>dest->top())
    {
        int temp=dest->top();
        dest->pop();
        src->push(temp);
        cout<<"Move Disk "<<temp<<" from "<<second<<" to "<<first<<endl;
    }
    else
    {
        int temp=src->top();
        src->pop();
        dest->push(temp);
        cout<<"Move Disk "<<temp<<" from "<<first<<" to "<<second<<endl;
    }
}

void tohIterative(int totDisks , stack<int>* src , stack<int>* aux , stack<int>* dest)
{
    string source="source";
    string auxilliary="auxilliary";
    string destination="destination";

    if(totDisks%2==0)
    {
        stack<int>* temp = aux;
        aux=dest;
        dest=temp;
    }

    int totMoves=pow(2,totDisks)-1;

    for(int i=totDisks;i>=1;i--)
    {
        src->push(i);
    }

    for(int i=1;i<=totMoves;i++)
    {
        if(i%3==1)
        {
            movediskFunct(src,dest,source,destination);
        }
        else if(i%3==2)
        {
            movediskFunct(src,aux,source,auxilliary);
        }
        else if(i%3==0)
        {
            movediskFunct(aux,dest,auxilliary,destination);
        }
    }
}


int main()
{
    int totDisks=3;

    stack<int>* src = new stack<int>;
    stack<int>* aux = new stack<int>;
    stack<int>* dest = new stack<int>;

    tohIterative(totDisks , src , aux , dest);
    return 0;
}
