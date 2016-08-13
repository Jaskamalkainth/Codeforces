#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;


const int maxn = 3e6+7;
ll a[maxn];
int n;

struct node
{
	ll val;
	node()
	{
		val = 0;  
	}
}tree[4*maxn];
void build(int id ,int left ,int right)
{
	if(left == right)
		tree[id] = a[left];
	int mid = (left + right)/2;
	build(2*id,left,mid);
	build(2*id+1,mid+1,right);
	tree[id] = tree[2*id]^tree[2*id+1];
}

ll query(int id ,int left ,int right , int lq ,int rq)
{
	if(left > rq || right < lq)
		return 0;
	if(left > lq && right < rq)
		return tree[id];
	int mid = (left+right)/2;
	return query(2*id,left,mid,lq,rq)^query(2*id+1,mid+1,right,lq,rq);
}

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);

	build(1,0,n-1);

	int q;
	scanf("%d",&q);
	while(q--)
	{
		int  l , r ; 
		scanf("%d%d",&l,&r);
		l--;
		r--;
		printf("%lld\n",query(1,0,n-1,l,r)^query(1,0,n-1,l,r));
	}
	return 0;
}
