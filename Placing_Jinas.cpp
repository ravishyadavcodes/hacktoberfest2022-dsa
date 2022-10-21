#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <cstring>
#include <time.h>
#include <chrono>
#include <random>
#include <ctime>

using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, arr) for (auto it = arr.begin(); it != arr.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int mod = 1e9+7;

long long power(long long n, long long m)
{
    if (m == 0)
        return 1;
    if (m == 1)
        return n;
    if (m % 2 == 1)
        return power(n, m - 1) * n % mod;
    else
    {
        long long temp = power(n, m / 2) % mod;
        return temp * temp % mod;
    }
}

ll nCr(ll n, ll r, vl &fact, vl &ifact) {
    ll temp = (fact[n]*ifact[r])%mod;
    temp = (temp*ifact[n-r])%mod;
    return temp;
}
void solve()
{
    int n;
    cin>>n;
    vi arr(n+1,0);
    for(int i = 0; i<=n; i++) cin>>arr[i];
    vl fact(400001,1);
    vl ifact(400001, 1);
    for(int i = 1; i<=400000; i++) fact[i] = (fact[i-1]*i)%mod;
    ifact[400000] = power(fact[400000], mod-2);
    for(int i = 400000-1; i>=0; i--) ifact[i] = (ifact[i+1]*(i+1))%mod;
    ll ans = 0;
    for(ll i = 0; i<=n; i++) {
        if(arr[i]==0) break;
        ans += (nCr((ll)arr[i]+i,i+1,fact,ifact))%mod;
    }
    cout<<ans%mod<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
