#include <iostream>

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
            int bot = 0, top = n-1;
            int ans = -1;
            
            // indice do maior valor menor ou igual a flechas
            while(bot <= top) {
                int mid = (bot + top)>>1;
                
                if(acc[mid] <= flechas) {
                    ans = mid;
                    bot = mid+1;
                } else {
                    top = mid-1;
                }
            }
            
            cout << n - ans - 1 << endl;
        }
    }
        
        
    return 0;
}
