#include<iostream>
#include<queue>
using namespace std;

struct Node{
	int x,y,t;
};

int vit[330][330];
int dirx[5]={0,0,-1,0,1};
int diry[5]={0,-1,0,1,0};
int ans,num,x,y,t;

queue<Node> que;
int bfs()
{	
	Node temp,now,nx;
	if(vit[0][0]==0)
		return -1;
	if(vit[0][0]==-1)
		return 0;
	temp.x=temp.y=temp.t=0;
	que.push(temp);
	while(!que.empty())
	{
		now=que.front();
		que.pop();
		for(int j=1;j<5;j++){
			nx.x=now.x+dirx[j];
			nx.y=now.y+diry[j];
			nx.t=now.t+1;
			if(nx.x<0 || nx.y<0)
				continue;
			if(vit[nx.x][nx.y]==-1)	
				return nx.t;
			if(nx.t>=vit[nx.x][nx.y])
				continue;
			vit[nx.x][nx.y]=0;//和上句结合看，看出是访问过，但不能赋值-1
			que.push(nx);
			}
	}
	return -1;
}

int main()
{	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	memset(vit,-1,sizeof(vit));
	cin>>num;
	while(num--){
		cin>>x>>y>>t;
		int xx,yy;
		for(int i=0;i<5;i++){
			xx=x+dirx[i];
			yy=y+diry[i];
			if(xx<0 || yy<0)
				continue;
			if(vit[xx][yy]==-1)
				vit[xx][yy]=t;
			else vit[xx][yy]=min(vit[xx][yy],t);
		}
	}
	cout<<bfs()<<endl;
	return 0;
}
