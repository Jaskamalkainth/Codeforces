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
class RollingHash_double
{
public:
	static const int nine_len = 1e9+1;
	vector<int> P0,P1;
	long long prime[2],mod[2];
	vector< pair<int,int>> HashF, HashR;
	string s;
	int len;
	int check_prime(ll n)
	{
		int flag = 0;
		for(int i = 2; i * i < n; i++)
			if(n % i == 0)
				flag = 1;
		if(flag)
			return 0;
		else
			return 1;
	}
	RollingHash_double(string sinp)
	{
		s = sinp;
		len = sinp.size();
		HashR.resize(len+2);
		HashF.resize(len+2);
		P0.resize(len+2);
		P1.resize(len+2);
		prime[0] = 31;
		prime[1] = 37;
		/*long long rand_mod1 = nine_len + rand() % nine_len;
        long long rand_mod2 = nine_len + rand() % nine_len;
        while(!check_prime(rand_mod1))
            rand_mod1++;
        while(!check_prime(rand_mod2))
            rand_mod2++;
        while(rand_mod1 == rand_mod2)
        {
            rand_mod1++;
            while(!check_prime(rand_mod1))
                rand_mod1++;
        }
        mod[0] = rand_mod1;
        mod[1] = rand_mod2;*/
		mod[0] = 1000016863;
		mod[1] = 1282475263;
		P0[0] = P1[0] = 1;
		for(int i = 1; i <= len; i++)
		{
			P0[i] = (1ll * P0[i-1] * prime[0]) % mod[0];
			P1[i] = (1ll * P1[i-1] * prime[1]) % mod[1];
		}
		Construct();
	}
	void Construct()
	{
		HashF[0] = HashR[len+1] = {0,0};
		for(int i = 1; i <= len; i++)
		{
			HashF[i].first = (1ll * HashF[i-1].first * prime[0] + s[i-1] ) % mod[0];
			HashF[i].second = (1ll * HashF[i-1].second * prime[1] + s[i-1] ) % mod[1];

			HashR[len-i+1].first = (1ll * HashR[len-i+2].first * prime[0] + s[len-i] ) % mod[0];
			HashR[len-i+1].second = (1ll * HashR[len-i+2].second * prime[1] + s[len-i]) % mod[1];
		}
	}
	pair<int,int> GetHashValue()
	{
		return {HashF[len].first,HashF[len].second};
	}
	pair<int,int> GetForwardHash(int l ,int r)
	{
		if(l == 1)
			return HashF[r];
		pair<int,int> hashp;

		hashp.first = (HashF[r].first - 1ll * HashF[l-1].first * P0[r-l+1] ) % mod[0];
		if(hashp.first < 0)
			hashp.first += mod[0];

		hashp.second = (HashF[r].second- 1ll * HashF[l-1].second * P1[r-l+1] ) % mod[1];
		if(hashp.second < 0)
			hashp.second += mod[1];
		return hashp;
	}

	pair<int,int> GetReverseHash(int l ,int r)
	{
		if(r == len)
			return HashR[l];
		pair<int,int> hashp;
		hashp.first= (HashR[l].first - 1ll * HashR[r+1].first* P0[r-l+1]) % mod[0];
		if(hashp.first< 0)
			hashp.first+= mod[0];
		hashp.second= (HashR[l].second- 1ll * HashR[r+1].second * P1[r-l+1] ) % mod[1];
		if(hashp.second < 0)
			hashp.second += mod[1];
		return hashp;
	}

	bool IsPalin(int l , int r)
	{
		if( r < l ) return true;
		return (GetForwardHash(l,r) == GetReverseHash(l,r));
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int q;
	cin >> q;
	map<pair<int,int>, int> mp;
	for (int i = 1; i <= q; ++i)
	{
		string x;
		cin >> x;
		RollingHash_double r1(x);
		mp[r1.GetHashValue()] = i;
	}
	RollingHash_double r2(s);
    for(int i = 1; i <= k; i++)
	{
        set<int> doneid;
		vector<int> ans;
		int flag = 1;
		for(int j = i; j <= s.size(); j+=k)
		{
			if(j+k-1 <= s.size())
			{
				int val = mp[r2.GetForwardHash(j, j+k-1)];
				if (val && (doneid.find(val) == doneid.end())){
					ans.eb(val);
					doneid.insert(val);
				} else {
					flag = 0;
					break;
				}
			}
			else
			{
				// calc my own hash value of the remaining string [j..s.size()] + [1..x] where total length = k
				pair<ll, ll> newhashval;
                int id = k-s.size()+j-1;
				newhashval.ff = (r2.GetForwardHash(1,id).ff +  (r2.P0[id])*1ll*r2.GetForwardHash(j,s.size()).ff) % r2.mod[0];
				newhashval.ss = (r2.GetForwardHash(1,id).ss +  (r2.P1[id])*1ll*r2.GetForwardHash(j,s.size()).ss) % r2.mod[1];
				int val = mp[newhashval];
                if (val && (doneid.find(val) == doneid.end())){
					ans.eb(val);
					doneid.insert(val);
				} else {
					flag = 0;
					break;
				}
			}
		}
		if(flag)
		{
			cout << "YES\n";
			for (auto i: ans)
				cout << i << " ";
			return 0;
		}
	}
    cout << "NO\n";
	return 0;
}










