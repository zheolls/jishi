#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct point
{
    int x,y;
}beginp,endp;
int minstep=1000000;
int **map;
int n,m;
vector<point> plist1,plist2,stack;
int nextp[8]={-1,0,0,1,1,0,0,-1};

bool is_in_stack(point p){
    for (auto i = stack.begin(); i < stack.end(); i++)
        if ((*i).x==p.x && (*i).y==p.y) return true;
    return false;
}

int DFS(point p,int depth){
    if (p.x==endp.x && p.y==endp.y){
        if (depth < minstep)
        {
            minstep = depth;
        }
        return depth;
    }
    int flag=0;
    for (int i = 0; i < 4; i++)
    {
        point temp;
        temp.x = p.x + nextp[2*i];
        temp.y = p.y + nextp[2*i+1];
        if (temp.x < 0 || temp.x>=n || temp.y < 0 || temp.y >= m) continue;
        if (is_in_stack(temp) || (map[temp.x][temp.y]==-1) ) continue;
        stack.push_back(temp);
        if (map[temp.x][temp.y]==1)
        {
            for (auto j = plist1.begin(); j < plist1.end(); j++)
            {
                if (is_in_stack(*j)) continue;
                stack.push_back(*j);
                flag=DFS(*j,depth+2);
                stack.pop_back();
            }
        }
        else if (map[temp.x][temp.y]==2)
        {
            for (auto j = plist2.begin(); j < plist2.end(); j++)
            {
                if (is_in_stack(*j)) continue;
                stack.push_back(*j);
                flag=DFS(*j,depth+2);
                stack.pop_back();
            }
        }
        else
        {
            flag=DFS(temp,depth+1);
        }
        stack.pop_back();
    }
    return flag;
    
}
int main(){
    int temp;
    cin>>m>>n;
    map=new int*[n];
    for (int i = 0; i < n; i++)
    {
        map[i]=new int[m];
    }
    
    //input and process
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
        {
            cin>>temp;
            map[i][j]=temp;
            if (temp==-2)
            {
                beginp.x=i;
                beginp.y=j;
            }
            else if (temp==-3)
            {
                endp.x=i;
                endp.y=j;
            }
            else if (temp==1)
            {
                point p;
                p.x=i;p.y=j;
                plist1.push_back(p);
            }
            else if (temp==2)
            {
                point p;
                p.x=i;p.y=j;
                plist2.push_back(p);
            }
            
            
            
        }
        
    }

    int flag=DFS(beginp,0);
    if (flag==-1)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<minstep<<endl;
    }    
}