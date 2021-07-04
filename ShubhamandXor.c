/* All Tracks -->  Algorithms --> Sorting -->  Bubble Sort --> Problem -->Shubham and Xor
Tag(s): Algorithms, Bubble sort algorithm, Easy, Linear search, Searching algorithm, Sorting
You are given an array of n integer numbers a1,a2 , .. ,an. 
Calculate the number of pair of indices (i,j) such that  1<=i<=j<=n  and ai xor aj = 0.

Input format
- First line: n denoting the number of array elements
- Second line: n space separated integers a1,a2 , .. ,an.

Output format
Output the required number of pairs.

Constraints
1<=n<=10^6
1<=ai<=10^9

SAMPLE INPUT 
5
1 3 1 4 3
SAMPLE OUTPUT 
2
Explanation
The 2 pair of indices are (1,3) and  (2,5).

//My C Solution:
#include <stdlib.h>
#define LEN 1000001
#define ll long long int 

ll cmpfunc (const void * a, const void * b) {
   return ( *(ll*)a - *(ll*)b );
}


int main(){
    ll A[LEN],i,j,n,temp,cnt =0,sum=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&A[i]);
    qsort(A,n,sizeof(ll),cmpfunc);
    temp=A[0];
    for(i=0;i<n;i++)
    {
        if( temp == A[i])
        {
            cnt++;
        }
        else
        {
            temp=A[i];
            sum+=cnt*(cnt-1)/2;
            cnt=1;
        }
    }

    printf("%lld\n",sum);
    return 0;
}

//My C++ Solution:
#include <bits/stdc++.h>
#define LEN 1000001
#define ll long long int
using namespace std;
 
int main(){
    ll A[LEN],i,j,n,temp,cnt =0,sum=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>A[i];
    sort(A,A+n);
    temp=A[0];
    for(i=0;i<n;i++)
    {
        if( temp == A[i])
        {
            cnt++;
        }
        else
        {
            temp=A[i];
            sum+=cnt*(cnt-1)/2;
            cnt=1;
        }
    }
    cout<<sum;
    return 0;
}

//My Python 3 Solution:
from collections import Counter
 
n=int(input())
array=list(map(int,input().split()))
count=0
d=Counter(array)
for key,val in d.items():
    if val>1:
        count+=val*(val-1)//2
print(count)

*/

/*Editorial:
This is easiest problem of the challenge.If for 2 numbers x,y if x xor y = 0 then x is equal to y. 
So for each distinct number say x suppose it comes cnt number of times in input array, 
then we just have to add the number of ways to pick two distinct numbers from cnt numbers to the answer.
All this can be done by simply sorting the array once and iterating over the elements.
Please have a look at the setter/tester code for implementation details.
Complexity: O(n*logn)

Author Solution by shubham goyal
//let's do it
 #include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1000000000000
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define S second
#define F first
#define boost1 ios::sync_with_stdio(false);
#define boost2 cin.tie(0);
#define mem(a,val) memset(a,val,sizeof a)
#define endl "\n"
#define maxn 1000005
ll arr[maxn];
inline ll c2(ll x)
{
	return (x*(x-1))/2; 
}
int main()
{
	boost1;boost2;
	ll i,j,n,x,y,ans=0,ptr;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>arr[i];
	sort(arr+1,arr+n+1);
	ptr=1;
	for(i=2;i<=n;i++)
	{
		if(arr[i]==arr[i-1])
		continue;
		x=(i-1)-ptr+1;
		ans+=c2(x);
		ptr=i;
	}
	x=n-ptr+1;
	ans+=c2(x);
	cout<<ans;
	return 0;
}


Tester Solution by Mitesh Agrawal
//Mitesh Agrawal
#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,j,n,a;
	long long ans = 0;
	unordered_map<int, int> mp;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &a);
		mp[a]++;
		ans -= (1ll) * (mp[a] - 1) * (mp[a] - 2) / 2;
		ans += (1ll) * (mp[a]) * (mp[a] - 1) / 2;
	}
	printf("%lld\n", ans);
    return 0;
}

*/

