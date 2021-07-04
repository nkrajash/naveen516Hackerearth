/* All Tracks --> Algorithms --> Sorting -->  Bubble Sort  -->
Save Patients
Tag(s): Ad-Hoc, Easy, Sorting
A new deadly virus has infected large population of a planet. A brilliant scientist has discovered a new strain of virus which can cure this disease. 
Vaccine produced from this virus has various strength depending on midichlorians count. A person is cured only if midichlorians count in vaccine batch is more than midichlorians count of person. 
A doctor receives a new set of report which contains midichlorians count of each infected patient, Practo stores all vaccine doctor has and their midichlorians count. 
You need to determine if doctor can save all patients with the vaccines he has. The number of vaccines and patients are equal.

Input Format
First line contains the number of vaccines - N. 
Second line contains N integers, which are strength of vaccines. 
Third line contains N integers, which are midichlorians count of patients.

Output Format
Print a single line containing 'Yes' or 'No'.

Input Constraint
1<N<10
Strength of vaccines and midichlorians count of patients fit in integer.

Problem Setter: Practo Tech Team

SAMPLE INPUT 
5
123 146 454 542 456
100 328 248 689 200
SAMPLE OUTPUT 
No



#include <stdio.h>
int main()
{
    int n=0,i=0,j=0,k=0,l=0,flag=0;
    int *V,*P,*C;
    
    scanf("%d",&n);
    
    V=(int *)malloc(n*sizeof(int));
    P=(int *)malloc(n*sizeof(int));
    C=(int *)malloc(n*sizeof(int));
    
    for(i=0;i<n;i++)
        scanf("%d",&V[i]);
    
    for(j=0;j<n;j++)
        scanf("%d",&P[j]);
        
    i=j=k=0;
    
    for(;i<n-1,j<n-1,k<n-1;i++,j++,k++){
        if(V[i]>P[j])
            C[k]=1;
        else
            C[k]=0;
    }
    
    for(;l<n;l++){
        if(C[l]==1)
            flag=1;
        else{
            flag=0;
            break;
        }
    }
    
    if(!flag)
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}
*/

/*
Input # 1
5
123 146 454 542 456
100 328 248 689 200

Output # 1
No

Input # 2
5
10 61 55 88 17
15 76 21 73 19

Output # 2
No

*/