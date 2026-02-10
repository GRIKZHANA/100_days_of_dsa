#include<stdio.h>
#include<string.h>

int main()
{
    char s[50];
    printf("Enter a string\n");
    scanf("%s",s);

    int l=strlen(s);

    for(int i=l-1;i>=0;i--)
    {
        printf("%c",s[i]);
    }
}