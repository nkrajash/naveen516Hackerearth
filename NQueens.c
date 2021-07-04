/* All Tracks --> Basic Programming  -->  Recursion  -->  Recursion and Backtracking  -->   Problem
N-Queens
Tag(s): Backtracking, Easy
Given a chess board having NxN cells, you need to place N queens on the board in such a way that no queen attacks any other queen.
Input:
The only line of input consists of a single integer denoting N.

Output:
If it is possible to place all the N queens in such a way that no queen attacks another queen, then print N lines having N integers. 
The integer in ith line and jth column will denote the cell (i,j) of the board and should be 1 if a queen is placed at (i,j) otherwise 0. 
If there are more than way of placing queens print any of them. If it is not possible to place all N queens in the desired way, 
then print "Not possible" (without quotes).

Constraints:
1<=N<=10.

SAMPLE INPUT 
4
SAMPLE OUTPUT 
0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 

//My C Solution:
#include <stdio.h>
#define N 11
 
void solveNQ(int);
int solveNQBacktrace(int NQueens[N][N],int col,int n );
void printNQueens(int NQueens[N][N],int n);
int isSafe(int NQueens[N][N], int row, int col );
 
 
int main(){
    int n=0;
    fscanf(stdin,"%d",&n);
 
    solveNQ(n);
    return 0;
}
 
int isSafe(int Nqueens[N][N], int row, int col)
{
    int i, j;
 
    // Check this row on left side
    for (i = 0; i < col; i++){
        //printf("%d ", Nqueens[row][i]);
        if (Nqueens[row][i])
            return 0;
    }
        
    // Check upper diagonal on left side
    for (i=row, j=col; i>=0 && j>=0; i--, j--){
        //printf("%d ", Nqueens[i][j]);
        if (Nqueens[i][j])
            return 0;
    }
 
    // Check lower diagonal on left side
    for (i=row, j=col; j>=0 && i<N; i++, j--){
        //printf("%d ", Nqueens[i][j]);
        if (Nqueens[i][j])
            return 0;
    }
 
    return 1;
}
 
 
void solveNQ(int n){
    int Nqueens[N][N]={
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},        
    };
 
    if(solveNQBacktrace(Nqueens,0,n))
        printf("Not possible\n");
    else
        printNQueens(Nqueens,n);
}
 
int solveNQBacktrace(int Nqueens[N][N],int col,int n){
    int i=0;
 
    if (col >= n)
        return 0;
 
    for (; i < n; i++)
    {
        if ( isSafe(Nqueens, i, col) )
        {
            Nqueens[i][col] = 1;
 
            if (!solveNQBacktrace(Nqueens, col + 1,n) )
                return 0;
 
            Nqueens[i][col] = 0;//Back track
        }
    }
    return 1;
}
void printNQueens(int NQueens[N][N],int n){
    int i,j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
            printf("%d ", NQueens[j][i]);
			//printf("%d ", NQueens[i][j]); Prints  the same solution in another way
        printf("\n");
    }
}

*/

