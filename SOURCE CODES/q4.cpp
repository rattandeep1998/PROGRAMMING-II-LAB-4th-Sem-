#include<bits/stdc++.h>
using namespace std;

int r,c1;

void accept(int a1[10][10])
{
    int i,j;
    cout<<"Enter the Rows and Columns of matrix\n";
    cin>>r>>c1;
    cout<<"Enter the element\n";
    for (i=0;i<r;i++)
    {
        for (j=0;j<c1;j++)
        {
            cin>>a1[i][j];
        }
    }
}

void display(int a1[10][10],int r,int c)
{
    int i,j;
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            cout<<a1[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void convert (int a[10][10],int b[10][10],int r,int c)
{
    int i,j,k=1;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }
    b[0][0]=r;
    b[0][1]=c;
    b[0][2]=k-1;
}

void fast(int B[10][10],int C[10][10])
{
    int i,j,m,n,pos[3]={0,0,0},count[3]={0,0,0};
    for (i=1;i<=B[0][2];i++)
    {
        m = B[i][1];
        count[m]++;
    }
    pos[0] = 1;
    for (i=1;i<B[0][1];i++)
    {
        pos[i] = pos [i-1] + count[i-1];
    }
    for (i=1;i<=B[0][2];i++)
    {
        m = B[i][1];
        n= pos[m];
        pos[m]++;
        C[n][0] = B[i][1];
        C[n][1] = B[i][0];
        C[n][2] = B[i][2];
    }
    C[0][0] = B[0][0];
    C[0][1] = B[0][1];
    C[0][2] = B[0][2];
}

int main()
{
    int a[10][10], b[10][10], c[10][10], d[10][10], e[10][10];
    accept(a);

    cout<<"The conventional matrix is \n";
    display(a,r,c1);
    convert(a,b,r,c1);
    cout<<"The sparse matrix is \n";
    display(b,b[0][2]+1,3);
    fast(b,c);
    cout<<"The transpose of sparse matrix is\n";
    display(c,c[0][2]+1,3);
}
