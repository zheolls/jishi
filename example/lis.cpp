#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int Lis_dp(int *arr,int n){
    int * f=new int[n];
    int i,j,max=0;
    for (i=0;i<n;i++) f[i]=1;
    for (i=0;i<n;i++){
        for (j=0;j<i;j++){
            if (arr[j]<arr[i] && f[j]+1>f[i])
                f[i]=f[j]+1;
        }
        if(max<f[i]) max=f[i];
    }
    return max;
}
int Lis_greedy(int * arr,int n){
    int * f=new int[n];
    int j=0;
    f[0]=arr[0];
    for (int i=1;i<n;i++)
        if (arr[i]>f[j])
            f[++j]=arr[i];
        else
            f[lower_bound(f,f+j,arr[i])-f]=arr[i];
    return j+1;
}

int main(){
    int arr[]={1,1,6,2,4,3,5,6,9,7,90};
    cout<<Lis_greedy(arr,11);
}