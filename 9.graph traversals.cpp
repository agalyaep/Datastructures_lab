#include<stdio.h>
#include<stdlib.h>
int source,v,e,time,visited[20],g[20][20];
void dfs(int i)
{
    int j;
    visited[i]=1;
    printf("%d->",i+1);
    for(j=0;j<v;j++)
    {
        if(g[i][j]==1 && visited[j]==0)
        dfs(j);
    }
}
int main()
{
    int i,j,v1,v2;
    printf("\t\t\tgraphs\n");
    printf("enter the number of edges:");
    scanf("%d",&e);
    printf("enter the number of vertices:");
    scanf("%d",&v);
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        g[i][j]=0;
    }
    for(i=0;i<e;i++)
    {
        printf("enter the edges (format: v1 v2):");
        scanf("%d%d",&v1,&v2);
        g[v1-1][v2-1]=1;
    }
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
        printf("%d",g[i][j]);
        }
        printf("\n");
    }
    printf("enter the source:");
    scanf("%d",&source);
    dfs(source-1);
    return 0;
}
/*output
                        graphs
enter the number of edges:3
enter the number of vertices:3
enter the edges (format: v1 v2):1 2
enter the edges (format: v1 v2):1 3
enter the edges (format: v1 v2):2 3
011
001
000
enter the source:1
1->2->3->