/*Best Submissions:
C:
#include <stdio.h>  
#include <stdlib.h>  
  
// every row must be a queen, array value is some queen's column
void printBoard(int rowQueen[], int n)  
{  
	int i,j;  
	for(i = 0; i < n; i++)        //?  
	{                  
		for(j = 0; j < n; j++)    //?  
		{  
			if(rowQueen[i] != j)  
				printf("0 ");  
			else   
				printf("1 ");   
		}  
		printf("\n");  
	}  
 
}  
 
// checking for row and col
int is_attacked(int rowQueen[], int row, int col)    
{  
	int row1 = 0;  
	while (row1 < row)
	{  
		if(rowQueen[row1] == col 
				|| abs(row1 - row) == abs(rowQueen[row1] - col))
		{
			return 1;  
		}
 
		row1++;  
	}  
 
	return 0;  
 
}  
 
void nqueens(int rowQueens[], int row, int n)    
{  
	if( row < n )  
	{  
		for(int col = 0; col < n; col++)
		{  
			if (rowQueens[n - 1] > -1)
			{
				break;
			}
 
			if(!is_attacked(rowQueens, row, col))  
			{  
				rowQueens[row] = col;  
				nqueens(rowQueens, row + 1, n);
 
			}  
		}  
 
	}  
	else
	{
	}
 
}  
  
int main(void)  
{  
	int n;  
	scanf("%d",&n);  
 
	if (n > 0)
	{
		int* pRowQueens = (int*)malloc(n * sizeof(int));
		for (int idx = 0; idx < n; idx++)
		{
			pRowQueens[idx] = -1;
		}
 
		nqueens(pRowQueens, 0, n);
 
		if (pRowQueens[n - 1] == -1)
		{
			printf("Not possible");
		}
		else
		{
			printBoard(pRowQueens, n);
		}
 
		free(pRowQueens);
	}
	return 0;  
 
} 

C++:
1).
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <utility>
#include <iterator>
#include <map>
#include <stack>
#include <queue>
 
 
#define mod 1000000007
#define ima 1000000004
#define imi -1000000004
#define llma 1000000000000000004
#define llmi -1000000000000000004
#define lp(i,n) for(i=0;i<n;i++)
#define li(i,n) for(i=n-1;i>=0;i--)
#define readi(x) scanf("%d",&x)
#define reads(x) scanf("%s",&x)
#define readc(x) scanf("%c",&x)
#define ll long long int
#define f first
#define s second
#define pa pair<ll,ll>
#define pad pair<double ,double>
#define pai pair<int,int>
#define mp make_pair
#define nn 1000005
#define pi 3.1415926535898
#define inf 1e35
#define diff 1e-7
#define sync ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
 
 
using namespace std;
 
int a[11][11];
int r[11];
int c[11];
 int n;
 
void set(int x,int y)
{
    int i;
    for(i=1;x+i<=n && y+i<=n;i++)
        a[x+i][y+i]+=1;
    for(i=1;x-i>0 && y-i>0;i++)
        a[x-i][y-i]+=1;
    for(i=1;x+i<=n && y-i>0;i++)
        a[x+i][y-i]+=1;
    for(i=1;x-i>0 && y+i<=n;i++)
        a[x-i][y+i]+=1;
}
 
void deset(int x,int y)
{
    int i;
    for(i=1;x+i<=n && y+i<=n;i++)
        a[x+i][y+i]-=1;
    for(i=1;x-i>0 && y-i>0;i++)
        a[x-i][y-i]-=1;
    for(i=1;x+i<=n && y-i>0;i++)
        a[x+i][y-i]-=1;
    for(i=1;x-i>0 && y+i<=n;i++)
        a[x-i][y+i]-=1;
}
 
int solve(int x)
{
    int i,j;
    if(x==n)
        return 1;
    for(i=1;i<=n;i++)
    {
        if(a[x+1][i]==0 && c[i]==0)
        {
            c[i]=1;
            a[x+1][i]=100;
            set(x+1,i);
            if(!solve(x+1))
            {
                deset(x+1,i);
                c[i]=0;
                a[x+1][i]=0;
            }
            else
                return 1;
        }
    }
    return 0;
}
 
int main()
{
    sync
    cin>>n;
    solve(0);
    int j;
    if(n==1)
        cout<<"1";
    else if(n>=2 && n<=3)
        cout<<"Not possible";
    else
    for(int i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            if(a[i][j]==100)
            cout<<"1 ";
        else
            cout<<"0 ";
        cout<<endl;
    }
}
2).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int N, S[25];
bool sol; 
 
void procesa_solucion(int s[]) {
    
    int tablero[N + 1][N + 1];
    
    memset(tablero, 0, sizeof(tablero));
    for (int i = 1; i <= N; i++)
        tablero[i][s[i]] = 1;
        
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            printf("%d ", tablero[i][j]);
        printf("\n");
    }
}
 
bool poda(int col, int fila, int s[]) {
    for (int ant = 1; ant <= col - 1; ant++)
        if(s[ant] == fila || (abs(s[ant] - fila) == abs(ant - col)))
            return false;
    return true;
}
 
void reinas(int col, int s[]) {
    if (col == N + 1) {
        sol = true;
        procesa_solucion(s);
    }
    else {
        for (int fila = 1; fila <= N; fila++) {
            if (poda(col, fila, s)) {
                s[col] = fila;
                reinas(col + 1, s);
                if (sol) return;
            }
        }
    }
}
 
int main()
{
    scanf("%d", &N);
    
    sol = false;
    reinas(1, S);
    if (!sol)
        printf("Not possible\n");
    return 0;
}
3).
#include <iostream>
using namespace std;
 
bool canplace(int a[100][100],int n,int row,int i){
    for(int j=0;j<n;j++)
    {
        if(a[row][j]==1)
        return false;
    }
    for(int j=0;j<row;j++)
    {
        if(a[j][i]==1)
        return false;
    }
    int x=i,y=row;
    while(x>=0||y>=0)
    {
        if(a[y][x]==1)
        return false;
        x--;
        y--;
    }
    x=i;y=row;
    while(x<+n-1||y>=0)
    {
        if(a[y][x]==1)
        return false;
        x++;
        y--;
    }
    return true;
}
 
bool nqueen(int a[100][100],int n,int row=0){
    if(row == n)
        return true;
    for(int i=0;i<n;i++)
    {
        if(canplace(a,n,row,i))
        {
            a[row][i]=1;
            if(nqueen(a,n,row+1))
            {
                return true;
            }
            a[row][i]=0;
        }
    }
    return false;
    
}
 
int main()
{
  int n;
  int a[100][100];
  cin>>n;
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
          a[i][j]=0;
  }
 if( nqueen(a,n))
 {
    for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
          cout<<a[i][j]<<" ";
        cout<<endl;  
  } 
 }
 else
 cout<<"Not possible";
    return 0;
}

4).
#include <iostream>
 
using namespace std;
 
int iTotQueen = 0;
 
void clearRow(int **iBoard, int iSize,int iPosX){
    if(iBoard[iPosX][iSize] >= 0){
       int iPosY = iBoard[iPosX][iSize];
       iBoard[iPosX][iPosY] = 0;
       iBoard[iPosX][iSize] = -1;
       iTotQueen -= 1; 
    }
}
 
bool bCheckPosition(int **iBoard,int iSize,int x, int y){
    for(int iPosX = 0,iPosY = y;iPosX<x;iPosX++){
        if(iBoard[iPosX][iPosY] == 1)
            return false;
    }
    for(int iPosX = x-1,iPosY = y-1;iPosX>=0 && iPosY>=0;iPosX--,iPosY--){
        if(iBoard[iPosX][iPosY] == 1)
            return false;
    }
    for(int iPosX = x-1,iPosY = y+1;iPosX>=0 && iPosY<iSize;iPosX--,iPosY++){
        if(iBoard[iPosX][iPosY] == 1)
            return false;
    }
    return true;
}
 
int PlaceQueen(int **iBoard, int iSize,int x , int y){
    int iRes = 0;
    if(y<iSize && bCheckPosition(iBoard,iSize,x,y)){
        iBoard[x][y] = 1;
        iBoard[x][iSize] = y;
        iTotQueen += 1;
        iRes = PlaceQueen(iBoard,iSize,x+1,0);
    }
    if(y<(iSize-1) && iTotQueen<iSize){
        clearRow(iBoard,iSize,x);
        iRes = PlaceQueen(iBoard,iSize,x,y+1);
    }
    return 0;
}
 
int main() {
    int **iBoard;
	int iQueens;
	cin >> iQueens;										// Reading input from STDIN
    iBoard = new int*[iQueens];
    for(int i=0;i<iQueens;i++){
        iBoard[i] = new int[iQueens + 1]();
        iBoard[i][iQueens] = -1;
    }
    
    PlaceQueen(iBoard,iQueens,0,0);
 
    if(iTotQueen==iQueens){
        for(int i=0;i<iQueens;i++){
            for(int j=0;j<iQueens;j++){
                cout<<iBoard[i][j]<< " ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"Not possible"<<endl;
    }
        
    return 0;	
}

5).
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
 
bool notattacked(int i,int j,vector<vector<int>> &nq){
        //row
        
        int n=nq.size();
        for(int r=0;r<n;r++){
            if(r!=j && nq[i][r]==1){
                return false;
            }
        }
        //col
        for(int r=0;r<n;r++){
            if(r!=i && nq[r][j]==1){
                return false;
            }
        }
        
        //upperleftdiag
        int x=i-1,y=j-1;
        while(x>=0 && y>=0){
            if(nq[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        //upperrightdiag
        x=i-1;
        y=j+1;
        while(x>=0 && y<n){
            if(nq[x][y]==1){
                return false;
            }
            x--;
            y++;
        }
        return true;
}
 
void nqueen(int i,vector<vector<int>> &nq,bool &isfound){
    if(i>=nq.size()){
        //print nq
        for(int x=0;x<nq.size();x++){
            for(int y=0;y<nq.size();y++){
                cout<<nq[x][y]<<" ";
            }    
            cout<<endl;
        }
        isfound=true;
        return;
    }
    
    for(int k=0;k<nq.size();k++){
        if(notattacked(i,k,nq)){
            nq[i][k]=1;
            nqueen(i+1,nq,isfound);
                if(isfound){
                    return;
                }
            nq[i][k]=0;
        }
    }
}
 
int main() {
	int N;
	cin >> N;										// Reading input from STDIN
	//cout << "Input number is " << num << endl;		// Writing output to STDOUT
 
    vector<vector<int>> nq;
    nq.resize(N);
    for(int i=0;i<N;i++){
        nq[i].resize(N,0);
    }
    bool isfound=false;
    nqueen(0,nq,isfound);
    if(isfound==false){
        cout<<"Not possible";
    }
}
6).
#include <bits/stdc++.h>
 
using namespace std;
#define ll int
int board[100][100];
 
int is_attacked(ll x,ll y,ll n)
{
    for(int i=0; i<x; i++) if(board[i][y] == 1) return 1;
 
    for(int i=0; i<x; i++)
        for(int j=0; j<n; j++)
            if(board[i][j] == 1 && (i+j == x + y ||j-i == y-x)) return 1;
 
    return 0;
 
}
bool backtrack(ll x,ll n)
{
    if(x>=n)
    {
        return true;
    }
   for(ll i=0; i<n; i++)
    {
        if(is_attacked(x,i,n)==0)
        {
            board[x][i]=1;
            if(backtrack(x+1,n))
            {
                return true;
            }
           board[x][i]=0;
        }
    }
    return false;
}
int main()
{
    ll q;
    cin>>q;
    ll m1,n;
    for(m1=0; m1<q; m1++)
    {
        for(n=0; n<q; n++)
            board[m1][n]=0;
        
    }
    if(backtrack(0,q)){
    for(m1=0; m1<q; m1++)
    {
        for(n=0; n<q; n++)
            cout<<board[m1][n]<<" ";
        cout<<endl;
    }
    }
    else
    cout<< "Not possible";
    return 0;
}
7).
#include <bits/stdc++.h>
using namespace std;
int N;
int is_occupied(int row[],int col[],int dias[],int diad[],int i,int j){
    if(row[i]==1)
        return 1;
    if(col[j]==1)
        return 1;
    if(dias[i+j]==1){
    	//printf("hi1\n");
        return 1;
    }
    if(diad[i-j]==1){
 
    //	printf("%dhi2\n",diad[i-j]);
        return 1;
    }
    else return 0;
}
int queens(int board[101][101],int row[],int col[],int dias[],int diad[],int n)
{
    if(n==0)
        return 1;
    for(int i=1 ; i<=N ; i++) {
        for(int j=1 ; j<=N ; j++){
            if(is_occupied(row,col,dias,diad,i,j)){
                //printf("%d %d\n",i,j);
                continue;
            }
            board[i][j]=1;
            row[i]=1;
            col[j]=1;
            dias[i+j]=1;
            diad[i-j]=1;
            
            //printf("hi%d %d\n",i,j);
           int res=queens(board,row,col,dias,diad,n-1);
           if(res==1)
            return 1;
            board[i][j]=0;
            row[i]=0;
            col[j]=0;
            dias[i+j]=0;
            diad[i-j]=0;
        }
    }
    return 0;
}
 
 
int main()
{
//	freopen("task.in","r",stdin);freopen("task.out","w",stdout);
    int board[101][101]={0};
    int col[101]={0};
    int row[101]={0};
    int diad[101]={0};
    int dias[101]={0};
    int n;
    scanf("%d",&N);
    n=N;
    int ans=queens(board,row,col,dias,diad,n);
    if(ans==1){
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++)
            {
                printf("%d ",board[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("Not possible\n");
    
}
8).
#include <cstdio>
#include <algorithm>
using namespace std;
 
bool board[20][20];
 
bool check(int row, int col, int n)
{
	for (int i = row; i >= 0; i--)
		if (board[i][col] == 1)
			return 0;
 
	int t = min(row, col);
	for(int i = row-t, j = col-t; i < n && j < n; i++, j++)
		if (board[i][j] == 1)
			return 0;
 
	t = min(n-1-row, col);
	for(int i = row+t, j = col-t; i >= 0 && j < n; i--, j++)
		if (board[i][j] == 1)
			return 0;
 
	return 1;
}
 
bool solve(int row, int n)
{
	if(row == n)
		return 1;
 
	for (int j = 0; j < n; j++)
	{
		if (check(row, j, n))
		{
			board[row][j] = 1;
			if (solve(row+1, n))
				return 1;
 
			board[row][j] = 0;
		}
	}
 
	return 0;
}
 
int main()
{
	int n;
	scanf("%d", &n);
 
	if (n == 1)
	{
		printf("1\n");
		return 0;
	}
 
	if (n == 2 or n == 3)
	{
		printf("Not possible\n");
		return 0;
	}
 
	solve(0, n);
 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
 
	return 0;
}
9).
#include<bits/stdc++.h>
using namespace std;
 
int n;
 
bool check(int a[11][11],int i,int j)
{
int x,p;
bool temp=true;
    for(x=0;x<n;x++)
    {
       if(a[i][x]==1)
       {
           temp=false;
           return temp;
       }
    }
    for(x=0;x<n;x++)
    {
        if(a[x][j]==1)
        {
            temp = false;
            return temp;
        }
    }
    if(i>=j){
        x=i-j;
        p=0;
    }
    else{
        p=j-i;
        x=0;
    }
    while(p<n && x<n){
        if(a[x][p]){
            return false;
        }
        p++;
        x++;
    }
 
    //00000
    //00000
    //00100//2,5
    //00000//3,3
    //00000
    x=i,p=j;
    while(x>=0 && p<n){
        if(a[x][p])
            return false;
        x--;
        p++;
    }
 
    x=i,p=j;
    while(x<n && p>=0){
        if(a[x][p])
            return false;
        x++;
        p--;
    }
    return true;
}
 
bool queen(int a[11][11],int row,int q)
{
    int i=row,j;
    if(q==0)
        return true;
    if(row==n)
        return false;
    for(j=0;j<n;j++)
    {
        bool flag=0,f=0;
        flag=check(a,i,j);
        a[i][j]=1;
 
        if(flag){
            f=queen(a,row+1,q-1);
            if(f)
                return true;
        }
        a[i][j]=0;
    }
    return false;
}
 
int main()
{
   int i,j;
   cin>>n;
 
   int a[11][11];
 
   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
        a[i][j]=0;
   }
 
   bool flag=queen(a,0,n);
   if(flag){
   for(i=0;i<n;i++){
    for(j=0;j<n;j++)
        cout<<a[i][j]<<" ";
    cout<<endl;
    }
   cout<<endl;
   }
   else
   {
       cout<<"Not possible";
   }
}

10).
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << "   ";
typedef long long ll;
typedef unsigned long long int ulli;
typedef ll ndt;//"new datatype"(change ll to ulli here)
#define REP(i,n) for(ndt i=0;i<(n);++i)
#define FOR(i,a,b) for(ndt i=(a);i<=(b);++i)
#define FORD(i,a,b) for(ndt i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
inline ndt frndt()//fastRead_ll();
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    ndt a=0;
    while (c>33)
    {
        a=a*10+c-'0';
        c=getchar_unlocked();
    }
    return a;
}

// usage: fastRead_ll(&N); N=frndt();
//#define gc() getchar_unlocked()
//int isSpaceChar(char c) {
//            return (c == ' ' || c == '\n' || c == '\r') ;
//        }
//inline ndt frndt()//FAST_IO()
//{
//    char ch;
//    ndt val=0LL;
//    ch=gc();
//    while(isSpaceChar(ch))T
//            ch=gc();
//    while(!isSpaceChar(ch))
//    {
//        val=(val*10)+(ch-'0');
//        ch=gc();
//    }
//    return val;
//}
//usage: N = frndt();


#define pc(x) putchar_unlocked(x);

//inline void fwndt(ndt n)//writeInt (int n)
//{
//    ndt N = n, rev, count = 0;
//    rev = N;
//    if (N == 0) { pc('0'); pc('\n'); return ;}
//    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
//    rev = 0;
//    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
//    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
//    while (count--) pc('0');
//}


inline void fwndt(ndt n)
{
	if (n == 0)
	{
		pc('0');
		pc('\n');
	}
	else if (n == -1)
	{
		pc('-');
		pc('1');
		pc('\n');
	}
	else
	{
		char buf[11];
		buf[10] = '\n';
		int i = 9;
		while (n)
		{
			buf[i--] = n % 10 + '0';
			n /= 10;
		}
		while (buf[i] != '\n')
			pc(buf[++i]);
	}
}

//usage: fwndt(n);
/////////////////////////////////////////////////////////////////////
//ios_base::sync_with_stdio(false); cin.tie(NULL);
 
int n;
int board[10][10];
 
bool isAttack(int newposi, int newposj)
{
    //DEBUG(newposi)
    //DEBUG(newposj)
    //cout << endl;
    //REP(i,n)
    //{
    //    REP(j,n)
    //        cout << board[i][j] << " ";
    //    cout << endl;
    //}
	
    REP(i,n)//col
    {
        if(board[i][newposj]==1 && i!=newposi)
        {
            //DEBUG(i)
            //cout << "coll" << endl;
            return true;
        }
    }
    REP(j,n)//row
    {
        if(board[newposi][j]==1 && j!=newposj)
        {
            //DEBUG(j)
            //cout << "roww" << endl;
            return true;
        }
    }
    int i=newposi-1, j=newposj-1;// diagonal up left
    while(i>=0 && j>=0)
    {
        if(board[i][j]==1)
        {
            //DEBUG(i)
            //DEBUG(j)
            //cout << "dul" << endl;
            return true;
        }
        --i,--j;
    }
    i=newposi+1, j=newposj+1;// diagonal down right
    while(i<n && j<n)
    {
        if(board[i][j]==1)
        {
            //DEBUG(i)
            //DEBUG(j)
            //cout << "ddr" << endl;
            return true;
        }
        ++i,++j;
    }
    i=newposi-1, j=newposj+1;//diagonal up right
    while(i>=0 && j<n)
    {
        if(board[i][j]==1)
        {
            //DEBUG(i)
            //DEBUG(j)
            //cout << "dur" << endl;
            return true;
        }
        --i,++j;
    }
    i=newposi+1, j=newposj-1;//diagonal down left
    while(i<n && j>=0)
    {
        if(board[i][j]==1)
        {
            //DEBUG(i)
            //DEBUG(j)
            //cout << "ddl" << endl;
            return true;
        }
        ++i,--j;
    }
    //cout << "noatack" << endl;
    return false;
}
 
bool backtracked;

bool fillboard(int nn)
{
    if(nn==0)
        return true;
    else
    {
        backtracked=false;
        REP(i,n)
        {
            REP(j,n)
            {
                if(board[i][j]!=1 && !isAttack(i,j))
                {
                    board[i][j]=1;
                    if(!fillboard(nn-1))
                    {
                        //cout << "backtrack" << endl;
                        //backtracked=true;
                        board[i][j]=0;
                    }
                    else
                        return true;
                }
            }
            //if(backtracked==false)
            {
                int k=0;
                for(;k<n;++k)
                {
                    if(board[i][k]==1)
                        break;
                }
                if(k==n)
                {
                    //backtracked = false;
                    return false;
                }
            }
        }
        
    }
    return false;
}
 
int main()
{
	cin >> n;
	REP(i,n)
	    REP(j,n)
	        board[i][j]=0;
	if(fillboard(n))
	{
	    REP(i,n)
	    {
	        REP(j,n)
	            cout << board[i][j] << " ";
	        cout << endl;
	    }
	}
	else
	    cout << "Not possible" << endl;
    return 0;
}
C++14:
1).
#include <bits/stdc++.h>
 
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define mod 1000000007
#define llt ll test;cin>>test;while(test--)
#define pb push_back
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define rep(i,a,b) for (ll i = a; i<b; ++i)
#define len(s) s.length()
#define MAX 100
 
using namespace std;
 
ll board[MAX][MAX];
 
ll n, i, j;
 
bool isSafe(ll row, ll col){
 
for (i = 0; i <= row; ++i)
if (board[i][col])
return false;
 
 
for(i = 0; i<n ; i++)
for(j = 0; j<n; j++)
if((i-j) == (row - col) || (i+j) == (row+col))
if(board[i][j] == 1)
return false;
 
return true;
}
 
bool solve(ll row){
if(row>=n)return true;
 
for (ll i = 0; i < n; ++i){
if (isSafe(row, i)){
board[row][i] = 1;
 
if (solve(row+1))
return true;
 
board[row][i] = 0;
}
}
 
return false;
}
 
int main()
{
boost;
 
cin>>n;
 
rep(i,0,n)
rep(j,0,n)
board[i][j] = 0;
 
bool ans = solve(0);
 
if(ans == false)
cout<<"Not possible\n";
 
else{
 
rep(i,0,n){
rep(j,0,n)
cout<<board[i][j]<<" ";
cout<<"\n";
}
 
}
 
return 0;
}
 
 
// #include<bits/stdc++.h>
// using namespace std;
 
// void printSolution(vector<vector<int >> ans)
// {
//     int n = ans.size();
    
//     for(int i = 0;i<n;i++)
//     {
//         for(int j = 0;j<n;j++)
//         {
//             cout<<ans[i][j]<<" "; 
//         }
//         cout<<endl;
//     }
// }
 
// bool isSafe(vector<vector<int >> ans, int row,int col)
// {
//     int i, j; 
//     int N = ans.size();
//      Check this row on left side
//     for (i = 0; i < col; i++) 
//         if (ans[row][i]) 
//             return false; 
  
//      Check upper diagonal on left side 
//     for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
//         if (ans[i][j]) 
//             return false; 
  
//     Check lower diagonal on left side
//     for (i = row, j = col; j >= 0 && i < N; i++, j--) 
//         if (ans[i][j]) 
//             return false; 
//     return true; 
    
// }
 
// bool NQueen(vector<vector<int >> &ans, int col,int N)
// {
   
//     if(col>=N)
//     {
//         return true;
//     }
    
//     for(int i = 0;i<N;i++)
//     {
//         if(isSafe(ans, i, col)){
//             ans[i][col] = 1;
//             if(NQueen(ans, col+1, N))
//             return true;
            
//             ans[i][col] = 0;
//         }
//     }
//     return false;
// }
 
// int main()
// {
//     int n;
//     cin>>n;
    
//     vector<vector<int >> ans;
//     for(int i = 0;i<n;i++)
//     {
//         vector<int > d;
//         ans.push_back(d);
//         for(int j = 0;j<n;j++)
//         {
//             ans[i].push_back(0); 
//         }
        
//     }
//     if(NQueen(ans, 0, n))
//     printSolution(ans);
 
// }
2).
#include <iostream>
 
using namespace std;
int board[10][10];
int size;
 
int Queen_position(int N);
int Is_Legal_move(int posx, int posy);
int main()
{
    int N;
    cin>>N;
    size = N;
    int res = Queen_position(N);
    if(res == 1)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                cout<<board[i][j]<<" ";
            cout<<endl;
        }
    }
    else
        cout<<"Not possible"<<endl;
    return 0;
}
int Is_Legal_move(int posx, int posy)
{
    for(int i = 0; i < size; i++)
    {
        if(board[i][posy] == 1)
            return 0;
        if(board[posx][i] == 1)
            return 0;
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(posx+ posy == i+j)
            {
                if(board[i][j] == 1)
                   {
                       return 0;
                   }
            }
            if(posx - posy == i-j)
            {
                if(board[i][j] == 1)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}
int Queen_position(int N)
{
    int k = size - N;
    if(N == 0)
        return 1;
    else
    {
        for(int i = k; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(Is_Legal_move(i, j))
                {
                    board[i][j] = 1;
                    if(Queen_position(N-1) == 0)
                        {
                            board[i][j] = 0;
                        }
                    else return 1;
 
                }
            }
        }
    }
        return 0;
}
3).
#include <bits/stdc++.h>
#define clr(a, v)             memset(a, v, sizeof a)
#define all(v)                v.begin(), v.end()
#define ast(v)                sort(v.begin(),v.end())
#define dst(v)                sort(v.begin(),v.end(), greater <int> ())
#define fast ios_base::       sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ass(cur, v)           cur.assign(v.begin(), v.end())
#define rep(i, l, r)          for (int i = l; i < r; i++)
#define rep2(i, l, r)         for (int i = l-1; i >= r; i--)
#define sfs(s)                scanf("%s", s)
#define sfl(n)                scanf("%lld", &n)
#define sffl(n, m)            scanf("%lld %lld",&n,&m)
#define sfffl(n, m, o)        scanf("%d %d %d",&n,&m, &o)
#define pf(n)                 printf("%d", n)
#define debug                 cout << " debug\n"
#define yes                   cout << "YES\n"
#define no                    cout << "NO\n"
#define sp                    cout << " "
#define nl                    cout << "\n"
#define prln(n)               printf("%d\n", n)
#define pfl(n)                printf("%lld\n", n)
#define I(n)                  cin >> n
#define II(n, m)              cin >> n >> m
#define III(a, b, c)          cin >> a >> b >> c
#define P(n)                  cout << n
#define PP(n, m)              cout << n << " " << m << "\n"
#define PPP(a, b, c)          cout << a << " " << b << " " << c << "\n"
#define R(n)                  return n
#define mid(b, e)             (b+e)/2
#define left(node)            node*2
#define right(node)           node*2+1
#define pii                   pair<int,int>
#define mp                    make_pair
#define pb                    push_back
#define S                     second
#define F                     first
#define PI                    3.1415926
 
struct greaters{
    bool operator()(const long& a, const long& b) const{
        return a > b;
    }
};
 
 
//-----------------------------------***********************----------------------------------------------//
 
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const int N = 2e5+5;
const int mod = 1e9+7;
 
string toString(int n){
    stringstream ss; ss << n;
    string s; ss >> s;
    return s;
}
 
int toInt(string s){
    stringstream ss; ss << s;
    int n; ss >> n;
    return n;
}
 
void reset(){
 
}
 
int n, ar[50][50];
bool isSafe(int row, int col){
    //column check
    for(int i = 0; i < row; i++){
        if(ar[i][col]){
            return false;
        }
    }
 
    //upper right diagonal check
    int r = row, c = col;
    while(r >= 0 and c < n){
        if(ar[r][c]){
            return false;
        }
        r--, c++;
    }
 
     //upper left diagonal check
    r = row, c = col;
    while(r >= 0 and c >= 0){
        if(ar[r][c]){
            return false;
        }
        r--, c--;
    }
    return true;
}
 
bool solve(int row){
    if(row >= n){
        return true;
    }
    for(int i = 0; i < n; i++){
        if(isSafe(row, i)){
            ar[row][i] = 1;
            if(solve(row+1)){
                return true;
            }
            ar[row][i] = 0;
        }
    }
    return false;
}
 
void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            P(ar[i][j]); sp;
        }
        nl;
    }
}
 
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    int tc = 1, cas = 0;
    while(tc--){
        //reset();
        I(n);
        if(solve(0)){
            print();
        }
        else{
            P("Not possible\n");
        }
    }
    return 0;
 
}
4).
#include<iostream>
using namespace std;
int N; 
bool safe(int **a,int row,int col)
{
	int i;
	for(i=0;i<col;i++)
	{
		if(a[row][i]==1)
		return false;
	}
	int j;
	for(i=row,j=col;i>=0&&j>=0;i--,j--)
	{
		if(a[i][j]==1)
		return false;
	}
	for(i=row,j=col;i<N&&j>=0;i++,j--)
	{
		if(a[i][j]==1)
		return false;
	}
	return true;
}
bool solvenq(int **ar,int col)
{
	int i;
	if(col>=N)
	return true;
	for(i=0;i<N;i++)
	{
		if(safe(ar,i,col))
		{
			ar[i][col]=1;
			if(solvenq(ar,col+1))
			return true;
			ar[i][col]=0;
		}
	}
	return false;
	
}
bool solve()
{
	int i,j;
	int **a;
	a=new int*[N];
	for(i=0;i<N;i++)
	{
		a[i]=new int[N];
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			a[i][j]=0;
		}
	}
    if(solvenq(a,0))
    {
    for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			cout<<a[j][i]<<" ";
		}
		cout<<endl;
	}
	}
	else
	{
		cout<<"Not possible";
	}
    return true;
}
int main()
{
	cin>>N;
	solve();
}
5).
#include <iostream>
using namespace std;
 
int s = 0;
 
int diagonal(int diag[11][11],int i,int j,int n){
	int p=i;
	int q=j;
	while(p<=n && q<=n){
		diag[p][q]=1;
		p++;
		q++;
	}
	p = i;
	q = j;
	while(p<=n && q>=0){
		diag[p][q]=1;
		p++;
		q--;
	}
}
 
int change(int a[11][11],int i,int j,int diag[11][11],int n){
	for(int p=0;p<n;p++){
		for(int q=0;q<n;q++){
			diag[p][q]=0;
		}
	}
	for (int p = 0; p < n; ++p){
		for (int q = 0; q < n; ++q){
			if(a[p][q]==1){
				diagonal(diag,p,q,n);
			}
		}
	}	
}
 
int chess(int n,int a[11][11],int row,int *allcol,int diag[11][11]){
	if(row == 0){
		for(int j=0;j<n;j++){
			a[row][j] = 1;
			allcol[j] = 1;
			change(a,row,j,diag,n); 
			chess(n,a,row+1,allcol,diag);
			a[row][j] = 0;
			allcol[j] = 0;
			change(a,row,j,diag,n);
		}
	}
	else if(row == n && s == 0){
		for(int i=0;i<row;i++){
			for(int j=0;j<row;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		s = 1;
	}
	else if((n==2||n==3) && s == 0){
		if(n==2 && row==1){
			cout<<"Not possible";
			s = 1;
		}
		else if(n==3 && row ==1){
			cout<<"Not possible";
			s = 1;
		}
	}
	else{
		for(int j=0;j<n;j++){
			if(allcol[j]!=1 && diag[row][j]==0){
				a[row][j]=1;
				allcol[j]=1;
				change(a,row,j,diag,n);
				chess(n,a,row+1,allcol,diag);
				a[row][j]=0;
				allcol[j]=0;
				change(a,row,j,diag,n);
			}
		}
	}
}
 
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[11][11] = {};
	int b[11][11] = {};
	int allrow[11] = {};
	chess(n,a,0,allrow,b);	
	return 0;
}



C#:
#All code by stupid_chris
#      ©(Christophe Savard)
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
 
namespace HackerEarth
{
    /// <summary>
    /// Solution class
    /// </summary>
    internal static class Program
    {
        #region Main
        /// <summary>
        /// Fast Console IO helper
        /// </summary>
        private static readonly ConsoleHelper console = new ConsoleHelper();
 
        /// <summary>
        /// Main method - Launches solver
        /// </summary>
        private static void Main()
        {
            //Depending on problem
            using (console)
            {
                //TestCases();
                Solve();
            }
            Console.ReadLine();
        }
 
        /// <summary>
        /// Solves the problem for multiple test cases
        /// </summary>
        private static void TestCases()
        {
            int n = console.NextInt();
            console.NextLine();
 
            for (int i = 0; i < n; i++)
            {
                Solve();
            }
        }
        #endregion
 
        #region Solution
        /// <summary>
        /// Solution
        /// </summary>
        private static void Solve()
        {
            int n = console.NextInt();
            if (n == 1)
            {
                console.Write('1');
                return;
            }
 
            int[,] board = new int[n, n];
            console.Write(PlaceQueens(0, n, board) ? PrintBoard(board) : "Not possible");
        }
 
        private static bool PlaceQueens(int row, int left, int[,] board)
        {
            int l = board.GetLength(0);
            for (int i = 0; i < l; i++)
            {
                board[row, i] = 1;
                if (IsValid(row, i, board) && (left == 1 || PlaceQueens(row + 1, left - 1, board)))
                {
                    return true;
                }
                board[row, i] = 0;
            }
            return false;
        }
 
        private static bool IsValid(int row, int column, int[,] board)
        {
            int j = column - 1, k = column + 1, l = board.GetLength(0);
            for (int i = row - 1; i >= 0; i--)
            {
                if (board[i, column] == 1 || (j >= 0 && board[i, j--] == 1) || (k < l && board[i, k++] == 1)) { return false; }
            }
            return true;
        }
 
        private static string PrintBoard(int[,] board)
        {
            int l = board.GetLength(0);
            StringBuilder sb = new StringBuilder(l * l * 2);
            for (int i = 0; i < l; i++)
            {
                sb.Append(board[i, 0]);
                for (int j = 1; j < l; j++)
                {
                    sb.Append(' ').Append(board[i, j]);
                }
 
                sb.AppendLine();
            }
 
            return sb.ToString();
        }
        #endregion
    }
 
    /// <summary>
    /// Fast Console IO helper
    /// </summary>
    internal sealed class ConsoleHelper : IDisposable
    {
        #region Constants
        /// <summary>
        /// The standard input and output buffers size (2^20, 1Mb)
        /// </summary>
        private const int baseSize = 1048576;
        #endregion
 
        #region Fields
        private readonly BufferedStream inStream; //Buffered console input stream
        private readonly BufferedStream outStream; //Buffered console output stream
        private readonly byte[] inBuffer; //Input buffer 
        private readonly byte[] outBuffer; //Output buffer
 
        private int inputIndex; //Input buffer current index
        private int outputIndex; //Output buffer current index
        private int bufferEnd; //Input buffer ending index
        #endregion
 
        #region Properties
        /// <summary>
        /// The buffer size, in bytes
        /// </summary>
        public int BufferSize { get; }
 
        /// <summary>
        /// If this memory stream is open and available to read/write
        /// </summary>
        public bool Open { get; private set; }
        #endregion
 
        #region Constructors
        /// <summary>
        /// Creates a new console IO helper reading from the standard Console input and output
        /// </summary>
        public ConsoleHelper() : this(baseSize) { }
 
        /// <summary>
        /// Creates a new console IO helper reading from the standard Console input and output with the specified buffer size
        /// <param name="bufferSize">Size of the buffer to use in bytes</param>
        /// </summary>
        public ConsoleHelper(int bufferSize)
        {
            //Open the input stream
            this.inStream = new BufferedStream(Console.OpenStandardInput(bufferSize), bufferSize);
            this.inBuffer = new byte[bufferSize];
 
            //Open the output stream
            this.outStream = new BufferedStream(Console.OpenStandardOutput(bufferSize), bufferSize);
            this.outBuffer = new byte[bufferSize];
 
            //Set fields
            this.inputIndex = this.outputIndex = this.bufferEnd = 0;
            this.BufferSize = bufferSize;
            this.Open = true;
        }
        #endregion
 
        #region Static methods
        /// <summary>
        /// Verifies that the passed character is a non-special ASCII character
        /// </summary>
        /// <param name="i">Character to validate</param>
        /// <returns>True if the character is not a special character</returns>
        public static bool ValidateChar(int i) => i >= ' ';
 
        /// <summary>
        /// Verifies that the passed character is a non-special ASCII character or a whitespace
        /// </summary>
        /// <param name="i">Character to validate</param>
        /// <returns>True if the character is not a whitespace or a special character</returns>
        public static bool ValidateCharNoSpace(int i) => i > ' ';
 
        /// <summary>
        /// Verifies that the passed character is a numerical character (0-9)
        /// </summary>
        /// <param name="i">Character to validate</param>
        /// <returns>True if the character is a numerical character, false otherwise</returns>
        public static bool ValidateNumber(int i) => i >= '0' && i <= '9';
 
        /// <summary>
        /// Verifies if a character is an Endline character
        /// </summary>
        /// <param name="i">Character to check</param>
        /// <returns>True if it is an Endline character, false otherwise</returns>
        public static bool IsEndline(int i) => i == '\n' || i == '\0';
        #endregion
 
        #region Methods
        /// <summary>
        /// Returns the next byte data in the console input stream
        /// </summary>
        /// <returns>Next data byte from the console</returns>
        public byte Read()
        {
            CheckBuffer();
            return this.inBuffer[this.inputIndex++];
        }
 
        /// <summary>
        /// Returns the next byte data in the console input stream without consuming it
        /// </summary>
        /// <returns>Next data byte from the console</returns>
        public byte Peek()
        {
            CheckBuffer();
            return this.inBuffer[this.inputIndex];
        }
 
        /// <summary>
        /// Skips a number of characters in the input stream
        /// </summary>
        /// <param name="n">Amount of chars to skip, defaults to 1</param>
        public void Skip(int n = 1) => this.inputIndex += n;
 
        /// <summary>
        /// Assures we have data available in the input buffer
        /// </summary>
        private void CheckBuffer()
        {
            //If we reach the end of the buffer, load more data
            if (this.inputIndex >= this.bufferEnd)
            {
                this.inputIndex = this.inputIndex - this.bufferEnd;
                this.bufferEnd = this.inStream.Read(this.inBuffer, 0, this.BufferSize);
 
                //If nothing was added, add a null char at the start
                if (this.bufferEnd < 1) { this.inBuffer[this.bufferEnd++] = 0; }
            }
        }
 
        /// <summary>
        /// Returns the next character in the console input stream
        /// </summary>
        /// <returns>Next character in the input stream</returns>
        public char NextChar() => (char)Read();
 
        /// <summary>
        /// Returns the next string token from the console input
        /// </summary>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <returns>Parsed string, separated by spaces or special characters such as line feeds</returns>
        public string Next()
        {
            byte b = SkipInvalid();
            ValidateEndline(b);
 
            //Append all characters
            StringBuilder sb = new StringBuilder().Append((char)b);
            b = Peek();
            while (ValidateCharNoSpace(b))
            {
                //Peek to not consume terminator
                sb.Append((char)b);
                Skip();
                b = Peek();
            }
 
            return sb.ToString();
        }
 
        /// <summary>
        /// Returns the next int value in the console input, this is a fast parse
        /// </summary>
        /// <exception cref="FormatException">If the text is not a valid integer</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for integer</exception>
        /// <returns>Parsed int value from the input</returns>
        public int NextInt()
        {
            //Skip invalids
            byte b = SkipInvalid();
            ValidateEndline(b);
 
            //Verify for negative
            bool neg = false;
            if (b == '-')
            {
                neg = true;
                b = Read();
            }
 
            //Get first digit
            if (!ValidateNumber(b)) { throw new FormatException("Integer parsing has failed because the string contained invalid characters"); }
 
            int n = b - '0';
            b = Peek();
            while (ValidateNumber(b))
            {
                //Peek to not consume terminator, and check for overflow
                n = checked((n << 3) + (n << 1) + (b - '0'));
                Skip();
                b = Peek();
            }
            //If the character causing the exit is a valid ASCII character, the integer isn't correct formatted
            if (ValidateCharNoSpace(b)) { throw new FormatException("Integer parsing has failed because the string contained invalid characters"); }
 
            return neg ? -n : n;
        }
 
        /// <summary>
        /// Returns the next long value in the console input, this is a fast parse
        /// </summary>
        /// <exception cref="FormatException">If the text is not a valid long</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for long</exception>
        /// <returns>Parsed long value from the input</returns>
        public long NextLong()
        {
            byte b = SkipInvalid();
            ValidateEndline(b);
 
            //Verify negative
            bool neg = false;
            if (b == '-')
            {
                neg = true;
                b = Read();
            }
 
            //Get first digit
            if (!ValidateNumber(b)) { throw new FormatException("Integer parsing has failed because the string contained invalid characters"); }
 
            long n = b - '0';
            b = Peek();
            while (ValidateNumber(b))
            {
                //Peek to not consume terminator, and check for overflow
                n = checked((n << 3) + (n << 1) + (b - '0'));
                Skip();
                b = Peek();
            }
            //If the character causing the exit is a valid ASCII character, the long isn't correct formatted
            if (ValidateCharNoSpace(b)) { throw new FormatException("Long parsing has failed because the string contained invalid characters"); }
 
            return neg ? -n : n;
        }
 
        /// <summary>
        /// Returns the next double value in the console input
        /// Note: fast double parsing is slightly harder, I'll implement it if I need to
        /// </summary>
        /// <exception cref="FormatException">If the text is not a valid double</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for double</exception>
        /// <returns>Parsed double value from the input</returns>
        public double NextDouble() => double.Parse(Next());
 
        /// <summary>
        /// Returns the next n int values on the same line in an array
        /// </summary>
        /// <param name="n">Number of values to seek</param>
        /// <exception cref="FormatException">If the text is not a valid integer</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for integer</exception>
        /// <exception cref="OutOfMemoryException">If the created array is too large for the system memory</exception>
        /// <returns>The n integer values in an array</returns>
        public int[] NextInts(int n)
        {
            int[] array = new int[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = NextInt();
            }
 
            NextLine();
            return array;
        }
 
        /// <summary>
        /// Returns the next n int values on the next m lines in the output stream under the form of an NxM matrix
        /// </summary>
        /// <param name="n">Number of rows to the matrix</param>
        /// <param name="m">Number of columns to the matrix</param>
        /// <exception cref="FormatException">If the text is not a valid integer</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for integer</exception>
        /// <exception cref="OutOfMemoryException">If the created 2D array is too large for the system memory</exception>
        /// <returns>The NxM matrix of integers</returns>
        public int[,] NextMatrix(int n, int m)
        {
            int[,] matrix = new int[n, m];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[i, j] = NextInt();
                }
 
                NextLine();
            }
 
            return matrix;
        }
 
        /// <summary>
        /// Returns the next line of text in the console
        /// </summary>
        /// <returns>Next string line from the console</returns>
        public string NextLine()
        {
            byte b = SkipInvalid();
            if (b == 0)
            {
                //Consume newline and return empty string
                Skip();
                return string.Empty;
            }
 
            //Read all the characters until the next linefeed
            StringBuilder sb = new StringBuilder().Append((char)b);
            b = Read();
            while (!IsEndline(b))
            {
                //Don't append special characters, but don't exit
                if (ValidateChar(b))
                {
                    sb.Append((char)b);
                }
                b = Read();
            }
 
            return sb.ToString();
        }
 
        /// <summary>
        /// Enumerates the given number of integers on the current line
        /// </summary>
        /// <param name="n">Number of integers on the current line</param>
        /// <returns>Enumerable of the integers</returns>
        public IEnumerable<int> EnumerateInts(int n)
        {
            while (n-- > 0)
            {
                yield return NextInt();
            }
 
            NextLine();
        }
 
        /// <summary>
        /// Enumerates all the characters in the next line until the feed is exhausted or an endline character is met
        /// </summary>
        /// <returns>Enumerable of all the characters in the current line</returns>
        public IEnumerable<char> EnumerateLine()
        {
            for (char c = NextChar(); !IsEndline(c); c = NextChar())
            {
                if (ValidateChar(c))
                {
                    yield return c;
                }
            }
        }
 
        /// <summary>
        /// Assures we are not trying to read more data on the line that there exists
        /// </summary>
        /// <param name="b">Byte data to verify</param>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        private void ValidateEndline(byte b)
        {
            //If empty char
            if (b == 0)
            {
                //Go back a char and throw
                this.inputIndex--;
                throw new InvalidOperationException("No values left on line");
            }
        }
 
        /// <summary>
        /// Skips all invalid character bytes then returns the first valid byte found, spaces are considered invalid
        /// </summary>
        /// <returns>The next valid character byte, cannot be a whitespace</returns>
        private byte SkipInvalid()
        {
            byte b = Peek();
            if (IsEndline(b)) { return 0; }
 
            while (!ValidateCharNoSpace(b))
            {
                Skip();
                b = Peek();
                //Return empty char if we meet an linefeed or empty char
                if (IsEndline(b)) { return 0; }
            }
 
            return Read();
        }
 
        /// <summary>
        /// Writes the given char to the console output
        /// </summary>
        /// <param name="c">Character to write</param>
        public void Write(char c) => WriteByte((byte)c);
 
        /// <summary>
        /// Writes the given char buffer to the console output
        /// </summary>
        /// <param name="buffer">Char buffer to write</param>
        public void Write(char[] buffer) => buffer.ForEach(c => WriteByte((byte)c));
 
        /// <summary>
        /// Writes the given string to the console output
        /// </summary>
        /// <param name="s">String to write</param>
        public void Write(string s) => Write(s.ToCharArray());
 
        /// <summary>
        /// Writes the given integer to the console output
        /// </summary>
        /// <param name="n">Integer to write</param>
        public void Write(int n) => Write(n.ToString().ToCharArray());
 
        /// <summary>
        /// Writes the given long to the console output
        /// </summary>
        /// <param name="n">Long to write</param>
        public void Write(long n) => Write(n.ToString().ToCharArray());
 
        /// <summary>
        /// Writes the given object to the console output using the object's ToString method
        /// </summary>
        /// <param name="o">Object to write</param>
        public void Write(object o) => Write(o.ToString().ToCharArray());
 
        /// <summary>
        /// Writes a sequence to the console output with the given string separator
        /// </summary>
        /// <typeparam name="T">Type of elements in the sequence</typeparam>
        /// <param name="e">Sequence to print</param>
        /// <param name="separator">String separator between each element, defaults to the empty string</param>
        public void Write<T>(IEnumerable<T> e, string separator = "") => Write(e.Join(separator).ToCharArray());
 
        /// <summary>
        /// Writes a linefeed to the console output
        /// </summary>
        public void WriteLine() => WriteByte(10);
 
        /// <summary>
        /// Writes the given char to the console output, followed by a linefeed
        /// </summary>
        /// <param name="c">Character to write</param>
        public void WriteLine(char c)
        {
            WriteByte((byte)c);
            WriteByte(10);
        }
 
        /// <summary>
        /// Writes the given char buffer to the console output, followed by a linefeed
        /// </summary>
        /// <param name="buffer">Char buffer to write to the output</param>
        public void WriteLine(char[] buffer)
        {
            Write(buffer);
            WriteByte(10);
        }
 
        /// <summary>
        /// Writes the given string to the console output, followed by a linefeed
        /// </summary>
        /// <param name="s">String to write</param>
        public void WriteLine(string s)
        {
            Write(s.ToCharArray());
            WriteByte(10);
        }
 
        /// <summary>
        /// Writes the given integer to the console output, followed by a linefeed
        /// </summary>
        /// <param name="n">Integer to write</param>
        public void WriteLine(int n)
        {
            Write(n.ToString().ToCharArray());
            WriteByte(10);
        }
 
        /// <summary>
        /// Writes the given long to the console output, followed by a linefeed
        /// </summary>
        /// <param name="n">Long to write</param>
        public void WriteLine(long n)
        {
            Write(n.ToString().ToCharArray());
            WriteByte(10);
        }
 
        /// <summary>
        /// Writes a sequence to the console output with the given string separator, follows by a linefeed
        /// </summary>
        /// <typeparam name="T">Type of elements in the sequence</typeparam>
        /// <param name="e">Sequence to print</param>
        /// <param name="separator">String separator between each element, defaults to the empty string</param>
        public void WriteLine<T>(IEnumerable<T> e, string separator = "")
        {
            Write(e, separator);
            WriteByte(10);
        }
 
        /// <summary>
        /// Writes the given object to the console output using the object's ToString method, followed by a linefeed
        /// </summary>
        /// <param name="o">Object to write</param>
        public void WriteLine(object o)
        {
            Write(o.ToString().ToCharArray());
            WriteByte(10);
        }
 
        /// <summary>
        /// Writes the given data byte to the console output, this does NOT write the actual number
        /// </summary>
        /// <param name="b">Data byte to write</param>
        public void WriteByte(byte b)
        {
            Flush();
            this.outBuffer[this.outputIndex++] = b;
        }
 
        /// <summary>
        /// Flushes the output buffer to the console if the buffer is full, or if it's being forced
        /// </summary>
        /// <param name="force">If the buffer must be forced to flush even if it isn't full</param>
        public void Flush(bool force = false)
        {
            if (this.outputIndex == this.BufferSize || force)
            {
                this.outStream.Write(this.outBuffer, 0, this.outputIndex);
                this.outStream.Flush();
                this.outputIndex = 0;
            }
        }
 
        /// <summary>
        /// Disposes of the resources of this ConsoleHelper, closing all the associated streams
        /// </summary>
        public void Dispose()
        {
            if (this.Open)
            {
                Flush(true);
                this.inStream.Dispose();
                this.outStream.Dispose();
                this.Open = false;
            }
        }
        #endregion
    }
 
    /// <summary>
    /// Useful extensions
    /// </summary>
    internal static class Extensions
    {
        #region Enumerable extensions
        /// <summary>
        /// Applies an action on each member of the enumerable
        /// </summary>
        /// <typeparam name="T">Type of elements in the Enumerable</typeparam>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="action">Action to apply to each parameter</param>
        public static void ForEach<T>(this IEnumerable<T> e, Action<T> action)
        {
            foreach (T t in e)
            {
                action(t);
            }
        }
 
        /// <summary>
        /// Joins all the elements of the enumerable into a string
        /// </summary>
        /// <typeparam name="T">Type of elements in the Enumerable</typeparam>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="separator">Separator string, defaults to the empty string</param>
        public static string Join<T>(this IEnumerable<T> e, string separator = "") => new StringBuilder().AppendJoin(e, separator).ToString();
 
        /// <summary>
        /// Finds the object with the maximum value in the enumerable
        /// </summary>
        /// <typeparam name="T">Type of objects in the Enumerable</typeparam>
        /// <typeparam name="TU">Comparing type, must implement IComparable(T)</typeparam>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="selector">Function calculating the value that we want the max from</param>
        /// <returns>The object with the maximum value in the enumerable</returns>
        public static T MaxValue<T, TU>(this IEnumerable<T> e, Func<T, TU> selector) where TU : IComparable<TU>
        {
            using (IEnumerator<T> enumerator = e.GetEnumerator())
            {
                if (!enumerator.MoveNext()) { throw new InvalidOperationException("No elements in sequence"); }
 
                T max = enumerator.Current;
                TU value = selector(max);
                while (enumerator.MoveNext())
                {
                    TU v = selector(enumerator.Current);
                    if (value.CompareTo(v) < 0)
                    {
                        max = enumerator.Current;
                        value = v;
                    }
                }
 
                return max;
            }
        }
 
        /// <summary>
        /// Finds the object with the minimum value in the enumerable
        /// </summary>
        /// <typeparam name="T">Type of objects in the Enumerable</typeparam>
        /// <typeparam name="TU">Comparing type, must implement IComparable(T)</typeparam>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="selector">Function calculating the value that we want the min from</param>
        /// <returns>The object with the minimum value in the enumerable</returns>
        public static T MinValue<T, TU>(this IEnumerable<T> e, Func<T, TU> selector) where TU : IComparable<TU>
        {
            using (IEnumerator<T> enumerator = e.GetEnumerator())
            {
                if (!enumerator.MoveNext()) { throw new InvalidOperationException("No elements in sequence"); }
 
                T min = enumerator.Current;
                TU value = selector(min);
                while (enumerator.MoveNext())
                {
                    TU v = selector(enumerator.Current);
                    if (value.CompareTo(v) > 0)
                    {
                        min = enumerator.Current;
                        value = v;
                    }
                }
 
                return min;
            }
        }
        #endregion
 
        #region String extensions
        /// <summary>
        /// Appends multiple objects to a StringBuilder, separated by the given string
        /// </summary>
        /// <typeparam name="T">Type of elements in the Enumerable</typeparam>
        /// <param name="sb">StringBuilder to append to</param>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="separator">Separator string</param>
        /// <returns>The StringBuilder instance after the appending is done</returns>
        public static StringBuilder AppendJoin<T>(this StringBuilder sb, IEnumerable<T> e, string separator = "")
        {
            using (IEnumerator<T> enumerator = e.GetEnumerator())
            {
                if (enumerator.MoveNext())
                {
                    sb.Append(enumerator.Current);
                    while (enumerator.MoveNext())
                    {
                        sb.Append(separator).Append(enumerator.Current);
                    }
                }
 
                return sb;
            }
        }
 
        /// <summary>
        /// Returns true if the string is null, or the empty string ""
        /// Note: this will never throw a NullRef exception given that it is an extension method calling a static method
        /// </summary>
        /// <param name="s">String to test</param>
        /// <returns>True if the string is null or empty, false otherwise</returns>
        public static bool IsEmpty(this string s) => string.IsNullOrEmpty(s);
 
        /// <summary>
        /// Creates a substring from a starting and ending index
        /// </summary>
        /// <param name="s">String to substring</param>
        /// <param name="start">Starting index</param>
        /// <param name="end">Ending index</param>
        /// <returns>The resulting substring</returns>
        public static string SubStr(this string s, int start, int end) => s.Substring(start, (end - start) + 1);
        #endregion
 
        #region Number extensions
        /// <summary>
        /// Tests if the given number is pair or not
        /// </summary>
        /// <param name="n">Number to test</param>
        /// <returns>True if the number is pair, false otherwise</returns>
        public static bool IsPair(this int n) => (n & 1) == 0;
 
        /// <summary>
        /// Tests if the given number is pair or not
        /// </summary>
        /// <param name="n">Number to test</param>
        /// <returns>True if the number is pair, false otherwise</returns>
        public static bool IsPair(this long n) => (n & 1L) == 0;
 
        /// <summary>
        /// Real Modulus function over the integer, not a remainder function like the normal C# mod
        /// </summary>
        /// <param name="n">Left operand of the mod</param>
        /// <param name="m">Right operand of the mod</param>
        /// <returns>The Modulus of n and m, within [0, m - 1]</returns>
        public static int Mod(this int n, int m) => ((n % m) + m) % m;
 
        /// <summary>
        /// Real Modulus function over the integer, not a remainder function like the normal C# mod
        /// </summary>
        /// <param name="n">Left operand of the mod</param>
        /// <param name="m">Right operand of the mod</param>
        /// <returns>The Modulus of n and m, within [0, m - 1]</returns>
        public static long Mod(this long n, long m) => ((n % m) + m) % m;
 
        /// <summary>
        /// Returns the triangle number of the current number
        /// </summary>
        /// <param name="n">Integer to get the triangle number from</param>
        /// <returns>The resulting triangle number</returns>
        public static int Triangle(this int n) => (n * (n + 1)) / 2;
 
        /// <summary>
        /// Returns the triangle number of the current number
        /// </summary>
        /// <param name="n">Long to get the triangle number from</param>
        /// <returns>The resulting triangle number</returns>
        public static long Triangle(this long n) => (n * (n + 1L)) / 2L;
 
        /// <summary>
        /// Counts the amount of set bits (1s in the binary representation) of a given integer
        /// </summary>
        /// <param name="n">Integer to get the set bits from</param>
        /// <returns>Amount of set bits of the integer</returns>
        public static int SetBits(this int n)
        {
            n = n - ((n >> 1) & 0x55555555);
            n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
            return (((n + (n >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
        }
 
        /// <summary>
        /// Counts the amount of set bits (1s in the binary representation) of a given long
        /// </summary>
        /// <param name="n">Long to get the set bits from</param>
        /// <returns>Amount of set bits of the long</returns>
        public static long SetBits(this long n)
        {
            n = n - ((n >> 1) & 0x5555555555555555);
            n = (n & 0x3333333333333333) + ((n >> 2) & 0x3333333333333333);
            return (((n + (n >> 4)) & 0xF0F0F0F0F0F0F0F) * 0x101010101010101) >> 56;
        }
        #endregion
 
        #region Array extensions
        /// <summary>
        /// Does a binary search through the sorted array to find the requested value
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="value">Value to find</param>
        /// <returns>The index of the found element, or -1 if it wasn't found</returns>
        public static int BinarySearch<T>(this T[] array, T value) => Array.BinarySearch(array, value);
 
        /// <summary>
        /// Clears the array of all elements
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to clear</param>
        public static void Clear<T>(this T[] array) => Array.Clear(array, 0, array.Length);
 
        /// <summary>
        /// Determines if the array contains the given value
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="value">Value to find</param>
        /// <returns>True if the value was found, false otherwise</returns>
        public static bool Contains<T>(this T[] array, T value) => Array.IndexOf(array, value) != -1;
 
        /// <summary>
        /// Enumerates the contents of an ArraySegment
        /// </summary>
        /// <typeparam name="T">Type contained within the ArraySegment</typeparam>
        /// <param name="segment">Segment to enumerate</param>
        /// <returns>Enumerable of all the values contained in the ArraySegment</returns>
        public static IEnumerable<T> Enumerate<T>(this ArraySegment<T> segment)
        {
            int max = segment.Offset + segment.Count;
            for (int i = segment.Offset; i < max; i++)
            {
                yield return segment.Array[i];
            }
        }
 
        /// <summary>
        /// Sees if an elements matching the specified condition exists in the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="match">Matching function to apply</param>
        /// <returns>True if a matching element exists, false otherwise</returns>
        public static bool Exists<T>(this T[] array, Predicate<T> match) => Array.Exists(array, match);
 
        /// <summary>
        /// Finds the first element matching the given condition in the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="match">Matching function to apply</param>
        /// <returns>The first found element that satisfied the match, or default(T) if none did</returns>
        public static T Find<T>(this T[] array, Predicate<T> match) => Array.Find(array, match);
 
        /// <summary>
        /// Finds the last element matching the given condition in the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="match">Matching function to apply</param>
        /// <returns>The last found element that satisfied the match, or default(T) if none did</returns>
        public static T FindLast<T>(this T[] array, Predicate<T> match) => Array.FindLast(array, match);
 
        /// <summary>
        /// Applies an action to every member of the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to loop through</param>
        /// <param name="action">Action to apply on each member</param>
        public static void ForEach<T>(this T[] array, Action<T> action) => Array.ForEach(array, action);
 
        /// <summary>
        /// Generates all the subsets of the given array of a size greater than 1
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to get the subsets from</param>
        /// <returns>All the subsets of size 1 or greater from the array</returns>
        public static IEnumerable<List<T>> GetSubsets<T>(this T[] array)
        {
            int max = 1 << array.Length, l = array.Length - 1;
            for (int i = 1; i < max; i++)
            {
                if ((i & -i) == i) { continue; }
 
                List<T> subset = new List<T>(array.Length);
                subset.AddRange(array.Where((t, j) => (i & (1 << (l - j))) != 0));
                yield return subset;
            }
        }
 
        /// <summary>
        /// Finds the first index of the given value in the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="value">Value to find</param>
        /// <returns>The index of the value in the array, or -1 if it wasn't found</returns>
        public static int IndexOf<T>(this T[] array, T value) => Array.IndexOf(array, value);
 
        /// <summary>
        /// Finds the last index of the given value in the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="value">Value to find</param>
        /// <returns>The last index of the value in the array, or -1 if it wasn't found</returns>
        public static int LastIndexOf<T>(this T[] array, T value) => Array.LastIndexOf(array, value);
 
        /// <summary>
        /// Reverses the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to reverse</param>
        /// <returns>The reversed array</returns>
        public static T[] Reverse<T>(this T[] array)
        {
            Array.Reverse(array);
            return array;
        }
 
        /// <summary>
        /// Sorts the array with the default comparer of T
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to sort</param>
        public static void Sort<T>(this T[] array) => Array.Sort(array);
 
        /// <summary>
        /// Sorts an array with the given comparison method
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to sort</param>
        /// <param name="comparison">Comparison method to sort the array with</param>
        public static void Sort<T>(this T[] array, Comparison<T> comparison) => Array.Sort(array, comparison);
        #endregion
    }
}

2).
using System;
namespace Dracula
{
    class Program
    {
        static void Main(string[] args)
        {
            var queens = new Queens(int.Parse(Console.ReadLine()));
            queens.Solved();
        }
    }
    
    public class Queens
    {
        private int _n;
        private bool[][] _queens;
        
        private bool[] _colEmpty;
        private bool[] _upDiagEmpty;
        private bool[] _downDiagEmpty;
        
        
        public Queens(int n)
        {
            _n = n;
            _queens = new bool[_n][];
            _colEmpty = new bool[_n];
            for(int i=0; i < _n; i++)
            {
                _queens[i] = new bool[_n];
                _colEmpty[i] = true;
            }
            
            _upDiagEmpty = new bool[(_n*2) - 1];
            _downDiagEmpty = new bool[(_n*2) - 1];
            for(int i=0; i < (_n*2)-1; i++)
            {
                _upDiagEmpty[i] = true;
                _downDiagEmpty[i] = true;
            }
        }
        
        public void Solved()
        {
            if(FindTheSolutions(0)){
                DisplayBoard();
            }else{
                Console.WriteLine("Not possible");
            }
        }
        
        private bool FindTheSolutions(int row)
        {
            if(row == _n)
            {
                return true;
            }
            
            for(int col = 0; col < _n; col++)
            {
                if(IsSafe(row, col))
                {
                    PlaceQueen(row, col);
                    
                    if(FindTheSolutions(row+1)){
                        return true;
                    }
                    
                    RemoveQueen(row, col);
                }
            }
            
            return false;
        }
        
        private void DisplayBoard()
        {
            for(int i=0;i<_n;i++)
            {
                for(int j=0; j<_n; j++)
                {
                    
                    Console.Write(_queens[i][j] ? "1 " : "0 ");
                }
                Console.WriteLine();
            }
        }
        
        private bool IsSafe(int r, int c)
        {
            bool isSafe = _colEmpty[c] && _upDiagEmpty[r+c] 
                        && _downDiagEmpty[(_n-1) + r - c];
            return isSafe;
        }
        
        private void PlaceQueen(int r, int c)
        {
            _queens[r][c] = true;
            _colEmpty[c] = false;
            _upDiagEmpty[r+c] = false;
            _downDiagEmpty[(_n-1)+r-c] = false;
        }
        private void RemoveQueen(int r, int c)
        {
            _queens[r][c] = false;
            _colEmpty[c] = true;
            _upDiagEmpty[r+c] = true;
            _downDiagEmpty[(_n-1)+r-c] = true;
        }
    }
}

Java:
1).
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
import java.util.*;
 
class TestClass {
    
    static int board[][];
    static int N;
    public static void main(String args[] ) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        N = Integer.parseInt(line);
        board = new int [N][N];
        if (nQueenSolve(0)) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    System.out.print(board[i][j] + " ");
                }
                System.out.println();
            }
        } else {
            System.out.print("Not possible");
        }
    }
    
    private static boolean nQueenSolve(int level) {
        for (int i = 0; i < N; i++) {
            if (isSafePosition(level, i)) {
            	//System.out.println("Safe position found at " + level + " " + i);
                board[level][i] = 1;
                if (level == N - 1) {
                    return true;
                } else {
                    if(!nQueenSolve(level + 1)) {
                        board[level][i] = 0;
                        continue;
                    } else {
                    	return true;
                    }
                }
            }
        }
        return false;
    }
    
    private static boolean isSafePosition(int x, int y) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N && !(board[i][j] == 1 && x == i && y==j); j++) {
                if (board[i][j] == 1 && (x == i || y == j || (x + y == i + j) || (x - y == i - j))) {
                    // Lie on the diagonals or lie on the same straight line
                   // System.out.println("safePos return false for " + x + " " + y + " : " + i + " " + j);
                    return false;
                }
            }
        }
        return true;
    }
}
2).
//IMPORTANT: Multiple classes and nested static classes are supported
//uncomment this if you want to read input.
//imports for BufferedReader

import java.io.BufferedReader;
import java.io.InputStreamReader;

//import for Scanner and other utility classes

class TestClass {
    
    static int number = 0;
    public static void main(String args[] ) throws Exception {
        //
        //Read input from stdin and provide input before running
        // Use either of these methods for input
 
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String line = br.readLine();
        //int N = Integer.parseInt(line);
        //
        //Scanner
        //Scanner s = new Scanner(System.in);
        //int N = s.nextInt();
        //
        //for (int i = 0; i < N; i++) {
        //    System.out.println("hello world");
        //}
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int n = Integer.parseInt(line);
        number = n;
        int arr[][] = new int[n][n];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                arr[i][j]=0;
            }
        }
//        int arr1[][] = arr;
        boolean done = false;
        for(int i = 0; i < n; i++)
        {
//        	arr = arr1;	
//        	System.out.println("In main For position x, y"+ 0 +","+i);
//       	 	for(int k = 0; k < number; k++)
//            {
//                for(int d = 0; d < number; d++)
//                {
//                    System.out.print(arr[k][d]);
//                }
//                System.out.println();
//            }
//       	System.out.println("-------------------");
        	
            done = makeBoard(arr, n, 0, i);
            if(done)
            {
            	break;
            }
        }
        
        if(done)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    System.out.print(arr[i][j] + " ");
                }
                System.out.println();
            }
        }
        else
        {
            System.out.println("Not possible");
        }
 
    }
    
    private static boolean makeBoard(int arr[][], int n, int x, int y)
    {
        boolean done = false;
        if(n>0 && x==number)
        {
            return false;
        }
        else if(n==0)
        {
            return true;
        }
        else
        {
            if(!isAttacked(arr, x, y))
            {
                arr[x][y]=1;
                n = n-1;
                if(n==0)
                {
                	return true;
                }
                for(int j = 0; j<number; j++)
                {
                	
                    done = makeBoard(arr, n, x+1, j);
                    if(done)
                    {
                        break;
                    }
                }
                if(!done)
                {
                	arr[x][y]=0;
                }
                
            }
            else
            {
                return false;
            }
        }
        return done;
    }
    
    private static boolean isAttacked(int arr[][], int x, int y)
    {
         for(int i = 0; i < number; i++)
        {
            for(int j = 0; j < number; j++)
            {
                if(arr[i][j]==1)
                {
                    if(x==i || y==j)
                    {
                        return true;
                    }
                    else if(i+j==x+y || i-j==x-y)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
}

Java 8:
1).
import java.util.*;
import java.io.*;
 
public class NQueenSolution {
	
	private static boolean isAttacked(Boolean[][] grid, int x, int y) {
		int i = 0;
		int N = grid.length;
		
		// Iterate over positions of the same (y)
		for(i=0; i<N; ++i) {
			if(grid[i][y] == true) {
				return true;
			}
		}
		
		// Iterate over positions of the same (x)
		for(i=0; i<N; ++i) {
			if(grid[x][i] == true) {
				return true;
			}
		}
		
		// Iterate over diagonal positions
		
		// First diagonal
		int d1_x = 0, d1_y = 0;
		if(x <= y) {
			d1_x = 0;
			d1_y = y - x;
		} else {
			d1_x = x - y;
			d1_y = 0;
		}
		
		while(d1_x < N && d1_y < N) {
			if(grid[d1_x][d1_y] == true) {
				return true;
			}
			d1_x += 1;
			d1_y += 1;
		}
			
		// Second diagonal
		if(N-1 - x < y) {
			y -= N-1 - x;
			x = N-1;
			while(y < N) {
				if(grid[x][y] == true) {
					return true;
				}
				x -= 1;
				y += 1;
			}
		} else {
			x += y;
			y = 0;
			while(x >= 0) {
				if(grid[x][y] == true) {
					return true;
				}
				x -= 1;
				y += 1;
			}
		}
		
		
		// Not attacked then...
		return false;
	}
	
	private static boolean placeQueen(Boolean[][] grid, int Q) {
		int N = grid.length;
		// Base case: Placed (N) queens, where (N x N) are the grid dimensions
		if(Q == N) { 
			return true;
		}
		
		boolean placedAll;
		
		// Iterate over all unattacked positions in the Q-th row
		for(int j=0; j<N; ++j) {
			if(!isAttacked(grid, Q, j)) {
				grid[Q][j] = true; // Place queen at (i, j)
				placedAll = placeQueen(grid, Q+1);
				if(placedAll) { // Solution found!
					return true;
				} else {
					grid[Q][j] = false; // Remove queen from (i, j)
				}
			}
		}
		
		// Tried all positions and couldn't find a solution...
		return false;
	}
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
 
		int N = sc.nextInt();
		Boolean grid[][] = new Boolean[N][N];	
		
		for(int i=0; i<N; ++i) {
		    for(int j=0; j<N; ++j) {
		        grid[i][j] = false;
		    }
		}
						
		if(placeQueen(grid, 0)) {
			for(Boolean[] row : grid) {
				for(Boolean pos : row) {
					System.out.print((pos ? 1 : 0) + " ");
				}
				System.out.println();
			}
			
		}  else {
			System.out.println("Not possible");
		}
		
		sc.close();
	}
 
}

2).
// IMPORTANT: Multiple classes and nested static classes are supported
 
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
//import for Scanner and other utility classes
import java.util.*;
import java.lang.Integer;
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        // Sample code to perform I/O:
        // Use either of these methods for input
 
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        //Scanner
        //Scanner s = new Scanner(System.in);
        //String name = s.nextLine();                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        // Write your code here
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[][] board = new int[n][n];
        placeQueens(board);
 
    }
    
	static void printBoard(int[][] board) {
		for (int i = board.length-1; i >= 0; i--) {
			for (int j : board[i]) {
				System.out.print(j + " ");
			}
			System.out.print("\n");
		}
	}
	
	static void placeQueens(int[][] board) {
		if (placeQueens(board, board.length)) {
			printBoard(board);
		} else {
			System.out.println("Not possible");
		}
	}
	
	static boolean placeQueens(int[][] board, int remainingQueens) {
		if (remainingQueens == 0) {
			return true;
		}
		
		//As each row can have only one queen in a solution, we start with the current
		//row board[remaingingQueens-1][0..n-1]. Loop through each column on the current
		//row to find the solution
		for (int j = 0; j < board.length; j++) {
			//check whether the current cell is open for a queen
			if (canPlace(board, remainingQueens-1, j)) {
				//if yes, then try to place the next queen on the next row
				//we use remainingQueens to indicate which row to try next
				if (!placeQueens(board, remainingQueens-1)) {
					//backtrack if there is no solution for the next queen if we 
					//start the current queen in board[remainingQueens-1][j]
					board[remainingQueens-1][j] = 0;
				} else {
					return true;
				}
			} 
		}
 
		return false;
	}
	
	static boolean canPlace(int[][] board, int r, int c) {
		for (int i = 0; i < board.length; i++) {
			if (board[r][i] == 1 && i != c) return false;
		}
		
		for (int i = 0; i < board.length; i++) {
			if (board[i][c] == 1 && i != r) return false;
		}
		
		for (int i=r+1, j=c+1; i<board.length & j<board.length; i++, j++) {
			if (board[i][j] == 1) return false;
		}
		for (int i=r-1, j=c-1; i>=0 & j>=0; i--, j--) {
			if (board[i][j] == 1) return false;
		}
 
		for (int i=r-1, j=c+1; i>=0 & j<board.length; i--, j++) {
			if (board[i][j] == 1) return false;
		}
		for (int i=r+1, j=c-1; i<board.length & j>=0; i++, j--) {
			if (board[i][j] == 1) return false;
		}
		board[r][c] = 1;
		return true;
	}
}
3).
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
class TestClass{
	static boolean flag=false;
    public static void main(String [] args) throws Exception{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int board [][] =new int [N][N];
        NQueens(board,0);
        if(!flag){
        	System.out.println("Not possible");
        }
    }
    
    public static void NQueens(int [][] board,int row){
    	if(flag){
    		return;
    	}
        if(row==board.length){
            for(int i=0;i<board.length;i++){
                for(int j=0;j<board.length;j++){
                    System.out.print(board[i][j]+" ");
                }
                System.out.println();
            }
            flag=true;
            return;
        }
        
        for(int col=0;col<board.length;col++){
            if(is_is_safe(board,row,col)){
                board[row][col]=1;
                NQueens(board,row+1);
                board[row][col]=0;
            }
        }
    }
    
    public static boolean is_is_safe(int [][] board,int row,int col){
        for(int i=row;i>=0;i--){
            if(board[i][col]==1)
               return false;
        }
        
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]==1)
               return false;
        }
        
        for(int i=row,j=col;i>=0 && j<board[row].length;i--,j++){
            if(board[i][j]==1)
               return false;
        }
        
        return true;
    }
}
4).
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
//import for Scanner and other utility classes
import java.util.*;
 
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner s = new Scanner(System.in);
        final int n = Integer.parseInt(s.nextLine());
        Board board = new Board(n);
        if (NQueens(board, 0)) board.print();
        else System.out.print("Not possible");
    }
    
    static boolean NQueens(final Board board, int r) {
        if (r == board.size) return true;
 
        for (int c = 0; c < board.size; c++) {
            if (board.canPlace(r, c)) {
                board.place(r, c);
                if (NQueens(board, r + 1))
                    return true;
                board.remove(r, c);
            }
        }
        return false;
    }
    
    static class Board {
        final int size;
        final int[][] board;
        Set<Integer> occupiedCols = new HashSet<>();
        Set<Integer> occupiedDiagonal = new HashSet<>();
        Set<Integer> occupiedAntiDiagonal = new HashSet<>();
 
        Board(int size) {
            this.size = size;
            this.board = new int[size][size];
        }
 
        boolean canPlace(int r, int c) {
            return !occupiedCols.contains(c) &&
                   !occupiedDiagonal.contains(startDiagonal(r, c)) &&
                   !occupiedAntiDiagonal.contains(startAntiDiagonal(r, c));
        }
 
        void place(int r, int c) {
            occupiedCols.add(c);
            occupiedDiagonal.add(startDiagonal(r, c));
            occupiedAntiDiagonal.add(startAntiDiagonal(r, c));
            board[r][c] = 1;
        }
 
        void remove(int r, int c) {
            occupiedCols.remove(c);
            occupiedDiagonal.remove(startDiagonal(r, c));
            occupiedAntiDiagonal.remove(startAntiDiagonal(r, c));
            board[r][c] = 0;
        }
 
        boolean valid(int r, int c) { return r >= 0 && r < size && c >= 0 && c < size; }
 
        int cellId(int r, int c) { return valid(r, c) ? r * size + c : -1; }
 
        int startDiagonal(int r, int c) {
            if (r == c) return 0;
 
            int dr = 0; int dc = 0;
            if (r > c) dr = r - c;
            else dc = c - r;
            return (valid(dr, dc)) ? cellId(dr, dc) : cellId(r, c);
        }
 
        int startAntiDiagonal(int r, int c) {
            int dr = 0; int dc = r + c;
            if (dc >= size) {
                dc = size - 1; dr = r - (dc - c);
            }
            return (valid(dr, dc)) ? cellId(dr, dc) : cellId(r, c);
        }
 
        void print() {
            for (int r = 0; r < size; r++) {
                for (int c = 0; c < size; c++) {
                    if (c != 0) System.out.print(" ");
                    System.out.print(board[r][c]);
                }
                System.out.println();
            }
        }
    }
}

JavaScript(Node.js):
1).
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});
 
process.stdin.on("end", function () {
   main(stdin_input);
});
 
var results = [];
 
function main(input) {
    //process.stdout.write("Hi, " + input + ".\n");       // Writing output to STDOUT
    let n = Number(input);
    let arr = new Array(n);
    for(var i=0;i<n; i++) {
		arr[i] = new Array(n).fill(0)
    }	
    
    nQ(arr, n, 0);
	if(results.length > 0) {
	    printArray();
	} else {
	    console.log('Not possible');
	}
}
 
let answer = false;
 
function nQ(arr, n, i) {
	
	if(n==2 || n==3) 
        return false;
	
	if(i==n) {
	    awnser = true;
        results.push(JSON.parse(JSON.stringify(arr)));
        return true;
	}
 
    let flag = false;
	for(let j =0; j<n; j++) {
		if(isValid(arr, n, i, j)) {
			arr[i][j] = 1;
                           
            if(nQ(arr, n, i+1)) {
                flag = true;
            }
 
            arr[i][j] = 0;
		}
    }
 
	return flag;
}
 
function isValid(arr, n, i, j) {
	
	let k=0;
	let l=0;
 
	// column check
	for(k=0; k<n;k++)
		if(arr[i][k] == 1)
			return false;
	// row check
    for(k=0; k<n;k++)
		if(arr[k][j] == 1)
			return false;	
 
	let d = Math.min(i,j);
		
	for(k = i-d, l = j-d; k<n && l<n; k++, l++)
		if(arr[k][l] == 1)
			return false;	
 
    d = Math.min(i, n-1-j);
 
    for(k = i-d, l = j+d; k<n && l>=0; k++, l--)
		if(arr[k][l] == 1)
			return false;	
 
	return true;
}
 
function printArray() {
    for(i=0;i<results[0].length;i++)
    	console.log(results[0][i].join(' '))
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
// Write your code here

2).
'use strict';
 
function place(r, c, board) {
  for (let prev = 0; prev < c; prev++) {
    if (board[prev] === r || (Math.abs(board[prev] - r) == Math.abs(prev - c)))
      return false;
  }
 
  return true;
}
 
let answer = false;
 
function backTrack(c, board) {
  if (c === board.length && !answer) {
    for (let j = 0; j < board.length; j++) {
      for (let i = 0; i < board.length; i++) {
        if (board[j] == i)
          process.stdout.write('1 ');
        else
          process.stdout.write('0 ');
      }
 
      console.log();
    }
    answer = true;
    return board;
  }
 
  for (let r = 0; r < board.length; r++) {
    if (place(r, c, board)) {
      board[c] = r;
      backTrack(c + 1, board);
    }
  }
 
}
 
function main() {
  const is = new Scanner();
  const n = is.nextInt();
  if (n <= 3 && n !== 1) {
    console.log('Not possible');
    return;
  }
 
  const board = new Array(n).fill(0);
  backTrack(0, board);
 
 
}
 
//
// api stdin
//
 
class Scanner {
  constructor() {
    this.index = 0;
    this.lines = stdinInput.trim().split('\n');
  }
 
  nextLine () {
    return this.lines[this.index++];
  }
 
  nextInt () {
    return parseInt(this.nextLine());
  }
 
  nextDouble () {
    return parseFloat(this.nextLine());
  }
 
  nextArray(cast = String) {
    return this.nextLine().split(' ').map(cast);
  }
 
  hasNext () {
    return this.index < this.lines.length;
  }
}
 
let stdinInput = '';
process.stdin.resume();
process.stdin.setEncoding('utf-8');
process.stdin.on('data', input => stdinInput += input);
process.stdin.on('end', () => main());

Pascal:
program Hello;
var board:array [1..10,1..10] of byte;
    col:array [1..10] of boolean;
    right:array[-20..20] of boolean;
    left:array[-20..20] of boolean;
    ch:boolean;
    n,j:byte;
    
procedure check(row:byte);
var i:byte;
begin
    if row > n then
    begin
        ch:=true;
        for i:=1 to n do
        begin
            for j:=1 to n do
                write(board[i][j],' ');
            writeln;
        end;
        exit;
    end;
    for i:=1 to n do
    if not col[i] and not left[row+i] 
    and not right[i-row] then
    begin
        col[i]:=true;
        left[row+i]:=true;
        right[i-row]:=true;
        board[row][i]:=1;
        check(row+1);
        col[i]:=false;
        left[row+i]:=false;
        right[i-row]:=false;
        board[row][i]:=0;
        if ch then exit;
    end;
end;
 
begin
    fillchar(board,sizeof(board),0);
    fillchar(right,sizeof(right),false);
    fillchar(left,sizeof(left),false);
    fillchar(col,sizeof(col),false);
    ch:=false;
    readln(n);
    check(1);
    if not ch then writeln('Not possible');
end.

PHP:
<?php
// N-Queens problem: put N Queens on a chess board NxN 
// sized such that they aren't at risk of capture
class Queens
{
	private $board = array();
	private $numQueens = 8;
	
	public function __construct($n = 8)
	{
		$this->numQueens = $n;
		
		// Fill the board with 0s
		for($i = 0; $i < $n; $i++)
		{
			$this->board[$i] = array_fill(0, $n, 0);
		}
	}
	
	function solve($queenNum, $row)
	{
		for($col = 0; $col < $this->numQueens; $col++)
		{
			if($this->allowed($row, $col))
			{
				// if this cell is allowed, set the queen here
				$this->board[$row][$col] = 1;
				
				// If last queen or subsequent queens have been placed, return
				if(($queenNum === $this->numQueens - 1) || $this->solve($queenNum + 1, $row + 1) === true) return true;
				
				// otherwise, if we get here we've backtracked and have to try replacing this queen
				$this->board[$row][$col] = 0;
			}
		}
		
		return false;
	}
	
	function allowed($x, $y)
	{
		$n = $this->numQueens;
		
		// Only test as far as the row being entered because there will never
		// be a situation where a Queen is moved behind other Queens.
		// Any further rows will all be empty.
		for($i = 0; $i < $x; $i++)
		{
			// test the column to check for another Queen
			if($this->board[$i][$y] === 1) return false;
			
			// Test the diagonals (backwards from the coordinate)
			$tx = $x - 1 - $i;
			$ty = $y - 1 - $i;	// diagonal this way \
			if(($ty >= 0) && ($this->board[$tx][$ty] === 1)) return false;
			
//			$tx = $x + 1 + $i;	// diagonal this way /
			$ty = $y + 1 + $i;	// diagonal this way /
			if(($ty < $n) && ($this->board[$tx][$ty] === 1)) return false;
		}
		
		return true;
	}
	
	// Rudimentary printing method
	function printBoard()
	{
		for($row=0; $row<$this->numQueens; $row++)
		{
			$sep = '-';
			for($col=0; $col<$this->numQueens; $col++)
			{
//				$sep .= '--';	// for every column add 2 dashes to then print below the row
				echo ' ';
				
				$cell = $this->board[$row][$col];
				if($cell === 1)
				{
					echo '1';
				}
				else
				{
					echo '0';
				}
			}
			
			echo "\n";
//			echo $sep . "\n";	// print the seperator row -------
		}
	}
}
// Run main ...
$L=intval(fgets(STDIN));
$queens = new Queens($L);
$ret = $queens->solve(0, 0);
if($ret === false)
echo "Not possible";
else
$queens->printBoard();
?>

Ruby:
n = gets.chomp.to_i
 
def solve(pos, row, size)
  return true if row == size
  
  (0...size).each do |col|
    found_safe = true
    (0...row).each do |q|
      found_safe = false && break if pos[q][:col] == col || (pos[q][:row] + pos[q][:col]) == (row + col) || (pos[q][:row] - pos[q][:col]) == (row - col)
    end
    
    if found_safe
      pos[row] = {:row => row, :col => col}
      return true if solve(pos, row + 1, size)
    end
  end
 
  return false
end
 
pos = []
 
if solve(pos, 0, n)
  (0...n).each do |row|
    (0...n).each do |col|
      print("#{pos[row][:col] == col ? 1 : 0} ")
    end
    print("\r\n")
  end
else
  puts "Not possible"
end

Python:
1).
n=input()
board=[[0 for i in xrange(n)] for j in xrange(n)]
 
def is_attacked(x,y):
    for i in xrange(n):
        if board[x][i] or board[i][y]:
            return True
    
    i,j=x-1,y+1
    while 0<=i and j<n:
        if board[i][j]==1:
            return True
        i-=1
        j+=1
    
    i,j=x-1,y-1
    while 0<=i and 0<=j:
        if board[i][j]==1:
            return True
        i-=1
        j-=1
        
    i,j=x+1,y-1
    while i<n and 0<=j:
        if board[i][j]==1:
            return True
        i+=1
        j-=1
    
    i,j=x+1,y+1
    while i<n and j<n:
        if board[i][j]==1:
            return True
        i+=1
        j+=1    
    return False
 
def N_Queens(N,z):
    if N==0: return True
    for i in xrange(z,z+1):
        for j in xrange(n):
            if is_attacked(i,j):
                continue
            board[i][j] = 1
            if N_Queens(N-1,i+1):
                return True
            board[i][j] = 0
    return False
 
if N_Queens(n,0):
    for i in xrange(n):
        for j in xrange(n):
            print board[i][j],
        print
else: print "Not possible"

2).
from __future__ import print_function
 
def read_single_integer():
    return int(raw_input().strip())
 
 
def read_array_of_integers():
    return map(int, raw_input().strip().split())
 
 
def read_single_string():
    return raw_input().strip()
 
 
def is_safe(board, row, col, n):
    for i in range(row):
        if board[i][col] == 1:
            return False
 
    for i, j in zip(range(row, -1, -1), range(col, n, 1)):
        if board[i][j] == 1:
            return False
 
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
 
    return True
 
 
def solve(board, row, n):
    # print(col, board)
    if row >= n:
        return True
 
    for i in range(n):
        if is_safe(board, row, i, n):
            board[row][i] = 1
 
            if solve(board, row + 1, n):
                return True
 
            board[row][i] = 0
    return False
 
 
def print_board(board, n):
    for i in range(n):
        for j in range(n):
            print(board[i][j], end=" ")
        print()
 
 
n = read_single_integer()
board = []
for i in xrange(n):
    board.append([0] * n)
if n == 2 or n == 3:
    print("Not possible")
elif solve(board, 0, n):
    print_board(board, n)
else:
    print("Not possible")

3).
def noConflicts(board, current):
	for i in range(current):
		if(board[i] == board[current]):
			return False
 
		if((current-i) == abs(board[current]-board[i])):
			return False
	return True				
 
 
def rQueens(board, current, size):
	if(current == size):
		return True
	else:
		for i in range(size):
			board[current] = i
			if(noConflicts(board, current)):
				done = rQueens(board, current+1, size)
				if(done):
					return True
		return False					
 
 
def nQueens():
	n = int(raw_input())
	board = [-1]*n
	done = rQueens(board, 0 , n)
	if(done):
		chess = [[0]*n for i in range(n)]
		for i in range(n):
			chess[i][board[i]] = 1
		
		for i in range(n):
			for j in range(n):
				print(chess[i][j]),
			print		
	else:
		print('Not possible')	
 
 
nQueens()

4).
def check(x,y,pos):
    for p,q in pos:
        if x == p:
            return True
        if y == q:
            return True
        if abs(x-p) == abs(y-q):
            return True
    return False
def bt(size,n,pos):
    if n == size:
        return pos
    for i in range(size):
        if not check(n,i,pos):
            ans = bt(size,n+1,pos+[(n,i)])
            if ans:
                return ans
    return 0
 
n = input()
pos = bt(n,0,[])
if pos:
    for i in range(n):
        for j in range(n):
            if (i,j) in pos:
                print 1,
            else:
                print 0,
        print
else:
    print 'Not possible'

Python 3:


*/

