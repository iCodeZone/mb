#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<bitset>

#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>

#include<iomanip>
#include<iostream>

#define debug cout<<"aaa"<<endl
#define d(a) cout<<a<<endl
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson l,mid,root<<1
#define rson mid+1,r,root<<1|1
#define MIN_INT (-2147483647-1)
#define MAX_INT 2147483647
#define MAX_LL 9223372036854775807i64
#define MIN_LL (-9223372036854775807i64-1)
using namespace std;

const int N = 1000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int n,m,dis[N];

struct node{//邻接表结点 
	int to,w;//终点和权值
	node(){}
	node(int to,int w):to(to),w(w){}
	bool operator< (const node &a) const{
		if(w==a.w) return to<a.to;
		else return w>a.w;
	}
};

vector<node> edge[N*N];

void Dijkstra(int s){
	for(int i=0;i<=n;i++) dis[i]=MAX_INT;
	dis[s]=0;
	priority_queue<node> q;
	q.push(node(s,dis[s]));
	while(!q.empty()){
		node x=q.top();q.pop();
		for(int i=0;i<edge[x.to].size();i++){
			node y=edge[x.to][i];
			if(dis[y.to]>x.w+y.w){
				dis[y.to]=x.w+y.w;
				q.push(node(y.to,dis[y.to])); 
			}
		}
	} 
}

int main(){
	int u,v,w;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<=n;i++){
			edge[i].clear();
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&u,&v,&w);
			edge[u].pb(node(v,w));
			edge[v].pb(node(u,w));
		}
		for(int i=1;i<=n;i++){
			Dijkstra(i);
			cout<<i<<":"<<endl;
			for(int i=1;i<=n;i++){
				cout<<i<<" "<<dis[i]<<endl;
			}
		}
		
	}
	return 0;
}
/*
debug
8 12
5 8 29
6 1 12
8 3 11
1 2 4
3 1 22
4 3 17
7 4 25
6 5 9
8 7 7
1 6 9
3 2 19
6 7 4
*/
