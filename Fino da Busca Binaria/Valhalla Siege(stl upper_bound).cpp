#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
int n, q;
ll a[N], k[N], acc[N];

int main() {
    ios_base::sync_with_stdio(false);
    
    cin >> n >> q;
    
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    for(int i = 0; i < q; i++)
        cin >> k[i];
        
    acc[0] = a[0];
    for(int i = 1; i < n; i++)
        acc[i] = acc[i-1] + a[i];
        
    ll flechas = 0;
    
    for(int i = 0; i < q; i++) {
        flechas += k[i];
        
        if(flechas >= acc[n-1]) {
            cout << n << endl;
            flechas = 0;
        } else {
            // indice do maior valor menor ou igual a flechas
            // indice do menor valor maior a flechas - 1
            int id = upper_bound(acc, acc+n, flechas) - acc - 1;
            
            cout << n - id - 1 << endl;
        }
    }
        
        
    return 0;
}
