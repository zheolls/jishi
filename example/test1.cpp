#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
struct point
{
    int i,j;
    int flag=0;
};

int main(){
    int i=0,j=0,m=0,sum=0;
    int arr[9][9];
    vector<point> Pointlist = vector<point>();
    for (i=0;i<9;i++)
        for (j=0;j<9;j++){
                int d;
                scanf("%d",&d);
                arr[i][j]=d;
                if (d==0) 
                {
                    point p;p.i=i;p.j=j;
                    sum++;
                    Pointlist.push_back(p);
                };
            }
    while (true)
    {
        point p=Pointlist[m];
        i=p.i;j=p.j;
        if (p.flag==0){
            int flag[10]={0};
            for (int k=0;k<9;k++){
                flag[arr[i][k]]=1;
                flag[arr[k][j]]=1;
            }
            for (int k=0;k<3;k++)
                for (int l=0;l<3;l++)
                    flag[arr[(i/3)*3+k][(j/3)*3+l]]=1;
            int k=1,g=0,h=0;
            for (;k<=9;k++) if (!flag[k]) {g=1;h=k;break;};
            k++;
            for (;k<=9;k++) if (!flag[k]) {g=0;break;};
            if (g){
                arr[i][j]=h;
                Pointlist[m].flag=1;
                sum--;
            }
        }
        m++;
        m%=Pointlist.size();
        if(!sum) break;

    }
    for (i=0;i<9;i++)
        for (j=0;j<9;j++)
        {
            printf("%d",arr[i][j]);
            printf(j==8 ? "\n":" ");
        }
    return 0;
}