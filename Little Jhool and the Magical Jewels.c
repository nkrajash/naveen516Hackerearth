/* All Tracks  --> Data Structures --> Hash Tables --> Basics of Hash Tables --> Problem -->
Little Jhool and the Magical Jewels
Tag(s): Basic Programming, Easy, Hash function

Little Jhool is still out of his mind - exploring all his happy childhood memories. 
And one of his favorite memory is when he found a magical ghost, who promised to fulfill one of Little Jhool's wish.

Now, Little Jhool was a kid back then, and so he failed to understand what all could he have asked for from the ghost. 
So, he ends up asking him something very simple. (He had the intuition that he'd grow up to be a great Mathematician, and a Ruby programmer, alas!) 
He asked the ghost the power to join a set of *the letters r, u, b and y * into a real ruby. And the ghost, though surprised, granted Little Jhool his wish...

Though he regrets asking for such a lame wish now, but he can still generate a lot of real jewels when he's given a string. 
You just need to tell him, given a string, how many rubies can he generate from it?

Input Format:
The first line contains a number t - denoting the number of test cases.
The next line contains a string.

Output Format:
Print the maximum number of ruby(ies) he can generate from the given string.

Constraints:
1 = t = 100
1 = Length of the string = 100

SAMPLE INPUT 
2
rrrruubbbyy
rubrubrubrubrubrubrubrubrubrubrubrubrubrb

SAMPLE OUTPUT 
2
0

#include <stdio.h>
#include <string.h>

int main()
{
    int t,i,j,min,c[4];
    char s[101];
    scanf("%d",&t);
    for(j=0;j<t;j++){
   	    scanf("%s",s);
       	for(i=0;i<4;i++)
       	    c[i]=0;
        for(i=0;i<strlen(s);i++)
        {
        	if(s[i]=='r')
        	    c[0]=c[0]+1;
        	else if (s[i]=='u')
        	    c[1]=c[1]+1;
        	else if(s[i]=='b')
        	    c[2]=c[2]+1;
        	else if(s[i]=='y')
        	    c[3]=c[3]+1;
        }
        min = c[0];
        for(i=1;i<4;i++)
        {
        	if(min>c[i])
        	    min = c[i];
        }
        printf("%d\n",min);
    }
}

*/

