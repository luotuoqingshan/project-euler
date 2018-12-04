#include "PE.h"


int check(int a[],int n){
	int res = 0;
	for(int i = 0;i < n;i++){
		res = res * 10 + a[i];
	}
	if(is_prime(res)) return res;
	else return 0;
}

int main(){
	int ans = 0;	
	for(int i = 1;i <= 9;i++){
		int a[10];
		for(int j = 1;j <= i;j++){
			a[j - 1] = j;
		}
		do{
			if(check(a,i)){
				ans = max(ans,check(a,i));
			}
		}while(next_permutation(a,a + i));
	}
	cout << ans << endl;
	return 0;
}
