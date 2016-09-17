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

const int maxn = 1e3+7;
ll arr[maxn][maxn];
ll sum[maxn][maxn];
int n , m;

inline void BUILD_partial_sum()
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			sum[i][j] = arr[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
}
inline ll QUERY_partial_sum(int x1, int y1 ,int x2, int y2)
{
	return sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];  
}
ll best[maxn][maxn];
int vis[maxn][maxn];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

	int  a, b; cin >> n >> m >> a >> b;
	for(int i = 1; i <= n ; i++)
		for(int j = 1; j <= m; j++)
			cin >> arr[i][j];
	BUILD_partial_sum();

	deque<int> Q;
	for(int i = 1; i <= n; i++)
	{
		Q.clear();
		for(int j = 1; j <= m; j++)
		{
			while(Q.size() && Q.back() > arr[i][j])
				Q.pop_back();
			Q.push_back(arr[i][j]);
			if( j >= b)
			{
				best[i][j] = Q.front(); // min for this window 
				if(Q.front() == arr[i][j-b+1])
					Q.pop_front();
			}
		}
	}
	vector<pair<ll,pii>> fans,ans;
	for(int j = b; j <= m; j++)
	{
		Q.clear();
		for(int i = 1; i <= n; i++)
		{
			while(Q.size() && Q.back() > best[i][j])
				Q.pop_back();
			Q.push_back(best[i][j]);
			if(i >= a)
			{
				ll rect_sum = QUERY_partial_sum(i-a+1,j-b+1,i,j);
				ll rect_min = Q.front();
				ll cost = rect_sum - 1ll*a*b*rect_min;
				ans.pb({cost,{i-a+1,j-b+1}});
				if(rect_min == best[i-a+1][j])
					Q.pop_front();
			}
		}
	}
	sort(all(ans));

	for(auto ii: ans)
	{
		int x = ii.ss.ff;
		int y = ii.ss.ss;
		if(vis[x][y] || vis[x+a-1][y] || vis[x][y+b-1] || vis[x+a-1][y+b-1])
			continue;
		fans.pb(ii);
		for(int i = x; i <= x+a-1; i++)
			for(int j = y; j <= y+b-1; j++)
				vis[i][j] = 1;
	}
	cout << fans.size() << "\n";
	for(auto &i: fans)
	{
		cout << i.ss.ff << " " << i.ss.ss << " " << i.ff << "\n";  
	}

    return 0;
}

