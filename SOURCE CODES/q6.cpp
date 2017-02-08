#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> S;
    unordered_map<char,int> ICP,ISP;
    //ICP - Incoming Precedence
    //ISP - InStack Precedence
    ICP['(']=4;
    ISP['(']=0;
    ICP['^']=3;
    ISP['^']=3;
    ICP['*']=2;
    ISP['*']=2;
    ICP['/']=2;
    ISP['/']=2;
    ICP['+']=1;
    ISP['+']=1;
    ICP['-']=1;
    ISP['-']=1;

    char* postfix = new char[100];
    char* infix = new char[100];
    int j=0;

    cout<<"Enter Infix Expression : ";
    cin>>infix;

    int n = strlen(infix);
    for(int i=0;i<n;i++)
    {
        if(infix[i]==')')
        {
            while(S.top()!='(')
            {
                postfix[j] = S.top();
                j++;
                S.pop();
            }
            S.pop();
        }
        else if(infix[i]=='(')
        {
            S.push(infix[i]);
        }
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
        {
            while(ICP[infix[i] <= ISP[S.top()]])
            {
                postfix[j] = S.top();
                j++;
                S.pop();
            }
            S.push(infix[i]);
        }
        else
        {
            postfix[j]=infix[i];
            j++;
        }
    }

    while(!S.empty())
    {
        postfix[j]=S.top();
        j++;
        S.pop();
    }
    postfix[j]='\0';
    cout<<endl<<"PostFix Expression is : "<<postfix<<endl;
    return 0;
}
