#include<bits/stdc++.h>
using namespace std;
int main(){
long long int t,n,n1;
cin>>t;
while(t--){
cin>>n1;
n=n1%12;
if(n==1){n=n1+11;}
else if(n==2 ){n=n1+9;}
else if(n==3){n=n1+7;}
else if(n==4 ){n=n1+5;}
else if(n==5 ){n=n1+3;}
else if(n==6 ){n=n1+1;}
else if(n==7){n=n1-1;}
else if(n==8){n=n1-3;}
else if(n==9){n=n1-5;}
else if(n==10){n=n1-7;}
else if(n==11){n=n1-9;}
else if(n==0){n=n1-11;}
if(n%12==1){cout<<n<<" WS"<<endl;}
else if(n%12==2){cout<<n<<" MS"<<endl;}
else if(n%12==3){cout<<n<<" AS"<<endl;}
else if(n%12==4){cout<<n<<" AS"<<endl;}
else if(n%12==5){cout<<n<<" MS"<<endl;}
else if(n%12==6){cout<<n<<" WS"<<endl;}
else if(n%12==7){cout<<n<<" WS"<<endl;}
else if(n%12==8){cout<<n<<" MS"<<endl;}
else if(n%12==9){cout<<n<<" AS"<<endl;}
else if(n%12==10){cout<<n<<" AS"<<endl;}
else if(n%12==11){cout<<n<<" MS"<<endl;}
else if(n%12==0){cout<<n<<" WS"<<endl;}
}
return 0;
