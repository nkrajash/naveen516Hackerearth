/*Monk and Prisoner of Azkaban
Tag(s): Data Structures, Easy, Stack, Stack
Monk's wizard friend Harry Potter is excited to see his Dad fight Dementors and rescue him and his Godfather Sirius Black. 
Meanwhile their friend Hermoine is stuck on some silly arrays problem. Harry does not have time for all this, so he asked Monk 
to solve that problem for Hermoine, so that they can go.

The problem is given an array A having N integers, for each i(1<=i<=N), find x+y, where x is the largest number less than i such that A[x]>A[i]
and y is the smallest number greater than i such that A[y]>A[i]. If there is no x<i  such that A[x]>A[i], then take x=-1. 
Similarly, if there is no y>i such that A[y]>A[i] , then take y=-1.


Input Format:
First line consists of a single integer denoting N.
Second line consists of N space separated integers denoting the array A.

Output Format:
Print N space separated integers, denoting x+y for each i(1<=i<=N)

Constraints:
1<=N<=10^6
1<=A[i]<=10^18

SAMPLE INPUT 
5
5 4 1 3 2
SAMPLE OUTPUT 
-2 0 6 1 3 

Explanation:
Values of x for each i: -1,1,2,2,4
Values of y for each i: -1,-1,4,-1,-1
So,x+y  for each i: -2,0,6,1,3

My C Solution:
#include <stdio.h>
#define input(x) scanf("%lld", &x)
#define output(x) printf("%lld ", x)
#define ll long long int
#define LEN 1000001

ll st[LEN];
ll front[LEN],arr[LEN],back[LEN];

int main(){
    ll n, size=0, temp ,x, i;
    input(n);
    for (i = 1; i <= n; ++i) {
	    input(arr[i]);
	}
	for (i = 1; i <= n; ++i) {
	    temp = st[size];
	    if ((!size) || (arr[temp] >= arr[i])) {
	        ++size;
	        st[size]=i;
	    } else {
	        while ((size) && (arr[temp] < arr[i])) {
	            front[temp] = i;
	            --size;
	            temp= st[size];
	        }
	        ++size;
	        st[size]=i;
	    }
	}
	while (size) {
	    temp = st[size];
	    front[temp] = -1;
	    size--;
	}
	size=0;
	for (i = n; i > 0; --i) {
	    temp = st[size];
	    if ((!size) || (arr[temp] >= arr[i])) {
	        ++size;
	        st[size]=i;
	    } else {
	        while ((size) && (arr[temp] < arr[i])) {
	            back[temp] = i;
	            --size;
	            temp= st[size];
	        }
	        ++size;
	        st[size]=i;
	    }
	}
	while (size) {
	    temp= st[size];
	    back[temp] = -1;
	    size--;
	}
	for (i = 1; i <= n; ++i) {
	    output((front[i] + back[i]));
	}
    return 0;
}

*/

