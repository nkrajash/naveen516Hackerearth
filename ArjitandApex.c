/* All Tracks -->  Algorithms -->  Greedy Algorithms --> Basics of Greedy Algorithms -->  Problem --> Arjit and Apex
Tag(s): Data Structures, Easy-Medium, Greedy algorithm
Arjit, Protector of The Realm, has an important task at hand. M new subjects are soon going to become a part of The Realm. 
The Realm, though, already has N subjects who are well skilled in the ways of The Realm. He wants the new subjects too to become perfect in the ways.

As any Protector would, Arjit also decides that the existing subjects should train the new subjects in the ways. 
What's so special about this situation though? Each current subject of The Realm has a special skill Sc and he has reached a level of proficiency Pc at this. 
Every new subject of The Realm feels his favorite skill he would like to have is ** Sn** and reach a proficiency ** Pn** at it.

Let's call a current subject Foo and a new subject Bar. Foo can train Bar if Foo's special skill is the same one that Bar feels is his favorite. 
This is what we call a good pair. If Foo's special skill and Bar's favorite skill are the same and also Foo's proficiency is the same that Bar wants to achieve, 
we call it a great combination.

Let A be the number of good pairs and B be the number of great combinations. Arjit would like to maximize the number of new subjects to be trained by current subjects, 
i.e., number of good pairs. And, after maximizing number the number of good pairs, he wishes to maximize the number of great combinations.

Arjit wishes to have at least G good pairs and at least H great combinations.
If only the good pairs criteria is met, print "Good" (without quotes).
If both criterion are met, print "Great" (without quotes).
Else, print ":(" (without quotes).

Input:
The first line of input contains T. T test cases follow.
The first line of each test case has two integers, M and N.
In the following M lines, there are two integers on each line, U and V denoting favorite skill and proficiency they wish to obtain.
In the N lines that follow, there are two integers on each line, W and X denoting the special skill and the level of proficiency that has been reached.
The last line of each test case has two integers, G and H.

Output:
Print "Good", "Great" or ":(" (without quotes) on a new line for each test case.

Constraints:
1<=T<=10
1<=M,N<=10^5
1<=U,V,W,X<=10^4
1<=G,H<=10^5

See the example to understand better.

SAMPLE INPUT 
1
2 2
1 1
2 3
1 1
2 3
2 2
SAMPLE OUTPUT 
Great
Explanation
You have 2 new subjects and 2 current members of the realm.
Each new member is perfectly matched with an existing member of the realm.
So, good pair count is 2 and great combination count is also 2.
So, the output is "Great" (without quotes).

//My Python Solution:
t = int(input())
for _ in range(t):
    m,n = map(int,input().split())
    d = dict()
    new = dict()
    for i in range(m):
        p,q = map(int,input().split())
        d[i] = (p,q)
    for i in range(n):
        p,q = map(int,input().split())
        new[i] = (p,q)
    g,h = map(int,input().split())
    g_c = 0
    h_c=0
    
    i = 0
    j = 0
    while i<len(d):
        while j<len(new):
            if new[j][0]==d[i][0]:
                g_c+=1
                if new[j][1]==d[i][1]:
                    h_c+=1
                
                i+=1
            j+=1
        break
 
    if h_c == h:
        print("Great")
    elif g_c == g:
        print("Good")
    else:
        print(":(")


*/

