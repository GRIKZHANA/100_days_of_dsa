#include<stdio.h>

int main()
{
    int m,n;
    printf("Enter the numbers of the rows and column\n");
    scanf("%d %d",&m,&n);

    if(m!=n)
    {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    int mat[m][n];

    printf("\nEnter the elements in the matrix\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }

    int is_symmetric = 1;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j] != mat[j][i])
            {
                is_symmetric = 0;
                break;
            }
        }
        if(is_symmetric==0)
            break;
    }

    if(is_symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}