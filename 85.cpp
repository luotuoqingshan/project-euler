#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a[10000];

void init(){
	for(int i = 0;i <= 9000;i++){
		a[i] = i * (i + 1) / 2;
	}
}

int main(){
	init();
	int diff = 1e9;
	int ans = 0;
	for(int i = 1;i <= 2000;i++){
		for(int j = 1;j <= 2000;j++){
			if((abs(a[i] * a[j] - 2000000) < diff)){
				diff = abs(a[i] * a[j] - 2000000);
				ans = i * j;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
