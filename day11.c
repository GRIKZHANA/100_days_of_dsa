#include<stdio.h>

int main()
{
    int m;int n;
    printf("Enter the number of the rows and columns of the first matrix\n");
    scanf("%d %d",&m,&n);
    int mat1[m][n];

    printf("\nEnter the elements in the first matrix\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("\nThe elements of the first matrix are\n");

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",mat1[i][j]);
        }
        printf("\n");
    }

    int mat2[m][n];

    printf("\nEnter the elements of the second matrix\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mat2[i][j]);
        }
    }
    printf("\nThe elements of the second matrix are\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",mat2[i][j]);
        }
        printf("\n");
    }

   
        int mat3[m][n];

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat3[i][j]=mat1[i][j]+mat2[i][j];
            }
        }

        printf("\nThe sum of the matrix 1 and matrix 2 are\n");
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d",mat3[i][j]);
            }
            printf("\n");
        }
    
    return 0;
}