/*All Tracks -->  Algorithms --> Dynamic Programming --> Problem --> Zulu and Alarm Clock

Tag(s): Algorithms, Bitmask, Dynamic Programming, Medium
Zulu is a very lazy kid. He always try to optimize everything in order to do minimal work possible. Once while setting alarm, he was stuck and needed your help?
You are given N clocks. Initially all these clocks have some fixed time in the format HH:MM:SS which follow standard 24 hour clock rule i.e. hour's clock is 
between 00 to 23(both inclusive), minute's and second's clock are between  to 00 to 59(both inclusive). 
Now, You need to set K alarm times which will be provided again in the same format HH:MM:SS out of these N clocks. 
Now the only operation you are allowed is to shift the hour, minute or the second clock times by 1 unit in either of the directions. 
i.e. You can either increase or decrease the given time. The cost of the above operation is 1 unit.

Now, note that the usual clock rules will apply while changing the second, minute or hour clock values. i.e. when second's clock is on  seconds and you make it to 60, 
instead of getting 60, you get 00 and minute's clock gets increased by 1 unit. On the other hand if you have 60 second and you try to decrease it by 1, you get 59 seconds and 
minute clock will get decreased by 1 unit. Similar changes for minute's clock will lead to change in the hour's clock. Note that there is no change in other clocks 
while we change the hour's clock i.e. hour clock when increased on 23 will go back to 00  or vice versa without affecting minute's and second's clock.
Calculate minimum number of operations needed to make a subset of K clocks of the N clocks equal to the set of K alarms.

Input:
First line of input contains T denoting number of test cases. For each of the test cases, first line contains two integers N denoting number of clocks and 
K denoting number of alarm times needed to be set. Now there follow N+K lines where first N lines contains list of available times on the clocks and 
next K lines contains the alarm times which you need to set using the given N clocks. Note that each of the time is given in the format HH:MM:SS only.

Output:
For each of the test cases, output in a single line the minimum number of operations required to set all alarms successfully.

Constraints:
1<=T<=2
1<=N<=50
1<=K<=17
K<=N

SAMPLE INPUT 
1
3 2
10:10:10
05:04:56
13:12:21
05:02:58
11:10:18

SAMPLE OUTPUT 
11

Explanation
In the given test case :
Clock 1 takes (5+7+12=24) time units to set alarm 1 and (1+0+8=9) time units to set alarm 2.
Clock 2 takes (0+2+2=4) time units to set alarm 1 and (6+5+22=33) time units to set alarm 2.
Clock 3 takes (8+9+23=40) time units to set alarm 1 and (2+2+3=7) time units to set alarm 2.
Thus, we can use clock 2 to set alarm 1 and clock 3 to set alarm 2 to get the minimum cost as 4+7=11.

//My C Solution(Partially Solved):
#include <stdlib.h>
#define N 51
#define K 18
#define LEN 10

typedef struct Clock{
    int CHH;
    int CMM;
    int CSS;
}clok;

typedef struct Alarm{
    int AHH;
    int AMM;
    int ASS;
}alarm;

int Compute_MinCost(clok ,alarm );

int main()
{
    int n,k,i,j,l,m,t,s,min,sec,hr;
    int Cost[N][K],minCost,temp;
    clok clk[N];
    alarm alrm[K];
    char line[LEN],tmp[3];
    
    fscanf(stdin,"%d\n",&t);
    for(i=0;i<t;i++){
        minCost= temp=0;
        fscanf(stdin,"%d",&n);
        fscanf(stdin,"%d\n",&k);
        for(j=0;j<n;j++){
            if(fgets(line,LEN,stdin)!=NULL)
                    ;
            m=s=0;
            min=hr=sec=0;
            while(line[m]){
                if(line[m]==':'){
                    tmp[s]='\0';
                    if(!hr){
                        clk[j].CHH = atoi(tmp);
                        hr=1;
                        s=0;
                    }
                    else if(!min){
                        clk[j].CMM = atoi(tmp);
                        min=1;
                        s=0;
                    }
                }
                else
                    tmp[s++]=line[m];
                m++;
            }
            if(!sec){
                clk[j].CSS = atoi(tmp);
                sec=1;
                s=0;
            }
        }
        for(l=0;l<k;l++){
            if(fgets(line,LEN,stdin)!=NULL)
                    ;
            m=s=0;
            min=hr=sec=0;
            while(line[m]){
                if(line[m]==':'){
                    tmp[s]='\0';
                    if(!hr){
                        alrm[l].AHH = atoi(tmp);
                        hr=1;
                        s=0;
                    }
                    else if(!min){
                        alrm[l].AMM = atoi(tmp);
                        min=1;
                        s=0;
                    }
                }
                else
                    tmp[s++]=line[m];
                m++;
            }
            if(!sec){
                alrm[l].ASS = atoi(tmp);
                sec=1;
                s=0;
            }
        }
        for(j=0;j<n;j++)
            for(l=0;l<k;l++)
                Cost[j][l]=Compute_MinCost(clk[j],alrm[l]);
        for(l=0;l<k;l++)
        {
            for(j=1;j<n;j++)
            {
                temp=Cost[j][l];
                s=j-1;
                while(s>=0 && Cost[s][l]>temp)
                {
                    Cost[s+1][l]=Cost[s][l];
                    s--;
                }
                Cost[s+1][l]=temp;
            }
        }
        for(j=0;j<n;j++){
            for(l=0;l<k;l++){
                if(j==0)
                    minCost+=Cost[j][l];
                //printf("Cost=%d\n",Cost[j][l]);
            }
        }
        printf("%d\n",minCost);
    }
    return 0;
}

int Compute_MinCost(struct Clock clk,struct Alarm alrm){
    int cost=0;
    if(clk.CSS>alrm.ASS){
        if((clk.CSS-alrm.ASS)<=30){
            if(clk.CSS-alrm.ASS)
                cost+=clk.CSS-alrm.ASS;
            clk.CSS-=clk.CSS-alrm.ASS;
            if(clk.CSS==00){
                if(clk.CMM==00){
                    clk.CMM=59;
                    clk.CHH=clk.CHH-1;
                }
                else
                    clk.CMM=clk.CMM-1;
            }
        }
        else{
            cost+=(60-clk.CSS)+alrm.ASS;
            clk.CSS+=(60-clk.CSS)+alrm.ASS;
            if(clk.CSS==60){
                clk.CSS=00;
                if(clk.CMM==59){
                    clk.CMM=00;
                    clk.CHH=clk.CHH+1;
                }
            }
            else
                clk.CMM=clk.CMM+1;
        }
    }
    else if(clk.CSS<alrm.ASS){
        if((alrm.ASS-clk.CSS)<=30){
            if(alrm.ASS-clk.CSS)
                cost+=alrm.ASS-clk.CSS;
            clk.CSS+=alrm.ASS-clk.CSS;
            if(clk.CSS==60){
                clk.CSS=00;
                if(clk.CMM==59){
                    clk.CMM=00;
                    clk.CHH=clk.CHH+1;
                }
                else
                    clk.CMM=clk.CMM+1;
            }
        }
        else{
            cost+=(60-alrm.ASS)+clk.CSS;
            clk.CSS=60-(60-alrm.ASS);
            if(clk.CMM==00){
                clk.CMM=59;
                clk.CHH=clk.CHH-1;
            }
            else
               clk.CMM=clk.CMM-1;
        }
    }

    //printf("%d+",cost);
    if(clk.CMM>alrm.AMM){
        if(clk.CMM-alrm.AMM<=30){
            if(clk.CMM-alrm.AMM)
                cost+=clk.CMM-alrm.AMM;
            clk.CMM-=clk.CMM-alrm.AMM;
            if(clk.CMM==00)
                if(clk.CHH==00)
                    clk.CHH=23;
                else
                    clk.CHH=clk.CHH-1;
        }
        else{
            cost+=(60-clk.CMM)+alrm.AMM;
            clk.CMM+=(60-clk.CMM)+alrm.AMM;
            if(clk.CMM==60){
                clk.CMM=00;
                if(clk.CHH==23)
                    clk.CHH=00;
            }
            else
                clk.CHH=clk.CHH+1;
        }
    }
    else if(clk.CMM<alrm.AMM){
        if(alrm.AMM-clk.CMM<=30){
            if(alrm.AMM-clk.CMM)
                cost+=alrm.AMM-clk.CMM;
            clk.CMM+=alrm.AMM-clk.CMM;
            if(clk.CMM==60)
                if(clk.CHH==23)
                    clk.CHH=00;
                else
                    clk.CHH=clk.CHH+1;                
        }
        else{
            cost+=(60-alrm.AMM)+clk.CMM;
            clk.CMM=60-(60-alrm.AMM);
            if(clk.CHH==00)
                clk.CHH=23;
            else
                clk.CHH=clk.CHH-1;
        }
    }

    //printf("%d+",cost);
    if(clk.CHH>alrm.AHH){
        if(clk.CHH-alrm.AHH<=12){
            if(clk.CHH-alrm.AHH)
                cost+=clk.CHH-alrm.AHH;
        }
        else
            cost+=(24-clk.CHH)+alrm.AHH;
    }
    else if(clk.CHH<alrm.AHH){
        if(alrm.AHH-clk.CHH<=12){
            if(alrm.AHH-clk.CHH)
                cost+=alrm.AHH-clk.CHH;
        }
        else
            cost+=(24-alrm.AHH)+clk.CHH;
    }
    //printf("%d\n",cost);
    return cost;
}

//Alt.C Solution(Partially Solved)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
struct time {
	int h, m, s;
};
 
int mintime (struct time t1, struct time t2) {
	int ans = 0;
	if (abs (t1.s- t2.s) <= 30) {
		ans += abs (t1.s-t2.s);
	}
	else {
		ans += (60 - abs (t1.s-t2.s));
		if (t2.s > 30) {
			t2.s = t1.s;
			t2.m = (t2.m+1)%60;
			if (t2.m == 0) {
				t2.h = (t2.h+1)%24;
			}
		}
		else {
			t2.s = t1.s;
			t2.m = (t2.m-1);
			if (t2.m == -1) {
				t2.m = 59;
				t2.h = t2.h-1;
				if (t2.h == -1) {
					t2.h = 23;
				}
			}
		}
	}
	//printf ("%d\n", ans);
	if (abs (t1.m- t2.m) <= 30) {
		ans += abs (t1.m-t2.m);
	}
	else {
		ans += (60 - abs (t1.m-t2.m));
		if (t2.m > 30) {
			t2.m = t1.m;
			t2.h = (t2.h+1)%24;
		}
		else {
			t2.m = t1.m;
			t2.h = t2.h - 1;
			if (t2.h == -1) {
				t2.h = 23;		
			}
		} 
	}
	//printf ("%d\n", ans);
	if (abs (t1.h- t2.h) <= 12) {
		ans += abs (t1.h-t2.h);
	}
	else {
		ans += (24 - abs (t1.h-t2.h));
	}
	return ans;
}
 
int main () {
	int t, n, k, min, ans, temp, index1, index2, count;
	struct time a[51];
	struct time b[20];
	char c1, c2;
	int i, j;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d%d", &n, &k);
		for (i = 0; i < n; i++) {
			scanf ("%d:%d:%d", &a[i].h, &a[i].m, &a[i].s);
		}
		for (i = 0; i < k; i++) {
			scanf ("%d:%d:%d", &b[i].h, &b[i].m, &b[i].s);
		}
		//for (i = 0 ;i < n; i++) {
		//	printf ("%d %d %d\n", a[i].h, a[i].m, a[i].s);
		//}
		min = INT_MAX;
		index1 = -1;
		index2 = -1;
		ans = 0;
		count = 0;
		int c[51][20];
		for (i = 0; i < k; i++) {
			for (j = 0; j < n; j++) {
				temp = mintime (b[i], a[j]);
				c[j][i] = temp;
			}
		}
		while (count != k) {
			min = INT_MAX;
			for (i = 0; i < n; i++) {
				for (j = 0;j < k; j++) {
					if (c[i][j] < min) {
						min = c[i][j];
						index1 = i;
						index2 = j;
					}
				}
			}
			ans += min;
			for (i = 0; i < n; i++) {
				c[i][index2] = INT_MAX;
			} 
			for (i = 0; i < k; i++) {
				c[index1][i] = INT_MAX;
			}
			count++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

*/

/*Editorial:
Setter: Amit Gupta
Tester: Hasan Jaddouh
Editorialist: Saatwik Singh Nagpal

Problem:
In the problem, we are given N digital clocks, which initially show some time. We need to set K alarms, atmost one on a clock. 
To set the alarm, we have to change the time of the clock to the time of the alarm. Each move is described in the problem. 
We need to find the minimum number of moves in which K alarms can be set.

Quick Explanation:
As K is small, we can solve it using dynamic programming with bitmasking. To get the number of steps between two times, we can do some precomputation, eg. a bfs.

Solution:
This problem can be solved using dynamic programming with bitmasking. How to come up with the state of the dp? Let's look at it. 
Suppose we can find the minimum number of steps needed to change the time from T1 to T2. Let it be denoted by steps(T1,T2). 
Let the initial time on the ith clocks be denoted by clocki and the time of ith alarm be alarmi. 
Let dp(i,mask) denote the minimum number of steps needed to set the alarms corresponding to the set bits in mask, 
if we considered only the first i clocks. How do we find the dp-transition?
To get dp(i, mask), we can do the transition like this :

dp(i, mask) = dp(i-1, mask) // We didn't use the ith clock to set an alarm on it.
for j = 0 to k-1:
    if jth bit is set in mask:
        dp(i, mask) = min(steps(clock[i], alarm[j]) + dp(i-1, mask xor (1<<j)), dp(i, mask)) // we set the jth alarm on the ith clock.
		
Now, this way we can find the minimum number of steps to set the K alarms. But how do we get steps(T1,T2) efficiently?
We can perform a step in 6 types of ways : 
increase hour, decrease hour, increase minute, decrease minute, increase second, decrease second. 
Imagine all the possible times (24*60*60 to be precise) to be nodes of a graph. 
Let there be edges between the nodes T1 and  T2, if can move from T1 to T2 or vice versa in just one step. 
Now, as in our dynamic programming solution, we only need to know the value of steps(clocki,alarmi), we can do a breadth first search from each  alarmi,
and find the minimum number of steps needed to reach each of the times from alarmi and store it in bfs(i,T'), 
which denotes the minimum number of steps needed to change the time from alarmi to T and vice versa. 
Now, we can use these values to do the dp transitions.

The time complexity for the dynamic programming part is O(N*K*2^K) and for the precomputation part, it will be O(K*24*60*60). 
So, the total time complexity per test case will be O(K*24*60*60+ N*K*2^K).

Bonus:
This problem can also be solved by minimum cost maximum bipartite matching. 
We can form a bipartite graph in which on one side we can keep all the clock times and on the other side we can keep all the alarm times. 
The edge between each clock time and the alarm time will correspond to the capacity of 1 and the cost of the edge would be the number of steps that would be 
required to set this alarm on this clock. 
When we find the min-cost-max-bipartite-matching of this bipartite graph, the max-bipartite-matching will be K, and the minimum cost for this matching will 
correspond to the minimum number of steps required to set these K alarms.
For implementation details, you can refer to the editorialist's solution here.


Author Solution by Amit Gupta
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int n, k, cost[55][25], dp[1<<17][51];
string s[55], a[20];
int sec1[55], min1[55], hr1[55], sec2[20], min2[20], hr2[20];
int rec(int mask, int id) {
	if(mask == (1<<k) - 1) return 0;
	if(id >= n) return MOD;
	if(dp[mask][id] != -1) return dp[mask][id];
	int res = MOD;
	res = min(res, rec(mask, id + 1));
	for (int i = 0; i < k; ++i) {
		if(!(mask & 1<<i))
			res = min(res, cost[id][i] + rec(mask | (1<<i), id + 1));
	}
	return dp[mask][id] = res;
}
void transform(string str, int id, int flag) {
	int hr = (str[0] - '0') * 10 + str[1] - '0';
	int mn = (str[3] - '0') * 10 + str[4] - '0';
	int sec = (str[6] - '0') * 10 + str[7] - '0';
	if(flag == 1) {
		hr1[id] = hr; min1[id] = mn; sec1[id] = sec;
	}
	else {
		hr2[id] = hr; min2[id] = mn; sec2[id] = sec;
	}
}
void cal(int mask, int i, int j) {
	int req = 0;
	int o_min1 = min1[i], o_sec1 = sec1[i], o_hr1 = hr1[i];
	if(1 & mask) {   // for second's part
		if(sec2[j] >= sec1[i]) {
			req += sec2[j] - sec1[i];
		}
		else {
			req += 60 - sec1[i];
			req += sec2[j];
			min1[i] ++;
			min1[i] %= 60;
			if(min1[i] == 0) {
				hr1[i] ++;
				hr1[i] %= 24;
			}
		}
	}
	else {
		if(sec2[j] <= sec1[i]) {
			req += sec1[i] - sec2[j];
		}
		else {
			req += 60  - sec2[j];
			req += sec1[i];
			min1[i] -= 1;
			min1[i] += 60;
			min1[i] %= 60;
			if(min1[i] == 59) {
				hr1[i] -= 1 ;
				hr1[i] += 24;
				hr1[i] %= 24;
			}
		}
	}
	if(2 & mask) {   // for minute's part
		if(min2[j] >= min1[i]) {
			req += min2[j] - min1[i];
		}
		else {
			req += 60 - min1[i];
			req += min2[j];
			hr1[i] ++;
			hr1[i] %= 24;
		}
		
	}
	else {
		if(min2[j] <= min1[i]) {
			req += min1[i] - min2[j];
		}
		else {
			req += 60  - min2[j];
			req += min1[i];
			hr1[i] -= 1 ;
			hr1[i] += 24;
			hr1[i] %= 24;
		}
	}
	if(4 & mask) {   // for hour's part
		if(hr2[j] >= hr1[i]) {
			req += hr2[j] - hr1[i];
		}
		else {
			req += 24 - hr1[i];
			req += hr2[j];
		}
	}
	else {
		
		if(hr2[j] <= hr1[i]) {
			req += hr1[i] - hr2[j];
		}
		else {
			req += 24  - hr2[j];
			req += hr1[i];
		}
	}
	cost[i][j] = min(cost[i][j], req);
	min1[i] = o_min1, sec1[i] = o_sec1, hr1[i] = o_hr1;
}
void reset() {
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 55; ++i) {
		for (int j = 0; j < 20; ++j) {
			cost[i][j] = MOD;
		}
	}
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		reset();
		cin>>n>>k;
		for (int i = 0; i < n; ++i) {
			cin>>s[i];
			transform(s[i], i, 1);
		}
		for (int i = 0; i < k; ++i) {
			cin>>a[i];
			transform(a[i], i, 2);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < k; ++j) {
				for (int mask = 0; mask < 8; ++mask) {
					cal(mask, i, j);
				}
			}
		}
		int res = rec(0, 0);
		cout<<res<<"\n";
	}
}
Tester Solution by Hasan Jaddouh
#include <iostream>
#include <assert.h>
#include <string>
#include <queue>
using namespace std;
long long readInt(long long l,long long r,char endd){
	long long x=0;
	int cnt=0;
	int fi=-1;
	bool is_neg=false;
	while(true){
		char g=getchar();
		if(g=='-'){
			assert(fi==-1);
			is_neg=true;
			continue;
		}
		if('0'<=g && g<='9'){
			x*=10;
			x+=g-'0';
			if(cnt==0){
				fi=g-'0';
			}
			cnt++;
			assert(fi!=0 || cnt==1);
			assert(fi!=0 || is_neg==false);
			
			assert(!(cnt>19 || ( cnt==19 && fi>1) ));
		} else if(g==endd){
			if(is_neg){
				x= -x;
			}
			assert(l<=x && x<=r);
			return x;
		} else {
			assert(false);
		}
	}
}
string readString(char endd){
	string ret="";
	while(true){
		char g=getchar();
		if(g==endd || g==-1){
			break;
		}
		
		ret+=g;
	}
	return ret;
}
long long readIntSp(long long l,long long r){
	return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
	return readInt(l,r,'\n');
}
string readStringLn(){
	return readString('\n');
}
string readStringSp(){
	return readString(' ');
}
int timest(string a){
	assert(a.length()==8);
	assert(a[2]==':');
	assert(a[5]==':');
	int h1=a[0]-'0';
	for(int i=0;i<8;i++){
		if(i==2 || i==5)continue;
		assert('0' <= a[i] && a[i]<='9');
	}
	h1 = h1 * 10 + a[1]-'0';
	int m1 = a[3]-'0';
	m1 = m1* 10 + a[4]-'0';
	int s1 = a[6]-'0';
	s1 = s1 * 10 + a[7]-'0';
	assert(0<=h1 && h1<=23);
	assert(0<=m1 && m1<=59);
	assert(0<=s1 && s1<=59);
	return s1 + 60*m1 + 60*60*h1;
}
string watch[55];
string alarm[55];
int n,k;
int T;
int dp[55][1<<18];
int dist[55][55];
int dis[90000];
void calc_dist(){
	queue<int> bf;
	int mod=60*60*24; 
	for(int i=1;i<=n;i++){
		for(int i=0;i<mod;i++){
			dis[i]=1<<30;
		}
		int st=timest(watch[i]);
		dis[st]=0;
		bf.push(st);
		while(!bf.empty()){
			int nd=bf.front();
			bf.pop();
			int ch= (nd+1)%mod;
			if(dis[ch] == 1<<30){
				dis[ch]= dis[nd]+1;
				bf.push(ch);
			}
			ch=(mod+nd-1)%mod;
			if(dis[ch] == 1<<30){
				dis[ch]= dis[nd]+1;
				bf.push(ch);
			}
			ch= (nd+60)%mod;
			if(dis[ch] == 1<<30){
				dis[ch]= dis[nd]+1;
				bf.push(ch);
			}
			ch=(mod+nd-60)%mod;
			if(dis[ch] == 1<<30){
				dis[ch]= dis[nd]+1;
				bf.push(ch);
			}
			ch= (nd+60*60)%mod;
			if(dis[ch] == 1<<30){
				dis[ch]= dis[nd]+1;
				bf.push(ch);
			}
			ch=(mod+nd-60*60)%mod;
			if(dis[ch] == 1<<30){
				dis[ch]= dis[nd]+1;
				bf.push(ch);
			}
		}
		for(int j=0;j<k;j++){
			dist[i][j] = dis[timest(alarm[j])];
		}
	}
}
int main(){
	//cin>>T;
	T=readIntLn(1,2);
	while(T--){
		//cin>>n>>k;
		n=readIntSp(1,50);
		k=readIntLn(1,17);
		assert(k<=n);
		for(int i=1;i<=n;i++){
			//cin>>watch[i];
			watch[i]=readStringLn();
		}
		for(int i=0;i<k;i++){
			//cin>>alarm[i];
			alarm[i]=readStringLn();
		}
		calc_dist();
		dp[0][0]=0;
		for(int i=1;i<(1<<18);i++){
			dp[0][i]=1<<30;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<(1<<k);j++){
				dp[i][j] = dp[i-1][j];
				for(int u=0;u<k;u++){
					if(j & (1<<u)){
						dp[i][j] = min(dp[i][j], dp[i-1][j- (1<<u)] + dist[i][u] );
					}
				}
			}
		}
		cout<<dp[n][(1<<k)-1]<<endl;
	}
	assert(getchar()==-1);
}

*/

