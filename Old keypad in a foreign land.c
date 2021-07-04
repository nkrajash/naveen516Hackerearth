/* All Tracks --> Algorithms --> Sorting --> Selection Sort --> Algorithms, Data Structures, Greedy algorithm, Sorting --> Problem --> 
Old keypad in a foreign land

Some people remain old fashioned and John is one of them. He doesn't like the new smart phones with full keypads and still uses the old keypads which require you to 
tap a key multiple times to type a single letter. For example, if the keyboard has two keys, one with the letters "adef" and the other one with the letters "zyx", 
then typing 'a' requires one keystroke, typing 'f' requires four keystrokes, typing 'y' requires two keystrokes, and so on.
He recently moved to a new country where the language is such that his keypad is not the most efficient. In every language some characters occur more often than others. 
He wants to create a specific keyboard for this language that uses N different letters. He has a large body of text in this language, and has already analyzed it to find 
the frequencies of all N letters of its alphabet.

You are given an array 'frequencies' with N elements. Each element of frequencies is the number of times one of the letters in the new language appears in the text 
John has. Each element of frequencies will be strictly positive. (I.e., each of the N letters occurs at least once.)

You are also given an array keySize. The number of elements of keySize is the number of keys on the keyboard. Each element of keySize gives the maximal number of letters 
that maybe put on one of the keys.

Find an assignment of letters to keys that minimizes the number of keystrokes needed to type the entire text. Output that minimum number of keystrokes. 
If there is not enough room on the keys and some letters of the alphabet won't fit, Output -1 instead.

Input Format

The first line will contain a number 'N' that specifies the size of 'frequencies' array
The second line will contain N numbers that form the frequencies array
The third line contains a number 'K' that specifies the size of the 'keySize' array
The fourth line contains K numbers that form the keySize array
Output Format

Output a single integer that is answer to the problem.
Constraints

frequencies will contain between 1 and 50 elements, inclusive.
Each element of frequencies will be between 1 and 1,000, inclusive.
keySizes will contain between 1 and 50 elements, inclusive.
Each element of keySizes will be between 1 and 50, inclusive.

SAMPLE INPUT 
4
7 3 4 1
2
2 2
SAMPLE OUTPUT 
19

Explanation
The foreign language has four letters. Let us call them W, X, Y and Z. John's text contains seven Ws, three Xs, four Ys, and one Z. 
The keyboard has two keys, each of them may contain at most two letters. One optimal solution is to use the keys "WZ" and "YX". 
We can then type each W and each Y using a single keystroke, and we need two keystrokes for each X and each Z. 
Therefore, the total number of keystrokes when typing the entire text will be 71 + 32 + 41 + 12 = 19.


//My submission
#include <stdio.h>
#define LEN 51
 
void selection_sort (int A[ ], int n) {
        int minimum,temp,i=0,j;        // temporary variable to store the position of minimum element
        for(; i < n-1 ; i++)  {         // reduces the effective size of the array by one in  each iteration.
             minimum = i ;        // assuming the first element to be the minimum of the unsorted array .
            for(j = i+1; j < n ; j++ ) {       // gives the effective size of the unsorted  array .
                if(A[ j ] < A[ minimum ])  {                //finds the minimum element
                minimum = j ;
                }
             }
		  temp=A[minimum]; // putting minimum element on its proper position by swapping
		  A[minimum] = A[i];
		  A[i]=temp;
        }
}

int main(){
	int i=0,j=0,k=0,temp,letters,freq[LEN],nkeys,key[LEN],total=0,sumkeys=0;
	scanf("%d",&letters);
	for(;i<letters;i++)
		scanf("%d",&freq[i]);
 
	//Selection sort
	selection_sort(freq,letters);
	scanf("%d",&nkeys);
	for(;j<nkeys;j++){
		scanf("%d",&key[j]);
		sumkeys+=key[j];
	}
	selection_sort(key,nkeys);

	if(letters>sumkeys)
		printf("-1\n");
	else{
        for(i=letters-1;i>=0;){
             k++;
             temp=0;
             for(j=0;j<nkeys;j++){
                 if(key[j]>=k){
                     temp+=freq[i]*k;
                     i--;
                 }
                 if(i<0)
                    break;
             }
             total+=temp;
         }
		printf("%d\n",total);
	}
	return 0;
}
*/

