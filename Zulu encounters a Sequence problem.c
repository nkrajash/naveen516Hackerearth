/* All Tracks --> Data Structures --> Arrays --> 1-D --> Problem -->
Zulu encounters a Sequence Problem
Tag(s): Data Structures, Easy, Implementation, One-dimensional
Zulu is good in maths. He loves to play with numbers. One day while browsing through a book, he encountered a nice problem. 
In the problem, he was given an array A of N numbers.
For each index i in the array we define two quantities. Let r be the maximum index such that r>=i and sub-array from i to r (inclusive) is either non-decreasing 
or non-increasing. Similarly, let l be the minimum index such that l<=i  and sub-array from l to i (inclusive) is either non-decreasing or non-increasing. 
Now, we define points of an index i to be equal to max(|Ai-Al|,|Ai-Ar|) . Note that l and r can be different for each index i.
The task of the problem is to find the index of the array A which have the maximum points.
Since the problem seems a bit harder, Zulu is struck. Can you solve this problem for Zulu?

Input:
In the first line of input,TEST  will be given which is the number of test cases. 
For each of the test case, a single integer N will be given in the first line. 
In the second line, N space separated integers will be provided.

Output:
For each of the test cases, output the points of the index which have maximum points in the array in a separate line.

Constraint:
1<=TEST<=5
1<=N<=2*10^5
-2*10^9<=A[i]<=2*10^9

SAMPLE INPUT 
2
2
1 2
3
-4 1 0
SAMPLE OUTPUT 
1
5

Explanation
In the first test case, M will be equal to |1-2|=1.
In the second test case: For the first index,L=-4,R=1.For the second index,L=-4,R=0. For the third index, L=1,R=0 . So the maximum value of M is |1-(-4)|=5.

//My C Solution:
#include <stdio.h>
#include <stdlib.h>
#define LEN 200001
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

typedef long long int ll;
int main()
{
    ll t,temp,N,i;
    ll A[LEN],lincr[LEN],rincr[LEN],ldecr[LEN],rdecr[LEN];
    ll minl,maxr,abs1,abs2,maxind,max1;
    scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&N);
		for(i=0;i<=N-1;i++){
		    scanf("%lld",&temp);
		    A[i]=temp;
		    lincr[i]=ldecr[i]=rincr[i]=rdecr[i]=i;
		}
		for(i=1;i<=N-1;i++)
		{
			if(A[i]<=A[i-1])
				lincr[i]=lincr[i-1];
			if(A[i]>=A[i-1])
				ldecr[i]=ldecr[i-1];
		}
		for(i=N-2;i>=0;i--)
		{
			if(A[i]<=A[i+1])
				rincr[i]=rincr[i+1];
			if(A[i]>=A[i+1])
				rdecr[i]=rdecr[i+1];
		}
		maxind = -1;
		for(i=0;i<=N-1;i++)
		{
			minl=min(ldecr[i],rdecr[i]);
			maxr=max(rdecr[i],rincr[i]);
			abs1 = labs(A[i]-A[minl]);
			abs2 = labs(A[maxr]-A[i]);
			max1 = max(abs1,abs2);
			maxind=max(maxind,max1);
		}
        printf("%lld\n",maxind);
	}
	return 0;
}

*/

/* Editorial:
Setter: Amit Gupta
Tester: Hasan Jaddouh
Editorialist: Saatwik Singh Nagpal

Problem:
You are required to find the max value of abs(Ai-Aj), such that the sequence of integers in the range (i,j) forms either a non-decreasing or a non-increasing sequence.

Solution:
Once, you can traverse i from 1 to N, checking that you are maintaining an non-decreasing sequence of integers. Everytime, you can take the answer to be max(ans,abs(Ai-Acur)),
where cur represents the current index that you are on, and i represents the lowest index such that you were able to maintain a sequence that was non-decreasing.
Similarly, you can traverse i from 1 to N, checking that you are maintaining an non-increasing sequence of integers. Everytime, you can take the answer to be max(ans,abs(Ai-Acur)), 
where cur represents the current index that you are on, and i represents the lowest index such that you were able to maintain a sequence that was non-increasing.
This way, the problem can easily be solved in O(N) time.

Tester Solution by Hasan Jaddouh
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;
long long readInt(long long l,long long r,char endd){
	long long x=0;
	int cnt=0;
	int fi=-1;
	bool is_neg=false;
	while(true){
		char g=getchar();
		if(g=='-'){
			assert(fi==-1);
			is_neg=true;
			continue;
		}
		if('0'<=g && g<='9'){
			x*=10;
			x+=g-'0';
			if(cnt==0){
				fi=g-'0';
			}
			cnt++;
			assert(fi!=0 || cnt==1);
			assert(fi!=0 || is_neg==false);
			
			assert(!(cnt>19 || ( cnt==19 && fi>1) ));
		} else if(g==endd || g==-1){
			if(is_neg){
				x= -x;
			}
			assert(l<=x && x<=r);
			return x;
		} else {
			assert(false);
		}
	}
}
string readString(int l,int r,char endd){
	string ret="";
	int cnt=0;
	while(true){
		char g=getchar();
		assert(g!=-1);
		if(g==endd){
			break;
		}
		cnt++;
		ret+=g;
	}
	assert(l<=cnt && cnt<=r);
	return ret;
}
long long readIntSp(long long l,long long r){
	return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
	return readInt(l,r,'\n');
}
string readStringLn(int l,int r){
	return readString(l,r,'\n');
}
string readStringSp(int l,int r){
	return readString(l,r,' ');
}
int T;
int n;
long long arr[200200];
int main(){
	T=readIntLn(1,5);
	while(T--){
		n=readIntLn(1,200000);
		for(int i=0;i<n;i++){
			if(i==n-1){
				arr[i]=readIntSp(-2000000000,2000000000);
			} else {
				arr[i]=readIntSp(-2000000000,2000000000);
			}
		}
		getchar();
		long long sol=0;
		long long old;
		old=arr[0];
		for(int i=1;i<n;i++){
			if(arr[i]>=arr[i-1]){
				sol = max(sol,arr[i]-old);
			} else {
				old=arr[i];
			}
		}
		old=arr[0];
		for(int i=1;i<n;i++){
			if(arr[i]<=arr[i-1]){
				sol = max(sol,old-arr[i]);
			} else {
				old=arr[i];
			}
		}
		reverse(arr,arr+n);
		old=arr[0];
		for(int i=1;i<n;i++){
			if(arr[i]>=arr[i-1]){
				sol = max(sol,arr[i]-old);
			} else {
				old=arr[i];
			}
		}
		old=arr[0];
		for(int i=1;i<n;i++){
			if(arr[i]<=arr[i-1]){
				sol = max(sol,old-arr[i]);
			} else {
				old=arr[i];
			}
		}
		cout<<sol<<endl;
	}
	assert(getchar()==-1);
}

*/

