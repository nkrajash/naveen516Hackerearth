/* Editorial:
This problem is a basic search problem. Linear search will exceed the time limit as its complexity is O(N). 
We can solve this problem by using binary search as explained in this article. Let us see why binary search will not give time limit exceed error. 
There are Q queries and size of array is N. So if we use linear search for each query then the total time will be O(NQ). But if we first sort the array 
which will take O(NlogN) and then apply binary search for each query then the total time will be O(QlogN + NlogN) which is indeed better than O(NQ).

Author Solution by Akash Sharma

    #include <iostream>
    #include <cassert>
    #include <algorithm>
    #include <vector>
    using namespace std;
    vector <long long > v;
    int main()
    {
    	int n, q;
    	long long x;
    	cin >> n >> q;
    	assert(1 <= n and n <= 100000);
    	assert(1 <= q and q <= 100000);
    	for(int i = 0;i < n;++i)
    	{
    		cin >> x;
    		v.push_back(x);
    	}
    	sort(v.begin(), v.end());
    	string s;
    	for(int i = 0;i < q;++i)
    	{
    		cin >> x;
    		assert(1 <= x and x <= 1000000000LL);
    		if(binary_search(v.begin(), v.end(), x))
    			s = "YES";
    		else
    			s = "NO";
    		cout << s << endl;
    	}
    }

*/