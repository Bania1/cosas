#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int j=29;
    int A[30], B[30];

    srand(time(NULL));

    /*for (int i = 0; i < 30; i++)
    {
        A[i] = 1 + rand()%10;
        B[i] = 1 + rand()%10;
    }*/
    
    for (int i = 0; i < 30; i++)
    {
        if (j >= 0)
        {
            A[i]=B[j];
            printf("A[%d]     --->     B[%d]\n", i, j);
            //printf("A[%d] = %d      --->     B[%d] = %d\n", i, A[i], j, B[j]);
            j--;
        }
    }
    
    
    return 0;
}