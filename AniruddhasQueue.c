/* All Tracks -->  Basic Programming --> Implementation --> Basics of Implementation --> Problem -->
Aniruddha's Queue
Tag(s): Basic Programming, Easy
Aniruddha is given a milestone M to reach in terms of distance. 
He is living in a different Galaxy where there are N days in a year.At the ith day he can walk atmost X distance.
Assuming he walks optimally you need to output the minimum day number on which he will reach the milestone.

Input
The first input line contains the T number of testcases. Each testcase consist of three lines First line consist of single integer N — the number of days in a year.
Next line contains N non-negative space-separated numbers— i.e. distance which Aniruddha will walk on ith day. 
It is guaranteed that at least one of those numbers is greater than zero.
And the third line consist of the value of milestone which Aniruddha has to reach.

Output
For each testcase you need to output the answer to the following query.

Constraints
1<=T<=10
1<=N<=10^5
0<=X<=10^8
0<=M<=10^16

SAMPLE INPUT 
2
5
1 5 0 0 2
9
3
1 0 3
2
SAMPLE OUTPUT 
1
3

Explanation
For the first testcase we have to reach a milestone of 9 units. On the 1st day we would cover at most 1 unit.
On the 2nd day we would cover at most 5 units.So total distance covered till 2nd day is 6 units.
On 3rd and 4th day he would not cover any distance as value of X on those days is 0. On the 5th day he would cover at most 2 units. 
So total distance covered till 5th day is 8 units.Then he will go to the first day of the next year.
So total distance covered till 1st day will now become 9 units which is equal to the milestone. So answer is 1.
Similarly answer for second testcase is 3.

//My C Solution:
#include<stdio.h>
#define LEN 100001

int main(){
    int t,ans,i;
    long long int n=0,m=0,count=0;
    long long int dist[LEN];
    scanf("%d",&t);
    while(t--){
        count=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&dist[i]);
            count += dist[i];
        }
        scanf("%lld",&m);
        ans=0;
        if(m>count){
            m%=count;
            if(m==0)
                m=count;
        }
        count=0;
        for(i=0;i<n;++i)
        {
            count +=dist[i];
            if(count>=m)
            {
                ans=i;
                break;
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}

//My C++ Solution:
#include<iostream>
using namespace std;

int main(){
    int t,ans,i;
    long long int n=0,m=0,count=0;
    cin>>t;
    while(t--){
        count=0;
        cin>>n;
        long long int dist[n];
        for(i=0;i<n;i++){
            cin>>dist[i];
            count += dist[i];
        }
        cin>>m;
        ans=0;
        if(m>count){
            m%=count;
            if(m==0)
                m=count;
        }
        count=0;
        for(i=0;i<n;++i)
        {
            count +=dist[i];
            if(count>=m)
            {
                ans=i;
                break;
            }
        }
        cout<<ans+1<<endl;
    }
    return 0;
}

*/

