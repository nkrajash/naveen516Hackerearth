/* All Tracks -->  Algorithms --> Searching --> Linear Search --> Problem -->
Wet clothes
Tag(s): Algorithms, Linear search, Searching algorithm, Very-Easy
We have m completely wet clothes out under sunshine waiting to become dry. we are now at second t1 and it's raining. 
It's going to rain again on seconds t2...tn and after each rain clothes will be completely wet again. Cloth number i needs ai seconds to become dry. 
We can go out and collect all dry clothes at any moment but can't do this more than  times. What is the maximum number of clothes we can collect until second tn? 
Note that the duration of each rain is almost zero, so we can ignore it. Also collecting clothes does not take any time from us.

Input format:
First line of input contains three integers n,m,g(2<=n<=100,1<=m,g<=100) respectively. In the second line will be n increasing numbers denoting t1..tn(0<=t1<..tn<=10^4). 
In the Last line will have  numbers denoting a1..am(1<=ai<=10000).

Output format:
In a single line print maxmimum number of clothes we can collect.

SAMPLE INPUT 
3 3 2
3 5 8
4 1 3
SAMPLE OUTPUT 
2
Explanation
In the sample, first we go outside at time 5(exactly before rain) and take second piece of clothes. Then for the second time, at second 8, we go and take third piece.

//My C Solution:
#include <stdio.h>
#define LEN 101

int main(){
	int n,k,m,c,i,g,A[LEN],T[LEN],x=0,max=0,gap[LEN];
    scanf("%d%d%d",&n,&m,&g);
    for(i=0;i<n;i++)
        scanf("%d",&T[i]);
    for(i=0;i<m;i++)
        scanf("%d",&A[i]);
    for(k=0;k<n-1;k++){
        x=T[k+1]-T[k];
        gap[k]=x;
    }
    max=gap[0];
    for(k=0;k<n-2;k++){
        if(gap[k+1]>max)
            max = gap[k+1];
    }
    c=0;
    for(i=0;i<m;i++){
        if(A[i]<=max)
            c+=1;
    }
    printf("%d",c);
    return 0;
}

//My Python solution:
n,m,g = input().split()
t = list(map(int,input().split()))
a = list(map(int,input().split()))
gap =[]
for i in range(len(t)-1):
    x = t[i+1]-t[i]
    gap.append(x)
m = max(gap)
c=0
for i in range(len(a)):
    if a[i]<=m:
        c+=1
print(c)

*/

