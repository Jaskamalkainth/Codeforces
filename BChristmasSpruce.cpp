#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int> g[],int u,vector<int> &leafcnt, vector<int> &isLeaf)
{
    if(g[u].size() == 0)
    {
        isLeaf[u] = 1;
        return ;
    }
    for(auto v: g[u])
    {
        dfs(g,v,leafcnt,isLeaf);
        if(isLeaf[v] == 1)
        {
            leafcnt[u]++;    
        }
    }
}
int main()
{
    int n; cin >> n;
    vector<int> g[n+1];
    for(int i = 1; i <= n; i++)
        g[i].resize(0);
    for(int i = 1; i <= n-1; i++)
    {
        int x; cin >> x;
        g[x].push_back(i+1);
    }
    bool flag = false;
    vector<int> isLeaf(n+1),leafcnt(n+1);
    dfs(g,1,leafcnt,isLeaf);
    for(int i = 1; i <= n; i++)
        if(!isLeaf[i] && leafcnt[i] <= 2)
        {
            flag = true;
            break;
        }
    if(!flag)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
