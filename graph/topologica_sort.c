#include <stdio.h>

int n,m;
int g[50][50];
int indeg[50],queue[50];

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u][v]=1;
        indeg[v]++;
    }

    int front=0,rear=0;
    for(int i=1;i<=n;i++)
        if(indeg[i]==0)
            queue[rear++]=i;

    while(front<rear){
        int u=queue[front++];
        printf("%d ",u);
        for(int v=1;v<=n;v++){
            if(g[u][v]){
                indeg[v]--;
                if(indeg[v]==0)
                    queue[rear++]=v;
            }
        }
    }
    return 0;
}
