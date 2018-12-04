#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct card{
	int n,c;
	card(){}
	card(int n,int c):n(n),c(c){}
	bool operator < (const card & rhs) const{
		return n < rhs.n || (n == rhs.n && c < rhs.c);
	}
	void read(){
		char s[5];
		scanf("%s",s);
		if(s[0] >= '2' && s[0] <= '9') n = s[0] - '0';
		if(s[0] == 'A') n = 14;
		if(s[0] == 'T') n = 10;
		if(s[0] == 'J') n = 11;
		if(s[0] == 'Q') n = 12;
		if(s[0] == 'K') n = 13;
		if(s[1] == 'H') c = 3;
		if(s[1] == 'C') c = 1;
		if(s[1] == 'D') c = 2;
		if(s[1] == 'S') c = 4;
	}
};

struct s{
	card a[5];
	void read(){
		for(int i = 0;i < 5;i++){
			a[i].read();
		}
	}
	int pair(){
		int cnt[15];
		memset(cnt,0,sizeof(cnt));
		for(int i = 0;i < 5;i++){
			cnt[a[i].n]++;
		}
		int ret = 0;
		for(int i = 2;i <= 14;i++){
			if(cnt[i] == 2) ret++;
		}
		return ret;
	}
	int three(){
		int cnt[15];
		memset(cnt,0,sizeof(cnt));
		for(int i = 0;i < 5;i++){
			cnt[a[i].n]++;
		}
		int ret = 0;
		for(int i = 2;i <= 14;i++){
			if(cnt[i] == 3) ret = i;
		}
		return ret;
	}
	int four(){
		int cnt[15];
		memset(cnt,0,sizeof(cnt));
		for(int i = 0;i < 5;i++){
			cnt[a[i].n]++;
		}
		int ret = 0;
		for(int i = 2;i <= 14;i++){
			if(cnt[i] == 4) ret = i;
		}
		return ret;
	}
	bool flush(){
		bool flag = true;
		for(int i = 1;i < 5;i++){
			if(a[i].c != a[0].c) return 0;
		}
		return 1;
	}
	bool straight(){
		sort(a,a + 5);
		for(int i = 1;i < 5;i++){
			if(a[i].n != a[i - 1].n + 1) return 0;
		}
		return 1;
	}
	int type(){
		if(straight() && flush()) return 9;
		if(four()) return 8;
		if(three() && pair()) return 7;
		if(flush()) return 6;
		if(straight()) return 5;
		if(three()) return 4;
		if(pair() == 2) return 3;
		if(pair() == 1) return 2;
		return 1;
	}
	int val(){
		sort(a,a + 5);
		int t = type();
		if(t == 9) return a[4].n;
		if(t == 5) return a[4].n;
		if(t == 6 || t == 1){
			int ret = 0;
			for(int i = 4;i >= 0;i--){
				ret = ret * 20 + a[i].n;
			}
			return ret;
		}	
		{
			int ret = 0;
			int cnt[20];
			memset(cnt,0,sizeof(cnt));
			for(int i = 0;i < 5;i++){
				cnt[a[i].n]++;
			}
			for(int j = 14;j >= 2;j--){
				if(cnt[j] == 4){
					ret = ret * 20 + j;
				}
			}
			for(int j = 14;j >= 2;j--){
				if(cnt[j] == 3){
					ret = ret * 20 + j;
				}
			}
			for(int j = 14;j >= 2;j--){
				if(cnt[j] == 2){
					ret = ret * 20 + j;
				}
			}
			for(int j = 14;j >= 2;j--){
				if(cnt[j] == 1){
					ret = ret * 20 + j;
				}
			}
			return ret;
		}
	}
	bool operator > ( s & rhs) {
		return type() > rhs.type() || (type() == rhs.type() && val() > rhs.val());
	}
};

int main(){
	int t;
	cin >> t;
	int cnt = 0;
	while(t--){
		s a,b;
		a.read(),b.read();
		if(a > b){
			cnt++;
		}
	}	
	cout << cnt << endl;
	return 0;
}
