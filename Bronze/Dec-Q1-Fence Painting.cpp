#include "bits/stdc++.h"
 
using namespace std;

#define all(X)   (X).begin(), (X).end()
#define test     int t;cin>>t;while(t--)
#define len(X)   (int)(X).size()
#define elif     else if
#define bignum   1e9+1
#define Int      long long
#define MAXN     1e4+1
//----------------Prototypes------------------
void IO(string Bessie);

//-----------------Globals--------------------

//-------------------x-x----------------------

int32_t main(){
    IO("paint");//

    long long x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    cout << ( y1>x2 and x1<y2? ( max(y2,y1) - min(x2,x1) ) : ((y1-x1) + (y2-x2)) ) << '\n';//true 
    return 0;
}

void IO(string Bessie = "") {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);
    if (len(Bessie)) {
        freopen((Bessie+".in").c_str(), "r", stdin);
        freopen((Bessie+".out").c_str(), "w", stdout);
     }
}
/*
What if 1st seg is not intersecting and 2nd seg < 1st seg  
*/
