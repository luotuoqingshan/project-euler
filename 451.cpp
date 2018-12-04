#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 2e7;

int ans[N + 5];

int cal(int x){
	for(int i = x - 2;i >= 1;i--){
		if(1LL * i * i % x == 1){
			return i;
		}
	}
}

int main(){
	for(int i = 3;i <= 15;i++){
		cout << cal(i) << endl;
	}

	return 0;
}
