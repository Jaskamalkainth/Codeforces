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
#define debug_hey(x)       {cerr << "hey " << #x << "\n";}
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

const int maxn = 207;
struct data
{
  int t,d,p;
  int id;
  bool operator<(const data& right) const
  {
    return d < right.d;    
  }
}inp[maxn];
int dp[207][2007];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);


    int n; cin >> n;
    for(int i = 1;i <= n; i++)
    {
      int t, d, p; cin >> t >> d >> p;
      inp[i].t = t;
      inp[i].d = d;
      inp[i].p = p;
      inp[i].id = i;
    }
    sort(inp+1,inp+n+1);
    for(int i = 1;i <= n; i++)
    {
      for(int t = 0; t <= 2000; t++)
      {
            dp[i][t] = dp[i-1][t];
            if(t < inp[i].d && t >= inp[i].t)
            {
              dp[i][t] = max(dp[i-1][t],dp[i-1][t-inp[i].t] + inp[i].p);    
            }
      }
    }
    int mxval = -1;
    int mxtime = 0;
    for(int t = 0; t <= 2000; t++)
    {
      if(dp[n][t] > mxval)
      {
        mxval = dp[n][t];
        mxtime =  t;
      }
    }
    vector<int> ans;
    int cur_id = n;
    while(mxtime > 0 && cur_id > 0)
    {
        if(dp[cur_id][mxtime] != dp[cur_id-1][mxtime])
        {
          ans.push_back(cur_id);    
          mxtime -= inp[cur_id].t;
        }
        cur_id--;
    }
    reverse(ans.begin(),ans.end());
    cout << mxval << "\n";
    cout << ans.size() << "\n";
    for(auto i: ans)
        cout << inp[i].id << " ";

    return 0;
}

