#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long point[14];
double tu[7][7];
int flag[7]={0};
int step[7]={0};
double ans=100000000;
int getdis(int i,int j){
    return (point[2*i]-point[2*j])*(point[2*i]-point[2*j])+(point[2*i+1]-point[2*j+1])*(point[2*i+1]-point[2*j+1]);
}
void getmin(int dp){
    if (dp==6){
        double temp=(tu[0][flag[1]])+(tu[flag[1]][flag[2]])+(tu[flag[2]][flag[3]])+
                   (tu[flag[3]][flag[4]])+(tu[flag[4]][flag[5]])+(tu[flag[5]][6]);
        if (temp<ans) ans=temp;
    }
    else
    for (int i=1;i<6;i++){
        if (step[i]) continue;
        flag[dp]=i;step[i]=1;

        getmin(dp+1);
        step[i]=0;
    }
    return;

}
int main(){
    point[0]=point[1]=0;
    int i =2;
    while (i<12){
        cin>>point[i];
        i++;
    }    
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)  tu[i][j]=sqrt(getdis(i,j));
    for(int i=1;i<6;i++){
        tu[i][6]=tu[i][0];
        tu[6][i]=tu[0][i];
    }
    tu[0][6]=tu[6][0]=10000000000;
    getmin(1);
    cout<<(ans)<<endl;
}