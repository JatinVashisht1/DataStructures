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
#define loop(i,a,b) 	for(int i=(a);i<(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++);
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<endl;
 
 
const int N=1e5+2 ;
const int MOD =1e9+7;
               
               
signed main()
{
    int marks[20][5];
    loop(i,0,20){
        loop(j,0,5){
            cin>>marks[i][j];
        }
    }
    int avgStu[5];
    loop(i,0,5){
        int sum =0;
        loop(j,0,20){
          sum+=marks[j][i];
        }
        avgStu[i]=sum;
    }
    cout << "The average marks obtained in each subject"<<endl;
    loop(i,0,5){
        cout<<"subject "<<i+1<<" = "<<avgStu[i]<<endl;
    }
        ///average marks for each student
        int avgSub[20];
    loop(i,0,20){
            int sum=0;

        loop(j,0,5){
            sum+=marks[i][j];
        }
        avgSub[i]=sum;
    }
    cout << "Average marks obtained by every student -> " << endl;
    loop(i,0,20){
        cout<<"Student ["<<i+1<<"] = "<<avgSub[i]<<"\n";
    }

    ////below 50
    cout << " the number of students who have scored below 50 in their average"<<endl;

        loop(i, 0, 20)
    {
        if(avgSub[i]<50){
            cout<<"Student "<<i+1<<endl;
        }
        else{
            continue;
        }
    }

    cout << " scores obtained by every student "<<"\n";
    loop(i,0,20){
        cout<<"Student "<<i+1<<" ";
        loop(j,0,5){
            cout<<marks[i][j]<<" ";
        }
        cout<<"\n";
    }

        return 0;
}