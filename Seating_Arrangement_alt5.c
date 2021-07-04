in c
#include <stdio.h>
int main()
{
int n,t,s,r;
scanf("%d",&t);
while(t--){
scanf("%d",&n);
s=n%12;
if(s==0)
n-=11;
else if(s<7)
n+=(2*(6-s)+1);
else
n-=(2*(s-7)+1);
r=n%6;
if(r==1 || r==0)
printf("%d WS\n",n);
else if(r==2 || r==5)
printf("%d MS\n",n);
else
printf("%d AS\n",n);
}
return 0;
}
