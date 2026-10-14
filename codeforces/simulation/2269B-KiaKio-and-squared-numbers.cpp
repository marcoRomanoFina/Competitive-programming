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

int N; cin >> N;
vector<int> lighthouses;
for(int i = 0; i < N; i++){
    int A; cin >> A;
    lighthouses.push_back(A);
}
for(int i = 0; i < 850; i++){ // la simulación, 810 es la maxima cantidad de estados O(k = 850*1000) === O(N)
    for(int j = 0; j < N; j++){ // en cada paso actualizamos el numero de cada lighthouse
        int tmp = 0;
        int lighthouse = lighthouses[j];
        while (lighthouse > 0) {
            int digit = lighthouse % 10;
                tmp += digit*digit;
                lighthouse /= 10;
        }
        lighthouses[j] = tmp;
    }
}
    // una vez terminadad la simulacón, podemos chequear en tiempo lineal
    int RES = 0;
    unordered_map<int,int> results;
    for(int k = 0; k < N; k++){
        results[lighthouses[k]]++;
    }
    for(auto& [key,value] : results){
        RES += (value*(value - 1))/2;
    }
    cout << RES << "\n";
    
}

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