/*I/O:
In #1:
5 4 3
228 3617 3998 6792 9968
5 3 1 1
Out #1:
4
In #2:
100 100 100
92 128 228 239 248 255 281 285 332 414 430 481 605 618 719 734 779 1000 1038 1071 1103 1269 1418 1506 1595 1746 1925 2138 2238 2303 2524 2833 3071 3143 3281 3311 3410 3516 3660 3718 3819 3945 4241 4347 4378 4386 4402 4434 4488 4724 4902 5060 5239 5371 5413 5423 5559 5607 5695 5893 6027 6292 6309 6383 6506 6548 6691 6906 6936 6948 7218 7304 7358 7372 7706 7766 7768 7881 7896 7919 8093 8161 8348 8397 8431 8628 8778 8812 8813 8848 8868 8897 8983 9102 9119 9350 9469 9589 9789 9803
5471 4484 2772 3084 8506 6650 5872 9662 4479 4200 7423 3607 396 4704 1641 2928 5939 4548 6809 935 748 7996 8034 6093 6064 3972 2872 9112 2975 3114 6387 5506 1675 9140 7696 6376 75 2521 6895 5819 3897 1731 9590 6915 964 3395 1708 7639 3967 2909 6431 2646 7968 8727 8015 4513 8450 3359 272 510 7699 7570 4012 999 6279 4934 8127 1721 3395 209 9577 630 5363 783 576 467 9028 656 139 5290 3114 6039 2360 3401 7340 2284 3846 8482 3171 8251 8860 473 7359 7971 9313 4537 1442 424 5617 7279
Out #2:
4
In #3:
100 100 10
13 119 299 481 530 601 621 666 720 803 810 913 965 981 1274 1279 1377 1522 1599 1802 1900 2212 2318 2577 2596 2655 2892 3200 3566 3631 3695 3870 4097 4142 4216 4618 4619 4638 4969 4989 5054 5168 5272 5395 5458 5476 5660 5712 5734 5878 5976 6011 6089 6141 6162 6401 6508 6593 6655 6681 6704 6853 6888 6904 6946 7005 7047 7093 7246 7321 7331 7417 7546 7741 7850 7860 8025 8041 8160 8291 8356 8383 8448 8493 8725 8738 8800 8851 9091 9150 9228 9255 9356 9407 9547 9592 9616 9673 9751 9874
62 2475 7003 6240 7760 8569 9487 8681 508 6687 1987 1787 2247 4289 9822 6572 7083 8069 3532 548 1399 5830 9167 5664 8572 3332 6618 83 6977 1730 1045 7776 5551 6327 1804 8305 53 2414 3488 9603 8181 7493 5220 5816 581 4017 4337 3459 5536 1289 1458 8863 7379 3111 4745 7609 9664 1275 9384 8753 5550 775 7209 590 9302 9843 583 9639 1016 7642 1475 1146 7300 3196 3087 5496 4130 2571 8758 3303 5514 2430 4146 8895 1180 4256 7029 7230 9018 7825 4689 1124 1625 1972 1920 3607 7636 3664 1068 5408
Out #3:
3
In #4:
100 100 1
87 92 111 201 218 296 480 592 680 691 763 772 1006 1243 1556 1739 1847 1946 1995 2044 2051 2161 2397 2487 2531 2570 2606 2810 2839 2846 2989 3229 3235 3243 3569 3651 3662 3698 3903 3980 3984 4224 4365 4414 4580 4776 4842 4868 4887 4897 5147 5198 5244 5250 5427 5671 5672 5786 5808 5953 6069 6283 6413 6453 6488 6512 6576 6604 6620 6659 6719 6937 7045 7055 7069 7102 7190 7363 7411 7435 7439 7645 7673 7676 7681 7948 8062 8364 8614 9011 9117 9204 9227 9313 9561 9580 9647 9656 9829 9989
7607 481 6816 7217 8028 3031 8301 770 6785 1834 7018 2115 2560 8659 6054 1234 6298 4624 6738 4411 6708 9665 4820 1988 6404 3405 6071 8674 5848 459 8362 7106 8575 1786 6493 2513 6654 6073 423 644 5052 367 2 7441 2198 6980 621 1732 1068 566 1993 8236 4018 5878 8733 9435 3568 8568 9507 4409 9475 4199 4872 8065 5241 3022 6671 5314 1113 624 9183 1295 4905 2960 3473 9072 9222 4762 723 5551 9488 5209 6743 5020 410 6750 372 6362 4014 4352 2468 2063 8520 4278 6421 8376 7590 3775 5800 6146
Out #4:
3
In #5:
100 100 2
105 243 386 594 638 719 736 743 882 895 931 985 1099 1130 1280 1305 1629 1660 1711 1812 1928 1974 2087 2090 2124 2349 2376 2639 2820 2959 3005 3165 3287 3414 3510 3547 3640 3651 3712 3787 3805 3900 3923 3962 4093 4096 4111 4132 4203 4301 4363 4551 4720 5085 5095 5212 5366 5422 5450 5586 5612 5731 5999 6006 6028 6088 6108 6250 6303 6330 6536 6665 6748 6786 7324 7336 7342 7471 7611 7697 7937 8017 8068 8280 8297 8353 8364 8442 8492 8540 8716 8772 9028 9118 9467 9546 9677 9857 9917 9971
4742 6521 2451 1547 3809 6965 7422 6109 1321 7488 686 2710 9779 5530 7079 137 6119 9401 2147 428 6194 230 3394 8988 5522 7790 9924 2071 9118 5922 4129 2048 9532 4327 2850 6270 4217 2295 7109 8253 4261 2447 3756 8779 3860 8943 8798 4764 6462 3197 309 2519 3791 3282 4959 4183 1080 6651 8590 3388 4172 233 9048 6663 5300 6274 9655 6385 5148 750 3433 9780 1651 2906 2305 9008 7359 3320 4612 6536 4119 4365 574 67 8471 610 4715 1835 1183 6612 7742 6033 1412 5557 8365 4247 9742 6984 6002 612
Out #5:
6
In #6:
100 100 5
70 81 314 320 430 466 485 499 562 779 990 1007 1075 1079 1139 1414 1433 1547 1662 1681 1751 2468 2479 2602 2685 2799 3044 3060 3110 3169 3271 3332 3343 3525 3719 3791 4090 4126 4194 4277 4420 4440 4603 4683 4820 4849 4917 4947 4981 5008 5100 5119 5188 5215 5239 5270 5353 5402 5413 5492 5615 5725 5857 5988 6042 6116 6235 6400 6437 6625 6632 6654 6689 6697 6773 6918 7126 7147 7154 7329 7453 7502 7943 7992 8080 8108 8241 8300 8411 8413 8627 8703 9038 9043 9081 9260 9360 9610 9683 9724
1010 2421 8089 6523 9731 531 9790 8079 1386 3968 9396 3835 1344 7624 5541 5469 4446 7484 3294 441 9236 2592 6032 5588 5478 6379 2513 6744 9194 7177 1609 5860 3835 1676 3509 8457 553 9415 4152 5086 1623 34 2901 6972 3116 4473 1814 2866 6499 1661 5064 4546 8890 5137 3917 7266 6390 4334 9048 8045 5950 2223 5332 432 8668 822 7918 5693 6864 3493 1558 9355 2412 9686 7395 8451 2728 9492 8620 9013 4911 3744 5183 4833 673 5996 8541 9487 6128 5731 1980 6167 4099 4895 2788 649 9973 1266 4595 791
Out #6:
7
In #7:
100 100 100
99 169 183 436 439 648 724 817 829 928 957 1177 1188 1248 1315 1353 1507 1601 1998 2004 2024 2100 2226 2285 2431 2455 2673 2962 3054 3197 3239 3335 3522 4204 4260 4371 4426 4429 4453 4550 4564 4732 4733 4913 4925 4928 4961 5049 5062 5145 5256 5263 5280 5364 5379 5501 5505 5539 5542 5597 5686 5809 5908 5929 5964 5990 5995 6066 6113 6356 6728 6749 6853 6942 6945 6985 7005 7112 7263 7319 7359 7516 7630 7718 7721 7775 8115 8462 8647 8834 8955 9240 9317 9556 9614 9648 9650 9880 9961 9976
1821 5954 8995 3071 8193 4932 100 8330 1147 2283 8402 2704 3276 1003 8719 3863 4580 7004 8463 5880 4509 7947 3757 6930 4113 9495 4213 8887 6303 8916 7175 2845 1962 9211 6891 6910 4922 5336 2807 1176 7609 5883 6843 8622 5270 2184 3653 790 6678 7207 1293 6441 5006 7204 8315 6455 3962 3840 8363 4656 794 1470 640 9707 1631 6071 255 6035 242 854 4655 6917 9758 5613 8416 3507 49 975 7136 8100 1455 115 4567 8177 447 408 2461 9146 6492 6267 3615 9359 5749 4866 9262 8440 269 4837 4159 9310
Out #7:
9
In #8:
100 100 50
95 101 175 179 214 340 370 1015 1028 1041 1109 1112 1117 1176 1208 1236 1300 1302 1367 1441 1538 1647 1822 1926 1973 2216 2288 2298 2451 2495 2511 2633 2706 2735 2752 2857 2863 2902 3025 3058 3357 3471 3488 3523 3596 3613 3659 4023 4159 4168 4209 4229 4262 4468 4570 4634 4759 4892 4925 5087 5217 5359 5364 5704 5716 5839 5877 5979 6037 6155 6397 6653 6742 6772 7019 7103 7109 7245 7324 7460 7738 7927 8495 8597 8656 8815 8836 8890 8981 9241 9341 9433 9472 9485 9593 9632 9678 9679 9697 9775
3 2 2 1 3 3 2 3 3 2 3 1 1 1 3 3 3 3 2 3 1 2 3 1 3 2 2 2 3 1 2 2 3 2 2 3 1 3 3 1 1 1 1 2 3 2 2 1 3 1 2 1 3 1 2 2 1 1 1 2 3 2 1 2 1 1 1 1 3 1 1 1 2 2 2 1 3 3 1 1 1 3 2 2 3 1 2 2 1 3 3 1 1 2 3 3 2 3 1 3
Out #8:
100
In #9:
100 100 10
219 294 313 323 500 710 817 927 1072 1150 1228 1254 1358 1366 1415 1527 1594 2078 2235 2250 2317 2415 2492 2645 2876 2929 3059 3065 3543 3545 3583 3606 3619 3662 3690 3816 3819 3974 4046 4060 4091 4160 4188 4221 4247 4425 4703 4706 4737 4742 4794 5059 5091 5168 5335 5374 5407 5429 5602 6015 6163 6172 6191 6206 6242 6278 6346 6375 6440 6516 6537 6562 6654 6687 6718 6867 7023 7054 7170 7331 7397 7584 7761 7953 8052 8090 8253 8496 8714 9001 9015 9097 9099 9129 9149 9158 9166 9292 9938 9964
2469 9226 3943 811 934 4906 1958 3826 9028 9364 6270 4205 2824 8967 6604 8111 8114 5576 5409 8319 1862 351 3331 2469 2665 2807 6922 6385 9241 2289 5315 4373 5475 2417 2177 1350 187 9344 6807 8671 3159 952 4143 701 8916 1435 1094 5284 4336 3069 9325 8536 5438 2389 8954 6101 7285 5520 3877 8953 2945 2830 923 4724 4449 9923 7231 1839 9223 4807 9492 3474 7531 3303 4404 1835 7048 3506 5980 5358 1646 6812 2733 6768 1582 4494 8093 6139 9057 3124 5988 5806 6786 5022 1248 6394 2127 6639 65 1301
Out #9:
3
In #10:
100 100 10
128 270 272 282 306 425 580 719 786 789 799 835 1214 1216 1278 1347 1574 1597 1752 1881 1909 2072 2172 2226 2300 2352 2429 2489 2540 2654 2790 2806 2994 3141 3229 3333 3340 3357 3495 3558 3658 3765 3820 3860 3932 3951 3977 4158 4204 4206 4245 4380 4531 4538 4703 4749 4756 4786 4863 5379 5386 5648 5919 6124 6194 6241 6260 6428 6470 6661 6690 6767 6907 7010 7067 7220 7344 7554 7568 7628 7654 7894 7979 8206 8250 8486 8806 8930 8937 9147 9150 9177 9195 9252 9293 9436 9726 9730 9875 9885
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
Out #10:
100
In #11:
100 1 100
66 100 152 224 276 318 360 463 718 741 830 880 1003 1126 1223 1338 1383 1561 1735 1917 1976 2013 2023 2085 2091 2099 2157 2216 2446 2450 2591 2609 2784 3156 3317 3439 3475 3587 3634 3723 3811 3930 4113 4124 4315 4335 4370 4596 4868 4942 4956 5121 5203 5287 5315 5437 5505 5593 5661 5892 5962 6069 6207 6210 6414 6445 6670 6780 6926 7199 7203 7207 7308 7316 7408 7559 7586 7691 7905 7924 8002 8317 8345 8380 8394 8474 8595 8765 8848 9053 9074 9173 9234 9390 9405 9443 9603 9625 9750 9936
1
Out #11:
1
In #12:
2 1 100
2372 7241
1
Out #12:
1
In #13:
2 1 100
5348 5508
1
Out #13:
1
In #14:
2 1 100
1198 6261
8023
Out #14:
0
In #15:
2 100 5
861 3048
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
Out #15:
100
In #16:
2 100 1
1445 2276
1120 39 2032 1785 5843 9521 4478 5433 409 318 8606 3187 9794 9876 2291 1566 9300 686 9477 1271 9911 2969 9790 6462 5928 5367 8158 8151 7993 5119 744 4235 1615 6907 9202 2196 2515 2136 5561 5716 9026 9097 4939 143 8669 2165 1642 444 4730 8373 7584 6824 1377 2439 1862 7491 5215 2173 3387 5648 1350 5983 3043 3801 8875 1028 309 7770 4727 6541 4092 5617 5015 4411 6968 9333 4829 5348 9658 4444 7996 9250 9387 3442 1167 547 2677 1753 9603 1850 1704 5684 3048 2813 1351 6298 884 8677 5753 4617
Out #16:
9
In #17:
2 2 1
9999 10000
1 2
Out #17:
1
In #18:
3 3 2
1 5 10
4 5 10000
Out #18:
2
In #19:
2 1 3
0 10000
10000
Out #19:
1
*/


