/* All Tracks --> Data Structures --> Stacks --> Basics of Stacks --> Problem -->
Stack and Queue <Nissan>
Tag(s): Arrays, Data Structures, Easy, Implementation, Queue, Stack, Stack
You are given a stack of N integers such that the first element represents the top of the stack and the last element represents the bottom of the stack. 
You need to pop at least one element from the stack. At any one moment, you can convert stack into a queue. The bottom of the stack represents the front of the queue. 
You cannot convert the queue back into a stack. Your task is to remove exactly K elements such that the sum of the K removed elements is maximised.

Input format :     
The first line consists of two space-separated integers N and K.
The second line consists of N space-separated integers denoting the elements of the stack.

Output format :
Print the maximum possible sum of the K removed elements
Constraints :
1<=N<=10^5
1<=K<=N
1<=A[i]<=10^9

SAMPLE INPUT 
10 5
10 9 1 2 3 4 5 6 7 8
SAMPLE OUTPUT 
40

Explanation
Pop two elements from the stack. i.e {10,9}
Then convert the stack into queue and remove first three elements from the queue. i.e {8,7,6}.
The maximum possible sum is 10+9+8+7+6 = 40

//My C Solution:
#include <stdio.h>
#define LEN 100001

int main() {
    int N,K,i,j;
    long long int A[LEN],sum=0,max=0;
    scanf("%d%d",&N,&K);
    for(i=0;i<N;i++)
        scanf("%lld",&A[i]);
    for(j=0;j<K;j++)
        sum+=A[j];
    max=sum;
    // one element atleast has to be popped from stack ,so it is K-1
    for(j=0;j<K-1;j++){
        sum = sum + A[N-1-j]-A[K-1-j];
        if(sum>=max)
            max = sum;
    }
    printf("%lld\n",max);
	return 0;
}
//My Python3 Solution:
n , k = map(int,input().split())
l = list(map(int,input().split()))

s = 0
for i in range(k):
    s += l[i]
    
m = s
for i in range(k-1):
    s = s - l[k-i-1] + l[n-1-i]
    if s>=m:
        m=s
print(m)

*/


