/*Time:2014.3.26
  Problem:寻找覆盖一个范围的最小区间数
  Tag:贪心
  *
*/

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAXN=1000000;

int N,END,ans=0;
pair<int,int> range[MAXN];


void solve()
{
	int i=0;
	int start=0,end=0;

	while(i<N)
	{
		if(range[i].first<=start+1){
			if(range[i].second>end)  //找最大
				end=range[i].second;
			i++;
		}
		
		else{
			if(range[i].first>end+1){  //后面没有能连上的
				ans=0;
				break;
			}
			ans++;     //更新
			start=end;
		}
		if(end==END){
			ans++;
			break;
		}
	}
	if(end!=END)  //到最后的点也没包含区间
		ans=0;
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&END);
	for(int i=0;i<N;i++)
		scanf("%d %d",&(range[i].first),&(range[i].second));

	sort(range,range+N);

	if(range[0].first>1)
		ans=0;
	else solve();

	if(ans==0)
		printf("%d",-1);
	else printf("%d",ans);
	return 0;
}

	