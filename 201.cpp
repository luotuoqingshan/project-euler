#include "PE.h"

int a[105];

int f[55][500005];

int main(){
	f[0][0] = 1;
	int sum = 0;
	for(int i = 1;i <= 100;i++){
		sum += i * i;
		for(int j = 50;j >= 1;j--){
			for(int k = sum;k >= i * i;k--){
				f[j][k] += f[j - 1][k - i * i];
			}
		}
	}
	long long ans = 0;
	for(int i = 0;i <= sum;i++){
		if(f[50][i] == 1){
			ans += i;
		}
	}
	cout << ans << endl;
	return 0;
}
