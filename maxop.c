#include "stack.h"
typedef struct
{
	int row;
	int col;
	char name;
	int* val;
}Mat;
Stack* operands;
Stack* operators;
int size=(int)'Z'-'A';
//int index=0; // index of array of matrices
Mat *arr=(Mat*) malloc(size*sizeof(Mat));
Mat* Mat_tmp[26];

void Mat_free(Mat* mat)
{

}

void Mat_create(char* buf,Mat *mat)
{
	int row=0;
	int col=0;
	int index=0;
	while(buf[index]!=']')
	{
		if(buf[index]=='[')
		{
			int col_index=index+1;
			while(buf[col_index]!=';')
			{
				col++;
				col_index+=1;
			}
		}
		if (buf[index]==';')
			row++;
		index+=1;
	}
	row+=1;
	mat->val=(int*) malloc(row*col*sizeof(int));
	mat->row=row;
	mat->col=col;
	mat->name=buf[0];
	index=0;
	int val_index=0;
	while(buf[index]!=']')
	{
		if(buf[index]>='0' &&  buf[index]<='9')
		{  
			if(buf[index-1]=='-')
				mat->val[val_index]=-(buf[index]-'0');
			else 
				mat->val[val_index]=buf[index]-'0';
			val_index++;
		}
		index++;
	}
}
void Mat_print_inline(Mat *mat)
{

	int i,j;
             printf("[");
             for (i=0;i<mat->row;i++)
		      {
		      for(j=0;j<mat->col;j++)
		      {
			      printf("%d ",*(mat->val+(i*mat->col)+j));
		      }
			      printf(";");
		 }
			      printf("]");


}
Mat* summation(Mat* mat1,Mat* mat2)
{
	return NULL;
}
Mat* subtraction(Mat* m1,Mat* m2)
{
	return NULL;
}
Mat* Multiplication(Mat* m1,Mat* m2)
{
	return NULL;
}
char* nmEx(char* buf)
{
	int index=0;
	int  nm_counter=0;
	while(buf[index]!='\0')
	{
			if(buf[index]>='A' && buf[index]<='Z')
			{
			nm_counter++;
			}
			index++;

			
	}
	char* name;
	name=(char*)malloc(nm_counter+1*sizeof(char));
	index=0;
	int count=0;
	while(buf[index]!='\0')
	{
			if(buf[index]>='A' && buf[index]<='Z')
			{
				name[count]=buf[index];
				count++;
			}
			index++;
	}
	name[count]='\0';
	return name;

			

				
	
}
Mat* creat_unity_mat(int row,int col);
{
	Mat* tmp=(Mat*)malloc(sizeof(Mat));
	tmp->row=row;
	tmp->col=col;
	tmp-val=(int*)malloc(row*col*sizeof(int));
	int i;
	for(i=0;i<row*col;i++)
		tmp->val[i]=1;
	return tmp;

}
Mat* creat_zero_mat(int row,int col)
{
	Mat* zero=(Mat*)malloc(sizeof(Mat));
	zero->row=row;
	zero->col=col;
	zero->val=(int*)malloc(row*col*sizeof(int));
	int i;
	for(i=0;i<row*col;i++)
		zero->val[i]=0;
	return zero;
}

Mat* MulEvaluate(char* buf)
{
	char* tmp_buf=nmEx(buf);
	int row,col;
	int index=tmp_buf[0]-'A';
	row=arr[index].row;
	col=arr[index].col;

	index=0;
	Mat* Result=creat_unity_mat(row,col);
	while(tmp_buf[index]!='\0')
	{
		int l=tmp_buf[index]-'A';
		Mat* t=MatMul(Result,&arr[l]);
		Mat_free(Result);
		Result=t;
		index++
	}
	free(tmp_buf);
	free(buf);
	return Result;
}
		


	
}
Mat* ArthEvaluate(char* buf)
{
	if(strlen(buf)==1)
		return &arr[buf[0]-'A'];
	int index=2;
	int i=buf[0]-'A';
	Mat* Result=&arr[i];
	while(buf[index]!='\0')
	{       Mat* tmp;
		if(buf[index]>='A' && buf[index]<='Z')
		{

			if(buf[index-1]=='+')
			{
			int j=buf[index]-'A';
			tmp=summation(Result,&arr[j]);
			Mat_free(Result);
			Result=tmp;
			
			}
			
			if(buf[index-1]=='-')
			{
				int j=buf[index]-'A';
				tmp=subtraction(Result,&arr[j]);
				Mat_free(Result);
				Result=tmp;
			
			}
		}
		index++;
	}
	return Result;
}


Mat* MatExp(char *buf)
{       Mat* Result;
	int Gindex=0;
	int lindex=0;
	int strt=0;
	while(buf[Gindex]!='\n')
	{       strt=Gindex;
		if(buf[Gindex]=='*')
		{
			lindex=Gindex+1;
			while(buf[lindex]!='+' || buf[lindex]!='-')
			{
				lindex++;
			}
		
			size_t fact_sz=lindex-Gindex+1;
			char* factor;
			factor=(char*)malloc(fact_sz+1*sizeof(char));
			strncpy(factor,buf+Gindex-1,fact_sz);
			factor[fact_sz]='\0';
			Mat* ftmp=MUlEvaluate(factor);
			free(factor);
			if(Gindex-1!=strt)
			{
				size_t arth_sz=Gindex-2-strt;
				char* arth;
				arth=(char*)malloc(arth_sz+1*sizeof(char));
				strncpy(arth,buf+str,arth_sz);
				arth[arth_sz]='\0';
				Mat* atmp=ArthEvalute(arth);//proceed with what's left   
			}
		}
	}



			





}
Mat* RecursiveParser(char* buf)
{        
	
	int index=0;
	while(buf[index]!='\0')
	{       
		if(buf[index]==' ')
			continue;
		if(buf[index]>='A' && buf[index]<='Z')
			push(operands,buf[index]);
		else
		{
			while(!isEmpty(operators) && prcedence(top(operators))>=prcedence(buf[index]))
			{
				char val2=pop(operands);
				char val1=pop(operands);
				char op=pop(operators);
				applyTo(&arr[val1-'A'],



int main()
{
	size_t input_sz=15000;	
	char *buf=(char*)malloc(input_sz*sizeof(char));
       while(1)
       {
       
	       
	       getline(&buf,&input_sz,stdin);
	       if(buf[1]=='=')
	       {
			int m=(int)buf[0]-'A';
	       		Mat_create(buf,&arr[m]);
			
	       }
	       else if (buf[1]=='+' || buf[1]== '-' || buf[1]=='*')
		       break;

       }
       unsigned int no_operands=0;
       unsigned int no_operators=0;
       int index=0;
       while(buf[index]!='\0')
       {
	       if (buf[index]>='A'&& buf[index]<='Z')
		       no_oprands++;
	       else
		       no_operators++;
	       index++;
       }
       operands=creatStack(no_operands);
       operators=createStack(no_operators);
       Mat* Result=RecursiveParser(buf);



     
       return 0;
}