/* Editorial:
Link to solution code in Python: http://ideone.com/ik46LI

For understanding concepts required to solve this problem, i.e., Sorting Algorithms and Greedy Technique, kindly go through their CodeMonk tutorial: 
http://hackerearth.com/codemonk/

The way to deal with this problem is to apply the greedy approach. The character which appears more number of times needs to be given the lower position in the key-pad. 
One issue which needs to be taken care of is when the number of key-presses available is less than the number of characters, the answer in that case would be -1.

So, how do we proceed?

We sort (Or reverse sort, depending on the implementation) both our arrays. One, involving the number of characters, two involving the key-presses.
Then, we pick one number at a time, and keep assigning it to the key-pads, until the key-pad is exhausted. We do this in a greedily manner.
Look at the implementation mentioned in the problem and setter's solution for more clarity.

Author Solution by Sachin Gupta
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<cassert>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<list>
#include<math.h>
#include<ctime>
#define LL long long
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define FOR(i,lb,ub) for(i=lb;i<=ub;i++)
#define RFOR(i,ub,lb) for(i=ub;i>=lb;i--)
#define FORS(it,v) for(it=v.begin();it!=v.end();it++)
#define st_clk double st=clock();
#define end_clk double en=clock();
#define show_time cout<<"\tTIME="<<(en-st)/CLOCKS_PER_SEC<<endl;
#define sc(n) scanf("%d",&n)
#define scst(n) scanf("%s",n)
#define f_in(st) freopen(st,"r",stdin);
#define f_out(st) freopen(st,"w",stdout);
LL gcd(LL a, LL b) { return b?gcd(b,a%b):a; }
using namespace std;
 #ifndef ONLINE_JUDGE
inline int getchar_unlocked() { return getchar(); }
#endif
template <class T>
inline void r_f(T &p)
{
         char c;
         int neg=0;
         while ((c=getchar_unlocked()) < 48 || c > 57)
		 	if (c==45)
		 		neg=1;
         p=c-48;
         while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
         if (neg) p*=-1;
}
int main()
{
     #ifndef ONLINE_JUDGE
     f_in("in.txt");
     //f_out("out.txt");
     #endif
     int n,ar[55],ks,key_ar[1005],key_sum=0,i;
     cin>>n;
     assert(n<=50);
     FOR(i,0,n-1)
     {
     	cin>>ar[i];
     	assert(ar[i]<=1000);
     }
     sort(ar,ar+n);
     cin>>ks;
     assert(ks<=50);
     FOR(i,0,ks-1)
     {
     	cin>>key_ar[i];
     	assert(key_ar[i]<=50);
     	key_sum += key_ar[i];
     }
     sort(key_ar,key_ar+ks);
     if (key_sum<n)
     {
     	cout<<-1;
     	return 0;
     }
     int ans=0,indx=1,j;
     for (i=n-1;i>=0;)
     {
     	for (j=0;j<ks && i>=0;j++)
     	{
     		if (key_ar[j]>0)
     		{
     			key_ar[j]--;
     			ans += indx*ar[i];
     			i--;
     		}
     	}
     	indx++;
     }
     cout<<ans;
     
return 0;
}

*/

