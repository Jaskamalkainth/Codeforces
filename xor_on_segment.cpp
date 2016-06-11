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
#define l(x) 		       (x << 1) + 1
#define r(x) 		       (x << 1) + 2
#define mid(l, r) 	       ((l + r) >> 1)
#define mp                 make_pair
#define pb                 push_back
#define all(a)             a.begin(),a.end()
#define debug(x)	       {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y)       {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define ss                 second
#define ff                 first
#define m0(x) 		       memset(x,0,sizeof(x))
#define snuke(c,itr)       for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

template<class T>
inline bool ispow2(T x){return (x!=0 && (x&(x-1))==0);} //0 or 1

template<class T> inline T powmod(T a,T b,T mod) {ll res = 1; while(b){if(b&1) res = (res*a)%mod;a = (a*a)%mod;b >>= 1;}return res;}
template<class T> inline T gcd(T a,T b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
template<class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}

inline int nextint(){ int x; scanf("%d",&x); return x; }
inline ll nextll(){ ll x; scanf("%lld",&x); return x; }

const int mod=1e9+7;

const ll  mx_ll   = numeric_limits<ll> :: max();
const int mx_int  = numeric_limits<int> :: max();

const long double PI = (long double)(3.1415926535897932384626433832795);

const int maxN = 1e5+7;
int n;
int arr[maxN];
int table[maxN][27];
int tree[27][4*maxN];
int lazy[27][4*maxN];

void build(int no , int node ,int left , int right)
 {
	if(left == right)
	{
		tree[no][node] = table[left][no];
		return;
	}
	int mid = (left + right) >> 1;
	build(no,2*node,left,mid);
	build(no,2*node+1,mid+1,right);
	tree[no][node] = tree[no][2*node]+  tree[no][2*node+1];
 }
void update(int no , int node , int left , int right , int lq , int rq)
{
	if(lazy[no][node])
	{
		tree[no][node] = (right-left+1) -  tree[no][node];
		if(left != right)
		{
			lazy[no][2*node] ^= 1;
			lazy[no][2*node+1] ^= 1;
		}
		lazy[no][node] = 0;
	}
	if(rq < left || lq > right)
		return;
	if(lq <= left && rq >= right)
	{
		tree[no][node] = (right-left+1) -  tree[no][node];
		if(left != right)
		{
			lazy[no][2*node] ^= 1;
			lazy[no][2*node+1] ^= 1;
		}
		lazy[no][node] = 0;
		return;
	}

	int mid = mid(left,right);
	update(no,2*node,left,mid,lq,rq);
	update(no,2*node+1,mid+1,right,lq,rq);
	tree[no][node] = tree[no][2*node]+  tree[no][2*node+1];
}
int query(int no , int node, int left , int right , int lq , int rq)
{
	if(lazy[no][node])
	{
		tree[no][node] = (right-left+1) -  tree[no][node];
		if(left != right)
		{
			lazy[no][2*node] ^= 1;
			lazy[no][2*node+1] ^= 1;
		}
		lazy[no][node] = 0;
	}
	if(rq < left || lq > right)
		return 0;
	if(lq <= left && rq >= right)
	{
		return tree[no][node];
	}
	int mid = mid(left,right);
	return query(no,2*node,left,mid,lq,rq) + query(no,2*node+1,mid+1,right,lq,rq);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	for(int i = 0; i < n; i++)
		for(int id = 0; id < 20; id++)
			table[i][id] = (arr[i]&(1<<id)) == 0 ? 0 : 1;
	for(int i = 0; i < 20; i++)
	{
		build(i,1,0,n-1);  
	}
	int m; cin >> m;
	while(m--)
	{
		int type; cin >> type;
		if(type == 1)
		{
			int l , r; cin >> l >> r;
			l--;
			r--;
			
			ll ans = 0ll;
			for(int j = 0; j < 20; j++)
				ans += (1ll<<j)*1ll*query(j,1,0,n-1,l,r);
			cout << ans << "\n";
			//return sum from l , r
		}
		else if(type == 2)
		{
			int l , r , x; cin >> l >> r >> x;
			l--;
			r--;
			for(int j = 0; j < 20; j++)
				if(x&(1<<j))
					update(j,1,0,n-1,l,r);
			//xor all the numbers from l to r with "x"
		}
	}
    return 0;
}