/*
Best Submissions:
C:

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
#define ASC 1
#define DSC -1
 
int read_int() {
    int n =0;
    int neg =0;
    register int c = getchar_unlocked();
    if ('-' == c) {
        neg =1;
        c = getchar_unlocked();
    }
    for(; (c>47 && c<58); c = getchar_unlocked())
        n = n * 10 + c - 48;
    if(neg)
        n *= -1;
    return n;
}
 
int main () {
    int T = read_int();
 
    while(T--) {
        int N = read_int();
        long int max=INT_MIN;
 
        long int L = read_int();
        if (1==N) {
            printf("0\n");
            continue;
        }
        long int R = read_int();
        max = labs(R-L);
        if (2==N) {
            printf("%ld\n", max);
            continue;
        }
        int flag;
        if (L>R)
            flag=DSC;
        else if (L<R)
            flag=ASC;
        N -=2;
        long int ppivot= L;
        long int cpivot= L;
        for (int idx=0; idx<N; idx++) {
            long int diff;
            long int num = read_int();
 
            if (num == R)
                continue;
            //Series Progression
            if ((ASC == flag && R < num) ||
                    (DSC == flag && R > num)) {
                L = R;
                R = num;
                continue;
            }
            //Pivot in Progression
            if (ASC == flag) {
                flag = DSC;
            } else {
                flag = ASC;
            }
            diff = labs(R - ppivot);
            if(diff > max)
                max = diff;
            diff = labs(R - cpivot);
            if (diff > max)
                max = diff;
            ppivot = cpivot;
            cpivot = R;
            L = R;
            R = num;
        }
        // cover right-most range
        if (labs(R - cpivot) > max)
            max = labs(R - cpivot);
 
        printf("%ld\n", max);
    }
    return 0;
}

C++:
1).Best Solution:
#define _GLIBCXX_IOSTREAM
#include<bits/stdc++.h>
 
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef std::pair<int,int> pii;
 
#define xx first
#define yy second
 
template<typename T> inline T max(T a,T b){return a>b?a:b;}
template<typename T> inline T min(T a,T b){return a<b?a:b;}
template<typename T> inline T abs(T a){return a>0?a:-a;}
template<typename T> inline bool repr(T &a,T b){return a<b?a=b,1:0;}
template<typename T> inline bool repl(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline T gcd(T a,T b){T t;if(a<b){while(a){t=a;a=b%a;b=t;}return b;}else{while(b){t=b;b=a%b;a=t;}return a;}}
template<typename T> inline T sqr(T x){return x*x;}
#define mp(a,b) std::make_pair(a,b)
#define pb push_back
#define I inline
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
 
#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof(x.end())i=x.begin();i!=x.end();++i)
 
struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define RX x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;char t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int &x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char &x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char *x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf &x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf &x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint &x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull &x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char *x){while(*x)P(*x++);RT}
I Fw&OP()(const char *x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;
 
const int N=200007;
 
int n,s[N];
 
int main()
{
	for(int T=in;T--;)
	{
		in,n;
		fo1(i,n)in,s[i];
		int lst=s[1],op=1,lv=s[1];ll ans=0;
		fo(i,2,n)if(s[i]!=lst)
		{
			if(op)
			{
				if(s[i]>lst)lst=s[i];
				else repr(ans,abs((ll)lv-lst)),lv=lst,lst=s[i],op=0;
			}
			else
			{
				if(s[i]<lst)lst=s[i];
				else repr(ans,abs((ll)lv-lst)),lv=lst,lst=s[i],op=1;
			}
		}
		repr(ans,abs((ll)lv-lst));
		out,ans,'\n';
	}
}
2).Other:
#include <bits/stdc++.h>
#include <climits>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define srep(i, begin, end) for (__typeof(end) i = begin; i != end; i++)
#define si(x) int x = scanInt();
#define sll(x) LL x = scanLong();
#define pi(x) printf("%d ", x)
#define pll(x) printf("%lld ", x)
#define nl printf("\n")
#define all(v) v.begin(), v.end()
using namespace std;
typedef long int LI; // 32 bit integer
typedef unsigned long int ULI; // 32 bit unsigned integer
typedef long long int LL; // 64 bit integer
typedef unsigned long long int  ULL; // 64 bit unsigned integer
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
LL mod = 1e9+7;
 
// Fast I/O
inline int scanInt() { int n = 0; char ch = getchar_unlocked();	int sign = 1;
	while(ch < '0' || ch > '9') {if(ch == '-')	sign = -1;ch = getchar_unlocked();}
	while(ch >= '0' && ch <= '9') {n = (n<<1)+(n<<3)+(int)(ch-'0');	ch = getchar_unlocked();}
	return n*sign;
}
 
inline LL scanLong() {LL n = 0;	char ch = getchar_unlocked();LL sign = 1;
	while(ch < '0' || ch > '9') {if(ch == '-')	sign = -1;ch = getchar_unlocked();}
	while(ch >= '0' && ch <= '9') {n = (n<<1)+(n<<3)+(LL)(ch-'0');ch = getchar_unlocked();}
	return n*sign;
}
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
#endif
	sll(t);
	while(t-->0) {
	    // write your code here...
	    sll(n);
	    LL arr[n], li[n], ld[n], ri[n], rd[n];
	    rep(i, 0, n) {
	        arr[i] = scanLong();
	        if(i == 0)
	            li[i] = 0;
	        else if(arr[i] >= arr[i-1])
	            li[i] = li[i-1];
	        else
	            li[i] = i;
	        if(i == 0)
	            ld[i] = 0;
	        else if(arr[i] <= arr[i-1])
	            ld[i] = ld[i-1];
	        else
	            ld[i] = i;
	    }
	    rep(i, n, 0) {
	        if(i == n-1)
	            ri[i] = n-1;
	        else if(arr[i] >= arr[i+1])
	            ri[i] = ri[i+1];
	        else
	            ri[i] = i;
	        
	        if(i == n-1)
	            rd[i] = n-1;
	        else if(arr[i] <= arr[i+1])
	            rd[i] = rd[i+1];
	        else
	            rd[i] = i;
	    }
	    LL pnts[n];
	    rep(i, 0, n) {
	        pnts[i] = max(abs(arr[i] - arr[min(li[i], ld[i])]), abs(arr[i] - arr[max(ri[i], rd[i])]));
	    }
		cout << *max_element(pnts, pnts+n) << endl;
	}
}

3).
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
static int parseint(void){
   int c, n;
   int neg=1;
   n = getchar_unlocked();
   if(n=='-'){
       neg=-1;
        n = getchar_unlocked() - '0';    
   }else{
       n = n-'0';
   }
   //n = getchar_unlocked() - '0';
   while ((c = getchar_unlocked()) >= '0')
       n = 10*n + c-'0';
    n*=neg;
   return n;
}
long long int calc(int n){
    if(n==1){
        parseint();
         return 0;
    }
    
    long long int L,a;
    L = parseint();
    a = parseint();
    bool incr = (a-L) > 0;
    long long int max=abs(a-L);
    
    int ant=a;
    for(int i=2;i<n;i++){
        // cout << max << ' ';
        a = parseint();
        while(a==ant && i<n-1){
            i++;
            a=parseint();
        }
        if(incr && (a-ant)<0){
            incr = false;
            L=ant;
        }else if(!incr && (a-ant)>0){
            incr=true;
            L=ant;
        }
        
        if(abs(a-L)>max) max = abs(a-L);
        ant = a;
    }
    // cout << max << ' ';
    return max;
    
}
int main() {
	int T,n;
	T = parseint();
// 	cout << T << '\n';
	while(T>0){
        n = parseint();
        // cout << n << '\n';
        // for(int i=0;i<n;i++){
        //     if(i!=0) cout << ' ';
        //     cout << parseint();
        // }
        // cout << '\n';
        printf("%lli\n", calc(n));
        T--;
	}
}

4).
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define pll pair<ll,ll>
#define FOR1(i,a) for(i=0;i<=a;i++)
#define FOR2(i,a,b) for(i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
typedef long long ll;
int main()
{
	ll t,temp,N,i;cin>>t;
	while(t--)
	{
		cin>>N;
		vll A(N),lincr(N),rincr(N),ldecr(N),rdecr(N);
		FOR1(i,N-1)
		cin>>temp,A[i]=temp,lincr[i]=ldecr[i]=rincr[i]=rdecr[i]=i;
 
		FOR2(i,1,N-1)
		{
			if(A[i]<=A[i-1])
				lincr[i]=lincr[i-1];
 
			if(A[i]>=A[i-1])
				ldecr[i]=ldecr[i-1];
		}
 
		for(i=N-2;i>=0;i--)
		{
			if(A[i]<=A[i+1])
				rincr[i]=rincr[i+1];
			if(A[i]>=A[i+1])
				rdecr[i]=rdecr[i+1];
		}
		ll minl,maxr,omax=-1;
		FOR1(i,N-1)
		{
			minl=min(ldecr[i],rdecr[i]);
			maxr=max(rdecr[i],rincr[i]);
			omax=max(omax,max(abs(A[i]-A[minl]),abs(A[maxr]-A[i])));
		}
		cout<<omax<<endl;
	}
	return 0;
}

C++14:
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main(){
    fast;
    long int t, n, i, x, prev, max, diff1, diff2;
    cin>>t;
    while(t--){
        max = diff1 = diff2 = 0;
        cin>>n;
        cin>>prev;
        for(i = 1; i < n; i++){
            cin>>x;
            if(x >= prev)
                diff1 += (x - prev);
            else{
                if(max < diff1)
                    max = diff1;
                diff1 = 0;
            }
            if(x <= prev)
                diff2 += (prev - x);
            else{
                if(max < diff2)
                    max = diff2;
                diff2 = 0;
            }
            prev = x;
        }
        if(diff1 > max)
            max = diff1;
        if(diff2 > max)
            max = diff2;
        cout<<max<<endl;
    }
}

C#:
/* ============================== *\
 *    All code by stupid_chris    *
 *      ©(Christophe Savard)      *
 * Concordia University, Montreal *
 *              2017              *
\* ============================== */
 
