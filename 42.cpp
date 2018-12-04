#include "PE.h"


int a[10000];

void init(){
	for(int i = 1;i < 10000;i++){
		a[i] = i * (i + 1) / 2;
	}
}

int main(){
	init();
	freopen("p042_words.txt","r",stdin);
	int ans = 0;
	int sum = 0;
	char c;
	while((c = getchar()) != EOF){
		if(c == '"'){
			if(sum == 0) continue;
			else{
				int i = lower_bound(a + 1,a + 10000,sum) - a;
				if(sum == a[i]) ans++;
			}
		}else{
			if('A' <= c && c <= 'Z'){
				sum = sum + c - 'A' + 1;
			}else{
				sum = 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
