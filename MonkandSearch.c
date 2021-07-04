/* All Tracks --> Algorithms --> Searching --> Binary Search --> Problem --> Monk and Search
Tag(s): Binary search algorithm, Easy, Searching algorithm
Monk and his friend Micro are on a quest to find the answer of Life, Universe and Everything. 
In order to complete it they need to answer Q queries on an array A having N integers. The queries can be of following two types:
0 x: Find the number of numbers in A which are not less than x.
1 x: Find the number of numbers in A which are greater than x.
Help them complete the quest and be back in time for the next Code Monk Challenge.

Input Format:
First line consists of a single integer denoting N.
Second line consists of N space separated integers denoting the array A.
Third line consists of a single integer denoting Q.
Each of the following Q lines consists of a query of one of the given two types.

Output Format:
For each query print the required answer in new line.

Constraints:
1<=N<=10^5
1<=Q<=3*(10^5)
1<=A[i],x<=10^9

SAMPLE INPUT 
4
1 2 3 4
3
0 5
1 3
0 3
SAMPLE OUTPUT 
0
1
2
Explanation
For first query, there are no numbers in the array which are not less than 5 so answer for first query is 0.
For second query, 4 is the only number greater than 3, so answer is 1.
For third query, 3 and 4 are the numbers in array which are not less than 3, so answer is 2.

//My C++ Solution:
#include <bits/stdc++.h>
#define pi(x) printf("%d\n",x)
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int ch,x;
        scanf("%d %d",&ch,&x);
        if(ch==0)
        {
            int low=0,high=n;
            while(high>low)
            {
                int mid=(low+high)/2;
                if(a[mid]<x)
                    low=mid+1;
                else
                    high=mid;
            }
            pi(n-low);

        }
        else
        {
            int ub=upper_bound(a,a+n,x)-a;
            printf("%d\n",n-ub);
        }
    }
    return 0;
}

*/

/*Editorial:
Author: vaibhav_jaimini
Tester: shubham1428
Editorialist: shubham1428

Brief Description: Given an array A, we have two types of queries :
1. In first query, we need to find count of numbers not less than x (or >=x )
2. In second query, we need to find count of numbers greater than x.

Prerequisite: Binary Search
Difficulty: Easy-Medium

Detailed Explanation:
First we need to sort the array.
Finding the index of first element in A which is not less than x is called lower_bound query in C++ STL. The answer of our first query is n-lower_bound(x)
Similarly, finding the index of first element in A which is greater than x is called upper_bound query in C++ STL. The answer of our second query is n-upper_bound(x).
So, the question is how to find these bounds?
Let's see how to find lower_bound in the given array for element x.

In our binary search loop:
1. If a[mid]>=x, we know our answer would not exceed x, so we do end=mid.
2. If a[mid]< x , we do start=mid+1.
And at last start will be the index we require.

Similarly, we can find upper_bound.

Pseudo Code:

int lower_bound(int start,int end,int item)
{
    while(start<end)
    {
        int mid=(start+end)>>1;
        if(arr[mid]>=item)
            end=mid;
        else start=mid+1;
    }
    return start;
}
int upper_bound(int start,int end,int item)
{
    while(start<end)
    {
        int mid=(start+end)>>1;
        if(arr[mid]<=item)
            start=mid+1;
        else end=mid;
    }
    return start;   
}
Time Complexity: O(Q*log(N)); N is the length of input array.
Space Complexity: O(N)

Author Solution by Vaibhav Jaimini
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int a[100100];
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1, a+1+n);
	int q;cin>>q;
	while(q--){
		int type;
		int x;
		cin>>type>>x;
		if(!type)cout<<(n-((int)(lower_bound(a+1, a+n+1, x)-a-1)))<<endl;
		else cout<<(n-((int)(upper_bound(a+1, a+n+1, x)-a-1)))<<endl;
	}
	return 0;
}
Tester Solution by Shubham Gupta
#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int lower_bound(int start,int end,int item)
{
	while(start<end)
	{
		int mid=(start+end)>>1;
		if(arr[mid]>=item)
			end=mid;
		else start=mid+1;
	}
	return start;
}
int upper_bound(int start,int end,int item)
{
	while(start<end)
	{
		int mid=(start+end)>>1;
		if(arr[mid]<=item)
			start=mid+1;
		else end=mid;
	}
	return start;	
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	int q;
	cin>>q;
	sort(arr,arr+n);
	while(q--)
	{
		bool type;
		int x;
		cin>>type>>x;
		if(type)cout<<n-upper_bound(0,n,x)<<"\n";
		else cout<<n-lower_bound(0,n,x)<<"\n";
	}
	return 0;
}

*/