/* Best Submissions:
C:
#include <stdio.h>

int main()
{
int n,m,g,wet,c=0,j,flag=0;
scanf("%d %d %d",&n,&m,&g);
int t[n],a[m],i;
for(i=0;i<n;i++)
scanf("%d",&t[i]);
for(i=0;i<m;i++)
scanf("%d",&a[i]);
wet=0;
for(i=1;i<n;i++)
{
wet=t[i]-t[i-1];
for(j=0;j<m;j++)
{
if(wet>=a[j])
{
c++;
a[j]=10001;
}
}
 
}
printf("%d",c);
}

C++:
#include <iostream>
 
using namespace std;
 
int main() {
	int numOfRains, numOfCloths, maxOutTimes, maxClothCollected = 0;
	cin >> numOfRains >> numOfCloths >> maxOutTimes;										
	int rainTimeArray[numOfRains];
	int dryTimeRequired[numOfCloths];
	for (int i= 0; i<numOfRains; i++)
	    cin >> rainTimeArray[i];
	for (int i= 0; i<numOfCloths; i++)
	    cin >> dryTimeRequired[i];
	    
	for(int i =1; i<numOfRains; i++)
	{
	    int key = rainTimeArray[i] - rainTimeArray[i-1];
	    for(int i=0; i<numOfCloths;i++)
	    {
	        if(key>= dryTimeRequired[i])
	        {
	            maxClothCollected++;
	            dryTimeRequired[i]=10001;
	        }
	    }
	    
	}
	cout << maxClothCollected;
}

C++14:
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,g;
    cin>>n>>m>>g;
    int a[n],b[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int Max=INT_MIN,count=0;
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    vector<int>t;
    for(int i=1;i<n;i++)
    {
        int p=a[i]-a[i-1];
        t.push_back(p);
    }
    for(int i=0;i<t.size();i++)
    {
        Max=max(Max,t[i]);
    }
 
    for(int i=0;i<m;i++)
    {
        if(b[i]<=Max)
        count++;
    }
    cout<<count;
    return 0;
}


C#:
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace WetCLoth
{
    class Program
    {
        static void Main(string[] args)
        {
            int n, m, g, noOfTimes = 0, wet = 0;
            string[] inputs = Console.ReadLine().Split(' ');
            n = int.Parse(inputs[0]);
            m = int.Parse(inputs[1]);
            g = int.Parse(inputs[2]);
 
            int[] t = new int[n];
            int[] a = new int[m];
 
            string[] rainTime = Console.ReadLine().Split(' ');
            string[] wetTime = Console.ReadLine().Split(' ');
 
            for (int i = 0; i < n; i++)
            {
                t[i] = int.Parse(rainTime[i]);
            }
 
            for (int i = 0; i < m; i++)
            {
                a[i] = int.Parse(wetTime[i]);
            }
 
            for (int i = 1; i < n; i++)
            {
                wet = t[i] - t[i - 1];
                for (int j = 0; j < m; j++)
                {
                    if (wet >= a[j])
                    {
                        noOfTimes++;
                        a[j] = 10001;
                    }
                }
            }
 
            Console.WriteLine(noOfTimes);
        }
    }
}

Java:
import java.util.*;
 
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception 
    {
	    Scanner scanner = new Scanner(System.in);
	    String values = scanner.nextLine();
 
	    String[] valueArray = values.split(" ");
	    int[] intArray = new int[3];
	
	    int i = 0;
	    
	  //  System.out.println(valueArray[0]+valueArray[1]+valueArray[2]);
	    for(String str: valueArray ) 
	    {
		    intArray[i] = Integer.parseInt(str);
		    i++;
		
	    }
	
 
	    int n = intArray[0];	
	    int m = intArray[1];
	    int g = intArray[2];
	    
	   // System.out.println(intArray[0]+intArray[1]+intArray[2]);
	     
	    if(g<1)
	    {
	        System.out.println(0);
	        return;
	    }
	
	    int[] nArray = new int[n];
	    int[] mArray = new int[m];
	    
	    int max = 0;
	    int count = 0;
	
	    for(int x = 0;x<n;x++)
	    {
		    nArray[x] = scanner.nextInt();
	    }
	    
	
	    for(int x = 0; x<(n-1); x++) 
	    {
		    if((nArray[x+1]-nArray[x])>max) 
		    {	
			
			    max = (nArray[x+1]-nArray[x]);
			
		    }	
	    }
	
	    
	    for(int num = 0; num<m;num++)
	    {
	        mArray[num] = scanner.nextInt();
	    }
	
	    
	    for(int num = 0; num<m;num++)
	    {
		    if(max>=mArray[num]) 
		    {
			    count++;
		    }
	    }
	
	System.out.println(count);
    }
}

Java 8:
import java.util.Scanner;
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        String[] rainSplits = scanner.nextLine().split(" ");
        int greatest = Integer.parseInt(rainSplits[1]) - Integer.parseInt(rainSplits[0]);
        for(int i = 1; i < rainSplits.length - 1; i++)
        {
            int left = Integer.parseInt(rainSplits[i]);
            int right = Integer.parseInt(rainSplits[i+1]);
            if(greatest < (right - left))
            {
                greatest = right - left;
            }
        }
        String[] timeSplits = scanner.nextLine().split(" ");
        int count = 0;
        for(String time:timeSplits)
        {
            if(Integer.parseInt(time) <= greatest)
                count++;
        }
        System.out.println(count);
 
    }
}

Pascal:
Program WetClothes;
uses math;
Type arr=array[0..107] of longint;
var t,d,a:arr; n,m,g,i,j,k:longint; ans:int64;
Procedure Sort(l,r:longint; var c:arr);
var i,j,x,tmp:longint;
begin   i:=l; j:=r; x:=c[(i+j) div 2];
        repeat
        while c[i]<x do inc(i);
        while c[j]>x do dec(j);
        if i<=j then begin
        tmp:=c[i]; c[i]:=c[j]; c[j]:=tmp;
        inc(i); dec(j);
        end;
        until i>j;
        if l<j then sort(l,j,c);
        if r>i then sort(i,r,c);
end;
Procedure Count;
begin   Sort(1,n-1,d);
        ans:=0;
        for i:=1 to m do
        begin   read(a[i]);
                if a[i]<=d[n-1] then ans:=ans+1;
        end;
        writeln(ans);
end;
begin   //assign(input,'1.inp'); reset(input);
        //assign(output,'1.out'); rewrite(output);
        readln(n,m,g);
        for i:=1 to n do read(t[i]);
        Sort(1,n,t);
        for i:=1 to n-1 do d[i]:=t[i+1]-t[i];
        Count;
        //close(input); close(output);
end.

PHP:
<?php
 
fscanf( STDIN, "%[^\n]", $inputLine1 ) ;
$rainCount          =   explode( " ", $inputLine1 )[0] ;
 
$clothesCount       =   explode( " ", $inputLine1 )[1] ;
 
$maximumAttempts    =   explode( " ", $inputLine1 )[2] ;
 
fscanf( STDIN, "%[^\n]", $inputLine2 ) ;
 
$rainTimingArray    =   explode( " ", $inputLine2 ) ;
 
fscanf( STDIN, "%[^\n]", $inputLine3 ) ;
 
$dryTimingArray     =   explode( " ", $inputLine3 ) ;
$maxDifference      =   0 ;
foreach( $rainTimingArray as $key   =>  $rainTiming )
{
    if( $key    !=  0 )
    {
        $maxDifferenceBetweenRain  =    max( $maxDifferenceBetweenRain, $rainTiming  - $rainTimingArray[ $key - 1 ] ) ;
    }
}
$dryClothes     =   0 ;
foreach( $dryTimingArray as $dryTiming )
{
    if( $dryTiming  <=  $maxDifferenceBetweenRain )
    {
        $dryClothes++ ;
    }
}
echo $dryClothes ;
 
 
 
?>

Python:
# Write your code here
[n,m,g] = map(int,raw_input().split())
rain = map(int,raw_input().split())
clothes = map(int,raw_input().split())
 
intervals = []
for i in range(1,len(rain)):
    intervals.append(rain[i]-rain[i-1])
m = max(intervals)
count = 0
 
for clothe in clothes:
    if clothe<=m:
        count += 1
 
print(count)

Python 3:
nmg = [int(x) for x in input().strip().split()]
n,m,g = nmg[0],nmg[1], nmg[2]
t = [int(x) for x in input().strip().split()]
a = [int(x) for x in input().strip().split()]
 
# m clothes
# g times you can pick up
# n times it will rain
count = 0
time_dif = [t[i]-t[i-1] for i in range(1,n)]
time_dif.sort(reverse=True)
large = time_dif[0]
for i in range(m):
    if a[i]<=large:
        count+=1
print(count)

Ruby:
=begin
# Sample code to perform I/O:
 
name = gets.chomp                # Reading input from STDIN
print "Hi, #{name}.\n"           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=end
 
# Write your code here
def wetClothes(n,m,g)
    c = m.dup
    collect = []
    (1..n.size-1).each do |i|
        have_time = n[i].to_i - n[i-1].to_i
        collect << c.count{|c| c.to_i <= have_time}
    end
    collect.max
end
 
g = gets.chomp.split.last.to_i
n = gets.chomp.split
m = gets.chomp.split
puts wetClothes(n,m,g)

*/

/*Editorial:
It can be proved one action is enough to get maximum answer.
Consider i such that ti+1 - ti  is maximum possible(for 1<=i<n ).
So we can go in second ti+1 and collect all clothes that dried(aj<=ti+1 - ti).

Author Solution by parsa abdollahi:
//be name khoda :)
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
const int N = 111;
int a[N];
int main() {
	int n, m, t, mx = -1, ans = 0;
	cin >> n >> m >> t;
	rep(i, n)
		cin >> a[i];
	sort(a, a + n);
	rep(i, n - 1)
		mx = max(mx, a[i + 1] - a[i]);
	rep(i, m) {
		cin >> t;
		if(t <= mx)
			ans++;
	}
	cout << ans << endl;
	return 0;
}

Tester Solution by Amirreza Poorakhavan:
// In the name of God.
// Ya Ali!
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 1;
int n, m, g;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> g;
	int mx = 0, last, ans = 0;
	cin >> last;
	while(--n){
		int x;
		cin >> x;
		mx = max(mx, x - last);
		last = x;
	}
	while(m--){
		int x;
		cin >> x;
		ans += x <= mx;
	}
	cout << ans << '\n';
}

*/