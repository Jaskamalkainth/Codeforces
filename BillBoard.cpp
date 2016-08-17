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


int h , w , n;
const int maxn = 2e5+7;

int tree[4*maxn];

inline void build(int id = 1 ,int left = 1 ,int right = h )
{
	if(left == right)
	{
		tree[id] = w;  
		return ;
	}
	int mid = mid(left,right);
	build(2*id,left,mid);
	build(2*id+1,mid+1,right);
	tree[id] = max(tree[2*id],tree[2*id+1]);
}
inline void point_update(int index ,int value ,int id = 1, int left= 1 , int right = h)
{
	if(left == right)
	{
		tree[id] -= value;  
		return ;
	}
	int mid = mid(left,right);
	if(index <= mid)
		point_update(index,value,2*id,left,mid);
	else
		point_update(index,value,2*id+1,mid+1,right);
	tree[id] = max(tree[2*id],tree[2*id+1]);
}
inline int query_index(int val , int id = 1 ,int left = 1 ,int right = h )
{
	if(tree[id] < val)
	{
			return -1;  
	}
	if(left == right)
	{
		return left;  
	}
	int mid = mid(left,right);
	if(tree[2*id] < val)
		return query_index(val,2*id+1,mid+1,right);
	else
		return query_index(val,2*id,left,mid);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifndef __APPLE__
    freopen("billboard.in", "rb", stdin);
    freopen("billboard.out", "wb", stdout);
#endif
	cin >> h >> w >> n;
	h = min(h,n);
	build();
	while(n--)
	{
		int x; cin >> x;
		int id = query_index(x);
		if(id == -1)
		{
			cout <<"-1\n";
			continue;
		}
		cout << id << "\n";
		point_update(id,x);
	}
    return 0;
}

