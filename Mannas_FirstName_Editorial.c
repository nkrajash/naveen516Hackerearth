#include <stdio.h>
#include <string.h>
int main()
{
    char arr[150];
    int t,i,a,b,l;
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%s\n",&arr);
        a=0;
        b=0;
        l=strlen(arr);
        for(i=0;i<=l-4;i++)
        {
            if(arr[i]=='S' && arr[i+1]=='U'&&arr[i+2]=='V'&&arr[i+3]=='O')
                a++;
        }

        for(i=0;i<=l-7;i++)
        {
            if(arr[i]=='S' && arr[i+1]=='U'&&arr[i+2]=='V'&&arr[i+3]=='O'&&arr[i+4]=='J'&& arr[i+5]=='I'&&arr[i+6]=='T')
                b++;
        }
        printf("SUVO = %d, ",a-b);
        printf("SUVOJIT = %d\n",b);
    }
    return 0;
}