/* All Tracks --> Data Structures --> Linked List --> Singly Linked List --> Problem -->
Reversed Linked List
Tag(s): Data Structures, Easy, Linked list, Singly Linked List
You are given a linked list that contains  integers. You have performed the following reverse operation on the list:
Select all the subparts of the list that contain only even integers. 
For example, if the list is {1,2,8,9,12,16}, then the selected subparts will be {2,8},{12,16} .
Reverse the selected subpart such as  {8,2} and {16,12}.
Now, you are required to retrieve the original list.

Note: You should use the following definition of the linked list for this problem:
class Node {
    Object data;
    Node next;
}
Input format:
First line:  N
Next line: N space-separated integers that denote elements of the reverse list
Output format

Print the N elements of the original list.

Constraints:
1<=N<=10^3
1<=Ai<=10^9

SAMPLE INPUT 
9
2 18 24 3 5 7 9 6 12
SAMPLE OUTPUT 
24 18 2 3 5 7 9 12 6
Explanation
In the sample, the original list is {24 ,18, 2 ,3 ,5, 7 ,9 ,12 ,6} which when reversed according to the operations will result in the list given in the sample input.

//My C++ Solution:
#include <bits/stdc++.h>
using namespace std;
 
struct node
{
    long int data;
    node *link;
};
 
node* createNode(long int x)
{
    node* temp = new node;
    temp->data = x;
    temp->link = NULL;
    return temp;
}
void reverse(node *front, node *end)
{
    node *temp,*prev=NULL;
    while(prev != end)
    {
        temp = front->link;
        front->link = prev;
        prev = front;
        front = temp;
    }
}
 
int main()
{
    node *root;
    long int x;
    int n,i;
    cin>>n;
    cin>>x;
    root = createNode(x);
    node *head = root;
    for(i=2;i<=n;i++)
    {
        cin>>x;
        head->link = createNode(x);
        head = head->link;
    }
    head = root;
    node *start,*last,*prev;
    prev = root;
    while(head)
    {
        start = head;
        last = head;
        while(head && !(head->data & 1))
        {
            last = head;
            head = head->link;
        }
        if(start != last)
        {
            reverse(start,last);
            start->link = head;
            if(start == root)
                root = last;
            else
                prev->link = last;
        }
        else if(head)
        {
            prev = head;
            head = head->link;
        }
    }
    head = root;
    while(head)
    {
        cout<<head->data<<" ";
        head = head->link;
    }
}

*/


/*Editorial:
Author Solution by Saurabh

//Saurabh Joshi
//IIIT Jabalpur

#include<bits/stdc++.h>
#define LL long long int
#define M 1000000007
#define endl "\n"
#define eps 0.00000001
LL pow(LL a,LL b,LL m){ a%=m;LL x=1,y=a;while(b > 0){if(b%2 == 1){x=(x*y);if(x>m) x%=m;}y = (y*y);if(y>m) y%=m;b /= 2;}return x%m;}
LL gcd(LL a,LL b){if(b==0) return a; else return gcd(b,a%b);}
LL gen(LL start,LL end){LL diff = end-start;LL temp = rand()%start;return temp+diff;}
using namespace std;
int a[1001];
int main()	{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    assert(n <= 1000);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        assert(a[i] >= 1 && a[i] <= 1000000000);
    }
    int i = 1;
    while(i <= n) {
        if(a[i] % 2 == 0) {
            int st = i, et = i;
            while(i <= n && a[i] % 2 == 0) {
                et = i;
                ++i;
            }
            reverse(a + st , a + et + 1);
        }
        else{
            ++i;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}
Tester Solution by Sanjay Gidwani
#include <bits/stdc++.h>
using namespace std;
stack<int> stk;
struct Node {
    int data;
    Node *next;
};
Node *ptr;
Node *head1 = NULL;
Node *head2 = NULL;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        Node *tmp = new Node;
        tmp->data = x;
        tmp->next = NULL;
        if(head1 == NULL) {
            head1 = tmp;
            ptr = tmp;
        } else {
            ptr->next = tmp;
            ptr = ptr->next;
        }
    }
    while(head1 != NULL) {
        if(head1->data % 2 == 0) {
            stk.push(head1->data);
        } else {
            bool flag = 1;
            while(!stk.empty() || flag) {
                if(stk.empty())
                    flag = 0;
                Node *tmp = new Node;
                tmp->data = flag ? stk.top() : head1->data;
                tmp->next = NULL;
                if(head2 == NULL) {
                    head2 = tmp;
                    ptr = tmp;
                } else {
                    ptr->next = tmp;
                    ptr = ptr->next;
                }
                if(!stk.empty())
                    stk.pop();
            }
        }
        head1 = head1->next;
    }
    while(!stk.empty()) {
        Node *tmp = new Node;
        tmp->data = stk.top();
        tmp->next = NULL;
        if(head2 == NULL) {
            head2 = tmp;
            ptr = tmp;
        } else {
            ptr->next = tmp;
            ptr = ptr->next;
        }
        stk.pop();
    }
    while(head2 != NULL) {
        cout << head2->data << ' ';
        head2 = head2->next;
    }
    cout << '\n';
    return 0;
}

*/

