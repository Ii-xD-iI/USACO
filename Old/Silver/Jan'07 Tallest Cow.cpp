/*Credit : Provoke#7150

There are some crucial observations to solve this problem. 

First, is it possible to have intervals such as: [1 6] and [4,7]? Cows 2 to 5 are shorter than 1 and 6, and cows 5, 6 are shorter than 4,7. That is inconsistent. So the intervals cannot intersect partially but only can be contained completely.
As the second observation, consider the following input with H = 6:

       1 2 3 4 5 6 7 8  intervals
       |-------------|  [1 8]
         |---| |-----|  [2 4] [5 8]
               |---|    [5 7]

Heights: 6 5 4 5 5 3 4 6
Check the correlation between the number of intervals a cow is contained in (endpoints are not included in the interval). For instance, cow 5 is in 1 interval [1,8] and its height is 5. Cow 6 is contained in 3 intervals [1,8],[5,8] and [5,7] and its height is 3.
Then the question becomes much easier. You can solve this problem with N cows, R intervals in O(NR) time technically which is a little bit slow. We can use the idea of prefix sum on an inverse index of cows from 1 to N. Another idea is to sort the intervals and not look to all intervals for each cow. 
However we can have duplicates of an interval in the input; you need to get rid of them. You can solve it with the complexity of O(R log R + N)
*/

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
// #include <array>
using namespace std;
#define elif else if
#define int long long
#define ceil(X,Y) (x + y-1)/y
#define len(X) (int) (X).size()
#define all(x) (x).begin(),(x).end()

const int NAX = 1e4+1;

signed main() { //cin.tie(nullptr)->sync_with_stdio(false);

    //a-b
    //a <= b
    int N, I, H, R;
    cin >> N >> I >> H >> R;

    vector<int> v(NAX);
	  set<pair<int,int> > dups;// > > instead of >> [cuz they are using old version of C++]

    for(int i {}; i < R; ++i) {
        int a, b; cin >> a >> b;
		  if(a > b) swap(a, b);

		  if(dups.count({a,b})) continue;

       dups.insert({a, b});
       v[a+1]--, v[b]++;
    }

    for(int i = 1; i < NAX; ++i) v[i] += v[i-1];
    for(int i = 1; i <= N; ++i) cout << v[i] + H << '\n';
    return 0;
}