/*Editorial:
Now in this problem as we know after reaching the last we will again come back to day 1. Now, if you calculate it by brute force or with naive approach you might end up getting TLE.
Brute Force or naive approach:
while we haven't reached m
loop on days
Complexity of this code can increase upto O(mn) in worst case. For worst case assume only day 1 value is 1 and rest are all 0 and there are 10^5 days. Consider m=10^16 in this case. total runtime will be (10^21) which is too too much.
The better approach:
As we know after reaching day n if we haven't find reached the destination we will come back to day 1. So from this observation we can formulate that if we loop k times through the days, the value of m is decreased by ksum_of_array. So what we can do is calculate the sum of the array. Take m%sum_of_array and than check which day he will reach destination.
Point to note: What if m%sum_of_array is 0 ? What if last element of array is also 0 ? This is left for reader to figure out as an exercise.

Author Solution by Aniruddha Sharma
//I Will Win Not Immediately But Definitely.. -Aniruddha Sharma
// Name:- Aniruddha Sharma
 
// Problem:- Aniruddha's Queue
// Site:- HackerEarth
 
#include<iostream>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<functional>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
using namespace std;
long long arr[100010];
int main()
{
	int t;
	scanf("%d",&t);
	//cin>>t;
	while(t--)
	{
		int i,noOfDays;
		scanf("%d",&noOfDays);
		//cin>>noOfDays;
		for(i=0;i<noOfDays;i++)
		{
			scanf("%lld",&arr[i]);
			//cin>>arr[i];
		}
		unsigned long long sum,ans=0;
		scanf("%llu",&sum);
		//cin>>sum;
		bool flag=false;
		for(i=0;i<noOfDays;i++)
		{
			ans+=arr[i];
			if(ans>=sum)
			{
				flag=true;
				break;
			}
		}
		if(flag)
		{
			printf("%d\n",i+1);
			//cout<<i+1<<endl;
		}
		else
		{
			sum=sum%ans;
			ans=0;
			for(i=0;i<noOfDays;i++)
			{
				ans+=arr[i];
				if(ans>=sum)
				{
					flag=true;
					break;
				}
			}
			if(sum!=0)
			printf("%d\n",i+1);
			else
			{
				ans=0;
				for(i=0;i<noOfDays;i++)
				{
					if(arr[i]>0)
					{
						ans=i;
					}
				}	
				printf("%d\n",ans+1);
			}
			//cout<<i+1<<endl;
		}
	}
	return(0);
}

//Tester Solution by Ashish Khatkar

//ID: ashish1610
//PROG: Aniruddha's Queue
//LANG: C++

#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		ll ar[n],cnt=0;
		for(int i=0;i<n;++i)
		{
			scanf("%lld",&ar[i]);
			cnt+=ar[i];
		}
		ll m;
		scanf("%lld",&m);
		m%=cnt;
		int ans;
		if(m==0)
		{
			for(int i=n-1;i>=0;--i)
			{
				if(ar[i]!=0)
				{
					ans=i;
					break;
				}
			}
		}
		else
		{
			for(int i=0;i<n;++i)
			{
				m-=ar[i];
				if(m<=0)
				{
					ans=i;
					break;
				}
			}
		}
		printf("%d\n",ans+1);
	}
	return 0;
}
*/

