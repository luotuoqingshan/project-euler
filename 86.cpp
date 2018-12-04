#include "PE.h"

set<pair<int,int> > s;
set<pair<int,pair<int,int> > > ss;

int check(int m){
	ss.clear();
	s.clear();
	for(int i = 1;2 * i <= m * 2;i++){
		for(int j = 1;j < i && 2LL * i * j <= m * 2;j++){
			int a = i * i - j * j;
			int b = 2LL * i * j;
			if(a > m * 2) continue;
			if(a > b) swap(a,b);
			for(int k = 1;k * a <= 2 * m && k * b <= 2 * m;k++)
			s.insert(make_pair(k * a,k * b));
		}
	}
//	for(auto p:s){
//		cout << p.first << " " << p.second << endl;
//	}
	for(auto p:s){
		int a = p.first;
		if(a > m) continue;
		for(int b = 1;b < p.second;b++){
			int c = p.second - b;
			if(c > m || b > m) continue;
			if(a >= b  && b >= c)
			ss.insert(make_pair(a,make_pair(b,c)));
		}
	}
	for(auto p:s){
		int a = p.second;
		if(a > m) continue;
		for(int b = 1;b < p.first;b++){
			int c = p.first - b;
			if(c > m || b > m) continue;
			if(a >= b && b >= c)
			ss.insert(make_pair(a,make_pair(b,c)));
		}
	}
//	for(auto p:ss){
//		cout << p.first << " " << p.second.first << " " << p.second.second << endl;
//	}
	return ss.size();
}

int main(){
	int n;
	for(int i = 1800;i <= 2000;i++){
		if(check(i) > 1000000){
			cout << i << endl;
			break;
		}
	}
	return 0;
}
