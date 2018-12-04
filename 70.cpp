#include "PE.h"
const int maxn = 10000005;
int a[maxn];
bool vis[maxn];
void phi(){
	for(int i = 2;i < 10000000;i++)
		a[i] = i;
	for(int i = 2;i < 10000000;i++){
		if(!vis[i]){
			a[i] = a[i] / i * (i - 1);
			for(int j = 2 * i;j < 10000000;j += i){
				vis[j] = 1;
				a[j] = a[j] /  i * (i - 1);
			}
		}
	}
}

bool check(int n){
	int A[15];
	int B[15];
	int tmp = n;
	int tot1 = 0,tot2 = 0;
	while(tmp > 0){
		A[tot1++] = tmp % 10;
		tmp /= 10;
	}
	tmp = a[n];
	
	while(tmp > 0){
		B[tot2++] = tmp % 10;
		tmp /= 10;
	}
	if(tot1 != tot2) return 0;
	sort(A,A + tot1);
	sort(B,B + tot2);
	for(int i = 0;i < min(15,tot1);i++){
		if(A[i] != B[i]) return 0;
	}
	return 1;
}

int main(){
	phi();
	double ans = 1e9;
	int id = 0;
	for(int i = 2;i < 10000000;i++){
		if(!check(i)) continue;
		if(1.0 * i / a[i] < ans){
			ans = 1.0 * i / a[i];
			id = i;
		}
	}
	cout << id << endl;
	return 0;
}
