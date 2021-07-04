/* All Tracks --> Algorithms --> Dynamic Programming --> 2 Dimensional --> Problem -->
Dreamplay and Upside Down
Tag(s): Algorithms, Dynamic Programming, Easy-Medium, String, Two dimensional
Dreamplay likes the strings that read the same upside down, that is, if we reverse the entire string, the string remains unchanged in other words, palindrome strings.
Bob does not want to upset his friend, and would thus like to make some changes, to the string P he already has, 
so that the string P is liked by dreamplay. Bob is allowed to make only two kinds of changes.
1.Add a character at end.
2.Replace a character.

Moreover, since Dreamplay is waiting for the string, Bob wants to do this in minimum steps. 
Can you find minimum number of steps needed to change the string P such that it reads same from both ends.

Input 
Only line of input consists of the string P

Output
Print a single integer, the minimum number of steps needed.

Constraints:
String P consists only of lowercase latin letters.
1<=length(P)<=5000

SAMPLE INPUT 
axcaa

SAMPLE OUTPUT 
1

Explanation:
We can change the char 'x' from string "axcaa" to obtain "aacaa" which satisfies the required property. 
Thus 1 step is needed.

//My C Solution:
#include <stdio.h>
#include <string.h>
#define LEN 5001

int getminstepspalindrome(char[],int);

int main()
{
    int steps;
    char line[LEN];
    if(fgets(line,LEN,stdin)!=NULL)
        ;
    steps=getminstepspalindrome(line,strlen(line));
    printf("%d",steps);
    return 0;
}

int getminstepspalindrome(char line[],int len){
    int steps=0,i,k,middle=len/2,begin,end=len-1,min=LEN,temp,temp1,temp2;
    for ( begin = 0 ; begin < middle ; begin++){
            if(line[begin]!=line[end-begin])
                steps++;
    }
	for(i=middle;i<=end;i++){
        temp=0;
        temp1=0;
        temp2=0;
		k=1;
        while(k){
            if((i-temp<0) || (i+k>end))
                break;
            if(line[i-temp]!=line[i+k])
                temp1++;
            temp++;
			k++;
        }
        temp1=temp1+len-(2*temp);
        temp=0;
		k=1;
        while(k){
            if((i-k<0)||(i+k>end))
                break;
            if(line[i-k]!=line[i+k])
                temp2++;
            temp++;
			k++;
        }     
        temp2=temp2+len-(2*temp);
        temp2--;
        if(temp2<temp1)
            temp1=temp2;
        if(temp1<min)
            min=temp1;
    }
	steps = (steps<min)?steps:min;
	return steps;
}

*/

