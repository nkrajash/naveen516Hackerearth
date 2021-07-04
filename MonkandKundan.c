/*All Tracks --> Data Structures --> Hash Tables --> Basics of Hash Tables  --> Problem -->
The Monk and Kundan
Tag(s): Ad-Hoc, Easy, Hash function, Hash table, Hash table
Kundan being a good friend of Monk, lets the Monk know that he has a following string Initial which consists of the following letters in the mentioned order: 
"abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ".

He also has various lists of strings, and now he wants the Monk to compute the Hash value of each list of strings.
Here's the following algorithm used by the Monk to do it.
So, the Hash is the summation of all the character values in the input:
(currentIndex + (position of the character In the string initial) ). And then this hash is multiplied by the Number of strings in the list.

Let's assume that the list of strings is: ["aA1", "b"]. So, our answer would be:
a: 0 + 0 = 0.
A: 1 + 36 = 37.
1: 2 + 26 = 28.
b: 0 + 1 = 1.

So, 2 * (0 + 1 + 37 + 28 ) = 2 * (66) = 132.

Input format:
The first line contains an integer T, denoting the number of test cases. For every test case, on a single line, there will be N number of strings all of them separated by a space, denoting all the strings of that particular list of strings.

Output format:
Print the required hash for each of the mentioned list of strings.

Constraints:
1 <= Test Cases <= 50
1 <= Length of a string <= 30
1 <= Number of strings in a list <= 20

Note:
All the characters in the input will be valid, that is, will be part of the string Initial.

SAMPLE INPUT 
3
aA1 b
a b c d
aa BB cc DD
SAMPLE OUTPUT 
132
24
640
Explanation
Refer to the statement again for the sample explanation.

//My C Solution:
#include <stdio.h>
#include <string.h>
#define LEN 1001

int ind(char s,int ind, char init[]){
    int i,k;
	for(i=0;i<strlen(init);i++){
		if(s==init[i]){
			k=(ind+i);
			break;
		}
	}
	return k;
}

int main(){
    char initial[]="abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i,ref,n,t,s;
    char str[LEN],*p;
    scanf("%d",&t);
    fgetc(stdin);
    for(i=0;i<t;i++){
        if(!fgets(str,LEN,stdin))
            ;
		s=ref=0;
		p=str;
		n=1;
		while(*p){
		    if(*p==' '){
		        ref=0;
		        n++;
		    }
		    else if(*p=='\n')
		        ;
		    else{
		        s+=(ind(*p,ref,initial));
		        ref++;
		    }
		    p++;
		}
		s*=n;
		printf("%d\n",s);
    }
    return 0;
}

//My Python Solution:
def index(ref,x):
    for i in range(len(ref)):
        if ref[i]==x:
            return i
            
ref = 'abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ'
ref  = list(ref)
n = int(input())
for i in range(n):
    l = list(input().split())
    s=0
    for i in range(len(l)):
        for j in range(len(l[i])):
            t= index(ref,l[i][j])
            s+=j+ t
    print(s*len(l))
*/

/*Editorial:
Author: Arjit Srivastava
Tester/Editorialist: Vedaanta Agarwalla

Brief Problem Description:
Calculate hash value of a list of strings where hash value is defined to be be (size of list)*(summation of F(ch) for all characters in list of strings)
where F(ch) = position of ch in string + position of ch in "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ".

Prerequisite:
Basic implementation ability

Difficulty:
Easy

Detailed Explanation:
1)Iterate over each string in the list.
2)Iterate over each character present in the string keep a note of its position in this string. Let it be 'i'.
3)For this character, iterate over the Initial string mentioned in the question and find its position in the mentioned string. Let it be 'x'. (We can precompute this for each character)
4)Add to answer (i+x).
5)After doing this for all the strings multiply the answer by the number of strings in the list.

Here the number of strings in the list is not given. To read such an input use getline(cin,s) in C++ or raw_input().split() in Python.

Time Complexity:
O( T * N * SZ )
where T is the number of test cases, N is the maximum number of strings in a list, SZ is the maximum length of a string.

Author Solution by Arjit Srivastava:
tc = int(raw_input())
s = "abcdefghijklmnopqrstuvwxyz123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
assert(tc>0 and tc<51)
while tc > 0:
    tc = tc - 1
    l = raw_input().split()
    n = len(l)
    assert(n>0 and n<21)
    hsh = 0
    for i in l:
        assert(len(i)>0 and len(i)<31)
        for j in xrange(len(i)):
            hsh = hsh + (j + s.index(i[j]))
    print hsh * n
	
Tester Solution by Vedaanta Agarwalla
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define maxn 100005
#define boost ios::sync_with_stdio(false);cin.tie(0)
#define fr freopen("source.txt","r",stdin),freopen("output.txt","w",stdout)
#define SET(a,b) memset(a,b,sizeof(a))
int main(){
	boost;
	
	int t;
	cin>>t;
	assert(1<=t&&t<=50);
	string s,base;
	getline(cin,s);
	base="abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while(t--){
		getline(cin,s);
		vector<string>v;
		string cur="";
		rep(i,s.size()){
			if(s[i]==' '){
				v.pb(cur);
				assert(1<=cur.size()&&cur.size()<=30);
				cur="";
			}
			else{
				cur+=s[i];
				assert(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z')||('0'<=s[i]&&s[i]<='9'));
			}
		}
		v.pb(cur);
		assert(1<=cur.size()&&cur.size()<=30);
		assert(1<=v.size()&&v.size()<=20);
		ll ans=0;
		for(string str:v){
			ll val=0;
			for(int i=0;i<str.size();i++){
				val+=1ll*i;
				for(int j=0;j<base.size();j++){
					if(base[j]==str[i])break;
					val++;
				} 
			}
			ans+=val;
		}
		cout<<1ll*v.size()*ans<<endl;
	}
	return 0;
}

*/

