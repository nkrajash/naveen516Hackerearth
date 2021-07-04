/* All Tracks --> Basic Programming --> Recursion --> Recursion and Backtracking --> Problem -->
Simran and stairs
Tag(s): Easy, Recursion
Simran is running up a staircase with N steps, and can hop(jump) either 1 step, 2 steps or 3 steps at a time.
You have to count, how many possible ways Simran can run up to the stairs.

Input Format:
Input contains integer N that is number of steps

Output Format:
Output for each integer N the no of possible ways w.

Constraints
1<=N<=30

SAMPLE INPUT 
4
SAMPLE OUTPUT 
7

// My C Solution:
#include <stdio.h>
 
int find(int n)
{
    int f[n];
    
    f[0]=1;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=n;i++)
		f[i]=f[i-1]+f[i-2]+f[i-3];
    
    return f[n];
}
 
// Driver code
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n", find(n));
    return 0;
}


*/

/* Editorial:
This is a simple question with recursion approach. For each number N, you can reach to N either from N-1 or N-2 or N-3 and same goes on till we reach 1 or 2 or 3.
for N=1, ans=1.
for N=2, ans = 2.
for n = 3, ans = 4
and for other N, ans = ans(N-1)+ans(N-2)+ans(N-3);

Author Solution by Sahil Singla
#include<bits/stdc++.h>
using namespace std;
int a[40]={0};
//tested pseudo Code : SS
int recursion(int n)
{
    if(n<=2)
    return a[n] = n;
    if(n==3)
    return a[n] = 4;
     if(a[n])
     return a[n];
     return a[n] = recursion(n-1)+recursion(n-2)+recursion(n-3);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    cout<<recursion(n);
}

//My Python 3 Solution
n=int(input())
steps=[0]*31
steps[1]=1
steps[2]=2
steps[3]=4
for i in range(4,n+1):
    steps[i]=steps[i-1]+steps[i-2]+steps[i-3]
print(steps[n])


*/


/*Best Submissions:
C:
#include <stdio.h>
//By definition,
//jump(i) = 0, i < 0
//jump(0) = 1
 
//Therefore, 
//jump(n) =
//                    0                 if n < 0
//                    1                 if n = 0
//    jump(n-1) + jump(n-2) + jump(n-3) if n > 0
int main(void) {
    int j[33] = {0, 0, 1}, *jump = j+3;
    for (int i = 0; i < 30; i++)
        jump[i] = jump[i-1] + jump[i-2] + jump[i-3];
    int nsteps;
    scanf("%d", &nsteps);
    printf("%d\n", jump[nsteps-1]);
    return 0;
}
C++:
#include<bits/stdc++.h>
using namespace std;
int a[40]={0};
 
int recursion(int n)
{
    if(n<=2)
    return a[n] = n;
    if(n==3)
    return a[n] = 4;
     if(a[n])
     return a[n];
     return a[n] = recursion(n-1)+recursion(n-2)+recursion(n-3);
}
int main()
{
    int n;
    cin>>n;
    cout<<recursion(n);
}


C++14:
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    int N;
    cin >> N;
    vector <int> DP(max(N + 1, 4));
    
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    
    for(int i = 4; i <= N; i++)
        DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
        
    DP[3] = 4;
        
    cout << DP[N] << endl;
    return 0;
}

C#:
using System;
using System.Collections.Generic;
 
  public class HackerEarth
    {
 
        public static void Main(string[] args)
        {
            int n  = Int32.Parse(Console.ReadLine());
            Console.WriteLine(Staircase(n));
        }
        
        public static int Staircase(int n) {
            
            //if(n == 1 || n ==0){
            //    return 1;
            //}
            //else if(n == 2){
            //    return 2;
            //}
            //return Staircase(n-3) + Staircase(n-2) + Staircase(n-1);

            int[] arr = new int[n+1];
            arr[0] = 1;
            arr[1] = 1;
            arr[2] = 2;
            for(int i=3;i<=n;i++){
                arr[i] = arr[i-1] + arr[i-2]+ arr[i-3];
            }
            return arr[n];
           
        }
    }

Java:
import java.util.*;
 
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    private static int dp[];
    public static void main(String args[] ) throws Exception {
       
        //Scanner
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        dp= new int[N+1];
        for(int i=0; i<=N; i++) {
            dp[i] = -1;
        }
        dp[0] = 1;
        System.out.println(new TestClass().getResult(N));
    }
    
    private int getResult(int n) {
        if(n<0) {
            return 0;
        }
        if(n == 0) {
            return 1;
        }
        if(dp[n] != -1) return dp[n]; 
        return dp[n] = getResult(n-1)+getResult(n-2)+getResult(n-3);
    }
}


Java 8:
import java.util.*;
 
class TestClss {
 
    static int arr[]=new int[31];
    public static void main(String args[] )
    {
        int n=new Scanner(System.in).nextInt();
        arr[3]=4;
        arr[7]=44;
        arr[10]=274;
        arr[30]=53798080;
    
        System.out.print(arr[n]);
    }
}

Java(Rhino.js):
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new BufferedReader(new InputStreamReader(System['in']));					
 
var n= sc.readLine();
// System.out.println(n);
var x=nextStep(n);
System.out.printf(x);
 
 
function nextStep(n){
    
    var arr=[1,2,4];
    var val=0;
    
    for(i=3;i<n;i++){
    val=arr[i-1]+arr[i-2]+arr[i-3];
    arr.push(val);
    }
    
    return arr[n-1];
    // if(n===1 || n===0){
    //     return 1;
    // }
    // else if(n===2){
    //     return 2;
    // }
    // else{
    //     return nextStep(n-1) + nextStep(n-2)+ nextStep(n-3);
    // }
}


Java(Node.js):
// Sample code to perform I/O:
 
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
    // if (input === 0 || input === 1){
    //     console.log(1);
    // }
    // if(input === 2 ){
    //     console.log(2);
    // }
    
    // var result = main(input -1) + main(input -2) + main(input -3);
    // console.log(result);
    
    var res = [];
    res[0] = 1;
    res[1] = 1;
    res[2] = 2;
    for (var i = 3; i <= input; i++)  
        res[i] = res[i-1] + res[i-2]  + res[i-3]; 
      
    console.log(res[input]); 
}
 

Pascal:
var
   n,i:longint;
   arr:array[0..30] of longint;
begin
  arr[0]:=1;
  arr[1]:=1;
  arr[2]:=2;
  readln(n);
  for i:=3 to n do
     arr[i]:=arr[i-1]+arr[i-2]+arr[i-3];
   writeln(arr[n]);
end.  

Python:
n = input()
dict_ = {}
def rec(n):
    if n ==1:
        return 1
    if n == 2:
        return 2
    if n == 3:
        return 4
    if n in dict_ :
        return dict_[n]
    steps = rec(n-1) + rec(n-2) + rec(n-3)
    dict_[n] = steps
    return steps
    
print rec(n)

Python 3:
# Write your code here
def count(n):
    if(n==0):
        return 1
    elif(n<0):
        return 0
    return count(n-1)+count(n-2)+count(n-3)
 
n=int(input())
steps=[0]*31
steps[1]=1
steps[2]=2
steps[3]=4
for i in range(4,n+1):
    steps[i]=steps[i-1]+steps[i-2]+steps[i-3]
print(steps[n])

*/


/*I/O:
In #1:
3
Out #1:
4
In #2:
7
Out #2:
44
In #3:
10
Out #3:
274
In #4:
30
Out #4:
53798080

*/