using namespace std;
#include "bits/stdc++.h"
#define len(DolphinOrz) (int)(DolphinOrz).size()
#define elif else if
#define all(Z) (Z).begin(), (Z).end()
#define ceil(X,Y) (X + Y-1)/Y
#define ll long long
void IO(string Bessie);

int32_t main() {
    IO("div7");
    ll n;cin>>n;

    vector<ll> v(n+2);
    for(int i=1; i<=n; ++i) {cin>>v[i]; v[i] += v[i-1];}
    for(int i=1; i<=n; ++i) {
        v[i] %= 7;
    }
    
    vector<pair<int, int>> k(8,{-1,-1});//start,end

    for(int i=1; i<= n; ++i) {
        if(k[v[i]].first == -1) k[v[i]].first = i, k[v[i]].second = i;
        else k[v[i]].second = i;
    }   

    ll ans{};

    for(auto i :k) {
        ans = max(ans, (ll)(i.second - i.first));
    }
    cout << ans;
    cerr << "\nTime Elapsed: " << 1000*clock()/CLOCKS_PER_SEC << " ms\n";
}

// int32_t main() {
//     IO("div7");


//     ll n;cin>>n;
//     vector<ll> v(n+2);

//     for(int i=1; i<=n; ++i) cin>>v[i];
    
//     for(int i=1; i<=n+1; ++i) {
//         v[i] += v[i-1];
//     }

//     for(int K=n; K>=0; --K) {

//         int l=0, r = K;
//         // cout << K << ": " << l << ' ' << r << '\n';
//         while(r != n+1) {
//             if(l == 0 and r == 0) {++l,++r;continue;}
//             if((v[r] - v[l])%7 == 0) {
//                 // cout << l << '-' << r << ", ";
//                 cout << (r-l) << '\n';

//                 return 0;
//             }
//             ++l,++r;
//         }
//         // cout << '\n';
//     }
//     cout << 0 << '\n';
//     cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
// }

void IO(string Bessie = "") {   
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if (len(Bessie)) {
        freopen((Bessie+".in").c_str(), "r", stdin);
        freopen((Bessie+".out").c_str(), "w", stdout);
    } 
}
// taskkill /IM "A.exe" /F
/*
5/29/2021
*/
