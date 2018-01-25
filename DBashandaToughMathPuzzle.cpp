#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 5e5+7;
int a[maxn];
int tree[4*maxn];
int gcd(int a , int b)
{
  if(b == 0)
      return a;
  else
      return gcd(b,a%b);
}
void build(int node, int l , int r)
{
    if(l == r)
    {
      tree[node] = a[l];    
      return ;
    }
    int mid = (l+r)>>1;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    tree[node] = gcd(tree[2*node],tree[2*node+1]);
}

void update(int node, int l ,int r, int id, int val)
{
    if(l > id || r < id)
        return;
    if(l >= id && r <= id)
    {
        tree[node] = val;
        return ;
    }
    int mid = (l+r)>>1;
    update(2*node,l,mid,id,val);
    update(2*node+1,mid+1,r,id,val);
    tree[node] = gcd(tree[2*node],tree[2*node+1]);
}

bool check(int node, int lq, int rq, int x)
{
    if(lq >= rq) 
        return 1;
    int a,b;
    if((a = tree[2*node]%x != 0) && (b = tree[2*node+1]%x != 0))
        return 0;
    int mid = (lq+rq)>>1;
    if(a)
        return check(2*node,lq,mid,x);
    else
        return check(2*node+1,mid+1,rq,x);
}

bool query(int node, int l , int r, int lq , int rq, int x, int& count)
{
  if(l > rq || r < lq)
      return 1;
  if(l >= lq && r <= rq)
  {
    if(tree[node]%x != 0)
    {
        count++;
        // now check in this range if only one element not divisible by x exsist or not
        if(count >= 2)
            return 0;
        else 
            return check(node,l,r,x);
    }
    return 1;
  }
  int mid = (l+r)>>1;
  return query(2*node,l,mid,lq,rq,x,count) && query(2*node+1,mid+1,r,lq,rq,x,count);
}
int main()
{
    int n; 
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    // build gcd tree
    build(1,1,n);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int tp;
        scanf("%d",&tp);
        if(tp == 1)
        {
            // query
            int l , r, x;
            scanf("%d%d%d",&l,&r,&x);
            int c = 0;
            if(query(1,1,n,l,r,x,c))
                puts("YES");
            else
                puts("NO");
        }
        else
        {
            int i, y;           
            scanf("%d%d",&i,&y);
            //update
            update(1,1,n,i,y);
        }
    }
    return 0;
}
