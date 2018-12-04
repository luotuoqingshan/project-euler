#include "PE.h"

long long dp[70][70];

int n,m;

int main(){
	dp[0][0] = 1;
	int n,m;
	cin >> n >> m;
	for(int k = 0;k <= n;k++){
		for(int l = 0;l <= m;l++){
			if(k == 0 && l == 0) continue;
			for(int i = 0;i <= n;i++){
				for(int j = 0;j <= m;j++){
					if((i + k) <= n && (j + l) <= m){
						dp[(i + k)][(j + l)] += dp[i][j];
					}
				}
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
