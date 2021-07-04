/* Maximum goodness:
All Tracks --> Data Structures -->  Arrays --> 1-D -->  Problem -->
Tag(s): Easy
Given an Array A consisting of 0's and 1's  of length N. The goodness of a subarray is defined as difference between number of 1's  and
number of 0's  present in the subarray.Output the length of longest subarray with maximum value of goodness.
Hint: Use kadane algorithm.

Input:
The first line of Input contains Integer N.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of array A.

Output:
Print length of Longest subarray with maximum goodness value.

Constraints:
1 <= N <= 10^3
0 <= A[i] <= 1

SAMPLE INPUT 
14
1 1 1 1 0 0 1 1 0 0 0 1 0 0
0 0 0 0 1 1 0 0 1 1 1 0 1 1

SAMPLE OUTPUT 
8
Explanation
The maximum value of difference of count of 1's  and count of 0's is 4 corresponding to subarrays [1,8] and [1,4] assuming 1 based indexing of
array but longest subarray is [1,8] hence answer is 8. 

//My C Solution:
#include <stdio.h>
#include <limits.h>
#define LEN 10001

int main() {
	int n,i,j,a[LEN],diff,o=0,z=0,max=INT_MIN,index=0; 	
	scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        z=0;
        o=0;
        for(j=i;j<n;j++)
        {
            if(a[j] == 0)
                z++;
            else
                o++;
            diff=o-z;
            if( diff> max){
                max=diff;
                index=j-i+1;
            }
            if(diff == max){
                if(index<j-i+1){
                    index=j-i+1;
                }
            }
        }
    }
    printf("%d\n",index);
    return 0;
}
*/

