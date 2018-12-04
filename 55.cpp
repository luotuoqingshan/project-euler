#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

struct BigInteger{
	int a[100],tot;
	BigInteger(){
		memset(a,0,sizeof(a));
		tot = 0;
	}
	void init(int n){
		tot = 0;
		memset(a,0,sizeof(a));
		while(n > 0){
			a[++tot] = n % 10;
			n /= 10;
		}
	}
	void op(){
		int b[100];
		for(int i = 1;i <= tot;i++){
			b[i] = a[tot + 1 - i];
		}
		for(int i = 1;i <= tot;i++){
			a[i] = a[i] + b[i];
			if(a[i] >= 10) a[i] -= 10,a[i + 1]++;
		}
		if(a[tot + 1] > 0) tot++;
	}
	bool check(){
		for(int i = 1;i <= tot / 2;i++){
			if(a[i] != a[tot + 1 - i]) return false;
		}
		return true;
	}
	void print(){
		for(int i = tot;i >= 1;i--){
			printf("%d",a[i]);
		}
		puts("");
	}
};

int main(){
	BigInteger a;
	int ans = 0;
	for(int i = 1;i < 10000;i++){
		a.init(i);
		int j;
		for(j = 1;j <= 50;j++){
			a.op();
			if(a.check()) break;
		}
		if(j > 50) ans++;
	}
	cout << ans << endl;
	return 0;
}
