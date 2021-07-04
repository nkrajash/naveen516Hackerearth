/* All Tracks --->  Basic Programming ---> Input/Output --->  Basics of Input/Output ---> 
Find Product
Tag(s): Very-Easy

You have been given an array A of size N consisting of positive integers. You need to find and print the product of all the number in this array Modulo 10^9 +7.

Input Format:
The first line contains a single integer N denoting the size of the array. The next line contains N space separated integers denoting the elements of the array Modulo 10^9 +7.

Output Format:
Print a single integer denoting the product of all the elements of the array Modulo .

Constraints:
1<=N<=10^3
1<=A[i]<=10^3

SAMPLE INPUT 
5
1 2 3 4 5
SAMPLE OUTPUT 
120

Explanation:
There are 5 integers to multiply. Let's store the final answer in 'answer'  variable. Since 1 is identity value for multiplication, initialize 'answer' as 1.

So the process goes as follows:
answer = 1
answer = (answer x 1) % (10^9 +7)
answer = (answer x 2) % (10^9 +7)
answer = (answer x 3) % (10^9 +7)
answer = (answer x 4) % (10^9 +7)
answer = (answer x 5) % (10^9 +7)

The above process will yield answer as 120.

#include <stdio.h>
#include <math.h>
#define N 1000

int main()
{
    long unsigned int A[N],answer=1;
    int i=0,n;
    scanf("%d",&n);
    while(n){
        scanf("%ld",&A[i]);
        answer= (int)((answer * A[i]) % (1000000007));
        i++;n--;
    }
    printf("%ld",answer);
    return 0;
}

//Editorial:

Hint: Check if your answer is overflowing the range of integer. You might want to use long long data type.

import java.util.*;
import java.lang.*;

class TestClass {
public static void main(String args[] ) throws Exception {
//Read input from stdin and provide input before running
//Use either of these methods for input
//Scanner
long p=1;
Scanner s = new Scanner(System.in);
int N = s.nextInt();
s.nextLine();
int arr[] = new int[N];

for (int i = 0; i < N; i++) {
arr[i] = s.nextInt(); 
}

for(int i=0;i<N;i++)
{
p = (long) ((p*arr[i])%(Math.pow(10,9)+7));
}
System.out.println(p);
}
}

Simple and working, C++ Solution:
#include <iostream>
#include <math.h>

using namespace std;

int main()
{

int n = 0;
int i;
long unsigned int answer = 1;
int modulo = pow(10, 9) + 7;

cin >> n;

int a[n];


for(i=0; i<n; i++)
cin >> a[i];

for(i=0; i<n; i++)
{
answer = (answer * a[i]) % modulo;

}

cout << answer;



return 0;
}

Another C++ Solution:
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
int arr[1000];
int l;
unsigned long long a=1;
unsigned const r=1000000007;
cin>>l;
for(int i=0;i<l;i++)
{
cin>>arr[i];
a=((a*arr[i])%r);

}
cout<<a;
return a;
}

I/O:
Input #1:
1000
246 667 10 462 11 119 977 817 882 599 119 908 866 109 870 18 910 169 604 766 955 393 522 434 39 379 510 404 649 615 699 574 954 898 588 574 767 459 127 398 912 25 82 602 335 711 86 162 332 328 644 999 296 882 200 844 297 264 650 221 246 761 46 756 143 593 510 900 634 115 618 180 777 420 614 41 863 946 961 999 667 470 224 107 211 80 866 759 791 903 1000 413 910 292 716 432 706 161 461 494 554 17 904 231 101 977 64 206 599 454 573 432 134 356 447 141 50 228 807 806 847 835 104 715 95 163 750 118 639 630 374 609 213 950 68 449 987 129 168 273 842 306 452 475 572 334 284 91 819 154 827 263 455 489 801 831 28 99 300 923 166 28 370 802 948 987 304 825 645 250 317 875 232 595 788 199 625 405 865 513 627 867 98 639 735 514 460 681 727 674 767 987 796 134 961 937 999 267 272 597 680 20 294 170 907 539 444 583 258 866 457 753 384 473 253 291 722 478 264 471 752 436 279 132 143 491 139 20 146 528 182 411 591 226 546 651 909 807 770 903 639 801 892 272 125 190 249 497 682 143 847 478 243 362 661 749 140 811 23 666 428 265 733 507 268 896 486 126 928 352 84 412 533 614 452 728 396 413 703 580 983 83 502 963 434 749 285 680 407 129 29 463 265 919 533 980 764 744 493 644 720 100 646 1 934 496 752 464 153 410 648 212 987 228 165 465 920 621 318 526 767 171 576 87 966 344 973 427 216 534 90 81 493 316 884 210 577 630 548 632 166 748 420 124 134 537 63 380 190 34 641 133 574 890 790 598 62 771 736 539 150 881 54 354 850 869 416 105 280 442 52 519 786 511 998 269 194 754 745 378 670 832 853 752 806 855 199 181 194 370 86 684 763 914 439 158 440 412 411 989 299 14 200 461 545 421 401 128 452 519 8 478 570 693 892 631 940 675 292 820 737 629 89 59 288 859 831 605 40 876 900 268 906 592 248 424 133 45 695 761 993 727 682 417 412 757 155 434 551 95 580 846 386 499 566 623 432 378 79 593 671 297 624 647 846 3 719 221 122 396 571 729 25 760 967 32 522 459 107 293 112 945 559 531 979 321 698 124 384 176 726 14 467 653 425 730 1 424 803 901 446 465 411 761 742 857 747 273 28 590 257 169 276 791 126 888 124 79 131 665 224 43 1 388 543 672 881 277 273 596 367 514 2 26 380 796 239 164 424 199 716 104 283 872 921 943 624 628 917 556 29 33 538 89 951 853 661 292 605 3 314 908 120 985 735 150 273 498 698 900 960 466 479 349 548 736 986 614 496 934 473 75 23 594 557 113 524 526 277 454 796 638 417 425 13 750 900 862 132 190 276 317 224 624 574 636 199 17 43 679 312 520 207 370 750 767 373 491 402 327 828 181 732 510 882 792 93 296 326 802 218 195 591 406 46 466 954 804 111 81 598 791 276 941 81 510 276 513 128 268 654 280 822 615 215 197 458 23 540 352 368 749 707 654 433 391 483 115 204 547 924 508 586 495 602 400 977 795 882 767 432 489 734 448 373 22 987 834 43 602 759 544 743 39 174 760 347 544 863 707 305 357 246 866 992 169 549 277 962 879 912 520 992 306 286 501 590 192 15 73 408 788 694 666 223 860 580 1 650 494 485 302 519 681 681 719 561 497 813 116 520 810 710 345 5 88 465 408 18 381 718 72 655 36 344 378 7 82 971 642 918 714 525 225 493 254 525 454 899 802 482 984 188 586 162 928 894 858 459 893 172 843 753 46 834 679 552 317 508 351 628 691 641 66 877 255 149 449 848 504 120 911 761 824 207 695 245 360 805 441 692 102 137 817 988 29 2 210 220 597 828 775 34 465 397 806 453 992 366 501 177 649 689 254 109 220 665 530 98 929 180 675 895 157 172 376 721 796 793 328 574 827 85 770 431 928 789 658 985 44 489 252 36 237 279 633 837 98 807 292 842 473 126 888 196 182 454 266 211 450 434 23 882 443 536 862 386 472 872 885 174 247 290 606 74 461 89 686 27 713 867 426 320 745 404 549 723 214 792 114 761 813 408 642 829 893 515 880 95 487 455 963 504 6 812 277 814 922 67 490 578 784 449 942 41 934 495 191 146 744 221 338 391 14 696 400 617 507 588 838 746 71 959 465 122 12 829 871 977 220 276 22 835 854 882 271 79 742 231 21 338 627 960 567 972 177 13 84 156 437 350 710 524 283 505 61 207 660 662 945 293 598 860 617 719 502 680 794 123 520
Output #1:
328683326

Input #2:
1000
290 112 217 950 559 866 239 367 549 141 323 967 927 267 917 681 348 478 868 325 332 391 445 738 809 573 792 662 942 877 727 131 86 723 397 657 507 511 369 921 459 960 870 657 399 973 856 586 674 679 104 133 836 851 716 534 245 29 613 880 119 737 640 62 888 967 969 361 51 937 3 813 912 480 624 694 900 926 255 726 499 435 514 297 752 805 340 230 543 735 517 954 913 104 972 958 843 695 50 379 540 500 171 370 658 737 376 540 639 233 215 920 925 659 243 158 920 741 362 191 606 8 945 142 360 138 695 648 103 20 514 148 999 1 591 136 454 100 561 272 697 452 426 841 538 298 71 614 941 553 352 278 120 769 721 948 286 4 450 801 212 463 854 586 881 227 276 130 412 987 962 82 248 195 835 398 350 766 59 16 868 108 50 649 633 436 939 829 186 763 675 804 728 194 276 615 332 985 464 472 350 72 631 616 771 115 644 389 929 886 946 571 860 214 114 741 443 318 6 696 917 725 741 725 838 600 645 540 800 240 55 110 600 208 388 53 612 464 996 474 854 828 618 915 590 755 751 832 964 877 191 448 89 57 224 837 970 918 81 595 869 398 353 869 617 934 991 742 773 65 506 274 243 476 710 975 723 486 746 130 135 139 714 2 119 229 929 953 531 295 284 876 577 269 849 175 798 516 178 230 924 610 154 599 635 639 253 928 68 336 674 993 791 535 621 788 250 61 643 448 734 855 751 368 36 244 516 758 564 768 853 698 30 899 530 634 186 996 261 364 437 341 143 175 906 638 341 187 123 101 824 209 870 668 457 860 334 271 947 246 81 368 662 507 562 469 430 977 779 974 375 693 249 37 250 345 29 987 114 34 378 886 561 538 497 959 863 820 426 141 201 205 618 89 216 191 827 853 668 139 947 762 437 878 65 145 390 175 525 395 164 177 784 406 455 739 657 658 927 807 89 394 276 48 587 58 15 371 807 276 878 716 555 723 8 117 300 707 384 740 998 940 814 38 461 188 247 650 606 227 256 192 623 799 729 117 394 323 380 179 260 410 380 58 316 95 443 585 893 736 961 957 71 607 304 797 535 410 537 503 498 465 690 686 830 843 301 365 92 599 74 849 149 336 938 789 778 210 484 807 672 764 966 651 473 459 885 556 56 815 983 187 234 761 669 534 928 662 41 301 761 818 596 308 558 985 429 800 810 712 952 270 675 752 373 863 962 489 560 764 673 203 674 322 774 830 925 156 955 169 851 614 611 511 38 232 99 430 772 767 193 372 865 122 830 417 21 87 140 5 857 30 646 407 500 965 914 149 553 923 567 916 400 817 359 203 43 749 308 111 27 612 410 585 911 641 910 254 535 66 522 19 463 860 766 173 662 593 984 309 775 76 97 732 98 97 550 76 723 498 30 48 542 459 273 596 136 107 47 28 849 157 928 191 669 91 203 859 864 655 665 767 276 116 142 279 927 863 693 911 709 842 305 380 756 965 728 716 182 286 269 645 392 681 813 292 250 177 817 728 288 874 309 185 71 209 842 612 834 25 565 828 794 484 568 762 572 652 600 875 781 410 844 197 704 145 245 751 469 650 301 772 915 835 363 513 340 384 295 703 486 78 847 577 347 971 645 39 17 834 341 77 785 91 976 21 819 317 286 253 460 107 364 261 948 57 670 529 277 96 237 737 66 529 866 570 328 377 346 863 174 556 793 245 997 205 43 360 111 546 692 652 617 454 242 337 31 832 887 494 83 526 694 848 226 818 502 186 645 273 560 44 716 348 339 911 868 726 37 249 383 212 125 562 43 62 811 955 290 538 929 791 716 948 587 14 79 717 715 170 866 789 358 786 446 339 488 197 787 417 836 590 6 198 813 497 98 392 926 980 344 325 717 369 985 179 151 960 706 707 217 236 74 781 825 245 224 584 337 991 827 868 326 695 984 642 664 756 147 374 609 839 379 315 781 713 653 474 727 61 289 474 636 835 613 202 948 631 810 577 936 363 562 44 919 779 290 869 360 707 609 479 18 368 276 302 88 459 686 922 43 275 252 962 346 115 99 866 560 829 131 479 31 376 477 995 962 895 610 670 581 78 93 881 636 490 746 265 379 853 569 170 627 429 395 440 631 993 11 142 602 944 817 471 281 869 565 251 439 90 95 280 363 856 240 774 665 954 284 813 730 982 560 951 630 725 704 700 398 239 844 770 512 410 61 316 211 429 429 613 930 447 474 171 319 19 359 345 978 642 948 177 202 534 18 160 648 698 369 925
Output #2:
115327841

Input #3:
1000
444 683 327 712 158 766 216 46 342 203 673 709 285 556 761 492 141 89 896 905 442 851 296 876 633 807 306 770 105 332 647 538 625 173 103 229 935 239 70 474 228 902 937 117 45 737 524 955 499 564 229 692 304 806 250 667 914 605 605 148 615 120 860 139 36 787 838 60 460 929 539 904 435 705 977 568 566 200 191 424 409 891 157 97 668 286 143 934 993 642 476 716 369 474 426 586 60 135 803 869 359 751 526 735 292 79 228 559 129 163 170 349 356 559 883 357 576 790 895 477 822 191 919 277 979 497 979 383 573 579 404 342 718 771 959 245 287 738 180 963 862 448 924 31 501 960 694 837 823 770 518 138 770 548 605 231 906 579 195 263 114 809 646 581 980 795 972 386 610 87 414 33 568 444 692 120 584 369 428 58 790 575 566 415 187 506 777 958 507 406 280 870 924 782 564 646 236 304 523 717 529 344 399 973 927 525 747 243 845 795 605 409 781 982 719 507 527 211 723 507 100 31 969 156 627 675 86 490 46 414 44 907 965 704 801 180 283 520 935 506 131 329 370 994 37 591 301 180 826 802 275 884 55 841 989 970 575 9 157 255 810 230 838 428 543 15 490 421 358 989 570 343 725 555 326 537 208 367 556 5 817 654 391 144 791 792 608 556 633 976 79 13 843 645 80 905 971 703 14 370 627 951 154 674 105 275 524 239 779 272 862 2 557 470 162 428 457 827 542 12 882 279 686 556 895 691 536 103 781 969 554 513 911 734 251 108 882 246 682 392 129 953 356 888 570 954 345 465 903 758 27 341 185 258 619 330 878 109 425 298 76 713 969 709 246 282 253 639 81 759 522 141 420 790 45 510 442 522 721 733 334 287 573 593 224 557 396 157 482 47 990 194 80 391 745 961 781 534 484 373 229 408 559 73 90 921 441 141 605 680 21 696 301 963 727 723 290 843 477 553 149 688 238 277 960 132 404 281 370 325 568 170 193 80 403 41 366 743 853 33 522 720 720 53 573 260 933 763 472 148 686 728 820 194 667 962 731 642 893 370 550 143 508 160 238 782 193 516 442 245 157 214 625 266 269 244 354 225 403 495 717 581 643 12 512 617 998 899 987 742 216 970 732 307 365 718 350 369 517 902 132 557 355 362 282 650 94 602 147 701 438 592 310 378 266 1 259 996 662 595 779 171 196 833 44 446 456 780 818 935 802 542 358 957 301 771 46 351 590 228 817 590 557 107 301 357 696 653 610 860 375 664 504 864 961 730 461 705 422 686 43 786 896 498 207 564 462 403 900 864 135 420 215 168 215 687 481 733 8 422 271 811 373 80 99 563 197 564 364 588 616 689 551 730 389 760 750 216 858 323 29 883 40 165 951 462 384 147 925 330 870 999 583 603 213 406 149 119 466 41 90 562 408 73 542 55 240 294 987 567 455 570 695 526 103 873 683 838 647 352 79 160 155 591 963 593 440 225 517 715 584 435 348 633 902 208 498 683 768 477 330 181 892 580 50 350 378 647 416 767 643 627 915 523 967 910 219 954 321 574 748 491 412 591 1000 996 953 234 618 807 294 938 205 511 111 295 977 566 880 294 413 710 423 186 343 182 563 466 884 280 810 269 692 608 350 160 887 247 408 997 779 116 958 721 9 179 878 864 906 717 595 304 898 502 822 827 906 410 660 614 908 289 217 941 632 873 474 976 278 236 618 577 70 890 352 992 704 940 944 87 326 701 120 661 408 229 611 877 16 307 252 658 316 505 123 260 26 436 645 37 974 873 484 597 374 730 156 660 241 340 97 543 278 535 711 438 169 176 185 790 448 642 930 853 858 36 277 458 231 67 742 688 368 549 185 971 599 888 757 555 623 402 633 666 278 977 291 706 308 458 285 449 760 615 191 56 930 155 34 754 40 342 691 193 870 687 180 794 7 688 866 827 567 89 840 428 27 776 874 411 669 750 449 550 851 307 579 645 549 384 179 355 80 82 707 853 321 892 609 282 794 74 121 500 415 655 979 643 66 988 614 556 190 213 709 759 823 101 740 563 991 994 493 128 388 821 448 824 89 364 897 496 153 519 958 752 168 615 645 374 118 705 494 408 30 207 126 907 907 190 889 802 158 834 163 713 262 445 464 410 779 871 364 764 262 331 346 438 698 655 685 472 212 84 965 233 807 144 372 154 167 211 422 101 73 992 118 924 147 638 136 961 885 831 612 398 460 706 310 676 872 886 629 869 532 956 260 972 741 625 526 702 912 409 883 350 219 99 514 102
Output #3:
688773086

Input #4:
1000
926 104 609 286 783 862 893 328 494 380 755 2 370 882 707 778 141 387 222 835 876 177 328 603 695 857 826 784 555 151 465 417 176 554 953 790 945 465 663 457 932 349 986 173 461 927 484 3 207 488 766 670 142 53 602 640 334 736 925 132 456 665 213 704 948 663 252 953 277 766 926 102 197 159 785 825 16 756 675 868 135 227 996 984 328 986 103 130 22 934 788 145 646 4 146 105 684 901 947 698 817 6 347 694 172 749 418 870 257 2 66 543 574 601 759 601 522 31 217 745 541 43 713 989 363 79 451 165 867 908 936 424 281 56 227 286 292 550 849 187 475 147 861 799 445 303 947 244 438 333 222 668 645 588 891 186 34 702 220 250 571 644 112 188 13 872 478 455 273 988 907 432 228 361 169 438 270 308 268 122 536 231 358 193 352 301 13 545 152 613 621 129 895 998 810 881 204 801 258 898 168 15 853 823 384 417 543 142 303 994 222 402 720 121 436 781 271 570 387 820 67 350 99 898 576 289 765 177 180 540 782 470 747 556 48 516 686 916 547 748 548 555 413 896 741 373 169 723 920 84 595 222 699 991 828 727 178 787 29 233 13 235 822 698 205 500 923 901 764 731 699 370 686 399 100 91 941 177 617 589 317 627 42 892 705 42 50 927 866 126 14 916 198 595 87 104 957 196 634 415 672 389 877 225 496 861 146 747 4 403 389 76 154 369 875 663 39 458 458 519 905 905 830 275 375 94 702 372 918 306 455 203 809 942 691 96 851 248 467 913 798 414 146 132 980 156 30 158 264 547 872 305 516 97 576 862 503 502 71 250 246 507 122 530 301 901 530 15 566 877 883 10 648 626 34 826 702 837 942 451 77 942 68 598 399 772 667 385 637 494 686 400 696 387 322 990 937 340 915 66 531 58 2 661 702 49 193 776 735 187 785 739 140 402 647 448 813 463 174 907 656 726 905 74 4 280 498 739 196 151 755 911 264 335 729 513 59 525 659 419 766 725 195 961 328 945 378 912 72 933 743 674 77 122 963 498 849 791 391 554 195 751 369 727 695 1 529 119 526 183 543 917 334 607 546 331 856 182 563 12 308 697 963 968 792 882 251 4 653 569 121 658 900 137 846 985 620 672 214 633 880 296 939 326 920 781 892 41 423 963 218 219 262 625 829 886 586 109 837 233 574 934 753 856 114 209 256 407 176 620 952 821 756 591 884 711 248 149 489 506 867 320 469 377 583 354 83 788 1 528 605 741 603 638 157 46 595 320 620 271 290 947 743 202 1 614 226 787 13 226 473 915 879 616 183 988 212 60 273 644 915 450 402 498 248 714 579 202 998 603 761 774 929 634 869 949 604 937 641 542 956 671 562 815 75 174 922 589 481 274 913 552 116 721 404 251 354 568 239 473 128 4 61 139 395 186 997 642 534 652 748 599 225 80 532 659 416 126 194 197 198 988 191 268 769 457 88 314 121 217 442 179 563 907 261 579 844 391 990 341 609 190 902 868 117 89 176 721 574 909 708 894 55 864 909 823 165 951 2 341 486 69 292 463 991 364 310 393 446 95 222 937 809 79 188 461 196 626 753 828 851 833 342 443 764 995 235 586 585 343 191 589 860 449 545 245 755 100 239 366 580 204 931 997 949 725 992 623 399 554 641 233 412 395 81 614 828 948 102 593 13 205 657 465 104 750 779 748 175 99 321 332 371 990 237 167 351 912 830 656 616 357 162 397 595 177 774 916 402 371 56 789 53 673 399 421 407 86 675 467 861 364 832 800 63 7 80 807 1000 743 269 57 37 780 315 814 967 271 747 514 547 37 673 826 761 298 991 274 763 244 716 617 328 23 628 193 587 660 727 387 701 477 778 818 53 147 534 820 393 313 16 261 13 980 429 814 617 560 470 805 49 72 301 836 798 768 8 810 23 522 401 471 69 585 353 252 502 20 129 596 609 453 688 753 446 913 673 879 940 476 555 313 893 997 252 28 80 78 196 677 134 586 777 45 809 512 380 873 92 592 761 120 232 132 251 162 61 281 50 222 617 790 318 25 362 887 185 812 580 103 309 174 521 267 788 496 966 57 168 467 977 969 802 192 877 365 71 365 145 806 144 180 483 366 501 618 362 779 151 130 819 565 442 297 615 862 558 998 39 132 273 419 983 152 461 632 621 255 713 716 842 941 959 959 635 13 739 545 501 858 595 161 83 694 661 191 253 709 17 789 645 353 639 972 196 293 546 464 287 908 469 16 590 776 316 47 985 406 715 321
Output #4:
281890757

*/


