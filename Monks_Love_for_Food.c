/*Code Monk (Stacks & Queues)

Monk's Love for Food

Our monk loves food. Hence,he took up position of a manager at Sagar,a restaurant that serves people with delicious food packages. It is a very famous place and people are always queuing up to have one of those packages. Each package has a cost associated with it. The packages are kept as a pile. The job of a manager is very difficult. He needs to handle two types of queries:

1) Customer Query:
When a customer demands a package, the food package on the top of the pile is given and the customer is charged according to the cost of the package. This reduces the height of the pile by 1. 
In case the pile is empty, the customer goes away empty-handed.

2) Chef Query:
The chef prepares a food package and adds it on top of the pile. And reports the cost of the package to the Manager.
Help him manage the process.

Input:
First line contains an integer Q, the number of queries. Q lines follow.
A Type-1 ( Customer) Query, is indicated by a single integer 1 in the line.
A Type-2 ( Chef) Query, is indicated by two space separated integers 2 and C (cost of the package prepared) .

Output:
For each Type-1 Query, output the price that customer has to pay i.e. cost of the package given to the customer in a new line. If the pile is empty, print "No Food" (without the quotes).

Constraints:
1 = Q = 105
1 = C = 107

SAMPLE INPUT 
6
1
2 5
2 7
2 9
1
1
SAMPLE OUTPUT 
No Food
9
7
Explanation
Initially, The pile is empty.
Chef adds a package with cost=5.
Chef adds a package with cost=7.
Chef adds a package with cost=9.
Customer takes the package on the top i.e. cost=9. Now package of cost=7 on top. Customer takes the package on the top i.e. cost=7.



#include <stdio.h>
#define N 100000
#define LEN 100
 
int main()
{
    int Q,Cost=0,j,i,t,k,stack[N];
    char str[LEN];
    //int *stack;
    scanf("%d",&Q);
    t=0;
    //stack=(int *)malloc(1*sizeof(int));
    for(i=Q;i>=0;i--){
        if(fgets(str,LEN,stdin)!=NULL){
            j=0;
            if(str[j]=='2'){
                //stack=(int *)realloc(stack,++t+1*sizeof(int));
                j+=2;
                //stack[t-1]=atoi(str+j);
                stack[t++]=atoi(str+j);
            }
            else if(str[j]=='1'){
                if(t==0)
                    printf("%s\n","No Food");
                else{
                    t--;
                    Cost=stack[t];
                    printf("%d\n",Cost);
                }
            }
        }
    }
    //free(stack);
    return 0;
}
*/


/*My C++ solution 
#include <iostream>
#include <cstdlib>
 
#define N 100000
#define LEN 100
using namespace std;
 
int main()
{
    int Q,Cost=0,j,i,t,k,stack[N];
    char str[LEN];
    cin>>Q;
    t=0;
    for(i=Q;i>=0;i--){
        if(fgets(str,LEN,stdin)!=NULL){
            j=0;
            if(str[j]=='2'){
                j+=2;
                stack[t++]=atoi(str+j);
            }
            else if(str[j]=='1'){
                if(t==0)
                    cout<<"No Food"<<endl;
                else{
                    t--;
                    Cost=stack[t];
                    cout<<Cost<<endl;
                }
            }
        }
    }
    return 0;
}
*/

/*I/O:
No I/O exists.

*/