#pragma warning disable IDE0018
#define TESTCASES
 
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
 
namespace HackerEarth
{
    /// <summary>
    /// Solution class
    /// </summary>
    internal static class Program
    {
        #region Main
        /// <summary>
        /// Modulo operator used in a lot of questions
        /// </summary>
        private const long mod = 1000000007L;
 
        /// <summary>
        /// Fast Console IO helper
        /// </summary>
        private static ConsoleHelper Console { get; }
 
        /// <summary>
        /// Pre processing setup
        /// </summary>
        static Program()
        {
            Console = new ConsoleHelper();
        }
 
        /// <summary>
        /// Main method - Launches solver
        /// </summary>
        private static void Main()
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
            System.Console.SetOut(File.AppendText(@"..\..\output.txt"));
            System.Console.Write($"\r\n\r\nTotal run time: {timer.Elapsed.TotalSeconds:0.000}s");
            System.Console.Out.Close();
#endif
        }
 
#if TESTCASES
 
        /// <summary>
        /// Solves the problem for multiple test cases
        /// </summary>
        private static void TestCases()
        {
            int t = Console.NextInt();
            Console.SkipNextLine();
 
            for (; t > 0; t--)
            {
                Solve();
            }
        }
 
#endif
        #endregion
 
        #region Solution
        private static void Solve()
        {
            int n = Console.NextInt();
            Console.SkipNextLine();
 
            long[] array = Console.NextLongs(n);
 
            long max = 0;
            int r = 0, l = 0;
 
            while (l < n)
            {
                while (++r < n && array[r] >= array[r - 1]) { }
 
                max = Math.Max(max, array[--r] - array[l]);
 
                if (r == n - 1)
                {
                    if (array[n - 1] >= array[r])
                    {
                        max = Math.Max(max, array[n - 1] - array[l]);
                    }
                    break;
                }
 
                l = ++r;
            }
 
            l = r = 0;
            while (l < n)
            {
                while (++r < n && array[r] <= array[r - 1]) { }
 
                max = Math.Max(max, array[l] - array[--r]);
 
                if (r == n - 1)
                {
                    if (array[n - 1] <= array[r])
                    {
                        max = Math.Max(max, array[l] - array[n - 1]);
                    }
                    break;
                }
                l = ++r;
            }
 
            Console.WriteLine(max);
        }
        #endregion
    }
 
    #region Tools
    // Solution does not extend beyond this point, those are merely tools to help along
    /// <summary>
    /// Fast Console IO helper
    /// </summary>
    [DebuggerStepThrough]
    internal sealed class ConsoleHelper : IDisposable
    {
        #region Constants
        /// <summary>
        /// The standard input and output buffers size (2^20, 1Mb)
        /// </summary>
        private const int baseSize = 1048576;
        /// <summary>
        /// Integer out string conversion buffer
        /// </summary>
        private static readonly char[] numBuffer = new char[20];
        #endregion
 
        #region Fields
        private readonly BufferedStream inStream; // Buffered console input stream
        private readonly StreamWriter outStream; // Buffered console output stream
 
        private readonly byte[] inBuffer; // Input buffer 
        private int inputIndex; // Input buffer current index
        private int bufferEnd; // Input buffer ending index
        #endregion
 
        #region Properties
        /// <summary>
        /// The buffer size, in bytes
        /// </summary>
        public int BufferSize { get; }
 
        /// <summary>
        /// If this memory stream is open and available to read/write
        /// </summary>
        public bool Open { get; private set; }
 
        /// <summary>
        /// Checks to see if there is still readable data within the stream
        /// </summary>
        /// <returns>True if there is still data to read, false otherwise</returns>
        public bool HasData => Peek() != 0;
        #endregion
 
        #region Constructors
        /// <summary>
        /// Creates a new console IO helper reading from the standard Console input and output
        /// </summary>
        public ConsoleHelper() : this(baseSize) { }
 
        /// <summary>
        /// Creates a new console IO helper reading from the standard Console input and output with the specified buffer size
        /// <param name="bufferSize">Size of the buffer to use in bytes</param>
        /// </summary>
        public ConsoleHelper(int bufferSize)
        {
            // Open the input/output streams
#if DEBUG
            // Test mode
            this.inStream = new BufferedStream(File.OpenRead(@"..\..\input.txt"), bufferSize);
            this.outStream = new StreamWriter(File.Create(@"..\..\output.txt", bufferSize), Encoding.ASCII, bufferSize);
#else // !DEBUG
// Submission mode
            this.inStream = new BufferedStream(Console.OpenStandardInput(bufferSize), bufferSize); // Submission stream
            this.outStream = new StreamWriter(Console.OpenStandardOutput(bufferSize), Encoding.ASCII, bufferSize);
#endif
 
            // Set fields
            this.inBuffer = new byte[bufferSize];
            this.inputIndex = this.bufferEnd = 0;
            this.BufferSize = bufferSize;
            this.Open = true;
        }
        #endregion
 
        #region Static methods
        /// <summary>
        /// Verifies that the passed character is a non-special ASCII character
        /// </summary>
        /// <param name="i">Character to validate</param>
        /// <returns>True if the character is not a special character</returns>
        public static bool ValidateChar(int i) => i >= ' ';
 
        /// <summary>
        /// Verifies that the passed character is a non-special ASCII character or a whitespace
        /// </summary>
        /// <param name="i">Character to validate</param>
        /// <returns>True if the character is not a whitespace or a special character</returns>
        public static bool ValidateCharNoSpace(int i) => i > ' ';
 
        /// <summary>
        /// Verifies that the passed character is a numerical character (0-9)
        /// </summary>
        /// <param name="i">Character to validate</param>
        /// <returns>True if the character is a numerical character, false otherwise</returns>
        public static bool ValidateNumber(int i) => i >= '0' && i <= '9';
 
        /// <summary>
        /// Verifies if a character is an Endline character
        /// </summary>
        /// <param name="i">Character to check</param>
        /// <returns>True if it is an Endline character, false otherwise</returns>
        public static bool IsEndline(int i) => i == '\n' || i == '\0';
 
        /// <summary>
        /// Takes a signed int value and copies it's characters at the end of the integer char buffer
        /// </summary>
        /// <param name="n">Int to write to the buffer</param>
        /// <returns>Head index at which the buffer's writing starts</returns>
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
                numBuffer[--head] = (char)((n % 10) + 48);
                n /= 10;
            }
            while (n > 0);
 
            if (neg) { numBuffer[--head] = '-'; }
            return head;
        }
 
        /// <summary>
        /// Takes a signed long value and copies it's characters at the end of the integer char buffer
        /// </summary>
        /// <param name="n">Long to write to the buffer</param>
        /// <returns>Head index at which the buffer's writing starts</returns>
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
                numBuffer[--head] = (char)((n % 10L) + 48L);
                n /= 10L;
            }
            while (n > 0L);
 
            if (neg) { numBuffer[--head] = '-'; }
            return head;
        }
        #endregion
 
        #region Methods
        /// <summary>
        /// Returns the next byte data in the console input stream
        /// </summary>
        /// <returns>Next data byte from the console</returns>
        public byte Read()
        {
            CheckBuffer();
            return this.inBuffer[this.inputIndex++];
        }
 
        /// <summary>
        /// Returns the next byte data in the console input stream without consuming it
        /// </summary>
        /// <returns>Next data byte from the console</returns>
        public byte Peek()
        {
            CheckBuffer();
            return this.inBuffer[this.inputIndex];
        }
 
        /// <summary>
        /// Skips a number of characters in the input stream
        /// </summary>
        /// <param name="n">Amount of chars to skip, defaults to 1</param>
        public void Skip(int n = 1) => this.inputIndex += n;
 
        /// <summary>
        /// Assures we have data available in the input buffer
        /// </summary>
        private void CheckBuffer()
        {
            // If we reach the end of the buffer, load more data
            if (this.inputIndex >= this.bufferEnd)
            {
                this.inputIndex = this.inputIndex - this.bufferEnd;
                this.bufferEnd = this.inStream.Read(this.inBuffer, 0, this.BufferSize);
 
                // If nothing was added, add a null char at the start
                if (this.bufferEnd < 1) { this.inBuffer[this.bufferEnd++] = 0; }
            }
        }
 
        /// <summary>
        /// Returns the next character in the console input stream
        /// </summary>
        /// <returns>Next character in the input stream</returns>
        public char NextChar() => (char)Read();
 
        /// <summary>
        /// Returns the next string token from the console input
        /// </summary>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <returns>Parsed string, separated by spaces or special characters such as line feeds</returns>
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
 
        /// <summary>
        /// Returns the next int value in the console input, this is a fast parse
        /// </summary>
        /// <exception cref="FormatException">If the text is not a valid integer</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for integer</exception>
        /// <returns>Parsed int value from the input</returns>
        public int NextInt()
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
 
            return neg ? -n : n;
        }
 
        /// <summary>
        /// Returns the next long value in the console input, this is a fast parse
        /// </summary>
        /// <exception cref="FormatException">If the text is not a valid long</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for long</exception>
        /// <returns>Parsed long value from the input</returns>
        public long NextLong()
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
 
            return neg ? -n : n;
        }
 
        /// <summary>
        /// Returns the next double value in the console input
        /// Note: fast double parsing is slightly harder, I'll implement it if I need to
        /// </summary>
        /// <exception cref="FormatException">If the text is not a valid double</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for double</exception>
        /// <returns>Parsed double value from the input</returns>
        public double NextDouble() => double.Parse(Next());
 
        /// <summary>
        /// Returns the next n int values on the same line in an array
        /// </summary>
        /// <param name="n">Number of values to seek</param>
        /// <exception cref="FormatException">If the text is not a valid integer</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for integer</exception>
        /// <exception cref="OutOfMemoryException">If the created array is too large for the system memory</exception>
        /// <returns>The n integer values in an array</returns>
        public int[] NextInts(int n)
        {
            int[] array = new int[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = NextInt();
            }
 
            SkipNextLine();
            return array;
        }
 
        /// <summary>
        /// Returns the next n long values on the same line in an array
        /// </summary>
        /// <param name="n">Number of values to seek</param>
        /// <exception cref="FormatException">If the text is not a valid long</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for long</exception>
        /// <exception cref="OutOfMemoryException">If the created array is too large for the system memory</exception>
        /// <returns>The n long values in an array</returns>
        public long[] NextLongs(int n)
        {
            long[] array = new long[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = NextLong();
            }
 
            SkipNextLine();
            return array;
        }
 
        /// <summary>
        /// Returns the next n int values on the next m lines in the output stream under the form of an NxM matrix
        /// </summary>
        /// <param name="n">Number of rows to the matrix</param>
        /// <param name="m">Number of columns to the matrix</param>
        /// <exception cref="FormatException">If the text is not a valid integer</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for integer</exception>
        /// <exception cref="OutOfMemoryException">If the created 2D array is too large for the system memory</exception>
        /// <returns>The NxM matrix of integers</returns>
        public int[,] NextMatrix(int n, int m)
        {
            int[,] matrix = new int[n, m];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[i, j] = NextInt();
                }
 
                SkipNextLine();
            }
 
            return matrix;
        }
 
        /// <summary>
        /// Returns the next line of text in the console
        /// </summary>
        /// <returns>Next string line from the console</returns>
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
 
        /// <summary>
        /// Skips the next token in input
        /// </summary>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        public void SkipNext()
        {
            byte b = SkipInvalid();
            ValidateEndline(b);
 
            for (b = Peek(); ValidateCharNoSpace(b); b = Peek())
            {
                Skip();
            }
        }
 
        /// <summary>
        /// Skips all the text on the current line and jump to the next
        /// </summary>
        public void SkipNextLine()
        {
            for (byte b = Read(); !IsEndline(b); b = Read()) { }
        }
 
        /// <summary>
        /// Enumerates the given number of integers on the current line
        /// </summary>
        /// <param name="n">Number of integers on the current line</param>
        /// <returns>Enumerable of the integers</returns>
        public IEnumerable<int> EnumerateInts(int n)
        {
            while (n-- > 0)
            {
                yield return NextInt();
            }
 
            SkipNextLine();
        }
 
        /// <summary>
        /// Enumerates all the characters in the next line until the feed is exhausted or an endline character is met
        /// </summary>
        /// <returns>Enumerable of all the characters in the current line</returns>
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
 
        /// <summary>
        /// Assures we are not trying to read more data on the line that there exists
        /// </summary>
        /// <param name="b">Byte data to verify</param>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        private void ValidateEndline(byte b)
        {
            // If empty char
            if (b == 0)
            {
                // Go back a char and throw
                this.inputIndex--;
                throw new InvalidOperationException("No values left on line");
            }
        }
 
        /// <summary>
        /// Skips all invalid character bytes then returns the first valid byte found, spaces are considered invalid
        /// </summary>
        /// <returns>The next valid character byte, cannot be a whitespace</returns>
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
 
        /// <summary>
        /// Writes the given char to the console output
        /// </summary>
        /// <param name="c">Character to write</param>
        public void Write(char c) => this.outStream.Write(c);
 
        /// <summary>
        /// Writes the given char buffer to the console output
        /// </summary>
        /// <param name="buffer">Char buffer to write</param>
        public void Write(char[] buffer) => this.outStream.Write(buffer);
 
        /// <summary>
        /// Writes the given string to the console output
        /// </summary>
        /// <param name="s">String to write</param>
        public void Write(string s) => this.outStream.Write(s);
 
        /// <summary>
        /// Writes the given integer to the console output
        /// </summary>
        /// <param name="n">Integer to write</param>
        public void Write(int n)
        {
            int head = GetIntBuffer(n);
            this.outStream.Write(numBuffer, head, 20 - head);
        }
 
        /// <summary>
        /// Writes the given long to the console output
        /// </summary>
        /// <param name="n">Long to write</param>
        public void Write(long n)
        {
            int head = GetLongBuffer(n);
            this.outStream.Write(numBuffer, head, 20 - head);
        }
 
        /// <summary>
        /// Writes the contents of the StringBuilder to the console output
        /// </summary>
        /// <param name="sb">StringBuilder to write to the output</param>
        public void Write(StringBuilder sb) => this.outStream.Write(sb.ToCharArray());
 
        /// <summary>
        /// Writes the given object to the console output using the object's ToString method
        /// </summary>
        /// <param name="o">Object to write</param>
        public void Write(object o) => this.outStream.Write(o);
 
        /// <summary>
        /// Writes a sequence to the console output with the given string separator
        /// </summary>
        /// <typeparam name="T">Type of elements in the sequence</typeparam>
        /// <param name="e">Sequence to print</param>
        /// <param name="separator">String separator between each element, defaults to the empty string</param>
        public void Write<T>(IEnumerable<T> e, string separator = "") => this.outStream.Write(new StringBuilder().AppendJoin(e, separator).ToCharArray());
 
        /// <summary>
        /// Writes a sequence to the console output with the given string separator
        /// </summary>
        /// <typeparam name="T">Type of elements in the sequence</typeparam>
        /// <param name="e">Sequence to print</param>
        /// <param name="separator">Character separator between each element</param>
        public void Write<T>(IEnumerable<T> e, char separator) => this.outStream.Write(new StringBuilder().AppendJoin(e, separator).ToCharArray());
 
        /// <summary>
        /// Writes a linefeed to the console output
        /// </summary>
        public void WriteLine() => this.outStream.WriteLine();
 
        /// <summary>
        /// Writes the given char to the console output, followed by a linefeed
        /// </summary>
        /// <param name="c">Character to write</param>
        public void WriteLine(char c) => this.outStream.WriteLine(c);
 
        /// <summary>
        /// Writes the given char buffer to the console output, followed by a linefeed
        /// </summary>
        /// <param name="buffer">Char buffer to write to the output</param>
        public void WriteLine(char[] buffer) => this.outStream.WriteLine(buffer);
 
        /// <summary>
        /// Writes the given string to the console output, followed by a linefeed
        /// </summary>
        /// <param name="s">String to write</param>
        public void WriteLine(string s) => this.outStream.WriteLine(s);
 
        /// <summary>
        /// Writes the given integer to the console output, followed by a linefeed
        /// </summary>
        /// <param name="n">Integer to write</param>
        public void WriteLine(int n)
        {
            int head = GetIntBuffer(n);
            this.outStream.WriteLine(numBuffer, head, 20 - head);
        }
 
        /// <summary>
        /// Writes the given long to the console output, followed by a linefeed
        /// </summary>
        /// <param name="n">Long to write</param>
        public void WriteLine(long n)
        {
            int head = GetLongBuffer(n);
            this.outStream.WriteLine(numBuffer, head, 20 - head);
        }
 
        /// <summary>
        /// Writes the contents of the StringBuilder to the console output, followed by a linefeed
        /// </summary>
        /// <param name="sb">StringBuilder to write to the output</param>
        public void WriteLine(StringBuilder sb) => this.outStream.WriteLine(sb.ToCharArray());
 
        /// <summary>
        /// Writes a sequence to the console output with the given string separator, follows by a linefeed
        /// </summary>
        /// <typeparam name="T">Type of elements in the sequence</typeparam>
        /// <param name="e">Sequence to print</param>
        /// <param name="separator">String separator between each element, defaults to the empty string</param>
        public void WriteLine<T>(IEnumerable<T> e, string separator = "") => this.outStream.WriteLine(new StringBuilder().AppendJoin(e, separator).ToCharArray());
 
        /// <summary>
        /// Writes a sequence to the console output with the given string separator, follows by a linefeed
        /// </summary>
        /// <typeparam name="T">Type of elements in the sequence</typeparam>
        /// <param name="e">Sequence to print</param>
        /// <param name="separator">Character separator between each element</param>
        public void WriteLine<T>(IEnumerable<T> e, char separator) => this.outStream.WriteLine(new StringBuilder().AppendJoin(e, separator).ToCharArray());
 
        /// <summary>
        /// Writes the given object to the console output using the object's ToString method, followed by a linefeed
        /// </summary>
        /// <param name="o">Object to write</param>
        public void WriteLine(object o) => this.outStream.WriteLine(o);
 
        /// <summary>
        /// Flushes the output buffer to the console if the buffer is full, or if it's being forced
        /// </summary>
        public void Flush() => this.outStream.Flush();
 
        /// <summary>
        /// Disposes of the resources of this ConsoleHelper, closing all the associated streams
        /// </summary>
        public void Dispose()
        {
            if (this.Open)
            {
                Flush();
                this.inStream.Dispose();
                this.outStream.Dispose();
                this.Open = false;
            }
        }
        #endregion
    }
 
    /// <summary>
    /// Useful extensions
    /// </summary>
    internal static class Extensions
    {
        #region Enumerable extensions
        /// <summary>
        /// Finds out if the amount of objects in the enumerable is equal to the given number
        /// </summary>
        /// <typeparam name="T">Type of element in the Enumerable</typeparam>
        /// <param name="e">Enumerable to iterate through</param>
        /// <param name="count">Number of items that the enumerable should be equal to</param>
        /// <returns>True if the amount of objects is equal to count, false otherwise</returns>
        public static bool EqualTo<T>(this IEnumerable<T> e, int count)
        {
            if (count < 0) { return false; }
 
            int total = 0;
            return !e.Any(t => ++total > count) && total == count;
        }
 
        /// <summary>
        /// Applies an action on each member of the enumerable
        /// </summary>
        /// <typeparam name="T">Type of elements in the Enumerable</typeparam>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="action">Action to apply to each parameter</param>
        public static void ForEach<T>(this IEnumerable<T> e, Action<T> action)
        {
            foreach (T t in e)
            {
                action(t);
            }
        }
 
        /// <summary>
        /// Tests whether or not the given collection of items is empty
        /// </summary>
        /// <param name="c">Collection to test</param>
        /// <returns>True if the collection is empty, false otherwise</returns>
        public static bool IsEmpty(this System.Collections.ICollection c) => c.Count == 0;
 
        /// <summary>
        /// Finds out if the amount of objects in the enumerable is greater than the given number
        /// </summary>
        /// <typeparam name="T">Type of element in the Enumerable</typeparam>
        /// <param name="e">Enumerable to iterate through</param>
        /// <param name="count">Number of items that the enumerable should be greater than</param>
        /// <returns>True if the amount of objects is greater than count, false otherwise</returns>
        public static bool GreaterThan<T>(this IEnumerable<T> e, int count)
        {
            if (count < 0) { return true; }
 
            int total = 0;
            return e.Any(t => ++total > count);
        }
 
        /// <summary>
        /// Joins all the elements of the enumerable into a string
        /// </summary>
        /// <typeparam name="T">Type of elements in the Enumerable</typeparam>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="separator">Separator string, defaults to the empty string</param>
        public static string Join<T>(this IEnumerable<T> e, string separator = "") => new StringBuilder().AppendJoin(e, separator).ToString();
 
        /// <summary>
        /// Joins all the elements of the enumerable into a string
        /// </summary>
        /// <typeparam name="T">Type of elements in the Enumerable</typeparam>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="separator">Separator character</param>
        public static string Join<T>(this IEnumerable<T> e, char separator) => new StringBuilder().AppendJoin(e, separator).ToString();
 
        /// <summary>
        /// Finds out if the amount of objects in the enumerable is less than the given number
        /// </summary>
        /// <typeparam name="T">Type of element in the Enumerable</typeparam>
        /// <param name="e">Enumerable to iterate through</param>
        /// <param name="count">Number of items that the enumerable should be less than</param>
        /// <returns>True if the amount of objects is less than count, false otherwise</returns>
        public static bool LessThan<T>(this IEnumerable<T> e, int count)
        {
            if (count <= 0) { return false; }
 
            int total = 0;
            return !e.Any(t => ++total >= count);
        }
 
        /// <summary>
        /// Finds the object with the maximum value in the enumerable
        /// </summary>
        /// <typeparam name="T">Type of objects in the Enumerable</typeparam>
        /// <typeparam name="TU">Comparing type, must implement IComparable(T)</typeparam>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="selector">Function calculating the value that we want the max from</param>
        /// <returns>The object with the maximum value in the enumerable</returns>
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
 
        /// <summary>
        /// Finds the object with the minimum value in the enumerable
        /// </summary>
        /// <typeparam name="T">Type of objects in the Enumerable</typeparam>
        /// <typeparam name="TU">Comparing type, must implement IComparable(T)</typeparam>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="selector">Function calculating the value that we want the min from</param>
        /// <returns>The object with the minimum value in the enumerable</returns>
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
        #endregion
 
        #region String extensions
        /// <summary>
        /// Appends multiple objects to a StringBuilder, separated by the given string
        /// </summary>
        /// <typeparam name="T">Type of elements in the Enumerable</typeparam>
        /// <param name="sb">StringBuilder to append to</param>
        /// <param name="source">Enumerable to loop through</param>
        /// <param name="separator">Separator string, defaults to the empty string</param>
        /// <returns>The StringBuilder instance after the appending is done</returns>
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
 
        /// <summary>
        /// Appends multiple objects to a StringBuilder, separated by the given string
        /// </summary>
        /// <typeparam name="T">Type of elements in the Enumerable</typeparam>
        /// <param name="sb">StringBuilder to append to</param>
        /// <param name="source">Enumerable to loop through</param>
        /// <param name="separator">Separator character</param>
        /// <returns>The StringBuilder instance after the appending is done</returns>
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
 
        /// <summary>
        /// Returns true if the string is null, or the empty string ""
        /// Note: this will never throw a NullRef exception given that it is an extension method calling a static method
        /// </summary>
        /// <param name="s">String to test</param>
        /// <returns>True if the string is null or empty, false otherwise</returns>
        public static bool IsEmpty(this string s) => string.IsNullOrEmpty(s);
 
        /// <summary>
        /// Creates a substring from a starting and ending index
        /// </summary>
        /// <param name="s">String to substring</param>
        /// <param name="start">Starting index</param>
        /// <param name="end">Ending index</param>
        /// <returns>The resulting substring</returns>
        public static string SubStr(this string s, int start, int end) => s.Substring(start, (end - start) + 1);
 
        /// <summary>
        /// Copies the contents of a StringBuilder instance to an array
        /// </summary>
        /// <param name="sb">StringBuilder to copy</param>
        /// <returns>Contents array of the StringBuilder</returns>
        public static char[] ToCharArray(this StringBuilder sb)
        {
            char[] buffer = new char[sb.Length];
            sb.CopyTo(0, buffer, 0, sb.Length);
            return buffer;
        }
        #endregion
 
        #region Number extensions
        /// <summary>
        /// Tests if the given number is pair or not
        /// </summary>
        /// <param name="n">Number to test</param>
        /// <returns>True if the number is pair, false otherwise</returns>
        public static bool IsPair(this int n) => (n & 1) == 0;
 
        /// <summary>
        /// Tests if the given number is pair or not
        /// </summary>
        /// <param name="n">Number to test</param>
        /// <returns>True if the number is pair, false otherwise</returns>
        public static bool IsPair(this long n) => (n & 1L) == 0;
 
        /// <summary>
        /// Real Modulus function over the integer, not a remainder function like the normal C# mod
        /// </summary>
        /// <param name="n">Left operand of the mod</param>
        /// <param name="m">Right operand of the mod</param>
        /// <returns>The Modulus of n and m, within [0, m - 1]</returns>
        public static int Mod(this int n, int m) => ((n % m) + m) % m;
 
        /// <summary>
        /// Real Modulus function over the integer, not a remainder function like the normal C# mod
        /// </summary>
        /// <param name="n">Left operand of the mod</param>
        /// <param name="m">Right operand of the mod</param>
        /// <returns>The Modulus of n and m, within [0, m - 1]</returns>
        public static long Mod(this long n, long m) => ((n % m) + m) % m;
 
        /// <summary>
        /// Returns the triangle number of the current number
        /// </summary>
        /// <param name="n">Integer to get the triangle number from</param>
        /// <returns>The resulting triangle number</returns>
        public static int Triangle(this int n) => (n * (n + 1)) / 2;
 
        /// <summary>
        /// Returns the triangle number of the current number
        /// </summary>
        /// <param name="n">Long to get the triangle number from</param>
        /// <returns>The resulting triangle number</returns>
        public static long Triangle(this long n) => (n * (n + 1L)) / 2L;
 
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
 
        /// <summary>
        /// Sums all the digits of the integer n
        /// </summary>
        /// <param name="n">Integer to sum the digits of</param>
        /// <returns>Sum of all the digits of n</returns>
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
 
        #region Array extensions
        /// <summary>
        /// Does a binary search through the sorted array to find the requested value
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="value">Value to find</param>
        /// <returns>The index of the found element, or -1 if it wasn't found</returns>
        public static int BinarySearch<T>(this T[] array, T value) => Array.BinarySearch(array, value);
 
        /// <summary>
        /// Clears the array of all elements
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to clear</param>
        public static void Clear<T>(this T[] array) => Array.Clear(array, 0, array.Length);
 
        /// <summary>
        /// Determines if the array contains the given value
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="value">Value to find</param>
        /// <returns>True if the value was found, false otherwise</returns>
        public static bool Contains<T>(this T[] array, T value) => Array.IndexOf(array, value) != -1;
 
        /// <summary>
        /// Enumerates the contents of an ArraySegment
        /// </summary>
        /// <typeparam name="T">Type contained within the array</typeparam>
        /// <param name="array">Array to iterate through</param>
        /// <param name="offset">Index offset to start the iteration at, defaults to 0</param>
        /// <param name="count">Amount of values to return, default to the whole array</param>
        /// <returns>Enumerable of all the values contained in the ArraySegment</returns>
        public static IEnumerable<T> Enumerate<T>(this T[] array, int offset = 0, int count = 0)
        {
            if (count == 0) { count = array.Length - offset; }
 
            int max = offset + count;
            for (int i = offset; i < max; i++)
            {
                yield return array[i];
            }
        }
 
        /// <summary>
        /// Finds the first element matching the given condition in the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="match">Matching function to apply</param>
        /// <returns>The first found element that satisfied the match, or default(T) if none did</returns>
        public static T Find<T>(this T[] array, Predicate<T> match) => Array.Find(array, match);
 
        /// <summary>
        /// Finds the last element matching the given condition in the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="match">Matching function to apply</param>
        /// <returns>The last found element that satisfied the match, or default(T) if none did</returns>
        public static T FindLast<T>(this T[] array, Predicate<T> match) => Array.FindLast(array, match);
 
        /// <summary>
        /// Applies an action to every member of the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to loop through</param>
        /// <param name="action">Action to apply on each member</param>
        public static void ForEach<T>(this T[] array, Action<T> action) => Array.ForEach(array, action);
 
        /// <summary>
        /// Generates all the subsets of the given array of a size greater than 1
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to get the subsets from</param>
        /// <returns>All the subsets of size 1 or greater from the array</returns>
        public static IEnumerable<List<T>> GetSubsets<T>(this T[] array)
        {
            int max = 1 << array.Length, l = array.Length - 1;
            for (int i = 1; i < max; i++)
            {
                if ((i & -i) == i) { continue; } // Exclude subsets of length 1
 
                List<T> subset = new List<T>(array.Length);
                subset.AddRange(array.Where((t, j) => (i & (1 << (l - j))) != 0));
                yield return subset;
            }
        }
 
        /// <summary>
        /// Finds the first index of the given value in the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="value">Value to find</param>
        /// <returns>The index of the value in the array, or -1 if it wasn't found</returns>
        public static int IndexOf<T>(this T[] array, T value) => Array.IndexOf(array, value);
 
        /// <summary>
        /// Finds the last index of the given value in the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="value">Value to find</param>
        /// <returns>The last index of the value in the array, or -1 if it wasn't found</returns>
        public static int LastIndexOf<T>(this T[] array, T value) => Array.LastIndexOf(array, value);
 
        /// <summary>
        /// Reverses the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to reverse</param>
        /// <returns>The reversed array</returns>
        public static T[] Reverse<T>(this T[] array)
        {
            Array.Reverse(array);
            return array;
        }
 
        /// <summary>
        /// Sorts the array with the default comparer of T
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to sort</param>
        public static void Sort<T>(this T[] array) => Array.Sort(array);
 
        /// <summary>
        /// Sorts an array with the given comparison method
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to sort</param>
        /// <param name="comparison">Comparison method to sort the array with</param>
        public static void Sort<T>(this T[] array, Comparison<T> comparison) => Array.Sort(array, comparison);
 
        /// <summary>
        /// Swap two elements in an array
        /// </summary>
        /// <typeparam name="T">Type of the array</typeparam>
        /// <param name="array">Aray to swap elements in</param>
        /// <param name="i">Index of the first element</param>
        /// <param name="j">Index of the second element</param>
        public static void Swap<T>(this T[] array, int i, int j)
        {
            T t = array[i];
            array[i] = array[j];
            array[j] = t;
        }
        #endregion
    }
    #endregion
}