/*Editorial:
Monk and Prisoner of Azkaban
Author : Vaibhav Jaimini
Tester : prat33k
Editorialist : prat33k
Brief Description : Need to find previous greater and next greater element using stack.
Pre-Requisites : Stacks
Difficulty : Easy
Detailed Editorial :
This problem can be solved using stack for find next greater element for each element of the given array, 
and then find the next greater for each element of the reverse array. For finding the next greater element of each element in the array, 
initially push the first element in the stack. 
After that, for each element in the array, check how many elements present in the stack are less than the current element of the array. 
For all those stack elements, current element is the next greater element of the array. The elements which were left in the stack after traversing 
all the elements of the array do not have any next greater element. Let's say, the index of the next greater element for ith  element is ans[i], 
and if the ith element doesn't have any greater element then, ans[i]=-1.

Similarly reverse the array, and store the index of the next greater element for each element of array in rev_ans[ ]. 
(previous greater for element of initial array).

If rev_ans[ i ] is not equal to -1, then change rev_ans[ i ] = n - rev_ans[ i ] , as the indexes stored are of reverse array.
For each element, answer is ans[ i ] + rev_ans[n-i].

//finding next greater element for each element of array a [   ]
    for i 1 to N 
       if(i==0)
        {
            st.push( a[i] );
        }
        else
        {
            if(!st.empty())
            {
                tp= st.top();

                st.pop();
                while(tp < a[i])
                {
                    next_greater[tp] = a[i];
                    if(st.empty())
                        break;

                    tp = st.top();
                    st.pop();

                }

                if(tp > a[i])
                    st.push(tp);
            }
            st.push(a[i]);
        }
        }
       //elements left in stack, do not have any next_greater element. 
        while(!st.empty())
        {
         tp = st.top();
        st.pop();
        next_greater[tp] =-1;
        }
Time Complexity: O(N)
Space Complexity : O(N)

Author Solution by Vaibhav Jaimini
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1010000];
int ng[1001000], pg[1001000];
int main(){
	int n; cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	
	stack<int> s;
	s.push(1);
	for(int i=2; i<=n; i++){
		while(s.size() and a[s.top()] < a[i]){
			ng[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}	
	while(s.size()){
		ng[s.top()] = -1;
		s.pop();
	}
	s.push(n);
	for(int i=n-1; i>=1; i--){
		while(s.size() and a[s.top()] < a[i]){
			pg[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while(s.size()){
		pg[s.top()] = -1;
		s.pop();
	}
	for(int i=1; i<=n; i++)cout<<pg[i]+ng[i]<<" ";cout<<endl;		
	return 0;
}

Tester Solution by Prateek Garg
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int ma = 1e6+5;
stack < pair <ll, int> > st;
ll ans[ma], ans1[ma], a[ma], b[ma];
int main()
{
	//freopen("i.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i==0)
		{
			st.push(make_pair(a[i],i));
		}
		else
		{
			if(!st.empty())
			{
				pair<ll,int> tp= st.top();
				st.pop();
				while(tp.first < a[i])
				{
					ans[tp.second] = i+1;
					if(st.empty())
						break;
					
					tp = st.top();
					st.pop();
				
				}
				if(tp.first >= a[i])
					st.push(tp);
			}
			st.push(make_pair(a[i],i));
		}
	}
	while(!st.empty())
	{
		pair <ll,int> tp = st.top();
		st.pop();
		ans[tp.second] =-1;
	}
	for(int i=n-1;i>=0;i--)
	{
		b[n-1-i] = a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			st.push(make_pair(b[i],i));
		}
		else
		{
			if(!st.empty())
			{
				pair<ll,int> tp= st.top();
				st.pop();
				while(tp.first < b[i])
				{
					ans1[tp.second] = i+1;
					if(st.empty())
						break;
					
					tp = st.top();
					st.pop();
				}
				if(tp.first >= b[i])
					st.push(tp);
			}
			st.push(make_pair(b[i],i));
		}
	}
	while(!st.empty())
	{
		pair <ll, int> tp = st.top();
		st.pop();
		ans1[tp.second] =-1;
	}
	
	//for(int i=0;i<n;i++)
	//{
	//	cout<<ans[i]<<" "<<ans1[n-1-i]<<endl;
	//}
	for(int i=0;i<n;i++)
	{
		if(ans1[i]!=-1)
			ans1[i] = n-ans1[i]+1;
	}
	for(int i=0;i<n;i++)
	{
		if(i!=n-1)
		cout<<ans[i]+ans1[n-1-i]<<" ";
		else
		cout<<ans[i] + ans1[n-1-i]<<endl;
	}
	return 0;
}
*/


