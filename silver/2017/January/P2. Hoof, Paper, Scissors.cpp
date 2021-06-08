using namespace std;
#include "bits/stdc++.h"
#define elif else if
#define all(Z) (Z).begin(), (Z).end()
#define len(x) (int)(x).size()
#define ceil(x,y) (x + y-1)/y
void IO(string Bessie);

int32_t main() {
    IO("hps");//
    int n;cin>>n;

    vector<vector<int>> prefval(n+7, vector<int> (3)), suffval(n+7, vector<int> (3));// Hoof, ppr, sissor;

    map<char,int> indx{{'H', 0}, {'P', 1}, {'S', 2}};
    
    for(int i=1; i <= n; ++i) {
        char c;cin>>c;
        prefval[i][indx[c]]++;
        suffval[i][indx[c]]++;
    }


    for(int i=1; i <=n; ++i) {
        for(int j{}; j < 3; ++j) {
            prefval[i][j] += prefval[i-1][j];
        }
    }

    for(int i=n-1; i >= 0; --i) {
        for(int j {}; j < 3; ++j) {
            suffval[i][j] += suffval[i+1][j]; 
        }
    }

    // for(int i {}; i <= n; ++i) 
    //     for(int j {}; j < 3; ++j) 
    //         cout << prefval[i][j] << " \n"[j == 2];
        
    // cout << '\n';
    
    // for (int i {}; i <= n; ++i) 
    //     for(int j {}; j < 3; ++j) 
    //         cout << suffval[i][j] << " \n"[j == 2];

    int mx{};
    
    for(int i = 1; i <= n; ++i) {
        
        vector<int> pref = prefval[i], suff = suffval[i];
        
        int mxi {};

        for(int j {}; j < 3; ++j) {
            for(int k {}; k < 3; ++k) {
                if(j==k) continue;

                mxi = max(mxi, pref[j] + suff[k]);
            }
        }

        mx = max(mx, mxi);
    }
    
    cout << mx;
    
    cerr << "\nTime Elapsed: [" << 1e3*clock()/CLOCKS_PER_SEC << " ms]\n";
}

void IO(string Bessie = "") { 
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    if (len(Bessie)) {
        freopen((Bessie+".in").c_str(), "r", stdin);
        freopen((Bessie+".out").c_str(), "w", stdout);
     }
}
// taskkill /IM "A.exe" /F
