#include <iostream>
using namespace std;
int sort(int *,int);
int main (int argc,char ** argv)
{
	int a[]={5,4,10,3,8,20,55,30};
	cout<<sort(a,8)<<endl;
}
int sort(int *a,int n)
{    int x;
	if(n==1)
		return a[0];

        x=sort(a+1,n-1);
	if (a[0]>x)
		x=a[0];
	return x;
}

