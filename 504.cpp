#include "PE.h"

int gcd(int a,int b){
	return b == 0 ? a : gcd(b,a % b);
}

bool vis[10000005];

void init(){
	for(int i = 1;i * i < 10000005;i++){
		vis[i * i] = 1;
	}
}

int cal(int m){
	int ans = 0;
	for(int a = 1;a <= m;a++){
		for(int b = 1;b <= m;b++){
			for(int c = 1;c <= m;c++){
				for(int d = 1;d <= m;d++){
					int S = (a + c) * (b + d);
					int B = gcd(a,b) + gcd(a,d) + gcd(c,b) + gcd(c,d);
					int A = (S - B + 2) / 2;
					if(vis[A]) ans++;
				}
			}
		}
	}
	return ans;
}

int main(){
	init();
	cout << cal(100) << endl;
	return 0;
}
