#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int a[15][15];
const int INF = 0x3f3f3f3f;

int dp[20][(1 << 15)];

int n;


int main(){
	n = 15;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 0;i <= 15;i++){
		for(int j = 0;j < (1 << 15);j++){
			dp[i][j] = -INF;
		}
	}
	dp[0][0] = 0;
	for(int i = 0;i <= 14;i++){
		for(int j = 0;j < (1 << 15);j++){
			if(__builtin_popcount(j) == i){
				for(int k = 0;k < 15;k++){
					if(j & (1 << k)) continue;
					dp[i + 1][j | (1 << k)] = max(dp[i + 1][j | (1 << k)],dp[i][j] + a[i + 1][k]);
				}
			}
		}
	}
	cout << dp[15][(1 << 15) - 1] << endl;
	return 0;
}
