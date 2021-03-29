#include "bits/stdc++.h"

#define len(Z) (int)(Z).size()
#define elif else if
#define all(Z) (Z).begin(), (Z).end()
#define ceil(X,Y) (X + Y-1)/Y
#define test(A) int A;cin>>A;while(A-->0)

using namespace std;

const int MAXN=1e2+7, INF = 2e9+7, MOD = 1e9+7;//check the limits u dum dum
const long long INFLL = 2e18+7;

void IO(string Bessie);

vector<vector<int>> grid(MAXN,vector<int>(MAXN));
vector<vector<bool>> light(MAXN,vector<bool> (MAXN));


void Moo(){
    
    int n;cin>>n;
    
    vector<bool> check(n*2+1);//base 1?

    for(int a,i {};i<n;++i) {
        cin>>a,check[a]=1;
    }
    vector<int> b,f;
    for(int i=1;i<=n*2; ++i) {
        if(check[i]) f.emplace_back(i);
        else b.emplace_back(i);
    }

    sort(all(b));
    sort(all(f));

    int fi=0,bi=0;
    int cnt{};
    
    while(fi<n and bi < n) {
        if(f[fi]> b[bi]) ++bi;

        elif(b[bi] > f[fi]) 
        
            fi++,bi++,cnt++;
    
    }

    cout << cnt << '\n';
}

int32_t main() {
    IO("highcard");//highcard
        
    // test(Dolphin_OTZ)
        Moo();
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