/*
Best Submissions:
C:
#include <stdio.h>
#include<string.h>
char a[50001],ch;
int main()
{
 
    int i=0,j,k,z,b[2000],count1=0,count2=0,temp;
    while((ch=getchar())!='\n' && ch!=EOF)
    {
 
        a[i++]=ch;
 
    }
      count1=sum(i);
      j=0;
      b[j++]=count1;
      temp=count1;
      while(count1--){
 
        a[i++]='@';
 
          b[j++]=sum(i);
 
             if(temp>b[j-1])
              temp=b[j-1];
      }
 
    printf("%d",temp);
 
    return 0;
}
int sum(int i){
 
    int count=0,k,j;
       if(i%2==0)
        {
           k=i/2;
        }
       else
         {
        k=i/2+1;
         }
        j=i-1;
 
    for(i=0;i<k;i++)
    {
           if(a[i]!=a[j--])
           {
 
              count++;
               }
           }
           return count;
}

C++:
1).
#include <iostream>
#include <string.h>
using namespace std;
 
int main()
{
    char st[5000];
    cin>>st;
    int leng=strlen(st),count=0,count1=1,last;
    for(int i=0;i<leng/2;i++)
    {
        if(st[i]!=st[leng-i-1])
        count++;
    }
    last=leng-1;
    for(int i=1;i<leng;i++)
    {
        count1=i; last=leng-1;
        if(count1<count)
        {
            for(int j=i;j<=((leng-i)/2)+(i-1);j++)
            {
                if(st[j]!=st[last])
                count1++;
                last--;
            }
            if(count1<count)
            count=count1;
        }
        else
        break;
    }
    cout<<count<<"\n";
    return 0;
}

2).
#include<bits/stdc++.h>
using namespace std;
#define boost() ios_base::sync_with_stdio(false),cin.tie(0)
#define all(c) c.begin(),c.end()
#define rep(i,c,n) for(i=c;i<n;i++)
#define dw(t) while (t--)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD 1000000007
long long gcd(long long a , long long b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
long long lcm(long long a,long long b)
{
  return a*b/gcd(a,b);
}
 
int main(){
  boost();
  string s;
  cin>>s;
  int l = s.length(),i,j,ans=100000,temp;
  rep(i,0,l){
    temp = 0;
    rep(j,i,l)
    {
        if(s[j]!=s[l-1-j+i])
            temp++;
    }
    ans=min(ans,i+temp/2);
  }
  cout<<ans<<"\n";
  return 0;
}

3).
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <fstream>
using namespace std;
#define PII pair<int,int>
#define PIVLLD pair<int, vector<int64_t>
#define PIVI pair<int, vector<int> >
#define PIS pair<int, string>
#define VI vector<int>
#define VLLD vector<int64_t>
#define VS vector<string>
#define OUT(it,x) for(auto (it)=(x).begin();(it)!=(x).end();(it)++) cout<<*(it)<<" "; cout<<"\n"
#define POUT(it,Begin,End) for(auto (it)=(Begin);(it)!=(END);(it)++) cout<<*(it)<<" "; cout<<"\n"
#define FOR(i,b,e) for(int (i)=(b); (i)<=(e); (i)++)
#define RFOR(i,b,e) for(int (i)=(b); (i)>=(e); (i)--)
#define ALL(x) (x).begin(),(x).end()
 
#define lld int64_t
#define INF 0xfffffff
 
int solve(string &s, int c)
{
    int l=s.length();
    int ans1=0;
    for(int i=1;i<=c;i++)
    {
        if(c+i>=l)
        ans1++;
        else if(s[c+i]!=s[c-i])
        ans1++;
    }
    if(c>=((s.length()+1)/2))
    {
        int ans2=0;
        for(int i=0;i<c;i++)
        {
            if(c+i>=l)
            ans2++;
            else if(s[c+i]!=s[c-i-1])
            ans2++;
        }
    ans1= min(ans1,ans2);
    }
    return ans1;
}
int main()
{
    string s;
    cin>>s;
    int min=s.length()-1;
    int l=min-1;
    for(int c=s.length()-1;c>=(s.length())/2;c--)
    {
        int ans=solve(s,c);
        if(ans<min)
        {
            min=ans;
        }
    }
    cout<<min;
}

4).
#include <bits/stdc++.h>
using namespace std;
 
#define llong long long 
#define len(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for(int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; ++ i <= n; )
 
string s;
 
int changecnt(int l, int r = len(s) - 1) {
    int ans = 0;
    for (; l < r; ++l, --r) ans += s[l] != s[r];
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    int ans = len(s);
    rep(i, len(s)) {
        ans = min(ans, i + changecnt(i));
    }
    cout << ans;
    
    return 0;
}

5).
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
        ordered_set;
 
#define ll long long int
#define ull unsigned long long
#define pb push_back
#define mp make_pair
 
#define fi first
#define se second
#define be begin()
#define en end()
 
#define REP(i, a, b, k) for(int i = a;i < b;i += k)
#define REPI(i, a, b, k) for(int i = a;i > b;i -= k)
#define REPITER(it, a) for(__typeof(a.begin()) it = a.begin();it != a.end(); ++it)
#define eps 1e-6
 
#define ini(n) scanf("%d",&n)
#define inl(n) scanf("%lld",&n)
#define bl() printf("%s\n","")
#define printi(n) printf("%d",n)
#define printl(n) printf("%lld",n)
 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef string str;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
 
 
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll MAX = 5e4 + 10;
const int ALPHABET_SIZE=26;
const int LN=19;
const double pi=3.14159265358979323846264338328;
 
template<class T>   //fast I/O operations
inline void in(T &p) {
    p=0; register char ch=0;
    while(ch<'0' or ch>'9') {ch=getchar();}
    while(ch>='0' and ch<='9') {p=(p<<1)+(p<<3)+ch-'0'; ch=getchar();}
}
 
string s;
ll len;
ll solve(ll x){
    ll ret=x,i,j;
    i=x,j=len-1;
    while(i<j){
        if(s[i]!=s[j])
            ret++;
        i++,j--;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,q,i,j,x,y,ans;
    t=1;
    while(t--){
        cin>>s;
        len=s.size();
        ans=len/2;
        REP(i,0,len/2,1){
            ans=min(ans,solve(i));
            if(ans==0) break;
        }
        printl(ans);bl();
    }
 
    return 0;
}

6).
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define sqr(a) ((a)*(a))
#define RAND(a,b) ((a)+rand()%((b)-(a)+1))
#define rsz resize
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef pair<int,int> ii;
 
string s;
 
int solve(int l)
{
	int r=s.size()-1;
	int ret=0;
	while(l<r)
	{
		if(s[l]!=s[r]) ret++;
		l++;
		r--;
	}
	return ret;
}
 
int main()
{
	//freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);
	ios::sync_with_stdio(false);
	int ans=1e9;
	cin >> s;
	forn(i,s.size()) ans=min(ans,i+solve(i));
	cout << ans << "\n";
	return 0;
}

C++14:
1).
#include<bits/stdc++.h>
#include<iostream>
#define pb push_back
#define ll long long
#define mod 1000000007
using namespace std;
 
int main() {
	string ss;
	cin>>ss;
	ll int n = ss.size();
	ll int ans = n;
	for(int i=n; i<=2*n; i++) {
		ll int steps = 0;
		for(int j=i-n; j<i/2; j++){
			if(ss[j] != ss[i-j-1])
				steps++;
		}
		ans = min(ans, steps+i-n);
	}
	cout<<ans<<endl;
	return 0;
}

2).
#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int n;
string s;
 
int compute(string a) {
    int cnt = 0;
    for( int i = 0, j = a.size() - 1; i < j; i++, j-- ) {
        if( a[i] != a[j] ) {
            cnt++;
        }
    }
    return cnt;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>s;
    n = s.size();
    int mn = INT_MAX;
    for( int i = 0; i <= n; i++ ) {
        string tmp = s;
        for( int j = 0; j < i; j++ ) {
            tmp += s[i-j-1];
        }
        // cout<<tmp<<"\n";
        mn = min(mn, compute(tmp) + i);
    }
 
    cout<<mn;
    
    return 0;
}

3).
#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    string a;
    cin>>a;
    int b = a.length();
    int d = b / 2;
    int c = 0;
    int e = b;
    int f = 0;
    int min = 10000;
    for (int j=0;j<d;j++)
    {
        c = f;
    for (int i=f;i<e/2;i++)
    {
        
        if (a[i]!=a[e-1-i])
        c = c + 1;
    }
    e = e + 1;
    f = f + 1;
    if (c<=min)
    min = c;
    }
    cout<<min;
    return 0;
}

4).
#include<bits/stdc++.h>
using namespace std;
 
const int MX = 5005;
int memo[MX][MX];
 
int solve(int i, int j, string &s) {
  if (i >= s.size() || j < 0) return 0;
  if (memo[i][j] != -1) return memo[i][j];
  if (j < i) return 0;
  int ans = 100000;
  int to_add = (s[i] != s[j]);
  
  ans = min(ans, solve(i + 1, j - 1, s) + to_add);
  //ans = min(ans, solve(i + 1, j, s) + 1);
 
  return memo[i][j] = ans;
}
 
int main () {
  string s;
  while (cin >> s) {
    memset(memo, -1, sizeof memo);
    int ans = 1000000;
    for (int i = 0; i < s.size(); i++) {
      ans = min(ans, solve(i, s.size() - 1, s) + i);
    }
    cout << ans << endl;
  }
}

5).
// Miroslaw
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cassert>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
using namespace std;
 
typedef long long LL;
typedef vector<int> VI;
 
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FOREACH(i,c) for(__typeof((c).begin())i = (c).begin();i!=(c).end(); ++i)
 
int cond = 1;
#define DB(X) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<" = "<<X<<endl;}}
#define DB2(X, Y) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<" = "<<X<<", "<<#Y<<" = "<<Y<<endl;}}
#define DB3(X, Y, W) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<" = "<<X<<", "<<#Y<<" = "<<Y<<", "<<#W<<" = "<<W<<endl;}}
#define DB4(X, Y, W, Z) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<" = "<<X<<", "<<#Y<<" = "<<Y<<", "<<#W<<" = "<<W<<", "<<#Z<<" = "<<Z<<endl;}}
#define DBP(X) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<" = ("<<X.first<<", "<<X.second<<")" << endl;}}
#define DBV(X) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<": ";FOREACH(__i,X)cerr<<*__i<<" ";cerr<<endl;}}
 
 
char tmp[5123];
 
int main() {
  scanf("%s", tmp);
  string s = tmp;
  int best = s.size() - 1;
  for (int i = 0; i < s.size(); ++i) {
    int r = i;
    for (int j = i; j < s.size(); ++j) {
      if (j < s.size() - 1 - j + i) {
        r += s[j] != s[s.size() - 1 - j + i];
      } else {
        break;
      }
    }
    best = min(best, r);
  }
  printf("%d\n", best);
  return 0;
}

6).
#include <stdio.h>
#include <stack>
#include <map>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
#include <set>
#include <queue>
#include <functional>
#include <climits>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ld long double
const double sn = 1e-6;
int dp[5005][5005];
char arr[5005];
int sz;
int solve(int l, int r) {
	if (l >= r)
		return 0;
	if (dp[l][r] != -1)
		return dp[l][r];
	int v1 = sz, v2 = sz;
	if (r == sz - 1)
		v1 = 1 + solve(l + 1, r);
	if (arr[l] == arr[r])
		v2 = solve(l + 1, r - 1);
	else
		v2 = 1 + solve(l + 1, r - 1);
	return dp[l][r] = min(v1, v2);
}
int main()
{
	scanf("%s", arr);
	sz = strlen(arr);
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
			dp[i][j] = -1;
	printf("%d\n", solve(0,sz-1));
	return 0;
}


C#:
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace SPOJ
{
    class Program
    {
        static void Main(string[] args)
        {
                string s = Console.ReadLine();
                int min = s.Length + 1;
                for (int i = 0; i < s.Length; i++)
                {
                    int toPa = i + IsPal(s.Substring(i, s.Length - i));
                    if (min > toPa)
                    {
                        min = toPa;
                    }
                }
                Console.WriteLine(min);
        }
        static int IsPal(string s)
        {
            int count = 0;
            for (int i = 0; i < s.Length/2; i++)
            {
                if (s[i]!=s[s.Length-i-1])
                {
                    count++;
                }
            }
            return count;
        }
    }
}

Java:
1).
import java.util.*;
import java.io.*;
import java.math.*;
public class code7 {
	InputStream is;
	PrintWriter out;
	static long mod=pow(10,9)+7;
	void solve()
	{
		String s=ns();
		int min=Integer.MAX_VALUE;
		for(int i=0;i<s.length();i++)
		{
			int count=i;
			for(int j=0+i,k=s.length()-1;j<k;j++,k--)
			{
				if(s.charAt(j)!=s.charAt(k))
					count++;
			}
			min=Math.min(min,count);
		}
		out.println(min);
	}
	public static int count(int x)
	{
		int num=0;
		while(x!=0)
		{
			x=x&(x-1);
			num++;
		}
		return num;
	}
	static long d, x, y;
	void extendedEuclid(long A, long B) {
	    if(B == 0) {
	        d = A;
	        x = 1;
	        y = 0;
	    }
	    else {
	        extendedEuclid(B, A%B);
	        long temp = x;
	        x = y;
	        y = temp - (A/B)*y;
	    }
	}
	long modInverse(long A,long M) //A and M are coprime
	{
	    extendedEuclid(A,M);
	    return (x%M+M)%M;    //x may be negative
	}
	public static void mergeSort(int[] arr, int l ,int r){
		if((r-l)>=1){
			int mid = (l+r)/2;
			mergeSort(arr,l,mid);
			mergeSort(arr,mid+1,r);
			merge(arr,l,r,mid);
		}
	}
	public static void merge(int arr[], int l, int r, int mid){
		int n1 = (mid-l+1), n2 = (r-mid);
		int left[] = new int[n1];
		int right[] = new int[n2];
		for(int i =0 ;i<n1;i++) left[i] = arr[l+i];
		for(int i =0 ;i<n2;i++) right[i] = arr[mid+1+i];
		int i =0, j =0, k = l;
		while(i<n1 && j<n2){
			if(left[i]>right[j]){
				arr[k++] = right[j++];
			}
			else{
				arr[k++] = left[i++];
			}
		}
		while(i<n1) arr[k++] = left[i++];
		while(j<n2) arr[k++] = right[j++];
	}
	public static void mergeSort(long[] arr, int l ,int r){
		if((r-l)>=1){
			int mid = (l+r)/2;
			mergeSort(arr,l,mid);
			mergeSort(arr,mid+1,r);
			merge(arr,l,r,mid);
		}
	}
	public static void merge(long arr[], int l, int r, int mid){
		int n1 = (mid-l+1), n2 = (r-mid);
		long left[] = new long[n1];
		long right[] = new long[n2];
		for(int i =0 ;i<n1;i++) left[i] = arr[l+i];
		for(int i =0 ;i<n2;i++) right[i] = arr[mid+1+i];
		int i =0, j =0, k = l;
		while(i<n1 && j<n2){
			if(left[i]>right[j]){
				arr[k++] = right[j++];
			}
			else{
				arr[k++] = left[i++];
			}
		}
		while(i<n1) arr[k++] = left[i++];
		while(j<n2) arr[k++] = right[j++];
	}
	 static class Pair implements Comparable<Pair>{
		 
	       int x,y,k,i;
	        
		Pair (int x,int y){
			this.x=x;
			this.y=y;
		}
	        
		public int compareTo(Pair o) {
					return this.x-o.x;
		}
	 
	        public boolean equals(Object o) {
	            if (o instanceof Pair) {
	                Pair p = (Pair)o;
	                return p.x == x && p.y == y && p.k==k;
	            }
	            return false;
	        }
	           
	 
	        @Override
	        public String toString() {
	            return  "("+x + " " + y +" "+k+" "+i+" )";
	        }
	    
	    } 
	    
	    public static boolean isPal(String s){
	        for(int i=0, j=s.length()-1;i<=j;i++,j--){
	                if(s.charAt(i)!=s.charAt(j)) return false;
	        }
	        return true;
	    }
	    public static String rev(String s){
			StringBuilder sb=new StringBuilder(s);
			sb.reverse();
			return sb.toString();
	    }
	    
	    public static long gcd(long x,long y){
		if(x%y==0)
			return y;
		else
			return gcd(y,x%y);
	    }
	    
	    public static int gcd(int x,int y){
	    	if(y==0) 
	    		return x; 
	    	return gcd(y,x%y);
	    }
	    
	    public static long gcdExtended(long a,long b,long[] x){
	        
	        if(a==0){
	            x[0]=0;
	            x[1]=1;
	            return b;
	        }
	        long[] y=new long[2];
	        long gcd=gcdExtended(b%a, a, y);
	        
	        x[0]=y[1]-(b/a)*y[0];
	        x[1]=y[0];
	        
	        return gcd;
	    }
	    
	    public static int abs(int a,int b){
		return (int)Math.abs(a-b);
	    }
	 
	    public static long abs(long a,long b){
		return (long)Math.abs(a-b);
	    }
	    
	    public static int max(int a,int b){
		if(a>b)
			return a;
		else
			return b;
	    }
	 
	    public static int min(int a,int b){
		if(a>b)
			return b;
		else 
			return a;
	    }
	    
	    public static long max(long a,long b){
		if(a>b)
			return a;
		else
			return b;
	    }
	 
	    public static long min(long a,long b){
		if(a>b)
			return b;
		else 
			return a;
	    }
	 
	    public static long pow(long n,long p,long m){
		 long  result = 1;
		  if(p==0)
		    return 1;
		if (p==1)
		    return n;
		while(p!=0)
		{
		    if(p%2==1)
		        result *= n;
		    if(result>=m)
		    result%=m;
		    p >>=1;
		    n*=n;
		    if(n>=m)
		    n%=m;
		}
		return result;
	    }
	    
	    public static long pow(long n,long p){
		long  result = 1;
		  if(p==0)
		    return 1;
		if (p==1)
		    return n;
		while(p!=0)
		{
		    if(p%2==1)
		        result *= n;	    
		    p >>=1;
		    n*=n;	    
		}
		return result;
	    }
	    public static void debug(Object... o) {
			System.out.println(Arrays.deepToString(o));
		}
	    void run() throws Exception {
			is = System.in;
			out = new PrintWriter(System.out);
			solve();
			out.flush();
		}
	   
	    public static void main(String[] args) throws Exception {
			new Thread(null, new Runnable() {
				public void run() {
					try {
						new code7().run();
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			}, "1", 1 << 26).start();
 
		}
	    private byte[] inbuf = new byte[1024];
		public int lenbuf = 0, ptrbuf = 0;
	 
		private int readByte() {
			if (lenbuf == -1)
				throw new InputMismatchException();
			if (ptrbuf >= lenbuf) {
				ptrbuf = 0;
				try {
					lenbuf = is.read(inbuf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return -1;
			}
			return inbuf[ptrbuf++];
		}
	 
		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}
	 
		private int skip() {
			int b;
			while ((b = readByte()) != -1 && isSpaceChar(b));
			return b;
		}
	 
		private double nd() {
			return Double.parseDouble(ns());
		}
	 
		private char nc() {
			return (char) skip();
		}
	 
		private String ns() {
			int b = skip();
			StringBuilder sb = new StringBuilder();
			while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
	 
		private char[] ns(int n) {
			char[] buf = new char[n];
			int b = skip(), p = 0;
			while (p < n && !(isSpaceChar(b))) {
				buf[p++] = (char) b;
				b = readByte();
			}
			return n == p ? buf : Arrays.copyOf(buf, p);
		}
	 
		private char[][] nm(int n, int m) {
			char[][] map = new char[n][];
			for (int i = 0; i < n; i++)
				map[i] = ns(m);
			return map;
		}
	 
		private int[] na(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = ni();
			return a;
		}
	 
		private int ni() {
			int num = 0, b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-') {
				minus = true;
				b = readByte();
			}
	 
			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = readByte();
			}
		}
	 
		private long nl() {
			long num = 0;
			int b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-') {
				minus = true;
				b = readByte();
			}
	 
			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = readByte();
			}
		}
	 
}

2).
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
 
// Built using CHelper plug-in
// Actual solution is at the top
//
// @author Sanket Makani
//

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DremplayAndUpsideDown solver = new DremplayAndUpsideDown();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class DremplayAndUpsideDown {
        public void solve(int testNumber, InputReader sc, PrintWriter w) {
 
            char c[] = sc.next().toCharArray();
 
            int n = c.length;
 
            int ans = Integer.MAX_VALUE;
 
            for (int i = 0; i < n; i++) {
                ans = Math.min(ans, getAnswer(c, i, n - 1) + i);
            }
            w.println(ans);
        }
 
        private int getAnswer(char[] c, int l, int r) {
 
            int mid = (r - l) >> 1;
 
            int ans = 0;
 
            for (int i = 0; i <= mid; i++) {
                if (c[l + i] != c[r - i])
                    ans++;
            }
            return ans;
        }
 
    }
 
    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;
 
        public InputReader(InputStream stream) {
            this.stream = stream;
        }
 
        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();
 
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
 
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }
 
        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            }
            while (!isSpaceChar(c));
 
            return res.toString();
        }
 
        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public String next() {
            return readString();
        }
 
        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
 
        }
 
    }
}


3).
import java.util.*;
import java.io.*;
class Main {
    	static class FastReader
    {
       BufferedReader br;
       StringTokenizer st;
 
       public FastReader()
       {
           br = new BufferedReader(new
                    InputStreamReader(System.in));
       }
 
       String next()
       {
           while (st == null || !st.hasMoreElements())
           {
               try
               {
                   st = new StringTokenizer(br.readLine());
               }
               catch (IOException  e)
               {
                   e.printStackTrace();
               }
           }
           return st.nextToken();
       }
 
       int nextInt()
       {
           return Integer.parseInt(next());
       }
 
       long nextLong()
       {
           return Long.parseLong(next());
       }
 
       double nextDouble()
       {
           return Double.parseDouble(next());
       }
 
       String nextLine()
       {
           String str = "";
           try
           {
               str = br.readLine();
           }
           catch (IOException e)
           {
               e.printStackTrace();
           }
           return str;
       }
   }
 
    public static void main(String args[] ) throws Exception {
        FastReader sc=new FastReader();
        String str=sc.next();
        int len=str.length();
        char c[]=new char[len+len-1];
        c[0]=str.charAt(0);
        for(int i=1,j=1;i<2*len-2;i+=2,j++){
            c[i]='#';
            c[i+1]=str.charAt(j);
        }
        int n=c.length;
        int i=n/2;
        int ans=Integer.MAX_VALUE;
        for(int j=i;j<n;j++){
            int a=j-1,b=j+1;
            int ch=0;
            while(b<n){
                if(c[a]!=c[b])
                    ch++;
                a--;b++;
            }
            ch+=len-(n-j);
            ans=Math.min(ans,ch);
        }
        System.out.println(ans);
    }
}

Java 8:
#pragma warning disable IDE0018
#define TESTCASES
//Tools and default solution template belongs to https://www.hackerearth.com/@christophe_savard
//Solution to the problem belongs to me
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
 
namespace CpForCompetitiveProgrammingHRDremplayAndUpsideDown
{
    public static class HRDremplayAndUpsideDown
    {
        #region Main
 
        private const long Mod = 1000000007L;
        private const long MaxArrySize = 100000000L;
        private static ConsoleHelper Console { get; set; }
 
        static HRDremplayAndUpsideDown()
        {
            Console = new ConsoleHelper();
        }
 
        //public static void Main_Solver(string[] args)
        public static void Main(string[] args)
        {
#if DEBUG
            Stopwatch timer = Stopwatch.StartNew();
#endif
            using (Console)
            {
#if TESTCASES
                TestCases();
#else // !TESTCASES
                Solve();
#endif
            }
#if DEBUG
            timer.Stop();
            System.Console.SetOut(File.AppendText(@"../../output.txt"));
            System.Console.Write($"\r\n\r\nTotal run time: {timer.Elapsed.TotalSeconds:0.000}s at {DateTime.Now}");
            System.Console.Out.Dispose();
#endif
        }
 
 
 
        #endregion
 
        #region Solution
 
#if TESTCASES
 
        private static void TestCases()
        {
            var s = Console.NextLine();
            var output = Solve(s);
 
            Console.WriteLine(output);
        }
 
#endif
        public static long Solve(string s)
        {
            var reverse = new string(s.Reverse().ToArray());
            if (s == reverse)
            {
                return 0;
            }
 
            var len = s.Length;
            var last = len - 1;
 
            var replaceCount = PalindromByReplace(s);
            var minOp = replaceCount;
 
            for (int i = 0; i <= last; i++)
            {
                var subString = s.Substring(i, len - i);
                var c = PalindromByReplace(subString);
                c += i;
 
                if (c < minOp)
                {
                    minOp = c;
                }
            }
 
            return minOp;
        }
 
        private static long PalindromByReplace(string s)
        {
 
            var reverse = new string(s.Reverse().ToArray());
            if (s == reverse)
            {
                return 0;
            }
 
 
            var len = s.Length;
            var last = len - 1;
 
            long replaceCount = 0;
 
            for (int i = 0; len - 3 >= 0 && i <= (len - 3) / 2; i++)
            {
                var chl = s[i];
                var chr = s[last - i];
 
                if (chl != chr)
                {
                    ++replaceCount;
                }
            }
 
            if (len % 2 == 0)
            {
                var chl = s[len / 2];
                var chr = s[last / 2];
 
                if (chl != chr)
                {
                    ++replaceCount;
                }
            }
 
            return replaceCount;
        }
 
        #endregion
    }
 
 
    //Tools belongs to https://www.hackerearth.com/@christophe_savard
    #region Tools
    [DebuggerStepThrough]
    public sealed class ConsoleHelper : IDisposable
    {
        #region Constants
        private const int BaseSize = 1048576;
        private static readonly char[] NumBuffer = new char[20];
        #endregion
 
        #region Fields
        private readonly BufferedStream _inStream;
        private readonly StreamWriter _outStream;
 
        private readonly byte[] _inBuffer;
        private int _inputIndex;
        private int _bufferEnd;
        #endregion
 
        #region Properties
        public int BufferSize { get; set; }
 
        public bool Open { get; private set; }
        #endregion
 
        #region Constructors
 
        public ConsoleHelper() : this(BaseSize) { }
 
 
        public ConsoleHelper(int bufferSize)
        {
            // Open the input/output streams
#if DEBUG
            // Test mode
            this._inStream = new BufferedStream(File.OpenRead(@"../../input.txt"), bufferSize);
            this._outStream = new StreamWriter(File.Create(@"../../output.txt", bufferSize), Encoding.ASCII, bufferSize);
#else // !DEBUG
            // Submission mode
            this._inStream = new BufferedStream(Console.OpenStandardInput(bufferSize), bufferSize); // Submission stream
            this._outStream = new StreamWriter(Console.OpenStandardOutput(bufferSize), Encoding.ASCII, bufferSize);
#endif
 
            // Set fields
            this._inBuffer = new byte[bufferSize];
            this._inputIndex = this._bufferEnd = 0;
            this.BufferSize = bufferSize;
            this.Open = true;
        }
        #endregion
 
        #region Static methods
 
        public static bool ValidateChar(int i)
        {
            return i >= ' ';
        }
 
 
        public static bool ValidateCharNoSpace(int i)
        {
            return i > ' ';
        }
 
 
        public static bool ValidateNumber(int i)
        {
            return i >= '0' && i <= '9';
        }
 
 
        public static bool IsEndline(int i)
        {
            return i == '\n' || i == '\0';
        }
 
 
        private static int GetIntBuffer(int n)
        {
            int head = 20;
            bool neg;
            if (n < 0)
            {
                neg = true;
                n = -n;
            }
            else { neg = false; }
 
            do
            {
                NumBuffer[--head] = (char)((n % 10) + 48);
                n /= 10;
            }
            while (n > 0);
 
            if (neg) { NumBuffer[--head] = '-'; }
            return head;
        }
 
 
        private static int GetLongBuffer(long n)
        {
            int head = 20;
            bool neg;
            if (n < 0L)
            {
                neg = true;
                n = -n;
            }
            else { neg = false; }
 
            do
            {
                NumBuffer[--head] = (char)((n % 10L) + 48L);
                n /= 10L;
            }
            while (n > 0L);
 
            if (neg) { NumBuffer[--head] = '-'; }
            return head;
        }
        #endregion
 
        #region Methods
 
        public byte Read()
        {
            CheckBuffer();
            return this._inBuffer[this._inputIndex++];
        }
 
 
        public byte Peek()
        {
            CheckBuffer();
            return this._inBuffer[this._inputIndex];
        }
 
 
        public void Skip(int n = 1)
        {
            this._inputIndex += n;
        }
 
 
        private void CheckBuffer()
        {
            // If we reach the end of the buffer, load more data
            if (this._inputIndex >= this._bufferEnd)
            {
                this._inputIndex = this._inputIndex - this._bufferEnd;
                this._bufferEnd = this._inStream.Read(this._inBuffer, 0, this.BufferSize);
 
                // If nothing was added, add a null char at the start
                if (this._bufferEnd < 1) { this._inBuffer[this._bufferEnd++] = 0; }
            }
        }
 
 
        public char NextChar()
        {
            return (char)Read();
        }
 
 
        public string Next()
        {
            byte b = SkipInvalid();
            ValidateEndline(b);
 
            // Append all characters
            StringBuilder sb = new StringBuilder().Append((char)b);
            b = Peek();
            while (ValidateCharNoSpace(b))
            {
                // Peek to not consume terminator
                sb.Append((char)b);
                Skip();
                b = Peek();
            }
 
            return sb.ToString();
        }
 
 
        public int NextInt(bool moveToNextLine = false)
        {
            // Skip invalids
            byte b = SkipInvalid();
            ValidateEndline(b);
 
            // Verify for negative
            bool neg = false;
            if (b == '-')
            {
                neg = true;
                b = Read();
            }
 
            // Get first digit
            if (!ValidateNumber(b)) { throw new FormatException("Integer parsing has failed because the string contained invalid characters"); }
 
            int n = b - '0';
            b = Peek();
            while (ValidateNumber(b))
            {
                // Peek to not consume terminator, and check for overflow
                n = checked((n << 3) + (n << 1) + (b - '0'));
                Skip();
                b = Peek();
            }
            // If the character causing the exit is a valid ASCII character, the integer isn't correct formatted
            if (ValidateCharNoSpace(b)) { throw new FormatException("Integer parsing has failed because the string contained invalid characters"); }
 
            if (moveToNextLine)
            {
                SkipToNextLine();
            }
 
            return neg ? -n : n;
        }
 
 
        public long NextLong(bool moveToNextLine = false)
        {
            byte b = SkipInvalid();
            ValidateEndline(b);
 
            // Verify negative
            bool neg = false;
            if (b == '-')
            {
                neg = true;
                b = Read();
            }
 
            // Get first digit
            if (!ValidateNumber(b)) { throw new FormatException("Integer parsing has failed because the string contained invalid characters"); }
 
            long n = b - '0';
            b = Peek();
            while (ValidateNumber(b))
            {
                // Peek to not consume terminator, and check for overflow
                n = checked((n << 3) + (n << 1) + (b - '0'));
                Skip();
                b = Peek();
            }
            // If the character causing the exit is a valid ASCII character, the long isn't correct formatted
            if (ValidateCharNoSpace(b)) { throw new FormatException("Long parsing has failed because the string contained invalid characters"); }
 
            if (moveToNextLine)
            {
                SkipToNextLine();
            }
 
            return neg ? -n : n;
        }
 
 
        public double NextDouble()
        {
            return double.Parse(Next());
        }
 
 
        public int[] NextInts(int n)
        {
            int[] array = new int[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = NextInt();
            }
 
            SkipToNextLine();
            return array;
        }
 
 
        public long[] NextLongs(int n)
        {
            long[] array = new long[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = NextLong();
            }
 
            SkipToNextLine();
            return array;
        }
 
 
        public int[,] NextMatrix(int n, int m)
        {
            int[,] matrix = new int[n, m];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[i, j] = NextInt();
                }
 
                SkipToNextLine();
            }
 
            return matrix;
        }
 
 
        public string NextLine()
        {
            byte b = SkipInvalid();
            if (b == 0)
            {
                // Consume newline and return empty string
                Skip();
                return string.Empty;
            }
 
            // Read all the characters until the next linefeed
            StringBuilder sb = new StringBuilder().Append((char)b);
            b = Read();
            while (!IsEndline(b))
            {
                // Don't append special characters, but don't exit
                if (ValidateChar(b))
                {
                    sb.Append((char)b);
                }
                b = Read();
            }
 
            return sb.ToString();
        }
 
 
        public void SkipNext()
        {
            byte b = SkipInvalid();
            ValidateEndline(b);
 
            for (b = Peek(); ValidateCharNoSpace(b); b = Peek())
            {
                Skip();
            }
        }
 
 
        public void SkipToNextLine()
        {
            for (byte b = Read(); !IsEndline(b); b = Read()) { }
        }
 
 
        public IEnumerable<int> EnumerateInts(int n)
        {
            while (n-- > 0)
            {
                yield return NextInt();
            }
 
            SkipToNextLine();
        }
 
 
        public IEnumerable<char> EnumerateLine()
        {
            for (char c = NextChar(); !IsEndline(c); c = NextChar())
            {
                if (ValidateChar(c))
                {
                    yield return c;
                }
            }
        }
 
 
        private void ValidateEndline(byte b)
        {
            // If empty char
            if (b == 0)
            {
                // Go back a char and throw
                this._inputIndex--;
                throw new InvalidOperationException("No values left on line");
            }
        }
 
 
        private byte SkipInvalid()
        {
            byte b = Peek();
            if (IsEndline(b)) { return 0; }
 
            while (!ValidateCharNoSpace(b))
            {
                Skip();
                b = Peek();
                // Return empty char if we meet an linefeed or empty char
                if (IsEndline(b)) { return 0; }
            }
 
            return Read();
        }
 
 
        public void Write(char c)
        {
            this._outStream.Write(c);
        }
 
 
        public void Write(char[] buffer)
        {
            this._outStream.Write(buffer);
        }
 
 
        public void Write(string s)
        {
            this._outStream.Write(s);
        }
 
 
        public void Write(int n)
        {
            int head = GetIntBuffer(n);
            this._outStream.Write(NumBuffer, head, 20 - head);
        }
 
 
        public void Write(long n)
        {
            int head = GetLongBuffer(n);
            this._outStream.Write(NumBuffer, head, 20 - head);
        }
 
 
        public void Write(StringBuilder sb)
        {
            this._outStream.Write(sb.ToCharArray());
        }
 
 
        public void Write(object o)
        {
            this._outStream.Write(o);
        }
 
 
        public void Write<T>(IEnumerable<T> e, string separator = "")
        {
            this._outStream.Write(new StringBuilder().AppendJoin(e, separator).ToCharArray());
        }
 
 
        public void Write<T>(IEnumerable<T> e, char separator)
        {
            this._outStream.Write(new StringBuilder().AppendJoin(e, separator).ToCharArray());
        }
 
 
        public void WriteLine()
        {
            this._outStream.WriteLine();
        }
 
 
        public void WriteLine(char c)
        {
            this._outStream.WriteLine(c);
        }
 
 
        public void WriteLine(char[] buffer)
        {
            this._outStream.WriteLine(buffer);
        }
 
 
        public void WriteLine(string s)
        {
            this._outStream.WriteLine(s);
        }
 
        public void WriteLine(int n)
        {
            int head = GetIntBuffer(n);
            this._outStream.WriteLine(NumBuffer, head, 20 - head);
        }
 
 
        public void WriteLine(long n)
        {
            int head = GetLongBuffer(n);
            this._outStream.WriteLine(NumBuffer, head, 20 - head);
        }
 
 
        public void WriteLine(StringBuilder sb)
        {
            this._outStream.WriteLine(sb.ToCharArray());
        }
 
 
        public void WriteLine<T>(IEnumerable<T> e, string separator = "")
        {
            this._outStream.WriteLine(new StringBuilder().AppendJoin(e, separator).ToCharArray());
        }
 
 
        public void WriteLine<T>(IEnumerable<T> e, char separator)
        {
            this._outStream.WriteLine(new StringBuilder().AppendJoin(e, separator).ToCharArray());
        }
 
 
        public void WriteLine(object o)
        {
            this._outStream.WriteLine(o);
        }
 
 
        public void Flush()
        {
            this._outStream.Flush();
        }
 
 
        public void Dispose()
        {
            if (this.Open)
            {
                Flush();
                this._inStream.Dispose();
                this._outStream.Dispose();
                this.Open = false;
            }
        }
        #endregion
    }
 
    public static class Extensions
    {
        #region Enumerable extensions
 
        public static bool EqualTo<T>(this IEnumerable<T> e, int count)
        {
            if (count < 0) { return false; }
 
            int total = 0;
            return !e.Any(t => ++total > count) && total == count;
        }
 
        public static void ForEach<T>(this IEnumerable<T> e, Action<T> action)
        {
            foreach (T t in e)
            {
                action(t);
            }
        }
 
        public static bool IsEmpty(this ICollection c)
        {
            return c.Count == 0;
        }
 
        public static bool GreaterThan<T>(this IEnumerable<T> e, int count)
        {
            if (count < 0) { return true; }
 
            int total = 0;
            return e.Any(t => ++total > count);
        }
 
        public static string Join<T>(this IEnumerable<T> e, string separator = "")
        {
            return new StringBuilder().AppendJoin(e, separator).ToString();
        }
 
        public static string Join<T>(this IEnumerable<T> e, char separator)
        {
            return new StringBuilder().AppendJoin(e, separator).ToString();
        }
 
        public static bool LessThan<T>(this IEnumerable<T> e, int count)
        {
            if (count <= 0) { return false; }
 
            int total = 0;
            return !e.Any(t => ++total >= count);
        }
 
        public static T MaxValue<T, TU>(this IEnumerable<T> e, Func<T, TU> selector) where TU : IComparable<TU>
        {
            using (IEnumerator<T> enumerator = e.GetEnumerator())
            {
                if (!enumerator.MoveNext()) { throw new InvalidOperationException("No elements in sequence"); }
 
                T max = enumerator.Current;
                TU value = selector(max);
                while (enumerator.MoveNext())
                {
                    TU v = selector(enumerator.Current);
                    if (value.CompareTo(v) < 0)
                    {
                        max = enumerator.Current;
                        value = v;
                    }
                }
 
                return max;
            }
        }
 
        public static T MinValue<T, TU>(this IEnumerable<T> e, Func<T, TU> selector) where TU : IComparable<TU>
        {
            using (IEnumerator<T> enumerator = e.GetEnumerator())
            {
                if (!enumerator.MoveNext()) { throw new InvalidOperationException("No elements in sequence"); }
 
                T min = enumerator.Current;
                TU value = selector(min);
                while (enumerator.MoveNext())
                {
                    TU v = selector(enumerator.Current);
                    if (value.CompareTo(v) > 0)
                    {
                        min = enumerator.Current;
                        value = v;
                    }
                }
 
                return min;
            }
        }
 
        public static List<List<T>> DeepClone<T>(this IEnumerable<IEnumerable<T>> e)
        {
            var newList = new List<List<T>>();
 
            foreach (var item in e)
            {
                List<T> newItem = new List<T>();
 
                foreach (var inner in item)
                {
                    newItem.Add(inner);
                }
 
                newList.Add(newItem);
            }
 
            return newList;
        }
 
        public static int StringDiff(this string s, string other)
        {
            int diff = 0;
 
            for (int i = 0; i < s.Length; i++)
            {
                if (i == other.Length)
                {
                    break;
                }
 
                if (s[i] != other[i])
                {
                    ++diff;
                }
            }
 
            return diff;
        }
 
        public static bool ForAllPermutation<T>(this IEnumerable<T> collection, Func<T[], bool> funcExecuteAndTellIfShouldStop)
        {
            var items = collection.ToArray();
            int countOfItem = items.Length;
 
            if (countOfItem <= 1)
            {
                return funcExecuteAndTellIfShouldStop(items);
            }
 
            var indexes = new int[countOfItem];
            for (int i = 0; i < countOfItem; i++)
            {
                indexes[i] = 0;
            }
 
            if (funcExecuteAndTellIfShouldStop(items))
            {
                return true;
            }
 
            for (int i = 1; i < countOfItem;)
            {
                if (indexes[i] < i)
                {
                    if ((i & 1) == 1)
                    {
                        Swap(ref items[i], ref items[indexes[i]]);
                    }
                    else
                    {
                        Swap(ref items[i], ref items[0]);
                    }
 
                    if (funcExecuteAndTellIfShouldStop(items))
                    {
                        return true;
                    }
 
                    indexes[i]++;
                    i = 1;
                }
                else
                {
                    indexes[i++] = 0;
                }
            }
 
            return false;
        }
 
        static void Swap<T>(ref T a, ref T b)
        {
            T temp = a;
            a = b;
            b = temp;
        }
 
        #endregion
 
        #region String extensions
 
        public static StringBuilder AppendJoin<T>(this StringBuilder sb, IEnumerable<T> source, string separator = "")
        {
            using (IEnumerator<T> e = source.GetEnumerator())
            {
                if (e.MoveNext())
                {
                    sb.Append(e.Current);
                    while (e.MoveNext())
                    {
                        sb.Append(separator).Append(e.Current);
                    }
                }
            }
 
            return sb;
        }
 
 
        public static StringBuilder AppendJoin<T>(this StringBuilder sb, IEnumerable<T> source, char separator)
        {
            using (IEnumerator<T> e = source.GetEnumerator())
            {
                if (e.MoveNext())
                {
                    sb.Append(e.Current);
                    while (e.MoveNext())
                    {
                        sb.Append(separator).Append(e.Current);
                    }
                }
            }
 
            return sb;
        }
 
 
        public static bool IsEmpty(this string s)
        {
            return String.IsNullOrEmpty(s);
        }
 
 
        public static string SubStr(this string s, int start, int end)
        {
            return s.Substring(start, (end - start) + 1);
        }
 
 
        public static char[] ToCharArray(this StringBuilder sb)
        {
            char[] buffer = new char[sb.Length];
            sb.CopyTo(0, buffer, 0, sb.Length);
            return buffer;
        }
        #endregion
 
        #region Number extensions
 
        public static bool IsPair(this int n)
        {
            return (n & 1) == 0;
        }
 
 
        public static bool IsPair(this long n)
        {
            return (n & 1L) == 0;
        }
 
 
        public static int Mod(this int n, int m)
        {
            return ((n % m) + m) % m;
        }
 
 
        public static long Mod(this long n, long m)
        {
            return ((n % m) + m) % m;
        }
 
 
        public static int Triangle(this int n)
        {
            return (n * (n + 1)) / 2;
        }
 
 
        public static long Triangle(this long n)
        {
            return (n * (n + 1L)) / 2L;
        }
 
        /// <summary>
        /// Counts the amount of set bits (1s in the binary representation) of a given integer
        /// </summary>
        /// <param name="n">Integer to get the set bits from</param>
        /// <returns>Amount of set bits of the integer</returns>
        public static int SetBits(this int n)
        {
            n = n - ((n >> 1) & 0x55555555);
            n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
            return (((n + (n >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
        }
 
        /// <summary>
        /// Counts the amount of set bits (1s in the binary representation) of a given long
        /// </summary>
        /// <param name="n">Long to get the set bits from</param>
        /// <returns>Amount of set bits of the long</returns>
        public static long SetBits(this long n)
        {
            n = n - ((n >> 1) & 0x5555555555555555);
            n = (n & 0x3333333333333333) + ((n >> 2) & 0x3333333333333333);
            return (((n + (n >> 4)) & 0xF0F0F0F0F0F0F0F) * 0x101010101010101) >> 56;
        }
 
 
        public static int SumDigits(this int n)
        {
            int total = 0;
            while (n > 0)
            {
                total += n % 10;
                n /= 10;
            }
            return total;
        }
        #endregion
 
        private static void Swap(long[] arr, int i, int j)
        {
            var t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
 
        private static int Partition(long[] arr, int l, int h, bool asc)
        {
            var x = arr[h];
            int i = (l - 1);
 
            for (int j = l; j <= h - 1; j++)
            {
                if (arr[j] <= x)
                {
                    i++;
 
                    if (asc)
                    {
                        Swap(arr, i, j);
                    }
                    else
                    {
                        Swap(arr, j, i);
                    }
 
                }
            }
 
            if (asc)
            {
                Swap(arr, i + 1, h);
            }
            else
            {
                Swap(arr, h, i + 1);
            }
 
            return (i + 1);
        }
 
        public static void QuickSort(this long[] arr, bool asc)
        {
            int l = 0;
            int h = arr.Length - 1;
 
            // create auxiliary stack
            int[] stack = new int[h - l + 1];
 
            // initialize top of stack
            int top = -1;
 
            // push initial values in the stack
            stack[++top] = l;
            stack[++top] = h;
 
            // keep popping elements until stack is not empty
            while (top >= 0)
            {
                // pop h and l
                h = stack[top--];
                l = stack[top--];
 
                // set pivot element at it's proper position
                int p = Partition(arr, l, h, asc);
 
                // If there are elements on left side of pivot,
                // then push left side to stack
                if (p - 1 > l)
                {
                    stack[++top] = l;
                    stack[++top] = p - 1;
                }
 
                // If there are elements on right side of pivot,
                // then push right side to stack
                if (p + 1 < h)
                {
                    stack[++top] = p + 1;
                    stack[++top] = h;
                }
            }
        }
 
        public static int BinarySearch(long[] a, long key)
        {
            int low = 0, high = a.Length - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (a[mid] == key)
                {
                    high = mid;
                    break;
                }
                else if (a[mid] < key)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
 
            if (high == a.Length - 1)
                return high;
            while ((high + 1 < a.Length) && a[high + 1] == key)
                high++;
            return high;
 
        }
    }
 
    #endregion
}

Python:
1).
def main():
    st = raw_input()
    N = len(st)
    ans = 100000
    if st == st[::-1]:
        print "0"
    else:
        for ln in range(N/2+1):
            temp = 0
            l=ln
            r=N-1
            while l < r:
                if st[l] != st[r]:
                    temp += 1
                l+=1
                r-=1
            ans = min(ans,temp+ln)
        print ans
 
if __name__ == '__main__':
    main()

2).
st=raw_input()
n=len(st)
res=0
for i in xrange(n/2):
  if st[i]!=st[n-1-i]:
    res+=1
for i in xrange(1,res):
  tmp=i
  st2=st+st[:i][::-1]
  for j in xrange((n+i)/2):
    if st2[j]!=st2[n+i-1-j]:
      tmp+=1
  res=min(res,tmp)      
print res
	

Python 3:
1).
s = input().strip()
cmin = len(s)//2
x = 0
n = cmin
while n > 0:
    c = 0
    for i, j in zip(s[:len(s)//2],s[:(len(s)-1)//2:-1]):
        if i != j:
            c = c + 1
    cmin = min(cmin, c+x)
    s = s[1:]
    n = n - 1
    x = x + 1
print(cmin)

2).
def checkpal(string):
    length = len(string)
    count =0
    if True:
        l1 = list(string[0:int(length/2)])
        l2 = list(string[int(length/2):])
        l2.reverse()
        for i in range(len(l1)):
            if l1[i]!=l2[i]:
                count +=1
    return count
 
def pal(string):
    length = len(string)
    count =[]
    for i in range(int(length/2)):
            stri = string+'0'*i
            count.append(checkpal(stri))
 
    return min(count)
 
text = input()
print(pal(text))

PHP:
<?php

//Read input from stdin and provide input before running code
//fscanf(STDIN, "%s\n", $name);
//echo "Hi, ".$name;
// echo "Hello World!";

$_fp = fopen("php://stdin", "r");
 
$str = str_split(trim(fgets($_fp)));
$n = count($str);
// echo "--".$n."---";
// print_r($str);
$strToProcess = $str;
$res = getConvertedStr($strToProcess, 0, $n-1);
// echo $res."\n";
for($i = 1; $i < $n/2; $i++){
    $strToProcess = $str;
    for($j = 1; $j <= $i; $j++)
        $strToProcess[$n + $j - 1] = $str[$i - $j];
    
    $t = $i + getConvertedStr($strToProcess, 0, $n + $i - 1);
    // echo $t."\n";
    if($t < $res)
        $res = $t;
        
}
echo $res;
 
function getConvertedStr($str, $l, $r){
    // echo "l : ".$l." r : ".$r."\n";
    if($l >= $r){
        return 0;
    }else{
        if($str[$l] == $str[$r]){
            return getConvertedStr($str, ++$l, --$r);
        }else{
            // return 0;
            return 1+getConvertedStr($str, ++$l, --$r);
        }
    }
    
    // return 
}

?>


Ruby:
str = gets.chomp.split('')
tmp = str
count,ans_new=0,0
ans=[]
 
max = str.length-2
 
for i in 1..max 
  tmp_s = str[i..str.length-1]
  tmp_s_l = tmp_s.length-1
  tmp_c=0
  for j in 0..(tmp_s_l-1)/2
    if tmp_s[j] != tmp_s[tmp_s_l-j]
      tmp_c +=1 
    end
  end
  ans.push(tmp_c + i)
end
 
l = str.length-1
 
for i in 0..(l-1)/2
  if str[i] != str[l-i]
    str[i] = str[l-i]
    count+=1
  end
end
ans.push(count)
 
puts ans.min


*/

