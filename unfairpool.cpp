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
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <cassert>
#include <list>
#include <tuple>
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
#define eb 				   emplace_back
#define all(a)             a.begin(),a.end()
#define debug(x)	   {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y)       {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z)    {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, w) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#w << " = " <<w <<"\n";}
#define ss                 second
#define ff                 first
#define m0(x) 		   memset(x,0,sizeof(x))
#define builtinpopcount    __builtin_popcount(x)

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

const ld TIME_LIMIT = 5.000001;
inline int break_TIME_LIMIT() { if(( 1.0 * clock() / CLOCKS_PER_SEC ) > TIME_LIMIT) return 1; else return 0; }
/* if(break_TIME_LIMIT())
			break;
*/

const int maxn = 3e5+7;

ll stu[101][101];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int  n , m  , x , y; 
	ll k;
	cin >> n >> m >> k >> x >> y;
	if(n == 1)
	{
		ll d = k / m;
		ll leftt = k % m;
		for(int i = 1; i <= m; i++)
			stu[1][i] = d;
		if(leftt != 0)
			for(int i = 1; i <= m; i++)
			{
				stu[1][i]++;
				leftt--;
				if(leftt  == 0)
					break;
			}
		cout << stu[1][1] << " " << stu[1][m] << " " << stu[x][y] << "\n";
		return 0;
	}
	ll t = 2*(n-1)*m;
	ll direct = k / t;
	for(int i = 1; i <= m; i++)
		stu[1][i] = direct;
	for(int i = 1; i <= m; i++)
		stu[n][i] = direct;
	for(int i = 2; i <= n-1; i++)
		for(int j = 1; j <= m; j++)
			stu[i][j] = 2*direct;
	ll qleft = k % t;
	if(qleft != 0)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				stu[i][j]++;
				qleft--;
				if(qleft == 0)
					break;
			}
			if(qleft == 0)
				break;
		}
		if(qleft != 0)
		{
			for(int i = n-1; i >= 2; i--)
			{
				for(int j = 1; j <= m; j++)
				{
					stu[i][j]++;
					qleft--;
					if(qleft == 0)
						break;
				}
				if(qleft == 0)
					break;
			}
		}
	}
	assert(qleft==0);
	ll a1,a2;
	a1 = -1;
	a2 = mx_ll;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			a1 = max(a1,stu[i][j]);
			a2 = min(a2,stu[i][j]);
		}
	}
	cout << a1 << " " << a2 << " " << stu[x][y] << "\n";






    return 0;
}

