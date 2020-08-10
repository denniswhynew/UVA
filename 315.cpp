#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N 100
using namespace std;
int aaa[N][N],sum;
char ch[2000],*m,*op;
int dis[N],low[N],n,now;

void dfs(int p,int q)
{
    low[q]=dis[q]= ++now;
    int child=0;
    bool ap=0;
    for(int i=1;i<=n;i++)
        if(aaa[q][i]&&i!=p)
        {
            if(dis[i])
                low[q]=min(low[q],dis[i]);
            else
            {
                child++;
                dfs(q,i);
                low[q]=min(low[q],low[i]);
                if(low[i]>=dis[q])
                    ap=1;
            }
        }
    if(p==q&&child>1||p!=q&&ap==1)
        sum++;
}

int main()
{
    while(cin>>n&&n!=0)
    {
        for(int i=1;i<=n;i++)
            dis[i]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                aaa[i][j]=0;
        now=sum=0;
        cin.get();
        while(gets(ch))
        {
            m=strtok(ch," ");
            int t1,t2;
            t1=atoi(m);
            if(t1==0)
                break;
            op=strtok(NULL," ");
            while(op!=NULL)
            {
                t2=atoi(op);
                aaa[t1][t2]=aaa[t2][t1]=1;
                op=strtok(NULL," ");
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==0)
                dfs(i,i);
        }
        cout<<sum<<endl;
    }
}
