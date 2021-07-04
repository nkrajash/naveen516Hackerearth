/* All Tracks --> Data Structures --> Hash Tables --> Basics of Hash Tables --> Problem
ICPC Team Management
Tag(s): Ad-Hoc, Easy
Little Chandan is an exceptional manager - apart from his role in HackerEarth - as the person who has to bug everyone, 
in general... and if possible, try to get some work done.
He's also offered a job as the coach of the best Russian teams participating for ACM-ICPC World Finals. 
Now, Chandan is an extremely good coach, too. But he's a weird person who thrives on patterns in life, in general. 
So, he has decided that if there are n number of students in total, and he is supposed to divide them in camps of k students - he want them to be arranged in such a way 
that the length of names of all the students in a camp is equal.
I know, totally weird, right?

Input:
The first line will contain the number of test cases. Which will be followed by two integers, n, k - denoting the number of total students, 
and the number of total students which will be allowed in one camp. 
After which, n lines will follow denoting the names of all the students who're willing to learn by the great coach.

Output:
If it is possible for all the students be arranged in a camp of k students, print "Possible", else print "Not possible".

Constraints:
1 <= Test Cases <= 50
1 <= N <= 1000
1 <= K <= 1000
1 <= LengthOfAString <= 100
The name of a programmer will always be in lower case.
PS: n%k will ALWAYS be equal to zero - that is, it will possible to divide the n students in equal sized camps of k.

SAMPLE INPUT 
2
6 3
arjit
tijra
genius
chanda
ashish
arjit
4 2
bond
coder
bond
lol

SAMPLE OUTPUT 
Possible
Not possible

Explanation:
In the first case, we can divide the six members into two teams of three with people having equal number of characters in their names. 
In the second case, we cannot do the same.


//My C Solution:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 101
#define MAX 1001

int main(){
    int i,j,N,K,l,t,*arr,flag;
    char name[LEN];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        arr = calloc(LEN,sizeof(int));
        flag= 0;
        scanf("%d%d",&N,&K);
        for(l=0;l<N;l++){
            scanf("%s",name);
            j=strlen(name);
            arr[j]++;
        }
        if(K==1||N==1)
            printf("Possible\n");
        else{
            for(j=1;j<=100;j++){
                if(arr[j]%K){
                    flag=1;
                    break;
                }
            }
            if(flag) 
                printf("Not possible\n");
            else
                printf("Possible\n");
        }
        free(arr);
    }
    return 0;
}

*/

/*Best Submissions:
C:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    int cases, N, K, i, j, len, bins[100], flag;
    scanf("%d", &cases);
    int results[cases];
    //printf("cases: %d\n", cases);
    
    for (i=0; i<cases; i++) {
    	flag = 0;
    	for (j=0; j<100; j++) {
    		bins[j] = 0;	
    	}
    	
    	scanf("%d %d", &N, &K);
    	//printf("scanned: %d, %d\n", N, K);
   		char str[N][100];
   		
   		for (j=0; j<N; j++) {
   			scanf("%s", str[j]);
   			len = strlen(str[j]);
   			//printf("%d\n", len);
   			bins[len] += 1;
   		}
   		
   		for (j=0; j<100; j++) {
   			if (bins[j] % K != 0) {
   				results[i] = 0;
   				flag = 1;
   				break;
   			}
   		}
   		if (flag == 0) {
   			results[i] = 1;
   		}
    }
    
    for (i=0; i<cases; i++) {
    	if (results[i] == 0) {
    		printf("Not possible\n");
    	}
    	else {
    		printf("Possible\n");
    	}
    }
    return 0;
}
C++:
1).
#include <iostream>
#include<string>
using namespace std;
 
int main()
{
	int T;
	cin >> T;
	for(int i=0;i<T;i++)
	{
    	int total,stu;
    	cin >> total;
    	cin >> stu;
    	int max=0;
    	int min=102;
    	string st;
    	int* len;
    	len=new int[total];
    	int* acc;
    	acc = new int[101]();
    	for(int j=0;j<total;j++)
		  {
		   	cin >> st;
		   	len[j]=st.size();
		   	acc[len[j]]++;
		   	if(len[j]>max)
		   	max=len[j];
		   	if(len[j]<min)
		   	min=len[j];
		   	st.clear();
		  }
		  int flag=0;
	  for(int k=min;k<=max;k++)
	  {
	  	if(acc[k]%stu!=0)
	  	flag=1;
	  }
	  
	  if(flag==1)
	  cout << "Not possible" <<endl;
	  else if(flag==0)
	  cout << "Possible" << endl;
	}
}

2).
#include <iostream>
#include <sstream>
#include <map>
using namespace std;
 
typedef map<int, int> mii;
 
 
void getInts(int& a, int& b)
{
   a = -1;
   b = -1;
   string line;
   getline(cin, line);
   istringstream iss(line);
   int n = -2;
   while (iss >> n)
   {
      if (a == -1)
         a = n;
      else
         b = n;
   }
}
 
int main()
{
   int num = 0;
   map<int, int> ii;
   auto itr = ii.begin();
   cin >> num;
   cin.ignore();
   int tot = -1;
   int k = 3;
   while (num--)
   {
      ii.clear();
      getInts(tot, k);
      string res = "Possible";
      string name;
      while (tot--)
      {
         getline(cin, name);
         if ((itr = ii.find(name.length())) == ii.end())
         {
            ii.insert(pair<int, int>(name.length(), 1));
         }
         else
         {
            ii[itr->first] = ++itr->second;
         }
      }
 
      for (auto itrM = ii.begin(); itrM != ii.end(); itrM++)
      {
         if (itrM->second % k != 0)
         {
            res = "Not possible";
            break;
         }
      }
      cout << res << endl;
   }
   return 0;
}
3).
#include<iostream>
#include<string>
#include<vector>
#include<map>
 
using namespace std;
 
int main()
{
 int t;
 cin>>t;
 
 while(t--)
    { int n,k;
      bool flag = true;
     cin>>n>>k;
     vector <string> a(n);
 
     for(int i =0;i<n;i++)
        cin>>a[i];
 
     map <int,int> table;
 
     for(int x =0;x<n;x++)
        {
         if(table[ a[x].length() ]  == NULL)
            {table[a[x].length()] = 1;}
         else
            table[a[x].length()]++;
        }
 
     for(map <int,int> :: iterator i = table.begin(); i != table.end(); i++)
        {if(i->second % k != 0)
            {flag  = false;break;
            }
        }
     if(flag)
        {cout<<"Possible\n";}
     else
        cout<<"Not possible\n";
    }
 
return 0;
}
4).
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int arr[100],i;
			for(i=1;i<=100;i++)
				arr[i]=0;
		int n,k;
		cin>>n>>k;
		if(n%k==0)
		{
			char a[n][100];
			for(i=0;i<n;i++)
				cin>>a[i];
			for(i=0;i<n;i++)
			{
				int len=strlen(a[i]);
				if(len<=100)
				{
				    if(arr[len]==k)
				    {
				    	arr[len]=0;
				    }
				    arr[len]++;
				}
				else
				{
					cout<<"Not possible\n";
				}
			}
			for(i=1;i<=100;i++)
			{
				if(arr[i]==0)
					arr[i]=k;
			}
			int count=0;
			for(i=1;i<=100;i++)
			{
				if(arr[i]==k)
					count++;
			}
			if(count==100)
				cout<<"Possible\n";
			else
				cout<<"Not possible\n";
		}
		else
		{
			cout<<"Not possible\n";
			break;
		}
	}
	return 0;
}
5).
#include <iostream>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        int a[102];
        
        // if(k==1)
        // cout << "Possible" << endl;
        // else
        {
                for(int i=0;i<102;i++)
                {
                    a[i]=0;
                }
                
                string s;
                for(int i=0;i<n;i++)
                {
                    cin >> s;
                    //  cout << "length" << s.length() << endl;
                    a[s.length()]++;
                }
                
                // for(int i=0;i<102;i++)
                // {
                //     cout << a[i];
                // }
                
                int fg=0;
                for(int i=0;i<102;i++)
                {
                    if(!(a[i]==0 || a[i]%k == 0))
                    {
                        fg=1;
                    }
                }
                
                if(fg)
                cout << "Not possible" << endl;
                else
                cout << "Possible" << endl;
            
        }
    }
}
6).
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t,i,flag;
    int arr[101];
    cin>>t;
    while(t--){
        memset(arr, 0, sizeof(arr));
        int n,k;
        flag=0;
        cin>>n>>k;
        while(n--){
            string str;
            cin>>str;
            arr[str.size()]+=1;
        }
        if(k==1){
            cout<<"Possible\n";
            continue;
        }
            
        for(i=1;i<101;i++){
            if(arr[i]%k!=0&&arr[i]!=0){
                flag+=1;
                break;
            }
        }
        if(flag==0){
            cout<<"Possible\n";
        }
        else{
            cout<<"Not possible\n";
        }
    }
    return 0;
}

C++14:
1).
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,l,a[101]={0},b=0;
        cin>>n>>k;
        
        string temp;
        
        while(n--)
        {
        
        cin>>temp;
         l = temp.size();
         a[l]++;
         
        
        }
        sort(a,a+101,greater<int>());
        
        l=0;
        while(a[l]!=0)
        {
            if(a[l]%k)
            {
                b=1;
                break;
            }
            l++;
        }
        
        if(b==0)
        cout<<"Possible"<<endl;
        else
        cout<<"Not possible"<<endl;
        
    }
    
    return 0;
}
2).
/* prateek_imkp1 */
#include<bits/stdc++.h>
#define ll long long int
#define loop(i,s,e) for(int i=s;i<=e;i++)
#define io std::ios::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define pb push_back
#define mkp make_pair
#define pii pair<ll,ll>
using namespace std;
#define MAX 100001
#define INF 1000000000000000
int main()
{
    io
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a;
        string str;
        
        while(n--)
        {
            cin>>str;
            a.pb(str.length());
        }
        sort(a.begin(),a.end());
        string flag="Possible";
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=a[i/k*k])
            {
                flag="Not possible";
                break;
            }
        }
        cout<<flag<<"\n";
    }
    
}

3).
/* prateek_imkp1 */
#include<bits/stdc++.h>
#define ll long long int
#define loop(i,s,e) for(int i=s;i<=e;i++)
#define io std::ios::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define pb push_back
#define mkp make_pair
#define pii pair<ll,ll>
using namespace std;
#define MAX 100001
#define INF 1000000000000000
int main()
{
    io
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a;
        string str;
        
        while(n--)
        {
            cin>>str;
            a.pb(str.length());
        }
        sort(a.begin(),a.end());
        string flag="Possible";
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=a[i/k*k])
            {
                flag="Not possible";
                break;
            }
        }
        cout<<flag<<"\n";
    }
    
}

4).
#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    int t,n,k;
    
    cin >> t;
    
    while(t--){
        cin >> n >> k;
        vector<int>vect;
        string str;
        int min = INT_MAX;
        
        for(int i = 0 ; i < n ; i++){
            cin >> str;
            vect.push_back(str.size());
            if(str.size() < min)
                min = str.size();
        }
        
        sort(vect.begin(),vect.end());
        
        int count = 0,flag = 0;
        
        if(k > 1){
            int current = min;
            int j;
            for(int i = 0 ; i < n ; i++){
                for(j = i+1 ; j < k+i ; j++){
                    //cout << vect[j] <<endl;
                    if(vect[i] != vect[j]){
                        flag = 1;
                        break;
                    }
                }
                i = j-1;
                if(flag == 1)
                    break;
            }
        }
        if(flag == 1)
            cout << "Not possible" <<endl;
        else
            cout << "Possible" <<endl;
    }
}

C#:
1).
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace icpc
{
    static class MyClass
    {
        public static int[] ToIntArray(this string s, char separator)
        {
            string[] ar = s.Split(separator);
            List<int> ints = new List<int>();
            foreach (var item in ar)
            {
                int v;
                if (int.TryParse(item, out v))
                    ints.Add(v);
            }
            return ints.ToArray();
        }
 
        static void Main(string[] args)
        {
           int t, tn, nosc,i,k,len;
           t = Convert.ToInt32(Console.ReadLine());
           for(k=0;k<t;k++)
           {
           		int[] a = new int[2];
           		string b = Console.ReadLine();
           		a = ToIntArray(b, ' ');
           		tn = a[0];
           		nosc = a[1];
           		string[] name = new string[tn];
           		int[] count = Enumerable.Repeat(0, 101).ToArray();
           		for (i=0;i<tn;i++)
           		{
           			name[i] = Console.ReadLine();
           		}
           		//count = 0;
           		for(i=0;i<tn;i++)
           		{
           			len = name[i].Length;
           			count[len]++;
           		}
           		bool f = true;
           		for(i=0;i<101;i++)
           		{
           			if(count[i] > 0)
           			{
           				if (count[i] % nosc != 0)
           				{
           					f = false;
           					break;
           				}
           			}
           		}
           		if (f)
           		{
           			Console.WriteLine("Possible");
           		}
           		else
           		{
           			Console.WriteLine("Not possible");
           		}
           }
        }
    }
}
2).
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace icpc
{
    static class MyClass
    {
        public static int[] ToIntArray(this string s, char separator)
        {
            string[] ar = s.Split(separator);
            List<int> ints = new List<int>();
            foreach (var item in ar)
            {
                int v;
                if (int.TryParse(item, out v))
                    ints.Add(v);
            }
            return ints.ToArray();
        }
 
        static void Main(string[] args)
        {
           int t, tn, nosc,i,k,len;
           t = Convert.ToInt32(Console.ReadLine());
           for(k=0;k<t;k++)
           {
           		int[] a = new int[2];
           		string b = Console.ReadLine();
           		a = ToIntArray(b, ' ');
           		tn = a[0];
           		nosc = a[1];
           		string[] name = new string[tn];
           		int[] count = Enumerable.Repeat(0, 101).ToArray();
           		for (i=0;i<tn;i++)
           		{
           			name[i] = Console.ReadLine();
           		}
           		//count = 0;
           		for(i=0;i<tn;i++)
           		{
           			len = name[i].Length;
           			count[len]++;
           		}
           		bool f = true;
           		for(i=0;i<101;i++)
           		{
           			if(count[i] > 0)
           			{
           				if (count[i] % nosc != 0)
           				{
           					f = false;
           					break;
           				}
           			}
           		}
           		if (f)
           		{
           			Console.WriteLine("Possible");
           		}
           		else
           		{
           			Console.WriteLine("Not possible");
           		}
           }
        }
    }
}
3).
using System; 
using System.Numerics; 
using System.Collections.Generic;
using System.Linq;
 
  class Program
    {
        static void Main(string[] args)
        {
            int totTestCase = ReadNumber();
            for (int i = 0; i < totTestCase; i++)
            {
                bool isPossible = true;
                string input = Console.ReadLine().Trim();
                string[] inputArray = input.Split(' ');
                int totalStudent = int.Parse(inputArray[0]);
                int numberPerGroup = int.Parse(inputArray[1]);
                string[] nameOfStudent = new string[totalStudent];
                ReadNames(ref nameOfStudent);
              
                var res = (from name in nameOfStudent
                           group name by name.Length into c
                            select (c.ToList<string>().Count)).ToList() ;
 
                isPossible = (from item in res
                               where item % numberPerGroup != 0
                               select item).Count()==0;
 
 
                Console.WriteLine((isPossible) ? "Possible" : "Not possible");  
                    
            }
            Console.Read();
        }
 
        private static void ReadNames(ref string[] nameOfStudent)
        {
            for (int i = 0; i < nameOfStudent.Length; i++)
            {
                nameOfStudent[i] = Console.ReadLine();
            }
        }
 
        private static int ReadNumber()
        {
            var readLine = Console.ReadLine();
            if (readLine != null)
            {
                var numbStr = readLine.Trim();
                return int.Parse(numbStr);
            }
            else return 0;
        }
 
    }

