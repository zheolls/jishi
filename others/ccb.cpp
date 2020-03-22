#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int ans=0;
    ans=(n/2)*(m/2);
    ans+=(m*(n%2)+n*(m%2))/2;
    cout<<ans;
}