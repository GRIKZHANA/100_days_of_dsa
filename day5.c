#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the value of n \n");
    scanf("%d",&n);

    int *arr1;
    arr1=(int *)malloc(n*sizeof(int));

    printf("Enter the elements in array 1 \n");
    for(int i=0; i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }

    printf("\nthe elements in array 1\n");
    for(int i=0; i<n;i++)
    {
        printf("%d ",arr1[i]);
    }  

    int m;
    printf("\nEnter the value of m\n");
    scanf("%d",&m);

    int *arr2;
    arr2=(int *)malloc(m*sizeof(int));

    printf("\nEnter the elements in array 2 \n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr2[i]);
    }

    printf("\nThe array 2 elements are\n");
    for(int i=0;i<m;i++)
    {
        printf("%d ",arr2[i]);
    }

    int p=m+n;

    int *arr3;
    arr3=(int *)malloc(p*sizeof(int));

    for(int i=0; i<n; i++)
    {
        arr3[i]=arr1[i];
    }
    for(int i=0;i<m;i++)
    {
        arr3[n+i]=arr2[i];
    }
    for(int i = 0; i < p - 1; i++)
    {
    for(int j = i + 1; j < p; j++)
    {
        if(arr3[i] > arr3[j])
        {
            int temp = arr3[i];
            arr3[i] = arr3[j];
            arr3[j] = temp;
        }
    }
    }

    printf("\n sorted arrival time\n");

    for(int i=0;i<p;i++)
    {
        printf("%d ",arr3[i]);
    }

    free(arr1);
    free(arr2);
    free(arr3);
}