/*
Editorial:
Problem:
Given a string s, convert it into a palindrome, performing minimum operations of the form:

Add a character to the string at the end.
Replace a character.
Solution: 
As the length of string, N<=5000 , we can think about an O(N^2) solution, which is quite easy to think. It would be safe to assume an upper bound of N on our answer. 
This would happen if we add N characters to the string such that we make it a palindrome.

Now, to find the minimum number of steps, we can iterate over the length of the final palindrome that we would obtain. We can iterate the length from N to 2N.
For every length, we compute the number of steps needed to get a palindrome of that particular length, and we take the minimum of all of them as our answer.

Pseudocode:

ans = N
for len in [N,2N]:
    steps = 0
    for i in [0,len/2]:
        if s[i] != s[len-i-1]:
            steps ++
    ans = min(ans, steps)

*/

/*
I/O:
In #1:
bbaabaaaaabbbbbbbaba
Out #1:
7
In #2:
bbaabaaaaabbbbb
Out #2:
2
In #3:
bbaabaaaaa
Out #3:
3
In #4:
bbaabaaaaabbbbbbbababaabaabaabbabababbbabbabbabbbabaabbbbbbaabaaaaaaaaababaaabbabbaaaaaabaababbaaabbbbbaaabababbaaabbbbaaababbbabaaabaaabbbbbbbbbbbabaaaaabaabababababbbaabaaaababaababbaaaabbababbbabbababbabbaabaaabbabbbbbbabaaaaaaabbabbaaaaabababbaabaaabaaaabbbaaabaabbbbaabbaaabbbabbbbababaabbaababbabaabbabbabaabbbbabbbbabbbbaabaabaabababbbbbaaabbabaaabaaabbbabaababbaaabbabaaaabbababbaaaaaabbabbabbabaabaabbabbbbababbbabbbbaaaaaababaaabbbaabbaaababbaaaabaabbaaabaabaaabababbaabaabbbabbbabaaababbbbaaaaaabbbbbaaaababababaabbbaabbabababbbaaababababaaabbaaababbbbbaabababbbbbbbaabbaaaaabbabbbbbbababaabbbbbbaaabbaabbbabaababaababbbbaabbaaabababbaaabaabbbaababbabbabaaabbababbbbaabbabbbbbababbbbbaababaababaaabbabbbababbaaabbbaaaabbbbaabaababbbaaababbbababaaabbaaababbbbbabbbabbabbbbbbaaaabaaaaabbaaababbababbaabbbaabaabbbbbaabaabbaaaaaabbabaabbbaabaaaaaaabbbabbbbaaaaabbaaaabababaaabbbaaaaaabbababbabbaabaaabbbababbbbbaabbabaababaabbbbbbbaababbbbabaaaabaaaabbbbbaababaabbababbaaaabbabbbbbababaabbaaab
Out #4:
229
In #5:
ccbbcbaabcccbabcbcaaaacabbaccccacaabcbbacacaacabcbccbaabcabbbccaabbcbbcacabcaaacacabacbccbaacbcbcaacacbaaaaccacccbaacaaabacaccabcbcbabbbacbabcaaccbccacbcbacacacbcaccabaccbccbaaaaabbacbacacbccbabcaacbbcccaccbcbacbacbcabaababccaaaacccccbbaabbccbcccabbacacaacbcccbaaacacabccabcccccabcaaaabbbcbbbaabccacccabacbcbbcbabacabbbbbbabbcabcbcbcaabcbcccbabaccccabbabbbacbbacbcccaaacaccababcccbcaccbcbcaacacbccbacbccbccaccbcbcabbbccabaacaccbcccbccaccbbcbcccbbccbacbcbcbbcbabcbacbbababcbcacbaaabbabacabbcbccbaccbbcbbbbcbbaacabaccbcbccabbbbccaabcbbcaccbbcaaaabababbabbbacaaabaabaccbcaaccaabcbbaccacbabbcccaccbcabcacabbaacccacbbabbabcccababcacababacccbacacabcbcccbabccccabcbaabbaaabaccccabbababaacabbcacbacacbbcbaabaabbbbaabcaaccbacbbaacacabcabacbaabcaabbccccccacbccccaabcbabaabcbbaaacccccabaaaabcaabbccccaccbacababbaccacababbacbbaaccbbacbbccaccaccabccbababbbacbacbaabcbbcaacaababbabbaacabcaabccabacbbbbcabcccacbacbababacaccabcaacbaabccaccacbccaabbcbaababaacaaaaaacccbcbbabbbbbcbcacbababacbbabcbabbcacbcaccbcaaabacaaababacaababcaccbababcabcababbaababcbabbcabbacccbbbccacbacccbccaabcaabcbbbccbaccbabcaacacaabababacabbcbbaccacbbbcbabccaccabcacabaacbbacbaccaabcaaaaacccabbaabaabcbacccbcbabaccbcbaabaaacabbaababbbbbcabaaaaaabacbbaabbaabbcacabbcbbcaabbcbaaaaacbabcaacaaacaacbcccbcbababbcbcacbcaaccaabbbbbacabaaaabcaababbccbccbccbbababbbaacbacccaacbcbccabcccaaabaacbbcacacaaabccccbcbbaacacaaccbaacbabaacccbbbcccaacbcacbcbbbbcbccaccccabcbcaccbbaacaabaabccaacccababccbcabbbaaababbbbaabbcacbbaaccbcaacacacaaacbcacbaacaccabccaaaacbaabbccbaaaccbbbcababbaacbabacbcbaacabcbababaabcbcbabaabcacacabaacbbbabcabaacbbcbccaaccccacaabaaaccbacacccbabcbbbbbaacabbbbbbbacaccabaacbcbaacbcbcbbcccbaaabaccbbacbccbaabacbaccbbbbcccccaccbccaaaababaaccccccbbbbbbabacaabbbccbcbaaaccbcabbccabbabbabcbcbccbbababcbbbaacbbaaccccbccabbabaaaabccbaaabcbbaacbacaaaabcabbababcbbabcabaaacbabcabaaabbbccaaccaabbcaccccabcacccbcbcbbbbbbbacbaacccccabacabbccbbccbcbcabababcbabbcaaccccbbcacaccccacbacaabccccabcacaaaccabcaccbcccbbaabbbcbcccccbbbcabcbaababbaacaacabaaabcaaabababcbbcaccaababacccababababaaaaacaaaabcbaaacabaccbcbbaaaabbbaaacbabababcabaacaabccbccbbcccabcaccbacbcaacaccaaacccbabbaabcabbbbcacabacccbcabcacacbcbabbbbaaaaaabccccacbcbcbbbabbabbcabccabacaabbcccbbabaacccaabcabaabacacbcacbabbbccbacaaacaaaabcabbbabaccaccbacbacbbbcbcacccabbabcaccabccacbcbaaaaccbacaccbcbcacbcaccbcacbabacbcbacbacaaaababbbaaabbbacacabbbcbcaacbcccbbabababcabaaabcccbbbbaaabbccccbbaaaccacacacbabcbabbabcaacacaaccccbccabbbaccacccaabbababcabcccaacbabbcbabcabbcbaacacbcbccabaaaaaaabcbabbcccacacbbabcbabbabcbbacabbaacacbbcbbbbababaacbbbccacbbbaaccabcbacbabbabcacaccbaacbaabaabcabbbacbbbccabaabcabcbbccbbacbbcbaacbbccccabacbabbcabbbbccbbccbcbacacbabcaccaababccbbacabbbccaabbaacabcbcbacabacaaaabcbbbabccacbcacbcaccbaaccccbbaacbbbbaacacabbbcbacabcabababccacabaabcbbababbcbabababccbcccbaababbcbaccccaaabcabaaabccabbbbacaaaccaabcacaabbccbaacaaccbccacccbabcbaabcaababbacacbcbbcccacbbbbccbaccaabccababacbcacbaccbbaccabbabaaaabaabbcbacccbcbaaabccaacbbccaababccacaaacbbcccbcaaacccbaccacbaacacaaabbcababaacbaaacbbbaabcacbcabcbbcbbcbccbacbabbbabaaabbaccacbabacbaccacbaccbcccbcbbaacbcacbaccbacacabcaabcabcabbcaaaacababbabbbcccccbbabcccaabaaacacccbabacabcbbccaabcacbaaaabbaccacacacbaabaababcaaaccaaacbcaabbacccaaaaaabcbaaaaccbbcbcbccbcbccbbccbabbaacaccabbccacacabababccbbcbaaaccccababaccabbbccbaabaabcbabaaaacbabbcabacccacaaccccacbabbbbabbcaccbbcacbbcbcaabbabbbacbcbcbcbaaccbbaabcbaabbabababbabbcbabacbbcacbbababcabcccbcaacaaabacaacabbbabbbcbabaababbbaacaacccbacccbccabbcaacccabbcbbccbcbbbcabacccabcababbaaaacbacccbabbbabaccbacbcaabaacccbacaaabcbaacccbbbacaabbaaaaacccacaccabccacabcccaaabcccacabbbaccbbacabcabaacbcabbcbbbbbacbbaccabbcaacaabaabbbccabaaabbabbcaaabcbaccbabccbbabcabbbcacbabbcccaccbcbbbcbbccabaccbcacbbaaacabcabaabbbbcaacbbcccbbbbbcaabacaacbccabaaaccabcbccbbaaabaabbbacbacaabbabacbcbbaaabaccbbaacacbccabbbcbbbbcccbbccbabbabbabbacaaabccbbbccccbaaaccbcccaabacbbaaccabacbcbabbbbbccbbacabccacaacaabbbaabcbaabababaacccaccbccbababbaaaccacccbcabcbaaacbcbccbbcccbbbaccabbacbbbcbabaccccabaccb
Out #5:
1299
In #6:
ccbbcbaabcccbabcbcaaaacabbaccccacaabcbbacacaacabcbccbaabcabbbccaabbcbbcacabcaaacacabacbccbaacbcbcaacacbaaaaccacccbaacaaabacaccabcbcbabbbacbabcaaccbccacbcbacacacbcaccabaccbccbaaaaabbacbacacbccbabcaacbbcccaccbcbacbacbcabaababccaaaacccccbbaabbccbcccabbacacaacbcccbaaacacabccabcccccabcaaaabbbcbbbaabccacccabacbcbbcbabacabbbbbbabbcabcbcbcaabcbcccbabaccccabbabbbacbbacbcccaaacaccababcccbcaccbcbcaacacbccbacbccbccaccbcbcabbbccabaacaccbcccbccaccbbcbcccbbccbacbcbcbbcbabcbacbbababcbcacbaaabbabacabbcbccbaccbbcbbbbcbbaacabaccbcbccabbbbccaabcbbcaccbbcaaaabababbabbbacaaabaabaccbcaaccaabcbbaccacbabbcccaccbcabcacabbaacccacbbabbabcccababcacababacccbacacabcbcccbabccccabcbaabbaaabaccccabbababaacabbcacbacacbbcbaabaabbbbaabcaaccbacbbaacacabcabacbaabcaabbccccccacbccccaabcbabaabcbbaaacccccabaaaabcaabbccccaccbacababbaccacababbacbbaaccbbacbbccaccaccabccbababbbacbacbaabcbbcaacaababbabbaacabcaabccabacbbbbcabcccacbacbababacaccabcaacbaabccaccacbccaabbcbaababaacaaaaaacccbcbbabbbbbcbcacbababacbbabcbabbcacbcaccbcaaabacaaababacaababcaccbababcabcababbaababcbabbcabbacccbbbccacbacccbccaabcaabcbbbccbaccbabcaacacaabababacabbcbbaccacbbbcbabccaccabcacabaacbbacbaccaabcaaaaacccabbaabaabcbacccbcbabaccbcbaabaaacabbaababbbbbcabaaaaaabacbbaabbaabbcacabbcbbcaabbcbaaaaacbabcaacaaacaacbcccbcbababbcbcacbcaaccaabbbbbacabaaaabcaababbccbccbccbbababbbaacbacccaacbcbccabcccaaabaacbbcacacaaabccccbcbbaacacaaccbaacbabaacccbbbcccaacbcacbcbbbbcbccaccccabcbcaccbbaacaabaabccaacccababccbcabbbaaababbbbaabbcacbbaaccbcaacacacaaacbcacbaacaccabccaaaacbaabbccbaaaccbbbcababbaacbabacbcbaacabcbababaabcbcbabaabcacacabaacbbbabcabaacbbcbccaaccccacaabaaaccbacacccbabcbbbbbaacabbbbbbbacaccabaacbcbaacbcbcbbcccbaaabaccbbacbccbaabacbaccbbbbcccccaccbccaaaababaaccccccbbbbbbabacaabbbccbcbaaaccbcabbccabbabbabcbcbccbbababcbbbaacbbaaccccbccabbabaaaabccbaaabcbbaacbacaaaabcabbababcbbabcabaaacbabcabaaabbbccaaccaabbcaccccabcacccbcbcbbbbbbbacbaacccccabacabbccbbccbcbcabababcbabbcaaccccbbcacaccccacbacaabccccabcacaaaccabcaccbcccbbaabbbcbcccccbbbcabcbaababbaacaacabaaabcaaabababcbbcaccaababacccababababaaaaacaaaabcbaaacabaccbcbbaaaabbbaaacbabababcabaacaabccbccbbcccabcaccbacbcaacaccaaacccbabbaabcabbbbcacabacccbcabcacacbcbabbbbaaaaaabccccacbcbcbbbabbabbcabccabacaabbcccbbabaacccaabcabaabacacbcacbabbbccbacaaacaaaabcabbbabaccaccbacbacbbbcbcacccabbabcaccabccacbcbaaaaccbacaccbcbcacbcaccbcacbabacbcbacbacaaaababbbaaabbbacacabbbcbcaacbcccbbabababcabaaabcccbbbbaaabbccccbbaaaccacacacbabcbabbabcaacacaaccccbccabbbaccacccaabbababcabcccaacbabbcbabcabbcbaacacbcbccabaaaaaaabcbabbcccacacbbabcbabbabcbbacabbaacacbbcbbbbababaacbbbccacbbbaaccabcbacbabbabcacaccbaacbaabaabcabbbacbbbccabaabcabcbbccbbacbbcbaacbbccccabacbabbcabbbbccbbccbcbacacbabcaccaababccbbacabbbccaabbaacabcbcbacabacaaaabcbbbabccacbcacbcaccbaaccccbbaacbbbbaacacabbbcbacabcabababccacabaabcbbababbcbabababccbcccbaababbcbaccccaaabcabaaabccabbbbacaaaccaabcacaabbccbaacaaccbccacccbabcbaabcaababbacacbcbbcccacbbbbccbaccaabccababacbcacbaccbbaccabbabaaaabaabbcbacccbcbaaabccaacbbccaababccacaaacbbcccbcaaacccbaccacbaacacaaabbcababaacbaaacbbbaabcacbcabcbbcbbcbccbacbabbbabaaabbaccacbabacbaccacbaccbcccbcbbaacbcacbaccbacacabcaabcabcabbcaaaacababbabbbcccccbbabcccaabaaacacccbabacabcbbccaabcacbaaaabbaccacacacbaabaababcaaaccaaacbcaabbacccaaaaaabcbaaaaccbbcbcbccbcbccbbccbabbaacaccabbccacacabababccbbcbaaaccccababaccabbbccbaabaabcbabaaaacbabbcabacccacaaccccacbabbbbabbcaccbbcacbbcbcaabbabbbacbcbcbcbaaccbbaabcbaabbabababbabbcbabacbbcacbbababcabcccbcaacaaabacaacabbbabbbcbabaababbbaacaacccbacccbccabbcaacccabbcbbccbcbbbcabacccabcababbaaaacbacccbabbbabaccbacbcaabaacccbacaaabcbaacccbbbacaabbaaaaacccacaccabccacabcccaaabcccacabbbaccbbacabcabaacbcabbcbbbbbacbbaccabbcaacaabaabbbccabaaabbabbcaaabcbaccbabccbbabcabbbcacbabbcccaccbcbbbcbbccabaccbcacbbaaacabcabaabbbbcaacbbcccbbbbbcaabacaacbccabaaaccabcbccbbaaabaabbbacbacaabbabacbcbbaaabaccbbaacacbccabbbcbbbbcccbbccbabbabbabbacaaabccbbbccccbaaaccbcccaabacbbaaccabacbcbabbbbbccbbacabccacaacaabbbaabcbaabababaacccaccbccbababbaaaccacccbcabcbaaacbcbccbbcccbbbaccabbacbbbcbabaccccabaccb
Out #6:
1299
In #7:
ccbbc
Out #7:
1
In #8:
ccbbcb
Out #8:
1
In #9:
ccbb
Out #9:
2
In #10:
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
Out #10:
0
In #11:
phqghumeaylnlfdxfircvscxggbwkfnqduxwfnfozvsrtkjprepggxrpnrvystmwcysyycqpevikeffmznimkkasvwsrenzkycxfxtlsgypsfadpooefxzbcoejuvpvaboygpoeylfpbnpljvrvipyamyehwqnqrqpmxujjloovaowuxwhmsncbxcoksfzkvatxdknlyjyhfixjswnkkufnuxxzrzbmnmgqooketlyhnkoaugzqrcddiuteiojwayyzpvscmpsajlfvgubfaaovlzylntrkdcpwsrtesjwhdizcobzcnfwlqijtvdwvxhrcbldvgylwgbusbmborxtlhcsmpxohgmgnkeufdxotogbgxpeyanfetcukepzshkljugggekjdqzjenpevqgxiepjsrdzjazujllchhbfqmkimwzobiwybxduunfsksrsrtekmqdcyzjeeuhmsrqcozijipfioneeddpszrnavymmtatbdzqsoemuvnpppsuacbazuxmhecthlegrpunkdmbppweqtgjoparmowzdqyoxytjbbhawdydcprjbxphoohpkwqyuhrqzhnbnfuvqnqqlrzjpxiogvliexdzuzosrkrusvojbrzmwzpowkjilefraamdigpnpuuhgxpqnjwjmwaxxmnsnhhlqqrzudltfzotcjtnzxuglsdsmzcnockvfajfrmxothowkbjzwucwljfrimpmyhchzriwkbarxbgfcbceyhjugixwtbvtrehbbcpxifbxvfbcgkcfqckcotzgkubmjrmbsztsshfroefwsjrxjhguzyupzwweiqurpixiqflduuveoowqcudhnefnjhaimuczfskuiduburiswtbrecuykabfcvkdzez
Out #11:
430
In #12:
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
Out #12:
0
In #13:
bbaabaaaaabbbbbbbababaabaabaabbabababbbabbabbabbbabaabbbbbbaabaaaaaaaaababaaabbabbaaaaaabaababbaaabbbbbaaabababbaaabbbbaaababbbabaaabaaabbbbbbbbbbbabaaaaabaabababababbbaabaaaababaababbaaaabbababbbabbababbabbaabaaabbabbbbbbabaaaaaaabbabbaaaaabababbaabaaabaaaabbbaaabaabbbbaabbaaabbbabbbbababaabbaababbabaabbabbabaabbbbabbbbabbbbaabaabaabababbbbbaaabbabaaabaaabbbabaababbaaabbabaaaabbababbaaaaaabbabbabbabaabaabbabbbbababbbabbbbaaaaaababaaabbbaabbaaababbaaaabaabbaaabaabaaabababbaabaabbbabbbabaaababbbbaaaaaabbbbbaaaababababaabbbaabbabababbbaaababababaaabbaaababbbbbaabababbbbbbbaabbaaaaabbabbbbbbababaabbbbbbaaabbaabbbabaababaababbbbaabbaaabababbaaabaabbbaababbabbabaaabbababbbbaabbabbbbbababbbbbaababaababaaabbabbbababbaaabbbaaaabbbbaabaababbbaaababbbababaaabbaaababbbbbabbbabbabbbbbbaaaabaaaaabbaaababbababbaabbbaabaabbbbbaabaabbaaaaaabbabaabbbaabaaaaaaabbbabbbbaaaaabbaaaabababaaabbbaaaaaabbababbabbaabaaabbbababbbbbaabbabaababaabbbbbbbaababbbbabaaaabaaaabbbbbaababaabbababbaaaabbabbbbbababaabbaaabbababbaaaaabbaaabababbababbabbaaaabbbaaaabaaabaaabaabababaaababbabaabaaaabaaaabbbaabaaaaabaaaabbababababaabbabaaababbabaaaaaababbbbbbaaababababbababbabababaaabbbbbabbaaaabbabaaaaaabaabbbbbbbbbaabbaabababbbbaaabaaaaabaaabbaaaabaaababbbbbaababaabaaabababbaaababaaababaaabbbabababaaaabaaabaabbbabaababababbabbabababbbbaababaabbbbbbaaaababbaaababbbbbbbaaaaabaabababaaaaaababbbabbaaaabbababbbbaabaaaaabaababbaaaabaaaababaabbbbbbaaabbabbaaabbaabaabbbbaababaaabbbabbaababbbbbabaaaaababbbaaaababbabaaabbbaabbaaababaaababaaaabaabaababbabbbaaaabababbbbaabbabbaabbaabbbaabaaabbbaabbaabbbbbaaabbaabbaabbbbbaaaabbbabbabbbaabaabaaabbbbbbabbaaabbaaabaaabbabbbabbaababbbbaabaabaababbababaaaabbbbbabbbbaabbbbabbabbaabbabbaababbabaaaabaabaababababbaaaaabaabbabaabbbbaabbbaabababababbbbabaaabaabaabbbbbabbbbbabbbaabbbabaaabbaaabbababaabbbbbbabbaabaabbbabaaabababaaabaaaaaabaaabbabaabbababababbaabababaaaaabaaabbbbbabbbbbbabbbbabbaaaabbaababbabaababaaabbbabbbabaabbababbbaabbbbbbabbabbaaaabaabbaabbbabbbbbbbbabbaabbbbabaaaabbaaabaabbaababbaaabbbaababbbbaaabaaabbabaaababbaabbbbabababbbbababbaaabbaabaabbbaaabbbabbbbbbbabbbaabbbbbaaaabbabbbabbababbabbbaaaabaabaabbababaaaabbbbbbabbabbbababaaababbabbabbabbabababbbbabaaabbbbabababbaababaababaaaabbabaabaaabbbbbabaabbbaabababaabaaababbababbbbaababbbaabaaaabababaaaabaabbbbaaaaaabbaabbaabbbbabbbaabbaaaabbabaabbabbabbbaababbaabbbbabababbbbabbbabbbaabbbbbbbabaaababaabaaaabbabbabaaaaabbbaaabbbababbababbbbabaabababbbbbbababbbbababbabaababaabababaabbababaababbbaaababbaaaaabbabbbbbaaabbaabaabaabaababbbababbabbabbaabbaaaababbababababababbabbbbabbabbabaabaabaabbbabaabaabababbbababaaabaabbbaabbababbbbbabbabbbbabbaabbbabaaaabbaaabababbaabbabbbbaaaabbbaaaaaababaababbaaaaabaaabaaaaabbaabaabaaabaaabbabbaabaaabababbbbabababbbaaabbabbbababababaaabbabbaabbbbbabbaabababababbaabbababbbabaaabaababbbbabbabbaaaaababbabaaaabbbaaabbabbabbaaabaabaaaababaaababbbbbbaaabbaaaababaaabbabababbbbaabbabbbabbababbbbbbabbbaabbbaabbbbaabbbabbbbbaaabaabaaabbaaaabbbbbbaaabaababaaaaababbabbbaabbabbaaaaaabbbabbababbbbabbabbbabaabaabbbbaababaababaaaababaaabbabbbbbabbababaaababbbaabbbaaaaaaababbbbabbbbaabbbbababbaabbaaaaaabbaaaabbabaaaaabbbaabbaaaaabbbbababbabaabbbabbbababaabbabbaabbbbaaaabbbbbbbaababbaaabbabaaaaabababbbbabbbbabbaababaaaabbabbaabbaaabbbaabababaabbaabbbbabaaabbabbbaababaaababababaabbbaaaabbabbabbbabbbabbbaaabbabbbbbbbbbaaaaaaabbabaabaababbaabbbbababbbabbabbaaaaabaaaaabbaaabbabbabbabbbabbaaaababbaabababbbbaaabbbbaaabababaabbabbababababbaabababbaaabaababbbaababaabbaabbbabbabbaaabbbaaaabbbaabaabaaaabaabbaababbbbbbaaaabbaabaaaaaabaababbbabaaabbbbbbaaabbabbbaabbabbbaabbbabbabaababaaabbbaabbbabaabbbbbaabbaaaabababbbbaaabaaabbbbbaabbaaaabbaaaaaabbabaaabbaabbabbbabbaabbaababaaaabababbbbabaabbababbabbabbaabbaaababaaababbbabbaabbaaababbaaaaabaaaababaaabababaaababababbaaaababbaaaababaaaabaabbaaabaaaabaababbbaaababbabbbbbbababbabaabbaaabaababbbbbbaaaabbbbbbbaaaabbabbabbabababbaabbbaabbaaaabaaaabbbbabaaaaaabaaaaabbabbbbbbababaabbaabaababbabababababaabbbaaaaaaaabaababaabaaaaaaabaaaabbaaabbaabbaababbbabaabbbbbbbbaabbbabbbaabbbaabaaabbbaaaaababaabaaaaabaaaaabbbbbbaabbababbbabaabbbbaaaaabbbbbbaabbbabbabbaabaaaabbabaabbabbbbbbbbbabbaaaabaaaaabbababaaabaabbaaabbbbababaaababbaaaababbababbbaabaaaaabaaaaabaaabbabaabbaaaabbababbaaabbabaaabbbbabbbbaaabbbabbabbabbbbbbbaaababaaaabaabaaaababbabaababaaabaabaabbbbabbaaaababbabaaabaaabbaaaaaaaaababbbbabbbbbbababbabbaabbabbbbbbaaaaaabbaaaaabbbbbbbbaabbbbabbbaabbabbabbabbbbabbbbbabaabbabbabbabbbbabababaabbaaabbabbbaabababbbaaaaabaaabbaaabaaabaaababaaaaabbbbabbaaaaabbabaabbaabaabaaabaaabaaaababbaabbbbbaabbbbabaabaaaaabbaaaaabbaaaaabaaabaaaabababbbaabababbbbbbababbaabaabababbaaaababaabbbbaaababaaaabaaabbbabbbbbabbbaabaaaabbbbaaaabaaaaaabbabaaaabbaababbaabbaaababbbbabaaabbbbabbabaabaaaaabbaaaabaaabbababbbaabaabaaaaaabbbaabbababbbaaabaaabbaaabaabbaabbaaaabbaaabaabbabaaabbabbbaabbbbabaababbbaabababbababbbabaaabbbbbbabbbaaaaaaabbabbba
Out #13:
1189
In #14:
bbaabaaaaab
Out #14:
2
In #15:
bbaabaaaaabbbbbbbaba
Out #15:
7
In #16:
bbaabaaaaabbbbbbbababaabaa
Out #16:
5
In #17:
bbaabaaaaabbbbbbbababaabaab
Out #17:
4

*/
