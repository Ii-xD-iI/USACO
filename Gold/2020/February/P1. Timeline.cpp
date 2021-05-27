using namespace std;
#include "bits/stdc++.h"
#define len(DolphinOrz) (int)(DolphinOrz).size()
#define elif else if
#define all(Z) (Z).begin(), (Z).end()
#define ceil(X,Y) (X + Y-1)/Y
void IO(string Bessie);

int N,M,C, NAX = 1e6+5;;

vector<vector<pair<int, int>>> Adj(NAX);
vector<int> InDegree(NAX), Ans(NAX), S(NAX);

int32_t main() {
    IO("timeline");
        
    cin>>N>>M>>C;
    for(int i {};i<N;++i) cin>>S[i+1];

    for(int a,b,c,i {};i<C; ++i) {
        cin>>a>>b>>c;
        Adj[a].push_back({b,c});
        ++InDegree[b];
    }

    queue<int> Topo;
    for(int i=1; i<=N; ++i) if(not InDegree[i]) Topo.push(i);

    while(not Topo.empty()) {
        int Curr = Topo.front();
        Topo.pop();
        for(auto child: Adj[Curr]) {
            int next = child.first , cost = child.second;
            S[next] = max(S[Curr] + cost , S[next]);

            --InDegree[next];
            if(not InDegree[next]) Topo.push(next);
        }
    }

    for(int i=1; i<=N; ++i) cout << S[i] << '\n';

    return 0;

}

void IO(string Bessie = "") {   
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if (len(Bessie)) {
        freopen((Bessie+".in").c_str(), "r", stdin);
        freopen((Bessie+".out").c_str(), "w", stdout);
    } 
}
// 05/27/2021 mm/dd/yyyy
