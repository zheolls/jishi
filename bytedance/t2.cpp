#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int position[2000];
int DELTA=0;
int max(int a,int b){
    int maxn=0,j=a;;
    for (auto i = a+1; i<DELTA && position[a]+b > position[i]  ; i++)
    {
        if (maxn<position[DELTA+i]){
            maxn=position[DELTA+i];
            j=i;
        }
    }
    return j;
    
}
int main(){
    int D,W;
    cin>>D>>W;
    int i=0;
    int cishu=0;
    while (cin>>position[DELTA])
    {
        DELTA++;
    }
    DELTA=DELTA/2;
    int a=0,b=W,d;
    int maxn=0;
    if (position[0]>W)
    {
        cout<<-1<<endl;
        return 0;
    }
    else if (W>=D)
    {
        cout<<0<<endl;
        return 0;
    }
    else
    {
        for (auto i = 0; W > position[i]  ; i++)
        {
            if (maxn<position[DELTA+i]){
                maxn=position[DELTA+i];
                a=i;
            }
        }
        W=W+position[DELTA+a]-position[a];
        cishu++;
        // cout<<a<<endl;
    }
    d=a;
    while (true)
    {
        if (position[d]+W>=D)
        {
            cout<<cishu<<endl;
            break;
        }
        
        d=max(a,W);
        // cout<<d<<endl;
        if (d==a)
        {
            cout<<-1<<endl;
            break;
        }
        
        // if (position[DELTA+d]+W>=D)
        // {
        //     cout<<cishu<<endl;
        //     break;
        // }
        W = W - (position[d]-position[a])+position[DELTA+d];
        a=d;
        cishu++;

    }
    
    
    

}