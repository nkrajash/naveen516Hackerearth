/* Speed.cpp*/

#include <iostream>
#define N 100000
using namespace std;

int main()
{
    int t,n,i,j,k,speed[N],ncars;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        ncars=1;
        for(j=0;j<n;j++)
            cin>>speed[j];
        for(k=1;k<n;k++){
            if(speed[k-1]>speed[k])
                ncars++;
            else
                speed[k]=speed[k-1];
        }
        cout<<ncars<<endl;
    }
    return 0;
}