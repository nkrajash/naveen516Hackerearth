/*Tester Solution by Chandan Singh
	Code Monk- Searching	https://www.hackerearth.com/problem/algorithm-template/341ba6b04f4c0cdc453505b06e397acb/test/         

    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
    	int N,Q;
    	cin>>N>>Q;
    	int a[N];
    	for(int i=0;i<N;i++)
    		cin>>a[i];
    	sort(A,A+N);
    	for(int i=0;i<Q;i++)
    	{
    		int X;
    		cin>>X;
    		bool flag=false;
    		int lb=0,ub=N-1;
    		while(lb<=ub)
    		{
    			int mid=(lb+ub)/2;
    			if(a[mid]>X)
    				ub=mid-1;
    			else if(a[mid]<X)
    				lb=mid+1;
    			else
    			{
    				flag=true;
    				break;
    			}
    		}
    		if(flag)
    			cout<<"YES"<<endl;
    		else
    			cout<<"NO"<<endl;
    	}
    	return 0;
    }
*/
