/*
 *
 *    J1K7_7
 * 
 */
#include <iostream>
using namespace std;
int arr[101][202];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

	int n , m; cin >> n >> m;
	for(int i = 0;i < n; i++)
		for(int j = 0; j < 2*m; j++)
			cin >> arr[i][j];  

	long long ans = 0ll;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 2*m; j+=2)
		{
			if(arr[i][j]+arr[i][j+1] != 0 )
				ans++;
		}
	}
	cout << ans << "\n";

    return 0;
}

