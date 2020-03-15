#include<iostream>
#include<string>
#include<algorithm>
class tree_arr_max
{
private:
    int *c;
    int *arr; 
    int n;
public:
    tree_arr_max(int n,int *arr){
        this->arr=new int[n+1]();
        c=new int[n+1]();
        this->n=n;
        for (int i = 1; i <= n; i++)
        {
            this->arr[i]=arr[i-1];
        }
        init();
    };
    void init(){
        for (int i = 1; i <= n; i++)
        {
            c[i]=arr[i];
            for (int j = 1; j < lowbit(i);j<<=1 )
            {
                c[i]=c[i] > c[i-j] ? c[i] : c[i-j];
            }
        }
    }

    void update(int x,int val){
        arr[x]=val;
        while (x<=n)
        {
            if (val>c[x]) c[x]=val;
            x+=lowbit(x);
        }
    }

    int lowbit(int x){
        return x&(-x);
    }

    int getQuerymax(int i,int j){

        i++;j++;
        int ans=0;
        while (true)
        {
            ans=ans>arr[j]?ans:arr[j];
            // std::cout<<ans<<std::endl;
            if (i>=j)
                return ans;
            j--;
            while (j-i >= lowbit(j))
            {
                ans=ans>c[j]?ans:c[j];
                j-=lowbit(j);
            }
        }
    }
};

 

int main(){
    int a[]={1,2,3,9,5,6,7,8,10};
    // tree_array_sum T=tree_array_sum(8);
    // T.setarr(a);
    // int *b=T.getarr();
    // std::cout<<T.get_sum(5)<<std::endl<<a[0];
    tree_arr_max T=tree_arr_max(9,a);
    std::cout<<T.getQuerymax(3,8)<<std::endl;

}