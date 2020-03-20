#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    long * a,*b;
    a=new long[n]();
    b=new long[n]();
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }

    if (n==1)
    {
        cout<<(a[0]>b[0]?a[0]:b[0]);
        return 0;
    }
    else if (n==2)
    {
        cout<<(a[0]+a[1]>b[0]+b[1]?a[0]+a[1]:b[0]+b[1]);
        return 0;
    }
    
    

    int max1=0,max2=0,max3=0;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]>=a[max1] )
        {
            max1=i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i==max1)
        {
            continue;
        }
        
        if (a[i]>=a[max2])
        {
            max2=i;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        if (i==max1 || i== max2)
        {
            continue;
        }
        
        if (a[i]>=a[max3])
        {
            max3=i;
        }
        
    }
    ans=a[max1]+a[max2]+a[max3];
    max1=0;max2=0;max3=0;
    for (int i = 0; i < n; i++)
    {
        if (b[i]>=b[max1] )
        {
            max1=i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i==max1)
        {
            continue;
        }
        
        if (b[i]>=b[max2])
        {
            max2=i;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        if (i==max1 || i== max2)
        {
            continue;
        }
        
        if (b[i]>=b[max3])
        {
            max3=i;
        }
        
    }
    if (b[max1]+b[max2]+b[max3]>ans){
        ans=b[max1]+b[max2]+b[max3];
    };
    cout<<ans<<endl;
}