/*Best Submissions:
C:
#include <stdio.h>
 
int main()
{
    int t,i,j,count1=0,count2=0,count3=0,count4=0,l,m;
    char str[101];
    
    scanf("%d",&t);
    
    for(i=0;i<t;i++)
    {
    	scanf("%s",str);
    	l=strlen(str);
    	for(j=0;j<l;j++)
    	{
    		if(str[j]=='r')
    			count1++;
    		else if(str[j]=='u')
    			count2++;
    		else if(str[j]=='b')
    			count3++;
    		else if(str[j]=='y')
    			count4++;
    		
    	}
    //	printf("counts is %d %d %d %d\n",count1,count2,count3,count4);
    	m=min(count1,count2,count3,count4);
    	printf("%d\n",m);
    	count1=0;
    	count2=0;
    	count3=0;
    	count4=0;
    }
    
    return 0;
}
 
int min(int a,int b,int c,int d)
{
	int m=a;
	if(b<m)
		m=b;
	if(c<m)
		m=c;
	if(d<m)
		m=d;
	return m;
}

C++:
1).
#include <iostream>
using namespace std;
 
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
 	string s;
 	cin>>s;
 	
 int r=0,u=0,b=0,y=0;	
 for(int i=0;i<s.size();i++)
 {
 	if(s[i]=='r')
 	 r++;
 	else if(s[i]=='u')
 	 u++;
 	 else if(s[i]=='b')
 	 b++;
 	 else if(s[i]=='y')
 	 y++;
 
 }
 	
 cout<<min(min(r,u),min(b,y))<<endl;	
 	
 	
 }
    return 0;
}
2).

#include <iostream>
#include<string.h>
using namespace std;
 
int main()
{
	char a[102];
    int t,i,count,max;
    cin>>t;
    while(t--)
    {
    	count=0;
    	max=10000;
    	cin>>a;
    	for(i=0;i<strlen(a);i++)
    	if(a[i]=='r')
    	count++;
    	if(count<max)
    	max=count;
    	count=0;
    	for(i=0;i<strlen(a);i++)
    	if(a[i]=='u')
    	count++;
    	if(count<max)
    	max=count;
    	count=0;
    	for(i=0;i<strlen(a);i++)
    	if(a[i]=='b')
    	count++;
    	if(count<max)
    	max=count;
    	count=0;
    	for(i=0;i<strlen(a);i++)
    	if(a[i]=='y')
    	count++;
    	if(count<max)
    	max=count;
    	cout<<max<<"\n";
    }
    return 0;
}

3).
#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main()
{
//cout << "Hello World!" << endl;
    int t;
    cin>>t;
    while(t--)
    {
    	//int ans;
    	string s;
    	cin>>s;
         int a[4]={0};
         for(int i=0;i<s.size();i++)
           {
           	switch(s[i])
           	{
           		case 'r':
           		a[0]++;
           		break;
           		case 'u':
           		a[1]++;
           		break;
           		case 'b':
           		a[2]++;
           		break;
           		case 'y':
           		a[3]++;
           		break;
           	}
           }
         sort(a,a+4);
         cout<<a[0]<<endl;
    }
 return 0;
}

4).
#include <iostream>
using namespace std;
int a[4];
int main()
{
    int t,i,j,min;
	cin>>t;
	string s;
	while(t--)
	{
	 cin>>s;
	 for(i=0;i<4;i++)
	 a[i]=0;
	 for(i=0;i<s.length();i++)
	 {
	 if(s[i]=='r')
	 a[0]++;
	 else if(s[i]=='u')
	 a[1]++;
	 else if (s[i]=='b')
	 a[2]++;
	 else if(s[i]=='y')
	 a[3]++;
	 }
	 min=a[0];
	 for(i=1;i<4;i++)
	 {
	 	if(a[i]<min)
	 	min=a[i];
	 	else
	 	min=min;
	 }
	 cout<<min<<endl;
	}
    return 0;
}

5).
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
#include<unordered_map>
using namespace std;
 
 
 
int main()
{
    
    int test;
    cin>>test;
    while(test--){
        string s;
        cin>>s;
        unordered_map<char,int> m;
        m['r']=0;m['u']=0;m['b']=0,m['y']=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='r'||s[i]=='u'||s[i]=='b'||s[i]=='y')
            {
                m[s[i]]+=1;
            }
            
        }
        vector< pair<int,char> > v;
        unordered_map<char,int>::iterator iter;
        for(iter=m.begin();iter!=m.end();iter++)
        {
            v.push_back(make_pair(iter->second,iter->first));
            
        }
        sort(v.begin(),v.end());
        cout<<v[0].first<<endl;
    }
 
 
return 0;
}

6).
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,l,a[4];
    string str;
    cin>>t;
 
    while(t--)
    {
        cin>>str;
        l=str.size();
        memset(a,0,sizeof(a));
 
        for(i=0;i<l;i++)
        {
            if(str[i]=='r')
                a[0]++;
            else if(str[i]=='u')
                a[1]++;
            else if(str[i]=='b')
                a[2]++;
            else if(str[i]=='y')
                a[3]++;
        }               //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
        sort(a,a+4);
                        //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
        cout<<a[0]<<endl;
    }
}

C++14:
1).
#include <bits/stdc++.h>
using namespace std;
 
int t, cnt[500];
string s;
 
int main()
{
    cin >> t;
    while (t--){
        cin >> s;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < s.length(); i++) cnt[s[i]]++;
        cout << min(min(cnt['r'], cnt['u']), min(cnt['b'], cnt['y'])) << endl;
    }
    return 0;
}

2).
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t ;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int ct_r=0,ct_y=0,ct_u=0,ct_b=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='r')
            ct_r++;
            else if(s[i]=='u')
            ct_u++;
            else if(s[i]=='b')
            ct_b++;
            else if(s[i]=='y')
            ct_y++;
        }
        int ans=ct_r;
        ans=min(ans,ct_u);
        ans=min(ans,ct_b);
        ans=min(ans,ct_y);
        cout<<ans<<"\n";
    }
}

3).
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
    int t,n,i,j;
    cin >> t;
    while(t--)
    {
        map<char,int> m;
        string s;
        cin >> s;
        n=s.length();
        for(i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        cout << min({m['r'],m['u'],m['b'],m['y']}) << endl;
    }
}

4).
#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define mod 1000000007
#define llt ll test;cin>>test;while(test--)
#define pb push_back
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define rep(i,a,b) for (ll i = a; i<b; ++i)
#define len(s) s.length()
 
using namespace std;
 
int main()
{
	boost;
	
	string str;
 
 
	llt{
	    map<char,ll> map;
		cin>>str;
		ll l = len(str);	
		rep(i,0,l){
			map[str[i]]++;
		}	
		//for(auto it = map.begin();it!=map.end();it++){
		//    cout<<it->se<<" ";
		//}
		//cout<<"\n";
		
		ll find = min(map['r'],map['u']);
		ll find1= min(find,map['b']);
		ll find2 = min(find1,map['y']);
	    cout<<find2<<"\n";
		
	}
 
	return 0;
}

5).
#include <bits/stdc++.h>
using namespace std;
 
#define fill(a,val) memset(a, (val), sizeof a)
#define pb push_back
#define lli long long int
#define scantype int
#define endl "\n"
#define unique(x) x.erase(unique(x.begin(),x.end()), x.end())
#define sort_f(x)  sort(x.begin(),x.end());
#define sort_r(x)  sort(x.rbegin(),x.rend());
 
lli MOD  = 1000000007;
lli inf = 1e15;
 
void scan(scantype &x);
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli string_to_number(string s){lli x=0; stringstream convert(s); convert>>x; return x;}
lli add(lli a,lli b){lli x = (a+b)%MOD; return x; }
lli mul(lli a,lli b){lli x = (a*b)%MOD; return x; }
lli sub(lli a,lli b){lli x = (a-b+MOD)%MOD; return x; }
lli divi(lli a,lli b){lli x = a;lli y = powermod(b,MOD-2,MOD);lli res = (x*y)%MOD;return res;}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
      string s;
      cin>>s;
      int arr[26]={0};
      for(int i=0;i<(int)s.length();i++)
      {
          arr[s[i]-'a']++;
      }
      int a1=min(arr['r'-'a'],arr['u'-'a']);
      int a2=min(arr['b'-'a'],arr['y'-'a']);
      int ans=min(a1,a2);
      cout<<ans<<endl;
    }
    return 0;
}

6).
#include <bits/stdc++.h>
 
#define SQ(a) (a)*(a)
 
#define F0R(i, a) for(int i = 0; i < (a); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define R0F(i, a) for(int i = (a) - 1; i >= 0; i--)
#define ROF(i, a, b) for(int i = (b) - 1; i >= (a); i--)
 
#define ran() (rand() & 0x7FFF)
#define rand31() ((ran() << 16) | (ran() << 1) | (ran() & 1))
#define rand32() ((ran() << 17) | (ran() << 2) | (ran() & 3))
#define rand63() (((ll)ran() << 48) | ((ll)ran() << 33) | ((ll)ran() << 18) | ((ll)ran() << 3) | ((ll)ran() & 7))
#define rand64() (((ll)ran() << 49) | ((ll)ran() << 34) | ((ll)ran() << 19) | ((ll)ran() << 4) | ((ll)ran() & 15))
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define UB upper_bound
#define LB lower_bound
#define X real()
#define Y imag()
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<ld> point;
 
int t;
ll cnt[26];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    F0R(test, t) {
        string s;
        cin >> s;
        F0R(i, 26) cnt[i] = 0;
        for(const char c : s) cnt[c - 'a']++;
        cout << min(min(cnt['r' - 'a'], cnt['u' - 'a']), min(cnt['b' - 'a'], cnt['y' - 'a'])) << endl;
    }
    return 0;
}

7).
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int a[26]={0};
        for(int i=0;i<str.length();i++)
        {
            a[str[i]-97]++;
        }
        int k=100;
        for(int i=0;i<26;i++)
        {
            if(i==24||i==1||i==17||i==20)
            {
                if(a[i]<k)
                {
                    k=a[i];
                }
            }
        }
        cout<<k<<"\n";
    }
    return 0;
}

C#:
1).
using System; 
class MyClass {
    static void Main(string[] args) {
        int cases = int.Parse(Console.ReadLine());
            char[] arr;
            int[] temp;
            int len,i;
            while ((cases--) > 0)
            {
                temp = new int[4];
                arr = Console.ReadLine().ToCharArray();
                len = arr.Length;
                for (i = 0; i < len; i++)
                {
                    if (arr[i] == 'r')
                        temp[0]++;
                    else if (arr[i] == 'u')
                        temp[1]++;
                    else if (arr[i] == 'b')
                        temp[2]++;
                    else if (arr[i] == 'y')
                        temp[3]++;
                }
                Console.WriteLine(Math.Min(Math.Min(temp[0], temp[1]), Math.Min(temp[2], temp[3])));
            }
    }
}
2).
using System; 
class MyClass {
    static void Main(string[] args) {
        
        // Read input from stdin and provide input before running
        //var line1 = System.Console.ReadLine().Trim();
        //var N = Int32.Parse(line1);
        //for (var i = 0; i < N; i++) {
        //    System.Console.WriteLine("hello world");
        //}
        //System.Console.WriteLine("Hello World!\n");
        
        int noOfTestCases =Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < noOfTestCases; i++)
            {
                string str = Console.ReadLine();
                int r=0, u=0, b=0, y=0;
                for (int j = 0; j < str.Length; j++)
                {
                    if (str[j] == 'r')
                        r++;
                    else if (str[j] == 'u')
                        u++;
                    else if (str[j] == 'b')
                        b++;
                    else if (str[j] == 'y')
                        y++;
                }
                if (r <= u)
                {
                    if (r <= b)
                    {
                        if (r <= y)
                            Console.WriteLine(r);
                        else
                            Console.WriteLine(y);
                    }
                    else
                    {
                        if (b <= y)
                            Console.WriteLine(b);
                        else
                            Console.WriteLine(y);
                    }
                }
                else
                {
                    if (u <= b)
                    {
                        if (u <= y)
                            Console.WriteLine(u);
                        else
                            Console.WriteLine(y);
                    }
                    else
                    {
                        if (b <= y)
                            Console.WriteLine(b);
                        else
                            Console.WriteLine(y);
                    }
                }
            }
            Console.ReadLine();
    }
}

3).
using System;
using System.Text;
namespace mahi
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            StringBuilder sb = new StringBuilder();
            while (n-- > 0)
            {
                string s = Console.ReadLine();
                int[] arr = new int[4];
                for (int i = 0; i < s.Length; i++)
                {
                    switch (s[i])
                    {
                        case 'r':
                            {
                                arr[0]++;
                                break;
                            }
 
                        case 'u':
                            {
                                arr[1]++;
                                break;
                            }
                        case 'b':
                            {
                                arr[2]++;
                                break;
                            }
                        case 'y':
                            {
                                arr[3]++;
                                break;
                            }
                    }
                }
                Array.Sort(arr);
                sb.Append(arr[0] + "\n");
            }
            Console.Write(sb);
        }
    }
}
4).
using System;
using System.Collections;
using System.Linq;
using System.Numerics;
 
namespace Codechef
{
    class Program
    {
        static int Main(string[] args)
        {
 
            int inttotal;
            string[] arr;
            int[] arrcount;
            try
            {
                inttotal = Convert.ToInt32(Console.ReadLine());
                arr = new string[inttotal];
                for (int i = 0; i < inttotal; i++)
                {
                    arr[i] = Console.ReadLine();
 
                }
                foreach (string str in arr)
                {
                    arrcount = new int[4];
                    arrcount[0] = str.Count(x => x == 'r');
                    arrcount[1] = str.Count(x => x == 'u');
                    arrcount[2] = str.Count(x => x == 'b');
                    arrcount[3] = str.Count(x => x == 'y');
                    Console.WriteLine(arrcount.Min());
                }
                Console.ReadLine();
            }
            catch (Exception ex)
            {
                throw ex;
            }
            return 0;
        }
    }
}

5).
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace ConsoleApp7
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = Convert.ToInt32(Console.ReadLine());
            string[] arr = new string[x];
            for(int i =0;i<x;i++)
            {
                arr[i] = Console.ReadLine();
            }
            for(int j=0;j<x;j++)
            {
                string z = arr[j];
                int[] a = new int[4];
                 a[0]= z.Count(t=>t=='r');
                 a[1] = z.Count(t => t == 'u');
                 a[2] = z.Count(t => t == 'b');
                 a[3] = z.Count(t => t == 'y');
                int c = a.Min();
                Console.WriteLine(c);
            }
            Console.ReadKey();
        }
    }
}


JavaScript(Node.js):
1).
function main(input) {
    var lines = input.split('\n');
    var num = +lines[0];
    for(var i = 1; i<=num; i++) {
        var line = lines[i].split('');
        print(find(line));
    }
}
 
function find(line) {
    var r = 0;
    var u = 0;
    var b = 0;
    var y = 0;
    
    for (var i = 0; i< line.length; i++) {
        switch (line[i]) {
            case 'r':
                r++;
            break;
            case 'u':
                u++;
            break;
            case 'b':
                b++;
            break;
            case 'y':
                y++;
            break;
        }
    }
    
    var arr = [r,u,b,y];
    arr.sort();
    return arr[0];
}
function print(str) {
    return process.stdout.write(str + '\n');
}
 
Array.prototype.inArray = function(element) {
    for(var i = 0; i< this.length; i++) {
        if(this[i] === element) return true;
    }
    return false;
}
 
Array.prototype.forEach = function(func) {
    for(var i = 0; i< this.length; i++) {
        func(this[i]);
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
    // input
    var res=[];
    input=input.split(/\r?\n/);
    var t=parseInt(input.shift());
    for(var i=0;i<t;i++){
        
        var arr={'r':0,'u':0,'b':0,'y':0};
        
        for(var j=0;j<input[i].length;j++){
            if(arr.hasOwnProperty(input[i][j])){
                arr[input[i][j]]++;
            }
        }
        
        var counts=[];
        for(var j in arr){
            counts.push(arr[j]);
        }
        res.push(Math.min.apply(null,counts));
    }
    
    process.stdout.write(res.join("\n"));
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
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});
 
process.stdin.on("end", function () {
   main(stdin_input);
});
 
function parseRubyText(string) {
    let r = 0
    let u = 0
    let b = 0
    let y = 0
    
    const splitString = string.split('')
    splitString.map((c)=> {
        switch(c) {
            case 'r':
                r = r + 1
                break
            case 'u':
                u = u + 1
                break
            case 'b':
                b = b + 1
                break
            case 'y':
                y = y + 1
                break
            default:
                
        }
    })
    if ( r === u && u === b && b === y ) {
        return r
    } else if ( r === 0 || u === 0 || b === 0 || y === 0) {
        return 0
    } else {
        return Math.min(...[r,u,b,y])
    }
}
 
function main(input) {
 const inputStrings = input.split('\n')
 const numberOfCases = inputStrings[0]
 
 inputStrings.map((string, i)=> {
     if ( i === 0 ) return
     
    console.log(parseRubyText(string))
 })
}


JavaScript(Rhino):
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);					// Reading input from STDIN
 
var testcases = sc.nextLine();	
 var str;
 
for(let i=0;i<testcases;i++){
    str = sc.next();
    check();
}
 
//remove after check
function check(){  
    let map=[];
    let count=[0,0,0,0];
    let str2 = str.split("");
    for(let i=0;i<str2.length;i++){
        if(str2[i]=="r"){
            count[0]++;
        }
        if(str2[i]=="u"){
            count[1]++;
        }
        if(str2[i]=="b"){
            count[2]++;
        }
        if(str2[i]=="y"){
            count[3]++;
        }
    }
    
    let m = count.sort();
    
    System.out.println(m[0].toFixed());
}

Java:
import java.util.*;
import java.lang.*;
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
class TestClass {
    public static void main(String args[] ) throws Exception {
        //Sample code to perform I/O:
        //Use either of these methods for input
 
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        //
        //Scanner
        //Scanner s = new Scanner(System.in);
        //String name = s.nextLine();                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        // Write your code here

        Scanner sc = new Scanner(System.in);
        int testCaseCount = Integer.parseInt(sc.nextLine());
        while(testCaseCount > 0){
            String inputStr = sc.nextLine();
            int rCount = 0;
            int uCount = 0;
            int bCount = 0;
            int yCount = 0;
            
            for(int i = 0; i < inputStr.length(); i++){
                if(inputStr.charAt(i) == 'r'){
                    rCount++;
                }
                if(inputStr.charAt(i) == 'u'){
                    uCount++;
                }
                if(inputStr.charAt(i) == 'b'){
                    bCount++;
                }
                if(inputStr.charAt(i) == 'y'){
                    yCount++;
                }
            }
            System.out.println(Math.min(Math.min(rCount, uCount), Math.min(bCount, yCount)));
            testCaseCount--;
        }
    }
}
2).
import java.util.*;
import java.lang.*;
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
class TestClass {
    public static void main(String args[] ) throws Exception {
        // Sample code to perform I/O:
        //Use either of these methods for input
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        //Scanner
        //Scanner s = new Scanner(System.in);
        //String name = s.nextLine();                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        // Write your code here
        Scanner sc = new Scanner(System.in);
        int testCaseCount = Integer.parseInt(sc.nextLine());
        while(testCaseCount > 0){
            String inputStr = sc.nextLine();
            int rCount = 0;
            int uCount = 0;
            int bCount = 0;
            int yCount = 0;
            for(int i = 0; i < inputStr.length(); i++){
                if(inputStr.charAt(i) == 'r'){
                    rCount++;
                }
                if(inputStr.charAt(i) == 'u'){
                    uCount++;
                }
                if(inputStr.charAt(i) == 'b'){
                    bCount++;
                }
                if(inputStr.charAt(i) == 'y'){
                    yCount++;
                }
            }
            System.out.println(Math.min(Math.min(rCount, uCount), Math.min(bCount, yCount)));
           
            testCaseCount--;
        }
    }
}

3).
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer; 
import java.util.concurrent.*; 
import java.util.Collections; 

class TestClass {
    public static void print(String x)
   {
        ConcurrentHashMap<Character, Integer> m =  new ConcurrentHashMap<Character, Integer>();
            char[] strArray = x.toCharArray(); 
	m.put('r',0);
	m.put('u',0);
    m.put('b',0);
    m.put('y',0);
        
        for (char c : strArray) { 
            if (m.containsKey(c)) { 
  
                m.put(c, m.get(c) + 1); 
            } 
            
 
        }
     int min=Collections.min(m.values());
 
     System.out.println(min);
        
   }  
    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()); 
        while(n-->0){
            String a=br.readLine();
            print(a);
        }
    }
}

4).
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        // Sample code to perform I/O:
        // Use either of these methods for input
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        //Scanner
        //Scanner s = new Scanner(System.in);
        //String name = s.nextLine();                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        // Write your code here
        
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
 
        int t = Integer.parseInt(br.readLine());
        while (t > 0) {
            String s = br.readLine();
            int r = 0, u = 0, b = 0, y = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == 'r') {
                    r = r + 1;
                } else if (s.charAt(i) == 'u') {
                    u = u + 1;
                } else if (s.charAt(i) == 'b') {
                    b = b + 1;
                } else if (s.charAt(i) == 'y') {
                    y = y + 1;
                }
            }
            System.out.println(min(min(r,b),min(u,y)));
            t--;
        }
    }
    private static int min(int a,int b)
    {
        return a<b?a:b;
    }
}

5).
import java.util.Scanner;
class Test
{
    public static void main(String ar[])
    {
        Scanner in=new Scanner(System.in);
        int r=0,u=0,b=0,y=0;
        int n=in.nextInt();
        for(int i=0;i<n;i++)
        {
            String s=in.next();
            for(int j=0;j<s.length();j++)
            {
                switch(s.charAt(j))
                {
                    case 'r':r++;
                    break;
                    case 'u':u++;
                    break;
                    case 'b':b++;
                    break;
                    case 'y':y++;
                    break;
                }
            }
       int     min=r;
            if(min>u)
            {
                min=u;
            }
            if(min>b)
            {
                min=b;
            }
             if(min>y)
             {
                 min=y;
             }
             System.out.println(min);
             r=0;
             u=0;
             b=0;
             y=0;
        }
    }
}

6).
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
import java.util.*;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
      
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());                // Reading input from STDIN
        
        String str;
        
        int[] a ;
        
        int[] ans = new int[t];
        for(int i=0;i<t;i++){
            str= br.readLine().trim();
            a = new int[4];
            for(int j=0;j<str.length(); j++){
                if(str.charAt(j)=='r')
                a[0]++;
                  if(str.charAt(j)=='u')
                   a[1]++;
                    if(str.charAt(j)=='b')
                     a[2]++;
                      if(str.charAt(j)=='y')
                       a[3]++;
            }
            
            int min = a[0];
            
            if(a[1] < a[0])
                min = a[1];
            if(a[2]<min)
                min = a[2];
            if(a[3]<min)
                min = a[3];
            
            ans[i] = min ;
            
        }

         for(int i=0;i<t;i++){
            System.out.println(ans[i]);
             
         }
    }
}

7).
import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
public class RubyJewels {
 
	public static void main(String[] args) throws IOException {
		Scan sc = new Scan();
		Print pr = new Print();
		int t = sc.scanInt();
		while (t-- != 0) {
			int count = 0;
			int arr[] = new int[4];
			char cc[] = sc.scanString().toCharArray();
			for (char c : cc) {
				switch (c) {
				case 'r':
					arr[0]++;
					break;
				case 'u':
					arr[1]++;
					break;
				case 'b':
					arr[2]++;
					break;
				case 'y':
					arr[3]++;
					break;
				default:
					break;
				}
			}
			count = Math
					.min(Math.min(arr[0], arr[1]), Math.min(arr[2], arr[3]));
			pr.println(count);
 
		}
		sc.close();
		pr.close();
 
	}
 
}
 
class Print {
	private final BufferedWriter bw;
	public Print() {
		this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
	}
	public void print(Object object) throws IOException {
		bw.append("" + object);
	}
	public void println(Object object) throws IOException {
		print(object);
		bw.append("\n");
	}
	public void close() throws IOException {
		bw.close();
	}
}
 
class Scan {
	private byte[] buf = new byte[1024];
	private int index;
	private InputStream in;
	private int total;
 
	public Scan() {
		in = System.in;
	}
 
	public int scan() throws IOException {
		if (total < 0)
			throw new InputMismatchException();
		if (index >= total) {
			index = 0;
			total = in.read(buf);
			if (total <= 0)
				return -1;
		}
		return buf[index++];
	}
 
	public int scanInt() throws IOException {
		int integer = 0;
		int n = scan();
		while (isWhiteSpace(n))
			n = scan();
		int neg = 1;
		if (n == '-') {
			neg = -1;
			n = scan();
		}
		while (!isWhiteSpace(n)) {
			if (n >= '0' && n <= '9') {
				integer *= 10;
				integer += n - '0';
				n = scan();
			} else
				throw new InputMismatchException();
		}
		return neg * integer;
	}
 
	public long scanLong() throws IOException {
		long integer = 0;
		int n = scan();
		while (isWhiteSpace(n))
			n = scan();
		int neg = 1;
		if (n == '-') {
			neg = -1;
			n = scan();
		}
		while (!isWhiteSpace(n)) {
			if (n >= '0' && n <= '9') {
				integer *= 10;
				integer += n - '0';
				n = scan();
			} else
				throw new InputMismatchException();
		}
		return neg * integer;
	}
 
	public double scanDouble() throws IOException {
		double doub = 0;
		int n = scan();
		while (isWhiteSpace(n))
			n = scan();
		int neg = 1;
		if (n == '-') {
			neg = -1;
			n = scan();
		}
		while (!isWhiteSpace(n) && n != '.') {
			if (n >= '0' && n <= '9') {
				doub *= 10;
				doub += n - '0';
				n = scan();
			} else
				throw new InputMismatchException();
		}
		if (n == '.') {
			n = scan();
			double temp = 1;
			while (!isWhiteSpace(n)) {
				if (n >= '0' && n <= '9') {
					temp /= 10;
					doub += (n - '0') * temp;
					n = scan();
				} else
					throw new InputMismatchException();
			}
		}
		return doub * neg;
	}
 
	public String scanString() throws IOException {
		StringBuilder sb = new StringBuilder();
		int n = scan();
		while (isWhiteSpace(n))
			n = scan();
		while (!isWhiteSpace(n)) {
			sb.append((char) n);
			n = scan();
		}
		return sb.toString();
	}
	
	public String scanStringWithSpaces() throws IOException {
		StringBuilder sb = new StringBuilder();
		int n = scan();
		while (isWhiteSpaceWithoutSpace(n))
			n = scan();
		while (!isWhiteSpaceWithoutSpace(n)) {
			sb.append((char) n);
			n = scan();
		}
		return sb.toString();
	}
	
	private boolean isWhiteSpaceWithoutSpace(int n) {
		if (n == '\n' || n == '\r' || n == '\t' || n == -1)
			return true;
		return false;
	}
 
	private boolean isWhiteSpace(int n) {
		if (n == ' ' || n == '\n' || n == '\r' || n == '\t' || n == -1)
			return true;
		return false;
	}
 
	public void close() {
		if (in != null)
			try {
				in.close();
			} catch (IOException e) {
 
			}
	}
}

8).
import java.util.*;
class TestClass 
{
    public static void main(String args[] ) throws Exception 
    {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
 
        for (int j = 0; j < t; j++)
        {
            String s = sc.nextLine();
            int a=0,f=0,c=0,d=0,g=0;
            for (int i =0 ; i< s.length();i++)
            {
                char b = s.charAt(i);
                if(b=='r')
                a++;
                if(b=='u')
                f++;
                if(b=='b')
                c++;
                if(b=='y')
                d++;
            }
           
            if(a>=1&&f>=1&&c>=1&&d>=1)
            {
                
               g =Math.min(a,Math.min(f,Math.min(c,d))); 
               System.out.println(g);
            }
            else
            System.out.println("0");
        }
        
 
       
    }
}

9).
import java.util.Scanner;
 
class Wel {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        String text;
        int r,u,b,y;
        int i,min;
        while (t-- > 0) {
            r=0;u=0;b=0;y=0;
            text = in.next();
            for (i=0;i<text.length();i++) {
                if (text.charAt(i)=='r')
                    r++;
                if (text.charAt(i)=='u')
                    u++;
                if (text.charAt(i)=='b')
                    b++;
                if (text.charAt(i)=='y')
                    y++;
            }
            min = Math.min(r,u);
            min = Math.min(min,b);
            min = Math.min(min,y);
            System.out.println(min);
        }
    }
}

10).
import java.util.*;
public class hackerearth1 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
            String s=sc.next();
            int[] a=new int[4];
            int i=0;
            for(i=0;i<s.length();i++)
            {
                char ch=s.charAt(i);
                if(ch=='r')
                    a[0]++;
                else if(ch=='u')
                    a[1]++;
                else if(ch=='b')
                    a[2]++;
                else if(ch=='y')
                    a[3]++;
            }
            int ans=minimum(a);
            System.out.println(ans);
        }
    }
    static int minimum(int[] a){
        int min=Integer.MAX_VALUE;
        for(int i=0;i<a.length;i++)
        {
            if(a[i]<min)
                min=a[i];
        }
        return min;
    }
    
}

Java 8:
1).
import java.io.*;
import java.util.*;
 
class TestClass {
    public static void main(String args[]) throws Exception {
        InputReader in = new InputReader(System.in);
        OutputWriter out = new OutputWriter(System.out);
        StringBuilder sb = new StringBuilder();
        int T = in.readInt(),n,l;
        String s;
        int[] count;
        for (int test = 0; test < T; test++) {
            s = in.readString();
            l = s.length();
            count = new int[4];
            for (int i = 0; i < l; i++) {
                switch (s.charAt(i)){
                    case 'r':
                        count[0]++;
                        break;
                    case 'u':
                        count[1]++;
                        break;
                    case 'b':
                        count[2]++;
                        break;
                    case 'y':
                        count[3]++;
                        break;
                }
            }
            n = Integer.MAX_VALUE;
            for (int i = 0; i < 4; i++) {
                if(count[i]<n)
                    n=count[i];
            }
            sb.append(n).append("\n");
        }
        out.print(sb.toString());
        out.flush();
        out.close();
    }
}
 
class InputReader {
 
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;
 
    public InputReader(InputStream stream) {
        this.stream = stream;
    }
 
    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }
 
    public int readInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }
 
 
    public long readLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        long sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }
 
    public String readLine() {
        int c = read();
        StringBuilder res = new StringBuilder();
        while (!isNewLineChar(c)) {
            res.appendCodePoint(c);
            c = read();
        }
        return res.toString();
    }
 
    private boolean isNewLineChar(int c) {
        return c == '\n';
    }
 
    public String readString() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }
 
    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
 
    public String next() {
        return readString();
    }
 
    public interface SpaceCharFilter {
        boolean isSpaceChar(int ch);
    }
}
 
class OutputWriter {
    private final PrintWriter writer;
 
    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }
 
    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }
 
    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }
 
    public void printLine(Object... objects) {
        print(objects);
        writer.println();
        this.flush();
    }
 
    public void close() {
        writer.close();
    }
 
    public void flush() {
        writer.flush();
    }
 
    public void println(Object... objects) {
        print(objects);
        writer.println();
        this.flush();
    }
}
 
class IOUtils {
 
    public static int[] readIntArray(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
    }
 
    public static int[] readIntArray(InputReader in, int size, long[] counts) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = in.readInt();
            if (array[i] % 2 == 0)
                counts[0]++;
            else
                counts[1]++;
        }
        return array;
    }
 
}

2).
import java.io.*;
import java.util.*;
class NewClass {
    public static void main(String args[]) throws Exception {
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        while(n!=0){
            int[] a = new int[127];
            String s = br.readLine();
            char[] b  = s.toCharArray();
            for(int i=0;i<b.length;i++){
                a[(int)b[i]]++;
            }
            System.out.println(Math.min(Math.min(Math.min(a[114],a[117]),a[98]),a[121]));
            n--;
        }
    }
}

3).
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
 


//@author Pulkit

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
    int r[]=new int[100];
   ArrayList<Integer> aa=new ArrayList<Integer>();
    StringBuilder anse=new StringBuilder();
    int T=s.PulkitInt();
    while(T!=0)
    {
        
       String in=s.next();
       for(int i=0;i<in.length();i++)
       {
       r[in.charAt(i)-'a']++;
       }
       aa.add(r['r'-'a']);
       aa.add(r['u'-'a']);aa.add(r['b'-'a']);
       
       aa.add(r['y'-'a']);
       
       Collections.sort(aa);
       anse.append(aa.get(0)+"\n");
       aa.clear();
       r['r'-'a']=0;
              r['u'-'a']=0;
                     r['b'-'a']=0;
                     r['y'-'a']=0;
    T--;
    }
        System.out.println(anse);
        }
    
    
}

4).
import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
 
import static java.lang.Math.*;
 
public class Sol {
 
    static long mod = 1000000007;
    
    public static void main(String args[]) throws Exception {
        //Scanner in;
        InputReader in;
        PrintWriter w;
        boolean online = false;
        String fileName = "input";
 
        if (online) {
            //in=new Scanner(new File(fileName + ".in"));
            in = new InputReader(new FileInputStream(new File(fileName + ".in")));
            w = new PrintWriter(new FileWriter("out.txt"));
        } else {
            //in=new Scanner(System.in);
            in = new InputReader(System.in);
            w = new PrintWriter(System.out);
        }
 
        int T = in.nextInt();
        //in.nextLine();
        //int T = 1;
 
        for (int t = 1; t <= T; t++) {
            String s = in.next();
            
            int f[] = new int[26];
            for(int i=0;i<s.length();i++) f[s.charAt(i) - 'a']++;
            
            w.println(min(f['r' - 'a'], min(f['u' - 'a'], min(f['b' - 'a'], f['y' - 'a']))));
        }
        
        w.close();
    }
    
    static class compare implements Comparator<pair>
    {
        @Override
        public int compare(pair P, pair p)
        {
            if(P.a != p.a) return (P.a - p.a);
            if(P.b != p.b) return (P.b - p.b);
            if(P.c != p.c) return (P.c - p.c);
            else return P.d - p.d;
        }
    }
    
    static class pair implements Comparable<pair>
    {
        int a,b,c,d;
        
        public pair(int A, int B, int C, int D)
        {
            a=A;
            b=B;
            c=C;
            d=D;
        }
        
        @Override
        public int compareTo(pair p)
        {
            if(this.a != p.a) return (this.a - p.a);
            if(this.b != p.b) return (this.b - p.b);
            if(this.c != p.c) return (this.c - p.c);
            else return this.d - p.d;
        }
        
        // ************  Use only when HashMap / HashSet of pair is taken       *******************
        //@Override
        //public boolean equals(Object p) {
        //    if(p instanceof pair) {
        //        pair P = (pair)p;
        //        return this.s == P.s && this.d == P.d;
        //    }
        //    
        //    return false;
        //}
        //
        //@Override
        //public int hashCode() {
        //    int hash = 7;
        //    hash = 79 * hash + this.d;
        //    //hash = 79 * hash + this.t;
        //    hash = 79 * hash + this.s;
        //    return hash;
        //}
    }
 
    static int arr[];
    static int size[];
 
    static void initialize(int n) {
        for (int i = 0; i <= n; i++) {
            arr[i] = i;
            size[i] = 1;
        }
    }
 
    static int root(int r) {
        while (arr[r] != r) {
            arr[r] = arr[arr[r]];
            r = arr[r];
        }
 
        return r;
    }
 
    static void union(int u, int v) {
        int r1 = root(u);
        int r2 = root(v);
 
        if (r1 != r2) {
            if (size[r1] < size[r2]) {
                arr[r1] = arr[r2];
                size[r2] += size[r1];
            } else {
                arr[r2] = arr[r1];
                size[r1] += size[r2];
            }
        }
    }
 
    private static long gcd(long a, long b) {
        while (b > 0) {
            long temp = b;
            b = a % b; // % is remainder
            a = temp;
        }
        return a;
    }
 
    private static long gcd(long[] input) {
        long result = input[0];
 
        for (int i = 1; i < input.length; i++) {
            result = gcd(result, input[i]);
        }
 
        return result;
    }
 
    private static long lcm(long a, long b) {
        return a * (b / gcd(a, b));
    }
 
    private static long lcm(long[] input) {
        long result = input[0];
 
        for (int i = 1; i < input.length; i++) {
            result = lcm(result, input[i]);
        }
 
        return result;
    }
 
    public static void Array_2dsort(Integer[][] a) {
        Arrays.sort(a, new Comparator<Integer[]>() {
            public int compare(Integer[] int1, Integer[] int2) {
                Integer numOfKeys1 = int1[1];       //about which column u want to sort
                Integer numOfKeys2 = int2[1];
                return numOfKeys1.compareTo(numOfKeys2);
            }
        });
    }
 
    static long powmod(long x, long n, long m) {
        if (n == 0) {
            return 1;
        } else if (n % 2 == 0) {
            return powmod(((x % m) * (x % m)) % m, n / 2, m);
        } else if (n % 2 == 1) {
            return (((x % m) * powmod(((x % m) * (x % m)) % m, (n - 1) / 2, m)) % m);
        } else {
            return 0;
        }
    }
 
    static class InputReader {
 
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;
 
        public InputReader(InputStream stream) {
            this.stream = stream;
        }
 
        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
 
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
 
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }
 
        public String nextLine() {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
 
        public int nextInt() {
            int c = read();
 
            while (isSpaceChar(c)) {
                c = read();
            }
 
            int sgn = 1;
 
            if (c == '-') {
                sgn = -1;
                c = read();
            }
 
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
 
            return res * sgn;
        }
 
        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
 
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public double nextDouble() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, nextInt());
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E') {
                        return res * Math.pow(10, nextInt());
                    }
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }
 
        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
 
            return res.toString();
        }
 
        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public String next() {
            return readString();
        }
 
        public interface SpaceCharFilter {
 
            public boolean isSpaceChar(int ch);
        }
 
    }
 
}

5).
import java.util.*;
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        // Sample code to perform I/O:
        // Use either of these methods for input
 
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        //Scanner
        Scanner sc = new Scanner(System.in);
        int n=Integer.parseInt(sc.nextLine());
        while(n-->0){
            String ip=sc.nextLine();
            int []a=new int[4];
            for(int i=0;i<4;i++)a[i]=0;
            for(char c:ip.toCharArray()){
                switch(c){
                    case 'r': a[0]++;break;
                    case 'u': a[1]++;break;
                    case 'b': a[2]++;break;
                    case 'y': a[3]++;break;
                }
            }
            int e=10000;
            for(int j=0;j<4;j++){
                if(e>a[j]){
                    e=a[j];
                }
            }
            System.out.println(e);
        }
 
        
 
        // Write your code here
 
    }
}


6).
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception 
    {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int occr=0;
        int tc=Integer.parseInt(br.readLine());
        char fKey[]={'r','u','b'};
        char yChar='y';
        // char iesChar[]={'i','e','s'};
        String testCases[]=new String[tc];
        for(int lt=0;lt<tc;lt++)
        {
            testCases[lt]=br.readLine();
        }
        for(int lt=0;lt<tc;lt++)
        {
            occr=0;
            String testCase=testCases[lt];
            int r=count(testCase,fKey[0]);
            int u=count(testCase,fKey[1]);
            int b=count(testCase,fKey[2]);
            if(r!=0 && u!=0 && b!=0)
            {
                int rub =r<u?r<b?r:b:u<b?u:b;
                int y=count(testCase,yChar);
            //    int i=count(testCase,iesChar[0]);
            //    int e=count(testCase,iesChar[1]);
            //    int s=count(testCase,iesChar[2]);
            //    int iesy=0,ies=0;
            //if(i!=0 && e!=0 && s!=0)
            //{
            //    ies=i<e?i<s?i:s:e<s?e:s;
            //}
                if(y!=0)
                {
                    occr=rub<y?rub:y;
                }
                
                
            }
            System.out.println(occr);
        }
    }
        public static int count(String s,char c)
        {
            int occ=0;
            for(int i=0;i<s.length();i++)
            {
                if(s.charAt(i)==c)
                occ++;
            }
            return occ;
        }
    
}

PHP:
1).
<?php
 
//Read input from stdin and provide input before running code
 
//fscanf(STDIN, "%s\n", $name);
//echo "Hi, ".$name;

fscanf(STDIN, "%s\n", $input);
for($i=1;$i<=$input;$i++)
{	$r=0; $u=0;$b=0;
	$y = 0;
	fscanf(STDIN, "%s\n", $input2);
	
	//Explode into array
	$Input =str_split($input2);
	foreach($Input as $I)
	{ 
		if($I == "r")
		{
			$r = $r + 1;
		}elseif($I == "u"){
			$u = $u + 1;
		}elseif($I == "b"){
			$b = $b + 1;
		}elseif($I == "y"){
			$y = $y + 1;
		}
	}
	
	if($r !=0 && $u !=0 && $b != 0 && $y != 0)
	{
		echo(min($r, $u, $b, $y)) ;
		
	}else{
		echo("0");
		
	}
	echo("\n");
}
 
 
?>

2).
<?php
 
$tc=(int)fgets(STDIN);
while($tc--){
$str=fgets(STDIN);
$r=substr_count($str,'r');
$u=substr_count($str,'u');
$b=substr_count($str,'b');
$y=substr_count($str,'y');
if($r== 0 || $u == 0 || $b == 0 || $y ==0){
	echo "0\n";
}
else{
	$arr=array();
	array_push($arr,$r,$u,$b,$y);
	sort($arr);
	echo $arr[0]."\n";
	
}
}
 
 
?>

3).
<?php
$cases = fscanf(STDIN, "%s");
	while($cases[0]) {
		$string = fscanf(STDIN, "%s");
		$string_array = str_split($string[0]);
		$letter_counts = array_count_values($string_array);
		if(isset($letter_counts['r']))
			$r = $letter_counts['r'];
		else
			$r = 0;
		if(isset($letter_counts['u']))
			$u = $letter_counts['u'];
		else
			$u = 0;
		if(isset($letter_counts['b']))
			$b = $letter_counts['b'];
		else
			$b = 0;
		if(isset($letter_counts['y']))
			$y = $letter_counts['y'];
		else
			$y = 0;
		$min = 25; //max length of string is 100
		if($r!=0 && $u!=0 && $b!=0 && $y!= 0)
			echo(min($r, $u, $b, $y));
		else
			echo "0";
		echo "\n";
		$cases[0]--;
	}
?>

Pascal:
Program HiHere;
VAR t,i,j,r,u,b,y,min:int64; s:array[1..101] of string; s2:string;
Begin
Readln(t);
for i:=1 to t do
Begin
Readln(s[i]);
end;
for i:=1 to t do
Begin
r:=0;
u:=0;
b:=0;
y:=0;
s2:=s[i];
for j:=1 to length(s[i]) do
Begin
if (s2[j] = 'r') then r:=r +1;
if (s2[j] = 'u') then u:=u + 1;
if (s2[j] = 'b') then b:=b + 1;
if (s2[j] = 'y') then y:=y + 1;
end;
min:=r;
if (u < min) then min:=u;
if (b < min) then min:=b;
if (y < min) then min:=y;
Writeln(min);
end;
Readln;
END.

Perl:
1).
use List::Util qw[min max];
$t=<STDIN>;
 
if($t < 1 || $t>100) {
	exit;
}
	
for($j=0;$j < $t;$j++) {
	$n=<STDIN>;
	if(length($n) < 1 || length($n) > 100)
	{
		exit;
	}
	my $r = $n =~ tr/r/r/;
	my $u = $n =~ tr/u/u/;
	my $b = $n =~ tr/b/b/;
	my $y = $n =~ tr/y/y/;
	
	$min = min($r,$b,$u,$y);
	print "$min\n";	
}

2).
use strict;
use List::Util qw[min max];
 
my $nb = <>;
 
for(my $i = 0; $i < $nb; $i++) {
	my $ruby = <>;
	my $r = ($ruby =~ tr/r//);
	my $u = ($ruby =~ tr/u//);
	my $b = ($ruby =~ tr/b//);
	my $y = ($ruby =~ tr/y//);
	my $val = min($r,$u,$b,$y); 
	print "$val\n";
}

Ruby:
1).
def print_answer(string)
  puts [string.count('r'), string.count('u'), string.count('b'), string.count('y')].min
end
 
number_of_tests = gets.chomp.to_i
problems =  Array.new
number_of_tests.times do
  problems << gets.chomp
end
problems.each do |problem|
  print_answer(problem)
end

2).
T = gets.to_i
 
for t in 1..T
	s = gets
	ruby = [0,0,0,0]
	s.split("").each do |i|
	  case i
		when 'r'
			ruby[0] += 1
		when 'u'
			ruby[1] += 1
		when 'b'
			ruby[2] += 1
		when 'y'
			ruby[3] += 1
		end
 
	end
	puts ruby.min
end

3).
def check(input)
	r = 0
	u = 0
	b = 0
	y = 0
	input.chars.each do |c|
		if c == 'r' 		
			r += 1
		end
		if c == 'u'
			u += 1
		end
		if c == 'b'
			b += 1
		end
		if c == 'y'
			y += 1
		end
	end
	min = r;
	if min > u
		min = u
	end
	if min > b
		min = b;
	end
	if min > y
		min = y
	end
	puts min
	
end
def main
	testcase = gets.chomp.to_i
	testcase.times do
		input = gets.chomp
		check(input)
	end
end
main

Python:
1).
n = int(input())
for i in xrange(n):
	min = 101
	dic = dict()
	dic = {x:0 for x in 'ruby'}
	string = raw_input()
	for s in string:
		if s in dic:
			dic[s] += 1
	for d in dic:
		if dic[d] < min:
			min = dic[d]
	print min
2).
t = int(input())
for i in range(t):
    n = raw_input()
    for j in range(0,len(n)):
            a = n.count('r')
            b = n.count('u')
            c = n.count('b')
            d = n.count('y')
    print(min(a,b,c,d));
3).
from collections import Counter
T = int(raw_input())
for t in range(T):
    s = raw_input()
    c = Counter(s)
    ruby = ['r','u','b','y']
    jewelscount = [c[x] for x in ruby]
    print(min(jewelscount))
4).
T = int(raw_input().strip())
for _ in xrange(T) :
    W = raw_input().strip()
    print min(W.count('r'),W.count('u'),W.count('b'),W.count('y'))

Python 3:
1.0052  33
1.00581 29
1.00842 31
1.00754 31
1.00678 32
1.00698 32
1.0112  1
1.02025 1
1.02267 6
1.02387 10
1.02588 28
1.02773 16
1.03041 27

1).
t=int(input())
for i in range(t):
	n=input()
	for j in range(0,len(n)):
		a1=n.count('r')
		a2=n.count('u')
		a3=n.count('b')
		a4=n.count('y')
	print(min(a1,a2,a3,a4));
2).
def main():
	from collections import Counter
	for _ in range(int(input())):
		string = list(str(input()))
		c = Counter(string)
		test = "ruby"
		min = 100
		for i in test:
			if min > c[i]:
				min = c[i]
		print(min)
		
main()
3).
from collections import Counter
T = int(input())
for _ in range(T):
    letters = Counter(input())
    #print(letters)
    if 'r' in letters.keys() and 'u' in letters.keys() and 'b' in letters.keys() and 'y' in letters.keys():
        print(min(letters['r'], letters['u'], letters['b'], letters['y']))
    else:
        print(0)
4).
t = int(input())
for i in range(t):
    str1 = input()
    r = str1.count("r")
    u = str1.count("u")
    b = str1.count("b")
    y = str1.count("y")
    
    count = 0
    while r>=1 and u>=1 and b>=1 and y>=1:
        count += 1
        r -= 1
        u -= 1
        b -= 1
        y -= 1
    print(count)

5).	
for t in range(int(input())):
    s = input()
    d = {'r':0, 'u':0, 'b':0, 'y':0}
    for c in s:
        if c in 'ruby':
            d[c] += 1
    print(min(d.values()))

6).
from collections import Counter
for _ in range(int(input())):
    s = Counter(list(input()))
    
    cnts = {}
    for x in s:
        if x in "ruby":
            cnts[x] = s[x]
    if len(cnts) == 4:
        print(min(cnts.values()))
    else:
        print(0)    


*/

