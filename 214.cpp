#include "PE.h"

const int maxn = 40000000 + 5;

int phi[maxn];
int dp[maxn];
void phi_table(int n){
	for(int i = 2;i <= n;i++){
		phi[i] = 0;
	}
	phi[1] = 1;
	dp[1] = 1;
	for(int i = 2;i <= n;i++){
		if(!phi[i]){
			for(int j = i;j <= n;j+= i){
				if(!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
	for(int i = 2;i <= n;i++){
		dp[i] = dp[phi[i]] + 1;
	}
	long long sum = 0;
	for(int i = 2;i <= n;i++){
		if(i == phi[i] + 1 && dp[i] == 25){
			sum += i;
		}
	}
	cout << sum << endl;
}

int main(){
	phi_table(40000000);	

	return 0;
}
