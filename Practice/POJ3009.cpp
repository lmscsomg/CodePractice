#include<iostream>
using namespace std;

#define INF 1000000
int map[21][21],step,w,h,start_x,start_y,res;
int direction[4][2]={
	{0,-1},{1,0},{0,1},{-1,0}
};


void dfs(int x,int y)
{
	step++;
	if(step>10 || step>=res)
		return ;
	int a,b;
	for(int i=0;i<4;i++)
	{
		a=x+direction[i][0];
		b=y+direction[i][1];
		if(map[a][b]==1 || a<0 || a>=h || b<0 || b>=w)//一开始出界或遇到石头
			continue;
		while(map[a][b]==2 || map[a][b]==0)//继续飞
		{
			a+=direction[i][0];
			b+=direction[i][1];
			if(a<0 || a>=h || b<0 || b>=w)
				break;  
		}
		if(a<0 || a>=h || b<0 || b>=w)//飞出去了，直接退出
			continue;

		if(map[a][b]==3)
		{
			res=step;
			//return;
		}
		if(map[a][b]==1)
		{
			map[a][b]=0;
			dfs(a-direction[i][0],b-direction[i][1]); //继续搜索
			step--;  //回溯继续搜索
			map[a][b]=1;
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	while(cin>>w>>h && w && h)
	{
		memset(map,0,sizeof(map));
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>map[i][j];
				if(map[i][j]==2){
					start_x=i;
					start_y=j;
				}
			}
		}
		res=INF;
		step=0;//细节
		dfs(start_x,start_y);
		if(res>10)
			cout<<-1<<endl;
		else
			cout<<res<<endl;
	}
	system("pause");
	return 0;
}

					