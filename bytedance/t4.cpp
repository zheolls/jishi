#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,m,N,x1,y1,x2,y2;
    cin>>n>>m;
    string * map=new string[n];
    for (int i = 0; i < n; i++)
    {
        cin>>map[i];
    }
    cin>>N;

    for (int i = 0; i < N; i++)
    {
        cin>>x1>>y1>>x2>>y2;
        x1-=1;x2-=1;y1-=1;y2-=1;
        if (map[x1][y1]!=map[x2][y2])
        {
            cout<<"NO"<<endl;
            continue;
        }
        
        int temp;
        if (x1>x2){
            temp=x1;x1=x2;x2=temp;
            temp=y1;y1=y2;y2=temp;
        }

        int j=x1,k=x2;
        for (; j < x2; j++)
            if (map[j][y1]!='.') break;
        for (; k > x1 ; k--)
            if (map[k][y2]!='.') break;
        if (k<=j)
        {
            int maxy=y1>y2?y1:y2;
            int miny=y1>y2?y2:y1;
            int flag=0;
            for (; k <= j; k++){
                int d=miny+1;
                for (; d <= maxy - 1; d++)
                {
                    if (map[k][d]!='.')
                    {
                        flag=1;break;
                    }
                    
                }
                if (d != maxy - 1)
                    {
                        flag=0;
                    }
            }
            if (!flag)
            {
                map[x1][y1]='.';
                map[x2][y2]='.';
                cout<<"YES"<<endl;
                continue;
            }

        }
        if (y1>y2){
            temp=x1;x1=x2;x2=temp;
            temp=y1;y1=y2;y2=temp;
        }

        j=y1;k=y2;
        for (; j < y2; j++)
            if (map[x1][j]!='.') break;
        for (; k > y1 ; k--)
            if (map[x2][k]!='.') break;
        if (k<=j)
        {
            int maxx=x1>x2?x1:x2;
            int minx=x1>x2?x2:x1;
            int flag=0;
            for (; k <= j; k++){
                int d=minx+1;
                for (; d <= maxx - 1; d++)
                {
                    if (map[d][k]!='.')
                    {
                        flag=1;break;
                    }
                    
                }
                if (d != maxx - 1)
                    {
                        flag=0;
                    }
            }
            if (!flag)
            {
                map[x1][y1]='.';
                map[x2][y2]='.';
                cout<<"YES"<<endl;
                continue;
            }
        }    
        cout<<"NO"<<endl;    
    }
    
}