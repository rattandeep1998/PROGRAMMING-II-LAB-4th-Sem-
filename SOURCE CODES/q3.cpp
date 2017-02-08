#include<bits/stdc++.h>
using namespace std;

void readSparseArray(int A[500][3])
{
    int tot;
    cout<<"Enter number of non-zero elements : ";
    cin>>tot;
    A[0][2]=tot;
    for(int i=1;i<=tot;i++)
    {
        cout<<"Enter the next element (row,column,value) : ";
        cin>>A[i][0]>>A[i][1]>>A[i][2];
    }
}

void transposeArray(int A[500][3],int B[500][3])
{
    B[0][0]=A[0][1];
    B[0][1]=A[0][0];
    B[0][2]=A[0][2];
    int k=1;
    int tot=A[0][2];
    for(int i=0;i<A[0][1];i++)
    {
        for(int j=1;j<=tot;j++)
        {
            if(i==A[j][1])
            {
                B[k][0]=i;
                B[k][1]=A[j][0];
                B[k][2]=A[j][2];
                k++;
            }
        }
    }
}

void displaySparseArray(int A[500][3])
{
    int tot=A[0][2];
    cout<<"After Transpose : "<<endl;
    cout<<"ROW\tCOLUMN\tVALUE"<<endl;
    for(int i=0;i<=tot;i++)
    {
        cout<<A[i][0]<<"\t"<<A[i][1]<<"\t"<<A[i][2]<<endl;
    }
    cout<<endl;
}

int main()
{
    int A[500][3],B[500][3],n,m;
    cout<<"Enter the size of matrix (rows,columns): ";
    cin>>n>>m;
    A[0][0]=n;
    A[0][1]=m;
    readSparseArray(A);
    transposeArray(A,B);
    displaySparseArray(B);
    return 0;
}
