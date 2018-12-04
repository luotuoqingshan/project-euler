
#include "PE.h"
const int maxn = 1000005;
int a[maxn];
bool vis[maxn];
void phi(){
	for(int i = 2;i <= 1000000;i++)
		a[i] = i;
	for(int i = 2;i <= 1000000;i++){
		if(!vis[i]){
			a[i] = a[i] / i * (i - 1);
			for(int j = 2 * i;j <= 1000000;j += i){
				vis[j] = 1;
				a[j] = a[j] /  i * (i - 1);
			}
		}
	}
}

int main(){
	phi();
	long long ret = 0;
	for(int i = 2;i <= 12000;i++){
		ret += a[i];
	}
	cout << ret << endl;
	return 0;
}

