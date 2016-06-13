/*
 *    J1K7_7
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <list>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <limits>
using namespace std;
typedef long long          ll;
typedef unsigned long long ull;
typedef long double        ld;
typedef pair<int,int>      pii;
typedef pair<ll,ll>        pll;
typedef vector<int>        vi;
typedef vector<long long>  vll;
#define l(x) 		       (x << 1) + 1
#define r(x) 		       (x << 1) + 2
#define mid(l, r) 	       ((l + r) >> 1)
#define mp                 make_pair
#define pb                 push_back
#define all(a)             a.begin(),a.end()
#define debug(x)	       {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y)       {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define ss                 second
#define ff                 first
#define m0(x) 		       memset(x,0,sizeof(x))
#define snuke(c,itr)       for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

template<class T>
inline bool ispow2(T x){return (x!=0 && (x&(x-1))==0);} //0 or 1

template<class T> inline T powmod(T a,T b,T mod) {ll res = 1; while(b){if(b&1) res = (res*a)%mod;a = (a*a)%mod;b >>= 1;}return res;}
template<class T> inline T gcd(T a,T b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
template<class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}

inline int nextint(){ int x; scanf("%d",&x); return x; }
inline ll nextll(){ ll x; scanf("%lld",&x); return x; }

const int mod=1e9+7;

const ll  mx_ll   = numeric_limits<ll> :: max();
const int mx_int  = numeric_limits<int> :: max();

const long double PI = (long double)(3.1415926535897932384626433832795);

const int maxN = 2e5+6;
ll a[maxN];
ll cnt1[maxN];
ll cnt2[maxN];
struct query
{
	ll lo , hi , val;  
}qq[maxN];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	ll n , m , k; cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
	{
		cin >> qq[i].lo >> qq[i].hi >> qq[i].val;
	}
	for(int i = 1; i <= k; i++)
	{
		int a , b; cin >> a >> b;
		cnt1[a]++;
		cnt1[b+1]--;
	}
	for(int i = 1; i <= m; i++)
		cnt1[i] += cnt1[i-1];

	for(int i = 1; i <= m; i++)
	{
		ll val = qq[i].val * 1ll* cnt1[i];
		cnt2[qq[i].lo] += val;
		cnt2[qq[i].hi+1] -= val;
	}
	for(int i = 1; i <= n; i++)
		cnt2[i] += cnt2[i-1];
	for(int i = 1; i <= n; i++)
	{
		cout << a[i]+cnt2[i] << " " ;
	}
    return 0;
}

