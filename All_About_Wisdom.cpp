#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
#define mp make_pair



struct node
{
	ll to , wisdom , cost;  
	node(ll a, ll b, ll c)
	{
		to = a;
		wisdom = b;
		cost = c;
	}
};
const int maxN = 1e5+7;
vector<node> G[maxN];
ll dist[maxN];
ll n , m , k ;


inline void clearall()
{
	for(int i = 0; i < maxN; i++)
	{
		G[i].clear();
		dist[i] = 0;
	}
}

bool dijkstra(ll check_val)
{
	for(int i = 0; i < maxN; i++)
		dist[i] = 1e9+8;
	dist[1] = 0;
	set<pair<ll , ll> > s;
	s.insert(mp(0,1));
	while(!s.empty())
	{
		auto top  = *s.begin();  
		s.erase(s.begin());
		ll d = top.first;
		ll u = top.second;
		for(auto &nn: G[u])
		{
			ll v = nn.to;
			ll cost = nn.cost;
			ll wis = nn.wisdom;
			if(wis <= check_val)
			{
				if(dist[v] > dist[u] + cost)
				{
					if(dist[v] != 1e9+8)
					{
						s.erase(s.find(mp(dist[v],v)));  
					}
					dist[v] = dist[u]+cost;
					s.insert(mp(dist[v],v));
				}
			}
		}
	}
	return dist[n] < k;
	  
}
int main()
{

	int t; scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		while(m--)
		{
			ll u , v, c, w; 
			scanf("%lld%lld%lld%lld",&u,&v,&c,&w);
			G[u].push_back(node(v,w,c));
			G[v].push_back(node(u,w,c));
		}
		ll low = 0 , high = 1e9+7;
		ll ans = -1;
		while(low < high)
		{
			ll mid = (low+high)/2;
			if(dijkstra(mid))
			{
				ans = high = mid;
			}
			else
			{
				low = mid+1;  
			}
		}
		printf("%lld\n",ans);
		clearall();
	}



	return 0;
}
