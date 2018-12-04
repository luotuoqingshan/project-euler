#include "PE.h"

int dp[10000000];
int cal(int n){
	if(n == 89) return 1;
	if(n == 1) return 0;	
	int &ret = dp[n];
	if(ret != -1) return ret;
	int tmp = 0;
	while(n > 0){
		int d = n % 10;
		tmp += d * d;
		n /= 10;
	}
	return cal(tmp);
}
int main(){
	memset(dp,-1,sizeof(dp));
	int ans = 0;
	for(int i = 1;i < 10000000;i++){
		ans += cal(i);
	}
	cout << ans << endl;
	return 0;
}
