/* All Tracks --> Data Structures --> Queues --> Basics of Queues -->  Problem -->
Monk and Power of Time
The Monk is trying to explain to its users that even a single unit of time can be extremely important and to demonstrate this particular fact 
he gives them a challenging task.
There are N processes to be completed by you, the chosen one, since you're Monk's favorite student. All the processes have a unique number assigned to them from 1 to N.
Now, you are given two things:
The calling order in which all the processes are called.
The ideal order in which all the processes should have been executed.
Now, let us demonstrate this by an example. Let's say that there are 3 processes, the calling order of the processes is: 3 - 2 - 1. 
The ideal order is: 1 - 3 - 2, i.e., process number 3 will only be executed after process number 1 has been completed; 
process number 2 will only be executed after process number 3 has been executed.

Iteration #1: Since the ideal order has process #1 to be executed firstly, the calling ordered is changed, i.e., the first element has to be pushed to the last place. 
Changing the position of the element takes 1 unit of time. The new calling order is: 2 - 1 - 3. Time taken in step #1: 1.

Iteration #2: Since the ideal order has process #1 to be executed firstly, the calling ordered has to be changed again, 
i.e., the first element has to be pushed to the last place. The new calling order is: 1 - 3 - 2. Time taken in step #2: 1.

Iteration #3: Since the first element of the calling order is same as the ideal order, that process will be executed. 
And it will be thus popped out. Time taken in step #3: 1.

Iteration #4: Since the new first element of the calling order is same as the ideal order, that process will be executed. 
Time taken in step #4: 1.

Iteration #5: Since the last element of the calling order is same as the ideal order, that process will be executed. 
Time taken in step #5: 1.

Total time taken: 5 units.
PS: Executing a process takes 1 unit of time. Changing the position takes 1 unit of time.

Input format:
The first line a number N, denoting the number of processes. 
The second line contains the calling order of the processes. 
The third line contains the ideal order of the processes.

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

//My C Submission:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 101
#define Q_SUCCESS 0
#define Q_FAIL NULL
#define Q_FULL -1
#define Q_EMPTY -2
#define Nmax (qd->nmax)
#define Size (qd->size)
#define Nitems (qd->nitems)
#define Array (qd->array)
#define Rear (qd->rear)
#define Front (qd->front)
#define Qfull(qd) (Nitems==Nmax)
#define QEmpty(qd) (Nitems==0)

typedef struct{
    int nmax;
    int size;
    int nitems;
    int front;
    int rear;
    int *array;
}Queue;
 
Queue *openQueue(int nmax,int size){
    register Queue *qd;
    if(nmax<1|| size<1)
        return Q_FAIL;
    qd=(Queue*)malloc(sizeof(Queue));
    if(qd==NULL)
        return Q_FAIL;
    Front= 0;
    Rear = nmax - 1;
    Nmax = nmax;
    Size = size;
    Nitems = 0;
    Array = (int*)malloc(nmax*size);
    return qd;
}

int enQueue(Queue *qd,int item){
    if(Qfull(qd))
        return Q_FULL;
    Rear = (Rear + 1)% Nmax; 
    Array[Rear] = item;
    Nitems++;
    return Q_SUCCESS;
}

int deQueue(Queue *qd,int item){
    if(QEmpty(qd))
        return Q_EMPTY;
    item = Array[Front];
    Front = (Front + 1)% Nmax;    
    Nitems--;
    return Q_SUCCESS;
}


int closeQueue(Queue *qd){
    free(qd);
    return Q_SUCCESS;
}


int main(){
    int n,t[LEN],i,cur=0,pval=0,execu=0;
    scanf("%d",&n);
    register Queue *qd;

    qd = openQueue(n,sizeof(int));
    if(qd==Q_FAIL)
        exit(1);

    for(i=0;i<n;i++){
        scanf("%d",&pval);
        enQueue(qd,pval);
    }

    for(i=0;i<n;i++){
        scanf("%d",&t[i]);
    }

    while(execu!=n){
        pval = Array[Front];
        if(pval==(t[execu])){
            deQueue(qd,pval);
            execu++;
            cur++;
        }
        else{
            deQueue(qd,pval);
            enQueue(qd,pval);
            cur++;
        }
    }
    printf("%d\n",cur);
    closeQueue(qd);
    return 0;
}

*/

