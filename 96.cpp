#include "PE.h"

char str[10][10];
int d[10][10];
bool vis[10];

bool check(int x,int y){
	memset(vis,0,sizeof(vis));
	for(int i = 0;i < 9;i++){
		if(vis[d[i][y]]) return false;
		if(d[i][y] != 0)vis[d[i][y]] = true;
	}
	memset(vis,0,sizeof(vis));
	for(int i = 0;i < 9;i++){
		if(vis[d[x][i]]) return false;
		if(d[x][i] != 0)vis[d[x][i]] = true;
	}
	memset(vis,0,sizeof(vis));
	int ix = x / 3, iy = y / 3;
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			int nowx = ix * 3 + i;
			int nowy = iy * 3 + j;
			if(vis[d[nowx][nowy]]) return false;
		 	if(d[nowx][nowy] != 0)vis[d[nowx][nowy]] = true;
		}
	}
	return true;
}

bool dfs(int x,int y){
	if(x == 9 && y == 0){
	/*	for(int i = 0;i < 9;i++){
			for(int j = 0;j < 9;j++){
				printf("%d",d[i][j]);
			}
			puts("");
		}*/
		return true;
	}
	if(d[x][y] != 0){
		if(y == 8) {if(dfs(x + 1,0)) return true;}
		else {if(dfs(x,y + 1)) return true;} 
	}else{
		for(int i = 1;i <= 9;i++){
			d[x][y] = i;
			if(check(x,y)){
				if(y == 8){
					if(dfs(x + 1,0)) return true;
				}else{
					if(dfs(x,y + 1)) return true;
				}
			}
			d[x][y] = 0;
		}
	}
	return 0;
}

int main(){
	freopen("p96.txt","r",stdin);
	int ans = 0;
	for(int Case = 1;Case <= 50;Case++){
		char string[55];
		scanf("%s",string);
		scanf("%s",string);
		for(int i = 0;i < 9;i++){
			scanf("%s",str[i]);
			for(int j = 0;j < 9;j++){
				d[i][j] = str[i][j] - '0';
			}
		}
		dfs(0,0);
		cout << d[0][0] << d[0][1] << d[0][2] << endl;	
		ans += d[0][0] * 100 + d[0][1] * 10 + d[0][2];
	}
	cout << ans << endl;
	return 0;
}
