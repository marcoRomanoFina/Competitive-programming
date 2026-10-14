#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void solve() {
    
    long long A, N, RES = 0; cin >> N;
    vector<ll> love;
    unordered_map<ll,ll> cant_love;
    for(int i = 0; i < N; i++){
        cin >> A;
        love.push_back(A);
    }
    for(int x = 0; x < N - 4; x++){ // calculo cuantas chords por love
        ll love_chord = love[x] + love[x+2] - love[x+4];
        cant_love[love_chord]++;
    }
    for(auto& [key,value] : cant_love){ // calculo todos los pares
        RES += (value*(value-1))/2;
    }

    for(int x = 0; x < N - 4; x++){ // resto los que no van
        ll love_chord = love[x] + love[x+2] - love[x+4];
        if(x + 6 < N){
            ll love_second_chord = love[x+2] + love[x+4] - love[x+6];
            if(love_second_chord == love_chord){
                RES--;
            } 
        }
        if(x + 8 < N){
             ll love_third_chord = love[x+4] + love[x+6] - love[x+8];
            if(love_third_chord == love_chord){
                RES--;
            } 

        }
    }

    cout << RES << "\n";
}

// 3 pasadas de O(N) queda complejidad lineal, la clave fue usar el unordered map,
// y guardar no las chords sino cuantas tienen el mismo love, y desp solo chequear
// cuantas comparten love y chords y restarlas

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