Java:
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
 
public class ZuluencountersaSequenceProblem {
 
	public static void main(String[] args) throws IOException {
		
		Reader sc = new Reader();
		int T = sc.nextInt();
		for(int t=0;t<T;t++){
			boolean flag = false;
			int N = sc.nextInt();   //9
			long max=0;
			long firstele=sc.nextLong();
			long lastele=0;
			if(N>=2){
			lastele=sc.nextLong();
			}
			if(firstele>lastele && N >1){
				max=firstele-lastele;
			}
			else if(lastele>firstele && N >1 ){
				max=lastele-firstele;
			}
			//long lastele=0;
			long lastnext = 0;
			for(int i=2;i<N;i++){
				
				
				//flag is set here
				if(lastele-firstele>0){
					flag=true;
				}
				else if(lastele-firstele<0){
					flag=false;
				}
				else if(lastele-firstele==0){
					continue;
				}// flag logic completed
 
				//iteration till last element
				
				for(int j=i;j<N;j++){
					lastnext=sc.nextLong();
					if(flag){
						if(lastnext-lastele>=0){
							lastele=lastnext;
						}else{
							i=j;
							if(max < lastele-firstele){
								
								max=lastele-firstele;
							}
							firstele=lastele;
							lastele=lastnext;
							flag=false;
							break;
						}
					}else{
						if(lastnext-lastele<=0){
							lastele=lastnext;
						}else{
							i=j;
							if(max < firstele-lastele){
								
								max=firstele-lastele;
							}
							firstele=lastele;
							lastele=lastnext;
							flag=true;
							break;
						}
					}
					i=j;
				}//itereation till last ele completed
				
				//getting max point diff
				if(flag){
					if(max < lastele-firstele){
						max = lastele-firstele;
					}
				}else{
					if(max < firstele-lastele){
						
						max=firstele-lastele;
					}
				}//max point dirr completed
 
				lastele=lastnext;
			}
			System.out.println(max);
		}
	}
	
