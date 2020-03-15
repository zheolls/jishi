#include<iostream>
#include<string>
#include<algorithm>
class tree_array_sum{
private:    
    int *c;
    int *a; 
    int n;
public:
    tree_array_sum(int n){
        a=new int[n+1];
        c=new int[n+1];
        for(int i=0;i<=n;i++){
            a[i]=c[i]=0;
        }
        this->n=n;
    }
    int * getarr(){
        return a+1;
    }

    void setarr(int * arr){
        for (int i=1;i<=n;i++){
            update(i,arr[i-1]);
        }
    }
    int lowbit(int x){
        return x&(-x);
    }
    int get_sum(int i){
        int ans=0;
        while (i>0)
        {
            ans+=c[i];
            i-=lowbit(i);
        }
        return ans;
    }
    void update(int i,int val){
        a[i]+=val;
        while (i <= n)
        {
            c[i] += val;
            i+=lowbit(i);
        }
    }
};
