#include<stdio.h>
#include<string.h>

int main()
{
    char s[50];
    printf("Enter a string \n");
    scanf("%s", s);
    int l=strlen(s);

    int left=0;
    int right=l-1;
    int ispalin=1;

    while(left<right)
    {
        if(s[left]!=s[right])
        {
            ispalin=0;
            break;
        }
        left++;
        right--;
    }

    if(ispalin==1)
    {
        printf("\nPALINDROME ");
    }
    else
    {
        printf("\nNOT A PALINDROME ");
    }
}