/*Best Submissions:
C:
#include <stdio.h>
 
unsigned long long a[1000001];
int x[1000001];
int y[1000001];
 
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	scanf("%lli",&a[i]);
    }
    x[0] = -1;
    for(i=1;i<n;i++){
    	
    	if(a[i]<a[i-1]){
    		x[i] = i;
    	}else if(x[i-1] != -1){
    		
    		j = x[i-1]-1;
    		while(j>=0){
    			if(a[i] < a[j]){
    				x[i] = j+1;
    				break;
    			}
    			j = x[j]-1;
    		}
    		if(j<0){
    			x[i] = -1;
    		}
    	}else{
    		x[i] = -1;
    	}
    }
    
    y[n-1] = -1;
    
    for(i=n-2;i>=0;i--){
    	
    	if(a[i] <a[i+1]){
    		y[i] = i+2;
    	}else if(y[i+1] != -1){
    		j = y[i+1]-1;
    		
    		while(j>=0){
    			
    			if(a[i] <a[j]){
    				y[i] = j+1;
    				break;
    			}
    			j =  y[j] -1;
    		}
    		if(j<0){
    			y[i] = -1;
    		}
    	}else{
    		y[i] = -1;
    	}
    }
    
    for(int i=0;i<n;i++){
    	printf("%d ",x[i] + y[i]);
    }
    printf("\n");
    return 0;
}
C++:
#include<bits/stdc++.h>
using namespace std;
#define pencho ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long ll;
#define mod 1000000007
#define int long long
//  ll read () {     
//  	bool minus = false;
//  	ll result = 0;
//  	char ch;
//  	ch = getchar();
//  	while (true) {
//  		if (ch == '-') break;
//  		if (ch >= '0' && ch <= '9') break;
//  		ch = getchar();
//  	}
//  	if (ch == '-') minus = true; else result = ch-'0';
//  	while (true) {
//  		ch = getchar();
//  		if (ch < '0' || ch > '9') break;
//  		result = result*10 + (ch - '0');
//  	}
//  	if (minus)
//  		return -result;
//  	else
//  		return result;
//  }
//  template <typename T>
//  inline void pr(T a) {
//  	char s[11];
//  	T t = -1;
//  	do {
//  		s[++t] = a % 10 + '0';
//  		a /= 10;
//  	} while (a > 0);
//  	while (t >= 0) putchar_unlocked(s[t--]);
//  	putchar_unlocked('\n');
//  }


//  void build(int node, int start, int end)
//  {
//      if(start == end)
//      {
//          // Leaf node will have a single element
//          tree[node] = A[start];
//      }
//      else
//      {
//          int mid = (start + end) / 2;
//          // Recurse on the left child
//          build(2*node, start, mid);
//          // Recurse on the right child
//          build(2*node+1, mid+1, end);
//          // Internal node will have the sum of both of its children
//          tree[node] = tree[2*node] + tree[2*node+1];
//      }
//  }
//   
//  void update(int node, int start, int end, int idx, int val)
//  {
//      if(start == end)
//      {
//          // Leaf node
//          A[idx] += val;
//          tree[node] += val;
//      }
//      else
//      {
//          int mid = (start + end) / 2;
//          if(start <= idx and idx <= mid)
//          {
//              // If idx is in the left child, recurse on the left child
//              update(2*node, start, mid, idx, val);
//          }
//          else
//          {
//              // if idx is in the right child, recurse on the right child
//              update(2*node+1, mid+1, end, idx, val);
//          }
//          // Internal node will have the sum of both of its children
//          tree[node] = tree[2*node] + tree[2*node+1];
//      }
//  }
//   
//   
//  int query(int node, int start, int end, int l, int r)
//  {
//      if(r < start or end < l)
//      {
//          // range represented by a node is completely outside the given range
//          return 0;
//      }
//      if(l <= start and end <= r)
//      {
//          // range represented by a node is completely inside the given range
//          return tree[node];
//      }
//      // range represented by a node is partially inside and partially outside the given range
//      int mid = (start + end) / 2;
//      int p1 = query(2*node, start, mid, l, r);
//      int p2 = query(2*node+1, mid+1, end, l, r);
//      return (p1 + p2);
//  }

signed main(){
    pencho
    int N; cin>>N;
    int A[N],pos_left[N]={0},pos_right[N]={0};
    for(int i=0;i<N;i++)    cin>>A[i];
    stack<pair<int,int>>great_left,great_right;
    for(int i=0;i<N;i++){
        while(!great_left.empty())
            if(great_left.top().first<=A[i])
                great_left.pop();
            else
                break;
        if(great_left.size())
            pos_left[i]=great_left.top().second;
        else
            pos_left[i]=i;
        great_left.push(make_pair(A[i],i));                
    }
    for(int i=N-1;i>=0;i--){
        while(!great_right.empty())
            if(great_right.top().first<=A[i])
                great_right.pop();
            else
                break;
        if(great_right.size())
            pos_right[i]=great_right.top().second;
        else
            pos_right[i]=i;
        great_right.push(make_pair(A[i],i));                
    } 
   
 // for(int i=0;i<N;i++)
 //   cout<<pos_left[i]<<" "<<pos_right[i]<<endl;
   int x,y;
    for(int i=0;i<N;i++){
        if(pos_right[i]==i) y=-1;
        else    y=pos_right[i]+1;    
        if(pos_left[i]==i) x=-1;
        else    x=pos_left[i]+1;
        cout<<x+y<<" ";    
    }           
}

C++14:
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1010000];
int ng[1001000], pg[1001000];
int main(){
	int n; cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	
	stack<int> s;
	s.push(1);
	for(int i=2; i<=n; i++){
		while(s.size() and a[s.top()] < a[i]){
			ng[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}	
	while(s.size()){
		ng[s.top()] = -1;
		s.pop();
	}
	s.push(n);
	for(int i=n-1; i>=1; i--){
		while(s.size() and a[s.top()] < a[i]){
			pg[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while(s.size()){
		pg[s.top()] = -1;
		s.pop();
	}
	for(int i=1; i<=n; i++)cout<<pg[i]+ng[i]<<" ";cout<<endl;		
	return 0;
}
C#:
using System;
using System.Collections.Generic;
using System.Linq;
 
// sort all of the numbers
// find the index of the number. find the next largest and the next smallest and add them
// nlogn to sort (can't really do counting sort because numbers are too big)
// logn to find (binary search) each number * n numbers
// nlogn complexity
// better than the n^2 it takes to run through the whole array for each number
 
public class Test
{
    public static int Split(int[] numbers, int[] positions, int start, int end)
    {
        int startPos = positions[start];
        int splitter = numbers[start];
        int leftside = start + 1;
        
        for (int i = start; i <= end; i++)
        {
            if (numbers[i] < splitter)
            {
                int tmp = numbers[leftside];
                int tmp2 = positions[leftside];
                positions[leftside] = positions[i];
                numbers[leftside++] = numbers[i];
                numbers[i] = tmp;
                positions[i] = tmp2;
            }
        }
        
        numbers[start] = numbers[--leftside];
        positions[start] = positions[leftside];
 
        numbers[leftside] = splitter;
        positions[leftside] = startPos;
        
        return leftside;
    }
    
    // Needs to include the index of end
    public static void Quicksort(int[] numbers, int[] positions, int start, int end)
    {
        if (end - start <= 0)
        {
            return;
        }
        
        int splitter = Split(numbers, positions, start, end);
        Quicksort(numbers, positions, start, splitter - 1);
        Quicksort(numbers, positions, splitter + 1, end);
    }
    
    public static int BinarySearch(int[] numbers, int target, int start, int end)
    {
        if (start > end)
        {
            return -1;
        }
        
        int midpoint = (start + end) / 2;
        
        if (target < numbers[midpoint])
        {
            return BinarySearch(numbers, target, start, midpoint - 1);
        } 
        else if (target > numbers[midpoint])
        {
            return BinarySearch(numbers, target, midpoint + 1, end);
        }
        
        return midpoint;
    }
    
    public static int FindXAndY(int[] numbers, int[] positions, int target, bool xOrY)
    {
        int n = numbers.Length;
        int index = BinarySearch(numbers, target, 0, n - 1);
        
        
        if (xOrY)
        {
            int i = index + 1;
            
            while (i < n)
            {
                if (numbers[i] > target && positions[i] > positions[index])
                {        
                    return numbers[i];
                }
                
                i++;
            }
            // Did not find something larger
 
            return -1;
        }
        else
        {
            int i = index - 1;
            
            while (i >= 0)
            {
                if (numbers[i] < target && positions[i] < positions[index])
                {
                    return numbers[i];
                }
                
                i--;
            }
            
            return -1;
        }
    }
    
    public static void Main()
    {
        int n;
        Int32.TryParse(Console.ReadLine(), out n);
        
        var numbers = Console.ReadLine().Split(' ').Select(d => {
            long tmp;
            Int64.TryParse(d, out tmp);
            return tmp;
        }).ToArray();
        
        //var numbersArray = numbers.ToArray();
 
        var answers = new List<long>();
        
        /*
        var positions = new int[n];
        
        for (int i = 0; i < n; i++)
        {
            positions[i] = i;
        }
        
        Quicksort(numbersArray, positions, 0, n - 1);
        
        //Console.WriteLine(string.Join(" ", positions));
        
        foreach (var ai in numbers)
        {
            answers.Add(FindXAndY(numbersArray, positions, ai, true) + FindXAndY(numbersArray, positions, ai, false));
        } */
        
        var x = new long[n];
        var y = new long[n];
        
        var stack = new Stack<long>();
        stack.Push(n-1);
        
        for (int i = n-2; i >= 0; i--)
        {
            while (stack.Count > 0)
            {
                if (numbers[i] > numbers[stack.Peek()])
                {
                    var top = stack.Pop();
                    x[top] = i + 1;
                }
                else
                {
                    break;
                }
            }
            
            stack.Push(i);
        }
        
        while(stack.Count > 0)
        {
            x[stack.Pop()] = -1;
        }
        
        stack.Push(0);
        
        for (int i = 1; i < n; i++)
        {
            while (stack.Count > 0)
            {
                if (numbers[i] > numbers[stack.Peek()])
                {
                    var top = stack.Pop();
                    y[top] = i + 1;
                }
                else
                {
                    break;
                }
            }
            
            stack.Push(i);
        }
        
        while(stack.Count > 0)
        {
            y[stack.Pop()] = -1;
        }
        
        for (int i = 0; i < n; i++)
        {
            answers.Add(x[i] + y[i]);
        }
        
        // Naive solution
        /*
        for (int i = 0; i < n; i++)
        {
            int x = -1;
            int y = -1;
            
           for (int k = i - 1; k >= 0; k--)
            {
                if (numbers[k] > numbers[i])
                {
                    x = k + 1;
                    break;
                }
            }
            
            for (int j = i + 1; j < n; j++)
            {
                if (numbers[j] > numbers[i])
                {
                    y = j + 1;
                    break;
                }
            }
            answers.Add(x + y);
        } */
        
        Console.WriteLine(string.Join(" ", answers));
    }
}
 
