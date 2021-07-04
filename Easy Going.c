/*All Tracks-->Algorithms-->Sorting-->Bubble Sort-->Problem
Easy Going.(Very Easy)
Tag(s): Very-Easy

Coders here is a simple task for you, you have given an array of size N and an integer M.
Your task is to calculate the difference between maximum sum and minimum sum of N-M elements of the given array.

Constraints:
1<=t<=10
1<=n<=1000
1<=a[i]<=1000

Input:
First line contains an integer T denoting the number of testcases.
First line of every testcase contains two integer N and M.
Next line contains N space separated integers denoting the elements of array.

Output:
For every test case print your answer in new line.

SAMPLE INPUT 
1
5 1
1 2 3 4 5
SAMPLE OUTPUT 
4

Explanation:
M is 1 and N is 5 so you have to calculate maximum and minimum sum using (5-1 =) 4 elements.
Maximum sum using the 4 elements would be (2+3+4+5=)14. 
Minimum sum using the 4 elements would be (1+2+3+4=)10. 
Difference will be 14-10=4.

Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
Marking Scheme:	Marks are awarded when all the testcases pass.
Allowed Languages:	Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), 
TypeScript, Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, 
OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, Visual Basic

// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

#include <iostream>
using namespace std;
#define N 1001

//int cmpfunc (const void * a, const void * b) {
//   return ( *(int*)a - *(int*)b );
//}
//

int main(){
    int arr[N],i,t,j,k,n,m,temp=0,is_sorted=0;
    long maxsum=0,minsum=0;
    cin>>t;
    for(i=0;i<t;i++){
        maxsum=0,minsum=0;
        cin>>n>>m;
        for(j=0;j<n;j++)
            cin>>arr[j];
        for(j=0;j<n;j++){
            is_sorted=1;
            for(k=j;k<n;k++){
                if(arr[j]>=arr[k]){
                    temp=arr[j];
                    arr[j]=arr[k];
                    arr[k]=temp;
                    is_sorted = 0;
                }
            }
            if(is_sorted)
                break;
        }
        //qsort(arr,n,sizeof(int),cmpfunc);
        for(k=n-1;k!=n-(n-m)-1;k--)
            maxsum+=arr[k];
        for(k=0;k!=(n-m);k++)
            minsum+=arr[k];
        cout<<maxsum-minsum<<endl;
    }
    return 0;
}

*/

/*Editorial:

//My c++ code here.
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

#include <iostream>
using namespace std;
#define N 1001

int main(){
    int arr[N],i,t,j,k,n,m,temp=0,is_sorted=0;
    long maxsum=0,minsum=0;
    cin>>t;
    for(i=0;i<t;i++){
        maxsum=0,minsum=0;
        cin>>n>>m;
        for(j=0;j<n;j++)
            cin>>arr[j];
        for(j=0;j<n;j++){
            is_sorted=1;
            for(k=j;k<n;k++){
                if(arr[j]>=arr[k]){
                    temp=arr[j];
                    arr[j]=arr[k];
                    arr[k]=temp;
                    is_sorted = 0;
                }
            }
            if(is_sorted)
                break;
        }
        //qsort(arr,n,sizeof(int),cmpfunc);
        for(k=n-1;k!=n-(n-m)-1;k--)
            maxsum+=arr[k];
        for(k=0;k!=(n-m);k++)
            minsum+=arr[k];
        cout<<maxsum-minsum<<endl;
    }
    return 0;
}
*/

/*
//Another cpp solution:

#include <bits/stdc++.h>
using namespace std;

int main()
{
int t;
cin>>t;
while(t--){
int n,m;
cin>>n>>m;
vector<int> a(n+1);
a[0]=0;
for(int i=1;i<=n;i++)
cin>>a[i];
sort(a.begin(),a.end());

for(int i=1;i<=n;i++)
a[i]+=a[i-1];
cout<<endl;
long int min=1000000000,max=0;
int t=n-m;
for(int i=t;i<=n;i++){
if(a[i]-a[i-t]>max)
max=a[i]-a[i-t];
if(a[i]-a[i-t]<min)
min=a[i]-a[i-t];
}
cout<<max-min<<endl;
}
return 0;
}

*/

