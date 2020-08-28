#include <stdio.h>
#define INF 9999999        // Use as infinite...

int main()
{
    printf("\n\t-= Prime's Algorithm =-\n\n");


    int v,i,j;

    printf("\tHow many vertex: ");
    scanf("%d",&v);

    int arr[v][v];          // n*n matrix
    int edge = 0;           // number of edge
    int selected[v];        // selected vertex

    for(i=0; i<v; i++)
    {
        selected[i]=0;      // at first make all selected vertex zero
    }

    selected[0]=1;
    /*
    Initial variable and array setup are done.....
    */

    // Now take every edge value as matrix
    printf("\n");
    for(i=0; i<v; i++)
    {
        for(j=0; j<v; j++)
        {
            printf("\tVertex[%d] => Vertex[%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    /*

    arr[5][5] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}
    };

    this input like that...
    you can use in manually like that.

    */


    /*
    Main Algorithm Start now ....
    */

    printf("\n\tEdge : Weight\n");

    while(edge < v-1)               // We now vertex-1=edge
    {

        int min = INF;              // At first take the minimum number as infinite
        int x=0;                    // Row
        int y=0;                    // Column



        for(i=0; i<v; i++)                                  // Check every row
        {
            if(selected[i]==1)                              // Start checking to selected vertex, Only if selected
            {
                for(j=0; j<v; j++)                          // Check every column
                {
                    if(selected[j]!=1 && arr[i][j]!=0)      // not in selected and there is an edge
                    {
                        if(min>arr[i][j])                   // Choose minimum edge
                        {
                            min=arr[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        printf("\t%d - %d : %d\n", x, y, arr[x][y]);
        selected[y] = 1;
        edge++;
    }

    return 0;
}
