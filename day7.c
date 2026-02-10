#include<stdio.h>

int fibo(int num);

int main()
{
    int n;
    printf("Enter a limit \n");
    scanf("%d",&n);
    int s=fibo(n);
    printf("\n%d",s);
}

int fibo(int num)
{
    if(num==0)
    {
        return 0;
    }
    else if(num==1)
    {
        return 1;
    }
    else
    return fibo(num-1)+fibo(num-2);
}