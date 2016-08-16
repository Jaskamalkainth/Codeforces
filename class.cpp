/*
 *    J1K7_7
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
#define debug4(x, y, z, w) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#w<<"\n";}
#define ss                 second
#define ff                 first
#define m0(x) 		       memset(x,0,sizeof(x))

const int mod=1e9+7;

template<class T> inline T gcd(T a,T b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
template<class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}
template<typename T, typename S> T expo(T b, S e, const T &m){if(e <= 1)return e == 0?1: b;\
	return (e&1) == 0?expo((b*b)%m, e>>1, m): (b*expo((b*b)%m, e>>1, m))%m;}
template<typename T> T modinv(T a) { return expo(a, mod-2, mod); }

inline int nextint(){ int x; scanf("%d",&x); return x; }
inline ll nextll(){ ll x; scanf("%lld",&x); return x; }

const ll  mx_ll   = numeric_limits<ll> :: max();
const int mx_int  = numeric_limits<int> :: max();

const long double PI = (long double)(3.1415926535897932384626433832795);


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifndef __APPLE__
    freopen("class.in", "rb", stdin);
    freopen("class.out", "wb", stdout);
#endif

	int n , r, c; cin >> n >> r >> c;
	char grid[r][c];
	memset(grid,'.',sizeof(grid));
	int rf = 1;
	int cf = 1;
	grid[0][0] = '#';
	n--;
	while(rf < r && cf < c &&  n >= 2)
	{
		grid[rf][0] = '#';
		grid[0][cf] = '#';
		n -= 2;
		rf++,cf++;
	}
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			if(n)
				if(grid[i][j] == '.')
				{
					grid[i][j] = '#';
					n--;
				}

	int arf = 1;
	int arc = 1;
	int ans;
	for(int i = 0; i < r; i++)
	{
		int cntrow = 0;
		for(int j = 0; j < c; j++)
		{
			if(grid[i][j] == '#')
				cntrow++;
		}
		arf = max(arf,cntrow);
	}

	for(int i = 0; i < c; i++)
	{
		int cntcol = 0;
		for(int j = 0; j < r; j++)
		{
			if(grid[j][i] == '#')
				cntcol++;
		}
		arc = max(arc,cntcol);
	}

	cout << min(arf,arc) << "\n";

	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
			cout << grid[i][j];
		cout << "\n";
	}

    return 0;
}