	static class Reader{
	    final private int BUFFER_SIZE = 1 << 16;
	    private DataInputStream din;
	    private byte[] buffer;
	    private int bufferPointer, bytesRead;
 
	    public Reader()
	    {
	        din = new DataInputStream(System.in);
	        buffer = new byte[BUFFER_SIZE];
	        bufferPointer = bytesRead = 0;
	    }
 
	    public Reader(String file_name) throws IOException
	    {
	        din = new DataInputStream(new FileInputStream(file_name));
	        buffer = new byte[BUFFER_SIZE];
	        bufferPointer = bytesRead = 0;
	    }
 
	    public String readLine() throws IOException
	    {
	        byte[] buf = new byte[64]; // line length
	        int cnt = 0, c;
	        while ((c = read()) != -1)
	        {
	            if (c == '\n')
	                break;
	            buf[cnt++] = (byte) c;
	        }
	        return new String(buf, 0, cnt);
	    }
 
	    public int nextInt() throws IOException
	    {
	        int ret = 0;
	        byte c = read();
	        while (c <= ' ')
	            c = read();
	        boolean neg = (c == '-');
	        if (neg)
	            c = read();
	        do
	        {
	            ret = ret * 10 + c - '0';
	        }  while ((c = read()) >= '0' && c <= '9');
 
	        if (neg)
	            return -ret;
	        return ret;
	    }
 
