/* All Tracks --> Data Structures --> Arrays --> 1-D  --> Problem
Monk and Power of Time
Tag(s): Data Structures, Easy, Queue
The Monk is trying to explain to its users that even a single unit of time can be extremely important and to demonstrate this particular fact he gives them a challenging task.
There are N processes to be completed by you, the chosen one, since you're Monk's favorite student. All the processes have a unique number assigned to them from 1 to N.

Now, you are given two things:
The calling order in which all the processes are called.
The ideal order in which all the processes should have been executed.
Now, let us demonstrate this by an example. Let's say that there are 3 processes, the calling order of the processes is: 3 - 2 - 1. The ideal order is: 1 - 3 - 2, i.e.,
process number 3 will only be executed after process number 1 has been completed; process number 2 will only be executed after process number 3 has been executed.

Iteration #1: Since the ideal order has process #1 to be executed firstly, the calling ordered is changed, i.e., the first element has to be pushed to the last place. 
Changing the position of the element takes 1 unit of time. The new calling order is: 2 - 1 - 3. Time taken in step #1: 1.

Iteration #2: Since the ideal order has process #1 to be executed firstly, the calling ordered has to be changed again, i.e., the first element has to be pushed to the last place. 
The new calling order is: 1 - 3 - 2. Time taken in step #2: 1.

Iteration #3: Since the first element of the calling order is same as the ideal order, that process will be executed. And it will be thus popped out. Time taken in step #3: 1.

Iteration #4: Since the new first element of the calling order is same as the ideal order, that process will be executed. Time taken in step #4: 1.

Iteration #5: Since the last element of the calling order is same as the ideal order, that process will be executed. Time taken in step #5: 1.

Total time taken: 5 units.
PS: Executing a process takes 1 unit of time. Changing the position takes 1 unit of time.

Input format:
The first line a number N, denoting the number of processes. The second line contains the calling order of the processes. The third line contains the ideal order of the processes.

Output format:
Print the total time taken for the entire queue of processes to be executed.

Constraints: 
1<=N<=100

SAMPLE INPUT 
3
3 2 1
1 3 2
SAMPLE OUTPUT 
5

// My C Solution:
#include <stdio.h>
#define N 101

int main()
{
    int org[N],ide[N],i,j,n,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&org[i]);
    for(j=0;j<n;j++)
        scanf("%d",&ide[j]);
    j=0;
    for(i=0;i<n;){
            if(org[j]==-1){
                j=(j+1)%n;
                continue;
            }
            if(org[j]==ide[i]){
                ++cnt;
                org[j]=-1;
                i++;
            }
            else
                ++cnt;
        j =(j+1)%n;
    }
    printf("%d",cnt);
    return 0;
}

*/



