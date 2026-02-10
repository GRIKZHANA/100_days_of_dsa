#include<stdio.h>

int power(int a, int b);

int main()
{   
    int base;
    int raise;
    printf("enter a base number\n");
    scanf("%d",&base);
    printf("\nEnter the power number \n");
    scanf("%d",&raise);
    int c=power(base,raise);
    printf("%d",c);
}

int power(int a, int b)
{
    if(b==0)
    {
        return 1;
    }
    else
    {
        int pow=a*power(a,b-1);
        return pow;
    }
}