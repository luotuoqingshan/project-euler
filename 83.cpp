#include "PE.h"
int a[85][85];
int d[85][85];

bool inq[85][85];
int dx[4] = {0,-1,0,1},dy[4] = {1,0,-1,0};
bool in(int x,int y){
	return 1 <= x && x <= 80 && 1 <= y && y <= 80;
}
void solve(){
	memset(d,0x3f3f3f3f,sizeof(d));
	d[1][1] = a[1][1];
	queue<pair<int,int> > q;
	q.push(make_pair(1,1));
	inq[1][1] = true;
	while(!q.empty()){
		pair<int,int> p = q.front();q.pop();
		int x = p.first;
		int y = p.second;
		inq[x][y] = false;
		for(int i = 0;i < 4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(in(nx,ny) && d[nx][ny] > d[x][y] + a[nx][ny]){
				d[nx][ny] = d[x][y] + a[nx][ny];
				if(!inq[nx][ny]){
					inq[nx][ny] = 1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	cout << d[80][80] << endl;
}
int main(){
	freopen("p083_matrix.txt","r",stdin);
	
	for(int i = 1;i <= 80;i++){
		for(int j = 1;j <= 80;j++){
			int d = 0;
			char c;
			while(true){
				c = getchar();
				if(c == ',' || c == EOF || c == '\n') break;
				d = d * 10 + c - '0';
			}
			a[i][j] = d;
		}
	}
	solve();
	return 0;
}
