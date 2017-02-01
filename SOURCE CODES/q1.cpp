#include<bits/stdc++.h>
using namespace std;

void addPolynomial(int A[1005],int pMax1,int B[1005],int pMax2,int C[1005])
{
	int i=0;
	while(i<=pMax1&&i<=pMax2)
	{
		C[i]=A[i]+B[i];
		i++;
	}
	while(i<=pMax1)
	{
		C[i]=A[i];
		i++;
	}
	while(i<=pMax2)
	{
		C[i]=B[i];
		i++;
	}	
}

int main()
{
	int A[10005],B[10005],C[10005];
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
	
	addPolynomial(A,pMax1,B,pMax2,C);
	
	int maxPower=max(pMax1,pMax2);
	for(int i=0;i<maxPower;i++)
	{
		cout<<C[i]<<"x^"<<i<<" + ";	
	}	
	cout<<C[maxPower]<<"x^"<<maxPower;
	
	return 0;
}
