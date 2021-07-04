/* All Tracks ---> Data Structures ---> Arrays ---> 1-D ---> Problem
Mark The Answer
Tag(s): Data Structures, Easy

Our friend Monk has an exam that has quite weird rules. Each question has a difficulty level in the form of an Integer. Now, Monk can only solve the problems that have difficulty level less than X . Now the rules are-

Score of the student is equal to the maximum number of answers he/she has attempted without skipping a question.
Student is allowed to skip just "one" question that will not be counted in the continuity of the questions.
Note- Assume the student knows the solution to the problem he/she attempts and always starts the paper from first question.

Given the number of Questions, N ,the maximum difficulty level of the problem Monk can solve , X ,and the difficulty level of each question Ai,  can you help him determine his maximum score?

Input Format:
First Line contains Integer N , the number of questions and the maximum difficulty X Monk can solve.
Next line contains N integers,Ai  denoting the difficulty level of each question.

Output Format:
Maximum score Monk can achieve in the exam.

Constraints
1<=N<=10^5
1<=X<=10^9
1<=Ai<=10^9

SAMPLE INPUT 
7 6
4 3 7 6 7 2 2
SAMPLE OUTPUT 
3

Explanation:
In this example, maximum difficulty = 6, Monk solves question 0 and 1, but skips the question 2 as A[2]>6. Monk then solves the question 3 , 
but stops at 4 because A[4]>6 and question 2 was already skipped. As 3 questions (0,1 and 3) were solved and 2 questions (2 and 4) have been skipped, therefore we print "3".


My C solution:
#include <stdio.h>
#define N 100001

int main()
{
    long long int A[N],X, n,cnt,skip,i;
    scanf("%lld",&n);
    scanf("%lld",&X);
    cnt=0;
    skip=0;
    for(i=0;i<n;i++){
        scanf("%lld",&A[i]);
        if(A[i]<=X){
            if(skip<=1)
                cnt++;
            else
                break;
        }
        else if(A[i]>X)
            skip=skip+1;
    }
    printf("%lld\n",cnt);
    return 0;
}

My Cpp solution:
#include <iostream>
#define N 100001
using namespace std;

int main()
{
    long long int A[N],X,n,cnt,skip,i;
    cin>>n;
    cin>>X;
    cnt=0;
    skip=0;
    for(i=0;i<n;i++){
        cin>>A[i];
        if(A[i]<=X){
            if(skip<=1)
                cnt++;
            else
                break;
        }
        else if(A[i]>X)
            skip=skip+1;
    }
    cout<<cnt;
    return 0;
}

*/


/*

Problem Statement:
Monk is attempting a test which has N questions. The number of questions he answers correct is the score he gets. He always has to start answering from starting of the question paper and he is allowed to skip atmost one question. Now given the difficulty level X upto which Monk can answer correctly and difficulty levels of each question in the order, find the Monk's score.

Explanation:
Start from index 0 iterate over the array of difficulty levels. Count the number of elements until you encounter an element whose value is greater than X and store the result in P. Skip this number and start from the index next to index having X. Again start counting the number of elements until you encounter an element whose value is greater than X and store the result in Q. At any point of iteration make sure you are not trying to access the index that are >=N.

Required result is P+Q. Complexity of solution O(N).

Author Solution by Pulkit Kapoor:

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d;
    cin>>n>>d;
    
    bool flag=false;
    int ans=0;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    for(int i=0;i<n;i++)
    {
        if(vec[i]>d)
        {
            if(flag==false)
            {
                flag=true;
                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}


Tester Solution by Vinay Kumar:

n,d = map(int,raw_input().split(' '))
assert(n >= 1 and n <= 10**5 and d >= 1 and d <= 10**9)
a = map(int,raw_input().split(' '))
for i in range(0,n):
	assert(a[i] >= 1 and a[i] <= 10**9)
prev = 0
curr = 0
i = 0
while i < n and a[i] <= d:
 	prev+=1
 	i+=1
i+=1
while i < n and a[i] <= d:
	curr+=1
	i+=1
print prev+curr

*/

