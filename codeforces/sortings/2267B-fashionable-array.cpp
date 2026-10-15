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
int N, A; cin >> N;
vector<int> FREQ(101,0);
vector<int> RES;
for(int i = 0; i < N; i++){
    cin >> A;
    FREQ[A]++;
}
while(RES.size() < N){ // como n <= 100 y cada numero es <= 100, estan acotados y podemos usar un vector de frecuencias
    for(int i = 100; i >= 1; i--){ // la idea es primero poner el maximo solo con los demas numeros sin repetir, y asi con el maximo en cada iteracion
        if(FREQ[i] > 0){
            RES.push_back(i);
            FREQ[i]--; // cada paso si usamos uno lo restamos
        }
    }
}

for(int i = 0; i < N; i++){
    cout << RES[i] << " ";
}
cout << "\n";   // complejidad total: O(N) (tecnicamente N <= 100 es acotado por una constante pero bueni)
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