/* Best Submissions:
C:
#include <stdio.h>
 
int main()
{
    int n, k, f[51], s[51], num_keys, i, j, l, temp;
    unsigned long int count;
    
    scanf("%d",&n);
    
    for(i=0; i<n; i++) {
    	scanf("%d", &f[i]);
    }
    
    scanf("%d", &k);
    
    for(i=0, num_keys = 0; i<k; i++) {
    	scanf("%d", &s[i]);
    	num_keys += s[i];
    }
    
    if(num_keys < n) {
    	printf("-1\n");
    } else {
    	for(i=0; i<n; i++) {
	    	for(j=0; j<n; j++) {
	    		if(f[j] < f[i]) {
	    			temp = f[i];
	    			f[i] = f[j];
	    			f[j] = temp;
	    		}
	    	}
	    }
	    
	    count = 0;
	    j = 1;
	    l = 0;
	    while(l < n) {
	    	for(i=0; i<k && l<n; i++) {
	    		if(s[i] > 0) {
	    			s[i]--;;
	    			count += (f[l] * j);
	    			l++;
	    		}
	    	}
	    	j++;
	    }
	    
	    printf("%lu\n", count);
    }
    
    return 0;
}

C++:
#include <iostream>
#include<algorithm>
using namespace std;
 
int main()
{
    int n,freq[50],num_key,keysizes[50],stroke=-1,total_key=0,i,j,index,factor;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>freq[i];
    cin>>num_key;
    for(i=0;i<num_key;i++)
    { cin>>keysizes[i];
      total_key=total_key+keysizes[i];
    }  
    if(n>total_key)
    {  cout<<stroke;
       return 0;
    }
    sort(freq,freq+n);
   
    index=0;
    stroke=0;
    factor=1;
    for(i=n-1;i>=0;i--)
    {
    	for(j=index;j<num_key;j++)
    	{
    		//cout<<index;
    		if(keysizes[j]>0)
    		{
    			keysizes[j]--;
    			index=j+1;
    			stroke=stroke+factor*freq[i];
    			if(index==num_key)
    			{ index=0;
    			  factor++;
    			}
    			break;
    		}
    		
    		//cout<<stroke;
    	}
    	//cout<<freq[i]<<endl;
    	
    	//cout<<stroke<<endl;
    }
    cout<<stroke<<endl;
    return 0;
}


C++14:
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define pi(x) printf("%d ",x)
#define pll(x) printf("%lld ",x)
#define endl() printf("\n")
#define mp make_pair
#define pb push_back
#define fr first
#define se second
#define M 1000000007
 
inline void si(int &result)
{
    result=0;
    int sign=1;
    char ch = getchar_unlocked();
    while(ch < '0' || ch > '9')
    {
	   if(ch=='-')
       {
           sign=-1;
       }
       ch = getchar_unlocked();
    }
    while(ch >= '0' && ch <= '9')
    {
        result = (result<<3) + (result<<1) + (ch - 48);
        ch = getchar_unlocked();
    }
    result*=sign;
}
 
int main()
{
	ll n,i,j,x=0,m;
	cin >> n;
	vector<ll> a(n);
	for(i=0;i<n;i++)
	{
	    cin >> a[i];
	}
	sort(a.begin(),a.end());
	cin >> m;
	vector<ll> b(m),c(m,1);
	for(i=0;i<m;i++)
	{
	    cin >> b[i];
	    x+=b[i];
	}
	if(x<n)
	{
	    cout << -1 << endl;
	    return 0;
	}
	ll ans=0;
	while(true)
	{
	    for(i=0;i<m;i++)
	    {
	        if(c[i]<=b[i])
	        {
	            ans+=c[i]*a.back();
	            c[i]++;
	            a.pop_back();
	        }
	        if(!a.size())
	        {
	            break;
	        }
	    }
	    if(!a.size())
	    {
	        break;
	    }
	}
	cout << ans << endl;
}


C#:
using System; 
class MyClass {
    static void Main(string[] args) {
        
        // Read input from stdin and provide input before running
        //var line1 = System.Console.ReadLine().Trim();
        //var N = Int32.Parse(line1);
        //for (var i = 0; i < N; i++) {
        //    System.Console.WriteLine("hello world");
        //}
 
        Run();
    }
    
          static void Run()
        {
            int n = int.Parse(Console.ReadLine());
            string[] strN = Console.ReadLine().Split();
            int k = int.Parse(Console.ReadLine());
            string[] strK = Console.ReadLine().Split();
            int[] freq = new int[n];
            int safeCounter = 0;
            for (int i = 0; i < strN.Length; i++)
            {
                int number = -1;
                bool success = Int32.TryParse(strN[i],out number);
                if (success)
                {
                    freq[safeCounter] = number;
                    safeCounter++;
                }
            }
            int[] eachKeyBoard = new int[k];
            int totalAllowedAlphabate = 0;
            safeCounter = 0;
            for (int i = 0; i < strK.Length; i++)
            {
                int number = -1;
                bool success = Int32.TryParse(strK[i], out number);
                if (success)
                {
                    eachKeyBoard[safeCounter] = number;
                    totalAllowedAlphabate += eachKeyBoard[safeCounter];
                    safeCounter++;
                }
               
            }
            if (totalAllowedAlphabate >= n)
            {
                Array.Sort(freq);
                int costIndex = 1;
                long totalCost = 0;
                int position = n - 1;
                while (position >= 0)
                {
                    for (int i = 0; i < k; i++)
                    {
                        if (eachKeyBoard[i] > 0)
                        {
                            totalCost += (costIndex * freq[position]);
                            eachKeyBoard[i]--;
                            position--;
                            if(position < 0)
                            	break;
                        }
                    }
                    costIndex++;
                }
                Console.WriteLine(totalCost);
            }
            else
                Console.WriteLine(-1);
        }
}


Python:
n = int(raw_input())
fre = map(int, raw_input().split())
k = int(raw_input())
key = map(int, raw_input().split())
fre = sorted(fre, reverse=True)
key = sorted(key)
ans, idx = 0, 1
totkey = sum(key)
if totkey < n:
    	print -1
    	exit (0)
x = 0
for i in xrange(n):
    	for j in xrange(k):
    		if x < n :
    			if key[j]>0:
    				key[j] -= 1
    				ans = ans + idx*fre[x]
    				x = x + 1
    	idx = idx+1
print ans


Python 3:
n = int(input())
fre = map(int, input().split())
k = int(input())
key = map(int, input().split())
fre = sorted(fre, reverse=True)
key = sorted(key)
ans, idx = 0, 1
totkey = sum(key)
if totkey < n:
        print(-1)
 
else:
    x = 0
    for i in range(n):
            for j in range(k):
                if x < n :
                    if key[j]>0:
                        key[j] -= 1
                        ans = ans + idx*fre[x]
                        x = x + 1
            idx = idx+1
    print(ans)

Python 3:
n=int(input())
freq=[int(x) for x in input().split()]
 
k=int(input())
keysizes=[int(x) for x in input().split()]	
 
if n>sum(keysizes):
	print('-1')
	
else:
	freq.sort()
	total=0
	h=1
	
	while len(freq)!=0:
		for i in range(len(keysizes)):
			try:
				total+=freq.pop()*h
				
			except IndexError:
				break
				
			keysizes[i] -= 1
		for e in keysizes:
			if e==0:
				keysizes.remove(e)
				
		h+=1
	print(total)


Ruby:


Java:
1).
import java.io.*;
import java.util.*;
class oldKeyboard
{
  public static void main(String[] args)throws IOException
  {
     BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	 
	 int n=Integer.parseInt(br.readLine());
	 String[] s=br.readLine().split(" ");
	 int[] arr=new int[n];
	 
	 for(int i=0;i<n;i++)
	  { arr[i]=(Integer.parseInt(s[i]));}
	int temp=arr[0];
  for(int i=0;i<n;i++)
	{
	   for(int j=i+1;j<n;j++)
	   {
	      if(arr[i]<=arr[j])
		  {
		     temp=arr[i];
			 arr[i]=arr[j];
			 arr[j]=temp;
		  }
	   }
	}	
	
	
	// Arrays.sort(arr);
	  
	  int k=Integer.parseInt(br.readLine());
	  String[] ks=br.readLine().split(" ");
	  int[] arr2=new int[k];
	  int sum=0;
	  for(int i=0;i<k;i++)
       { arr2[i]=(Integer.parseInt(ks[i])); sum+=arr2[i];}
	 temp=arr2[0];
    for(int i=0;i<k;i++)
	{
	   for(int j=i+1;j<k;j++)
	   {
	      if(arr2[i]<=arr2[j])
		  {
		     temp=arr2[i];
			 arr2[i]=arr2[j];
			 arr2[j]=temp;
		  }
	   }
	}
 
 
 
	//Arrays.sort(arr2);
	  int i=0,j=0;
	  int count=1;
	  int res=0;
	 if(sum<n)
	  System.out.println(-1);
	 else
	     {
		    while(i<n && j<k)
			{ //System.out.println(arr2[j]);
              if(arr2[j]!=0){			  
			  res+=count*arr[i];
			  		    //System.out.println(count+" ....."+arr[arr.length-i-1]);
			   arr2[j]--;
			   j++;
			   if(j==k)
			    {j=0; count++;}
				i++;
				}
				else
				 { j=0;count++;}
				
			}
			
		    System.out.println(res);
		 } 
   }
}   

2).import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
     Scanner sc = new Scanner(System.in);
     int sum =0;
     int factor =0;
     int temp;
     int f = sc.nextInt();
     int[] freq = new int[f];
     for(int i =0;i<f;i++)
     freq[i] = sc.nextInt();
     int n = sc.nextInt();
     long maxKeys = 0;
     int[] keys = new int[n];
     for(int i=0;i<n;i++){
         keys[i] = sc.nextInt();
         maxKeys+=keys[i];
     }
     Arrays.sort(freq);
     for(int i=0;i<f;i++){
        System.out.println(freq[i]);
     }
     if(maxKeys < f)
     System.out.println(-1);
     else{
     for(int i =f-1;i>=0;){
         factor++;
         temp=0;
         for(int j=0;j<n;j++){
             if(keys[j]>=factor){
                 temp+=freq[i];
                 i--;
             }
            if(i<0)
            break;
         }
         sum+=factor*temp;
     }
     System.out.print(sum);
     }
    }
}

Java 8:
import java.util.*; 
import java.io.*;
public class Sort {
	public static void main(String[] args)throws Exception {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int n=Integer.parseInt(in.readLine());
        String[] aa=in.readLine().split(" ");
        ArrayList<Integer> a=new ArrayList<Integer>();
        for(int i=0;i<n;i++){
        	a.add(Integer.parseInt(aa[i]));
        }
        Collections.sort(a,Collections.reverseOrder());
        int q=Integer.parseInt(in.readLine());
        aa=in.readLine().split(" ");
        ArrayList<Integer> b=new ArrayList<Integer>();
        int sum=0;
        for(int i=0;i<q;i++){
        	b.add(Integer.parseInt(aa[i]));
        	sum+=b.get(i);
        }
        if(sum<n)
        	out.println("-1");
        else{
        	int total=0;
        	Collections.sort(b);
        	int qCnt=1;
        	Iterator<Integer> itr = a.iterator();
        	while(!a.isEmpty()){
        		for(int i=0;i<b.size();i++){
        			int temp;
        		if(b.get(i)!=0){ 
        			if(itr.hasNext()){
       				 temp=itr.next();
        		total+=qCnt*(int)temp;
        		b.set(i,b.get(i)-1);
        		//System.out.println(temp+" "+total);
        		itr.remove();
        	
        		}
        		}
        		}qCnt++;
        	}
        	out.println(total);
        }
        out.close();
	}
}

Ruby:
=begin
# Read input from stdin and provide input before running code
 
print "Please enter your name: "
name = gets.chomp
print "Hi #{name}\n"
=end
 
letter_num = gets.to_i
letter_freq = gets.split(' ').map(&:to_i).sort.reverse
 
key_num = gets.to_i
# O(nm), n = key_num, m = avg key_size
key_arr = gets.split(' ').map(&:to_i).map do |key_pad|
  (1..key_pad).to_a
end.flatten.sort
 
if key_arr.length >= letter_num
  sum = 0
  letter_freq.each_with_index do |lfreq, i|
    sum += lfreq * key_arr[i]
  end
 
  puts sum
else
  puts -1
end
 

*/


