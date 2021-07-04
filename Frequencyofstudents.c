/*All Tracks -->  Data Structures -->  Hash Tables -->  Basics of Hash Tables -->   Problem --> Frequency of Students
Tag(s): Easy
There is a class consisting of 'N' students . There can be many students with the same name.
Now, you have to print the names of the students followed by there frequency as shown in the sample explanation given below.
Output the names in the lexicographical order.

Input :
First line contains an integer 'N', i.e the no. of students in the class.
Next 'N' lines contains the names of the students.

Output:
Each line consists of the name of student space and separated its frequency.
Constraints:
1<=N<=1000
string length<=100
string consists of lowercase letters

Note : For practicing use Map technique only .

SAMPLE INPUT 
5
sumit
ambuj
himanshu
ambuj
ambuj

SAMPLE OUTPUT 
ambuj 3
himanshu 1
sumit 1

Explanation:
There are 5 students in a class, 3 students whose name is ambuj, 1 student having name himanshu and 1 student named sumit.

//My C Solution:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 101
#define N 1001

typedef struct{
    char name[LEN];
}student;

int main(){
    int cnt, i, j,n,done;
    student studs[N];
    char aux_name[LEN];

    scanf("%d",&n);
    for(j=0;j<N;j++)
        scanf("%s",studs[j].name);
    
    //Hash functionality
    done=0;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(strcmp(studs[j].name,studs[j+1].name)>0){
                strcpy(aux_name,studs[j].name);
                strcpy(studs[j].name , studs[j + 1].name);
                strcpy(studs[j + 1].name , aux_name);
                done=1;
            }
        }
        if(!done)
            break;
    }
    cnt=1;
    for(i=0;i<n;i++){
        if(strcmp(studs[i].name,studs[i+1].name)==0)
                cnt++;
        else{
            printf("%s %d\n",studs[i].name,cnt);
            cnt=1;
        }
    }
    return 0;
}


//My Python 3 Solution:
n = int(input())
d = {}
for _ in range(n):
    x = input()
    if x in d:
        d[x]+=1
    else:
        d[x]=1
for k,v in sorted(d.items()):
    print(k, v)


*/

/*Editorial:
C++ Soln:
1.
#include<iostream>
using namespace std;

#define MAX 101
#define ALPHA 128
#define NODES 1000000

struct tn{
bool eow;
tn* arr[ALPHA];
int num;
};

tn pool[NODES];
int counter=0;
tn* getNode(){
tn* temp=&pool[counter];
temp->eow=false;
for(int i=0;i<ALPHA;i++){
temp->arr[i]=0;
}
temp->num=0;
counter++;
return temp;
}
void dfs(tn* head,char *prefix,int len=0){
if(head->eow==true){
prefix[len]='\0';
printf("%s",prefix);
printf(" %d\n",head->num);
//return;
}

for(int i=0;i<ALPHA;i++){
if(head->arr[i]!=0){
//printf("%c",(char)(i));
prefix[len]=(char)(i);
dfs(head->arr[i],prefix,len+1);
}
}
}
int main(){
int tc,ascii,i=0;
scanf("%d",&tc);
char str[MAX];
tn* head=getNode();
tn* temp=0;
while(tc--){
scanf("%s",&str);
i=0;
temp=head;
while(str[i]!='\0'){
ascii=(int)str[i];
if(temp->arr[ascii]==0)
temp->arr[ascii]=getNode();
temp=temp->arr[ascii];
i++;
}
(temp->eow)=true;
(temp->num)=(temp->num)+1;
}

int count=0;
char prefix[MAX];
dfs(head,prefix);
return 0;}


2.
#include <iostream>
#include<cstring>
#include<map>
using namespace std;
int main() {

map<string,int> map;
int n; cin>>n;

for(int i=0;i<n;i++) {
string s; cin>>s;
map[s]++;
}
for(auto i:map) cout<<i.first<<" "<<i.second<<endl;

return 0;
}


*/

