#include <stdio.h>
#include <string.h>
#define MAX 101

int main()
{
    char s[MAX];
    int i=0,j=0,flag=0;
    if(fgets(s,MAX,stdin)!=NULL){
        j=strlen(s)-1;
        while(i!=j/2){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                flag=1;
                break;
            }
        }
    }
    if(!flag)
        printf("YES");
    else
        printf("NO");
}