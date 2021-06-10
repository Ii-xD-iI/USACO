using namespace std;
#include "bits/stdc++.h"
#define elif else if
#define all(Z) (Z).begin(), (Z).end()
#define len(x) (int)(x).size()
#define ceil(x,y) (x + y-1)/y
void IO(string Bessie);

struct point{ int x=0, y{}; };

const int NAX = 502; 
int N,M, pointCnt{};
vector<int> dx{1,-1,0,0}, dy {0,0,-1,1};
vector<vector<int>> v(NAX, vector<int> (NAX)), way(NAX, vector<int> (NAX)), visited(NAX, vector<int> (NAX));
point initiate;

bool FfBfs(int Val){

    for(auto &i :visited) {
        fill(all(i), 0);
    }

    queue<pair<int,int>> Flood;
    Flood.push({initiate.x, initiate.y});
    visited[Flood.front().first][Flood.front().second] = 1;

    while(not Flood.empty()) {
        // int X = Flood.front().first;
        // int Y = Flood.front().second;
        auto Curr = Flood.front();
        Flood.pop();

        for(int i {}; i < 4; ++i) {
            
            int X = Curr.first+ dx[i], Y = Curr.second + dy[i];

            if(X < 1 or X > N or Y < 1 or Y > M or visited[X][Y] or (abs ( v[Curr.first][Curr.second] - v[X][Y] ) > Val) ) continue;

            visited[X][Y] = 1;
            Flood.push({X,Y});
        }

    }
    bool ye = true;
    for(int i = 1; i <= N; ++i) {
        for(int j=1; j <= M; ++j) {
            if(way[i][j] and visited[i][j]==0) ye = false;
        }
    }
    return ye;
}

int32_t main() {
    IO("ccski");//

    cin>>N>>M;

    for(int i=1; i <= N; ++i) {
        for(int j=1; j <= M; ++j) {
            cin>>v[i][j];
        }
    }

    for(int i=1; i <= N; ++i)
        for(int j=1; j <= M; ++j) {
            cin>>way[i][j];
            if(way[i][j]) 
                initiate.x = i, initiate.y = j;
            
        }
    
    int Dlow = 0, Dhigh = 1e9;//min(a_i, a_j) == 0 && ,max(a_i, a_j) == 1e9; abs(0, 1e9) = 1e9 MAX D

    while( Dhigh != Dlow) {//11111_1_000
        int mid = ((Dhigh + Dlow)>>1);

        if(FfBfs(mid)) Dhigh = mid;
        else Dlow = mid+1;

    }
    cout << min(Dhigh, Dlow);

    cerr << "\nTime Elapsed: [" << 1e3*clock()/CLOCKS_PER_SEC << " ms]\n";
}

void IO(string Bessie = "") { 
    cin.tie(nullptr)->sync_with_stdio(false); 
    if (len(Bessie)) {
        freopen((Bessie+".in").c_str(), "r", stdin);
        freopen((Bessie+".out").c_str(), "w", stdout);
     }
}
// taskkill /IM "A.exe" /F
/*
6/11/2021
02:07am
*/