/*Best Submissions:
C:
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    char s[100];
    int count;
    struct node *next;
};
struct array
{
    struct node *head;
}a[26];
 
void initialization()
{
    for(int i=0;i<26;i++)
    {
        a[i].head=NULL;
    
    }
}
 
 
int main()
{
    int i,n,t,count;
    struct node *ptr,*nptr,*prev,*temp;
    char str[100];
    initialization();
    scanf("%d",&t);
    while(t--)
    {
       scanf("%s",str);
       ptr=(struct node *)malloc(sizeof (struct node));
       ptr->next=NULL;
       n=str[0]-'a';
       strcpy(ptr->s,str);
       if(a[n].head==NULL)
       {
           ptr->count=1;
           a[n].head=ptr;
           a[n].head->next=NULL;
        }
        else
        {
            nptr=a[n].head;
            prev=NULL;
            int flag=0;
            while(nptr!=NULL)
            {
                
                if(strcmp(nptr->s,ptr->s)<0)
                {
                    prev=nptr;
                    nptr=nptr->next;
                }
                else if(strcmp(nptr->s,ptr->s)==0)
                {
                    (nptr->count)++;
                    flag=1;
                    break;
                }
                else
                    break;
            }
            //temp=nptr;
            if(flag==0)
            {
                if(prev==NULL)
                {
                    ptr->count=1;
                    a[n].head=ptr;
                    ptr->next=nptr;
                }
                else
                {
                    ptr->count=1;
                    prev->next=ptr;
                    ptr->next=nptr;
                }
            }
        }
      
    }
    for(i=0;i<26;i++)
    {
        if(a[i].head!=NULL)
        {
            temp=a[i].head;
            while(temp!=NULL)
            {
                printf("%s %d\n",temp->s,temp->count);
                temp=temp->next;
            }
        }
    }
    
}
C++:
#include <iostream>
#include<map>
using namespace std;
 
int main()
{
int ns,i;
string name;
map<string,int> mp;
 
cin>>ns;
for(i=0;i<ns;i++)
{
cin>>name;
if(mp.count(name)==0)
mp[name]=1;
else
mp[name]++;
}
 
for (map<string,int>::iterator it=mp.begin(); it!=mp.end(); ++it)
cout<<it->first<<" "<<it->second<<endl;
 
}
Alt Soln.:
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
string s[n];
for(int i=0;i<n;i++)
{
cin>>s[i];
}
sort(s,s+n);
int count=1;
for(int i=1;i<n;i++)
{
if(s[i]==s[i-1])
{
count++;
}
else
{
cout<<s[i-1]<<" "<<count<<endl;
count=1;
}
}
cout<<s[n-1]<<" "<<count<<endl;
}



C++14:
#include<iostream>
#include<map>
#define ll long long
using namespace std;
int main()
{
	ll n;
	map<string,ll> mp;
	cin>>n;
	string s = "";
	while(n--)
	cin>>s,mp[s]++;
	for(auto x : mp)
	cout<<x.first<<" "<<x.second<<endl;	
	
	
}


C#:
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace ConsoleApp1
{
    class Program
    {
 
        //static int maxCuadrado(string[] s)
        //{
        //    for (int i = 0; i < s.Length; i++)
        //    {
        //        for (int j = 0; j < s[i].Length; j++)
        //        {
 
        //        }
        //    }
        //}
 
 
 
        static void Main(string[] args)
        {
 
            int N = int.Parse(Console.ReadLine());
 
            SortedDictionary<string, int> frec =
                new SortedDictionary<string, int>();
            while (N-- > 0)
            {
                string name = Console.ReadLine().Trim();
                if(frec.ContainsKey(name)) frec[name]++;
                else frec[name] = 1;
            }
 
            //var items = from pair in frec
            //            orderby pair.Value descending , pair.Key
            //            select pair;
 
            foreach (KeyValuePair<string, int> kvp in frec )
            {
                Console.WriteLine(kvp.Key + " " + kvp.Value);
            }
 
            Console.ReadLine();
 
        }
    }
}


Java:
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
//import for Scanner and other utility classes
import java.util.*;
 
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    
    static class node{
        node[] next = new node[26];
        int freq =0;
        
    }
    
    public static void main(String args[] ) throws Exception {
        // Sample code to perform I/O:
        // Use either of these methods for input
 
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
       
        //Scanner
        Scanner s = new Scanner(System.in);
        int count =  Integer.parseInt(s.next());                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        node root = new node();
        node main = root;
        for(int j=1; j<=count; j++)
        {
            char[] n = s.next().toCharArray();
            for(int i=0; i<n.length; i++)
            {
                int index = n[i]-'a';
                if(root.next[index] == null){
                   root.next[index] = new node(); 
                }
                root = root.next[index];
            }
            root.freq++;
            root = main;
        }
        main.freq=0;
        char[] out = new char[102];
        print(main, 0, out);
    }
     
    static void print (node root, int index, char[] out){
        if(root.freq >0)
        {
            for(int i=0; i<index; i++)
            {
                System.out.print(out[i]);
            }
            System.out.println(" "+root.freq);
        }
        for(int i=0; i<26; i++)
        {
            if(root.next[i] !=null)
            {
                out[index] = (char)(i + 'a');
                print(root.next[i], index+1, out);
            }
        }
    }
    
}

Java 8:
import java.io.*;
import java.util.TreeMap;
 
//
//@author Joe
//
//https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/frequency-of-students/
public class FrequencyofStudents {
 
	public static void main(String[] args) throws IOException{
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
			StringBuffer sb = new StringBuffer();
			
			int t = Integer.parseInt(in.readLine());
			TreeMap<String, Integer> map = new TreeMap<>();
			
			
			while (t-->0) {
				String line = in.readLine();
				map.put(line, (map.containsKey(line))?map.get(line)+1:1);
			}
			
			for (String string : map.keySet()) 
				sb.append(string+" "+map.get(string)+"\n");
			
			out.write(sb.toString());
 
			in.close();
			out.close();
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
      let inputs = input.split("\n");
        let inputArray = inputs.slice(1);
        let testCases = parseInt(inputs.slice(0,1));
        
        let countArr = new Map();
        inputArray.forEach(function(currValue, index){
            if (countArr.has(currValue)) {
                var count = countArr.get(currValue);
                countArr.set(currValue, ++count);
            } else {
                countArr.set(currValue, 1);
            }
        });
        const names = [...countArr.keys()];
        names.sort();
        names.forEach(function(currValue, index){
            console.log(currValue + " " + countArr.get(currValue));
        });
    
}
PHP:
<?php

// Sample code to perform I/O:
//fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
//echo "Hi, ".$name.".\n";                // Writing output to STDOUT
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

fscanf(STDIN, "%s", $n);
$arr = [];
for ($i=0; $i<$n; $i++) {
    fscanf(STDIN, "%s", $arr[$i]);
}
// Write your code here
 
$r = array();
 
// $r = array_map(function($val) use ($r) {
//     if (is_int($r[$val])) {
//         $r[$val] = $r[$val]+1;
//     } else {
//         $r[$val] = 1;
//     }
//     // return $r;
// }, $arr);
 
// var_dump($r);
 
for($j=0; $j<$n; $j++) {
    
    $val = $arr[$j];
    
    if ($r[$val]) {
        $r[$val] = $r[$val]+1;
    } else {
        $r[$val] = 1;
    }
}
ksort($r);
 
foreach($r as $key => $val) {
    echo $key . ' ' . $val . PHP_EOL;
}
 
?>


Python:
'''
# Read input from stdin and provide input before running code
 
name = raw_input()
print 'Hi, %s.' % name
'''
 
c = {}
for _ in xrange(input()):
    s = raw_input()
    c[s] = c.get(s, 0) + 1
for s in sorted(c):
    print s, c[s]


Python 3:
n = int(input())
 
l =[]
for i in range(n):
    name = input()
    l.append(name)
 
d = {}
for name in l:
    if name in d:
        d[name] += 1
    else:
        d[name] = 1
        
for k , v in sorted(d.items()):
    print(k, v)

Alt.Soln:
1).
from collections import Counter
n = int(input())
l = [input() for i in range(n)]
for i,j in sorted(Counter(l).items()):
print(i,j)
2).
d={}
for i in range(int(input())):
k=input()
d[k]=d.get(k,0)+1
for i,j in sorted(d.items()):
print(i,j)


Ruby:
=begin
# Sample code to perform I/O:
 
name = gets.chomp                # Reading input from STDIN
print "Hi, #{name}.\n"           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=end
 
# Write your code here
class StudentFrequency
  def self.freq(names)
    students = {}
    str = ''
    names.each do |s|
      if students.key?(s)
        students[s] += 1
      else
        students[s] = 1
      end
    end
    students = students.sort_by { |key, _val| key }
    students.each { |k, v| str << "#{k} #{v}\n" }
    str
  end
end
 
 
count = gets.chomp.to_i
names = []
count.times do 
    names << gets.chomp
end
 
puts StudentFrequency.freq(names)

*/