/*I/O:
In #1:
50
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
1
49
Out #1:
-1

In #2:
50
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50
1
50
Out #2:
22100

In #3:
50
1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000 1000
50
50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50 50
Out #3:
50000

In #4:
45
437 481 922 614 954 437 916 627 387 746 791 644 989 477 340 405 374 712 685 418 741 946 841 866 391 731 521 677 275 283 258 997 258 182 533 323 400 140 500 422 325 588 959 596 485
46
44 34 1 10 26 43 45 36 12 39 20 11 23 46 32 22 29 25 29 37 17 35 15 37 6 30 22 32 13 1 4 10 18 38 35 45 48 31 24 45 30 3 9 43 29 16
Out #4:
25594

In #5:
46
315 946 130 958 450 987 392 714 165 115 385 689 596 37 338 183 998 428 284 668 546 187 993 112 55 780 780 882 727 863 541 381 363 154 234 502 112 439 430 867 450 467 914 632 485 948
27
8 9 1 7 3 3 6 9 4 6 3 7 4 2 6 6 10 1 10 9 10 9 9 2 10 6 2
Out #5:
27992

In #6:
46
336 15 884 582 182 170 897 22 734 527 434 434 252 656 132 40 7 946 10 794 513 316 664 56 471 767 468 45 865 281 381 355 994 41 810 469 726 966 773 102 943 801 965 593 572 907
1
3
Out #6:
-1

In #7:
46
57 793 138 444 840 532 991 946 743 662 72 768 953 61 843 221 830 167 885 347 471 363 826 181 729 870 894 231 875 899 930 98 212 26 696 256 175 422 55 730 392 63 790 556 953 602
48
20 32 46 12 12 36 11 10 19 44 14 42 26 32 44 9 2 39 19 36 42 31 34 7 32 15 39 27 15 4 43 29 46 9 11 40 12 8 34 26 33 46 43 4 30 28 37 25
Out #7:
24588

In #8:
49
671 721 888 433 77 547 369 715 896 338 495 997 779 560 249 104 808 78 232 141 308 622 60 796 196 470 751 547 198 567 53 42 932 189 758 50 620 674 600 819 194 353 577 490 235 281 167 336 150
4
36 37 16 40
Out #8:
99088

In #9:
46
679 165 183 386 122 126 944 102 191 1000 710 589 239 648 18 724 302 963 461 117 155 557 397 800 135 252 599 58 427 215 660 903 27 933 546 277 301 889 540 724 314 805 544 486 980 343
3
46 4 42
Out #9:
137010

In #10:
50
835 970 994 22 333 1000 66 495 696 291 543 427 66 564 319 824 771 784 11 617 426 232 171 465 772 644 236 574 283 404 951 863 392 417 211 10 363 245 291 621 523 466 339 912 751 941 904 680 144 859
45
33 32 6 6 28 4 23 31 23 36 33 8 47 13 20 12 38 32 8 32 15 41 19 4 24 37 21 15 15 18 25 32 4 13 13 47 35 14 36 40 30 50 50 8 40
Out #10:
25893

*/