Java:
// import java.util.Scanner;
import java.util.Stack;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.PrintWriter;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
 
        // Scanner s = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        long[] arr = new long[n];
        int[] answers = new int[n];
        
        Stack<Integer> stack = new Stack<>();
        PrintWriter pr = new PrintWriter(System.out);
        
        for (int i = 0; i < n; ++i) {
            arr[i] = Long.parseLong(st.nextToken());
            while (!stack.empty() && arr[i] >= arr[stack.peek()]) {
                stack.pop();
            }
            if (stack.empty()) {
                answers[i] = -1;
            } else {
                answers[i] = stack.peek() + 1;
            }
            stack.push(i);
        }
        
        stack = new Stack<>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stack.empty() && arr[i] >= arr[stack.peek()]) {
                stack.pop();
            } 
            if (stack.empty()) {
                answers[i] += -1;
            } else {
                answers[i] += stack.peek() + 1;
            }
            stack.push(i);
        }
        
        for (int i = 0; i < n; ++i) {
            pr.print(answers[i] + " ");
        }
        pr.flush();
        pr.close();
    }
}
// class Element {
//     private long element;
//     private int index;
//     public Element(long element, int index) {
//         this.element = element;
//         this.index = index;
//     }
//     public long getElement() { return element; }
//     public int getIndex() { return index; }
// }