/*Best Submissions:
C:


C++:
    #include <bits/stdc++.h>
    #define pb push_back
    #define mp make_pair
    #define int64 long long int
    #define unit64 unsigned long long int
    using namespace std;
     
    const int N = 55;
     
    int n, m;
    string st;
    int a[N][N];
    int H1[N], M1[N], S1[N];
    int H2[N], M2[N], S2[N];
     
    vector <int> hungarian (void)
    {
    	// Global a[n][m] is the input matrix.
    	// I don't know how the hell this is O (n^3)
    	// but believe me this shit is O (n ^ 3).
    	//
    	vector<int> u (n + 1), v (m + 1), p (m + 1), way (m + 1);
    	for (int i = 1; i <= n; i++) {
    		p[0] = i;
    		int j0 = 0;
    		vector<int> minv (m + 1, 1000000000);
    		vector<char> used (m + 1, false);
    		do {
    			used[j0] = true;
    			int i0 = p[j0], j1, delta = 1000000000;
    			for (int j = 1; j <= m; j++)
    			if (!used[j]) {
    				int cur = a[i0][j] - u[i0] - v[j];
    				if (cur < minv[j])
    					minv[j] = cur, way[j] = j0;
    				if (minv[j] < delta)
    					delta = minv[j], j1 = j;
    			}
    			for (int j = 0; j <= m; j++)
    			if (used[j])
    				u[p[j]] += delta, v[j] -= delta;
    			else
     				minv[j] -= delta;
    			j0 = j1;
    		} while (p[j0] != 0);
    		do {
    			int j1 = way[j0];
    			p[j0] = p[j1];
    			j0 = j1;
    		} while (j0);
    	}
    	vector <int> ans (n + 1);
    	for (int i = 1; i <= m; i++) {
    		ans[p[i]] = i;
    	}
    	return ans;
    }
     
    int findmin (int I, int J)
    {
    	int ret = 1000000000;
    	for (int i = 0; i <= 1; i++) {
    		for (int j = 0; j <= 1; j++) {
    			for (int k = 0; k <= 1; k++) {
     
    				int H = H1[J], M = M1[J], S = S1[J];
    				int hh = H2[I], mm = M2[I], ss = S2[I];
 
    				if (i == 0 && S < ss) {
    					if (mm == 59) {
    						mm = 0;
    						hh++;
    						if (hh == 24) hh = 0;
    					} else mm++;
    					if (mm == 60) mm = 0;
    				}
    				if (i == 1 && S > ss) {
    					if (mm == 0) {
    						mm = 59;
    						hh--;
    						if (hh < 0) hh = 23;
    					} else mm--;
    					if (mm < 0) mm = 59;
    				}
    				if (j == 0 && M < mm) {
    					hh++;
    					if (hh == 24) hh = 0;
 
					}
    				if (j == 1 && M > mm) {
    					hh--;
    					if (hh < 0) hh = 23;
    				}
    				int ans = 0;
    				if (i == 0) {
    					if (S >= ss) ans += S - ss;
    					else ans += 60 - ss + S;
    				} else {
    					if (S <= ss) ans += ss - S;
    					else ans += 60 - S + ss;
    				}
    				if (j == 0) {
    					if (M >= mm) ans += M - mm;
    					else ans += 60 - mm + M;
    				} else {
    					if (M <= mm) ans += mm - M;
    					else ans += 60 - M + mm;
    				}
    				if (k == 0) {
    					if (H >= hh) ans += H - hh;
    					else ans += 24 - hh + H;
    				} else {
    					if (H <= hh) ans += hh - H;
    					else ans += 24 - H + hh;
    				}
    				ret = min (ret, ans);
    			}
    		}
    	}
    	return ret;
    }
    void solve ()
    {
    	scanf ("%d %d", &m, &n);
    	for (int i = 1; i <= m; i++) {
    		cin >> st;
    		H1[i] = 10 * (st[0] - '0') + st[1] - '0';
    		M1[i] = 10 * (st[3] - '0') + st[4] - '0';
    		S1[i] = 10 * (st[6] - '0') + st[7] - '0';
    	}
    	for (int i = 1; i <= n; i++) {
    		cin >> st;
    		H2[i] = 10 * (st[0] - '0') + st[1] - '0';
    		M2[i] = 10 * (st[3] - '0') + st[4] - '0';
    		S2[i] = 10 * (st[6] - '0') + st[7] - '0';
    	}
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= m; j++) {
    			a[i][j] = findmin (i, j);
    		}
    	}
    	vector <int> ans = hungarian ();
    	int sum = 0;
    	for (int i = 1; i <= n; i++) {
    		sum += a[i][ans[i]];
    	}
    	printf ("%d\n", sum);
    }
    int main ()
    {
    	int t;
    	scanf ("%d", &t);
    	while (t--) solve ();
    	return 0;
    }

Alt. Solution:
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <string>
#include <cassert>
 
using namespace std;
 
typedef long long LL;
typedef vector < int > VI;
typedef pair < int,int > II;
typedef vector < II > VII;
const int MOD = 1e9+7;
inline int mult(int a , int b) { LL x = a; x *= LL(b); if(x >= MOD) x %= MOD; return x; }
inline int add(int a , int b) { return a + b >= MOD ? a + b - MOD : a + b; }
inline int sub(int a , int b) { return a - b < 0 ? MOD - b + a : a - b; }
LL powmod(LL a,LL b) { if(b==0)return 1; LL x=powmod(a,b/2); LL y=(x*x)%MOD; if(b%2) return (a*y)%MOD; return y%MOD; }
 
struct Time {
  int h, m, s;
};
Time move(int i, Time cur) {
  if (i == 0) {
    cur.h = (cur.h + 1) % 24; return cur;
  }
  if (i == 1) {
    cur.h = (cur.h + 23) % 24; return cur;
  }
  if (i == 2) {
    cur.m ++;
    if(cur.m == 60) {
      cur.m = 0, cur = move(0, cur);
    } return cur;
  }
  if (i == 3) {
    cur.m --;
    if(cur.m == -1) {
      cur.m = 59, cur = move(1, cur);
    } return cur;
  }
  if (i == 4) {
    cur.s ++;
    if(cur.s == 60) {
      cur.s = 0, cur = move(2, cur);
    } return cur;
  }
  cur.s --;
  if(cur.s == -1) {
    cur.s = 59, cur = move(3, cur);
  } return cur;
}
 
int n, k;
int dp[51][1<<17];
int getID(Time t) {
  return t.s + 60 * t.m + 60 * 60 * t.h;
}
int bfs[18][60 * 60 * 24 + 1];
Time rev[60*60*24];
Time clocks[51], alarms[18];
int go(int i, int mask) {
  if(mask == (1<<k)-1)
    return 0;
  if(i == n) return MOD;
  if(dp[i][mask] != -1)
    return dp[i][mask];
  int ret = go(i+1, mask);
  for(int j = 0; j < k; j ++)
    if(!(mask & (1<<j)))
      ret = min(ret, bfs[j][getID(clocks[i])] + go(i+1, (mask|(1<<j))));
  return dp[i][mask] = ret;
}
int main() {
  for(int i = 0; i < 60*60*24; i ++) {
    rev[i].s = i%60;
    rev[i].m = (i/60)%60;
    rev[i].h = (i/(60*60))%24;
  }
  int t; cin >> t;
  while(t --) {
    cin >> n >> k;
    for(int i = 0; i < n; i ++) {
      string s; cin >> s;
      clocks[i].h = (s[0]-'0')*10+(s[1]-'0');
      clocks[i].m = (s[3]-'0')*10+(s[4]-'0');
      clocks[i].s = (s[6]-'0')*10+(s[7]-'0');
    }
    for(int i = 0; i < k; i ++) {
      string s; cin >> s;
      alarms[i].h = (s[0]-'0')*10+(s[1]-'0');
      alarms[i].m = (s[3]-'0')*10+(s[4]-'0');
      alarms[i].s = (s[6]-'0')*10+(s[7]-'0');
    }
    memset(bfs, -1, sizeof(bfs));
    for(int i = 0; i < k; i ++) {
      queue<int>q;
      q.push(getID(alarms[i]));
      bfs[i][getID(alarms[i])] = 0;
      while(!q.empty()) {
        int tp = q.front();
        q.pop();
        Time cur = rev[tp];
        for(int l = 0; l < 6; l ++) {
          int id = getID(move(l, cur));
          if(bfs[i][id] == -1) {
            bfs[i][id] = bfs[i][tp] + 1;
            q.push(id);
          }
        }
      }
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << endl;
  }
  return 0;
}

	
	
Java:
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Arrays;
import java.util.InputMismatchException;

 class HungarianBipartiteMatching
{
    private final double[][] costMatrix;
    private final int        rows, cols, dim;
    private final double[]   labelByWorker, labelByJob;
    private final int[]      minSlackWorkerByJob;
    private final double[]   minSlackValueByJob;
    private final int[]      matchJobByWorker, matchWorkerByJob;
    private final int[]      parentWorkerByCommittedJob;
    private final boolean[]  committedWorkers;
 
    public HungarianBipartiteMatching(double[][] costMatrix)
    {
        this.dim = Math.max(costMatrix.length, costMatrix[0].length);
        this.rows = costMatrix.length;
        this.cols = costMatrix[0].length;
        this.costMatrix = new double[this.dim][this.dim];
        for (int w = 0; w < this.dim; w++)
        {
            if (w < costMatrix.length)
            {
                if (costMatrix[w].length != this.cols)
                {
                    throw new IllegalArgumentException("Irregular cost matrix");
                }
                this.costMatrix[w] = Arrays.copyOf(costMatrix[w], this.dim);
            }
            else
            {
                this.costMatrix[w] = new double[this.dim];
            }
        }
        labelByWorker = new double[this.dim];
        labelByJob = new double[this.dim];
        minSlackWorkerByJob = new int[this.dim];
        minSlackValueByJob = new double[this.dim];
        committedWorkers = new boolean[this.dim];
        parentWorkerByCommittedJob = new int[this.dim];
        matchJobByWorker = new int[this.dim];
        Arrays.fill(matchJobByWorker, -1);
        matchWorkerByJob = new int[this.dim];
        Arrays.fill(matchWorkerByJob, -1);
    }
 
    protected void computeInitialFeasibleSolution()
    {
        for (int j = 0; j < dim; j++)
        {
            labelByJob[j] = Double.POSITIVE_INFINITY;
        }
        for (int w = 0; w < dim; w++)
        {
            for (int j = 0; j < dim; j++)
            {
                if (costMatrix[w][j] < labelByJob[j])
                {
                    labelByJob[j] = costMatrix[w][j];
                }
            }
        }
    }
 
    public int[] execute()
    {
        //
        // Heuristics to improve performance: Reduce rows and columns by their
        // smallest element, compute an initial non-zero dual feasible solution
        // and
        // create a greedy matching from workers to jobs of the cost matrix.
        //
        reduce();
        computeInitialFeasibleSolution();
        greedyMatch();
        int w = fetchUnmatchedWorker();
        while (w < dim)
        {
            initializePhase(w);
            executePhase();
            w = fetchUnmatchedWorker();
        }
        int[] result = Arrays.copyOf(matchJobByWorker, rows);
        for (w = 0; w < result.length; w++)
        {
            if (result[w] >= cols)
            {
                result[w] = -1;
            }
        }
        return result;
    }
 
    protected void executePhase()
    {
        while (true)
        {
            int minSlackWorker = -1, minSlackJob = -1;
            double minSlackValue = Double.POSITIVE_INFINITY;
            for (int j = 0; j < dim; j++)
            {
                if (parentWorkerByCommittedJob[j] == -1)
                {
                    if (minSlackValueByJob[j] < minSlackValue)
                    {
                        minSlackValue = minSlackValueByJob[j];
                        minSlackWorker = minSlackWorkerByJob[j];
                        minSlackJob = j;
                    }
                }
            }
            if (minSlackValue > 0)
            {
                updateLabeling(minSlackValue);
            }
            parentWorkerByCommittedJob[minSlackJob] = minSlackWorker;
            if (matchWorkerByJob[minSlackJob] == -1)
            {
                //
                //An augmenting path has been found.
                //
                int committedJob = minSlackJob;
                int parentWorker = parentWorkerByCommittedJob[committedJob];
                while (true)
                {
                    int temp = matchJobByWorker[parentWorker];
                    match(parentWorker, committedJob);
                    committedJob = temp;
                    if (committedJob == -1)
                    {
                        break;
                    }
                    parentWorker = parentWorkerByCommittedJob[committedJob];
                }
                return;
            }
            else
            {
                //
                //Update slack values since we increased the size of the
                //committed
                //workers set.
                //
                int worker = matchWorkerByJob[minSlackJob];
                committedWorkers[worker] = true;
                for (int j = 0; j < dim; j++)
                {
                    if (parentWorkerByCommittedJob[j] == -1)
                    {
                        double slack = costMatrix[worker][j]
                                - labelByWorker[worker] - labelByJob[j];
                        if (minSlackValueByJob[j] > slack)
                        {
                            minSlackValueByJob[j] = slack;
                            minSlackWorkerByJob[j] = worker;
                        }
                    }
                }
            }
        }
    }
 
    protected int fetchUnmatchedWorker()
    {
        int w;
        for (w = 0; w < dim; w++)
        {
            if (matchJobByWorker[w] == -1)
            {
                break;
            }
        }
        return w;
    }
 
    protected void greedyMatch()
    {
        for (int w = 0; w < dim; w++)
        {
            for (int j = 0; j < dim; j++)
            {
                if (matchJobByWorker[w] == -1
                        && matchWorkerByJob[j] == -1
                        && costMatrix[w][j] - labelByWorker[w] - labelByJob[j] == 0)
                {
                    match(w, j);
                }
            }
        }
    }
 
    protected void initializePhase(int w)
    {
        Arrays.fill(committedWorkers, false);
        Arrays.fill(parentWorkerByCommittedJob, -1);
        committedWorkers[w] = true;
        for (int j = 0; j < dim; j++)
        {
            minSlackValueByJob[j] = costMatrix[w][j] - labelByWorker[w]
                    - labelByJob[j];
            minSlackWorkerByJob[j] = w;
        }
    }
 
    protected void match(int w, int j)
    {
        matchJobByWorker[w] = j;
        matchWorkerByJob[j] = w;
    }
 
    protected void reduce()
    {
        for (int w = 0; w < dim; w++)
        {
            double min = Double.POSITIVE_INFINITY;
            for (int j = 0; j < dim; j++)
            {
                if (costMatrix[w][j] < min)
                {
                    min = costMatrix[w][j];
                }
            }
            for (int j = 0; j < dim; j++)
            {
                costMatrix[w][j] -= min;
            }
        }
        double[] min = new double[dim];
        for (int j = 0; j < dim; j++)
        {
            min[j] = Double.POSITIVE_INFINITY;
        }
        for (int w = 0; w < dim; w++)
        {
            for (int j = 0; j < dim; j++)
            {
                if (costMatrix[w][j] < min[j])
                {
                    min[j] = costMatrix[w][j];
                }
            }
        }
        for (int w = 0; w < dim; w++)
        {
            for (int j = 0; j < dim; j++)
            {
                costMatrix[w][j] -= min[j];
            }
        }
    }
 
    protected void updateLabeling(double slack)
    {
        for (int w = 0; w < dim; w++)
        {
            if (committedWorkers[w])
            {
                labelByWorker[w] += slack;
            }
        }
        for (int j = 0; j < dim; j++)
        {
            if (parentWorkerByCommittedJob[j] != -1)
            {
                labelByJob[j] -= slack;
            }
            else
            {
                minSlackValueByJob[j] -= slack;
            }
        }
    }
 
    
}
 
public class zu {
	public static void main(String[] args) throws IOException 
	{
		int t=i();
		for(int r=0;r<t;r++)
		{
			
		
	int n=i(),k=i();
	int m[]=new int[n];
	int h[]=new int[n];
	int s[]=new int[n];
	int a[]=new int[k];
	int b[]=new int[k];
	int c[]=new int[k];
	for(int j=0;j<n;j++)
	{
		String q=s();
		String x[]=q.split(":");
		h[j]=Integer.parseInt(x[0]);
		m[j]=Integer.parseInt(x[1]);
		s[j]=Integer.parseInt(x[2]);
		//out.println(m[j]);
	}
	double v[][]=new double[k][n];
	for(int z=0;z<k;z++)
	{
		String e=s();
		String x[]=e.split(":");
		int h1=Integer.parseInt(x[0]);
		int m1=Integer.parseInt(x[1]);
		int s1=Integer.parseInt(x[2]);
		int hs=h1;
		int ms=m1;
		int ss=s1;
		for(int g=0;g<n;g++)
		{
			int j=Math.abs(s[g]-s1);
			if(j<60-j)
			{
				v[z][g]=v[z][g]+j;
			}
			else 
			{
				
				v[z][g]=v[z][g]+60-j;
				if(s[g]<s1)
				{
					m1=(m1+1)%60;
				}
				else
				{
					m1=(m1-1)%60;
				}
			}
            
			 j=Math.abs(m[g]-m1);
			// out.println(v[z][g]);
			if(j<60-j)
			{
				v[z][g]=v[z][g]+j;
			}
			else 
			{
				v[z][g]=v[z][g]+60-j;
				if(m[g]<m1)
				{
					h1=(h1+1)%24;
				}
				else
				{
					h1=(h1-1)%24;
				}
			}
			//out.println(v[z][g]);
			 j=Math.abs(h[g]-h1);
				if(j<24-j)
				{
					v[z][g]=v[z][g]+j;
				}
				else 
				{
					v[z][g]=v[z][g]+24-j;
					
				}
				h1=hs;
				 m1=ms;
				 s1=ss;
			//out.println(v[z][g]);
		}
		 
		
	}
	 HungarianBipartiteMatching hbm = new HungarianBipartiteMatching(v);
     int[] result = hbm.execute();
     long se=0;
    for(int re=0;re<k;re++)
    {
    	se=se+(long)v[re][result[re]];
    }
	out.println(se);
	
		}
		out.close();
	}
	static InputReader in = new InputReader(System.in);
    static OutputWriter out = new OutputWriter(System.out);
    
    static int i()
    {
    	return in.readInt();
    }
    
    static long l()
    {
    	return in.readLong();
    }
    
    static double d()
    {
    	return in.readDouble();
    }
    
    static String s()
    {
    	return in.readString();
    }
    
    static void Iarr( int[] array, int no )
    {
    	for( int i=0 ; i<no ; i++ )
    	{
    		array[i] = i(); 
    	}
    }
    
    static void Larr( long[] array, int no )
    {
    	for( int i=0 ; i<no ; i++ )
    	{
    		array[i] = l(); 
    	}
    }
    
    static void Darr( double[] array, int no )
    {
    	for( int i=0 ; i<no ; i++ )
    	{
    		array[i] = d(); 
    	}
    }
    
    static void Sarr( String[] array, int no )
    {
    	for( int i=0 ; i<no ; i++ )
    	{
    		array[i] = s(); 
    	}
    }
    
    private static class InputReader
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
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars)
            {
                curChar = 0;
                try
                {
                    numChars = stream.read(buf);
                } catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }
 
        public int readInt()
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
            int res = 0;
            do
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
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
            } while (!isSpaceChar(c));
            return res.toString();
        }
        public double readDouble() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, readInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, readInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }
        public long readLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
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
 
    private static class OutputWriter
    {
        private final PrintWriter writer;
 
        public OutputWriter(OutputStream outputStream)
        {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }
 
        public OutputWriter(Writer writer)
        {
            this.writer = new PrintWriter(writer);
        }
 
        public void print(Object... objects)
        {
            for (int i = 0; i < objects.length; i++)
            {
                if (i != 0)
                    writer.print(' ');
                writer.print(objects[i]);
            }
        }
 
        public void println(Object... objects)
        {
            print(objects);
            writer.println();
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

import java.awt.Checkbox;
import java.awt.Point;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.Map.Entry;
 
import javax.print.attribute.SetOfIntegerSyntax;
 
     
public class Main{
        		  	private static InputStream stream;
        		    	private static byte[] buf = new byte[1024];
        		    	private static int curChar;
        		    	private static int numChars;
        		    	private static SpaceCharFilter filter;
        		    	private static PrintWriter pw;
        		    	private static long count = 0,mod=1000000007;
        		    //	private static TreeSet<Integer> ts=new TreeSet[200000];
        		    	public final static int INF = (int) 1E9;
 
        		        
        		        public static void main(String[] args) {
        		        	InputReader(System.in);
        		    		pw = new PrintWriter(System.out); 
        		            new Thread(null ,new Runnable(){
        		               public void run(){
        		                   try{
        		                       solve();
        		                       pw.close();
        		                   } catch(Exception e){
        		                       e.printStackTrace();
        		                   }
        		               }
        		           },"1",1<<26).start();
        		       }
        		        public static void Merge(long a[],int p,int r){
        		            if(p<r){
        		                int q = (p+r)/2;
        		                Merge(a,p,q);
        		                Merge(a,q+1,r);
        		                Merge_Array(a,p,q,r);
        		            }
        		        }
        		        public static void Merge_Array(long a[],int p,int q,int r){
        		           long b[] = new long[q-p+1];
        		            long c[] = new long[r-q];
        		            for(int i=0;i<b.length;i++)
        		                b[i] = a[p+i];
        		            for(int i=0;i<c.length;i++)
        		                c[i] = a[q+i+1];
        		            int i = 0,j = 0;
        		            for(int k=p;k<=r;k++){
        		                if(i==b.length){
        		                    a[k] = c[j];
        		                    j++;
        		                }
        		                else if(j==c.length){
        		                    a[k] = b[i];
        		                    i++;
        		                }
        		                else if(b[i]<c[j]){
        		                    a[k] = b[i];
        		                    i++;
        		                }
        		                else{
        		                    a[k] = c[j];
        		                    j++;
        		                }
        		            }
        		        }
        		    	public static long gcd(long x, long y) {
        		    		if (x == 0)
        		    			return y;
        		    		else
        		    			return gcd( y % x,x);
        		    	}	public static boolean isPrime(int n) {
        		    	// Corner cases
			    		if (n <= 1)
			    			return false;
			    		if (n <= 3)
			    			return true;
			     
			    		// This is checked so that we can skip 
			    		// middle five numbers in below loop
			    		if (n % 2 == 0 || n % 3 == 0)
			    			return false;
			     
			    		for (int i = 5; i * i <= n; i = i + 6)
			    			if (n % i == 0 || n % (i + 2) == 0)
			    				return false;
			     
			    		return true;
			    	}
        		        static LinkedList<Integer> adj[];
        		        static boolean Visited[];
        		        static HashSet<Integer> exc;
        		        static long oddsum[]=new long[1000001];
        		        static int co=0,ans=0;
        		       
        		        public static void solve() {
 
        		        	int t=nextInt();
        		        		while(t-->0)
        		        	{
        		        	
        		        	int n=nextInt();
        		        	int k=nextInt();
        		        	Pair curr_time[]=new Pair[n];
        		        	Pair req[]=new Pair[k];
        		        	for(int i=0;i<n;i++){
        		        		String  s=nextLine();
        		        		String arr[]=s.split(":");
        		        		curr_time[i]=new Pair(Integer.parseInt(arr[0]),Integer.parseInt(arr[1]),Integer.parseInt(arr[2]));
        		        		
        		        	}
        		        	for(int i=0;i<k;i++){
        		        		String  s=nextLine();
        		        		String arr[]=s.split(":");
        		        		req[i]=new Pair(Integer.parseInt(arr[0]),Integer.parseInt(arr[1]),Integer.parseInt(arr[2]));
        		        		
        		        	}
        		        	
        		        	double time[][]=new double[n][k];
        		        	for(int i=0;i<n;i++){
        		        		for(int j=0;j<k;j++){
        		        			time[i][j]=calc_all_poss(curr_time[i], req[j]);
        		        		}
        		        	}
        		            HungarianBipartiteMatching hbm = new HungarianBipartiteMatching(time);
 
        		            int[] result = hbm.execute();
        		        	long ans=0;
        		        	for(int i=0;i<n;i++){
        		        		if(result[i]>=0)
        		        		ans+=time[i][result[i]];
        		        	}
        		        	pw.println(ans);
        		        	
        		        	
        		        	
        		        	}
        		        	
        		        }
        		        
        		        static int[] hungarianMethod(int w[][]) {
        		            final int n = w.length, m = w[0].length, PHI = -1, NOL = -2;
        		            boolean[] x[] = new boolean[n][m], ss = new boolean[n], st = new boolean[m];
        		            int[] u = new int[n], v = new int[m], p = new int[m], ls = new int[n], lt = new int[m], a = new int[n];
        		            int f = 0;
 
        		            for (int i = 0; i < n; i++)
        		                for (int j = 0; j < m; j++)
        		                    f = Math.max(f, w[i][j]);
 
        		            Arrays.fill(u, f);
        		            Arrays.fill(p, INF);
        		            Arrays.fill(lt, NOL);
        		            Arrays.fill(ls, PHI);
        		            Arrays.fill(a, -1);
 
        		            while (true) {
        		                f = -1;
        		                for (int i = 0; i < n && f == -1; i++)
        		                    if (ls[i] != NOL && !ss[i])
        		                        f = i;
 
        		                if (f != -1) {
        		                    ss[f] = true;
        		                    for (int j = 0; j < m; j++)
        		                        if (!x[f][j] && u[f] + v[j] - w[f][j] < p[j]) {
        		                            lt[j] = f;
        		                            p[j] = u[f] + v[j] - w[f][j];
        		                        }
        		                } else {
        		                    for (int i = 0; i < m && f == -1; i++)
        		                        if (lt[i] != NOL && !st[i] && p[i] == 0)
        		                            f = i;
 
        		                    if (f == -1) {
        		                        int d1 = INF, d2 = INF, d;
        		                        for (int i : u)
        		                            d1 = Math.min(d1, i);
 
        		                        for (int i : p)
        		                            if (i > 0)
        		                                d2 = Math.min(d2, i);
 
        		                        d = Math.min(d1, d2);
 
        		                        for (int i = 0; i < n; i++)
        		                            if (ls[i] != NOL)
        		                                u[i] -= d;
 
        		                        for (int i = 0; i < m; i++) {
        		                            if (p[i] == 0)
        		                                v[i] += d;
        		                            if (p[i] > 0 && lt[i] != NOL)
        		                                p[i] -= d;
        		                        }
 
        		                        if (d2 >= d1)
        		                            break;
        		                    } else {
        		                        st[f] = true;
        		                        int s = -1;
 
        		                        for (int i = 0; i < n && s == -1; i++)
        		                            if (x[i][f])
        		                                s = i;
 
        		                        if (s == -1) {
        		                            for (int l, r; ; f = r) {
        		                                r = f;
        		                                l = lt[r];
 
        		                                if (r >= 0 && l >= 0)
        		                                    x[l][r] = !x[l][r];
        		                                else
        		                                    break;
 
        		                                r = ls[l];
        		                                if (r >= 0 && l >= 0)
        		                                    x[l][r] = !x[l][r];
        		                                else
        		                                    break;
        		                            }
 
        		                            Arrays.fill(p, INF);
        		                            Arrays.fill(lt, NOL);
        		                            Arrays.fill(ls, NOL);
        		                            Arrays.fill(ss, false);
        		                            Arrays.fill(st, false);
 
        		                            for (int i = 0; i < n; i++) {
        		                                boolean ex = true;
        		                                for (int j = 0; j < m && ex; j++)
        		                                    ex = !x[i][j];
        		                                if (ex)
        		                                    ls[i] = PHI;
        		                            }
        		                        } else
        		                            ls[s] = f;
        		                    }
        		                }
        		            }
 
        		            for (int i = 0; i < n; i++)
        		                for (int j = 0; j < m; j++)
        		                    if (x[i][j])
        		                        a[j] = i;
        		            return a;
        		    }
        		        
        		     static   boolean incnotifier=false,decnotifier=false;
        		     
        		     
        		     public static int calc_all_poss(Pair curr_time,Pair req_time){
        		    	 int tot_op=Integer.MAX_VALUE;
        		    	 //case 1
        		    	 reset();
        		    	 int op=cal_sec_fwd(curr_time.s, req_time.s);
        		    	 if(incnotifier){
        		    		 reset();
        		    		 op+=cal_min_fwd(curr_time.m+1, req_time.m);
        		    	 }
        		    	 else if(decnotifier){
        		    		 reset();
        		    		 op+=cal_min_fwd(curr_time.m-1, req_time.m);
        		    	 }
        		    	 else{
        		    		 reset();
        		    		 op+=cal_min_fwd(curr_time.m, req_time.m);
        		    	 }
        		    	 
        		    	 if(incnotifier){
        		    		 reset();
        		    		 op+=Math.min(cal_hr_fwd(curr_time.h+1, req_time.h),cal_hr_rev(curr_time.h+1, req_time.h));
        		    	 
        		    	 }
        		    	 else if(decnotifier){
        		    		 reset();
        		    		 op+=Math.min(cal_hr_fwd(curr_time.h-1, req_time.h),cal_hr_rev(curr_time.h-1, req_time.h));
            		    	 	 }
        		    	 else{
        		    		 reset();
        		    		 op+=Math.min(cal_hr_fwd(curr_time.h, req_time.h),cal_hr_rev(curr_time.h, req_time.h));
            		    	}
        		    	 tot_op=Math.min(tot_op, op);
        		    	 
        		    	 //case 2
        		    	 reset();
        		    	 op=cal_sec_fwd(curr_time.s, req_time.s);
        		    	 if(incnotifier){
        		    		 reset();
        		    		 op+=cal_min_rev(curr_time.m+1, req_time.m);
        		    	 }
        		    	 else if(decnotifier){
        		    		 reset();
        		    		 op+=cal_min_rev(curr_time.m-1, req_time.m);
        		    	 }
        		    	 else{
        		    		 reset();
        		    		 op+=cal_min_rev(curr_time.m, req_time.m);
        		    	 }
        		    	 
        		    	 if(incnotifier){
        		    		 reset();
        		    		 op+=Math.min(cal_hr_fwd(curr_time.h+1, req_time.h),cal_hr_rev(curr_time.h+1, req_time.h));
        		    	 
        		    	 }
        		    	 else if(decnotifier){
        		    		 reset();
        		    		 op+=Math.min(cal_hr_fwd(curr_time.h-1, req_time.h),cal_hr_rev(curr_time.h-1, req_time.h));
            		    	 	 }
        		    	 else{
        		    		 reset();
        		    		 op+=Math.min(cal_hr_fwd(curr_time.h, req_time.h),cal_hr_rev(curr_time.h, req_time.h));
            		    	}
        		    	 tot_op=Math.min(tot_op, op);
        		    	
        		    	 
        		    	 //case 3
        		    	 reset();
        		    	  op=cal_sec_rev(curr_time.s, req_time.s);
        		    	 if(incnotifier){
        		    		 reset();
        		    		 op+=cal_min_fwd(curr_time.m+1, req_time.m);
        		    	 }
        		    	 else if(decnotifier){
        		    		 reset();
        		    		 op+=cal_min_fwd(curr_time.m-1, req_time.m);
        		    	 }
        		    	 else{
        		    		 reset();
        		    		 op+=cal_min_fwd(curr_time.m, req_time.m);
        		    	 }
        		    	 
        		    	 if(incnotifier){
        		    		 reset();
        		    		 op+=Math.min(cal_hr_fwd(curr_time.h+1, req_time.h),cal_hr_rev(curr_time.h+1, req_time.h));
        		    	 
        		    	 }
        		    	 else if(decnotifier){
        		    		 reset();
        		    		 op+=Math.min(cal_hr_fwd(curr_time.h-1, req_time.h),cal_hr_rev(curr_time.h-1, req_time.h));
            		    	 	 }
        		    	 else{
        		    		 reset();
        		    		 op+=Math.min(cal_hr_fwd(curr_time.h, req_time.h),cal_hr_rev(curr_time.h, req_time.h));
            		    	}
        		    	 tot_op=Math.min(tot_op, op);
        		    	 
        		     
 
        		    	 //case 4
        		    	 reset();
        		    	 op=cal_sec_rev(curr_time.s, req_time.s);
        		    	 if(incnotifier){
        		    		 reset();
        		    		 op+=cal_min_rev(curr_time.m+1, req_time.m);
        		    	 }
        		    	 else if(decnotifier){
        		    		 reset();
        		    		 op+=cal_min_rev(curr_time.m-1, req_time.m);
        		    	 }
        		    	 else{
        		    		 reset();
        		    		 op+=cal_min_rev(curr_time.m, req_time.m);
        		    	 }
        		    	 
        		    	 if(incnotifier){
        		    		 reset();
        		    		 op+=Math.min(cal_hr_fwd(curr_time.h+1, req_time.h),cal_hr_rev(curr_time.h+1, req_time.h));
        		    	 
        		    	 }
        		    	 else if(decnotifier){
        		    		 reset();
        		    		 op+=Math.min(cal_hr_fwd(curr_time.h-1, req_time.h),cal_hr_rev(curr_time.h-1, req_time.h));
            		    	 	 }
        		    	 else{
        		    		 reset();
        		    		 op+=Math.min(cal_hr_fwd(curr_time.h, req_time.h),cal_hr_rev(curr_time.h, req_time.h));
            		    	}
        		    	 tot_op=Math.min(tot_op, op);
        		    	 return tot_op;
        		    	
        		     }
        		     
        		     public static void reset(){
        		    	 incnotifier=false;
        		    	 decnotifier=false;
        		     }
        		     //calculate seconds 
        		     public static int cal_sec_fwd(int curr_sec,int req_sec){
        		        	int tot_op=0;
        		        	for(int i=curr_sec;;i++){
        		        		if(i>=60){
        		        		i=i%60;
        		        		incnotifier=true;
        		        		}
            		        	
        		        		if(i==req_sec){
        		        			break;
        		        		}
        		        		tot_op++;
        		        		
        		        	}
        		
        		        	return tot_op;
        		        }
        		        public static int cal_sec_rev(int curr_sec,int req_sec){
        		        	int tot_op=0;
        		         	for(int i=curr_sec;;i--){
        		        		if(i<0){
            		        		i=59;
            		        		decnotifier=true;
            		        		
        		        		}
                		        	
            		        		if(i==req_sec){
            		        			break;
            		        		}
            		        		tot_op++;
            		        		
        		        	}
        		       return tot_op;
        		        }
        		        
        		     //calc minutes
        		        public static int cal_min_fwd(int curr_min,int req_min){
        		        	int tot_op=0;
        		        	for(int i=curr_min;;i++){
        		        		if(i>=60){
        		        		i=i%60;
        		        		incnotifier=true;
        		        		}
            		        	
        		        		if(i==req_min){
        		        			break;
        		        		}
        		        		tot_op++;
        		        		
        		        	}
        		
        		        	return tot_op;
        		        }
        		        
        		        public static int cal_min_rev(int curr_min,int req_min){
        		        	int tot_op=0;
        		         	for(int i=curr_min;;i--){
        		        		if(i<0){
            		        		i=59;
            		        		decnotifier=true;
            		        		
        		        		}
                		        	
            		        		if(i==req_min){
            		        			break;
            		        		}
            		        		tot_op++;
            		        		
        		        	}
        		       return tot_op;
        		        }
        		        
        		        // calc hours
        		        public static int cal_hr_fwd(int curr_hr,int req_hr){
        		        	int tot_op=0;
        		        	for(int i=curr_hr;;i++){
        		        		if(i>=24){
        		        		i=i%24;
        		        		incnotifier=true;
        		        		}
            		        	
        		        		if(i==req_hr){
        		        			break;
        		        		}
        		        		tot_op++;
        		        		
        		        	}
        		
        		        	return tot_op;
        		        }
        		        
        		        public static int cal_hr_rev(int curr_hr,int req_hr){
        		        	int tot_op=0;
        		         	for(int i=curr_hr;;i--){
        		        		if(i<0){
            		        		i=23;
            		        		decnotifier=true;
            		        		
        		        		}
                		        	
            		        		if(i==req_hr){
            		        			break;
            		        		}
            		        		tot_op++;
            		        		
        		        	}
        		       return tot_op;
        		        }
        		        
        		      
        		        public static long pow(long n, long p,long mod) {
        					if(p==0)
        						return 1;
        					if(p==1)
        						return n%mod;
        					if(p%2==0){
        						long temp=pow(n, p/2,mod);
        					return (temp*temp)%mod;
        					}else{
        						 	long temp=pow(n,p/2,mod);
        						 	temp=(temp*temp)%mod;
        						 	return(temp*n)%mod;
        						 	
        					}
        				}
        		        public static String reverseString(String s) {
        					StringBuilder sb = new StringBuilder(s);
        					sb.reverse();
        					return (sb.toString());
        				}
        		        
        		        
        		        private static void BFS(int n,int v,int w){
        		        	int level[]=new int[n+1];
        		        	boolean Visited[]=new boolean[n+1];
        		        	Queue<Integer> q=new LinkedList<Integer>();
        		        	q.add(v);
        		        	Visited[v]=true;
        		        	while(!q.isEmpty()){
        		        		int top=q.poll();
        		        		
        		        		for(int i:adj[top]){
        		        			//pw.println(i+" "+top);
        		        			if(!Visited[i])
        		        			{
        		        				level[i]=level[top]+1;
            		        			
        		        				q.add(i);
        		        			}
        		        			
        		        			Visited[i]=true;
        		        			if(i==w){
        		        				if(level[i]<=5)
        		        				pw.println("Yes");
        		        				else
        		        					pw.println("No");
        		        				return; 
        		        			}
        		        		}
        		        	}
        		        	
        		        	pw.println("No");
        		        }
        		        
        		        private static long ncr(int n,int k){
    				    	if (k < 0 || k > n) return 0;
    				        if (n-k < k) k = n-k;
    			
    				        BigInteger x = BigInteger.ONE;
    				        for (int i = 1; i <= k; i++) {
    				            x = x.multiply(new BigInteger(""+(n-i+1)));
    				            x = x.divide(new BigInteger(""+i));
    				        }
    			
    				return x.longValue();
    				    }
        		       private  static long fact(long count){
        		        	long ans=1;
        		        	for(int i=1;i<=count;i++){
        		        		ans*=i;
        		        	}
        		        	return ans;
        		        }
        		        
        		        
        		        static int state=1;
        		        static long no_exc=0,no_vert=0;
        		      static Stack<Integer> st;
        		      static HashSet<Integer> inset;
        		        private static void topo(int curr){
        		        	
        		        	Visited[curr]=true;
        		        	inset.add(curr);
        		        	for(int x:adj[curr]){
        		        		if(adj[x].contains(curr) || inset.contains(x)){
        		        			state=0;
        		        			return;
        		        		}
        		        		if(state==0)
        		        			return;
        		        		
        		        	}
        		        	st.push(curr);
        		        	
        		        	inset.remove(curr);
        		        }
        		        static HashSet<Integer> hs;
        		       
        		     	private static void buildgraph(int n){
        		    		adj=new LinkedList[n+1];
        		    		Visited=new boolean[n+1];
        		    		st=new Stack<Integer>();
        		    		inset=new HashSet<Integer>();
        		    		exc=new HashSet<Integer>();
        		    		
        		    		state=1;
        		    		for(int i=0;i<=n;i++){
        		    			adj[i]=new LinkedList<Integer>();
        		    		
        		    		}
     
     
        		    	}
        		     	
        		    	// To Get Input
        		    	// Some Buffer Methods
     
        		     	public static void sort(long a[]){
        		     		Merge(a, 0, a.length-1);
        		     	}
        		    	public static void InputReader(InputStream stream1) {
        		    		stream = stream1;
        		    	}
     
        		    	private static boolean isWhitespace(int c) {
        		    		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        		    	}
     
        		    	private static boolean isEndOfLine(int c) {
        		    		return c == '\n' || c == '\r' || c == -1;
        		    	}
     
        		    	private static int read() {
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
     
        		    	private static int nextInt() {
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
     
        		    	private static long nextLong() {
        		    		int c = read();
        		    		while (isSpaceChar(c))
        		    			c = read();
        		    		int sgn = 1;
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
     
        		    	private static String nextToken() {
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
     
        		    	private static String nextLine() {
        		    		int c = read();
        		    		while (isSpaceChar(c))
        		    			c = read();
        		    		StringBuilder res = new StringBuilder();
        		    		do {
        		    			res.appendCodePoint(c);
        		    			c = read();
        		    		} while (!isEndOfLine(c));
        		    		return res.toString();
        		    	}
     
        		    	private static int[] nextIntArray(int n) {
        		    		int[] arr = new int[n];
        		    		for (int i = 0; i < n; i++) {
        		    			arr[i] = nextInt();
        		    		}
        		    		return arr;
        		    	}
     
        		    	private static long[][] next2dArray(int n, int m) {
        		    		long[][] arr = new long[n][m];
        		    		for (int i = 0; i < n; i++) {
        		    			for (int j = 0; j < m; j++) {
        		    				arr[i][j] = nextLong();
        		    			}
        		    		}
        		    		return arr;
        		    	}
        		    	private static char[][] nextCharArray(int n,int m){
        		    		char [][]c=new char[n][m];
        		    		for(int i=0;i<n;i++){
        		    			String s=nextLine();
        		    			for(int j=0;j<s.length();j++){
        		    				c[i][j]=s.charAt(j);
        		    			}
        		    		}
        		    		return c;
        		    	}
     
        		    	private static long[] nextLongArray(int n) {
        		    		long[] arr = new long[n];
        		    		for (int i = 0; i < n; i++) {
        		    			arr[i] = nextLong();
        		    		}
        		    		return arr;
        		    	}
     
        		    	private static void pArray(int[] arr) {
        		    		for (int i = 0; i < arr.length; i++) {
        		    			pw.print(arr[i] + " ");
        		    		}
        		    		pw.println();
        		    		return;
        		    	}
     
        		    	private static void pArray(long[] arr) {
        		    		for (int i = 0; i < arr.length; i++) {
        		    			pw.print(arr[i] + " ");
        		    		}
        		    		pw.println();
        		    		return;
        		    	}
     
        		    	private static void pArray(boolean[] arr) {
        		    		for (int i = 0; i < arr.length; i++) {
        		    			pw.print(arr[i] + " ");
        		    		}
        		    		pw.println();
        		    		return;
        		    	}
     
        		    	private static boolean isSpaceChar(int c) {
        		    		if (filter != null)
        		    			return filter.isSpaceChar(c);
        		    		return isWhitespace(c);
        		    	}
     
        		    	private interface SpaceCharFilter {
        		    		public boolean isSpaceChar(int ch);
        		    	}
     
     
    }
        		    
        		    class HungarianBipartiteMatching
 
        		    {
 
        		        private final double[][] costMatrix;
 
        		        private final int        rows, cols, dim;
 
        		        private final double[]   labelByWorker, labelByJob;
 
        		        private final int[]      minSlackWorkerByJob;
 
        		        private final double[]   minSlackValueByJob;
 
        		        private final int[]      matchJobByWorker, matchWorkerByJob;
 
        		        private final int[]      parentWorkerByCommittedJob;
 
        		        private final boolean[]  committedWorkers;
 
        		     
 
        		        public HungarianBipartiteMatching(double[][] costMatrix)
 
        		        {
 
        		            this.dim = Math.max(costMatrix.length, costMatrix[0].length);
 
        		            this.rows = costMatrix.length;
 
        		            this.cols = costMatrix[0].length;
 
        		            this.costMatrix = new double[this.dim][this.dim];
 
        		            for (int w = 0; w < this.dim; w++)
 
        		            {
 
        		                if (w < costMatrix.length)
 
        		                {
 
        		                    if (costMatrix[w].length != this.cols)
 
        		                    {
 
        		                        throw new IllegalArgumentException("Irregular cost matrix");
 
        		                    }
 
        		                    this.costMatrix[w] = Arrays.copyOf(costMatrix[w], this.dim);
 
        		                }
 
        		                else
 
        		                {
 
        		                    this.costMatrix[w] = new double[this.dim];
 
        		                }
 
        		            }
 
        		            labelByWorker = new double[this.dim];
 
        		            labelByJob = new double[this.dim];
 
        		            minSlackWorkerByJob = new int[this.dim];
 
        		            minSlackValueByJob = new double[this.dim];
 
        		            committedWorkers = new boolean[this.dim];
 
        		            parentWorkerByCommittedJob = new int[this.dim];
 
        		            matchJobByWorker = new int[this.dim];
 
        		            Arrays.fill(matchJobByWorker, -1);
 
        		            matchWorkerByJob = new int[this.dim];
 
        		            Arrays.fill(matchWorkerByJob, -1);
 
        		        }
 
        		     
 
        		        protected void computeInitialFeasibleSolution()
 
        		        {
 
        		            for (int j = 0; j < dim; j++)
 
        		            {
 
        		                labelByJob[j] = Double.POSITIVE_INFINITY;
 
        		            }
 
        		            for (int w = 0; w < dim; w++)
 
        		            {
 
        		                for (int j = 0; j < dim; j++)
 
        		                {
 
        		                    if (costMatrix[w][j] < labelByJob[j])
 
        		                    {
 
        		                        labelByJob[j] = costMatrix[w][j];
 
        		                    }
 
        		                }
 
        		            }
 
        		        }
 
        		     
 
        		        public int[] execute()
 
        		        {
 
        		            //
                            //
        		            //Heuristics to improve performance: Reduce rows and columns by their
                            //
        		            //smallest element, compute an initial non-zero dual feasible solution
                            //
        		            //and
                            //
        		            //create a greedy matching from workers to jobs of the cost matrix.
                            //
        		            //
 
        		            reduce();
 
        		            computeInitialFeasibleSolution();
 
        		            greedyMatch();
 
        		            int w = fetchUnmatchedWorker();
 
        		            while (w < dim)
 
        		            {
 
        		                initializePhase(w);
 
        		                executePhase();
 
        		                w = fetchUnmatchedWorker();
 
        		            }
 
        		            int[] result = Arrays.copyOf(matchJobByWorker, rows);
 
        		            for (w = 0; w < result.length; w++)
 
        		            {
 
        		                if (result[w] >= cols)
 
        		                {
 
        		                    result[w] = -1;
 
        		                }
 
        		            }
 
        		            return result;
 
        		        }
 
        		     
 
        		        protected void executePhase()
 
        		        {
 
        		            while (true)
 
        		            {
 
        		                int minSlackWorker = -1, minSlackJob = -1;
 
        		                double minSlackValue = Double.POSITIVE_INFINITY;
 
        		                for (int j = 0; j < dim; j++)
 
        		                {
 
        		                    if (parentWorkerByCommittedJob[j] == -1)
 
        		                    {
 
        		                        if (minSlackValueByJob[j] < minSlackValue)
 
        		                        {
 
        		                            minSlackValue = minSlackValueByJob[j];
 
        		                            minSlackWorker = minSlackWorkerByJob[j];
 
        		                            minSlackJob = j;
 
        		                        }
 
        		                    }
 
        		                }
 
        		                if (minSlackValue > 0)
 
        		                {
 
        		                    updateLabeling(minSlackValue);
 
        		                }
 
        		                parentWorkerByCommittedJob[minSlackJob] = minSlackWorker;
 
        		                if (matchWorkerByJob[minSlackJob] == -1)
 
        		                {
 
        		                    //
                                    //
        		                    // An augmenting path has been found.
                                    //
        		                    //
 
        		                    int committedJob = minSlackJob;
 
        		                    int parentWorker = parentWorkerByCommittedJob[committedJob];
 
        		                    while (true)
 
        		                    {
 
        		                        int temp = matchJobByWorker[parentWorker];
 
        		                        match(parentWorker, committedJob);
 
        		                        committedJob = temp;
 
        		                        if (committedJob == -1)
 
        		                        {
 
        		                            break;
 
        		                        }
 
        		                        parentWorker = parentWorkerByCommittedJob[committedJob];
 
        		                    }
 
        		                    return;
 
        		                }
 
        		                else
 
        		                {
 
        		                     //
                                     //
        		                     // Update slack values since we increased the size of the
                                     //
        		                     // committed
                                     //
        		                     // workers set.
                                     //
        		                     //
 
        		                    int worker = matchWorkerByJob[minSlackJob];
 
        		                    committedWorkers[worker] = true;
 
        		                    for (int j = 0; j < dim; j++)
 
        		                    {
 
        		                        if (parentWorkerByCommittedJob[j] == -1)
 
        		                        {
 
        		                            double slack = costMatrix[worker][j]
 
        		                                    - labelByWorker[worker] - labelByJob[j];
 
        		                            if (minSlackValueByJob[j] > slack)
 
        		                            {
 
        		                                minSlackValueByJob[j] = slack;
 
        		                                minSlackWorkerByJob[j] = worker;
 
        		                            }
 
        		                        }
 
        		                    }
 
        		                }
 
        		            }
 
        		        }
 
        		     
 
        		        protected int fetchUnmatchedWorker()
 
        		        {
 
        		            int w;
 
        		            for (w = 0; w < dim; w++)
 
        		            {
 
        		                if (matchJobByWorker[w] == -1)
 
        		                {
 
        		                    break;
 
        		                }
 
        		            }
 
        		            return w;
 
        		        }
 
        		     
 
        		        protected void greedyMatch()
 
        		        {
 
        		            for (int w = 0; w < dim; w++)
 
        		            {
 
        		                for (int j = 0; j < dim; j++)
 
        		                {
 
        		                    if (matchJobByWorker[w] == -1
 
        		                            && matchWorkerByJob[j] == -1
 
        		                            && costMatrix[w][j] - labelByWorker[w] - labelByJob[j] == 0)
 
        		                    {
 
        		                        match(w, j);
 
        		                    }
 
        		                }
 
        		            }
 
        		        }
 
        		     
 
        		        protected void initializePhase(int w)
 
        		        {
 
        		            Arrays.fill(committedWorkers, false);
 
        		            Arrays.fill(parentWorkerByCommittedJob, -1);
 
        		            committedWorkers[w] = true;
 
        		            for (int j = 0; j < dim; j++)
 
        		            {
 
        		                minSlackValueByJob[j] = costMatrix[w][j] - labelByWorker[w]
 
        		                        - labelByJob[j];
 
        		                minSlackWorkerByJob[j] = w;
 
        		            }
 
        		        }
 
        		     
 
        		        protected void match(int w, int j)
 
        		        {
 
        		            matchJobByWorker[w] = j;
 
        		            matchWorkerByJob[j] = w;
 
        		        }
 
        		     
 
        		        protected void reduce()
 
        		        {
 
        		            for (int w = 0; w < dim; w++)
 
        		            {
 
        		                double min = Double.POSITIVE_INFINITY;
 
        		                for (int j = 0; j < dim; j++)
 
        		                {
 
        		                    if (costMatrix[w][j] < min)
 
        		                    {
 
        		                        min = costMatrix[w][j];
 
        		                    }
 
        		                }
 
        		                for (int j = 0; j < dim; j++)
 
        		                {
 
        		                    costMatrix[w][j] -= min;
 
        		                }
 
        		            }
 
        		            double[] min = new double[dim];
 
        		            for (int j = 0; j < dim; j++)
 
        		            {
 
        		                min[j] = Double.POSITIVE_INFINITY;
 
        		            }
 
        		            for (int w = 0; w < dim; w++)
 
        		            {
 
        		                for (int j = 0; j < dim; j++)
 
        		                {
 
        		                    if (costMatrix[w][j] < min[j])
 
        		                    {
 
        		                        min[j] = costMatrix[w][j];
 
        		                    }
 
        		                }
 
        		            }
 
        		            for (int w = 0; w < dim; w++)
 
        		            {
 
        		                for (int j = 0; j < dim; j++)
 
        		                {
 
        		                    costMatrix[w][j] -= min[j];
 
        		                }
 
        		            }
 
        		        }
 
        		     
 
        		        protected void updateLabeling(double slack)
 
        		        {
 
        		            for (int w = 0; w < dim; w++)
 
        		            {
 
        		                if (committedWorkers[w])
 
        		                {
 
        		                    labelByWorker[w] += slack;
 
        		                }
 
        		            }
 
        		            for (int j = 0; j < dim; j++)
 
        		            {
 
        		                if (parentWorkerByCommittedJob[j] != -1)
 
        		                {
 
        		                    labelByJob[j] -= slack;
 
        		                }
 
        		                else
 
        		                {
 
        		                    minSlackValueByJob[j] -= slack;
 
        		                }
 
        		            }
 
        		        }
        		    }
        		    
        		    class Node{
        		    	int to;
        		    	long dist;
        		    	Node(int to,long dist){
        		    		this.to=to;
        		    		this.dist=dist;
        		    	}
        		    	
        		    }
        		    class Pair implements Comparable<Pair>{
        				
    					
    					int h,m,s;
    					Pair(int h,int m,int s){
    					
    						this.h=h;
    						this.m=m;
    						this.s=s;
    					}
    					@Override
    					public int compareTo(Pair o) {
    				
    					//	if(((double)a/(double)b)!=((double)o.a/(double)o.b))
    					//	return (int)(((double)o.a/(double)o.b)-((double)a/(double)b));
    					//	else
    							
    					//return (int)(o.size-size);
    						return 0;
    					}
    					public int hashCode() {
    							//int hu = (int) (x ^ (x >>> 32));
    							//int hv = (int) (y ^ (y >>> 32));
    							//int hw = (int) (mass ^ (mass >>> 32));
    							//return 31 * hu + hv ;
    						return 0;
    						}
    						public boolean equals(Object o) {
    							Pair other = (Pair) o;
    						//	return x == other.x && y == other.y;
    						return false;
    						}
    				}  class Dsu{
	    		    	private int rank[], parent[] ,n;
	    		    	private static int[] parent1;
	    		    	Dsu(int size){
	    		    		this.n=size+1;
	    		    		rank=new int[n];
	    		    		//parent=new int[n];
	    		    		parent=new int[n];
	    		    	makeSet();
	    		
	    		    	}
	    		    	
	    		    	void makeSet(){
	    		    		for(int i=0;i<n;i++){
	    		    			parent[i]=i;
	    		    		}
	    		    	}
	    		    	
	    		    	int find(int x){
	    		    		if(parent[x]!=x){
	    		    			
	    		    			parent[x]=find(parent[x]);
	    		    		}
	    		    		return parent[x];
	    		    	}
	    		    
	    		    	
	    		    	boolean union(int x,int y){
	    		    		int xRoot=find(x);
	    		    		int yRoot=find(y);
	    		    		
	    		    		if(xRoot==yRoot)
	    		    			return false;
	    		    		if(rank[xRoot]<rank[yRoot]){
	    		    		parent[xRoot]=yRoot;	
	    		    		}else if(rank[yRoot]<rank[xRoot]){
	    		    			parent[yRoot]=xRoot;
	    		    		}else{
	    		    			parent[yRoot]=xRoot;
	    		    			rank[xRoot]++;
	    		    		}
	    		    		return true;
	    		    	}
 
	    		     
	    		    }


	
Python:
import sys
import copy
SIMPLE, STARRED, PRIMED = 0, 1, 2
 
 
# ------- hungarian method ------- BEGIN
def hungarian(matrix, deepcopy=True):
    if deepcopy:
        matrix = copy.deepcopy(matrix)
    n = len(matrix)
 
    # Step 1:
    # For each row of the matrix, find the smallest element and
    # subtract it from every element in its row. Go to Step 2.
    for row in matrix:
        m = min(row)
        if m != 0:
            row[:] = map(lambda x: x - m, row)
 
    mask_matrix = [[SIMPLE] * n for _ in matrix]
    row_cover = [False] * n
    col_cover = [False] * n
 
    # Step 2
    # Find a zero (Z) in the resulting matrix.  If there is
    # no starred zero in its row or column, star Z. Repeat for
    # each element in the matrix. Go to Step 3.
    for r, row in enumerate(matrix):
        for c, value in enumerate(row):
            if value == 0 and not row_cover[r] and not col_cover[c]:
                mask_matrix[r][c] = STARRED
                row_cover[r] = True
                col_cover[c] = True
 
    row_cover = [False] * n
    col_cover = [False] * n
 
    # Step 3
    # Cover each column containing a starred zero.  If K columns
    # are covered, the starred zeros describe a complete set of
    # unique assignments. In this case, go to DONE, otherwise,
    # go to Step 4.
 
    match_found = False
 
    while not match_found:
        for i in range(n):
            col_cover[i] = any(mrow[i] == STARRED for mrow in mask_matrix)
 
        if all(col_cover):
            match_found = True
            continue
        else:
            # Step 4(, 6)
            zero = _cover_zeroes(matrix, mask_matrix, row_cover, col_cover)
 
            # Step 5
            # Construct a series of alternating primed and starred zeros as
            # follows.  Let Z0 represent the uncovered primed zero found in
            # Step 4.  Let Z1 denote the starred zero in the column of Z0
            # (if any). Let Z2 denote the primed zero in the row of Z1
            # (there will always be one).  Continue until the series terminates
            # at a primed zero that has no starred zero in its column. Unstar
            # each starred zero of the series, star each primed zero of the
            # series, erase all primes and uncover every line in the matrix.
            # Return to Step 3.
 
            primes = [zero]
            stars = []
            while zero:
                zero = _find_star_in_col(mask_matrix, zero[1])
                if zero:
                    stars.append(zero)
                    zero = _find_prime_in_row(mask_matrix, zero[0])
                    stars.append(zero)
 
            # Erase existing stars
            for star in stars:
                mask_matrix[star[0]][star[1]] = SIMPLE
 
            # Star existing primes
            for prime in primes:
                mask_matrix[prime[0]][prime[1]] = STARRED
 
            # Erase remaining primes
            for r, row in enumerate(mask_matrix):
                for c, val in enumerate(row):
                    if val == PRIMED:
                        mask_matrix[r][c] = SIMPLE
 
            row_cover = [False] * n
            col_cover = [False] * n
            # end of step 5
 
        # end of step 3 while
 
    # reconstruct the solution
    solution = []
    for r, row in enumerate(mask_matrix):
        for c, val in enumerate(row):
            if val == STARRED:
                solution.append((r, c))
    return solution
    #end of minimize
 
 
# Internal methods
 
 
def _cover_zeroes(matrix, mask_matrix, row_cover, col_cover):
 
    # Repeat steps 4 and 6 until we are ready to break out to step 5
    while True:
        zero = True
 
        # Step 4
        # Find a noncovered zero and prime it.  If there is no
        # starred zero in the row containing this primed zero,
        # go to Step 5. Otherwise, cover this row and uncover
        # the column containing the starred zero. Continue in
        # this manner until there are no uncovered zeros left.
        # Save the smallest uncovered value and go to Step 6.
 
        while zero:
            zero = _find_noncovered_zero(matrix, row_cover, col_cover)
            if not zero:
                break  # continue with step 6
            else:
                row = mask_matrix[zero[0]]
                row[zero[1]] = PRIMED
 
                try:
                    index = row.index(STARRED)
                except ValueError:
                    return zero  # continue with step 5
 
                row_cover[zero[0]] = True
                col_cover[index] = False
 
        # Step 6
        # Add the value found in Step 4 to every element of
        # each covered row, and subtract it from every element
        # of each uncovered column.  Return to Step 4 without
        # altering any stars, primes, or covered lines.
 
        m = min(_uncovered_values(matrix, row_cover, col_cover))
        for r, row in enumerate(matrix):
            for c, __ in enumerate(row):
                if row_cover[r]:
                    matrix[r][c] += m
                if not col_cover[c]:
                    matrix[r][c] -= m
    # end of _cover_zeroes
 
 
def _find_noncovered_zero(matrix, row_cover, col_cover):
    for r, row in enumerate(matrix):
        for c, value in enumerate(row):
            if value == 0 and not row_cover[r] and not col_cover[c]:
                return (r, c)
    else:
        return None
 
 
def _uncovered_values(matrix, row_cover, col_cover):
    for r, row in enumerate(matrix):
        for c, value in enumerate(row):
            if not row_cover[r] and not col_cover[c]:
                yield value
 
 
def _find_star_in_col(mask_matrix, c):
    for r, row in enumerate(mask_matrix):
        if row[c] == STARRED:
            return (r, c)
    else:
        return None
 
 
def _find_prime_in_row(mask_matrix, r):
    for c, val in enumerate(mask_matrix[r]):
        if val == PRIMED:
            return (r, c)
    else:
        return None
# ------- end of hungarian method -------
 
 
# [-1, 1].product([-1, 1]).map do |(s_dir, m_dir)|
#   (h_a, m_a, s_a) = alarm
#   (h_c, m_c, s_c) = clock
 
#   # cost of adjusting seconds
#   cost = s_dir * (s_a - s_c) % 60
#   # Update minutes and hours
#   d_m_c = s_a == s_c ? 0 : (s_dir == (s_a > s_c ? 1 : -1) ? 0 : s_dir)
#   d_h_c = (m_c == 59 && d_m_c > 0) ? 1 : (m_c == 0 && d_m_c < 0 ? -1 : 0)
#   m_c = (m_c + d_m_c) % 60
#   h_c = (h_c + d_h_c) % 24
#   # cost of adjusting minutes
#   cost += m_dir * (m_a - m_c) % 60
#   # Update hours
#   d_h_c = m_a == m_c ? 0 : (m_dir == (m_a > m_c ? 1 : -1) ? 0 : m_dir)
#   h_c = (h_c + d_h_c) % 24
#   # cost of adjusting hours
#   cost += [(h_a - h_c) % 24, (h_c - h_a) % 24].min
# end.min
 
def _sign(x):
    return int(2 * (int(x) - 0.5))
 
def min_cost(alarm, clock):
    costs = []
    for s_dir in [-1, 1]:
        for m_dir in [-1, 1]:
            h_a, m_a, s_a = alarm
            h_c, m_c, s_c = clock
 
            # cost of adjusting seconds
            cost = (s_dir * (s_a - s_c)) % 60
            # update minutes and hours
            if s_a != s_c and s_dir != _sign(s_a > s_c): d_m_c = s_dir
            else: d_m_c = 0
 
            if m_c == 59 and d_m_c == 1: d_h_c = 1
            elif m_c == 0 and d_m_c == -1: d_h_c = -1
            else: d_h_c = 0
 
            m_c = (m_c + d_m_c) % 60
            h_c = (h_c + d_h_c) % 24
            # cost of adjusting minutes
            cost += (m_dir * (m_a - m_c)) % 60
            # update hours
            if m_a != m_c and m_dir != _sign(m_a > m_c): d_h_c = m_dir
            else: d_h_c = 0
 
            h_c = (h_c + d_h_c) % 24
            # cost of adjusting hours
            cost += min((h_a - h_c) % 24, (h_c - h_a) % 24)
            costs.append(cost)
    return min(costs)
 
 
if __name__ == '__main__':
    tests_no = int(sys.stdin.readline().strip())
 
    for _ in range(tests_no):
        clocks_no, alarms_no = [int(x) for x in sys.stdin.readline().strip().split()]
 
        clocks = []
        for _ in range(clocks_no):
            clocks.append([int(x) for x in sys.stdin.readline().strip().split(':')])
 
        alarms = []
        for _ in range(alarms_no):
            alarms.append([int(x) for x in sys.stdin.readline().strip().split(':')])
 
        cost_matrix = []
        for alarm in alarms:
            cost_matrix.append([])
            for clock in clocks:
                cost_matrix[-1].append(min_cost(alarm, clock))
 
        max_cost = max(max(cost_matrix))
        for _ in range(clocks_no - alarms_no):
            cost_matrix.append([max_cost] * clocks_no)
 
        solutions = hungarian(cost_matrix)
 
        total_cost = 0
        for solution in solutions[:alarms_no]:
            i, j = solution
            total_cost += cost_matrix[i][j]
 
        print(total_cost)

Python 3:
import sys
import copy
SIMPLE, STARRED, PRIMED = 0, 1, 2
def hungarian(matrix, deepcopy=True):
    if deepcopy:
        matrix = copy.deepcopy(matrix)
    n = len(matrix)
 
    # Step 1:
    # For each row of the matrix, find the smallest element and
    # subtract it from every element in its row. Go to Step 2.
    for row in matrix:
        m = min(row)
        if m != 0:
            row[:] = map(lambda x: x - m, row)
 
    mask_matrix = [[SIMPLE] * n for _ in matrix]
    row_cover = [False] * n
    col_cover = [False] * n
 
    # Step 2
    # Find a zero (Z) in the resulting matrix.  If there is
    # no starred zero in its row or column, star Z. Repeat for
    # each element in the matrix. Go to Step 3.
    for r, row in enumerate(matrix):
        for c, value in enumerate(row):
            if value == 0 and not row_cover[r] and not col_cover[c]:
                mask_matrix[r][c] = STARRED
                row_cover[r] = True
                col_cover[c] = True
 
    row_cover = [False] * n
    col_cover = [False] * n
 
    # Step 3
    # Cover each column containing a starred zero.  If K columns
    # are covered, the starred zeros describe a complete set of
    # unique assignments. In this case, go to DONE, otherwise,
    # go to Step 4.
 
    match_found = False
 
    while not match_found:
        for i in range(n):
            col_cover[i] = any(mrow[i] == STARRED for mrow in mask_matrix)
 
        if all(col_cover):
            match_found = True
            continue
        else:
            # Step 4(, 6)
            zero = _cover_zeroes(matrix, mask_matrix, row_cover, col_cover)
 
            # Step 5
            # Construct a series of alternating primed and starred zeros as
            # follows.  Let Z0 represent the uncovered primed zero found in
            # Step 4.  Let Z1 denote the starred zero in the column of Z0
            # (if any). Let Z2 denote the primed zero in the row of Z1
            # (there will always be one).  Continue until the series terminates
            # at a primed zero that has no starred zero in its column. Unstar
            # each starred zero of the series, star each primed zero of the
            # series, erase all primes and uncover every line in the matrix.
            # Return to Step 3.
 
            primes = [zero]
            stars = []
            while zero:
                zero = _find_star_in_col(mask_matrix, zero[1])
                if zero:
                    stars.append(zero)
                    zero = _find_prime_in_row(mask_matrix, zero[0])
                    stars.append(zero)
 
            # Erase existing stars
            for star in stars:
                mask_matrix[star[0]][star[1]] = SIMPLE
 
            # Star existing primes
            for prime in primes:
                mask_matrix[prime[0]][prime[1]] = STARRED
 
            # Erase remaining primes
            for r, row in enumerate(mask_matrix):
                for c, val in enumerate(row):
                    if val == PRIMED:
                        mask_matrix[r][c] = SIMPLE
 
            row_cover = [False] * n
            col_cover = [False] * n
            # end of step 5
 
        # end of step 3 while
 
    # reconstruct the solution
    solution = []
    for r, row in enumerate(mask_matrix):
        for c, val in enumerate(row):
            if val == STARRED:
                solution.append((r, c))
    return solution
    #end of minimize
 
 
# Internal methods
 
 
def _cover_zeroes(matrix, mask_matrix, row_cover, col_cover):
 
    # Repeat steps 4 and 6 until we are ready to break out to step 5
    while True:
        zero = True
 
        # Step 4
        # Find a noncovered zero and prime it.  If there is no
        # starred zero in the row containing this primed zero,
        # go to Step 5. Otherwise, cover this row and uncover
        # the column containing the starred zero. Continue in
        # this manner until there are no uncovered zeros left.
        # Save the smallest uncovered value and go to Step 6.
 
        while zero:
            zero = _find_noncovered_zero(matrix, row_cover, col_cover)
            if not zero:
                break  # continue with step 6
            else:
                row = mask_matrix[zero[0]]
                row[zero[1]] = PRIMED
 
                try:
                    index = row.index(STARRED)
                except ValueError:
                    return zero  # continue with step 5
 
                row_cover[zero[0]] = True
                col_cover[index] = False
 
        # Step 6
        # Add the value found in Step 4 to every element of
        # each covered row, and subtract it from every element
        # of each uncovered column.  Return to Step 4 without
        # altering any stars, primes, or covered lines.
 
        m = min(_uncovered_values(matrix, row_cover, col_cover))
        for r, row in enumerate(matrix):
            for c, __ in enumerate(row):
                if row_cover[r]:
                    matrix[r][c] += m
                if not col_cover[c]:
                    matrix[r][c] -= m
    # end of _cover_zeroes
 
 
def _find_noncovered_zero(matrix, row_cover, col_cover):
    for r, row in enumerate(matrix):
        for c, value in enumerate(row):
            if value == 0 and not row_cover[r] and not col_cover[c]:
                return (r, c)
    else:
        return None
 
 
def _uncovered_values(matrix, row_cover, col_cover):
    for r, row in enumerate(matrix):
        for c, value in enumerate(row):
            if not row_cover[r] and not col_cover[c]:
                yield value
 
 
def _find_star_in_col(mask_matrix, c):
    for r, row in enumerate(mask_matrix):
        if row[c] == STARRED:
            return (r, c)
    else:
        return None
 
 
def _find_prime_in_row(mask_matrix, r):
    for c, val in enumerate(mask_matrix[r]):
        if val == PRIMED:
            return (r, c)
    else:
        return None
def _sign(x):
    return int(2 * (int(x) - 0.5))
 
def min_cost(alarm, clock):
    costs = []
    for s_dir in [-1, 1]:
        for m_dir in [-1, 1]:
            h_a, m_a, s_a = alarm
            h_c, m_c, s_c = clock
 
            # cost of adjusting seconds
            cost = (s_dir * (s_a - s_c)) % 60
            # update minutes and hours
            if s_a != s_c and s_dir != _sign(s_a > s_c): d_m_c = s_dir
            else: d_m_c = 0
 
            if m_c == 59 and d_m_c == 1: d_h_c = 1
            elif m_c == 0 and d_m_c == -1: d_h_c = -1
            else: d_h_c = 0
 
            m_c = (m_c + d_m_c) % 60
            h_c = (h_c + d_h_c) % 24
            # cost of adjusting minutes
            cost += (m_dir * (m_a - m_c)) % 60
            # update hours
            if m_a != m_c and m_dir != _sign(m_a > m_c): d_h_c = m_dir
            else: d_h_c = 0
 
            h_c = (h_c + d_h_c) % 24
            # cost of adjusting hours
            cost += min((h_a - h_c) % 24, (h_c - h_a) % 24)
            costs.append(cost)
    return min(costs)
 
 
if __name__ == '__main__':
    tests_no = int(sys.stdin.readline().strip())
 
    for _ in range(tests_no):
        clocks_no, alarms_no = [int(x) for x in sys.stdin.readline().strip().split()]
 
        clocks = []
        for _ in range(clocks_no):
            clocks.append([int(x) for x in sys.stdin.readline().strip().split(':')])
 
        alarms = []
        for _ in range(alarms_no):
            alarms.append([int(x) for x in sys.stdin.readline().strip().split(':')])
 
        cost_matrix = []
        for alarm in alarms:
            cost_matrix.append([])
            for clock in clocks:
                cost_matrix[-1].append(min_cost(alarm, clock))
 
        max_cost = max(max(cost_matrix))
        for _ in range(clocks_no - alarms_no):
            cost_matrix.append([max_cost] * clocks_no)
 
        solutions = hungarian(cost_matrix)
 
        total_cost = 0
        for solution in solutions[:alarms_no]:
            i, j = solution
            total_cost += cost_matrix[i][j]
 
        print(total_cost)


*/


