/* All Tracks ---> Basic Programming ---> Implementation  --->Basics of Implementation --->  
Min-Max
Tag(s): Basic Programming, Very-Easy
Given an array of integers . Check if all the numbers between minimum and maximum number in array exist's within the array.
Print 'YES' if numbers exist otherwise print 'NO'(without quotes).

Input:
Integer N denoting size of array.
Next line contains N space separated integers denoting elements in array.

Output:
Output your answer.

Constraints:
1<= N <= 1000
1<= a[i] <= 100

SAMPLE INPUT 
6
4 2 1 3 5 6
SAMPLE OUTPUT 
YES

//My C Solution:
#include <stdio.h>
#include <stdlib.h>
#define N 1000

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int min=1,max=100,n,i=0,a[N],dup=0,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a, n, sizeof(int), cmpfunc);
    max=a[n-1];
    min=a[0];
    for(i=0;i<n;i++){
        if(i!=n-1){
            if(a[i+1]== a[i])
                dup++;
            else if((a[i+1])==(a[i]+1))
                count++;
        }
        else{
            if(a[i+1]== min)
                dup++;
            else
                count++;
        }
    }
    if((a[n-1]==a[0]+count-1) && dup==n-count)
        printf("YES");
    else
        printf("NO");
    return 0;
}

//My C++ Solution:
#include <iostream>
using namespace std;
#include <cstdlib>

#define N 1000

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int min=1,max=100,n,i=0,a[N],dup=0,count=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    qsort(a, n, sizeof(int), cmpfunc);
    max=a[n-1];
    min=a[0];
    for(i=0;i<n;i++){
        if(i!=n-1){
            if(a[i+1]== a[i])
                dup++;
            else if((a[i+1])==(a[i]+1))
                count++;
        }
        else{
            if(a[i+1]== min)
                dup++;
            else
                count++;
        }
    }
    if((a[n-1]==a[0]+count-1) && dup==n-count)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}


// Java solution:
import java.util.*;
import java.io.*;
class temp {
public static void main(String args[] ) throws Exception {
FastReader s=new FastReader();
PrintStream p = System.out;
boolean b1 = false,b2=false;
int n=s.nextInt();
int a[]= new int[n];

for(int i=0;i<n;i++)
{
a[i]=s.nextInt();
}
Arrays.sort(a);
boolean flag=true;

for(int j=0;j<n-1;j++)
{
if((a[j+1]-a[j])>1)
flag=false;
}
System.out.println((flag==true)?"YES":"NO");
}
static class FastReader{
BufferedReader br;
StringTokenizer st;

public FastReader(){
br = new BufferedReader(new
InputStreamReader(System.in));
}

String next(){
while (st == null || !st.hasMoreElements()){
try{
st = new StringTokenizer(br.readLine());
}
catch (IOException e){
e.printStackTrace();
}
}
return st.nextToken();
}

int nextInt(){
return Integer.parseInt(next());
}

long nextLong(){
return Long.parseLong(next());
}

double nextDouble(){
return Double.parseDouble(next());
}

String nextLine(){
String str = "";
try{
str = br.readLine();
}
catch (IOException e){
e.printStackTrace();
}
return str;
}
}
}

// C++ solution:
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i,c=0,k=0,min1=100000,max1=0,flag=0;;
int arr[1001];
cin>>n;
for(i=0;i<n;i++)
{
cin>>k;
arr[k]++;
if(k>max1)
max1=k;
if(min1>k)
min1=k;
}
for(i=min1;i<=max1;i++)
{
if(arr[i]==0)
{
flag=1;
break;
}
}
if(flag==1)
cout<<"NO";
else
cout<<"YES";
}

Input #1:
10
8 6 2 10 10 7 7 9 7 5
Output #1:
NO

Input #2:
10
4 5 1 5 5 5 5 1 5 3
Output #2:
NO
Input #3:
10
4 5 2 4 2 3 1 5 1 2
Output #3:
YES
Input #4:
10
6 8 10 12 14 16 18 20 22 24
Output #4:
NO
Input #5:
100
17 11 6 15 9 16 15 10 19 12 15 17 19 10 2 7 2 16 20 9 5 9 3 7 20 19 14 8 16 13 4 3 3 4 4 19 14 10 2 19 15 15 14 6 10 16 19 18 10 14 15 4 8 1 13 11 11 8 3 16 12 18 17 2 12 13 1 9 7 9 5 1 12 1 6 3 2 6 18 7 1 12 5 12 18 14 11 4 3 11 5 1 14 2 12 14 15 6 6 6
Output #5:
YES
Input #6:
1000
27 11 16 5 29 16 15 10 29 22 15 7 29 10 2 17 22 6 20 29 25 9 3 7 20 9 4 18 16 23 24 3 23 14 24 19 4 30 2 19 25 15 14 26 20 16 9 8 10 14 5 24 8 1 23 21 21 18 23 16 12 28 27 22 12 13 11 19 17 19 25 1 22 1 16 3 2 6 28 17 21 2 5 12 18 4 1 14 13 1 15 21 4 22 2 4 15 6 6 6 8 12 30 26 15 4 10 22 14 9 24 3 4 23 8 6 15 22 17 28 21 9 22 1 18 8 14 29 16 26 21 6 8 10 7 21 8 16 14 1 8 13 3 29 24 16 18 15 8 9 23 24 20 29 12 5 21 19 27 13 25 30 16 21 2 25 20 8 30 25 14 3 6 3 17 27 9 1 5 4 9 6 8 17 7 20 1 12 18 11 29 23 9 12 15 27 15 19 26 20 25 1 26 9 23 2 24 1 8 6 15 2 19 10 8 15 25 21 7 30 22 3 2 16 23 27 12 14 10 27 9 23 20 16 10 11 21 30 20 5 9 14 6 23 7 29 16 28 3 18 12 1 8 30 22 2 29 5 28 25 13 8 29 21 6 18 9 13 7 28 6 8 3 28 22 29 18 30 1 21 8 19 24 3 27 4 24 7 19 17 7 25 23 24 6 27 10 21 1 24 4 21 17 16 2 28 4 21 7 20 1 30 30 11 30 9 24 14 1 4 4 14 20 8 22 14 12 19 1 11 25 22 27 23 23 5 25 25 12 25 5 23 6 29 14 29 24 27 15 20 9 9 13 18 1 22 4 21 9 2 22 17 13 17 25 15 19 6 25 20 8 21 27 24 14 18 27 27 30 9 25 21 23 12 20 18 19 2 2 27 13 20 12 22 24 4 27 30 29 14 8 21 26 6 15 22 3 26 14 4 8 24 26 14 25 23 16 13 2 16 11 1 21 19 23 9 6 5 6 24 1 17 23 29 24 2 6 7 6 4 6 1 8 28 2 25 11 11 13 12 3 16 13 12 28 6 8 4 9 16 7 1 1 27 16 21 4 22 2 24 19 28 8 30 18 30 4 13 5 19 27 3 12 25 8 20 16 29 20 11 16 30 26 28 11 11 24 25 18 24 21 7 6 14 21 20 24 14 3 17 7 5 16 4 18 7 11 17 14 6 20 19 19 25 24 24 19 23 1 18 5 30 10 9 3 10 29 18 27 28 21 17 8 21 27 2 19 10 16 24 28 19 9 29 13 2 14 9 26 23 20 19 4 29 10 29 16 1 9 10 7 11 4 21 26 19 10 12 22 21 28 8 18 1 8 13 27 11 25 8 16 23 28 2 13 11 1 5 11 9 30 6 8 23 23 17 26 9 6 4 27 9 19 10 24 7 4 10 13 2 10 8 2 22 24 16 23 17 21 12 6 28 1 29 8 27 24 16 3 4 27 23 1 2 21 19 18 27 5 19 18 26 6 10 11 27 9 3 4 11 1 23 23 29 21 26 1 27 2 12 21 25 22 30 3 22 3 21 15 27 18 18 17 29 12 14 29 26 4 12 20 29 9 20 16 9 23 4 7 9 24 9 28 28 4 15 18 3 12 12 27 29 7 28 29 4 6 20 20 27 10 20 1 28 4 7 6 10 24 6 18 24 3 29 2 21 28 7 17 28 28 23 5 30 11 2 1 13 15 22 4 6 5 21 30 18 26 10 17 16 9 22 12 10 14 15 29 21 25 23 6 27 5 17 6 11 2 12 27 20 11 14 17 10 4 30 9 11 29 13 28 2 3 4 23 11 8 11 4 9 20 7 22 18 16 30 20 10 11 3 28 14 1 28 2 2 8 1 19 11 29 28 10 16 24 17 12 12 16 23 14 22 12 30 5 22 23 19 19 9 3 8 26 23 9 13 19 10 26 23 21 9 24 17 27 28 19 10 7 16 20 27 5 10 13 10 26 23 7 9 5 18 18 29 29 23 19 6 23 30 29 11 7 20 25 2 25 28 23 1 19 26 19 30 2 11 20 26 9 14 15 22 14 28 27 24 3 27 17 22 28 16 18 15 19 8 23 27 13 17 21 23 23 30 3 5 5 27 23 23 29 27 6 25 1 9 26 24 28 9 20 5 23 4 26 24 15 5 30 17 21 18 10 15 2 10 28 25 14 14 30 25 21 4 19 7 25 21 18 30 14 13 22 23 2 17 25 19 11 29 5 21 10 21 15 23 1 20 21 16 19 20 22 1 3 2 21 22 26 19
Output #6:
YES
Input #7:
1000
42 59 57 43 38 33 55 89 23 14 27 90 49 60 43 46 16 31 18 16 70 89 27 94 99 2 3 89 52 54 96 37 31 3 31 91 69 57 28 85 65 24 40 62 73 54 4 31 87 61 8 49 50 36 22 71 44 72 37 26 65 40 16 75 17 85 55 77 79 53 16 65 80 24 97 46 58 53 29 4 11 71 60 99 32 31 1 75 93 11 43 39 76 27 73 94 82 95 97 93 60 46 10 39 21 6 58 58 80 47 84 98 17 44 15 35 77 55 54 18 34 56 36 67 51 78 83 42 27 77 73 47 71 67 72 24 39 16 63 65 94 31 96 17 53 24 63 8 84 95 74 83 6 70 19 76 62 94 59 42 46 42 16 35 21 60 25 36 36 68 36 88 60 18 29 65 22 83 13 24 98 51 86 23 77 14 37 44 26 25 75 19 27 58 4 4 53 50 93 62 40 1 17 3 80 95 43 54 24 58 18 41 31 68 76 62 5 7 55 40 30 98 45 33 42 57 71 59 88 4 64 96 72 51 26 70 27 26 98 95 80 8 16 72 42 37 70 24 3 97 17 84 3 85 43 16 26 68 59 52 18 66 62 28 40 79 100 5 88 59 86 37 34 93 29 49 92 58 86 5 10 96 51 51 49 71 11 100 35 10 30 27 42 60 71 59 79 76 93 40 81 47 63 33 53 98 23 56 52 12 46 4 56 41 38 3 75 14 55 56 50 99 62 44 36 23 79 21 78 95 38 62 38 25 21 4 34 70 84 64 3 90 1 23 57 31 32 18 34 25 17 58 43 48 81 50 81 66 39 50 20 50 20 80 64 6 48 41 57 81 47 31 92 92 2 100 26 62 79 97 49 17 68 16 41 59 94 15 33 49 97 54 78 15 5 18 71 12 33 75 97 72 59 67 16 67 67 76 31 23 65 92 21 88 44 75 65 3 56 25 55 9 74 40 79 94 7 92 78 45 94 33 50 70 86 37 7 74 11 95 95 97 68 79 54 13 81 18 58 73 77 53 52 57 83 57 44 85 25 65 42 85 85 52 41 3 75 57 72 49 14 40 67 96 6 81 95 77 15 67 53 27 76 94 32 89 70 53 52 14 70 27 66 22 24 36 82 91 54 98 24 72 92 61 54 29 85 12 96 75 82 40 41 48 25 94 82 6 85 80 69 36 40 80 23 94 61 93 40 51 3 18 54 40 57 44 85 62 92 38 22 51 78 66 71 17 76 19 58 27 70 94 88 100 10 85 28 49 10 98 80 58 82 23 55 88 85 14 47 94 27 12 5 57 71 73 83 9 29 90 29 8 39 54 91 49 8 54 2 9 57 33 81 53 35 46 98 33 57 31 53 82 42 69 56 58 93 25 72 24 73 79 67 58 67 53 18 23 42 19 9 80 13 80 56 66 18 35 28 33 79 90 3 44 37 39 56 97 5 58 59 94 2 46 19 24 30 59 1 54 4 31 52 77 58 60 69 27 76 26 61 98 28 93 24 95 60 96 96 62 37 43 55 80 1 35 74 34 36 4 58 39 66 95 7 61 4 61 43 60 27 74 56 76 77 42 33 80 43 41 73 50 18 53 29 65 35 13 27 97 56 60 4 33 52 35 28 35 27 10 90 80 80 88 77 61 100 42 1 65 34 58 95 8 73 69 4 33 14 65 79 59 100 34 5 21 98 31 4 83 39 37 84 35 88 64 65 95 35 37 61 53 93 83 69 88 28 100 65 61 3 95 41 86 4 72 89 82 92 79 2 98 48 40 50 97 89 50 100 62 52 39 68 33 100 76 52 91 77 1 52 20 47 63 30 86 6 52 74 24 39 63 28 86 94 88 75 3 33 46 69 24 89 63 67 31 16 12 3 64 75 90 28 74 37 13 38 74 7 59 65 15 53 18 62 33 17 53 68 15 91 76 33 23 49 27 62 26 15 89 86 27 77 93 49 20 84 76 96 82 43 12 97 20 35 5 93 99 57 43 64 92 10 11 28 10 63 53 44 98 23 57 15 17 41 100 93 45 78 1 41 50 14 69 87 98 38 64 49 59 19 1 85 87 24 48 97 18 69 66 33 20 46 85 68 77 86 76 29 33 94 28 88 67 21 88 54 33 25 27 97 29 37 13 11 82 16 99 88 54 62 26 70 59 10 96 33 67 32 53 52 96 20 81 58 28 94 67 96 42 75 9 49 41 16 25 51 52 14 32 94 70 42 32 19 43 50 68 43 87 63 34 76 75 96 68 42 77 67 4
Output #7:
YES
Input #8:
1000
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 7 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
Output #8:
NO

*/