/*Editorial:
Brief Description:

Given 2 integers N,M.
In the following M lines, there are two integers on each line, U and V denoting
favorite skill and proficiency they wish to obtain.
In the N lines that follow, there are two integers on each line, W and X denoting
the special skill and the level of proficiency that has been reached.
The last line of each test case has two integers, G and H.

Print "Good", "Great" or ":(" (without quotes) on a new line for each test case.

Arjit wishes to have at least G good pairs and at least H great combinations.
If only the good pairs criteria is met, print "Good" (without quotes).
If both criterion are met, print "Great" (without quotes).
Else, print ":(" (without quotes).

Pre-requisites: Implementation Skills, Data Structure Knowledge (Set).

Difficulty Level: Easy - Medium.

Hints: Use Suitable Data Structure (Set) to store Old Subjects Values,
then check for every new subject if there is a corresponding old subject
in the set.

Detailed Editorial:

This Question depends on your Implementation Skills and Data Strcuture Knowledge.

Firstly, you need to check this condition: "after maximizing number the number
of good pairs, he wishes to maximize the number of great combinations."

Actually this condition is tricky because every great combination
is considered as good pair, so the condition is interested only in
"maximize the number of great combinations" only.

So how to maximize the number of great combinations ??

You should first check for great combination, so one good way is
to use suitable data structure (set) to store old (current) subjects,
then loop over the new subject and check for every one if there is
a corresponding old subject with the same pair ( skill,proficiency ).

If there is a one, increase the number of great combinations, number of good pairs
because every great combination is considered good pair.

Note: The reverse isn't right, "Good pair isn't necessary a great combination".

Then mark each used old subject as used.

Now loop over again new subjects (for the remaining new subjects which don't form great combination),
Then check if there is and old subject that has the same Skill (good pair).

Note: Remember to erase all used old subjects from the storing sets.

Now do the check, and compare the number of Great Combinations, Good Pairs with G , H.

Note: The absolute Greedy Solution is Wrong, because you maybe form a good pair
and lose the opportunity to make (Great Combination and Good Pair) at the same time.

For clarity take this example:
1
1 3
1 7
1 2
1 4
1 7
1 1

Here Absolute greedy will form only a good pair between (1 7), (1,2), but
actually the solution should be (1 7), (1 7) forming 1 good pair+1 great combination.

Time Complexity: O(NlogN+ MlogM) .
Note: logN or logM, for inserting and searching in Set.
Memory Space Combination: O(N+M).

Solution in C++:
#include <bits/stdc++.h>

using namespace std;

multiset < pair < int , int > > great;
multiset < int > good;
vector < pair < int , int > > v;
bool finished [100000 + 10];

int main()
{

    int t, n , m, tem1, tem2, g , h;

    cin >> t;

    while(t--){


        good.clear();                           // clear storage for every case
        great.clear();
        v.clear();
        memset(finished, false, sizeof finished);

        cin >> n >> m;

        for(int i = 0; i < m; i++){             // new subjects

            cin >> tem1 >> tem2;
            v.push_back({tem1, tem2});
        }

        for(int j = 0; j < n; j++){

            cin >> tem1 >> tem2;
            great.insert({tem1, tem2});     
            good.insert(tem1);
        }

        cin >> g >> h;

        int numGreat = 0, numGood = 0;

        for(int i = 0; i < m; i++){

            pair < int , int > check = v[i];

            if(great.find(check) != great.end()){       // check if this pair found in the old subjects

                finished[i] = true;                     // mark as selectedto be good pair and great combination
                great.erase(great.find(check));         // erase this old subjects from th set
                good.erase(good.find(v[i].first));

                numGreat++; 
                numGood++;
            }
        }

        for(int i = 0; i < m; i++){

            if(finished[i]) continue;               // we can't choose an old subject more than once

            if(good.find(v[i].first) != good.end()){

                numGood++;
                good.erase(good.find(v[i].first));
            }
        }

        if(numGood >= g && numGreat >= h) cout << "Great\n";
        else if (numGood >= g) cout << "Good\n";
        else cout << ":(\n";
    }


    return 0;
}
Editorialist: Omar Khaled
Author Solution by Tanmay Sahay
#include <bits/stdc++.h>
using namespace std;
void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
const int maxm = 1e5 + 1;
const int maxn = 1e5 + 1;
int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> m >> n;
		multiset<int> bar[maxm], foo[maxn];
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			bar[u].insert(v);
		}
		for (int i = 0; i < n; i++)
		{
			int w, x;
			cin >> w >> x;
			foo[w].insert(x);
		}
		int good = 0, great = 0;
		for (int skill = 1; skill <= maxm; skill++)
		{
			int tmp = 0;
			for (auto proficiency: bar[skill])
				if (foo[skill].count(proficiency))
					tmp++, foo[skill].erase(foo[skill].find(proficiency));
			int t1 = bar[skill].size();
			int t2 = foo[skill].size();
			good += tmp, great += tmp;
			t1 -= tmp;
			good += min(t1, t2);
		}
		int g, h;
		cin >> g >> h;
		if (good >= g and great >= h)
			cout << "Great\n";
		else if (good >= g)
			cout << "Good\n";
		else
			cout << ":(\n";
	}
	return 0;
}
Tester Solution by Aniruddha Sharma
 
// Name:- Aniruddha Sharma
 
// Problem:- Arjit and Apex
 
// Site:- HackerEarth
 
#include<iostream>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<functional>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<assert.h>
using namespace std;
struct realm
{
	int x;
	int y;
}new_subjects[100010],current_subjects[100010];
bool myFunc(struct realm a,struct realm b)
{
	if(a.x<b.x)
		return true;
	else if(a.x==b.x && a.y<b.y)
		return true;
	else 
		return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n,g,h;
		cin>>m>>n;
		assert(m>=1 && m<=100000);
		assert(n>=1 && n<=100000);
		for(int i=0;i<m;i++)
		{
			cin>>new_subjects[i].x>>new_subjects[i].y;
			assert(new_subjects[i].x>=1 && new_subjects[i].x<=10000);
			assert(new_subjects[i].y>=1 && new_subjects[i].y<=10000);	
		}
		for(int i=0;i<n;i++)
		{
			cin>>current_subjects[i].x>>current_subjects[i].y;
			assert(current_subjects[i].x>=1 && current_subjects[i].x<=10000);
			assert(current_subjects[i].y>=1 && current_subjects[i].y<=10000);		
		}
		cin>>g>>h;
		assert(g>=1 && g<=100000);
		assert(h>=1 && h<=100000);
		sort(new_subjects,new_subjects+m,myFunc);
		sort(current_subjects,current_subjects+n,myFunc);
		int i,j,good=0,great=0;
		for(i=0,j=0;i<m &&j<n;)
		{
			if(new_subjects[i].x==current_subjects[j].x)
			{
				if(new_subjects[i].x==current_subjects[j].x && new_subjects[i].y==current_subjects[j].y)
					great++;
				if(new_subjects[i].x==current_subjects[j].x)
					good++;
				j++;	
			}
			else if(new_subjects[i].x>current_subjects[j].x)
			{
				while(new_subjects[i].x>current_subjects[j].x)
					j++;
			}
			i++;
		}	
		if(g==good && h==great)
			cout<<"Great"<<endl;
		else if(g==good)
			cout<<"Good"<<endl;
		else
			cout<<":("<<endl;		
	}
	
	return(0);
}

*/


