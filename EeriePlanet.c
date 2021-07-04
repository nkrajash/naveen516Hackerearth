/* All Tracks -->  Data Structures -->  Queues  --> Basics of Queues -->  Problem --> Eerie Planet
Tag(s): Medium, Priority queue, Queue, Queue
You own a club on eerie planet. The day on this planet comprises of H hours. 
You appointed C crew members to handle the huge crowd that you get, being the best club on the planet. Each member of the crew has fixed number of duty hours to work. 
There can be multiple or no crew members at work at any given hour of the day.
Being on weird planet, the rules of this club cannot be normal. Each member of the crew only allows people who are taller than him to enter the club when he is at work.
Given the schedule of work and heights of the crew members, you have to answer Q queries. 
Each query specifies the time of entry and height of a person who is visiting the club. You have to answer if the person will be allowed to enter the club or not.

Input:
First line of the input contains 3 integers,H,C,Q . Representing number of hours in a day, number of crew members and number of queries respectively.
Next C lines follow, where each line contains 3 integers,hi,Si,Ei , representing height of the crew member and start and end hour of his/her work schedule. 
He/she works for hours [Si,Ei], both inclusive.
Next Q lines follow, each containing 2 integers,hi,ti , representing height and time (in hour) of the person trying to enter the club.

Output:
Q lines, each line containing "YES" or "NO", without the quotes, answering if the person will be allowed to enter the club or not.

Constraints:
1<=H<=10^9
1<=C<=10^5
1<=Q<=10^5
1<=Si<=Ei<=H
1<=ti<=H
1<=hi<=10^7

SAMPLE INPUT 
10 1 5
50 2 6
10 1
10 2
50 5
51 6
100 10
SAMPLE OUTPUT 
YES
NO
NO
YES
YES
Explanation
During the first hour, there is no crew member and hence person is allowed.
During hours 2 and 5, person is not taller than crew member, hence is not allowed to enter.
4th person is taller than the crew member at work and hence person is allowed.
During the 10th hour, there is no crew member and hence person is allowed.

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define fi first
#define sc second

multiset<int> pq;
multiset<pii > leave;
pair<pii, int> emp[100005], query[100005];
int ans[100005];

int main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	int h, t, c, q, i, j, x, y, z, a, b;
	cin >> h >> c >> q;
	for (i = 0; i < c; ++i) {
		cin >> x >> y >> z;
		emp[i] = mkp(mkp(y, z), x);
	}
	for (i = 0; i < q; ++i) {
		cin >> x >> y;
		query[i] = mkp(mkp(y, x), i);
	}
	sort(emp, emp+c);
	sort(query, query+q);
	int cur = 0;
	int start = 0;
	int end = 0;
	j = 0;
	for (i = 0; i < q; ++i) {
		int entry = query[i].fi.fi;
		int height = query[i].fi.sc;
		int idx = query[i].sc;
		while (j < c && emp[j].fi.fi <= entry) {
			pq.insert(emp[j].sc);
			leave.insert(mkp(emp[j].fi.sc, emp[j].sc));
			j += 1;
		}
		while (!leave.empty() && leave.begin()->fi < entry) {
			pq.erase(pq.find(leave.begin()->sc));
			leave.erase(leave.begin());
		}
		if (!pq.empty() && *(--pq.end()) >= height) {
			ans[idx] = 0;
		} else {
			ans[idx] = 1;
		}
	}
	for (i = 0; i < q; ++i) puts(ans[i] == 0 ? "NO" : "YES");

	return 0;
}

*/