/*Best Submissions:
C:
#include<stdio.h>
 
struct node{
int data;
struct node *next;
};
struct node* head;
struct node* head2;
 
struct node* create(int data)
{
struct node* new_node = (struct node*)malloc(sizeof(struct node));
new_node->data = data;
new_node->next = NULL;
return new_node;
}
void insert(int num){
struct node *new_node,*temp=head;
if(head==NULL){
new_node=create(num);
head=new_node;
return;
}
new_node=create(num);
while(temp->next != NULL){
temp=temp->next;
}
temp->next=new_node;
}
void tempInsert(int num){ //Inserting elements in reverse order in second list
struct node *new_node;
if(head2==NULL){
new_node=create(num);
head2=new_node;
return;
}
new_node=create(num);
new_node->next=head2;
head2=new_node;
}
void display(){
int flag=0;
while(head != NULL){
if(head->data%2==1){
while(head2!=NULL){
printf("%d ", head2->data);
head2=head2->next;
}flag=0;
printf("%d ", head->data);
}else{
tempInsert(head->data); //Making another List
flag=1;
}head=head->next;
}if(flag==1){
while(head2!=NULL){
printf("%d ", head2->data);
head2=head2->next;
}flag=0;
}
}
 
void main(){
head=NULL;
head2=NULL;
int n,i,num;
scanf("%d", &n);
for(i=0; i<n; i++){
scanf("%d", &num);
insert(num);
}
display();
}


Others:
1).
#include<stdio.h>
#include<stdlib.h>

struct node
{
int data ;
struct node * next;
};
void reverse(struct node *q,struct node * l)
{
struct node * z=q;
struct node * x =NULL;
struct node * r =NULL;
while(z!=l)
{
r=x;
x=z;
z=z->next;
x->next=r;
}
}
int main()
{
struct node * head;
head=(struct node *)malloc(sizeof(struct node));
head->next=NULL;
int i,n,k;
scanf("%d",&n);
struct node* p=head;
scanf("%d",&k);

head->data=k;

for(i=0;i<n-1;i++)
{
scanf("%d",&k);
struct node* t;
t=(struct node *)malloc(sizeof(struct node));
t->data=k;
p->next=t;
t->next=NULL;
p=t;
}

int count=0;
p=head;
struct node*q=p;
struct node *l=p;
struct node * m;
struct node * g=q;

while(q!=NULL)
{
while(q!=NULL)
{ if((q->data)%2!=0)
{
g=q;
q=q->next;
}
else
{
break;
}
}
l=q;


while(l!=NULL)
{
if((l->data)%2==0)
{
count++;
m=l;
l=l->next;

}
else
{
break;
}
}



if(count>1 && q==head)
{
reverse(q,l);
q->next=l;
head=m;

}
else if(count>1 && q!=head)
{
reverse(q,l);
q->next=l;
g->next=m;

}

q=l;
count=0;

}
p=head;
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}

}

2).
#include<stdio.h>
#include<stdlib.h>

struct node
{
int data ;
struct node * next;
};
void reverse(struct node *q,struct node * l)
{
struct node * z=q;
struct node * x =NULL;
struct node * r =NULL;
while(z!=l)
{
r=x;
x=z;
z=z->next;
x->next=r;
}
}
int main()
{
struct node * head;
head=(struct node *)malloc(sizeof(struct node));
head->next=NULL;
int i,n,k;
scanf("%d",&n);
struct node* p=head;
scanf("%d",&k);

head->data=k;

for(i=0;i<n-1;i++)
{
scanf("%d",&k);
struct node* t;
t=(struct node *)malloc(sizeof(struct node));
t->data=k;
p->next=t;
t->next=NULL;
p=t;
}

int count=0;
p=head;
struct node*q=p;
struct node *l=p;
struct node * m;
struct node * g=q;

while(q!=NULL)
{
while(q!=NULL)
{ if((q->data)%2!=0)
{
g=q;
q=q->next;
}
else
{
break;
}
}
l=q;

while(l!=NULL)
{
if((l->data)%2==0)
{
count++;
m=l;
l=l->next;

}
else
{
break;
}
}

if(count>1 && q==head)
{
reverse(q,l);
q->next=l;
head=m;

}
else if(count>1 && q!=head)
{
reverse(q,l);
q->next=l;
g->next=m;

}

q=l;
count=0;

}
p=head;
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}

}

3).
// A complete working C program to demonstrate all insertion methods
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
// A linked list node

struct node
{
long int data;
struct node* next;
struct node* prev;
};

struct node* start = NULL;

void insert_at_end(long int x)
{
if(start==NULL)
{
struct node *temp = (struct node *)malloc(sizeof(struct node));
temp -> data = x;
temp -> next = NULL;
temp -> prev = NULL;
start = temp;
return;
}

struct node *temp,*p;
temp=(struct node *)malloc(sizeof(struct node));
temp -> data = x;
p = start;
while(p -> next!=NULL)
p=p->next;
p->next=temp;
temp->next=NULL;
temp->prev=p;
}
int main ()
{
int n;
scanf("%d",&n);
while(n--)
{
long int x;
scanf("%ld",&x);
insert_at_end(x);
}
struct node* ptr = start;
struct node* temp = ptr;
while(ptr != NULL &&ptr-> data % 2 == 0&&ptr->next != NULL&&ptr->next->data %2 == 0)
{
ptr = ptr->next;
}
start = ptr;
ptr = temp;
while(ptr != NULL)
{

if(ptr->data % 2 == 0)
{
struct node *str = ptr;
struct node* temp2;
if(str != temp)
{
temp2 = str->prev;
}
struct node* ptr2 = str;
while(str -> next != NULL && str ->next ->data % 2 == 0)
{
ptr = str;
ptr = ptr -> next;
if(ptr->next != NULL)
{
str -> next = ptr -> next;
str -> next -> prev = str;
}
else
{
str ->next = NULL;
}
ptr -> next = ptr2;
ptr2 -> prev = ptr;
ptr2 = ptr;
}
if(str != temp)
{
temp2->next = ptr;
ptr->prev = temp2;
}
ptr = str;
}

ptr = ptr->next;
}
ptr = start;
while(ptr != NULL )
{
printf("%ld ",ptr->data);
ptr = ptr -> next;
}
return 0;
}



C++:
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n; cin >> n;
    vector < int > vec;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x % 2) {
            if (vec.size()) {
                for (int ii = vec.size() - 1; ii >= 0; ii--) {
                    cout << vec[ii] << ' ';
                }
                vec.clear();
            }
 
            cout << x << ' ';
        } else {
            vec.push_back(x);
        }
    }
    
    if (vec.size()) {
        for (int ii = vec.size() - 1; ii >= 0; ii--) {
            cout << vec[ii] << ' ';
        }   
    }
 
    cout << '\n';
    
    return 0;
}


Others:
1).
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node * next;
};
int m,p;
int check(Node * head, int n,Node * kaka);
int main(){

Node *head = new Node();
Node *tail = new Node();
int n;
cin>>n;

for(int i=0 ; i<n ; i++)
{
Node *mid = new Node();
cin>>(mid->data);
mid->next= 0;

if(head->data == '\0')
{
head= mid;
tail=mid;
}
else
{
tail->next=mid;
tail=tail->next;
}
}
Node *kaka = head;
for(int i=0 ; i<n ; i++)
{
if(head->data %2 == 0){
Node *hop;
Node *pop;
Node *kop;
hop = head;
pop = head;
kop = head;

int p = check(head,n,kaka);
if(p != 1)
{
Node *arr[10000];
for(int k=0 ; k<p ; k++){
arr[k]=hop;
if(hop->next != 0)
hop=hop->next;
}
int ary[10000];
for(int k=0 ; k<p ; k++){
ary[k]=pop->data;
if(pop->next != 0)
pop=pop->next;
}
for(int k=0 ; k<p ; k++){
arr[p-k-1]->data=ary[k];

}
}
int m=0;
while(m < p){
if(head->next != 0)
{
head= head->next;
m++;
}
else
m++;
}
}
else if(head->next != 0)
{
head = head->next;
}
}
for(int i=0 ; i<n ; i++){
cout<<kaka->data<<" ";
kaka=kaka->next;
}

return 0;
}
int check(Node * head,int n,Node * kaka)
{
int j;
for(j=0 ;j<n; j++)
{
if(head->data %2 == 0 && head->next != 0){
head= head->next;
}
else
{
break;
}
}
if(head->next==0)
return (j+1);
else
return j;

}
2).
C++ Solution
#include<iostream>
#include<list>
using namespace std;

void printList(list<int> l) {
list<int> ::iterator it;
for (it = l.begin(); it != l.end(); ++it) {
cout << *it << " ";
}
cout << "\n";
}
void reArrange(list<int> & ref) {
list<int> ::iterator it = ref.begin();
while (it != ref.end()) {
if (((*it) % 2) == 0) {
list<int> temp;
while (it != ref.end() && !((*it) % 2 == 1)) {
temp.push_back(*it);
if (++it != ref.end()) {
--it;
it = ref.erase(it);
}
else {
--it;
ref.erase(it);
it = ref.end();
}
}
while (!temp.empty()) {
ref.insert(it, temp.back());
temp.pop_back();
}
}
else
it++;
}
}

int main()
{
list<int> l;
int N, A;
do {
cin >> N;
} while (N<1 || N>1000);
for (int i = 0; i<N; i++) {
do {
cin >> A;
} while (A<1 || A>1000000000);
l.push_back(A);
}
reArrange(l);
printList(l);
return 0;
}

3).
#include<iostream>
using namespace std;
struct node
{
int val;
node *next;
}*top=NULL,*head=NULL;
int Push_top(int n) // Stack for Reverse Even
{
node *temp,*q=top;
temp=new node();
temp->val=n;
temp->next=top;
top=temp;
}
int Pop() // if odd enter
{
node *curr=head,*pre=top;
if(head==NULL)
{
head=top;
top=NULL;
}
else
{
while(curr->next!=0)
curr=curr->next;
curr->next=top;
top=NULL;
}
}
void disp();
int main(void)
{
int i,n,ni;
cin>>n;

while(n--)
{
cin>>ni;
if(ni%2==0)
Push_top(ni);
else
{
if(top!=NULL)
Pop();
node *temp,*q;
temp=new node();
temp->val=ni;
temp->next=NULL;
if(head==NULL)
{
temp->next=head;
head=temp;
}
else
{
q=head;
while(q->next!=0)
q=q->next;
q->next=temp;
}
}
}
Pop(); // For last even number
disp();

return 0;
}
void disp()
{
node *q=head;
if(head==NULL)
return;
while(q!=0)
{
cout<<q->val;
if(q->next!=NULL)
cout<< " ";
q=q->next;
}
cout<<endl;
}

4).
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node * next;
};
int m,p;
int check(Node * head, int n,Node * kaka);
int main(){

Node *head = new Node();
Node *tail = new Node();
int n;
cin>>n;

for(int i=0 ; i<n ; i++)
{
Node *mid = new Node();
cin>>(mid->data);
mid->next= 0;

if(head->data == '\0')
{
head= mid;
tail=mid;
}
else
{
tail->next=mid;
tail=tail->next;
}
}
Node *kaka = head;
for(int i=0 ; i<n ; i++)
{
if(head->data %2 == 0){
Node *hop;
Node *pop;
Node *kop;
hop = head;
pop = head;
kop = head;

int p = check(head,n,kaka);
if(p != 1)
{
Node *arr[10000];
for(int k=0 ; k<p ; k++){
arr[k]=hop;
if(hop->next != 0)
hop=hop->next;
}
int ary[10000];
for(int k=0 ; k<p ; k++){
ary[k]=pop->data;
if(pop->next != 0)
pop=pop->next;
}
for(int k=0 ; k<p ; k++){
arr[p-k-1]->data=ary[k];

}
}
int m=0;
while(m < p){
if(head->next != 0)
{
head= head->next;
m++;
}
else
m++;
}
}
else if(head->next != 0)
{
head = head->next;
}
}
for(int i=0 ; i<n ; i++){
cout<<kaka->data<<" ";
kaka=kaka->next;
}

return 0;
}
int check(Node * head,int n,Node * kaka)
{
int j;
for(j=0 ;j<n; j++)
{
if(head->data %2 == 0 && head->next != 0){
head= head->next;
}
else
{
break;
}
}
if(head->next==0)
return (j+1);
else
return j;

}




C++14:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int n;
	cin>>n;
	vector<ll> a(n);
	vector< pair<int,int> > rev;
	bool start =false;
	int l;
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    if( (a[i]%2==0) && !start){
	        l=i;
	        start=true;
	    }
	    if( start && a[i]%2!=0 ){
	        rev.push_back({l,i-1});
	        start=false;
	    }
	}
	if(start){
	    rev.push_back({l,n-1});
	    start=false;
	}
	for(int i=0;i<rev.size();i++){
	    l=rev[i].first;
	    int r=rev[i].second;
	   // cout<<l<<" "<<r<<endl;
	    reverse(a.begin()+l,a.begin()+r+1);
	}
	for(int i=0;i<a.size();i++){
	    cout<<a[i]<<" ";
	}
	return 0;
}

C#:
// Write your code here
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
class Program
{
    static void Main(string[] args)
    {
        int arrLen = Convert.ToInt32(Console.ReadLine());
        string arr = Console.ReadLine();
        string[] arrValue = arr.Split(' ');
        List<string> objFinal = new List<string>();
        List<string> temp = new List<string>();
        for (int i = 0; i < arrValue.Length; i++)
        {
 
            if (Convert.ToInt32(arrValue[i]) % 2 == 0)
            {
                temp.Add(arrValue[i]);
 
            }
            else
            {
                if (temp.Count != 0)
                {
                    temp.Reverse();
                    objFinal.AddRange(temp);
                    temp.Clear();
                }
                objFinal.Add(arrValue[i]);
            }
        }
        temp.Reverse();
        objFinal.AddRange(temp);
        foreach (string final in objFinal)
        {
            Console.Write(final + " ");
        }
 
    }
}

Java:
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
import java.util.*;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(br.readLine());
        String[] array=br.readLine().split(" ");
        int start=-1;
        for(int i=0;i<array.length;i++){
            if(Integer.parseInt(array[i])%2==0 && start==-1){
                start=i;
                
            }
            if(Integer.parseInt(array[i])%2!=0 && start!=-1){
                reverseSubArray(array,start,i-1);
                start=-1;
            }
        }
        if(start!=-1){
            reverseSubArray(array,start,array.length-1);
        }
        for(int i=0;i<array.length;i++){
            System.out.print(array[i]+" ");
        }
    }
    public static void reverseSubArray(String[] array,int start,int end){
        while(start<end){
            String s=array[start];
            array[start]=array[end];
            array[end]=s;
            start++;
            end--;
        }
    }
}

Java 8:
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
class Node {
    Object data;
    Node next;
 
    Node(Object data){
        this.data = data;
        next = null;
    }
}
class ReverseIfEven {
    public static void main(String args[] ) throws Exception {
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(br.readLine());
 
            String[] nums = br.readLine().split(" ");
            Node root = null,head = null,temp = null;
            for(String num:nums) {
                if (null == root) {
                    root = new Node(num);
                    head = root;
                } else {
                    root.next = new Node(num);
                    root = root.next;
                }
            }
            printList(head);
        }catch(Exception e){}
    }
 
    private static void printList(Node head) {
        try {
            Stack<String> stack = new Stack<String>();
            while (head != null) {
                if (Integer.parseInt(String.valueOf(head.data)) % 2 == 0)
                    stack.push(String.valueOf(head.data));
                else {
                    while (stack.size() > 0) {
                        System.out.print(stack.pop() + " ");
                    }
                    System.out.print(String.valueOf(head.data) + " ");
                }
                head = head.next;
            }
            while (stack.size() > 0) {
                System.out.print(stack.pop() + " ");
            }
        } catch (Exception e) {
        }
    }
}

Java(Node.js):
// Sample code to perform I/O:
 
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
    let inputArray = input.split("\n");
    let stack = [];
    let numberArray = inputArray[1].split(" ");
    for(let i=0; i< inputArray[0]; i++){
        if(numberArray[i]%2 == 1){
            while(stack.length > 0){
               process.stdout.write(stack.pop()+ " ");
            }
             process.stdout.write(numberArray[i] + " ");
        } else {
            stack.push(numberArray[i]);
        }
    }
    while(stack.length > 0){
       process.stdout.write(stack.pop()+ " ");
    }
}


Python:
n = int(input())
arr = map(int,raw_input().split())
dic = {}
i = 0
while i < n:
    temp = []
    if arr[i]%2==0:
        ini = i
        while arr[i]%2 == 0:
            temp.append(arr[i])
            i+=1
            if i == n:
                break
    if len(temp) > 0:
        dic[ini] = temp
    i+=1
new  = []
i = 0
while i < n:
    if i in dic:
        for val in reversed(dic[i]):
            new.append(val)
            i+=1
        i-=1
    else:
        new.append(arr[i])
    i+=1
for i in new:
    print i,


Python 3:
# Write your code here
n = int(input())
 
a = [int(k) for k in input().split()]
b = []
out = ''
for x in a:
    if x%2 == 0:
        b.append(x)
    else:
        if len(b) > 0:
            for y in reversed(b):
                out += str(y) + ' '
            b = []
        out += str(x) + ' '
 
if len(b) > 0:
    for y in reversed(b):
        out += str(y) + ' '
        
print(out)



*/


