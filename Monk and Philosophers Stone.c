/*  Monk and Philosopher's Stone
Harry Potter wants to get the Philosopher's stone to protect it from Snape. 
Monk being the guard of Philosopher's Stone is very greedy and has a special bag, into which he can add one gold coin at a time or can remove the last gold coin he added. 
Monk will sleep, once he will have the enough number of gold coins worth amount X. To help Harry, Dumbledore has given a same kind of bag to Harry (as of Monk) with 
N gold coins each having worth A[i] where i range from 1<=i<=N.

enter image description here

Dumbledore also gave him a set of instructions which contains two types of strings:
1) "Harry" (without quotes): It means Harry will remove ith coin from his bag and throw it towards Monk and Monk will add it in his bag, where i will start from 1 and go up to N.
2) "Remove" (without quotes): it means Monk will remove the last coin he added in his bag.
Once the worth of the coins in Monk's bag becomes equal to X, Monk will go to sleep. In order to report Dumbledore, Harry wants to know the number of coins in Monk's bag, the first time their worth becomes equal to X.

Help Harry for the same and print the required number of coins. If the required condition doesn't occur print "-1" (without quotes).

Input:
The first line will consists of one integer N denoting the number of gold coins in Harry's Bag.
Second line contains N space separated integers, denoting the worth of gold coins.
Third line contains 2 space separated integers Q and X, denoting the number of instructions and the value of X respectively.
In next Q lines, each line contains one string either "Harry" (without quotes) or "Remove" (without quotes).

Output:
In one line, print the the number of coins in the Monk's bag, the first time their worth becomes equal to X.

Constraints:
1<=N<=10^4
1<=A[i]<=10^4
1<=Q<=10^5
1<=X<=10^7

SAMPLE INPUT 
4
3 1 1 4
6 7
Harry
Harry
Harry
Remove
Remove
Harry
SAMPLE OUTPUT 
2
Explanation
Initailly, set of instructions contains "Harry", then Harry will throw 1st coin to Monk which is of worth 3 . 
Similarly Monk will have 2nd and 3rd gold coin in its bag, both having worth 1.
Now set contains "Remove" 2 times, which means Monk will remove 3rd and 2nd coin, both having worth 1.
Now Harry will throw 4th coin towards Monk having worth 4. Now the Monk's bag contains 2 coins with worth 3 and 4, which is equal to worth 7.
So the answer is 2.

//My C Solution:
#include <stdio.h>
#include <string.h>
#define N 10001
#define LEN 10

int main()
{
    long int A[N],n,i,Q,X,j,k=0,ncoins=0,stk[N];
    char line[LEN];
    scanf("%ld",&n);
    for(i=0;i<n;i++)
        scanf("%ld",&A[i]);
    scanf("%ld%ld",&Q,&X);
    for(i = j = 0; Q>0;Q--){
        scanf("%s",line);
        if(!strncmp(line,"Harry",5)){
            stk[j++]=A[i];
            k+= A[i++];
            ncoins++;
            if(k==X){
                printf("%ld",ncoins);
                return 0;
            }
        }
        else if(!strncmp(line,"Remove",6)){
            ncoins--;
            --j;
            k-= stk[j];
            if(k==X){
                printf("%ld",ncoins);
                return 0;
            }            
        }
    }
    printf("-1");
    return 0;
}



C:
1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){
		int H[1000000],M[1000000],mtop=-1,i,j,sum=0;
		long int n,m;
		char ins[10];
		scanf("%d",&j);
		for(i=0;i<j;i++){
				scanf("%d",&H[i]);
		}
		scanf("%d%d",&n,&m);
		for(i=0,j=0;i<n;i++){
			scanf("%s",ins);
			if(strcmp(ins,"Harry")==0){
				++mtop;
				M[mtop]=H[j++];
				sum+=M[mtop];
			}
		    else{
					sum-=M[mtop];
					M[mtop]=0;
					mtop--;
			}	
			if(sum==m){
					printf("%d",mtop+1);
					exit(0);
			}
		}
		printf("-1");
}

2.
#include <stdio.h>
 
int main(){
	int num,a=0,c=0;
	scanf("%d", &num);
	int arr[num];
	int stack[num];
	for(int itr=0;itr<num;itr++)
	    scanf("%d",&arr[itr]);
	    int num1,num2,sum=0;
	scanf("%d",&num1);
	scanf("%d",&num2);
	for(int itr=0;itr<num1;itr++)
	{
	    sum=0;
	    char ch[100];
	    scanf("%s",ch);
	   if(ch[0]=='H')
	   stack[c++]=arr[a++];
	   else
	   c=c-1;
	   for(int itr1=0;itr1<c;itr1++)
	        sum=sum+stack[itr1];
	  if(num2==sum)
	 {
	printf("%d\n",c);
	break;
	 }
    }
   if(num2!=sum)
    printf("-1");
	}


C++:
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q,x,i=0,k=0,j=0;
    string str;
    cin>>n;
    vector<string> vec;
    stack<int> s;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    i=0;
    cin>>q>>x;
    for(i=0;i<q;i++)
    {
        cin>>str;
        vec.push_back(str);
    }
    i=0;
    while(q--)
    {
        if(vec[j]=="Harry")
        {
            s.push(arr[i]);
            k=k+arr[i];
            i++;
            j++;
        }
        else
        {
            if(s.size()>0)
            {
            k=k-s.top();
            s.pop();
            j++;
            }
        }
        if(k==x)
        {
            cout<<s.size()<<endl;
            break;
        }
        if(q==0)
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}

C#:
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
 
namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            Stack mystack = new Stack();
            int intTestCases = Convert.ToInt32(Console.ReadLine());
            int[] Values = new int[intTestCases];
            Values = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int[] Cases = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int count = 0, sum = 0, counts=0 ;
            for (int i = 0; i < Cases[0]; i++)
            {
                sum = 0;
                string str = Console.ReadLine();
                if(str=="Harry")
                {
                    mystack.Push(Values[count]);
                    count++;
                    foreach (int item in mystack)
                    {
                        sum += item;
                    }
                    if (Cases[1] == sum)
                    {
                        Console.WriteLine(mystack.Count);
                        counts++;
                        break;
                    }
                }
                else //if(str == "Remove")
                {
                    mystack.Pop();
                }
            }
            
            if(counts == 0)
            {
                Console.WriteLine(-1);
            }
 
            //int[] intPasses = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
 
        }
    }
}


Java:
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
 
public class simplecode{
 
    public static void main(String[]args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a[] =new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=Integer.parseInt(st.nextToken());
        }
        int stack[] = new int[n];
        int top = -1;
        int sum=0,index=0;
        st = new StringTokenizer(br.readLine());
        int q=Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        while(q-->0)
        {
            if(br.readLine().charAt(0)=='H')
            {
                stack[++top]=a[index];
                sum+=a[index];
                index++;
            }
            else
            {
                sum-=stack[top--];
            }
            if(sum==x)
            {
                System.out.println(top+1);
                break;
            }
        }
        if(q<0)
        System.out.println(-1);
    }
}


Java 8:
import java.util.*;
import java.io.*;
 
class Scan
{
	private byte[] buf=new byte[1024];
	private int index;
	private InputStream in;
	private int total;
	public Scan()
	{
		in=System.in;
	}
	public int scan()throws IOException
	{
		if(total<0)
		throw new InputMismatchException();
		if(index>=total)
		{
			index=0;
			total=in.read(buf);
			if(total<=0)
			return -1;
		}
		return buf[index++];
	}
	public int scanInt()throws IOException
	{
		int integer=0;
		int n=scan();
		while(isWhiteSpace(n))
		n=scan();
		int neg=1;
		if(n=='-')
		{
			neg=-1;
			n=scan();
		}
		while(!isWhiteSpace(n))
		{
			if(n>='0'&&n<='9')
			{
				integer*=10;
				integer+=n-'0';
				n=scan();
			}
			else throw new InputMismatchException();
		}
		return neg*integer;
	}
	public double scanDouble()throws IOException
	{
		double doub=0;
		int n=scan();
		while(isWhiteSpace(n))
		n=scan();
		int neg=1;
		if(n=='-')
		{
			neg=-1;
			n=scan();
		}
		while(!isWhiteSpace(n)&&n!='.')
		{
			if(n>='0'&&n<='9')
			{
				doub*=10;
				doub+=n-'0';
				n=scan();
			}
			else throw new InputMismatchException();
		}
		if(n=='.')
		{
			n=scan();
			double temp=1;
			while(!isWhiteSpace(n))
			{
				if(n>='0'&&n<='9')
				{
					temp/=10;
					doub+=(n-'0')*temp;
					n=scan();
				}
				else throw new InputMismatchException();
			}
		}
		return doub*neg;
	}
	public String scanString()throws IOException
	{
		StringBuilder sb=new StringBuilder();
		int n=scan();
		while(isWhiteSpace(n))
		n=scan();
		while(!isWhiteSpace(n))
		{
			sb.append((char)n);
			n=scan();
		}
		return sb.toString();
	}
	private boolean isWhiteSpace(int n)
	{
		if(n==' '||n=='\n'||n=='\r'||n=='\t'||n==-1)
		return true;
		return false;
	}
}
 
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        Scan scan = new Scan();
        
        int size = scan.scanInt();
        
        int[] coins = new int[size];
        
        for(int i =0;i<size;i++){
            coins[i] = scan.scanInt();
        }
        
        int q = scan.scanInt();
        int value = scan.scanInt();
        int index = 0;
        
        Stack<Integer> stack = new Stack<Integer>();
        
        int currSum = 0;
        
        StringBuffer result = new StringBuffer();
        
        while(q-- > 0){
            String query = scan.scanString();
            if(query.equals("Harry")){
                stack.push(coins[index++]);
                currSum+=stack.peek();
            }
            else{
                currSum-=stack.pop();
            }
            if(currSum == value){
                result.append(stack.size());
                break;
            }
        }
        
        if(result.toString().isEmpty()){
            result.append("-1");
        }
        
        System.out.println(result.toString());
 
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
   main(stdin_input);
});
 
function main(input) {
    let data = input.split('\n');
    let bag  = data[1].split(' ').map(value => parseInt(value)).reverse();
    let x = parseInt(data[2].split(' ')[1]);
    let sum = 0 ;
    let coin = 0;
    let monkbag = [];
    
    for(i = 3 ;i< data.length  ;i++ ){
        
       if(data[i] === "Harry"){
           let pop = bag.pop();
           sum +=  pop;
           monkbag.push(pop);
       }
       else{
           sum -= monkbag.pop();
       }
       if(sum === x){
          console.log(monkbag.length)
          var flag = 1;
           break;
       }
           
        
    }
    // console.log(sum);
    if(flag !== 1){
        console.log(-1);
    }
    
    
}
 
 
Pascal:
uses crt;
var a,b,d,e,f,g,i,j,k,n,m,c,count,t,q,x:longint;
type d2a=array[1..1000,1..1000] of longint;
var gr:d2a;
var s,bf,cr:string;
var ed,ar:array[1..1000000] of longint;
begin
        readln(n);
        for i:=1 to n do
        begin
                read(ar[i]);
        end;
        readln(Q,X);
        k:=1;
        b:=1;
        for i:=1 to q do
        begin
                readln(s);
                if(s='Harry') then
                begin
                        ed[k]:=ar[b];
                        count:=count+ed[k];
                        k:=k+1;
                        b:=b+1;
                        if(count=x) and (d=0) then
                        begin
                                c:=k;
                                d:=1;
                        end;
                        continue;
                end;
                if(s='Remove') then
                begin
                        k:=k-1;
                        count:=count-ed[k];
                        ed[k]:=0;
                end;
 
         end;
         writeln(c-1);
end.

PHP:
<?php
 
// Read input from stdin and provide input before running code
 
//fscanf(STDIN, "%s\n", $name);
//echo "Hi, ".$name;
 

$monk_coins =0;
$monk_value =array();
$n = intval(trim(fgets(STDIN)));
$h_coins = trim(fgets(STDIN));
$b = trim(fgets(STDIN));
$h_coins = explode(" ",$h_coins);
krsort($h_coins);
 
 
$b = explode(" ",$b);
$n2 = intval($b[0]);
 
$value = $b[1];
while($n2--){
	$q = trim(fgets(STDIN));
	// echo $q;
	if( $q== "Harry"){
		$monk_value[]= intval(array_pop($h_coins));
		$monk_coins++;
	
	}else if($q == "Remove"){
		array_pop($monk_value);
		$monk_coins--;
	}
	
	if(array_sum($monk_value) == $value){
		echo $monk_coins;
		die();
	}
}
echo -1;
?>


Python:
num = int(input())
val = [int(i) for i in raw_input().split(" ")]
 
 
waste = [int(j) for j in raw_input().split(" ")]
Monk = []
check  = 0
for k in range(waste[0]):
    ins = raw_input()
    
    if ins[0] == 'H':
        Monk.append(val[check])
        check = check + 1
        
    
    elif ins[0] == 'R':
        if len(Monk) != 0:
            Monk.pop()
    if sum(Monk) == waste[1]:
        print len(Monk)
        break
 
if sum(Monk) != waste[1]:
    #if len(Monk) == 0:
    print '-1'


Python 3:
from collections import deque
 
N = int(input())
coins = list(map(int, input().split(' ')))
Q, X = map(int, input().split(' '))
 
left = 0
summ = 0
bag = deque()
 
for i in range(Q):
    string = input()
    if string == 'Harry':
        summ += coins[left]
        bag.append(coins[left])
        left += 1
        if summ == X:
            break
    if string == 'Remove':
        summ -= bag.pop()
 
if summ == X:
    print(len(bag))
else:
    print('-1')

Ruby:
n = gets.chomp.to_i
arr = gets.chomp.split.map(&:to_i)
queries_count, expected_sum = gets.split.map(&:to_i)
curr_sum = 0
i = 0
monks_stack = []
count = 0
queries_count.times do
    query = gets.chomp
    if query.eql? "Harry"
        monks_stack.push(arr[i])
        curr_sum += arr[i]
        i += 1
        count += 1
    else
        item = monks_stack.pop
        curr_sum -= item
        count -= 1
    end
    break if curr_sum == expected_sum
end
puts curr_sum == expected_sum ? count : -1

Scala(2.11.8):
import scala.io.StdIn
import scala.collection.mutable.Stack
import scala.collection.mutable.Queue
 
object Philosopher {
    def main(args: Array[String]): Unit = {
 
        val queueHarry = Queue[Int]()
        val stackMonk = Stack[Int]()
 
        val totalNrOfCoins = StdIn.readLine().toInt
        StdIn.readLine().split(' ') foreach (coin => queueHarry.enqueue(coin.toInt))
 
        val constraints = StdIn.readLine().split(' ') map Integer.parseInt // no of commands, desired amount
 
        val nrOfCommands = constraints(0)
        val goal = constraints(1)
 
        def solve(turn : Int, monk: Int): Int = monk match {
            case _ if (monk == goal) => stackMonk.size
            case _ => turn match {
                case i if i == 0 => -1
                case i => StdIn.readLine() match {
                    case "Harry" => {
                        if(queueHarry.isEmpty) -1
                        else {
                            val coin = queueHarry.dequeue()
                            stackMonk.push(coin)
                            solve(turn - 1, monk + coin)
                        }
                    }
                    case "Remove" => {
                        if(stackMonk.isEmpty) -1
                        else {
                            val coin = stackMonk.pop()
                            solve(turn - 1, monk - coin)
                        }
                    }
                }
            }
        }
 
        println(solve(nrOfCommands, 0))
    }
}

Scala:
import scala.io.StdIn
import scala.collection.mutable.Stack
 
object HelloWorld {
    
    def main(args: Array[String]) {
        
        val N = StdIn.readInt()
        val A = StdIn.readLine().split(" ").map(_.toInt)
        val input = StdIn.readLine().split(" ").map(_.toInt)
        val Q = input(0)
        val X = input(1)
        
        val monksBag = new Stack[Int]()
        val harrysBag = new Stack[Int]()
        for (i <- A.length - 1 to 0 by -1) {
            
            harrysBag.push(A(i))
        }
        
        
        var hasReachedXBefore = false
        var coinWorth = 0
        var numOfCoins = -1
        for (q <- 1 to Q) {
            
            val instruction = StdIn.readLine()
            
            if (instruction == "Remove") {
                if (!monksBag.isEmpty) {
                    coinWorth -= monksBag.pop
                    if ((coinWorth == X) && (!hasReachedXBefore)) {
                        hasReachedXBefore = true
                        numOfCoins = monksBag.size
                    }
                }
            }
            else if (!harrysBag.isEmpty) {
                    val coin = harrysBag.pop
                    
                    coinWorth += coin
                    monksBag.push(coin)
                    
                    if ((coinWorth == X) && (!hasReachedXBefore)) {
                        hasReachedXBefore = true
                        numOfCoins = monksBag.size
                    }
            }
        }
        
        println(numOfCoins)
        
    }
    
}
 



*/
