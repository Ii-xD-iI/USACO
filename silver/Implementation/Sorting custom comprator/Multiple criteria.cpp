#include "bits/stdc++.h"
 
using namespace std;

#define all(X)   (X).begin(), (X).end()
#define test     int t;cin>>t;while(t--)
#define len(X)   (int)(X).size()
#define elif     else if
#define bignum   1e9+1
#define Int      long long
#define MAXN     1e9
//----------------Prototypes------------------
void IO(string Bessie);

//-----------------Globals--------------------

//-------------------x-x----------------------

struct Person {
    int Height{};
    int weight{};
};

bool CustomComparator(Person& a , Person& b) {
    if(a.Height == b.Height)//if primary comparators are equal
        return a.weight < b.weight;//sort using the secondary factor (weight).

    return a.Height < b.Height; // sorts array in assending order
    //a = ith element , b > ith element (position)
    //
}

int32_t main(){
    IO("");//haybales

    int NumberOfElements{};
    cin>>NumberOfElements;
    vector<Person> array(NumberOfElements);
    for(int Element {};Element<NumberOfElements;++Element)  {
        cin>>array[Element];
    }  
    sort(all(array) , CustomComparator);
    for(auto Element: array) cout << Element << ' ';
    cout << '\n';
    return 0;
}

void IO(string Bessie = "") {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);
    if (len(Bessie)) {
        freopen((Bessie+".in").c_str(), "r", stdin);
        freopen((Bessie+".out").c_str(), "w", stdout);
     }
}
