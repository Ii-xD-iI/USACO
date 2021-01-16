#include "bits/stdc++.h"
#define len(X) (int)(X).size()
using namespace std;
const int MAXN = 1e5+1,INF = 2e9+1;

struct Extreme {
    int Maxx=-INF,Maxy=-INF;
    int Minx=INF,Miny=INF;
};

void IO(string Bessie);
void solve();
void dfs(int& A);

int n,m;
vector<pair<int,int>> v(MAXN);
map<int,vector<int>> adj;
vector<bool> visited(MAXN);
Extreme initial;
long long perimeter=INF;

int main(){
    IO("fenceplan");

    cin>>n>>m;
    for(int i {};i<n;++i) cin>>v[i].first >> v[i].second;//already 0 based  
    for(int i=0,a,b;i<m;++i) {
        cin>>a>>b,--a,--b;
        adj[a].push_back(b),adj[b].push_back(a);
    }    

    solve();
    return 0; 
}

void solve() {
    for(int i {};i<n;++i) {
        if(not visited[i]) {
            dfs(i);
            if(( (initial.Maxx-initial.Minx) + (initial.Maxy - initial.Miny) )*2  < perimeter) {
                perimeter = ( (initial.Maxx-initial.Minx) + (initial.Maxy - initial.Miny) )*2;
                /*Reset stuff*/
            }
            initial.Maxx=-INF,initial.Maxy=-INF;
            initial.Minx=INF,initial.Miny=INF;
        }

    }
    cout << perimeter << '\n';
}
void dfs(int& A) {
    initial.Maxx = max(initial.Maxx, v[A].first);
    initial.Minx = min(initial.Minx, v[A].first);
    initial.Maxy = max(initial.Maxy, v[A].second);
    initial.Miny = min(initial.Miny, v[A].second);

    visited[A] = true;
    for(auto& i:adj[A]) {
        if(not visited[i]) dfs(i);
    }
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

//(((best.maxY-best.minY) + (best.maxX - best.minX))*2 ) < (((initial.maxY-initial.minY) + (initial.maxX - initial.minX))*2)

/*
1/16/2020 m/dd/yyyy
4:5 pm
*/