/*Best Submissions:
C:
#include <stdio.h>
#include <stdlib.h>
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
int cmp(const void *p, const void *q) { //ASC Order
	return (*(const lint*)p > *(const lint*)q);
}
 
int main () {
	lint N = getli();
    lint *NA = (lint*) malloc ((N+1)*sizeof(lint));
    NA[0]=0;
    for (lint ni=1; ni<=N; ) NA[ni++] = getli();
    qsort (NA+1, N, sizeof(lint), cmp);
    
    lint ans =0, cnt=1;
    for (lint ni=2; ni<=N; ++ni) {
        if (NA[ni]==NA[ni-1]) ++cnt;
        else { ans += cnt*(cnt-1)/2; cnt =1; }
    } ans += cnt*(cnt-1)/2;
    putli(ans, 0);
	return 0;
}

C++:
#include <iostream>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x)
// void bubble_sort(int *a, int n){
//   for(int i=0;i<n-1;i++){
//     for(int j=0;j<n-i-1;j++){
//       if(a[j]>a[j+1]){
//         int temp = a[j];
//         a[j] = a[j+1];
//         a[j+1] = temp;
//       }
//     }
//   }
// }
void fastscan(int &x){
  register int c = gc();
  x = 0;
  for(;c<48||c>57;c=gc());
  for(;c>47 && c< 58; c=gc()){
    x = (x<<1) + (x<<3) + c - 48;
  }
}
int main(){
  int n;
  long long int count = 0, k;
  fastscan(n);
  int a[n];
  for(int i=0;i<n;i++)
    fastscan(a[i]);
  sort(a,a+n);
  // bubble_sort(a,n);
  for(int i=0;i<n;++i){
    k = 1;
    while(a[i]==a[i+1]){
      ++i;
      k++;
    }
    count = count + k*(k-1)*0.5;
  }
  cout << count << endl;
  return 0;
}

C++14:
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin>>n;
 
    unsigned int arr[n];
	long long int gt=0,counter=1;
	for(int i=0;i<n;i++)
		cin>>arr[i];
//
//for(register int i=0;i<n-1;i++)
//	for(register int j=0;j<n-1-i;j++)
//	{
//		if(arr[j]>arr[j+1])
//		{
//			temp=arr[j];
//			arr[j]=arr[j+1];
//			arr[j+1]=temp;
//		}
//	}
//
	sort(arr,arr+n);
	for(register int i=0;i<n-1;i++)
	{
 
		if(arr[i]==arr[i+1])
		{
			counter++;
		}
		else if(counter>1)
			{
			    gt+=(counter*(counter-1))>>1;
				counter=1;
			}
	}	
	cout<<gt;
	return 0;
}

C#:
using System;
using System.IO;
 
class ShubamXor
{
    static CustomIO customIO = new CustomIO();
    static void Main()
    {
        int N = customIO.ReadInt();
        long[] input = customIO.ReadLongArray(N);
        Array.Sort(input);
        int i = 1;
        long t1 = input[0], k, s1 = 0, s2 = 1;
 
        for (; i < N; i++)
        {
            k = input[i];
            if (t1 != k)
            {
                t1 = k;
                s1 += s2 * (s2 - 1);
                s2 = 1;
                continue;
            }
            s2++;
        }
        Console.WriteLine(s1 >> 1);
        customIO.Close();
    }
}
 
class CustomIO
{
    BufferedStream bStream;
    Byte[] inputBuffer;
    int bufferCapacity = 10485760;
    int inputBufferPos = 0, bufferReadSize = 0;
    public CustomIO()
    {
        bStream = new BufferedStream(Console.OpenStandardInput(), bufferCapacity);
        inputBuffer = new byte[bufferCapacity+1];
        LoadBuffer();
    }
 
    void LoadBuffer()
    {
        if (inputBufferPos >= bufferReadSize)
        {
            inputBufferPos -= bufferReadSize;
            bufferReadSize = bStream.Read(inputBuffer, 0, bufferCapacity);
            if (bufferReadSize == 0)
                inputBuffer[inputBufferPos] = 0;
        }
    }
 
    public void Close() => bStream.Close();
 
    private static bool ValidateNumbers(byte b) => b >= '0' && b <= '9';
    
    private void SkipInvalid()
    {
        while (inputBuffer[inputBufferPos] <= ' ')
            inputBufferPos++;
    }
 
    public int ReadInt()
    {
        SkipInvalid();
        byte begin = inputBuffer[inputBufferPos];
        int value = default(int);
        while (ValidateNumbers(begin))
        {
            value = (value << 3) + (value << 1) + (begin - '0');
            begin = inputBuffer[++inputBufferPos];
        }
        return value;
    }
 
    public long[] ReadLongArray(int length, char separator = ' ')
    {
        SkipInvalid();
        byte begin = inputBuffer[inputBufferPos];
        long value = 0; int index = 0;
        long[] result = new long[length];
        while (true)
        {
            if (begin == separator)
            {
                result[index++] = value;
                value = 0;
            }
            else if (ValidateNumbers(begin))
                value = (value << 3) + (value << 1) + (begin - '0');
            else
                break;
            begin = inputBuffer[++inputBufferPos];
        }
        result[index] = value;
        return result;
    }
 
}

Java:
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;
 
public class SubXor {
	public static void main(String[] args) throws IOException {
		Reader sc=new Reader();
		int n=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<a.length;i++)
		{
			a[i]=sc.nextInt();
		}
		Arrays.sort(a);
		long tmp=1;
		long result=0;
		for(int i=1;i<n;i++)
		{
			
			if((a[i]^a[i-1])==0){
				result+=tmp;
				tmp++;
			}else{
				tmp=1;
			}
				
			}
		
		System.out.println(result);
	}
	
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
}

Java 8:
import java.util.*;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
 
 
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
     static class Reader
    {
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
    public static void main(String args[] ) throws Exception {
        // Sample code to perform I/O:
        // Use either of these methods for input
        //
        ////BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        //
        ////Scanner
        //Scanner s = new Scanner(System.in);
        //String name = s.nextLine();                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        //
        //
 
        // Write your code here
        Reader s=new Reader();
        int n=s.nextInt();
        int a[]=new int[n];
        for(int i=0;i<n;i++)
        a[i]=s.nextInt();
        
       // for(int i=0;i<n-1;i++)
        //
        //{
        //    boolean b=false;
        //    for(int j=0;j<n-i-1;j++)
        //  if(a[j]>a[j+1]){
        //      int t=a[j];
        //      a[j]=a[j+1];
        //      a[j+1]=t;
        //      b=true;    
        //      
        //  }
        //  if(!b)
        //  break;
        //}
        Arrays.sort(a);
         // long t=a[0];
          long m=1;
          long ans=0;
          for(int i=1;i<n;i++){
              if(a[i]==a[i-1])
              m++;
              else
              { //t=a[i];
                ans=ans+((m-1)*m)/2;
                m=1;
              }
          }
          ans = ans+((m-1)*m)/2;
          System.out.println(ans);
 
    }
}

Java(Node.js):
'use strict';
 
function main() {
  const is = new Scanner();
 
  const n = is.nextInt();
  const array = is.nextArray(Number);
  const repeats = {};
  array.forEach(item => {
    if (!repeats.hasOwnProperty(item))
      repeats[item] = 0;
    repeats[item]++;
  });
 
  let answer = 0;
  Object.keys(repeats).forEach(i => {
    if (repeats[i] > 1)
      answer += (repeats[i] * (repeats[i] - 1)) / 2;
  });
  console.log(answer);
}
 
class Scanner {
  constructor() {
    this.index = 0;
    this.lines = stdinInput.trim().split('\n');
  }
 
  nextLine() {
    return this.lines[this.index++];
  }
 
  nextInt() {
    return parseInt(this.nextLine(), 10);
  }
 
  nextDouble() {
    return parseFloat(this.nextLine());
  }
 
  nextArray(cast = String) {
    return this.nextLine().split(' ').map(cast);
  }
 
  hasNext() {
    return this.index < this.lines.length;
  }
}
 
let stdinInput = '';
process.stdin.resume();
process.stdin.setEncoding('utf-8');
process.stdin.on('data', (input) => { stdinInput += input; });
process.stdin.on('end', () => main());

Perl:
my $n = <STDIN>;
$n -= 0;
my @d = split(/\s+/o,<STDIN>);
 
my %dd =();
for(my $i=0;$i<$n;$i++){
    $dd{$d[$i]} ++;
}
my $sum = 0;
 
foreach my $x (keys %dd){
    if($dd{$x}-0 > 1){
        my $x = $dd{$x}-1;
        $sum += $x * ($x+1) / 2;
    }
}
print "$sum\n";
# 2-1  3 - 3  4 - 6
# n(n+1)/2

PHP:
<?php

// Sample code to perform I/O:
// 
//fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
//echo "Hi, ".$name.".\n";                // Writing output to STDOUT
// 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

 
// Write your code here
 
fscanf(STDIN, "%d\n", $n);
 
$l = '';
 
while (false !== ($n = fgets(STDIN, 4096))) {
    $l .= $n;
}
 
$l = array_map('intval', explode(' ', $l));
 
echo array_sum(array_map(
    function ($v) {
        return abs(array_sum(range(1, $v)) - $v);
    },
    array_filter(
        array_count_values($l),
        function ($v) {
            return $v > 1;
        }
    )
));

Python:
from collections import Counter
from math import factorial as fac
arg=input()
 
dict1=Counter(raw_input().strip().split())
#b=map(int,raw_input().strip().split())
 
s=0
for a in dict1.values():
    if a>2:
        s+=(a*(a-1))/2
    elif a==2:
        s+=1
print s

Python 3:
from collections import Counter
 
# Write your code here
n = int(input().strip())
 
c = Counter(input().strip().split())
r = sum((v * (v - 1)) // 2 for v in c.values() if v > 1)
print(r)

Ruby:
def get_result(n)
    ((n-1)*n)/2
end
def solution
gets.to_i
res = {}
gets.chomp.split(' ').each {|val| res[val] = res[val].to_i + 1}
result = 0
res.values.each {|val| result += get_result(val)}
puts result
end
solution

*/
