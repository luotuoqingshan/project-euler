#include "PE.h"
unordered_map<LL,int> harsh,strong,sum;

LL n;

LL bfs(){
	LL ans = 0;
	queue<LL> q;
	for(int i = 1;i <= 9;i++){
		q.push(i);
		harsh[i] = 1;
		sum[i] = i;
	}	
	while(!q.empty()){
		LL p = q.front();q.pop();
		for(int i = 0;i < 10;i++){
			if( (p * 10LL + i) % (sum[p] + i) == 0){
				if(p * 10LL + i >= n) continue;
				if(!harsh.count(p * 10LL + i)){
					harsh[p * 10LL + i] = 1;
					sum[p * 10LL + i] = sum[p] + i;
					q.push(p * 10LL + i);
				}
			}
		}
	}
	for(auto x : harsh){
		LL num = x.first;
		if(miller_rabin(num / sum[num]))
			strong[num] = 1;
	}
	for(auto x : strong){
		LL num = x.first;
		for(int j = 0;j < 10;j++){
			if(num * 10 + j >= n) continue;
			if(miller_rabin(num * 10 + j)){
				ans += num * 10 + j;
			}
		}
	}
	return ans;
}

int main(){
	cin >> n;	
	cout << bfs() << endl;
	return 0;
}
