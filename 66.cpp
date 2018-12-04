#include "PE.h"

int ans[1005];
int main(){
	int ret = 0;
	for(int i = 1;i <= 1000;i++){
		int x = sqrt(i);
		if(x * x == i) continue;
		for(int j = 1;j <= 1000000;j++){
			long long y = 1LL * i * j * j + 1;
			long long z = sqrt(y);
			if(y== z * z){
				ans[i] = z;
				break;
			}
		}
		cout << ans[i] << endl;
		ret = max(ret,ans[i]);	
	}
	cout << ret << endl;
	return 0;
}
