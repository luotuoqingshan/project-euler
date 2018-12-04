#include "PE.h"
int a[105][105];
int dp[105][105];
int main(){
	freopen("p067_triangle.txt","r",stdin);
	for(int i = 1;i <= 100;i++){
		for(int j = 1;j <= i;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 1;i <= 100;i++){
		for(int j = 1;j <= 100;j++){
			dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - 1]) + a[i][j];
		}
	}
	int ans = 0;
	for(int i = 1;i <= 100;i++){
		ans = max(ans,dp[100][i]);
	}
	cout << ans << endl;
	return 0;
}
