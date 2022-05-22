#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> fig(n);
    for(int i = 0; i < n; i++){
        cin >> fig[i];
    }
    /*
        1 inside 2: 3
        1 inside 3: 4

        2 inside 1: 3
        2 inside 3: infinite

        3 inside 1: 4
        3 inside 2: infinite

        pay attention to 2 inside 1 inside 3
    */
    //Check first figure
    int ans = 0;
    if(fig[1] + fig[0] == 5){
        cout << "Infinite\n";
        return 0;
    }
    else{
        ans += fig[1] + fig[0];
    }
    for(int i = 2; i < n; i++){
        if(fig[i] + fig[i - 1] == 5){
            cout << "Infinite\n";
            return 0;
        }
        if(fig[i] == 2 and fig[i - 1] == 1 and fig[i - 2] == 3) ans += 2;
        else ans += fig[i] + fig[i - 1];
    }
    cout << "Finite\n" << ans << "\n";
    return 0;
}