/*Best Submissions:
C:
#include<stdio.h>
int main ()
{
  unsigned long int n,m;
  //printf("enter the no. of ques and difficulty level");
  scanf(" %lu %lu",&n,&m);
  unsigned long int a[n],i;
  //printf("enter the value of diif");
  for(i=0;i<n;i++)
  {
     scanf("%lu",&a[i]);
  }
  unsigned long int j=0,k=0;
  for (i=0;i<n;i++)
  {
    if(a[i]>m)
    {
      j++;
    }
    if(a[i]<=m&&j<2)
    {
      k++;
    }
    
  }
  printf("%lu",k);
 
 return 0;
 
}

C++:
#include <iostream>
using namespace std;
 
int main() {
	int i,n,a[100000],count=0,g=0,x;
	cin>>n;
	cin>>x;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		
		
	}
	 
	for(i=0;i<n;i++)
	{
		if(x>=a[i])
		{ count++;
		 
		
			
		}else {
			break;
		}
	}
 
	for(i=count+1;i<n;i++)
	{
		if(x>=a[i])
		{ g++;
		
		
			
		}else {
			break;
		}
	}
	
	cout<<count+g;
	
	return 0;
}

C++14:
#include<iostream>
using namespace std;
int main()
{
    int n;
cin>>n;
int k;
cin>>k;
int a[n];
int i;
for(i=1;i<=n;i++)
{
    cin>>a[i];
}
int c=0;
int b=1;
int j;
for(j=1;j<=n;j++)
{
    if(a[j]<=k)
    {
        c++;
    }
    else
    {
        if(b==1)
        {
            j=j;
            b++;
        }
        else
        {
            break;
        }
    }
 
}
cout<<c<<endl;
 
}

C#:
using System; 
using System.Numerics;
class MyClass {
    static void Main(string[] args) {
        string[] NX = Console.ReadLine().Split(' ');
        int N = int.Parse(NX[0]);
        int X = int.Parse(NX[1]);
        int count = 0;
        string[] numlist = Console.ReadLine().Split(' ');
        int[] nums = new int[N];
        bool flag = false;
        for(int i = 0; i < numlist.Length; i++){
        	nums[i] = int.Parse(numlist[i]);
        }
        for(int i = 0; i < nums.Length; i++){
        	if(nums[i] <= X && !flag){
        		count++;
        	}
        	else if(nums[i] > X && !flag){
        		flag = true;
        		continue;
        	}
        	if(flag == true){
        		if(nums[i] <= X){
        			count++;
        		}
        		else{
        			break;
        		}
        	}
        }
        Console.WriteLine(count);
    }
}

Java:
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
 
public class MarkAnswer {
 
	public static void main(String[] args) throws IOException {
		Reader2 sc=new Reader2();
		int n=sc.nextInt();
		int x=sc.nextInt();
		int difficulty=0;
		int count=0;
		boolean skip=false;
		for(int i=0;i<n;i++){
			difficulty=sc.nextInt();
			if(difficulty<=x){
				count++;
			}else{
				if(skip){
					break;
				}
				skip=true;
			}
		}
		System.out.println(count);
	}
 
}
class Reader2
{
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;
 
    public Reader2()
    {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }
 
    public Reader2(String file_name) throws IOException
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

Java 8:
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.*;
 
 
class TestClass {
    public static void main(String args[] ) throws Exception {
       Reader s = new Reader();
       int N = s.nextInt();
       int l = s.nextInt();
       int max = Integer.MIN_VALUE;
       int currStreak = 0;
       int skip = 0;
       while(N-- >0){
           int curr = s.nextInt();
           if(curr<=l&&skip<=1){
               currStreak++;
           }else{
               if(skip<1){
                   skip++;
               }else{
                   skip++;
                   max = Math.max(currStreak,max);
                   currStreak = 0;
                   break;
               }
           }
       }
       max = Math.max(currStreak,max);
       System.out.println(max);
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
    //Enter your code here
    //process.stdout.write("Hello World!");
    
    //console.log(input);
    var arr = input.split("\n");
   // console.log(arr);
   var data = arr[0].split(' ').map(Number);
   var N = data[0];
  // console.log(N);
   var Max = data[1];
   
   var posibleskip = [];
   var num = arr[1].split(" ").map(Number);
   
   var skips =0;
   var max =0;
   
   for(var i=0; i<N; i++){
       
       if(num[i]<= Max){
           max ++
            //console.log(num[i])
       }
       else{
           skips ++;
           if(skips >1){
               console.log(max);
               return 
           }
       }
      
   }
   console.log(max);
   
   
   //console.log(data)
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
 
Pascal:
const	fi	=	'Mark.inp';
	maxN	=	trunc(1e5);
type	int	=	longint;
var	n,X,res,m,i,c	:	int;
	a 	:	array[1..maxN]	of	int;
{}
procedure laymax(var a: int; b: int);
begin
	if a<b then a:=b;
end;
{}
BEGIN
	//assign(input,fi);	reset(input);
	readln(n,x);
	m := 1;a[2]:=0;
	for i:=1 to n do
	  begin
		read(c);
		if c<=X then inc(a[m])
		 else begin inc(m); a[m]:= 0; end;
	  end;
	res := a[1]+a[2];
	writeln(res);
END.

Perl:
use strict;
use warnings;
 
chomp(my $line = <STDIN>);
my ($nums,$max_dif) = split ' ', $line;
chomp($line = <STDIN>);
my @arr = split ' ', $line;
my $score = 0;
my $skipped;
foreach my $val (@arr) {
    if($val > $max_dif) {
        last if $skipped;
        $skipped = 1;
    } else {
        $score++;
    }
}
print $score;


PHP:
<?php
$input = trim(fgets(STDIN));
$arr = explode(" ", $input);      
$n=$arr[0];
$x=$arr[1];
$temp=0;
$c=0;
$input = trim(fgets(STDIN));
$arr = explode(" ", $input);    
foreach($arr as &$number){
    $q = (int)$number;
    if($temp<=1)
   	{
    	if($q<=$x)
    		$c++;
    	else
    		$temp++;
    }
}
echo $c;
?>

Python:
'''
# Read input from stdin and provide input before running code
 
name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
#print 'Hello World!'
n = raw_input()
noQues = int(n.split()[0])
maxDifficulty = int(n.split()[1])
 
arrStr = raw_input()
arr = arrStr.split()
arr = [ int(x) for x in arr ]
count = 0
skip = 0
for i in arr:
	if i > maxDifficulty:
		skip = skip + 1
	else:
		count = count +1
	if skip >= 2:
		break
	
print count

Python 3:
# n : number of questions
# x : max dif level that monk can solve
# ar = dif level of each questions
 
# rules :
# student is allowed to skip one question
# score = max number of questions solved without skipping
 
''' 
input
First Line contains Integer N , the number of questions and the maximum difficulty X Monk can solve.
Next line contains N integers, Ai denoting the difficulty level of each question.
'''
n,k = input().split()
n = int(n)
k = int(k)
 
 
ar = input().split()
for x in range(len(ar)):
    ar[x] = int(ar[x])
 
score = 0
brk = len(ar)
for x in range(len(ar)):
    if ar[x] <= k :
        score += 1
    else :
        brk = x
        break
 
for x in range(brk+1,len(ar)):
    if ar[x] <= k:
        score += 1
    else :
        break
print(score)


Ruby:
ques,diff = gets.chomp.split(" ")
ques = ques.to_i
diff = diff.to_i
a = gets.chomp.split(" ")
res = []
count1,count2 = 0,0
index = 0
i = 0
for i in 0...a.size
    if a[i].to_i > diff
        index = i
        break
    else
        count1 += 1
    end
end
 
if i == a.size-1
    puts count1
else
    for i in index+1...a.size
        if a[i].to_i > diff
            break
        else
            count2 += 1
        end
    end
    puts count1+count2
end

*/
