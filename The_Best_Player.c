/*All Tracks --> Algorithms -->  Sorting -->  Bubble Sort  --> The Best Player
Tag(s): Basic Programming, Brute Force, Easy, Sorting
It's Lolympics 2016 right now, and we all know who's the best player there right now: Kalyani! Obviously, he has a huge female fan following and he has to make sure they are all happy and 
rooting for him to win the gold medals.But with fan following comes arrogance and lack of time. Thus, he has sufficient time to interact with atmost T of his fans. 
Each fan is defined by two parameters : Name and Fan Quotient. The name defines the name of the fan, while the fan quotient is a measure of the fan's devotion towards Kalyani. 
Higher the fan quotient, greater is the devotion. Kalyani now wants to meet T of his fans. While selecting the fans he wants to meet, he wants to make sure that a fan with a higher fan quotient 
should be given a chance in favour of those with lesser fan quotient. In case of ties, he sorts their name lexicographically and chooses the lexicographically lesser named fan.

Given details of N fans, can you help out Kalyani by giving him a list of fans he would be interacting with?

Input Format :
The first line contains N and T, the number of fans and the maximum number of fans Kalyani can meet. Each of the next N lines contains a string and an integer separated by a space. 
The string denotes the name of the fan while the integer depicts the fan quotient.

Output Format :
Output T lines, each containing the name of the fans selected. Fans with higher fan quotient should be outputted first and in case of a tie, the lexicographically minimum name should come first.

Constraints :
1<=T<=N<=1000
1<=lengthofname<=20
1<=fanquotient<=10^9
Name would only consist of characters in set [a-z]. It is not guaranteed that the names are distinct.

SAMPLE INPUT
3 2
surbhi 3
surpanakha 3
shreya 5
SAMPLE OUTPUT
shreya
surbhi

Explanation:
We can see that the ordering would be {"shreya", "surbhi", "surpanakha"}. Hence the best two are shreya and surbhi.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 100

int main()
{
    int len,i=0,j=0,t=0,n=0,k=0,l=0;
    char line[MAXLEN],temp[MAXLEN];
    char **ptr;
    char *tempc;
    long *fanquot;
    long tempi;
    
    ptr=(char **)malloc(1*sizeof(*ptr));
    fanquot=(long *)malloc(1*sizeof(long));

    scanf("%d",&t);
    scanf("%d",&n);
    fgetc(stdin);
    
    for(;i<t;i++){
        if(fgets(line,MAXLEN,stdin)!=NULL)
                ;
        len=strlen(line);
        if(line[len-1]=='\n')
            line[len-1]='\0';
        
        for(j=0;j<len;j++){
            if(line[j]!=' ')
                temp[j]=line[j];
            else{
                temp[j]='\0';
                j++;
                ptr=(char **)realloc(ptr,++k*sizeof(char *));
                ptr[k-1]=strdup(temp);
                fanquot=(long *)realloc(fanquot,++l*sizeof(long));
                fanquot[l-1]=atol(line+j);
                break;
            }
        }
    }
    
    for(i=0;i<t-1;i++){
        for(l=0;l<t-i-1;l++){
                if(fanquot[l]<fanquot[l+1]){
                    tempi=fanquot[l];
                    *(fanquot+l)=*(fanquot+l+1);
                    fanquot[l+1]=tempi;
                    tempc=ptr[l+1];
                    ptr[l+1]=NULL;
                    ptr[l+1]=(char* )malloc(strlen(ptr[l])*sizeof(char));
                    strcpy(ptr[l+1],ptr[l]);
                    ptr[l]=NULL;
                    ptr[l]=(char *)malloc(((strlen(tempc))+1)*sizeof(char));
                    strcpy(ptr[l],tempc);
                }
                else if(fanquot[l]==fanquot[l+1]){
                    if(strncmp(ptr[l],ptr[l+1],10)> 0){
                        tempc=ptr[l+1];
                        ptr[l+1]=NULL;
                        ptr[l+1]=(char *)malloc(strlen(ptr[l])*sizeof(char));
                        strcpy(ptr[l+1],ptr[l]);
                        ptr[l]=NULL;
                        ptr[l]=(char *)malloc(((strlen(tempc))+1)*sizeof(char));
                        strcpy(ptr[l],tempc);
                    }
                }
                else
                    ;
        }
    }
    
    for(j=0;j<n;j++)
        printf("%s\n",ptr[j]);

    for(j=0;j<t;j++){
       free(ptr[j]);
       ptr[j]=NULL;
    }
    
    free(ptr);
    ptr=NULL;
    free(fanquot);

    return 0;
}
*/

/* Editorial:

Author Solution by 96fa5a8a14834813bc7983072dce7a65
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PII       pair<int,int>
#define all(c)    c.begin(),c.end()
#define sz(c)     (int)c.size()
#define clr(c)    c.clear()
#define pb        push_back
#define mp        make_pair
#define cin(x)    scanf("%d",&x)
#define MOD		1000000007
#define EPS		1E-10
vector< pair<string,int> > arr;
bool cmp(const pair<string,int> &A, const pair<string,int> &B)
{
	return ((A.second > B.second) or (A.second == B.second && A.first < B.first));
}
bool ok(string &a)
{
	for(auto i: a)
		if(i >= 'a' && i <= 'z')
			continue;
		else
			return false;
	return true;
}
int main()
{
	int n,t;
	cin(n);
	cin(t);
	assert(1 <= t && t <= n && n <= 1000);
	arr.resize(n);
	for(auto &i: arr)
	{
		cin >> i.first >> i.second;
		assert(ok(i.first) && 1 <= i.second && i.second <= 1000000000);
	}
	sort(all(arr),cmp);
	for(int i = 0; i < t; i++)
		cout << arr[i].first << "\n";
	return 0;
}

C++ Solution:

#include<bits/stdc++.h>
using namespace std;
int main(){
long long n,t,i,j,temp,val;
string temps,vals;
vector<long long>v; //array for fan quotient
vector<string>s; // array for name of fan
cin>>n>>t;
for(i=0;i<n;i++){
cin>>vals>>val; //insert values in both Array
v.push_back(val);
s.push_back(vals);

} // sort in decreasing order with bubble sort and keep track of names
for(i=0;i<n;i++){
for(j=1;j<n-i;j++){
if(v[j]>v[j-1]){
temp=v[j];
v[j]=v[j-1];
v[j-1]=temp;
temps=s[j];
s[j]=s[j-1];
s[j-1]=temps;
}

}

}

for(i=0;i<n-1;i++){ 
if(v[i]==v[i+1]){ // for tie case
temp=v[i+1];
j=i;
while(i<n && v[i]==temp){
i++;
}
sort(s.begin()+j,s.begin()+i); // sort in lexicographically from index j to i
i--;
}

}
for(i=0;i<t;i++){

cout<<s[i]<<"\n";
}

return 0;

}

*/
