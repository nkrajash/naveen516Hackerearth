/*All Tracks -->  Data Structures --> Hash Tables --> Basics of Hash Tables -->  Problem
Easy one
Aurora is the Annual Cultural Festival of IIITM Gwalior which also happens to be Central India's largest Cultural Festival...!.
This year the promotion team of Aurora is distributing free passes for the fest if one can successfully answer the following question :

Given an array 'A' of 'N' non-negative integers and 'Q' queries. 
Each query consist of a single integer 'X', you have to simply tell the no. of occurrences of integer 'X' in the given array 'A'.

Input :
First line consists of an integer 'T' i.e. the no. of test cases.
First line of each test case consists of two space separated integers 'N' and 'Q' i.e. the no. of elements in the array and no. of queries.
Next line contains 'N' space separated non-negative integers.
Following 'Q' lines contains a single non-negative integer 'X'.

Output :
For each query output the no. of occurrences of 'X' in the given array.

Constraints :
1<=T<=10
1<=N<=10^5
1<=Q<=10^5
0<=array element Ai<=10^9
0<=X<=10^9

SAMPLE INPUT 
1
5 3
5 8 1 4 5
1
5
3

SAMPLE OUTPUT 
1
2
0

Explanation:
Self Explanatory.

//My C Solution:
#include <stdio.h>
#include <stdlib.h>
#define LEN 100001
#define ll long long int

typedef struct {
    ll n;
    ll c;
} strA;

ll binarySearch(strA arr[], ll l, ll r, ll x);
int compare(const void * a, const void * b);

ll main(){
    strA A[LEN];
    ll N,t,Q,X,i,j,num,cnt,head,tail;
    scanf("%lld",&t);
    for(i=0;i<t;i++){
        scanf("%lld%lld",&N,&Q);
        for(j=0;j<N;j++){
            scanf("%lld",&num);
            A[j].n=num;
        }
        qsort(A, N, sizeof(strA), compare);
        cnt = 1;
        tail=0;
        for (head=1; head<N; ++head) {
            if (A[tail].n ==A[head].n){
                ++cnt;
            }
            else {
                A[tail++].c = cnt;
                cnt=1;
                A[tail].n = A[head].n;
            }
        }
        A[tail].c = cnt;
        N= tail;
        for(j=0;j<Q;j++){
            scanf("%lld",&X);
            cnt = binarySearch(A, 0, N, X); 
            printf("%lld\n",cnt);
        }
    }
    return 0;
}


int compare(const void * a, const void * b) 
{ 
    return ( *(ll *)a - *(ll *)b ); 
}

ll binarySearch(strA arr[], ll l, ll r, ll x) 
{
    ll mid;
    while(l<=r){
        mid = l + (r - l) / 2; 
        if (arr[mid].n == x) 
            return arr[mid].c;
        else if (arr[mid].n > x)
            r = mid -1;
        else
            l = mid +1;
    }
    return 0;
}


//My Python 3 Solution
from collections import Counter

t = int(input())
for _ in range(t):
    n,q = map(int,input().split())
    arr = list(map(int,input().split()))
    d = Counter(arr)
    for _ in range(q):
        temp = int(input())
        print(d[temp])

*/

