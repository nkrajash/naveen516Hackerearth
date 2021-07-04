/*All Tracks -->  Algorithms -->  Searching  --> Binary Search -->  Problem -->
Discover the Monk
Tag(s): Binary Search, Easy
You are given an array A of size N, and Q queries to deal with. 
For each query, you are given an integer X, and you're supposed to find out if X is present in the array A or not.

Input:
The first line contains two integers, N and Q, denoting the size of array A and number of queries. The second line contains N space separated integers, 
denoting the array of elements Ai. The next Q lines contain a single integer X per line.

Output:
For each query, print YES if the X is in the array, otherwise print NO.

Constraints:
1 <= N, Q <= 10^5
1 <= Ai <= 10^9
1 <= X <= 10^9

SAMPLE INPUT
5 10
50 40 30 20 10
10
20
30
40
50
60
70
80
90
100

SAMPLE OUTPUT
YES
YES
YES
YES
YES
NO
NO
NO
NO
NO



#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int n,q,X,i,j=0,k=0,num,flag=0,high,low,mid;
    int *A;
    A=(int *)malloc(1*sizeof(int));
    
    scanf("%d",&n);
    scanf("%d",&q);
    
    for(i=0;i<n;i++){
        scanf("%d",&num);
        A=(int *)realloc(A,++k*sizeof(int));
        A[k-1]=num;
    }
    
    qsort(A, n, sizeof(int), cmpfunc);

    for(i=0;i<q;i++){
        scanf("%d",&X);
        low=0;
        high=n-1;
        flag=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(A[mid]<X)
            {
                low=mid+1;
            }
            else if(A[mid]>X)
            {
                high=mid-1;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
    
}
*/

