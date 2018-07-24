#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int n;
double p, a[N], b[N];

// true: se da p deixar ligado
// false: se n da
bool magic(double time) {
    double precisa = 0.0;
    double tem = p * time;
    
    for(int i = 0; i < n; i++) 
        precisa += max(0.0, a[i]*time - b[i]);
    
    return tem >= precisa;
}

int main() {
    double sum = 0.0;
    scanf("%d %lf", &n, &p);
    for(int i = 0; i < n; i++) {
        scanf("%lf %lf", a+i, b+i);
        sum += a[i];
    }

        
    if(p >= sum) {
        printf("-1\n");
        return 0;
    }
        
    double bot = 0, top = 1e10 + 100;
    int t = 200;
    while(t--) {
        double mid = (bot + top)/2.0;
        
        if(magic(mid)) {
            bot = mid;
        } else {
            top = mid;
        }
    }
    
    printf("%.14lf\n", bot);
    
    return 0;
}
