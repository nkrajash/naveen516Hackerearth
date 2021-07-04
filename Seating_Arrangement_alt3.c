In C++
#include<iostream>

using namespace std;

int opp(int x)
{
int t;
t=x%12;
int r;
switch(t)
{

case 1: r=x+11;
break;
case 2: r=x+9;
break;
case 3: r=x+7;
break;
case 4: r=x+5;
break;
case 5: r=x+3;
break;
case 6: r=x+1;
break;
case 7: r=x-1;
break;
case 8: r=x-3;
break;
case 9: r=x-5;
break;
case 10: r=x-7;
break;
case 11: r=x-9;
break;
case 0: r=x-11;
break;

}
return r;
}

int main()
{
int t,n;
cin>>t;
int i;
int m;
for(i=0;i<t;i++)
{
cin>>n;

cout <<opp(n);
m=n%6;
if(m==0 || m==1)
cout<<" WS\n";
else if(m==2 || m==5)
cout<<" MS\n";
else if(m==3 || m==4)
cout<<" AS\n";

}

return 0;
}
