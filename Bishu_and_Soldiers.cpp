/*
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll i,n,q,x,y,z;
    cin>>n;
    vector<ll> v(n);
    for(i=0;i<n;i++)
    	cin>>v[i];
    cin>>q;
    while(q--){
    	cin>>x;
    	y = 0;
    	z = 0;
    	for(i=0;i<n;i++){
    		if(v[i] <= x){
    			y++;
    			z += v[i];
    		}
    	}
    	cout<<y<<" "<<z<<endl;
    }
    return 0;
}
*/