/* Editorial:

Monk and power of time - EDITORIAL
Author : Chandan Singh 
Tester : Deepankar Anil Kumar 
Editorialist : Deepankar Anil Kumar

Difficulty : Easy

Pre-Requisites : Queue

Problem : Given N processes , and the order in which they are called and the order in which they have to executed. Find the time taken to execute all of them in the execution order given.

Explanation :

Now , the solution of this problem is straight simulation , where we have to simulate as the statement dictates.

For simulating it we can use queue data structure . First push the tasks in the queue Q in the order in which they were called. Now , iterate through the queue from the front , and check whether the current process in the queue matches with the first process in the order of execution if it matches then execute it other wise send the process in the front of the queue and again repeat this process.

The pseudo code for this solution would be :

Q = queue containing the processes in the order they were called
time = 0
while Q is not empty :
     time = time + 1
     x = process in front of Q
     if x == current process in execution order :
            remove  x from Q
     else :
            move the x from front to the back of the Q
The complexity of this algorithm will be O(N^2) for the worst case scenario , such as this :

Call order = 1 2 3 4 5 Execution order = 5 4 3 2 1

Time Complexity: O(N^2)

Author Solution by Chandan Singh
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N,Num;
	cin>>N;
	queue<int> Q;
	for(int i=0;i<N;i++)
	{
		cin>>Num;
		Q.push(Num);
	}
	int a[N];
	for(int i=0;i<N;i++)
		cin>>a[i];
	int total_time = 0, executed_job = 0;
	while(!Q.empty())
	{
		int job = Q.front();
		if(job == a[executed_job]){
			Q.pop();
			total_time++;
			executed_job++;
		}
		else
		{
			Q.pop();
			Q.push(job);
			total_time++;
		}
	}
	cout<<total_time<<endl;
	return 0;
}

Another C++ Solution:
#include <iostream>
using namespace std;
 
void shift_array(int *p, int n)
{
	int j;
   	for(j = 0; j < n-1; j++)
   	{
   		p[j] = p[j+1];
	}	
}
 
int main()
{
    int N, i, NN, j, push, time_count;
 
    cin>>N;
    time_count = 0;
    
    int ideal[100] = {0};
    int calling[100] = {0};
    
    for(i = 0; i < N; i++)
    	cin>>calling[i];
    
    for(i = 0; i < N; i++)
    	cin>>ideal[i];
    
    NN = N;
    i = 0;
   
    while(NN > 0)
    {
    	if(ideal[i] == calling[0])
    	{
			shift_array(calling, NN);
			NN--;
			time_count++;
			i++;
    	}
    	else
    	{
    		push = calling[0];
			shift_array(calling, NN);
			calling[NN - 1] = push;
			time_count++;
    	}
    }
    cout<<time_count;
    return 0;
}

Another Java Solution:
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
 
 
public class Task {
	private Queue<Integer> idealQueue;
	private Queue<Integer> inputQueue;
	
	public Task(String input, String ideal) throws Exception {
		idealQueue = new Queue<Integer>(Integer.class);
		inputQueue = new Queue<Integer>(Integer.class);
		populateQueue(ideal, idealQueue);
		populateQueue(input, inputQueue);
	}
	
	private void populateQueue(String data, Queue<Integer> queue) throws Exception {
		String [] inputs = data.split("\\s+");
		for(String input : inputs) {
			queue.enqueue(Integer.parseInt(input));
		}
	}
	
	public int scheduleAndComplete() throws Exception {
		int timeUnit = 0;
		
		while(!idealQueue.isEmpty() || !inputQueue.isEmpty()) {
			if(idealQueue.peek() == inputQueue.peek()) {
				idealQueue.dequeue();
				inputQueue.dequeue();
				timeUnit++;
			}
			else {
				inputQueue.enqueue(inputQueue.dequeue());
				timeUnit++;
			}
		}
		
		return timeUnit;
	}
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N  = Integer.parseInt(br.readLine());
		Task task = new Task(br.readLine(), br.readLine());
		
		System.out.println(task.scheduleAndComplete());
		
 
	}
	
	public class Queue<T> {
 
	    private static final int SPECIAL_EMPTY_VALUE = -1;
	    private static final int MAX_SIZE = 100;
	    private T[] elements;
 
	    private int headIndex = SPECIAL_EMPTY_VALUE;
	    private int tailIndex = SPECIAL_EMPTY_VALUE;
 
	    public Queue(Class<T> clazz) {
	        this(clazz, MAX_SIZE);
	    }
 
	    @SuppressWarnings("unchecked")
		public Queue(Class<T> clazz, int size) {
	        elements = (T[]) Array.newInstance(clazz, MAX_SIZE);
	    }
 
	    public void enqueue(T data) throws QueueOverflowException {
	        if (isFull()) {
	            throw new QueueOverflowException();
	        }
	        tailIndex = (tailIndex + 1) % elements.length;
	        elements[tailIndex] = data;
 
	        // This is the first element enqueued, set the head index
	        // to the tail index.
	        if (headIndex == SPECIAL_EMPTY_VALUE) {
	            headIndex = tailIndex;
	        }
	    }
 
	    public boolean offer(T data) {
	        if (isFull()) {
	            return false;
	        }
	        try {
	            enqueue(data);
	        } catch (QueueOverflowException qoe) {
	            
	        }
 
	        return true;
	    }
 
 
	    public T dequeue() throws QueueUnderflowException {
	        if (isEmpty()) {
	            throw new QueueUnderflowException();
	        }
 
	        T data = elements[headIndex];
 
	        // This was the last element in the queue.
	        if (headIndex == tailIndex) {
	            headIndex = SPECIAL_EMPTY_VALUE;
	        } else {
	            headIndex = (headIndex + 1) % elements.length;
	        }
 
	        return data;
	    }
 
	    public T peek() throws QueueUnderflowException {
	        if (isEmpty()) {
	            throw new QueueUnderflowException();
	        }
 
	        return elements[headIndex];        
	    }
 
	    public boolean isEmpty()  {
	        return headIndex == SPECIAL_EMPTY_VALUE;
	    }
 
	    public boolean isFull()  {
	        int nextIndex = (tailIndex + 1) % elements.length;
 
	        return nextIndex == headIndex;
	    }
 
	   
	}
	
	 public static class QueueOverflowException extends Exception {
	    }
 
	    public static class QueueUnderflowException extends Exception {
	    }
 
 
}

Another one Java Solution:
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int N = Integer.parseInt(line);
        String s1=br.readLine();
        String s2=br.readLine();
        String p[]=s1.split(" ");
        String q[]=s2.split(" ");
        Queue<String> qe=new LinkedList<String>();
        for(int i=0;i<q.length;i++)
        qe.add(p[i]);
        int j=0,k=0;
        while(!qe.isEmpty()){
        	if(qe.peek().equals(q[j])){
        	qe.poll();
        	j++;
        	k++;}
        	else{
        		String b= qe.peek();
        		qe.poll();
        		qe.add(b);
        		k++;
        	}
        }
        System.out.println(k);
    }
}


*/


