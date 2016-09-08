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
#define left(x) 		   (x << 1)
#define right(x) 		   (x << 1) + 1
#define mid(l, r) 	       ((l + r) >> 1)
#define mp                 make_pair
#define pb                 push_back
#define all(a)             a.begin(),a.end()
#define debug(x)	       {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y)       {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z)    {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, w) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#w << " = " <<w <<"\n";}
#define ss                 second
#define ff                 first
#define m0(x) 		       memset(x,0,sizeof(x))

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


const int maxn = 1e6+7;
const int maxchar = 27;
int trie[maxn][maxchar] , word_ending_id[maxn];
int sz = 1;

inline void insert(string str,int id)
{
	int len = str.length();
	int node = 0;
	for(int i = len-1; i >= 0; i--)
	{
		int ch;
		if(str[i] >= 'a' && str[i] <= 'z')
			ch = str[i]-'a';
		else
			ch = str[i] -'A';
		if(trie[node][ch] == -1)
			trie[node][ch] = sz++;
		node = trie[node][ch];
	}
	word_ending_id[node] = id;
}
vi ans;
int dp[maxn];
string inp;
int n;
inline int query(int id)
{
	int node = 0;
	for(int i = id; i < n; i++)
	{
		int ch = inp[i]-'a';
		if(trie[node][ch] == -1)
			return -1;
		node = trie[node][ch];	
		if(word_ending_id[node] != -1 && dp[i+1] != -1)
		{
			return word_ending_id[node];  
		}
	}
	return -1;
}

int main()
{

	memset(trie,-1,sizeof(trie));
	memset(word_ending_id,-1,sizeof(word_ending_id));
	memset(dp,-1,sizeof(dp));

	scanint(n);
	cin >> inp;

	int t; scanint(t);
	vector<string> sos(maxn);
	for(int i = 1; i <= t; i++)
	{
		string x; cin >> x;
		sos[i] = x;
		insert(x,i);
	}
	dp[n] = 0;
	for(int i = n-1; i >= 0; i--)
		dp[i] = query(i);

	int i = 0;
	while(i < n)
	{
		cout << sos[dp[i]] << " ";
		i += sos[dp[i]].length();
	}
	  return 0;
}

