/*
 Time:2014.3.15
 Tag:MST(Minimum Spanning Tree),Prim
 Description:最小生成树之Prim算法(类似Dijkstra算法)
*/

int cost[MAX_V][MAX_V];
int minicost[MAX_V]; //minicost[u]表示已经生成的树到u的最小距离
bool used[MAX_V];
int V;

int Prim()
{
  fill(minicost,minicost+V,INF);
  fill(used,used+V,false);
  
  minicost[0]=0;
  int res=0;

  while(true){
    int v=-1;
    for(int u=0;u<V;u++){
      if(!used[u] && (v==-1 || minicost[u]<minicost[v]))
	 v=u;
    }

    if(v==-1)
      break;

    used[v]=true;
    res+=minicost[v];

    for(int u=0;u<V;u++)
      minicost[u]=min(minicost[u],cost[v][u]);
  }
  return res;
}



