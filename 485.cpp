#include "PE.h"

const int maxn = 1e8 + 5;
int d[maxn];
int n,k;
int q[maxn];
int main(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j += i){
			d[j]++;
		}
	}
	int l = 1,r = 0;
	long long sum = 0;
	for(int i = n;i >= 1;i--){
		if(l <= r && q[l] >= i + k){
			l++;
		}
		while(l <= r && d[q[r]] <= d[i]){
			r--;
		}
		q[++r] = i;
		if(i + k - 1 <= n){
			sum += d[q[l]];
		}
	}	
	cout << sum << endl;
	return 0;
}
