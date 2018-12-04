#include "PE.h"

const int maxn = 5e8 + 5;

int phi[maxn];

int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		phi[i] = i;
	}
	for(int i = 2;i <= n;i++){
		if(phi[i] == i){
			for(int j = i;j <= n;j += i){
				phi[j] /= i;
				phi[j] *= (i - 1);
			}
		}
	}
	long long ans = 0;
	for(int i = 1;i <= n;i += 2){
		ans += phi[i];
	}
	cout << ans << endl;
	return 0;
}
