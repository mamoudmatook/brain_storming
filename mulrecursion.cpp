#include <iostream>
using namespace std;
int mulrec(int a, int b);
int main (int argc,char **argv)
{
	cout<<mulrec(4,3)<<endl;
}
int mulrec(int a,int b)
{
	if(b==0)
		return 0;
	return a+mulrec(a,b-1);
}


