#include "PE.h"

using namespace std;

long long cal(int n){
	long long ans = 0;
	for(int x = 1;x <= n;x++){
		for(int y = 1;y <= n;y++){
			if(x + y >= n) continue;
			int d = abs(x - y);
			int m = (n - x - y) / 2;
			if(d < m) ans += (m - d) * (m - d - 1) / 2;
		}
	}
	ans += n / 6 * 2;
	for(int x = 1;x <= n;x++){
		if(x * 3 >= n) break;
		ans += (n - 3 * x) / 3 * 2;
	}
	for(int x = 1;x <= n;x++){
		for(int y = 1;y <= n;y++){
			if(2 * x + 2 * y >= n) break;
			ans += (n - 2 * x - 2 * y) / 2;
		}
	}
	for(int x = 1;x <= n;x++){
		for(int y = 1;y <= n;y++){
			int d = abs(x - y);
			if(n - x - y - 2 * d <= 0) continue;
			ans += (n - x - y - 2 * d) / 4 * 3;		
		}
	}
	for(int x = 1;x <= n;x++){
		if(x * 2 >= n) break;
		ans += (n - 2 * x) / 4 * 3;
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	long long ans = cal(n);
	cout << ans << " " << ans % 12 << " " << ans / 12 << endl;
	return 0;
}