/*Best Submissions:
C:
#include<stdio.h>
int main()
{
    int t,top=-1;
    int arr[1000000];
    scanf("%d",&t);
    while(t--)
    {
        int q;
        scanf("%d",&q);
        if(q==1)
        {
            if(top==-1)
            {
                printf("No Food\n");
            }
            else
            {
                printf("%d\n",arr[top]);
                arr[top]=NULL;
                top--;
            }
        }
        if(q==2)
        {
            top++;
            scanf("%d\n",&arr[top]);
        }
    }
}


C++:
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define loop(x,n) for(int x = 0; x < n; x++)
#define ll long long int
 
int main(){
    
    int n,i;
    cin>>n;
    stack<int> s;
    loop(i,n){
        int q;
        cin>>q;
        if(q==1){
            if(s.empty()) cout<<"No Food"<<endl;
            else{
                cout<<s.top()<<endl;
                s.pop();
            }
        }
        else{
            int c;
            cin>>c;
            s.push(c);
        }
    }
}


C++14:
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    int t=0;
    cin>>n;
    queue<int> c;
    queue<int> ex;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        c.push(x);
    }
     for(int i=0;i<n;i++)
    {
        cin>>x;
        ex.push(x);
    }
    while(!c.empty())
    {
        if(c.front()!=ex.front())
         {
           x=c.front();
           c.push(x);
           c.pop();
           t++;
      }
       else if(c.front()==ex.front())
       {
        c.pop();
        ex.pop();
        t++;
       }
    }
    cout<<t<<endl;
}

C#:
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
 
class Test
{
    public static void Main(string[] agrs)
    {
        var q = int.Parse(Console.ReadLine());
        var result = new StringBuilder();
        var stack = new Stack<string>();
        for (int i = 0; i < q; i++)
        {
            var inputs = Console.ReadLine().Split(' ').ToList();
            if (inputs.Count == 1)
                result.AppendLine(stack.Count > 0 ? stack.Pop() : "No Food");
            else
            {
                stack.Push(inputs[1]);
            }
        }
        Console.WriteLine(result);
    }
}


Java:
//uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
//import for Scanner and other utility classes
import java.util.*;
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
class TestClass {
    public static void main(String args[] ) throws Exception {
        
        //Scanner
        Scanner s = new Scanner(System.in);
        int q = s.nextInt();
        List<String> list = new ArrayList();
        while(q-- >=0){
            String type = s.nextLine();
            String str[] = type.split(" ");
            switch(str[0]){
                case "1":
                    if(list.size()==0)
                        System.out.println("No Food");
                    else{
                        System.out.println(list.remove(list.size()-1));
                    }
                    break;
                case "2":
                    list.add(str[1]);
            }
            
        }
 
    }
}


Java 8:
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
 
class TestClass {
    static BufferedReader br;
    static Queue<Integer> q;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        int N = ri();
        int[] calling,ideal;
        q = new LinkedList<>();
        calling = ria();
        ideal = ria();
        for(int i=0;i<N;i++) {
            q.add(calling[i]);
        }
        int count = 0, sum = 0;
        for(int i=0;i<N;i++) {
            int idealVal = ideal[i];
            count = 0;
            int k = q.poll();
            while(k != idealVal) {
                q.add(k);
                k = q.poll();
                count++;
            }
            sum += (count+1);
        }
        System.out.println(sum);
    }
 
    static String rl() throws IOException { return br.readLine();}
    static int ri() throws IOException { return Integer.parseInt(rl());}
    public static int[] ria() throws IOException {
        StringTokenizer st = new StringTokenizer(rl());
        int l = st.countTokens();
        int[] ar = new int[l];
        for(int i=0;i<l;i++) ar[i] = Integer.parseInt(st.nextToken());
        return ar;
    }
}

Python:
q = int(raw_input())
stack = []
while q:
    query = raw_input().split()
    if query[0] == '1':
        if len(stack)==0:
            print "No Food"
        else:
            print stack.pop()
    else:
        stack.append(query[1])
    q-=1



Python 3:
from sys import stdin, stdout
input()
food_list=[]
for q in stdin.read().splitlines():
    if q[0]=='1':
        if len(food_list)>0:
            print(food_list.pop())
        else:
            print("No Food")
    else:
        food_list.append(q[2:])


Perl:
use strict;
use warnings;
 
chomp(my $t = <STDIN>);
my $line;
my @stack;
while($t-- > 0) {
    chomp($line = <STDIN>);
    if(substr($line,0,1) eq '1') {
        if(@stack) {
            print pop @stack, "\n";
        } else {
            print "No Food\n";
        }
    } else {
        my ($q, $val) = split ' ', $line;
        push @stack, $val;
    }
}


Pascal:
Program HiHere;
VAR q,x,y,k,i:int64; a:array[1..100001] of int64;
Begin
Readln(q);
for i:=1 to q do
Begin
Read(x);
if (x = 1) then
Begin
Readln;
if (k = 0) then Writeln('No Food') else Begin Writeln(a[k]); k:=k - 1; end;
end else Begin k:=k + 1; Readln(y); a[k]:=y; end;
end;
Readln;
END.

PHP:
<?php

// Sample code to perform I/O:
//fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
//echo "Hi, ".$name.".\n";                // Writing output to STDOUT
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
// Write your code here
$q = fgets(STDIN);
$chef = array();
for($i=0;$i<$q;$i++){
    $query = fgets(STDIN);
    $cases = explode(" ",$query);
    if($cases[0] == 1){
        if(count($chef) == 0){
            echo "No Food".PHP_EOL;
        }else{
            $price = array_pop($chef);
            echo $price.PHP_EOL;
        }
    }else if($cases[0] == 2){
        $chef[] = $cases[1];
    }
}
?>

Ruby:
test = gets.chomp.to_i
big_list = []
while test>0
	test -=1
	inp = gets.chomp.split(' ')
	if inp.size == 1
		if big_list.size==0
			puts "No Food"
		else
			puts big_list[big_list.size-1]
			big_list.pop
		end
	else
		big_list.push(inp[1])
	end
end


*/


