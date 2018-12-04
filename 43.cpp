#include "PE.h"

int a[10] = {0,1,2,3,4,5,6,7,8,9};

bool check(int i,int j,int k,int d){
	long long num = a[i - 1] * 100 + a[j - 1] * 10 + a[k - 1];
	if(num % d == 0) return true;
	return 0;
}

int main(){
	long long sum = 0;
	do{
		long long tmp = 0;
		if(a[0] == 0) continue;
		for(int i = 0;i < 10;i++){
			tmp = tmp * 10 + a[i];
		}
		if(!check(2,3,4,2)) continue;
		if(!check(3,4,5,3)) continue;
		if(!check(4,5,6,5)) continue;
		if(!check(5,6,7,7)) continue;
		if(!check(6,7,8,11)) continue;
		if(!check(7,8,9,13)) continue;
		if(!check(8,9,10,17)) continue;
		sum += tmp;
	}while(next_permutation(a,a + 10));
	cout << sum << endl;
	return 0;
}
