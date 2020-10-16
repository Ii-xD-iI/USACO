#include "bits/stdc++.h"
 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define elif else if
#define test int t;cin>>t;while(t--)
#define sz(x) (int)(x).size()

using namespace std;

int main(){	
    freopen("haybales.in", "r", stdin); freopen("haybales.out", "w", stdout);

	int n,q;cin>>n>>q;
	vector<int> v(n);
	for(int i {};i<n;i++)cin>>v[i];
	sort(all(v));
	while(q--){
		int a,b;cin>>a>>b;
		cout << upper_bound(all(v),b) - lower_bound(all(v),a) << '\n';
	}
    return 0;
}

//taskkill /IM "main.exe" /F
/*
10/16/2020 mm/dd/yyyy
*/
