/* All Tracks -->  Algorithms --> Sorting --> Problem --> Monk being monitor
Tag(s): Easy-Medium, Sorting, Sorting
Monk being the monitor of the class needs to have all the information about the class students. 
He is very busy with many tasks related to the same, so he asked his friend Mishki for her help in one task. 
She will be given heights of all the students present in the class and she needs to choose 2 students having heights h1 and h2 respectively, 
such that h1>h2 and difference between the number of students having height h1 and number of students having height h2 is maximum.

Note: The difference should be greater than 0.

As Mishki has never been a monitor of the class, help her in the same. If there exists such students, then print the required difference else print "1" (without quotes).

Input:
The first line will consists of one integer T, which denotes the number of test cases.
For each test case:
One line consists of a integer N, denotes the number of students in the class.
Second line contains N space separated integers, where ith integer denotes the height of the ith student in the class.

Output:
For each test case, if the required difference exists then print its value, otherwise print 1. Print the answer for each test case in a new line.

Constraints:
1<=T<=10
1<=N<=10^5
1<=height of the student<=10^6

SAMPLE INPUT 
1
6
3 1 3 2 3 2
SAMPLE OUTPUT 
2
Explanation
Here T=1 and N = 6.

Number of students having height = 3 is 3.
Number of students having height = 2 is 2.
Number of students having height = 1 is 1.

Here Mishki can choose students with height=3 (h1) and height = 1 (h2) , as the difference between number of students having height (h1) and 
number of students having height (h2) is maximum and greater than 0.

#include <iostream>
#include <algorithm>
using namespace std;
struct mem
{
    int val,count;
};

int cmp(struct mem a,struct mem b)
{
    if(a.val<b.val)
      return 1;
    else
      return 0;
}

int cmp1(struct mem a,struct mem b)
{
    if(a.count<b.count)
      return 1;
    else
      return 0;
}
int main()
{
     int t,n;
     cin>>t;
     while(t)
     {
         int n;
         cin>>n;
         struct mem arr[n];
         for(int i=0;i<n;i++)
         {
            cin>>arr[i].val;
            arr[i].count=1;
         }
         sort(arr,arr+n,cmp);
         for(int i=1;i<n;i++)
         {
             if(arr[i].val==arr[i-1].val)
             {
              arr[i].count+=arr[i-1].count;
              arr[i-1].count=-1;
             }
         }
         sort(arr,arr+n,cmp1);
         struct mem temp;
         int k=0;
         while(arr[k].count<=0)
         {
             k++;

         }
         int op=arr[n-1].count-arr[k].count;
         if(op>0)
         cout<<op<<"\n";
         else
         cout<<"-1\n";
         t--;
     }
    return 0;
}


*/


/*Editorial:
Author: ptk23
Tester: vaibhav_jaimini
Editorialist: vaibhav_jaimini

Brief Description: Given an array of N integers, find the maximum difference between frequency of any two different integers, 
making sure that the integer having greater frequency is also greater in value than the second integer.

Prerequisite: Any O(nlogn) sorting algorithm like Merge Sort or Quick Sort.

Hint: Sort distinct heights, maintaining the frequency of each height. In the sorted list, for each height find the minimum frequency in left.

Difficulty: Easy

Detailed Editorial:
First we need to count the frequency of all the distinct heights and store it in an array frequency[] (frequency[i] will denote the number of students having height i). 
Make a new array distinct_heights[] containing all the distinct heights and sort it in ascending order. 
Our condition is, if we choose two heights h1 and h2, then we want that h1>h2 and frequency[h1] > frequency[h2]  and we want to find the maximum value of  
frequency[h1] - frequency[h2] for all such h1 and h2. 
Since we have sorted distinct_heights[], for all  j(0<=j<=i),distinct_heights[j]<distinct_heights[i], so now for each height distinct_heights[i], 
we just need to find the height between distinct_heights[0] to distinct_heights[i-1] having minimum frequency. 
This will give us the maximum answer that we can achieve if we choose h1=distinct_heights[i]. 
So we'll do this for all i and find the maximum of that to arrive at the final answer. 
To find the minimum frequency for all i we can maintain a prefix minimum.

Pseudo Code:

solve(n, heights[])
    distinct_heights = []
    ans = 0
    cnt = 0
    initialize an array frequency[] by 0
    for i = 0 to n-1
        if frequency[height[i]] is 0
            distinct_heights[cnt] = height[i]
            cnt = cnt+1
        frequency[height[i]] = frequency[height[i]]+1
    sort(distinct_heights, cnt)
    min_frequency = n+1
    for i = 0 to cnt-1
        cur_frequency = frequency[distinct_heights[i]]
        ans = maximum(ans, cur_frequency-min_frequency)
        min_frequency = minimum(min_frequency, cur_frequency)

    if ans is 0
        return -1
    else
        return ans

Time Complexity: O(nlogn)
Space Complexity: O(n)

Author Solution by Prateek Garg
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 1e5+5;
int a[MAX],fre[1000005],pre_m[MAX];
pair <int,int> p[MAX];
int main()
{
	//freopen(argv[1],"r",stdin);
	//freopen(argv[2],"w",stdout);
	int t;
	for(scanf("%d",&t);t;--t)
	{
		int n;
		cin>>n;
		assert(n>=1 and n<=1e5);
		for(int i=1;i<=1e6;i++)
			fre[i]=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			assert(a[i]>=1 and a[i]<=1e6);
			fre[a[i]]++;
		}
		int k=0;
		for(int i=1;i<=1e6;i++)
		{
			if(fre[i])
			{
				p[k] = make_pair(i,fre[i]);
				if(k==0)
				{
					pre_m[k]= fre[i];
				}
				else
				{
					pre_m[k] = min(pre_m[k-1], fre[i]);
				}
				k++;
			}
		}
		sort(p,p+k);
		int ma=-1;
		for(int i=k-1;i>=0;i--)
		{
			if(p[i].second != pre_m[i])
			{
				ma = max(ma, p[i].second - pre_m[i]);
			}
		}
		cout<<ma<<endl;
	}
	return 0;
}

*/

