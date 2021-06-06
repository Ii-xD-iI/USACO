using namespace std;
#include "bits/stdc++.h"
#define len(x) (int)(x).size()

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    vector<vector<int>> coords;
    vector<vector<int>> freq(2e3+7, vector<int> (2e3+7));

    for(int a=0,b=0,c=0,d=0,i {}; i <= 2; ++i) {

        cin>>a>>b>>c>>d;

        // cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; 

        if(c < a) swap(a,c);
        if(d < b) swap(d,b);

        coords.push_back({a+1000,b+1000,c+1000,d+1000});
    }

    // for(auto i :coords) {
    //     for(int j {}; j < i.size(); ++j) cout << i[j] << ' ';
    //     cout << '\n';
    // }

    for(int i {}; i < 2; ++i) {
        for(int j= coords[i][0] ; j < coords[i][2]; ++j) {

            for(int k= coords[i][1] ; k < coords[i][3]; ++k) {
                freq[j][k]++;
            }
        }
    }

    for(int i=coords[2][0]; i < coords[2][2]; ++i) {
        for(int j = coords[2][1]; j < coords[2][3]; ++j) {
            freq[i][j] = 6;
        }
    }
    int cnt{};

    for(int i {}; i < len(freq); ++i) {
        for(int j {}; j < len(freq[i]); ++j) {
            // cout << freq[i][j] << ' ';
            if(freq[i][j] != 0 and freq[i][j] != 6) ++cnt;
        }
        // cout << '\n';
    }

    cout << cnt << '\n';
}
