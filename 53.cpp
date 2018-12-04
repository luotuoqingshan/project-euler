#include "PE.h"

const int maxn = 1000000;
int main(){
	long long ans = 0;
	for(int n = 1;n <= 100;n++){
		long long now = 1;
		int j;
		for(j = 0;j <= n / 2;j++){
			if(now > maxn) break;
			now *= (n - j);
			now /= (j + 1);
		}
		if(j == n / 2 + 1) continue;
		else ans += n - j - j + 1;	
	}
	cout << ans << endl;
	return 0;
}