/*
Input #1
5
5 4 2 3 1
5 2 1 4 3
Output #1
7
Input #2
10
5 4 8 9 1 6 3 2 7 10
1 6 8 9 5 4 10 3 2 7
Output #2
27
Input #3
15
5 11 12 13 15 6 14 2 7 10 4 8 9 3 1
4 15 8 2 6 9 11 10 7 5 13 14 3 1 12
Output #3
75
Input #4
30
5 29 12 16 25 17 18 30 27 10 4 23 20 3 1 24 26 19 14 9 6 22 8 13 15 21 28 7 11 2
17 20 6 18 21 5 22 24 28 7 23 3 27 19 10 30 15 25 12 16 2 1 11 9 4 8 29 14 13 26
Output #4
226
Input #5
40
5 29 12 16 25 36 18 37 27 32 34 40 20 3 1 24 26 19 33 9 6 22 8 13 15 21 28 7 11 2 31 39 14 38 4 17 30 35 10 23
14 39 4 5 23 7 40 8 36 17 30 21 3 35 33 32 12 16 20 25 31 13 22 34 19 18 29 11 27 15 1 38 26 6 28 10 9 37 2 24
Output #5
491
Input #6
60
5 52 12 16 25 36 18 37 27 51 34 40 20 3 48 57 60 19 33 41 6 22 58 13 15 43 28 7 46 59 31 39 14 38 4 55 56 54 10 23 9 24 21 35 2 11 32 1 47 42 49 29 53 44 17 30 50 8 45 26
55 15 44 60 7 33 14 27 16 1 25 59 48 18 35 39 30 37 11 34 45 17 22 28 21 5 23 41 51 26 13 19 36 3 12 24 53 43 38 4 10 31 57 20 29 49 2 6 46 56 40 52 54 42 47 9 58 8 50 32
Output #6
1056
Input #7
70
5 52 12 70 25 36 18 37 27 51 68 40 20 3 48 57 60 19 33 41 6 22 58 13 15 43 28 63 64 59 31 39 14 69 4 55 56 65 10 23 67 24 21 35 2 11 32 1 47 42 66 29 53 44 17 61 50 8 45 26 30 62 7 46 54 49 9 34 38 16
46 8 20 39 51 34 59 22 21 5 66 41 11 65 33 44 2 40 68 31 58 50 23 29 4 38 17 49 30 48 67 18 27 62 60 26 14 64 28 7 56 12 63 16 69 35 43 15 36 45 55 19 54 61 9 3 37 1 53 10 47 52 42 24 32 6 57 70 25 13
Output #7
1515
Input #8
80
5 52 12 70 25 36 18 37 27 51 68 40 20 3 76 57 60 19 33 41 6 22 58 13 15 43 28 63 64 59 31 79 14 69 4 55 72 65 10 23 67 24 21 80 2 75 74 1 47 42 66 29 53 44 17 61 50 8 45 73 30 62 7 46 54 77 9 34 38 16 26 56 71 32 78 48 49 11 39 35
38 51 9 47 3 45 72 46 30 23 13 35 52 80 70 39 14 75 62 29 55 78 17 73 67 42 60 10 7 24 50 26 20 61 33 76 2 21 16 15 22 32 43 18 41 28 79 48 68 36 12 27 54 49 6 34 64 31 53 19 57 58 74 40 44 63 59 37 69 5 8 1 77 11 25 4 71 65 66 56
Output #8
1733
Input #9
90
5 52 12 70 25 36 18 37 27 51 68 40 84 3 76 57 60 19 33 41 6 87 58 13 15 43 28 63 64 59 31 79 14 69 4 88 72 65 10 23 67 81 21 80 90 82 74 1 47 42 89 29 53 44 17 61 50 8 85 73 30 62 7 46 54 77 9 34 38 16 26 56 71 32 83 48 49 11 39 35 24 75 78 20 86 45 22 55 66 2
3 15 86 44 14 46 32 58 53 69 20 56 50 88 83 62 80 34 19 81 31 65 45 26 10 74 72 22 9 38 64 7 90 42 18 30 78 39 21 63 36 54 84 47 24 85 82 68 48 67 37 25 28 61 60 49 29 23 57 55 35 16 4 1 5 12 13 17 59 70 33 66 41 51 11 73 6 76 52 8 89 87 75 43 71 2 79 77 40 27
Output #9
2304
Input #10
100
93 52 12 70 25 36 18 37 27 99 68 40 84 3 76 57 60 19 33 41 92 87 58 13 15 43 28 63 64 59 31 97 14 69 4 88 72 65 10 23 67 81 21 80 90 82 74 1 95 42 89 29 53 44 17 61 50 8 85 73 30 62 7 46 54 77 9 34 38 16 26 56 71 32 83 48 49 11 91 35 24 75 78 20 86 45 94 55 98 2 39 96 5 22 100 6 79 66 51 47
40 6 94 44 48 5 28 68 77 78 18 47 4 92 37 30 10 50 42 38 100 88 31 65 32 8 81 82 49 27 60 29 69 41 70 1 33 87 26 54 89 67 39 12 99 24 34 14 51 64 53 11 15 23 58 63 43 71 74 22 97 2 83 55 93 98 80 79 84 72 45 36 75 95 61 56 25 86 9 91 35 76 66 7 73 3 90 21 57 59 52 17 62 96 16 85 19 13 46 20
Output #10
2615
*/

