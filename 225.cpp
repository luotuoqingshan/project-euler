#include "PE.h"

map<pair<int,pair<int,int> > ,bool> vis;

#define mp make_pair 
bool check(int x){
	vis.clear();
	int a = 1,b = 1,c = 1;
	vis[mp(1,mp(1,1))] = true;
	while(true){
		int temp = (c + a + b) % x;
		if(temp == 0) return 0;
		a = b,b = c,c = temp;
		if(vis.count(mp(a,mp(b,c)))) return 1;
		vis[mp(a,mp(b,c))] = true;
	}
}

int main(){
	int cnt = 0;
	for(int i = 1;;i += 2){
		if(check(i)){
			cnt++;
			cout << cnt << " " << i << endl;
			if(cnt == 124)
				break;
		}
	}
	return 0;
}
