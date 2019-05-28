#include <stdio.h>
#include <stdlib.h>
int arr[10];
int main()
{
	int i;
	for (i=0;i<10;i++)
		arr[i]=i;
	for (;i>=0;i--)
		printf("%d ",arr[i-1]);
	return 0;

}
