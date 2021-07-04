/* All Tracks ---> Basic Programming  --->  Input/Output  ---> Basics of Input/Output  --->  Problem  --->
Seating Arrangement
Tag(s): Very-Easy

Akash and Vishal are quite fond of travelling. They mostly travel by railways. They were travelling in a train one day and they got interested in the seating arrangement of their compartment. 
The compartment looked something like shown in the image in docx.

So they got interested to know the seat number facing them and the seat type facing them. The seats are denoted as follows : 

Window Seat : WS
Middle Seat : MS
Aisle Seat : AS

You will be given a seat number, find out the seat number facing you and the seat type, i.e. WS, MS or AS.

INPUT
First line of input will consist of a single integer T denoting number of test-cases. Each test-case consists of a single integer N denoting the seat-number.

OUTPUT
For each test case, print the facing seat-number and the seat-type, separated by a single space in a new line.

CONSTRAINTS
1<=T<=105
1<=N<=108
SAMPLE INPUT 
2
18
40
SAMPLE OUTPUT 
19 WS
45 AS


#include <stdio.h>
#define N 108

int main()
{
    int i,l,t,n;
    int RWS[]={6,7,18,19,30,31,42,43,54,55,66,67,78,79,90,91,102,103};    
    int RMS[]={5,8,17,20,29,32,41,44,53,56,65,68,77,80,89,92,101,104};
    int RAS[]={4,9,16,21,28,33,40,45,52,57,64,69,76,81,88,93,100,105};
    int LAS[]={3,10,15,22,27,34,39,46,51,58,63,70,75,82,87,94,99,106};
    int LMS[]={2,11,14,23,26,35,38,47,50,59,62,71,74,83,86,95,98,107};
    int LWS[]={1,12,13,24,25,36,37,48,49,60,61,72,73,84,85,96,97,108}; 
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(l=0;l<N/6;l++){
            if(n==RWS[l]){
                if(l%2==0)
                    printf("%d %s\n",RWS[l+1],"WS");
                else
                    printf("%d %s\n",RWS[l-1],"WS");
            }
        }
        for(l=0;l<N/6;l++){
            if(n==RMS[l]){
                if(l%2==0)
                    printf("%d %s\n",RMS[l+1],"MS");
                else
                    printf("%d %s\n",RMS[l-1],"MS");
            }
        }
        for(l=0;l<N/6;l++){
            if(n==RAS[l]){
                if(l%2==0)
                    printf("%d %s\n",RAS[l+1],"AS");
                else
                    printf("%d %s\n",RAS[l-1],"AS");
            }
        }
        for(l=0;l<N/6;l++){
            if(n==LWS[l]){
                if(l%2==0)
                    printf("%d %s\n",LWS[l+1],"WS");
                else
                    printf("%d %s\n",LWS[l-1],"WS");
            }
        }
        for(l=0;l<N/6;l++){
            if(n==LMS[l]){
                if(l%2==0)
                    printf("%d %s\n",LMS[l+1],"MS");
                else
                    printf("%d %s\n",LMS[l-1],"MS");
            }
        }
        for(l=0;l<N/6;l++){
            if(n==LAS[l]){
                if(l%2==0)
                    printf("%d %s\n",LAS[l+1],"AS");
                else
                    printf("%d %s\n",LAS[l-1],"AS");
            }
        }            
    }
    return 0;
}

*/