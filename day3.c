#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    int num;
    printf("Enter a number");
    scanf("%d",&n);

    int *ptr;
    ptr=(int *)malloc(n*sizeof(int));

    printf("Enter the array's element \n ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ptr[i]);
    }

    printf("The array elements are \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",ptr[i]);
    }

    printf("\nEnter a number to be searced");
    scanf("%d",&num);

    int count=0;

    for(int i=0;i<n;i++)
    {
        if(ptr[i]==num)
        {
            count=n-i;
            printf("Found at index %d",i);
        }
    }
    printf(" \n Comparisons=%d",count);

    free(ptr);
}