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
#define eb                 emplace_back
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
int inp[maxn];
vi G[maxn];
int st[maxn],en[maxn],flat[maxn],timer = 0;
int A[maxn];
inline void edfs(int u, int p)
{
	st[u] = ++timer;
	flat[timer] = u;
	for(auto &v: G[u])
		if(v != p)
			edfs(v,u);
	en[u] = timer;
}
const int BLOCK = 340;
struct query
{
	int l , r, idx;
	query()
	{
		l = r = idx = 0;  
	}
	query(int _l, int _r, int _idx)
	{
		l = _l , r = _r , idx = _idx;  
	}
	bool operator < ( const query &b) const
	{
		if((l/BLOCK) == (b.l/BLOCK))
		{
			return r < b.r;  
		}
		return l < b.l;
	}
}Q[maxn];	
int n; 
ll ans[maxn],sum[maxn], freq[maxn];

ll curr_max = 0;
inline void add(int id)
{
	int color = A[id];
	sum[freq[color]] -= color;
	freq[color]++;
	sum[freq[color]] += color;
	curr_max = max((ll)curr_max,freq[color]);
}
inline void remove(int id)
{
	int color = A[id];
	sum[freq[color]] -= color;
	freq[color]--;
	sum[freq[color]] += color;
	if(sum[curr_max] == 0)
		curr_max--;
}


int curr_l = 1 , curr_r = 0;
inline void solve()
{
	sort(Q+1,Q+n+1);
	for(int i = 1; i <= n; i++)
	{
		int req_l = Q[i].l;
		int req_r = Q[i].r;
		while(curr_l < req_l)
		{
			remove(curr_l++);  
		}
		while(curr_l > req_l)
		{
			add(--curr_l);  
		}
		while(curr_r < req_r)
		{
			add(++curr_r);  
		}
		while(curr_r > req_r)
		{
			remove(curr_r--);  
		}
		ans[Q[i].idx] = sum[curr_max];
	}
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for(int i = 1;i <= n; i++)
		cin >> inp[i];
	for(int i = 1;i <= n-1; i++)
	{
		int u , v; cin >> u >> v;
		G[u].eb(v);
		G[v].eb(u);
	}
	edfs(1,-1);

	for(int i = 1; i <= n; i++)
		A[i] = inp[flat[i]];

	for(int i = 1; i <= n; i++)
	{
		Q[i] = query(st[i],en[i],i);  
	}
	solve();

	for(int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";  
	}
    return 0;
}

