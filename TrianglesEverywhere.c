/* Best Submissions:
C:
#include<stdio.h>
long long int power(long int x, long  int y,long int p) 
{ 
     long int res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 
int main()
{
    long long int n,i,j=5,t,p=1000000007;
    scanf("%lld",&t);
    while(t--)
    {
        j=5;
    scanf("%lld",&n);
    printf("%lld\n",(2*power(3,n,p)-1)%p);
    }
}

C++:
#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
int f[1000006] = {1};
 
int mul(long long x, long long y) {
    return x * y % M;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 1000000; ++i) {
        f[i] = mul(f[i - 1], 3) + 2;
        if (f[i] >= M) {
            f[i] -= M;
        }
    }
    int t;
    for (cin>>t; t; --t) {
        int n;
        cin>>n;
        cout<<f[n]<<"\n";
    }
    return 0;
}


C++14:
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
 
using ll     =           long long;
using ull    =  unsigned long long;
using flt    =               float;
using dbl    =              double;
using ldbl   =         long double;
using cp     =       complex<ldbl>;
using ivec   =         vector<int>;
using istack =          stack<int>;
using ip     =       pair<int,int>;
using iqueue =          queue<int>;
using ipq    = priority_queue<int>;
using idq    =          deque<int>;
using iset   =            set<int>;
using imset  =       multiset<int>;
using imap   =        map<int,int>;
using ivmap  =       map<int,ivec>;
 
const int mod = 1e9+7; const ldbl pi = acos(-1.0);
 
#ifdef __Codeforces__
#define get_char _getchar_nolock
#define put_char _putchar_nolock
#else
#define get_char getchar_unlocked
#define put_char putchar_unlocked
#endif
 
class xistream { 
	int next() {
    	int c = get_char(); while (isspace(c)) c = get_char(); return c; }
    template<typename T> int accumulate(int c, T &x) {
    	for (x = 0; c >= '0' and c <= '9'; x *= 10, x += c-'0', c = get_char()); return c; }
	template<typename T> xistream& get_int(T &x) {
    	int c = next(), s = 0; 
    	if (c == '-') s = 1, c = get_char();
    	if (accumulate(c,x), s) x = -x; 
    	return *this; } 
	template<typename T> xistream& get_uint(T &x) {
    	int c = next(); accumulate(c,x); return *this; }
    template<typename T> xistream& get_flt(T &x) {
    	ll dec = 0, f = 0; int c = next(), s = 0;
    	if (c == '-')
    		s = 1, c = get_char(); 
    	if (accumulate(c,dec) == '.')
    		accumulate(get_char(),f);
    	while (f > 0 and f%10 == 0) f /= 10;
    	x = dec, x += T(f)/pow(10.0,to_string(f).size());
    	if (s) x = -x; return *this; }
public:
    friend xistream& operator>>(xistream &in, int8_t &x)  { return in.get_int(x); } 
    friend xistream& operator>>(xistream &in, int16_t &x)  { return in.get_int(x); } 
    friend xistream& operator>>(xistream &in, int32_t &x)  { return in.get_int(x); } 
    friend xistream& operator>>(xistream &in, int64_t &x)  { return in.get_int(x); } 
    friend xistream& operator>>(xistream &in, uint8_t &x)  { return in.get_uint(x); } 
    friend xistream& operator>>(xistream &in, uint16_t &x) { return in.get_uint(x); } 
    friend xistream& operator>>(xistream &in, uint32_t &x) { return in.get_uint(x); } 
    friend xistream& operator>>(xistream &in, uint64_t &x) { return in.get_uint(x); } 
    friend xistream& operator>>(xistream &in, flt &x)  { return in.get_flt(x); } 
    friend xistream& operator>>(xistream &in, dbl &x)  { return in.get_flt(x); } 
    friend xistream& operator>>(xistream &in, ldbl &x) { return in.get_flt(x); } 
	friend xistream& operator>>(xistream &in, char &c) { c = in.next(); return in; } 
    friend xistream& operator>>(xistream &in, string &s) {
    	s.clear(); 
    	for (int c = in.next(); !isspace(c); c = get_char()) 
    	    s.push_back(c); 
    	return in; }
	friend void get_line(string &s) { 
		s.clear(); 
		for (int c = get_char(); c != '\n'; c = get_char()) 
		    s.push_back(c); }
 } xin;
    		
class xostream {
	ldbl mu; 
	template<typename T> xostream& put_uint_aux(T x) {
        char s[21]; int i = 0; 
        while (x)
        	s[i++] = '0'+(x%10), x /= 10; 
    	while (i > 0)
        	put_char(s[--i]); 
        return *this; }
    template<typename T> xostream& put_uint(T x) {
    	if (x == 0) { 
    	    put_char('0'); return *this; }
        return put_uint_aux(x); }
    template<typename T> xostream& put_int(T x) {
    	if (x == 0) { 
    	    put_char('0'); return *this; }
        if (x < 0) 
            put_char('-'), x = -x;
        return put_uint_aux(x); }
    template<typename T> xostream& put_uflt_aux(T x) {
    	ll dec = x; 
    	if (put_uint(dec), (x -= dec) > 0)
    		put_char('.'), dec = round(mu*x), put_uint_aux(dec);
    	return *this; }
    template<typename T> xostream& put_flt(T x) {
    	if (x == 0) { 
    	    put_char('0'); return *this; }
    	if (x < 0) 
    	    put_char('-'), x = -x; 
    	return put_uflt_aux(x); }
public:
	void set_precision(int p) { mu = pow(10.0,p); }
	xostream() { set_precision(8); }
    friend xostream& operator<<(xostream &out,  int8_t x)  { return out.put_int(x); } 
    friend xostream& operator<<(xostream &out, int16_t x)  { return out.put_int(x); } 
    friend xostream& operator<<(xostream &out, int32_t x)  { return out.put_int(x); } 
    friend xostream& operator<<(xostream &out, int64_t x)  { return out.put_int(x); } 
    friend xostream& operator<<(xostream &out, uint8_t x)  { return out.put_uint(x); } 
    friend xostream& operator<<(xostream &out, uint16_t x) { return out.put_uint(x); } 
    friend xostream& operator<<(xostream &out, uint32_t x) { return out.put_uint(x); } 
    friend xostream& operator<<(xostream &out, uint64_t x) { return out.put_uint(x); } 
    friend xostream& operator<<(xostream &out, flt x) { return out.put_flt(x); } 
    friend xostream& operator<<(xostream &out, dbl x) { return out.put_flt(x); } 
    friend xostream& operator<<(xostream &out, ldbl x) { return out.put_flt(x); } 
    friend xostream& operator<<(xostream &out, char c) { put_char(c); return out; }
    friend xostream& operator<<(xostream &out, const string &s) {
    	for (auto c: s) 
    	    put_char(c); 
    	return out; } } xout;
 
const auto mod_add = [](int x, int y) { return x += y, x %= mod; };
const auto mod_mul = []( ll x, int y) { return x *= y, x %= mod; };
const auto mod_sqr = [](int x)        { return mod_mul(x,x); };
const auto mod_sub = [](int x, int y) { return mod_add(x,mod-y); };
const auto mod_pow = [](int x, ll  y) { 
    int z = 1; 
    while (y) { 
        if (y&1) 
            z = mod_mul(z,x); 
        x = mod_sqr(x), y >>= 1; } 
    return z; };
const auto mod_inv = [](int x) { return mod_pow(x,mod-2); };
const auto mod_div = [](int x, int y) { return mod_mul(x,mod_inv(y)); };
const auto mod_mac = [](int x, int y, int z) { return mod_add(x,mod_mul(y,z)); };
 
struct combinatorics {
	struct Factorial: ivec { Factorial(int n) { resize(n+1), front() = 1; } } 
		fact, inv_fact;
	combinatorics(int n) : fact(n), inv_fact(n) {
		for (int i = 0, j = 1; i < n; i = j++)
			inv_fact[j] = mod_inv(fact[j] = mod_mul(fact[i],j)); }
	int P(int n, int r) { return mod_mul(fact[n],inv_fact[n-r]); }
	int P(int n, const ivec &r) { 
		int ans = fact[n]; for (auto k: r) ans = mod_mul(ans,inv_fact[k]); return ans; }
	int  C(int n, int r) { return mod_mul(fact[n],mod_mul(inv_fact[r],inv_fact[n-r])); }
	int Cr(int n, int r) { return C(n+r-1,r); } };
	
struct sieve: vector<bool> {
	sieve(int n) {
		resize(n+1,true), at(0) = at(1) = false; 
		for (int p = 2, q = 4, d = 4; q <= n; q += d+1, ++p, d += 2)
			if (at(p))
				for (int u = q; u <= n; u += p)
					at(u) = false; } };
 
ivec divisors(int n) {
	ivec ans; istack s;
	for (int d, i = 1; i*i <= n; ++i)
		if (n%i == 0 and (ans.push_back(i), d = n/i) > i)
			s.push(d);
	while (not s.empty())
		ans.push_back(s.top()), s.pop(); 
	return ans; }
	
int phi(int n) { 
    int ans = n;
    for (int p = 2; p*p <= n; ++p) 
        if (n%p == 0) 
        	for (ans /= p, ans *= p-1, n /= p; n%p == 0; n /= p);
    if (n > 1)
		ans /= n, ans *= n-1;
    return ans; } 
 
ivec prime_factors(int n) {
	ivec ans; 
	for (int p = 2; p*p <= n; ++p)
		if (n%p == 0)
			for (ans.push_back(p), n /= p; n%p == 0; n /= p);
	if (n > 1)
		ans.push_back(n);
	return ans; }
	
class extendedEuclid: stack<ll> {
	void next(ll t, ll &x, ll &y) { x = y, y *= -top(), y += t; }
	void mod_inv(ll B, ll y) {
		while (not empty()) 
		    next(inv,inv,y), pop(); 
		inv %= B, inv += B, inv %= B; }
public: 
    ll gcd, inv; 
    extendedEuclid(ll a, ll b) : gcd(a), inv(1) {
        ll B = b, y = 0; 
        while (b > 0) 
            push(a/b), next(a,gcd,b), a = gcd; mod_inv(B,y); } };
 
template<class T> struct binary_indexed_tree: vector<T> {
    binary_indexed_tree(const int n) { this->resize(n+1,0); }
    void add(int i, const T d) { 
        const int p = this->size(); while (i < p) this->at(i) += d, i += (i&-i); }
    T sum(int i) const { 
        T ans = 0; while (i) ans += this->at(i), i -= (i&-i); return ans; } };
 
struct disjoint_set_union: vector<int> {
	disjoint_set_union(int n) { resize(n,-1); }
	int root(int i) const { while (at(i) != -1) i = at(i); return i; }
	bool disjoint(int i, int j) const { return root(i) != root(j); }
	bool same_set(int i, int j) const { return root(i) == root(j); }
	void join(int i, int j) {
		int u = root(i), v = root(j); if (u != v) at(max(u,v)) = min(u,v); } };
 
template<typename T> struct segment_tree: vector<T> {
	int n;
	struct next {
		int j, k, u, v; next(int i, int s, int t) :
			j((i << 1)+1), k(j+1), u((s+t)>>1), v(u+1) {} };
	T construct(int i, int s, int t, const vector<T> &a)  {  
    	if (s == t)  
    		return this->at(i) = a[s];  
    	const auto p = next(i,s,t);
		return this->at(i) = construct(p.j,s,p.u,t,a)+construct(p.k,p.v,t,a); }  
	void update(int i, int s, int t, int l, T d) { 
		if (this->at(i) += d, s != t) {
			const auto p = next(i,s,t);
			if (l <= p.u)
				update(p.j,s,p.u,l,d); 
			else
				update(p.k,p.v,t,l,d); } }
	int sum(int i, int s, int t, int l, int r) const { 
		if (s >= l and t <= r) 
			return this->at(i); 
		if (s > r or t < l) 
			return 0; 
		const auto p = next(i,s,t); 
		return sum(p.j,s,p.u,l,r)+sum(p.k,p.v,t,l,r); } 
public:
	segment_tree(int array_size) : n(array_size) { this->resize(n << 2,0); }
	segment_tree(const vector<T> &a) : n(a.size()) { this->resize(n<<2), construct(0,0,n-1,a); }  
	void update(int i, T d) { update(0,0,n-1,i,d); } 
	T sum(int l, int r) const { return sum(0,0,n-1,l,r); } };
 
template<class T>
struct o_set : tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update> {
	T   key(size_t i) const { return *this->find_by_order(i); }
	size_t order(T k) const { return  this->order_of_key(k); } };
	
const string ans[] = {"No","Yes"};
 
const int N = 1e6+2; int dp[N];
 
const auto initialize = []() {
    dp[1] = 1; 
    for (int i = 2; i < N ; ++i)
        dp[i] = mod_mac(2,3,dp[i-1]); };
 
const auto solve_s = []() { 
    int n; xin >> n;  return dp[n+1];
};
 
const auto solve_m = []() { int t; xin >> t; while (t--) xout << solve_s() << '\n'; };
 
int main() { initialize(), solve_m(); }

Java:
import java.util.*;
import java.io.*;
import java.math.*;
class Triangles{
	static long mod=1000000007;
	public static void main(String args[]){
		FastReader sc = new FastReader();
		int q,x,i;
		long val;
		long a[]=new long[1000001];
		a[1]=5;
		val=3;
		for(i=2;i<=1000000;i++){
			a[i]=((val*4)%mod+(a[i-1]%mod))%mod;
			val=(val*3)%mod;
		}
		q=sc.nextInt();
		while(q-->0){
			x=sc.nextInt();
			out.println(a[x]);
		}
		out.flush();
	}
 
	static PrintWriter out;
	static class FastReader{
		BufferedReader br;
		StringTokenizer st;
		public FastReader(){
			br=new BufferedReader(new InputStreamReader(System.in));
			out=new PrintWriter(System.out);
		}
		String next(){
			while(st==null || !st.hasMoreElements()){
				try{
					st= new StringTokenizer(br.readLine());
				}
				catch (IOException e){
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt(){
			return Integer.parseInt(next());
		}
		long nextLong(){
			return Long.parseLong(next());
		}
		double nextDouble(){
			return Double.parseDouble(next());
		}
		String nextLine(){
			String str = "";
			try{
				str=br.readLine();
			}
			catch(IOException e){
				e.printStackTrace();
			}
			return str;
		}
	}
 
	static class pair{
		int first,second;
		pair(int f,int s){
			first=f;
			second=s;
		}
	}
 
	public static boolean isPrime(int n) {
		if(n<2) return false;
		for(int i=2;i<=(int)Math.sqrt(n);i++) {
			if(n%i==0) return false;
		}
		return true;
	}
 
	public static void print(int a[],int l,int r){
		int i;
		for(i=l;i<=r;i++)
			out.print(a[i]+" ");
		out.println();
	}
 
	public static long fastexpo(long x, long y, long p){
		long res=1;
		while(y > 0){
			if((y & 1)==1)
				res= ((res%p)*(x%p))%p;
			y= y >> 1;			
			x = ((x%p)*(x%p))%p;
		}
		return res;
	}
 
	public static boolean[] sieve (int n) {
		boolean primes[]=new boolean[n+1];
		Arrays.fill(primes,true);
		primes[0]=primes[1]=false;
		for(int i=2;i*i<=n;i++){
			if(primes[i]){
				for(int j=i*i;j<=n;j+=i)
					primes[j]=false;
			}
		}
		return primes;
	}
 
	public static long gcd(long a,long b){
        return (BigInteger.valueOf(a).gcd(BigInteger.valueOf(b))).longValue();
    }
 
    public static void merge(int a[],int l,int m,int r){
        int n1,n2,i,j,k;
        n1=m-l+1;
        n2=r-m;
 
        int L[]=new int[n1];
        int R[]=new int[n2];
 
        for(i=0;i<n1;i++)
            L[i]=a[l+i];
        for(j=0;j<n2;j++)
            R[j]=a[m+1+j];
 
        i=0;j=0;
 
        k=l;
        while(i<n1&&j<n2){
            if(L[i]<=R[j]){
                a[k]=L[i];
                i++;
            }
            else{
                a[k]=R[j];
                j++;
            }
            k++;
        }
 
        while(i<n1){
            a[k]=L[i];
            i++;
            k++;
        }
        while(j<n2){
            a[k]=R[j];
            j++;
            k++;
        }
    }
    public static void sort(int a[],int l,int r){
        int m;
        if(l<r){
            m=(l+r)/2;
            sort(a,l,m);
            sort(a,m+1,r);
            merge(a,l,m,r);
        }
    }
}


Java 8:
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
 

//Built using CHelper plug-in
//Actual solution is at the top
//
//@author John Martin

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TrianglesEverywhere solver = new TrianglesEverywhere();
        solver.solve(1, in, out);
        out.close();
    }
 
    static class TrianglesEverywhere {
        public void solve(int testNumber, InputReader c, OutputWriter w) {
            long m = (int) 1e9 + 7;
            long pre_comp[] = new long[(int) 1e6 + 100], res[] = new long[(int) 1e6 + 100];
            res[0] = 1;
            pre_comp[0] = 1;
            for (int i = 1; i < 1e6 + 100; i++) {
                pre_comp[i] = pre_comp[i - 1] * 3;
                pre_comp[i] %= m;
                res[i] = pre_comp[i] + pre_comp[i - 1] + res[i - 1];
                res[i] %= m;
            }
 
            int tc = c.readInt();
            while (tc-- > 0) {
                w.printLine(res[c.readInt()]);
            }
 
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
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }
 
        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }
 
        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
 
        }
 
    }
 
    static class OutputWriter {
        private final PrintWriter writer;
 
        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }
 
        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }
 
        public void close() {
            writer.close();
        }
 
        public void printLine(long i) {
            writer.println(i);
        }
 
    }
}

Python:
mod=10**9+7
 
a=[0]*(10**6+2)
a[0]=1
 
for i in range(1,10**6+2):
    a[i]=3*a[i-1]+2
    a[i]%=mod
s=""
for _ in range(int(raw_input())):
    s+=str(a[int(raw_input())])+"\n"
print(s)

Python 3:
from sys import stdin
mod = 1000000007
dp = [0]*1000001
dp[0] = 1
for i in range(1,1000001):
    dp[i] = ((dp[i-1]*3)%mod + 2)%mod
    
for _ in range(int(stdin.readline())):
    print(dp[int(stdin.readline())])

*/