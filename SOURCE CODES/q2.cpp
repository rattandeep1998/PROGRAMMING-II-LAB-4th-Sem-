#include<bits/stdc++.h>
using namespace std;

void makeSparsePolynomial(int A[],int pMax1,int B[],int pMax2,int C[][105],int presentIndex)
{
	for(int i=0;i<=pMax2;i++)
	{
		C[presentIndex][i*presentIndex]=A[presentIndex]*B[i];
	}
}

int main()
{
	int A[105],B[105],C[105][105],ANS[105];
	int pMax1,pMax2;
	
	cout<<"Enter the maximum power of first polynomial :";
	cin>>pMax1;
	
	for(int i=pMax1;i>=0;i--)
	{
		int coeff;
		
		cout<<"Enter coefficient of x^"<<i<<": ";
		cin>>coeff;
		A[i]=coeff;
	}
	cout<<endl;
	
	cout<<"Enter the maximum power of second polynomial :";
	cin>>pMax2;
	
	for(int i=pMax2;i>=0;i--)
	{
		int coeff;
		cout<<"Enter coefficient of x^"<<i<<": ";
		cin>>coeff;
		B[i]=coeff;
	}
	cout<<endl;
	
	int maxPower=pMax1*pMax2;
	
	for(int i=0;i<=pMax1;i++)
	{
		makeSparsePolynomial(A,pMax1,B,pMax2,C,i);
	}
	
	for(int j=0;j<=maxPower;j++)
	{
		int colSum=0;
		for(int i=0;i<=pMax1;i++)
		{
			colSum+=C[i][j];
		}
		
		ANS[j]=colSum;
	}
	
	for(int i=0;i<=pMax1;i++)
	{
		cout<<"Partial Array "<<i<<" : ";
		for(int j=0;j<maxPower;j++)
		{
			cout<<C[i][j]<<"x^"<<j<<" + ";
		}
		cout<<C[i][maxPower]<<"x^"<<maxPower<<endl;
	}
	
	cout<<"ANS : \t";
	for(int i=0;i<maxPower;i++)
	{
		cout<<ANS[i]<<"x^"<<i<<" + ";	
	}	
	cout<<ANS[maxPower]<<"x^"<<maxPower;
	
	return 0;
}