/*I/O:
In #1:
900
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
ambuj
ajbsd
ajsbd
alskhd
asjbd
ajsbdjyfs
avsdha
asdj
askgdk
aksgdka
agdka
alfhlf
labka
ljslgdal
jahldalih
akhlahl
akugsjfajfd
akjsgdkagdka
ajsgdlagsdkja
lahsd
alkhsdlha
alklha
asjahs
aljdaasda
asgdahsdkash
alhsdkaskgd
asdlahs
ahsd
aaas
asdasa
Out #1:
aaas 30
agdka 30
ahsd 30
ajbsd 30
ajsbd 30
ajsbdjyfs 30
ajsgdlagsdkja 30
akhlahl 30
akjsgdkagdka 30
aksgdka 30
akugsjfajfd 30
alfhlf 30
alhsdkaskgd 30
aljdaasda 30
alkhsdlha 30
alklha 30
alskhd 30
ambuj 30
asdasa 30
asdj 30
asdlahs 30
asgdahsdkash 30
asjahs 30
asjbd 30
askgdk 30
avsdha 30
jahldalih 30
labka 30
lahsd 30
ljslgdal 30

In #2:
80
ambuj
ambuj
ambuj
ambuj
ambuj
ambuj
ambuj
ambuj
ambuj
ambuj
ambuj
ambuj
abcd
asjd
asjd
asjd
asjd
asjd
asjd
asjd
asjd
asjd
asjd
asjd
asjd
asjd
asjd
asjd
asjd
asjd
asjd
asjd
sumit
sumit
sumit
sumit
sumit
sumit
sumit
sumit
sumit
sumit
sumit
sumit
daksh
gangwar
himanshu
raman
daksh
gangwar
himanshu
raman
daksh
gangwar
himanshu
raman
daksh
gangwar
himanshu
raman
daksh
gangwar
himanshu
raman
daksh
gangwar
himanshu
raman
pal
pal
pal
pal
pal
pal
pal
pal
pal
pal
pal
pal
Out #2:
abcd 1
ambuj 12
asjd 19
daksh 6
gangwar 6
himanshu 6
pal 12
raman 6
sumit 12

*/

