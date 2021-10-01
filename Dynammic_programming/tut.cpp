 /*By Saksham Awasthi*/
               
#include<bits/stdc++.h>
using namespace std;
               
               
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define M_PI            3.14159265358979323846
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++);
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<endl;
 
 
const int N=1e5+2 ;
const int MOD =1e9+7;

 vector<int>dp(100,-1);
 int fibUp(int n){
     if(n==0 or n==1)return n;
     if(dp[n]!=-1)return dp[n];
     return dp[n]=fibUp(n-1)+fibUp(n-2);
 }

 int fibLow(int n){
     vector<int> d(n+1,0);
  
     d[0]=0;
     d[1]=1;
     loop(i,2,n){
         d[i]=d[i-1]+d[i-2];
     }
     return d[n];

 }

int fib(int n ){
    if(n==0 or n==1)return n;
    return fib(n-1)+fib(n-2);
}               
signed main()
{
 cout<<fibLow(5)<<endl;
 
return 0;
}