	    public long nextLong() throws IOException
	    {
	        long ret = 0;
	        byte c = read();
	        while (c <= ' ')
	            c = read();
	        boolean neg = (c == '-');
	        if (neg)
	            c = read();
	        do {
	            ret = ret * 10 + c - '0';
	        }
	        while ((c = read()) >= '0' && c <= '9');
	        if (neg)
	            return -ret;
	        return ret;
	    }
 
	    public double nextDouble() throws IOException
	    {
	        double ret = 0, div = 1;
	        byte c = read();
	        while (c <= ' ')
	            c = read();
	        boolean neg = (c == '-');
	        if (neg)
	            c = read();
 
	        do {
	            ret = ret * 10 + c - '0';
	        }
	        while ((c = read()) >= '0' && c <= '9');
 
	        if (c == '.')
	        {
	            while ((c = read()) >= '0' && c <= '9')
	            {
	                ret += (c - '0') / (div *= 10);
	            }
	        }
 
	        if (neg)
	            return -ret;
	        return ret;
	    }
 
	    private void fillBuffer() throws IOException
	    {
	        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
	        if (bytesRead == -1)
	            buffer[0] = -1;
	    }
 
	    private byte read() throws IOException
	    {
	        if (bufferPointer == bytesRead)
	            fillBuffer();
	        return buffer[bufferPointer++];
	    }
 
