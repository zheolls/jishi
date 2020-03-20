#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define INF 10000000
using namespace std;
struct E
{
    int value;
    int v1;
    int v2;
}*edgelist;
struct V
{
    int index;
    int d = INF;
    bool visited = false;
    vector<E*> edges;
}*vlist;


int main(){
    int n,m,s,u,v,w,l;
    cin>>n>>m>>s;
    s--;
    vlist=new V[n];
    edgelist=new E[m];
    auto minn = [](int x,int y) -> int{ return x>y?y:x;};
    for (int i = 0; i < n; i++){
        vlist[i].index=i;
        vlist[i].d = ( i == s ? 0 : INF );
    }
    
    for (int i = 0; i < m; i++)
    {
        cin>>u>>v>>w;
        u--;v--;
        edgelist[i].v1=u;
        edgelist[i].v2=v;
        edgelist[i].value=w;
        vlist[u].edges.push_back(edgelist+i);
        vlist[v].edges.push_back(edgelist+i);
    }
    cin>>l;
    for (int i = 0; i < n; i++)
    {
        
        int x,min=INF;

        for (int j = 0; j < n; j++)
            if (!vlist[j].visited && vlist[j].d <= min){
                min = vlist[j].d;
                x=j;
            }
        vlist[x].visited = true;
        for (auto k=vlist[x].edges.begin();k < vlist[x].edges.end();k++)
        {
            V*  p=((**k).v1==x ? vlist+(**k).v2 : vlist + (**k).v1);
            (*p).d = minn((*p).d , (**k).value+vlist[x].d);
        }
    }
    for (auto i = 0; i < n; i++)
    {
        cout<<i+1<<":"<<vlist[i].d<<endl;
    }
    int count=0;
    for (int i = 0; i < n; i++)
        if (vlist[i].d==l)
            count++;
    
    for (int i = 0; i < m; i++)
    {
        if ((vlist[edgelist[i].v1].d-l)*(vlist[edgelist[i].v2].d-l) < 0) count++;
        else if (vlist[edgelist[i].v1].d < l && vlist[edgelist[i].v2].d < l )
        {
            if (2 * l < edgelist[i].value + vlist[edgelist[i].v1].d + vlist[edgelist[i].v2].d)
            {
                count+=2;
            }
            else if (2 * l == edgelist[i].value + vlist[edgelist[i].v1].d + vlist[edgelist[i].v2].d)
            {
                count++;
            }  
        }
        else if (vlist[edgelist[i].v1].d == l || vlist[edgelist[i].v2].d == l)
        {
            count+=(vlist[edgelist[i].v1].d + edgelist[i].value > l && vlist[edgelist[i].v1].d < l );
            count+=(vlist[edgelist[i].v2].d + edgelist[i].value > l && vlist[edgelist[i].v2].d < l );
        }        
    }
    cout<<count<<endl;

}