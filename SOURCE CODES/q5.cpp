#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<char*> S;
    char* input = new char[100];
    cout<<"Enter Postfix Expression for Evaluation : ";
    cin>>input;

    int n=strlen(input);

    cout<<n<<endl;

    for(int counter=0;counter<n;counter++)
    {
        //cout<<input[counter]<<"    wejdsjkds"<<endl;
        if(input[counter]=='+'||input[counter]=='-'||input[counter]=='*'||input[counter]=='/'||input[counter]=='^'||input[counter]=='%')
        {
            int j=0;
            char* first=S.top();
            S.pop();
            char* second=S.top();
            S.pop();
            char* newInput = new char[100];

            newInput[j]='(';
            j++;
            for(int i=0;second[i]!='\0';i++,j++)
            {
                newInput[j]=second[i];
            }

            newInput[j]=input[counter];
            j++;

            for(int i=0;first[i]!='\0';i++,j++)
            {
                newInput[j]=first[i];
            }
            newInput[j]=')';
            j++;
            newInput[j]='\0';

            //strcat(first,second);
            S.push(newInput);
        }
        else
        {
            char* opt = new char[2];
            opt[0]=input[counter];
            opt[1]='\0';
            //cout<<opt<<"     b labakan"<<endl;
            S.push(opt);
        }
        //cout<<S.top()<<endl;
    }
    //cout<<"Size:"<<S.size()<<endl;
    //string output = S.top();
    cout<<endl<<"Actual Infix Expression Is : "<<S.top()<<endl;
    S.pop();
    return 0;
}
