#include<iostream>
#include<string>
using namespace std;
int minp=0,maxp=0,ans,n;
void getmax(string strr,int x ,int y){
    int i;
    int max=1,temp=0;
    ans=1;
    if (x > maxp || y < minp )
    {
        while (x > 0 && strr[x]>=strr[x-1])
        {
            x--;
        }
        while (y < n-1 && strr[y]<=strr[y+1])
        {
            y++;
        }        
    }
    else
    {
        x=0;y=n-1;
    }
    temp=x;
    for (i=x+1; i <= y; i++)
    {
        if (strr[i]>=strr[i-1])
        {
            max++;
        }
        else
        {
            if (max>ans)
            {
                ans=max;
                maxp=i-1;
                minp=temp;
            }
            temp=i;
            max=1;
        }
    }
    if (max>ans)
    {
        ans=max;
        minp=temp;
        maxp=ans+minp-1;
        
    }
    
}
int main(){
    int m,x,y,i,j;
    char a;
    string strr;
    cin>>n>>m;
    cin>>strr;
    x=0;y=n-1;
    while(m--)
    {
        cin>>a;
        if (a=='q')
            cout<<strr<<":"<<ans<<":|"<<minp+1<<","<<maxp+1<<endl;
        else
        {
            cin>>x>>y;
            x--;y--;
            for (j=x;j<=y;j++)
                strr[j]=!(strr[j]-'0')+'0';
            getmax(strr,x,y);
        }        
    }
    return 0;
}