/* Best Submission:
C:
#include<stdio.h>
void shift(int *p,int n)
{
    int j;
    for(j=0;j<n-1;j++)
    {
        p[j]=p[j+1];
    }
}
int main()
{
    int N,i,NN,p,time;
    scanf("%d",&N);
    time=0;
    int ideal[100]={0};
    int calling[100]={0};
    for(i=0;i<N;i++)
    scanf("%d",&calling[i]);
    for(i=0;i<N;i++)
    scanf("%d",&ideal[i]);
    
    NN=N;
    i=0;
    while(NN>0)
    {
        if(ideal[i]==calling[0])
        {
            shift(calling,NN);
            NN--;
            time++;
                 i++;
        }
        else
        {
            p=calling[0];
            shift(calling,NN);
            calling[NN-1]=p;
            time++;
        }
    }
    printf("%d",time);
}
C++:
#include<bits/stdc++.h>
using namespace std;
void rotate(queue<int> &q)
{
    int curr=q.front();
    q.pop();
    q.push(curr);
}
int main()
{
    int n;
    cin>>n;
    vector<int> called(n),ideal(n);
    queue<int> q1,q2;
    for(int i=0;i<n;i++)
    {
    cin>>called[i];
    q1.push(called[i]);
    }
    for(int i=0;i<n;i++)
    cin>>ideal[i];
    int count=0;
    int index=0;
    while(!q1.empty())
    {
        int curr=q1.front();
        ++count;
        if(curr==ideal[index])
        {
            ++index;
            q1.pop();
        }
        else
            rotate(q1);
    }
    cout<<count;
}    

C++14:
// Write your code here
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n;
    queue<int> q1,q2;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        q1.push(x);
    }
    for(int i=0;i<n;i++)
    {
        cin>>x;
        q2.push(x);
    }
    int t=0;
    while(q1.empty()!=true)
    {
        int r=q1.front();
        //q1.pop();
        if(q1.front()==q2.front())
        {
            t++;
          q1.pop();
            q2.pop();
        }
        else
        {
            while(q1.empty()!=true && q1.front()!=q2.front())
              {
                  int y=q1.front();
                  q1.pop();
                  t++;
                  q1.push(y);                  
              }
        }
    }
	cout<<t;    
}

C#:
using System;
using System.Linq;
using System.Collections.Generic;
public class Queue
{
    static void Main()
    {
        int executed_job =0;
        int time_count =0;
        int N = Int32.Parse(Console.ReadLine());
        Int32[] callingEle = Array.ConvertAll(Console.ReadLine().Split(' '),Int32.Parse);
        Queue<Int32> queue = new Queue<Int32>();
        foreach(var ele in callingEle)
        {
            queue.Enqueue(ele);
            
        }
        Int32[] idealEle = Array.ConvertAll(Console.ReadLine().Split(' '),Int32.Parse);
        while(queue.Any())
        {
            int job = queue.Peek();
            if(job == idealEle[executed_job])
            {
                queue.Dequeue();
                executed_job++;time_count++;
            }
            else
            {
                queue.Dequeue();
                queue.Enqueue(job);
                time_count++;
            }
        }
        Console.WriteLine(time_count);
        
        
    }
}

Java:
import java.util.*;
public class MonkAndThePowerOfTime {
	public static void main (String[] args) {
		Scanner s = new Scanner(System.in);
		int noOfProcess = s.nextInt();
		//Queue<Integer> callingOrder = new Queue<Integer>();
		Queue<Integer> callingOrder = new LinkedList<Integer>();
		for(int i = 0 ; i < noOfProcess ; i++)
			callingOrder.add(s.nextInt());
		int [] idealOrder = new int[noOfProcess];
		for(int i = 0 ; i < noOfProcess ; i ++)
			idealOrder[i] = s.nextInt();
		MonkAndThePowerOfTime m = new MonkAndThePowerOfTime();
		m.solution(callingOrder,idealOrder);
	}
	private void solution ( Queue<Integer> callingOrder , int[] idealOrder)
	{
		int time = 0 ;
		int i = 0;
		while(!callingOrder.isEmpty()) {
			int process = callingOrder.remove();
			if(process == idealOrder[i]) {
				time++;
				i++;
			}
			else {
				callingOrder.add(process);
				time++;
				}
			}
		System.out.print(time);	
		}
	}

Java 8:
import java.util.LinkedList;
import java.util.Queue;
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] line1 = br.readLine().split(" ");
        String[] line2 = br.readLine().split(" ");
        Queue<Integer> q1 = new LinkedList<Integer>();
        Queue<Integer> q2 = new LinkedList<Integer>();
        for(int i = 0; i< n; i++){
            q1.offer(Integer.parseInt(line1[i]));
            q2.offer(Integer.parseInt(line2[i]));
        }
        int cont = 0;
        while(q1.size()>0){
            if(q1.peek()!=q2.peek()){
                q1.offer(q1.poll());
            }else{
                q1.poll();
                q2.poll();
            }
            cont++;
        }
        System.out.println(cont+"");
    }
}

Javascript(Node.js):
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});
 
process.stdin.on("end", function () {
   main(stdin_input.split("\n"));
});
 
function main(input) {
    const n = Number(input[0]);
    const call = input[1].split(" ").map(x=> Number(x));
    const ideal = input[2].split(" ").map(x=> Number(x));
    const m = new monk(call,ideal);
    const res = m.process();
    process.stdout.write(res.toString());
}
 
class monk {
    constructor(call, ideal){
        this.ideal = ideal.reverse();
        this.call = call.reverse();
        this.steps = 0;
    }
    process(){
        const ideal = this.ideal;
        const call = this.call;
        while(this.call.length > 0){
            this.steps++;
            const tmpi = ideal.pop();
            const tmpc = call.pop();
            if(tmpi!=tmpc){
                ideal.push(tmpi);
                call.unshift(tmpc);
            }
        }
        return this.steps;
    }
}

Python:
n = input()
queue = map(int, raw_input().split())
arr_ideal = map(int, raw_input().split())
 
front = 0
cost = 0
for idl in arr_ideal:
    # print queue
    # print 'front->', front
    front = front%len(queue)
    while queue[front] != idl:
        front+=1
        cost+=1
        front = front%len(queue)
    del queue[front]
print cost+n

Python 3:
import collections as col
 
s = int(input())
org_or = col.deque(list(map(int , input().split()))) 
ide_or = col.deque(list(map(int , input().split()))) 
t = 0
while len(org_or) != 0 :
    o = org_or.popleft()
    i = ide_or.popleft()
    if o == i:
        t +=1
    else:
        t += 1
        org_or.append(o)
        ide_or.appendleft(i)
print(t)


*/

