#include "PE.h"
vector<int> d[10][100];
int a[10];
void dfs(vector<int> now,int n){
	if(n == 6){
		int v = now[n - 2] % 100;
		for(int i = 0;i < d[a[n]][v].size();i++){
			int x = d[a[n]][v][i];
			if(x % 100 == now[0] / 100){
				vector<int> tmp = now;
				now.push_back(x);
				int sum = 0;
				for(int i = 0;i < now.size();i++){
					sum += now[i];
					printf("%d ",now[i]);
				}	
				cout << sum << endl;
			}
		}
		return;
	}
	int v = now[n - 2] % 100;
	for(int i = 0;i < d[a[n]][v].size();i++){
		int x = d[a[n]][v][i];
		vector<int> tmp = now;
		tmp.push_back(x);
		dfs(tmp,n + 1);
	}
}
int main(){
	for(int i = 1;i <= 200;i++){
		int n = i * (i + 1) / 2;
		if(n >= 1000 && n < 10000){
			d[1][n / 100].push_back(n);
		}
		n = i * i;
		if(n >= 1000 && n < 10000){
			cout << n << endl;
			d[2][n / 100].push_back(n);
		}
		n = i * (3 * i - 1) / 2;
		if(n >= 1000 && n < 10000){
			d[3][n / 100].push_back(n);
		}
		n = i * (2 * i - 1);
		if(n >= 1000 && n < 10000){
			d[4][n / 100].push_back(n);
		}
		n = i * (5 * i - 3) / 2;
		if(n >= 1000 && n < 10000){
			d[5][n / 100].push_back(n);
		}
		n = i * (3 * i - 2);
		if(n >= 1000 && n < 10000){
			d[6][n / 100].push_back(n);
		}
	}	
	for(int i = 1;i <= 6;i++)
		a[i] = i;
	do{
		for(int j = 0;j < 100;j++){
			for(int i = 0;i < d[a[1]][j].size();i++){
				int x = d[a[1]][j][i];
				vector<int> vec;
				vec.push_back(x);
				dfs(vec,2);
			}
		}
	}while(next_permutation(a + 1,a + 1 + 6));
	return 0;
}
