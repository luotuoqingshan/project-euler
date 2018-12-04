#include "PE.h"

int gcd(int a,int b){
	return b == 0 ? a : gcd(b,a % b);
}

int main(){
	int cnt = 0;
	for(int d = 4;d <= 12000;d++){
		for(int n = d / 3;n <= (d + 1) / 2;n++){
			if(gcd(n,d) > 1) continue;
			if(d > 2 * n && d < 3 * n) cnt++;
		}
	}
	cout << cnt << endl;	
	return 0;
}
