#include "PE.h"
#include <string>
using namespace std;
int tot;
string s[1000005];
queue<string> q;
void init(int n,int m){
	for(int i = 3;i <= n;i++){
		for(int j = 1;j <= tot;j++){
			q.push(s[j]);
		}
		tot = 0;
		while(!q.empty()){
			string p = q.front();
			q.pop();
			for(int i = 0;i < p.length();i++){
				p[i] = p[i] + 1;
			}
			reverse(p.begin(),p.end());
			for(int i = 1;i < p.length();i++){
				string tmp1 = p.substr(i,p.length() - i); reverse(tmp1.begin(),tmp1.end());
				string tmp = p.substr(0,i) + 'A'  + tmp1;
				s[++tot] = tmp;
			}
		}
	}
	sort(s + 1,s + 1 + tot);
	cout << s[m] << endl;
}

int main(){
	tot = 0;
	s[++tot] = "BA";
	int n,m;
	cin >> n >> m;
	init(n,m);
	return 0;
}
