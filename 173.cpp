#include "PE.h"

int main(){
	LL n;
	cin >> n;
	LL ans = 0;
	for(int i = 2; i * 4 <= n;i++){
		int l = 0,r = 1e8;
		while(l < r){
			int mid = (l + r + 1) / 2;
			LL first = i;
			LL last = first + (mid - 1) * 2;
			LL sum = (first + last) * 2 * mid;
			if(sum <= n) l = mid;
			else r = mid - 1;
		}
		ans += l;
	}
	cout << ans << endl;
	return 0;
}