/* Best Submissions:
C:
#include <stdio.h>
 
int main()
{
   int n,a[100],i,id[100],t=0,k,l,j,si,diff,pre;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
   	scanf("%d",&a[i]);
   }
   for(i=0;i<n;i++)
   {
   	scanf("%d",&id[i]);
   }
   for(j=0;j<n;j++)
   {
   	si=j;
   	for(i=j;i<n;i++)
   	{
   		if(a[i]==id[j])
   		{
   		diff=i-si;
   		l=si;
   		for(k=0;k<diff;k++)
   		{
   			l=si;
   			pre=a[si];
   			while(l<=n-1)
   			{
   			a[l]=a[l+1];
   			l++;
   			}
   			a[n-1]=pre;
   		}
   		//for(i=0;i<n;i++)
	 //	{
//   	printf("%d ",a[i]);
//		 }
 
			t=t+diff+1;
   		}
   	//	t++;
   	}
   }
   printf("%d",t);
    return 0;
}

C++:
#include<iostream>
using namespace std;
void iter(int *A,int n)
{
  int i,temp=A[0];
  for(i=1;i<n;i++)
  A[i-1]=A[i];
  A[n-1]=temp;
}
//work in a circular queue
int main()
{
  int n,i,k=0;
  cin>>n;
  int *A,B[n],*p;
  A=new int[n];
  p=A;
  for(i=0;i<n;i++)
  	cin>>A[i];
  for(i=0;i<n;i++)
    cin>>B[i];
  i=0;  
  while(i<n)
  {  
  while(A[0]!=B[i])  
  {
  iter(A,n-i);
  k++;
  }
  k++;
  A++;
  i++;
  }
  delete[] p;  
  cout<<k;
  return 0;
}

C++14:
#include<bits/stdc++.h>
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define mp(a,b) make_pair(a,b)
#define popb(a) pop_back(a)
#define popf(a) pop_front(a)
typedef long long int lli ;
typedef long long ll;
using namespace std;
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n;
cin>>n;
list <int> call,ideal;
int ent;
for(int i=0;i<n;++i)
{
cin>>ent;
call.pb(ent);
}
for(int i=0;i<n;++i)
{
cin>>ent;
ideal.pb(ent);
}
long time=0;
while(ideal.size()!=0)
{
if(*ideal.begin()==*call.begin())
{
	ideal.popf();
	call.popf();
}
else
{
 
	rotate(call.begin(),++call.begin(),call.end());
}
time+=1;	
}
cout<<time<<"\n";
return 0;
}

C#:
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
class MyClass {
    static int count;
    static void Main(string[] args)
    {
 
      count = Convert.ToInt16(System.Console.ReadLine());
      char[] splitChar = new char[] { ' ' };
 
     
      string[] temp = (System.Console.ReadLine()).Split(splitChar, StringSplitOptions.RemoveEmptyEntries).ToArray();
      Queue<int> actualOrder = new Queue<int>();
     
      foreach (string sNum in temp)
        actualOrder.Enqueue(Convert.ToInt16(sNum));
temp=null;
 
       temp = (System.Console.ReadLine()).Split(splitChar, StringSplitOptions.RemoveEmptyEntries).ToArray();
       Queue<int> prefOrder = new Queue<int>();
     
      foreach (string sNum in temp)
        prefOrder.Enqueue(Convert.ToInt16(sNum));
temp=null;
 
      int actualRemoved;
      int unitOfWork=0;
      while (actualOrder.Count != 0)
      {
        if (actualOrder.Peek() != prefOrder.Peek())
        {
          unitOfWork++;
          actualRemoved = actualOrder.Dequeue();
          actualOrder.Enqueue(actualRemoved);
        }
        else
        {
          unitOfWork++;
          actualOrder.Dequeue();
          prefOrder.Dequeue();
        }
      }
 
 
 
      System.Console.WriteLine(unitOfWork);
      System.Console.ReadLine();
    }
}


Java:
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
 
public class MonkandPowerofTime {
 
	public static void main(String[] args) {
		
		BufferedReader bufferedReader=new BufferedReader(new InputStreamReader(System.in));
		
		try {
			int process=Integer.parseInt(bufferedReader.readLine());
			
			String[] input1=bufferedReader.readLine().split(" ");
			String[] input2=bufferedReader.readLine().split(" ");
			
			Queue<Integer> queue=new LinkedList<>();
			int[] numbers=new int[process];
			
			for(int i=0;i<process;i++){
				queue.add(Integer.parseInt(input1[i]));
				numbers[i]=Integer.parseInt(input2[i]);
				
			}
			
			int count=0;
			int result=0;
			while(result<process){
				
				int value=numbers[result];
				int queueValue=queue.peek();
				if (value==queueValue) {
					//System.out.println("M:"+value+" :"+queueValue);
					
					result++;
					count++;
					
					queue.poll();
				}
				
				else {
					int v=queue.poll();
					//System.out.println("Poll:"+v);
					
					queue.add(v);
					count++;
				}
				
				
				
				
				
			}
			
			System.out.println(count);
			
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
 
	}
 
}

Java 8:
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
 
 
// IMPORTANT: Multiple classes and nested static classes are supported
//uncomment this if you want to read input.
//import java.io.BufferedReader;
//import java.io.InputStreamReader;

class TestClass {
    public static void main(String args[] ) throws Exception {
        
        //Read input from stdin and provide input before running
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String line = br.readLine();
        //int N = Integer.parseInt(line);
        //for (int i = 0; i < N; i++) {
        //    System.out.println("hello world");
        //}
        //
 
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Queue<Integer> queue = new LinkedList<Integer>();
        for(int i=0;i<n;i++){
        	queue.add(sc.nextInt());
        }
        int[] correct = new int[n];
        for(int i=0;i<n;i++){
        	correct[i] = sc.nextInt();
        }
        int time = 0;
        for(int i=0;i<n;i++){
        	int num = correct[i];
        	int a;
        	while((a = queue.poll())!=num){
        		queue.add(a);
        		time++;
        	}
        	time++;
        }
        System.out.println(time);
 
    }
}
Pascal:
Program HiHere;
VAR n,i,j,t,aux,aux2:int64; a,id:array[1..102] of int64;
Begin
Readln(n);
for i:=1 to n do
Begin
Read(a[i]);
end;
Readln;
for i:=1 to n do
Begin
Read(id[i]);
end;
i:=1;
 
while (i <= n) do
Begin
while (a[i] <> id[i]) do
Begin
 
a[n + 1]:=a[i];
for j:=i to n do
Begin
a[j]:=a[j + 1];
end;
t:=t + 1;
 
end;
 
i:=i + 1;
t:=t + 1;
end;
Writeln(t);
Readln;
END.

Perl:
use strict;
use Data::Dumper;
 
# Read input from stdin and provide input before running code
my $inputhash = {};
# Echo input to output.
my $count = 0;
 
$inputhash->{NUMBER} = <STDIN>;
 
$inputhash->{ELEMENTS} = [split (" ",<STDIN>)];
 
$inputhash->{ORDER} = [split (" ",<STDIN>)];
 
 
 
my $verifyelements = have_same_elements($inputhash);
if($verifyelements) {
	my	$cost = CalculateCost($inputhash);
	print "$cost";
}
 
sub have_same_elements {
    my ($args) = @_;
    my %counts = ();
    $counts{$_} += 1 foreach (@{$args->{ORDER}});
    $counts{$_} -= 1 foreach (@{$args->{ELEMENTS}});
    return !(grep { $_ != 0 } values %counts);
}
sub CalculateCost {
	my ($args) = @_;
	my $totalcost = 0;
	my $count1 = 0;
	my @array = @{$args->{ORDER}};
	while(scalar @{$args->{ORDER}} >0) {
		if($args->{ELEMENTS}->[0] == $args->{ORDER}->[0]) {
			shift @{$args->{ORDER}};
			shift @{$args->{ELEMENTS}};
			$totalcost++;
		}
		else {
			my $last = shift @{$args->{ELEMENTS}};
			push(@{$args->{ELEMENTS}},$last);
			$totalcost = $totalcost + 1;
		}
	}
	return $totalcost;
}
 
PHP:
<?php
 

//Read input from stdin and provide input before running code
//fscanf(STDIN, "%s\n", $name);
//echo "Hi, ".$name;
 
function shift(&$arr,$front) {
	$arr[] = $arr[$front];
	$arr[$front] = 0;
}
function pop(&$arr, $front) {
	$arr[$front] = 0;
}
$tc = trim(fgets(STDIN));
$front = 0;
$rear = $tc-1;
$queue = explode(" ", trim(fgets(STDIN)));
$ideal = explode(" ", trim(fgets(STDIN)));
$out = 0;
while(1) {
	if($queue[$front]==$ideal[0]) {
		pop($queue, $front);
		array_shift($ideal);
		$front++;
	} else {
		shift($queue, $front);
		$front++;
		$rear++;
	}
	$out++;
	if(count($ideal) == 0) {
		break;
	}
}
echo $out;
 
 
?>

Python:
'''
# Read input from stdin and provide input before running code
 
name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
#print 'Hello World!'
 
N = int(raw_input())
callingOrder = map(int, raw_input().split(" "))
idealOrder = map(int, raw_input().split(" "))
 
time = 0
 
for cur in idealOrder:
	while cur != callingOrder[0]:
		callingOrder = callingOrder[1:] + [callingOrder[0]]
		time += 1
	time += 1
	callingOrder = callingOrder[1:]
print time


Python 3:
n = int(input())
wrong = [int(x) for x in input().split()]
ideal = [int(x) for x in input().split()]
 
step = int(0)
total_step = int(0)
while step<n:
    if wrong[0] == ideal[step]:
        wrong.pop(0)
        total_step +=1
        step +=1
    else:
        x = wrong.pop(0)
        wrong.append(x)
        total_step +=1
print(total_step)

Ruby:
require 'thread'
q=Queue.new
n=gets.to_i
a=gets.split(" ")
a.each do |x|
q<<x
end
b=gets.split(" ")
i=0
t1=0
while !q.empty? do
val=q.pop
t1=t1+1
if val==b[i]
i=i+1
else
q<<val
end
end
puts t1

JAVAScript(Node.js):
function main(input) {
	var inputs = input.split('\n');
	var n = +inputs[0];
	var co = inputs[1].split(' ');
	var io = inputs[2].split(' ');
	var time = 0;
	while (co.length) {
		if (co[0] === io[0]) {
			co.shift();
			io.shift();
		} else {
			var temp = co[0];
			co.shift();
			co.push(temp);
		}
		time++;
	}
	console.log(time);
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
 
JAVAScript(Rhino):
// Below is a sample code to process input from STDIN.
// Equivalent in effect to the Java declaration import java.io.*;
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']); 
 
var size = sc.nextInt();
var array_one = []; 
var array_two = []; 
var time_unit = 0; 
 
for(i=0; i<size; i++){
	array_one[i] = sc.nextInt().toFixed(0)
}
 
for(i=0; i<size; i++){
	array_two[i] = sc.nextInt().toFixed(0)
}
 
for(i=0; i<size; i++){
 
	while(array_one[i] != array_two[i]){
		var position = array_one[i]; 
		array_one.splice(i,1); 
		array_one.push(position); 
		time_unit++; 
	}
	
}
 
var newNumber; 
newNumber =  time_unit + size ; 
System.out.println(newNumber.toFixed(0)); 


*/