Java:
1).
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
public class TestClass {
    public static void main(String args[] ) throws Exception {
      
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       int tc= Integer.parseInt(br.readLine());
       for(int i=0;i<tc;i++)
       {
           HashMap<Integer,ArrayList<String>> hm = new HashMap<>();
         String input[] = br.readLine().split(" ");
         int n = Integer.parseInt(input[0]);
         int k = Integer.parseInt(input[1]);
         for(int j=0;j<n;j++)
         {
           String name = br.readLine();
           if(!hm.containsKey(name.length()))
           {
               ArrayList<String> al = new ArrayList<>();
               al.add(name);
            hm.put(name.length(),al);   
           }
           else
           {
             ArrayList<String> al = hm.get(name.length());
             al.add(name);
             hm.put(name.length(),al);
           }
         }
       int f=1;
       for(Map.Entry<Integer,ArrayList<String>> e:hm.entrySet())
       {
          if(e.getValue().size()%k != 0)
          {
              f=0;
             break;
          }
          //else
          //{
          //    n=n-e.getValue().size();;
          //}
       }
       if(f==1 )//&& n==0)
       {
           
           System.out.println("Possible");
       }
       else
       {
           if(k==1)
           {
            System.out.println("Possible");    
           }
           else
           {
          System.out.println("Not possible"); 
           }
       }
    }
    }
}
2).
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class TestClass {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));	
		int T=Integer.parseInt(br.readLine().trim());
		String s;
		StringTokenizer st;
		while(T>0)			{
			if((s=br.readLine().trim())!=null)	{
				st = new StringTokenizer(s);	
				int sum = 0;
				int N = Integer.parseInt(st.nextToken());
				int K = Integer.parseInt(st.nextToken());
				int arr[] = new int[101];
				boolean flag = false;
				while(N> 0 ){
					if((s=br.readLine().trim())!=null)	{
						arr[s.length()]++;
						N--;
					}
				}
				for(int i=0;i<=100;i++)	{
					if(arr[i]%K!=0)	{
						flag = true;
						break;
					}
				}
				System.out.println(!flag ? "Possible" : "Not possible");
				T--;
			}
		}
	}
}
3).
    import java.io.DataInputStream;
    import java.io.FileInputStream;
    import java.io.IOException;
    import java.io.PrintWriter;
    import java.util.LinkedHashMap;
    import java.util.Map.Entry;
    import java.util.TreeMap;
    import java.util.*;
    import java.io.*;
    class ICPCTeam {
       public static void main(String[] args) throws IOException {
       InputStreamReader reader=new InputStreamReader(System.in);
       BufferedReader in=new BufferedReader(reader);
       int t=Integer.parseInt(in.readLine());
       for(int j=0;j<t;j++){
        StringTokenizer st=new StringTokenizer(in.readLine());
       int n=Integer.parseInt(st.nextToken());
       int k=Integer.parseInt(st.nextToken());
      
       int actual_divide=n/k;
       Hashtable<Integer,Integer> hs=new Hashtable<>();
       for(int i=0;i<n;i++){
 
        String str=in.readLine();
        int len=str.length();
      
        if(hs.get(len)!=null){
			hs.put(len,hs.get(len)+1);
        }
        else{
            hs.put(len,1);
        }
       }
       int ind=0;
      // System.out.println(hs);
        for(Map.Entry m : hs.entrySet()){
       if((int)m.getValue()%k!=0){
            ind=1;
            System.out.println("Not possible");
            break;
        }
    }
       if(ind==0){
        System.out.println("Possible");
       }
     }
  }
}

Java 8:
1).
import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
 
import static java.lang.Math.*;
 
class Cf182 implements Runnable 
{
	static class InputReader 
	{
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;
		private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 
		public InputReader(InputStream stream) 
		{
			this.stream = stream;
		}
		
		public int read()
		{
			if (numChars==-1) 
				throw new InputMismatchException();
            
			if (curChar >= numChars) 
			{
				curChar = 0;
				try
				{
					numChars = stream.read(buf);
				}
				catch (IOException e)
				{
					throw new InputMismatchException();
				}
                
				if(numChars <= 0)               
					return -1;
			}
			return buf[curChar++];
		}
     
		public String nextLine()
		{
			String str = "";
			try
			{
				str = br.readLine();
			}
			catch (IOException e)
			{
				e.printStackTrace();
			}	
			return str;
		}
		public int nextInt() 
		{
			int c = read();
            
			while(isSpaceChar(c)) 
				c = read();
		
			int sgn = 1;
        
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
            
			int res = 0;
			do
			{
				if(c<'0'||c>'9') 
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			while (!isSpaceChar(c)); 
        
			return res * sgn;
		}
        
		public long nextLong() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-')
			{
				sgn = -1;
				c = read();
			}
			long res = 0;
			
			do 
			{
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}	
			while (!isSpaceChar(c));
				return res * sgn;
		}
		
		public double nextDouble() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-')
			{
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') 
			{
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') 
			{
				c = read();
				double m = 1;
				while (!isSpaceChar(c))
				{
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, nextInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}
    
		public String readString() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do 
			{
				res.appendCodePoint(c);
				c = read();
			} 
			while (!isSpaceChar(c));
            
			return res.toString();
		}
     
		public boolean isSpaceChar(int c) 
		{
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
     
		public String next()
		{
			return readString();
		}
        
		public interface SpaceCharFilter
		{
			public boolean isSpaceChar(int ch);
		}
	}
	public static void main(String args[]) throws Exception 
	{
		new Thread(null, new Cf182(),"Main",1<<27).start();
	}	
	
	public static long gcd(long a, long b) 
	{ 
		if (a == 0) 
			return b; 
		return gcd(b % a, a); 
	} 
  
	public static long findGCD(long arr[], int n) 
	{ 
		long result = arr[0]; 
		for (int i = 1; i < n; i++) 
			result = gcd(arr[i], result); 
		return result; 
	}	 
	
	public void run()
	{
		InputReader sc = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		int T = sc.nextInt();
		int K,N,flag=0;
		for(int i=0;i<T;i++)
		{
		    N = sc.nextInt();
		    K = sc.nextInt();
		    String s;
		    flag=0;
		    HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
		    for(int j=0;j<N;j++)
		    {
		        s = sc.next();
		        if(map.containsKey(s.length()))
		            map.put(s.length(),map.get(s.length())+1);
		        else
		            map.put(s.length(),1);
		    }
		    for(int val : map.values())
		    {
		        if(val%K != 0)
		        {
		            flag=1;
		            break;
		        }
		    }
		    if(flag==0)
		        System.out.println("Possible");
		    else
		        System.out.println("Not possible");
		}
		w.flush();
		w.close();
	}
}

2).
import java.lang.reflect.Array;
import java.util.Scanner;
import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
import static java.lang.Math.*;
public class main implements Runnable {
 
    static ArrayList<Integer> adj[];
 
    static void Check2(int n) {
        adj = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }
 
    }
 
    static void add(int i, int j) {
 
        adj[i].add(j);
        adj[j].add(i);
    }
 
    public static void main(String[] args) {
        new Thread(null, new main(), "Check2", 1 << 26).start();// to increse stack size in java
    }
 
    static long mod = (long) (1e9 + 7);
 
    public void run() {
                /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        //Scanner in=new Scanner(System.in);
 
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
 
        int t=in.nextInt();
        while (t-->0) {
 
        int n=in.nextInt();
        int k=in.nextInt();
 
        int f[]=new int[101];
 
 
        for(int i=0;i<n;i++){
            String s=in.next();
            f[s.length()]++;
        }
        int flag=0;
        for(int i=0;i<=100;i++){
         if(f[i]%k!=0)flag=1;
        }
        w.println((flag==0?"Possible":"Not possible"));
 
 
 
 
 
        }
 
        w.close();
    }
 
 
 
 
    static class pair{
 
 
        int x,y;
        pair(int a,int b){
            x=a;
            y=b;
        }
 
    }
 
 
 
 
 
    static long power(long x,long y){
        if(y==0)return 1%mod;
        if(y==1)return x%mod;
 
 
        long res=1;
        x=x%mod;
        while(y>0){
 
 
            if((y%2)!=0){
                res=(res*x)%mod;
            }
 
 
            y=y/2;
            x=(x*x)%mod;
        }
 
 
        return res;
 
 
 
    }
 
 
    static  int gcd(int a,int b){
 
        if(b==0)return a;
        return gcd(b,a%b);
    }
 
    static  void sev(int a[],int n){
 
        for(int i=2;i<=n;i++)a[i]=i;
        for(int i=2;i<=n;i++){
 
            if(a[i]!=0){
                for(int j=2*i;j<=n;){
 
                    a[j]=0;
                    j=j+i;
                }
            }
 
        }
 
    }
 
 
    static class node{
 
        int y;
        int val;
 
        node(int a,int b){
 
            y=a;
            val=b;
 
        }
 
 
    }
 
    static class InputReader
    {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;
 
        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }
 
