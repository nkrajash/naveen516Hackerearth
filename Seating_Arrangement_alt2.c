in cpp**
#include <iostream>
using namespace std;
int main()
{
int i,j,test;
cin>>test;
int seat[test],opp[test];
for(i=0;i<test;i++)
{
cin>>seat[i];
}
for(i=0;i<test;i++)
{
for(j=1;j<=12;j++)
{
if((seat[i]-j)%12==0)
{
opp[i]=seat[i]+(13-(2*j));
}
}
if((seat[i]-1)%12==0||(seat[i]-6)%12==0||(seat[i]-7)%12==0||(seat[i]-12)%12==0)
{
cout<<opp[i];
cout<<" WS\n";
}
if((seat[i]-3)%12==0||(seat[i]-4)%12==0||(seat[i]-9)%12==0||(seat[i]-10)%12==0)
{
cout<<opp[i];
cout<<" AS\n";
}
if((seat[i]-2)%12==0||(seat[i]-5)%12==0||(seat[i]-8)%12==0||(seat[i]-11)%12==0)
{
cout<<opp[i];
cout<<" MS\n";
}

}
return 0;
}
