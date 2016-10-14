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
const int oo = 0x3f3f3f3f;
const ll  OO = 0x3f3f3f3f3f3f3f3fll;

const ld TIME_LIMIT = 5.000001;
inline int break_TIME_LIMIT() { if(( 1.0 * clock() / CLOCKS_PER_SEC ) > TIME_LIMIT) return 1; else return 0; }
/* if(break_TIME_LIMIT())
   break;
   */

const int maxn = 7e4+7;
struct mypair
{
	int l , r;  
};
mypair HashF[maxn], HashR[maxn];
int prime[2],mod[2];


int P0[maxn], P1[maxn];

inline void RollingHash_double()
{
	prime[0] = 31;
	prime[1] = 37;
	mod[0] = 999999937;
	mod[1] = 999999929;
	P0[0] = 1;
	P1[0] = 1;
	for(int i = 1; i < maxn; i++)
	{
		P0[i] = (1ll * P0[i-1] * prime[0]) % mod[0];
		P1[i] = (1ll * P1[i-1] * prime[1]) % mod[1];
	}
}
inline void Construct(string s)
{
	int len = s.length();
	HashF[0] = HashR[len+1] = {0,0};

	for(int i = 1; i <= len; i++)
	{
		HashF[i].l = (1ll * HashF[i-1].l * prime[0] + s[i-1] ) % mod[0];
		HashF[i].r = (1ll * HashF[i-1].r * prime[1] + s[i-1] ) % mod[1];

		HashR[len-i+1].l = (1ll * HashR[len-i+2].l * prime[0] + s[len-i] ) % mod[0];
		HashR[len-i+1].r= (1ll * HashR[len-i+2].r * prime[1] + s[len-i]) % mod[1];
	}
}
inline pair<int,int> getHashValue(string s)
{
	Construct(s);
	int len  = s.length();
	return {HashF[len].l,HashF[len].r};
}
inline mypair GetForwardHash(int l ,int r , int len)
{
	if(l == 1)
		return HashF[r];
	pair<int,int> hashp;
	hashp.first = (HashF[r].l - 1ll * HashF[l-1].l * P0[r-l+1]) % mod[0];
	if(hashp.first < 0)
		hashp.first += mod[0];

	hashp.second = (HashF[r].r- 1ll * HashF[l-1].r * P1[r-l+1]) % mod[1];
	if(hashp.second < 0)
		hashp.second += mod[1];
	mypair FH;
	FH.l = hashp.first;
	FH.r = hashp.second;
	return FH;
}

inline mypair GetReverseHash(int l ,int r , int len)
{
	if(r == len)
		return HashR[l];
	pair<int,int> hashp;
	hashp.first= (HashR[l].l - 1ll * HashR[r+1].l* P0[r-l+1] ) % mod[0];
	if(hashp.first< 0)
		hashp.first+= mod[0];
	hashp.second= (HashR[l].r- 1ll * HashR[r+1].r * P1[r-l+1] ) % mod[1];
	if(hashp.second < 0)
		hashp.second += mod[1];
	mypair FH;
	FH.l = hashp.first;
	FH.r = hashp.second;
	return FH;
}

bool isPalin(int l , int r, int len)
{
	if( r < l ) return true;
	mypair FH = GetForwardHash(l,r,len);
	mypair RH = GetReverseHash(l,r,len);
	if(FH.l == RH.l && FH.r == RH.r)
		return true;
	return false;
}


ll dp[5000] , sum[5000];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

	string s; cin >> s;
	int len = s.length();

	RollingHash_double();
	Construct(s);


	sum[0] = 1;
	for(int i = 1; i < len; i++)
	{
		int temp = 0;
		for(int j = 0; j <= i; j++)
		{
			temp += isPalin(j+1,i+1,len);
		}
		sum[i] = sum[i-1] + temp;
	}

	for(int i = 1; i < len; i++)
	{
		int temp = 0;
		for(int j = 1; j <= i; j++)
		{
			temp += sum[j-1] * isPalin(j+1,i+1,len);
		}
		dp[i] = dp[i-1] + temp;
	}

	cout << dp[len-1] << "\n";
	return 0;
}