        public int read()
        {
            if (numChars==-1)
                throw new InputMismatchException();
 
            if (curChar >= numChars)
            {
                curChar = 0;
                try
                {
                    numChars = stream.read(buf);
                }
                catch (IOException e)
                {
                    throw new InputMismatchException();
                }
 
                if(numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }
 
        public String nextLine()
        {
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
        public int nextInt()
        {
            int c = read();
 
            while(isSpaceChar(c))
                c = read();
 
            int sgn = 1;
 
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
 
            int res = 0;
            do
            {
                if(c<'0'||c>'9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));
 
            return res * sgn;
        }
 
        public long nextLong()
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            long res = 0;
 
            do
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public double nextDouble()
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.')
            {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.')
            {
                c = read();
                double m = 1;
                while (!isSpaceChar(c))
                {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, nextInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }
 
        public String readString()
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c = read();
            }
            while (!isSpaceChar(c));
 
            return res.toString();
        }
 
        public boolean isSpaceChar(int c)
        {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public String next()
        {
            return readString();
        }
 
        public interface SpaceCharFilter
        {
            public boolean isSpaceChar(int ch);
        }
    }
}

3).
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
 
 
 
public class TestClass {
 
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(new
                     InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int PulkitInt()
        {
            return Integer.parseInt(next());
        }
        long nextLong()
        {
            return Long.parseLong(next());
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
    
    
    public static void main(String[] args) {
    FastReader s=new FastReader();
    Map<Integer,Integer> aa=new HashMap<Integer,Integer>();
 
    int T=s.PulkitInt();
    StringBuilder ans=new StringBuilder();
    int max_string=101;int current=0;
    while(T!=0)
    {
            for(int i=1;i<101;i++)
        aa.put(i, 0);
        int N=s.PulkitInt();int count=0;
        int one_camp=s.PulkitInt();
        int in_one=N/one_camp;
      //  System.out.println("in one is "+one_camp);
        String input;int hashValue;
        for(int i=1;i<=N;i++)
        {
            input=s.next();
            hashValue=input.length()%max_string;
             current=aa.get(hashValue);
             
            aa.put(hashValue, ++current);
           // System.out.println("--- "+current);
           
        
        }
        boolean flag=true;
         for(int i=1;i<101;i++)
         {
              if(one_camp==1)
             {
             flag=true;
             break;
             }
             if(current==N)
             {
                 flag=true;
             break;
             }
             if(aa.get(i)%one_camp!=0 && aa.get(i)!=0)
             {
             flag=false;
             break;
             }
         }
         if(flag==false)
        ans.append("Not possible"+"\n");
         else
        ans.append("Possible"+"\n");
         
       // System.out.println(aa);
         aa.clear();
         
        T--;
    }
        System.out.println(ans);
   }
}

4).
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
import java.util.*;
 
 
class TestClass {
    public static void main(String args[] ) throws Exception {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        Map<Integer,Integer> hm=new HashMap<Integer,Integer>();
        
        for(int j=1;j<=t;j++)
        {
        	String[] tokens = br.readLine().split("\\s");
        int total=Integer.parseInt(tokens[0]);
        int groups=Integer.parseInt(tokens[1]);
        for(int i=1;i<=total;i++)
        {
        	String str=br.readLine();
        	int l=str.length();
        	if(hm.containsKey(l))
        	{
        		int oldvalue=hm.get(l);
        		hm.replace(l,oldvalue+1);
        	}
        	else
        	{
        		hm.put(l,1);
        	}
        	
        }
        int flag=0;
        for(Map.Entry<Integer,Integer> entry:hm.entrySet())
        {
        	int value=entry.getValue();
        	
        	if(value%groups!=0)
        	{
        		
        		flag=1;
        		break;
        	}
        }
        if(flag==1)
        {
        	System.out.println("Not possible");
        }
        else
        {
        	System.out.println("Possible");
        }
        hm.clear();
        }
 
    }
}

	
	
JavaScript(Node.js):
1).
function main(input) {
	var _input = input.trim().split('\n');
	for (var i = 1; i < _input.length;) {
		var meta = _input[i].split(" ");
		var n = parseInt(meta[0]);
		var k = parseInt(meta[1]);
		
		var data = _input.slice(i+1, i + 1 + n);
		
		// console.log("data : " , data);
		
		var arrIndex = []
		var mapCount = {};
		
		for (var j = 0; j < data.length; j++) {
			var current = data[j].length;
			if (arrIndex.indexOf(current) == -1) {
				arrIndex.push(current);
				mapCount[current] = 1;
			}
			else {
				mapCount[current] += 1;
			}
		}
		
		// console.log("mapCount : " , mapCount);
		
		var isValid = true;
		for (var prop in mapCount) {
			if (mapCount.hasOwnProperty(prop)) {
				var value = mapCount[prop];
				if (value % k != 0) {
					isValid = false;
					break;
				}
			}
		}		
		
		if (isValid) {
			console.log("Possible");
		}
		else {
			console.log("Not possible");
		}
		
		i = i + 1 + n;
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

2).
function main(input) {
    //Enter your code here
    var lines = input.split("\n");
    var i = 0;
    var numTest = parseInt(lines[i++]);
    
    while (numTest--){
    	var aa = lines[i++].split(" ");
    	var n = parseInt(aa[0]);
    	var k = parseInt(aa[1]);
    	//process.stdout.write( n +" "+k +"\n" );
    	var mm = {};
    	for (var j =0;j<n;j++){
    		var str = lines [i++];
    		var len = str.length;
    		if (mm[len] != undefined){
    			mm[len] = mm[len] + 1;
    			//process.stdout.write(len + " "+ mm[len] + "\n" );
    		} else {
    			mm[len] = 1;
    			//process.stdout.write(len + " "+ mm[len] + "\n" );
    		}
    	}
    	var flag = true;
    	
    	for( var key in mm){
    		
    		if (mm[key] % k != 0)
    		{
    			flag = false;
    			break;
    		}
    	}
    	
    	if (flag)
    	process.stdout.write("Possible\n");
    	else
    	process.stdout.write("Not possible\n");
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

3).
Array.prototype.insert = function (index, item) {
  this.splice(index, 0, item);
};
function main(input) {
	var array = input.toString().split("\n");
	var index;
	
	var j=1;
	
	for (index = 0; index < parseInt(array[0]); index++) {
		var loopVar;
		var arr = array[j].toString().split(" ");
		var students = arr[0];
		var teamSize = arr[1];
		
		var resArray = [ ];
		var tempLoopVar;
		for (tempLoopVar = 0; tempLoopVar < 101; tempLoopVar++) {
			resArray[tempLoopVar] = 0;
		}
		j++;
		for (loopVar = 0; loopVar < parseInt(students); loopVar++) {
			var len = parseInt(array[j].length);
			j++;
			arrValue = resArray[len];
    		if (resArray[len] == 0) {
		    	resArray[len] = 1;
			} else {
			    resArray[len] = resArray[len] + 1;
			}
		}
		var possible = 1;
		for (tempLoopVar = 0; tempLoopVar < 101; tempLoopVar++) {
			var temploopval = resArray[tempLoopVar]
		    if(temploopval % teamSize != 0){
		    	possible = 0;
		    }
		}
		if(possible == 1)
		{
			console.log("Possible");
		}else{
			console.log("Not possible");
		}
		
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
Program HiHere;
VAR t,i,j:int64; n,k:array[1..51] of int64; names:array[1..51,1..1001] of string; s:string; len:array[1..101] of int64; b:boolean;
Begin
Readln(t);
for i:=1 to t do
Begin
Readln(n[i],k[i]);
for j:=1 to n[i] do
Begin
Readln(names[i,j]);
end;
end;
for i:=1 to t do
Begin
for j:=1 to n[i] do
Begin
len[length(names[i,j])]:=len[length(names[i,j])] + 1;
end;
 
b:=true;
for j:=1 to 101 do
Begin
if (len[j] mod k[i] <> 0) then b:=false;
end;
if b then Writeln('Possible') else Writeln('Not possible');
 
for j:=1 to 101 do
Begin
len[j]:=0;
end;
 
 
end;
Readln;
END.

Ruby:
1).
# Read input from stdin and provide input before running code
t = Integer(gets.chomp)
i=0
begin
	#n,c =line.split.map(&:to_i)	
	line = gets.chomp
	n,c =line.split.map(&:to_i) 
	j=0
	hash=Hash.new(0)	
	begin
		name= gets.chomp
		hash[name.length]+=1
		j+=1
	end while j < n
	i+=1
	flag =0
	hash.each do
		|k,v|
		if v%c!=0 then
			flag =1
		end
	end
	if flag ==0 then
		puts "Possible"	
	else
		puts "Not possible"
	end
end while i < t

2).
T = gets.chomp.to_i                                                                                                                            
details = []                                                                                                                                   
T.times do                                                                                                                                     
    d = []                                                                                                                                     
    d[0] = gets.chomp.split(' ')                                                                                                               
    d[1] = []                                                                                                                                  
                                                                                                                                               
    d[0][0].to_i.times do                                                                                                                      
        d[1] << gets.chomp                                                                                                                     
    end                                                                                                                                        
                                                                                                                                               
    details << d                                                                                                                               
end                                                                                                                                            
                                                                                                                                               
details.each {|detail|                                                                                                                         
    n = detail[0][0].to_i                                                                                                                      
    k = detail[0][1].to_i                                                                                                                      
                                                                                                                                               
    names = detail[1]                                                                                                                          
                                                                                                                                               
    h = []                                                                                                                                     
                                                                                                                                               
    possible = true                                                                                                                            
    names.each {|name|                                                                                                                         
        possible = true                                                                                                                        
                                                                                                                                               
        i = 0                                                                                                                                  
        while 1                                                                                                                                
            if h[i].nil?                                                                                                                       
                h[i] = []                                                                                                                      
                break                                                                                                                          
            elsif h[i].size >= k                                                                                                               
                i += 1      
                next                                                                                                                           
            elsif h[i][0].length == name.length                                                                                                
                break                                                                                                                          
            end                                                                                                                                
                                                                                                                                               
            i += 1                                                                                                                             
        end                                                                                                                                    
                                                                                                                                               
        h[i] << name                                                                                                                           
                                                                                                                                               
    }                                                                                                                                          
                                                                                                                                               
    if h.size != (n/k)                                                                                                                         
        puts "Not possible"                                                                                                                    
    else                                                                                                                                       
        puts "Possible"                                                                                                                        
    end                                                                                                                                        
                                                                                                                                               
                                                                                                                                               
}                     
3).
test1 = gets.chomp.to_i
#test1= test1.to_i
test1.times do 
n,k = gets.chomp.split
n = n.to_i
k = k.to_i
 
len = {}
n.times do
 name = gets.chomp
 if len.has_key? name.length
 	len[name.length] += 1
 else
 	len[name.length] = 1
 end
 end
 n_pos = false
 len.each do |e,v|
  if v%k != 0
	n_pos = true
  end
 end
 if n_pos
 	puts "Not possible"
 else
 	puts "Possible"
 end
end
 
Perl:
1).
use strict;
 
my $TestCases = <STDIN>;
 
#Loop for each test case
for (my $i=0;$i<$TestCases;$i++){
	
	my $Line2 = <STDIN>;
	my ($NumberOfStudents, $NumberAllowedInACamp) = split(" ",$Line2);
 
	my %StudentArray = ();
	my $message = "Possible";
 
	#Loop for each student
	for (my $j=0;$j<$NumberOfStudents;$j++){
		my $Student = <STDIN>;
		chomp $Student;
		
		my $Length = length $Student;
		
		if ($StudentArray{$Length} == $NumberAllowedInACamp){
			$StudentArray{$Length} = 1;
		} else {
			$StudentArray{$Length}++;
		}
	}
	
	foreach my $keys (keys %StudentArray){
		if ($StudentArray{$keys} != $NumberAllowedInACamp){
			$message = "Not possible";
		}
	}
	
	print "$message\n";
	
}
2).
use strict;
use Data::Dumper;
my $n = <>;
chomp($n);
foreach(1..$n){
	my $temp = <>;
	my ($t,$k) = split(/ /,$temp);
	my $tot;
	foreach(1..$t){
		my $l= <>;
		chomp($l);
		$tot->{length($l)}++;
	}
	my $fg = 1;
	foreach(values %$tot){
		if ($_%$k !=0 ){
			$fg = 0;
			last;
		}
	}
	#print Dumper $tot;exit;
	if($fg){
		print "Possible\n"
	}
	else{
		print "Not possible\n"
	}
}
3).
    use strict;
    my $t=<>;
    chomp($t);
    for(my $i=0;$i<$t;$i++)
    {
    my $no = <>;
    my @nk= split(' ',$no);
    my @names;
    my %count;
    for(my $i=0;$i<$nk[0];$i++)
    {
    %count={};
    my	$s=<>;
    	chomp($s);
    	my $len= length $s;
    	push(@names,$len);
    }
    foreach my $name (@names)
    {
        $count{$name}++;
    }
     
    my $flag=0;
    foreach my $word (sort keys %count)
    {
    	if($word =~ /^HASH/)
    	{
    	    		delete($count{$word});
    	}	
    
   	#print "work is $word frequency: $count{$word} \t $nk[1] \t ";
     if($count{$word}%$nk[1] != 0 && $count{$word}<$nk[1]  )
     {
     	 	 	 $flag=1;
     }
     if($count{$word}%$nk[1] != 0)
     {
      $flag=1;
     }
     }
    
     if($flag == 0)
     {
     print 	"Possible \n"
     }
     else
     {
     	print "Not possible \n";
     }
    }

PHP:
1).
<?php
error_reporting(E_ERROR);
fscanf(STDIN,"%d\n",$T);
while($T--)
{
$str	=	trim(fgets(STDIN));
$str	=	explode(" ",$str);
$N	=	intval($str[0]);
$K	=	intval($str[1]);
$rem	=	$N%$K;
if($rem	!==	0)
{
print("Not possible\n");
continue;
}
$strarr	=	array();
$div	=	$N/$K;
while($N--)
{
$strarr[]	=	trim(fgets(STDIN));
}
$team	=	0;
$flag	=	0;
for($i=0;$i<count($strarr);)
{
$count	=	1;	
$index	=	$i+1;
$team	+=1;
for($j=$i+1;$j<count($strarr);$j++)
{
if($count===$K)
break;
if(strlen($strarr[$i]) === strlen($strarr[$j]))
{
$temp	=	$strarr[$j];
$strarr[$j]	=	$strarr[$index];
$strarr[$index]	=	$temp;
$index +=1;
$count++;
 
}
}
$i	=	$index;
}
if($div	=== $team && $flag !== 1)
print("Possible\n");
else
print("Not possible\n");
 
}
?>

Python:
1).
from collections import defaultdict
tests = int(raw_input())
for test in range(tests):
    [total,each_group] = list(int(each) for each in raw_input().split())
    if total%each_group!=0:
        print "Not possible"
        continue
    names=[]
    for each in range(total):
        names.append(raw_input())
    names_dict = defaultdict(int)
    for name in names:
        names_dict[len(name)] = names_dict[len(name)] + 1
    is_possible = True
    for items in names_dict.values():
        if items%each_group!=0:
            print "Not possible"
            is_possible=False
            break
    if is_possible:
    	print "Possible"
2).
tc = int(raw_input())
assert(tc>0 and tc<51)
for i in xrange(tc):
	n, k = map(int, raw_input().split())
	l = [0]*1000
	ok = True
	assert(n>0 and n<1001)
	assert(k>0 and k<1001)
	assert(n>=k)
	assert(n%k==0)
	for j in xrange(n):
		a = raw_input()
		l[len(a)] +=1
	for z in l:
		if z%k!=0:
			ok = False
			break
	if (ok):
		print "Possible"
	else:
		print "Not possible"

3).
n=int(raw_input())
t=[]
names=[]
for i in range(n):
	t.append(map(int, raw_input().split()))
	temp=[]
	for j in range(t[i][0]):
		temp.append(raw_input())
	names.append(temp)
 
def check(a,b):
	d={}
	for j in range(a[0]):
		if len(b[j]) not in d.keys():
			d[len(b[j])]=1
		else:
			d[len(b[j])]+=1
	if len(d)>a[0]/a[1]:
		return 'Not possible'
	for i in d.keys():
		if d[i]%a[1]!=0:
			return 'Not possible'
		return 'Possible'
 
for i in range(n):
	print check(t[i],names[i])

