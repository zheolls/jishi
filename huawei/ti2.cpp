#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long point[14];
double ans=1000000000;
int getdis(int i,int j){
    return (point[2*i]-point[2*j])*(point[2*i]-point[2*j])+(point[2*i+1]-point[2*j+1])*(point[2*i+1]-point[2*j+1]);
}
int main(){
    double tu[7][7];
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
    int flag[7]={0};
    flag[0]=1;
    for (int i = 1; i < 6; i++){
        if (flag[i]) continue;
        flag[i]=1;
        for (int j = 1; j < 6; j++){
            if (flag[j]) continue;
            flag[j]=1;
            for (int k = 1;  k< 6; k++){
                if (flag[k]) continue;
                flag[k]=1;
                for (int l = 1; l < 6; l++){
                    if (flag[l]) continue;
                    flag[l]=1;
                    for (int m = 1; m < 6; m++){
                        if (flag[m]) continue;
                        double temp=(tu[0][i])+(tu[i][j])+(tu[j][k])+(tu[k][l])+(tu[l][m])+(tu[m][6]);
                        if (temp<ans) ans=temp;                        
                        flag[m]=0;
                    }
                    flag[l]=0;
                }
                flag[k]=0;
            }
            flag[j]=0;
        }
        flag[i]=0;
    }
    cout<<(int)(ans)<<endl;
}