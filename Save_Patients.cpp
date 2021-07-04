/*
Detailed Editorial:

This question has a very short and easy solution:

as you can easily sort the vaccines and midichlorians in ascending order 
Then start a loop from the first patient and compare the vaccine with the midichlorian:

If the corresponding midichlorian for any patient is stronger than the vaccine: Just print "No" as the doctor can't save all patients.

If you complete the loop and every patient vaccine is stronger that the corresponding midichlorian
so print "Yes" .

Time Complexity: O(NlogN)

Memory Space Complexity: O(Constant * N)

Note: Constant =2 , for the 2 arrays.


#include <bits/stdc++.h>
using namespace std;

int vaccine [100000 + 10];
int patient [100000 + 10];

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);   // decrease the time of cin,, cout

    int n;

    cin >>       n         ;

    for(int i = 0; i < n; i++) cin >> vaccine[i];
    for(int i = 0; i < n; i++) cin >> patient[i];

    sort(patient, patient + n);         // sort the vaccine in ascending order
    sort(vaccine, vaccine + n);         // sort the midichlorians count in ascending order

    for(int i = 0; i < n; i++){

        if(vaccine[i] <= patient[i]){   // if at least one patient can't be rescued, print No

            cout << "No";           
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}

*/


/*
Alternate)solutions - 1

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
long int n;
cin>>n;
long int varint[n],mitro[n];
int count= 0;
for(int i = 0;i<n;i++){
cin>>varint[i];
}
for(int i = 0;i<n;i++){
cin>>mitro[i];
if(varint[i]>mitro[i]){
count++;
break;
}
}
if(count>=1){
cout<<"No"<<endl;
}else{
cout<<"Yes"<<endl;
}
return 0;
}
*/



/*
Alternate)solutions - 2
simple solution
// Sample code to perform I/O:

cin >> name; // Reading input from STDIN
cout << "Hi, " << name << ".\n"; // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i,val,s=0,s1=0;
cin>>n;
for(i=0;i<n;i++)
{
cin>>val;
s+=val;
}
for(i=0;i<n;i++)
{
cin>>val;
s1+=val;
}
if(s>s1)
{
cout<<"No"<<endl;

}
else
cout<<"Yes"<<endl;
return 0;
}
*/
