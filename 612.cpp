#include "PE.h"

long long dp[20][(1 << 10) + 5];
int a[20],tot = 0;
void cal(long long n){
	memset(dp,0,sizeof(dp));
	long long tmp = n;
	while(tmp > 0){
		a[++tot] = tmp % 10;
		tmp /= 10;
	}
	reverse(a + 1,a + 1 + tot);
	for(int i = 1;i < a[1];i++){
		dp[1][1 << i]++;
	}
	int now = (1 << a[1]);
	for(int i = 2;i <= tot;i++){
		for(int j = 0;j < (1 << 10);j++){
			for(int k = 0;k < 10;k++){
				dp[i][j | (1 << k)] += dp[i - 1][j];
			}
		}
		for(int j = 0;j < a[i];j++){
			dp[i][now | (1 << j)]++;
		}
		for(int j = 1;j < 10;j++){
			dp[i][1 << j]++;
		}
		now |= (1 << a[i]);
	}
	dp[tot][now]++;
}
const long long mod = 1000267129;

int main(){
	long long n = 1;
	for(int i = 1;i <= 18;i++){
		n *= 10;
	}
	cal(n - 1);	
	long long ans = 0;
	for(int i = 0;i < (1 << 10);i++){
		dp[18][i] %= mod;
	}
	for(int i = 0;i < (1 << 10);i++){
		for(int j = 0;j < (1 << 10);j++){
			if(i & j){
				ans += dp[18][i] * 1LL * dp[18][j] % mod;
				ans %= mod;
			}
		}
	}
	long long sum = 0;
	for(int i = 0;i < (1 << 10);i++){
		if(dp[2][i] != 0){
		/*	for(int j = 0;j < 10;j++){
				if(i & (1 << j)) printf("1");
				else printf("0");
			}
			puts("");*/
		}
	}
	ans = (ans - (n - 1) % mod + mod) % mod;
	ans = ans * ((mod + 1) / 2) % mod;
	cout << ans << endl;
	return 0;
}
