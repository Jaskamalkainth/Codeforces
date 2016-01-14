
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
typedef long long          ll;
typedef unsigned long long ull;
typedef long double        ld;
#define l(x) 		       (x << 1) + 1
#define r(x) 		       (x << 1) + 2
#define mid(l, r) 	       ((l + r) >> 1)
#define mp                 make_pair
#define pb                 push_back
#define all(a)             a.begin(),a.end()
#define pr(n)              printf("%d",n)
#define s(n)               scanf("%d",&n)
#define debug(x)	       {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y)       {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y ;}
#define ss                 second
#define ff                 first
#define m0(x) 		       memset(x,0,sizeof(x))
#define snuke(c,itr)       for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

const ll  mx_ll   = numeric_limits<ll> :: max();
const int mx_int  = numeric_limits<int> :: max();

const long double PI = (long double)(3.1415926535897932384626433832795);

inline bool ispow2(int x){return (x!=0 && (x&(x-1))==0);} //0 or 1

int msb(unsigned x){ union { double a; int b[2]; }; a = x; return (b[1] >> 20) - 1023; }

template<class T>
inline void cinarr(T a, int n){ for (int i=0;i<n;++i) cin >> a[i];}


inline int nextint(){ int x; scanf("%d",&x); return x; }
inline ll nextll(){ ll x; scanf("%lld",&x); return x; }


typedef vector<ll> VI;
typedef pair<ll,ll> PII;

// return a % b (positive value)
int mod(int a, int b) {

	if( b == 0 )
		return a;
	return ((a%b)+b)%b;
}

// computes gcd(a,b)
int gcd(int a, int b) {
	int tmp;
	while(b){a%=b; tmp=a; a=b; b=tmp;}
	return a;
}

// computes lcm(a,b)
int lcm(int a, int b) {
	return a/gcd(a,b)*b;
}

// returns d = gcd(a,b); finds x,y such that d = ax + by
int extended_euclid(int a,int b,int &x , int &y) {
	if (!b) { x=1, y=0; return a; }
	ll ret=extended_euclid(b,a%b,x,y), t=x;
	x=y, y=t-a/b*x;
	return ret;
}


// computes b such that ab = 1 (mod n), returns -1 on failure
int mod_inverse(int a, int n) {
	int x, y;
	int d = extended_euclid(a, n, x, y);
	if (d > 1) return -1;
	return mod(x,n);
}

// Chinese remainder theorem (special case): find z such that
// z % x = a, z % y = b.  Here, z is unique modulo M = lcm(x,y).
// Return (z,M).  On failure, M = -1.
PII chinese_remainder_theorem(int x, int a, int y, int b) {
	int s, t;
	int d = extended_euclid(x, y, s, t);

	cout << "x = " << x << " a = " <<  a << " y = " << y <<  " b = " <<  b << " d = "  << d<< " s = " << s << " t = " << t << "\n";

	if ( mod(( a-b ) ,d) != 0 ) 
		return make_pair(0, -1);

	return make_pair(mod(s*b*x + t*a*y , x*y )/d, x*y/d);
}

// Chinese remainder theorem: find z such that
// z % x[i] = a[i] for all i.  Note that the solution is
// unique modulo M = lcm_i (x[i]).  Return (z,M).  On 
// failure, M = -1.  Note that we do not require the a[i]'s
// to be relatively prime.
PII chinese_remainder_theorem(const VI &x, const VI &a) {
	PII ret = make_pair(a[0], x[0]);
	for (int i = 1; i < x.size(); i++) {
		ret = chinese_remainder_theorem(ret.second, ret.first, x[i], a[i]);
		if (ret.second == -1) break;
	}
	return ret;
}

// computes x and y such that ax + by = c; on failure, x = y =-1
void linear_diophantine(int a, int b, int c, int &x, int &y) {
	int d = gcd(a,b);
	if (c%d) {
		x = y = -1;
	} else {
			x = c/d * mod_inverse(a/d, b/d);
		y = (c-a*x)/b;
	}
}


ll n , m , k;
vector<ll> a;

const ll maxN = 1e12;
ll L = 1 ;

bool solve()
{

	L = a[0];
	for (int i = 1; i < a.size(); i++)
	{
		L /= gcd(L,a[i]);
		if ( L > n / a[i] )
			return false;

		L *= a[i];
	}

	vector<ll> c;
	for(int i = 0; i < k; i++)
	{
		c.pb(mod(-i,a[i]));
	}


	ll col_num ;
	ll row_num = L;


	col_num = chinese_remainder_theorem(c,a).ff;
	ll l = chinese_remainder_theorem(c,a).ss;
	debug(l);
	
	debug(row_num );
	debug(col_num);


	if ( ( col_num + k ) > m ) 
		return false;


	debug(row_num );
	debug(col_num);


	for(int i = 0; i < k; i++)
	{
		if( gcd(row_num , col_num + i ) != a[i] )
			return false;
	}
	return true;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	/*
	vector<int> r ;
	vector<int> mod;

	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		ll x , y ; cin >> x >> y;
		mod.pb(x);
		r.pb(y);
	}
	cout << chinese_remainder_theorem( r , mod ).ff << "\n";
	cout << chinese_remainder_theorem( r , mod ).ss << "\n";

*/
	cin >> n >> m >> k;

	for(int i = 0 ; i < k ; i++)
	{
		ll x;
		cin >> x;
		a.pb(x);		
	}


	if ( solve() )
	{
		cout << "YES" << "\n"; ;
	}
	else
	{
		cout << "NO" << "\n" ;
	}


}
