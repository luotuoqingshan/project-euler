#include "PE.h"

int fac[15];

const int maxn = 1e6 + 5;


bool inq[10 * maxn];

int to(int n){
	int tmp = n;
	int sum = 0;
	while(tmp > 0){
		int digit = tmp % 10;
		tmp /= 10;
		sum += fac[digit];
	}
	return sum;
}

int Dp(int n){
	//cout << n << endl;
	if(inq[n]) return 0;	
	inq[n] = 1;
	int ans = Dp(to(n));
	inq[n] = 0;
	return ans + 1;
}

int main(){
	fac[0] = 1;
	for(int i = 1;i <= 9;i++)
		fac[i] = fac[i - 1] * i;
	int mx = 0;
	for(int i = 1;i < 1000000;i++){
		if(Dp(i) == 60) mx++;
	}
	cout << mx << endl;
	return 0;
}