/* Best Submissions:
C:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define pcx putchar_unlocked
#define gcx getchar_unlocked
typedef long int lint;
 
inline lint getli () {
	lint n =0;
	int c = gcx();
	while(c<'0' || c>'9') c = gcx();
	while(c>='0' && c<='9') {
		n = n * 10 + c-'0';
		c = gcx();
	} return n;
}
inline void putli (lint n, char lc) {
	if (0 == n) {
		pcx('0'); if(lc) pcx(lc); return;
	}
	char s[24]; lint rdi =-1;
	while (n) {
		s[++rdi] = '0' + n % 10;
		n /= 10;
	}
	while (rdi>=0) pcx(s[rdi--]);
	if(lc) pcx(lc);
}
typedef struct {
    int num;
    int cnt;
} NumT;
int cmp(const void *p, const void *q) {
    return (((NumT*)p)->num < ((NumT*)q)->num);
}
lint bsGTcnt (NumT a[], lint l, lint r, lint x) { //1-indexed
    if (x > a[l].num) return 0;
    else if (x < a[r].num) return a[r].cnt;
	while (l <= r) {
		lint m = (r+l)/2;
		if (a[m].num > x && a[m+1].num <= x) return a[m].cnt;
		if (a[m].num > x) l = m + 1;
		else r = m - 1;
	}
	return 0;
}
lint bsGEcnt (NumT a[], lint l, lint r, lint x) { //1-indexed
    if (x >= a[l].num)
        return (x > a[l].num) ? 0 : a[l].cnt;
    else if (x <= a[r].num) return a[r].cnt;
	while (l <= r) {
		lint m = (r+l)/2;
		if (a[m].num >= x && a[m+1].num < x) return a[m].cnt;
		if (a[m].num > x) l = m + 1;
		else r = m - 1;
	}
}
int main () {
    lint N = getli() +1;
    NumT NA[N+1];
    NA[0].num = INT_MAX; NA[0].cnt =0;
    NA[N].num = 0; NA[0].cnt =0;
    
    for (lint ni=1; ni<N; ) { 
        NA[ni].num = getli(); NA[ni++].cnt =1;
    }
    qsort (NA, N, sizeof(NumT), cmp);
    
    lint tail =0;
    for (lint head=1; head<N; ++head) {
        if (NA[tail].num != NA[head].num) {
            if (++tail != head) {
                NA[tail].num = NA[head].num;
                //NA[tail].cnt =1; // already set
            } 
        } else ++NA[tail].cnt;
    } N = tail;
    for (lint ni=1; ni<=N; ++ni) NA[ni].cnt += NA[ni-1].cnt;
    //for (lint ni=0; ni<=N; ++ni)
    //  printf("%d:%d ",NA[ni].num,NA[ni].cnt); pcx('\n');
    
    lint Q = getli() +1;
    while (--Q) {
        if (getli()) { // # > X
            putli (bsGTcnt (NA, 1, N, getli()), '\n');
        } else { // # >= X
            putli (bsGEcnt (NA, 1, N, getli()), '\n');
        }
    }
	return 0;
}

Alt. Soln:
#include<stdio.h>
void sort(long l, long h, long long a[], long long b[])
{
    if(l<h)
    {
        long m=(l+h)/2;
        sort(l, m, a, b);
        sort(m+1, h, a, b);
        merge(l, m, h, a, b);
    }
}
void merge(long l, long m, long h, long long a[], long long b[])
{
    long i=l, j=m+1, k=l;
    
    while(k<=h)
    {
        if(i<=m && j<=h)
        {
            if(a[i]<=a[j])
            {
                b[k]=a[i];
                k++;
                i++;
            }
            else
            {
                b[k]=a[j];
                k++;
                j++;
            }
        }
        else if(i>m)
        {
            b[k]=a[j];
            k++;
            j++;
        }
        else
        {
            b[k]=a[i];
            k++;
            i++;
        }
    }
    for(i=l; i<=h; i++)
    {
        a[i]=b[i];
    }
}
void bs(long long a[], long l, long h, long long x, long n)
{
    if(l<=h)
    {
        long m=(l+h)/2;
        if(a[m]>=x)
        {
            if(a[m-1]<x)
            printf("%ld\n", n-m);
            else
            bs(a, l, m-1, x, n);
        }
        else
        {
            bs(a, m+1, h, x, n);
        }
    }
}
void bs1(long long a[], long l, long h, long long x, long n)
{
    if(l<=h)
    {
        long m=(l+h)/2;
        if(a[m]>x)
        {
            if(a[m-1]<=x)
            printf("%ld\n", n-m);
            else
            bs1(a, l, m-1, x, n);
        }
        else
        {
            bs1(a, m+1, h, x, n);
        }
    }
}
int main()
{
    long n, q, i, j;
    scanf("%ld", &n);
    
    long long a[n], b[n], x;
    
    for(i=0; i<n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(0, n-1, a, b);
    
    scanf("%ld", &q);
    
    for(;q--;)
    {
        scanf("%ld %lld", &i, &x);
        
        if(i==0)
        {
            if(a[0]>=x)
            printf("%ld\n", n);
            else if(a[n-1]<x)
            printf("0\n");
            else
            bs(a, 0, n-1, x, n);
        }
        else
        {
            if(a[0]>x)
            printf("%ld\n", n);
            else if(a[n-1]<=x)
            printf("0\n");
            else
            bs1(a, 0, n-1, x, n);
        }
    }
}
C++:
#include<bits/stdc++.h>
using namespace std;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define mod 1000000007
#define ll long long
//const ll mod=1000000007;
#define vi vector<int>
#define pi pair<int,int>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define fills(x,y) memset(x,y,sizeof x)
#define rep(i,n) for(i=0;i<n;++i)
#define REP(i,k,n) for(i=k;i<=n;++i)
#define tr(i,c) for(auto &i:c)
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define inchar          getchar
#define outchar(x)      putchar(x)
#define bitcount(n) __builtin_popcountll(n)
#define sz(a) int((a).size())
//static const int inf = INT_MAX;static const long long infl = LONG_MAX;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }
template<typename T> void scan(T &x){x=0;register T c=inchar();while((c<48)||(c>57))c=inchar();\
for(;c<48||c>57;c=inchar());for(;c>47&&c<58;c=inchar())x=(x<<3)+(x<<1)+(c&15);}
template<typename T> void output(T n){char snum[65];int i=0;do {snum[i++]=n%10+'0';n/=10;}\
while(n);i=i-1;while(i>=0)outchar(snum[i--]);outchar('\n');}
inline void instr(char *str){register char c=0;register int i=0;while(c<33)c=inchar();while (c!='\n'&&c!=' '&&c!=EOF){\
str[i]=c;c=inchar();++i;}str[i]='\0';}
template<typename T> T lcm(T a, T b){return (a*(b/__gcd(a,b)));}
template<typename T> T MOD(T a, T b) {return (a<b ? a : a%b);}
template<typename T> T add(T a, T b, T c){T x=a+b;return (x>=c ? x-c : x);}
template<typename T> T mod_neg(T a, T b) {a=MOD(a, b);if(a<0){a+=b;}return a;}
template<typename T> T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T> T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=MOD(x*p,m);p=MOD(p*p,m);n>>=1;}return x;}
template<typename T> T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;\
xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T> T mod_inverse(T a, T n){T x,y;T d = extended_euclid(a, n, x, y);return (d>1?-1:mod_neg(x,n));}
#define tcsolve() int tcs; scan(tcs); while(tcs--) solve();
 
int binary(int n,int arr[],int len)
{
    int i=0,mid,sz=len;
    while(i<=sz)
    {   mid=(i+sz)/2;
        //trace(mid);
        if((arr[mid]==n and arr[mid-1]!=n) or (n>arr[mid-1] and n<arr[mid]))
        {   //trace(mid);
            return mid;
        }
        if(arr[mid]>=n)
            sz=mid-1;
        else
            i=mid+1;
    }
    return -1;
}
void solve()
{
int n,i,j,sum=0,ans,q,x,num;
scan(n);
int arr[n+2];
REP(i,1,n)
{
    scan(arr[i]);
}
arr[0]=0;
sort(arr,arr+n+1);
scan(q);
while(q--)
{
    scan(x),scan(num);
 
    if(!x)
       {
       ans=binary(num,arr,n);}
    else {
        ans=binary(num+1,arr,n);
    }
    if(~ans)
    printf("%d\n",n-ans+1);//,trace(ans);
    else puts("0");
}
}
main()
{
#ifndef ONLINE_JUDGE
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
#endif
solve();
}

C++14:
#include<bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ull unsigned long long
 
int binarySearch(vector<unsigned long> arr, int l, int r, unsigned long x)
{
   if (l >= r)
   {
        int mid = l + (r - l)/2;
 
        if (arr[mid] <= x)  
            l = mid + 1;
        
        else
            r = mid;
        
        return binarySearch(arr, l, r, x);
   }
 
    return l;
}
 
 
int main()
{
    SPEED;
    unsigned long x,n;
    unsigned int q;
    char c;
    cin>>n;
    vector<unsigned long> arr(n);
    for(unsigned int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cin>>q;
    while(q--)
    {
        int i = 0;
        cin>>c>>x;
        if(c == '0')
            cout<<n - (lower_bound(arr.begin(),arr.end(),x) - arr.begin())<<"\n";
        else
            cout<<n - (upper_bound(arr.begin(),arr.end(),x) - arr.begin())<<"\n";
        
 
    }
    return 0;
}

C#:
#define MANUAL_SCAN_FOR_EOL
 
#if !LINQPAD
using System;
using System.IO;
using System.Text;
#endif
 
class MonkAndSearch_v3
{
	static void Main ()
	{
		using (var sw = new StreamWriter(Console.OpenStandardOutput(), Encoding.ASCII, 1 << 20))
		{
			CCR.SetStream(Console.OpenStandardInput(), true);
 
			var n = int.Parse(CCR.ReadLine().Trim());
			var a = new int[n];
 
			if (CCR.ReadVector(a) != n)
				throw new Exception("CCR.ReadVector(a) != n");
	
			Array.Sort(a);
	
			var p = new int[2];
 
			for (var q = int.Parse(CCR.ReadLine().Trim()); q-- > 0; )
			{
				if (CCR.ReadVector(p) != 2)
					throw new Exception("CCR.ReadVector(p) != 2");
 
				var d = p[0];
				var x = p[1];
				var i = lower_bound(a, 0, n, x + d);
	
				sw.WriteLine(n - i);
			}
		}
	}
 
	static int lower_bound (int[] values, int lo, int hi, int key)
	{
	    while (lo < hi)
	    {
	        int pivot = (lo + hi) / 2;
	
	        if (values[pivot] < key)
	            lo = pivot + 1;
	        else
	            hi = pivot;
	    }
	
	    return lo;
	}
}
 
static class CCR
{
	const byte ASC_HT = 0x09, ASC_LF = 0x0A, ASC_CR = 0x0D, ASC_SP = 0x20;
	const byte ASC_0 = (byte)'0', ASC_9 = (byte)'9';
 
	internal static Stream m_stream;
	internal static bool m_destroy_stream;
	internal static int m_sentinels = 1;
#if DEBUG_TINY_BUFFERS
	internal static byte[] m_buffer = new byte[TINY_BUFFER + m_sentinels + 1];
#else
	internal static byte[] m_buffer = new byte[(1 << 15) + m_sentinels + 1];
#endif
	internal static int m_buffered = 0;
	internal static int m_tail_pos = 0;
	internal static int m_crlf_pos = 0;
	internal static int m_read_pos = 0;
 
	public static void SetStream (Stream stream, bool take_ownership = false)
	{
		if (m_destroy_stream && m_stream != null)
			m_stream.Dispose();
 
		m_buffered = m_tail_pos = m_crlf_pos = m_read_pos = 0;
		m_stream = stream;
		m_destroy_stream = take_ownership;
	}
 
	public static void Assign (string filename)
	{
		SetStream(null);
		SetStream(new FileStream(filename, FileMode.Open, FileAccess.Read, FileShare.Read), true);
	}
 
	internal static int refill ()
	{
		if ((m_buffered -= m_read_pos) > 0)
			Buffer.BlockCopy(m_buffer, m_read_pos, m_buffer, 0, m_buffered);
 
		int bytes_req = m_buffer.Length - 1 - m_sentinels - m_buffered;
 
		if (bytes_req == 0)
			Array.Resize(ref m_buffer, m_buffer.Length + (bytes_req = m_buffer.Length));
 
		int bytes_got = m_stream.Read(m_buffer, m_buffered, bytes_req);
 
		m_buffered += bytes_got;
		m_tail_pos = m_crlf_pos = m_read_pos = 0;
 
		for (int i = 0; i < m_sentinels; ++i)
			m_buffer[m_buffered + i] = ASC_LF;
 
//		for (int i = m_buffered + m_sentinels; i < m_buffer.Length; ++i)
//			m_buffer[i] = 0;
 
		return bytes_got;
	}
 
	internal static bool buffer_next_line ()
	{
		int h = m_tail_pos = m_crlf_pos = m_read_pos;
 
		for ( ; ; )
		{
			if (h < m_buffered)
			{
#if MANUAL_SCAN_FOR_EOL
				// 1629 + 2392 on NILBOG (1k*1M + 1M*1k)
				for (var b = m_buffer; b[h] != ASC_LF; )
					++h;
#else
				// 1361 + 2059 on NILBOG
				h = Array.IndexOf(m_buffer, ASC_LF, h);
#endif
				if (h < m_buffered)
				{
					m_read_pos = h + 1;
					break;
				}
			}
 
			h -= m_read_pos;
 
			if (refill() < 1)  // postcondition: m_read_pos = 0
				if ((m_read_pos = m_buffered) == 0)
					return false;
				else
					break;
		}
 
		while (h > m_tail_pos && m_buffer[h - 1] == ASC_CR)
			--h;
 
		m_crlf_pos = h;
 
		return true;
	}
 
	public static string ReadLine ()
	{
		if (buffer_next_line())
			return Encoding.ASCII.GetString(m_buffer, m_tail_pos, m_crlf_pos - m_tail_pos);
 
		return null;
	}
 
	public static int ReadVector (int[] result)
	{
		if (!buffer_next_line())
			return 0;
 
		var b = m_buffer;
		int h = m_tail_pos;
		int n = 0;
 
		for (byte c = b[h++]; ; c += ASC_0)
		{
			while (c == ASC_SP || c == ASC_HT)
				c = b[h++];
 
			if ((c -= ASC_0) >= 10)
				if ((c += ASC_0) == ASC_CR || c == ASC_LF)
					return n;
				else
					throw new Exception("CCR::ReadVector<I32>(): invalid input");
 
			int v = c;
 
			for ( ; (c = (byte)(b[h++] - ASC_0)) < 10; )
				v = v * 10 + c;
 
			result[n++] = v;
		}
	}
}

Java:
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
 
public class Main {
    private static InputReader in = new InputReader();
    private static PrintWriter out = new PrintWriter(System.out);
    private static StringBuilder sb = new StringBuilder();
    private static int N, Q;
    private static int arr[];
 
    public static void main(String args[]) throws Exception {
        N = in.nextInt();
        arr = in.nextIntArray(N);
        Q = in.nextInt();
        Arrays.sort(arr);
 
        while (Q-- > 0) {
            int cmd = in.nextInt(), x = in.nextInt();
            sb.append(cmd == 0 ? N - lowestBound(x) : N - upperBound(x)).append("\n");
        }
 
        out.print(sb);
        out.close();
    }
 
    private static int upperBound(int x) {
        int l = 0, r = N;
        while (l < r) {
            int m = (l + r) >> 1;
            if (arr[m] <= x) l = m + 1;
            else r = m;
        }
        return l;
    }
 
    private static int lowestBound(int x) {
        int l = 0, r = N;
        while (l < r) {
            int m = (l + r) >> 1;
            if (arr[m] < x) l = m + 1;
            else r = m;
        }
        return l;
    }
 
    static class InputReader {
        private int lenbuf = 0, ptrbuf = 0;
        private InputStream in;
        private byte[] inbuf = new byte[1024];
 
        InputReader() {
            in = System.in;
        }
 
        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = in.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }
 
        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }
 
        private int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b)) ;
            return b;
        }
 
        int nextInt() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
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
 
        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }
    }
}


Java 8:
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
 
public class Main {
    private static InputReader in = new InputReader();
    private static PrintWriter out = new PrintWriter(System.out);
    private static StringBuilder sb = new StringBuilder();
    private static int N, Q;
    private static int arr[];
 
    public static void main(String args[]) throws Exception {
        N = in.nextInt();
        arr = in.nextIntArray(N);
        Q = in.nextInt();
        Arrays.sort(arr);
 
        while (Q-- > 0) {
            int cmd = in.nextInt(), x = in.nextInt();
            sb.append(cmd == 0 ? N - lowestBound(x) : N - upperBound(x)).append("\n");
        }
 
        out.print(sb);
        out.close();
    }
 
    private static int upperBound(int x) {
        int l = 0, r = N;
        while (l < r) {
            int m = (l + r) >> 1;
            if (arr[m] <= x) l = m + 1;
            else r = m;
        }
        return l;
    }
 
    private static int lowestBound(int x) {
        int l = 0, r = N;
        while (l < r) {
            int m = (l + r) >> 1;
            if (arr[m] < x) l = m + 1;
            else r = m;
        }
        return l;
    }
 
    static class InputReader {
        private int lenbuf = 0, ptrbuf = 0;
        private InputStream in;
        private byte[] inbuf = new byte[1024];
 
        InputReader() {
            in = System.in;
        }
 
        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = in.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }
 
        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }
 
        private int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b)) ;
            return b;
        }
 
        int nextInt() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
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
 
        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }
    }
}


Java(Node.js):
"use strict";
 
function main(lines) {
    const array = lines[1].split(' ').map(Number).sort((a, b) => b - a);
    const last = array.length - 1;
    
    let data, index;
    for(let i = 3, l = lines.length; i < l; i++) {
        data = lines[i].split(' ').map(Number);
        index = search(array, data[1], 0, last);
        
        if(array[index] === data[1]) {
        	if(data[0] === 0) {
				while(array[++index] === data[1]) {
				}
				
				console.log(index);
			}
			else {
				while(array[--index] === data[1]) {
				}
				
				console.log(index + 1);
			}
        }
        else if(array[index] < data[1]) {
            console.log(index);
        }
        else if(array[index] > data[1]) {
            console.log(index + 1);
        }
    }
}
 
function search(values, target, a, b) {
    let m;
    
    if(values[a] <= target) {
        return a;
    }
    else if(values[b] >= target) {
        return b;
    }
    
    while(a <= b) {
        m = Math.floor((a + b) / 2);
        
        if(values[m] === target) {
            return m;
        }
        else if(values[m] > target) {
            a = m + 1;
        }
        else {
            b = m - 1;
        }
    }
    
    return a;
}
 
process.stdin.resume();
process.stdin.setEncoding('utf-8');
let stdin_input = '';
 
process.stdin.on('data', function(input) {
    stdin_input += input;
});
 
process.stdin.on('end', function() {
    main(stdin_input.split(/\n/g));
});


Python:
from bisect import bisect
 
if __name__ == '__main__':
    N = input()
    A = sorted(map(int, raw_input().split()))
    for __ in xrange(input()):
        q, B = map(int, raw_input().split())
        if q == 0:
            # print number of numbers in Array >= x
            ind = bisect(A, B - 1)
 
        else:
            # print number of numbers in Array greater than x
            ind = bisect(A, B)
        print N - ind

Python 3:
from bisect import bisect
from sys import stdin,stdout
n=int(stdin.readline())
l=list([int(z) for z in stdin.readline().split()])
l.sort()
q=int(stdin.readline())
#print(n,l)
while q:
    val,num=[int(z) for z in stdin.readline().split()]
    
    if val==0:
        stdout.write(str(n-bisect(l,num-1))+'\n')
    else:
        stdout.write(str(n-bisect(l,num))+'\n')
    
    q-=1

Ruby:
# predicate ->(x) { if arr[x] >= val }
def search_gt(arr,val)
  st = 0
  en = @n - 1
  while st < en
    mid = (st + (en - st) / 2)
    if arr[mid] > val
      en = mid
    else
      st = mid + 1
    end
  end
  if arr[st] > val
    return @n - st
  else
    return 0
  end
end
def search_gte(arr, val)
  st = 0
  en = @n - 1
  while st < en
    mid = (st + (en - st) / 2)
    if arr[mid] >= val
      en = mid
    else
      st = mid + 1
    end
  end
  if arr[st] >= val
    return @n - st
  else
    return 0
  end
end
 
@n = gets.chomp.to_i
arr = gets.chomp.split.map(&:to_i).sort
t = gets.chomp.to_i
t.times do
  choice, val = gets.chomp.split.map(&:to_i)
  puts choice == 0 ? search_gte(arr,val) : search_gt(arr,val)
end

*/