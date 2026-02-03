#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    int num;
    int in;
    printf("Enter the number of the element \n");
    scanf("%d",&n);

    int *ptr;

    ptr=(int *)malloc(n*sizeof(int));

    printf("Enter the elements in the ptr \n");

    for(int i=0;i<n;i++)
    {
        printf("Enter a number at %d index \n",i);
        scanf("%d",&ptr[i]);
    }

    printf("\n");

    for(int i=0;i<n;i++)
    {
        printf("the element at the %d index is %d \n",i,ptr[i]);
    }

    printf("Enter a number to be inserted \n");
    scanf("%d",&num);
    printf("Enter the index at which number is to be inserted \n");
    scanf("%d",&in);

    ptr=(int *)realloc(ptr,(n+1)*sizeof(int));

    for(int i=n;i>in;i--)
    {
        ptr[i]=ptr[i-1];
    }

    ptr[in]=num;

    printf("New array after the reallocation \n");

    for(int i=0;i<=n;i++)
    {
        printf("the element at the %d index is %d \n",i,ptr[i]);
    }

    free(ptr);

}