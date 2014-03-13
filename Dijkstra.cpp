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


//复杂度O(ElogV),用优先队列

