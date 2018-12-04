#include "PE.h"
const int N = 1e6 + 5;
long long a[N];

map<long long,bool> b,c;

int main(){
	for(int i = 1;i < N;i++){
		a[i] = 1LL * i * (i + 1) / 2;
		long long x = 1LL * i * (3 * i - 1) / 2;
		long long y = 1LL * i * (2 * i - 1);
		b[x] = 1;c[y] = 1;
	}
	for(int i = 2;i < N;i++){
		if(b.count(a[i]) && c.count(a[i])){
			cout << a[i] << endl;
		}
	}
	return 0;
}