4).
t=raw_input()
T=int(t)
for test in range(1,T+1):
	
	x=raw_input()
	[n,k]=list(map(int,x.split()))
	names=[]
	for i in range(1,n+1):
		y=raw_input()
		names.append(y)
	
	names_len=list(map(len,names))
	len_exist=[]
	for j in range(1,101):
		len_exist.append(0)
	for length in names_len:
		len_exist[length]=len_exist[length]+1
	z=1
	for x in len_exist:
		if (x!=0):
			if x%k==0:
				continue
			else:
				print("Not possible")
				z=0
				break
	if z==1: print("Possible")


Python 3:
1).
testcases=int(input())
no_of_stud=[]
no_per_group=[]
student_dict={}
 
for i in range(0,testcases):
      n,k=input().split()
      no_of_stud.append(int(n))
      no_per_group.append(int(k))
      student=[]
      for j in range(0,int(n)):
          student.append(input())
      student_dict[i]=student
 
#print (no_of_stud)
#print(no_per_group)
#print(student_dict)
 
def team_manage(no_of_stud,no_per_group,student_list):
    group_dict={}
#    print(student_list)
    for x in student_list:
        group_dict[len(x)]=[]
    for x in student_list:
        group_dict[len(x)].append(x)
 
#    print(group_dict)
    possible=1
    for z in group_dict.keys():
        if len(group_dict[z]) % no_per_group !=0:
            possible=0
            break
    if possible==0:
        print("Not possible")
    else:
        print("Possible")
 
for y in range(0,testcases):
    team_manage(no_of_stud[y],no_per_group[y],student_dict[y])
2).
T= int(input())
for _ in range(T):
    n, k = list(map(int, input().split(' ')))
    students = {}
    ans = "Possible"
    for _ in range(n):
        l = len(input())
        students.setdefault(l, 0)
        students[l] += 1
    #print(k,students)
    for v in students.values():
        if v != k and v % k != 0:
            ans = "Not possible"
            break
    print(ans)
3).
def func(arr,n,k):
    
    dict_n = {}
    
    for v in arr:
        if dict_n.get(v) is None:
            dict_n[v] = 1
        else:
            dict_n[v] += 1
    
    for v in arr:
        if dict_n.get(v) % k != 0:
            print('Not possible')
            return
    print('Possible')
    
 
tests = int(input())
for i in range(tests):
    n, k = list(map(int, input().split()))
    arr = ['']*n
    for j in range(n):
        arr[j] = len(input())
    func(arr,n,k)

4).	
for _ in range(int(input())):
    n,k = map(int,input().split())
    d = {}
    output = "Possible"
    for _ in range(n):
        s = len(input())
        if s not in d:
            d[s] = 1
        else:
            d[s] += 1
    for i in d.values():
        if i%k != 0:
            output = "Not possible"
            break
    print(output)


*/

