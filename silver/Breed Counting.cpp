#include "bits/stdc++.h"
 
#define all(x)   (x).begin(), (x).end()
#define test     int t;cin>>t;while(t--)
//---------------------------------
#define len(x)   (int)(x).size()
#define elif     else if
//---------------------------------
using namespace std;

class Prefcow {
	public:
		int a{};
		int b{};
		int c{};	
};

void IO(string Bessie);

int main(){
	IO("bcount");

	int n,q;cin>>n>>q;
	
	vector<int> cow(n);
	for(int i {};i<n;++i) cin>>cow[i];

	vector<pair<int,int>> query(q);
	
	for(int i {};i<q;++i) {
		int x,y;cin>>x>>y;
		x--;y--;
		query[i].first = x;
		query[i].second = y;
	}

	vector<Prefcow> sum(n);

	if((cow[0] == 3)) {
		sum.at(0).c++;
	}
	
	elif((cow[0]==1)) {
		sum.at(0).a++;
	}
	
	else {
		sum.at(0).b++;
	}
	
	for(int i=1;i<n;++i) {
		if (cow[i] == 3) {sum[i] = sum[i-1]; sum[i].c++;}
		elif ((cow[i]==2)) {sum[i] = sum[i-1]; sum[i].b++;}//2
		else {sum[i] = sum[i-1]; sum[i].a++;}//1		
	}

	for(int i {};i<q;++i) {
		if(query[i].first == 0) {
			cout << sum[query[i].second].a << " ";
			cout << sum[query[i].second].b << " ";
			cout << sum[query[i].second].c << '\n';
		}

		else { 
			cout << abs( sum[query[i].second].a  - sum[query[i].first -1].a) << " "; 
			cout <<  abs( sum[query[i].second].b  - sum[query[i].first -1].b) << " ";
			cout << abs( sum[query[i].second].c  - sum[query[i].first -1].c)<< '\n';
		}
	}

	return 0;
}

void IO(string Bessie = "") { 
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    if (len(Bessie)) {
        freopen((Bessie+".in").c_str(), "r", stdin);
        freopen((Bessie+".out").c_str(), "w", stdout);
    }
}

/*
11/23/2020 
zio :;
*/