/*I/O:
In  #1:
1
Out #1:
1 
In  #2:
2
Out #2:
Not possible
In  #3:
3
Out #3:
Not possible
In  #4:
4
Out #4:
0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 
In  #5:
5
Out #5:
1 0 0 0 0 
0 0 1 0 0 
0 0 0 0 1 
0 1 0 0 0 
0 0 0 1 0 
In  #6:
6
Out #6:
0 1 0 0 0 0 
0 0 0 1 0 0 
0 0 0 0 0 1 
1 0 0 0 0 0 
0 0 1 0 0 0 
0 0 0 0 1 0 
In  #7:
7
Out #7:
1 0 0 0 0 0 0 
0 0 1 0 0 0 0 
0 0 0 0 1 0 0 
0 0 0 0 0 0 1 
0 1 0 0 0 0 0 
0 0 0 1 0 0 0 
0 0 0 0 0 1 0 
In  #8:
8
Out #8:
1 0 0 0 0 0 0 0 
0 0 0 0 1 0 0 0 
0 0 0 0 0 0 0 1 
0 0 0 0 0 1 0 0 
0 0 1 0 0 0 0 0 
0 0 0 0 0 0 1 0 
0 1 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 
In  #9:
9
Out #9:
1 0 0 0 0 0 0 0 0 
0 0 1 0 0 0 0 0 0 
0 0 0 0 0 1 0 0 0 
0 0 0 0 0 0 0 1 0 
0 1 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 0 
0 0 0 0 0 0 0 0 1 
0 0 0 0 0 0 1 0 0 
0 0 0 0 1 0 0 0 0 
In  #10:
10
Out #10:
1 0 0 0 0 0 0 0 0 0 
0 0 1 0 0 0 0 0 0 0 
0 0 0 0 0 1 0 0 0 0 
0 0 0 0 0 0 0 1 0 0 
0 0 0 0 0 0 0 0 0 1 
0 0 0 0 1 0 0 0 0 0 
0 0 0 0 0 0 0 0 1 0 
0 1 0 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 0 0 
0 0 0 0 0 0 1 0 0 0 

*/