/*Editorial:
There are offline and online solution for this question.

Offline:
There are three types of time in the question. Start time of duty for a crew member, End time of the duty for a crew member and a query time.
Maintain a sorted set of all such timings and process them in ascending order of timing.
When we arrive at the start of duty of any crew member, push this height into a max heap.
When we arrive at the end of duty of any crew member, mark height of this particular crew member to be invalid.
When we arrive at any query time, keep poping from heap until we get valid height member, and compare query height with it and record this answer.

At the end, all queries are processed in increasing order of time and can be outputted in given order.
Refer to setter's code for this approach.

Online:
Compress all given times and perform range maximum query using segment tree.
Refer to tester's code for this approach.

Time Complexity :O(n*log(n)) , where n=c+q

Author Solution by Mitesh Agrawal
//Mitesh Agrawal
#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define ff first 
#define ss second 
int guardHeights[100005];
int queryHeights[100005];
int invalid[100005];
int ans[100005];
struct node{
	bool query;
	int timer;
	bool start;
	int id;
	node(bool query, int timer, bool start, int id) : query(query), timer(timer), start(start), id(id) { }
};
bool cmp(node a, node b){
	if(a.timer != b.timer)
		return a.timer < b.timer;
	else
		return a.query < b.query;
}
int main(){
	int i,j,h,c,q,s,e,max_h;
	scanf("%d %d %d", &h, &c, &q);
	vector<node> timeSortedQueries;
	priority_queue<ii> pq;
	ii tp;
	for(i = 0; i < c; i++){
		scanf("%d %d %d", &guardHeights[i], &s, &e);
		timeSortedQueries.push_back(node(0, s, 1, i));
		timeSortedQueries.push_back(node(0, e + 1, 0, i));
	}
	for(i = 0; i < q; i++){
		scanf("%d %d", &queryHeights[i], &s);
		timeSortedQueries.push_back(node(1, s, 0, i));
	}
	sort(timeSortedQueries.begin(), timeSortedQueries.end(), cmp);
	for(auto el : timeSortedQueries){
		if(!el.query){
			if(el.start)
				pq.push({guardHeights[el.id], el.id});
			else
				invalid[el.id] = 1;
		}
		else{
			max_h = 0;
			while(!pq.empty()){
				tp = pq.top();
				if(!invalid[tp.ss]){
					max_h = tp.ff;
					break;
				}
				else
					pq.pop();
			}
			ans[el.id] = (queryHeights[el.id] > max_h);
		}
	}
	for(i = 0; i < q; i++)
		printf("%s\n", ans[i] ? "YES" : "NO");
    return 0;
}
Tester Solution by Satyaki Upadhyay
//satyaki3794
#include <bits/stdc++.h>
#define ff first
#define ss second
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)
 
using namespace std;
void verify(int n, int l, int r){
	assert(n >= l && n <= r);
}
const int N = 100002;
int H, C, Q, cc, ans[N], tree[12*N], lazy[12*N];
int crew[N][3], qarr[N][2];
map<int, int> compress;
void update(int node, int s, int e, int lo, int hi, int val){
	if(s > e || lo > hi)	return;
	if(lazy[node] != 0){
		tree[node] = max(tree[node], lazy[node]);
		if(s != e){
			lazy[LEFT(node)] = max(lazy[LEFT(node)], lazy[node]);
			lazy[RIGHT(node)] = max(lazy[RIGHT(node)], lazy[node]);
		}
		lazy[node] = 0;
	}
	if(s > hi || lo > e)	return;
	if(s >= lo && e <= hi){
		tree[node] = max(tree[node], val);
		if(s != e){
			lazy[LEFT(node)] = max(lazy[LEFT(node)], val);
			lazy[RIGHT(node)] = max(lazy[RIGHT(node)], val);
		}
		return;
	}
	int mid = (s+e)/2;
	update(LEFT(node), s, mid, lo, hi, val);
	update(RIGHT(node), mid+1, e, lo, hi, val);
	tree[node] = max(tree[LEFT(node)], tree[RIGHT(node)]);
}
int query(int node, int s, int e, int pos){
	if(s > e)	return 0;
	if(lazy[node] != 0){
		tree[node] = max(tree[node], lazy[node]);
		if(s != e){
			lazy[LEFT(node)] = max(lazy[LEFT(node)], lazy[node]);
			lazy[RIGHT(node)] = max(lazy[RIGHT(node)], lazy[node]);
		}
		lazy[node] = 0;
	}
	if(s > pos || pos > e)	return 0;
	if(s == e)	return tree[node];
	int mid = (s+e)/2;
	int a = query(LEFT(node), s, mid, pos);
	int b = query(RIGHT(node), mid+1, e, pos);
	return max(a, b);
}
 
int main(){
	scanf("%d%d%d", &H, &C, &Q);
	verify(H, 1, 100000*10000);
	verify(C, 1, 100000);
	verify(Q, 1, 100000);
	for(int i=1;i<=C;i++){
		scanf("%d%d%d", &crew[i][0], &crew[i][1], &crew[i][2]);
		verify(crew[i][0], 1, 10000*1000);
		verify(crew[i][1], 1, H);
		verify(crew[i][2], 1, H);
		compress[crew[i][1]];
		compress[crew[i][2]];
	}
	for(int i=1;i<=Q;i++){
		scanf("%d%d", &qarr[i][0], &qarr[i][1]);
		verify(qarr[i][0], 1, 10000*1000);
		verify(qarr[i][1], 1, H);
		compress[qarr[i][1]];
	}
	cc = 0;
	for(auto &it : compress)
		it.ss = ++cc;
	for(int i=1;i<=C;i++){
		update(1, 1, cc, compress[crew[i][1]], compress[crew[i][2]], crew[i][0]);
	}
	for(int i=1;i<=Q;i++){
		if(query(1, 1, cc, compress[qarr[i][1]]) < qarr[i][0])	printf("YES\n");
	    else  printf("NO\n");
	}
    return 0;
}

*/