/* Best Submissions:
#include <stdio.h>
 
int main()
{
    int n, min, max;
    int num, a[101]={0};
    
    scanf("%d", &n);
    
    scanf("%d", &num);
    min=max=num;
    a[min]=1;
    
    while(--n){
        scanf("%d", &num);
        if(min>=num)
            min=num;
        else if(max<num)
            max=num;
        a[num]=1;
    }
    
    while(a[++min])
        ;
    if(min>max)
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}

C++:
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n, A[1000] = {}, may = 0, men = 101, m;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        if(m < men) men = m;
        if(m > may) may = m;
        A[m]++;
    }
    for(int i = men; i <= may; i++)
        if(A[i] == 0) {cout << "NO"; return 0;}
    cout << "YES" << endl;
    return 0;
}

C++14:
#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    int j,count=0,temp,min;
    for(int i=0;i<N-1;i++)
    {
    for(j=0;j<N-1;j++)
    {
        if(a[j+1]<a[j])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
    }
 
    for(j=1;j<N;j++)
    {
    if(a[j]-a[j-1]>=2)
    {
        cout<<"NO";
        break;
    }
    else
    {
        count++;
    }
    }
    if(count==N-1)
    cout<<"YES";
    return 0;
}

C#:
using System; 
using System.Numerics;
using System.Collections.Generic;
using System.Linq;
class MyClass {
    static void Main(string[] args) {
       HashSet<int> hs = new HashSet<int>();
       
       int n = Convert.ToInt32(Console.ReadLine());
       string[] str = Console.ReadLine().Split(' ');
       int min = int.MaxValue;
       int max = int.MinValue;
       
       for(int i=0; i<n ; i++){
           int v = Convert.ToInt32(str[i]);
           if(min > v){
               min=v;
           }
           if(max < v){
               max = v;
           }
           hs.Add(v);
       }
       
       bool found = true;
       
       for(int i = min ; i<=max; i++){
           if(!hs.Contains(i))
           {
               found = false;
               break;
           }
       }
       
       if(found){
           Console.WriteLine("YES");
       }else{
           Console.WriteLine("NO");
       }
       
    }
}

Java:
/* IMPORTANT: Multiple classes and nested static classes are supported */
 
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int nums[] = new int[N];
        String numbers[] = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            nums[i] = Integer.parseInt(numbers[i]);
        }
        Arrays.sort(nums);
        int min = nums[0];
        int max = nums[N-1];
        int ctr = Math.abs(max-min-1);
        
        for(int step = 1, i = 1;i<N||ctr==0;i++) {
            //  System.out.println(step+"-"+ctr+"-"+nums[i]);
            if(ctr==0) {
                 break;
             }
             if(nums[i] == min + step) {
                 step++;
                 ctr--;
             }
        }
        if(ctr==0) System.out.println("YES");
        else System.out.println("NO");
    }
}