/*I/O:
In #1:
6
2 1
arjit
tijra
9 3
umknhvlktyodvzfmltrwrpudxyrkasuujbdjjeltgl
okqtwhafffhdjpaocxkekdrcklirpnogzfzqvmfyskavakuatxgzcj
ktuothmyxjkvgghzydyoducbuoqtqxmyhaacakcunwwkiibzcvdwjkpkyklevxxtkhzgznjgomwlbrgqcqjyatdllpolb
pnqetpiouhehqdifitqrzqqnr
hkjzfhazokpcdrcypozudukauantnrmecpkiroluwrif
tzztkzzvr
sunnnyaybrrqobjmwrix
qjyahcbulxuilizwnxyxasklxuuk
bsbqagwvwceoyzivnksoukxdgsfvijutofagwpspinwbgzcdagaoxlwkebjkdukhxsxvcxiibqzjjztizfsih
6 3
asmhleggpyystednwefpopaaerzeqnwbpzroziawchu
rgtmqfdtbennow
kfokbhpspltmklhjbiiuauzmywxonlsxsznweqbmlkcdeeebaguspkntropcjdfuaqugykkiaotla
tygvgucwpdarozqyzeotxmabtookvcubzqeighazswqaedwxeldpefbvzsllbicvpxmpoxywlufidufqqfafapimvbejhrbm
qldkwemmfejrwehfewnmsommbmbfvlqffkkpttztfvgswqijbbxrjhwqvlrhfvzhezebjfucvwbifyem
dawmsmxyrcsiefnkfrlgwbezgbdolihrfbbuuywcmtakqfhdwnwxebfbkqpwy
5 5
ijnkqzqrqjwawxlfjlsabbghqmdlpaafyywznlzkpsbgesyptnltggficwscdhhdywib
ixgwtqnxasbavtrqlixcgtrgcqcuskwizisid
rlpoeuisxatniyrkfoikiyuczqtizkpmmlwhipj
dhzovlttjgjmrybbyrmprvylxpivneq
qyrmurtijfclgkfxpctdzxnoxeosngramqtpobcflhfstvlntmdludjrppdnlsaaxxes
4 2
ocszcdlpvqlnjvfhyrisb
rffyqbihqgixgtno
cqyykquktczedjkmtsqbsjjptqdgnszkoegdtwccwtmk
flwvkeggjyzyqyprirkjomtqgkognicqhggcccthlicagzluxazevmwrmvvltssxlrqrwgimxoqbcaenyxu
9 3
hvp
hbrkhvdabjrpaiuldhoyzljtoavnm
sawezqvmhesrcydpjsfynuwrgvcbkdhqcacqjwvolwdjptanwchklcexlvuffjvxviwcoamwramubzoitsjobiqnv
erqvmgwllcxpppjtzzbbhxtvoay
smzepbbhkmytngpqgxhykpepiamr
sfiouuhbakcofggmktcavsmcgovyhqgrvbzgc
ogcm
mwrsaxczcffjhbfonvzzbdaubwqozqgufpws
vfncxgieynotwwvdzueqqk

Out #1:
Possible
Not possible
Not possible
Not possible
Not possible
Not possible

In #2:
10
3 3
cytrpnpckjntnpvamt
teqphgzfrdrslmenchzihwsyuimwtqgltcdvkgipssykyrjjvpuoxvwclxx
kpuxpegutbyjenvnvnxzgyflkepupbcejlvibxjlrjoxuudyvgdxesddbmovvfujiczachbvlkyreihwqikvcgnoerekkvttv
1 1
uzcmfckvoxprmeebhwtfifreebirnldzvhjeigoqbzxbukrsjsbugm
6 6
bxxjxxzkoyjvoleyybfvbjosxisfnyzouskgsavhnbngxkfxktealayupvdjfkjloazvfjmvnxhtvlok
qyefrfanofcflwwaxlpkqewyphldovjeofyqfae
gzhyufmijmufxrpaqjtl
lnaxfgpymtvfpzmrrxmasrawdis
ftwzaaujsskjmuytitsazvrrusxymtlrgfylwbkm
mcgmhsrgtiiqifrnpic
3 3
pcngjthvgojhmmvgwgwupegy
ovpporgkdncsacwzndbsfpcdhwedmraemrpjxrpmsf
jgmnrexmyjscgqgozdwgzejyrelvmyzwzqnhvjbkvqngpqkdythiabbifiltazetlkeccruwoaxassmjsx
7 1
hia
xziyohbxsahoejulqdvylztybcfdoessmpvxgtuwrniqwesiehxiculbixomhzqsrec
vnvqnyyxevlfuxvgvvxpietnhzphtuqtjjbbdkssrgrnbifeqnhqeyjcaofmzgbupxloxshjwemgyusio
fzpopsrqtrpvv
fzjgreuivkesdxrgojw
rzuoyhlwkqhrwpwhpaouawlfctymhtfcjuqb
mkqzqeegvbtlvtnwogccrjfbisqfvdrododafvypcmcqoendryrohhwgvoiammfkrzjusehkgz
4 1
iozcaexdpnvqmnamhsovjgwexgsbvroxgemabvudqylhggheaf
qgzorkvstqriofmzawaerybvs
ytzvkzltwusksveneycognrmvyhgxatvlhrgfh
acoevnujaratl
6 2
gxzbxkmtjmxilfqsaeixdcnyftjats
ugutbfouxleausztlkvxohbjmldccgzrojqveo
lqcnycmozwouxpvrdjwqhzxpjbtrdjinkvubhmobozguwlmaaicsftg
osiyhmlnnjjxbwbtweqdynqlbhhpis
arkurvznecuqxgfs
ifnmojiwbtvc
7 7
paswilipcjsbrcxmpqvrvemmcpiccxqvlykrcsyz
axnmojbtnsydllvdg
srptxapizduekqlofezpzesmwhodxaikwxxojbhpjcnunronvjlxgygvzktfrzoouh
sfsevrlhwhxumekbtyuewgrazrpicftzqwrgosquqdhhzougcxqvyu
owhbsofcuyqbmozbwdfihbcdwzepvlnhpdlowvfejumkxxmowhsbtirydtiknjlflvb
iqofckbhpcidfeqopagovyjjxohwnlebdooinzsfoaczjethsgdjeybsisljzvsntykqtjmsdemamzlvgdmgs
sjc
10 2
okvdohkwqdgpxogqviccbfwnrwvawqujbqqxtlofkykztkjafyuzeyphljzsztvguujjvektuakzwdopjut
ufhmleyspytpbfbehgjqkqkgxugotjpy
ermtjudycoxgskxrsqoltvlbeofxfwqbycgdjsmuij
bwjfngsiwqhflzjfkguiiurlmuprxyjyhbkajrjjvotzvargplsctrjpbsajelimrludzl
cdfzbkcrigxpizbggwmkqztgjvhuohuhjvoiwsidtyxntmaofedtywsjcwmuozvo
uarcpuczazjnlmjhkjhyrfzmcaoiehipupnoyzhufkfnplgukuswbzlpxrwmeftpom
fjdqjklhqudnozsfbwbtnctornepvuacksl
bogdsodpfiujddbcsxhsywoetosdamfpjkvyojyakrvmtu
fnftkf
gqnfryfe
4 4
dbvdgppucvyswgrrrwwgvrhjovbopzrtedzwtsrqxqjnaxkkcycr
gtirsdgzdfjxuswjcwttjrimdgtizvfixgarxcysxmddymerxdlenqtsfezmtzoe
qfinmunhrzcpentuk
x

Out #2:
Not possible
Possible
Not possible
Not possible
Possible
Possible
Not possible
Not possible
Not possible
Not possible

In #3:
10
49 1
utaui
yukyst
luwfg
yjgjqv
vtzvge
ixwakr
ljuse
ktsvw
rvkhae
qmpzo
fcbcsi
zebnj
ayrir
fhrazq
kxmlak
suwpl
oacey
tnhalu
ekplur
pghfu
eqpkc
jmirf
qlbaez
uefns
aucykd
igtzs
kqqqz
vjfuxi
mzwzz
gstkg
jcdcd
ygmqpi
oxsqwh
zxxubj
lmfjxf
hchygs
ezssw
utiwd
whfid
wexbcb
iljxu
wxvhh
nyadfv
qhvfqy
xbvnsu
vhwgt
gxyyze
ntofyz
aixaqu
1 1
ooarw
19 1
ghtuc
zplqmv
zicrfz
crawpg
kdlyng
rnwygd
wwjgp
wbfwh
fbkack
kpvbtj
eiymi
afbyan
genbsf
lmync
fidit
yxyxd
aogbol
otiley
azyoc
30 5
osumgl
hjqhqp
binox
ofvvk
cfzdfx
crxmid
tofzk
onndme
lbarcg
junsl
gryexb
sufok
ddzef
ehsxgw
wdzylz
uoiprm
uncpe
uebmde
hdzlgw
lnlgny
otsob
gcggka
vvlqej
rhbjrn
lyevxr
dtiow
sbysq
ahlqph
xpnbnk
jflan
48 8
ozzih
dlowsn
mexgrg
xpphzg
mzjuqt
pjagw
fpduxy
jodsld
ekvywg
tqqxc
xjoxe
tfjzb
ftaqi
myqbc
gcjdh
hisym
hhkvyk
lvhpg
tvfgtw
wymum
xjcva
wxfpzk
jbgzg
wceli
yxzija
vtqphp
ubejf
rzsbkg
kdrou
bvkaqc
nwmloe
qpjcr
wamugi
zmzob
epyqf
vxsogo
garhms
jkkwlm
xhcaxb
dhblg
fnvjmb
tecmqy
jxkzvz
jatvhb
pyddmk
pcuki
kgtsdw
wqzhx
29 1
swpgzp
xfwoyg
cspdkt
etvuae
lpsrxv
ksvfau
daoqjm
bqrsea
mvwjb
wzifl
qukmsb
spaha
cbwnyv
kqtkul
fejoq
vkutnt
xxpyy
ueodq
oiqmd
jrddh
wiubzv
byygkm
kiqos
kaphz
xzzsp
kaqfkn
jkqsa
ccvso
fzuanm
3 3
pousno
mvzgj
acqoo
42 1
ppdtvd
psgva
tyanoh
rbmirx
wqywwp
tebjm
xmksa
nfgusz
ovfwx
nmsxo
fxuob
aiymkg
jwktq
dkmlsz
vjsdbu
pmcad
hrohz
epvlf
nxxhiu
rhpozz
xhnhc
frrcpx
xytuq
wdwta
hqjwoe
typweo
jupbsp
dxknzl
bnrchw
qmyqow
vzpyn
tixzaa
uusqdz
etyhn
gupqhu
jecmno
zqcfma
uwggo
wsegh
vidxx
vdrngm
obito
48 6
spnljz
aafmgx
ndyufl
wehwd
sbhtp
fsrgfh
zaoglq
klezlh
vdeug
towuj
plwaec
vdhzh
micijf
drnrqv
rqjeif
xjkbp
zcqsr
oxmae
vrpwpu
kzwdc
judrry
dxyene
xhgwl
yborjg
aljge
cwsbq
pvdmks
qytmdp
tnuxdj
corgvp
daehwv
gtcep
yhiiwm
uqmxc
vnxbgo
yvsvh
evsmgi
xnlfp
ksuzs
qshaz
unvoum
ccdws
pelyyw
pzdcxe
eghoc
dwgmvm
mswuz
bgwxl
4 2
dnpsie
kjiwb
areyjn
kufmfy

Out #3:
Possible
Possible
Possible
Not possible
Not possible
Possible
Not possible
Possible
Not possible
Not possible

In #4:
10
28 7
nmjvh
odcjfz
kkicvo
eafqix
ojrlu
dpnkpu
mojqub
jfzvhh
vduvep
swjje
gbjaf
iuvqs
xfevcs
eahgi
vjnny
yukrp
dklty
zinkp
ywpony
eqrpsx
thbspn
elbkz
dxedyc
askso
nzcbx
vtvora
qaooo
viwgoh
35 1
lznie
opoyc
hqvesq
vabwew
lusynj
lhytnu
kanife
phhqj
zrajhw
ygpxe
jtqqf
rksonp
xqwckt
dxxraz
zvsdn
gdjbb
vpjvld
dbmwp
fdfot
ypapoa
lyeke
glrwt
wzqdpq
ixoeqg
kxtli
ofnkbf
gutrw
zaxscz
lroaw
omprjn
ettia
jmnlom
lcyhrx
cplnm
nryvf
9 1
eayasd
ckibx
spcfuk
wznbi
judsx
gjrka
mdvfb
xkwaqo
bacwbt
3 1
bdbds
wtmug
aypzi
39 1
xsmrk
ujpyw
hwhtl
henfs
wmygsa
cdafs
lziyot
kuges
djhrt
kzbyov
peqrd
unkhh
sxohu
dftsqs
dzyela
yljaul
blnijt
ocljd
yqrixf
mmwlf
mpfbeq
rtmff
latil
nnolzg
goirdz
jgjomb
wvtrra
bkbtq
ajoxm
pzlie
pntev
noeayq
xleil
rmxiz
qgocx
urcczk
zinuo
vxrgep
rjmup
31 1
bzllx
hxkda
vakpm
tbanxn
nabkgj
cyqdd
gkcpnh
fikqte
gpkyz
nqltw
sqjxbj
xuliw
dluzgo
xhwmhn
liqgco
tipzf
klyta
fvsoj
wyoyr
lzjao
wzgjl
pqeow
tybvqt
abpzlg
jhgdif
mndbi
rdxjl
psfim
fbdwt
qkfncx
qiylnv
18 18
wrhbao
uvoefm
qkfspo
ixaua
yxpfnw
fnjaj
jbgxk
efgyx
pidst
lbmys
nmcnq
mwjqtu
qocaph
iliofz
wmlugs
yyhgf
kahqx
ovvny
30 1
uzkdk
agcwp
wrambs
lrogo
zoqfxs
nspgft
idacl
fwaih
leaob
zkfdya
xybnll
qcvvu
bzkdd
esjyff
zurqdb
tbumsb
lkadw
ldhbd
rkcgqh
zbths
uclda
ipmqr
fhsuo
vttdaj
gxgjh
vmvnvn
gexnom
pyhhs
rchpfp
hskxfi
38 19
culre
fxozp
dgeubl
tzore
rwyetv
iekrni
enqjc
dhjnl
xmrpm
pghrla
unexdf
buexhy
cnpix
eemhn
zsevw
pixve
jbrkb
pqbxg
zsruo
bddmsk
powok
qedgr
sbkjl
ukcmm
wquzd
eldihg
lmcanb
gcegw
jahpcz
joouyp
fppnv
noguyp
ifrsl
ezzpb
tugfko
jazict
nerby
elppa
19 1
fojtf
mjbktx
qcjgd
cwzys
zfvdi
lvjelq
bzjrn
rtmdu
shjrae
algrje
vgbuqt
bqjub
pqyzho
bqslsr
hbvpop
pzkakg
hovqk
howzn
tbvcb

Out #4:
Possible
Possible
Possible
Possible
Possible
Possible
Not possible
Possible
Not possible
Possible

In #5:
10
17 17
dvjlg
vspvm
lenuze
ezwjbn
udzejr
omkmvm
jowlm
ifmvyy
rqpfa
vkicgx
lzltii
cftuj
ktnyb
bfqgv
udfpza
pdins
vebqb
41 1
xapoa
niljbv
mvidmf
wjmfjx
crkoc
rmegmn
zczfum
xqffad
jfhetl
iqday
znknhk
jvncfg
bowye
ivdzxa
bvemih
unliam
tfvlc
feqeh
thlsq
fqdtdx
ighjiv
zdaani
ceela
bujlqr
deaso
qnzyyf
pwgsy
pqezt
iirfra
gtcmc
pvqczq
edjiu
lzmeej
caoimm
wqnuf
guzsug
kqspsp
cdvgmj
nqmgv
ijtab
anpsuq
32 4
bgoxpy
leawmq
jirrk
cjuvs
nqrjm
wotvro
wogzvu
ygfst
lmkzwb
gfkhr
filkl
ddbzrg
khbgm
azvyv
gjxgsk
ogyxo
arqoga
lonaku
jcnjnm
zfylr
qzxqd
fcmwnv
rmmoi
tvnay
vswmr
evtvsk
jqnzna
aqhme
vafoof
ayzotu
ypfpq
entkf
8 8
duabfq
lpxqyz
capbi
nvguo
mhxjfx
faucv
xvuph
gmdjpu
33 33
yxeld
hyjee
xlewk
yjgogr
aoccu
ccjold
fdpnoj
dqokfj
lcohk
kahlw
qvref
ihmrjk
nyjey
alzjq
nqdlzr
elldst
yhknuw
znwvew
jxxja
gvnkr
sklea
stbmy
czxujp
slsym
skgts
xyasup
ubgvlf
qeegcy
utjefk
jbipt
sucye
ylmsd
mjigtn
14 2
lgnycp
hdfcg
jkqep
tmedlx
mwwwp
pixqmv
tvaktg
zsnaby
ttvmfs
jhhre
utyqf
sefkit
uuxkf
imquvs
31 1
vidada
ncnmfn
owptcv
agfiow
lezqt
seyia
fgnwnq
wzvbc
cnpjxq
plkzpw
sfthjz
qgycob
ijvxa
vosxtt
uilxsd
crboy
xxphn
ktson
vydobr
fkvjv
kezyxd
ozjsuh
ynial
rlztj
cgvmfm
ndvhf
vvmzfx
yrpeof
sqwivi
qodptf
kbnamu
37 1
czluf
updpd
oiapbo
vgzgeg
zucvm
fzfvpd
ktoxqa
dqngla
ravhc
lyadp
timupa
qslta
undhoj
vldae
ykezbf
ixgxy
fperop
omndw
tohkto
vjvpvd
mktys
kwjhjs
kxzxfu
oyaoy
tcoqd
fdmnj
yvjjo
xiomz
uwcsba
jctaq
nyiyou
trwwia
eokuwj
xkari
vtehgf
ctxetp
acrvqt
25 25
ygdzs
cfwqg
opgxj
kuhrsa
ewoucx
intamf
xmdio
cdvju
logvus
saiyw
kbubz
vxvrmw
ivvvi
enggl
melyp
jazie
krpry
bgvmaa
ddwty
dzcpl
lfaybi
ngqfjf
gmuka
gktdvg
hmbrz
5 5
bondv
arswn
yjgvwv
bhwoc
iytvk

Out #5:
Not possible
Possible
Not possible
Not possible
Not possible
Possible
Possible
Possible
Not possible
Not possible

In #6:
50
34 17
vlsfh
mzrrb
zpwzdg
swgvo
qtloj
gflpb
kmvcrr
zqgjjp
zypri
imuxj
pmafvg
mblem
nvmahq
ceqnfv
aupkt
zmcxtj
gjnig
niiaoa
ghkzrw
ipnmg
liotx
ulixfv
quadri
hvrua
xsymzm
bpgnnt
twxeu
gqiyqj
ajpyyj
vhokpb
mkzjs
rngrzt
suiuxl
ediikw
5 5
sphww
bpgjbq
glczlm
jkrken
wgkdvu
18 9
nobrk
elvps
nfbgm
rnqip
zhuzn
hrmswe
vjldzg
vxurma
jwpanm
oqccr
ckzukq
ceqnqy
lkownk
dmsew
lnlfkr
iqzyf
ccuvop
tfirc
25 25
relgc
qsaju
onjzx
svkqn
gdistu
bftisx
xvucxm
vcopqh
vhvdvr
tuvbia
cjcqbm
qykdb
sspkpq
yhitko
wobdvf
chymw
hhgvcf
fvcsk
ghffh
dxdxba
lrzyhm
ujqhp
zizjcq
csojcw
uobjek
24 1
rzghvc
jeayr
iuilqy
nwsoo
grpueo
voqbog
tgnprc
hhsou
ltoqp
fobtb
drmasc
punhf
xkgokm
pojev
sqtsd
oteug
rpgjo
gclgt
srcda
tyber
xuafi
mbyzt
jxtqum
yqjnp
13 1
ygrqep
whamsn
ykvjc
ppebk
etopjg
tyxck
zpqwdg
ipysb
xyzdkj
pnenxr
lmbkq
izuqf
riihbm
30 2
phulh
bhqpjf
zbluyw
snsbj
baafy
ushkv
hyofdp
gzlwyi
voecjo
zqbxvx
gwnnv
gxgty
ygepyw
kmamkl
dfvnbr
ocgxxs
doasj
tiupm
fgoflf
eemzk
wzchpd
lxuyz
ssbcnd
ggfcn
mwwjqz
afutj
qcrdt
tjobky
arwlbm
ctlaw
36 3
gbqctl
wysces
znfpd
vbgklo
bcvup
uvppzi
djkqui
hyzxnc
kzfgd
lkbavf
brmiv
nblebd
dzxtz
ylzmf
qbntvj
ausun
ktboe
ctffg
dxyyw
fzurd
gcggy
ioohv
rtcdcv
huhgpt
lfmitb
eqosh
ohsrx
oyryx
qhrtdc
xlkxh
afeuxg
afbbr
yrtcia
oktdyd
hahdqr
yvkoa
35 1
rzsgv
qrxacd
rikycj
kvtkjh
aztqxn
adexff
mqkozi
gzivd
vxhefn
gndcxx
qswxd
nryxz
mdezy
gqljm
lixxlc
ttxru
ngsznw
pezbo
ahdgc
wqvqax
cfihx
khjpmx
phsuii
nkfzb
tkrin
ivvlvx
berdjk
osgpm
gqecld
qtnxdd
jjwqf
ilsxw
pgutsc
slxgq
uylkt
1 1
mccehk
17 1
qbjxsj
zvxsm
unoboa
epqsd
texjnb
vjusee
czzypx
smwcc
wguchu
vgscq
gsuslp
ogdzr
zvbkm
tehubg
ophlru
flvvqa
patvl
15 1
lgmhh
cmvlg
soonow
kaotok
fuqri
boiotp
nhndu
swbrv
gfizy
idgwl
clssn
sdmkds
dagqy
cqnstm
wxyjsi
46 46
ttrtl
iwrev
zpuza
kqtfi
rhedj
whzjxc
ziuagu
dfutwx
azwheb
yxpjxr
itramw
faduih
ukxizy
bcpoe
owfwk
zzhkwf
fvlkdo
jswri
qdgmhb
emycfd
mmsji
oobdl
lpduz
cvglx
xhxhky
pmvhc
grlrf
amkdp
enqhzj
ytidq
fintv
uamxko
ienyny
dpmffx
mucxzd
mmidbh
iahrku
cyopp
ookusp
dkwqj
moxdw
apqdvl
qxtpmq
cdokyi
oxepz
yinbsd
37 37
xhqgax
cvfhf
juago
ebbrwc
xelbvw
cifts
wifsh
ivbpy
mfdvhi
jvolg
fqjnkz
cfscms
afcqyi
xlrgk
jwukim
oliefu
sxijbd
cjqvh
xqcpn
xzaci
dccjjo
zkcxx
dddskz
mctyy
znuatn
hsbihj
vwvaf
nujlp
nexsnu
hidbpt
nwpcko
yvhkiz
vddled
pjani
ffpyu
vtxisc
hlckk
47 47
nqwwnp
wngzi
lljvk
yxyjzi
tfrbt
hlmde
hlccz
hsmkz
brgic
axkewd
ohsicj
tqfam
zzfzl
qmkrgv
zxmzic
hzvzbn
zhbdrs
fdxavt
ppvsz
fbdchw
jsmctl
pgisb
rsyxm
inftb
rkiqh
tufek
jqjwf
fmdsso
wqkdlp
kshhq
aqkga
qyooq
jkabd
ufrkao
rixoov
uqgbxf
wczqk
ejotp
aobsek
ihmqo
cwexgk
qtegga
wcgls
staqi
ubhtj
fkzwa
acmhf
12 2
zqnxgd
vtmgzg
zddsvc
dzqlhp
olufhs
iluzpi
nwrqb
hggad
alobvv
kxxlmz
jponma
wcvnc
42 14
wulwcp
btcjrg
vvzatq
qqrqok
mcggp
ossmw
bplkqg
kombcq
bawwmh
kbescr
hmhpzn
zpwhy
pkzkiz
duupq
xodlfw
vvwhu
meqwkf
rkugzt
krkrm
mzxbv
gwhpn
ltldc
kewbv
inmwv
ozpgx
jxndc
fiwxz
wwezk
cptci
hgija
fzjdsx
ibpcvu
iwhrq
qdojmz
wplpq
jwtjn
jmejxh
wrcse
azfxs
ghfzdn
sqkzn
okgbk
35 7
ypihye
nfifs
ehyhc
jpayvw
rbvpn
ipqpgz
wodrf
jirpz
gqgamp
xgqnez
iiedn
cgpgra
zabcj
cdpun
gutzc
xvkva
gkdfer
qcvinf
tunmg
sbhdjp
jtuqwd
tcluol
ryceq
pxvfap
jowamy
vwjydk
pttkkc
ychnf
hdumd
gzogz
kjopik
yjpkm
fwufe
erjbqx
kohyl
39 3
luqhqi
bfisiw
iaoqn
sdpyoe
fmjzij
gelbrj
ynkuyu
ssbvka
vebdqa
uetgon
bexxa
wkjbbk
uvdgjj
fmxot
cnhhe
ovcjt
oxpdt
pelfcb
fvwms
vkoxpb
gjldxe
oefgef
ydwglw
noatre
lasuc
eafotb
tjmxl
vtmyk
mfkgyh
yxymsq
qgieyq
vkrap
lyewnx
ydywbq
ydjxj
gekkss
vxwmf
imxic
unhdm
16 16
zcrrvd
qknkha
diyidx
atjdxh
wvrrsc
hsofo
cjlpms
xrjar
nrinv
wrxln
aybjr
shxqr
wrudbk
luyxyw
njaioc
jgnkny
41 1
tlozo
lnwqkt
mjnyku
cdtgv
eddcnx
upzniy
zksptq
yomeg
ryiux
qyzyx
kmaty
hpprd
fmguq
wxpoc
qjrkxe
fzmiia
efxda
emsmg
hfxhnj
husgs
lnexg
dhxiy
pndvp
xtrysb
gvjyr
mtvzpi
xwidro
bkscq
biips
zgxzz
rpxbb
onqvxl
rilfp
zopnr
tcoavj
zikmci
fhgnun
ktkga
peijzc
ykkpws
alaby
42 2
gtpvy
kncwvn
qxjph
iapux
hfupjw
eplogq
umugt
smsseh
nddfns
tspfvz
gnxea
klqtxm
cvstq
nimrm
csvxhf
rvdnaz
gzfspx
sncap
fktux
gjkqo
iwscy
hobvog
ytjsb
rzxaf
crzem
rsyqoc
utrmm
skggqb
gfjgu
xycwbg
jbala
hlcrt
esykhk
fgunf
pdghvj
cewwps
llahd
fowiuu
ltrru
qprwqm
xrrxk
wfiizt
10 5
tlszlu
wieskc
msuhi
wxlfed
zpgrg
bmejts
cmjwp
fpkce
uwdcai
yipwju
17 1
aylivb
ruuumd
uvbyf
gczho
llcbpc
fcffud
qtxwbf
jrqmc
qajls
jydxz
sxaga
ljxlo
nconnb
qlczz
flfna
vsgrxt
chrct
5 5
vzxhdl
mleff
njnszf
egqhsy
wbqkg
21 21
ppqvpd
jrfpv
wmfsms
apiqnk
wqtlwf
rfyetb
oobowl
dmose
weiqx
ygoqgw
qzhpf
ingit
urjxxl
ewrcmw
wrbfgq
wnbwa
wagcw
wmqtf
afebh
jquxyo
qksjnq
5 1
nouqz
vlwzzl
wyuudt
ayhici
vqusd
46 23
apidp
enwcz
yztuh
cbseru
zrkkfo
gfdya
sjtcgy
wptme
vhabeu
udjvuu
juwuyl
ahxwff
vslixp
pxtzvq
zureb
mpqmc
korun
qkhtf
gclmw
sgcloq
ksilwx
liswhc
qcbied
jhtwtx
zptqww
wgejyl
rgafs
rdvxmg
chtdrz
slfij
omkmrs
igquhd
hecfho
cqsux
aygzae
uhdpk
cwxtf
zgyqc
dqmbqf
gmofd
carvqd
yvrmgi
ttokvf
xhuay
avnpw
vtvro
20 20
txfyk
tjkxi
zxbty
ngtcog
wldhg
sxuhwg
unoej
roiber
rhwqkk
dvylp
nzevo
gyeqyq
kroed
izkza
wjtffe
talhr
tzbgi
kcfld
nmxjw
mwnue
10 2
jvfrs
swytiv
strzf
wdajfg
usstl
epdub
eonwd
eztnp
feklj
vxdgh
32 2
bgtrju
vjqrnx
xozqh
rtrux
vitpvl
dmdmq
xeyssh
foxal
vjdtj
nlbeh
rqtcxp
gnnuf
madxd
sakbd
wjlkda
yuctq
lpfdp
wleyp
dcxqj
ixyjs
ebbjv
tgjjtv
ldtrz
izkhuf
gvnlz
brqwbu
qowkq
jlgqm
jlliq
gqnffz
zyhrg
tauulv
27 9
jhjvx
rwuotg
opqyd
ddzbny
hlrzdx
tizgq
oeslok
hgljz
iekmz
bdkpb
fnclaj
xohkyc
cwartj
jkkhr
tsekx
cibjh
qnavib
ucfai
npukng
nfmdix
arcswr
kegpi
mumki
sstwxk
izcjl
bkckns
kxrbpa
7 1
orhlj
ibqsk
ydawce
sigkw
chwrah
uxqooc
xnnjbm
45 3
ofdcr
xuzcf
gragi
rvzit
gmhdqw
qnnolp
psroky
kqyvu
fufdg
fnxoz
btktxj
upsbyq
otqhkt
wfkbz
ebnyaq
uwbfo
bxpwih
nqhwa
fdnsoq
qhprup
nbuhwz
vamaqk
epppby
vsuaqi
surns
tohukv
onkjpz
pjevd
dysksg
ktqlk
pfnyyi
bykcg
hccbx
tcxtyo
wqadh
moochp
wojhu
dbokio
ekmbm
uelwp
gtmpme
epvoxw
zleve
etjiqp
rndqn
10 5
tzsnyx
jhxizt
riquey
xzofdh
sgkpdo
rwqci
pggaft
pxxfca
mmbsly
bzougv
37 1
oyfeo
vtpohd
umrfve
rlowfg
afihdb
lpgui
bkzya
nyrjhq
hfqdpb
shqqz
kgpgfu
nthste
uowysk
aqceg
impsc
jcyzuk
ueoubk
iwnwcb
tkeghk
ktvva
pyeeli
vpbct
rlckvo
yrumx
dpvup
xejle
bofgk
bftwj
wtuom
aszql
odcdd
zjktg
rlkbw
mzciqp
zrbfr
gxuln
llpbc
25 5
jkmsm
qjlby
abwsi
ortxq
nayjal
nsibm
btvlkc
dwfjy
jtwvoh
aolks
rqriny
ghhrrl
tzykor
nzbtc
yhduk
vzfkc
zsbjgm
jdjlzo
twoxo
kkczjo
fqcnl
upecl
zdjun
moqre
aoxngx
33 1
fadsma
hvfod
kovxn
qxtcqf
zmumxg
pgyoz
dvkoqq
szmzjg
kwkupb
qvogb
vikdos
isiwhs
yibvdb
qrpun
unfmlp
xlajw
egpcbh
ejvrl
dwrxx
sthmq
wrbrgu
puyzgx
dssivz
nbudse
neciel
rvcdfy
duhhxu
xslsh
qgdct
xkmker
aemxtg
matho
mcdepc
13 13
epspyb
stxzx
xloaoz
dhuez
yghwl
wasups
xpfdd
jjvyv
wtizvy
urgkqw
xdfwzg
laizv
wqgkfr
39 1
eqnjh
jxbym
ahjwp
cmewi
dfzdz
uegdeo
upjdz
ndmzo
drkti
lvaere
rrrtq
pwbgfn
ccqdm
puhti
ekrav
pfzay
nzbnfc
lazcj
vuzajk
qneniw
puhju
jbidal
ovpem
fcilfc
qaokrl
xbkxk
azhir
mxipn
lsdcmx
zntyad
jdehw
vipjm
tybnlq
uqgbzg
qpttbb
ntavxi
cnodu
uftyi
nkcmna
41 1
sfpgo
ynwlya
plzfl
iummg
lpbgg
hiyaad
lypfm
fezlf
otemy
chzmte
yrcbzk
ojirbw
hhwejp
dfenq
wkmqj
myead
dbqbq
wrvol
njazox
ulfiqq
viytfa
kmpwp
oxaolw
rrnep
kajzf
svrfd
pqwdt
pkmezb
cjusxn
sokrg
alwrix
imoyf
hdcyw
gviyzr
peqvq
nszxlh
eqacnn
trswh
eyphk
roucgy
vlvjn
8 4
rswwpf
ruosam
iiwdnc
togcs
ycuab
fvfkao
ktjlt
amopme
39 39
htvoad
thjdxd
avwuw
ybmdy
gnpksv
xjrsk
tcgzk
gckhiy
wbbpzt
eeqiky
wavvms
nnibsk
tpqle
cfprz
fxvjur
xzooxd
dzish
eqygn
ydeosn
dszrwn
zonzu
yrtcjq
ibsbl
mwcrp
wszwu
zitdbv
xgxcb
wkcayu
csfpm
dwokq
xensh
ulvhl
livudt
rbcuff
mnuyb
eyslam
xveuxm
igqaop
ohwlf
15 3
qkwkw
ntprf
xtgumq
yjlsm
mskktt
osyvet
xpsbm
xjzcpc
ibhyjl
glvcaf
qfjmpq
slinj
ywnbkg
uvnlqd
igbyrs
32 4
ihsyc
lbcai
avlxy
ofnlt
ltppay
wtkuhx
ayizin
nexdn
elxmh
krswz
rmoxuh
hpuyy
nsblo
mtrzk
ekafmk
turkcs
jvmlj
fihbxm
rkkgn
fcaai
hcanxr
ptzbrk
ilzxhh
yhsql
sdqiv
mqzwus
fqfajm
rwyyt
txfkix
tqjen
zticrr
ygeppy
21 1
hpjbst
odpvw
backz
mdxtbe
anxso
tlbsjk
efmxlr
edhoeq
kpyqk
olutu
ccauk
snmqs
nonhb
tdzfh
qvebxz
aolxsk
fpkzal
mkrizh
nvbfgw
lciahv
rvddc
27 3
vmgvdv
nowro
qtrlb
owizw
ncfjv
exnuyo
cjwmm
uigjjn
dezof
jguxu
epmjli
kdwfa
foami
hybtnc
yzrxnh
odexzq
vrwqm
cfyis
exkruh
hhyqvr
pfcgtu
qqitq
vflzm
xuyixp
lrofxc
zwmsc
sxqkbh
2 2
hckdyc
qhvyg
48 16
pvpcs
pjfnvb
vinbuj
biivj
xhyqhr
vdyaec
uwstt
yicaot
pqece
lirdjj
ozuxso
dhekm
pwanad
dhftxp
hzgmut
dxayy
yhwhrs
pgmzz
ovimby
byujhc
ljsjp
scqaux
olfhik
sumjas
hoegnm
ovrzhu
afukra
hkpxwl
vzqrl
pblir
wamxq
kmxqmf
rfrhb
fdkyo
nltxmq
bioqq
gdues
trhln
rhndpv
tkvdz
nhueh
gdjsd
fyken
foohx
cumnjv
teeoev
nyfrnm
niodtn
49 7
vfcyf
artke
jmizjv
hmzxv
fwxvvr
pjemq
lhlxpd
nidibv
ddrcxm
elqwmi
ogokc
jmcwg
ufzsih
xoxxa
rblmoh
tjgob
qcanus
tkfly
izpby
ldhny
pficua
vvymd
gghlrl
pmomnj
rrupb
wzwwk
nvwka
gmzai
imhftz
acpmn
nfhja
zuptl
rzszl
nkhzp
htebok
vhbsf
gdrmke
zckigc
ggyru
nwsfa
ekcly
jjjrfl
vukck
erfmtd
srbrs
jbxgv
ozyzgp
irqdec
ryooi

Out #6:
Not possible
Not possible
Possible
Not possible
Possible
Possible
Possible
Not possible
Possible
Possible
Possible
Possible
Not possible
Not possible
Not possible
Not possible
Not possible
Not possible
Possible
Not possible
Possible
Possible
Not possible
Possible
Not possible
Not possible
Possible
Not possible
Not possible
Possible
Not possible
Not possible
Possible
Possible
Not possible
Possible
Possible
Possible
Not possible
Possible
Possible
Not possible
Not possible
Not possible
Not possible
Possible
Not possible
Not possible
Not possible
Not possible

In #7:
43
25 1
pybdsw
vonyus
nabazgr
lobwke
eqajjz
znptzus
sslviqe
hmphedq
ydjaxz
elpmgr
bnjumu
twxksv
iqrmkue
ipyamgk
edchfn
atkdas
rmljol
hdsaawb
yakhtqw
jhmpcmi
evatrfs
nfvnuku
udzmiy
vvjxcv
qnxyhp
40 1
azrxqkj
yihrie
kvddpp
qxyrlj
hzqxgzr
hecvhh
qjtvywn
aiomqq
uaodcc
yuzxez
lhqhil
ndaadrd
tyvvip
jgsvjto
qrwtnr
rjynqv
yhdfeez
uwppsmf
dkugug
ejljoun
xgrzxrj
ntcjwd
komljww
nnxzyrz
vjxisb
swqzcvi
wheszuf
yvqepbz
qnjfwfd
neuojh
iicyof
mccarkq
asjqdj
imtrah
czshipq
cibkpxf
aapeovp
wjldpf
agvprna
lkmklz
10 5
kwqxoii
wgyyqz
mxexzo
depinor
zcuvlat
nqqizs
tinxbrr
tpnpgw
ombhqd
rqlqnsl
48 1
prtvpc
ipkewef
cosjiim
evpcqho
jygucn
tojplqc
octfzu
otwlwb
zgssjn
nmfftn
siotiit
vzlhqdu
tloerhz
davcml
uxjgiqy
ijruic
upowpoh
qtpcsk
zvphaxy
xwnpiz
xkdymv
nfdjam
iskvpn
xfrcvm
saifrlq
vowqnh
wzmixgo
ddvkzgf
plpwcl
rlrgude
eaqydn
kzcizcc
qrhhajg
idhgse
frgmyg
nzyygg
cnmfnf
dljdiw
xlgfzwf
svpsqw
yfjplin
jsrjfe
btuypsx
tczsre
xkvukg
rpwuyw
abvqsqt
dfxdivk
14 1
mrmpous
gghjzax
xmnuyfo
idmtqrh
fumcirs
zjruqve
xkfzwvb
acnjqw
xzxulg
ztlddpx
cbneebr
ptijld
jdgrbd
zvdvlru
18 6
fzlmyn
fwofxtx
ybjrfwd
skztpu
kqbokv
hbtoqe
hoqdejw
weempyt
aeucpx
aiztyp
lhkvzer
kaibzz
apqebpm
wtzuss
kuqqlrf
rbkwmyv
aexhzd
nofrcnw
37 1
bhwvkzv
qlemjrm
bbosceg
yumaziy
oaajjs
cfcbfo
hcibjs
aiiapx
huamtik
nwxmjt
fodqhdi
cwbmdyf
oyvvkco
tswtrs
ozxqyn
vcgxxfp
bealef
zcbldmi
iephyba
bjbpabd
rqxcif
mvlmtr
kblyrs
exljgmg
teizeg
dqsvoko
penpldd
bhxzxdj
kwhilor
tdhdjz
lgtxlz
mizpcz
waekueq
nujykts
krvgqj
edtkvjc
banezb
42 14
motcln
omkbdmb
kzlvowi
oooesss
ovhiaj
uzqiow
jggrvm
htmzxnb
djenhg
tqocpaw
fkpjkf
sruzcj
ejkxdd
ttumghe
vagmpaa
fbwpaun
vlidyqu
alrklbe
kboqkaz
fmqoont
uenecu
kdmpele
ikalfsa
efhbou
pduiqu
ienfva
sxsxyhl
cponml
qqpzivl
qtpwpl
cmhegn
fjlujko
kigocfe
ohwfztn
oravdoy
neunkkf
gltgxku
pyrdac
vwlhibk
efowfhq
cwfatfh
odciqti
31 1
axvraj
bkizays
ivktyld
pijjdiz
pothhp
rbahod
ddjhhz
snjlygy
qdvfxru
kljzcwu
lvgcmy
vikjcio
lfhmqx
ngtkdof
jhgdau
ikzyya
bczntm
wcwmks
ktdhtvh
kbqitp
broobg
cqlunet
yovttmb
gcftuyr
xgftkr
jwiiyf
vxuoarx
aoueimd
ykpyyk
mcuyeyj
sudefpw
37 1
cahyep
kqrxzdd
fowflr
buvpyhl
smuibx
hcvhlzr
kyzfcc
orjknqw
azpdod
jzbglk
vfvwlo
avuldvp
qvzkgp
itiycfj
vwebmr
oytcdkf
mrcxggf
iaqrln
wsvubbj
atumbyh
tvnzxz
vowbfx
mbidip
kmaojj
zxrvjau
vyrqxva
gqfifwe
lrsifn
mvrqkbx
hltnria
fslnynq
ojqysk
qaqpnkw
yxwnqov
menabem
pvftkbr
kuzosx
10 2
nnmibpm
gfwibd
ijideuu
kvrpjv
fshtin
wwcsyyg
tykqgmu
idjvsbq
zegvikw
hhwbbfd
1 1
vfwvffo
11 11
fpuwclm
ojhbmlm
swiwfgl
ccspgz
jfbxsul
luzxpo
qowehpy
akzsgqh
gouwrt
vcafop
aqxtped
41 41
oqbvrwu
qqgcmx
urinewn
wzopdn
bgrwpb
rtyxrx
ksdoie
hqbstns
stydtl
lcsrqlv
hahywti
ncylsa
eeicvfo
wzuqpwo
oxmlih
ubajwy
pggzdse
jcmljby
prxcgd
nmwhoyp
iiyyau
osclli
drfcrio
bqqjkh
oqizea
myoubcd
myptlcv
gusooan
edvilx
aoypyg
asmwaan
ptfwmh
ipyptgu
jafygs
xflxwv
omalrp
ztusfn
imfkas
khysebf
qjqjyy
mzheybb
8 2
tfqnkyk
ldwckmi
pipzbz
pwjfazm
dzvhvxs
fqsyytu
bqflsh
oopeych
16 4
rnrvotw
hfmhpbe
ahopnr
miuzwo
oipuom
dxaabsa
isxfyfa
bthvqi
ubvugcn
yhzkey
wlhtiui
ypyiahe
hicawss
bsofwo
dmodik
puhbmtu
47 1
kmzpqz
uhxkday
gpzkozt
vzghrw
egvgjmk
lfvhbeh
cwlzjjw
iwosjj
abjlazm
vptrfe
yvrncx
ofkjxll
souzfd
hizpqhu
bysitv
kypjjo
uhmjzn
ozjrofl
lpufzxk
ziubeu
wbcimc
xqmlrm
xikyvig
atwtjb
pxfuxv
lzcbdq
oitote
mfqfdy
fghqrtn
ciidxu
zdricn
obpjsz
hbjmve
pkbqfm
mrhcsak
uhcjbwn
ebyaluo
zzrgqky
skpzsvh
wansmnx
ozqknlu
fntbyk
avkmasi
ebydypc
asynlu
wwcgegv
qsczed
42 1
lwoisv
jpnpip
vgeuzu
jocndnb
gyqhwo
pmfvvbz
zdwefq
peeqggw
jydkoo
qovgbre
hablgih
fjtrwhj
uazvvpu
ryfzxgr
orcsnc
kztrxm
pgcjytw
ypwlcbq
ntzbdv
dttlxu
heconoz
udtqhb
ssostn
mmzeiy
sbxydq
tunddm
oalmmc
axzvee
rcxqvfm
abqlkm
zxvgok
btsxpoo
pijqujn
cvfqou
uvsghfr
mtzgie
afkiad
zphmawe
tkgffhj
lqdoohm
hupatgi
yxepghz
28 1
fprozt
zxqlzj
lsgisz
egorcbt
mdaqxn
magimo
vwmaree
qtguscs
wdfrqzn
fccsjsb
dwuvfo
bfcfkyq
pnvdysj
dbkeuu
jwdkpl
gwjfoil
zemmwn
ouzfcs
soebfyo
fcbdus
jvcaxy
dypskk
qknvtf
rtvvgg
lxennnk
zyxllb
ipbidpy
zrzruh
31 1
sdtial
npmurco
npfxwyg
oqhlden
fmgltge
fowfeyw
zwbzjz
intqfer
hchclb
vadwubn
hiiypm
uzqezo
bxttrc
ralhxdd
ksxdonl
qpmhkf
hwoktfe
lcyjkaz
swbrhof
ucbiqp
hllrir
pdmzor
szxtss
vrggrdl
fgqpwfp
dwtxjjc
noaiki
vkaqzgu
aibrxrq
zfbufm
xtzvit
11 11
wrxedy
jrvkga
fftdir
kpkbgps
vwmwdim
ocmhpev
tzbyate
ckwqiz
rxakvy
cwiewhs
uslcuq
50 2
ukoxsjm
fhgyjgy
neiezd
toyupf
pjehmqv
hylafhe
jimdkb
vsafct
dnqxcn
oatpke
bvzojle
xnxvba
vqplxcd
vcsjfem
rqfwuv
qklwutj
tbfbwhf
lbuqgf
ghdudw
vfxbnv
cxfoxfo
vtkllx
ssggzjo
yujsgno
bzyaps
jvrspcj
nwobsr
qtujue
ijezwk
meuercl
vemcfe
irfocpb
dcsoges
fqqywx
psapai
zjvvww
rnumet
bviiiaz
qeplktb
ihfjpy
nvhzxrq
vbceby
mmuljlo
juogtf
rezfbuo
vdgsnn
edpuucr
sylhao
kmtwkk
gslblo
24 1
npyesu
ixmlhm
ctbxeh
qndygwy
ubxjlfv
bjqrfg
wxqjvra
ryvguef
gbjvcdg
xefejb
tkvakm
qbehbln
jxqdmc
khacgf
dplywe
ymlowc
kywiktv
slylct
cnhfjmu
fufzfxg
dajkqi
jyusjix
zbagis
qhutagq
44 1
pukpozu
snvfrh
buvhps
oqnidea
vqagud
dimssn
jzagmal
gsysvoo
qtqhwor
qbxotl
axewbo
zhfhbyz
rnykmi
glrvwox
oektggq
cyvpag
yjqzmz
uhmoeux
sxiaef
kppqoj
ayfhcxk
lrbdgjg
avduyw
kajeay
teabjzp
pfikhw
qwdpszd
vlwbil
ienotp
guoictj
ozblqzx
sfzilg
xldxei
hpopfm
nqqxoh
nmuufy
uvpggq
snusedk
tujducs
wrublyx
wzdpmq
psibwn
uchqqj
xxpqjh
30 5
nmbmmu
xmwtvuu
vjlahhc
xxtwwu
bypldx
lyscpun
hxiloa
msmnmb
apvbqm
ecebbcv
dcssbqr
aejlutf
qfblhnl
tgsamam
tdwpada
wjrhkzq
nucjtfb
oufwtou
wzgipnh
npooknh
sqsfunm
hxzzdxt
bwlfpfz
iytool
gpdahxj
haiqbm
blrgls
osuhrwv
pjulxip
zixlefm
30 2
nmhvdn
yywvev
bpagdf
klcylxp
hjgruvr
kwxyfu
fmnpjg
ouniwo
bwqsoci
ooeurk
kzilbd
huugclb
szknvp
fdfawdd
fzpssf
wabhkf
yszfxzl
cquovu
rdkmbjc
eogqkl
ixtasah
ylszmku
uimgzto
ytqofep
rulqdne
vmcucvz
ikzfotu
zxtarj
ctmkuza
orclusv
31 31
pqpxsj
hpbzydh
gpjxlex
vurweah
xawfox
uxzaao
yiwtst
sergwfq
knhbifw
dpbpma
hfbmib
covketl
uofriew
egcucep
ffeqnwq
izrkjj
uxazkv
rrvfuan
fumjfiv
rouqbt
tnecwpk
goedmyk
yuodhtq
oypiesa
irlogrg
lnahyf
azorzlu
tjtjadn
ohmboiw
dnzdsep
ftybpjk
32 16
oigztj
bfkdpp
koyzwd
lrzeskr
wnkcasp
egtlovq
afhqksz
fgqfhk
rnxkrh
rrabuwn
jyhkefk
ympiycq
sactcg
scmxoa
wqlkpw
yijzut
qgxgqjm
lqimej
mbsgtgs
jmhlwtm
rulhjhr
rzwqsk
nwczyd
wywrma
dihimr
zkzlol
ndpmyb
uowqqog
mygbcpv
ucjakq
pyybjsf
urltfr
35 7
pppsbj
slazpd
yblkaox
bxepdi
pclsea
krxuuxs
cqfjlyl
uxvcjlq
izgogi
gqxqqqb
wvvroz
nkxcrwh
qdhnjcn
crwcco
javxfxu
ozulyf
brzidty
xbfvito
xigcrkp
xkvtxo
mfnerzv
rcneje
zcgsyor
nyylzg
jeqddo
cqfyew
omxregd
ecyxsaz
jpcvhnt
dwexeso
frecpfv
fckpwr
cfytsx
wbpbwz
yxarbhm
10 1
augtvm
gpjcqh
rgrpbdj
pdxawxa
sugrhxl
fkhkyqb
truxqh
fzbgpka
aytezi
qckrjv
13 1
qiizef
qfarhnt
gfqhqa
piohss
wstcwto
ieydssx
gskndvw
vdokbi
xpwkqgu
rtqgoxg
yscppx
mlqtqic
wgynyw
28 4
lniwnb
vbtglhb
mkjvml
fzicye
yrpotez
bfkuic
zhkutyq
yfolllx
ryxnejh
tltygf
xbzygc
anustjg
gpfqfdp
zikeii
jshfzg
doqncm
qvkyyh
tigcwk
ahcmcp
imlyorq
flndjin
wdnysp
omgzfie
uvqbpf
fecwrq
mymjhb
ejzupqw
yathir
25 5
yjiait
cudcao
azlhneq
alauppx
zjlzxsm
hajhahe
mskomku
iyvarm
usfawc
gjhpfdy
biltnd
eautys
mqsncx
hwadbx
vbbptnb
ngbmuq
aiwstlc
rlnahwc
klhiia
drwmjo
gzarhse
hvfhnu
ewpeiqr
irhpng
arvobph
43 43
kzixvr
hqmeqs
stvtnj
btlaptr
dhsyse
dewvddi
keebdxg
phgewr
ruhwpi
lrovzel
nqqfqp
bzejke
zflvgv
mxbvald
ahnzrrl
fvhpfsv
zpkpzw
okqphym
xaxsmvz
hyznvkt
innpflw
dswgcy
cpwkvjr
ycbgoie
fsvbop
meevarq
fasloos
nxmkbsr
nmkumrm
nljmazk
xhajlul
whlxjz
kgnely
ykoklua
stivzls
nbcfaa
kirues
sxgqju
lfhzag
wamxqbf
mtxrnd
iznhxb
nbtapf
7 1
kprgmw
ezpydxd
oimwcw
nsvopar
zhwbmiw
afaxkv
vrskem
32 16
ubwhxdb
wcmieel
imjcur
exeatb
xhqjkwa
odwjbcx
htxhoo
gqwpcic
avjrtt
zloixab
xtugbz
nnjqgrm
ggjgar
keiqbz
nimvlk
skflya
ksxnik
dnzgrn
dfhwzx
eanyyu
eorhayz
hncnhk
gsxorvd
yjlrvt
uuvzqvs
kercrfc
lnernw
ssgyeo
bngnpou
hrabjkh
purippr
tpgcal
24 8
kvjuigd
eplhax
mvkttaf
aldofv
osrkub
nrlppsm
efsswu
vbhvrn
ljzxmf
xlhxji
gisgbu
ekmyvi
kaukfl
mrxvwnf
olrbadq
lkgikb
iotojkd
fulpwns
pbbbohg
oafgznm
xgzeux
kwinwn
usacwi
kacmftp
24 4
zxncbh
rigkxji
cgprxml
fjnwnw
voccel
xdpyacc
lgfprnl
bqlfug
fpeaafo
xymrwln
cuglhn
lpynjun
zxveje
qmsrrtz
uldypt
jkaeodm
gngkci
svpkyf
pcyqbct
lijrew
opxuxwp
ksbkdf
uvbbqqx
pwahgw
13 1
foxahv
umpjlzk
jqhggkd
ilnhhro
giljaf
ophtede
pzrvhs
gejspy
ptadhdt
qlngckz
usglnhv
yihltyn
fnvrljv
11 1
ozpafax
prepvaq
nlajvt
vhaexf
tzoexr
jcxygfo
yraylvo
uuihek
lggoak
pnjaar
owejiyj
32 32
vobemng
wdeijx
clmozat
iqgjxgc
wfcxtv
cgazcf
wnxlrkl
illjlm
izlmxty
ljxjhka
cdezkzn
lhhufl
ulpgtl
tssdhrk
htigtky
mmpibje
ykqgau
ocjyihs
jzxxwr
yeqelrj
leiqxk
wctkyx
acsgqt
ygeozyn
gpvzak
rqkixo
zobrglm
wjfwlno
rczele
qkvuskk
wpprza
nvpppa
13 13
csxslq
korrte
vmlliuz
yykvbih
lfkenj
qgnmwda
jvhennf
gffbag
mlixng
soybiz
aihgkm
kdvyqfl
gbqwtn
26 1
ayfhzq
sozqhmr
aqkojo
kgqzxj
giwain
kbpkufh
umyncjk
wlyqhdx
rnwqcby
bvtipzr
udrcdzu
gdapbg
yzlksjb
brmjwap
zequcdf
yptrbp
qbmrnfs
gnjehl
niqumy
oehtrjd
nckfmvm
gqtryl
onirlpb
ejhjudx
rxggng
ggmlri

Out #7:
Possible
Possible
Possible
Possible
Possible
Not possible
Possible
Not possible
Possible
Possible
Not possible
Possible
Not possible
Not possible
Possible
Not possible
Possible
Possible
Possible
Possible
Not possible
Possible
Possible
Possible
Not possible
Possible
Not possible
Not possible
Not possible
Possible
Possible
Not possible
Not possible
Not possible
Possible
Not possible
Not possible
Possible
Possible
Possible
Not possible
Not possible
Possible
In #8:
10
20 4
jajmvp
snxjgyg
wbjfzdt
hieomg
iqpbin
dqmlue
kupmqqu
idnpdyk
ucimwmk
bcqblj
cnobhrs
bqgbcj
banjhq
nirfoz
ejbgek
cmczvuw
luvuvb
obkqxi
wxamzn
bczshmn
32 32
hdjugn
arcdnv
hyielpz
rqwdii
ugsqvxd
kgyzmya
ltokjp
lhviqos
olwfgoj
azzgbsy
ocdappy
wopbuy
qlsvab
mfimiz
xhjvhyl
qaqtog
hacxjo
pbakvlk
eoiwcmm
kimpch
agtjlfy
jtefckz
qsmumf
ndyozq
qmxnquz
qnzpiak
ibelsmz
yogkckr
cjawiz
cyglla
etqhayi
vycrlo
42 3
kadwoqo
xeivpaz
afzpiw
jsjmej
fpjyfxe
jdtgtxd
hxgobtd
oarrip
tvzkjf
byllkbo
ubhqel
gvzavp
wjkmbn
femzlg
rjijnv
xxqnjn
jlznkwk
gtqseh
hmursb
bbciyu
mcbvlb
ijjxzrw
qlotnx
qctzssv
zoowmi
cxbxcj
sfbpchw
nayvkoi
kwlaps
ntbawma
xhslirs
bimeeb
jusovg
typpptd
rkuydbv
hhrbuk
svgqsib
cqcwqs
jperue
mnvrbn
fmzpoo
dsldegu
25 25
nestjm
wrmxprm
itgzdki
pygxpd
vnbsut
zclzub
ktemsvm
bdwzih
bfifdbz
wsdgcsc
egqtbrn
xnyhtb
fphxaiz
jiecack
ufocgj
eruoog
mflisk
wjuobys
qxwkvby
xlirjo
ozhzomm
jnrmhkv
mmniuph
qckfnx
yejubb
13 1
vvguqow
xiaaivv
gahuvui
xvnlyhy
lddhbo
ekhtrk
dffuatb
zvdehjk
ofoqbyr
objhsy
yrebyw
qabtgrs
pcrpzkf
30 3
gtyrrkb
abctti
bqrtbya
kancmhd
fxmtrg
cyzftq
ffltvtr
uemjgow
yjwevx
mrsjxdi
yalrne
xespnbn
fawspqk
yxoxpi
ablfkk
ikeywr
bcfaqdf
uyjwoa
wxpkfna
itwyhmv
vjbtuvy
nuqskv
aeoiazy
csruozn
pvngkt
gbegon
keypppp
oyntupd
mwzxoc
kmzrdqj
1 1
igbitnb
7 1
qiireva
hbfhnk
bktpso
rjishs
pvnlhmw
kdbajbg
hekedsk
5 1
epzslk
yepuxda
flxawnv
aewmfm
yinhsp
6 1
eworwe
szmjxz
yuszjr
nzorhd
ogzgnhm
hemupl

Out #8:
Possible
Not possible
Not possible
Not possible
Possible
Not possible
Possible
Possible
Possible
Possible

In #9:
10
1 1
lgsng
19 1
hfj
qh
oou
hyap
dvdbm
csb
kdjqi
x
kr
uck
dm
edu
blfs
qwr
gddep
nxoxh
i
gnr
j
25 25
j
iob
weewi
eyj
ba
tbk
iparq
dxe
zmjq
iba
iuwzy
njp
qwwn
me
gn
dssh
fya
cdhw
bc
ii
rxicz
yeli
z
zj
fc
17 1
nzrcn
s
rum
jobxb
lqa
vpfk
d
v
tjr
wtpm
znzn
vkqx
mj
mhe
te
e
bza
49 7
ehqi
qbrzh
a
hl
hmamw
sxoe
wll
zubi
y
elrvy
hh
kk
by
qiv
i
k
hzk
tnhux
njni
sds
u
knfst
ypi
kspz
k
ujr
hcogl
a
dipv
nhfdc
rin
wm
rsxky
ppev
ba
z
qdyt
fg
dhj
plib
vx
r
mus
mw
higyo
ekuju
jic
kq
zcurr
5 1
xc
hp
qzgin
a
aly
58 1
qltsr
v
whuci
duuu
naccf
kahfc
sj
eb
iyzf
ch
hkur
lk
kgn
hg
j
dv
zju
qkeu
wczn
xzxod
eei
pvxwu
xgqk
czqus
j
tfb
e
vgdqa
ft
n
qlli
itk
j
c
cg
t
ov
arcg
ucyoq
xshc
q
u
dddxi
vqpvk
hw
qv
w
ajv
zx
sbb
rbalk
xnfpf
yv
bf
kcrw
v
tezrr
ydlrb
48 12
wahne
fdnqy
tvo
gsvx
ddsne
e
wvr
mhex
suzx
wcsg
ooc
cndz
sh
z
e
q
lqg
x
u
xsgiq
ut
tgy
f
rtb
uonq
qh
hibwu
prxm
oiz
gt
fdy
cwip
brio
nfknu
q
xntt
xbk
f
no
nyl
uois
jqpz
d
jhw
ajj
r
ljzg
chift
8 8
yzjp
v
de
oxio
nkf
w
iq
d
15 15
tvwij
go
hfwq
mnkdg
ych
vnjg
wpg
m
z
mppgd
alm
u
a
qml
mvyu

Out #9:
Possible
Possible
Not possible
Possible
Not possible
Possible
Possible
Not possible
Not possible
Not possible

In #10:
10
13 1
vcce
yilm
hj
a
emswv
t
hy
kba
emx
n
p
cm
oavdc
3 1
r
auwkf
n
37 37
pvs
k
aqsq
ozfv
makfo
td
l
ohx
ih
zd
vip
r
iaea
wbah
hx
zsfst
xyk
pk
veeod
s
yw
iuyh
il
zypxy
yigd
q
jgbcc
kihn
jypx
jl
llq
kv
vduf
febnh
puoh
rucwf
ne
55 11
tk
pxn
wkd
yh
y
ulq
jv
wvex
ogrc
i
krm
kgej
cxc
nd
xkb
jnv
xjhf
wzib
tanxp
qhuym
vsm
a
f
bfag
ere
agebq
d
yp
b
wkyj
oxeih
ew
rln
yukg
xmsw
dpijg
hoz
kyud
gx
lrarw
t
zb
soyi
bg
r
gb
oekg
nopb
dvi
j
seqz
b
kmogo
xbw
cvq
20 20
rkmbp
yrll
nkfun
jrt
qow
igukx
lpz
atna
fbz
ojh
djr
qnpd
lzb
fobgf
niw
tzyv
lhcy
vhluq
a
lmkba
34 1
ogba
kjyzt
kwdzm
kdw
iyyn
b
nj
nmup
bsj
odwm
qvu
uffxy
mj
jiwr
b
kyges
lsv
vgn
d
h
zuce
vswym
de
j
blhm
nimdr
uxqcy
kyo
dttr
xdx
gx
pgxz
s
dym
4 1
nyne
rjon
qnk
z
49 1
wd
oenh
rwz
dxcu
pes
ot
nprjr
xtijq
hyit
e
bptmr
ukmfn
h
csd
wy
jmlyb
gk
j
l
ivie
xjuhi
ghzt
f
wwgqk
fg
fwhcp
knoi
ljko
wggi
s
jzvb
ni
msya
rfr
tmi
k
wkan
cgz
embuf
g
odvus
ujt
ir
oomfm
ii
bdwmo
dg
bo
bsua
29 1
aqa
qnl
nbh
e
sv
xp
bpt
a
tyvm
tec
bxke
w
trudf
uccpd
mbmw
hdzfk
rwtq
vkx
lu
ymkfi
y
u
r
uxtx
xxk
oqs
qqqpc
sjvp
v
32 4
pgg
hcp
cftza
gci
go
qsyx
ncik
ivz
taym
so
tc
z
bzxem
zpa
vozgp
lthyu
h
lzass
yyhcn
lb
fvj
ww
nrdp
bze
emvb
fpfx
a
png
mhde
y
p
cvlk

Out #10:
Possible
Possible
Not possible
Not possible
Not possible
Possible
Possible
Possible
Possible
Not possible

*/