/*
C:
    #include <stdio.h>
     
    int main(){
    	 int h,c,q,i;
        scanf("%d%d%d",&h,&c,&q);
         //s1(&h);s1(&c); s1(&q);
        int k=-1;
        int a[c],s[c],e[c];
        for( i=0;i<c;i++){//s1(&a[i]);s1(&s[i]); s1(&e[i]);
        scanf("%d%d%d",&a[i],&s[i],&e[i]);
        if(k<a[i])k=a[i];
        }
        
        while(q--)
        {
            int z,x;//s1(&z);s1(&x);
            scanf("%d%d",&z,&x);
            int f=0;
            if(k<z){printf("YES\n");f=1;}
            else 
            {
                for( i=0;i<c;i++)
                {
                    if(x>=s[i]&&x<=e[i]&&z<=a[i])
                    {
                        printf("NO\n");f=1;break;
                    }
                }
            }
            if(f==0)printf("YES\n");
        }
        
    }

C++:
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int hr,c,q,i;
    scanf("%ld %ld %ld",&hr,&c,&q);
    
    long int crew[c],start[c],end[c],max;
    for(i=0;i<c;i++)
        scanf("%ld %ld %ld",&crew[i],&start[i],&end[i]);
 
    max = *std::max_element(crew,crew+c);
    while(q--)
    {
        long int hi,ti,j=0;
        int ch=0;
        scanf("%ld %ld",&hi,&ti);
        
        if(hi>max)
            cout<<"YES\n";
        else
        {
        for(i=0;i<c;i++)
        {
            if(hi<=crew[i])
            {
                if(ti>=start[i] && ti<=end[i])
                {
                    ch=1;
                    break;
                }
            }
        }
            if(ch==1)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
    }
    return 0;
}

Alt.Solution:
#include<iostream>
using namespace std;
struct seg{
    seg *left, *right;
    int Cnt;
    seg(int _Cnt){
        Cnt = _Cnt;
        left = NULL;
        right = NULL;
    }
};
int query(seg *root, int l, int r, int idx){
    if(idx > r || l > idx) return 0;
    if(!root) return 0;
    if(l == r) return root->Cnt;
    return max(root->Cnt, max(query(root->left, l, (l + r)/2 , idx) , query(root->right, (l + r)/2 + 1, r, idx)));
}
seg  *update(seg *root, int l, int r, int s , int e, int val){
    if(s > r || l > e) return root;
    if(!root) root = new seg(0);
    if(l >= s && r <= e){
        root->Cnt = max(root->Cnt, val);
        return root;
    }
        root->left  = update(root->left, l, (l + r)/2 , s , e ,val);
        root->right = update(root->right, (l + r)/2 + 1, r, s, e,  val);
    return root;
}
int main(){
    seg *root = new seg(0);
    int n, c, q;
    scanf("%d %d %d", &n, &c, &q);
    for(int i = 1 ; i <= c ; ++i){
        int h, s , e;
        scanf("%d %d %d", &h, &s, &e);
        root = update(root, 1, 1e9, s, e, h);
    }
    while(q--){
        int h, t;
        scanf("%d %d", &h, &t);
        if(query(root, 1, 1e9, t) < h)
            printf("YES\n"); else
                printf("NO\n");
    }
    
}

C++14:
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	long long h,c,q;
	vector< pair<pair<long long,long long>,long long > >vv1;
	priority_queue< pair<long long,pair<long long,long long> > >aa;
	scanf("%lld %lld %lld",&h,&c,&q);
	for(int i=0;i<c;i++)
	{
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		vv1.push_back(make_pair(make_pair(b,c),a));
	}
	bool ans[100010]={1};
	vector< pair<pair<long long,long long>,long long > >vv;
	for(int i=0;i<q;i++)
	{
		long long hh,tt;
		scanf("%lld %lld",&hh,&tt);
		vv.push_back(make_pair(make_pair(tt,hh),i));
	}
	sort(vv.begin(),vv.end());
	sort(vv1.begin(),vv1.end());
	long long cnt=0;
	for(int i=0;i<vv.size();i++)
	{
		if(aa.size()>0 && ((vv[i].first).first)<((aa.top().second).first))
		{
			ans[vv[i].second]=true;
			continue;
		}
		while( cnt<c && ((vv1[cnt].first).second) < ((vv[i].first).first) )
		{
			cnt++;
		}
		while( cnt<c && ((vv1[cnt].first).first) <= ((vv[i].first).first) && ((vv1[cnt].first).second) >= ((vv[i].first).first) )
		{
			aa.push(make_pair(vv1[cnt].second,vv1[cnt].first));
			cnt++;
		}
		while(aa.size()>0 && ((vv[i].first).first) > ((aa.top().second).second) )
		{
			aa.pop();
		}
		if(aa.size()>0)//&&((vv[i]->first)->first)>=((aa.top()->second)->first)&&((vv[i]->first)->first)<=((aa.top()->second)->second))
		{
			if((vv[i].first).second>aa.top().first)
			{
				ans[vv[i].second]=true;
			}
			else
			{
				ans[vv[i].second]=false;
			}
		}
		else
		{
			ans[vv[i].second]=true;
		}
	}
	for(int i=0;i<q;i++)
	{
		if(ans[i])printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

C#:
using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
 
namespace ALL
{
    class EeriePlanet
    {
        class ConsoleInput : IDisposable
        {
            public void Dispose()
            {
 
            }
 
            public string ReadLine()
            {
                return Console.ReadLine();
            }
 
            public void WriteLine(object o)
            {
                Console.WriteLine(o);
            }
 
            public void Write(object o)
            {
                Console.Write(o);
            }
 
            public int Read()
            {
                return Console.Read();
            }
        }
 
        class Crew
        {
            public int Height { get; set; }
 
            public int Start { get; set; }
 
            public int End { get; set; }
 
        }
 
        public static void Main(string[] args)
        {
 
            using (var console = new ConsoleInput())
            {
                int[] data = console.ReadLine().Split(' ').Select(e => int.Parse(e)).ToArray();
                int hours = data[0];
                int totalCrewMembers = data[1];
                int totalQueries = data[2];
                int max = 0;
                List<Crew> crews = new List<Crew>();
 
                for(int i = 0; i< totalCrewMembers; i++)
                {
                    data = console.ReadLine().Split(' ').Select(e => int.Parse(e)).ToArray();
                    
                    crews.Add(new Crew { Height = data[0], Start = data[1], End = data[2] });
                    max = Math.Max(data[0], max);
                }
 
                for(int i = 0; i < totalQueries; i++)
                {
                    data = console.ReadLine().Split(' ').Select(e => int.Parse(e)).ToArray();
                    bool flag = true;
                    if(data[0] <= max)
                    {
                        foreach (var crew in crews)
                        {
                            if (crew.Start <= data[1] && crew.End >= data[1] && crew.Height >= data[0])
                            {
                                flag = false;
                                break;
                            }
                        }
                    }
                   
 
                    if(flag)
                    {
                        console.WriteLine("YES");
                    }
                    else
                    {
                        console.WriteLine("NO");
                    }
                }
            }
        }
    }
}

Java:
import java.io.*;
import java.lang.reflect.Member;
import java.math.BigInteger;
import java.util.*;
 
import static java.lang.System.out;
 
//
//Created by USER on 01/06/2018.
//
class Competition {
 
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
 
        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }
 
        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
 
            if (neg)
                return -ret;
            return ret;
        }
 
        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
 
        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
 
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
 
            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }
 
            if (neg)
                return -ret;
            return ret;
        }
 
        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
 
        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
 
        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }
 
    static class Print {
        private BufferedWriter bw;
 
        public Print() {
            this.bw = new BufferedWriter(new OutputStreamWriter(out));
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
 
    static class Crew{
        int h,s,t;
        public Crew(int h,int s,int t){
            this.h = h;
            this.s = s;
            this.t = t;
        }
    }
    public static void main(String args[]) throws IOException {
        Reader fr = new Reader();
        //Scanner fr = new Scanner(System.in);
        Print print = new Print();
        int H = fr.nextInt();
        int C = fr.nextInt(); //crew
        int Q = fr.nextInt();
        LinkedList<Crew> list = new LinkedList<>();
        int max = Integer.MIN_VALUE;
        for (int i = 0 ; i < C; i++){
            int h = fr.nextInt();
            if(h > max)
                max = h;
            int s = fr.nextInt();
            int t = fr.nextInt();
            list.add(new Crew(h, s, t));
        }
        while(Q-->0){
            int h = fr.nextInt();
            int t = fr.nextInt();
            boolean flag = true;
            if(h<=max){
                Iterator<Crew> iterator = list.iterator();
                while(iterator.hasNext()){
                    Crew crew = iterator.next();
                    if(t >= crew.s && t <= crew.t && h<= crew.h){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
                print.println("YES");
            else
                print.println("NO");
        }
 
        print.close();
 
    }
 
 
}


Java 8:
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.*;
 
import static java.lang.Integer.MAX_VALUE;
 
 
public class nirav {
    public static void main(String[] args) throws IOException {
        Scan scn = new Scan();
        Print prnt = new Print();
        int H = scn.scanInt();
        int C = scn.scanInt();
        int Q = scn.scanInt();
        int height[] = new int[C];
        int begin[] = new int[C];
        int free[] = new int[C];
        int max=0;
        int min=MAX_VALUE;
        for(int i=0;i<C;i++){
            height[i] = scn.scanInt();
            begin[i] = scn.scanInt();
            free[i] = scn.scanInt();
            max = Math.max(height[i],max);
        }
        for(int i=0;i<Q;i++){
            int person = scn.scanInt();
            int time = scn.scanInt();
            boolean flag=false;
            if(person>max){
                flag = true;
            }else {
                flag = true;
                for (int j = 0; j < C; j++) {
                    if (begin[j]<=time && time<=free[j] && height[j]>=person){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                prnt.printLine("YES");
            }else{
                prnt.printLine("NO");
            }
        }
 
 
 
        prnt.close();
    }
}
 
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
 
    public char scanCharacter()throws IOException
    {
        int n=scan();
        while(isWhiteSpace(n))
            n=scan();
        return (char)n;
    }
 
    public long scanLong()throws IOException
    {
        long lng=0;
        int n=scan();
        while(isWhiteSpace(n))
            n=scan();
        int neg=1;
        if(n=='-')
        {
            neg=-1;
            n=scan();
        }
        while(!isWhiteSpace(n) && n!='.')
        {
            if(n>='0'&&n<='9')
            {
                lng*=10;
                lng+=n-'0';
                n=scan();
            }
            else throw new InputMismatchException();
        }
        if(n=='.')
        {
            n=scan();
            long temp=1;
            while(!isWhiteSpace(n))
            {
                if(n>='0'&&n<='9')
                {
                    temp/=10;
                    lng+=(n-'0')*temp;
                    n=scan();
                }
                else throw new InputMismatchException();
            }
        }
        return neg*lng;
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
 
 
class Print
{
    private final BufferedWriter bw;
    public Print()
    {
        bw=new BufferedWriter(new OutputStreamWriter(System.out));
    }
    public void print(String str)throws IOException
    {
        bw.append(str);
    }
    public void printLine(String str)throws IOException
    {
        print(str);
        bw.append("\n");
    }
    public void close()throws IOException
    {
        bw.close();
    }
}


Java(Node.js):

Python:
import heapq
 
 
h, c, q = map(int, raw_input().split())
 
crew = []
for _ in xrange(c):
    crew.append(map(int, raw_input().split()))
 
queries = []
for i in xrange(q):
    hi, t = map(int, raw_input().split())
    queries.append((hi, t, i))
 
crew.sort(key=lambda element: element[1])
queries.sort(key=lambda element: (element[1]))
 
 
res = []
q = []
heapq.heapify(q)
cc = 0
last_hour = -1
_max_now = -1
_max_exit_time = None
for x in queries:
    i = x[1]
    if last_hour != i:
        while len(crew) > cc and crew[cc][1] <= i:
            # put end time and height
            heapq.heappush(q, (crew[cc][2], crew[cc][0]))
            if crew[cc][0] > _max_now:
                _max_now = crew[cc][0]
                _max_exit_time = crew[cc][2]
            cc += 1
 
        if i > _max_exit_time:
            max_removed = False
            while len(q)>0:
                if q[0][0] < i:
                    pop = heapq.heappop(q)
                    if not max_removed: max_removed = (pop[1] == _max_now)
                else : break
    
            if len(q) == 0:
                _max_now = -1
                _max_exit_time = None
            elif max_removed:
                _max_now = -1
                for qq in q:
                    if qq[1] > _max_now:
                        _max_now = qq[1]
                        _max_exit_time = qq[0]
    res.append((x[2], 'YES' if x[0] > _max_now else 'NO'))
    last_hour = i
 
res.sort()
for r in res: print r[1]


Python 3:
def main():
    h, c, q = map(int, input().split())
    crew_list = []
    for _ in range(c):
        ht, s, e = map(int, input().split())
        crew_list.append((ht, s, e))
 
    max_height = max(crew_list, key=lambda x: x[0])[0]
 
    for _ in range(q):
        hi, ti = map(int, input().split())
        if hi > max_height:
            print('YES')
        else:
            ans = 'YES'
            for m in crew_list:
                if m[1] <= ti <= m[2] and m[0] >= hi:
                    ans = 'NO'
                    break
            print(ans)
 
 
if __name__ == '__main__':
    main()


*/