/* Best Submissions:
C:
#include<stdio.h>
int main()
{
    int t,n,m,u,v,w,x,g,h,i,j,k,p[2][10004],s[2][10004];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            p[0][i]=u;
            p[1][i]=v;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            s[0][i]=u;
            s[1][i]=v;
        }
        scanf("%d %d",&g,&h);
        w=x=0;
        n=n<m?n:m;
        for(i=0;i<n;i++)
        {
            if(p[0][i]==s[0][i])
                w++;
            if(p[1][i]==s[1][i])
                x++;
        }
        if(w==g && x==h)
            printf("Great\n");
        else if(w==g || x==h)
            printf("Good\n");
        else
            printf(":(\n");
    }
 
return 0;
}

C++:
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int M,N;
		scanf("%d%d",&M,&N);
		if(M>N)
			printf(":(\n");
		else{
			vector<int> a,b,c,d;
			int num1,num2;
			for(int i=0;i<M;i++){
				scanf("%d%d",&num1,&num2);
				a.push_back(num1);
				b.push_back(num2);
			}
			for(int j=0;j<N;j++){
				scanf("%d%d",&num1,&num2);
				c.push_back(num1);
				d.push_back(num2);
			}
			int G,H;
			scanf("%d%d",&G,&H);
			for(int p=0;p<M;p++){
				if(binary_search(c.begin(),c.end(),a[p])){G--;
				//a.erase(a.begin()+p);
				}
			}
			for(int q=0;q<M;q++){
				if(binary_search(d.begin(),d.end(),b[q])){H--;
				//b.erase(b.begin()+q);
				}
			}
			if(G<=0 && H<=0)
				printf("Great\n");
			else if(G<=0)
				printf("Good\n");
			else
				printf(":(\n");
		}
	}
	return 0;
}

C++14:
#include <bits/stdc++.h>
using namespace std;
 
struct node
{
    int s;
    int p;
    bool operator<(const struct node & n) const
    {
        if(this->s == n.s) return this->p < n.p;
        return this->s < n.s;
    }
};
 
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int M, N, i;
        int flag1, flag2;
        flag1 = 1;
        flag2 = 1;
        cin >> M >> N;
        map <int, int> mymap1;
        map <struct node, int> mymap2;
        struct node temp1;
        for(i = 0; i < M; i++)
        {
            cin >> temp1.s >> temp1.p;
            mymap1[temp1.s]++;
            mymap2[temp1]++;
        }
        for(i = 0; i < N; i++)
        {
            cin >> temp1.s >> temp1.p;
            if(!flag1) continue;
            if(!mymap1[temp1.s])
            {
                flag1 = 0;
                continue;
            }
            mymap1[temp1.s]--;
            if(!flag2) continue;
            if(!mymap2[temp1])
            {
                flag2 = 0;
                continue;
            }
            mymap2[temp1]--;
        }
        if(!flag1) cout << ":(" << endl;
        else if(!flag2) cout << "Good" << endl;
        else cout << "Great" << endl;
    }
    return 0;
}


C#:
using System;
using System.Numerics;
using System.Collections.Generic;
using System.Linq;
 
class MyClass
{
	public class Subject
	{
		public int Prof { get; set; }
		public string Status { get; set; }
	}
 
	static void Main(string[] args)
	{
 
		var line1 = System.Console.ReadLine().Trim();
		var testCases = Int32.Parse(line1);
		for (var i = 0; i < testCases; i++)
		{
			var subjects = System.Console.ReadLine().Trim().Split(' ');
			var newSubjects = Int32.Parse(subjects[0]);
			var existingSubjects = Int32.Parse(subjects[1]);
			var desired = new List<KeyValuePair<int, int>>();
			var existing = new Dictionary<int,List<Subject>>();
			for (int j = 0; j < newSubjects; j++)
			{
				var skillInput = System.Console.ReadLine().Trim().Split(' ');
				var skill = Int32.Parse(skillInput[0]);
				var proficiency = Int32.Parse(skillInput[1]);
				desired.Add(new KeyValuePair<int, int>(skill, proficiency));
			}
			for (int j = 0; j < existingSubjects; j++)
			{
				var skillInput = System.Console.ReadLine().Trim().Split(' ');
				var skill = Int32.Parse(skillInput[0]);
				var proficiency = Int32.Parse(skillInput[1]);
 
				if (existing.ContainsKey(skill))
					existing[skill].Add(new Subject() { Prof = proficiency,Status = "None" });
				else existing.Add(skill, new List<Subject> { new Subject() { Prof = proficiency, Status = "None" } });
			}
 
			var expectedResult = System.Console.ReadLine().Trim().Split(' ');
			var goodPair = Int32.Parse(expectedResult[0]);
			var greatCombination = Int32.Parse(expectedResult[1]);
			var goodCount = 0;
			var greatCount = 0;
 
			foreach (var des in desired.OrderByDescending(x => x.Value))
			{
				var skill = des.Key;
				var prof = des.Value;
				var subjectsList = existing.ContainsKey(skill) ? existing[skill] : null;
				if (subjectsList != null)
				{
					var great = subjectsList.FirstOrDefault(x=>x.Prof == prof && x.Status != "Great");
					if (great != null)
					{
						greatCount++;
						if (great.Status == "Good")
						{
							var replace = subjectsList.FirstOrDefault(x => x.Status == "None");
							if (replace != null)
								replace.Status = "Good";
							else goodCount--;
						}
						great.Status = "Great";
					}
					else
					{
						var replace = subjectsList.FirstOrDefault(x => x.Status == "None");
						if (replace != null)
						{
							goodCount++;
							replace.Status = "Good"; 
						}
					}
				}
			}
 
			if (greatCombination == greatCount)
				Console.WriteLine("Great");
			else if (goodPair == goodCount)
				Console.WriteLine("Good");
			else
				Console.WriteLine(":(");
		}
	}
}


Java:
import java.io.*;
import java.util.*;
 
class ArjitAndApex
{
    public static void main(String args[] ) throws Exception 
    {
        int T = Fio.fin.readInt();
        while(T-->0)
        {
        	
        	int M = Fio.fin.readInt();
        	int N = Fio.fin.readInt();
        	HashMap<Long,LinkedList<Long>> hm = new HashMap(M);
        	
        	while(M-->0)
        	{
        		
        		long U = Fio.fin.readLong();
        		long V = Fio.fin.readLong();
        		//Fio.fout.println(U+" "+V);
        		if(hm.containsKey(U))
        		{
        			hm.get(U).add(V);
        		}
        		else
        		{
        			LinkedList l = new LinkedList<Long>();
        			l.add(V);
        			hm.put(U,l);
        		}
        	}
        	
        	int good=0;
        	int great=0;
        	while(N-->0)
        	{
        		long W = Fio.fin.readLong();
        		long X = Fio.fin.readLong();
        		if(hm.containsKey(W))
        		{
        			//good++;
        			if(hm.get(W).contains(X))
        				great++;
        		}
        	}
        	
        	int Good = Fio.fin.readInt();
        	int Great = Fio.fin.readInt();
        	Fio.fout.println(":(");
        	//
        	//if(great>=Great)
        	//{
        	//	Fio.fout.println("Great");
        	//}
        	//else if(good>=Good)
        	//{
        	//	Fio.fout.println("Good");
        	//}
        	//else
        	//{
        	//	Fio.fout.println(":(");
        	//}
        	//
        }
        Fio.fout.close();
    }
}
 
class Fio
{
    public static FastInput  fin = new FastInput();
    public static FastOutput fout= new FastOutput(true);
    
    public static class FastInput 
    {
        private final InputStream in;
        private final char[] brkChar;
        private byte[] buf; 
        private int curBufCharPos;
        private int bufSize;
 
        public FastInput(InputStream in,char[] brkChar)
        {
            this.in=in;
            buf = new byte[1024];
            curBufCharPos =0;
            bufSize  =0;
            this.brkChar=brkChar;
        }
        public FastInput(InputStream in)
        {
            this(in,null);
        }
        public FastInput()
        {
            this(System.in,null);
        }
 
        public int read()
        {
            if(bufSize==-1)
            {
                throw new InputMismatchException();
            }
            if(curBufCharPos>=bufSize)
            {
                curBufCharPos=0;
                try 
                {
                    bufSize=in.read(buf);
                } 
                catch (IOException x) 
                {
                    throw new InputMismatchException();
                }
                if(bufSize<=0)
                {
                    return -1;
                }
            }
            return buf[curBufCharPos++];
        }
        public int readInt()
        {
            int c = read();
            while (isBreakChar(c))
                c = read();
 
            int sign=1;
            if(c=='-')
            {
                sign=-1;
                c=read();
            }
            int res=0;
            do
            {
                if(c<'0' || c>'9')
                {
                    throw new InputMismatchException();
                }
                res=res*10+(c-'0');
                c=read();
            }
            while(!isBreakChar(c));
            return sign*res;
        }
        public long readLong()
        {
            int c = read();
            while (isBreakChar(c))
                c = read();
 
            int sign=1;
            if(c=='-')
            {
                sign=-1;
                c=read();
            }
            long res=0;
            do
            {
                if(c<'0' || c>'9')
                {
                    throw new InputMismatchException();
                }
                res=res*10+(c-'0');
                c=read();
            }
            while(!isBreakChar(c));
            return sign*res;
        }
        public float readFloat()
        {
            int c=read();
            while(isBreakChar(c))
                c=read();
            int sign=1;
            if(c=='-')
            {
                sign=-1;
                c=read();
            }
            float res=0;
            while(!isBreakChar(c) && c!='.')
            {
                if(c=='e' || c=='E')
                    return (float) (res*Math.pow(10, readInt()));
                if(c<'0' || c>'9')
                    throw new InputMismatchException();
 
                res = res*10 + (c-'0');
                c=read();
                //System.out.println("RES 1 : "+res);
            }
            if(c=='.')
            {
                c=read();
                float fac=10;
                do
                {
                    if(c=='e' || c=='E')
                        return (float) (res*Math.pow(10, readInt()));
                    if(c<'0' || c>'9')
                        throw new InputMismatchException();
 
                    //System.out.println("c   2 : "+ res +" "+ (c-'0')/fac + " "+ (res+(c-'0')/fac));
                    res+= (c-'0')/fac;
                    fac*=10;
                    c=read();
                    //System.out.println("RES 2 : "+res);
                }
                while(!isBreakChar(c));
            }
            return res*sign;
        }
        public double readDouble()
        {
            int c=read();
            while(isBreakChar(c))
                c=read();
            int sign=1;
            if(c=='-')
            {
                sign=-1;
                c=read();
            }
            double res=0;
            while(!isBreakChar(c) && c!='.')
            {
                if(c=='e' || c=='E')
                    return res*Math.pow(10, readInt());
                if(c<'0' || c>'9')
                    throw new InputMismatchException();
 
                res = res*10 + (c-'0');
                c=read();
                //System.out.println("RES 1 : "+res);
            }
            if(c=='.')
            {
                c=read();
                //int count=0;
                double fac=10;
                do
                {
                    if(c=='e' || c=='E')
                        return res*Math.pow(10, readInt());
                    if(c<'0' || c>'9')
                        throw new InputMismatchException();
 
                    //res= res*10+(c-'0');
                    //count++;
                    res+=(c-'0')/fac;
                    fac*=10;
                    c=read();
                }
                while(!isBreakChar(c));
                //res/=Math.pow(10, count);
            }
            return res*sign;
        }
        public char readChar()
        {
            int c = read();
            if(c!='\n' && read()=='\n')
                return (char)c;
            throw new InputMismatchException();
        }
        public String readString()
        {
            int c = read();
            while(isBreakChar(c))
            {
                c=read();
            }
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c=read();
            }
            while (!isBreakChar(c));
            return res.toString();
        }
        public String readStringLine()
        {
            int c = read();
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c=read();
            }
            while (c!='\n');
            return res.toString();
        }
        public String next()
        {
            return readString();
        }
        public boolean hasNextInLine()
        {
            //System.out.println(buf[curBufCharPos]);
            if(buf[curBufCharPos-1]!='\n')
                return true;
            return false;
        }
        public boolean hasConsequtiveNewLines()
        {
            //System.out.println(buf[curBufCharPos]);
            if(buf[curBufCharPos-1]=='\n' && buf[curBufCharPos-2]=='\n')
                return true;
            return false;
        }
        public boolean hasNext()
        {
            int c = read();
            setIteratorToPrev();
            return !(c==-1 || isBreakChar(c));
        }
        private void setIteratorToPrev()
        {
            curBufCharPos--;
        }
 
        private boolean isBreakChar(int c) 
        {
            if(brkChar==null)
                return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
            else
            {
                for(char ch : brkChar)
                {
                    if(c==ch)
                        return true;
                }
            }
            return false;
        }
    }
    
    public static class FastOutput
    {
        private final PrintWriter writer;
        private final boolean autoFlush;
 
        public FastOutput(OutputStream outputStream,boolean autoFlush) 
        {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
            this.autoFlush=autoFlush;
        }
        public FastOutput(boolean autoFlush) 
        {
            this(System.out,autoFlush);
        }
        public FastOutput(OutputStream outputStream) 
        {
            this(outputStream,false);
        }
        public FastOutput() 
        {
            this(System.out,false);
        }
 
        public void print(Object... objects) 
        {
            for (int i = 0; i < objects.length; i++)
            {
                if (i != 0) 
                {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
            if(autoFlush)
                flush();
        }
 
        public void println(Object... objects)
        {
            for (int i = 0; i < objects.length; i++)
            {
                if (i != 0) 
                {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
            writer.println();
            if(autoFlush)
                flush();
        }
 
        public void close()
        {
            writer.close();
        }
 
        public void flush() 
        {
            writer.flush();
        }
    }
    
}


Java 8:
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.PriorityQueue;
import java.util.Scanner;
 
class TestClass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T-->0){
        	System.out.println(":(");
        }
        
    }
}
 
 
class test{
	public int u;
	public int v;
	test(int u,int v){
		this.u = u;
		this.v = v;
	}
}

PHP:
<?php

// Sample code to perform I/O:
//fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
//echo "Hi, ".$name.".\n";                // Writing output to STDOUT
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
// Write your code here
fscanf(STDIN, "%d\n", $t);
for($l = 0; $l < $t; $l++){
    $mn = fgets(STDIN);
    $mn = explode(" ",$mn);
    $m = $mn[0];
    $n = $mn[1];
    
    $nSkills = [];
    $nProf = [];
    for($k = 0; $k < $m; $k++){
        $uv = fgets(STDIN);
        $uv = explode(" ",$uv);
        $nSkills[$k] = $uv[0];
        $nProf[$k] = $uv[1];
    }
    
    $oSkills = [];
    $oProf = [];
    for($z = 0; $z < $n; $z++){
        $uv = fgets(STDIN);
        $uv = explode(" ",$uv);
        $oSkills[$z] = $uv[0];
        $oProf[$z] = $uv[1];
    }
    $gh = fgets(STDIN);
    $gh = explode(" ",$gh);
    $good = 0;
    $great = 0;
    
    for($i = 0; $i < count($nSkills); $i++){
        //for($j = 0; $j < count($oSkills); $j++){
            if($nSkills[$i] == $oSkills[$i]){
                $good++;
                if($nProf[$i] == $oProf[$i]){
                    $great++;
                }
            }
       // }    
    }
    $res = ":(";
    if($good == $gh[0]){
        $res = "Good";
        if($great == $gh[1]){
            $res = "Great";
        }
    }
    echo $res."\n";
}
?>



Python:
t = int(raw_input())
 
for i in range(t):
    m,n = map(int,raw_input().split())
    arr1 = []
    arr2 =[]
    for j in range(m):
        u,v = map(int,raw_input().split())
        arr1.append(u)
        arr2.append(v)
    gd =0
    gt=0
    for j in range(n):
        w,x = map(int,raw_input().split())
        for k in range(m):
            if(arr1[k]==w and arr2[k]==x):
                gt +=1
            if(arr1[k]==w):
                gd+=1
    g,h = map(int,raw_input().split())
    if(g>=gd and h>=gt):
        print "Great"
    elif(g>=gd):
        print "Good"
    else:
        #print ":"
		print ":("


Python 3:
new = {}
existing = {}
t = int(input())
for i in range(0,t):
	good = 0
	great = 0
	notgood = 0
	m,n = map(int,input().split())
	for j in range(0,m):
		a,b = map(int,input().split())
		if a not in new:
			new[a] = [b]
		else:
			new[a].append(b)
	
	for j in range(0,n):
		a,b = map(int,input().split())
		if a not in existing:
			existing[a] = [b]
		else:
			existing[a].append(b)
		
	
	
	for j in new.keys():
		if j not in existing:
			notgood+=1
		else:
			for k in new[j]:
				if k in existing[j]:
					great+=1
	good = len(new) - notgood
	
	g,gg = map(int,input().split())
	if g>=good and gg>=great:
		print("Great")
	elif g>=good and gg<great:
		print("Good")
	else:
		print(":(")


Ruby:
gets.to_i.times do
	m,n = gets.split(" ").collect(&:to_i)
	new_skills = []
	new_hash = []
	existing_skills = []
	existing_hash = []
	m.times do
		new_skill_prof = gets.split(" ")
		new_skills << new_skill_prof.first
		new_hash << new_skill_prof.hash
	end
	n.times do
		exis_skill_prof = gets.split(" ")
		existing_skills << exis_skill_prof.first
		existing_hash << exis_skill_prof.hash
	end
	g,h = gets.split(" ").collect(&:to_i)
	actual_h = (new_hash & existing_hash).size
	actual_g = (new_skills & existing_skills).size
	if(actual_g >= g && actual_h >= h)
		puts "Great"
	elsif(actual_g >= g)
		puts "Good"
	else
		puts ":("
	end
end

*/