Java 8:
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
import static java.lang.Math.*;
 
public class CodingLegacy {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Palindrome solver = new Palindrome();
        int t = 1;
 
        for(int i=0;i<t;i++) {
            solver.solve(i+1, in, out);
        }
        out.close();
    }
 
    static class Palindrome {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = new long[n];
 
            for (int i = 0; i <n; i++) {
                a[i] = in.nextLong();
            }
 
            long[] nge1 = new long[n];
            long[] nge2 = new long[n];
 
            Stack<Integer> s = new Stack<>();
            for(int i=0;i<n;i++){
                while( !s.isEmpty() && a[s.peek()]<=a[i]){
                    s.pop();
                }
 
                nge1[i] = s.isEmpty()?-1:s.peek() +1;
                s.push(i);
            }
            s.removeAllElements();
 
            for(int i=n-1;i>=0;i--){
                while( !s.isEmpty() && a[s.peek()]<=a[i]){
                    s.pop();
                }
 
                nge2[i] = s.isEmpty()?-1:s.peek() +1;
                s.push(i);
            }
 
//            out.println(Arrays.toString(nge1));
//            out.println(Arrays.toString(nge2));
 
            for (int i = 0; i < n; i++) {
                out.print((nge1[i] + nge2[i])  + " ");
            }
        }
    }
 
    static class Maths{
        public static long gcd(long a, long b)
        {
            if (a == 0)
                return b;
            return gcd(b % a, a);
        }
 
        public static long factorial(int n){
            long fact = 1;
            for(int i=1;i<=n;i++){
                fact *= i;
            }
            return fact;
        }
    }
 
    static class Characters{
        public static boolean isVovel(char a){
            if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
                return true;
            }
            return false;
        }
    }
 
    static class Binary {
        public static long numberOfBits(long n){
            long count=0;
            while(n>0){
                count++;
                n >>=1;
            }
            return count;
        }
    }
 
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
 
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
 
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
 
        public int nextInt(){
            return Integer.parseInt(next());
        }
 
        public Long nextLong(){
            return Long.parseLong(next());
        }
    }
}