Java 8:
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
public class MinMax {
 
	public static void main(String[] args) throws IOException {
 
		BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
 
		int num=Integer.parseInt(bi.readLine());
		String[] strNums;
 
		strNums = bi.readLine().split("\\s");
		int[] n = new int[strNums.length];
		for(int i=0; i<strNums.length; i++) {
			n[i] = Integer.parseInt(strNums[i]);
		}
		
		int temp;
		for(int i=0; i < num; i++){  
			for(int j=1; j < (num-i); j++){  
				if(n[j-1] > n[j]){  
					temp = n[j-1];  
					n[j-1] = n[j];  
					n[j] = temp;  
				}  
 
			}  
		}
		
		int start=n[0];
		for(int i=1;i<n.length;i++){
			if((start+1)==n[i]){
				start++;
				continue;
			}
			else if(start==n[i]){
				continue;
			}
			else{
				System.out.println("NO");
				System.exit(0);
			}
		}
		System.out.println("YES");
 
	}
 
}

JavaScript(Rhino):
// Below is a sample code to process input from STDIN.
// Equivalent in effect to the Java declaration import java.io.*;
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);
 
var len = sc.nextInt();
var arr = [];
 
for(var i = 0; i < len; i++){
	arr[i] = sc.nextInt();
}
 
