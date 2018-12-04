#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
int a[10000],tot;
int main(){
	freopen("p059_cipher.txt","r",stdin);
	char c;
	while((c = getchar()) != EOF){
		if(c > '9' || c < '0') continue;
		int d = c - '0';
		while(true){
			c = getchar();
			if(c > '9' || c < '0'){
				a[++tot] = d;
				break;
			}else{
				d = d * 10 + c - '0';
			}
		}
	}
	cout << tot << endl;
	return 0;
}
