#include "bits/stdc++.h"
 
#define all(x)   (x).begin(), (x).end()
#define test     int t;cin>>t;while(t--)
// #define IO(NAME) ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0); if(fopen(NAME ".in", "r")) freopen(NAME ".in", "r", stdin),freopen(NAME ".in", "w", stdout); 
//---------------------------------
#define len(x)   (int)(x).size()
#define elif     else if
#define bignum   1e9+1
//---------------------------------
using namespace std;

void IO(string Bessie);

int N,M;
vector<vector<int>> adj(3e3+1);
vector<int> query(3e3+1),burrr(3e3+1), visited(3e3+1);

void dfs(int& A);

int main(){
	IO("closing");//
	
	cin>>N>>M;
	for(int i {};i<M;++i) {
		int a,b;cin>>a>>b;
		a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i{};i<N;++i) {
		int asdfghjkl{};
		cin>>asdfghjkl;
		asdfghjkl--;
		query[i]=asdfghjkl;
	}
	for(int I{};I<N;++I) {
		if(not (I==0)) {
			burrr[query[I-1]] = -1;
		}

		for(int i {};i<N;++i) {
			if(burrr[i]!=-1) {dfs(i);break;}
		}
		// dfs(I);//Hmmmmm

		int connected{};
		for(int J{};J<N;++J) {
			if(visited[J]==1 or burrr[J] == -1) ++connected;
		}
		cout << (connected == N? "YES\n" : "NO\n");
		fill(all(visited), 0);
	}	
	return 0;
}

void dfs(int& A) {
	if( visited[A]==0 ) visited[A] = 1;	
	for(auto& J : adj[A]) {
		if(burrr[J]!=-1 and visited[J] ==0) dfs(J);
	}
}

void IO(string Bessie = "") { 
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    if (len(Bessie)) {
        freopen((Bessie+".in").c_str(), "r", stdin);
        freopen((Bessie+".out").c_str(), "w", stdout);
     }
}
