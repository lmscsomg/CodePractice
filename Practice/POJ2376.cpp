/*Time:2014.3.26
  Problem:Ѱ�Ҹ���һ����Χ����С������
  Tag:̰��
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
			if(range[i].second>end)  //�����
				end=range[i].second;
			i++;
		}
		
		else{
			if(range[i].first>end+1){  //����û�������ϵ�
				ans=0;
				break;
			}
			ans++;     //����
			start=end;
		}
		if(end==END){
			ans++;
			break;
		}
	}
	if(end!=END)  //�����ĵ�Ҳû��������
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

	