/*
I/O:
In #1:
100
1 1 1 1 0 0 1 0 0 0 1 1 0 1 1 0 0 1 1 1 0 0 0 1 1 0 1 1 0 1 1 1 0 0 1 1 1 0 0 1 0 0 0 0 1 1 1 1 0 1 1 1 1 0 0 1 0 1 1 0 1 1 0 0 1 1 0 1 1 0 0 0 1 1 0 1 1 1 0 0 1 1 0 1 0 1 1 0 1 1 1 0 0 1 1 0 0 1 0 1
Out #1:
95
In #2:
1000
1 1 0 0 0 0 0 0 0 0 0 1 1 0 1 0 0 1 1 0 1 0 1 0 0 0 0 0 1 1 0 0 1 0 1 1 0 0 1 0 1 1 1 1 1 0 0 0 1 1 0 1 0 1 1 0 1 0 0 1 1 1 0 1 1 1 0 0 0 0 1 0 1 1 0 0 0 1 1 0 0 0 1 1 0 0 0 0 1 0 1 0 1 0 0 1 1 0 0 1 0 1 0 0 1 1 1 0 0 0 0 0 1 1 1 0 1 0 0 0 1 0 1 1 1 1 1 0 0 1 0 0 0 1 1 0 1 0 1 0 1 1 1 0 1 1 1 0 0 0 1 0 0 0 0 1 0 1 0 1 0 1 0 0 1 0 1 1 0 0 1 0 0 1 1 0 0 1 0 0 1 1 0 1 0 1 1 0 0 0 0 0 1 0 1 1 1 1 1 1 0 0 1 1 0 0 1 0 0 1 0 0 0 0 0 1 1 0 1 0 0 0 1 0 0 1 1 1 1 0 1 1 1 0 0 0 1 0 1 0 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 1 0 1 0 0 1 1 1 1 0 1 0 0 0 1 0 1 0 0 0 0 0 1 1 0 0 1 0 0 1 0 0 1 0 1 0 1 1 0 0 0 1 1 1 1 0 0 0 0 0 0 1 0 0 1 0 1 1 0 1 0 0 0 1 0 1 1 1 0 1 0 0 1 1 0 1 1 0 0 1 1 1 1 1 1 1 0 0 1 0 0 1 1 0 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 1 1 0 0 0 0 1 0 0 1 1 0 0 0 1 0 0 0 1 1 1 0 1 0 1 1 0 0 0 1 0 1 0 0 0 0 1 0 1 0 1 1 0 0 1 1 1 0 1 1 1 0 0 1 0 0 0 1 1 1 1 1 0 0 0 1 0 1 1 1 1 0 0 0 0 0 1 0 1 0 0 1 0 0 0 1 0 0 1 0 1 1 0 0 0 1 0 1 1 0 1 1 0 1 1 1 0 1 0 1 1 1 1 0 1 0 1 0 1 1 0 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 0 1 0 1 0 1 1 0 0 0 1 1 1 1 1 0 1 1 0 1 0 1 0 1 1 0 1 0 0 1 0 1 1 0 0 0 1 0 1 0 1 1 0 1 1 1 1 0 1 1 0 1 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 0 0 1 0 0 1 1 0 1 0 1 0 1 0 0 0 1 0 1 1 1 0 0 1 1 0 1 0 0 1 0 1 0 1 0 1 1 0 0 0 1 1 1 1 0 0 0 1 0 0 0 1 1 0 1 0 1 0 1 0 1 1 1 0 0 0 1 1 1 1 1 0 1 0 1 1 1 0 0 1 0 1 1 1 1 0 1 1 0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 1 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 1 0 0 0 0 1 1 0 1 0 0 1 0 1 0 1 0 0 0 0 1 1 1 0 1 0 1 0 0 1 0 0 1 1 1 0 0 1 0 1 1 1 0 1 0 0 1 0 0 0 0 1 1 0 1 0 1 0 1 0 1 1 0 0 0 0 1 0 1 0 0 1 1 1 0 0 0 1 1 1 0 0 0 1 0 1 0 0 0 0 0 0 0 1 1 0 1 0 0 0 0 0 1 1 1 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 1 1 0 0 0 1 1 1 1 1 0 0 0 0 1 0 1 0 1 0 0 0 1 0 1 0 0 1 0 0 0 0 0 1 0 1 1 1 1 1 0 0 1 1 0 1 1 0 1 1 0 0 1 1 1 0 1 1 1 1 0 0 1 1 0 1 0 0 1 0 0 0 1 1 1 0 1 1 0 1 1 1 1 0 1 1 0 0 0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 1 0 1 1 1 0 1 0 0 0 0 1 1 0 1 0 0 0 0 1 0 0 1 1 0 0 0 1 0 0 1 1 0 1 1 1 0 1 0 0 1 0 0 0 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 0 0
Out #2:
95

In #3:
999
1 0 0 1 1 0 0 1 0 1 0 0 1 1 0 0 1 0 1 1 0 1 1 1 1 1 1 1 0 0 1 0 1 0 1 1 0 0 1 0 0 0 0 0 0 0 1 0 1 1 0 0 0 0 0 1 1 1 1 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 1 1 0 0 0 1 1 0 1 0 1 0 1 0 1 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 1 0 1 0 1 1 0 0 0 1 0 1 0 0 1 1 1 1 1 1 0 1 1 0 1 0 0 1 0 0 0 0 0 0 1 1 1 1 1 0 1 0 0 1 1 1 1 1 0 0 0 0 0 1 0 1 0 1 0 1 0 0 1 1 0 1 0 0 1 0 0 0 0 1 0 1 0 0 0 1 0 1 1 1 1 1 0 0 1 0 1 0 0 0 0 1 0 1 1 1 1 1 0 0 1 0 1 1 0 0 0 0 1 1 1 1 1 0 0 1 0 0 0 0 0 1 1 1 1 0 0 1 0 1 0 1 1 0 0 0 1 0 1 0 1 1 1 1 0 1 0 0 0 0 1 0 0 1 1 1 0 1 1 1 1 0 1 1 0 0 0 0 1 1 0 1 1 1 0 1 0 0 1 1 1 0 1 0 0 0 1 0 1 0 1 1 1 0 0 1 0 0 0 0 0 0 1 0 1 1 1 1 1 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 0 1 1 0 0 1 0 1 0 1 0 1 1 0 1 0 0 1 0 0 1 1 0 0 1 1 1 1 0 0 0 1 0 1 1 1 1 1 1 0 0 1 1 0 0 0 0 0 0 1 1 0 0 0 1 1 1 1 0 0 1 0 0 1 1 1 1 0 1 0 0 0 1 0 0 0 0 0 1 0 1 0 1 1 0 0 1 1 1 1 0 1 0 1 1 0 0 0 1 1 1 1 0 1 0 0 0 0 0 0 0 0 0 1 0 1 1 1 1 0 1 0 1 0 0 0 1 0 1 1 0 1 1 1 1 1 0 0 0 0 1 1 1 1 1 0 0 0 1 1 0 0 1 0 0 0 0 0 0 0 0 1 1 1 1 1 0 0 1 1 1 1 1 1 1 1 0 0 0 0 1 1 0 1 0 0 0 1 0 0 1 0 1 1 0 1 0 1 0 1 1 0 1 0 0 1 1 1 1 1 1 1 1 0 0 1 0 0 1 1 0 0 1 0 0 0 0 1 0 0 1 1 0 0 0 0 0 0 0 1 1 0 1 1 1 0 1 1 1 1 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 1 1 0 1 1 0 1 0 0 1 1 1 0 1 1 0 1 1 0 0 0 0 0 1 0 0 0 1 0 1 1 0 0 1 1 1 1 0 0 0 0 0 1 1 0 1 1 0 0 1 0 0 0 0 1 0 0 0 1 0 1 1 1 1 0 1 0 0 1 1 0 1 1 0 1 1 1 0 1 0 0 1 1 1 0 0 0 0 1 0 1 1 1 1 1 1 1 1 0 0 1 1 0 0 0 1 0 1 1 1 0 1 0 0 0 1 1 1 1 1 1 0 1 0 0 0 0 1 1 0 1 0 0 1 0 1 0 0 1 1 1 1 0 0 1 1 0 1 1 0 0 1 1 1 0 1 1 1 1 1 0 0 0 1 0 1 1 0 1 0 0 1 1 0 1 1 1 0 1 0 0 1 0 0 1 1 1 1 0 1 0 0 1 0 0 1 1 1 0 1 1 0 0 1 1 1 1 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1 1 0 1 0 1 0 0 0 1 0 0 1 1 1 1 0 0 1 0 1 0 1 0 0 1 1 0 0 1 1 1 0 1 0 1 1 0 0 0 1 1 0 0 1 0 0 0 1 0 0 0 0 1 1 0 1 0 1 0 0 0 1 0 1 1 0 0 0 0 1 1 1 1 0 0 0 0 0 0 1 1 0 0 1 0 0 1 0 1 0 1 1 0 0 0 1 0 1 1 1 1 0 1 1 1 0 1 1 1 1 1 1 1 1 0 1 0 1 1 0 0 1 1 1 1 1 0 0 0 1 1 1 0 0 1 1 1 1 1 0 0 1 0 1 0 0 1 1 1 0 1 0 0 0 1 0 1 1 1 1 1 1 1 0 0 1
Out #3:
327

In #4:
1000
1 0 1 1 0 0 0 1 0 0 0 0 0 0 1 0 1 1 0 0 0 0 1 0 1 1 1 0 0 1 1 1 1 1 1 1 1 1 0 0 1 1 0 1 0 0 1 0 0 1 1 1 1 0 0 0 0 1 1 1 1 1 0 0 0 0 0 1 1 1 1 0 0 1 1 0 1 1 1 0 0 1 0 0 0 0 1 1 1 1 1 0 1 1 1 0 0 1 0 0 1 1 1 0 0 1 1 1 1 0 0 0 0 1 0 1 0 0 0 1 1 0 0 0 1 1 1 0 0 0 0 0 1 0 0 0 0 1 1 0 0 1 1 1 1 1 1 1 0 1 1 0 1 1 0 1 1 1 0 0 1 1 1 1 1 1 0 0 0 0 1 0 1 1 1 1 1 0 0 1 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 1 1 1 1 1 0 0 1 1 1 1 1 0 1 0 1 1 1 1 0 0 0 0 1 0 1 0 0 1 1 0 1 1 1 1 0 1 1 0 1 1 1 1 1 1 1 1 1 1 0 1 0 1 0 1 1 0 1 1 0 1 0 1 1 0 0 1 0 1 0 1 0 0 1 1 0 0 1 0 1 1 0 1 0 1 0 0 1 1 0 1 1 1 0 1 1 1 0 1 1 0 0 0 1 1 0 0 1 1 0 0 1 1 1 0 0 1 1 1 1 1 1 0 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 1 0 0 1 1 0 0 1 1 0 1 1 1 1 1 1 1 0 1 1 1 0 0 1 1 0 0 1 0 1 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 1 1 1 1 1 0 1 1 0 1 0 1 1 1 0 0 0 1 1 0 0 1 1 0 0 0 1 1 1 1 0 1 1 1 1 0 0 0 0 1 0 1 1 1 1 1 0 1 0 0 0 0 1 1 0 0 0 1 0 1 0 0 1 0 1 0 0 0 0 0 0 1 0 0 0 1 0 0 1 1 1 1 1 1 1 0 1 1 0 1 1 1 0 1 1 0 1 0 0 0 0 1 0 0 1 1 1 1 0 1 1 1 1 1 1 1 1 0 0 0 0 0 1 0 1 0 1 1 1 0 1 1 0 0 0 1 0 1 1 0 0 0 0 0 1 0 1 1 1 0 1 1 0 1 0 1 0 0 0 0 1 1 0 0 1 1 0 1 0 0 0 0 1 0 0 1 0 0 1 1 0 0 1 1 0 0 0 1 0 1 0 1 1 1 1 0 0 1 1 1 1 1 0 0 1 0 0 1 0 1 1 1 1 1 1 0 0 0 0 0 1 0 1 1 1 0 0 0 1 0 0 0 0 0 0 1 1 0 1 0 0 1 1 0 0 0 0 1 1 1 0 1 0 1 0 1 1 1 0 1 0 0 1 1 0 1 1 0 1 0 1 0 1 1 0 1 0 1 0 0 0 0 1 1 0 1 1 0 1 1 1 1 0 1 0 1 1 0 1 0 0 0 0 0 1 0 1 1 0 0 1 0 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 1 0 1 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 0 1 0 1 1 0 1 0 1 1 1 0 1 0 0 0 0 1 1 0 1 1 1 0 1 1 1 0 1 1 0 0 1 1 1 0 0 1 0 1 1 0 0 1 0 0 1 0 1 0 0 0 0 1 0 0 0 0 1 1 0 1 1 0 0 1 1 1 0 1 1 0 0 1 1 0 1 0 1 1 1 0 1 0 0 0 1 1 0 1 0 0 1 1 0 0 1 0 0 0 1 1 0 0 1 1 0 1 0 1 0 1 0 0 0 0 0 0 1 1 1 1 0 1 1 0 1 0 0 1 0 1 1 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 1 0 1 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 1 0 0 1 1 0 1 1 1 0 1 0 1 0 1 1 1 0 0 0 0 0 0 1 1 0 0 0 0 1 0 1 0 1 0 0 1 1 0 0 1 0 1 1 1 0 1 0 0 1 1 0 1 0 1 0 0 1 0 1 0 1 0 1 0 1 0 0 0 1 0 0 1 1 1 0 0 0 1 1 1 0 1 0 0 0 1
Out #4:
696

In #5:
980
1 0 0 1 1 1 0 0 0 1 1 0 1 0 1 1 0 1 1 0 1 0 0 0 1 1 1 1 0 0 1 0 0 1 1 0 0 0 0 1 1 1 1 0 0 1 0 0 1 0 0 0 1 1 0 1 1 0 0 0 0 1 1 0 1 1 0 0 0 1 0 1 0 0 0 1 1 1 1 1 1 0 1 1 0 1 1 1 1 0 0 0 1 0 1 0 1 0 1 1 0 1 0 1 1 1 0 1 0 0 1 0 0 0 1 1 0 1 0 0 1 0 1 0 1 1 0 1 0 0 1 1 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1 1 1 0 1 1 0 1 1 1 0 0 1 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 0 1 1 1 1 0 1 1 1 0 0 1 1 1 1 1 0 1 0 1 0 1 1 0 1 1 0 0 1 1 0 0 0 1 0 1 1 0 0 1 0 0 1 1 0 1 1 1 1 0 0 1 1 0 1 1 0 0 1 0 0 1 1 0 0 1 1 0 1 1 1 0 0 0 1 0 0 1 0 0 1 1 0 1 0 0 1 0 0 0 0 1 1 0 1 1 0 0 0 1 1 1 0 0 0 1 1 1 0 0 1 1 0 1 1 1 1 1 1 1 0 1 0 0 1 0 0 0 1 1 1 1 1 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 1 0 0 1 0 0 1 0 1 0 0 0 1 1 1 0 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1 1 0 0 1 0 0 0 0 0 1 0 1 0 0 1 1 1 0 0 1 0 1 0 1 0 0 1 1 1 0 1 0 0 1 1 1 0 0 1 0 0 0 1 1 0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 1 1 1 1 1 0 0 0 0 1 1 0 0 0 0 1 1 1 1 1 1 1 0 0 1 0 0 0 1 0 1 0 1 0 0 0 1 0 1 1 0 1 1 1 0 0 0 1 1 0 0 1 1 0 0 1 1 0 1 0 1 0 1 0 0 0 1 1 1 0 0 0 0 0 0 1 0 0 0 1 0 1 0 1 0 1 0 0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 1 0 0 1 0 1 0 0 0 1 1 1 0 0 1 0 1 1 1 0 0 1 0 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 1 1 0 1 1 1 1 1 0 0 1 1 0 1 0 1 0 0 1 0 1 0 1 0 1 1 1 1 1 1 1 0 0 1 1 0 0 0 0 1 1 1 0 0 1 1 1 0 1 1 0 0 1 0 0 0 1 1 0 0 0 0 1 1 0 1 0 1 1 0 1 0 0 1 0 0 0 1 0 1 1 0 0 1 1 1 1 0 0 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 1 1 0 1 0 0 0 1 1 1 1 1 0 0 1 1 1 0 1 0 0 1 0 1 0 0 1 0 1 0 0 0 1 0 1 1 0 1 0 0 1 0 1 1 1 0 0 0 1 1 0 1 0 1 1 1 1 0 1 1 1 0 1 0 0 0 1 1 0 1 1 0 0 1 0 1 0 0 0 0 0 1 1 0 1 0 1 1 0 0 1 1 1 0 1 1 1 1 1 1 0 1 0 0 0 1 1 0 1 0 1 0 1 1 1 1 0 1 1 0 0 0 0 0 1 0 1 0 1 1 1 1 1 1 1 0 1 1 1 0 1 1 0 0 1 0 1 1 1 0 0 0 1 0 1 1 0 0 1 0 0 1 1 0 1 1 1 0 1 0 0 0 0 1 0 0 0 1 0 1 0 1 1 0 1 0 0 0 1 1 0 1 1 1 1 1 0 1 1 1 0 1 1 1 0 1 1 0 1 1 1 1 1 1 0 1 1 1 1 0 0 1 1 1 0 0 0 1 0 1 0 0 1 1 0 1 1 0 1 1 0 1 1 0 0 0 0 1 1 0 0 0 1 0 1 1 1 0 0 1 1 1 1 0 1 1 0 1 1 1 1 0 1 0 1 1 1 1 1 0 0 1 1 0 1 1 1 0 0 1 1 1 1 1 0 1 0 1 1 1 0 0 1 1 0 1 1 0
Out #5:
414

In #6:
789
1 1 0 0 1 1 0 1 1 1 0 1 1 0 1 0 0 1 0 0 1 0 1 0 0 0 0 1 1 0 1 0 1 0 1 1 0 1 1 0 1 0 1 0 0 0 1 0 1 0 0 0 0 1 0 1 0 1 0 0 1 0 0 0 0 0 0 0 0 1 1 0 1 1 1 0 0 0 1 0 0 0 0 1 0 1 1 0 0 1 0 0 0 1 0 0 1 1 1 0 1 1 0 0 0 0 1 0 1 1 1 1 1 0 0 0 1 1 0 0 0 0 0 1 1 1 1 0 1 1 0 1 0 0 0 1 1 0 1 1 1 0 0 0 0 1 1 0 1 1 1 1 1 1 0 0 0 0 1 0 0 0 0 0 0 0 1 0 1 1 1 0 0 1 0 1 1 1 1 0 0 1 1 0 0 0 0 1 0 0 1 1 1 1 1 1 0 1 0 0 0 0 0 0 0 0 1 1 1 1 0 1 0 1 0 0 0 1 1 0 1 1 0 0 1 0 1 1 0 1 0 0 0 1 0 1 1 1 1 1 1 0 1 0 1 1 1 0 1 0 0 0 1 1 0 1 0 0 1 0 0 1 1 0 0 1 1 0 1 0 1 0 0 0 0 0 1 1 1 1 1 1 1 0 0 1 1 1 0 1 0 1 1 1 1 1 1 0 0 1 0 0 0 0 0 0 1 1 0 1 1 0 1 1 0 0 1 1 1 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1 1 1 0 0 1 0 1 0 1 1 0 0 1 0 0 0 1 1 1 1 1 1 1 0 1 0 1 0 1 0 0 0 1 1 0 0 1 1 1 0 1 1 0 1 1 1 1 1 0 0 0 0 0 0 1 0 1 0 0 0 1 0 1 1 1 0 1 1 1 0 1 1 1 0 0 1 0 1 1 0 0 0 0 0 1 0 1 0 0 1 1 1 0 0 0 1 0 1 0 1 1 0 1 1 0 1 1 0 0 1 1 1 1 0 1 1 0 0 1 0 0 0 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 0 0 0 0 1 0 1 1 1 0 1 1 0 0 1 1 1 0 1 1 0 1 1 0 1 1 1 0 0 0 1 0 1 1 0 1 0 1 0 0 1 0 1 0 1 0 0 1 0 0 1 1 0 0 0 0 0 0 0 0 1 1 0 0 0 1 1 1 1 1 1 1 0 1 0 1 0 1 1 0 1 1 1 1 0 0 0 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 0 0 0 0 1 0 1 0 1 0 1 1 1 0 0 1 1 0 1 0 1 0 1 0 0 0 0 1 1 0 1 0 0 0 1 0 0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 0 1 1 1 1 0 1 0 1 0 0 0 1 0 1 0 0 1 0 0 0 1 0 0 0 1 0 0 1 0 1 0 1 1 1 1 1 0 1 0 1 0 0 0 1 1 1 0 0 0 0 0 1 1 0 1 0 0 1 0 1 1 0 1 1 1 0 1 1 0 0 1 0 1 0 1 1 1 0 1 1 1 0 0 1 1 1 0 1 1 1 1 0 1 0 1 0 1 0 0 1 0 0 0 1 1 0 1 0 1 1 0 0 0 1 1 1 1 1 1 1 0 1 1 0 0 0 1 0 0 1 1 1 0 1 0 0 0 1 0 0 1 0 1 0 0 1 1 1 1 1 1 1 0 1 0 0 1 0 0 1
Out #6:
577

In #7:
908
1 1 0 0 1 0 1 0 1 0 1 0 0 0 0 0 0 0 1 0 1 0 1 0 0 1 1 1 0 0 0 0 0 0 1 1 0 0 0 0 1 1 0 1 1 0 0 1 1 0 0 0 1 0 0 1 0 1 0 0 1 0 1 1 1 1 0 1 0 0 1 0 1 0 0 1 0 0 1 0 1 1 1 0 1 1 0 0 1 1 0 1 0 1 1 0 0 1 1 0 1 1 0 1 0 1 1 1 1 0 0 0 1 0 0 1 1 1 1 1 0 1 0 0 0 1 0 0 1 0 1 1 1 0 1 0 1 0 0 0 1 1 0 0 0 0 0 0 0 1 1 1 0 1 0 1 0 0 1 1 1 1 1 0 0 1 1 0 0 1 1 0 1 0 0 1 0 1 0 0 0 1 1 0 0 1 0 1 0 0 0 1 0 1 1 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 1 1 1 0 1 1 0 1 1 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 0 0 1 1 0 0 1 1 1 1 1 1 0 0 1 1 1 1 0 0 0 1 0 1 0 0 0 0 1 1 0 1 0 1 1 1 0 0 1 1 0 0 0 0 0 1 1 0 0 0 1 0 0 1 0 0 0 0 1 1 0 0 1 0 0 0 0 1 1 1 1 1 0 1 0 1 0 0 0 0 0 0 1 1 1 0 1 1 0 0 1 1 0 0 0 0 0 1 0 0 1 0 0 1 1 0 0 1 1 1 0 0 0 0 0 0 1 1 0 1 0 1 0 1 1 0 1 0 1 1 0 0 1 1 1 0 0 1 1 0 0 0 0 0 0 0 0 1 1 0 1 1 1 1 1 0 1 1 0 0 1 0 1 1 1 0 1 1 1 0 1 1 0 0 0 0 1 0 0 1 1 1 1 1 1 1 0 0 1 1 0 0 0 1 1 0 1 1 1 0 0 1 0 1 1 1 0 1 0 1 0 1 1 0 0 0 0 1 0 0 0 0 1 1 0 1 0 0 1 0 0 0 1 0 1 0 0 1 0 0 0 0 1 0 1 0 1 0 0 1 0 0 0 1 0 0 1 1 1 0 1 0 0 0 0 1 0 0 0 1 0 1 0 1 0 0 1 0 1 1 1 0 0 1 0 0 1 0 1 1 0 1 1 0 0 0 0 0 0 0 1 1 1 0 0 0 0 1 1 0 1 1 0 0 1 0 0 1 0 0 1 1 0 1 1 0 1 1 0 1 0 1 0 1 1 0 1 1 0 0 1 0 0 1 1 0 1 1 0 1 0 0 1 1 1 0 1 0 0 0 0 0 1 0 1 0 1 1 0 0 0 0 0 0 0 1 1 0 1 1 0 0 0 0 0 1 1 1 0 1 1 1 1 0 0 0 0 1 1 1 1 1 1 0 0 1 0 1 1 0 1 1 0 0 0 1 1 1 1 1 0 1 0 0 1 0 1 1 0 0 0 0 1 0 1 0 0 1 0 0 1 1 0 1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 1 1 1 1 0 1 0 1 0 0 1 0 0 1 1 1 1 1 0 0 1 1 1 1 0 1 1 1 0 0 0 0 0 1 0 0 1 1 0 0 1 0 1 1 1 0 1 0 1 1 1 1 1 1 0 1 1 1 1 0 0 1 1 1 1 0 1 1 0 0 0 1 1 0 0 1 0 0 1 1 1 0 1 1 1 1 1 0 0 0 0 0 1 0 1 1 0 0 1 1 1 0 0 1 0 0 1 0 0 0 0 0 1 0 1 0 0 1 1 1 1 1 1 1 0 1 1 0 0 0 0 1 1 1 1 1 0 1 1 0 0 0 1 1 0 1 0 1 1 1 0 1 1 1 1 1 0 0 1 1 0 1 0 1 0 0 1 1 0 0 0 0 0 0 0 1 1 0 0 0 1 0 1 0 1 0 0 1 0 0 0 0 0 1 1 1 1 1 1 1 1 0 1 0 0 1 0 1 1 0 1 1 0
Out #7:
168

In #8:
1000
1 0 1 1 1 0 1 0 0 0 1 1 0 1 1 0 1 1 1 0 0 1 1 1 0 0 0 0 0 1 1 0 0 0 1 0 1 0 1 0 1 1 1 1 1 1 0 0 1 1 1 0 0 1 0 0 0 0 1 0 0 0 1 0 1 1 1 0 1 0 0 1 0 0 1 0 0 0 1 0 0 1 1 0 0 1 1 0 0 0 1 1 0 0 0 0 1 0 1 0 1 0 1 0 0 1 0 1 1 0 1 0 0 0 0 1 1 1 0 0 0 0 1 1 0 1 0 1 0 1 0 0 1 0 1 1 1 1 1 1 0 1 0 1 1 0 1 0 1 0 0 0 1 0 1 0 0 1 0 1 1 0 1 0 0 1 1 0 1 1 0 0 1 0 1 0 0 1 0 1 1 0 1 1 0 1 0 1 1 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1 1 1 1 0 0 1 0 1 0 0 1 1 1 1 1 1 1 0 1 1 1 0 1 1 1 0 0 1 1 0 1 0 1 0 0 0 0 0 0 0 0 1 0 0 0 1 1 0 1 1 1 1 1 0 1 0 1 1 1 0 1 1 1 0 0 0 1 1 1 1 1 1 0 1 0 1 1 1 1 0 1 1 1 1 0 0 0 1 0 0 1 0 1 1 0 1 0 0 1 1 0 1 0 1 1 1 0 0 1 1 0 1 0 1 1 0 1 0 1 1 1 1 0 1 0 1 0 1 0 0 0 0 0 0 0 1 0 1 0 1 0 1 0 0 1 0 0 1 1 0 1 1 1 0 1 0 1 0 1 1 0 1 1 1 0 0 1 0 0 1 1 1 1 1 1 1 1 1 0 1 1 1 0 1 1 0 0 1 1 0 1 1 0 0 0 0 0 0 0 0 1 0 1 1 1 1 1 1 1 0 1 1 0 0 1 1 0 0 0 0 0 0 0 0 1 0 0 1 1 1 1 1 0 1 0 1 1 1 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 1 0 0 0 1 0 1 0 0 0 1 0 1 0 1 0 1 1 0 0 1 0 1 1 1 1 1 1 1 1 1 0 1 0 1 0 1 0 0 0 0 1 0 0 1 1 1 1 1 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 0 1 1 1 1 1 0 1 0 1 0 1 0 1 1 1 1 1 1 1 1 1 0 1 1 0 0 1 1 1 1 1 1 0 1 0 0 1 1 1 0 0 1 1 0 0 0 0 0 1 1 1 0 0 0 1 1 0 1 1 1 0 1 0 0 0 0 1 1 1 1 0 0 0 0 0 1 1 1 0 1 1 1 1 0 0 1 1 0 1 0 1 1 0 0 1 0 0 1 0 0 0 0 1 1 0 1 1 0 1 1 1 1 0 1 1 1 0 0 1 0 1 0 1 1 1 1 1 1 1 0 0 1 0 0 1 0 1 1 0 0 1 0 0 0 1 1 0 1 0 0 0 0 1 0 0 1 0 0 0 1 1 0 0 1 1 0 0 1 1 1 1 1 0 0 0 0 1 0 0 1 1 0 0 0 0 0 0 0 1 1 0 1 1 0 0 0 1 1 1 0 1 1 0 1 1 0 1 0 1 1 1 0 1 0 0 0 1 0 1 1 0 0 1 1 0 0 0 0 0 0 0 1 1 0 1 0 1 1 1 0 0 1 1 1 1 0 0 1 1 1 0 1 0 1 1 1 1 1 1 0 1 1 0 1 0 1 0 1 0 1 0 1 0 0 1 1 1 0 1 1 0 0 1 0 0 0 0 0 1 0 0 1 1 0 1 1 0 0 1 0 1 0 0 1 0 1 1 1 0 0 1 0 1 0 1 1 0 1 0 0 1 1 1 0 1 1 0 1 1 0 1 1 0 1 0 0 1 1 0 0 1 0 0 1 0 1 0 0 1 0 0 1 0 1 1 1 1 0 0 1 1 1 0 1 1 0 0 1 0 0 1 1 0 0 0 0 1 1 1 1 1 1 0 0 0 1 0 0 0 1 0 1 1 0 0 1 1 1 1 0 0 1 0 1 0 0 1 0 1 0 0 1 1 1 0 1 0 1 0 1 1 0 1 0 1 0 1 1 1 0 1 1 0 0 1 0 1 0 0 1 1 0 1 0 1 1 0 1 1 1 1 0 1 1 1 0 1 1 1 1 1 0 1 1 1 0
Out #8:
794

In #9:
378
0 0 1 1 0 0 0 1 0 0 1 0 1 1 1 1 1 1 0 0 0 0 1 1 1 1 1 1 1 0 0 0 0 1 1 0 1 1 0 1 1 0 1 0 1 0 1 1 0 0 1 1 1 0 0 1 1 0 0 0 0 1 0 0 0 0 1 1 1 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 1 1 0 1 1 1 1 1 1 0 1 0 1 0 0 1 1 0 0 1 0 0 1 0 1 1 0 1 0 1 0 1 0 1 0 1 0 0 1 1 1 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 1 1 0 0 1 1 0 0 1 0 1 1 1 0 1 0 0 1 1 1 1 1 1 1 1 0 0 1 1 1 0 1 1 1 0 0 1 1 1 0 0 1 0 0 0 1 1 1 0 0 0 0 0 1 0 1 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 1 1 1 1 1 0 0 1 1 0 1 0 1 1 1 0 1 0 0 1 1 1 1 0 0 0 0 0 1 1 1 1 1 1 0 0 1 1 1 0 1 1 0 1 1 0 0 1 0 0 0 0 1 1 0 1 0 0 1 1 0 1 1 1 1 1 1 1 1 1 0 1 1 0 0 0 0 1 0 0 0 0 0 1 1 0 1 0 1 0 0 0 1 0 0 1 1 0 0 0 1 1 1 1 0 1 0 1 0 0 0 1 0 1 1 0 0 0 0 1 0 1 1 0 1 0 1 1 1 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1
Out #9:
74

In #10:
1000
1 1 1 1 0 0 0 0 0 1 0 1 1 0 0 1 1 1 0 0 1 0 0 1 0 0 0 0 0 1 0 1 0 0 1 1 1 1 1 1 1 0 1 1 0 0 0 0 1 1 1 1 1 0 1 1 0 0 0 1 1 0 1 0 1 1 1 0 1 1 1 1 1 0 0 1 1 0 1 0 1 0 0 1 1 0 0 0 0 0 0 0 1 1 0 0 0 1 0 1 0 1 0 0 1 0 0 0 0 0 1 1 1 1 1 1 1 1 0 1 0 0 1 0 1 1 0 1 1 0 0 0 0 0 1 1 1 1 0 1 1 1 1 1 0 0 0 1 0 1 1 0 0 0 0 1 1 0 1 0 1 1 1 0 0 1 0 0 1 0 0 0 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 0 1 0 0 0 1 1 0 0 0 1 0 0 1 1 0 1 0 0 1 0 0 1 1 1 1 0 1 1 0 0 1 1 1 1 0 0 1 1 0 0 0 0 0 1 0 0 1 1 0 0 0 1 0 1 1 1 1 1 0 0 0 0 1 1 1 0 0 1 1 1 1 1 0 1 1 0 1 1 0 0 1 0 1 1 0 0 1 1 1 0 1 0 0 0 0 1 1 1 1 0 0 1 0 0 1 0 0 1 1 1 1 1 1 0 0 1 1 1 0 1 1 1 0 0 1 0 1 1 1 0 1 0 1 0 1 1 1 0 0 1 0 0 1 1 0 0 0 1 1 0 0 0 0 1 1 0 0 1 0 0 0 1 0 0 1 1 1 1 1 1 1 0 1 0 0 1 1 0 0 0 0 0 1 0 0 0 0 1 1 0 1 0 1 0 1 1 0 0 1 1 0 0 1 0 1 1 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 1 1 1 0 1 0 1 0 0 0 0 1 0 0 1 0 1 0 0 1 0 0 1 0 1 1 1 1 1 0 1 1 0 0 0 1 1 1 1 1 0 0 1 0 1 0 0 1 0 1 0 1 1 0 1 1 0 0 1 1 0 0 0 1 1 0 0 0 0 0 1 1 1 0 0 1 1 1 1 1 0 0 0 0 1 0 0 1 0 0 0 1 0 0 1 0 0 0 1 0 1 0 1 0 0 0 0 1 0 1 0 0 1 0 0 1 1 1 1 1 0 1 0 0 0 1 1 1 0 1 1 1 1 1 0 1 1 0 0 1 0 1 1 0 1 0 1 0 0 0 0 0 0 1 1 0 1 0 1 0 0 0 1 1 0 1 1 1 1 1 1 0 0 0 1 1 1 1 0 0 0 1 0 0 1 0 0 0 1 0 0 0 0 1 1 1 0 1 0 1 0 1 0 0 0 1 1 0 1 0 1 1 1 0 0 0 0 1 1 1 1 1 0 0 1 0 0 0 1 0 1 1 0 0 0 0 0 0 0 1 0 0 1 0 0 1 0 0 1 1 1 1 1 1 0 0 1 1 1 0 1 0 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 0 1 0 0 0 0 1 0 0 0 0 0 1 1 1 1 0 0 1 0 1 1 1 1 0 0 0 1 1 1 1 1 0 0 1 0 0 1 1 0 0 1 0 1 1 0 0 0 1 0 0 1 0 0 0 1 1 1 1 0 0 1 0 1 0 1 0 0 0 1 1 1 1 0 1 0 0 1 0 1 0 1 0 1 1 1 0 0 1 0 1 1 0 1 1 1 1 1 1 0 1 1 1 1 0 0 0 1 1 0 0 0 1 1 1 0 1 1 0 1 0 0 1 1 0 0 0 1 0 0 0 0 1 1 1 1 1 1 1 0 0 1 0 0 1 1 1 1 1 1 0 1 1 1 1 0 1 1 1 0 1 1 0 1 0 0 1 0 0 1 1 0 0 1 0 1 1 1 1 0 0 1 0 1 1 0 0 0 0 1 0 1 1 1 1 1 1 1 0 0 0 0 1 0 0 1 0 1 1 0 1 1 1 1 1 0 1 0 0 1 0 0 1 1 0 0 1 1 0 0 0 1 1 0 1 1 1 1 0 1 1 1 1 1 1 1 1 1 0 0 1 0 0 0 0 1 0 1 0 1 0 0 1 0 0 1 1 1 0 1 1 1 0 0 1 0 1 1 0 0 0 0 1 1 0 0 1 0 1 1 0 1 0 1 1 1 0 1 1 1 0 1 1 0 0 0 1 1 1 1 0
Out #10:
965
*/