	    public void close() throws IOException
	    {
	        if (din == null)
	            return;
	        din.close();
	    }
	}
}

Java 8:
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
import java.io.*;
import java.util.*;
class TestClass {
    static class Reader {
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;
 
    public Reader() {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }
 
    public Reader(String file_name) throws IOException {
        din = new DataInputStream(new FileInputStream(file_name));
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }
 
    public String readLine() throws IOException {
        byte[] buf = new byte[64];
        int cnt = 0, c;
        while ((c = read()) != -1) {
            if (c == '\n') break;
            buf[cnt++] = (byte) c;
        }
        return new String(buf, 0, cnt);
    }
 
    public int nextInt() throws IOException {
        int ret = 0;
        byte c = read();
        while (c <= ' ') c = read();
        boolean neg = (c == '-');
        if (neg) c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (neg) return -ret;
        return ret;
    }
 
    public long nextLong() throws IOException {
        long ret = 0;
        byte c = read();
        while (c <= ' ') c = read();
        boolean neg = (c == '-');
        if (neg) c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (neg) return -ret;
        return ret;
    }
 
    public double nextDouble() throws IOException {
        double ret = 0, div = 1;
        byte c = read();
        while (c <= ' ') c = read();
        boolean neg = (c == '-');
        if (neg) c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (c == '.') while ((c = read()) >= '0' && c <= '9') ret += (c - '0') / (div *= 10);
        if (neg) return -ret;
        return ret;
    }
 
