/*Time:2012.3.13
 *Tag:Dijkstra
 *Description:单源最短路径
 *
 */


//复杂度O(V^2)
int cost[MAX_V][MAX_V];  //各边权值
int d[MAX_V];  //d[u]表示从起始点到u的最短距离
bool used[MAX_V];
int V;  //顶点数

void Dijkstra(int s){
  fill(d,d+V,INF);
  fiil(use,used+V,false);
  d[s]=0;
  
  while(true){
    int v=-1;
    for(int u=0;u<V;u++){
      if(!used[u] && (v==-1 || d[u]<d[v]))
	v=u;
    }
    //所有点均访问过
    if(v==-1)
      break;

    used[v]=true;
    //更新
    for(int u=0; u<V; u++)
      d[u]=min(d[u],d[v]+cost[v][u]);
  }
}


//优化，复杂度O(ElogV)
struct edge{
  int to;
  int cost;
};

typedef pair<int, int> P; //first是最短距离，second是顶点编号

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void Dijkstra(int s){
  priority_queue<P,vetor<P>, greater<P> > que;

  fill(d,d+V,INF);
  d[s]=0;
  que.push(P(0,s));
  while(!que.empty()){
    P p=que.top();
    que.pop();
    int v=p.second;
    if(d[v]<p.first)
      continue;
    for(int i=0;i<G[v].size();i++){
      edge e=G[v][i];
      if(d[e.to] > d[v]+e.cost){
	d[e.to]=d[v]+e.cost;
	que.push(P(d[e.to],e.to);
      }
    }
  }
}