/*Editorial:
It's an ad-hoc problem. You may get tricked into believing that this problem has a lot to do with string algorithms, or the likes, but to solve this one: 
you don't need any of those tricks. You need to notice that all you need is the length of strings to be stored, 
and since the value of n is very low (1000) - all the lengths can be easily hashed in an array of 1000, 
and then we could simply iterate over the array where all the lengths are hashed and if we find any value which modulo is NOT equal to zero, 
we would know that there are not enough people of that given length to form a group in a camp.

You may look at the implementation of the tester and setter for clarification.

Author Solution by Arjit Srivastava:
tc = int(raw_input())
assert(tc>0 and tc<51)
for i in xrange(tc):
	n, k = map(int, raw_input().split())
	l = [0]*1000
	ok = True
	assert(n>0 and n<1001)
	assert(k>0 and k<1001)
	assert(n>=k)
	assert(n%k==0)
	for j in xrange(n):
		a = raw_input()
		l[len(a)] +=1
	for z in l:
		if z%k!=0:
			ok = False
			break
	if (ok):
		print "Possible"
	else:
		print "Not possible"

Tester Solution by Ashish Khatkar:
//ID: ashish1610
//PROG:
//LANG: C++
//
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define vi				vector<int>
#define vl				vector<ll>
#define	pii				pair<int,int>
#define pil				pair<int, ll>
#define pll				pair<ll, ll>
#define pli 			pair<ll, int>
#define pb(v, a)		v.push_back(a)
#define mp(a, b)		make_pair(a, b)
#define MOD				1000000007
#define rep(i, a, b)	for(i=a; i<=b; ++i)
#define rrep(i, a, b)	for(i=a; i>=b; --i)
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")
ll pow_mod(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
int cnt[105];
int main()
{
	int t, i;
	si(t);
	rep(i, 1, t)
	{
		memset(cnt, 0, sizeof(cnt));
		int n, k, j;
		si(n);
		si(k);
		string str;
		rep(j, 1, n)
		{
			cin>>str;
			// cout<<str<<" "<<str.length()<<endl;
			cnt[str.length()]++;
		}
		bool flag = true;
		rep(j, 1, 100)
		{
			// pi(cnt[j]);
			// pn;
			if(cnt[j] % k)
			{
				flag = false;
				break;
			}
		}
		if(flag)
			cout<<"Possible\n";
		else
			cout<<"Not possible\n";
	}
	return 0;
}

*/
