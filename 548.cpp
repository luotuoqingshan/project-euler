#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std;




const int N = 100000000;
const int maxn = N + 5;

bool vis[maxn];int prime[maxn],tot;

void get_primes(){
    vis[1] = 1;
    tot = 0;
    for(int i = 2;i <= N;i++){
        if(!vis[i]){
            prime[tot++] = i;
        }
        for(int j = 0;j < tot && i * prime[j] <= N;j++){
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}


typedef long long LL;
map<vector<int> ,LL> mp;
map<vector<int> ,bool> inq;
const LL M = 1e16;

bool cmp(int a,int b){
    return a > b;
}

int a[20];
LL ans ;

void dfs(int i,int n,vector<int> v){
    if(i == n){
        sort(v.begin(),v.end(),cmp);
        ans += mp[v];
        return;
    }
    for(int j = 1;j <= a[i];j++){
        vector<int> tmp = v;
        tmp.push_back(j);
        dfs(i + 1,n,tmp);
    }
    dfs(i + 1,n,v);
}

void solve(vector<int> v){
    ans = 0;
    for(int i = 0;i < v.size();i++){
        a[i] = v[i];
    }
    vector<int> empty(0);
    dfs(0,v.size(),empty);
    mp[v] = ans;
}

void init(){
    vector<int> v;
    mp[v] = 1;
    queue<pair<vector<int> ,LL > >q;
    v.push_back(1);
    q.push(make_pair(v,2));
    inq[v] = 1;
    while(!q.empty()){
        pair<vector<int> , LL > p = q.front();q.pop();
        vector<int> tmp = p.first;LL num = p.second;
        solve(tmp);
        for(int i = 0;i < tmp.size();i++){
            vector<int> tmp1 = tmp;
            tmp1[i]++;
            LL num1 = num * prime[i];
            if(i > 0){
                if(tmp1[i] > tmp1[i - 1]) continue;
            }
            if(num1 > M) continue;
            if(!inq[tmp1]){
                inq[tmp1] = true;
                q.push(make_pair(tmp1,num1));
            }
        }
        vector<int> tmp1 = tmp;LL num1 = num * prime[tmp.size()];tmp1.push_back(1);
        if(num1 > M) continue;
        if(!inq[tmp1]){
            inq[tmp1] = true;
            q.push(make_pair(tmp1,num1));
        }
    }
}

LL cal(LL num){
    LL tmp = num;
    vector<int> v;
    for(int i = 0;i < tot && 1LL * prime[i] * prime[i] <= num;i++){
        if(tmp % prime[i] == 0){
            int m = 0;
            while(tmp % prime[i] == 0){
                tmp /= prime[i];
                m++;
            }
            v.push_back(m);
        }
    }
    if(tmp > 1) v.push_back(1);
    sort(v.begin(),v.end(),cmp);
    return mp[v];
}

int main(){
	for(int i = 1;i <= 100000000;i++){
		if(cal(i) == 252){
			cout << i << endl;
			break;
		}
	}
   /* get_primes();
    init();
    LL sum = 0;
    for(auto v : mp){
        LL num = v.second;
        if(num > M) continue;
        if(cal(num) == num){
            sum += num;
            cout << num << endl;
        }
    }
    cout << "sum = " << sum << endl;*/
    cout << 1476496720219841378LL - 365635994747142144LL - 84372124269019136LL - 967798930861457408LL - 46545625738641408LL - 1 << endl;
    return 0;
}

/*
 *
 1
1
48
29808
2496
1280
28672
454656
2342912
57409536
34753216512
11534336
218103808
5806013294837760
583041810432
73014444032
2624225017856
467515780104192
1305670057984
1014849232437248
46545625738641408
4446425022726144
404620279021568
967798930861457408
84372124269019136
365635994747142144
sum = 1476496720219841378
 */