/*Best Submissions:
C:
#include <stdio.h>
#include <stdlib.h>
#define pcx putchar_unlocked
#define gcx getchar_unlocked
typedef long int lint;
typedef struct {
    int n;
    int c;
} fInt_t;
 
lint getl () { //Positive
	lint n =0;
	register int c = gcx();
	while(c<'0' || c>'9') c = gcx();
	while(c>='0' && c<='9') {
		n = n * 10 + c-'0';
		c = gcx();
	}
	return n;
}
void putl (lint li, char lc) {//Positive
	if (0 == li) {
		pcx('0'); if(lc) pcx(lc); return;
	}
	char s[24]; auto idx =-1;
	while (li) {
		s[++idx] = '0' + li % 10;
		li /= 10;
	}
	for (auto jdx=idx; jdx>=0; --jdx) pcx(s[jdx]);
	if(lc) pcx(lc);
}
int cmp(const void *p, const void *q) { //ASC Order
	return ((*(const fInt_t*)p).n > (*(const fInt_t*)q).n );
}
lint bSearch(fInt_t na[], lint l, lint r, lint x) {
	while (l <= r) {
		lint m = (l+r)/2;
		if (na[m].n == x) return na[m].c;
		if (na[m].n < x) l = m + 1;
		else r = m - 1;
	}
	return 0;
}
int main () {
	lint T = getl() +1;
    fInt_t *NA = (fInt_t *) malloc(100000 * sizeof(fInt_t));
	while(--T) {
        lint N = getl();
        lint Q = getl() +1;
        for (lint ni=0; ni<N; ++ni) {
            NA[ni].n = (int) getl(); 
        }
        qsort (NA, N, sizeof(fInt_t), cmp);
        lint tail =0, nCnt=1;
        for (lint head=1; head<N; ++head) {
            if (NA[tail].n ==NA[head].n) ++nCnt;
            else {
                NA[tail++].c = nCnt; nCnt=1;
                NA[tail].n = NA[head].n;
            }
        } NA[tail].c = nCnt;
        N = tail;
        while (--Q) {
            putl(bSearch(NA, 0, N, getl()), '\n');
        }
	}
	return 0;
}

C++:
1).
#include<iostream>
#include<unordered_map>
using namespace std;
#include<cstring>
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);
void fastscan(int &x)
{register int c=gc();x=0;
 for(;c<48||c>57;c=gc());
 for(;c>47&&c<58;c=gc())
 {x=(x<<1) +(x<<3)+c-48;}
}
 
int main()
{ios_base::sync_with_stdio(0);
    int t;
 fastscan(t);
 while(t--)
 {int n,q;
  fastscan(n);fastscan(q);
  unordered_map<int,int>mp;
  for(int i=0;i<n;++i)
  {int x;
   fastscan(x);
   if(mp.count(x)==0)
   {mp[x]=0;}
   mp[x]++;
  }
  for(int i=0;i<q;++i)
  {int x;
   fastscan(x);
   if(mp.count(x)==0)
   {cout<<0<<"\n";}
   else
   {cout<<mp[x]<<"\n";}
  }
 }
}

2).
#include<iostream>
#include<map>
#include<cstdio>
typedef long long ll;
using namespace std;
void fastscan(ll &number)
{bool negative = false;
 register int c;
 number = 0;
 c = getchar();
 if (c=='-')
 {negative = true;
  c = getchar();
 }
 for (; (c>47 && c<58); c=getchar())
 number = number *10 + c - 48;
 if (negative)
 number *= -1;
}
int main()
{ll t,x,n,q,i,a;
 map <ll,ll> m;
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
 cin>>t;
 for(x=0;x<t;++x)
 {cin>>n>>q;
  for(i=0;i<n;++i)
  {cin>>a;
   if(m.find(a)==m.end())
   m.insert(make_pair(a,1));
   else
   m[a]++;
  }
  for(i=0;i<q;++i)
  {cin>>a;
   if(m.find(a)==m.end())
   cout<<'0';
   else
   cout<<m[a];
   cout<<"\n";
  }
  m.clear();
 }
 return 0;
}

3).
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(false);
    int t;
    long int max=0;
    cin>>t;
    while(t--)
    {
        map<long int,int>M;
        int n,q;long int a;
        
        cin>>n>>q;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            M[a]++;
        }
        while(q--)
        {
            cin>>a;
            cout<<M[a]<<"\n";
        }
    }
    return 0;
}

4).
#include<bits/stdc++.h>
#include<map>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace  std;
 
int main()
{    fast;
    int t;
    cin>>t;
    while (t--)
    {
        long int q,n,data;unordered_map<long int,long int> m;
        cin>>n>>q;
        while(n--)
        {cin>>data; m[data]++;
            
        }
        while(q--)
        {  long int query;
            cin>>query;
            cout<<m[query]<<"\n";
        }
    }
    return 0;
}

5).
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t,q,n,i;
    scanf("%d",&t);
    long int temp;
    map <long int,int> m;
    while(t--)
    {
        m.clear();
        scanf("%d%d",&n,&q);
        for(i=0;i<n;i++)
        {
            scanf("%ld",&temp);
            m[temp]++;
        }
        while(q--)
        {
            scanf("%ld",&temp);
            printf("%d\n",m[temp]);
        }
    }
    return 0;
}

C++14:
1).
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
     
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q,i,k;
        cin>>n>>q;
        map<ll, ll> m;
        for(i=0;i<n;i++)
        {
            map<ll, ll>::iterator it;
            cin>>k;
            it=m.find(k);
            if(it!=m.end())
            {
                (*it).second=(*it).second +1;
            }
            else
            {
                m.insert(pair<ll, ll>(k,1));
            }
        }
        while(q--)
        {
            cin>>k;
            map<ll, ll>::iterator itr;
            itr=m.find(k);
            if(itr!=m.end())
            cout<<(*itr).second<<"\n";
            else
            cout<<"0"<<"\n";
        }
    }
return 0;
}
2).
#include <bits/stdc++.h>
using namespace std ;
typedef long double ld ;
typedef long long int ll ;
#define tez ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
#define be begin()
#define en end()
#define fi first
#define se second
#define mp make_pair
#define t() ll t; cin>>t; while(t--)
#define all(a) a.be,a.en
#define rall(a) a.rbegin(),a.rend()
#define lob lower_bound
#define upb upper_bound
#define inp(a,n) for(ll i=0 ; i<n ; i++){ll j; cin>>j; a.pub(j);}
#define pub(a) push_back(a)
#define pob() pop_back()
#define vll vector <ll>
#define pll pair<ll,ll>
#define mll map <ll,ll>
#define in insert
#define sz size()
#define bsrch(a,x) binary_search(all(a),x)
#define srt(a) sort(all(a))
#define mst(a,x) memset(a,x,sizeof(a))
int main()
{
    tez
    t()
    {
        ll n,q ;
        cin>>n>>q ;
        mll m ;
        for(ll i=0 ; i<n ; i++)
        {
            ll j ;
            cin>>j ;
            m[j]++ ;
        }
        while(q--)
        {
            ll x ;
            cin>>x ;
            cout<<m[x]<<'\n' ;
        }
    }
    return 0;
}

3).
#include <bits/stdc++.h>
using namespace std ;
typedef long double ld ;
typedef long long int ll ;
#define tez ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
#define be begin()
#define en end()
#define fi first
#define se second
#define mp make_pair
#define t() ll t; cin>>t; while(t--)
#define all(a) a.be,a.en
#define rall(a) a.rbegin(),a.rend()
#define lob lower_bound
#define upb upper_bound
#define inp(a,n) for(ll i=0 ; i<n ; i++){ll j; cin>>j; a.pub(j);}
#define pub(a) push_back(a)
#define pob() pop_back()
#define vll vector <ll>
#define pll pair<ll,ll>
#define mll map <ll,ll>
#define in insert
#define sz size()
#define bsrch(a,x) binary_search(all(a),x)
#define srt(a) sort(all(a))
#define mst(a,x) memset(a,x,sizeof(a))
int main()
{
    tez
    t()
    {
        ll n,q ;
        cin>>n>>q ;
        unordered_map<ll,ll> m ;
        for(ll i=0 ; i<n ; i++)
        {
            ll j ;
            cin>>j ;
            m[j]++ ;
        }
        while(q--)
        {
            ll x ;
            cin>>x ;
            cout<<m[x]<<'\n' ;
        }
    }
    return 0;
}

4).
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(--t>=0)
    {
        long n,q;
        cin>>n>>q;
        unordered_map<long,long>m;
        for(long i=0;i<n;i++)
        {
            long temp;
            cin>>temp;
            m[temp]++;
        }
        while(--q>=0)
        {
            long qe;
            cin>>qe;
           // if(m.find(qe)==m.end())
            //cout<<"0\n";
            //else
            cout<<m[qe]<<"\n";
        }
    }
}

5).
#include<bits/stdc++.h>
using namespace std;
#include<map>
int main(){
      int t,n,q;
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      long m,query;
    cin>>t;
    while(t--){
        cin>>n>>q;
          map<long,long> hash;
        while(--n>=0){ 
      
            cin>>m;
            hash[m]++;
        }
        while(--q>=0){ cin>>query;
            cout<<hash[query]<<"\n";
        }
    }
    return 0;
}

Java:
1).
import java.io.*;
import java.util.*;  
import java.lang.*;
class EasyOne
{   
    public static void main(String args[])throws IOException
{   InputReader sc = new InputReader(System.in);	
    PrintWriter w  =new PrintWriter(System.out);
    int t=sc.nextInt();
     while(t--!=0)
     { int n=sc.nextInt();
       int q=sc.nextInt();
        Hashtable<Integer,Integer>ht=new Hashtable<>();
        for(int i=0;i<n;i++)
        { int tmp=sc.nextInt();
            if(ht.containsKey(tmp)) ht.put(tmp,ht.get(tmp)+1);
            else ht.put(tmp,1);
        }
        for(int i=0;i<q;i++)
        { int tmp=sc.nextInt();
          if(ht.containsKey(tmp)==true)
            w.println(ht.get(tmp));
            else 
            w.println("0");
        }
         }
   w.close();
      }
      
}
class InputReader
{
	private InputStream stream;
	private byte[] buf = new byte[8192];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;
	
	public InputReader(InputStream stream)
	{
		this.stream = stream;
	}
	
	public int read()
	{
		if (numChars==-1) 
			throw new InputMismatchException();
		
		if (curChar >= numChars)
		{
			curChar = 0;
			try 
			{
				numChars = stream.read(buf);
			}
			catch (IOException e)
			{
				throw new InputMismatchException();
			}
			
			if(numChars <= 0)				
				return -1;
		}
		return buf[curChar++];
	}
 
	public String nextLine()
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
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
	public int nextInt()
	{
		int c = read();
		
		while(isSpaceChar(c)) 
			c = read();
		
		int sgn = 1;
		
		if (c == '-') 
		{
			sgn = -1;
			c = read();
		}
		
		int res = 0;
		do 
		{
			if(c<'0'||c>'9') 
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		while (!isSpaceChar(c)); 
		
		return res * sgn;
	}
	
	public long nextLong() 
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') 
		{
			sgn = -1;
			c = read();
		}
		long res = 0;
		
		do 
		{
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		while (!isSpaceChar(c));
			return res * sgn;
	}
	
	public double nextDouble() 
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') 
		{
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!isSpaceChar(c) && c != '.') 
		{
			if (c == 'e' || c == 'E')
				return res * Math.pow(10, nextInt());
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		if (c == '.') 
		{
			c = read();
			double m = 1;
			while (!isSpaceChar(c)) 
			{
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				m /= 10;
				res += (c - '0') * m;
				c = read();
			}
		}
		return res * sgn;
	}
	public char nextChar()
	{  int c =read();
	     while(isSpaceChar(c)) c=read();
	     return (char)c;
	    
	}
	public String readString() 
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do 
		{
			res.appendCodePoint(c);
			c = read();
		} 
		while (!isSpaceChar(c));
		
		return res.toString();
	}
 
	public boolean isSpaceChar(int c) 
	{
		if (filter != null)
			return filter.isSpaceChar(c);
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
 
	public String next() 
	{
		return readString();
	}
	
	public interface SpaceCharFilter 
	{
		public boolean isSpaceChar(int ch);
	}
}

2).
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;
 
public class codechef_first_code {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    int gcd(int a, int b)
    {
        if(b==0)return a;
        return gcd(b,a%b);
    }
 
 
    void solve() {
        int t=ni();
        while (t-->0) {
            int n = ni();
            int q = ni();
            int a[] = na(n);
            HashMap<Integer, Integer> h = new HashMap<>();
            for (int i = 0; i < n; i++) {
                if (h.containsKey(a[i])) {
                    int temp = h.get(a[i]);
                    h.put(a[i], ++temp);
                } else {
                    h.put(a[i], 1);
                }
            }
            while (q-- > 0) {
                int a1 = ni();
                if (h.containsKey(a1)) {
                    out.println(h.get(a1));
                } else {
                    out.println(0);
                }
            }
        }
    }
 
    void run() throws Exception
    {
        is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        out = new PrintWriter(System.out);
 
        long s = System.currentTimeMillis();
        solve();
        out.flush();
        if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
    }
 
    public static void main(String[] args) throws Exception { new codechef_first_code().run(); }
 
    private byte[] inbuf = new byte[1024];
    public int lenbuf = 0, ptrbuf = 0;
 
    private int readByte()
    {
        if(lenbuf == -1)throw new InputMismatchException();
        if(ptrbuf >= lenbuf){
            ptrbuf = 0;
            try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
            if(lenbuf <= 0)return -1;
        }
        return inbuf[ptrbuf++];
    }
 
    private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
    private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
 
    private double nd() { return Double.parseDouble(ns()); }
    private char nc() { return (char)skip(); }
 
    private int[][] matix(int y1,int y2){
        int a[][]=new int[y1][y2];
        for (int i = 0; i <y1 ; i++) {
            for (int j = 0; j < y2; j++) {
                a[i][j]=ni();
            }
        }
        return a;
    }
 
    private String ns()
    {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
 
    private char[] ns(int n)
    {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while(p < n && !(isSpaceChar(b))){
            buf[p++] = (char)b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }
 
    private char[][] nm(int n, int m)
    {
        char[][] map = new char[n][];
        for(int i = 0;i < n;i++)map[i] = ns(m);
        return map;
    }
 
    private int[] na(int n)
    {
        int[] a = new int[n];
        for(int i = 0;i < n;i++)a[i] = ni();
        return a;
    }
 
    private int ni()
    {
        int num = 0, b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
 
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
 
    private long nl()
    {
        long num = 0;
        int b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
 
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
 
    private static void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
}

3).
import java.io.*;
import java.util.*;  
import java.lang.*;
class EasyOne
{   
    public static void main(String args[])throws IOException
{   InputReader sc = new InputReader(System.in);	
    PrintWriter w  =new PrintWriter(System.out);
    int t=sc.nextInt();
     while(t--!=0)
     { int n=sc.nextInt();
       int q=sc.nextInt();
        Hashtable<Integer,Integer>ht=new Hashtable<>();
        for(int i=0;i<n;i++)
        { int tmp=sc.nextInt();
            if(ht.containsKey(tmp)) ht.put(tmp,ht.get(tmp)+1);
            else ht.put(tmp,1);
        }
        for(int i=0;i<q;i++)
        { int tmp=sc.nextInt();
          if(ht.containsKey(tmp)==true)
            w.println(ht.get(tmp));
            else 
            w.println("0");
        }
         }
   w.close();
      }
      
}
class InputReader
{
	private InputStream stream;
	private byte[] buf = new byte[8192];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;
	
	public InputReader(InputStream stream)
	{
		this.stream = stream;
	}
	
	public int read()
	{
		if (numChars==-1) 
			throw new InputMismatchException();
		
		if (curChar >= numChars)
		{
			curChar = 0;
			try 
			{
				numChars = stream.read(buf);
			}
			catch (IOException e)
			{
				throw new InputMismatchException();
			}
			
			if(numChars <= 0)				
				return -1;
		}
		return buf[curChar++];
	}
 
	public String nextLine()
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
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
	public int nextInt()
	{
		int c = read();
		
		while(isSpaceChar(c)) 
			c = read();
		
		int sgn = 1;
		
		if (c == '-') 
		{
			sgn = -1;
			c = read();
		}
		
		int res = 0;
		do 
		{
			if(c<'0'||c>'9') 
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		while (!isSpaceChar(c)); 
		
		return res * sgn;
	}
	
	public long nextLong() 
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') 
		{
			sgn = -1;
			c = read();
		}
		long res = 0;
		
		do 
		{
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		while (!isSpaceChar(c));
			return res * sgn;
	}
	
	public double nextDouble() 
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') 
		{
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!isSpaceChar(c) && c != '.') 
		{
			if (c == 'e' || c == 'E')
				return res * Math.pow(10, nextInt());
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		if (c == '.') 
		{
			c = read();
			double m = 1;
			while (!isSpaceChar(c)) 
			{
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				m /= 10;
				res += (c - '0') * m;
				c = read();
			}
		}
		return res * sgn;
	}
	public char nextChar()
	{  int c =read();
	     while(isSpaceChar(c)) c=read();
	     return (char)c;
	    
	}
	public String readString() 
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do 
		{
			res.appendCodePoint(c);
			c = read();
		} 
		while (!isSpaceChar(c));
		
		return res.toString();
	}
 
	public boolean isSpaceChar(int c) 
	{
		if (filter != null)
			return filter.isSpaceChar(c);
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
 
	public String next() 
	{
		return readString();
	}
	
	public interface SpaceCharFilter 
	{
		public boolean isSpaceChar(int ch);
	}
}

4).
import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;
 
class TestClass
{
    public static void main(String args[]) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw=new PrintWriter(System.out);
        
        String s=br.readLine();
        String[] c=s.split(" ");
        int t=Integer.valueOf(c[0]);
        
        for(int j=0; j<t; j++)
        {
            s=br.readLine();
            c=s.split(" ");
            int n=Integer.valueOf(c[0]);
            int q=Integer.valueOf(c[1]);
            
            s=br.readLine();
            c=s.split(" ");
            HashMap<Integer, Integer> hm=new HashMap<>();
            for(int i=0; i<n; i++) {
            
                int x=Integer.valueOf(c[i]);
                
                if(hm.containsKey(x)) {
                    
                    int ct=hm.get(x);
                    ct++;
                    hm.put(x, ct);
                }
                
                else
                    hm.put(x, 1);
            }
            
            for(int i=0; i<q; i++) {
                
                s=br.readLine();
                c=s.split(" ");
                int x=Integer.valueOf(c[0]);
                
                if(hm.containsKey(x))
                    pw.println(hm.get(x));
                
                else
                    pw.println("0");
            }
        }
        
        br.close();
        pw.close();
    }
}

Java 8:
1).
import java.io.*;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
 
class TestClass {
 
    public static void main(String args[]) throws Exception {
        InputReader s = new InputReader(System.in);
        PrintWriter pr = new PrintWriter(System.out);
        int t = s.nextInt();
        for (int i = 0; i < t; i++) {
            int N = s.nextInt();
            Map < Integer, Integer > map = new HashMap < > ();
            int Q = s.nextInt();
            for (int j = 0; j < N; j++) {
                int x = s.nextInt();
                Integer value = map.get(x);
                if (value == null) {
                    map.put(x, 1);
                } else map.put(x, value + 1);
            }
            for (int j = 0; j < Q; j++) {
                int x = s.nextInt();
                Integer value = map.get(x);
                if (value == null) {
                    pr.println(0);
                } else pr.println(value);
 
            }
        }
        pr.close();
    }
}
class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[8192];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;
 
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
 
    public String nextLine() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
    public int nextInt() {
        int c = read();
 
        while (isSpaceChar(c))
            c = read();
 
        int sgn = 1;
 
        if (c == '-') {
            sgn = -1;
            c = read();
        }
 
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        }
        while (!isSpaceChar(c));
 
        return res * sgn;
    }
 
    public long nextLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
 
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        }
        while (!isSpaceChar(c));
        return res * sgn;
    }
 
    public double nextDouble() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!isSpaceChar(c) && c != '.') {
            if (c == 'e' || c == 'E')
                return res * Math.pow(10, nextInt());
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!isSpaceChar(c)) {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                m /= 10;
                res += (c - '0') * m;
                c = read();
            }
        }
        return res * sgn;
    }
    public char nextChar() {
        int c = read();
        while (isSpaceChar(c)) c = read();
        return (char) c;
 
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

2).
import java.io.*;
import java.util.*;  
import java.lang.*;
class EasyOne
{   
    public static void main(String args[])throws IOException
{   InputReader sc = new InputReader(System.in);	
    PrintWriter w  =new PrintWriter(System.out);
    int t=sc.nextInt();
     while(t--!=0)
     { int n=sc.nextInt();
       int q=sc.nextInt();
        Hashtable<Integer,Integer>ht=new Hashtable<>();
        for(int i=0;i<n;i++)
        { int tmp=sc.nextInt();
            if(ht.containsKey(tmp)) ht.put(tmp,ht.get(tmp)+1);
            else ht.put(tmp,1);
        }
        for(int i=0;i<q;i++)
        { int tmp=sc.nextInt();
          if(ht.containsKey(tmp)==true)
            w.println(ht.get(tmp));
            else 
            w.println("0");
        }
         }
   w.close();
      }
      
}
class InputReader
{
	private InputStream stream;
	private byte[] buf = new byte[8192];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;
	
	public InputReader(InputStream stream)
	{
		this.stream = stream;
	}
	
	public int read()
	{
		if (numChars==-1) 
			throw new InputMismatchException();
		
		if (curChar >= numChars)
		{
			curChar = 0;
			try 
			{
				numChars = stream.read(buf);
			}
			catch (IOException e)
			{
				throw new InputMismatchException();
			}
			
			if(numChars <= 0)				
				return -1;
		}
		return buf[curChar++];
	}
 
	public String nextLine()
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
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
	public int nextInt()
	{
		int c = read();
		
		while(isSpaceChar(c)) 
			c = read();
		
		int sgn = 1;
		
		if (c == '-') 
		{
			sgn = -1;
			c = read();
		}
		
		int res = 0;
		do 
		{
			if(c<'0'||c>'9') 
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		while (!isSpaceChar(c)); 
		
		return res * sgn;
	}
	
	public long nextLong() 
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') 
		{
			sgn = -1;
			c = read();
		}
		long res = 0;
		
		do 
		{
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		while (!isSpaceChar(c));
			return res * sgn;
	}
	
	public double nextDouble() 
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') 
		{
			sgn = -1;
			c = read();
		}
		double res = 0;
		while (!isSpaceChar(c) && c != '.') 
		{
			if (c == 'e' || c == 'E')
				return res * Math.pow(10, nextInt());
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		}
		if (c == '.') 
		{
			c = read();
			double m = 1;
			while (!isSpaceChar(c)) 
			{
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				m /= 10;
				res += (c - '0') * m;
				c = read();
			}
		}
		return res * sgn;
	}
	public char nextChar()
	{  int c =read();
	     while(isSpaceChar(c)) c=read();
	     return (char)c;
	    
	}
	public String readString() 
	{
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do 
		{
			res.appendCodePoint(c);
			c = read();
		} 
		while (!isSpaceChar(c));
		
		return res.toString();
	}
 
	public boolean isSpaceChar(int c) 
	{
		if (filter != null)
			return filter.isSpaceChar(c);
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
 
	public String next() 
	{
		return readString();
	}
	
	public interface SpaceCharFilter 
	{
		public boolean isSpaceChar(int ch);
	}
}

3).
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    
    	 static class InputReader {
	        private InputStream stream;
	        private byte[] buf = new byte[1024];
	        private int curChar;
	        private int numChars;
 
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
 
	        public String readLine() {
	            int c = read();
	            while (isSpaceChar(c))
	                c = read();
	            StringBuilder res = new StringBuilder();
	            do {
	                res.appendCodePoint(c);
	                c = read();
	            } while (!isEndOfLine(c));
	            return res.toString();
	        }
 
	        public String readString() {
	            int c = read();
	            while (isSpaceChar(c))
	                c = read();
	            StringBuilder res = new StringBuilder();
	            do {
	                res.appendCodePoint(c);
	                c = read();
	            } while (!isSpaceChar(c));
	            return res.toString();
	        }
 
	        public long readLong() {
	            int c = read();
	            while (isSpaceChar(c))
	                c = read();
	            int sgn = 1;
	            if (c == '-') {
	                sgn = -1;
	                c = read();
	            }
	            long res = 0;
	            do {
	                if (c < '0' || c > '9')
	                    throw new InputMismatchException();
	                res *= 10;
	                res += c - '0';
	                c = read();
	            } while (!isSpaceChar(c));
	            return res * sgn;
	        }
 
	        public int readInt() {
	            int c = read();
	            while (isSpaceChar(c))
	                c = read();
	            int sgn = 1;
	            if (c == '-') {
	                sgn = -1;
	                c = read();
	            }
	            int res = 0;
	            do {
	                if (c < '0' || c > '9')
	                    throw new InputMismatchException();
	                res *= 10;
	                res += c - '0';
	                c = read();
	            } while (!isSpaceChar(c));
	            return res * sgn;
	        }
 
	        public boolean isSpaceChar(int c) {
	            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	        }
 
	        public boolean isEndOfLine(int c) {
	            return c == '\n' || c == '\r' || c == -1;
	        }
	    }
 
	    static class OutputWriter {
	        private final PrintWriter writer;
 
	        public OutputWriter(OutputStream outputStream) {
	            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
	                    outputStream)));
	        }
 
	        public OutputWriter(Writer writer) {
	            this.writer = new PrintWriter(writer);
	        }
 
	        public void print(Object... objects) {
	            for (int i = 0; i < objects.length; i++) {
	                if (i != 0)
	                    writer.print(' ');
	                writer.print(objects[i]);
	            }
	        }
 
	        public void printLine(Object... objects) {
	            print(objects);
	            writer.println();
	        }
 
	        public void close() {
	            writer.close();
	        }
	    }
    
    public static void main(String args[] ) throws Exception {
        
		
		InputReader in = new InputReader(System.in);
	    OutputWriter out = new OutputWriter(System.out);
	     
		int T = in.readInt();
		StringBuilder output = new StringBuilder();
		while (T-- > 0) {
			
			int N = in.readInt();
			int Q = in.readInt();
			Map<Integer, Integer> countMap = new HashMap<>();
			
			for (int i=0;i<N;i++) {
				int num = in.readInt();
				if (!countMap.containsKey(num)) {
					countMap.put(num, 1);
				}
				else {
					int value = countMap.get(num);
					countMap.put(num, ++value);
				}
			}
			
			while (Q-- >0) {
				int num = in.readInt();
				if (!countMap.containsKey(num)) {
					output.append(0).append("\n");
				}
				else {
					output.append(countMap.get(num)).append("\n");
				}
			}
		}
		
		out.print(output);
		out.close();
 
	
    }
}

4).
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
 
class Easyone {
 
	static class FastIO {
		private final InputStream is;
		private final byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
 
		public FastIO() {
			this(System.in);
		}
 
		public FastIO(final InputStream is) {
			this.is = is;
		}
 
		public int[] nextArray(final int n) {
			final int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			return a;
		}
 
		public int read() {
			if (numChars == -1) {
				throw new RuntimeException();
			}
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = is.read(buf);
				} catch (final IOException e) {
					throw new RuntimeException();
				}
				if (numChars <= 0) {
					return -1;
				}
			}
			return buf[curChar++];
		}
 
		public String nextLine() {
			return readLine();
		}
 
		public String readLine() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			final StringBuilder sb = new StringBuilder();
			do {
				sb.append((char) c);
				c = read();
			} while (!isEndOfLine(c));
			return sb.toString();
		}
 
		public String next() {
			int c = read();
			while (isSpaceChar(c)) {
				c = read();
			}
			final StringBuilder sb = new StringBuilder();
			do {
				sb.append((char) c);
				c = read();
			} while (!isSpaceChar(c));
			return sb.toString();
		}
 
		public long nextLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}
 
		public int nextInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}
 
		public boolean isSpaceChar(final int c) {
			return (c == ' ') || (c == '\n') || (c == '\r') || (c == '\t') || (c == -1);
		}
 
		public boolean isEndOfLine(final int c) {
			return (c == '\n') || (c == '\r') || (c == -1);
		}
	}
 
	public static void main(String[] args) {
 
		FastIO f = new FastIO();
		PrintWriter pw = new PrintWriter(System.out);
		int t = f.nextInt();
		while (t-- > 0) {
			int n = f.nextInt();
			int q = f.nextInt();
			HashMap<Integer, Integer> map = new HashMap<>();
			while (n-- > 0) {
				map.compute(f.nextInt(), (K, V) -> V == null ? 1 : ++V);
			}
			while (q-- > 0) {
				pw.println(map.getOrDefault(f.nextInt(), 0));
			}
		}
		pw.flush();
	}
 
}


Python:
1).
def main():
    an = ""
    for _ in xrange(int(inp.readline())):
        n,q=map(int,inp.readline().split())
        a=map(int,inp.readline().split())
        d={}
        for i in a:
            try:
                d[i]+=1
            except KeyError:
                d[i]=1
        for i in xrange(q):
            t=int(inp.readline())
            try:
                print d[t]
            except KeyError:
                print 0
if __name__ == "__main__":
    from sys import stdin as inp, stdout as out
    main()

2).
R = lambda: map(int, raw_input().split())
 
for _ in range(input()):
    n, q = map(int, raw_input().split())
    c = {}
    for x in raw_input().split():
        c[x] = c.get(x, 0) + 1
    for _ in range(q):
        print c.get(raw_input(), 0)

Python 3:
1).
for j in range(int(input())):
    di = {}
    size , query = list(map(int ,input().strip(" ").split(" ")))
    for st in  input().strip(" ").split(" "):
        if st in di:
            di[st] += 1
        else:
            di[st] = 1
    for k in range(query):
        print (di.get(input() , 0))

2).
from collections import Counter
 
for _ in range(int(input())):
    n, q = map(int, input().split())
    wc = Counter(map(int, input().split()))
    for _ in range(q):
        print(wc[int(input())])

3).
# Write your code here
for _ in range(int(input())):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    d=dict()
    for i in l:
        try:
            d[i]+=1
        except:
            d[i]=1
    for _ in range(k):
        a=int(input())
        try:
            print(d[a])
        except:
            print(0)

4).
from collections import Counter,defaultdict
t = int(input())
for _ in range(t):
    n,q = map(int,input().split())
    #print(n)
    #print(q)
    arr = list(map(int,input().split()))
    #print(arr)
    d = defaultdict(int)
    d = Counter(arr)
    print(d)
    for _ in range(q):
        temp = int(input())
        print(d[temp])

*/


/*Editorial:

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,a;
        cin>>n;
        int q;
        cin>>q;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            m[a]+=1;
        }

        while(q--)
        {
            int x;
            cin>>x;
            cout<<m[x]<<endl;
        }
    }
    return 0;
}

*/