/*Best Submissions:
C:
#include <stdio.h>
 
int main(){
int n,current=0,max=0,start =0, end = 0, s=0,t=0 ;
scanf("%d", &n);
int arr[n];
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
if(arr[i]==0)
arr[i]=-1;
}
for(int i=0;i<n;i++){ // kadane Algo..to find the max sum in subarray.
current+=arr[i];
if(current>=max){
max=current;
start=s;
end=i;
}
if(current<0)
{
current=0;
s=i+1;
}
if((end-start)>=t)
t=end-start+1;
}
printf("%d",t);
return 0;
}

C++:
1).
#include <stdio.h>
 
int main(){
int n,current=0,max=0,start =0, end = 0, s=0,t=0 ;
scanf("%d", &n);
int arr[n];
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
if(arr[i]==0)
arr[i]=-1;
}
for(int i=0;i<n;i++){ // kadane Algo..to find the max sum in subarray.
current+=arr[i];
if(current>=max){
max=current;
start=s;
end=i;
}
if(current<0)
{
current=0;
s=i+1;
}
if((end-start)>=t)
t=end-start+1;
}
printf("%d",t);
return 0;
}

2).
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int n ; 
	cin>>n;
	int arr[n];
	int i;
	int n1 = 0 , first = 1 , max = 0 , k , end , max2 =0;
	stack<int> st;
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(i=1;i<=n;i++)
	{
		if(arr[i] == 1)
		{
			n1++;
		}
		if(arr[i] == 0)
		{
			n1--;
		}
		if(n1 < 0 && st.empty())
		{
			n1 = 0;
			continue;
		}
		if(n1 > 0 && st.empty())
		{
			st.push(i);
		}
		if(n1 >= max)
		{
			max = n1;
			end = i;
		}
		if((n1 < 0 && !st.empty()) || (i == n))
		{
			n1 = 0;
			int top = st.top();
			st.pop();
			k = end - top + 1;
			if(k > max2)
			{
				max2 = k ;
			}
			end = -1;
		}
	}
	cout<<max2;
}

3).
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,l=0,r=0,c=0,d=0,f=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int j=0;j<n;j++){
        l=0;
        r=0;
    for(int i=j;i<n;i++){
        if(a[i]==0)
        l++;
        else
        r++;
        if((r-l)==c){
        d=max((i-j+1),d);
        }
        if(r-l>c){
            d=i-j+1;
            c=r-l;
            
        }
    }
    }
    
    cout<<d;
    return 0;
}

C++14:
1).
#include <stdio.h>
 
int main(){
int n,current=0,max=0,start =0, end = 0, s=0,t=0 ;
scanf("%d", &n);
int arr[n];
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
if(arr[i]==0)
arr[i]=-1;
}
for(int i=0;i<n;i++){ 
current+=arr[i];
if(current>=max){
max=current;
start=s;
end=i;
}
if(current<0)
{
current=0;
s=i+1;
}
if((end-start)>=t)
t=end-start+1;
}
printf("%d",t);
return 0;
}

2).
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int j,i,n;
	cin>>n;
	int A[n];
	for(i=0;i<n;i++)
	{
		cin>>A[i];
		if(A[i]==0)
		A[i]=-1;
	}
	int ans,best=0,sum=0;
	//Algo for max subarray
	for(i=0;i<n;i++)
	{
		sum=max(A[i],sum+A[i]);
		best=max(sum,best);
	}
	//cout<<best<<endl;
	int max=-1,curr_sum;
	for(i=0;i<n;i++)
	{
		curr_sum=A[i];
		for(j=i+1;j<=n;j++)
		{
			if(curr_sum==best)
			{
				if(j-i>max)
				max=j-i;
			}
			if(curr_sum>best or j==n)
			break;
			curr_sum=curr_sum+A[j];
		}
		
	}
	cout<<max<<endl;
}

3).
#include<bits/stdc++.h>
using namespace std;
int maxsum(int arr[],int n)
{
	int max_upto_here=0;
	int subset=0;
	int curr_start=0;
	int curr_end=0;
	int max_start=0;
	int max_end=0;
	vector<int> v1;
	for(int i=0;i<n;i++)
	{
 
		subset+=arr[i];
		if(subset<0)
			{subset=0;
				curr_end=i+1;
				curr_start=i+1;
			}
		else
			curr_end=i;
		if(subset>=max_upto_here)
			{max_upto_here=subset;
				max_start=curr_start;
				max_end=curr_end;
				v1.push_back(max_end-max_start+1);
			}
	}
	sort(v1.begin(),v1.end());
	return v1[v1.size()-1];
 
	
 
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		{cin>>arr[i];
			if(arr[i]==0)
				arr[i]=-1;
		}
	cout<<maxsum(arr,n)<<endl;
}

Java:
1).
import java.io.*;
import java.util.*;
import java.lang.*;
 
class TestClass
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw=new PrintWriter(System.out);
        
        String s = br.readLine();
        int n=Integer.valueOf(s);
        
        s=br.readLine();
        String[] s1=s.split(" ");
        int[] a=new int[n];
        
        for(int i=0;i<n;i++)
          a[i]=Integer.valueOf(s1[i]);
          
          for(int i=0;i<n;i++)
            {
                if(a[i]==0)
                 a[i]=-1;
            }
            
            int start=0;
            int st=0;
            int end=0;
            
            int currsum=a[0];
            int maxsum=a[0];
            
            for(int i=1;i<n;i++)
            {
                currsum+=a[i];
                
                if(currsum<a[i])
                  {
                      st=i;
                      currsum=a[i];
                  }
                  
                  if(maxsum<=currsum)
                    {
                        maxsum=currsum;
                        start=st;
                        end=i;
                    }
            }
            
            int len=(end-start+1);
            System.out.println(len);
        
        br.close();
        pw.close();
    }
}
2).
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        String str = br.readLine();
        String[] s = str.trim().split("\\s+");
        int[] arr = new int[num];
        for(int i=0;i<num;i++){
            arr[i] = Integer.parseInt(s[i]);
            if(arr[i]==0) arr[i]=-1;
        }
        
        int sum=0,max=0,maxLen=0;
        for(int i=0;i<num;i++){
            sum=0;
            for(int j=i;j<num;j++){
                sum+=arr[j];
                if(sum>max){
                    max=sum;
                    maxLen=j-i+1;
                } else if(sum==max){
                    maxLen = j-i+1>maxLen?j-i+1:maxLen;
                }
            }
        }
        
        System.out.println(maxLen);
    }
}

3).
import java.io.*;
import java.util.*;
 
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        // Sample code to perform I/O:
        // Use either of these methods for input
        //
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s[]=br.readLine().trim().split(" ");
        int a[]=new int[n];
        int max=0,length=0,sum=0,j=0;
        for(int i=0;i<n;i++)
            a[i]=Integer.parseInt(s[i]);
        for(int i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                if(a[j]==0)
                    sum--;
                else 
                    sum++;
                if(sum>max)
                {    
                    max=sum;
                    length=j-i+1;
                }
                else if(sum==max && length <(j-i+1))
                    length=j-i+1;
            }
            sum=0;
        }
        System.out.println(length);
    }
}


Java 8:
1.04818 64 1
1.05168 64 3
1.04602 64 4
1).
import java.awt.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
public class Timepass {
    public static void main(String [] args) throws Exception {
        long MOD = (long) Math.pow(10, 9) + 7;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        StringTokenizer st=new StringTokenizer(s);
        int t=1;
 
        while(t-->0) {
            int n=Integer.parseInt(st.nextToken());
 
            s = br.readLine();
            st=new StringTokenizer(s);
 
            int maxDiffSoFar = 0;
            int maxDiffHere = 0;
            int maxLenHere = 0;
            int maxLenSoFar = 0;
            for (int i = 0; i<n; i ++) {
                int x = Integer.parseInt(st.nextToken());
                if (x == 0) {
                    maxDiffHere--;
                    maxLenHere++;
                } else if (x == 1 && maxDiffHere < 0) {
                    maxDiffHere = 1;
                    maxLenHere = 1;
                } else {
                    maxDiffHere++;
                    maxLenHere++;
                }
 
                if (maxDiffHere >= maxDiffSoFar) {
                    maxDiffSoFar = maxDiffHere;
                    maxLenSoFar = maxLenHere;
                }
            }
            System.out.println(maxLenSoFar);
        }
    }
}

2).
import java.awt.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
public class Timepass {
    public static void main(String [] args) throws Exception {
        long MOD = (long) Math.pow(10, 9) + 7;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        StringTokenizer st=new StringTokenizer(s);
        int t=1;
 
        while(t-->0) {
            int n=Integer.parseInt(st.nextToken());
 
            s = br.readLine();
            st=new StringTokenizer(s);
 
            int maxDiffSoFar = 0;
            int maxDiffHere = 0;
            int maxLenHere = 0;
            int maxLenSoFar = 0;
            for (int i = 0; i<n; i ++) {
                int x = Integer.parseInt(st.nextToken());
                if (x == 0) {
                    maxDiffHere--;
                    maxLenHere++;
                } else if (x == 1 && maxDiffHere < 0) {
                    maxDiffHere = 1;
                    maxLenHere = 1;
                } else {
                    maxDiffHere++;
                    maxLenHere++;
                }
 
                if (maxDiffHere >= maxDiffSoFar) {
                    maxDiffSoFar = maxDiffHere;
                    maxLenSoFar = maxLenHere;
                }
            }
            System.out.println(maxLenSoFar);
        }
    }
}

3).
import java.io.*;
import java.util.*;
 
public class Main{
    public static void main(String []args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int a[] = new int[n];
        
        String str = br.readLine();
        
        for(int i=0;i<n;i++)
        {
            a[i] = str.charAt(2*i)-48;
            if(a[i]==0)a[i]--;
        }
        
        int max_ending_here = 0;
        int max_so_far = 0;
        int s = 0;
        int end = 0,start = 0;
        
        for(int i=0;i<n;i++)
        {
            max_ending_here += a[i];
            
            if(max_ending_here >= max_so_far)
            {
                start =s;
                end = i;
                max_so_far = max_ending_here;
            }
            if(max_ending_here < 0 )
            {
                max_ending_here = 0;
                s = i+1;
            }
        }
        System.out.println(end-start+1);
    }
}

JavaScript(Node.js):
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
    let inp = input.split("\n");
    let n = inp[0];
    let Arr = inp[1].split(" ");
    let tempMax =0, max =0;
    let start =0, end=0, tempStart =0;
    for(let i =0; i < n; i++){
	    if(+Arr[i] === 1){
		    tempMax++;
			tempStart = tempStart || i+1;
	    } else {
		    tempMax = tempMax - 1;
	    }
 
	     if(max <= tempMax){
			start = tempStart;
		    max = tempMax;
		    end = i+1;
	    } else if(tempMax < 0) {
	        tempStart =0;
		    tempMax = 0;
	    }
    }
    console.log(end-start+1);
}
 

Python:
1).
def longestArr(arr):
    cur_sum = 0
    max_sum = 0
    start = 0
    end=0
    new_start = 0
    for ind, val in enumerate(arr):
        if val==1:
            cur_sum += 1
        else:
            cur_sum -= 1        
        if cur_sum >= max_sum:
            max_sum = cur_sum
            start = new_start
            end = ind
        if cur_sum < 0:
            new_start = ind + 1
            cur_sum = 0
    return end-start + 1
N= input()
 
x = map(int, raw_input().split())
print longestArr(x)


2).
C = int(raw_input().strip())
tab = list(map(int,raw_input().strip().split(" ")))
 
maxG = 0
maxL = 0
for i in range(len(tab)):
	cG = 0
	for j in range(i,len(tab)):
		if tab[j] == 1:
			cG += 1
		else:
			cG -= 1
		if cG > maxG :
			maxG = cG
			maxL = j-i+1
		elif cG == maxG:
			maxL = max((j-i+1),maxL)
print(maxL)

3).
N = input()
arr = map(int, raw_input().split())
max_sum = 0
current_sum = 0
start = end = 0
new_start = 0
for i in range(N):
    if arr[i] == 1:
        current_sum += 1
    else:
        current_sum -= 1
    if current_sum >= max_sum:
        max_sum = current_sum
        start = new_start
        end = i
    if current_sum < 0:
        current_sum = 0
        new_start = i + 1
 
print (end - start) + 1

Python 3:
1.05109 64 1
1.01671 64 2
1).
# Write your code here
N = int(input())
A = list(map(int, input().split()))
 
for i in range(N):
    if A[i] == 0:
        A[i] = -1
 
total = start = end = max_total = beg = 0
 
for i in range(N):
    total += A[i]
    
    if total < 0:
        total = 0
        beg = i + 1
    
    if max_total <= total:
        max_total = total
        start = beg
        end = i
 
print(end - start + 1)

2).
t=int(input())
l=list(map(int,input().split()))
ma=0
c=0
m=0
d=0
for i in range(t):
    if(l[i]==1):
        c=c+1
        d=d+1
    elif(l[i]==0):
        if(d>m and c>=ma):
            m=d
            ma=c
        c-=1
        if(c>=0):
            d+=1
        if(c<0):
            c=0
            d=0
if(d>m and c>=ma and l[i]==1):
            m=d
            ma=c        
print(m)


3).
n, c, v1, v1i, g, gl = int(input()), 0, 0, -1, 0, 0
for i, ai in enumerate(input().split()):
    if ai == '1':
        c += 1
    else:
        c -= 1
    if c < v1:
        v1, v1i = c, i
    if c - v1 > g:
        g, gl = c - v1, i - v1i
    elif c - v1 == g and i - v1i > gl:
        gl = i - v1i
print(gl)

4).
I = lambda : input() # simple string input
N = lambda : int(input()) # integer num
nl = lambda : list(map(int, input().strip().split())) # num_list
nsl = lambda : input().split() # num_str_list
 
n = N()
num_list = nl()
final_list = [num_list[0]] + [0]*(n-1)
for i in range(1, n):
    if(num_list[i] == 1):
        final_list[i] = final_list[i-1] + 1
    else:
        final_list[i] = final_list[i-1] - 1
    if(final_list[i] == -1):
        final_list[i] = 0
 
max_occurance = 0
max_index = 0
zero_index = 0
flag = False
 
for i in range(n-1, -1, -1):
    if(final_list[i] > max_occurance):
        max_occurance = final_list[i]
        max_index = i
        flag = True
    if(flag and final_list[i]==0 and final_list[i-1] == 0):
        zero_index = i+1
        flag = False
 
print(max_index-zero_index+1)

5).
input()
list1 = list(map(int,input().split()))
ma=le=curr=start=0
for i in range(len(list1)):
    if list1[i]==1:
        curr+=1
    else :
        curr-=1
    if curr<0:
        curr=0
        start=i+1
    if curr>=ma:
        ma=curr
        le = max(le,i-start+1)
print(le)

*/