    private void fillBuffer() throws IOException {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1) buffer[0] = -1;
    }
 
    private byte read() throws IOException {
        if (bufferPointer == bytesRead) fillBuffer();
        return buffer[bufferPointer++];
    }
 
    public void close() throws IOException {
        if (din == null) return;
        din.close();
    }
}
    private static int mod_diff(int a, int b){
        if(a-b>=0) return a-b;
        else return b-a;
    }
    private static int maximum(int a, int b){
        if(a>=b) return a;
        else return b;
    }
    private static int index_sign(int a, int b){
       if(a>=b) return 1;
        else return 0;
    }
    public static void main(String args[] ) throws Exception {
        /* Sample code to perform I/O:
         * Use either of these methods for input
 
        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String name = br.readLine();                // Reading input from STDIN
        System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        //Scanner
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();                 // Reading input from STDIN
        System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        */
 
        // Write your code here
        Reader in = new Reader();
        int t, n,i,l,r,max_diff,temp_sign, sign;
        long[]a ;
        long diff;
        t = in.nextInt();
        while(t-->0){
            n = in.nextInt();
            a = new long[n];
            for(i=0;i<n;i++){
                a[i]= in.nextInt();
            }
            diff=r=l=0;
            while(l<n){
                while(r+1<n&&a[r+1]>=a[r])
                    r++;
                if(diff< a[r]-a[l])
                    diff= a[r]-a[l];
                if(r==n-1){
                    break;
                }
                else{
                    r++;
                    l=r;
                }
            }
            l=r=0;
            while(l<n){
                while(r+1<n&&a[r+1]<=a[r])
                    r++;
                if(diff< a[l]-a[r])
                    diff= a[l]-a[r];
                if(r==n-1){
                    break;
                }
                else{
                    r++;
                    l=r;
                }
            }
            System.out.println(diff);
        }
 
    }
}

JavaScript(Node.js):
function main(input) {
    //Enter your code here
    const inputArray = input.split('\n');
    let numOfTestCases = parseInt(inputArray[0], 10);
    let index = 1;
    while (numOfTestCases) {
        const numOfElements = parseInt(inputArray[index++], 10);
        const numbersArray = inputArray[index++].split(' ').map(Number);
        let decreasingOrderDiff, 
            increasingOrderDiff, 
            decreasingOrderStart = 0, 
            increasingOrderStart = 0,
            decreasingOrderDiffTemp,
            increasingOrderDiffTemp;
        for (let i=1; i < numOfElements; i++) {
            if (numbersArray[i] > numbersArray[i-1]) {
                decreasingOrderDiffTemp = Math.abs(numbersArray[i-1] - numbersArray[decreasingOrderStart]);
                decreasingOrderDiff = Math.max(decreasingOrderDiff, decreasingOrderDiffTemp) || decreasingOrderDiffTemp;
                decreasingOrderStart = i;
            }
            
            if (numbersArray[i] < numbersArray[i-1]) {
                increasingOrderDiffTemp = Math.abs(numbersArray[i-1] - numbersArray[increasingOrderStart]);
                increasingOrderDiff = Math.max(increasingOrderDiff, increasingOrderDiffTemp) || increasingOrderDiffTemp;
                increasingOrderStart = i;
            }
        }
        decreasingOrderDiffTemp = Math.abs(numbersArray[numOfElements-1] - numbersArray[decreasingOrderStart]);
        decreasingOrderDiff = Math.max(decreasingOrderDiff, decreasingOrderDiffTemp) || decreasingOrderDiffTemp;
        increasingOrderDiffTemp = Math.abs(numbersArray[numOfElements-1] - numbersArray[increasingOrderStart]);
        increasingOrderDiff = Math.max(increasingOrderDiff, increasingOrderDiffTemp) || increasingOrderDiffTemp;
        console.log(Math.max(increasingOrderDiff, decreasingOrderDiff));
        numOfTestCases--;
    }
}
 
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;
});
 
process.stdin.on("end", function () {
   main(stdin_input);
});


Python:
1).
for _ in range(input()):
    n = input()
    arr = map(int,raw_input().strip().split())
    index = 0
    ans = 0
    while index<n-1:
        temp = arr[index]
        while index<n-1 and arr[index]<=arr[index+1]:
            index+=1
        ans = max(ans,abs(temp-arr[index]))
        temp = arr[index]
        while index<n-1 and arr[index]>=arr[index+1]:
            index+=1
        ans = max(ans,abs(temp-arr[index]))
    print ans
2).
def points(a, i, n):
    d = 0
    l = i
    for j in xrange(i - 1, -1, -1):
        diff = a[j] - a[j + 1]
        if d > 0:
            if diff < 0:
                l = j + 1
                break
        elif d < 0:
            if diff > 0:
                l = j + 1
                break
        else:
            d = diff
        l = j
    d = 0
    u = i
    for j in xrange(i + 1, n):
        diff = a[j] - a[j - 1]
        if d > 0:
            if diff < 0:
                u = j - 1
                break
        elif d < 0:
            if diff > 0:
                u = j - 1
                break
        else:
            d = diff
        u = j
    return max(abs(a[u] - a[i]), abs(a[i] - a[l]))
 
def solve(a, n):
    best = 0
    for i in xrange(n):
        pi = points(a, i, n)
        if pi > best:
            best = pi
    return best
 
def solve2(a, n):
    l = n * [0]
    u = n * [0]
    u[n - 1] = n - 1
    iup = 0
    idn = 0
    for i in xrange(1, n):
        diff = a[i] - a[i - 1]
        if diff > 0:
            l[i] = iup
            idn = i
        elif diff < 0:
            l[i] = idn
            iup = i
        else:
            l[i] = min(idn, iup)
    iup = n - 1
    idn = n - 1
    for i in xrange(n - 2, -1, -1):
        diff = a[i + 1] - a[i]
        if diff > 0:
            l[i] = iup
            idn = i
        elif diff < 0:
            l[i] = idn
            iup = i
        else:
            l[i] = max(idn, iup)
    return max(max(abs(a[u[i]] - a[i]), abs(a[i] - a[l[i]])) for i in xrange(n))
 
def main():
    t = input()
    for _ in xrange(t):
        n = input()
        a = map(int, raw_input().split())
        print solve2(a, n)
 
main()

Python 3:
1).
for _ in range(int(input())):
    num = int(input())
    List = list(map(int, input().split()))
    diff,prev,diff = 0,0,0
    
    # increasing
    prev = i = List[0]
    for curr in List[1:]:
        if prev <= curr:
            diff = max(diff, curr-i)
        else:
            i = curr
        prev = curr
    
    # decreasing
    prev = i = List[0]
    for curr in List[1:]:
        if prev >= curr:
            diff = max(diff, i-curr)
        else:
            i = curr
        prev = curr
    print(diff)

2).
def main():
    T=int(input())
    for _ in range(T):
        N=int(input())
        arr=list(map(int,input().split()))
        ans=0
        old=arr[0]
        for i in range(N):
            if(arr[i]>=arr[i-1]):
                ans=max([ans,arr[i]-old])
            else:
                old=arr[i]
        old=arr[0]
        for i in range(N):
            if(arr[i]<=arr[i-1]):
                ans=max([ans,old-arr[i]])
            else:
                old=arr[i]
        arr=arr[-1::-1]
        for i in range(N):
            if(arr[i]>=arr[i-1]):
                ans=max([ans,arr[i]-old])
            else:
                old=arr[i]
        old=arr[0]
        for i in range(N):
            if(arr[i]<=arr[i-1]):
                ans=max([ans,old-arr[i]])
            else:
                old=arr[i]
        print(ans)
 
if __name__=='__main__':
    main()

*/