/*Best Submissions:
C:
#include <stdio.h>
#include <stdlib.h>
 
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
 
int main(int argc, char *argv[])
{
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; t++)
    {
        int n;
        scanf("%d", &n);
        int *numbers = (int *)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &numbers[i]);
        }
        qsort(numbers, n, sizeof(int), cmp);
        int minimum = 100001, maximum = 0;
        int pre = -1, c = 0;
        for(int i = 0; i < n; i++)
        {
            int number = numbers[i];
            if(pre == -1)
            {
                c = 1;
                pre = number;
                continue;
            }
            if(pre == number)
            {
                c += 1;
            }
            else
            {
                if(c > maximum)
                {
                    maximum = c;
                }
                if(c < minimum)
                {
                    minimum = c;
                }
                c = 1;
            }
            pre = number;
        }
        if(c > maximum)
        {
            maximum = c;
        }
        if(c < minimum)
        {
            minimum = c;
        }
        int d = maximum - minimum;
        printf("%d\n", d > 0 ? d : -1);
    }
    return 0;
}

C++:
#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define len(s) s.length()
#define forp(i,a,b) for( i=a;i<=b;i++)
#define FOR(tt,a,b) for(int tt=a;tt<=b;tt++)
#define rep(i,n)    for( i=0;i<n;i++)
#define ren(i,n)    for( i=n-1;i>=0;i--)
#define forn(i,a,b) for( i=a;i>=b;i--)
#define all(v) v.begin(),v.end()
#define b(v) v.begin()
#define e(v) v.end()
#define mem(n,m) memset(n,m,sizeof(n))
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define gl(cin,s)  getline(cin,s);
#define bitc(n) __builtin_popcountll(n)
#define present(s,x) (s.find(x) != s.end()) 
#define cpresent(s,x) (find(all(s),x) != s.end()) 
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
 
#define boost ios_base::sync_with_stdio(0)
#define MOD 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define SIZE 1000001
 
typedef long long  ll;
typedef unsigned long long ull;
typedef long double  ldo;
typedef double  db ;
using namespace std;
int main()
{  	
	//#ifndef ONLINE_JUDGE
	//freopen(fi, "r", stdin);
	//#endif
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//cin.ignore();
	//cin.clear();
	boost;
	//cin.tie(0);
	//cout<<"Case #"<<tt<<": ";
	int i,n,t,x;
	int cnt[SIZE];
	cin>>t;
	while(t--){
		cin>>n;
		mem(cnt,0);
		forp(i,1,n){
			cin>>x;
			cnt[x]++;
		}
		vii v;
		forp(i,1,SIZE-1){
			if(cnt[i]){
				v.pb(cnt[i]);
			}
		}
		sort(all(v));
		if(v[0]==v[v.size()-1]){
			cout<<"-1\n";
		}
		else{
			cout<<v[v.size()-1]-v[0]<<endl;
		}
	}
	return 0;
}

C++14:

C#:



*/



