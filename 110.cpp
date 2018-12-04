#include "PE.h"

const int maxn = 1e6 + 5;

struct num{
	LL v;
	LL div;
	vector<int> d;	
	bool operator < (const num & rhs) const{
		if(div == rhs.div) return v > rhs.v;
		return div < rhs.div;	
	}
	num(LL vv = 0,LL ddiv = 0,vector<int> dd = vector<int>()):v(vv),div(ddiv){
		d = dd;
	}
};

priority_queue<num> pq;

vector<int> primes = get_primes(10000000);

map<num,bool> mp;
void init(){
	LL ans = 1e18;
	pq.push(num(1,1,vector<int>()));
	while(!pq.empty()){
		num p = pq.top();pq.pop();
		if(mp.count(p)) continue;
		mp[p] = true;
		LL nowv = p.v;
		LL temp = p.div; 
		vector<int> nowd = p.d;
		if(nowv >= ans) continue;
		if(temp >= 8000000){
				ans = min(ans,nowv);	
				continue;
		}
		for(int i = 0;i < nowd.size();i++){
			vector<int> temp1 = nowd;
			temp1[i] = nowd[i] + 1;	
			LL tempv = nowv * primes[i];
			pq.push(num(tempv,temp / (2 * nowd[i] + 1) * (2 * nowd[i] + 3),temp1));
		}
		vector<int> temp1 = nowd;
		LL tempv = nowv * primes[nowd.size()];		
		temp1.push_back(1);
		pq.push(num(tempv,temp * 3,temp1));
	}
	cout << ans << endl;
}

int main(){
	//init();
	for(int i = 1;i <= 25;i++){
		cout << i * (i + 1) / 2 << endl;
	}
	return 0;
}
