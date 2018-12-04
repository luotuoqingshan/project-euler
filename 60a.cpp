#include <cstdio>  
#include <iostream>  
#include <algorithm>  
#include <cstring>  
#include <cmath>  
#include <vector>  
using namespace std;  
bool tag[1000001];  
int p[1000001];  
int cnt;  
void get_prime()  
{  
    cnt = 0;  
    tag[1] = 1;  
    for (int i = 2; i < 50000; i++)  
    {  
        if (!tag[i])  
        p[cnt++] = i;  
        for (int j = 0; j < cnt && p[j] * i < 50000; j++)  
        {  
            tag[i*p[j]] = 1;  
            if (i % p[j] == 0)  
            break;  
        }  
    }  
}  
bool isprime(long long x)  
{  
    if(x < 50000) return !tag[x];  
    long long m = (long long)sqrt(x * 1.0);  
    for(int i = 0; i < cnt && m >= p[i]; i++)  
        if(x % p[i] == 0) return false;  
    return true;  
}  
int getwei(long long x)  
{  
    int cnt = 0;  
    while(x)  
    {  
        x /= 10;  
        cnt++;  
    }  
    return cnt;  
}  
long long get(long long a, long long b)  
{  
  
    int wb = getwei(b);  
    for(int i = 0; i < wb; i++) a *= 10LL;  
    return a + b;  
}  
vector<int>g[5555];  
int main()  
{  
    get_prime();  
    for(int i = 0; i < cnt; i++)  
        for(int j = i + 1; j < cnt; j++)  
            if(isprime(get(p[i], p[j])) && isprime(get(p[j], p[i])))  
                g[i].push_back(j);  
    int ans = 11111111;  
    for(int a = 0; a < cnt; a++)  
    {  
        for(int ta = 0; ta < g[a].size(); ta++)  
        {  
            int b = g[a][ta];  
            for(int tb = 0; tb < g[b].size(); tb++)  
            {  
                int c = g[b][tb];  
                if(!isprime(get(p[c], p[a]) )|| !isprime(get(p[a], p[c]))) continue;  
                for(int tc = 0; tc < g[c].size(); tc++)  
                {  
                    int d = g[c][tc];  
                    if(!isprime(get(p[d], p[a])) || !isprime(get(p[a], p[d]))) continue;  
                    if(!isprime(get(p[d], p[b])) || !isprime(get(p[b], p[d]))) continue;  
                    for(int td = 0; td < g[d].size(); td++)  
                    {  
                        int e = g[d][td];  
                        if(!isprime(get(p[e], p[a])) || !isprime(get(p[a], p[e]))) continue;  
                        if(!isprime(get(p[e], p[b])) || !isprime(get(p[b], p[e]))) continue;  
                        if(!isprime(get(p[e], p[c])) || !isprime(get(p[c], p[e]))) continue;  
                        ans = min(ans, p[a] + p[b] + p[c] + p[d] + p[e]);  
                        printf("%d %d %d %d %d\n", p[a], p[b], p[c], p[d], p[e]);  
                    }  
                }  
            }  
        }  
    }  
    printf("%d\n", ans);  
    return 0;  
}  