/*I/O:
In #1:
6
1
a
A
0
zzzzzzzzzzzzzzzzzzz
aaaaaaaaaaaaaaaaaaa
Out #1:
26
0
36
35
646
171

In #2:
40
qclDztbYqxG bZJyu3493wqUR67Z2lA Pft8lYJI6JCCGbthGR3 FoJ0DIp9IhzIGt2Vel
1UN3 0iTr9QJZkZJDGdC7pNCcPxxoXM 6P olZIU esJ4 rnWCyJUUetW9cogl9SBvKCN0 6 KqBNQJTQR8C06Anhz7O Isp9YLaM5Ax
flG6LFCsj wFDGrfWmy 8qcEe90ezKsHKpObt QFwio7B2geesSM2nRtr3HQK toiRrA0HIgilUCb9ON53OdN dqsOH0Nxkq0AqrkVbJ2 NQ2 4s9QPdqdrdvxkUg2TCJ xIz0c1ONU0l0xM0nGNpak4Y81p HFW8RfxPbBOg 8lqK0ryImuNpAHA tfYhEa2D2w64 eP9v0gYWyy4IIptUi3GjMlBk 0reGCp397dJsOVaw7uoond3aycVx 3LaPn9wYYwV652r0041XwmeSA
EcdA3iIjnpwRr6NjLc HfS6ZwY0ZLZl
5hreDkmrXQkk6Ju25NunUnU8yjC O zRDCQWjYewTRLlUVZlK3GQr VrmIjrcr26ODGqkV1jZe1wwcTc zGIUCV8Zn SLHrCb86vvO6oeGtv 7L6LfeAds0XQUHk3 eya4BNV2 Qio67fY5Y1E4hj5VAEIpwFq 6qJnFY4l5zjcoBIlZEZivGqcpeENGH wikeNyHi9 Nw7XgAcs22
KfRAGNXuC1gXEgtjJS9R1He9ymtg7 TwWRuRphtrhyxpoY LR8QWDBzKYoIlM0PmugtOoYO92awI jH PYr44gRUwupOuu8 fdzYnDHoE 8jk7BF9IbPzM XoaSF2L1 PlrkKNgrU qVgT4yl2eGwbv5oB 33W3uGkLKUeWdu1VMeHWt5yjy7U4mZ 5rvNV8npRS1lYseJeQUDpHicadR tT6efq5TX2FnstCPKtB340dIcTpotx kdv96Y267qgiujWnOlY Eeo81Qt9uqJSRrVeBD6c9R ofoph2uTdqRUYmCrpI mDE DTgC13wFEYjfbWqLMLJ9a0
mqFtEBy9l7fyMH zGElzpbXFepCrQEQUxuJIKEn9mPnrz kH2Ul4tt qCFW9nhI6vchuNr kEIKjk rRiY0tIsvpvuKGJLwYA1uBnunigHJa qYClGEpViT4OUb9Y5zxiIZL1Zws h Mb8uqekDQvL779Kfo8FG9FxVxDDjpV dGPoaU3fN6cdWMNKGEJ yyPqEWTWr2RwJMj8muFaCduQpSSySn
A8 qItlH0fKfhvc yyhd9LD8JqchdCxKSiI5hPaVb Tiv8 e6hCafnkUwbLeeU5lzM8grn gnAW7
GqgKiZ0COpUp9vf4qf 6LxZHCGulPk1q3xF1A0T 5peF3afqSICJ14 kH Yu7MtoKVhZUfy3fLSYHeeg1tUPM rf7CnkrWOMAZiB6MWYgU
gwanDEhkFKYDR5EaAd fiHytNoAWH1M4Cb8vba
Cj84iCwz9Wfmc4vqMXanqmX6xaWe GnqEIUi4xKFvLvGCt oPNF9SoqvbFh6fuowG Zkd4 UcxnRStsmJUzPXNJf1FuVbs bWrbcKiPWCNntcq0HtGp1 Hr5AOnRFnSfYp hqLD7te UHGbHsY3syW BCVFudQ1o9k9NfMSi0hxnFhz4RwI gYm6fgkSAzjFnam01
4KsReQch4Z1Vt3Tp9PvePESIvU 0YaA2MLoYGaEMPhbRhwcDUCMZMJ SIGgdgrDRMTcDXQMQ S9LJUuiniT0 gtZKt812rLIguI y2vchiMRTo0eMM3CQ LDvBvdcLnbuxRMWikRi zGiUdkCNqLTqvebccfZAwc6
8kOONePigDzfnJ pLjS DVigePvpptLbdWaqd4gSwB9x Xk6Dg3zDz o8LeehrzWj8xagx9X8ZpN60 Vyiy8mNGl9TNeBT CCxM5Vftnh1 42Dwo8Omq72OIo9bd 2Avk7Mpqbll7vUPlDK Wk0 79HOBaBlIp8kxNnJDH Rm5XJxYw6HEOuFcGyIiE 4SFHwjv8Dl vazvztoyBQzNc6paNBvGtowtPvP C MsJGq3vpL3 mxJPi5kad0F3sJ9k2R mzaYYHSNaBiU8iklRzO3XbM8OIdQY UAAs1SSb8 0isp4TmyR9QEML
BGNAvXncUAcJeIHL9FIC8Z0EqS3 VlEFmTsa9RVy D7i 5G6Od8HeppyJWw6fpo U3iGn2QboXK kzxQa5PEaC8bAebhAG OzUWjTZ4OWwLVb wqfx55H hi 6OVa7Wmim ofGqVdf5O HrjqQwzyb83
O202 gijA 7vnJKkgP9ud5lYmXkPjSFlXfSTft yvn9sS5G7CclPYM8aGi QWIw0fB4iKZaY55ftgIAevCFk Ds86DlNjjxhQYeyXtTGhkwMkrT HbJ0HuvBnv88k53wBVXSvMnaR aUZho7Q3Wt eUXvwwzFXzo 58s6O0MhOXnwcuuBXqrzK4 DfuOWyifC9NFcDdaan3noxsKhhU r 3Xzv GPP
Ttk7bDqrPWa6anTaArZRzooVy2j em6xQ0GJEUxZGj KcL76DveGyJ66 7SqHj4emzAJVJux2z 2Zrou5zMG6LFaDwP2ZukNxv6UPHKoG eLju4JpkrQAt02wJdXd4lS63Oc6kJ wGDuCQLFc6V7BtnvLmfE DORghx7fh 9rDrhBXcai0ON9Fi ShqoRRJuvUd 37aOIDiOl1u05kF9cG9vgov 2bbsLgol285UmiBn3XP Bp8tSqAxSJ80T
Jy34AzLgfGb3sZDS5F1UEziuKzLqCc F3rai0SKv yr5iHohJA MlAZjCj
WgcHAc3BKjsGyfISrdFv520m t cuxvIDPm4kOC0GN4KkS8mmML8 UEQLsi7hOf6ZAsPmhe KpUskT7HEVr59uMAmurzSSP9bXwrh0 TXT92hT0TJvWK55t2hu0OUgO8 UqLaRR5Ot8pyhlo2w9ywZw6kx h4WSJiwteaznld4YCvU bt80UxoaIh0rk JjfWKDurOfK JeLTkSu8nG0z4PLhY9EXVWkxM1tmg aZ1oJSNOA Kb8nKLIXKy8nf8Z YGs6k4TbNDlE5akVWpM9u mOVlhrx6GVXkUWgw2fhDGiSZVmw XrSfDpLqoXvdbPh m8hxf6 2Y4GUnL8BaZasmK3uqCbu4rd2 5MSsODWJH7VuuK5B3uhtrch fQbvCZ4VhW
0MkHOcn x4LLYfKU2wAKg4 mGIe8E2IrqoDtV5uf7QT1BTJ4zuXGm
5woHZAdyBallvYCN8uAT4ZAq IVgb96snblzqpvD02x a1ny 7Mf6bqW10wXIV OEYcEKSiN2rUGT wCdOmPPSL0h50Mq zpf13hXm 5E4zTBtucisB0418YFnEhGubR PqpK6n V3bP YFHeCV0j6IMTWww0Ag GR 0hTMLCPuxgI4g mXL0l24 bkYJvCFGEXqQVVvlKqASr stsAWeW7UoSdFNSWsCcdBhdx
WhXP4IcMS4bOzC9xemG8noLUru4 qgm7V D11WhJ2mPVhqHHns3WLk4nxebRO70w 6WVyayEIZ56dCsqK7ycW p5POPK5pEU3amf61k5c3KMBgGQT DHuFo6ct0DmLZ6FYZeULj XU315QXH O3PVdM2198ivoR0Y4obrLAznKI b3Nuoz96ypS4 PmnA55dEUXBAOXk lAVoEtmR1r8GWfkeEIaK960M t6Zeygx0
OeWeaQQcbP5 aZE tqaFmmLqgbdEG 5x3bn1M8bOi369i I0oIRL0y00TvwGjA91pyj II6HfH79uaK81QT1tlLvpBbT8i QfFu AT 1q4Lf2ivW11oDRS f4tSWgGkPw
TRckIvJQD1Eg1SoDcWwA4oE2wk23q ZgFI7PcXnbnNpD ruq56VR9n14h 6LtADd8b7wdAgJpKtZT9XqjPC p4JX9I7C4EKep50 AV ghjCNkvriB aetdMh0N4A55cIbBvTX6obv JUzWfxv7MF ux sGx1fsvxSSIaBW4lZ8Ve 7rL4p jekDmoef XE60XVPpaA8aPPaswHyrxXh G g3 JJRcTnsPdX2MIKxBc2iw20pss7z
p0DXNdWOedLMVbVv4yiI KFIdQNoOxn3epE0sh6db3m4UD1 uyaX1ZQs1kQ8vQd4Qss S593wFrHExVe hFUTc2nRPVDSxHdZ5g X85ZA8S2rDy3e35MzE4W KbUW1lu0bKo V8CWjL8heWTGlxiqLdXAxyWQ gavLHVDFvp5ZpD8QqAapKQNp3 Fi2yjdiD6PAstAaCVuiV RQuEiVhfWY05i2Uo M3yj9lcKkaLZTbMmMXZOSqfgQl6HAa r7JO bOKDacvbncwSh RQFAiZSQb9LGyIq mmGrvBRF DTFwW7fYH8x8PIQ1dY PgS4BBDr 2BkqvaM224uaGslWBf EYKyiFQvFAQ3Lu3
5e0vmX eDAJFb5IGoUJUNk9TQe jrZ2H2tJyhnysccs NopQgrit4Gc7cYMmO xtwL2lSTIx 8d71JJw4l6pS i76HY8vdKwYr MbyUcmarqGRJQ0NXql1tzaREvYbG Aa22UaRKAyWgNuI5 mO4MUaQNWJmj3AF i Y7fteSsOi1ncJPtltjKGh3wttYk
G1 hGNVX8COCr8VDjvv rdHYrPl Un5Jv1ZFev2 krhi6X Y36 JZwhsdXj3Nm
lNOXitp1fIKioM9kjsQyw9BClvtBP ExSB4b1vh1XrFED92SJYzlBF ska2ix9l3X WNi WDnJ50A9QohFGaMaHpCFcRYGNMMbGm KnePhi1ssE TSOItSIrm1FrkhTlhy4WRUC88 niIpJjtTmBbJnLtZ2TEwwMGUf ufm6xHZ5sL t ozj0ENLDNigKERWAe96tDMmHJh5 i7mEX1aicW4PM6 KbZF9FeYod57P5X0kgxkSbWU 5t2qM
VNEY 831FlirB0I5 i27NyGIazCZgJy4nNAiI EojV b8xB1cMI9YoJa2fYtQuD9 Z6SB41Yx6PE32Gd pTYXWbWkt9Ye5a sk97sO5Jn1toOXBxYfhqBVAWTNxDmE 1vlxTjwRLaZe6FBNg5iLUlOrkkiOh hB2 zHBrFBnPvenMC5 5rz2x6H5OHL
EL LhcJx96yNmyLLizETsk7Kgi SV4xoNHWvYI2NMyCl6X1o5pGT1ayIe iPPgIKCUKnFNmPKRYBDeeaVUD 2ITHYgdttP0l5hOvIHethu4
hvJ0JXBVoT65Dp5CGoo7QYZ a hBpuDkAqUCzpYvqE oArhgy0olaOtwH W8Dndv1utS8dNsaK2I zhM ChXgb3 lQKTWTfFmgZ35r13NMpq mFE8xQK9Qayc1NHHERB KKENYhl7tDaRKAsKXVfRW9j pIBMjhEwryLlZkax bSdx6mtmdfzhE907aHMhK GM jMpCvR8Up QDrR9iFtNqUdGke6AQL0ruuI0WBD Blclzv2m8tv5EHSumjEeY4l3Pd4Wy ez9YyaeFEIPYktZ7qLdBfAMpzuKz arzvF34S DL5crzNHzBKe2K94lNtVI IyfVNsZ5N7WlP8NpVa6cMU0ewMm
CRX45 hPOhgK7tl Ux2uyVBPfX GJogL85O3hdK4Nf NLjH11GVvhaCP02hWZ5AGFWBg6o avHDJ5XD T5ykZsVBEcAIe5V DNPb2TpaOvOygTmL7chlr wLknBHWOBDZ LPJi1dlbPZWjZHizBIrDPYxRf LhJGgkY7TTl3 VW9dTckKJuPRyWlBaDYKnyG0bCxKt1 YalJ7QtBqNn7pxasvNaGw j4wSr3
Qw3T H TLl2n7sRaRIjY1r9 4cscHvLe3HZ34mCusxZ6fqDF1 NAfVGfg F4ixwwlzZ6 cQ6ZWjfAb5B5CxH2TSaWrsl6Y
dTghKMt DnwilI6KNHGYiQ F0WlpXA2sZXI1cx nJN2zWNsocWh6nY I7tvTOpdE GThY1bDXKbNzcnbqsuKXUkzsp7w FWgpymbNsbViEjuIgWE pK6jyO6eXhdj6Q60b1ErJh Jl 11QKe07LX0 PLiK4zBW8 EKxneCchDbcrNpztkhd2jO4WIbpIQl tSE9ngULon410rfJ n8u4oIbEvDPMsODf2GSyE UYsDU1P0wYVV8zX3LW7 sh8hKW9aauBJSOt1345 AR 0eETWEEE1jLLBrj0pP1G4YCN4rBH
JtBpLM JIua25ixfSG wPOZcQyqZ4wiUw5jZ1r46Fx fpPPpjFjrzFYCy6nAWjbXRX p95vVm6BaCQT5Eqg0fV5HVala L2 RCM51Eg4np5vs4xRcGR9 2YGhlP1jiJE ytD8zEnjZZn8F8t6RtekILh6IJ7wn jK0CbB2PwhqcWAga gfTvwSbv6F8Q2NDIKQ5L45g e8YCFHBoP FODmLBV0oPBtY
FbVSuVQk5RzTiI9TQfuHBf hqHo4bKAQ1Seofkm6cs 1T tzk K1HpF4lbN2Mygm1XgqEi6 JkTKLD6jQzkCxve3vZM3M5
BJHE0MY9JfrimUJropy2EWH7BKFtq iQlNx5JJ5FLQmYcSuR1DvIX55jXj MJHMIQsEahDF2zYl5c3dMsrh hF I9bGCgC9Bw54JZwF mkC2hGI hQ4vg4gCGY7P
LANy4sSl p95vksHszLWDL
DPfnmC0TOfGZoM HHvv
ICEXxwF7CX5gnVHP 7guMRcAO8bCT1t0ZKsh4 Oi1NRgNQ o sQEWk0gyVXqBeeVJJUGKJSL2WdV h2v3hNRJR6FM8046UU fZLH7RXMq0zKy4MlMjG v GKhRedWLY8fLo4tSd8fvvEAqm0 65W6WWeiAShBiAUMJcXBkTfg dUoZCA9J kbvaxSiNqgKF1 coxvJ7oWQaM PDW2rTRvZjG IK9Yn7OH7Jc9LZ7
4T5u4kw32g NB34TLF5NlkaD 7TlIGXu2iaZeQETfwoPvmRNS 2WyUkUD4jE7F45peYLLJAbCaV VAJVejipOlTPejWCkJHIA ua uOGNYIVGCtH0 12s9g99fBmruXsH hLrXSIxNjvc5DPmhemHhge q0mM8K
Out #2:
10312
37188
151920
2276
96072
230940
97647
14070
24924
2610
78474
50520
224180
62772
116312
122889
8488
303380
6537
136304
112296
43490
148597
275300
81828
14133
137676
85788
22710
267700
123144
24052
205524
110747
20658
35091
1558
1386
138510
59600
In #3:
40
mamHCpv3c6Ja82c9O BN9vEc5eKgqKou367cE69P
6kNqCGnq 2EerDGQc D q9v0k l03uCK9n QpPoF3mz8E8yWgccm2m4Ly fl4XAy0DpGn3H0gAB0ajQDS Gf1zJk2VprOasjW3Vg PdhLK70E06OJv8Vhy aDklOC3YUjdWWuBFgoAhyAWUwu5eXD oXxNzVBy
edrh3G nssf04FZKMmn4DR6Q3HApYaFUz KMC6u1hXpjhvBoNF2CQCQ2huHso4K aMl86O6 n2cjN3Tiu9lLVLNg 11Rihygr2GCSgnETq 0IXXzNGLHN0D3tgB74Ea L2p7k9zAQtm Ifo6X7tGlBDRf 0hl7fd59rAOxRCbBuSCBRvkFiJRd XYtmNd2M1W31gznlLx vm2PeCT3poxNc sEwt886C fkeZqT1mDaeX5TvmdlSd5WaOnxJX BD 8PrgBnum9vqW Sy7lVzalEUpSF1XsStxmOSX L8Cg1h0y fP79D7LugGS7k IIV96uThwS9eDxo
Aj3Up9Uac mDalLLCExvWhEC8Qs4F9j7xiMMj
7l2DNC4CxdObDlXY jOwCH
iy3dKiYD JfzQ7mwDfL5ekt30sx KLbdcBIqk1DWF2 i2cIKDLCVFOuP2 NlciVZyBE2lowrB vRQIK1LNtCYUZcb
AzLLl3j eOA0qlt HMU1LYXsGyFSwAdzZ6J xA32Fq UCQNtTM9cvs727cqZH9Yo3izxS MULt9 1ijyS5rX5zqhtpqlxzvRwXQMdNn eKIE25pZvYf5EfET rifAZtozqy8a2F88cODvoQv3yrF u 6D0en1M9s ZqYyD9c Lb3MWcLfauVDN4y4m9aB8eWKk WcMZB9qqkXK F44lSnDNS 9sK4bLUtZVGApGwajjDWjhsK3zTwNC
pWTgu9KG3BmP1KvaDXFetYeOzTeeJL avVo9QpVDGkgAYb3k31 1aV72 QKUUnj3jl94PeA7FQCNHhkSXS WjpgPaEpabnYeIu7p l13TgtUjLaH3NbMVQDmTWx C3j15ZKhV AkdRSAjTGqgJDORNPdzrFVr7RF wz1IY9OmSPgQMUYFHSJF7Bx2K OD22Z1vchZE AqyniHxDO7fIPtcjgEKlOEUrU ZZVYw3oq7sH7ckHkP SIcJGNz9eJWoMelyl MPkPxemb3IOXG6i Hkfp1XKaSqah0PVZQDD6S9rnK R vSuCm G4fJI0bWB5qHsofdTgnzsAI0xAbf ZxS8bSsgGrglgfa9Ua
D
NEom0nu4JTKAq0 mnD4nIXF4u eER CVbnoqPDYl42Cjb1ejBec6OCS6As iOblH3FbF7L6Dd JV p4puj0NT nJBM3ESS2BZZk4cYCBB4XZ5wxmK8 kq9NHd TdyMa9O bG6pmV 2Ni46kqWaht5 AlSWciCcJHlQF 7RtWdCNh7S2BYLTgFcfTZ 8kmxBxS8gT0lVo2Eh hF0KoXnBV F3 VQjNadm8QiaXsYo2ZbnKHh03
LWbHI m4OzwEPVIMPJMs fz DEKhllI8zzc SSuBbfMO5cbQJlxv
KCKK3Xgl4JGvRtgI Ss0fOf em UHE71CeGkR8uBie9MREdvK yeBuvFz1 vlcv1ER 7IE7qX70LsHMOFgwOBESeIv Ud5O45gy XpS1MflVNTlp8Oz
GVn1Qksqi Snma6HeYpDhWGpcq TkO1 wStA5KND1SKP308f vr0 zTFvlmw4R OAQxX2mqWowa 8eA6OLtN1xA84 YUaHyBKq7QqmFlz Rog yBHdOv3dQT2Rveen4 FggtGiPB6fJfKbIxZq eF4B
swppKwb8NLgKa5Wil71 7WV8gaAKrziApUypp5wbAa5Ae9TPrz wBt etvLJ1nvDNIdDEPqOYOl41u 2UIPdg lr0TtBK0i8W6z4BVKrfY5 19JcWlTqgmw1ffjoPFTZD 2Rkl8VuQTvkXXnMXKpC62H2F8 JL4vs2CEqaLrOyJG ohBXpQ8sRlY6M0q94ck6KQ4Tuvt K7eKJPJe1Z1jQqc27tmBd3ejAc9b nh 65Xl6ONmPH20T04Zpuz1XlsRdza BABjR78GL S5CSdy0Ev86nriAwBaNCNymJrCP5V oqsf70FyJs
kNBGeVm rBJJAFotlwlEh0n4YvVUuZa4i5H 7pXbluaoAjwBzIcQHcncMwrrt0 BroS5NP9b27ev0gH0Ji0n INtfev xCPFjBgOPtVfEDS1gcjBl uOHwe7pA1lrd eIRTxlx0QKanlsJBnB hEJY8zUt3nXZ3
6CM fe5AoCKLpGSwbLbMGHlJPZfnh 6e6Fzvwnddmw3KMP2lizV5Qi88FuQ miukaL8ieVAfrFjXdCNnz6BUcJJnD jiWsMVw ERaElLilr8kwMn9vmizU wpn T0aEz2Ytkf11et9V6FU8qgyG2 DA2gxh74lf6xbVyoHfS5 P2zMHcbah sxICPlDTbE3d
fAatIjvrtKraPS2T nVV MYQOilSI2hzTNW nwscdAXEuqJhHjDe 1uhgvyYeAL8S39xyst 4FIK9 AuY5NQUFDh3w4oZP DjERoL96j98M56elDbxsdT mrQ3dPEjNdXY9zMrzBCPHDTk6O
2j7rjmq1LCSTN0wqR TB Zd9DbmmiDPskAhfXcfxkmYPZJb vh7i7 yFnKaBj4IMquAL3S3HAgqz WCKv9sOk8e2RTaC7w2yS1ZW wcdfpVdGTXsdCZlNapQd TKENWkoYtsbJwYzhUEMe0v5L sZFhz3h3JYUJWzQbje BhKkKXckIV EFhxEzqM1us8Qt5E fOx3yUQGRE4EGuh4Gy3YSxP JdFG27f yk2E9iyplkbnbSD
oGy0ZnlTHrZX7kJ 14OsQgk77EnGm8R10cdksfVvN FEgnCnuobzih3Q5ELNSaBY4L8ZY VASV0GryyKxCBUo D2 z8gLTWSfGZMysKf8PdzQm1NV DoJHSP5SJefNzbTvCS6C mRTT
Xn HDtOrf3IC GKVDBfwmc8p8b e830odV BFoAc1temcU15LEdaqApuuuA5rO OSRf0659A0IxlfI W8eLn4Vl i XdygbeHrCQlsvS O5G0xpqnhIKJHFE7 I3Jul29Ocv0T9Ux2GMLbi 3vjA3W9tdf4HBQ3 GxvnEjXtWe9G0KkxdyT2wdoB5mF0OW lCvJdQzjh0aSp7vXqY
FwqF876oRrq9HX1fZF9ZB6 JwY SZ 5 iE6IEQ7DUTgPr22I9l gDaMwfwERmsDqtCQtOpjSM9pGu 3S1b7Qo0Nku2HQkwLaUiPkupA xPJAOwz6DfP0VUDa WJdb Xss6YDfXIVM6P3c LwEmPQDBI 6jBcf5uWfCnP X3dTrMA5YXor9eczDhHvCS vQ5Djo8bwmkQ sVgaDjW
x8 x8VArbOA2haSFWr vrrLy8GmEEpZFe IYP6ZmYvbbm3rUp0X7YJqo
wUUuDtF2DGqgUF1A61NghMtj XCWLwjq
ZIR tpFJRMJguJHtgGvEY2VE sro gYZkrGtBWgoH
nCHYQy4G zpXklJO894FU46evVdbK8ECUcEo1hM v6dtG t5v9PjcniF 4mL7ozLSNd8Gljj uoB8QE3hDutW0mRrJ 4dGsgfzpzDGZK7xg9vSv2X6WtD 58PjyuA9OUILVvZeNcDRqCgHxrkw PBASE2n6EkOL5I cOUi1hlpXSbC1 SUGwUi7hiyuG 1VXN0yoIEP76kOiQd6LzubNo03pl7 mwfTH5EfTqEiOJ8K8TciW40 EYWqwyXpIg2xe32A0T5UtSVMi2 gHqxUARsLDD3rKNi6R5rtxbj25TLw fEPQIBAK 5oEQiPV CrtNuGqTioH7qHm DXXqatsy8ko
rzxyi1wI Y0OHfzwzTU8d4Vw6SS7tmxzNeBG6Ph 9KShKaAxrd4MXyLGaO2L7 13ggc4JHXPqkotdvA1fSN2vA9vqDM
F OLRvn0TWxGkzyKR QhCpDeSY4A KIRX2TVhMTo6b9QiYGu57NyvLGlCJy R5IvogPu DyCU0kAflO0fkpRa9 cSGy3igdj7 QIbBbcP5ZMVuByxO4SjwVbJ
HpGNL5FLn Msrm5QHfUExkuoLNECkkkjiNKgZ7Vm qU2XIOQfoHAfr8eSxrK00a7 eI0LyJ73QzC1ISO8tzQL7V grksnST3 76fK4m3Yf 3UnNGoULzKunkleEJspxDVr FqRX5VnqxJzre0cmXAHS5mhR6Y6P MN0dylX 7gjOwDsZPDNEkmorU4aM9wZVfn4 FetSVIXoeRzGl4Agub HmRrzNFsVf9d499F9Im6sItN l7
4YBMoG7nDgM CKTOJxhhLXtIb2uQcyg rqmxlaEhZFlyyU soci48pW3tsIVcqCVtak6a30w 22Jx7NLPNRRRDZRSg5av GgOKdnOiCqM6 lwoKCuzpVU8 xPJy6Q6GTiD7GJawDHHPMiJ0t vTBraX2eIuK9GHq 0kDMcrzBhZdjrSOEHPl O7zGNK20 HUN7G6zPIOD2peg6xU7ZaH byoO 9Rn8d5mty1NqG24YfNA7ZDpXZ6lE 1LeHxm6
d50WIle8l7JN RgzGWoblvDXDnEcM lBjdnD TDr4k NcT Jkhuq3HP8Wuo5mdi0n3m0EI7 x76s3idDN Lm4cTTsW
5TjNcZpEX 65yg2IB6s3gN s8K2LAKH1R g2fnzXDVl6 puIPo58MqbkTum8jdSu8XZJ6Dtse YArkkyzIycvXOnzChBcVzgIMkSk6j xaYvB5cqPI zs GoDvISrT24zRPxG32cKPlA0cXw4wdm Q UFBr4dzQs61nwrCKxlbDHn uqunbuge
jsvzu9OC1l2Ms0thEq1RvT 79Ao0mZJ tQ9CcqTZK72WCBs CzUHkASYEs5120sd5K
me9ohaqT Xw3oyBYh52fUgAqzF4zcBRDr x4t8539Cj0ZgYIvKh DaBDxp7vWllDij6gg175bDKPr 4H1f2SV2HlojW0LBN1 YPxigJx2 sTcGaPYh8xhr 8Z7jjibfwAcC 5 C99mWnwh8D0b2ljXUAFPPceP0 LOaqEl5s IE98Dn0VOjGpQ35P fuYYMBS1ARm39occk0zKtzbz
yFq lWt0dvWZ6PrR QnDZr845WxDvJRFWUxufpoXx2fpU cHFELeOZN9qiAGw1 z8DhZsJrYTEQrCqm zL XYZbB m5Q5MghPbyLz70vV39ZX7dvJWb6y 6KmiB0QDGj9p184t hBoUsXwoYWFbNhGWieg PDnH3xH0ROEnaW6R2mO VRBpgpWah4eXt XkUM1ei5 cZ4p4bkA kpL4jxNtSECHYyadVONd1L RRebMOAFbi AKSoHxVbgWsYe7Vd7H GA EDwZ2hVuxAOSxe1VR56
iwuiwb rGqEQSR3X0JchaXl9SA MnbrFyN7KsR8GDzLG2z yduoI9iPfdVDqAOH HDqnQ 6msSHOotmKZM25TTxuA JV97V4DMXY2Wu9cBddBbwt4u 80zI3mRlczqO1aszeB q5Ls8Urexs11K1n2TBXQymWy1nB
1xUH6WCtn1tEqf YTkWSic0F4ZQL953dPJl7 9xCiSM WIZc XI6a5HFTiVLnP4AUniFBp 7puLAOWFBrxUDBsys8uwyAxTv fgYiELlmbw 7DEI 05CSUZ43X0GTb7W
lq5ZYXOT4gth0sSz18F5FOMYQLn sB2RmMUCxJZYAor 95zeF80mfiHrtUYDLyKR8T tFN3wxy0JC3gIWDIGq5 euuJLZgTonjtGsmExLbDXSQ
KrZ9ZhQNa11xSqn8L LuDDg XlHz Rbld5nzItUIfoY JT9bXSEkZJovX69ARCgol wdby9lyzp35DykxKn4xOh8Ww1ad pL7f7B2R5xHGys0doO5rC1n2J 6MnSaav0agoT Fk87GNBJSIG1cQPpUlKYbegR GMrliM2 LMXftSkijsSWCuT3w7M 51vaYsyoRJjQmVkqy0yMZQSWrwuS o69zXODjw JjWUOE8GRYSNRb0EkVmkJHnWJt 7uv 5UonSMux4ByRDCvfbq m99LHf4 COhWwsCg2 fWP9o5gKYza4vlpgtGoou4eMsaXB clmL3UVZtpqJOB7bmX0
y6PuU7xL kmqvDkjyS1FC7DPOw gPQG6MgMZ4NuoB xTHFl6RKVdPfKVI 4q6IVIVX7s nmOnfIRMSRVETqaexnT8mDOLTli CBsYmb4a8ZolYMEP8d8eQ2 SnLfE0lH79H Jh5N GTpDrwU2 qrJZI
Z5eYbNK4mYVGD0n6a WsI40W1sb7q58NjHS12gsMmTG g6ZN3is2KzYNc 09erTdNuyYkLA4LSTnRQbLlZV5
Out #3:
2748
62623
244320
2856
1602
18756
150896
267900
39
156366
8885
37287
64623
194656
50949
75625
48681
125230
45720
103110
116865
8344
2566
6136
253859
14880
37688
124527
144900
23136
79332
10124
96525
203509
54792
45117
23410
258480
63613
14036
In #4:
40
4rGVXNtMJo2XkTv0n9SMIm93mwu 2qtRRaVnyNQOJbKr9EGM tMuYiDbszI0ix1RBT3vvEbe1ZY5G C4Dlb5VHteqlvqXfCDUkJYkcyO g6VBh8KXfyWpqLI9CySv5chFF8GW 4cHgesgW423BGU2RnKYXCOgfnY2N5 9oZgYBIrACwTMRe4ribuy
RivY7bqcCTq2w9cS37mYpy8 VlYcPxNyeRUXFAsEo85b6hMGyc J3Ys6GbNgnp28uI3 8YCktfC6OhUZV 5QM38JPna741qoIZ8oV9syHCofu Swpv8gBQO8Eaj9UFaMyLMY AfwEwYsJLyQ uWZu89K JEq04t El8K5tkZVfoGnMpX248gHz3aoj LZrY5GPBSMgQVHyBRqWT 9604CsdxI qhJs2XDfVm0kwz5Ckl0E7t6u1PQFdq y13rRC 1cxaOwBNDvDqYTg9 DYREjy57l A vXfrIKMA0VuErK
7AlcjIRbuy6NQOHa8M896gajU3C5 vqByj47hftywoxujp6UX2HT I223IXKicubdE9ZWxsStCaWOxL TJbec3QdizX kgTuN7GoLjwRWD2VwMnySgw1mrB Yj 9g9DPn5WkxbZ0Cqf
LqwVB9P7it k80n2Myd JfaiOEVtu5 9Wn4OB W1vQWHWk1F0Pf7xRln9xQYHq 4gt41MPWk8Nn 7mkCq3 Z6H3X8toPs
SH2Xs1ABTA9Mvxf LfVO6Rz kgTJc PWyjtNm6n8PH0ZazRRBLSHQ i1A02zMzEdQl5J9vJ2SkqHoLQO jl77 xjC6kAo Wu9Of6x83gqUnxB919L oKezMUGiNICCzSDCWKV BoNu QhtHWv9uozOJnj4ofhBRrdkEKwbi WCxr3QeKzT2QPJ 6ss68mlgLjKcsoCSaDKWMbyYu AHE7SQkp Gpj5OIVoO3ngvyT6BYn4q6wSw LU7 L6jVZynkjIjesOO1YiRP4v9nC7t9 WHnc3Q4ny7i1d GScDkbmya26 43ZlBt8fqUg17Ih2Z
NXZIbWPSzcqdUI9OrzUMgVgCoAD XOibTWlRTF8gey4ycST6PPGfhUP fAZGq7Co4qqQDnw7wSmQAk4IfF6 79Br4uEEXnnSf3Y yC603IS0XBX3ZQInu1Cgrrdr Wu zuBQfvKM1dakReHGTM
B7ELlVXHQkpyn3fF7FsCDMssOL0xX duu glgyQnsupfnBjVWg2IhF
2my6nViyEOuAL MrEyMWfLtIjSnxefoWzcrEV A5jnDVNV8IJ4dRRVv75UopI6txgSj2 a2DGT1hTiiu8JBrFg692CbJuT 5qmP1of4 XCYaq0Q9d1mMGz6YhoN2 ZfqQwtJR6SHfoySlR5luXd K59LbhwjL1Q3MLOiYNpxm8uT7eA 0f5k5B8i 3yrTA6zgJ3t68PStbNAsBhQO hpFBOmgE7CGG ctbzIECwt2g3yQTSGqjZf YdekztJb4RfkREm8MiZdSpIw0I9 KHCFZDVTsHORm6nMcQyKORKrj3Alc
lG63vIbWSPInN3ZvCwENkZf2e TGTtC9apkMo5JKsKhCizj5zuj6ASb EZJa0rOxYfWedcoqqCve8W6Mro kKQyGF7ja7YWz0DPOlw9CLzv rLWbfXPIqOJXII5 mZeUxQG2IBjIj 613aFSPPnUo4iRrU VdX4ODID1 FGj70U1hsaffjp1q6UVpk8V3Hhkw z0k9JyCorIQ2jjsFR alR7nk L0Z55aTR5kCBwhl G4LbrTqB yi91mu4 3MtZvU
00aBNkWPjty7dLz4VmtY92AeO b4HSCrv oZw9SkPwLOpn9eU mWOu8JRNdReKzbAt bHU0Wa 4ui0x1CSi0xRTRy5srHeWaMupiHx w6mQepdSyLcQwyrvcLkMUtqSo 0L5EVkkf cOoCoLb WDcLL x4dxMjk5MMz8pslwiFxa 5k7dXf8jQha7zhXPBD95zl K5G1 NZxn8ROZG9qOhMJEfLOtArq phvbfYKSxMKUK8QOpJ4IinTTjSIX WR mxh75c4DSmMzbkK52NiwW 8ejRkr0NxNwot4AC1mQ8jH3 RHRBZto51BjZNyb
M6t3NOOOVCRoMNOyNXfst7 mPb1WPu3M3PSPFuyxZmJoT KRByOc 5Z3wZ9KxAYlk likljDpILiNEDrBbjVWOW5n1FzYL Q6P0l3D4MbTyAJNuWfyuC 7S5Cej8l8F7S1qa5Fx0uCL EvX SnPl8VmBNIXnG2XmOWBoSl7Fe B2NYEqXZg pXDQoL2Ch39DhNR94Sx 5lZu3pMsoZINHKGeSdjZbCCxwr3P 5FVvq yxa92
i0nfQqqhqzqYTkRqLtodtqYatwqoaC xQoqww1THFJo1 Fe8STRyIT7vHNBsaEBoCgcx hFMa2WndL3FkuslBwl5cUY1zPu3grR tg LqS4oL6GgXTX16vo0fWXJ98b1J
3UzTIm hqOmIsmDICM kaksji BDjRh
t1tYQYtQv9NGepcGo7gLeMt Kr3KVT4JdPMRg 1PgCemHhgKVEjmy8dvPFtWycd oBXsjmVO QLjRD6XvQSQDn1TGi K9OdGe VDTGK1N3mAkSTO8 5wP2BF1crqx3pIaKrRp2DH 5jZtmdbvZSZZG cvnAd6chMFccivO
un8ajHSnl5sGaoMsUnk WfEbjEkS6ZdXbPfo G4D8EgHZB3zYcQPhHMqjEY26anWn3 f7VM17GsUSjopenn1iiaazZqNEVe3 qLj8XYlvNJndYlQCFyGz3NcN 2E8sO2QSk0VTPUyLlANJvN Fj8FOa pvvS7W9w t3T bxAGa to8
S9pKnhyl 3 Oy88HEnr8QbfyJj3JYRpuwzswzV8 CVLRLzFw99i5SA9S1Q1CNPnT1q ZKIqnxDIDWCYx70YbzVBTxITebZ0Ip NUrs SBOpzEbApQsKTWy4qcAe32fSKfSv
wm53m CHE8QRhsB5AEMCR4etoXXa nopbCoV1GXDCcwQ1QHbLQojJ5eoRV
iDde1a0D DpfgQijK0meCom8U2 ZShpeQaTI1Zhfk21cQbZCPuHQw Qn1VTlFico4 31ocAsMdnIkBmfbBNKWeZOY 4EUtY8BjqdlSBncW3sK WUiHwU axEH JcQzUF16gFgFGwx10hSQD2Q2eATbt ocE1vtTzem8ypgEb TC0yFnZRVVpF3juhAxA0oD3OjO AlUb7o Pou9GWd8UWa9IXCjQJ4D6YwtDF Qet3XU2SrYJ2uNiZpF lMz7rW8csuJ55yhQTL6uXzMlZ fppu37evsLoMSz
vQtQaJd1ZdNqUExQk5geqMVAj5GV 1V G85sEXP2pn
5jdGs4dmMAesI5AXSx01A o19wU81IfNq0QKKxyCPS1X2xHx9vz 37UoGeOOAMDGK2ZJF s5y5S5yh8fEW lVhgmR2twjd E5J9Dh9CEfDhWAP xz3Cu1lFqjcsw LhK303JkllFloKZ5 6TC4ym 8k Mo sKPlLsr60hQdlmla
oTqVAazbb4lhIdVlCZbnvcZX CrRdrVVCqgbamw0Rm ZdBr2i8 thYLCoHxaZbJpGABMwr9GdRwuq2t
K28NH2YeNUb4Y1 oAbEl1Akd2Tdx Kg Rl zjj WyF HBAlTV8xpuOC 3SVoDBc4z 3EUGqVe6MMsLqfxKewoYvYgO6X0b7 XNXUVTmguEhMnbASLR3Ed d4Ed7yZVSx8iqFba1EkmfmqvYI wfXtcUGJG9tXK89Ubgo2fvNXk1e9sm FM6g104P FOW1ynZLuTVEMuT3dcN8
SpDjM6vdi OxcT1EefWgTVBaB rm6xq
8Fp0ol9neAjucilwlWcQ RDUxDHL7uTZK1MriZBSaE ZGPkQCEfhPTxN Fb9DnzfBwQ5cx74n uWmB 27JWLQ7ob duxiRCB o9Td3zbIL JxcsxWVK0mkcGatx6nAQWb7ZyEF YT7aEBPcXfCh2ElvwL NitIcYQkr 66QNbuv7tzaJowPflnX3ihdFzIteNN C7HS 3P7mkeYn7BWt5nxVUwgOddEHO0bXU Q98HslphdDJBj25ONJsGX hqJY96ajpNCQSa3NahAR1aXakHmx dScDp0TS Iz56eA6U2DlJb4LvT4E dGKmzkH RhUY6YPbeAVd5W
8o F8P97 DqBTqjeHSPTb p5T grkEY7fHPb kNqPBia JsGkD5S jXVVihIxkLeH90mSiSo vJfRb7hkSLdzwasTV00dQUDxgIYSF XHWmZvzohz32kSSBWOTrTx7jxHI 2Gf4oD7NiddcSyUe L 4yATeKHFwjNW K
Rr0RYJnzA 6C s1BsofIeuwF1hiEpcxDzXm AmiuVA4CYYomNz
ZrMyLvbJyqu
xzKGcXvFdT0KvGoQa96TIv7qn OlVDAgKVI9qV9exn7 oi914oxJ1Zd d1L7qzhd I AMJ38eGqfzsEL9JTFx2qtzlll3c z ktI3ApKDdEVTMynxcawY8M2 hmpxK auDdzo1WvnIj FNZ9Di5YCL7 nZnFivrUae SxpEK8qPfMz019J01mWX3 dBiu2Q 7VonWWxlkwkKt
bbzwx83ipagr U6J1PQK6RzUwXZXi3tIAOVp3r 3V658SDP4LePapguKIPWSIFo bjx05NDq1Tq5 iOPyBCC4pSUlVuo8Bx28KP1 vz86HS8PDxYOpP9VFraqoNETEt Ak ZFhkypxnmr QWEpBoXN5 Za5MQnVaMMjn8O 98dN0eGUNsFQ8GJG1 6E
jWxfL4ljxw2cRXU zqpuFL22ndA12qUWob FcPMeWLNGT60wT9G lUZQMKuQ TOiPbXIEXoNi4zg3yCHayOcqpr b5SVd0vX3GcM fC9B2hV7IimkmnfIrfvdy L4AlArRRAs6SM1nAA4VYlDhU0H1 KHdN1YjeriyWqcyCYS67 YbPRVIxeFjBAyLHP0ZG7 A6jPpEjSOkKqi8tFE8 BToS dxEbhLpk0vpAmXxw4N Y 9pw4bNwzeiidIHOVjB3whMcoJ YLae4LKKo0O0L9iejOiNDP un8YNH9jjJEM3Q uMIyO3OBP4IDJlS20 xaJ3x
Bq S3oprdxKdN5MkWwBH4Ca8REgg A1j
hbdxtG8 x9mg99mRl4wuABiMxwjuV8Qc6TBy LWc0XenqMe 8Hk0eD2yCzKV4y1 eaCwiAWzyffGjSy49 3oV J2Dcu2MdDdvCGGTMRb 4yUJHAQFimQucGd61IgZHz t8a2buZ1y VM1soHHLyYzilSHn1B0M5g5EtY PnnOZ0PP9y AmUs fpSKKJ8ooYRm5vz2MiB3itjc9ItX8
lK0Dm 3g01Ln4IF0LluCe1fzqsadAF6efohV f3soSAwodFrioonCjzpq7fWhXh p8paILvYe5bbh 5T3dhP2qZLH2eqK1FSfv183QJNOe roT4WJufeHVVIrtNDtyWNJi
bC3n
3nChSnyPMifi490nmlEXWwuu6 zZuiwB4NWg 6Sy8ZiX9tiEDNFFKQPC 6A
FjPCWv hON SmuRgyZCzsCs V1NKUcRzxrXMbRg3x VPJHrMsdBHV3C3tOTxuYW lhhrMIY v7NxN5CMV sc99nqk wnKcNJksv8y0tmNj1ep2iM0 Ec4H7BlDoSHERAiuPBlcZCu28 qUIOdFi5uQ9xSpWrD3W4qlhS1LF WmOBuI35cMGKsNdLm fDOSTIPl5oMwwLXil0cKp KFlU6pHVAkSQKj4E8toJjxCnJ gFEa0k26K7KeYON3 nOg3uVifAAXV 67 A0oUGZJdJFxe sZIKzaXoAOtT0w5FKwxZRruw4
rlxwS4zx9lzayrkJWizad90Q1b wxFqjJav16GQUm EFxWEFhhWvJQBoEz0HnBe f WnJT2q JQaQ40EZPz9mgA nJOHiQpwU TewIZza9RO2TCh2 jtFouKzdkqn1Nl6fWL
bbYk7Rb0J 6n2 eln2ZBSzjumXLp ac9WIdPN 8302 a 4N9IeK7F7JEJ0aYXqn OqADMvNC1LcaDCauQgPnXL O1cmJ9S ta2qpfq2PNiFsC4WHgW8wqiN9rzDI 8xA2jwLn0N0YBXLmiuVmHOp G0b9AKs
5z8tyuDjukHeBpE4ZJ464 CJxD66hHjGrzcZxOT8 F1v8pSd2cXjiptEFt6qg3pgGFucOP B1zod1eDIaQKOj3i24Ob7MyJNCMHeW G 7AT6fqyY5Cb1phS
nJbBB1sRCIMYaBcXz8O A3a7tuy3jkRs5ehnqmBC2zg6oZ vW1AGlOTVO8NB8gnA 8fMFcFpAx5E0 fM84z7 iksq1qjver B 7PLazytfWH uaEWwD0Ekzs NKAhGH2g04fx2exN5seCsOxW B0h0XbebBFszX1js9521sbaZ
Out #4:
55132
208872
37387
26032
242220
42945
6273
168000
146505
227867
138208
30432
3372
61550
72512
39718
7140
175264
5094
72480
11472
109802
2799
248080
83986
6904
379
107310
88500
234707
3399
100711
29124
86
9232
224067
41949
67584
27564
64460
In #5:
40
BgdPv3id0wHc
6A8YVWKygL91V q2axoq2NSOOAVS yERSpiI z 0UZVgrUVXXYx JUU6T90FutAskgCZOmQ 5RduEn8DN5vGHiwvG3229fYvuPnZRP ZSp49aKYMGjrFD4mWQ52PRsElI8fK eBKDA9Gwm4y4KoaqbA88
GE45DFWT9G4uADKnTFzfStXBWqPiP7 q3VbypIlhf3IwGNJlFXeTF7uF GdB9mhS u1IGAAV jJzuLZ94iHvnVBOrCh0epvJSknl g4Yz8nZ5Gj4 lokhy7CHl0sigoBGZ6i2PaMcUtSc cMiIWygjiAf rJBRqV2TOG7xIdYrjM6c3f4ppc57h
ff0SEOrjFn3Sdu7YcQBqF UwC38JNG19BmHoPE Oyo3HvwN MTdwDymy SAi8eunZupWjPB pN2XiJnDrVQ3rncyt4fEVpgGpmY yRqf3M2q05m1 bShYhcEqCmN9YL2c0lbdiNwKEK8e ElGk397KrQit5l06ii kFY pXjsJ2dH1hKiJjzPGT IwFQjYu 9RFIEBDDEiIzCHwCZWEpp7xkoX DoRBJYlBwvkeDb084kEi9 MLIWsOrE
IWncbCsJXCcMmXkC yjz MjW6Y7r8xgcNviIU0t9FhwZcME jekovv7CjHwbVu 9Eer2wSALq JQ3yIvVOlPP8cJCnasI5jtsP3SiW
O0
UB8A3WNPYxl 03mtSH7NsK1FzyPMqvtyJ u O4lMQ9uIR3Ww S7htQbpn8O129t aJsbEcyUy8 vlNdI2MippcAaQ 2 mPpDf6JwvRjApyvl2nzDZ4zz 8rfFHm fRnfhbV0uh3N61n3r5 hCQ4ZYn0Rlm7fBV uUzXwKfAtJF30
6CR2MsW0FLTQGzaJ66MLolDW Gz9XUmcutRmz96NjsXwLwBn kJ06Q0ecK pX SAeArOQPvy2Qmj1d7NQNwIn26pmXB bEi8O2LyI8WaCMnaPLs Q8UdeMfAdt6fidgUy2K1lI1IW nXLdSHJaGD5tEGfs5C0 WsjY27tmMuj6aZ DVNcthy6oLh6LiWhPd NNOxjgHUuUSCVEPC1V ARjDEWi8bKeELbQlHc53B9mKiJ2Ui E2 En7LgIBXONnmaxi3LVtZDO 9 Vh
QWIigsQMpse3TY4eS7VAXx K2Urb3r7r01bm8hbnUBkqTuJO XNr39rXrgndeVFMS7FPS 980Uu7D6DRVvD fMiUc2GwZeac s8qRAfu86ZpXPiCAdP mnLP3T gVbncavhUDUTnsar5YYJfHPl5P4m 6Ks5ksPV8sGndVf OKNHc7dBfCMwou4w5PJu IyH7zQyZ8ed5x1CbqSSMjpi K0DVTliWi6QreVeGynH fGfv1wY2EgICiZSOgcK0PGryPt Pu3MawEghVsd4SHhUyDVmKT8D0LZap 6W3o1 AzVtCD9024Dm7eirYxfft
s 6urBgqoN76MANh4l6 X7 Xs58LjtsTSERrM9KH 9shD w006hlxPzbePjyteSmWLNJLdHjqZ WSJrpAugrn5GX3fIxAa2vBXg4Af kmI5RkHEvXMPksqqUQyCF5 q2XAV1aNSqcgcaNAPXJQBYNe20weeC dbwDPhT GNiGNNnW67R7kNHdyAi4Wem byWNEYB5qFHo5W U6BNrapzpRWgNS2YKlLzG8YG4 tR97MDgODzdHAPMEEIyTCIi8EoEua NVGDHvgKkT8P3VsORRyXP2hyD
YhtPWFnH8l7iX2rvEoneLzlAzu9b Ul9jtKVZx1Qc HrCET1P3QXe7wbOY tD5pzYzb8BjV1f beM0kN Yz1pa4x6pO7zHJI4FjoTNfn9X8AEK 1 lP XTFj7qfrf OA3lRHUKMrZNfzHvHQR8REm78YTq U7lOMNkEmlXK9iFsx61Fzr2cFCp oxpsKAAuQgT7s 5 56txzpQz5ep3vCVrKZN QbaamKwi9agctGwounZ0QR1jZ jDFmSWY1rlhEajccszWDyfCT6i
3J4H7Li H7ReXvmlme3qAHKxRu3Sj u95rNOCV8Qnnrc 8QcZShS55gSPDdV60EjlCK xgikR7OAv B6y5r6lkGzzyYdyiJ0ubJxBUoMr9 ZxDYe AGbAXJo7bVExddOPVuyoqZl V4BaKQyqdP83dn5VQmORPu9z rNE769NUEWFpz2k5S0QIib YnaXA1j82bDbg9mOMXiTK W4lP10gKTN07ORw6IUPXYeg3ioQ7X 8NdCYJuneVN4WI0Q XcnnAmeeP9c VzWNxF6RlGYP9qzBWCxM
Zmh0MV0qBczCZc 0LnMgPyyJGp N2Y UpWb2z9gGiEcUNyxwIa1qQjEFRQ29e Rh8t3PGFnH4EsKN4Eq5evBW pDaCxQIusVTz rkb5RtY8HEMtmyF d8sr9ORt1OqMVq 05x3I2LssdGVXc4OTK6BCz0bv39 Op QVwer3p9xfhuV5AJuPhZqWbku kqnseHUQ3 uBX0YqY8xW DpQEVC LdJltB2NKVvSRsP5 MpK8hOoO4oVmZcxJlniGAu4P4fo9q
QZhuOAeo0ICccpxSpe bm6TJzwABKfAKdIul7YkJFT Sah6hmyGAxnpXAYUuV1BzpeL0adx NTBNhTWKhZPSyGsd9d8 bjTs W0M7vvFE5VyoB9jR5fgliaeqszU KAlxNEuBBfESmQmLCAQaCBl Lvo6eM14NmNmSHlN33qUO UH3rPuTOubXShvdWt9Pzqt888Wkq HLQ3q96FMdybH1skD3Q QnPsPzya8r70r3cJifz9CZweei qpGv8e8Jr Eo6yakaCad4BkewFgmO127Jsuuvhb 4eD76KY1r4gMGJY5UTlJepjK QKqiW2Kqwy8ZGh5V1 0w1g 0emJ6ylhpKM
zzoDRn2GfEnf9a5 SUiJ0uPJMPz q4f8BX5bszrZrG9NbnqZwdr4dMJV oC2F2z711O9FR Hc244ksGhoXsexVGEiwGR3 YLdYGl4g XPEYdc3 cNvPWwHxslv27xrfI2doduySS8 B03eK1VV0wRyIOSX4IAF aqwch8gy lOcsLEmBIsgpgMkHh chV7
f pRaffcdaMbdX3vpYOem5iIDPn
D9MtvaQYU7KNnAFYXHEOEcn bowWIu00PkJMwH6K0x1 tfzaK5N3ZtTPk3sJ1Tr
SGhsD8jhGKXPJ9DcNjsl2u5 w6WMVkBAm4pFZbrfuW1gc nqXl05BvZaPaZQqUlitS45 KL Mv4ZlzUKueWOjKAkzCflbLwv1Abl p02CsH 5JRasRsH2rhxuYO YaNLxXXGK95Xhr1IfoJgrIr uz1SpSBTl1hZg9bbjyBj4Q9wK07v1 3VsVW f7YPMcLrqddR0tVvTxuZ5 speHOxbOg3zmBh9ikZzIvR38cETlb gqYh0Lw5zSeU5FneInc h13F2YDLOk77Fj 4XByUdYxpKsOVy DflyIWR9LyHToEftoEZHB3bTCczQ
njtIeQH2pSom0lfPXSP9 lCztOvu9Z9 roMRreTmFi5GzMBW5M8 2lR8BUlQNr8kYw0k3B5ZpYvAv9mv G6mwWwOzaMss4E3ZpvBiCxEGzBg mhLV0 eUZFzFvC0GWKYBrt1Y3rNtSix X6B5tKgms1d3FBRPD2rSy1qDFBr TqqPnr3PMB1xR HRzzgBnR7rf3UDq9leW s7JM mpiwPHfNLZu wuBdQIzU ntK7YuhPcYEyIo 5B6 XgeHd do2Essod6RWoaOqtrZpZPGvesJ1L kV P4zWu
LbBL3gPXWacb1YpAFy1AQC 0MgeHxGnoB8dJBsX uLvm2lEceychpq tp7FIm449voZ D77ZUfB7rn IuEkwKf5wcXXb NZAspsyxTbROVRXT8cmfZpQECLcCEI
bZ0b4f1mIZiI5v6jhhjgEkTjN5 RcAsdePfLKtAAZIANFanQ0cx8 vhFPJieuqr5CUV2jG6mefXSe b0DWvzYDzdr
j XrMGPO8QxXcqiYh9E qRszyHao JRzd8CeQcnbMCIpJvZFTk A98mZi6T 67Y 6BXhe0HjXryotJyjD9lYHqv6pfmXb 3d2hDsYYoKKiAi1E94F1SZ99m eWGyxZ 1dCNsy9SOkHjDVGWNl3QdMXN p80o5dScULBg Rds7iXIfCC2 VOoXbQLl od8A0e8igKPdnNedX04T fUnW7S0GRB24b
6tq9flHL eEkOmPuNN6FNbWlBDaTJhN ssPU9umnpr0RwpuKH1yw B2NWrOJQ4HwQKXaPIYyWcl2adtGP8 mQyx9v7cxF1inhRA nRjlogzZ2CESf336Zn3mJSGG UivsxH UB sRfzaud060sGmuv k MIHBxxE0sxQA30Nxp wQq1uWMhu 9MuNXYSb ZDLN1 AEUDM9pZx8z5vPu7D6ixgdUHw vQvRgUqg9Rtm3OoEHfE8 Y1H6S2GbSv2TIkU4AyrEt0hVlmhQd fkjPXh2gZzljhwhLde9B71tqe 8Tlz0vyLN94b02LHxtHamdkgGcWd qTVbBAebv1ODuk
7gj8YZaahTkGRVYTvYxCKj obzqolxRnex5D87x5p7XTNH2C6Sv eYkuUx1 QHlxGokmqo0Ye pLeiFrjVK2z5pZyNZdqxuUolC fC026h7NeIapQ pEVFesgc ucT Gbx GKkjnU5eRgfeoF8X4k C7BWztzvilUwCpaN9I 4dR3oRYV3yuSFGxsQ1K 6Dvy xScDMyF2ywhNHe o T6dPnXUjKYtTNNjJH YMIMPzcoDrJW6dSZp0PVjdwiEtUkd
4BgjgbhC XMX6b9jQoCIf2IJRy4aKOQCAwcEDsd
sTB1aTfI6PrMssvDH kVFNeE89xph SsLjCc6OLU0tQypEXURE2dpJGL3 cIyDqCJNQBuiMePtBQHuV 2xB4P2HbHLZ4 LILKWyUpnUZSZd1h1nvZ0s au9iK Hg92JIVrD8bLD kjknBsVPGvF4T4d kn3zj2GLgiFlJqP3GsbCqs NLPGSdgw1g 1MUZHtnejqnjXizrJNqJ4RYJ 6ZB3nQJvXt00P724To3tMqiU lGtXVl5iDyq3PPN4pAMacMk6
G Ba2
ffiZSRytPl5D8GxiSf1Z 3Mlvodg2axfFlVwA4sHrExsTQN vOhfaZeNKhI0szbLt p4qXWXb70Y FzRJmjBoh3NsL0PyPwyqJRB20e
ThIPJFwpgxnd BHcVk8lpM dCOpZThbGND0KwK1R8S KnKvyAI Z Gq6MiSm PaCIsGw3V2r2YRfeVhI2IarJ tqLs6oZ4Grl0QuG8YFZZgaFZ0 t4fylO2JR7yY1SPyS1orS 3fseyZk94pBCgZF4pqwyYtKD1kS
oAYIRTyHI9MHOuarR9Fvkv 7TXflwn r45RyNq6VCOruuBYs c9SFyHxyG0dthx423CyWYMLqYj xzuNz2 L5344Nl9MA1lBsUetyTWvgegout bfV8ONDDcGiOvYWS49ap 9dHSLyEEu3hbcw5T0l4j5Ig4a91DJQ G XL
LL1wa Qs8 ad29eNLP0eqFifAC ePNBaZEafsKJOHtZ3Ks00n34 5BO z1Nt81Nk324T5YW8Hm JA oYE9FADBeERJoyBmEUTWd64wPn6h 2H4mFY3Q Va FcYxnJCq7afBdYSaXbaphcEYi 9xonMyM4cCWvrDjCX 8Nti7w57Stn APqRZF1 IATIy14 kIUb5U8KBfoOllyekN60SQ ypGk7 omBD4yoBjdMCWmOCI 4Vl5Oxejy
tlI1F1 jiJdoDSAah0aGcMf OmXmOHoNvVCZs0wpeR q4MvKizDTzi8kXLvYH kAGo41HhgMoJOBJ6tAbmP9SHA jVlba9anXwAEP6AEOl 3i98lVDpj0 ZGzmF0 Q 3S6d93JXUrc7IwF1
OLrhhvSAZS91HjcTuqcF369D3LLV esT1X9nF0rcnYeCiGKPzGGJU 5LZIXAWX4qxS8Khp1zku9zHL
E0e57ttLJMzHGlknXQUVNXyTCTMt 0gZ1MQw91wwOWutHvu M3zAERJkhtL02 0Wrmr1AZgoeb2UVoR h9u3rk3luQ1VXe7RMoNBeZV0c D RQ2dtZZo0K 5QhA ZtLLiIryJ2Sull z171RUKQzrGdw8lTPO0A2Jxy5Rn8l cWlp9O eZapvCAQDKEbdObnld8bxfh6SfQk5 T0ei 8olXMO7Z93SRui5mkiUCtqwcXf6DO BIcWOKf0OXeiHVPOODngT1 lZW5ycXgH
YRbLwU5xmPcYqf16KAckqzUtuf59 5dNlJb9ii4bkyTrrSSX qktl9ysvnKJ690bBHdeMy ceLQ31mUeuQ8zsdbc2BZQ knICJyp 6iNz7rqhmZhCN153r 13OuvQ10 D9af R4v3t4pwOHBjwykRHOLZJs5KRwlzhW gW90pxeLt8bm sB4 deQUunxFg8ymOkr eH9ig9PZ7HR xr1DK0
lRiWZGjusLy4ul115xzspxV
3 5udyOwi9fSeCyyBPLBajY1bBxCk8YN dE1QbyNvijTi6Y35Rje7BOYwSrN oLnoOVlLZpf47KZqbxj85bNE Vfqi wRAKZODRMrAdLSHQfMCn81Vi t5 Q a8FfVgb1OdGe0DXZIm7axH qBmMUh4bCwtcw4k5ksMEXB3 xiZuwK3
UrnLU4GhDHNS O4pzSzazhhXU9AfP7 7IOtm390W2 yR6ZuNV9DS08mU62mv41jvNDfkn QNlMzR5uFnvXG7UonE 6DBE7f9s4UT HtwUBx9EWaYx21s2gz6Rbo AX4REpnXwYACU7WHm1 OKZqGCvIpSRZXPxEF tlbBR61VkVzGn2xiM7HJ1GSH5Mug YteOtDshs2jVMBKhBg59N8uERt ixihpdpYPiPScyVH 8dg rMXuRCydJ3ps03yF5KcAKn3ev 07e8wXPlXLym73iRQY1ptzYI YmPijfVHQlAEY66nX3Syw1kMHoMnj 5YHdhZWHzOtzUZrNkp
S1 OFrlaMgv7UpoOISVRbdgvyE l9PT lMzGdSXMzjzbZR uEZ6RJ6HYeveUC8HNGyX6usjbwjj2 I qeFdwhXiQ9YYcF6jLny7GLh KjKIPWwgmM3jeCqVHbU7j4sHXf
OPPOMeXf7yB Zh7kuFdBIRfD9JFgLuU aG DqQ3RAUqtFC 8O24Ma6xy91GQ6t LswYspHDF2 2kajjIBzwP4ULdjtLA9k6MfNSZ6F NKo6prP3BWBSOTz1qlaN fqvLxDRyNbGwP LwOXhrp8YPMhEdjfpxVcfl9 B5AeGw0tn9QnaB5gdHYfJyuMI2 ABoefGaxIMhXolWLN0W4Hv72Z4 8 fIjlWNtRTQ6 WEpWyY4cJL ugW9MPQfBMMCoTWp28Uj0
Out #5:
325
57843
64908
138825
22866
86
77012
171680
197152
176325
166576
171465
161472
222700
81912
1748
7932
195504
211584
31892
13288
123150
256440
161177
3116
142296
218
19710
62670
65920
169575
51230
10398
173712
104566
907
74679
232798
40728
162720
In #6:
40
KkEUwhqa6AX3ZBI23P Eoq9SSD7ivlU T7btZ2MAsJwLiLPQ6qHvMwWf Yljwkj64 CQE1MZCc sGHVxCuZ gTPmPlKdQ 3eZV9vnuSGEEn2t NQnrRvWJ0vO cGu9CbN3myri doqIiwZ1E5y kDQCA1qRKfIGsfNrAh hHukglxBF1Unk1ecbO33L RA7G36OTlnlGF0mBHnztl3 Kd8o8SnhrQ9Aqm NIb6WkwOdZ
Yt7k9AG28 EprXAG 5z yiQkcWMdkHbdQvCg3Jt6J6o4UM kSZVjQzM 00WyDx1ld5txrsS vQf5MEHtS2e r5K7qb5py3VEo6gbpbMSHHwVc ZKqbTzYvk9 7 xATE4iTC92YRF
yB74WKWjYTYbyPi pMDVy9U w4gZuxaEOxNa1iTIvDM2oRo 98lH1KLjOmcZsKIV75 k ji7PiVmPu0urZewC2NiwNf1gC MDKXoE9761b Ou
bU1rBZjwEqdbOjGXT PJC9AOdkn9MgwbrCNtTAznGCvGN niuMnLwbJvcT0hZGo dWO k4PmKHlh4V2jUE4Ip4f 7WxGgfOoeRnUX8pqN5oHMBU 73eXz90ZHT VfqBagswVBbp
Cv3wRQyin Wn7jJHfAfdr91umWPdfEimjqY snmmQQIYVoIO7ghZglIC2Jc873f3
kvFTv2j2mL45 LJTyrm1HedSVwY05e8DtbLC ODgDcrGJzCxg69f geDXqTnZzGVsV9r9m01bZ4 LNc3DGELI4u2cN8jG z INk23 PmSCoyrssstvh hTKFnlCmQj94fvM8VJPi0tx27II8 4rshCHZeYm539 nKrGS9BAUxGCBowbHY7wI6e0 1eWSvAntE2cZcfSSHrVsaIQKll zNwxYfhAz7amF5Al oFxdpXmQyvGJsh
y6g2qF KB BSpNKaVMwYPGc0vPnv5Cc1Y4g DYf7N6xxHF43Yl7 39fGSKDkYuGXW6rFoYZu 5KF2eofdBP65aW0eagjEXsZ SDy GdDQJwu5QxftjM8 UNSvIng5e8tXIU9 2TsVhD1ghW2365hfurfuHddM QP3BPSn0qjwDtNW6ZBPN6 kX4dJfCa1aqSuzn6MOA DyW7KXr2nl4Q5zWnow 3d7ZJvfwGcgzaIMEPvs CweiGCxTG2 Y0vUIYHKI jLHESbMiNX1h5pcQrTuK 4JBiabnorDy iEo7JbOzfjpD5o7w54 tSk
CCR UfdOH F XMo9 ICCFUKybnty6e6f vUA3Yd YI7gJBSCFJ4gGGIAaZBFYXOgwYy Nosr azpN4bih2jK60 szQKY1Gude397B U8RSqjZPxxBvvNOI3JNga Hs687IAYdExWFEWSYphWYs2NNRR JUpBYo4MuCyEQlw yHUPAhhBylEBa0J
LWBEqR6C2xU YZv0Mlc idDc0ayHyzRuUBZ 4C5cm8bwDid2 7bMdkCy11OsDAjEhALVu7yF8Kaovb xVwVJnefFWBLAUZEdc3iUI EFQZsHAlgkl0
fTq97lwK8wTWtKNQKglbWvWXx62w7w JGfbd WR tVC7sqP1KZ73RDzkYMx7nVQDUG7HBs i 0hnDvZ mBFJLayXP7 gkn7t8oC21UaR 4SKy4Tq q0LjvScK9frOBjW1Vby4MLNSmo1 sqdCvzTw2a CbkvKsmn1 r8NhbsI1 DHQOV4qQ ymRJEy7y8tfXfLdAiSDgE24zNC0cm CXB0If xXWXNYRHAB VrOoM lP xRxKgiZUn20Trt6D3l3E
FRx87 2hsfNYI4EqM3J
TfGqezXBvM0vXao K8T gsg8QWn51Jh uxafv b1mqud 5n0R4ZDjWmESlEx9eK9a4pmJ5V 32JwyPXIuAJleA 5vrqU0z3efCN1I8I7kUvSgvg36UBb byNL3JpLZOe49FNRXRaN 5qexbeGdkL61HjhU1KjDtSa lB 9uZ 9TMVHQPuUpvmjmk2STM A4eNg83dXVPf J4Xa58dYME3VwK VrSD9UZhd35Zu11RA6Egwji zxi6fC9uDanvsgB 4c2425oLxQnxzfFOjjGsiAs 6OxJ9s2sxtOWcTGVcjGie3j gbbzXfrsvL4y2wL1f8NbyD
n43Zbr5H0khzMX6MTq7hhqrc K80QYfP MeZHQ 02CfLBJCBxEQRutKCdqIxl62DfS RLMrhYvX9msgJwWIVzDT1HOOuj6 po2yUR2uaJzgKDcHW8t MG8VLyXj8GTaXvr ta2MV6Rp4SNyItZn E HTVtHBGTIhd jy 8LscPN 1ZF7qcjX bf0u160LMgWGZqdcbxkL2r Al2S2f1GLV1IBKdQWrDhB6DDcqAX9t EGeIB8o67bfrkSTeWc8Gu52bt6 GSYZYKyXRNeCN3
HWSYG13ihprVuKJe u zqOltlQvjxtHzh5IgHsOWii
4eNRqtZglO0pfAjlnnZnr C l q5 kWwGCDgYNx PBxpBsjtPfQQKcimzI0Q5H4 PQcOt AJnM1rCCRySC7ZChJj OLjhfO7aTQViBBIr NUIagv6BKh dNeYVGCL009M3GYpR4 CVADML1nStA5dGxHA5u1JvAhOF Wc8ZRGCZJvsTZSRlVeIEr0q 9BDXJ9Xl2iKAUD5GuyQ2O26u yum99kBBH
5N Mm3AYjEccilCe BhhvX2DBtQ HC8hD6SvAx7fc X5sSLI295DDWHd5qY DQDTTwUX34gQfy2NJXCV5 qTBpws KVc5ETBhAr81fd2L BB x3tqbHHWI IGWMHLG0CRR0n0l0GnCg72M8cn5D 5JM9L WyRN nNj
TE0cgLLHmk3AN8Yvw6 SQR2TmahdULfRtrBD7TC10 xCIRajYh 30A2oNETfAUEdir Qwk62A3DUZ4ttabHu4eoMxfoMt5za gB51x0VdK 1ApDNL PQojpV7sxc7rnj3wLtbZRe OJibz7oPNfX851FvTttBgfGPD4L FRvI0Ev8Lgm jWWUhh55aHi7X9Pp4bcDr91o59lw OD7p01h9B0pw P9X7l5eBQJd3DCBLc45wyYVT Ecr37yIXPmeqyFYU 6UJWgkULMkneqiEvNkl h5BR lPtaFMnsYAp2khoh7g f1Q6tdsKtwOaDxZD21yl
e4 aA3voNBi47TusAaRHNkULrke5QRn uumLbqvBYN4YnTuQxvV RXx pHUsHXKo0JRYvdINmc1pxmq qZ155D1izlo Q31Z OM3gbiesjBVwnb3fUALQ1BwGvQ 7fHAFNlRE9ggr7XK7Lcd2t2J Jq9Fn2pI 4goR4FSORuzdGNffd76eARr0OslQ XM KuXv9KC hChcMN nzSS3E7P6HRfsqeMY
hdmdJIn3pq3HLmezAogPbocUyxxVkx veJ3rFwV3E53PxvqVybQxKxERkLnKB xAgrOWW2AQ5cdTH DGJu4QbnboUNvm5Elty dFzvUDB2JaUWzt qoCQr5qAcfMRa 8IpyL5ti7lt40UANFwXF1IbkP21Etu d1DEA Jb80Dj8Zqn7kvd7 3GaIbVaK7zqB vanCMKLufMKHKHGDatf1g 1iRQDw4xb54zWL1jeLYcj313kh pkBdBwaB6ZdwGBTtrX9ZeKa
Zq6VfBr6z0VBN6IPBSXfc4A NLF2oJ8SY mMP5vhEqSvkWToFwsUc9Ak3FV gJQqvFC4AOZSzi Svkv70gYfHqh5C9pB4 AtYdzucxFRZV7eSmkxpAHZXPIlcKlt JBR95lV0LPuV3c2sbA1 PZZqJCvDMqkdN03nUCgjDkO OfVw7J5tmhcSJFsZbFbux 5bzrjO5nDGxJWv8wuWLnLFCynq KFwLuVMjghpmtf68hNbrkj5N PqcmZ xdKoWGpOzFBcibsTvAZlToW3eEw 26Gs9L7sU9BmQSDf6e2 SRkepsChdQgUx1gRDLPAwTJyH WYc59FXi Fs9jzHJQv UwLOAvVB3XnkTX5KnlpUPZFeO8 C8NchIeGIQYWMC1igQaBi 7t8BwKJViYRw6W
6vKvwL8nigxtqqQfTh6lg40qlYj0OZ TplwmarvjqMbkuZCNMiAOg 2ikuxPJ lsBnymvAOJKTrfUp K7pQedBp2bgQ8wZ 6 qyDkwfICA8oJ8NESybYEiO0Y1 Vm0OUNWBJJDKngz MesSnIMEI03K2RQ3qK mGIgyx7N5pl C6wHGag3nhfN93Ou1cC2YTHYevL1 yRdmf7aNcFEJdiINQng0gxtvKzG5
y6zIbxEOauKEOO9tid73DHTLYOltiN QcyL43tIbWugdv4fa TcR XTuYoo6GHl rojoZ3cJh9wkODC1qId Hlv49bB6lqsZydSviW CoFVmuVzifjQ4B4C2EV JdcuIqpucyGnZ8hmI253nJmf1ts ajYYCxHufA0mdXWLYnMirEK1CEGT srigQbh1UpySEk3Z4Jhu7zMrI20gQ U IhkbVWDnf8C 6e1NpFiy0jHiwjFaa BDyPWVhMRxp9v8TL3HvYMTAPo7OO 1h6gbAirle tJlXR75m7
vSqlwq6fKUYAhETZ9jOLuTU1Ko9 Z xPH1e0ZCb NTIMgoKC52blODZftkBNedXYE nSUSGwV737bIA bKkhzNlwyokeOBJ5QX1RrNwJIzXDQ PzL76NNSlC7wr5ah Uv0i8W0mr96EWUNNma1p rXJClelShcBFXlg ELPHEzUQvsu8Jmw3iarLuX Y38j8lN7dbtbZITCImpOWEkr3jZ0
SZxsDggB1Kf18 AzEC3TENevKmHYky48YXAfMq U pm2q K5cy8ldSARIkUVv7S0iSjCGYayQ6T Kotq4XlXSmFTrD22bHFY0ZeHsDW yZSXUe5jCWsWJxpAAVZ05Xk MJ3mWGf SilXaN1gH8A8KZvr7BDBjnsUYa PLyrGkerKFnzixkF 3O5ThG8dScB77WB hUg7JPEcDn pqhdHW0DYKYbS uZ2t kL mp8fJYxZH7fX4a B88o0X 07QbS7MZx2BEg1ZnaFlNMlPO0r
d5W0gLQXgieh zjVhA04aa5tuQBM9c3lAL 4Rec cQc3mO10e7fWEqmX 3Z3f9moS506iA9e3VNYadsK7d9 MMxg4XChTQB1pHDWZztNbRAXcy
77YAV6KSyI5unnV SmsCx48PZl6TgKaF2ORYG7nmKsC6x
eP14Kndr zrY0qGOoDjucqGHuub55s3dUQxHc 88vlcDc85L6OSXVk0j1SbaPJ 2bA9i7Z6lw hIRqrSvmotji5tJPHfX treBJA5exPnjrg KjMwjKtUCXJjxaUFAYj0 a6uiJTElXzi4HhyOWC QUixL5CaWBx98UtGCXxhGb4 DDODXIjfLUa8i IJw08HPYdLb37M6yEYnN3uxnbyWv Z0EeGFle iU65TtJ2BYqO0ub eCXsMQGlWm aMtNHqJJNpCWEyixb9HElt
2ZzVTVYgBhXxFGh0dNITgBIZsR6sPn dlgBPo4gF4G135ktsj8k7qmSm xA3SXEcpWcVwe3P8AJaW EQ6KpVaknT wTWkIieYjWiDBj jg65s9qR9LQU3znQ7JiWyN1ijh
QV3XLLsa2sWHcKIFUpxnO05FrxO xPZx9ucC12Ogi5x GUBjlr3xgMaR 6hENE3HP z8HDokRfaN0 cEGpnS6nlDpkHBzrzc wXnE fLI lZhlTrfX8eXQF hokDczMO C4fNCLTBREC tydygk2M5mgg8SwyKmJIrxUvQ 79o Hzlb4AUgXunR qsd75ZRRf8Cb63c7HSJhfvrKNYGf wu15qwCOoNSLlB7sIu8OZnTuYBqaG9 v5a6 IbklG8p7qsmezLnu1
wj0w0mFKaYvqnjsN m pRYuPnChNJwrS8in9OLqe9yJ418A3 r4wi8dsfE4 8 FSjjI eUi5EHVcrjcvkcPPGtZUvuN2evn XFRc9EN sizoGWcGTql20 iAjqQ1yqVTgz BR6SeRSntAvYtbuE39iW9uPQeSvgNR axLQIeI25thW9CETemT4kFWx7LYyi CemdS0X2tVShVHySFrkphD0Iq4YDNW JhU0q3 9k7nR78Xi54agXnP 8eni6vD7Uhoql2ULmwRZz3Usdd VvpUB9Z22dvesWpEsfgZc8xcvFaa wbmJZq
IewKy8mt1Fx8opY1XYs e9GcgFz6qmMKF wsYT0QSJwo3Op0Eptre c93kRJcvKNZUAdLMR8j9Ptjw jyMqlvK5 nVn qhvPupvPpY48YSzDKaIFnQSRsv8f MInyGONsTnI PBtkYspZs2E3DD1qDG41NZ dEPld58U95imIcODzROkDEFsT7yON
MPdD2d WlaH0nnhLecZyUzkMiIvKZ1 ifBIzuSfd4n1UKOcp3ylXNktAl bitoE0tTuyCJTXWl1fjrGFhQX c0 7DXEgqd
6KQZfH5VPJ0LX YXjPphzGqc3hNyBh BVFAKgA1SEbcVj K ZMHal5pFGHfaA0EmREAaMm KNdZoN3LQfgro bwqmw8kiAJD0t1YOtQvnN
v6Lu9 POxWV79C56wTNFCcj4ZGZZtgx8 ZN3z9DTYTdsWd Gu5 lmN0L601vx4UNhmbgwj52zO O7D7XGIGmID6 NAjF82tyVK pPTaP524uM52iJxXiTmPBExFY jo9rMFY36TBw3eMl ICDrCNmsa oeWUvoZiM8pt51UV2KCUgEWpyX WhiHHFWtF8ssG
Nbge1q9xd4Qb113 mZW00VtsKngwm4hnfTv qG09vl DNiqbwymQUQ2Y8zetBitIDrAoIwTN 31 aog 4SJcnOsnZTDnCFE1g QA2ngKBmcHcsB5GBlfvlecAiQ XezdWEEy1VZVWYoX1nhAz9hs 7hOcFK8okrrG 21I 429ctoYGWg7UCybYbe1Q4cIz EhtxVu5aXccuNDVZ2atTq0PXj4SKr Oe45g HFKIgZBLdp3sM21TSkauM5niEwpf1i nbcoVwBzpHt2oNxHOy157y8F22 XkDtSdrlASyvq ORpqGWqCV2g
1d8Of6L3u6Sj36bBkosy7If 3GIadY AGDrcSnGeb w0qKT2rLt9Mafkeh XdW2BL1YD3GwOidwJulBp3vj7EF 6RaxR 7pLHXerrA0cynn0iU8To MOwv0hHRUHIzTkULjgfrtM BiCM2Az04eWv7qbvA8zDfsC6OJ99 pmGfVa HfasgqZzdrSlPEMwqDzyRJQF7T
f7eaVDBKP jxt11zBxq1meagkA7LkirHZOYpps Y2T1wckdrQUB ZIyiZG5iCMs60xbOxp cvbRCeBAteys0MWh7AyBXxgsTBiJyJ JIW6p14hE9th4UBSVN gxi6gtPcS1ilV9QgWTxhEoj rshIkJM3ymYs1jZ4Kq rETKid2ZIbwYVVKA 4NcEA gwnGt4nuWD71X uWUj9fmGOJ5O6VuulAFllHPjZH7 38e2IYLwMOvmqB2MoaMQGvEfK Brt1q ITr94aGkl0XPvk 5Zx3 Mg4V 3dGUILTs0u8z2ChHWLnjl1 Fy8jw2T9aevVCa
fadcTte 9Dtxf4Z yD7atJsUpeKo4l3gN4snDHmG5K7 cw7SmXn kLb1LPPUN1 gOeW049v HrAh4VroGyUim40 NfJrDIMGgcQrv ZOPUreUGeYEJi2opwpPWon7grtwR dnd4KgK hslRHpLD dzt4KvhLPTeZICYt1ylJKh Z WqNQu7XrhQiN8DGO3Kt8EGXVJgbG fcKPZ6nyvsq1ml3
agjJU5ZvQO5aM1kULZP4AiRQ D64Gs8bqWV3DYNT0sIDlis8hCP labIrwD4Z1m7KGe x2B4prmnV2tQR3mwzglDGUPBP53AWP D9yIbRJCMSjgg19BYTYfyHKWiP SAS3hkc rKVtDqffXC0koX0qCx 6CXi9aLwlAJZH CFzWcGyfENvA Jf3JrILAkaL9JjPOZ2MZfukB6Rq9YA
x9MMKDCSBkqptJyBeU1sAEO7GBis 05Yvz22Z9w7QKtRfMUc lHNO6wkTk0 fX1o7zBjRvscJPqqfPTGF kwVxJ1fQnTPBpjXiXSZlM
Out #6:
133392
53647
32888
40136
7278
125132
231540
99694
29218
194920
1372
235500
185878
4557
130065
84196
216216
126015
128193
324700
102900
174128
96481
197460
24636
4028
153945
31242
172620
211806
73620
20550
27524
91824
205056
80927
229159
117330
87210
21140
In #7:
20
1fgjta7A4mIRn2fXN9sp8pXtq kHM9K7VuEiXisu 2
RXTtEy qvGIODhd7HVkE9UGjhqh3rh DL5ywEGV8dTIzSAVZ82ud ZN1PpbDwP63tykBde 8k
2kQNqjXW6aZhl ONoo777gBDTd5qSzz vHbpMOMeI y8h9vRk7OodjgiEWkU c ClCL7XrSXkcB9Jvi5dZ9JCTUc3hDri clZJs994zm6Ar01bK lLyu6KzH5KKHR qNhLz QUdblLFC K81wZDDeCg6b2631ZrL2 qytHKtwk5Y4R6 uhBvJSccVZg4zf9Y3Pt RzULQReanGQT9i wjbb0HWoPkrIb EnZsMK Nn7p7 8jTW8ycNPliYp6J878xNK09uG
gpUOrUzAAzVy4G3Vh 9xPoIfo73A9wtSBbMcHpFoqI jZjGl5GtCsWhkoz1i5rRi fMmgoBDGHIT35eyM
oniamiVSXHxP997k1AxaAIByCL8x4 rMr8gb9kOQnV6SXD00w6WqOiBP7z9B wiWZqUQeKHbI00Ez8vu4IJ aI08oeYO1g2qdrAq G3c03lIao8P8vT4SAP1E7x XY4lIaIl15kLl5G3Rj5o ou xCpYn8M kzTP9gjznQoOQtmY AfAK6ejUV8Ub5ZwmgOzrTWg rf5TVcZ4lX1KGWZunMyrc JFCms0F602DMLQPt0 KlTfYprJ2A MXb5FrwiJd8KRjJqTsk XmC6fNH
tbC5znwQNcdoEbP8oFHYiy8Ma8z4 AzQh1r5QfcQutIW3x JMStqhEQ3NWMSBhMp6OcWZFYu8U kYBPITFPpUaWoI4F3l0 Yxb92o6jOsrT8 aNiIxqOvY2Yc XvclqPsOj BNdD2DsXb8IFqYWooIpY Aw1QfMijeZ6O348NLjoJ7Jo9gv HhRk3H5x0qnm2tLwMdqy AtHQIY5C
pVbY5ztrW9K9nUq xRqwedgMn1H6Cd1SBMkG PGnjwWwttrmCcJzM5FZQN4bpzeZzi Ps2 EGf0ZxpckpS 7s82jzu8PTeuKnugxCnd2kxSykWS QFxv9PFVZZtD4j4y7 KWU5rTGI4 ea sF3lSXFJ50xc3L JIZMHWT0w8SIfgsZJDwQcKapeb YK7rNWpSNa7NYzEewhi4EU2ThNr8GX
LqakFNBkm5UVV0GafRTTbDSW4is QcUdABt3cShpf5lDGFy9aBykjs V HY9mXM5bJpwFY YHoUbcqn17S0vIV T81NtAPB5lSuUqXRJXKR k6IdLx6i4mvUb3bAebY71
jMPU6d9 kcrLzWFdd ZgH9cXIOlJ7UKnVnTPMRHW9Ljuv je9tmRIN7 pf 83Bz7NAymBRi AP8DNIjLXgvrJKctYgCBUvYxJnAU M bnTkR9JbRU8PcxPV3v7E jXU8uVAEgoHzyp2dXnc I4CQ NIecFZpniE29jXTTOGOxfFJs rdNegTA12sZwfQr6lAffI efRSXsQzAs1AxZ5nj0E61XLJ
WLqYym1p2Afl EG2mmMR23 vH1U I120HpMmUGguSaUnxRCNd DYkDKTHzE1kF0S2FOk JgcKQcvK2rPaRlF W2hsscMIXRBhr6bm91qeMWgnieZdyk
u4zZNwMHmdsVfPonLuASplN YG7 ADD94OWA9Paq4zJMFAX Y5H5rosexqOPIQS 4SUzQxux
ajib18ihOcHZQ73syuUbqYod iSiAxktMYXANYaJGSl IztsFHgl9gILT7X 1kpGWTRae4 gHZDgdTfQJS9bHIBYnBZPyT9wph 7qB4Y8T0u U riwCeaCjAdJST2qwnvZuGGdGpd 7b3Oy8MrK j6vPhMQlt9IPcQ8TgJhauPdDH
TbBcjad8wrFUgbA nY8xnycnuuBgLeYI IEuYr mBLxeouMbFR3ypi4s q7VzlU9Y3dF gwlXh3TWRNmCTarJayd pJqQPWp A6Un8QnBKR8IeArX3 eLXHibAzJ j1Hy b2wWTsTRTN0SRuOMHgPXmVT wcg9umF8MBNin15cT6Zymn0e aT fRXZ9d5sE7wYgPT9KtkI rCPe2XgOiq 5ontekZJoR4KvSWvQy46RGv8K3Ix9 YMPYJNTRy49gn3jqjjjMMh4N30x
n2oROTbxKyn0a Koq4Ku0lNPjEmZME2aHbz 8VMGTsGvwT91vEKJXGeQ9T LnSmZykmDYU9h72tyA1pw4c c fiLOeF0Nq4knv5uItT1mUICq0J4BpN 81MxAn4KzSDGBcRk s dcVBbVjLAK10JsUKaDsrjvt94dBrFO
anei5r1RgdZsubXbblD7iGSLauPH Jpk6C HSTHWfXK4ahMcXh vlhkvP32tNPPSQy0U78hvcvSrDM1s eChvNXlrpaA8Ofj dbBoxj4JPoHFVJnYdi13oZDfce nqj9a7NLQf3mi9O7KGX8GdqO lcg6XyJBql4yxG9E1SffcsgZX LNs f99ogQWGbf5330OHJJJGBCKD00A kEIumXh IWrmmJaJFCKIl3ymqBsLhixx8PQ WMtIvoAKde8 qJCFVtjhKpXK7xd64d
yclE4pt3VLrR5PEh htidVhvpgvJcJV7E4nWdLc 6UOr4EzsnhgxtxlduiLwI2 wv6DpqUATIB4sPxQARsMeIIkD9
VncrNG iCCpNZvuzk0KEm5Tj91fCG2emF lHJWdb6BYiief04Yl7xvs7pXc svr3MPBjvdbc2LfEW546f7AuvSJ mQDy6drUqBTRd7 8L03Kvnd4KKbiReaPvOsQq5G wGbL6 tywTsfQisjHU38 PQt8KIGLxFOTQZu3hOQnBTpDBPE 2AYed3MJflvpLWZNqUv9x8JaAyxC9c
qpp6dfOr4C v Co8h sqtQDVYSyAgGU jG InwgUPoYemTKW500KEEPUTWVdAo 4i8U ENP5SR WcZSk1IoyRDVmHdTdJ8jIq0y1f30L8 wHJ8EvKR gDGzGlyCSQP7 rRofeD37Dz1Gk3rgS9tOVtf6 uUIfk7CV6ZGazmLRgp48B93 e8rDDAjgTKz4a9fMs SAYvVmhAgvs1g8ggSLHsfhiZkay SRAjBVXcwtgYcbBG QjsHbpXZxM9trJzoAQ axA1Xc8Rew90KtlTffOvdbOH7
1D TzzE9Sxcii3dikVUK6yug EFz1o07FOK6J nRLpkEm1bCw 6Ga3V1V0dtSf bxzKmVW7jG6Gn1g5 dr3Um0Qbol5b7OVYxUAFIZXI ZDwHUjHfyKwQeBqO 3ou0eza2HooZyOv6gEFJI0mCSLWo D QsYUpsgMgF2u6LGJ1CLqXQL 3H531q6 UGw3VQw6kMW2dvkk1td E0q2fhbeD4osKJchSzf 3sSvjog3OoFGZENF87wgjR3hX 3k6n2Ka8Q4LygPYN5d914l vnnWeYe1BTRjv7OzCoua4336 oWX2d3n6J EtGI ND
Rn9N4y9uBZEgu sDXp0KrkV0S6CLoKvsaRlmZEbtGGl taBBlYIr9LO08zxupxAIElfyNs nZkDwabuTEx2mijGp9DZfgyMlOu yaoJQt42UJsfyt zvfP4D1tLo7VvYJvWX65SzyYoo3m XmJiwf1XEgjXHS XAe 5uWRiMJl900PuzKkGgHXOQF2LYz bc2Mmbr8UKuipuOFGCWj7mAbIDua 7mpYz1vKE0ZQNPCRJVtNEr9 j0RnkmEujtkV8P I3wYa3XbgD adTZeFVjH5HeF 7QwEFB0t1EwX6ny6nyJ e
Out #7:
4482
13790
170982
11972
160575
89672
102516
35567
120778
29897
14445
65460
172890
58860
144312
13312
81720
193824
234040
191088
In #8:
30
d82XA8McX wAumyvo GN oFG pIrvHR3YcHTqmUs R4aYt6FTEXxtfKBJrmAvnz1Vi 1g0YAz N104fBPeUrU36E9I dcWoz83XTb3fqLIewILGH IRhc2WizL5PgHqIXw7FsXpqfH9 XiKp3S9yFyTbvDv2rvYGFLQq0bP Hb3ziq su7CrpCPP8OjnxHQ2uxYg2 MAdfX0 JkCKKAK
vy1PcsknPqFkes
6iUzMgSP4XKTeBx8RfhJcplkRLgV T8oEhgBcl70yI4sWoMy2pRm14F MQkruB23reQNIadHSj49LtMH YzNtQnKq4qCWxsIwT9hbE5TIHIGE KqPui1 0Q JL7htqiailm2ZGwxobb62530hNJjO yZQmXCN9b45S4Kg ajiStAlfkP733wB62hrMDjjUI 16p751ai4cscikpqOE45j1e VeTulzCJEkUtB g7Ixv36DnuMRXAKkhoOJY8gSP4A3I qyH63uZrX71oIIW552XQRMkF07 4a1ziUICaP mVVWLhs azUU7U2crNDWzs9aKjAoLF d0AREvlOCcmFtkY0jEYMVi8 A6MBHoAHcgFtwD8pi3g0z4QcU iMIiuVijc40c83GwsA3cprdwgTg03 Ya3lzzWaWNRfGAXRh2eIZAB8SDzNQ
BLd9NUsbNjrYZnDrqShFiAq IBtvny1rpJoZIf7 syMWS TqAOArrEfWa33B N48N17E1K1PCdUaHRc9su VcKW6IfR3Het9Bt ntohuatshHUYg4 qLe rjUT L9gZ6 bgTLvzJbc AHH2QI0q41yTyLnV01Nfcaa2d LVm5rpiwBK
F96AkscATLCtOKkIIu1 bZmaaS1 Bbb2 lZLEf8ltE7PJ0HzQ9XKZkYorN3uAGO np24BQjsoU pKvKl9TWSmppNwYKcdOMPf1 DZvp3gUVx
75bw21 WCyTKn SD4d olFbtT8FrHDWPFVR8EnKz6XPV1jLNc 3kYw0VyVwGZvPx1oA1OSDlH7mN4kT 3qrai3mZ0Lbtm1h5Umka54qg A906kQtm8EJho2nA28 9gtpJhYxFqqdfzTaxmrzWjESgf9 P2quvMvd9BDd2H5Wk7opv2 dSke5E h3LlUDEeF7nuhjFJiyKWsQowb 0DLIuO8OitkXJeee4c94 NXk1w3hASrQoGXp6XrcexEUKKvg JtUJ PddsUH d
62iuUUrUw 0Hk9SUSeoQsKQSowbpdrz5cE8
5jhmZVFu g95qkO8b90YV5YC0lXGAh HDURRYZ48QFyrfXcA o6mI0yFy6JOdxfq ZbtHPVbpFB30dB ToW7f mdGBn2M3Yrx WZpwAWLE5A7lkOZ1TuqYuP nQI8YbtBnzwImyPQ ZxHSuRttWklcd 91xaprAFLvJU I80E FajiH2R5fsTQiEEDYo94oRrG
aAF vk0o2IzQLtBl BQqH24crEn6i 1BOj0rernna6B m7sHxiMfiD5rtXQfEIm7BtPT7mRd ckG5 76uCAAqZETxT45I3UC5iHt Yl4saWc UJ6C 5aLds0Hnd8Yzh4IfPqNR y5p1kNgbEqeoTfVYlSIQ5mLm4nHCQr poMEXHCOIcuaNsEvujg 9UytsFMvs
RtTfYEuotAOIBZgM7 WbHOg QfDRSYgx8L 72coZdbS0oqfH ELLpt PqODvQp NQ780CMQn qasxPKs9XTo0KqjTe4JnSfAZa vAchbsbyS yuB7ph6Y7KfWQzMkoyOmRKCIirTmy Jrzolu I23 2zyqZLhjWsPtfdG1SGm6eQknUCe ZhruoyWlxCyK5Eccqyt4mGwwSf BfUjtno8HlJf fHNDrZIFDIsVLIHnZk68yLSK TaS9 rUVNGKRkCvYBDR925a
CRblD74QH1McxVJfxoL4TR Dx1CUlGfN4tKzpEWN3 9zc4sqCLzDtXgW4f aDoTLFE1FJLeX Lm2jYOwpf45VlMSNmCLit4
GEJB28sbdnm6ZtK TE2942oNJyZ4KrIGcLZa05B9GVcm hG7mm81ywKvMQQyQx0p2p7
NHZjU oSlq3q9PfM8Hq8ZNwVbq E2LOfiuVPmaVzqi3M08WxNufrv fbsjBQ4meOUPcM4hZbOMFSOIhMWgi O5Hkh JR6fBDvzHdEWr83RYYTeIGg UKV46q76vcXxUx2Cwf FKmCDFL1dNblgYdEhHSfFmfb QMeZdT5Hwkrg9XAlvBeUGKOi bslvbTlEeyPxYfGQgc8xSLSD3
t8IZO0drsVuiiYTTcaDT7mi YJrium9FtrJYrZr7FRVe dmepUZahRdXJq9 0dBrJymdov 0CxZroh4hGhZjqvwZ6uUh8 O2UaHrDRKGdy8NcQkR
CsAOtNAcxufs1FeoeZuQe6K cNvn Q5asNY0qR9TgW7oRuodE6pgKPti P6VC2ntzVTDdRqwv54c8iU3frp pCUbn UCwR6L4vIAQrJrv9sAFBxTdBM1kSCc BRxsua16eEDm7x Qk7QW3 NAbKD9Y S8IdTu2xgu3iIh55f RDFDy1q4n 75U5jsFeU8H0OOFPqF2ywu NI
gmPxsNMhbmWpqH g wdrNIpA wInLcMHuQpoU 5ara4CsHwjsbvfwvDxmQn d9axHMnTC2H40IRVl0SV wYH8XaLYu3lajvpMzXJAw 3mC icGNF
21YC7 LaNNwf8KURLJGj1LiO12msmu Hj8i04Pk3LfgMWWfrZ3hs4auszlR2U s 0TAFIcOTeGSm nNqDB0kVLk2HW6 NSBLz4u3dibE8eNU9NikUTv5Q 46JBXnQlhVWEqls3le xTjtC0IVMrgnyY37DvOlCyBqraSyp t7XAcK8OtgpqFebrrztPj3SMgxKD
m89HK9HNH9kU52cCRSin 4zm3LGLmkddItKMwWLfX
lSCBdAj k3qjewLgU3 5eUgOhMiljewWZLiVNKk0m
pcyNAZ2 mFOSyQSCiiwuiLHyVrBk1hDFxRnW9 Jm2JX9vmwJFTrOvXMUfLqi uA6flI1Bm W296eVyUt4UZl74R6Ilj2 yCpkISIywOGR7qfttp8hS CNq6evweHX5h
pCnHZysJTGipl7dwPdg f5W2QYgOcW 66xf96PX8VAQOBJxUQJHD 2HBGHq906FTLYxX4tKUv4PgD 0oAnJnnqglRBcNKU86 CMa1S7Szg5is7 RiKE0VW6VnmCH11pccysuIxVSr vrWWGZ7ze3BZ1 aMaDnpHiv R3IYkpMVMMj1Szj pXbSuByAv6GUCbarNQ2Lo7
9YWitWhlDsnYN6fVJnR7SsT9DyGra k8hTZZ3K0w56ivpvjFWi7 UuNdy05L7gnLCIjet NDxLNHlEbG0S438n8spsHHGNJvE5 wHgGdzQcfZXRHgAXgR7wWvDM
XSZ19JZsEzwyokhgmvgEFKK6DN5 7TPOefqHVzJyIN5EBGyfHzpK6yG8 3YN0xX5IAB0 PLYL5Fr9KeezngsApX UmeMg7s8t5o6jcDa5m37hXe kwY2ylVnAvxUJ2E3jTrdOS5DofUit 1k0GGLB Jdnu8T00uKKM8 eNhmf30GAZEEG QO9kND 7jRQDLFHdj G62XDs2F5BvYuKBu2TK S35Iafdvus5eKYAuc4 qpWkN2VOQ0YtrzsT pZJUMLf6SCxYJdXBaY9bFc wk lHI BP18JwowYBl Ifrwoj1Mh49xv5pTLXAqZu1Ojvb 75X
4WzLUrTG2o8KNj aeG8DbaRRtgu JaYxUG0zupM6xEnNI cV0yELyxNwCdV62BQ0uCDZ zJJKfKUsTBiyyXxsBpmvkcy 0QvzNWGrMnMXqYjWVrki elDZRtbNhSY78KC3Ut5IZB EyUBtYdXKkmYNIzf500PyEctHs920 2j
CiHeaZIZcFhsbji4W P 40PEihqCkDLx13S8dsdok24QX6sP 5Ox7dskFDLcZbxCSPxOiE RpbhDaq6tMfUvbePG7JJeJ8mF R zfH I1z90r3ceaq5AfgbIVlXEa1r iTT5teo7KV0ZOTc6Ol1 1ETtHVfxUVaO4jbDJgc3rUYpW1lM ZQQnw6IJZzSdO LroXg8w
gLWDC8clKZjn4ouDuMrBWI8i1QoR T t4Qd1lqRtNvE pye5bzbEAyOKNp wzDKonnaSjteK oNB75Zy7ngU6wIom
lITlmUwu8YCw7NUx10k1UpaycC6 N6rbmnEHEPpljDy5sevqT vxSloOkpOzyDXdzMKOAc6vLc PeRK9lI joge62 4ZBe1zDWhjDmbGfqJCGCffAyZmAGP 5mfpRuG8NVhlD KMCyPEfmvUWX3ARWgDFVob xCLhw2VEqXdRJ58A2h1E2he8z4a5 wyJfIHK6m aK ZAhbKl2r8C0qqhXez4rRJWWhMFKIo yDWXYXeJI447tHs Fnp4kMsH YHKsrI9
OGQGSQqb4AdXNpmWJqIgRQ 0rxCEMUM47ilP8MsAclvxT MBaZ15O9od f5I K8qhNR0FL2gpD0TFoS v9lI1AhBHHEw0PuAovP lMu342J nxFj4FJMQZjCLD38HGz GxW9LqODArHKtnojdsIfQdshfok Ktq Nrz2LZ8 Ibo5dJ9x6HGoPLhRbPMpUGKk2eVqui MgA0lGDFlg1Ixq n ZyIWGB9 jXxcqafCTIbKw jjEA72GOWX QuT4A6FRlF
ZTiQ4Rnfx6BOq l hQhwvw G9GYifB2tztzlHEC lj PIKW1Btr3BJUdWFkhG SavwYdm0ZWzla5 xIw0aKdTVFgk tA2tQ Y vBw6IUQw YjwetzHxOumJfcvs1FZn0VMyrxjxH y1fj3tjo2AoMvFTcdr0EieE2sp3441 lyIHmVVWlAu9gqE5Qznma3P uF8xTmHj12GexU5PmZJVIEveFzaLv Ml6BqKqBE9d2wO1nRSfB4exAoVI VUKDRORmbd6VSQfaUuGooVpPGnle8
fWLWSmTVuC52oPHB4pC OVlR7NYoZeJXsVA1 ZgSkpEapYfZxZIn7v6MkcGwrHSO7B sBSL7GsvoVy6qEEPmPPKjR wEtWHn0u Qfo5UVQlosecVRwhM rcVZnqU ZVY BW2BJapY9XQQt7syqBhUrD3dn hL0HzxVfdhy7M8LkdlKN2QT0vnKJdO 8fiAWyeGKZ5rb9fWgTbgGlmuBqRbf OL AgWvJo5MQxX34hsL4O5lK E80ZRCFuMpJMm8GEJ l66yomb RWPm7ctd krAH9TDR uvV 3E7JRqdw360EXS 5gr
Out #8:
119115
396
349060
78715
29330
162480
2714
94042
90519
178866
18605
8208
82780
24654
99957
33714
77500
3296
4047
34496
86306
25980
250940
61461
89580
18852
150105
174636
179996
240960
In #9:
30
zihDjJ0vgSzGDPFU6R2OmdFp JZgct 22bMPg6HyKlYLbynsgx DRf5iobioBCk44H5C 7yCaMLP78Qt2sbWk 5y8Dush s30CZGnKUHj7HhiMq9U0gp PYogOnIYa 36yjWPjVKfi79EihpLTjLvFXH dm4jptRYZcZOxr3o910T4QC0mUIS zDKgPwaUDXU AUcILm0SAUoraFMaH6WviSq EgE1hqN2bZEp0OVfKDhLttZf9wF g7OBpFT VHNd3f0KWEwPJ2iVyd4LB6Y 0RPHZO28z9k0oEz6RQorUvteoqYQ Hap5Z8RSdW7GDPonkXJz85Jfp2K 3d6s5dKhx4qQ8EnZhFcGaivQAcW0z 1iv0tFBnlw
yfa1dGwmIsbJp3hnVxZ ksVAioILaLqfeHrtmMBc 1BAVNIN D0yJn7v7 kt4A Tj yCFyeJIs7RDaXpeNHACU2cHLkgjA85 rcvPvZccxu 5SwZ
qL4oExYRELz9a3F 4G3EII3Zt0NK77NtH74q6k cNDtDPnM6BAp4s6Ai5jaqbocPlP6EH 4nTxgciGzHppan56LdPDCrYM VMGnpdfKG 4yR6vpNrJi37Gb iWbcH3e QoUUalEiut6lJmgC uZ1lay ceM
8jHNZeE2fAoMdjDvcpoyX4l FRo 7DWKBkTGuHTBMvEgIOqQKr frTAZakNZgbl7ZowODGSZ7ZoCk6 GZR0mWk0ihCQDzuG0 iByFmGMJtI5 p2FSIBM8igqBu USEYZXBNt8yDDnRD 2jj66LC3WgISnZW5ATJGfln6n7Vc1 L5kJ 9cNynqVOp1dFuKef BvgGYIVFSSEKqZsZAl9IfWaucCpH Vo3hfSJ0rxP2oZF9dNhOAuz 4cPt468Il8bp7cTaHwSbFd y7CSnepjdgCZUO63PdtI1k9FadW 7 KtCGFkp47BEvWVy99O4z08jQ2o3 K38S8bS gmNAFlxYgU05LGjwf4gbXrpjk3VhPl RKdsxYrXEIT
gVrWApSxi37 47F5dEgKJs558u eRpjjvNgvExKakXyGgRdbz wTtUAyAP3ksNr6j202BGfCzef
xGtGAGUxTzWcvFUpiPw8 ppUrYiNRxBsJlO1PqV45aDGK7rA hDXSze1FjHKXpjxDCf0Y7H8khXd vArLQjnmH5oZTQhEsUy5J sN9OcyqvW2UQWdISr8 es2c 3RWSNBcdCLmdsoqD7OV6Mdn HB10u7FZLFa27 qsQdepjJhRdQlRPAfyam1trjouQQZ JnPDNSBqrnI8 tuV3KG ilL cmhQbT80q59kPJwkTwrNNVyZphJsVR BVedxOX0aEwMAQSpowvV5z5ek XvEf66fPbQZAtpncY 2zFquJy S2Ucty blTMZksTj8XmU0bZP7ql wc6FUHDIPEVUeXC
3IbEtgwJyCAO49 xOvm31JdduzUfo7 6yezqLEIqlxvM0pcJub4ra2SbcB rDRsHYADw 4t90E4ZnFSXqqduwUoGQmM2Kb Q1CkWFSLY8HmYN3j f9ngQ5ueyDN BiQmqxO5Rx29iZzlgO7 8APzPB05ulYTHQVAye ShS mH0qyLaUsVCPZeaYBh1w19pa YjjRuPd kzYjQ8
blxxMzV os7LDkGUF9pBULxFh uvbJGNzEu4UWX9Gy9d2xyKa ZF0U10Vu fJsR6ZQoP NQnTVF7 CvOdOpyY2bWbL41lDefI4LMMjZBTc 7PGPaKAnJztSswKIpq13fZkJp98 eJES1aBGXCXcIe6TdY MnQvSw1xU6z8nh2R4 bJftKKq ReH1pb8PiCtXQ2Mdddvh5Hs Pn6SjORk9qaOsXinfBc3C6EXeOY9 zUsBTtwrmpSjosfSnc1J3RuQkhb7I nT2gEDNAnH52XoMPbmi4vM5Y uBkVNw2ZL9zRt19D0 9KDH2cRU7TThlsfU06tx4YK8uln 0R 54lhLAkpc0vIH4OIjof3wO9WHIIcw
2fuq5t46HtQPKHGnPvVp r P5
rYbV7YJS3BMOowR2xKdfUWILwW4A02 RYQzVJGaj3cIkmOEz yeqot0qHdE8Nn
C YfsPuTRjfTCH2w8HyRy2Ntz qse8WyYZtcxkgQ xBDmUzL6mdMPXYCqm o6UjDf v IQCgsdx02T MF 7 K72iy1HLVfzCgRQA YVSgCNr3yWquxHXuNeazWLQT5 qbuNoBYnXcRRVJUNUF2 a6hCVzUxkc1aNNilICgEanYXYBFFHN KXTTU
wqEH8Y rCTiHxWMWJKi qWsuzSlI1NfqGQfcMBnAlItx lZINFy86jjTQzexAWoPTUvB IZD7Gt7sCRWYbPd 49jXLdUwocmPUxPZ6X561GFJIGr4Hy RhgvmoHHgmJaO0c t6ek5K28fqdSZEkQ75LOX bxY2eB7Hi i 6WZJ1L6KsPmjPjoNKvuKQcbclJ6 3dt6rmZAj59dl NnxwHeyyLBh5hZKF8DyaaWZfoL NuXILEK6TS49SalNTIFhM68Kvnr yJfpdFxXaeIZs oDimfT21
zBOa 9n6tnVRQS d0FPkYODOnFCwv56fF xZcm F7I9kJuGtLNF6xtyf2t6qUq 8aHn59rdN ehxdE1kw6D tHxtsbbaza3EDhrwFrMuwlA PdkcrtX6dg yHrMRAG koUp3X7BOor9SgbxqiUYFT2Zi
Oo4KvfZ HzVjZDi28JQGfD7XVJ co3MS6n84x
06EAE27ISDt1HiKwUp38tbDfs2XV hRR87ETb4M dxAkK9H9tnCFohBAA fp6FnWK9lEEQwlwL NkUpGvJLt1MFVYAmPw7SWjo7Ao YFjNP WojviqI1rnt7MRSCh2cOhduD3 U2lVRs43BWt h6th78 EondMmXGu8uvn OmB5MsV11jf3No3C3a RvQtziYBFUeGajWnStwr FjGCofQ1K ZHgeTzxl6JDRuqf4m5PArt58s Hij 0VJRoq4SeS3voThMVWA23e 0igQCTyUWDTdM5f 7MlhWWkGhsoe
EM0KwAM UpamsV9 5WUulYfPzQ kCzicDUoWsDpGAUbv7c Z 47p36hvgElH4Ta5dKAuX2cPK0VL gJJZf9 c8PLbTOt2dKfEQaCdV B6N3GMDsB
vi1ca9kgM JY7ZU Fjj8Lpq0pD4hegv6O h9aK4 aiCMqy1anrrLhKYzLct7YJ14ekr1a qlRplyV6XR xopmOH5 OJfpLphEY5 nFlHET9 JvW4F6h RhSCNBkLWvboCCwRvx b85oETRx ckcnhH6odUYXse3NLpQx3Z2jC EKkGfz0cTAmpowm5VYqHD 3z4f glO9PJiBc6agF05MR1Kf4TV Q1uZAyNHlmpBXbaAN8DZrFqZVhvTz
t9dLuAU3AOjNBRS9gGJiiih 6nXYwD8jtI0IZ7Mzzqr01Zd3 Tosbs9zBvKj4w Lhg1BCgsNfsm6G0YGhP VBXCuIJo89OOtp xWjbuIxi1DxGi4W4 fuhI8KkTnp9gPivA lCNGduQjzfKOzL1N0eNgm5qMfmlrs6 ZLfQjQw8l iAW5 QapbpCAJuykHdXDWO ixuYlVxpdaKOlByaPGgNvLD44UH cpLGlFPM8QR9VraXUdaCyO mWaVDrkvu iwoGf6SmmaTpD1oqGtfd7V Lkc64HS5faisNT lvRI
srFcNGfJR5bpJ4ODJTPlepWlkhwla Sr0YJKZPLmt 5rzmKqU woSHI6a8ZxwyjPtI8m7iBGhiR DQQLodIMSIk4 cSeZmU2fxABOrzrFIGBX FVS2AjXa8W2dZ gOgoAHWmVTfGjS6pU9xEJAkAGVG8k sl1Jusc3dHgCwCvxbD6Bsbhp6P8 hAYaw H8kAW0bUcn99U6LVf2R0wE r0L1uePZ360nYHI9VA8o2
hExP2 3jOnR08Nf VV5iqPoTd6WYfmEpIJsZG f dM4HyR3axefiS34j
Mh9sc97g1t6jGXxPONRRLpY9d8iWsa sbwDbJ7bYlipBU KIijQaK2oj ti b5D5MBAq7JGehLztBaMXl cTEa5A25AwA5y0 nSdqiJrdwmT0H8Lkfjehb6XVwRsfyN rulFPFWKBLOtKO EUTd6ExMuZ
l939x3TIduBCGPSjYn4Ht VUnXxq PH3y6G3tSDLPZHYM7JJE5 SGCNWnRJbThF1S189p1lwljI uqyYhKVyWs4u4BOS6oZMPBEsP fiZPLp5 s4GiNqq5JLQP mC0TR6saJGkfpUCgCJeEZLsNcJZER JwSL1cCzWKgdXBSnlO7Pw04zz4 8 95sqmP0h7oLpc9uTL44Ro J8Ma3jKY9jkIhXl6
PWNPDpfQlRzk59s5YxhHj8hxf pR F7DuXaiNvWNpELSW usxzeVrCOE4R5O
seJMwXVyiLYuwUVeJYmIeM4UC yyRtuHT9h0 CrO3cyHe8ouNpF3I6x 1yrlILuB6u5Iaee7yr8Bfj Sgr81 C3K68AP 4w5v8i9rHheca7Wr8m1wqXH6N HXYiR4DGG95 E4V1uy7QPxNBEMHM5nI1kXSV aW5crLwreMSOUu6jEgVaZ9Pv5VF 6 DVh9sRY7wlsIE99Die4HyM2LZdzrr H8fHO upIupAz QEI5opuGtyA f CJ6cHOKpVly38fyuQTZ pIaSsnBtt1lyDnYRRz NIQel5iZRV9fQkefNlVE8Fb
Z96WiU9fsDaCoLS1AuCD2v wZxd0LLMmJj2uNYr5RxKRmH Rm80q1QBMy0nfCHAMsnzv hKgnZhNfo810QuPmFaEXBeR54OR nc9rPIjtY5YdcqC k8bP0Aiib pKsJyzIwyZIBbEXSOk55 o83hmVcl6Dfy y0asd7OJ7ton5zCEyYcuuJDDs8v nBXQibij1mNWwUJ9mn6SA0xZGII kJeKcYe OMq7Va8O8vU3fmbSozcvrLTZI0
S76ke74VtBGu5y iL4G5MVJ6iHM52M8T6 cck6rYrIUM0stZ1WEc1JW9umZAwhy cqS7HQRVQ2sVD AZh2X S6f6kADwbHKGtgbEyJbqH5royvVU 4bzdBIYSAnsh6AwGCAhAVFZ Z2GWIcLMg SYo
PCrZqcUYw3dM7Lci KRZIns1vG 1hE5lUDTnmoEwjRy M1jyIv6sWFXHppDTC0 p7gE7vGfba4afiMm0Npiwd1mU SVonKSaUzzTjFM8bl ETgm6t HTxHHc0uaRNPmg3c9T wXETI8 xF1ZdaQIL dqJyYrFJtXj1cmw7pV1 F
FTOj2ETFHBA CIOE41g7dXC21NQYLS NZCvBUdVtBfzsWtC4Kbl3b3
QHf8AOaVk0d83sLfvSOf1DptBm IpJTRDKK7yMbIpLINmoVCX ZbwhWk7mDk3p6z9ouGz1Lut 99W2TyvTl6lPAtBYejAVLZqgy 8kLhvGhzkzlh4s n042m7MUZuVrL0N89x za9aM1aqZ0dQJbL67U6ohmsw fUl64JYgZJpAo0A dEraEjfMdHb4IMGihBbAik EWPzA0dlVss Te 7UjlJVTlm0W8YYP VA8Xiifa5d7nCi 4hrNOH7F5joTkJWFb50KR1 5oRFZlD3XPMkgWC NmTWJkbzWRSJYRG 6iw6AhgUtB2MfPsYTa2TNDiHB RJ0nn4ao4 SdRuEzwvXcYf47aTyNSlA
Hfsbs4ohCiEzJeFdkbPD7bQJhlGUAQ ASKC5TyOTDxsz
Out #9:
280364
34398
54660
299860
10556
254049
98007
277153
2757
7818
101416
177200
56452
4194
199908
36729
152201
185130
110184
9570
51129
109356
9460
223877
114924
54387
72504
6780
257640
3560
In #10:
30
50
s5h0FktbQNcGwWqzlldmG kxUz7 hkRCLrFAw8Uqu3nr YQWjbjpHpBWvdPYYPuv9 f V1XRmUJ637En4bIsAwqRqBkvbMcyja 5 6xYByaNt7fTdN9aOdfdbCBXT VBVDXmPkBOgNQP9hQwxBPg 4b6mfybUrEgfV11VrpS MohLO9C 9Fcm z0GHfqL4DB 2XHlkaYz zTMC 5zGyX nb6OhUm5EEIL dkgQ2hqAl2uhXyv8Rz7gAGhZhadxNE q4Z93VfcOurjpW56R9wWM90chZryZ
wFMx0A 1bvyeiCgDbEI6MTQ3dtkHcJLTu5rKc GGK2Y9qyugY6fwlxgthcB GQOovBFT2Up6tAFL6zZZDm g BRCp65RG4ZhO fggEpRGCO3pvhSQE9cYIKeuqmvGv phkMNnhGj VJ17E7BKb DFpvTiIWHpXQqOz6zzz23dY szm9OsTQdBYhp3tKSNxbwerQ9S KlHw52UyZVXDmkFmSX6pb80bNmQ 4wUeSz 6FGo TIoqujhefNgxmdPzqwfaAX IFAw3yuNSASkokj47qDEUxlx 0Ief 9fDtoM2zrEyT0ckE8JQIV333mtV VliMUBWd8tPx3l 1RTpnizhydC
0LjW ICtMC5RgCSxpvVqJuH8 h5vyCzrZ 0g9Bwvz8cGI8GB1DXZhiFOHor9 6GS Ia6aUmcQ7dmctX8UQRJ6 ucTx0S0BTP01 9LgwxY3GB1vKjbCXDS u9ZwYSzKV8p NEWAUU8zMLY9iOIUzQ74
ZpHRCLbyssJxBb0D8DXpGVPJ38aI sOWHE90 UVAXzv2QgxCRWvmJ eVvvvUdDb Q5P1ELbT4JZZXHCvvhCIk cC29ybcY4dBQ8ILrjSneRm7U7JZ OlHQPQE7ZHxS sb2s0c pc5Kw
t0ntYtF5S8eW2LQA69Zw1TmP0wmSM 55R JykOeochMwvsj ZvxnqLZGO4aIQwcIUMP3X9ujMl5H UOMR5MWw4gYCZAmVW6 UbEAcukjrUsNyb hDAMuod9zRJ78hWAAu J8
VYF4HJk0PAmcudyGfRmiFRl8dW LMbEg3qx zNR2BR znbnDD32cFvRm75kAQk PCZ016lpgxUSs1d1M7a8bGtgNpYs gZAX1Wzava8Zx iqeMd1Q f Fwo8tbC1W78U
LD3zExbCWIsGRKaNdxYPeDZOmH6Dbt d3UjJzsDo DBKQVEg9wC0szrII7qy97BiA26 YaPGMLkWHW09o4PY0EsMctkv 7ImKQ9bQ5BRtmzYl6Pqlklbh0vteI3 kR9xBtaopPlLbqZamO
8Br3t6niMjNJ5VxdlaathfgaU4 NqXEAQtsxRPn3O5L 2eicYN4zRqxtijdCwPZkA4KIqySlO fFDXXRkMgrk0K5mVvjlQf4z7vGbF y8nx0ffswhor63fouogvzb U6md9OXIjO88FWlZWiEr3BqFWUpN
P zZIZJ0SXdQF40T2BST68W8 LWf6uKCRUsYNftSgcABlFVc
J73xEkVOD88Td7omJyW7wl2CwS6 G0523Zd0hCU
5AdRPVIGbZfU qhQCQAH8RCU29opJf38C86
ZrLvTHgkIplKZ8XSfOm gkDOeK3t2stweHt03II9iI7bMEt v8lV3gsk4 sjb0JlEBm0y 5Lhd eySMg hoKfQYohlnw4wnWP0kACDQIK9k4YTn VsMf4FBWGp3j H3E2YwnL zxG4P0enXLaAR5m3mR1ZshL hAheYpI0HmdSAswglTjQ6dfhJL pm6NyiKQf38pA1xIoUikWeYz93oIw 4X6MD096lqCNRBc4 D8qQJZFssOW0PNECPrv
Sm7z5y6g5tTzTR2ozetXWEr2bZIgQI zqgrUvtN3FnWgNE23MXw7aLZx4Bj 3jQwjo4bFllLYpUFrFw0G1oDIZu maLuz PPP4mV5hj7w9NOPrPA1Jxxzu4W8Y9N 6hGObYT0KkwtvSFF36L8BG 9th4fGtjO6xTnMOKs2j 42 IqlAkmD echXmkHDicAOql2Y96FxT9l1DC LP c4pH4b8Rpj83Grl syXFS MzDJfkK1ZZOa5oJ 9eY5TqzCct Yt7lSPcZCbDJnn2x9R64i7v5WD D9P5C cob5PmAzVpe7jwXWPUFiD
5L1r523R 4bFyTr4JwDBjS UJSQU22U7UKLHy9SG1ISUR gXCW7z mx 68bhFN6d w8eQnK9 ZXUQw0cN 5I08rGlR3oY5nh3ttxu1i9ywS95I Av2GJQ TaAQo1MVY6TgMZta4rLzcU7R6p IlZgkxcCD rCEfYU2T4GfaySGuYVvXQ7QgC
aFZ Nc8xGVzAHM3tIGxBHTDPkLzMQV z3yV1k35FVpUjaxJNCoGnYBKg TwuX8ho7m2FrSOT8EeXN W IyC2YlZtyWUpa7OdB93y laOU410xS3cHARzhc7W2MU7 MLN GhGoNVzJ2sTDp2FcxcFGV 0 6xOHRivSIyD2g6 VYkC0ZvFU JphgoyeHddrUAsuO2FtpteXj8 qqRJK2aJG6uM6Aq2VwHrUBy q95 qKRvRX713gk2PWf9ar6
dZrEw5z6uP52N0IRKp190tyaIMN ZkHHoyoPr3yUACEs0 FQkbb6Gb25KUx6d3vZ2M0rp8oRQ7bP 9 Kc iJfzkn6TjSGNnm56hRlfet9J3Iil7 cpK ibIvhzyNY27L1XyDmm3ojvR9m0OOTo IFvRp4K0lxu9yRTJw K17n6oLTl vhnU7fV tWhxcRwBpU
B8NwLDt7u81kk5OmsorwFh5axWSR09 vBSdMtooACWAfQA6hS wAkhYGGliGsANpoTSH4WVNh9Oo0r hMaw0tJVwutHGvdK6rI l 8GdjMoLleKil PQz8zjZYQLc3nP5ZD93YuGorub IV0sqG5P j7cGmz Ceiplq5GlBctzisdaE mGo4Gti71Gi3zCNzm6JX5ck
PUaAjnXvGyK8db5hECZYaPPsLdri OA0PR4h36SBkAmzUDe57H q7OOdd8rMJvBdxKNxKnqI0TZpyoV E8YKRLrjxX73lRCNeJW QNgEErUDQolIsQa5Skgk XhqA PuVni3jJSs WEmBWsKwV289VP4Tff2sUlwAMEX nV1cEqxFwdRWxZ Q20OsOmv2dmYcG9Brj1klN 7sQxiCZpfYih4Pv2bgdMTqViIfC 4ypdkpSyp7JyGFOe89YFZ9ExfF Q GM8h2GJDYZ55rscYV6Cr4bLpsm4BN 61rmbGCi cvFVYWtFVBs2fSU7ZJS4PiSSOHuI Uyi6uHfd2ibdCbR0Z8z1Ff53gJrG1F v7BH2QFvSeBXJ901f9ZyAdx7YlJmD0
dT5c9IrJXi3iSNbMEl5exxd h W0RNy8ERJT2Nnzv fjXGUGS e7BmuE8dK0hCdy6Icz8 4kdLEwPVqEG 0vafxmzTtmhQo SI kDgwJZZ7S3n ILKhgMvrnQx3Uns 0GjL9D2j5xXqpfXl uJ86kANvQ585yTguy
WCjDhDEfUBqsJN49xYMHz
Gkwkuw GLRQUcLm pe5QHP7wFnxWWHbC k2rEkazhSz VnrGuS5CEX8BjFFg2LJOVh XU843s3QfzZtQto 2ezBMMpFcHtQDMY8Sj OdFmnS9dy5R0Fszv78 t6nDwHOlADUc UG8unyq7sbLrNZWzX ng5zF haMdLT74BcwwZ5Vntb7HjFigxFEwv aN6jXpazwkojaoCYjtmbze Kx5XLbeHYJq62LdbaGVUtW10P eTQ6YigWUmpgEt06jJfpd nwrI
yJwHsALI7 eGM HPLWL lO3e9W9vL9paiPnMu5kyYTj zSWMfLOD7R5k2 Ghi6qov2H
aS1vuLU1GmGJGSjgMQz0SU35JuAVO WiZ3KjYc mhK8DKKMvluYSn59r 1hm7N9dfiotnmy0u5z HuAM2SC8A6qenUeYXmhc mdT5kmi4VQE HLr5rf6C5FUb7Qkyw71Rt1Zgb15bz 3IJ8Kg3ruopSWtYBBdOD4 qNsXFz27gfmIP5synJDWsAGy4Z0Dfc VxNJNGZJ9Lfrn5QvSJBeaEK 55Wi1wKCxqdQV5o5YpGr kj4wbeG7qEU51v3JFkp1c00CeF hR3
d5cqmVtgxiPnsWPJUuMh6esIr5MOHg lKQ39uu2Is2h bvjYi0QKN
xtH1LKbhOvw7F A8h bBZ375b8sLo4TZMHk 9iOyLg1GhaMedOHDxzZO2oq nxgYtSNRkQx4mMAv0 Wk0e0uKOHp3 EpveQ95tLbhe
1EFyVLIt x8IV6Vk0dwwvkLLqCtfK6xcyXJ IxEj5q9qffWplc ooWG7QdFGKLXSRLaU fxQC9h84gYcF2qU1NEWXZHE7Z6JlO h CWvO fzIzO9e5HGD zDQbeSciJuhTIbEzlbPAv ENCGmI 01VN6OXvchRrFqUNgy4 mbL11tmWqb cNR6DdEl7x0faD7WhoPoI7EYbcU2o A4GUwamQbyLbpXVsHy8n mKc
JCQkanl hyMAWbsRu7KBf4xOmYMDquym Uss1FzhsaWk9MlZAQx4arAdzK YpxO8YHqarKGhnDrUbHlu C577cFAZNDSwusnIWFrG2gD1Fk 86lIg0xehbOJ01reD0XaHajZFJ6dla oCdlryOsx9T ZxZJinbPk2ZlGdSJGxgOJrrgfm bCHXV0nvSQ b8YlgAzzpErfK0BaHS6RWoDeM kv2 X BrdfC5kMDtzah9CZIkTReojYn QKlDam5C41KWoe PoWCY KiBgwpZ1UXdyHJaRmHUtu58DSyOt mZvDYn4vXimrkBYAQ kOM5pi04Qxm2
9tI7YI9PW2snq7 UVnRpHJVMGY9bJ gT kcFfFgokXioMT nLsDEdjr4aO9s7WqL MMZ SOrfLLVooDsA0ZA0oeTd9oJxn9aISw x94CjoTiRnSpKz7 x1ZuYGpRLTfxgeoBNTDmKiZckk ep1xriq0o2OwnWveIhY w0rapI4PCPLE
9DBmvTKeEuj6DtjYXE J RZyhdE2kM OGSZfgoy5eZZKvtXmPE4cz3oaTcbqp UghV8AIM8drNFvz83YOPB5oVnfLhWZ wVBp4888gvtHrUIHJQPGr98MGyc1E3 jmLL5IPiO7GH vflimyxegz50wA TnZKPcvvONWkm CFUuUCnMISOeSI3xU9wB lsXw9ZTeQWiJR
7cxipHm7ohP4LSL6Y0PPw7vA3Rd3 yJIfs957uC4hsvBNJPUx tk2OcSvLTPWZamtb ul9qF9KgPbBa 8iQ0pl y2ljzZe21Sgp4jf6mBi8xvIO4vd1kW OKyUKY3SKNacUJA8xzGL IX9XUuKg76rC19CM eYJrnF59NweJLmpsA5d5FlX6msi4f ThxBcWOUMzb4Aq1tNjMhjgSuvdvLGu AHtGzZC PPHXQzrvT0tWh0dGxN3YwXuIkVVagv
IeZkhB ROxmSq91W 0mNOXj45VKhXAz jBuYA2U0ovS 7o5p0r h3 sJ8chcP ew7RubUadjkQZRVllhj35m3AcPV2T cghclLhpv24B6P5PqVZYZI4ZM 0EuJ swiCRCxxAqulG5UJJzq1W
hLm7unoONr 3VThL wrTMNoOaLgKBsNXiOOPureC 5zGES91Mp0V9 bFBj1kfiekuchYn2fswnHgtf 4FiwiXuI oTYEY6a2dmIweRx6LZiExPLP
3a F4Wy9JhDBuAmf9RIIoKKONuJ0qNK VbPucwOlcecP dwLrL8E1Ntlh5hX9 QmNXb00nnE1PsXLwknlGqq 9tXLcaEFoCKB nK2OVL6bMUtD45xkjFM4TDXFm tC6IobRf0MJ9tPeykJoA79hKczRp 4JUxz81TkxZXm uY V7s3oFQgfpgXzrRIPy WQrKSB 7XbCF84CVbOPVIbl53lqojJGXsVhg i hS
aX9VH078wVVZyN63YKaBf DJeqvqk2uLrumZGtyQAis vYQjqzo7mjFbbN4vUFQxItuZ0Um CJB4VSjdrMn
mqI85qZ pIrfiHGsgahMOyizFF ZTksPtD1JlmNr4x9kInZ0 j9eSYkJgxf wlaIPFRaVCTT0T0n8 dW2UWCXchX33xWG uqdfgkue2ZH9KlOds3LeGB Cnzb3V4nFvi3s 0GnXhGan4 eAlUwzh4Egf g3ReWwgAcILkKsfVIqxiTOricf nE Zuc1fry4wY9OxnjJksv WTcAf5qkZUpDQb p1CHI
kmdFKDnKOy6z4Nv4L pHCBLwYX0p9E EARD2kEhA4dQVziI4vKE5uuC b rm9VEbcoz2rp zjCS75vIE6nByUOIeyk1 tscROmVVqIGbGcTG Uf3lsefrcl7up KzIPzr5y8w8r9RfKq3UqWFA7ntvW QzD8DDlDZ9w758lHvov nlwz3MD4kWlWxcQlvqgy zGFxIdKTyBcjjIvI CRbDD2Vcb2L6B K9IELg NZ bsWtBLRrZOSdk5KuKNm73zJileX USUWG7F aUNylMaVDMBuLh5MYIIeuN o1DcCRzeuArc 9YQIGLxWKzPrCnAqOvYCEBi
z8Ephk zt1 H0sKcPCDwFDuSi lGgmUdF1toRBHx9 VyBOBZulJCnyDktrUCsgOJVK8tj5M
sC4pMh0X ImWXurkfzi1e7eU pUix5Q
H0DT8SXRY0YH WaepXrdNxd7jZTuVi mQzW2uTTbz0XBbpLqMw5lYT6nS6by8 2B87fPBLnOkMbfa6letkSxlqj GmxNC7n JxvM Oe1 jkrTyyI4KmxEu99ZWrtgyiC0N3 XuMYAOehiyf9X1foIJ 7FRCPxhfrZ0D H jiHQS1pcorsuXvfADVMjtkzzbjihw GgzUHWVEOcn
5Mc8OxdrNu1zddeePGqUNLX KNfdYQ0eN0uDw uKiwrNGCbwaEAiDNt uU7ejQhSQ39 HuzhdhtvN3qiuzqQTADPvqXuui3 JbYVUAHevAIQ9Z80ZejEd PhdEbZRVxskr3RRFuip2 mbAda4ptb7vMKT9WgDgRzSimnOPP GTK0hSyypmrIN5UqLGgkSG IdLC4GyB3mL0YbmO3AiqAVEfh v 2AnYVcIodC LRvBpvTQ1eet7L8c23dx7U1FV9 O3CFwQ4XC1 6XfZtteqhcFZ3zd3SLJbTV dSbOjtVDqrMI6Qi U8Jg
R7 czyE7aEBEQTaNPKVp JXIaZh xmpDlsD8Kmfxng7ohxzLJwR8Yr M84 9cKxmArN VT T7dNo9dM2onGlYB QQmElu7 NiXUVab7JitbwD1XKWqhmfGIu 9d9Z83hla44Lm3tSf0L zE41g4OTUZUIIYEsen3SFf EPxG HzW7tmAZxd k7lALCJQO68nhxNyNlr CEY 3dI3oBHqMqkwl0ra A417VAaU5V5D6dwwY6HPs1pUwK m7Hvndi 0PihHQgNmShwkoHZgRz
rVyJjUQpRitvHTmiSc6vu1CzWyk erO cwa3V38Z5vwPSC2cmzJlc k67Wt2LwZcdC XCSsVGrQjS0YggtRxh Oxgsko IV6UUA7v7sjBN E24D4Ew6qMN9GVg0xxfXT 424DzRKqjLaN3V MugK448yfdOW28o0kP07F0ZiYYf0 xhsoFRox VQo38P rhk6kzOWbqEL d8Y1OOXtpmRekbh orC7m8Y7jncuQ356dDo O 01VGDb buCZIc8RDsta4 BWoO35vg3qY1tDju3Tqr2SU j
VMs7 fUSSBH2IuzwPM0u0lRpWZh6GXI1Jd7
JIGpgsYd2s Q A5gxY3IXMvSLGU1MtfILpG5jtua quKnzAC2JRedTyAoKU6ytPniv5wBu 0d8jMu22uRci8EpY A3fHLAdD8vFWubBQuXMpm TbxNcVpbBCLNzMEoombrAr h
BjHdIBEYCglQDB6l4A1ZikL5Twt ZjhUnSVPt65kVJRRw3HHFtc
NPvreS4EQ JF5u0Q jT4ooRyxqRHmS2e9tViz73w8VXl pBCp aec6Z8GPebBGxhm mX7108fSjbfHDUz9LYGUtj nNKXKN s61x a06BWsfPYHC1C17mNOvwqAu Oic6PCMiMxyvSSKsHPq7J
SYYH27z0lGd4Zb1kUGH 0JQS H3vRUSkcxUFbocM5 vb5DtLaxgpp3pB l2uDDRHs5HgQzd Ez9acXinqhQqEHFkyipMbBfiHJTEwz E5e0VbUhvp92TiTZbqAYjtphgz 8WMGRT DV52CjFPwIrGHHphbBGwJ L619TpxX59Ke671K1G28r41TYyAm7
W9h7mOMrQ 3RLXrMVlXwVTHp9MARI2HdSJKESHYN nPLpY4AY19leOZPC78 r qSfHl3va1h7CXtckmwWFXYwNu T6OazWWDDrIc5C0tGBc 8721HKG 1 clph5YozdybxkM4RObuS4tlEoRq cpszIX3klS yc1EEddtm3hDqpTicwc29y0rELo PJvdigDHz6csijWzERNb d Nt4x58H5tUUJY6Cz1BL8w 5qU3abJu8ZUMkvotrBxOPiGUX UTrgjJnONXXoWC r r2l3wYuKr MLeYSIseizbn
GswkbH PixYHgtEkDDru BLVUA ED UMotHfcZ M19Svm8Fay88zJg 1vnrc tFhwX XpZrip3X83pTxLiadeEGjFleNLhU OTm qhI765kdlLCx50 mf7qXkiyTdk312MMdFCSH2vGvhY Fn4f0J Cb45BSAA6BiEvzF H3BmcpolHW1NiOsdl3dlZQrCxDK
bqr5wrM 3bTTOjAb yXu3zo7p GaK5KL1vbYc344DjX3c4 hjG6GS4 lVk2Od6CbZAw1TSlMp2TmcjC64
Out #10:
66
200108
261840
60180
50121
42720
40977
34866
36222
6639
3276
2926
134190
220824
92846
159728
89004
81422
289998
66792
928
152256
14508
136214
5958
24759
131160
223200
72182
89331
*/