var min = arr[0];
var max = 0;
 
for(var i=0; i<arr.length; i++){
	for(var j = 0; j<i; j++){
		if(arr[i] == arr[j]){
			arr.splice(i, 1);
			i--;
			break;
		}
	}
	if(arr[i] < min){
		min = arr[i];
	}
	if(arr[i] > max){
		max = arr[i];
	}
}
 
len = arr.length;
 
if(len == (max-min+1)){
	print('YES');
}
else{
	print('NO');
}

JavaScript(Node.js):
function main(input) {
    //Enter your code here
   
var a = input.split('\n');
	var n = a[0] - 1;
	a = a[1].split(' ').sort(function(o, p){return o-p});
	var x = a[0], c = -1, r = a[n] - a[0];
	for(i = 0; i <= n; i++){
		if(x == a[i]){
			x++;
			c++;
		}
	}
	if(c === r){
    	process.stdout.write("YES");
	}else{
    	process.stdout.write("NO");
	}
 
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
var i,j,tmp,c,n:longint;
a:array[1..1000] of longint;
procedure swap(var x,y:longint);
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;
begin
    readln(n);
    for i:=1 to n do
    read(a[i]);
    for i:=1 to n-1 do
    for j:=i+1 to n do
    if a[i]>a[j] then swap(a[i],a[j]);
    c:=1;
    for i:=1 to n-1 do
    if (a[i]<>a[i+1]-1) and (a[i]<>a[i+1]) then 
    begin
        c:=0;
        break;
    end;
    if c=1 then writeln('YES') else writeln('NO');
end.

Perl:
$dummy=<>;
$input=<>;
@data=split(/ /,$input);
my @arr = keys { map { $_ => 1 } @data };
$min=$arr[0];
$max=$arr[0];
foreach(@arr){
        if($_>$max){
            $max=$_;
            }
        if($_<$min){
            $min=$_;
            }
    }
$flag=$max-$min+1;
 
 
for($i=$min;$i<=$max;$i++){
    foreach(@arr){
        $flag-- if $i==$_;
        }
    }
if ($flag==0){
print "YES";    
}else{
    print "NO";
    }

	
Python:
count = int(raw_input())
 
str_in = raw_input()
list_str = str_in.split(' ')
 
for i in range(count):
    list_str[i] = int(list_str[i])
max_n = max(list_str)
min_n = min(list_str)
val = "YES"
while min_n < max_n:
    if min_n not in list_str:
        val = "NO"
        break
    min_n += 1
print(val)


Python 3:
n = int(input())
array = [int(x) for x in input().split(" ")]
array.sort()
yes = True
for i in range(1,len(array)):
    if (array[i] - array[i-1]) > 1:
        yes = False
if yes:
    print("YES")
else:
    print("NO")


PHP:

<?php

fscanf(STDIN, "%d\n", $len);
fscanf(STDIN, "%[^,]", $str);
 
$a = explode(' ', $str);
 
 
function checkExist($min,$max, $a){
    for($i = $min;$i<=$max;$i++){
    if(!in_array($i,$a)){
        return false;
    }
}
return true;
}
 
 
 
echo checkExist(min($a), max($a),$a) ? "YES\n" : "NO\n";
 
?>

R:
a <- scan("stdin", what = "")
a <- as.integer(a)
n <- a[1]
arr <- a[2:(length(a))]
m <- min(arr)
m2 <- max(arr)
z <-c(m : m2)
count <- 0
for(i in 1:length(z))
{
  if(z[i]  %in% arr)
    count <- count+1
}
 
if(count == length(z))
{
    cat("YES")
}else{
    cat("NO")
}

Ruby:

=begin
# Read input from stdin and provide input before running code
 
print "Please enter your name: "
name = gets.chomp
print "Hi #{name}\n"
=end
 
n = gets.to_i
arr = gets.chomp.split(' ').map(&:to_i)
arr_x = arr.uniq.sort
 
# print "sorted = #{sorted_arr}\n"
 
flag = true
for i in 0..arr_x.length-2
    flag &&= (arr_x[i]+1 == arr_x[i+1]);
    break unless flag
end
s = flag ? "YES" : "NO"
print "#{s}"


*/