/*Best Submissions:
C:
#include <stdio.h>
//Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[]
void merge(int arr[], int l, int m, int r);
 
// l is for left index and r is right index of the sub-array
//  of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
   if (l < r)
   {
      int m = l+(r-l)/2; //Same as (l+r)/2 but avoids overflow for large l & h
      mergeSort(arr, l, m);
      mergeSort(arr, m+1, r);
      merge(arr, l, m, r);
   }
}
 
//Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    //create temp arrays
    int L[n1], R[n2];
 
    //Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    // Merge the temp arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// A iterative binary search function. It returns location of x in
// given array arr[l..r] if present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
  while (l <= r)
  {
    int m = l + (r-l)/2;
 
    if (arr[m] == x) return m;  // Check if x is present at mid
 
    if (arr[m] < x) l = m + 1; // If x greater, ignore left half
 
    else r = m - 1; // If x is smaller, ignore right half
  }
  return -1; // if we reach here, then element was not present
}
 
int main()
{
    int n,q,check,i,x,array[100020];
    scanf("%lld%lld",&n,&q);
    
    for(i=0;i<n;i++)
    {
    	scanf("%lld",&array[i]);
    }
    
    mergeSort(array,0,n);
    
    for(i=0;i<q;i++)
    {
    	scanf("%lld",&x);
    	
    	check=binarySearch(array,0,n,x);
    	
    	if(check==-1)
    	{
    		printf("NO\n");
    	}
    	else
    	{
    		printf("YES\n");
    	}
    }
    return 0;
}

C++:
#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	vector <int> v;
	int n, q,x;
	scanf("%d %d\n",&n,&q);
	for(int i=0;i<n;i++)
	{
	cin>>x;
	v.push_back(x);
	}
	
	sort(v.begin(),v.end());
	
	for(int i=0;i<q;i++)
	{
		scanf("%d",&x);
		int k=binary_search(v.begin(),v.end(),x);
		if(k)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}

C++14:
#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 100010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;
 
int N, Q;
ll a, x;
vector<ll> A;
 
int main () {
    scan(N); scan(Q);
    for (int i=0; i<N; i++) {
      scan(a);
      A.pb(a);
    }
    sort(A.begin(), A.end());
    for (int i=0; i<Q; i++) {
        scan(x);
        printf("%s\n", binary_search(A.begin(), A.end(), x) ? "YES" : "NO");
    }
    return 0;
}


C#:
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
class MyClass {
    static void Main(string[] args) {
     var inputs = Console.ReadLine().Trim().Split(' ').Select(x => Convert.ToInt32(x)).ToArray();
            List<int> valuesList = Console.ReadLine().Trim().Split(' ').Select(x => Convert.ToInt32(x)).OrderByDescending(x => x).Reverse().ToList();
            StringBuilder sb = new StringBuilder(inputs[1]);
            for (int i = 0; i < inputs[1]; i++)
            {
                int result = valuesList.BinarySearch(Convert.ToInt32(Console.ReadLine().Trim()));
                if(result>=0)
                {
                    sb.AppendLine("YES");
                }
                else
                {
                    sb.AppendLine("NO");
                }
            }
            Console.WriteLine(sb.ToString());
    }
}

Java:
import java.io.*;
import java.util.Arrays;
 
public class DiscoverMonk {
    public static void main(String[] args) throws Exception {
        BufferedWriter bo = new BufferedWriter(new OutputStreamWriter(System.out));
        Reader reader = new Reader();
        int n = reader.nextInt();
        int q = reader.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = reader.nextInt();
        }
        Arrays.sort(a);
        StringBuilder res = new StringBuilder();
        int x;
        for (int i = 0; i < q; i++) {
            x = reader.nextInt();
            int l = 0, r = n - 1, mid;
            mid = (l + r) / 2;
            while (l <= r) {
                if (a[mid] > x) {
                    r = mid - 1;
                } else if (a[mid] == x) {
                    res.append("YES\n");
                    break;
                } else {
                    l = mid + 1;
                }
 
                mid = (l + r) / 2;
            }
            if (l > r) {
                res.append("NO\n");
            }
        }
 
        bo.append(res);
        bo.close();
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
 
        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
 
            if (neg)
                return -ret;
            return ret;
        }
 
        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
 
        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
    }
 
}

Java8:
import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
 
class TestClass {
 
    public static void main(String args[]) throws Exception {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        InputReader in = new InputReader(System.in);
        OutputWriter out = new OutputWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int n = in.readInt();
        int q = in.readInt(), l, r;
//        int[] arr = IOUtils.readIntArray(in, n);
//        Arrays.sort(arr);
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            set.add(in.readInt());
        }
        for (int i = 0; i < q; i++) {
            if(set.contains(in.readInt()))
                sb.append("YES\n");
            else
                sb.append("NO\n");
        }
        out.print(sb.toString());
        out.flush();
        out.close();
    }
 
    private static boolean binSearch(int[] arr, int v) {
        int l = 0, r = arr.length-1;
        while (l<=r){
            int mid = (l + r) / 2;
            if(arr[mid] == v)
                return true;
            else if(arr[mid]>v)
                r = mid-1;
            else
                l = mid+1;
 
        }
        return false;
    }
 
 
    private static int getFirst(int[] arr, int v) {
        int l = 0;
        int r = arr.length - 1;
        int mid;
        int midVal;
        while (l <= r) {
            mid = (l + r) / 2;
            midVal = arr[mid];
            if (midVal == v) {
                if (mid > 0 && arr[mid - 1] == v) {
                    r = mid - 1;
                } else
                    return mid;
            }else if(midVal>v){
                if(mid>0 && arr[mid-1]<v)
                    return mid;
                r = mid-1;
            }else {
                l = mid+1;
            }
        }
        return -1;
    }
 
    private static int getLast(int[] arr, int l, int v) {
        int len = arr.length;
        int r = len - 1;
        int mid;
        int midVal;
        while (l <= r) {
            mid = (l + r) / 2;
            midVal = arr[mid];
            if (midVal == v) {
                if (mid + 1 < len && arr[mid + 1] == v) {
                    l = mid + 1;
                } else
                    return mid;
            } else if (midVal < v) {
                if(mid+1< len && arr[mid+1]>v)
                    return mid;
                l = mid + 1;
            } else {
 
                r = mid - 1;
            }
        }
        return len - 1;
    }
 
 
}
 
class InputReader {
 
    private InputStream stream;
    private byte[] buf = new byte[1024];
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
 
 
    public long readLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        long sgn = 1;
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
 
    public String readLine() {
        int c = read();
        StringBuilder res = new StringBuilder();
        while (!isNewLineChar(c)) {
            res.appendCodePoint(c);
            c = read();
        }
        return res.toString();
    }
 
    private boolean isNewLineChar(int c) {
        return c == '\n';
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
 
    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
 
    public String next() {
        return readString();
    }
 
    public interface SpaceCharFilter {
        boolean isSpaceChar(int ch);
    }
}
 
class OutputWriter {
    private final PrintWriter writer;
 
    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
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
        this.flush();
    }
 
    public void close() {
        writer.close();
    }
 
    public void flush() {
        writer.flush();
    }
 
    public void println(Object... objects) {
        print(objects);
        writer.println();
        this.flush();
    }
}
 
class IOUtils {
 
    public static int[] readIntArray(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
    }
 
    public static int[] readIntArray(InputReader in, int size, long[] counts) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = in.readInt();
            if (array[i] % 2 == 0)
                counts[0]++;
            else
                counts[1]++;
        }
        return array;
    }
 
}


Perl:
use strict;
my $tem = <>;
chomp($tem);
my ($n, $q) = split(/ /, $tem);
$tem = <>;
chomp($tem);
my %arr;
@arr{split(/ /,$tem)} = (1..$n);
foreach(1..$q){
	my $x = <>;
	chomp($x);
	if(exists $arr{$x}){
		print "YES\n";
	}
	else {
			print "NO\n";
	}
}

Python:
data = raw_input().split()                                                         
input_data = set(raw_input().split())                                              
                                                                                   
for _ in xrange(int(data[1])):                                                     
  if raw_input() in input_data:                                                    
    print ( 'YES' )                                                                 
  else:                                                                            
    print ( 'NO' )

Python3:
#from bisect import bisect_left
n,q=map(int,input().split())
a=set(input().split())
x=[]
for _ in range(q):
    x.append(input())
for i in range(q):
    if(x[i] in a):
        print("YES")
    else:
        print("NO")


Ruby:
n,q = gets.split(" ").map(&:to_i)
arr = gets.split(" ").map(&:to_i)
h = Hash.new("NO")
arr.each do |a|
	h[a] = "YES"
end
# puts "#{h}"
q.times do
	puts h[gets.to_i]
end


PHP:
<?php
fscanf(STDIN, "%d%d\n", $N, $Q);
$A = explode(" ", trim(fgets(STDIN)));
$A = array_flip($A);
for($i = 0; $i < $Q; $i++) {
    fscanf(STDIN, "%d\n", $X);
    echo (isset($A[$X])) ? "YES\n" : "NO\n";
}
?>

Pascal:
var
  i,n,m,d:longint;
  A,B:array[0..101010] of int64;
 
function _TNP(x:int64;L,R:longint):int64;
  var
    vtg:longint;
 
  begin
    while (L <= R) do
      begin
        vtg:=(L+R) div 2;
        if (A[vtg] = x) then exit(1);
        if (A[vtg] > x) then R:=vtg-1
        else L:=vtg+1;
      end;
    exit(0);
  end;
 
procedure _QS(L,R:longint);
  var
    i,j:longint;
    sng,tg:int64;
 
  begin
    sng:=A[(L+R) div 2];
    i:=L;
    j:=R;
    repeat
      while (A[i] < sng) do inc(i);
      while (A[j] > sng) do dec(j);
 
      if (i <= j) then
        begin
          tg:=A[i];
          A[i]:=A[j];
          A[j]:=tg;
          inc(i);
          dec(j);
        end;
    until (i > j);
 
    if (L < j) then _QS(L,j);
    if (i < R) then _QS(i,R);
  end;
 
BEGIN
 
  read(n,m);
  for i:=1 to n do
    read(A[i]);
  for i:=1 to m do
    read(B[i]);
 
  _QS(1,n);
 
  d:=0;
  for i:=1 to m do
    if (_TNP(B[i],1,n) = 1) then writeln('YES')
    else writeln('NO');
 
 
END.

*/