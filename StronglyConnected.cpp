#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

const int mod = 1000000007;

long long pot[1100000];
long long ch[1100][1100];
long long s[1100];
long long nn[1100];

// a*x + b*y = gcd(a,b)
int extGcd(int  a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    
    int g = extGcd(b,a % b,y,x);
    y -= a / b * x;
    return g;
}

// ASSUME: gcd(a, m) == 1
int modInv(int a){
    int x,y;
    extGcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}

int main() {
    pot[0] = 1;
    for (int i = 1; i <= 1100000; i++) {
        pot[i] = (pot[i-1] * 2) % mod;
    }

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) ch[i][j] = 1;
            else ch[i][j] = (ch[i-1][j-1] + ch[i-1][j]) % mod;
        }
    }

    nn[0] = 1;
    for (int n = 1; n <= 1000; n++) {
        for (int i = 1; i <= n; i++) {
            long long th = (ch[n][i] * pot[i * (n-1)]) % mod;
            nn[n] -= th * nn[n-i];
            nn[n] = ((nn[n] % mod) + mod) % mod;
        }

        long long nnn = nn[n];
        for (int i = 1; i < n; i++) {
            long long th = (ch[n-1][i-1] * s[i]) % mod; 
            th = (th * nn[n-i]) % mod;
            nnn = (nnn + th) % mod;
        }


        s[n] = mod-nnn;
        //printf("%lld\n", s[n]);
    }

    int t, n;
    for (scanf("%d", &t); t; t--) {
        scanf("%d", &n);
        printf("%lld\n", s[n]);
    }
}