/*Editorial:
Here in this solution i am using backtracking approach. In this problem we have to place a queens if possible in each row such that it is at safe position. 
safe position here means: 
1. there is no other queen in that same row 
2. there is no other queen in that same coloumn. 
3. there is no other queen present diagnoaly corresponding to the current position.
for checking these three things i have made a funciton issafe(); and for solving the main problem recursively(using backtracking) i have made a solve function.

#include<bits/stdc++.h>
using namespace std;
int ar[11][11];
int n;

bool issafe(int row,int col)
{
    // coloumn check
    int count=0;
    for(int k=0;k<row;k++)
        if(ar[k][col]==1)
            return false;


    //upper right diagnoal 
    int k=row; int l=col;
    while(k>=0&&l<n){
        if(ar[k][l]==1)
            return false;
        k--; 
        l++;    
    }

    //upper left diagnoal
    k=row; l=col;
    while(k>=0&&l>=0)
    {
        if(ar[k][l]==1)
            return false;
        k--; 
        l--;
    }
    return true;
}

bool solve(int row)
{
    if(row>=n)
        return true;

    for(int i=0;i<n;i++)
    {
        if(issafe(row,i)){
            ar[row][i]=1;
            if(solve(row+1))
                return true;
            ar[row][i]=0;
        }
    }
    return false;
}

void print1()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }
}

main()
{
    cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		    ar[i][j]=0;

    if(solve(0))
        print1();
    else
        cout<<"Not possible";
}

Author Solution by Vaibhav Jaimini
#include<bits/stdc++.h>
using namespace std;
int mat[110][110]={0};
int n;
int state=0;
int attacked(int x, int y){
	if(mat[x][y])return 1;
	for(int i=1; i<=n; i++){
		
		if(y-i >= 1  && mat[x][y-i])return 1;
		if(y+i <= n && mat[x][y+i])return 1;
		if(x-i >= 1 && mat[x-i][y])return 1;
		if(x+i <= n && mat[x+i][y])return 1;
		if(x-i >= 1 && y-i >= 1 && mat[x-i][y-i])return 1;
		if(x+i <= n && y+i <= n && mat[x+i][y+i])return 1;
		if(x+i <= n && y-i >= 1 && mat[x+i][y-i])return 1;
		if(x-i >= 1 && y+i <= n && mat[x-i][y+i])return 1;
	}
	return 0;
}
void print(){
	cout<<endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
		cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
int solve(int x){
	if(x == 0){
		print();
		return 1;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(attacked(i, j) == 1)continue;
			mat[i][j] = 1;
			if(solve(x-1))return 1;
			mat[i][j] = 0;
		}
	}
	return 0;
}
int main(){
	cin>>n;
	if(solve(n))
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
		cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	else
		cout<<"Not possible\n";
	return 0;
}


// C/C++ program to solve N Queen Problem using backtracking - Printing all solutions in N-Queen Problem
#include<bits/stdc++.h> 
#define N 4 
  
// A utility function to print solution
void printSolution(int board[N][N]) 
{ 
    static int k = 1; 
    printf("%d-\n",k++); 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n"); 
    } 
    printf("\n"); 
} 
  
// A utility function to check if a queen can 
// be placed on board[row][col]. Note that this 
// function is called when "col" queens are 
// already placed in columns from 0 to col -1. 
// So we need to check only left side for 
// attacking queens 
bool isSafe(int board[N][N], int row, int col) 
{ 
    int i, j; 
  
    // Check this row on left side 
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    // Check upper diagonal on left side 
    for (i=row, j=col; i>=0 && j>=0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    // Check lower diagonal on left side 
    for (i=row, j=col; j>=0 && i<N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 
  
// A recursive utility function to solve N Queen problem 
bool solveNQUtil(int board[N][N], int col) 
{ 
    // base case: If all queens are placed 
    then return true 
    if (col == N) 
    { 
        printSolution(board); 
        return true; 
    } 
  
    // Consider this column and try placing 
    this queen in all rows one by one 
    bool res = false; 
    for (int i = 0; i < N; i++) 
    { 
        // Check if queen can be placed on 
        board[i][col]
        if ( isSafe(board, i, col) ) 
        { 
            // Place this queen in board[i][col]
            board[i][col] = 1; 
  
            // Make result true if any placement 
            // is possible 
            res = solveNQUtil(board, col + 1) || res; 
  
            // If placing queen in board[i][col] 
            //doesn't lead to a solution, then 
            //remove queen from board[i][col]
            board[i][col] = 0; // BACKTRACK 
        } 
    } 
  
    // If queen can not be place in any row in 
        this column col then return false
    return res; 
} 
  
//This function solves the N Queen problem using 
//Backtracking. It mainly uses solveNQUtil() to 
//solve the problem. It returns false if queens 
//cannot be placed, otherwise return true and 
//prints placement of queens in the form of 1s. 
//Please note that there may be more than one 
//solutions, this function prints one of the 
//feasible solutions.

void solveNQ() 
{ 
    int board[N][N]; 
    memset(board, 0, sizeof(board)); 
  
    if (solveNQUtil(board, 0) == false) 
    { 
        printf("Solution does not exist"); 
        return ; 
    } 
  
    return ; 
} 
  
// driver program to test above function 
int main() 
{ 
    solveNQ(); 
    return 0; 
} 

*/