/*Editorial:
This problem basically asks you to calculate how many times we can derive the word "ruby" from the given string.

The flow of the problem is such that it asks the user to input the number of test cases as the first input. 
Then ‘t’ integers follow the number of test cases which was given as input previously.

For every input String we have to calculate the number of " rubies " we can derive.
The basic flow of the program will be as below :

Start
Take in the number of test cases  
While there is a test case remaining to be handled  
    Take in the string in which number of rubies has to be found  
    Initialize the array 'a' with initial values as 0.  
    Read the string till null ( '\0' ) character occurs.
    For every r increment a[0]
    For every u increment a[1]
    For every b increment a[2]
    For every y increment a[3]
    Find the minimum value from the array. 
    Print the minimum value which would be the number of possibilities of deriving "ruby" from input string.  
Stop


Author Solution by Arjit Srivastava
tc = int(raw_input())
while (tc>0):
	tc = tc - 1
	a = raw_input()
	r, u, b, y = a.count('r'), a.count('u'), a.count('b'), a.count('y')
	print min(r, min(u, (min(b, y))))


*/

/*I/O:
In #1:
10
xndttmdfrootikifokpfybngthjtsnimvmunukcnqumvnceqzvoufkeokspjtanjpvcmxdvya
jyohyidkifxmxxxdpwhqxixppuifaamqaajrhcizsznmkuoamjfhrpegjplrdkbqgnqqvxjjp
wlffsgpehqhxlgejtukggjddklaasynluivoyxsskahoyzlehrbankvbgbkdqvcrbopvwaxoo
nugtabsqfxzlmplkeeoibtijitqdmpgqsujdzamtlncgdqjqbjdhetohdxrysjjipmonrybia
thbxpgonprkwnivgnfbsnbczqpsgfewxazeertzyqaingncbztswjdfriayaviekowlssvpye
tqlgavskglombkepgjhsbjueusdvbcjdfmgioxtphousutxohctyfxnehxvspxraaxagzqjxz
lcwulpchzmxnkmfjugamcjbtnyvrfrculrzrjknrasevxgyuduqvxioejtvghcgrvwabxkooy
iehnnnmitnrrbdeyfhjlmtvnsxlmndqkgqgdczztdgarmluexjtmwsaojrfjvnmrxpqclvshb
deghtjddpmopntyowtigfzlbvbweqlsyjkihpccdzbkbrbcrpxhyezuhkguthksxscbpsrbar
bsmyirlheygmzrnbznhbvcnzbsfwdgusjochwaguamqrkjtilvubhmwhiudynzbbhcsxumssb
Out #1:
1
1
2
2
0
1
2
1
2
3

In #2:
33
nvuzibvy
ieyymjehxymrspvxyasqjxwiuagrhsufcublnupnnh
hnviwtmzgdiokriofvptzltswvuoqffate
ystgibmbzfgavtgjzhfiguawmllqlwcpzluiplswcwoyrbmwatakcpofmumtgzfmcyxutlgwllgwseaouuhyedtwjvvxwy
vbowyhcosqcjmxgjlzayqafpoxcwycnvvwvmscdkdpysbbgqmwqlrefdfamhhilnzditqotvq
lkwvgozmhdgryblupyxljakywmhnvmjsuziqndujdezqwhyzkujvyrdsdjbfwabuyrkpmks
bpsbluknqzfwiepezrlrghxszmzqtdfqflelmxpajnjfmv
igqzstorudnfxdwurbkjjcoetgdxhyj
jvchkgcmbul
znaltgpjlhiucdufdazmvmzailcpcriawizlwjexlwgwksomfvelawtfboahtdupzmtamizvyaq
gwwkczozejpguftjocnbrvheiaeapazilpdulxmtxxsaimgiiewzctdpoo
xemuexaxccgldnciytmehvgvtkmsqpoyynxpizpbdeknsuxaevwdeqeqjtbmnmfihhsxmschifgfmqcwoiochymfh
klqckhxhlpwygcpbuegzxyqkirrqqxdushxilzsqbykeevkz
clbyjbliahrmevvesqywxoiqojthrqlrwkyqskxiwfitmwdrpoeywvnxkolbttduflsfctctchgwraydifgnaht
jxlbrllufmgljikhnwtkkzbmiorxdcclpabndybufobjgukmivxxnwjriiwlwvrahxovxyoxcqyobqmobuuynqk
kzblsieebspuyio
sufsfywcjsrrlkezlttxfdnngieubdspiqmafzalfedrunczfqifpmtlcrhbquhefacte
pdolzupupzgcahqwyjfmfrorfwiupvjpmtiqjwadfotfefm
zebjscbkigmfwxquvvr
joypaelxexeseoxywrbhkacmyxrcdzgtsccdgzykihzdbsspqylsolozaabemv
avuyimetyjcburutfvcmnxkdygjhamntgfvfalfotyi
cttnxpnrhzqzrtzlyyxkzcnuwkikbfyzwbasczkebsjowulhrpwcvvbzcegkeusignngumnqfcnteh
qbtddiyujovsfinxnjyeevthvaour
vzql
yvxvxovobkaxejlykyjnluzzcuwkcqtotufvwzxrlfetetcorcuyochulhaozfuvbgwpvauqwhdtzlchfxhbjcuqngr
fsucugtzycywfhzolymcuvjucoqcrewwyylbsvjdnhjvegxnsbrxvgtargymbhbizblzsgqyrfjkx
tsxwrtphnmyymrssgmjdtxxbnngwafjexqmoteadjqccewvwuw
lwhjuuqwcyhvsvcrfezyfkujezvxviwcnaaxtfzwffiiryrsmulhhdytqpgwolo
kipbmqzfvrxbrofsfvxjivdhjaeydjekfpmqoadwnqwplriqtciwzfemyrltowtifqtibypwominifoavhaxnylcggxk
jgyfckyvppgucflvvplyautvtlhkvdfbtugselkjw
tgobkrwrtxuxymtqrugcpteivveznbgdoubllxsgvbn
dqqmuspezis
dfrfbblkllzlayhdetafkdtzsmcuo
Out #2:
0
1
0
1
0
3
0
1
0
1
0
0
2
1
4
0
1
0
0
0
1
3
1
0
3
4
1
0
0
0
1
0
1

In #3:
33
pugaequcigprzbvvqkluidixifznvtsstgygcrdltrcldjcauaaitptnuhopsnplsidqqwrn
tkfhojrhcowhxhkrxoplovzlvzzorrivbetbmuygxy
qiaayordfdbcsdsbdlhvfoxzvdxbiikykbgoodawqdanylwahabuqnlqwarnadd
iyahbamhaznnzeanbvz
gypbhxqfvgsmm
hdghvxnpskvbhkallgaydodsawpadsduesmibect
xbslsmfwpejohmqezfnypppbmxmd
buodftsuokbaypwzfxvobpliwmwpbvqncsn
btogykfegcplsmzkxjtkgqesazjagfdkjgxrxadjsizansjjwrrzatvyldcegbvjxxnboitvmcrmhxjeskqcildizmvxwclmijq
myeudemudchoywnbvxkqhowteqvgpimygztuucexmxqihcsofazrexagnxwctgrjultjbfahi
frrbiniebbxngbxzwlypwgohyxxwrryprspmezwothvincultepohwqvaygzlkswnpryqlqjxacdjatpmtdcrhscbzuo
rlcaadiarviwbrphyxtdgcimrpsmjqj
fyfeikjnciubincykrgltexehdordfajgyitex
bzvczoytxbhtxfckckjdviastrmtuldvygiujwbzfxgkcormzihxbupmiwds
bufiowjqrbxbffarsjqaozxsmkbbtds
jczbmkvjtfhqklnzyvargazdlutqdaugpqspmwlmpzgdqgrgjonteenhrjyebyu
sqdllcqtpvsxhqyhgasdyn
wjwiekuccskdtxf
oukxtfxnyvrvpxwug
tmkjbfmndisnfsuwuizpdcmnmikigemsaoszudmzaatuszcnzzpaffhsrotkwhuvljigilqmtjtyrkrpsdu
vwflfrxpkwmjz
yfqazuszzyf
hwodurutffrvpmhedzausqjuqxhvixxwdxplwidppptzonedphftdtwfjwywhrutfyfnviddtq
iriyscxoaggf
dpyqkibgnpezkvkmgudyybhd
sdxxowmuamfmqq
jrrpvnslkugyioqxegznneejaukvqzpoilxldtuzzcgrjvhf
xhbdbrxbsuzbinxobutfpij
cphbpusyrkrolvbkkjikitayeihdwowyfmxrbxmapeddaiazpdxoxtlwstojwabqvgrndfo
wuzrpot
bevqohzptsgxqgmagtyrgytyidbnhcjkxyewjqdlttpcdktc
niibyjvqvudcjmofaoxkqnhulxcfyzphjqnnmoreprqvxpxfwolb
vabgguzacqesrhdloarnhnpqqzenfuitjopkcqoxpufrlddcmvpsejuhqycanbhbvcajd
Out #3:
1
1
1
0
0
0
0
0
0
2
2
0
1
2
0
2
0
0
0
1
0
0
0
0
0
0
0
0
1
0
0
2
1

In #4:
73
aclnbkbzqtvjvtvxdahhimirlsk
xdcraywfygqxzctmtqsxqmsnbrswwvazwrhgzjo
xwikhrbybfbvmzbildlhjidjhuoukqxxgadscimzfeiwnzhfeaxkgtehfjslrowxyvjbn
yvlhmfqxvhbhnwixluolzwflqsvnoqsgpcgxjrxpanofgnhevk
wpykolkxskhjhryenwliuscqdevoutaknwnjwyaj
aeswrxzrngwdttkwhbcvbcsqxggeezmwenvcpiunnwspxqwcviswpwcrmwczeqjphs
cfurseijdytetkmjezqpcoxpjczcwbiuofmmwujymzmymqkoxuwwumrocjvtsjvjwtid
keoleutiypwiwwjydltxgubwwjggqnihkunktclisgngptmyjgdfcbnmavrkuemax
dagbyqmlsqumvciwgygznkwcntbnxceuzzmyzhzjxdetjbyvbgnooxkpdvyaqzqor
doituzjrgaxxwrancbcqhznzuforxgykwlwjzzmretuqsjipbdlau
jyurliwwwkuwuvcuzamefjkixlrvwkqkqdmxyurhddiatjhksmlityfulmdbivmgcyzu
dqhu
ecmvjgmqppwzcwuibaklpnbjwbiuaoosbzegxwiqhqngoiznebltagwiqzgppajho
oqqfnmlojivkqaoubpzlhzjtwvjhfalerjamotyrskejzesmzlywesfbsmsxdablbyfjuzb
dhclubncbxqmrydpsmnpusfugjdhqdhittfrrmeblwpwgbokerw
bluoqmoqqm
nryvefjyvcnkaaevksmurpfxhhjyselkqrdxfzdgk
purqrgwivcxbqmzlxtytbgbenqrvksdlmokxiblxggawidnwwx
advtvweppjpmntuyqwluckavuylwkfiafszlevcwxkw
pktsvphoihfnmnpktjnamcckdlaygsyzelijdfmquojol
zwncwmjyqy
cwazgoaosbaqmhxxmpiexzjaeklaosdvjepytuwghlqasu
bnhpipyrwooqedobaarj
urqungktvulathsafykjugnsexgyoakvtgru
afbfwowrpvsugndogpycawmrj
tiszppbqmzgkuvfylimbavdoltncaeratctmkpkhpmcwqr
ecwnnfhoaxzggxolaoxekshdrgdznmprrvuobkaumlngiura
zoqsbkibjscyrgrjbwlggwkryhvhiqvekojzel
kxipqgigzfufdohtlpebachqyncmeeayekkqycisiurez
zxygttwljtamtvvpdngcqmobhgsqkahxsuswzcqibhnqreucsewfvfjcxfazox
odmfxchwhzawnqsexnbtgvuufi
vvlyqnuyrxmvvwcbjrpspwygyyfxcor
hvqxejlglo
sorbnoxtfjpykmgdf
omdzspyccpuwzlrxttgaiqlowjqrezdszzosmqiuwbenkln
zkmgoqkgnyrglyoavwmjsnjgo
lenkfyhbzypwycbuqy
bbwtrahjynax
ovfo
idqqlcaajretsvqcixvkcyhyegedtqimssmbzhsbucbgmbsxcqmhhrbvwmehx
asmjmyhxvgiyu
htpvrweyjfmjjvg
monuzknomzzuubaly
zwsqtqalruonhnkvylnwrmgzqxx
ccnqiiuhicdrm
frioaiwivatfajukaatiupzggugznbssk
coijhukfmukjuwgkqsyruqpftdceboujhpucxwlge
qrdfpropixcpqdcmogzqjoyglpdbvrwbfhodpneiokwlrdjjjnwmznqwxfnqphskdiqadwv
rsmlscg
gjkvpsbeptvvxxtlmidrqhwlazgnjcaublufbpwajwzogkx
gakvrvcljswtzwoxvhpunkzkjaizgrbanenosbetqhvgujulyscugxabqufadhdsmrbwijaxo
sfmkpsgvoirckmlchqmhtopgnzwswyynldhhroljokmr
enaigyvbaosudeihrdzcriydhnahqjozojywzwysmyjctwfevwashtbwpxrlj
esnkfncajzqfnfzkuinmypngszrzqj
ahfohhubnpavmtywtxda
jobagzmjjpnfrscduaaoojf
oacrdpfkhnlseatrdkuahojqwojxfvuyekhxupnxdtqykwm
mlzvrbmnbdwezhvkgwuhasfqnupioebefqujgdhcbqkdrmwqwakybhzmxyfrbure
ykcmhnhbxxolywphqfumtdkrxshnmbcebcxtkotekeeeqmkcismirvdqlepdokq
wvftmaakrjfmxqzyomrjoqddlsiggorrlzoiaxbrcd
cvtqtmmiipdoxnrknzwovreszwidxhizsrngsqnvyipljbeqnxusrlgpflzj
wpxchxwpfoglnfkoxboynhydzjgdrfkyshpbdtwuqonwlhnnlazuacxyqskzadtnekth
pdmqeljyinejgnieelvgtrwruwu
jubyrbaqxfaicllwpwxwofhq
qmdcvzrvnhzneuuogmmcadicsnmwhylltglzwsoqeydpvqkraptxpdnyyinzkntphkljhguat
ysmbxpbygrgb
lwzqicndhm
qdvhasxwtmvtrxcdbpdunchpwgoqdmkukjqduieuoryscusmmnsdid
oggoxsbhjt
qptgphruybkzjfkkxwgpyrooknwrbrxcpptgjhfghsjftyvnainqlwg
xgtdeyfkacessjhgvnvsdaaeqqobbllciezxoscdewxhuklcirl
nayagsutpnfrqtzrwnsejxfchonxebzgmzbqhxbkzbobpmqicseuanjxaslwgjqqjwzflz
nocjamty
Out #4:
0
0
2
1
0
0
1
1
1
1
1
0
0
2
1
0
0
1
0
0
0
0
0
0
1
1
0
0
1
1
0
1
0
0
1
0
0
0
0
1
0
0
0
0
0
0
1
0
0
0
1
0
1
0
0
0
0
2
1
0
1
1
0
1
0
0
0
1
0
1
1
1
0

In #5:
73
buinsmxzeboljvgggffvhxiusgwdca
obsdwtsyuozfkswwzkcqnlfocde
jtzirubzgezngmlcvktgylpbhuowhdzwddztlvbliybctzigbeoqxldjahqyssxvdmigcwrvx
yhdsjysuqmhgilhpismihuopulcdfdirblezlclcbvofwsmeegtczkmhuumtyiyolbaey
ugjtmnzzhhggutlpavjcrjqpboqzxtqjybmhmnemruaahkpgbohavaa
cmonworyrwqdleoysbjrllrkejkxnkxqjjyzphticzkteipuqhmxfgrpeihoocinopbela
bzffpofpzmmyuzqynlsibnnfgjvhkbpjaqsdysdnnanvmbsvbqkelrkagpdrdudokwqn
bsfpaejmzswsipjueh
xzxdrjxwqujmvcjybujrjhabbfshizbzelwmukgfsqcumdjffabjjukqzjxhzowqjkoe
rvybqlhozxnxwwfsrvuewvxieefdgnofwmyqnggkxvjhgcjsmxyzpfeg
brqho
yppkepngcxurschxkxsnnicampngvdmcyrjzmsbgm
ehnzqtacfgdznq
lyyugtcgsqxvcmkqahuzsfhwvhlzqwwjntvvtqomxkhpyarh
wlappfidkqqxljzusjwkcalmsisiividemmnkzaxncnhkbsmdq
cavvkqameskurhaczewtrigbfkpbrtczqtszhyagwitzwplrnxppovmienkqtbkqmsdwuxcj
vunraumokojpqrxvajzsnyeenwzygxaytpan
swtcapethwnhufmwvemkgjcwkufpmjvsuxblod
qfrzcfdtwqemj
ktysrjtfgfwermhzo
hnspcflnaicflsiozmwkumyltzqzpsafpivsho
wjxrecwqgyhqxfmoqncvorjfryyoogczmdgydvptyzhpufkpiwyhzcaj
nrzrzftikpmeoxubgdzcgleiccvocvtkdiuajolkjb
muoqikmwbcjz
caxgsviwsulcmmnlbszgyzdoeslkrjqi
wtmwfqqdxbljyanwfeehaupamfjgbn
puf
jhpylbujugccxgr
c
renvcoipihwbu
sonrwbposywyampdvybxqekxwrokufgwgaoxhnmtkzfjrudldkasajrikatlsls
tnkinsvatjtypm
vbdqwkhvviznsqqeennyzuaabczqlhntkvlmbqyjoadsjnae
ovjvhwienpunpokmpytpqpuguevmvtbeamolevijhgvrlxhajzqsubfq
bepipkmbmibmyueoaknugejuqpchgjlykivbpnkoowhzdylhjboqxbjbdzlqghilgx
ibpkedtuitvzphmmaoektedhuvbpwjpcguhpleio
cnak
m
wyksusizonqeruxinzfhasctezhdimsvbohuihznqlgnbrfkesefcadihqzgamyngyhe
fldbszumri
fdqzygavcxdrr
sfuprkdlmcvootlvdhsbjywssgfggyjejzwmg
xsohwwlvjtikmnzoibwpujgoveioqkanwjtdedpjvammks
qyjrhabsmfrsuhrpnbslcecjjwejwhmiqccjhlhhtomqvdciqmtuydjrmgmrh
fatdpktjlanwzsqqhmriwipampgdmv
kbuiwbeojwgwrvcmqyetasxlzsfnzgbobubhlzimodfztpvrcsw
dehwurkyubtxpbuohhcjycwhvelnvl
wamzwlyjeulygrnf
fhdnpsirjqninksck
tdlfnkokvma
qqmjicdcjaohmdhga
dgibvjvttzbsgsncometevjcglkcoayccynxvbdzafgwj
dzp
poxegsfqvizfhdbvsvuykrmjqjnikbgcopgqznhvbmfdsdteum
vunpp
jbrxfvwxjkzrrwszaz
oblrumdjniqjzxvqujwb
jh
tsjnkcamxmwthonjcflsbpjtzojuweghdtr
oofjgvpabixsqlhxffzhyktdfuwjrgxgjfjhgqexiaodmtebplgwlaasqfvebi
dzzjp
cwmdlpalctttcfbuszwbv
fegdhreuretyfujt
evkdborqowrwrulfqjlca
jloaou
yzfo
kcdpcphxtpucepykemhkopewq
uisqkaktuwdnagdblgwvxbjdrcopnbqxzuseinzjteqqpypkeudqvvdchprposirbvlbzs
uqtpavkozgclupfpzfwjbyxipfpeglfggbesjaptuuzraylyshjhfzi
pmlbqpidhqrcpdbbwqzmoapprfuokyivwugfbbmkbltrxogtezrqfyz
deygiacthnmgsrmjgjskmfhzrdudeqyxjtshavmfeurjvbqexzzvvmkbobndbmyaliwndizv
xptjpjvykapzoiilmvtcfpkcohtjycvyujoz
g
Out #5:
0
0
2
1
1
1
2
0
1
1
0
1
0
0
0
1
0
0
0
0
0
0
0
0
1
0
0
1
0
0
2
0
0
1
0
0
0
0
2
0
0
1
0
2
0
1
1
0
0
0
0
0
0
1
0
0
0
0
0
1
0
0
0
0
0
0
0
1
1
2
2
0
0

In #6:
13
xloagfljt
jnol
chniuliance
zzicxuxk
bzjuy
h
vyblorkc
fyk
eraoqn
bnnuwgjjzzg
jgnlmk
fwmhqvhckkd
af
Out #6:
0
0
0
0
0
0
0
0
0
0
0
0
0
In #7:
13
blsujvdqoiodf
jvgjpnkv
epbudwziwbje
pdgjzypv
pl
ywdymble
eupaigzg
xmu
kbhws
sobv
mpqbryvt
mlke
zydtzfoyeu
Out #7:
0
0
0
0
0
0
0
0
0
0
0
0
0

In #8:
13
undo
dbapkimw
dkrsgu
i
rikbiiypakq
mh
buj
xbgqlbkqwaydf
mrmrkr
mmztkjfw
iym
ydrmqzh
kwazhbbkoofxi
Out #8:
0
0
0
0
0
0
0
0
0
0
0
0
0

In #9:
20
dvdebzkwoffjxfnfcagzkhpjzauldhhmgenhpalopkfoxentkviooqrpxxrdugjhuoefkflphwpcwsyk
hrmxugluwtobymclvcvugjcqftqscmqgtmkpstkowyoxcuayhzrukkfbnhwqloirhyupwmnicqfx
wcleawcowwhglpnxwdxxfeeytqipyyfkthrwihbybosevqbggkmyqzmoazbn
jokrzhnypqbzjbesmrmfjzeitwxcamqzkylfmakxnbcbdcwisfckurypisbatqsnamolseazdmeieammutfhzmylqtdgnii
ikgatwttivbcghncdumbsougtwalkcwlvejxtbcpwikhbzamqoaqxxrwfmntawtlgiclalxedawc
nrqvigk
vpuztbpbrghnqrcziluixpolokbkhbolovjldiliikxvgysmmwkpj
ljsndkuavfiiwpmrkhchridrachmbcarbpijpdnurcapeigrsvtrewcsdwt
ggvfbsjrumiczskftkazikltvnoiudzhgudtsr
zvwtyrbpnysrsnxrmnjaabiaunbttzgtkmhiyitnxsekuosnvbsdmzyqqvchzgxqqkxli
jquoutwffzvrcqtm
wdaxrutbehsbndbmgkgxahgiydwbptamrkjdbeufbvkfsyhh
ptqbautjjpennraodpkmiexjmpvkhwdujftwrafawemnypmtonlfivglgozvjbwqxebfedahtteoglquyhsjjrt
nrwqf
iagsycgdgijeyaibdyozikmcitevykojbdljjzzzdwaxgahlwo
vhdlauqzcvxxekewuxdrzjmzbt
ahawxcumbmuezudalvwhdudwkheiraxurnohwxjqyqtcdbqqxdkpcqk
qddavhhuupdcgetahnppprwwxfrimhlumrtrjhola
laqshoegxagsmnsmugbefjiaiiojhtzbfcucqcoeqaeichdirqyruyauzhp
xbzhektcdixxviizskzhoenwawqlu
Out #9:
1
2
0
2
0
0
1
0
0
2
0
2
2
0
0
0
1
0
2
0

In #10:
20
edfnntkatonkggwdjpljxouqkhdliqhwrkdlunkdtcosplwdksgu
ngcmecxsfhmzvzorzfjysiptlxjvqzgpctqoocchzcvjy
ylzdeacrrbnxachtvwbszdgcucyqkifsllctqztza
hrigiirykkhatxslqdvzl
ydzvculfomsofsugfqkarlqhjgyqoxygtfoftkavnvrzmyfepznwtmjlirkusshocirset
hhuaxdljvjopmessohjgzhmyhknbmxnvfrgombszebqnxqtxhitseuinmidgcdtdsyfeyxwlilwphzwfrof
vkflfzyaeqn
f
ommrwmnvmdzrnwuyitwffzevfaipmuuydoujhwasfntgcliocjixfdfjvxbessctjedrltntuensethdnqrhgoiqblpwvgus
cilpmvtwlddgtoskthdebepkqidvbbkajrlcqbnfwpnmhrepllbqzciggspnetlkebnguihjhfgku
jooxsfijxkhicsivkjfeehoqrwxnrcbunumkiqvapixqhtajte
iyfyxqzymqbjioujdwbgheslmlydolaxosstpmzsbvhssecj
rvxtnarrtfavredjhknyttydyekxtk
hlvpqtotppraxlyyfytxhazlykzomflpxwcuq
prxeantbfiwvahnjpdmgucedbmeotdjef
onnomwhdzpeocpuyzjuldngyufzjwjlyssqfjyrytukmnrqsoszbmzmvotshkvhwwgsafpzggmazwdwrauotsgzoug
iojnzmhkzcmkogviesajjvjgejvnfzbggfxjqwyvbkzfrhqwlctjqlseloutnakgzqlyoaalcpdzsfcnge
oamxeoppnrokmnppvotfaakwagncphqewecmdtiffrfcmkmfciwvukjnjggnvxahysnjojvwf
nhvteiwoeowujszzuycaaegmfhp
neuipuevmawskovzpyywwefrjonzbwlyjvhewyoxyrwgblygklaqzqmjpdpmkaseriyeazrskdvgxsjksloozhxzpiv
Out #10:
0
0
1
0
0
2
0
0
2
0
0
0
0
0
0
1
1
0
0
2

*/