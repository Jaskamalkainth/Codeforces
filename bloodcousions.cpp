/*
 *    J1K7_7
 *
 *    You can use my contents on a Creative Commons - Attribution 4.0 International - CC BY 4.0 License.  XD 
 *    - JASKAMAL KAINTH
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
#include <cassert>
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
#define left(x)		   (x << 1)
#define right(x) 	   (x << 1) + 1
#define mid(l, r) 	   ((l + r) >> 1)
#define mp                 make_pair
#define pb                 push_back
#define all(a)             a.begin(),a.end()
#define debug(x)	   {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y)       {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z)    {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, w) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#w << " = " <<w <<"\n";}
#define ss                 second
#define ff                 first
#define m0(x) 		   memset(x,0,sizeof(x))

inline int nextint(){ int x; scanf("%d",&x);   return x; }
inline ll  nextll() { ll  x; scanf("%lld",&x); return x; }

#define gc getchar
template <typename T> void scanint(T &x) {
	T c = gc(); while(((c < 48) || (c > 57)) && (c!='-')) c = gc();
	bool neg = false; if(c == '-') neg = true; x = 0; for(;c < 48 || c > 57;c=gc());
	for(;c > 47 && c < 58;c=gc())	x = (x*10) + (c - 48); if(neg)	x = -x;
}
// variadics
template<typename T >T min_ ( T a , T b ) { return a > b ? b : a ; }
template < typename T ,  typename... Ts > T min_( T first , Ts... last ){ return  min_(first, min_(last...)); }

// lambda exp auto  square = [](int inp) { return inp * inp; } ;

template<class T, class S> std::ostream& operator<<(std::ostream &os, const std::pair<T, S> &t) {
	os<<"("<<t.first<<", "<<t.second<<")";
	return os;
}
template<typename T> ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "["; size_t last = v.size() - 1; for(size_t i = 0; i < v.size(); ++i) {
    out << v[i]; if (i != last) out << ", "; } out << "]"; return out;
}

ll pwr(ll base, ll p, ll mod){
ll ans = 1; while(p) { if(p&1) ans=(ans*base)%mod; base=(base*base)%mod; p/=2; } return ans;
}
ll gcd(ll a, ll b) {  return b == 0 ? a : gcd(b,a%b); }
ll lcm(ll a, ll b) {  return a*(b/gcd(a,b)); }

const long double PI = (long double)(3.1415926535897932384626433832795);
const ll  mx_ll   = numeric_limits<ll> :: max();
const int mx_int  = numeric_limits<int> :: max();
const int mod = 1e9+7;
const int oo = 0x3f3f3f3f;
const ll  OO = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 1e5+7;
int st[maxn],en[maxn],timer = 1;
vector<int> level[maxn];
const int MAXN = 1e6+7; 
const int MAXLOG = 20; 
int par[MAXN][MAXLOG];
int d[MAXN];
vi G[maxn];
void dfs(int v,int p = -1){
	st[v] = timer++;
    par[v][0] = p;
    if(p + 1)
        d[v] = d[p] + 1;
	level[d[v]].pb(st[v]);
    for(int i = 1;i < MAXLOG;i ++)
        if(par[v][i-1] + 1)
            par[v][i] = par[par[v][i-1]][i-1];
    for(auto u : G[v])
        if(p - u)
            dfs(u,v);
	en[v] = timer-1;
}

int lca(int v,int u){
    if(d[v] < d[u])
        swap(v,u);
    for(int i = MAXLOG - 1;i >= 0;i--)
        if(par[v][i] + 1 and d[par[v][i]] >= d[u])
            v = par[v][i];
    if(v == u)
        return v;
    for(int i = MAXLOG - 1;i >= 0;i--)
        if(par[v][i] - par[u][i])
            v = par[v][i], u = par[u][i];
    return par[v][0];
}
int kth(int u, int k) {
    if(k > d[u])    return -1;
    for(int i = MAXLOG-1; i >= 0; i--) {
        if((1<<i) & k) {
            u = par[u][i];
        }
    }
    return u;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	vi root;
	for(int i = 1; i <= n; ++i)
	{
		int x; cin >> x;
		if(x == 0)
			root.pb(i);
		else
		{
			G[i].pb(x);
			G[x].pb(i);
		}
	}
	for(auto u: root)
	{
		dfs(u);
	}
	int m; cin >> m;
	for(int i = 1; i <= m; ++i)
	{
		int v, p; cin >> v >> p;
		int pv = kth(v,p);
		if(pv == -1)
			cout << 0 << " ";
		else
		{
			auto lr = lower_bound(all(level[d[pv]+p]),st[pv]);
			auto rr = upper_bound(all(level[d[pv]+p]),en[pv]);
			cout << rr-lr-1<< " ";
		}
	}
    return 0;
}