/* Best Submissions:
Bash:
# Sample bash code
#! /bin/bash
# // https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/find-product/
# echo $(man eval);
read n;
# declare -a array;
read array;
p=1000000007;
k=1;
# array=$(echo $array | tr ' ' '*' | bc);
for i in $array
do
    k=$(( ($k * $i) % $p ));
done;
echo $k;


C:
#include <stdio.h>
 
int main()
{
    unsigned N, i, answer = 1;
    
    do
    {
    scanf("%d", &N);
    }
    while(N < 1 && N > 1000);
    
    long int a[N];
    
    for(i = 0; i < N ; i++)
    {
    	do
    	{
    		scanf("%li", &a[i]);
    	}		
    	while(a[i] < 1 && a[i] > 1000);
    }
 
    for(i = 0; i < N; i++)
    {
    	answer = (answer * a[i]) % (1000000007);
    }
    printf("%i", answer);
}
C++:
#include <iostream>
#include<math.h>
using namespace std;
 
int main()
{
    int n;
    long int ans=1;
    cin>>n;
    int a[n],m=pow(10,9)+7;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0)
        a[i]=-a[i];
        ans=(ans*a[i])%m;
    }
    cout <<ans<< endl;
    return 0;
}

C++14:
#include<iostream>
using namespace std;
int main() {
    long long ans=1,n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        ans=(ans*x)%1000000007;
    }
    cout<<ans;
}
C#:
using System; 
using System.Numerics;
class MyClass {
    static void Main(string[] args) {
        int length = Convert.ToInt32(System.Console.ReadLine());
        
        var strArray = System.Console.ReadLine().Split(' ');
        
        double answer = 1;
        var func = Math.Pow(10,9)+7;
        foreach(var str in strArray)
        {
        	var num = Convert.ToInt32(str);
        	answer = (answer*num)%func;
        }
        
        System.Console.WriteLine(answer);
    }
}
Java:
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class FindProduct {
 
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		long N = 1_000_000_007;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		br.readLine();
		StringTokenizer st = new StringTokenizer(br.readLine());
		long res = 1;
		while (st.hasMoreTokens()) {
			res = ((res % N) * (Integer.parseInt(st.nextToken()) % N)) % N;
		}
		System.out.println(res);
		br.close();
	}
 
}


JAVA 8:
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
      
        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String arrayStr = br.readLine();
        String[] str = arrayStr.split(" ");
        long prod = 1;
        for(int i =0; i<N; i++){
            prod = (prod * Integer.parseInt(str[i])) % ((long)Math.pow(10,9) +7);
            
        }
        System.out.println(prod);    
 
      
    }
}
Java(Rhino):
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);
var input = sc.nextInt();
var ans=1;
for(var i=0;i<input;i++)
{
	var n=sc.nextInt();
	ans*=n;
	ans=ans%(1000000000+7);
}
print(ans);

Java(Node.js):
function main(input) {
    var numbers=input.split('\n')[1].split(' '),output=1;
    for(var i=0;i<numbers.length;i++){
        output=(output*numbers[i])%1000000007;
    }
    process.stdout.write(output);
}
 
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;
});
 
process.stdin.on("end", function () {
   main(stdin_input);
});
 
Pascal:
const q=1000000007;
var a:array[1..1000000]of longint;
    n:longint;
 
procedure nhap;
var i:longint;
begin
    readln(n);
    for i:=1 to n do read(a[i]);
end;
 
procedure xuli;
var i:longint;s:qword;
begin
    s:=1 ;
    for i:=1 to n do
        s:=(s*a[i]) mod q;
    writeln(s);
end;
 
begin
    nhap;
    xuli;
end.

Perl:
use strict;
 
=comment
# Read input from stdin and provide input before running code
 
# Echo input to output.
 
 
=cut
my @input;
 
while(my $fred = <STDIN>) {
    chomp $fred;
    push(@input, $fred);
}
 
my $answer = 1;
for(split(/ /,@input[1])){
    $answer = ($answer * $_) % (1000000007);
}
 
print $answer;

PHP:
<?php

//Read input from stdin and provide input before running code
//fscanf(STDIN, "%s\n", $name);
//echo "Hi, ".$name;
 
$a = intval(fgets(STDIN));
$a = trim(fgets(STDIN));
$a = explode(" ",$a);
$ans = 1;
foreach($a as $v){
	$ans = ($ans*$v)%(pow(10,9)+7);
}
echo $ans;
 
 
?>


Python:
no_of_integer = raw_input()
integers = raw_input().split()
answer = 1
for value in integers:
    value_int = int(value)
    answer=(answer*value_int)%(10**9+7)
print(answer)

Python 3:

import sys
n = int(input(""))
value = 1
list1 = list(map(int,input().split()))
for i in range(n):
	value = (value * list1[i]) % (1000000007)
 
print(value)

R(Rscript):
a <- scan("stdin", skip=1, quiet=TRUE)
temp <- 1
for (i in 1:length(a)) {
temp <- ((temp * a[i]) %% (10^9 + 7))
}
write(temp, "")

Ruby:
=begin
# Read input from stdin and provide input before running code
 
print "Please enter your name: "
name = gets.chomp
print "Hi #{name}\n"
=end
 
size = gets.chomp.to_i
input = gets.chomp
input_arr = []
product = 1
input.split(" ").each do |s|
  input_arr << s.to_i 
end
 
input_arr.each do |i|
	product = (product * i) % (10**9 + 7)
end
 
puts product

VB:
Module Main
 
    Sub Main()
        Dim A() as string
        Dim N as integer
        Dim r as integer
        Dim x as integer
        
        N = console.readline()
        A = split(console.readline())
        r = 1
        
        for x = 0 to N-1
        	r = (r * A(x)) Mod ((10^9) + 7)
        next 
        
        console.writeline(r)
        
        
    End Sub
 
End Module


*/