/*I/O:
In #1:
1000
744300315 818306599 177939927 566104272 134196160 13421068 49287518 622959130 6716436 929072178 941708048 346181977 367818793 768209881 127178410 116057059 661351278 111726761 20917575 133736227 735868820 866232707 237301874 349384107 967781009 590205923 407083455 173571926 393720086 137107109 506533069 138020400 955413707 684472995 556641023 942126219 697894062 458444893 417601700 557126850 240033422 359309748 903308826 460368566 127519628 30487235 428941976 641387257 994730347 302375902 627639836 583115518 168608608 864941709 932499624 988905968 307663983 339583079 14994245 701384068 476690187 521527313 691920819 284620245 58516660 101078193 79262815 756410721 412039437 496864515 166053922 652072858 856174262 69362747 112441423 836210241 99849982 393899750 330113850 947096680 696275651 957753685 530212198 864884258 822695393 315228173 706306578 130359375 654811251 721300822 684259794 984017789 242828135 228696964 121154386 301344794 182291508 200417200 910271866 594330945 697281714 76325788 98920154 405972327 145688534 63877929 94698920 98054867 457777678 424812769 897667899 154053329 382566453 280396448 871453938 57778197 595624620 577760515 40653923 102952223 151577689 577430068 86970011 394405823 806127031 208124396 548266968 988418538 408541596 458538833 435265834 105823309 387380972 534185988 364311988 385585858 598063916 459010907 336157076 55841593 883823675 233824974 62411273 118906479 514221421 933865211 176684675 109846041 364142077 69854949 65314615 515719765 647285016 152284625 910125587 305928398 212925373 310908906 146863287 621466968 769447739 582129121 579806628 9345062 116315108 944118615 394930919 714379023 255645873 731087995 622736967 139469547 964912968 685148240 258376025 331650741 619013450 287577051 294013133 983155526 357431999 359327747 351391643 4717014 364128723 114033581 310645411 577054095 424942487 457508698 51037414 46906577 39637818 630844042 56251638 8469277 427479008 451182557 575364651 683124881 182270551 198101617 675110779 999699870 883249856 933486804 183866962 354779657 73580206 477880094 190451535 431012205 689724192 541843177 435729218 53852915 655876757 598890981 630907009 80819243 56399678 681944423 127725819 948553847 165304816 36493809 809539475 445300175 487676365 384904125 128425055 669946915 435522093 656052186 522163136 171288301 442055341 706030098 526067957 515635546 36426543 569035843 946647750 726150735 110879019 234893320 780003649 619272128 833784300 263427009 552607722 742700329 797887783 532849893 543770527 963192598 569343701 353310001 261009125 57020065 590730477 241950531 579483331 26252569 898002716 101646466 197540869 340058056 660192915 576125178 855693602 696619458 145161020 654857703 422770192 108556391 889751022 55290192 580344870 723535321 171233552 132952591 318752001 969121335 518318835 862522527 784830284 940178887 68348879 45839408 849715303 659079355 287789939 281714985 685331924 38309006 235877803 735389144 378367062 896070717 311514321 86577015 592690174 309191693 741434717 867976717 417748083 483702091 923266908 998092952 59753763 94500460 983561894 378505764 916138146 354397081 241028290 700968429 147092319 309377169 599324189 996807622 968456523 887114127 278522606 506304798 925423132 514400408 94210294 156306545 262987477 405724614 95399911 855677650 714916306 836834628 576170719 985180740 173053070 351953978 835790043 232806832 298970789 671868289 611312595 215108934 26265369 852340885 768593715 25874039 14234405 367917903 22681660 835207279 107548381 153720618 194028429 885487864 668121025 288238722 41794409 931108501 693963335 137194319 639302503 261395993 826545298 67989573 99093084 999598367 419943550 934883127 84921551 718914339 606751415 696234145 934023272 485533135 401091381 555133338 511407173 415325785 923051240 386605185 103049416 883115972 540325802 297077844 768603836 60963178 585316565 662914596 992071679 131796251 652625266 483890533 393192243 331686916 551880105 492285327 183801634 971823654 279684805 268723184 543254344 886436219 964957329 329793968 224485705 218565061 884927305 588409229 633890846 660494897 975014413 736940261 543610868 515340214 34018104 164731055 576303392 471851020 680162002 420891422 603647270 185303620 757298306 996839513 516990535 161694762 341641191 553308520 133518415 621325995 822031704 529289111 360278565 639505384 859083078 437280621 858070444 744010382 25689849 344477641 257021630 704262 933934253 800632498 368560827 820468708 817879904 797380570 292319727 498041906 70788343 895966997 683345525 828086648 745322861 52852411 989781409 939480403 606160930 975816176 413322749 280708985 505105286 773601313 772730720 216704715 63398285 483317516 960715096 89088133 827795156 70253078 942308746 614245761 870885575 163385925 434714468 541281830 960766494 579550547 39323735 31554837 328033895 575185611 859641484 73356755 480554373 701939245 865353509 86715303 677755420 278676257 219940639 35377057 904793921 992671359 252081771 968192205 328505226 65313218 57280337 8816733 135566295 852105435 623062493 858968221 15491359 57776961 400250051 976257852 489843859 292090137 860329040 817877753 719792100 572486876 743750859 200346472 274426120 609104367 139578126 804697891 740296975 212035117 840074947 645090895 57222827 944673069 465799451 385728052 9986286 375596139 394544784 998068933 227701573 17607277 857037153 95709283 927900589 109803555 71967135 417744447 254410044 784812526 88138551 974202143 357299401 831889409 27064966 484241872 293510127 166643092 288939762 33807101 378678208 981531060 531414347 435901034 926204128 997213797 821629085 788706766 372809935 68690220 639292050 453027860 86297496 348845554 548737142 14198084 458649109 473220628 284458882 713059152 258033154 372597432 539777646 467848906 57003192 566842611 952090778 350513318 733485702 93546891 384320418 964680261 75077951 915734764 253097646 853798430 765464912 74726730 495021547 138274847 143416950 134313596 443819058 82230797 483159150 992556199 948945233 794324610 465776827 85920466 359900113 576326332 458517898 899677758 44175237 515521089 466520368 996266014 866034407 52522422 89812905 102871176 17202682 17407207 871122292 122816680 871205636 636587203 50059761 218743535 627378401 45993062 353057130 71197458 128223859 688732631 916270009 77169091 483057240 234563187 15605908 842957352 810889518 474123805 595151461 855064754 842161246 61671829 703847120 560712004 966710602 646176376 663583179 836429635 516099934 387221822 959246314 239821921 23809025 9306075 458565455 503703777 55299136 811622585 427417587 36039346 352871567 196203947 113208436 835928807 430767133 128814344 531402510 241656650 455454500 126553971 949237755 150132097 40742151 505601226 710844100 859969104 4293953 226943631 696398738 520393886 614165452 508161404 760215807 490490828 517467478 218781261 994194605 425282965 882920197 274128543 461322311 235791764 470332489 427047098 924236922 901099621 408377793 308155783 995272622 863832293 287226105 944510376 13964389 180484607 302627954 577324841 40453710 306921906 804268471 589368800 827315792 418433922 97530203 587531598 908924750 467514032 658829210 755635706 892796996 541749407 882280600 354119306 630057522 205129440 781166404 554294443 106229060 42060548 862450225 954018033 905892840 2192682 751044760 772373581 182677288 53672713 202214773 223130998 360594619 6483243 812499797 40426762 277433516 762546351 627958359 38874617 230060382 139303920 794510322 122857377 681053326 529307273 329493035 163627199 734436712 963175790 717921641 693182123 5236337 432888218 647200155 763645529 435080899 250761267 388535461 617758186 304433979 590750233 693405535 517544949 597233475 358421683 557971710 874666990 120968033 38446420 913541607 203544766 177750340 560568280 178918495 858803665 89875553 508411529 22430864 676828616 324103670 592868856 370010739 329340006 878273425 869727245 92985534 165870675 120488511 334037346 783628861 277438842 924787578 329550747 794983790 374537404 687972430 352955500 101720746 808940462 391401919 15262352 12485228 569152258 428346983 43920074 280472275 370738887 552331602 155419490 47567503 876435271 600804697 270094593 58291628 479078122 139821837 3793514 644948796 112826700 337830859 281094008 390265541 115134789 610644755 37765682 489672192 151133536 390721181 591392937 960073997 634639452 459171640 825075576 56308061 887518623 868995649 336780335 110773861 273843602 344716176 10857715 2795224 945520873 133468659 61086852 277115346 125806848 917396717 922064141 238633547 107743927 55674501 481415439 222878715 518835607 519181120 712550907 669969142 909902301 303943843 482559490 397058104 763115483 160151418 453366164 503150457 29147066 790146499 466440669 155507020 134862674 477298384 10818595 932899898 610767042 71905446 210015243 736573889 841818514 984595736 827723787 949562441 40270236 309139225 172441155 411622194 828320345 884992061 81591335 590738997 41452256 564150824 987797100 657084090 724302241 293679615 12750898 605965659 83826113 479191566 613989030 71205139 956489949 624807624 856621388 419773343 549229422 66636631 8863583 391047935 903748718 836587370 193126727 796535305 998242946 365567882 208157498 679079642 103076294 142265184 122334990 144528549 706416007 110132089 654128990 283234600 256328056 666879887 741716610 192670520 146071453 355705639 116392010 955077753 980513262 973013398 227367447 382259035 892166380 236231030 773306970 795915097 925334751 966433696 444966753 923577696 184517929 653124250 455173690 140110575 795389433 577508679 137155475 354321791 540157120 791284465 490072742 796485175 458164351 231789351 989155694 456752155 440011341 105547704 411829908 273040955 78561101 639197354 655299989 823243832 727944735 281123310 471675280 653279485 100073358 916642032 429373533 284591286 422282633 884547222 424701860 70188417 314572252 561857335 424510207 854729371 205658151 914582949 651214545
Out #1:
744300315 818306599 177939927 941708048 929072178 6716436 622959130 49287518 13421068 134196160 566104272 346181977 367818793 768209881 127178410 116057059 661351278 111726761 20917575 133736227 735868820 866232707 237301874 349384107 967781009 590205923 407083455 393720086 173571926 137107109 506533069 138020400 955413707 684472995 556641023 942126219 697894062 458444893 127519628 460368566 903308826 359309748 240033422 557126850 417601700 30487235 428941976 641387257 994730347 168608608 583115518 627639836 302375902 864941709 988905968 932499624 307663983 339583079 14994245 701384068 476690187 521527313 691920819 284620245 58516660 101078193 79262815 756410721 412039437 496864515 856174262 652072858 166053922 69362747 112441423 836210241 947096680 330113850 393899750 99849982 696275651 957753685 864884258 530212198 822695393 315228173 706306578 130359375 654811251 684259794 721300822 984017789 242828135 910271866 200417200 182291508 301344794 121154386 228696964 594330945 98920154 76325788 697281714 405972327 145688534 63877929 94698920 98054867 457777678 424812769 897667899 154053329 382566453 871453938 280396448 57778197 595624620 577760515 40653923 102952223 151577689 577430068 86970011 394405823 806127031 408541596 988418538 548266968 208124396 458538833 435265834 105823309 598063916 385585858 364311988 534185988 387380972 459010907 336157076 55841593 883823675 233824974 62411273 118906479 514221421 933865211 176684675 109846041 364142077 69854949 65314615 515719765 647285016 152284625 910125587 305928398 212925373 310908906 146863287 621466968 769447739 582129121 116315108 9345062 579806628 944118615 394930919 714379023 255645873 731087995 622736967 139469547 685148240 964912968 258376025 331650741 619013450 287577051 294013133 983155526 357431999 359327747 351391643 4717014 364128723 114033581 310645411 577054095 424942487 51037414 457508698 46906577 56251638 630844042 39637818 8469277 427479008 451182557 575364651 683124881 182270551 198101617 675110779 183866962 933486804 883249856 999699870 354779657 477880094 73580206 190451535 431012205 689724192 541843177 435729218 53852915 655876757 598890981 630907009 80819243 56399678 681944423 127725819 948553847 165304816 36493809 809539475 445300175 487676365 384904125 128425055 669946915 435522093 522163136 656052186 171288301 442055341 706030098 526067957 515635546 36426543 569035843 946647750 726150735 110879019 234893320 780003649 833784300 619272128 263427009 552607722 742700329 797887783 532849893 543770527 963192598 569343701 353310001 261009125 57020065 590730477 241950531 579483331 26252569 101646466 898002716 197540869 340058056 660192915 145161020 696619458 855693602 576125178 654857703 422770192 108556391 580344870 55290192 889751022 723535321 171233552 132952591 318752001 969121335 518318835 862522527 784830284 940178887 68348879 45839408 849715303 659079355 287789939 281714985 38309006 685331924 235877803 378367062 735389144 896070717 311514321 86577015 592690174 309191693 741434717 867976717 417748083 483702091 998092952 923266908 59753763 916138146 378505764 983561894 94500460 354397081 241028290 700968429 147092319 309377169 599324189 996807622 968456523 887114127 94210294 514400408 925423132 506304798 278522606 156306545 262987477 405724614 95399911 836834628 714916306 855677650 576170719 351953978 173053070 985180740 835790043 232806832 298970789 671868289 611312595 215108934 26265369 852340885 768593715 25874039 14234405 367917903 22681660 835207279 107548381 153720618 194028429 885487864 668121025 288238722 41794409 931108501 693963335 137194319 639302503 261395993 826545298 67989573 99093084 999598367 419943550 934883127 84921551 718914339 606751415 696234145 934023272 485533135 401091381 555133338 511407173 415325785 923051240 386605185 60963178 768603836 297077844 540325802 883115972 103049416 585316565 662914596 992071679 131796251 652625266 483890533 393192243 331686916 551880105 492285327 971823654 183801634 279684805 543254344 268723184 886436219 964957329 329793968 224485705 218565061 884927305 588409229 633890846 660494897 975014413 736940261 34018104 515340214 543610868 164731055 757298306 185303620 603647270 420891422 680162002 471851020 576303392 996839513 516990535 161694762 341641191 553308520 133518415 621325995 822031704 529289111 360278565 859083078 639505384 437280621 744010382 858070444 25689849 344477641 704262 257021630 933934253 800632498 368560827 797380570 817879904 820468708 292319727 498041906 70788343 895966997 683345525 828086648 745322861 52852411 989781409 939480403 975816176 606160930 413322749 280708985 505105286 773601313 772730720 216704715 63398285 960715096 483317516 89088133 942308746 70253078 827795156 614245761 870885575 163385925 960766494 541281830 434714468 579550547 39323735 31554837 328033895 575185611 859641484 73356755 480554373 701939245 865353509 86715303 677755420 278676257 219940639 35377057 904793921 992671359 252081771 968192205 65313218 328505226 57280337 8816733 135566295 852105435 623062493 858968221 15491359 57776961 400250051 976257852 489843859 292090137 860329040 817877753 572486876 719792100 743750859 274426120 200346472 609104367 139578126 804697891 740296975 212035117 840074947 645090895 57222827 944673069 465799451 9986286 385728052 375596139 394544784 998068933 227701573 17607277 857037153 95709283 927900589 109803555 71967135 417744447 784812526 254410044 88138551 974202143 357299401 831889409 484241872 27064966 293510127 288939762 166643092 33807101 981531060 378678208 531414347 926204128 435901034 997213797 821629085 788706766 372809935 14198084 548737142 348845554 86297496 453027860 639292050 68690220 458649109 57003192 467848906 539777646 372597432 258033154 713059152 284458882 473220628 566842611 733485702 350513318 952090778 93546891 384320418 964680261 75077951 74726730 765464912 853798430 253097646 915734764 495021547 138274847 443819058 134313596 143416950 82230797 483159150 992556199 948945233 794324610 465776827 85920466 359900113 899677758 458517898 576326332 44175237 515521089 996266014 466520368 866034407 52522422 89812905 17202682 102871176 17407207 871205636 122816680 871122292 636587203 50059761 218743535 627378401 71197458 353057130 45993062 128223859 688732631 916270009 77169091 483057240 234563187 810889518 842957352 15605908 474123805 595151461 842161246 855064754 61671829 646176376 966710602 560712004 703847120 663583179 836429635 959246314 387221822 516099934 239821921 23809025 9306075 458565455 503703777 55299136 811622585 427417587 36039346 352871567 196203947 113208436 835928807 430767133 455454500 241656650 531402510 128814344 126553971 949237755 150132097 40742151 859969104 710844100 505601226 4293953 226943631 508161404 614165452 520393886 696398738 760215807 517467478 490490828 218781261 994194605 425282965 882920197 274128543 461322311 235791764 470332489 924236922 427047098 901099621 408377793 308155783 995272622 863832293 287226105 944510376 13964389 180484607 302627954 577324841 306921906 40453710 804268471 418433922 827315792 589368800 97530203 892796996 755635706 658829210 467514032 908924750 587531598 541749407 781166404 205129440 630057522 354119306 882280600 554294443 42060548 106229060 862450225 954018033 751044760 2192682 905892840 772373581 182677288 53672713 202214773 223130998 360594619 6483243 812499797 277433516 40426762 762546351 627958359 38874617 794510322 139303920 230060382 122857377 681053326 529307273 329493035 163627199 963175790 734436712 717921641 693182123 5236337 432888218 647200155 763645529 435080899 250761267 388535461 617758186 304433979 590750233 693405535 517544949 597233475 358421683 874666990 557971710 120968033 38446420 913541607 560568280 177750340 203544766 178918495 858803665 89875553 508411529 592868856 324103670 676828616 22430864 370010739 329340006 878273425 869727245 92985534 165870675 120488511 334037346 783628861 924787578 277438842 329550747 808940462 101720746 352955500 687972430 374537404 794983790 391401919 569152258 12485228 15262352 428346983 43920074 280472275 370738887 155419490 552331602 47567503 876435271 600804697 270094593 479078122 58291628 139821837 112826700 644948796 3793514 337830859 281094008 390265541 115134789 610644755 151133536 489672192 37765682 390721181 591392937 960073997 825075576 459171640 634639452 56308061 887518623 868995649 336780335 110773861 344716176 273843602 10857715 2795224 945520873 133468659 125806848 277115346 61086852 917396717 922064141 238633547 107743927 55674501 481415439 222878715 518835607 519181120 712550907 669969142 909902301 303943843 397058104 482559490 763115483 453366164 160151418 503150457 29147066 790146499 466440669 477298384 134862674 155507020 10818595 71905446 610767042 932899898 210015243 736573889 984595736 841818514 827723787 949562441 40270236 309139225 172441155 411622194 828320345 884992061 81591335 590738997 657084090 987797100 564150824 41452256 724302241 293679615 12750898 605965659 83826113 613989030 479191566 71205139 956489949 856621388 624807624 419773343 549229422 66636631 8863583 391047935 836587370 903748718 193126727 796535305 122334990 142265184 103076294 679079642 208157498 365567882 998242946 144528549 706416007 110132089 256328056 283234600 654128990 666879887 192670520 741716610 146071453 355705639 116392010 955077753 973013398 980513262 227367447 382259035 773306970 236231030 892166380 795915097 925334751 966433696 444966753 923577696 184517929 455173690 653124250 140110575 795389433 577508679 137155475 354321791 540157120 791284465 490072742 796485175 458164351 231789351 989155694 456752155 440011341 411829908 105547704 273040955 78561101 639197354 655299989 823243832 727944735 471675280 281123310 653279485 916642032 100073358 429373533 284591286 422282633 424701860 884547222 70188417 314572252 561857335 424510207 854729371 205658151 914582949 651214545 

In #2:
1000
206976325 367860673 400236834 790100678 846886989 957268455 448319137 737924932 165838800 214115037 50617102 35014726 11820552 57861259 83381095 935630820 360036917 90068954 768703037 672486793 962004469 15458910 24236835 930390818 868196417 415331911 292675849 998808744 702890508 466850094 61102823 909866833 834710766 313856008 552483862 534114106 123640814 802999 272039038 289479614 67434387 175172491 324494339 931771291 85550101 407875433 719918462 445587017 350460738 341137850 118073810 312465207 356596759 142310644 95372376 77309527 410158907 240564576 76118270 113049414 707414669 989737445 875432598 394641786 156109804 427916460 928755892 279750618 281235810 53311281 569230231 201186548 81000123 746240921 132957838 166550223 6632705 852876299 464653591 357093443 46530501 435243752 669558649 403127259 430070748 617447376 480436786 840229654 858011951 409071407 953279067 417942972 251325203 681228017 812584757 407435007 109144476 593857000 539701976 242896637 499684632 108932206 444083184 580684754 707689478 429557374 747234976 714322182 134950024 64404919 71415624 181480524 499648670 593490624 584607783 929719417 210937999 65044568 769949070 68949950 474115974 575744489 339409273 725441177 109488857 4510381 985392535 71149684 598367381 525094510 314046320 98052012 486543067 610645855 531253118 46748896 40203228 131004445 761071077 175153252 195409363 832486701 356633775 695058033 278493676 941241557 624777449 489431675 858802476 247242871 410897976 185434802 675503711 750307248 910875978 784992567 754817628 748784864 856142250 205701360 126395725 22704921 156269724 612938791 633350775 687522841 659687686 673554003 818527285 273275114 701223606 13936648 105761814 57857380 561511032 236771842 851615289 38804832 726203516 562934116 286047702 989617843 748368917 961551412 592441442 511761246 599060330 199775421 260546109 455202579 405476781 386941833 477907499 414262856 852396975 111258274 101785696 364601012 637328628 772829332 637876126 191068585 639282331 596154291 101442316 53309714 832926132 953057604 92114546 411645999 368508072 378162247 401263841 116876988 192230011 993705282 628638234 791290340 45997055 741700694 99009271 451473835 128642527 429433121 865736690 833555853 393207746 820038737 198156865 30536373 445384420 836032990 74121309 937183103 284703632 175563625 990492816 117629764 128621228 82607361 529275762 349645651 313285960 783055955 466522639 505515970 629277588 947677224 149322661 675274642 689377917 100848283 126748476 670536795 530281404 845001517 356609000 923489149 517556605 554765864 806541874 815457377 243315205 880663182 752640479 528018836 56226806 595649646 498164951 37364386 678257007 27440713 387010036 991542966 663013019 706049026 349575287 292290606 653726249 351414299 967565248 195620518 452262582 946830075 718673664 982543985 644347944 75282663 906033133 14420900 482564878 565091358 829878276 725880082 445754540 435035106 106415270 354497697 30684752 604580220 391862082 561458110 484537284 631388470 405517427 66654 337437495 607609065 292357260 843680096 959023363 112438859 39300613 411285944 911785285 610490628 246346280 408649580 685773291 4895765 423070480 20854520 569987122 105465107 746734602 15741661 393016565 705666223 222755710 276217668 162762794 614617791 837675777 647300078 98522612 95709555 647366731 435960107 703318619 792240342 132156554 514858333 904679200 23973518 926144277 668980837 634464145 25006908 77630416 172753787 29902672 353217247 193608307 599889794 458682354 940342908 468147806 851698918 498525482 690903515 127916585 661288275 158037658 818108713 161104704 256560269 766334619 808471435 692520375 322169589 453228128 824676928 837027921 210423680 848650445 615688549 879404516 335630942 640695457 957034931 508384728 670598128 162768530 701993034 270487921 621450883 494852293 738635727 325666152 993377774 282055593 306099088 654666049 440093250 976724152 815770752 696653519 743058770 476758538 241690245 65228358 929986666 66367173 754772630 140410345 767533969 370461179 872331212 103164910 11156635 681882494 464065990 534271114 844651023 166059023 804759035 318618257 660911316 395911113 644284408 506805441 677966705 802899847 13987841 118059955 779623998 829758593 667229825 375199119 159033482 908920069 292943828 941536499 827803593 47716458 934463195 447853914 270693988 806794406 403535175 134366974 341193252 867601164 668638087 185844274 33660187 325913473 504462531 547087854 574340937 1263290 53893294 104823994 804163137 67881135 75400300 436303486 750156079 742630124 664018957 761705912 651550192 956962784 703242411 331870137 857195593 490221957 779724050 980405932 149532715 183259224 114772905 490725966 50860388 635927344 676570239 937036926 814357168 33549121 336641131 388698105 34812411 243050776 493522098 691491899 163448262 568922397 980311736 766120692 164068872 644330692 527826604 815619063 453809828 83585366 5551 163521772 573807322 779729600 143927704 723340036 962988824 111216960 66582353 866365563 599660655 743152592 655918840 266534175 629218064 845076322 655232279 516546826 88127097 1270728 60555076 104091711 422709476 40866812 870212402 586778347 537713855 250555357 254913761 991523682 186657074 254919312 7561806 760464396 34648911 4005861 336320783 850154086 967739172 402903136 569036000 419916179 998572079 77471191 686450353 627790142 922547512 194198983 144336968 863190961 195469710 57408395 967282671 618179185 98275206 690011424 57473883 635989061 793083133 312387643 480029094 979740206 567306954 340107251 592720953 601955865 344113111 929041736 304626302 164368635 184461223 873662302 584284813 35549653 951133492 270735165 663339794 873681004 464934147 660193113 589388316 512920208 717601508 409187338 131099392 668393065 99198761 41089626 156898477 744798245 353477268 636927571 724538451 920784222 977034821 169775755 375256438 173664284 98817490 679882739 338032918 135795064 553545040 922317730 171344716 357194884 45569246 687200862 83392239 363019744 199910326 672780554 875939951 917511833 81967891 859555694 438421250 33683003 900645319 595319726 778481248 254122586 84763648 355536050 27423159 61798469 525311804 402679596 87979104 476645646 82562335 278528373 464957061 488623726 53362454 636301777 845818609 98931699 176018990 929210847 461951442 375929315 601991400 190407744 145957500 536475642 49963437 584378749 570158645 950608755 179698474 201156244 57247692 264462122 409208645 84670851 178776942 934520448 487350446 119272397 263682445 422429132 397800769 728639506 911052858 451163222 217457634 756871466 550094920 393476623 538598665 864562713 769405937 140590064 54970456 915363436 529582058 104933892 352258536 99740702 908058998 531957010 153413297 817823041 648935483 562621941 902493891 827712424 349658740 242360689 946984820 465857537 664789820 197301940 47013394 428359029 648465161 264471027 37746847 51076432 510464001 576345511 915639144 132386289 569451926 970609599 47749725 99033983 928059842 252524612 51291036 688635191 784481621 57220684 358974583 285933455 619842624 113984826 113645878 822017716 356345514 913147049 287875252 873651685 110448988 334888645 302010714 611430500 451876023 339757560 662506931 962340023 916103070 578146074 94726311 338071347 401272024 994992387 437105330 181848217 247516999 340912717 722999759 884514971 398133401 81974342 170448426 17976024 195959167 136610655 692510091 404821032 902274056 980385342 278472716 865239395 167790338 432999781 476669895 619666360 772757340 139176825 434522734 541376761 569839251 529249045 879448108 823627626 376757783 169069789 5475843 624274781 509982505 580991953 361306104 908115905 662966294 531754529 778608281 711441812 520881535 323634723 116262843 423155590 156536417 247251911 140911337 324326754 680251691 617581231 796509466 305525383 609274407 231032199 846902143 31630009 612797595 578866602 855257635 989555378 600452742 713249829 466346510 110435247 146758133 827652613 871067503 809724427 211923493 502192135 373682590 732805028 825826858 489945433 8476969 982363274 737197343 149388305 159206379 269965385 766969535 955715844 575490767 228760294 39264395 274909262 112906654 652061989 853775863 968164288 494133718 306744957 533930468 960480228 269696555 680688601 788132840 140764057 342929379 56333 495472544 716611968 585377712 173815753 59073752 593854680 8695378 648787446 743242985 20418108 918752831 362728871 976133952 494243597 591489164 867914698 769152858 704395818 372493038 475445073 525076457 866626756 782190029 911523277 827106983 51886583 444728229 467756174 45166991 787657607 320328858 393155886 356785926 905706569 419487990 268376030 352077601 428183367 917163475 95320585 448601475 835916305 458049455 277251778 182676254 902054971 145166475 804345463 458967140 370175864 132306887 984043596 236802619 914496915 748083224 916425953 818899849 192811452 236698479 716583192 832985410 557027336 962255429 42287688 315250257 381743419 310663717 667327857 662443137 227827191 615164793 111044611 916259848 73214247 240812740 98936101 827785569 238495566 755797915 286752708 608671430 888104802 123312656 697990400 655118068 871395879 614416353 326534269 916723683 851114831 43117460 749709092 260658518 857889240 791996779 428425126 92149010 102660495 95752982 754592147 183004038 563434126 718153109 99263885 489164725 958965849 50716337 316950293 49977766 659030603 456219353 511165547 547135404 579532008 209155947 54769824 303444238 676088651 381304092 72684272 379719833 276937903 822393364 640378350 134827142 466906494 68803476 226976152 422083341 17072809 981568298 457603730 433023287 552237758 409383966 922188011 363719958 312616654 91654655 413697724 971647256 547874007 924863270 371299012 127406014 986535568 426068835 283366604 662624218 807372926 356050875 42344050 84310828 30960590 535238752 71654321 350383436 456558579 298630472 772466776 326147739 132715121 82586857 759171025 684952879
Out #2:
206976325 367860673 790100678 400236834 846886989 957268455 448319137 165838800 737924932 214115037 11820552 35014726 50617102 57861259 83381095 935630820 360036917 90068954 768703037 672486793 962004469 15458910 24236835 930390818 868196417 415331911 292675849 466850094 702890508 998808744 61102823 909866833 123640814 534114106 552483862 313856008 834710766 802999 289479614 272039038 67434387 175172491 324494339 931771291 85550101 407875433 719918462 445587017 118073810 341137850 350460738 312465207 356596759 95372376 142310644 77309527 410158907 113049414 76118270 240564576 707414669 989737445 281235810 279750618 928755892 427916460 156109804 394641786 875432598 53311281 569230231 201186548 81000123 746240921 132957838 166550223 6632705 852876299 464653591 357093443 46530501 435243752 669558649 403127259 840229654 480436786 617447376 430070748 858011951 409071407 953279067 417942972 251325203 681228017 812584757 407435007 539701976 593857000 109144476 242896637 134950024 714322182 747234976 429557374 707689478 580684754 444083184 108932206 499684632 64404919 593490624 499648670 181480524 71415624 584607783 929719417 210937999 474115974 68949950 769949070 65044568 575744489 339409273 725441177 109488857 4510381 985392535 71149684 598367381 98052012 314046320 525094510 486543067 610645855 40203228 46748896 531253118 131004445 761071077 175153252 195409363 832486701 356633775 695058033 278493676 941241557 624777449 489431675 858802476 247242871 185434802 410897976 675503711 910875978 750307248 784992567 205701360 856142250 748784864 754817628 126395725 22704921 156269724 612938791 633350775 687522841 659687686 673554003 818527285 236771842 561511032 57857380 105761814 13936648 701223606 273275114 851615289 286047702 562934116 726203516 38804832 989617843 748368917 599060330 511761246 592441442 961551412 199775421 260546109 455202579 405476781 386941833 477907499 414262856 852396975 637876126 772829332 637328628 364601012 101785696 111258274 191068585 639282331 596154291 92114546 953057604 832926132 53309714 101442316 411645999 368508072 378162247 401263841 116876988 192230011 791290340 628638234 993705282 45997055 741700694 99009271 451473835 128642527 429433121 865736690 833555853 393207746 820038737 198156865 30536373 836032990 445384420 74121309 937183103 284703632 175563625 128621228 117629764 990492816 82607361 529275762 349645651 313285960 783055955 466522639 947677224 629277588 505515970 149322661 675274642 689377917 100848283 126748476 670536795 530281404 845001517 356609000 923489149 517556605 806541874 554765864 815457377 243315205 880663182 752640479 595649646 56226806 528018836 498164951 37364386 678257007 27440713 991542966 387010036 663013019 706049026 349575287 292290606 653726249 351414299 452262582 195620518 967565248 946830075 718673664 982543985 644347944 75282663 906033133 106415270 435035106 445754540 725880082 829878276 565091358 482564878 14420900 354497697 631388470 484537284 561458110 391862082 604580220 30684752 405517427 66654 337437495 607609065 843680096 292357260 959023363 112438859 39300613 411285944 911785285 408649580 246346280 610490628 685773291 4895765 569987122 20854520 423070480 105465107 746734602 15741661 393016565 705666223 162762794 276217668 222755710 614617791 837675777 98522612 647300078 95709555 647366731 435960107 703318619 132156554 792240342 514858333 23973518 904679200 926144277 668980837 634464145 77630416 25006908 172753787 29902672 353217247 193608307 498525482 851698918 468147806 940342908 458682354 599889794 690903515 127916585 661288275 158037658 818108713 161104704 256560269 766334619 808471435 692520375 322169589 824676928 453228128 837027921 210423680 848650445 615688549 335630942 879404516 640695457 957034931 701993034 162768530 670598128 508384728 270487921 621450883 494852293 738635727 993377774 325666152 282055593 306099088 654666049 815770752 976724152 440093250 696653519 476758538 743058770 241690245 929986666 65228358 66367173 754772630 140410345 767533969 370461179 103164910 872331212 11156635 534271114 464065990 681882494 844651023 166059023 804759035 318618257 660911316 395911113 644284408 506805441 677966705 802899847 13987841 118059955 779623998 829758593 667229825 375199119 159033482 908920069 292943828 941536499 827803593 47716458 934463195 806794406 270693988 447853914 403535175 867601164 341193252 134366974 668638087 185844274 33660187 325913473 504462531 547087854 574340937 104823994 53893294 1263290 804163137 67881135 436303486 75400300 750156079 742630124 664018957 956962784 651550192 761705912 703242411 331870137 857195593 490221957 980405932 779724050 149532715 183259224 114772905 635927344 50860388 490725966 676570239 814357168 937036926 33549121 336641131 388698105 34812411 493522098 243050776 691491899 163448262 568922397 527826604 644330692 164068872 766120692 980311736 815619063 83585366 453809828 5551 111216960 962988824 723340036 143927704 779729600 573807322 163521772 66582353 866365563 599660655 655918840 743152592 266534175 845076322 629218064 655232279 516546826 88127097 60555076 1270728 104091711 870212402 40866812 422709476 586778347 537713855 250555357 254913761 760464396 7561806 254919312 186657074 991523682 34648911 4005861 336320783 569036000 402903136 967739172 850154086 419916179 998572079 77471191 686450353 922547512 627790142 194198983 144336968 863190961 195469710 57408395 967282671 618179185 690011424 98275206 57473883 635989061 793083133 312387643 567306954 979740206 480029094 340107251 592720953 601955865 344113111 304626302 929041736 164368635 184461223 873662302 584284813 35549653 951133492 270735165 873681004 663339794 464934147 660193113 131099392 409187338 717601508 512920208 589388316 668393065 99198761 41089626 156898477 744798245 353477268 636927571 724538451 920784222 977034821 169775755 98817490 173664284 375256438 679882739 687200862 45569246 357194884 171344716 922317730 553545040 135795064 338032918 83392239 672780554 199910326 363019744 875939951 917511833 81967891 438421250 859555694 33683003 900645319 355536050 84763648 254122586 778481248 595319726 27423159 61798469 476645646 87979104 402679596 525311804 82562335 278528373 464957061 53362454 488623726 636301777 845818609 98931699 176018990 929210847 461951442 375929315 536475642 145957500 190407744 601991400 49963437 584378749 570158645 950608755 264462122 57247692 201156244 179698474 409208645 84670851 487350446 934520448 178776942 119272397 263682445 422429132 397800769 550094920 756871466 217457634 451163222 911052858 728639506 393476623 538598665 864562713 769405937 531957010 908058998 99740702 352258536 104933892 529582058 915363436 54970456 140590064 153413297 817823041 648935483 562621941 902493891 349658740 827712424 242360689 946984820 465857537 47013394 197301940 664789820 428359029 648465161 264471027 37746847 51076432 510464001 576345511 915639144 132386289 569451926 970609599 47749725 99033983 51291036 252524612 928059842 688635191 784481621 57220684 358974583 285933455 356345514 822017716 113645878 113984826 619842624 913147049 287875252 873651685 110448988 334888645 611430500 302010714 451876023 339757560 662506931 962340023 578146074 916103070 94726311 338071347 401272024 994992387 437105330 181848217 247516999 340912717 722999759 884514971 398133401 17976024 170448426 81974342 195959167 136610655 692510091 278472716 980385342 902274056 404821032 865239395 167790338 432999781 476669895 772757340 619666360 139176825 434522734 541376761 569839251 529249045 823627626 879448108 376757783 169069789 5475843 624274781 509982505 580991953 361306104 908115905 662966294 531754529 778608281 711441812 520881535 323634723 116262843 423155590 156536417 247251911 140911337 324326754 680251691 617581231 796509466 305525383 609274407 231032199 846902143 31630009 612797595 578866602 855257635 600452742 989555378 713249829 466346510 110435247 146758133 827652613 871067503 809724427 211923493 502192135 825826858 732805028 373682590 489945433 8476969 982363274 737197343 149388305 159206379 269965385 766969535 955715844 575490767 228760294 39264395 112906654 274909262 652061989 853775863 494133718 968164288 306744957 960480228 533930468 269696555 680688601 788132840 140764057 342929379 56333 585377712 716611968 495472544 173815753 648787446 8695378 593854680 59073752 743242985 20418108 918752831 362728871 976133952 494243597 372493038 704395818 769152858 867914698 591489164 475445073 525076457 866626756 782190029 911523277 827106983 51886583 444728229 467756174 45166991 787657607 356785926 393155886 320328858 905706569 268376030 419487990 352077601 428183367 917163475 95320585 448601475 835916305 458049455 182676254 277251778 902054971 145166475 804345463 370175864 458967140 132306887 984043596 236802619 914496915 748083224 916425953 818899849 192811452 236698479 557027336 832985410 716583192 962255429 42287688 315250257 381743419 310663717 667327857 662443137 227827191 615164793 111044611 916259848 73214247 240812740 98936101 827785569 238495566 755797915 655118068 697990400 123312656 888104802 608671430 286752708 871395879 614416353 326534269 916723683 851114831 857889240 260658518 749709092 43117460 791996779 92149010 428425126 102660495 95752982 754592147 563434126 183004038 718153109 99263885 489164725 958965849 50716337 316950293 49977766 659030603 456219353 511165547 579532008 547135404 209155947 303444238 54769824 676088651 72684272 381304092 379719833 276937903 226976152 68803476 466906494 134827142 640378350 822393364 422083341 17072809 457603730 981568298 433023287 409383966 552237758 922188011 312616654 363719958 91654655 971647256 413697724 547874007 986535568 127406014 371299012 924863270 426068835 807372926 662624218 283366604 356050875 535238752 30960590 84310828 42344050 71654321 350383436 456558579 772466776 298630472 326147739 132715121 82586857 759171025 684952879 

In #3:
1000
671024078 144087680 626636093 15613913 639555883 906391588 922825165 7465368 479155771 574952531 93793309 658556983 510860252 135273799 50128602 684658074 142484624 81455103 520633514 369828147 277887559 243885810 970902910 383404487 775856951 327646352 128089395 759938933 26779557 751140361 407234260 697803634 747744392 33870353 713417546 239816626 792778292 488759062 99798346 124450414 916227945 46108006 783007397 427088196 181381804 833135998 111746269 176382779 914591100 484896134 546210926 44995011 728781944 369630187 280915849 357155246 697276538 409005243 969610531 724056094 12661955 376844790 274376079 612922699 263231494 840309977 852739324 908526137 181585390 805054021 32976551 97813334 851162026 668500299 377417881 885060181 354152648 341680502 61442960 121260100 826576635 460170237 18771462 407874930 829800423 299687310 617546528 379593312 708692552 587157058 956165758 573870858 816518199 83058188 186793556 79749693 923368164 892049232 840792181 104953554 697103252 726285083 55283239 400781630 247301733 432701120 138358162 601454381 774381621 199801121 575230832 453474607 659971357 594002293 861349537 342288131 893689602 331412416 574397795 454898505 918569473 530563552 28769362 587604023 613621739 68079270 519870067 389506255 960128501 360662248 494459808 509748104 86947330 549743046 910529733 186765415 982444165 48887895 788219795 609342137 101205367 215966978 62816744 613693076 809969270 776682632 955981206 703658871 108095047 382895352 11073727 879180871 913458903 39843088 466784893 379596994 107922357 986654960 769103248 68050857 199833559 116079407 430315313 139297240 518338804 193361397 326062654 353299321 94765643 966798800 962641457 195971010 182765777 25458200 809664085 992735046 654657183 618161642 548910268 762752229 1056994 559983994 494449451 767032248 452343434 961234344 999145593 560265790 800405655 620765192 480832999 852755565 736844598 911148311 992052804 107699754 104509707 170631810 460999074 51791702 137430609 423640530 247762711 172712738 301615082 909943147 17964135 956272264 380621140 419390755 571540845 234194485 979374748 65990295 1226733 284234533 879740990 852888677 844500323 532662996 473653869 177849673 237934912 63014818 941514335 82504068 170714571 898540393 253135877 631713644 950332094 243082837 907870526 50611156 268311926 62001959 960554302 286276061 18274222 341175442 705666815 442331418 575369926 537557914 360838065 429113010 821792447 93095406 134518039 518809121 478274754 608171907 549175145 716209665 523703076 490689479 798713732 694417647 241746223 51849608 178647642 192078317 147448797 86518167 242689472 415760722 1036477 55760126 554553134 19310699 396935567 112736300 314158468 824821844 650294214 527512884 106451206 324603012 620608290 240969244 695928484 98883043 849141150 245103628 667609059 225360577 588309458 466322791 919778223 830055680 370688750 950942217 22133996 370653898 889976735 117339820 786414620 891013212 173099945 193484105 762840262 422551863 306220405 76998729 247373706 956514618 457027965 353824911 133633981 77636254 594794154 829562464 29035648 296451655 927182443 549161058 521812232 515491900 15483848 294106806 198063931 238688950 97565374 72714279 609342847 987542109 190054098 248273818 878555320 215670394 441757923 493911933 638222256 747978327 423427013 885595961 557009296 880454977 91937224 543159628 810607582 539247729 225238443 692159581 835699384 152420885 241320639 210027967 520429136 109320838 356651124 718493066 200526139 454216498 791207344 809868986 441758606 981261441 910659155 172830277 49448186 204933429 666742209 687670441 952911755 90169221 425782754 362437402 823140550 517719977 905597029 633748131 56967705 130835471 178424064 745183440 135772707 419744702 807727758 656201842 381581891 164378882 227211260 582108030 618595379 18418603 244493367 912870336 852196396 155152521 85700612 901644581 360085950 604959172 589315022 165514056 547644744 15097775 380467810 223301645 385334103 138581190 857049776 294818159 121933013 35473839 892517951 257705719 307734892 700245708 766423913 689316782 717140941 993635172 123941163 188252671 12053774 368434529 101123006 716766521 523587050 39339969 618411102 736189351 496815492 60242475 901703406 44460236 927856601 134687567 120278232 165707055 273268757 977328007 460525213 395201769 865318197 205559515 652907487 25569440 905805223 271847751 567402574 475462515 265482922 691343736 663715186 130053048 59778265 764838191 846819568 435881666 656694512 317747021 172071016 153510003 230505847 926290773 50486590 158362447 60978340 170764822 324069501 334247096 609180 637111066 729448864 718443729 842670580 234872702 744013168 600992154 506720453 163932093 76454669 624719726 855275829 740169854 754772773 915054093 357524396 454108693 203452110 14218907 624372065 375523125 20245262 854877912 154330249 70731851 13240358 215308588 94013024 189826211 402072035 94622204 826937276 131520898 665582284 522124207 218909952 262111803 123116361 578146756 426043896 52087381 202866481 281319724 792257234 810155606 48890168 2297981 116780650 252342277 869033240 741152714 480381753 889278501 596030625 634712001 812526703 461787335 850020589 759056079 504129897 104608975 706194634 183583524 88646225 371776917 705707730 307556176 633888719 828824090 885702931 59932614 880911470 941085763 193768689 525685055 751241368 95175208 380499388 868022017 347517484 249532627 461691083 827899236 991327479 57721707 315127589 656370533 372025393 17664529 415426611 876155289 122273503 121621244 59738812 210919727 345914512 617962894 518475902 832319583 299303335 256695184 744768548 32731157 50297299 938537237 558416211 801538666 33712444 938915598 522077035 233746280 40964576 983768117 914161867 32292054 894006175 229289455 541178939 118547920 246953983 956605549 847219560 369227486 930743145 759474724 580147212 129174008 377437617 951139466 961493590 676740951 60351001 558778490 709472107 110648299 349832078 120404670 912186965 236060873 911836619 286780351 469807152 952801195 123064819 236485371 837609600 869587345 465774825 231304890 988135264 565245160 40426791 687871176 934472645 971169935 447345899 367136208 952860294 677299867 170792025 766870236 206557169 231143026 325648725 916029276 341791324 675480802 888950297 106494640 911541674 800786915 393274990 233865178 606104461 368856160 470350548 296230413 238443505 788641724 527535302 79095120 353886883 567962092 766966295 140875879 391648378 66828545 360528439 197025024 744128411 531320463 963895259 950685580 762463488 142060335 719231207 104254812 817541136 460697855 210749451 581599161 114001121 456540793 667980690 720105582 825396952 138331237 868852346 63840456 779489313 248903999 995451928 133376195 816866091 614934574 126768426 61030820 681763119 487296864 258055843 278407881 18617326 74467453 81609812 633597166 216527787 653357370 737851977 34068922 114055224 801117779 468184435 228056345 257658571 136165124 800678278 83055523 127012713 669530623 999412330 759018377 918434621 847380609 744910923 587817063 462315183 871679348 501364235 996594653 211492563 759420077 127518885 82626241 833887530 209128697 716223406 50415316 862486066 306591734 937000590 829057642 107709512 257701376 57113986 217884435 246382851 710308615 153456309 225911915 232355589 5384990 984930291 3306561 852765599 582357566 591123624 167597133 306553265 92487858 16708137 518045828 704424286 144227021 453188420 390828167 353355717 21928177 293759835 68358135 328519910 83276776 897415776 288745773 193494503 807046113 359146559 439877353 369871079 512602867 518305620 602226667 370504209 355752262 605533227 75786159 938109827 49173202 243383291 244663092 141661059 260091427 615225271 698601697 404318447 68413690 941946215 610190516 90341866 88222401 678548650 271378127 171499176 428480777 560123899 364993678 88043241 919270458 657387383 457914319 284389676 175693002 60140985 654893884 531445263 518190563 730680042 322071442 567363765 826579684 566734533 561541175 86671110 34476155 112659223 343505909 102889844 54605438 953696424 45748061 142827838 484761425 317126187 166843366 765758553 877250085 531837043 853801793 649036894 41740777 164232463 785942922 217433778 76889799 293353157 601395393 595080361 24033199 923466834 14960477 703129234 342717718 576501652 642316696 377193872 689160874 985822604 480083715 743766311 792035379 525831775 739110501 129313155 842957961 905953866 895071707 572724397 290307260 601389851 74277643 332048037 618138665 860220564 549481814 695028463 6090072 3393558 142625175 30123270 926860391 157585652 585768856 269578108 734087303 228085551 646771979 275764528 66424506 979372045 19530839 710976236 357720171 611157691 840289390 53194483 517111556 587877448 625918880 807418815 41783650 552712874 139466851 659922314 265449789 541465017 207467128 271539860 544858574 202608654 154179482 324235317 360194305 739948337 593813424 946797959 968033887 93101755 222562487 886974744 72473799 94609677 597950979 282710322 705767367 290756720 335904804 75395274 731150519 961823683 735330440 772934168 367052908 727313643 285372833 632502696 121295011 345356312 904042556 666153584 547964965 58222037 990388900 908159270 798170373 436718676 707473580 618720611 382336782 930036066 358211706 307326932 877162094 956162684 590037253 435445812 99435755 925942057 510841085 830586273 740282091 98687877 456036792 107334999 826001519 593925976 739837694 947296529 939282287 496396601 465966464 487247251 554618637 308871716 247922872 205305361 745590391 955396452 676542323 127927172 737948869 34754028 287770455 467627315 843433063 877807708 903073126 942868817 803749764 266430563 625971441 396548206 365118439 934524584 503883204 191119957 528450559 96237250 138416485 320249197 592633850 456899300 807496448 999768839 765771015 907935671 57590551 363877757 715848474 734132874 344321280 306313695 768886901 632091735 773941009 464836316 509899442
Out #3:
144087680 671024078 626636093 15613913 639555883 906391588 922825165 7465368 479155771 574952531 93793309 658556983 510860252 135273799 142484624 684658074 50128602 81455103 520633514 369828147 277887559 970902910 243885810 383404487 775856951 327646352 128089395 759938933 26779557 751140361 747744392 697803634 407234260 33870353 124450414 99798346 488759062 792778292 239816626 713417546 916227945 46108006 783007397 833135998 181381804 427088196 111746269 176382779 546210926 484896134 914591100 44995011 728781944 369630187 280915849 697276538 357155246 409005243 969610531 724056094 12661955 376844790 274376079 612922699 263231494 840309977 852739324 908526137 181585390 805054021 32976551 851162026 97813334 668500299 377417881 885060181 121260100 61442960 341680502 354152648 826576635 460170237 407874930 18771462 829800423 573870858 956165758 587157058 708692552 379593312 617546528 299687310 816518199 186793556 83058188 79749693 892049232 923368164 840792181 697103252 104953554 726285083 55283239 400781630 247301733 138358162 432701120 601454381 774381621 199801121 575230832 453474607 659971357 594002293 861349537 342288131 331412416 893689602 574397795 454898505 918569473 28769362 530563552 587604023 613621739 68079270 519870067 389506255 960128501 549743046 86947330 509748104 494459808 360662248 910529733 186765415 982444165 48887895 788219795 609342137 101205367 955981206 776682632 809969270 613693076 62816744 215966978 703658871 108095047 382895352 11073727 879180871 913458903 39843088 466784893 379596994 107922357 769103248 986654960 68050857 199833559 116079407 430315313 518338804 139297240 193361397 326062654 353299321 94765643 966798800 962641457 195971010 182765777 25458200 809664085 992735046 654657183 548910268 618161642 762752229 559983994 1056994 494449451 961234344 452343434 767032248 999145593 560265790 800405655 620765192 480832999 852755565 736844598 911148311 107699754 992052804 104509707 51791702 460999074 170631810 137430609 423640530 247762711 301615082 172712738 909943147 17964135 380621140 956272264 419390755 571540845 234194485 979374748 65990295 1226733 284234533 879740990 852888677 844500323 532662996 473653869 177849673 63014818 237934912 941514335 82504068 170714571 898540393 253135877 950332094 631713644 243082837 268311926 50611156 907870526 62001959 960554302 286276061 341175442 18274222 705666815 537557914 575369926 442331418 360838065 429113010 821792447 93095406 134518039 518809121 478274754 608171907 549175145 716209665 523703076 490689479 798713732 694417647 241746223 178647642 51849608 192078317 147448797 86518167 415760722 242689472 1036477 554553134 55760126 19310699 396935567 695928484 240969244 620608290 324603012 106451206 527512884 650294214 824821844 314158468 112736300 98883043 245103628 849141150 667609059 225360577 588309458 466322791 919778223 370688750 830055680 950942217 370653898 22133996 889976735 891013212 786414620 117339820 173099945 193484105 762840262 422551863 306220405 76998729 956514618 247373706 457027965 353824911 133633981 29035648 829562464 594794154 77636254 296451655 927182443 294106806 15483848 515491900 521812232 549161058 198063931 97565374 238688950 72714279 609342847 987542109 215670394 878555320 248273818 190054098 441757923 493911933 638222256 747978327 423427013 885595961 557009296 880454977 810607582 543159628 91937224 539247729 225238443 692159581 835699384 152420885 241320639 210027967 718493066 356651124 109320838 520429136 200526139 441758606 809868986 791207344 454216498 981261441 910659155 172830277 49448186 204933429 666742209 687670441 952911755 90169221 823140550 362437402 425782754 517719977 905597029 633748131 56967705 130835471 745183440 178424064 135772707 656201842 807727758 419744702 381581891 582108030 227211260 164378882 618595379 18418603 244493367 852196396 912870336 155152521 85700612 901644581 547644744 165514056 589315022 604959172 360085950 15097775 380467810 223301645 385334103 857049776 138581190 294818159 121933013 35473839 892517951 257705719 700245708 307734892 766423913 689316782 717140941 993635172 123941163 188252671 12053774 368434529 101123006 716766521 523587050 39339969 618411102 736189351 496815492 60242475 44460236 901703406 927856601 134687567 120278232 165707055 273268757 977328007 460525213 395201769 865318197 205559515 652907487 25569440 905805223 271847751 567402574 475462515 130053048 663715186 691343736 265482922 59778265 764838191 656694512 435881666 846819568 317747021 172071016 153510003 230505847 926290773 50486590 158362447 170764822 60978340 324069501 729448864 637111066 609180 334247096 718443729 600992154 744013168 234872702 842670580 506720453 163932093 76454669 624719726 855275829 740169854 754772773 915054093 357524396 454108693 203452110 14218907 624372065 375523125 854877912 20245262 154330249 70731851 94013024 215308588 13240358 189826211 402072035 665582284 131520898 826937276 94622204 522124207 218909952 262111803 123116361 426043896 578146756 52087381 202866481 48890168 810155606 792257234 281319724 2297981 116780650 252342277 741152714 869033240 480381753 889278501 596030625 634712001 812526703 461787335 850020589 759056079 504129897 104608975 183583524 706194634 88646225 371776917 307556176 705707730 633888719 828824090 885702931 880911470 59932614 941085763 193768689 525685055 380499388 95175208 751241368 868022017 347517484 249532627 461691083 827899236 991327479 57721707 315127589 656370533 372025393 17664529 415426611 876155289 122273503 59738812 121621244 210919727 518475902 617962894 345914512 832319583 299303335 744768548 256695184 32731157 50297299 938537237 558416211 938915598 33712444 801538666 522077035 40964576 233746280 983768117 914161867 32292054 894006175 229289455 541178939 118547920 246953983 956605549 369227486 847219560 930743145 129174008 580147212 759474724 377437617 961493590 951139466 676740951 60351001 558778490 709472107 110648299 120404670 349832078 912186965 236060873 911836619 286780351 469807152 952801195 123064819 236485371 837609600 869587345 465774825 565245160 988135264 231304890 40426791 687871176 934472645 971169935 447345899 952860294 367136208 677299867 170792025 766870236 206557169 231143026 325648725 675480802 341791324 916029276 888950297 911541674 106494640 800786915 233865178 393274990 606104461 470350548 368856160 296230413 238443505 79095120 527535302 788641724 353886883 567962092 766966295 140875879 391648378 66828545 360528439 197025024 744128411 531320463 963895259 762463488 950685580 142060335 719231207 817541136 104254812 460697855 210749451 581599161 114001121 456540793 825396952 720105582 667980690 138331237 63840456 868852346 779489313 248903999 995451928 133376195 816866091 61030820 126768426 614934574 681763119 487296864 258055843 278407881 18617326 74467453 633597166 81609812 216527787 653357370 737851977 114055224 34068922 801117779 468184435 228056345 257658571 800678278 136165124 83055523 127012713 669530623 999412330 759018377 918434621 847380609 744910923 587817063 462315183 871679348 501364235 996594653 211492563 759420077 127518885 82626241 833887530 209128697 57113986 257701376 107709512 829057642 937000590 306591734 862486066 50415316 716223406 217884435 246382851 710308615 153456309 225911915 232355589 5384990 984930291 3306561 852765599 591123624 582357566 167597133 306553265 92487858 16708137 704424286 518045828 144227021 453188420 390828167 353355717 21928177 293759835 68358135 897415776 83276776 328519910 288745773 193494503 807046113 359146559 439877353 369871079 512602867 518305620 602226667 370504209 355752262 605533227 75786159 938109827 49173202 243383291 244663092 141661059 260091427 615225271 698601697 404318447 68413690 941946215 90341866 610190516 88222401 678548650 271378127 171499176 428480777 560123899 364993678 88043241 919270458 657387383 457914319 175693002 284389676 60140985 654893884 531445263 518190563 322071442 730680042 567363765 826579684 566734533 561541175 86671110 34476155 112659223 343505909 953696424 54605438 102889844 45748061 142827838 484761425 317126187 166843366 765758553 877250085 531837043 853801793 649036894 41740777 164232463 217433778 785942922 76889799 293353157 601395393 595080361 24033199 923466834 14960477 985822604 689160874 377193872 642316696 576501652 342717718 703129234 480083715 743766311 792035379 525831775 739110501 129313155 842957961 905953866 895071707 572724397 290307260 601389851 74277643 332048037 618138665 549481814 860220564 695028463 3393558 6090072 142625175 30123270 926860391 269578108 585768856 157585652 734087303 228085551 646771979 66424506 275764528 979372045 19530839 710976236 357720171 611157691 840289390 53194483 625918880 587877448 517111556 807418815 552712874 41783650 139466851 659922314 265449789 541465017 154179482 202608654 544858574 271539860 207467128 324235317 360194305 739948337 593813424 946797959 968033887 93101755 222562487 886974744 72473799 94609677 597950979 282710322 705767367 75395274 335904804 290756720 731150519 961823683 367052908 772934168 735330440 727313643 285372833 632502696 121295011 666153584 904042556 345356312 547964965 58222037 908159270 990388900 798170373 707473580 436718676 618720611 956162684 877162094 307326932 358211706 930036066 382336782 590037253 435445812 99435755 925942057 510841085 830586273 740282091 98687877 456036792 107334999 826001519 739837694 593925976 947296529 939282287 496396601 465966464 487247251 554618637 247922872 308871716 205305361 745590391 955396452 676542323 127927172 737948869 34754028 287770455 467627315 843433063 903073126 877807708 942868817 803749764 266430563 625971441 396548206 365118439 503883204 934524584 191119957 528450559 96237250 138416485 320249197 807496448 456899300 592633850 999768839 765771015 907935671 57590551 363877757 344321280 734132874 715848474 306313695 768886901 632091735 773941009 509899442 464836316 

In #4:
1000
1 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47 49 51 53 55 57 59 61 63 65 67 69 71 73 75 77 79 81 83 85 87 89 91 93 95 97 99 101 103 105 107 109 111 113 115 117 119 121 123 125 127 129 131 133 135 137 139 141 143 145 147 149 151 153 155 157 159 161 163 165 167 169 171 173 175 177 179 181 183 185 187 189 191 193 195 197 199 201 203 205 207 209 211 213 215 217 219 221 223 225 227 229 231 233 235 237 239 241 243 245 247 249 251 253 255 257 259 261 263 265 267 269 271 273 275 277 279 281 283 285 287 289 291 293 295 297 299 301 303 305 307 309 311 313 315 317 319 321 323 325 327 329 331 333 335 337 339 341 343 345 347 349 351 353 355 357 359 361 363 365 367 369 371 373 375 377 379 381 383 385 387 389 391 393 395 397 399 401 403 405 407 409 411 413 415 417 419 421 423 425 427 429 431 433 435 437 439 441 443 445 447 449 451 453 455 457 459 461 463 465 467 469 471 473 475 477 479 481 483 485 487 489 491 493 495 497 499 501 503 505 507 509 511 513 515 517 519 521 523 525 527 529 531 533 535 537 539 541 543 545 547 549 551 553 555 557 559 561 563 565 567 569 571 573 575 577 579 581 583 585 587 589 591 593 595 597 599 601 603 605 607 609 611 613 615 617 619 621 623 625 627 629 631 633 635 637 639 641 643 645 647 649 651 653 655 657 659 661 663 665 667 669 671 673 675 677 679 681 683 685 687 689 691 693 695 697 699 701 703 705 707 709 711 713 715 717 719 721 723 725 727 729 731 733 735 737 739 741 743 745 747 749 751 753 755 757 759 761 763 765 767 769 771 773 775 777 779 781 783 785 787 789 791 793 795 797 799 801 803 805 807 809 811 813 815 817 819 821 823 825 827 829 831 833 835 837 839 841 843 845 847 849 851 853 855 857 859 861 863 865 867 869 871 873 875 877 879 881 883 885 887 889 891 893 895 897 899 901 903 905 907 909 911 913 915 917 919 921 923 925 927 929 931 933 935 937 939 941 943 945 947 949 951 953 955 957 959 961 963 965 967 969 971 973 975 977 979 981 983 985 987 989 991 993 995 997 999 1001 1003 1005 1007 1009 1011 1013 1015 1017 1019 1021 1023 1025 1027 1029 1031 1033 1035 1037 1039 1041 1043 1045 1047 1049 1051 1053 1055 1057 1059 1061 1063 1065 1067 1069 1071 1073 1075 1077 1079 1081 1083 1085 1087 1089 1091 1093 1095 1097 1099 1101 1103 1105 1107 1109 1111 1113 1115 1117 1119 1121 1123 1125 1127 1129 1131 1133 1135 1137 1139 1141 1143 1145 1147 1149 1151 1153 1155 1157 1159 1161 1163 1165 1167 1169 1171 1173 1175 1177 1179 1181 1183 1185 1187 1189 1191 1193 1195 1197 1199 1201 1203 1205 1207 1209 1211 1213 1215 1217 1219 1221 1223 1225 1227 1229 1231 1233 1235 1237 1239 1241 1243 1245 1247 1249 1251 1253 1255 1257 1259 1261 1263 1265 1267 1269 1271 1273 1275 1277 1279 1281 1283 1285 1287 1289 1291 1293 1295 1297 1299 1301 1303 1305 1307 1309 1311 1313 1315 1317 1319 1321 1323 1325 1327 1329 1331 1333 1335 1337 1339 1341 1343 1345 1347 1349 1351 1353 1355 1357 1359 1361 1363 1365 1367 1369 1371 1373 1375 1377 1379 1381 1383 1385 1387 1389 1391 1393 1395 1397 1399 1401 1403 1405 1407 1409 1411 1413 1415 1417 1419 1421 1423 1425 1427 1429 1431 1433 1435 1437 1439 1441 1443 1445 1447 1449 1451 1453 1455 1457 1459 1461 1463 1465 1467 1469 1471 1473 1475 1477 1479 1481 1483 1485 1487 1489 1491 1493 1495 1497 1499 1501 1503 1505 1507 1509 1511 1513 1515 1517 1519 1521 1523 1525 1527 1529 1531 1533 1535 1537 1539 1541 1543 1545 1547 1549 1551 1553 1555 1557 1559 1561 1563 1565 1567 1569 1571 1573 1575 1577 1579 1581 1583 1585 1587 1589 1591 1593 1595 1597 1599 1601 1603 1605 1607 1609 1611 1613 1615 1617 1619 1621 1623 1625 1627 1629 1631 1633 1635 1637 1639 1641 1643 1645 1647 1649 1651 1653 1655 1657 1659 1661 1663 1665 1667 1669 1671 1673 1675 1677 1679 1681 1683 1685 1687 1689 1691 1693 1695 1697 1699 1701 1703 1705 1707 1709 1711 1713 1715 1717 1719 1721 1723 1725 1727 1729 1731 1733 1735 1737 1739 1741 1743 1745 1747 1749 1751 1753 1755 1757 1759 1761 1763 1765 1767 1769 1771 1773 1775 1777 1779 1781 1783 1785 1787 1789 1791 1793 1795 1797 1799 1801 1803 1805 1807 1809 1811 1813 1815 1817 1819 1821 1823 1825 1827 1829 1831 1833 1835 1837 1839 1841 1843 1845 1847 1849 1851 1853 1855 1857 1859 1861 1863 1865 1867 1869 1871 1873 1875 1877 1879 1881 1883 1885 1887 1889 1891 1893 1895 1897 1899 1901 1903 1905 1907 1909 1911 1913 1915 1917 1919 1921 1923 1925 1927 1929 1931 1933 1935 1937 1939 1941 1943 1945 1947 1949 1951 1953 1955 1957 1959 1961 1963 1965 1967 1969 1971 1973 1975 1977 1979 1981 1983 1985 1987 1989 1991 1993 1995 1997 1999 2001
Out #4:
1 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47 49 51 53 55 57 59 61 63 65 67 69 71 73 75 77 79 81 83 85 87 89 91 93 95 97 99 101 103 105 107 109 111 113 115 117 119 121 123 125 127 129 131 133 135 137 139 141 143 145 147 149 151 153 155 157 159 161 163 165 167 169 171 173 175 177 179 181 183 185 187 189 191 193 195 197 199 201 203 205 207 209 211 213 215 217 219 221 223 225 227 229 231 233 235 237 239 241 243 245 247 249 251 253 255 257 259 261 263 265 267 269 271 273 275 277 279 281 283 285 287 289 291 293 295 297 299 301 303 305 307 309 311 313 315 317 319 321 323 325 327 329 331 333 335 337 339 341 343 345 347 349 351 353 355 357 359 361 363 365 367 369 371 373 375 377 379 381 383 385 387 389 391 393 395 397 399 401 403 405 407 409 411 413 415 417 419 421 423 425 427 429 431 433 435 437 439 441 443 445 447 449 451 453 455 457 459 461 463 465 467 469 471 473 475 477 479 481 483 485 487 489 491 493 495 497 499 501 503 505 507 509 511 513 515 517 519 521 523 525 527 529 531 533 535 537 539 541 543 545 547 549 551 553 555 557 559 561 563 565 567 569 571 573 575 577 579 581 583 585 587 589 591 593 595 597 599 601 603 605 607 609 611 613 615 617 619 621 623 625 627 629 631 633 635 637 639 641 643 645 647 649 651 653 655 657 659 661 663 665 667 669 671 673 675 677 679 681 683 685 687 689 691 693 695 697 699 701 703 705 707 709 711 713 715 717 719 721 723 725 727 729 731 733 735 737 739 741 743 745 747 749 751 753 755 757 759 761 763 765 767 769 771 773 775 777 779 781 783 785 787 789 791 793 795 797 799 801 803 805 807 809 811 813 815 817 819 821 823 825 827 829 831 833 835 837 839 841 843 845 847 849 851 853 855 857 859 861 863 865 867 869 871 873 875 877 879 881 883 885 887 889 891 893 895 897 899 901 903 905 907 909 911 913 915 917 919 921 923 925 927 929 931 933 935 937 939 941 943 945 947 949 951 953 955 957 959 961 963 965 967 969 971 973 975 977 979 981 983 985 987 989 991 993 995 997 999 1001 1003 1005 1007 1009 1011 1013 1015 1017 1019 1021 1023 1025 1027 1029 1031 1033 1035 1037 1039 1041 1043 1045 1047 1049 1051 1053 1055 1057 1059 1061 1063 1065 1067 1069 1071 1073 1075 1077 1079 1081 1083 1085 1087 1089 1091 1093 1095 1097 1099 1101 1103 1105 1107 1109 1111 1113 1115 1117 1119 1121 1123 1125 1127 1129 1131 1133 1135 1137 1139 1141 1143 1145 1147 1149 1151 1153 1155 1157 1159 1161 1163 1165 1167 1169 1171 1173 1175 1177 1179 1181 1183 1185 1187 1189 1191 1193 1195 1197 1199 1201 1203 1205 1207 1209 1211 1213 1215 1217 1219 1221 1223 1225 1227 1229 1231 1233 1235 1237 1239 1241 1243 1245 1247 1249 1251 1253 1255 1257 1259 1261 1263 1265 1267 1269 1271 1273 1275 1277 1279 1281 1283 1285 1287 1289 1291 1293 1295 1297 1299 1301 1303 1305 1307 1309 1311 1313 1315 1317 1319 1321 1323 1325 1327 1329 1331 1333 1335 1337 1339 1341 1343 1345 1347 1349 1351 1353 1355 1357 1359 1361 1363 1365 1367 1369 1371 1373 1375 1377 1379 1381 1383 1385 1387 1389 1391 1393 1395 1397 1399 1401 1403 1405 1407 1409 1411 1413 1415 1417 1419 1421 1423 1425 1427 1429 1431 1433 1435 1437 1439 1441 1443 1445 1447 1449 1451 1453 1455 1457 1459 1461 1463 1465 1467 1469 1471 1473 1475 1477 1479 1481 1483 1485 1487 1489 1491 1493 1495 1497 1499 1501 1503 1505 1507 1509 1511 1513 1515 1517 1519 1521 1523 1525 1527 1529 1531 1533 1535 1537 1539 1541 1543 1545 1547 1549 1551 1553 1555 1557 1559 1561 1563 1565 1567 1569 1571 1573 1575 1577 1579 1581 1583 1585 1587 1589 1591 1593 1595 1597 1599 1601 1603 1605 1607 1609 1611 1613 1615 1617 1619 1621 1623 1625 1627 1629 1631 1633 1635 1637 1639 1641 1643 1645 1647 1649 1651 1653 1655 1657 1659 1661 1663 1665 1667 1669 1671 1673 1675 1677 1679 1681 1683 1685 1687 1689 1691 1693 1695 1697 1699 1701 1703 1705 1707 1709 1711 1713 1715 1717 1719 1721 1723 1725 1727 1729 1731 1733 1735 1737 1739 1741 1743 1745 1747 1749 1751 1753 1755 1757 1759 1761 1763 1765 1767 1769 1771 1773 1775 1777 1779 1781 1783 1785 1787 1789 1791 1793 1795 1797 1799 1801 1803 1805 1807 1809 1811 1813 1815 1817 1819 1821 1823 1825 1827 1829 1831 1833 1835 1837 1839 1841 1843 1845 1847 1849 1851 1853 1855 1857 1859 1861 1863 1865 1867 1869 1871 1873 1875 1877 1879 1881 1883 1885 1887 1889 1891 1893 1895 1897 1899 1901 1903 1905 1907 1909 1911 1913 1915 1917 1919 1921 1923 1925 1927 1929 1931 1933 1935 1937 1939 1941 1943 1945 1947 1949 1951 1953 1955 1957 1959 1961 1963 1965 1967 1969 1971 1973 1975 1977 1979 1981 1983 1985 1987 1989 1991 1993 1995 1997 1999 2001 

In #5:
1000
2 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50 52 54 56 58 60 62 64 66 68 70 72 74 76 78 80 82 84 86 88 90 92 94 96 98 100 102 104 106 108 110 112 114 116 118 120 122 124 126 128 130 132 134 136 138 140 142 144 146 148 150 152 154 156 158 160 162 164 166 168 170 172 174 176 178 180 182 184 186 188 190 192 194 196 198 200 202 204 206 208 210 212 214 216 218 220 222 224 226 228 230 232 234 236 238 240 242 244 246 248 250 252 254 256 258 260 262 264 266 268 270 272 274 276 278 280 282 284 286 288 290 292 294 296 298 300 302 304 306 308 310 312 314 316 318 320 322 324 326 328 330 332 334 336 338 340 342 344 346 348 350 352 354 356 358 360 362 364 366 368 370 372 374 376 378 380 382 384 386 388 390 392 394 396 398 400 402 404 406 408 410 412 414 416 418 420 422 424 426 428 430 432 434 436 438 440 442 444 446 448 450 452 454 456 458 460 462 464 466 468 470 472 474 476 478 480 482 484 486 488 490 492 494 496 498 500 502 504 506 508 510 512 514 516 518 520 522 524 526 528 530 532 534 536 538 540 542 544 546 548 550 552 554 556 558 560 562 564 566 568 570 572 574 576 578 580 582 584 586 588 590 592 594 596 598 600 602 604 606 608 610 612 614 616 618 620 622 624 626 628 630 632 634 636 638 640 642 644 646 648 650 652 654 656 658 660 662 664 666 668 670 672 674 676 678 680 682 684 686 688 690 692 694 696 698 700 702 704 706 708 710 712 714 716 718 720 722 724 726 728 730 732 734 736 738 740 742 744 746 748 750 752 754 756 758 760 762 764 766 768 770 772 774 776 778 780 782 784 786 788 790 792 794 796 798 800 802 804 806 808 810 812 814 816 818 820 822 824 826 828 830 832 834 836 838 840 842 844 846 848 850 852 854 856 858 860 862 864 866 868 870 872 874 876 878 880 882 884 886 888 890 892 894 896 898 900 902 904 906 908 910 912 914 916 918 920 922 924 926 928 930 932 934 936 938 940 942 944 946 948 950 952 954 956 958 960 962 964 966 968 970 972 974 976 978 980 982 984 986 988 990 992 994 996 998 1000 1002 1004 1006 1008 1010 1012 1014 1016 1018 1020 1022 1024 1026 1028 1030 1032 1034 1036 1038 1040 1042 1044 1046 1048 1050 1052 1054 1056 1058 1060 1062 1064 1066 1068 1070 1072 1074 1076 1078 1080 1082 1084 1086 1088 1090 1092 1094 1096 1098 1100 1102 1104 1106 1108 1110 1112 1114 1116 1118 1120 1122 1124 1126 1128 1130 1132 1134 1136 1138 1140 1142 1144 1146 1148 1150 1152 1154 1156 1158 1160 1162 1164 1166 1168 1170 1172 1174 1176 1178 1180 1182 1184 1186 1188 1190 1192 1194 1196 1198 1200 1202 1204 1206 1208 1210 1212 1214 1216 1218 1220 1222 1224 1226 1228 1230 1232 1234 1236 1238 1240 1242 1244 1246 1248 1250 1252 1254 1256 1258 1260 1262 1264 1266 1268 1270 1272 1274 1276 1278 1280 1282 1284 1286 1288 1290 1292 1294 1296 1298 1300 1302 1304 1306 1308 1310 1312 1314 1316 1318 1320 1322 1324 1326 1328 1330 1332 1334 1336 1338 1340 1342 1344 1346 1348 1350 1352 1354 1356 1358 1360 1362 1364 1366 1368 1370 1372 1374 1376 1378 1380 1382 1384 1386 1388 1390 1392 1394 1396 1398 1400 1402 1404 1406 1408 1410 1412 1414 1416 1418 1420 1422 1424 1426 1428 1430 1432 1434 1436 1438 1440 1442 1444 1446 1448 1450 1452 1454 1456 1458 1460 1462 1464 1466 1468 1470 1472 1474 1476 1478 1480 1482 1484 1486 1488 1490 1492 1494 1496 1498 1500 1502 1504 1506 1508 1510 1512 1514 1516 1518 1520 1522 1524 1526 1528 1530 1532 1534 1536 1538 1540 1542 1544 1546 1548 1550 1552 1554 1556 1558 1560 1562 1564 1566 1568 1570 1572 1574 1576 1578 1580 1582 1584 1586 1588 1590 1592 1594 1596 1598 1600 1602 1604 1606 1608 1610 1612 1614 1616 1618 1620 1622 1624 1626 1628 1630 1632 1634 1636 1638 1640 1642 1644 1646 1648 1650 1652 1654 1656 1658 1660 1662 1664 1666 1668 1670 1672 1674 1676 1678 1680 1682 1684 1686 1688 1690 1692 1694 1696 1698 1700 1702 1704 1706 1708 1710 1712 1714 1716 1718 1720 1722 1724 1726 1728 1730 1732 1734 1736 1738 1740 1742 1744 1746 1748 1750 1752 1754 1756 1758 1760 1762 1764 1766 1768 1770 1772 1774 1776 1778 1780 1782 1784 1786 1788 1790 1792 1794 1796 1798 1800 1802 1804 1806 1808 1810 1812 1814 1816 1818 1820 1822 1824 1826 1828 1830 1832 1834 1836 1838 1840 1842 1844 1846 1848 1850 1852 1854 1856 1858 1860 1862 1864 1866 1868 1870 1872 1874 1876 1878 1880 1882 1884 1886 1888 1890 1892 1894 1896 1898 1900 1902 1904 1906 1908 1910 1912 1914 1916 1918 1920 1922 1924 1926 1928 1930 1932 1934 1936 1938 1940 1942 1944 1946 1948 1950 1952 1954 1956 1958 1960 1962 1964 1966 1968 1970 1972 1974 1976 1978 1980 1982 1984 1986 1988 1990 1992 1994 1996 1998 2000 2002
Out #5:
2002 2000 1998 1996 1994 1992 1990 1988 1986 1984 1982 1980 1978 1976 1974 1972 1970 1968 1966 1964 1962 1960 1958 1956 1954 1952 1950 1948 1946 1944 1942 1940 1938 1936 1934 1932 1930 1928 1926 1924 1922 1920 1918 1916 1914 1912 1910 1908 1906 1904 1902 1900 1898 1896 1894 1892 1890 1888 1886 1884 1882 1880 1878 1876 1874 1872 1870 1868 1866 1864 1862 1860 1858 1856 1854 1852 1850 1848 1846 1844 1842 1840 1838 1836 1834 1832 1830 1828 1826 1824 1822 1820 1818 1816 1814 1812 1810 1808 1806 1804 1802 1800 1798 1796 1794 1792 1790 1788 1786 1784 1782 1780 1778 1776 1774 1772 1770 1768 1766 1764 1762 1760 1758 1756 1754 1752 1750 1748 1746 1744 1742 1740 1738 1736 1734 1732 1730 1728 1726 1724 1722 1720 1718 1716 1714 1712 1710 1708 1706 1704 1702 1700 1698 1696 1694 1692 1690 1688 1686 1684 1682 1680 1678 1676 1674 1672 1670 1668 1666 1664 1662 1660 1658 1656 1654 1652 1650 1648 1646 1644 1642 1640 1638 1636 1634 1632 1630 1628 1626 1624 1622 1620 1618 1616 1614 1612 1610 1608 1606 1604 1602 1600 1598 1596 1594 1592 1590 1588 1586 1584 1582 1580 1578 1576 1574 1572 1570 1568 1566 1564 1562 1560 1558 1556 1554 1552 1550 1548 1546 1544 1542 1540 1538 1536 1534 1532 1530 1528 1526 1524 1522 1520 1518 1516 1514 1512 1510 1508 1506 1504 1502 1500 1498 1496 1494 1492 1490 1488 1486 1484 1482 1480 1478 1476 1474 1472 1470 1468 1466 1464 1462 1460 1458 1456 1454 1452 1450 1448 1446 1444 1442 1440 1438 1436 1434 1432 1430 1428 1426 1424 1422 1420 1418 1416 1414 1412 1410 1408 1406 1404 1402 1400 1398 1396 1394 1392 1390 1388 1386 1384 1382 1380 1378 1376 1374 1372 1370 1368 1366 1364 1362 1360 1358 1356 1354 1352 1350 1348 1346 1344 1342 1340 1338 1336 1334 1332 1330 1328 1326 1324 1322 1320 1318 1316 1314 1312 1310 1308 1306 1304 1302 1300 1298 1296 1294 1292 1290 1288 1286 1284 1282 1280 1278 1276 1274 1272 1270 1268 1266 1264 1262 1260 1258 1256 1254 1252 1250 1248 1246 1244 1242 1240 1238 1236 1234 1232 1230 1228 1226 1224 1222 1220 1218 1216 1214 1212 1210 1208 1206 1204 1202 1200 1198 1196 1194 1192 1190 1188 1186 1184 1182 1180 1178 1176 1174 1172 1170 1168 1166 1164 1162 1160 1158 1156 1154 1152 1150 1148 1146 1144 1142 1140 1138 1136 1134 1132 1130 1128 1126 1124 1122 1120 1118 1116 1114 1112 1110 1108 1106 1104 1102 1100 1098 1096 1094 1092 1090 1088 1086 1084 1082 1080 1078 1076 1074 1072 1070 1068 1066 1064 1062 1060 1058 1056 1054 1052 1050 1048 1046 1044 1042 1040 1038 1036 1034 1032 1030 1028 1026 1024 1022 1020 1018 1016 1014 1012 1010 1008 1006 1004 1002 1000 998 996 994 992 990 988 986 984 982 980 978 976 974 972 970 968 966 964 962 960 958 956 954 952 950 948 946 944 942 940 938 936 934 932 930 928 926 924 922 920 918 916 914 912 910 908 906 904 902 900 898 896 894 892 890 888 886 884 882 880 878 876 874 872 870 868 866 864 862 860 858 856 854 852 850 848 846 844 842 840 838 836 834 832 830 828 826 824 822 820 818 816 814 812 810 808 806 804 802 800 798 796 794 792 790 788 786 784 782 780 778 776 774 772 770 768 766 764 762 760 758 756 754 752 750 748 746 744 742 740 738 736 734 732 730 728 726 724 722 720 718 716 714 712 710 708 706 704 702 700 698 696 694 692 690 688 686 684 682 680 678 676 674 672 670 668 666 664 662 660 658 656 654 652 650 648 646 644 642 640 638 636 634 632 630 628 626 624 622 620 618 616 614 612 610 608 606 604 602 600 598 596 594 592 590 588 586 584 582 580 578 576 574 572 570 568 566 564 562 560 558 556 554 552 550 548 546 544 542 540 538 536 534 532 530 528 526 524 522 520 518 516 514 512 510 508 506 504 502 500 498 496 494 492 490 488 486 484 482 480 478 476 474 472 470 468 466 464 462 460 458 456 454 452 450 448 446 444 442 440 438 436 434 432 430 428 426 424 422 420 418 416 414 412 410 408 406 404 402 400 398 396 394 392 390 388 386 384 382 380 378 376 374 372 370 368 366 364 362 360 358 356 354 352 350 348 346 344 342 340 338 336 334 332 330 328 326 324 322 320 318 316 314 312 310 308 306 304 302 300 298 296 294 292 290 288 286 284 282 280 278 276 274 272 270 268 266 264 262 260 258 256 254 252 250 248 246 244 242 240 238 236 234 232 230 228 226 224 222 220 218 216 214 212 210 208 206 204 202 200 198 196 194 192 190 188 186 184 182 180 178 176 174 172 170 168 166 164 162 160 158 156 154 152 150 148 146 144 142 140 138 136 134 132 130 128 126 124 122 120 118 116 114 112 110 108 106 104 102 100 98 96 94 92 90 88 86 84 82 80 78 76 74 72 70 68 66 64 62 60 58 56 54 52 50 48 46 44 42 40 38 36 34 32 30 28 26 24 22 20 18 16 14 12 10 8 6 2 

*/

