#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
bool check(int mid,int T, vector<int> &res, vector<pair<int,pair<int,int>>> info)
{
    vector<pair<int,pair<int,int>>> temp;
    for(auto i: info)
        if(i.second.first >= mid)
            temp.emplace_back(i);
    sort(temp.begin(),temp.end());
    if(temp.size() >= mid)
    {
        int time = 0;
        int i = 0;
        while(i < mid)
        {
            time += temp[i].first;
            i++;
        }
        if(time <= T)
        {
            res.clear();
            int i = 0;
            while(i < mid)
            {
                res.emplace_back(temp[i].second.second);
                i++;
            }
            return true;
        }
    }
    return false;
}
int main()
{
    int n, T; cin >> n >> T;
    vector<pair<int,pair<int,int>>> info(n+1);
    for(int i = 1; i <= n; i++)
    {
        info[i].second.second = i;
        cin >> info[i].second.first >> info[i].first;    
    }
    int low = 1;
    int high = n;
    vector<int> result;
    int ans = 0;
    while(low <= high)
    {
        int mid = (low+high)>>1;
        if(check(mid,T,result,info))
        {
            ans = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    cout << ans << "\n";
    if(ans != 0)
    {
        cout << result.size() << "\n";
        for(auto i: result)
            cout << i << " ";
        cout << "\n";
    }
    else
    {
      cout << 0 << "\n";    
    }
    return 0;
}
