#include <stdio.h>

#include <stdlib.h>

#include <math.h>


void free_input(int **ptr,int N)
{
       	int i;
	for ( i = 0; i < N; i++)
{
    int* currentIntPtr = ptr[i];
    free(currentIntPtr);
   currentIntPtr=NULL;
}
}

void free_inputf(float **ptr,int N)
{ 
	int i;
	for ( i = 0; i < N; i++)
{
    float* currentIntPtr = ptr[i];
    free(currentIntPtr);
   currentIntPtr=NULL;
}

}
void negate(int **a,int m,int n)
{ int i,j;
	for (i = 0; i < m; i++)

    {


        for (j = 0; j < n; j++)

        {
              a[i][j]=-a[i][j];
             // *(*(a + i) + j)=-(*(*(a + i) + j));

        }

    }
}



int **create(int m, int n, int mo)

{

    int i,j; int **a;

    a = (int**)malloc(m * sizeof(int*));

    

    for(i = 0; i < m; i++)

    {

        *(a + i) = (int *)malloc(n * sizeof(int));

    }

    if(mo)

    {

    printf("\nEnter Values to the matrix (One by one) :");

    

    for(i = 0; i < m; i++)

    {

        for(j = 0; j < n; j++)

        {

            scanf("%d", &(*(*(a + i) + j)));

        }

    }

	}

    return a;

}



float **createfl(int m, int n, int mo)

{

    int i,j; float **a;

    a = (float**)malloc(m * sizeof(float*));

    

    for(i = 0; i < m; i++)

    {

        *(a + i) = (float *)malloc(n * sizeof(float));

    }

    if(mo)

    {

    printf("\nEnter Values to the matrix (One by one) :");

    

    for(i = 0; i < m; i++)

    {

        for(j = 0; j < n; j++)

        {

            scanf("%f", &(*(*(a + i) + j)));

        }

    }

	}

    return a;

}



void print (int **a, int m, int n)

{

	int i, j;

    for (i = 0; i < m; i++)

    {

        printf("\n");

        for (j = 0; j < n; j++)

        {

            printf("%d\t", *(*(a + i) + j));

        }

    }

    printf("\n\n*********************");

}



void printfl (float **a, int m, int n, int mo)

{

	int i, j;

    if(mo)

    {

    for (i = 0; i < m; i++)

    {

        printf("\n");

        for (j = 0; j < n; j++)

        {

            printf("%f\t", *(*(a + i) + j));

        }

    }

    printf("\n\n*********************");

	}

	else

	{

		for (i = 0; i < m; i++)

    {

        printf("\n");

        for (j = 0; j < n; j++)

        {

            printf("%d\t", (int)*(*(a + i) + j));

        }

    }

    printf("\n\n*********************");

	}

}



int **matadd (int **a, int m, int n, int **b)

