#include "bits/stdc++.h"
 
using namespace std;

#define all(x)   (x).begin(), (x).end()
#define test     int t;cin>>t;while(t--)
// #define IO(NAME) ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0); if(fopen(NAME ".in", "r")) freopen(NAME ".in", "r", stdin),freopen(NAME ".in", "w", stdout); 
#define len(x)   (int)(x).size()
#define elif     else if
#define bignum   1e9+1

//----------------Prototypes------------------
void IO(string Bessie);
void dfs(int& A);
//-----------------Globals--------------------
map<int,vector<int>> adj;
vector<int> vis(2e2+7);
//-------------------x-x----------------------

class Node {
	public:
		int x{};
		int y{};
		int p{};	
};

int main(){
	IO("moocast");//moocast
	
	int N;cin>>N;
	vector<Node> V(N);
	for(int i {};i<N;++i) {
		cin>>V[i].x >> V[i].y >> V[i].p;
	}

	for(int i {};i<N;++i) {
		for(int j{};j<N;++j) {
			if(i==j) continue;
			elif( sqrt( pow( abs(V[i].x - V[j].x ),2 ) + pow( abs(V[i].y - V[j].y),2) ) <= V[i].p ){
				adj[i].push_back(j);
			}
		}
	}
	int maxcnt=0;

	for(int i {};i<N;++i) {
		int cnt{};
		dfs(i);
		for(int j {};j<N;++j) {
			if(vis[j]==1) ++cnt;
		}
		// cout << cnt << '\n';
		maxcnt = max(maxcnt, cnt);

		fill(all(vis), 0);
	}
	cout << maxcnt << '\n';
	return 0;
}

void dfs(int& A) {
	vis[A] = 1;
	for(auto Node: adj[A]){
		if(!vis[Node])	dfs(Node);
	} 
}

void IO(string Bessie = "") { 
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    if (len(Bessie)) {
        freopen((Bessie+".in").c_str(), "r", stdin);
        freopen((Bessie+".out").c_str(), "w", stdout);
     }
}
//sqrt( pow( abs(V[i].x - V[j].x ),2 ) + pow( abs(V[i].y - V[j].y),2) ) <= (V[i].p+V[j].p)
