#include <stdio.h>
int main()
{
    printf("\n    -=# All Pairs Shortest Path #=-\n\n");
    printf("    Note: for infinite value use -1\n\n");
    int v,i,j;

    printf("\t[+] Number of vertex: ");
    scanf("%d",&v);

    printf("\n");

    int matrix[v][v];


    for(i=0; i<v; i++)
    {
        for(j=0; j<v; j++)
        {
            printf("\t[%d] to [%d]: ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }


    int testCase=0;   //So called middleMan
    while(testCase < v)
    {
        for(i=0; i<v; i++)
        {
            for(j=0; j<v; j++)
            {
                int a=matrix[i][testCase];
                int b=matrix[testCase][j];

                if(matrix[i][j]==-1)
                {
                    if(a!=-1 && b!=-1 && a+b>-1)
                        matrix[i][j]=a+b;
                }
                else if(matrix[i][j] > a+b)
                {
                    matrix[i][j] = a+b;
                }
            }
        }


        //just Show every matrix
        printf("\n\tMatrix number: %d\n",testCase+1);
        if(testCase+1==v)
        {
            printf("\t(final matrix) \n");
        }
        for(i=0; i<v; i++)
        {
            for(j=0; j<v; j++)
            {
                printf("\t%d",matrix[i][j]);
            }
            printf("\n");
        }


        testCase++;
    }

    return 0;
}
