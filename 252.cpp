#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
#define maxn 510
struct point{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
    point operator+(const point&a)const{return point(x+a.x,y+a.y);}
    point operator-(const point&b)const{return point(x-b.x,y-b.y);}
    int operator*(const point&a)const{return x*a.y-y*a.x;}
    int norm()const{return x*x+y*y;}
    int operator <(const point&a)const{return (*this)*a>0||((*this)*a==0&&norm()<a.norm());}
    void out(){printf("x:%d y:%d\n",x,y);}
    void in(){scanf("%d%d",&x,&y);}
};
//bool cmp(const point&a,const point&b )
//{
//    return a*b>0||a*b==0&&a.norm()<b.norm();
//}
int n;
point src[maxn];
point dat[maxn];
int f[maxn][maxn];

int scan(int tot)
{
    int res=0;
    memset(f,0,sizeof f);
    for(int i=1;i<tot;i++ )
    {
        int j=i-1;
        while(j>=0&&dat[i]*dat[j]==0)j--;
        bool flag= j==i-1;//判断共线
        while(j>=0)
        {
            int area=dat[j]*dat[i];
            int k=j-1;
            while(k>=0&&(dat[j]-dat[i])*(dat[k]-dat[j])>0)k--;
            if(k>=0)area+=f[j][k];
            if(flag)f[i][j]=area;
            res=max(res,area);
            j=k;
        }
        if(flag)for(int j=1;j<i;j++)
            f[i][j]=max(f[i][j],f[i][j-1]);
    }
    return res;
}
int solve(){
    int res=0;
    for(int i=0;i<n;i++){
        int m=0;
        for(int j=0;j<n;j++)
            if(src[j].y>src[i].y||(src[j].y==src[i].y&&src[j].x>=src[i].x))
            dat[m++]=src[j]-src[i];
       // printf("m:%d i:%d\n",m,i);

        //dat[0].out();
        sort(dat,dat+m);
        //dat[0].out();
        res=max(res,scan(m));
    }
    return res;
}

long long S[maxn * 2];int T[maxn * 2];
int main(){
	n = 500;
	S[0] = 290797;
	for(int i = 1;i <= 1000;i++){
		S[i] = (S[i - 1] * S[i - 1]) % 50515093;
		T[i] = S[i] % 2000 - 1000;
	}
	for(int i = 0;i < 500;i++)
		src[i].x = T[i * 2 + 1],src[i].y = T[i * 2 + 2];
        double ans=(double)solve()/2.0;
        printf("%.1f\n",ans);
    return 0;
}