/*Best_Submissions:
C:
#include<stdio.h>
int main()
{
    long long n,k;
    scanf("%lld",&n);
    scanf("%lld",&k);
    int arr[n];
    for(long long i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    long long sum = 0,ans=0;
    for(long long i=0; i<k; i++)
    {
        sum = sum + arr[i];
    }
    ans=sum;
    for(long long i=0; i<k-1; i++)
    {
        sum = (sum + arr[n-i-1] - arr[k-1-i]);
        if(sum>=ans)
            ans=sum;
    }
    printf("%lld",ans);
    return 0;
}


C++:
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
int n,k;
cin>>n>>k;
int c=k;
long long s[n],s1[n],a[n];
long long sum=0;
for(auto i=1;i<=n;i++) cin>>a[i];
 
s[1]=a[1];
s1[1]=a[n];
for(auto i=2;i<=k;i++){
s[i]=s[i-1]+a[i];
s1[i]=a[n-i+1]+s1[i-1];
}
 
sum=s[k];
for(auto i=1;i<k;i++){
sum=max(sum,s[i]+s1[k-i]);
}
cout<<sum;
return 0;
}


C++14:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main(){
    ll n,k,i;
    cin>>n>>k;
    ll a[n],pre[n],suf[n];
    for(i=0;i<n;i++){
        cin>>a[i];
        pre[i]=a[i];
        if(i>0){
            pre[i]+=pre[i-1];
        }
    }
    for(i=n-1;i>=0;i--){
        suf[i]=a[i];
        if(i<(n-1)){
            suf[i]+=suf[i+1];
        }
    }
    ll ans=pre[k-1];
    for(i=1;i<k;i++){
        ans=max(ans,pre[k-1-i]+suf[n-i]);
    }
    cout<<ans<<endl;
}

C#:
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace Paris_having_similar_elements
{
    class Program
    {
                static public void Main(string[] args)
        {
 
            long[] input = Console.ReadLine().Split().Select(x => long.Parse(x)).ToArray();
            long N = input[0];
            long K = input[1];
            long[] arr = Console.ReadLine().Split().Select(x => long.Parse(x)).ToArray();
 
            long[] prefix = new long[N];
            prefix[0] = arr[0];
            for (long i = 1; i < N; i++)
                prefix[i] = prefix[i - 1] + arr[i];
 
            long ans = 0;
            for (long i = 0; i < K; i++)
            {
                long temp = prefix[i] + prefix[N - 1] - prefix[N - K + i];
 
                ans = ans > temp ? ans : temp;
            }
 
            Console.WriteLine(ans);
        }
    }
}

Java:
import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
 
import static java.lang.Math.*;
 
public class name_of_file implements Runnable
{
    static class InputReader
    {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;
        private BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
 
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
    
    public static void main(String args[]) throws Exception
    {
        new Thread(null, new name_of_file(),"name_of_file",1<<26).start();
    }
	
    //class Wand {
    //    int ind;
    //    int val;
    //    Wand(int a, int b) {
    //        ind = a;
    //        val = b;
    //    }
    //} 
	//(This statement shows how to make our own class)
    
    //to count no of 1 in binary form::
    long count_one (int n){
            long count=0;
            while(n>0)
            {
               n = n&(n-1);
               count++;
            }
            return count;
       }
    //To Find most significant setbit of a number::
    int Last_set_bit(int n){
        return (int)(Math.log(n)/Math.log(2));
    }   
    //power mod::
    static long powmod(long x, long n, long m) {
        if (n == 0) {
            return 1;
        } 
        else if (n % 2 == 0) {
            return powmod(((x % m) * (x % m)) % m, n / 2, m);
        } 
        else if (n % 2 == 1) {
            return (((x % m) * powmod(((x % m) * (x % m)) % m, (n - 1) / 2, m)) % m);
        } 
        else {
            return 0;
        }
    }
    //GCD od 2 nos::
    public static long gcd(long a, long b) {
        if(b==0) return a;
        return gcd(b%a,a);
    }
    //GCD of Array::
    public static long gcd(long[] input) {
        long result = input[0];
 
        for (int i = 1; i < input.length; i++) {
            result = gcd(result, input[i]);
        }
 
        return result;
    }
    //LCM of 2 nos::
    public static long lcm(long a, long b) {
        return a * (b / gcd(a, b));
    }
    //LCM of Array::
    public static long lcm(long[] input) {
        long result = input[0];
 
        for (int i = 1; i < input.length; i++) {
            result = lcm(result, input[i]);
        }
 
        return result;
    }
    //BINARY TREE::
    public class Node{
        int data;
        Node left,right;
        Node(int data){
            this.data = data;
            left = right = null;
        }
 
        public void insert(int value){
            if(value<=data){
                if(left==null) left = new Node(value);
                else left.insert(value);
            }
            else{
                if(right==null) right = new Node(value);
                else right.insert(value);
            }
        }  
 
        public boolean contains(int value){
           if(value==data) return true;
            else if(value<data){
                if(left==null) return false;
                else return left.contains(value);
            }
            else{
                if(right==null) return false;
                else return right.contains(value);
            }
        }
    }
    //FOR FINDING HEIGHT OF A TREE::
    public int maxht(Node root){
        if(root == null) return 0;
        else{
            int ld = maxht(root.left);
            int rd = maxht(root.right);
            
            if(ld>rd) return ld+1;
            else return rd+1;
        }
    }
    //Graph::
    public class graph{
        ArrayList<Integer> a;
        int d;
        boolean b;
 
        void graph(){
            this.d = 0;
            this.b = false;
        }
    }
    //Code starts right here... 
    public void run()
    {
        InputReader sc = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        //write your code here
        //take input through sc.nextInt and all and output through w.print & w.println
        long i,max=0,j;
		long n=sc.nextLong();
		long k=sc.nextLong();
		long a[]=new long[(int)n];
		long s1[]=new long[(int)n];
		long s2[]=new long[(int)n];
		long b[]=new long[(int)k+1];
		   for(i=0;i<n;i++)
		   a[(int)i]=sc.nextLong();
		long u=k;
		long y=0;
			long s=a[0];
			long sr=a[(int)n-1];
			s1[0]=s;
			s2[0]=sr;
			for(i=1;i<n;i++){
				s=s+a[(int)i];
				s1[(int)i]=s;
				//System.out.print(s2[(int)i]+" ");
			}
			j=1;
			for(i=n-2;i>=0;i--){
				sr=sr+a[(int)i];
				s2[(int)j]=sr;
				j++;
			}
			int x=0;
			y=0;
			b[0]=s1[(int)k-1];
			j=1;
			for(i=k-2;i>=0;i--){
				b[(int)j]=s1[(int)i]+s2[(int)x];
				j++;
				x++;
			}
			//for(i=0;i<k+1;i++)
				//System.out.print(b[(int)i]+" ");
		   long m2=-1;
		   for(i=0;i<k+1;i++){
		   	if(b[(int)i]>m2)
		   		m2=b[(int)i];
		   }
		   w.println(m2);                  
        w.close();
    }
    
}


Java 8:
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
 
public class StackAndQ {
	int temp=0;
	void solve() {
		LinkedList ll = new LinkedList();
		int N=nextInt();
		int K=nextInt();
		long maxSum=0;
		int i=K;
		while(N-->0){
			temp=nextInt();
			if(i-->0)
				maxSum+=temp;
			ll.add(temp);
		}
		if(K==N)
			pw.print(maxSum);
		else{
			maxSum = ll.findMaxSum(maxSum,K);
			pw.print(maxSum);
		}
	}
	class Node {
		int val;
		Node next;
		Node previous;
	}
	 
	class LinkedList {
		Node root;
		Node last;
		
		
		public void add(int val) {
			if (root == null) {
				Node n = new Node();
				n.val = val;
				root = n;
				last = n;
			}else {
				Node n = new Node();
				n.val = val;
				last.next = n;
				n.previous = last;
				last = last.next;
			}
		}
 
		public long findMaxSum(long sum,int K) {
			long maxSum=sum;
			int count=K;
			Node currNode =root;
			while(K-->1)
				currNode=currNode.next;
			while(count-->1)
			{
				sum=sum+last.val-currNode.val;
				if(maxSum<sum)
					maxSum=sum;
				last=last.previous;currNode=currNode.previous;
			}
			return maxSum;
		}
 
		public long get(int val) {
 
			return 0;
		}
	}
 
	InputStream is;
    PrintWriter pw;
    String INPUT = "";
    void run() throws Exception {
        is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        pw = new PrintWriter(System.out);
        long s = System.currentTimeMillis();
        solve();
        pw.flush();
        if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
    }
 
    public static void main(String[] args) throws Exception { new StackAndQ().run(); }
 
    private byte[] inbuf = new byte[1024];
    public int lenbuf = 0, ptrbuf = 0;
 
    private int readByte() {
        if(lenbuf == -1)throw new InputMismatchException();
        if(ptrbuf >= lenbuf){
            ptrbuf = 0;
            try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
            if(lenbuf <= 0)return -1;
        }
        return inbuf[ptrbuf++];
    }
 
    private int nextInt() {
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
 
    private long nextLong() {
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
 
    private void tr(Object... o) { if(INPUT.length() > 0)System.out.println(Arrays.deepToString(o)); }
}

Javascript(Node.js):
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
var stdin_input_array = [];
var current_line = 0;
 
 
process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});
 
process.stdin.on("end", function () {
    stdin_input_array = stdin_input.split('\n');
    main(stdin_input_array);
});
 
function readLine() {
    return stdin_input_array[current_line++];
}
 
function main(input) {
    var line = readLine().split(' ').map(Number);
    var N = line[0], K = line[1];
    var array = readLine().split(' ').map(Number);
    
    K = K - 1;
    N = N - 1;
    
    var sum = 0;
    for (var i = K; i >= 0; i--) {
        sum = sum + array[i];
    }
    
 
    var step = K;
    var maxSum = sum;
    while (step > 0) {
        sum = sum - array[step];
        sum = sum + array[N - (K - step)];
 
        if (sum >= maxSum) {
            maxSum = sum;
        }
        step--;
    }
    
    console.log(maxSum);
}
 


Python:
n,k=map(int,raw_input().split())
arr=list(map(int,raw_input().split()))
q=0
for i in range(len(arr)-1,len(arr)-k-1,-1):
    q+=arr[i]
s=0
ans=-1
for i in range(0,k):
    s+=arr[i]
    ans=max(s+(q-arr[len(arr)-k+i]),ans)
    q=q-(arr[len(arr)-k+i])
print(ans)


Python 3:
n,k=map(int, input().split())
a=list(map(int, input().split()))
 
val=a[0]
i=n-1
while i>n-k:
    val+=a[i]
    i-=1
ans=val
for j in range(1,k):
    val+=a[j]-a[i+1]
    i+=1
    ans=max(ans,val)
print(ans)    

Ruby:
ip = gets.chomp.split
k = ip[1].to_i
n = ip[0].to_i
arr = gets.chomp.split.map(&:to_i)
arr1 = arr[0..k-1].reverse + arr[n-k..n-1].reverse
max_sum = 0
sum = 0
len = arr1.length
i=0
while i<k
    max_sum += arr1[i]
    i+=1
end
sum = max_sum
while i<len-1
    sum+=arr1[i]
    sum-=arr1[i-k]
    if sum>max_sum
        max_sum = sum
    end
    i+=1
end
puts max_sum


*/

/*Editorial:
Author Solution by Kruti Dharaiya:
#include <bits/stdc++.h>
#define ll long long
#define MAX 2000000
using namespace std;
int main() {
    ll n,k;
    cin>>n>>k;
    ll arr[n+1];
    for(int i=0;i<n;i++) cin>>arr[i];
    ll prefix[n+1];
    prefix[0]=arr[0];
    for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+arr[i];
    ll ans=0;
    for(int i=0;i<k;i++){
        ll temp=prefix[i]+prefix[n-1]-prefix[n-k+i];
        ans=max(ans,temp);
    }
    cout<<ans;
    return 0;
}

*/