Javascript(Node.js):
let inputString = '';
let currentLine = 0;
 
function start() {
  process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
  });
 
  process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));
 
    main();
  });
}
 
function readLine() {
  return inputString[currentLine++];
}
 
function main() {
  const n = parseInt(readLine(), 10);
  const arr = readLine().split(' ').map(arrTemp => parseInt(arrTemp, 10));
  myWork(n, arr)
}
 
function myWork(n, arr) {
  let rightLargest = new Array(n)
  let leftLargest = new Array(n)
  let index
 
  leftLargest[0] = -1
  let stack = [0]
  for (let i = 1; i < n; i++) {
    do {
      index = stack.pop()
    } while (index != null && arr[index] <= arr[i])
 
    if (index != null && arr[index] > arr[i]) {
      leftLargest[i] = index + 1
      stack.push(index)
    } else {
      leftLargest[i] = -1
    }
    stack.push(i)
  }
 
  rightLargest[n-1] = -1
  stack = [n - 1]
  for (let i = n - 2; i > -1; i--) {
    do {
      index = stack.pop()
    } while(index != null && arr[index] <= arr[i])
 
    if (index != null && arr[index] > arr[i]) {
      rightLargest[i] = index + 1
      stack.push(index)
    } else {
      rightLargest[i] = -1
    }
    stack.push(i)
  }
  let rs = []
  for(let i = 0; i < n; i++) {
    rs[i] = (leftLargest[i] || -1) + rightLargest[i]
  }
  console.log(rs.join(' '))
}
 
start()

Pascal:
var d,e,g,i,j,k,m,n,mi,t,s,tf,tf2:longint;
var f,ar,arr,m1,n1:array[1..1000000] of int64;
begin
        readln(n);
        for i:=1 to n do
        begin
                read(ar[i]);
        end;
        j:=1;
        for i:=1 to n do
        begin
                for k:=j-1 downto 1 do
                begin
                        if(ar[i]>ar[arr[k]]) then
                        begin
                                m1[arr[k]]:=i;
                                arr[k]:=0;
                                j:=j-1;
                                continue;
                        end;
                        break;
                end;
                arr[j]:=i;
                j:=j+1;
        end;
        for i:=1 to j-1 do
        begin
                m1[arr[i]]:=-1;
        end;
        j:=1;
        for i:=n downto 1 do
        begin
                for k:=j-1 downto 1 do
                begin
                        if(ar[i]>ar[f[k]]) then
                        begin
                                n1[f[k]]:=i;
                                f[k]:=0;
                                j:=j-1;
                                continue;
                        end;
                        break;
                end;
                f[j]:=i;
                j:=j+1;
        end;
        for i:=1 to j-1 do
        begin
                n1[f[i]]:=-1;
        end;
        for i:=1 to n do
        begin
                write(n1[i]+m1[i],' ');
        end;
end.

Python:
n = input()
 
lis = map(int, raw_input().split())
 
stack1 = []
left_max = []
right_max = [0]*n
 
for i in xrange(n):
    cur = lis[i]
    while ( len(stack1) != 0 and lis[stack1[-1]] <= cur):
        stack1.pop()
    
    if len(stack1) == 0:
        left_max.append(-1)
    else:
        left_max.append(stack1[-1] + 1 )
    
    stack1.append(i)
stack1 = []
for i in xrange(n):
    ind = n-1-i
    cur = lis[ind]
    while ( len(stack1) != 0 and lis[stack1[-1]] <= cur):
        stack1.pop()
    if len(stack1) == 0:
        right_max[ind] = -1
    else:
        right_max[ind] = stack1[-1] + 1 
    
    stack1.append(ind)
    
for i in xrange(n):
    print (left_max[i] + right_max[i]),

Python 3:
n = int(input())
a = [int(x) for x in input().split()]
s = list()
l1 = [-1]*n
l2 = [-1]*n
s.append(n-1)
for i in range(n-2,-1,-1):
    while s:
        if a[s[-1]] < a[i]:
            l1[s[-1]] = i+1
            s.pop()
        else:
            break
    s.append(i)
while s:
    l1[s[-1]] = -1
    s.pop()
s = list()
s.append(0)
for i in range(1,n):
    while s:
        if a[s[-1]] < a[i]:
            l2[s[-1]] = i+1
            s.pop()
        else:
            break
    s.append(i)
while s:
    l2[s[-1]] = -1
    s.pop()
l3 = [x+y for x,y in zip(l1,l2)]
print(*l3)

*/