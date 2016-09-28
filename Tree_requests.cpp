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

const int maxn = 5e5+7;
vi G[maxn];

int st[maxn],en[maxn],timer = 0;
int d[maxn];
vector<pair<int,ll> > depth[maxn];
string s;
int n , m; 
inline ll p2(int x)
{
	return 1 << x;  
}
inline void dfs(int u , int p)
{
	if(p+1)
		d[u] = d[p] + 1;
	else
		d[u] = 1;
	st[u] = ++timer;  
	auto temp = depth[d[u]].back();
	pair<int,ll> tpar = {st[u],temp.ss^p2(s[u-1]-'a')};
	depth[d[u]].pb(tpar);
	for(auto &v: G[u])
		if(v != p)
			dfs(v,u);
	en[u] = timer;
}

int main()
{
	scanint(n);
	scanint(m);
	for(int i = 2;i <= n; i++)
	{
		int x; 
		scanint(x);
		G[i].emplace_back(x);
		G[x].emplace_back(i);
	}
	cin >> s;
	for(int i = 1; i <= n; i++)
		depth[i].pb({0,0});
	dfs(1,-1);
	for(int i = 1; i <= m; i++)
	{
		int v, h;
		scanint(v);
		scanint(h);
		int cnt = 0;
		int itl = lower_bound(all(depth[h]),mp(st[v],-1ll)) - depth[h].begin();
		int itr = upper_bound(all(depth[h]),mp(en[v],-1ll)) - depth[h].begin();
		if(depth[h][itr].ff != en[v])
			itr--;
		ll val = depth[h][itl-1].ss ^ depth[h][itr].ss;
		if(!val || (val&(val-1))==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

