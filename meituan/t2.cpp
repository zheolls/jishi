#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int max=1,ans=1;
    int flag=0,flag2=1;;
    double * arr=new double[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    for (int i = 1; i < n; i++)
    {
        if (arr[i]>arr[i-1])
        {
            max++;
        }
        else if(i==n-1)
        {
            if (max>ans)
            ans=max;
        }
        
        else if(arr[i+1] > arr[i-1] && flag2){
            max++;
            flag=i;
            i++;
            flag2=0;
        }
        else {
            if (max>ans) ans=max;
            int temp=i;
            if (flag) 
                i=flag;
            flag=temp;
            flag2=1;
            max=1;
        }
        if (max>ans)
            ans=max;
    }
    cout<<ans<<endl;
    
}