#include "bits/stdc++.h"
#define len(X) (int)(X).size()
#define int long long
using namespace std;
const int MAXN = 1e5+7,INF = 2e9+1;
void IO(string Bessie);
int32_t main() {
    IO("maxcross");//

    int n,k,q;
    cin>>n>>k>>q;
    vector<int> v(MAXN);//based 1 indexing
    v[0] = 0;
    while(q--) {
        int a;cin>>a;
        v[a]=1;
    }

    for(int i=1;i<=n;++i) {
        v[i] += v[i-1];
    }
    // for(int i {};i<=n;++i) {
        // cout << v[i] << ' ';
    // }
    int ans=INF;
    for(int i=k;i<=n;++i) {
        int a = abs(v[i] - v[i - k]);
        ans = min(ans, a);
    }
    cout << ans << '\n';
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
0  1  2  2  2  3  3  3  3  4  5 

1/16/2020 m/dd/yyyy
*/
