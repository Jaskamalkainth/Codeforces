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

const int MAXN = 1e4+7;
string s; 
int len;
int P[MAXN], HashF[MAXN], HashR[MAXN];
class RollingHash {
    public:
        RollingHash() {
            prime = 100001;
            mod1 = 1000000007;
            mod2 = 1897266401;
            P[0] = 1;
            for(int i=1; i<MAXN; i++) {
                P[i] = 1LL * P[i-1] * prime % mod1;
            }
        }

        void Construct() {
            HashF[0] = HashR[ len+1 ] = 0;
            for(int i=1; i<=len; i++) {
                HashF[i] = ( 1LL * HashF[i-1] * prime + s[i-1] ) % mod1;
                HashR[len-i+1] = ( 1LL * HashR[len-i+2] * prime + s[ len - i ] ) % mod1; 
            }
        }

        int GetForwardHash( int l, int r ) {
            if( l == 1 ) return HashF[r];
            int hash = HashF[r] - 1LL * HashF[l-1] * P[ r - l + 1 ] % mod1;
            if( hash < 0 ) hash += mod1;
            return hash;
        }
        int GetBackwardHash( int l, int r ) {
            if( r == len ) return HashR[l];
            int hash = HashR[l] - 1LL * HashR[r+1] * P[ r - l + 1 ] % mod1;
            if( hash < 0 ) hash += mod1;
            return hash;
        }
        bool IsPalin( int l, int r ) {
            if( r < l ) return true;
            return (GetForwardHash(l, r) == GetBackwardHash(l, r));
        }

    private:
        int prime, mod1, mod2;
};
//	RollingHash obj;
//	obj.Construct();

ll sum[MAXN];
ll dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	len = s.length();
	RollingHash obj;
	obj.Construct();
	sum[0] = 1;
	for(int i = 1; i < len; i++)
	{
		ll temp = 0;
		for(int j = 0; j <= i; j++)
		{
			temp += obj.IsPalin(j+1,i+1);
		}
		sum[i] = sum[i-1] + temp;
	}
	dp[0] = 0;
	for(int i = 1; i < len; i++)
	{
		ll temp = 0;
		for(int j = 1; j <= i; j++)
		{
			temp += (obj.IsPalin(j+1,i+1)*sum[j-1]);  
		}
		dp[i] = dp[i-1] + temp;
	}
	cout << dp[len-1] << "\n";

    return 0;
}