/*
Best Submissions:
C:
#include <stdio.h>
 
int main(){
 
    int t,n,*a,i,j,m,temp,sum,dif;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        dif=0;
        scanf("%d %d",&n,&m);
        a=(int *)malloc(n*sizeof(int));
         for(i=0;i<n;i++)
          scanf("%d",&a[i]);
        
        for(i=0;i<n-1;i++)
        {
           for(j=0;j<n-i-1;j++)
           {
              if (a[j]>a[j+1])
              {
                  temp=a[j];
                  a[j]=a[j+1];
                  a[j+1]=temp;
              }
            }
       }
       
       for(i=0;i<n-m;i++)
        sum=sum+a[i];
        
       for(i=m;i<n;i++)
        dif=dif+a[i];
        
       printf("%d\n",dif-sum);
   }
}
C++:
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t,n,m;
	cin >> t;
	while(t--) {
	    cin>>n>>m;
	    int a[n];
	    for(int i=0; i<n; ++i) {
	        cin>>a[i];
	    }
	    sort(a,a+n);
	    int k = abs(n-m), min=0, max=0;
	    for(int i=0; i<k; ++i) {
	        min += a[i];
	    }
	    for(int i=n-1; i>=n-k; --i) {
	        max += a[i];
	    }
	    cout<<max-min<<"\n";
	}
	return 0;
}

C++14:
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++)
        
        {
            cin>>a[i];
        }
        sort(a,a+n);
        // for(int i=0;i<n;i++)
        //{
        //    cout<<a[i]<<"\t";
        //}
        int y=n-m;
        int p=0,q=0;
        for(int i=0,j=n-1;i<n-m;i++,j--)
        {
           p+=a[i];
           q+=a[j];
        }
        cout<<q-p<<"\n";
        
    }
}

C#:
using System;
using System.IO;
 
namespace Problems
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.SetIn(new StreamReader(Console.OpenStandardInput(),
                               Console.InputEncoding,
                               false,
                               bufferSize: 1024));
                               
            int noOfTestCases = Int32.Parse(Console.ReadLine());
            int noOfElements, sumElements, index;
            int[] elements;
 
            int maxSum, minSum;
            for (int test = 0; test < noOfTestCases; test++)
            {
                maxSum = minSum = 0;
                string[] temp = Console.ReadLine().Split(' ');
                noOfElements = Int32.Parse(temp[0]);
                sumElements = Int32.Parse(temp[1]);
                elements = new int[noOfElements];
                temp = Console.ReadLine().Split(' ');
                for (int i = 0; i < noOfElements; i++)
                    elements[i] = Int32.Parse(temp[i]);
 
                BubbleSort(ref elements);
 
                for (index = 0; index < sumElements; index++)
                {
                    minSum += elements[index];
                    maxSum += elements[noOfElements - index - 1];
                }
 
                Console.WriteLine(maxSum - minSum);
            }
 
        }
 
        public static void BubbleSort(ref int[] inputs)
        {
            int high = inputs.Length-1;
            int lastSwapIndex = high;
            bool swap = true;
            int index,temp;
 
            while(swap)
            {
                swap = false;
                for (index=0;index<lastSwapIndex;index++)
                {
                    if(inputs[index] > inputs[index+1])
                    {
                        temp = inputs[index];
                        inputs[index] = inputs[index + 1];
                        inputs[index + 1] = temp;
                        high = index;
                        swap = true;
                    }
                }
                lastSwapIndex = high;
            }
        }
    }
}

Java:
import java.util.*;
import java.util.Arrays;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
class TestClass 
{
    public static void main(String args[] ) throws Exception 
    {
        Reader s=new Reader();
        int T= s.nextInt();
    
        for(int i=0;i<T;i++)
        {
            int M=s.nextInt();
            int N=s.nextInt();
            
            int arr[]=new int[M];
            
            for(int j=0;j<M;j++)
        {
            arr[j]=s.nextInt();
        }
        
        Arrays.sort(arr);
        int number = M-N;
        int min=0,max=0;
        int len=arr.length;
        
        for(int j=N;j<len;j++)
        {
            max+=arr[j];
        }
        
        //System.out.println("max is "+max);
        
        for(int j=0;j<number;j++)
        {
            min+=arr[j];
        }
        //System.out.println("min is "+min);
        
        
        System.out.println(max-min);
        }
    }
    
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
}

Java 8:
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
 
//
//@author Saurabh Dutta
//@problemLink https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/min-max-difference/
//

class EasyGoing {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
 
        while(T-- > 0) {
            String[] input = br.readLine().split(" ");
            int N = Integer.parseInt(input[0]);
            int M = Integer.parseInt(input[1]);
            input =  br.readLine().split(" ");
 
            int[] arr = new int[N];
            for(int i=0;i<N;i++){
                arr[i] = Integer.parseInt(input[i]);
            }
            Arrays.sort(arr);
            int diff = 0;
            for(int i=0;i<M;i++){
                diff+= arr[N-1-i] - arr[i];
            }
            System.out.println(diff);
            
 
 
 
        }
    }
}

PHP:
<?php
//
// Sample code to perform I/O:
 
//fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
//echo "Hi, ".$name.".\n";                // Writing output to STDOUT
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
//
 
// Write your code here
$details = array();
$f = fopen( 'php://stdin', 'r' );
while( $line = fgets( $f ) ) {
    $details[] = $line;
}
$testcases = $details[0];
for($d = 1;$d<count($details);$d++){
    $maxSum = 0;
    $minSum=0;
    $NMArray = explode(' ',$details[$d]);
    $limit = $NMArray[0];
    $M = $NMArray[1];
    $elements = $limit - $M;
    $d++;
    $array = explode(' ',$details[$d]);
    $temp = 0;
 
    for($i=0;$i<$limit;$i++) {
        for($j=0;$j<$limit-$i-1;$j++) {
            if($array[$j] > $array[$j+1]) {
                $temp = $array[$j];
                $array[$j] = $array[$j+1];
                $array[$j+1] = $temp;
            }
        }
        if(($limit-$i)  > $M){
            $maxSum += $array[$limit-$i-1];
        }
        if($elements  > ($limit-$i-1)){
            $minSum += $array[$limit-$i-1];
        }
    }
    echo $diff =  $maxSum-$minSum."\n";
 
}
//$testcases = $details[0];
//$NMArray = explode(' ',$details[1]);
//$limit = $NMArray[0];
//$M = $NMArray[1];
//$elements = $limit - $M;
//$maxSum = 0;
//$minSum = 0;
//$array = explode(' ',$details[2]);
//$temp = 0;
// 
//for($i=0;$i<$limit;$i++) {
//    for($j=0;$j<$limit-$i-1;$j++) {
//        if($array[$j] > $array[$j+1]) {
//            $temp = $array[$j];
//            $array[$j] = $array[$j+1];
//            $array[$j+1] = $temp;
//        }
//    }
//    if(($limit-$i)  > $M){
//        $maxSum += $array[$limit-$i-1];
//    }
//    if($elements  > ($limit-$i-1)){
//        $minSum += $array[$limit-$i-1];
//    }
//}
//echo $diff =  $maxSum-$minSum;

?>

Python:
from sys import stdin
for _ in range(int(stdin.readline())):
    l = map(int , stdin.readline().split())
    r = map(int , stdin.readline().split())
    r.sort()
    max_sum = sum(r[l[1]:])
    min_sum = sum(r[:l[0]-l[1]])
    print max_sum-min_sum

Python 3:
t = int(input())
for i in range(t):
        arr1 = list(map(int, input().split()))
        arr2 = list(map(int,(input().split() )))
        arr2.sort()
        m = arr1[0] - arr1[1]
        #print(m)
        y = abs(sum(arr2[:m]) - sum(arr2[arr2.__len__() - m:]))
        #print(arr2[arr2.__len__()-m:])
        print(y)

Alt.Solution:
for _ in range(int(input())) :
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    print(-sum(arr[:len(arr)-m]) + sum(arr[m:]))
		

Ruby:
=begin
# Sample code to perform I/O:
 
name = gets.chomp                # Reading input from STDIN
print "Hi, #{name}.\n"           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=end
 
# Write your code here
num_cases = gets.chomp.to_i
 
num_cases.times  {
    n, m = gets.chomp.split(/\s+/).map {|e| e.to_i}
    diff = n - m
    array = gets.chomp.split(/\s+/).map {|e| e.to_i}.sort
    min_sum = array[0...diff].inject(:+)
    max_sum = array[(array.size - diff)...array.size].inject(:+)
    printf "%d\n", (max_sum - min_sum)
}



*/