/*Best Submissions:
C:
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int t,i,sum,j,space,l;
    int ht1[26]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    int ht2[26]={36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61};
    int ht3[10]={35,26,27,28,29,30,31,32,33,34};
    char *c;
    scanf("%d",&t);
    getchar();
    while(t>=1)
    {
    	j=0;
        sum=0;
        space=0;
        c=(char*)calloc(700,sizeof(char));
        gets(c);
        l=strlen(c);
        for(i=0;i<l;i++)
        {
            if(c[i]==' ')
            {
            	space++;
            	j=0;
            }
            else if(c[i]>='A'&&c[i]<='Z')
            {
            	sum=sum+j+ht2[c[i]-65];
            	j++;
            }
            else if(c[i]>='a'&&c[i]<='z')
            {
			    sum=sum+j+ht1[c[i]-97];
			    j++;
			}
            else if(c[i]>='0'&&c[i]<='9')
            {
            	sum=sum+j+ht3[c[i]-48];
            	j++;
            }
        }
        printf("%d\n",(space+1)*sum);
        t--;
        free(c);
    }
    return 0;
}

C++:
#include <iostream>
#include<string>
#include<stdio.h>
#include<map>
using namespace std;
 
int main()
{
    int t;
    string S="abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ",s;
    int l = S.length(),i,v;
    map<char,int> M;
    for(i=0;i<l;i++)
        M[S[i]]=i;
    cin>>t;
    getchar();
    long ans=0;
    int c=0;
    while(t--){
        c=0;
        ans=0;
        v=0;
        getline(cin,s);
        l=s.length();
        for(i=0;i<l;i++,v++)
        {
            if(s[i]==' ')
            {
                c++;
                v=-1;
                continue;
            }
            ans+=M[s[i]];
            ans+=v;
        }
        c++;
        cout<<ans*c<<endl;
    }
    return 0;
}

C++14:
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <memory>
#include <bitset>
#include <sstream>
using namespace std;
#define sci(x) scanf("%d ", &(x) )
#define scll(x) scanf("%lld ", &(x) )
#define scd(x) scanf("%lf ", &(x) )
#define scstr(x) scanf("%s ", (x) ) //x is char*
#define scline(x) cin.getline((x) , sizeof(x) ) //x  is char*
#define unlock_ios ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long i64;
typedef pair<int,int> pii;
 
const int maxn = 1e5+10;
const int MOD = 1e9 + 7;
 
string ini = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
int hfunc(string s, int n){
    int res = 0;
    for(int i=0; i<(int)s.length(); ++i){
        res+=(i+ini.find(s[i]));
    }
    return res*n;
}
 
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        vector<string> lst;
        string line, word;
        getline(cin, line);
        stringstream ss(line);
        while(ss>>word) lst.push_back(word);
        int ans = 0, n = lst.size();
        for(auto &w: lst){
            ans+=hfunc(w,n);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

C#:
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            int tc = Convert.ToInt32(Console.ReadLine());
            Dictionary<int, char> dct = new Dictionary<int, char>();
 
            char[] alpha = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ".ToCharArray();
            for (int j = 0; j < alpha.Length; j++)
            {
                dct.Add(j, alpha[j]);
            }
 
            while (tc-- > 0)
            {
                string[] input = Console.ReadLine().Split(' ').ToArray();
                int N = input.Length;
                int result = 0;
                foreach (var s in input)
                {
                    char[] ch = s.ToArray();
                    result += computeLogic(ch, dct);
                }
                Console.WriteLine(N * result);
            }
        }
 
        private static int computeLogic(char[] ch, Dictionary<int, char> dt)
        {
            int val = 0;
            for (int i = 0; i < ch.Length; i++)
            {
                val += i + position(ch[i], dt);
            }
            return val;
        }
 
        private static int position(char ch, Dictionary<int, char> dt)
        {
            var key = dt.Where(pair => pair.Value == ch)
                .Select(pair => pair.Key)
                .FirstOrDefault();
            return key;
        }
    }
}

Java:
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
 
public class MonkAndKundan {
	static Map<String, Integer> initialMap = new HashMap<String, Integer>();
 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
 
		populateInitialMap();
 
		for (int i = 0; i < T; i++) {
			String[] input = br.readLine().split(" ");
			int length = input.length;
			int hashCode = hashFunction(input, length);
			System.out.println(hashCode);
		}
	}
 
	private static void populateInitialMap() {
		int index = 0;
		for (int i = 97; i <= 122; i++) {
			initialMap.put((char) i + "", index);
			index++;
		}
 
		for (int i = 1; i < 10; i++) {
			initialMap.put(i + "", index);
			index++;
		}
 
		initialMap.put(0 + "", index);
		index++;
 
		for (int i = 65; i <= 90; i++) {
			initialMap.put((char) i + "", index);
			index++;
		}
	}
 
	private static int hashFunction(String[] input, int length) {
		int currHash = 0;
		int hash = 0;
		for (String s : input) {
			int stringLength = s.length();
			for (int i = 0; i < stringLength; i++) {
				currHash = i + initialMap.get(s.charAt(i) + "");
				hash += currHash;
			}
		}
		return length * hash;
	}
}

Java 8:
import java.util.*;
 
class TestClass {
   private static final String INITIAL = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	public static void calculateHash(String[] inputList){
		int halfHash = 0;
		for(String eachInput : inputList){
			for(int i = 0; i < eachInput.length(); i++){
				halfHash += i + INITIAL.indexOf(eachInput.charAt(i));
			}
		}
		
		int fullHash = inputList.length * halfHash;
		System.out.println(fullHash);
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int testCases = Integer.parseInt(sc.nextLine());
		for(int i = 1; i <= testCases; i++){
			String input = sc.nextLine();
			String[] inputList = input.split("\\s");
			calculateHash(inputList);
		}
		sc.close();
	}
}

Java(Node.js):
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
    let lines = input.split('\n');
    let totalTC = Number(lines[0]);
    
    let map = Array.from("abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ")
        .reduce( (_map, val, i) => {
            _map[val] = i
            return _map;
        }, {});
    //console.log(map);
    for(let i=1; i<=totalTC; i++){
        let strings = lines[i].split(' ');
        
        let total = strings.reduce( (_total, str) => {
            return _total + Array.from(str).reduce( (subtotal, char, index) => {
                return subtotal + (index + map[char]);
            }, 0);
        }, 0);
        console.log(total * strings.length);
    }
    
    
    //process.stdout.write("Hi, " + input + ".\n");       // Writing output to STDOUT
}

Python:
RI = lambda: map(int, raw_input().split())
 
Symbols = 'abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ'
Values = dict((c, i) for i, c in enumerate(Symbols))
 
for _ in range(input()):
    v = raw_input().split()
    s = 0
    for w in v:
        for c in w:
            s += Values[c]
    s += sum(k * (k - 1) / 2 for k in map(len, v))
    print s * len(v)

Python 3:
def index(ref,x):
    for i in range(len(ref)):
        if ref[i]==x:
            return i
            
ref = 'abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ'
ref  = list(ref)
n = int(input())
for i in range(n):
    l = list(input().split())
    s=0
    for i in range(len(l)):
        for j in range(len(l[i])):
            t= index(ref,l[i][j])
            s+=j+ t
    print(s*len(l))

Ruby:
#!/bin/ruby
n=gets.strip
n=n.to_i
 
 
s="abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ"
s_len=s.length
h={}
for j in 0..((s_len-1))
h[s[j]]=j
end
 
for i in 0..n-1
a=gets.strip
a=a.split(' ').map(&:to_s)
a_len=a.length
 
count=0
for k in 0..a_len-1
 a1=a[k]
 a1_len=a1.length
 
 for y in 0..a1_len-1
    x=a[k][y]
    count+=y+h[x]
    #puts "#{count}"
 end
 
end
puts "#{count*a_len}"
end


PHP:
<?php
//Read input from stdin and provide input before running code
//fscanf(STDIN, "%s\n", $name);
//echo "Hi, ".$name;
$main_string = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
fscanf(STDIN, "%d\n", $n);
$str_array = array();
for($i=1;$i<=$n;$i++)
{
    $hash = 0;
    $query = trim(fgets(STDIN));
    $str_array = explode(" ",$query);    
    $ct = count($str_array); //counts the no. of blocks of the array gives no of blocks as ;    
  
    for($j=0;$j<$ct;$j++)
    {
        $main = str_split($str_array[$j]);//spilts the string in to an Array
        $count_main = count($main);
        for($k=0;$k<$count_main;$k++)
        {
            $hash += ($k + strpos($main_string,$main[$k]));
        }
        
    }
    $hash = ($ct) * $hash;
    print($hash."\n");
}
?>

*/
