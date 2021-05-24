using namespace std;
#include "bits/stdc++.h"
#define len(X) (X).size()
#define int long long

void IO(string Bessie);

int32_t main() {
	IO("moobuzz");

	int n,k=0, r=4e18,l = 0;
	cin>>n;
	
	while(l!=r) {
		
		int mid = ((l+r)>>1);
		
		k = mid-(mid/3+mid/5)+mid/15;

		if(k < n) l=mid+1;
		else r=mid;
	}
	cout << r; 
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