/*I/O:
In #1:
2
50 17
09:04:08
07:15:07
17:25:09
06:57:31
03:55:51
05:50:45
05:57:07
15:32:16
05:40:17
18:35:06
10:35:34
08:25:31
06:45:09
01:32:33
16:43:25
09:04:01
07:48:09
16:55:03
02:26:04
17:29:23
15:16:29
07:19:52
15:01:41
03:18:47
13:48:25
19:22:50
17:07:19
08:20:57
09:26:28
02:07:38
10:29:23
03:03:22
04:44:38
05:42:45
10:08:02
11:10:49
14:08:02
13:48:15
07:22:15
12:07:30
04:45:46
16:43:54
19:56:07
12:46:06
07:48:04
12:02:05
04:30:25
02:17:09
18:13:44
00:44:16
01:39:54
05:21:38
09:19:33
07:32:50
03:06:15
08:00:02
05:14:46
05:17:24
10:39:23
00:15:16
08:22:15
19:32:17
13:38:25
08:46:57
13:46:16
17:51:32
11:16:09
50 17
02:42:38
06:01:33
17:39:56
06:54:41
17:03:55
12:51:18
18:12:01
08:32:28
10:37:01
07:48:41
09:59:37
03:45:53
15:52:25
00:25:54
11:23:41
10:27:13
02:57:23
11:36:39
08:43:00
03:32:04
13:53:11
11:24:18
06:30:46
17:55:52
07:04:18
12:06:35
00:27:09
18:45:42
17:53:05
18:45:24
14:55:04
13:29:14
19:07:00
10:10:34
03:21:34
14:01:43
17:14:30
05:10:20
16:47:57
06:27:33
14:30:12
10:13:22
19:16:01
11:28:57
11:53:09
18:04:22
08:30:34
18:32:29
16:49:10
14:19:26
00:48:21
17:32:44
17:08:20
02:52:13
08:29:55
10:23:07
15:16:55
02:28:21
08:40:54
19:29:04
07:13:16
01:16:25
09:56:53
11:32:42
08:43:21
14:12:23
09:31:55
Out #1:
160
183

In #2:
2
50 17
17:51:38
01:50:27
11:14:23
18:35:20
14:46:42
03:15:25
19:39:20
00:18:51
19:06:53
04:06:01
13:10:37
07:46:50
01:30:47
06:58:19
19:41:25
07:19:30
05:30:22
07:50:18
19:41:09
09:01:49
03:56:29
03:23:56
05:11:06
11:58:04
14:17:10
13:38:32
18:05:17
19:30:40
13:45:39
12:59:34
08:36:21
14:30:07
03:38:56
12:27:40
18:01:01
18:16:56
17:29:25
18:31:11
19:22:42
13:53:58
10:18:16
01:28:21
01:34:40
18:05:13
03:47:21
09:21:36
16:24:48
15:03:45
16:57:27
07:47:52
07:06:57
08:32:54
18:11:50
12:09:10
10:05:06
18:22:55
04:39:30
09:03:35
19:14:54
01:34:53
13:56:53
00:10:14
08:27:55
01:54:45
12:43:19
15:45:14
13:33:42
50 17
19:39:17
08:41:11
07:11:06
00:37:16
16:49:25
09:02:27
11:39:07
15:41:56
13:02:27
02:10:15
12:39:38
11:41:09
04:02:54
19:57:41
01:58:34
16:01:20
04:13:55
18:42:11
10:28:04
19:02:46
16:28:16
11:07:13
17:30:29
13:27:19
10:13:42
14:15:27
11:08:58
19:11:44
00:38:52
06:04:46
03:48:20
10:04:44
10:11:18
11:40:22
14:39:14
04:24:06
19:04:19
06:52:25
11:17:31
18:09:33
02:05:20
08:20:47
04:35:48
10:08:20
10:28:01
04:12:18
09:03:54
05:16:36
01:00:33
05:32:22
09:30:40
16:10:37
14:07:23
08:15:19
05:01:55
18:34:38
02:37:35
19:30:00
10:22:48
16:10:40
11:56:52
05:13:03
06:41:30
10:45:06
05:22:15
09:30:30
06:41:49
Out #2:
180
172

In #3:
2
50 17
11:19:21
10:29:30
07:29:26
06:48:50
13:13:40
00:30:08
09:26:35
05:17:33
17:00:20
06:39:58
08:29:48
12:25:55
08:58:33
09:13:09
10:37:34
14:06:19
12:14:33
18:16:48
14:55:31
13:11:42
04:50:21
11:48:54
18:17:36
12:28:55
13:46:15
15:20:07
10:20:52
12:51:29
11:15:07
19:49:12
10:23:35
01:17:12
19:57:48
00:15:59
06:12:04
15:51:43
16:14:26
07:33:44
13:52:52
13:48:57
11:40:29
07:45:14
01:22:54
11:53:06
05:47:23
02:36:05
12:23:48
05:51:40
12:43:38
09:38:02
11:34:41
15:06:38
07:03:55
03:03:12
06:14:44
18:49:08
09:51:03
01:27:04
19:43:05
12:25:11
10:43:10
00:05:27
19:02:17
07:18:33
17:20:13
12:58:05
08:52:07
50 17
13:50:21
19:35:27
06:15:01
08:27:54
12:45:58
07:48:05
10:40:12
16:50:28
13:49:07
15:18:06
13:58:30
02:16:02
02:05:49
00:14:32
19:54:56
04:20:45
19:35:52
19:28:52
12:06:47
18:01:27
06:27:31
16:59:25
19:38:17
02:30:03
19:12:41
16:40:31
13:40:52
13:03:50
13:44:35
16:19:36
18:22:55
01:37:01
02:51:24
12:12:26
05:42:42
08:33:52
02:50:43
01:44:03
15:26:31
15:43:56
09:15:30
10:43:26
01:07:56
06:10:26
05:58:18
00:05:04
02:38:17
03:06:16
17:47:24
12:16:43
08:25:42
19:03:39
17:42:28
18:26:18
00:11:02
18:13:44
15:38:55
17:51:43
05:41:29
04:46:06
10:23:32
09:08:17
02:01:25
19:15:04
06:19:00
09:20:09
14:44:17
Out #3:
188
158

In #4:
2
50 17
19:55:03
19:25:30
18:12:40
02:46:53
10:24:41
12:08:07
19:14:58
00:24:14
05:23:21
04:05:13
11:00:33
17:28:02
13:57:03
02:17:48
15:31:44
18:50:16
00:36:12
09:31:17
00:44:03
01:32:11
10:53:01
17:26:10
18:47:03
01:50:28
12:34:52
14:27:02
00:08:51
14:09:11
05:54:14
13:42:14
08:50:53
09:02:39
06:15:05
12:10:40
00:35:43
12:25:58
08:14:13
00:26:07
07:38:48
13:26:09
07:15:19
08:05:38
17:34:11
04:34:24
07:38:09
15:55:36
08:16:45
13:21:26
13:04:12
04:12:58
19:27:28
14:51:46
19:22:16
18:31:38
13:54:32
05:51:57
06:54:09
14:13:57
14:42:30
17:33:52
19:21:10
01:44:12
14:36:27
02:00:21
14:06:57
14:21:17
02:53:40
50 17
03:20:19
02:12:24
14:17:19
02:06:49
14:43:24
18:45:14
00:06:14
04:13:56
14:14:51
16:30:30
04:39:28
17:13:32
07:51:58
14:46:00
01:08:03
11:00:08
01:37:10
16:11:12
05:47:01
15:38:49
06:56:05
14:45:30
14:13:10
03:42:29
02:01:11
18:37:27
05:33:48
13:19:52
02:34:23
03:38:30
03:34:27
02:52:25
08:03:30
12:06:19
04:31:37
06:14:31
07:01:12
06:42:48
02:54:05
00:02:55
07:46:47
11:53:11
12:49:33
04:31:51
07:07:04
03:52:33
16:43:09
11:47:13
11:14:43
13:01:29
02:57:59
13:23:38
13:03:07
14:09:53
03:03:22
16:04:27
07:51:34
00:49:21
17:23:17
01:18:26
09:56:13
10:45:46
05:34:21
08:08:36
11:38:32
08:21:26
10:03:23
Out #4:
174
156

In #5:
2
50 17
09:08:16
14:00:37
00:23:23
10:27:22
15:35:43
10:05:20
18:51:24
11:03:56
17:27:48
16:16:18
07:49:54
14:45:47
19:32:50
07:58:04
18:23:57
06:41:55
16:14:12
14:55:08
15:58:43
19:00:17
15:51:07
12:42:04
00:56:34
16:32:09
10:03:18
18:59:02
02:02:01
15:34:46
13:04:40
02:12:59
00:21:37
16:49:45
11:12:33
04:00:41
02:06:16
19:41:08
01:57:18
09:50:09
01:38:19
19:56:46
00:47:49
18:10:23
07:53:13
01:49:37
07:10:43
13:50:48
07:16:29
03:11:32
19:10:51
06:39:48
08:05:18
16:32:02
14:54:57
04:43:18
19:53:55
07:31:56
05:59:33
16:13:12
11:58:20
06:24:29
18:59:38
07:06:05
09:47:55
01:47:30
19:03:51
12:38:01
13:52:26
50 17
16:57:24
15:58:10
04:51:03
06:34:19
15:13:34
13:46:52
05:47:30
15:23:24
18:42:57
05:06:07
17:15:22
02:20:47
01:08:24
01:18:01
19:40:46
15:53:45
08:23:44
14:09:33
13:20:51
07:18:10
01:42:40
19:27:48
11:13:07
01:58:05
15:03:45
18:22:19
16:50:20
11:26:00
19:21:20
15:51:32
12:08:32
18:21:42
09:07:54
07:16:53
12:41:25
13:49:25
10:51:30
19:36:03
06:41:45
11:38:31
15:05:05
03:42:52
03:29:42
03:31:44
18:26:20
09:26:29
19:16:04
12:41:32
01:57:34
05:45:29
01:30:31
12:31:35
10:42:00
10:10:36
12:35:25
18:08:13
12:38:54
07:37:16
01:18:56
18:45:25
09:49:43
14:19:14
06:33:18
03:31:54
12:54:43
14:01:53
16:37:31
Out #5:
136
176

In #6:
2
50 17
07:28:08
12:10:47
00:10:53
08:46:15
02:06:15
06:44:31
02:29:41
10:11:37
05:35:34
12:47:55
10:45:25
03:04:23
18:08:00
04:45:00
19:24:17
04:12:19
14:26:53
05:31:13
01:07:35
03:01:16
03:25:03
08:11:27
11:12:28
05:42:32
01:16:13
00:25:25
02:20:48
06:44:22
15:27:51
02:50:33
18:38:15
06:36:46
01:55:51
10:14:54
10:43:14
10:42:25
18:05:57
09:01:54
15:08:45
06:01:36
16:10:32
16:35:30
19:29:50
07:20:22
03:17:29
10:57:17
13:29:40
05:07:50
17:30:22
04:12:28
08:35:51
13:07:06
03:58:52
11:12:14
02:22:43
17:12:45
00:59:48
10:23:47
04:37:09
07:53:44
05:47:14
06:15:32
14:39:25
02:17:58
03:30:39
19:22:53
09:35:39
50 17
04:48:52
05:22:18
02:37:42
16:59:26
17:59:45
18:31:47
04:53:05
11:52:30
15:53:18
00:01:34
08:06:40
19:45:41
06:56:57
18:39:53
09:58:56
03:17:12
10:29:25
11:35:57
19:07:15
04:25:52
05:55:33
09:15:08
07:07:04
06:46:49
17:52:14
10:12:44
18:11:22
18:42:52
19:21:03
05:32:44
07:26:07
19:06:50
15:55:00
02:48:21
07:40:31
11:28:28
13:06:06
11:38:33
05:19:09
19:10:40
11:37:11
11:05:15
04:11:24
19:06:36
01:51:36
06:11:14
14:31:26
00:44:30
06:54:35
00:06:45
04:22:08
13:31:53
11:47:26
06:02:58
15:01:25
18:59:08
09:33:24
06:21:50
18:30:48
16:37:05
10:10:09
18:54:00
08:38:17
12:24:46
04:31:18
17:41:02
10:30:21
Out #6:
160
151

In #7:
2
50 17
15:11:37
13:15:07
10:01:38
10:38:03
09:50:16
02:51:19
18:37:12
05:58:19
09:34:59
14:34:46
01:04:13
08:05:38
13:09:16
17:25:47
14:34:27
18:09:08
03:24:16
16:36:23
06:51:27
11:11:00
14:47:10
08:11:29
09:22:15
16:52:47
00:08:14
05:15:20
10:08:07
08:45:35
03:37:01
10:42:11
00:47:19
07:13:33
06:59:30
00:35:08
14:16:39
16:36:36
13:04:08
04:15:56
19:09:45
00:41:57
12:46:42
17:15:24
17:57:57
04:05:40
05:14:20
01:16:58
19:08:46
16:37:56
16:16:45
05:04:30
02:26:48
12:37:36
13:40:52
06:44:32
18:05:41
18:16:38
15:14:12
16:24:10
00:42:14
12:03:41
04:10:10
08:30:29
13:04:53
01:09:42
06:35:33
15:35:29
00:52:18
50 17
18:15:20
18:08:29
18:11:16
10:02:11
18:35:19
03:39:09
03:18:21
00:01:28
19:40:58
00:47:42
10:42:06
15:32:58
04:43:02
05:47:04
11:43:59
01:15:51
03:41:33
08:52:38
05:02:38
16:38:13
15:00:56
04:47:31
08:07:50
02:33:25
06:31:14
12:09:42
07:22:13
16:38:51
02:57:50
11:24:20
12:58:43
04:07:30
16:49:34
04:38:46
16:59:39
17:18:33
17:42:45
16:22:52
00:40:59
04:50:44
10:26:46
05:52:30
11:12:13
17:24:59
00:00:11
18:29:50
18:24:29
07:06:15
16:01:29
11:01:45
09:17:06
18:29:12
14:26:45
02:03:27
13:33:24
16:38:16
11:50:08
16:02:11
00:31:29
09:53:29
10:53:49
13:01:58
01:21:04
11:53:44
05:10:40
08:39:01
07:57:53
Out #7:
163
153

In #8:
2
50 17
19:17:21
10:51:40
05:58:50
09:59:32
00:21:18
00:32:52
02:38:15
06:07:16
17:56:12
00:05:47
15:43:14
05:44:37
06:08:44
12:40:47
17:16:18
16:53:47
19:26:55
09:50:32
13:56:05
17:53:21
19:29:10
06:55:43
19:53:58
19:38:18
08:37:56
03:02:24
10:02:03
09:35:49
01:16:51
13:53:35
14:54:17
11:40:08
18:02:28
11:49:07
16:59:58
13:52:47
16:18:09
03:08:49
08:33:10
06:31:05
03:17:59
03:40:31
03:25:33
07:16:53
01:16:24
00:31:29
01:12:49
04:35:43
02:48:43
11:07:20
10:54:22
15:02:16
08:02:59
13:36:56
05:36:10
08:44:41
15:00:31
16:50:49
09:47:29
14:12:38
07:54:32
02:08:32
01:15:19
08:28:50
01:32:31
13:12:51
12:11:33
50 17
13:46:59
05:45:25
01:33:56
10:36:49
14:39:28
03:38:58
16:55:26
11:06:16
16:01:04
13:19:51
03:27:10
00:33:17
03:50:21
12:58:08
09:45:16
17:54:18
15:57:30
09:28:52
09:29:12
15:14:55
10:00:11
08:27:27
00:25:13
07:45:06
17:20:44
13:14:54
09:45:19
12:44:49
15:22:37
10:03:34
07:43:18
09:10:57
06:23:49
09:44:38
03:21:23
05:59:13
06:32:33
17:20:39
16:38:19
05:12:23
08:32:50
07:11:16
07:30:10
16:14:00
12:15:29
15:22:09
11:30:26
19:16:12
10:08:20
12:47:07
07:49:43
10:47:20
13:41:08
02:16:26
10:03:33
16:39:38
04:57:24
13:18:53
15:15:28
05:24:45
09:44:40
01:02:32
13:04:42
19:26:53
08:59:53
04:10:32
03:09:45
Out #8:
152
176

In #9:
2
50 17
08:51:21
17:08:13
19:37:57
16:00:23
06:34:41
07:51:04
08:25:09
15:05:38
14:55:50
03:10:21
06:08:26
01:46:19
09:30:08
08:52:51
03:41:59
15:54:33
18:05:40
05:30:30
06:41:14
05:47:13
14:29:29
03:20:09
18:05:25
04:45:13
12:31:09
02:19:41
03:42:41
05:20:04
10:24:33
12:06:11
06:36:17
09:16:50
05:29:11
03:14:34
06:23:37
02:40:43
02:02:54
18:46:32
11:54:30
17:36:30
16:48:39
03:14:43
10:19:15
03:04:10
18:48:46
00:29:07
13:48:47
18:24:06
10:50:24
05:38:43
17:23:28
03:36:08
17:23:55
06:24:29
01:51:59
07:15:09
06:10:26
06:54:31
17:36:59
01:11:59
04:26:10
04:26:26
10:34:13
08:16:57
19:03:27
14:15:30
13:26:36
50 17
18:10:57
12:24:23
01:24:09
17:38:48
15:05:03
02:04:12
00:51:09
01:46:22
13:02:39
04:41:32
14:19:05
07:21:21
05:53:21
17:50:15
13:21:24
08:05:40
04:44:36
15:46:41
01:34:25
12:02:46
13:10:21
19:25:11
16:49:55
01:42:01
10:53:14
00:36:11
12:16:26
02:54:36
07:33:34
19:10:39
00:26:17
05:18:12
07:30:48
18:14:02
08:24:35
14:20:11
15:46:19
00:53:54
06:17:20
13:33:58
15:22:16
00:09:15
15:40:07
10:36:56
00:26:49
11:59:51
11:54:25
12:00:58
05:14:41
18:21:28
06:35:34
05:48:15
10:48:19
05:56:31
00:46:23
07:09:54
06:08:47
05:39:30
08:38:59
00:34:38
02:05:27
15:55:51
18:09:01
08:34:11
10:13:13
08:35:24
02:24:26
Out #9:
151
161

In #10:
2
50 17
16:16:45
10:22:37
05:40:59
18:29:56
07:41:46
05:18:35
02:48:41
10:02:30
18:59:55
05:47:08
07:08:38
04:05:11
04:15:54
01:54:17
02:39:09
13:24:12
06:27:03
16:39:08
11:14:24
13:27:42
00:47:40
01:17:51
08:34:16
03:55:10
01:45:45
10:26:09
11:00:20
00:11:17
15:44:23
15:19:11
04:27:11
18:23:56
10:07:52
15:28:39
08:26:56
08:04:10
01:11:05
19:58:54
15:48:36
17:11:48
16:15:40
08:19:36
16:57:11
09:24:37
14:29:48
13:24:38
01:42:06
00:12:05
10:34:41
07:12:53
05:31:03
01:07:58
06:01:41
02:53:07
14:30:36
07:53:32
01:56:18
02:10:50
16:32:04
16:08:56
01:54:30
05:30:31
11:07:41
03:34:35
14:00:25
12:04:23
13:03:31
50 17
02:43:39
05:02:21
10:25:39
11:13:35
16:41:34
07:45:54
19:18:54
12:08:54
14:59:13
05:23:06
09:04:49
12:28:30
00:55:31
16:24:06
05:06:41
16:09:23
11:40:54
12:13:04
07:15:25
14:35:16
18:26:50
18:17:06
13:07:43
00:37:47
03:32:43
02:05:22
04:27:40
03:40:27
00:18:32
15:57:31
14:21:43
16:53:50
18:38:33
13:44:04
06:18:39
13:39:21
18:56:48
09:51:55
13:44:48
00:31:18
13:14:35
12:58:34
16:02:46
18:49:40
01:55:56
17:43:22
15:09:38
00:23:18
00:52:00
19:21:40
00:14:03
04:38:53
17:41:12
01:09:14
19:52:43
08:09:05
19:09:01
12:53:17
18:59:13
07:09:17
01:58:43
19:50:59
10:02:34
07:43:25
15:52:29
18:05:51
19:07:38
Out #10:
174
172

In #11:
2
50 17
10:34:52
16:07:47
15:35:54
06:39:41
18:52:44
05:01:37
12:56:58
09:14:12
06:25:08
15:38:43
10:27:21
13:06:30
09:55:00
05:59:54
07:30:08
07:15:41
03:29:44
03:37:39
18:20:06
07:58:28
03:24:22
07:55:55
16:34:19
18:08:41
09:34:04
18:12:24
11:48:39
07:29:31
01:23:14
17:39:34
16:55:39
08:50:01
00:00:20
07:09:48
02:59:55
05:30:25
14:51:42
14:41:27
09:28:45
18:41:25
09:25:22
02:52:43
06:25:18
06:11:20
10:25:48
10:49:28
07:01:48
10:42:17
17:06:44
02:19:39
01:01:59
14:31:52
16:51:02
13:45:21
00:15:04
14:17:28
00:19:33
02:44:02
17:41:59
15:50:23
06:38:36
09:37:04
06:08:31
02:08:23
13:05:09
18:31:39
04:08:54
50 17
17:39:04
15:44:17
18:29:18
15:46:51
18:19:08
06:37:49
18:59:16
00:11:02
14:04:13
17:29:33
12:46:47
09:19:54
08:22:08
07:55:02
13:58:54
14:08:30
07:42:11
19:19:26
11:30:34
03:59:39
08:35:15
14:47:20
18:55:00
06:29:51
12:05:31
00:50:14
08:48:19
07:56:03
13:20:05
03:14:45
05:33:44
12:07:53
14:42:07
14:10:39
11:19:47
19:10:04
07:01:22
00:25:19
17:16:30
18:15:11
12:23:41
16:27:59
07:04:32
07:49:25
10:55:38
00:20:18
18:52:34
08:43:15
10:25:12
04:56:24
05:00:47
09:52:56
18:42:37
11:40:39
18:23:22
16:10:21
02:22:47
11:45:55
09:23:44
15:31:23
19:39:23
10:23:49
13:05:13
16:36:47
04:31:10
13:46:54
11:52:20
Out #11:
178
170
In #12:
2
50 17
14:00:46
13:13:42
09:28:14
14:12:59
17:13:14
17:28:30
02:07:15
00:13:33
12:25:03
17:49:20
06:22:06
12:05:45
03:42:10
00:10:54
02:24:38
05:46:24
17:23:17
14:11:48
02:57:18
13:38:47
18:18:02
11:39:57
17:04:49
01:04:34
08:23:47
13:02:49
19:22:37
13:44:08
05:33:42
07:47:48
04:02:11
05:57:28
05:28:24
12:53:53
10:50:59
02:12:26
17:32:47
13:05:22
09:30:33
14:51:29
09:58:53
12:47:30
18:53:51
13:52:50
18:28:48
17:44:33
13:10:27
02:52:17
03:41:38
00:06:49
19:08:10
11:26:58
05:33:07
08:17:07
13:24:04
16:20:37
03:50:03
18:20:57
12:20:18
06:27:45
12:26:15
00:42:31
15:52:09
09:09:17
12:03:03
07:29:41
06:45:30
50 17
01:00:32
08:32:38
08:21:42
16:40:42
17:15:58
17:18:47
11:05:42
07:26:10
15:50:29
18:11:47
09:09:24
10:39:29
13:50:57
14:11:33
01:32:36
02:28:13
18:37:23
15:25:25
11:17:16
00:22:19
04:14:34
11:25:50
14:31:37
09:55:38
05:04:16
09:41:40
15:40:11
07:42:35
06:14:48
17:02:21
18:07:10
03:28:31
05:26:33
08:40:31
02:24:32
07:49:18
08:37:31
05:47:50
16:23:14
19:53:30
08:03:55
08:25:38
14:17:17
05:00:18
02:20:44
02:15:07
13:01:17
19:49:14
18:02:35
15:10:26
02:33:48
08:09:57
11:23:56
17:53:37
17:19:06
16:59:39
16:49:57
03:55:40
11:20:42
18:03:03
12:28:33
08:07:38
09:10:06
11:29:03
05:33:21
13:44:47
17:10:52
Out #12:
161
165
In #13:
2
50 17
08:07:39
14:12:46
00:33:27
07:30:18
14:05:33
15:25:57
11:05:26
14:30:35
16:42:23
13:16:05
19:27:53
15:44:22
12:47:08
01:36:58
01:20:02
13:17:01
05:23:36
05:54:15
19:43:10
01:28:45
10:12:08
12:59:19
09:15:14
12:10:01
09:35:43
15:24:47
13:20:12
10:54:52
13:52:53
02:19:26
16:39:19
15:20:19
17:55:13
00:34:10
12:03:08
09:35:33
06:41:36
18:16:40
17:50:03
10:16:56
17:44:49
13:27:40
08:36:31
16:17:47
18:29:04
06:09:04
09:14:43
00:22:15
03:53:51
02:04:59
14:58:22
10:57:02
00:21:48
13:58:49
03:26:55
06:22:20
02:38:11
18:16:22
02:15:48
01:20:08
11:14:35
02:41:28
10:07:29
08:59:46
15:02:57
03:32:19
10:04:23
50 17
09:31:46
13:57:00
16:25:32
10:15:36
13:55:09
12:39:36
02:26:47
17:55:26
11:07:29
13:17:54
14:44:16
06:46:39
15:43:26
07:42:46
15:24:17
04:31:56
10:51:07
12:32:27
04:14:30
06:45:32
09:25:09
13:17:47
01:39:50
15:03:34
06:32:26
05:36:18
17:49:59
05:32:57
15:17:49
04:23:13
07:15:45
08:19:49
05:34:27
09:12:21
11:18:42
03:24:13
10:23:41
07:31:19
10:11:32
04:00:06
06:54:40
15:34:53
09:19:44
01:30:04
01:39:56
08:29:53
17:52:58
11:18:06
05:09:56
16:35:42
07:27:56
00:09:57
18:16:39
13:14:34
14:45:19
14:40:24
03:44:12
08:24:24
07:00:55
02:16:43
01:39:14
01:52:06
00:33:44
19:18:53
07:12:13
02:48:15
13:15:22
Out #13:
168
179
In #14:
2
50 17
06:13:41
12:58:55
10:06:41
09:29:47
15:36:37
01:15:50
03:19:49
15:48:16
04:06:12
05:07:30
00:52:44
04:45:27
17:07:38
04:51:55
06:18:11
16:27:20
11:17:15
16:32:43
03:46:24
19:47:12
05:18:24
08:04:04
19:31:05
01:50:42
07:04:02
19:11:06
01:40:31
15:25:29
07:46:23
16:10:00
14:26:13
00:47:54
02:14:51
14:46:03
18:04:07
00:01:44
09:01:31
17:20:33
11:36:38
14:02:54
14:15:55
19:22:57
04:24:18
14:08:00
14:09:45
03:04:33
07:09:08
11:51:47
00:17:38
03:47:43
12:09:09
12:08:01
10:09:49
00:48:29
00:25:53
07:00:23
01:23:38
13:13:59
07:10:19
12:16:09
14:51:41
05:25:21
01:55:19
09:47:54
10:49:16
09:05:01
11:41:02
50 17
16:48:11
00:35:08
12:21:15
12:43:23
14:57:53
16:11:54
05:00:09
06:54:54
18:42:49
02:59:21
17:20:14
11:41:52
14:53:35
14:16:08
03:18:44
12:35:03
07:33:24
19:44:08
02:51:14
15:59:12
09:15:48
03:05:03
07:19:47
14:50:58
14:51:56
03:23:03
02:10:45
02:24:03
12:09:18
12:06:15
14:57:51
19:32:08
01:18:53
00:42:44
05:27:50
01:33:03
13:18:25
12:07:05
03:40:01
01:42:29
04:43:20
07:43:09
07:37:23
10:16:23
14:44:13
01:16:59
10:45:34
08:10:01
09:20:07
02:58:48
00:56:37
07:13:40
10:57:14
09:27:13
03:07:17
18:40:16
15:01:12
01:22:01
18:21:56
09:02:08
01:02:50
05:59:34
03:46:51
08:11:35
18:11:00
03:28:36
02:24:34
Out #14:
143
198
In #15:
2
50 17
04:17:24
15:53:39
02:47:04
17:49:57
02:27:39
07:12:32
13:28:33
08:05:58
18:46:31
01:37:38
13:11:00
09:24:56
12:06:44
09:45:49
01:32:53
04:18:35
10:59:57
07:15:14
00:56:53
13:59:50
19:55:10
02:46:46
08:47:32
06:46:15
06:12:49
18:27:47
01:29:11
13:25:21
09:25:54
17:42:48
08:13:31
04:34:41
12:18:19
06:36:44
06:31:00
09:07:54
02:20:48
03:13:59
03:41:00
01:56:07
04:21:06
08:57:00
13:16:32
17:23:18
14:46:43
10:23:04
13:06:08
03:49:44
06:29:41
09:54:23
02:57:14
19:36:27
01:37:05
15:10:01
12:36:23
13:37:54
03:44:06
17:47:34
02:40:24
11:49:32
07:23:09
03:52:32
16:00:07
03:28:46
18:46:34
04:50:13
07:09:07
50 17
08:39:25
03:41:19
05:33:45
12:22:10
16:35:06
01:52:23
04:37:54
16:24:02
14:15:28
01:04:59
04:21:52
02:38:08
18:20:41
05:18:59
11:33:41
19:31:45
11:49:32
16:10:27
18:16:37
11:38:55
03:20:37
08:25:54
08:18:45
15:08:14
07:40:29
05:38:35
00:51:03
06:12:21
01:53:10
02:29:03
07:21:02
16:27:26
12:22:09
00:18:58
04:16:14
18:15:28
16:34:54
15:01:24
02:10:47
12:02:29
01:19:36
09:00:42
12:27:19
18:23:18
09:27:27
07:49:08
15:18:57
06:59:08
15:33:00
03:32:28
00:32:05
06:53:48
17:52:33
08:08:18
06:57:16
12:01:53
18:48:30
19:56:22
08:03:04
17:18:42
10:25:30
07:04:02
05:05:14
07:44:49
19:34:32
11:19:29
04:44:46
Out #15:
180
200
In #16:
2
50 17
14:14:34
10:29:39
12:30:08
09:02:00
09:34:46
06:37:21
07:46:12
09:34:17
14:14:52
07:46:13
09:31:53
04:25:58
07:44:31
02:06:25
00:03:03
02:29:15
06:33:30
12:13:23
14:09:35
01:14:15
14:53:11
02:42:48
18:20:22
15:38:06
05:21:50
16:53:22
09:27:28
08:14:50
13:13:44
13:24:23
16:42:45
11:54:47
07:39:27
12:51:58
04:14:45
06:40:01
19:36:29
02:41:52
07:21:26
01:15:25
01:14:12
02:57:50
05:44:05
14:50:01
18:08:05
19:08:13
19:36:23
19:39:22
08:25:23
06:19:53
00:36:10
14:07:31
10:19:24
03:47:47
09:19:04
13:31:41
02:28:15
19:07:05
07:45:57
07:56:53
06:31:49
09:11:29
15:55:37
14:58:10
17:41:18
00:28:25
12:28:01
50 17
15:06:54
19:04:15
13:57:27
16:53:44
07:25:38
02:01:25
14:38:54
13:37:10
19:47:50
16:08:16
19:03:06
13:19:01
17:22:00
12:23:41
03:29:19
07:04:28
12:21:54
14:57:07
06:04:07
16:48:25
12:59:32
08:18:20
09:34:32
11:14:10
16:03:09
07:07:17
11:12:24
12:28:57
14:06:57
18:16:25
08:54:47
02:22:03
18:44:13
15:04:10
13:27:42
16:54:10
09:24:14
10:33:27
06:05:31
08:24:22
19:44:49
11:59:47
09:28:54
15:23:08
07:31:13
10:53:36
17:03:39
13:33:04
14:50:11
14:37:45
03:05:26
05:41:41
18:51:17
14:50:40
01:29:56
10:10:49
01:05:10
16:47:14
15:42:03
14:39:22
12:17:14
14:20:42
06:40:06
16:57:41
04:33:03
18:15:38
00:27:18
Out #16:
149
176
In #17:
2
50 17
12:40:06
13:08:46
13:43:18
17:20:59
00:05:42
18:02:22
16:53:05
00:37:35
08:15:09
17:17:18
12:16:04
14:23:37
00:39:41
05:42:22
05:45:32
18:36:34
14:35:39
03:37:18
01:53:23
19:44:40
00:47:53
18:01:06
16:36:53
07:14:43
00:30:50
04:45:00
14:41:27
09:08:43
15:14:15
02:30:27
18:53:43
02:01:12
09:53:08
00:01:47
02:07:44
03:52:58
14:31:20
01:48:04
11:41:55
01:25:13
11:42:02
07:52:13
13:42:01
16:31:08
18:49:01
10:25:44
07:59:29
01:49:18
03:26:00
06:19:49
05:28:21
11:50:11
16:02:21
18:31:07
15:08:52
04:39:10
03:43:41
03:33:32
03:54:07
08:48:32
03:59:45
08:45:56
01:25:04
13:36:28
12:49:52
07:11:38
14:45:06
50 17
09:36:46
06:50:41
13:59:58
16:55:47
09:41:01
13:22:36
13:04:56
02:46:22
05:14:30
11:04:44
02:32:04
08:36:10
15:59:55
07:15:58
11:43:16
11:28:35
04:47:27
05:25:06
08:41:41
07:35:48
18:15:19
01:06:38
11:02:35
12:26:58
13:34:19
01:14:23
05:55:10
11:15:25
01:40:06
03:33:07
17:28:53
03:15:57
09:58:49
16:18:20
06:37:56
12:07:19
06:19:07
12:37:03
05:35:15
05:07:03
17:26:55
09:16:28
10:20:01
03:48:43
10:46:59
16:46:21
08:52:44
15:55:05
00:17:14
19:11:45
02:39:04
09:01:25
15:32:38
10:01:23
17:31:15
10:11:30
19:06:40
09:23:55
01:04:43
01:01:42
05:40:31
18:35:16
08:50:03
11:46:13
05:52:38
16:55:55
06:30:05
Out #17:
133
155
In #18:
2
50 17
06:24:53
19:44:20
03:38:13
19:11:13
01:16:20
16:29:41
06:05:40
13:53:30
16:13:25
13:48:45
13:51:29
19:06:22
05:38:23
14:43:48
00:13:50
16:20:11
12:21:10
14:50:08
06:07:57
03:16:48
05:45:33
12:57:38
01:42:50
10:40:17
14:38:57
02:38:25
12:29:43
03:29:47
03:52:23
06:03:25
00:20:07
06:48:03
14:16:56
11:01:02
10:40:02
09:58:17
06:21:13
04:56:07
10:31:23
07:39:56
19:17:35
19:27:40
19:30:48
19:56:12
14:40:09
07:24:25
03:24:40
01:29:56
05:50:33
07:10:29
13:17:07
17:31:35
05:20:22
09:29:43
18:49:39
04:30:07
04:25:40
05:33:27
16:53:38
19:15:15
08:22:03
14:04:29
12:38:44
18:20:57
17:26:56
03:04:40
07:24:09
50 17
05:57:04
13:58:00
01:53:32
10:20:31
04:47:11
14:44:18
12:45:01
12:05:10
00:29:36
12:36:31
10:13:20
04:01:04
16:45:44
14:18:50
02:59:23
13:21:18
19:29:45
02:31:28
19:28:24
05:14:08
18:48:48
01:08:33
16:28:08
12:38:31
02:32:26
08:49:10
03:26:18
11:21:20
11:13:27
01:12:13
05:24:24
18:30:55
09:38:07
11:44:03
15:36:26
00:24:25
18:21:37
07:42:22
10:24:31
16:59:47
19:39:06
00:26:01
11:18:49
01:56:18
11:15:05
13:46:17
03:24:46
02:18:02
08:48:26
00:32:31
05:42:51
02:19:22
10:15:11
10:44:48
14:27:25
12:07:26
02:07:24
08:33:33
17:49:16
09:52:41
10:37:31
10:32:04
11:33:58
00:30:37
06:19:14
07:57:48
15:10:19
Out #18:
149
168
In #19:
2
50 17
00:41:00
04:04:16
00:38:09
11:00:39
09:05:26
10:42:17
16:17:36
16:16:53
09:46:01
07:22:33
19:25:39
00:17:12
09:51:40
13:09:20
05:46:56
18:51:38
17:49:00
00:19:39
09:32:43
08:36:54
03:37:57
08:28:55
06:11:22
08:35:35
13:18:38
16:21:17
08:43:34
00:49:31
17:54:14
14:10:18
06:31:34
12:04:11
10:21:10
05:41:20
11:03:33
09:01:07
19:56:37
05:27:54
11:56:41
13:01:03
08:19:28
01:53:32
06:01:01
11:22:46
11:30:26
09:07:31
13:10:08
19:35:57
03:02:34
19:43:49
09:27:37
04:30:36
00:03:42
15:32:13
16:34:16
14:00:29
09:22:54
19:56:00
15:13:58
14:26:17
00:52:23
08:43:01
17:29:27
17:20:43
17:22:06
07:36:47
14:43:55
50 17
14:10:57
07:05:19
06:37:17
07:55:09
04:41:25
16:12:15
04:19:04
15:34:37
15:00:37
15:29:52
15:13:01
18:18:57
16:43:20
14:45:45
13:32:34
02:32:16
11:57:54
19:44:51
07:18:04
04:35:07
17:45:37
19:56:44
08:20:33
17:33:38
00:09:09
11:44:48
12:17:07
01:54:49
03:04:16
09:00:06
07:24:53
15:34:35
01:15:12
11:14:47
19:05:26
11:37:12
03:28:11
13:21:02
06:27:29
06:06:32
04:46:40
05:26:44
15:27:37
07:22:02
17:03:47
00:02:14
03:52:41
00:11:58
19:19:25
15:52:41
10:04:08
02:30:26
10:41:22
05:46:48
01:30:28
08:27:57
12:04:15
06:07:19
00:30:39
02:43:12
06:27:40
09:53:27
19:52:20
16:11:13
16:54:27
01:05:01
14:35:13
Out #19:
170
165
In #20:
2
50 17
09:39:13
03:03:36
10:47:56
19:20:38
06:16:48
08:09:36
00:03:12
19:13:53
03:16:38
09:39:14
00:10:00
05:36:39
04:46:56
10:01:21
08:24:05
06:04:53
05:41:29
11:53:27
13:12:55
15:56:39
18:34:17
08:02:57
16:47:59
13:41:06
12:27:10
11:57:25
18:01:10
06:50:46
01:49:45
12:20:16
14:02:38
12:01:36
00:34:51
18:46:37
19:14:51
00:55:10
12:46:48
04:10:37
15:48:12
19:11:31
07:24:30
02:57:29
11:10:16
14:27:43
17:32:26
06:02:42
11:39:07
01:33:54
03:35:28
11:24:59
07:27:42
04:01:32
18:21:49
10:23:57
12:38:14
10:28:06
00:25:36
13:22:53
12:16:28
05:07:55
05:24:06
00:42:34
16:54:33
12:18:31
10:29:44
13:45:39
13:00:56
50 17
09:46:25
14:42:05
16:19:07
01:22:13
05:17:38
11:53:21
07:39:09
06:48:25
10:05:36
18:11:09
05:08:58
02:15:17
11:03:57
01:21:23
05:36:18
04:35:09
02:23:17
10:50:11
05:52:46
01:59:43
10:30:42
19:03:32
04:25:36
19:45:56
03:31:36
12:59:15
03:38:03
05:01:11
18:05:07
15:39:28
12:48:58
10:09:12
12:19:08
01:20:11
00:14:57
17:56:31
02:34:40
14:39:29
09:52:03
11:45:31
03:32:51
09:35:49
06:29:42
05:42:35
19:02:54
03:51:09
07:05:43
17:37:33
03:28:38
10:13:33
17:19:05
07:34:06
13:22:47
04:59:46
04:58:22
06:46:23
00:47:45
06:50:52
12:12:11
09:14:30
05:50:00
13:47:11
13:35:36
05:25:35
17:33:53
02:25:30
10:34:29
Out #20:
150
145
In #21:
2
20 9
03:57:24
16:49:45
02:47:39
12:16:16
18:48:03
08:12:48
03:52:02
10:22:39
05:55:33
03:32:38
09:33:47
19:39:10
10:08:54
09:39:02
04:55:01
06:41:14
13:44:40
02:03:41
16:10:59
11:28:56
05:54:21
11:15:35
11:44:00
14:16:27
11:36:33
19:20:46
17:32:59
04:26:30
16:14:35
20 4
13:52:12
19:56:23
14:27:17
18:19:20
16:10:23
17:16:27
17:21:11
01:21:29
04:30:21
08:18:56
16:56:37
16:40:22
02:52:47
12:39:11
18:56:57
13:22:23
03:11:07
02:07:37
03:48:00
17:29:12
06:05:49
19:28:47
11:16:07
19:48:27
Out #21:
134
70
In #22:
2
20 7
05:35:03
04:51:06
12:28:41
11:13:05
05:51:31
16:35:36
02:49:32
08:40:13
16:27:39
09:43:36
11:29:13
09:07:46
11:22:01
07:15:16
16:01:24
13:16:30
11:21:54
07:39:40
18:05:30
16:24:36
04:34:49
11:47:31
04:11:11
19:07:39
04:07:53
01:31:04
19:12:48
20 3
09:35:35
18:24:25
15:55:04
06:50:51
11:05:47
17:47:32
00:41:05
10:55:44
10:16:24
04:28:48
05:22:25
02:48:56
04:16:53
09:53:54
07:22:33
00:35:54
15:40:13
13:24:52
08:42:13
02:03:23
13:04:50
03:42:34
05:55:15
Out #22:
95
38
In #23:
2
20 1
15:46:10
06:39:30
03:35:21
06:01:58
13:32:51
01:47:32
17:30:25
16:14:33
11:15:12
14:54:20
04:17:40
17:51:18
03:42:14
13:41:03
18:24:02
05:55:08
12:35:08
10:25:33
09:06:59
01:33:20
00:38:06
20 3
15:06:17
04:47:30
09:01:40
03:38:16
06:49:58
01:42:30
13:29:13
16:14:54
01:53:52
16:58:38
08:50:42
13:02:44
01:46:23
03:54:26
06:23:26
14:53:03
13:27:59
12:15:46
10:04:24
15:45:31
02:59:33
18:52:00
04:57:55
Out #23:
15
31

In #24:
2
20 9
10:46:22
10:25:34
12:34:44
00:31:28
09:37:58
09:39:34
17:30:15
01:31:33
11:33:32
08:09:12
17:55:51
06:25:05
11:22:41
17:07:19
12:44:43
16:46:46
19:47:52
15:41:46
04:21:37
00:55:45
05:28:06
04:04:40
00:48:49
12:20:53
14:37:21
02:22:04
08:18:52
03:24:00
16:14:24
20 7
04:41:14
07:23:08
05:55:11
16:10:36
15:35:37
08:13:43
02:34:51
11:10:50
02:05:53
18:45:26
15:25:12
06:15:37
12:22:23
02:52:03
02:10:17
13:23:10
02:43:27
14:00:32
13:08:13
15:57:17
10:27:18
13:20:25
14:44:41
01:45:15
18:17:24
16:12:20
19:23:20
Out #24:
143
91
In #25:
2
20 3
14:53:21
12:08:53
13:41:46
19:19:33
17:26:18
16:26:30
02:41:40
05:03:57
06:48:52
12:30:30
00:06:06
10:51:11
13:13:38
05:23:23
19:51:08
18:11:07
16:11:06
18:37:29
16:20:36
05:40:33
17:41:34
06:00:06
19:55:31
20 7
11:39:07
08:14:42
18:43:26
04:07:44
04:50:36
09:55:51
12:41:26
14:41:05
16:42:49
19:18:20
16:45:19
11:58:20
01:58:38
01:11:30
18:18:23
08:11:01
05:15:33
18:22:42
17:10:53
00:35:00
07:08:37
13:49:09
07:54:23
08:43:42
01:54:53
17:56:19
11:37:04
Out #25:
39
79
In #26:
2
20 7
09:15:14
00:46:17
03:28:06
04:42:06
10:21:34
04:58:22
05:18:12
14:20:17
03:32:11
07:41:25
19:30:12
08:39:05
04:57:27
11:51:31
15:34:36
03:42:21
18:08:13
03:27:58
11:44:35
16:08:15
10:21:52
05:42:02
11:00:22
16:43:26
08:55:45
14:12:04
04:48:19
20 4
13:23:30
08:26:45
06:40:14
01:45:10
03:23:58
03:50:51
06:04:56
14:34:47
17:05:51
04:44:59
07:30:27
02:40:07
10:32:09
05:28:08
12:43:49
17:09:02
18:53:15
16:47:46
08:23:39
03:29:34
11:31:50
12:59:50
00:37:26
10:55:01
Out #26:
89
53
In #27:
2
20 5
03:43:01
14:12:09
14:15:48
05:30:55
06:32:15
18:14:28
04:26:22
00:34:31
01:24:51
05:12:57
16:42:49
18:03:38
10:17:11
15:18:45
15:34:19
19:13:11
09:32:27
00:19:37
08:25:15
11:51:00
11:45:36
03:36:37
10:26:59
15:54:39
12:38:32
20 2
11:00:39
16:53:07
09:02:44
18:52:01
08:42:46
12:43:44
06:58:24
02:27:03
10:59:00
06:43:26
13:56:28
00:45:38
15:03:10
02:48:41
10:24:29
11:18:00
02:06:15
09:06:09
15:56:35
17:29:53
07:58:38
12:20:44
Out #27:
71
26
In #28:
2
20 9
01:04:24
18:34:22
07:16:48
17:30:28
14:54:15
05:07:27
19:13:17
05:38:51
08:06:19
19:07:45
05:14:30
01:17:48
14:37:04
01:30:53
07:07:38
06:28:39
02:28:11
11:59:44
03:34:18
06:47:24
17:25:58
19:59:39
03:33:40
19:47:36
08:29:54
16:52:54
07:15:49
04:09:49
12:53:26
20 10
15:08:04
09:07:01
15:34:25
08:05:35
11:44:42
09:02:47
16:03:49
11:52:13
14:06:32
14:38:47
00:03:38
04:45:11
07:30:51
07:09:02
04:24:01
13:04:10
02:49:24
10:24:22
10:25:18
08:08:33
05:15:19
01:06:19
15:08:50
07:04:33
19:37:06
01:13:47
06:17:57
10:50:49
00:51:32
10:57:27
Out #28:
126
146

In #29:
2
20 5
14:36:27
15:38:10
03:12:22
14:17:15
10:04:25
19:48:44
06:46:11
13:04:26
11:04:36
16:05:29
04:11:23
10:56:03
18:04:52
14:18:49
18:45:34
08:54:31
07:06:05
05:21:19
02:37:25
19:49:31
13:09:40
00:08:41
09:24:41
05:06:22
19:16:51
20 7
10:52:28
16:20:42
04:24:18
15:06:31
12:35:05
10:34:38
03:42:41
10:23:08
11:18:10
03:34:06
06:37:15
04:12:10
09:07:33
19:57:19
10:30:57
00:34:33
19:47:47
10:26:48
02:36:26
07:00:56
05:10:46
07:47:50
17:06:50
09:39:49
06:55:45
13:54:57
02:39:12
Out #29:
74
114

In #30:
2
20 3
14:28:20
13:11:39
16:49:16
01:44:44
08:44:25
09:55:34
13:55:46
09:58:40
18:50:14
01:16:13
19:29:51
04:02:50
16:24:19
08:02:37
11:02:10
18:29:55
04:01:32
00:07:04
17:58:44
00:12:25
09:29:59
05:00:59
09:59:18
20 10
00:41:39
12:45:33
02:37:23
14:00:09
15:17:42
05:16:24
14:39:39
03:38:15
16:37:51
16:10:10
15:21:58
14:59:03
12:48:48
14:13:39
15:10:37
09:23:10
04:22:25
11:40:01
00:50:33
06:57:01
11:19:44
00:46:13
00:42:14
10:49:20
05:24:36
03:30:40
17:45:23
05:37:34
12:37:47
09:29:42
Out #30:
37
149
In #31:
2
50 17
03:54:36
01:09:44
00:42:26
22:31:49
01:31:11
00:21:11
03:37:58
00:05:35
22:31:55
00:53:50
21:16:32
02:41:54
10:22:04
00:54:37
03:13:42
12:32:25
02:35:33
01:17:51
21:49:56
01:50:39
20:16:38
13:28:09
03:19:20
03:34:38
01:33:38
02:28:35
12:45:37
02:16:37
12:29:51
00:22:57
22:13:14
13:27:32
01:30:02
20:08:58
12:48:25
02:57:46
22:52:19
12:44:36
01:05:44
12:25:36
22:20:13
23:47:57
22:59:34
21:08:44
20:23:19
00:07:42
20:12:54
03:37:34
12:37:54
23:05:15
12:17:06
23:35:35
20:20:52
23:31:33
23:51:29
03:38:26
13:07:26
00:12:48
12:20:59
13:27:25
21:06:20
13:56:26
11:44:31
12:50:05
03:17:45
01:46:06
01:30:56
50 16
10:59:00
01:57:27
21:27:01
12:00:47
00:08:02
00:12:10
01:52:00
02:59:35
02:21:39
00:11:43
22:14:04
03:30:26
13:35:11
23:11:41
22:33:19
23:23:20
23:41:22
01:45:26
00:54:26
11:39:24
21:44:17
00:39:44
23:33:20
03:34:26
03:57:00
10:07:41
13:06:49
12:21:47
22:50:27
10:11:31
22:22:35
20:14:03
23:34:13
12:52:25
13:29:57
10:05:54
03:01:00
12:21:23
12:44:54
12:47:29
23:51:10
02:05:18
21:40:57
23:28:38
22:33:44
12:03:13
23:11:41
13:04:03
21:28:56
11:42:43
10:17:02
12:41:40
12:06:20
01:55:41
22:23:46
01:58:32
13:46:51
11:06:38
01:36:12
01:22:56
00:45:48
02:22:21
02:34:23
13:57:35
00:56:33
20:07:04
Out #31:
167
135
In #32:
2
50 16
20:34:36
21:41:04
01:29:24
23:27:58
02:54:31
23:03:19
12:44:22
23:49:59
21:05:10
23:48:44
02:44:47
22:15:04
00:48:51
03:56:45
13:04:01
13:07:49
12:01:27
10:13:04
01:28:55
11:03:13
22:16:50
03:40:10
12:46:27
10:05:41
23:04:49
20:39:11
12:05:59
12:49:53
20:00:08
22:49:57
23:38:12
22:33:21
00:18:46
13:32:21
10:11:33
20:23:58
22:20:23
00:49:12
12:26:49
02:19:11
21:41:50
12:14:38
11:38:58
13:33:00
00:21:07
01:59:07
03:28:10
02:14:47
02:54:41
23:45:54
00:05:14
03:52:23
22:15:56
10:18:53
12:49:43
10:26:33
23:51:09
20:49:17
11:34:46
20:36:15
21:49:48
03:11:17
03:43:28
22:22:54
01:47:59
23:41:07
50 17
12:43:43
12:07:13
03:05:03
03:37:45
01:59:49
20:54:47
03:58:44
00:51:01
10:01:12
01:27:54
22:45:34
01:22:15
12:41:06
03:44:48
21:02:13
22:37:17
22:10:19
13:03:49
13:00:35
01:08:24
10:10:04
02:01:53
01:21:45
21:01:09
22:14:25
00:47:24
13:09:26
12:58:05
12:49:10
10:11:55
23:03:24
22:57:11
21:53:50
11:00:30
12:44:26
21:35:33
02:09:17
22:31:01
00:40:19
21:04:32
22:56:07
12:21:21
13:06:29
11:02:25
11:13:27
20:40:46
00:13:37
21:38:42
23:05:49
02:09:47
13:02:42
03:48:26
11:54:41
21:25:49
12:54:26
22:32:44
10:43:21
22:00:38
22:49:00
22:15:59
22:06:51
21:55:42
02:18:03
01:31:58
22:51:40
11:27:02
03:48:06
Out #32:
157
178
In #33:
2
50 15
10:36:45
11:03:07
23:06:28
20:14:41
02:19:30
11:16:19
21:31:31
01:56:55
03:37:58
01:39:17
03:42:55
21:59:56
13:13:48
23:36:59
23:46:43
23:32:00
11:35:31
13:49:11
00:49:56
12:55:28
13:00:24
03:28:36
11:57:39
11:14:30
21:19:47
12:16:05
11:35:01
22:06:52
01:50:21
13:45:39
23:11:00
22:16:17
03:50:42
22:43:26
23:25:23
02:51:59
11:54:11
02:36:39
22:02:08
22:14:49
03:16:29
10:34:11
11:20:21
01:11:29
20:05:13
01:00:48
11:21:38
11:47:07
22:48:01
03:28:15
23:08:19
13:59:24
01:41:28
22:21:55
00:07:34
10:10:42
13:35:24
03:55:24
11:27:45
10:43:43
20:27:32
00:41:10
20:26:33
22:43:25
13:27:33
50 17
11:53:06
21:48:16
01:32:03
00:22:56
11:09:29
13:43:24
00:07:18
03:25:47
23:07:19
11:39:16
00:13:23
10:58:27
00:06:40
21:17:29
20:59:51
22:24:41
22:32:41
22:13:07
13:10:40
02:20:51
22:02:11
23:52:08
13:06:50
01:22:43
23:28:44
00:14:50
21:16:06
22:55:16
11:16:33
13:19:03
13:58:25
02:27:55
12:03:42
03:11:30
13:54:10
22:02:51
02:33:11
13:18:26
02:05:36
02:35:54
23:50:09
12:10:05
01:32:09
11:09:50
11:31:29
20:03:25
11:32:03
21:19:30
12:30:50
22:40:53
13:50:42
12:20:21
11:46:21
11:31:58
10:28:11
03:30:19
12:52:48
13:11:14
11:30:20
12:29:17
10:45:27
00:42:25
12:35:16
13:06:48
20:00:37
01:03:41
02:32:28
Out #33:
141
197
In #34:
2
50 16
11:03:18
21:15:27
20:37:26
11:52:35
02:26:40
00:02:17
10:25:15
00:52:39
22:49:18
03:40:15
10:30:26
11:07:53
23:13:51
03:02:09
13:33:26
10:09:48
20:47:45
02:35:50
23:34:58
03:34:24
21:49:26
02:11:32
00:53:20
12:28:04
23:44:09
00:45:25
11:51:13
03:53:13
12:34:30
11:24:33
20:36:28
11:42:50
02:18:23
01:47:20
11:40:43
20:46:40
21:01:28
23:19:31
23:38:07
22:03:20
22:37:05
12:00:32
00:39:33
13:02:48
10:21:23
11:52:29
20:35:36
21:04:07
12:34:53
03:22:28
01:15:01
23:36:54
10:36:36
23:28:04
13:32:32
01:05:59
23:29:06
23:44:27
11:11:56
01:16:53
00:20:54
10:54:24
01:27:04
22:06:35
11:41:17
23:54:52
50 15
10:07:04
10:00:36
12:58:40
13:40:00
12:18:56
00:37:58
12:05:08
01:08:00
12:27:33
03:32:48
21:21:28
10:04:15
20:30:43
10:28:20
10:19:59
02:09:49
22:58:02
03:58:48
20:45:45
03:05:39
03:33:53
21:15:52
21:50:44
21:39:46
12:30:29
22:56:13
02:27:17
00:38:19
03:11:06
01:47:42
11:03:20
12:28:07
10:19:37
01:00:25
22:54:29
13:27:48
20:34:29
11:04:15
00:35:53
12:14:00
12:31:32
21:56:13
12:40:41
20:18:48
12:28:54
22:38:49
02:24:04
13:53:57
02:42:59
20:10:33
10:26:20
10:47:40
01:39:17
03:49:57
03:59:57
02:31:07
23:26:06
00:34:03
02:52:27
11:24:04
01:01:44
13:15:31
20:14:39
13:02:36
01:21:42
Out #34:
178
135
In #35:
2
50 15
01:25:25
01:18:51
01:14:01
11:20:24
23:23:02
22:35:03
23:06:24
02:40:53
01:36:59
02:31:49
11:09:31
11:55:29
13:53:07
23:26:17
13:13:45
00:34:14
20:18:59
11:51:03
23:58:51
20:08:18
12:03:26
22:53:08
03:04:17
03:57:27
01:25:35
22:58:07
11:27:34
23:45:37
10:19:37
13:14:13
11:15:36
21:15:48
11:06:29
10:32:03
13:54:31
02:52:13
21:53:10
01:07:01
13:59:25
22:41:54
11:52:44
11:53:55
13:12:17
01:58:08
00:39:11
02:02:20
22:58:32
00:01:50
03:29:52
23:40:22
03:32:16
13:17:16
03:46:48
00:21:06
02:30:13
11:59:26
23:23:45
23:50:36
11:00:40
11:45:04
20:03:42
20:02:57
13:24:19
02:48:06
03:41:47
50 16
13:11:33
03:42:56
13:43:47
20:53:44
11:12:22
10:40:58
20:08:39
01:36:31
00:04:07
23:13:37
22:18:33
03:19:39
23:50:29
23:40:22
01:28:21
11:09:44
22:07:35
01:45:54
22:11:25
02:24:35
00:05:32
22:55:13
02:14:11
01:09:35
13:56:21
00:04:02
13:26:35
11:18:09
13:47:38
23:49:50
13:28:30
20:15:33
12:59:50
11:06:27
23:35:42
22:15:38
10:15:02
01:07:38
21:14:31
12:14:27
10:38:35
22:10:36
20:06:25
23:25:28
00:26:38
20:11:55
23:42:32
20:54:49
00:38:45
12:07:08
11:21:58
23:26:48
12:55:25
21:38:13
01:32:17
20:48:34
12:59:47
02:28:51
03:34:02
23:59:38
23:26:32
13:45:37
20:56:15
01:12:33
23:11:25
00:19:54
Out #35:
146
137
In #36:
2
50 7
16:12:16
17:02:56
02:00:43
07:43:28
19:31:03
19:23:02
11:01:23
17:37:13
08:00:37
09:47:19
02:05:50
02:55:26
04:38:07
01:19:38
17:26:46
05:04:13
08:48:10
19:33:19
07:56:30
14:39:01
13:47:01
11:19:25
10:51:39
04:02:20
01:45:37
13:07:07
08:57:38
00:11:51
03:04:42
02:37:19
14:17:04
17:58:33
08:07:50
04:53:08
00:35:37
16:09:15
10:34:23
17:59:22
10:01:57
11:35:47
08:48:30
05:03:19
19:27:11
00:23:04
02:39:17
14:16:40
09:25:08
18:07:30
07:38:40
09:35:08
10:45:21
13:51:39
20:57:42
12:22:56
23:47:40
22:27:51
03:51:39
50 12
16:11:49
18:27:20
01:00:10
09:23:00
18:10:17
09:00:24
05:27:51
19:14:16
16:31:50
07:01:25
11:25:01
17:49:06
03:27:46
12:52:51
04:21:09
04:43:39
11:15:46
16:59:18
17:48:37
17:34:13
14:52:29
08:59:24
14:06:41
09:35:40
13:11:07
10:20:27
00:41:29
03:25:06
16:12:27
07:28:34
01:05:24
11:53:12
11:21:34
19:07:08
18:45:57
05:12:52
11:47:12
13:51:16
00:39:30
16:25:22
07:30:01
11:05:54
09:35:47
18:21:00
19:29:10
05:10:55
00:03:31
02:59:49
13:48:24
17:23:40
23:05:14
01:30:20
20:18:11
11:56:36
12:55:35
02:15:26
02:03:58
11:30:32
23:45:00
20:22:46
03:46:42
21:13:51
Out #36:
60
126
In #37:
2
50 7
10:00:23
19:25:16
13:58:41
10:41:15
07:38:03
05:18:20
12:14:51
12:50:39
03:14:16
17:34:44
19:13:25
12:43:56
10:54:50
07:35:04
13:49:25
16:39:37
09:34:34
14:23:28
08:51:31
05:56:07
18:57:05
03:16:31
07:48:40
09:35:27
11:25:25
15:36:05
06:27:40
18:39:52
10:18:05
06:34:13
01:40:31
01:00:56
01:59:30
09:08:45
18:00:25
12:15:27
11:46:31
03:00:03
19:22:18
13:27:25
12:09:23
10:52:54
01:56:29
12:17:45
14:32:05
01:22:21
00:17:06
11:04:29
01:24:41
09:33:02
12:52:39
23:38:17
23:00:06
13:09:28
22:01:52
03:36:48
03:14:57
50 8
08:46:07
13:58:31
18:33:38
17:59:47
17:23:28
19:32:59
03:33:10
10:57:35
03:43:39
04:20:59
01:14:17
17:34:07
09:05:20
16:48:36
00:53:24
09:05:04
08:17:56
05:41:49
04:48:41
09:21:20
13:36:20
09:02:27
07:31:18
10:47:32
07:08:48
14:07:58
06:58:41
09:07:02
17:56:08
00:09:14
10:28:20
19:44:10
19:14:10
03:01:36
11:43:59
10:10:14
02:19:53
09:49:25
14:32:08
11:27:53
09:42:42
10:13:34
07:09:32
00:34:19
02:18:18
14:19:04
12:39:46
00:30:23
00:55:19
19:47:28
22:12:46
22:11:25
10:44:21
20:37:55
23:07:57
20:46:09
03:29:45
00:35:19
Out #37:
68
82
In #38:
2
50 7
14:41:26
03:37:29
02:15:49
15:31:25
10:58:03
14:40:34
01:53:26
08:46:19
14:06:36
11:09:16
04:11:21
06:07:28
12:58:43
15:57:58
13:25:44
08:40:25
07:09:48
01:05:07
10:10:18
00:48:51
14:56:39
05:50:17
00:15:18
08:23:50
02:30:07
05:17:48
09:37:44
16:28:38
15:50:34
05:23:50
10:25:39
14:03:27
14:37:59
10:10:09
01:14:19
04:49:14
09:16:22
09:49:49
13:04:11
05:28:42
15:32:22
16:10:33
00:55:05
04:56:05
14:10:11
17:14:52
16:38:08
13:59:03
05:41:31
11:37:11
01:16:28
13:35:40
02:16:12
10:02:02
01:48:19
23:08:55
03:28:30
50 3
08:15:44
12:03:16
00:55:11
11:35:03
01:10:43
04:28:30
17:27:37
05:51:57
16:35:49
03:45:24
18:28:34
07:36:35
02:39:06
09:53:38
14:27:32
08:36:03
08:42:51
14:39:09
19:48:46
05:45:47
19:23:31
16:21:41
03:20:09
06:30:22
09:22:12
03:10:48
18:50:18
16:28:58
14:58:36
15:41:04
09:41:49
02:50:15
15:31:51
15:47:59
10:56:51
09:22:43
05:51:17
15:00:08
07:43:39
10:39:42
13:47:37
05:51:55
11:55:33
10:24:41
18:42:14
11:29:27
12:16:27
18:55:12
12:37:16
01:08:27
12:32:58
20:34:12
23:03:49
Out #38:
69
32
In #39:
2
50 7
09:39:55
05:39:49
13:06:20
07:09:18
06:29:20
08:12:18
02:49:56
16:04:19
18:37:28
04:30:10
01:29:38
13:31:51
01:02:30
17:29:36
15:36:40
05:19:45
04:39:52
02:55:16
15:14:36
04:15:20
17:30:37
00:42:13
09:29:09
07:34:41
06:07:04
07:24:46
11:53:13
03:45:17
03:05:51
19:43:54
06:44:03
05:35:09
15:15:53
15:41:04
11:24:05
00:38:47
01:43:10
15:52:41
12:13:42
07:03:16
03:37:19
02:42:37
01:21:34
14:28:24
02:42:29
07:48:33
03:24:20
16:12:49
15:35:33
03:51:30
23:03:12
23:19:32
00:01:20
21:49:14
00:18:11
00:18:24
13:22:19
50 15
12:38:57
07:37:07
17:32:40
08:17:42
08:07:32
16:14:55
14:19:32
02:37:53
00:06:40
00:28:58
09:56:27
00:04:05
04:28:28
09:43:19
14:30:53
00:56:22
09:08:42
09:07:49
03:28:41
07:36:38
14:09:27
17:37:40
14:16:56
07:56:50
17:11:00
03:17:59
14:57:35
02:42:32
10:18:33
19:02:29
19:30:35
12:37:40
14:48:50
07:03:06
09:46:58
16:33:35
02:52:55
03:16:11
03:20:05
11:55:11
05:12:18
00:58:41
11:03:37
04:06:52
07:10:43
01:28:30
07:46:41
00:53:56
09:51:08
02:21:53
11:46:00
21:15:44
23:36:04
20:36:57
21:56:02
22:02:04
11:42:54
10:38:01
13:00:08
10:31:24
03:18:20
11:47:14
00:18:51
21:00:03
12:24:51
Out #39:
81
155
In #40:
2
50 2
05:45:22
02:59:36
15:48:13
18:35:05
07:14:13
16:38:55
05:43:40
14:36:46
01:16:31
09:12:08
06:11:41
02:18:50
10:59:36
17:27:52
01:57:30
11:24:05
00:51:49
19:12:41
03:45:24
08:53:03
15:15:29
15:28:56
16:43:58
10:51:13
02:24:05
18:49:23
06:23:13
04:05:46
02:53:33
02:37:51
00:25:36
09:31:06
19:48:29
13:27:32
04:20:32
02:55:02
10:21:03
09:24:58
09:55:03
02:50:55
08:25:32
03:12:58
16:10:32
16:06:15
08:22:09
01:45:12
02:45:10
15:08:05
15:03:24
18:42:56
10:20:59
10:09:31
50 13
00:00:24
04:36:11
11:14:05
10:43:14
03:31:37
11:47:16
04:33:24
08:18:31
16:37:51
09:25:32
18:40:34
01:22:54
02:54:09
10:09:31
09:24:15
01:03:11
11:53:40
05:55:51
02:15:16
19:46:14
17:29:19
03:07:29
12:43:19
09:20:28
06:13:30
05:40:31
02:08:42
11:43:32
10:18:48
14:08:27
11:23:55
08:28:42
19:15:34
14:37:58
16:04:16
18:38:37
16:04:33
02:47:14
02:28:27
15:22:30
09:26:04
18:26:53
15:55:13
11:53:33
06:48:13
15:41:39
08:36:28
18:58:35
04:28:19
06:32:13
20:16:46
03:14:43
10:10:23
00:49:27
03:41:38
23:57:31
11:32:08
22:14:43
00:43:24
03:31:36
12:20:34
12:47:52
12:53:38
Out #40:
12
131

*/
