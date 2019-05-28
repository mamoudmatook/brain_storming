#include <stdio.h>
#include <stdlib.h>
int main()
{
	size_t buff_sz=100;
	char * buff;
	buff=(char*)malloc(buff_sz*sizeof(char));
	getline(&buff,&buff_sz,stdin);
       int index=0;
       while(buff[index]!='\0')
       {
	       printf("%c",buff[index]);
	       index++;
       }
       return 0;
}