/*I/O:
In #1:
5
5 4 2 3 1
5 2 1 4 3
Out #1:
7
In #2:
10
5 4 8 9 1 6 3 2 7 10
1 6 8 9 5 4 10 3 2 7
Out #2:
27
In #3:
15
5 11 12 13 15 6 14 2 7 10 4 8 9 3 1
4 15 8 2 6 9 11 10 7 5 13 14 3 1 12
Out #3:
75
In #4:
30
5 29 12 16 25 17 18 30 27 10 4 23 20 3 1 24 26 19 14 9 6 22 8 13 15 21 28 7 11 2
17 20 6 18 21 5 22 24 28 7 23 3 27 19 10 30 15 25 12 16 2 1 11 9 4 8 29 14 13 26
Out #4:
226
In #5:
40
5 29 12 16 25 36 18 37 27 32 34 40 20 3 1 24 26 19 33 9 6 22 8 13 15 21 28 7 11 2 31 39 14 38 4 17 30 35 10 23
14 39 4 5 23 7 40 8 36 17 30 21 3 35 33 32 12 16 20 25 31 13 22 34 19 18 29 11 27 15 1 38 26 6 28 10 9 37 2 24
Out #5:
491

*/

/*Editorial:
Author Solution by Coding Club IIT Jammu:
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
*/
