#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b?0:1;
}
int main(){
    int n,m;
    while (cin>>n>>m)
    {
        int *arr= new int [n+m];
        for (int i = 0; i < n+m; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n+m,cmp);
        cout<<arr[0];
        for (auto i = 1; i < m+n; i++)
        {
            if (arr[i]>arr[i-1])
            {
                cout<<" "<<arr[i];
            }
        
        }
        cout<<endl;
    }

    
    
}