/*Best Submissions:
C:
#include <stdio.h>
 
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,j;
        scanf("%d",&n);
        int inp[n];
        long long sum=0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&inp[j]);
            sum+=inp[j];
        }
        long long m;
        scanf("%lld",&m);
        j=0;
        if(m>=sum)
        {
        m=m%sum;
        sum=0;
        if(m!=0)
        {
        while(sum<m)
        {
            if(j==n)
            j=0;
            sum+=inp[j];
            j++;
        }
        printf("%d\n",j);
        }
        else if(m==0)
        {
        j=n-1;
        while(inp[j]==0)
        j--;
        
            printf("%d\n",(j+1));
        }
        }
        else
        {
            sum=0;
            while(sum<m)
        {
            if(j==n)
            j=0;
            sum+=inp[j];
            j++;
        }
        printf("%d\n",j);
        }
    }
    return 0;
}

C++:
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
 
using namespace std;
typedef long long LL;
LL scan()
{
    LL n=0;
    LL ch=getchar_unlocked();
    while( ch <48 )ch=getchar_unlocked();
    while( ch >47 )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
}
int main()
{
    long long t,n,i,j,f,m,x,mx;
    //cin>>t;
    //scanf("%lld",&t);
    t=scan();
    while(t--)
    {
        //scanf("%lld",&n);
        n=scan();
        long long a[n],b[n];
        mx=0;
        for(i=0;i<n;i++)
        {
            //scanf("%lld",a+i);
            a[i]=scan();
            mx+=a[i];
        }
        //scanf("%lld",&m);
        m=scan();
        m = m%mx;
        if(m==0)
        {
            m=mx;
        }
        f=-1;
        b[0]=a[0];
        if(b[0]>=m)
        {
            //cout<<1<<endl;
            printf("1\n");
            continue;
        }
        for(i=1;i<n;i++)
        {
            b[i]=a[i]+b[i-1];
            if(b[i]>=m)
            {
                f=1;
                break;
            }
        }
        if(f==1)
        {
            printf("%lld\n",i+1);
            //cout<<i+1<<endl;
            continue;
        }
//        x=b[n-1];
//        while((x<<1)<m)
//        {
//            x=x<<1;
//        }
//        m=m-x;
//        //cout<<m<<endl;
//        while(m>x)
//        {
//            m = m-x;
//        }
//        //cout<<m<<endl;
//        LL lo=0,hi=n-1,mid;
//        while(1)
//        {
//            //if(lo>hi) break;
//            mid=lo + (hi-lo)/2;
//            if(mid==0 || (b[mid]>=m && b[mid-1]<m))
//            {
//                break;
//            }
//            if(b[mid]<m)
//            {
//                lo=mid+1;
//            }
//            else
//            {
//                hi=mid;
//            }
//        }
//
//        printf("%lld\n",mid+1);
        //cout<<i+1<<endl;
    }
    return 0;
}

C++14:
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
const int MAX = 1000010;
int n, t;
ll m;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	cin>>t;
	while(t--) {
		cin>>n;
		ll arr[n];
		ll sm = 0;
		for( int i = 0; i < n; i++ ) {
			cin>>arr[i];
			sm += arr[i];
		}
		cin>>m;
		m %= sm;
		if( m ) {
			int i = 0;
			while( i < n && m > 0 ) {
				m -= arr[i];
				i++;
			}
			cout<<i<<"\n";
		}
		else {
			int i = n-1;
			while( i >= 0 && !arr[i] ) {
				i--;
			}
			cout<<(i+1)<<"\n";
		}
	}
 
	return 0;
}

C#:
using System; 
using System.Numerics;
using System.Collections.Generic;
class MyClass {
    static void Main(string[] args) {
        int testCase = Convert.ToInt16(Console.ReadLine());
        while(testCase-- >0)
        {
        	int n = Convert.ToInt32(Console.ReadLine());
        	string[] numbers = Console.ReadLine().Split(' ');
        	long m = Convert.ToInt64(Console.ReadLine());
        	long travel = m;
        	List<long> distance = new List<long>(n+3);
        	long sum = 0;
        	int i =0;
        	int k =0;
        	for(;i<n;i++)
        	{
        		long temp = Convert.ToInt64(numbers[i]);
        		distance.Add(temp);
        		sum += temp;
        		m -= temp;
        		if(temp>0)
        		{
        			k = i+1;
        		}
        		if(m<1)
        		{
        			break;
        		}
        	}
        	sum *= travel/sum;
        	if(m<1||travel==sum)
        	{
        		Console.WriteLine(k);
        	}
        	else
        	{
        		m = travel % sum;
        		for(i=0;i<n;i++)
        		{
        			m = m - distance[i];
        			if(m<1)
        			{
        				Console.WriteLine(i+1);
        				break;
        			}
        		}
        	}
        }
    }
}

Java:
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        Reader r = new Reader();
        int T = r.nextInt();
        int N, input[], lastNonZeroIndex = 0;
        long M, sum, remainder;
        for(int i = 0; i < T; i++){
            N = r.nextInt();
            input = new int[N];
            sum = 0;
            for(int j = 0; j < N; j++){
                input[j] = r.nextInt();
                if(input[j] > 0){
                    sum += input[j];
                    lastNonZeroIndex = j + 1;
                }
            }
            M = r.nextLong();
            if(M != 0){
                remainder = M % sum;
                if(remainder > 0){
                    for(int k = 0; k < N; k++){
                        remainder -= input[k];
                        if(remainder < 1){
                            System.out.println(k + 1);
                            break;
                        }
                    }
                }
                else{
                    System.out.println(lastNonZeroIndex);
                }
            }
            else{
                System.out.println("0");
            }
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
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        Reader r = new Reader();
        int T = r.nextInt();
        int N, input[], lastNonZeroIndex = 0;
        long M, sum, remainder;
        for(int i = 0; i < T; i++){
            N = r.nextInt();
            input = new int[N];
            sum = 0;
            for(int j = 0; j < N; j++){
                input[j] = r.nextInt();
                if(input[j] > 0){
                    sum += input[j];
                    lastNonZeroIndex = j + 1;
                }
            }
            M = r.nextLong();
            if(M != 0){
                remainder = M % sum;
                if(remainder > 0){
                    for(int k = 0; k < N; k++){
                        remainder -= input[k];
                        if(remainder < 1){
                            System.out.println(k + 1);
                            break;
                        }
                    }
                }
                else{
                    System.out.println(lastNonZeroIndex);
                }
            }
            else{
                System.out.println("0");
            }
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

Java(Node.js):
function main(input) {
	var array = input.split("\n"), output = "", i, j, cases = array[0], n, xarr, m, xarrsum;
	for(i = 1; i < (cases*3) + 1; i+=3) {
		n = Number(array[i]);
		xarr = array[i+1].split(" ");
		xarrsum = 0;
		m = Number(array[i+2]);
		for(j = 0; j < xarr.length; j+=1) {
			xarrsum += Number(xarr[j]);
		}
		m%=xarrsum;
		if( m===0 ) {
			output+= (xarr.length - xarr.reverse().findIndex(function(inp){return Number(inp)>0;})) + "\n";
		}
		else {
			for(j = 0; j < xarr.length; j+=1) {
				m-= Number(xarr[j]);
				if(m <= 0) {
					output+= (j+1).toString() + "\n";
					break;
				}
			}
		}
	}
    process.stdout.write(output);
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
 

PHP:
<?php

// Sample code to perform I/O:
//fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
//echo "Hi, ".$name.".\n";                // Writing output to STDOUT
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
// Write your code here
fscanf(STDIN, "%s\n", $test);
for($i=0;$i<$test;$i++){
    fscanf(STDIN, "%s\n", $days);
    fscanf(STDIN, "%[^\n]", $distance);
    fscanf(STDIN, "%s\n", $target);
    $distarray = explode(' ',$distance);
    $sumarray = array_sum($distarray);
    $rem = $target%$sumarray;
    $sum = 0;
    for($j=0;$j<$days;$j++){
        if($rem == 0){
            $sum = $sum + $distarray[$j];
            if($sum == $sumarray){
                $out = $j+1;
                print_r($out."\n");
                break;
            }
            continue;
        }
        $sum = $sum + $distarray[$j];
        if($sum >= $rem){
            $out = $j+1;
            print_r($out."\n");
            break;
        }
        if($j == $days-1){
            $j = -1;
        }
    }
}
?>

Python:
t=int(raw_input())
while t:
	a=int(raw_input())
	b=map(int,raw_input().split())
	d=int(raw_input())
	c=d%sum(b)
	if(c==0):
		c=sum(b)
	i=0
	while True:
		if((c-b[i])<=0):
			print i+1
			break
		else:
			c=c-b[i]
		i=i+1
		if(i==a):
			i=0
	t=t-1

Python 3:
t=int(input())
import sys
for i in range(t):
    nos=int(input())
    steps=list(map(int,sys.stdin.readline().split()))
    ms=int(input())
    z=0
    sumi=0
    totalsum=sum(steps)
    tobedone=ms%totalsum
    if tobedone==0:
        for j in range(len(steps)-1,-1,-1):
            if steps[j]!=0:
                val=j
                break
    else:    
        for j in range(len(steps)):
            sumi+=steps[j]
            if sumi>=tobedone:
                val=j
                break
    print(val+1)

Ruby:
t = gets.to_i
t.times do
    no_days = gets.to_i
    day_distance = gets.chomp.split(' ').map(&:to_i)
    milestone = gets.to_i
    
    year_distance = day_distance.inject(:+)
    milestone = milestone%year_distance
    milestone = year_distance if milestone == 0
    i = 0
    
    #puts "no_days = #{no_days}, day_distance = #{day_distance}, milestone = #{milestone}"
    while milestone > 0 do
        #puts "milestone = #{milestone}, day_distance[#{i-1}] #{day_distance[i-1]}"
        milestone -= day_distance[i]
        i += 1
    end
    puts i
end

*/
