// :pray: DolGarlic orz orz orz orz orz

//coordinates are dots, not cells

/*
(1, 1) [Origin] = top left
(NAX, NAX)  = bottom right
*/
using namespace std;
#include "bits/stdc++.h"
#define len(x) (int)(x).size()
void IO(string Bessie);

int N, K;
long long Ans{};
const int NAX = 1e3+2;
vector<vector<long long>> barn (NAX, vector<long long> (NAX));//2D Difference Array

void Query(int x1, int y1, int x2, int y2);
void compute();

int32_t main() { IO("paintbarn");//paintbarn

	cin >> N >> K;
	for (int i {}; i < N; ++i) {
		
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		Query(x1+1, y1+1, x2+1, y2+1);
	}

	compute();

	for(int i = 1; i <= 1e3; ++i) Ans += std::count(barn[i].begin(), barn[i].end(), K);
	
	cout << Ans;
	return 0;
}

void Query(int x1, int y1, int x2, int y2) {

	barn [x1] [y1]++; //top left 
	barn [x2] [y2]++; //bottom right 
	barn [x1] [y2]--; //bottom left 
	barn [x2] [y1]--; //top right

}

void compute() {
	for (int i = 1; i <= 1000; ++i) 
		for (int j = 1; j <= 1000; ++j) {
			barn[i][j] += barn [i-1] [j] 
						+ barn [i] [j-1]
						- barn [i-1][j-1]; //| A ∪ B | = | A | + | B | - | A ∩ B |
		}
}

void IO(string Bessie = "") { 
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    if (len(Bessie)) {
        freopen((Bessie+".in").c_str(), "r", stdin);
        freopen((Bessie+".out").c_str(), "w", stdout);
     }
}
/*
Sample test case diagram : https://ibb.co/514Rby8

7/1/2021 m/d/yyyy 
no more korean == britishers :clown:
*/