{

    int **ar; int i, j;

    ar = create(m, n, 0);

    for(i = 0; i < m; i++)

    {

        for (j = 0; j < n; j++)

        {

            *(*(ar + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);

        }

    }

    return ar;

}



int **matsub (int **a, int m, int n, int **b)

{

    int **ar; int i, j;

    ar = create(m, n, 0);

    for(i = 0; i < m; i++)

    {

        for (j = 0; j < n; j++)

        {

            *(*(ar + i) + j) = *(*(a + i) + j) - *(*(b + i) + j);

        }

    }

    return ar;

}



int **matmult (int **a, int m1, int n1, int **b, int m2, int n2)

{

    int **ar; int i, j, k;

    ar = create(m1, n2, 0);

    for (i = 0; i < m1; i++)

    {

        for (j = 0; j < n2; j++)

        {

            *(*(ar + i) + j) = 0;

            for (k = 0; k < m2; k++)

            {

                *(*(ar + i) + j) += *(*(a + i) + k) * *(*(b + k) + j);

            }

        }

    }

    return ar;

}



float **matrps(float **a, int m, int n)

{

	int i, j; float **trps;

	trps = createfl(n, m, 0);

	for(i = 0; i < m; i++)

	{

		for(j = 0; j < n; j++)

        {

            *(*(trps + j) + i) = *(*(a + i) + j);

        }

	}

	return trps;	

}



float determinant(float **a, int k)

{

	float s = 1, det = 0, **b;

	int i, j, m, n, c;

	b = createfl(k, k, 0);

	if (k == 1)

    {

     return (*(*(a + 0) + 0));

    }

	else

    {

		det = 0;

		for (c = 0; c < k; c++)

		{

			m = 0;

			n = 0;

			for (i = 0;i < k; i++)

			{

				for (j = 0 ;j < k; j++)

				{

					*(*(b + i) + j) = 0;

					if (i != 0 && j != c)

					{

						*(*(b + m) + n) = *(*(a + i) + j);

						if (n < (k - 2))

						{

							n++;

						}

						else

						{

							n = 0;

							m++;

						}

					}

				}

			}

				det = det + s * (*(*(a + 0) + c) * determinant(b, k - 1));

				s = -1 * s;	

		}

	}

 

    return (det);

}



float **matinv(float **a, int f, float det)

{

	float **b, **fac, **inverse;

	b = createfl(f, f, 0); fac = createfl(f, f, 0); inverse = createfl(f, f, 0);

	int p, q, m, n, i, j;

	for (q = 0;q < f; q++)

	{

		for (p = 0;p < f; p++)

		{

			m = 0;

			n = 0;

			for (i = 0;i < f; i++)

			{

				for (j = 0;j < f; j++)

				{

					if (i != q && j != p)

					{

						*(*(b + m) + n) = *(*(a + i) + j);

						if (n < (f - 2))

						{

						n++;

						}

						else

						{

							n = 0;

							m++;

						}

					}

				}

			}

			*(*(fac + q) + p) = pow(-1, q + p) * determinant(b, f - 1);

		}

	}

	for (i = 0;i < f; i++)

	{

		for (j = 0;j < f; j++)

		{

			*(*(b + i) + j) = *(*(fac + j) + i);

        }

    }

    for (i = 0;i < f; i++)

    {

		for (j = 0;j < f; j++)

		{

			*(*(inverse + i) + j) = *(*(b + i) + j) / det;

        }

    }

	return inverse;	

}



int main() 

{

	int **a, **b, **c, m1, n1, m2 , n2, opt;

	float **a1, **b1, d;

	do  

	{

	 printf("\n1)Add two matrices");  

        printf("\n2)Substract two matrices");  

        printf("\n3)Multiply two matrices");  

        printf("\n4)Transpose of a matrix");  

        printf("\n5)Determinant of a matrix");  

        printf("\n6)Inverse of a matrix");

 	printf("\n7)Negate  of a  matrix");

        printf("\n8)Quit !");

        printf("\nEnter your choice : ");

        scanf("%d", &opt);

        switch(opt) 

        {

            case 1: 

            printf("\n Enter the size of the 1st matrix(A) (in rc order) :");

            scanf("%d%d", &m1, &n1);

            a = create(m1, n1, 1);

            printf("\n Enter the size of the 2nd matrix(B) (in rc order) :");

            scanf("%d%d", &m2, &n2);

            if (m1 == m2 && n1 == n2)

            {

		b = create(m2, n2, 1);

                c = matadd(a, m1, n1, b);

                printf("\nResult A + B =\n");

                print(c,m1,n1);
		free_input(a,m1);
		free_input(b,m2);
		free_input(c,m1);
                free(a);free(b);free(c);

                break;

            }

            else

            {

                printf("\n Can not be added \n*********************");
                free_input(a,m1);
		free_input(b,m2);
                free(a);free(b);

                break;

            }

            

            case 2:

            printf("\n Enter the size of the 1st matrix(A) (in rc order) :");

            scanf("%d%d", &m1, &n1);

            a = create(m1, n1, 1);

            printf("\n Enter the size of the 2nd matrix(B) (in rc order) :");

            scanf("%d%d", &m2, &n2);

            if (m1 == m2 && n1 == n2)

            {

		b = create(m2, n2, 1);

                c = matsub(a, m1, n1, b);

                printf("\nResult A - B =\n");

                print(c, m1, n1);
		free_input(a,m1);
		free_input(b,m2);
		free_input(c,m1);
                free(a);free(b);free(c);

                break;

            }

            else

            {

                printf("\n Cannot be subtracted \n*********************");
                free_input(a,m1);
		free_input(b,m2);
                free(a);free(b);

                break;

            }

            

            case 3:

            printf("\n Enter the size of the 1st matrix(A) (in rc order) :");

            scanf("%d%d", &m1, &n1);

            a = create(m1, n1, 1);

            printf("\n Enter the size of the 2nd matrix(B) (in rc order) :");

            scanf("%d%d", &m2, &n2);

            

            if(n1 == m2)

            {

				b = create(m2, n2, 1);

                c = matmult(a, m1, n1, b, m2, n2);

                printf("\nResult AB =\n");

                print(c, m1, n2);
		free_input(a,m1);
		free_input(b,m2);
		free_input(c,m1);

                free(a);free(b);free(c);

                break;

            }

            else

            {

                printf("\nCannot be multiplied.\n*********************");
                free_input(a,m1);
		free_input(b,m2);
                free(a);free(b);

                break;

            }

            

            case 4:

            printf("\n Enter the size of the matrix (in rc order):");

            scanf("%d%d", &m1, &n1);

            a1 = createfl(m1, n1, 1);

            

            b1 = matrps(a1, m1, n1);

            printf("\nResult Transpose of A = \n");

            printfl(b1, m1, n1, 0);
	    free_inputf(a1,m1);
	    free_inputf(b1,m1);

            free(a1);free(b1);

            break;

            

            case 5:

            printf("\n Enter order of the square matrix (r only):");

            scanf("%d", &m1);

            a1 = createfl(m1, m1, 1);

            d = determinant(a1, m1);

            printf("\nResult Determinant of A = \n");

            printf("%f", d);
	    free_inputf(a1,m1);

            free(a1);

            break;

            

            case 6:

            printf("\n Enter order of the square matrix (r only):");

            scanf("%d", &m1);

            a1 = createfl(m1, m1, 1);

            d = determinant(a1, m1);

            

            if(d == 0)

            {

				printf("\nInverse of Entered Matrix is not possible\n*********************");
                                free_inputf(a1,m1);
				free(a1);

			}

			else

			{

            b1 = matinv(a1, m1, d);

            printf("\nResult Inverse of A =\n");

            printfl(b1, m1, m1, 1);
	    free_inputf(a1,m1);
	    free_inputf(b1,m1);

            free(a1);free(b1);

            break;

			}

			

	case 7:

            printf("\n Enter the size of your matrix (in rc order) :");
            scanf("%d%d", &m1, &n1);
            a = create(m1, n1, 1);
	    negate(a,m1,n1);
            printf("\nResult -A =\n");
            print(a, m1, n1);
	    free_input(a,m1);
	    free(a);
            break;

	case 8:
       		break;	    

	default: 

		printf("\nInvalid Entry ! Try again...\n");
		getchar();   //to clear buffer for scanf

		break;

        }

	} while(opt != 8);

	return 0;

}

