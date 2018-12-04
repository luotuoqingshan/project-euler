#include "PE.h"

int a[9];
map<int,int> ans;
int main(){
	long long sum = 0;
	for(int i = 0;i < 9;i++){
		a[i] = i + 1;
	}
	do{
		int x = 0,y = 0,z = 0;
		for(int i = 0;i < 9;i++){
			for(int j = i + 1;j < 8;j++){
				x = 0,y = 0,z = 0;
				for(int k = 0;k <= i;k++){
					x = x * 10 + a[k];
				}
				for(int k = i + 1;k <= j;k++){
					y = y * 10 + a[k];
				}
				for(int k = j + 1;k < 9;k++){
					z = z * 10 + a[k];
				}
				if(1LL * x * y == z) ans[z] = 1;
			}
		}
	}while(next_permutation(a,a + 9));
	for(auto x : ans){
		sum += x.first;
	}
	cout << sum << endl;
	return 0;
}
