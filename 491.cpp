#include "PE.h"

const int maxn = 60000;

int d[maxn][10];
int x[10][2];
long long dp[maxn][15];

int main(){
	int N = 1;
	for(int i = 1;i <= 10;i++)
		N *= 3;
	for(int i = 0;i < N;i++){
		int temp = i;
		for(int j = 0;j < 10;j++){
			d[i][j] = temp % 3;
			temp /= 3;
		}
	}
	x[0][0] = 1;
	x[0][1] = 2;
	for(int i = 1;i < 10;i++){
		x[i][0] = x[i - 1][0] * 3;
		x[i][1] = x[i - 1][1] * 3;
	}
	for(int i = 1;i < 10;i++){
		dp[x[i][0]][i] = 1;
	}
	for(int i = 2;i <= 20;i++){
		for(int j = N - 1;j >= 0;j--){
			int temp[10];
			for(int k = 0;k < 10;k++){
				temp[k] = d[j][k];
			}
			for(int k = 0;k < 10;k++){
				if(temp[k] < 2){
					for(int l = 0;l < 11;l++){
						dp[j + x[k][0]][(l * 10 + k) % 11] += dp[j][l];
					}
				}
			}
		}
	}
	for(int i = 0;i < 11;i++){
		cout << dp[N - 1][i] << endl;
	}
	return 0;
}
