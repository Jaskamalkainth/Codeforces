#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int k; cin >> k;
	int mon[12];
	for(int i = 0; i < 12; i++) cin >> mon[i];
	sort(mon,mon+12);
	reverse(mon,mon+12);
	int cnt = 0;
	int ans = 0;

	int flag = 0;
	for(int i = 0; i < 12; i++)
	{
		if(cnt < k )
		{
			cnt += mon[i];  
			ans++;
		}
		else
		{
			flag = 1;
			break;
		}
	}
	if( flag == 1  || cnt >= k)
		cout << ans << "\n";
	else
		cout << "-1" <<"\n";


	return 0;
}
