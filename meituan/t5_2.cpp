//AVLtree
#include<iostream>
#include<string>
using namespace std;
struct divide{
    int length;
    bool number;
    int index;
    divide * next,* pre;
};
int main(){
    int n,m,x,y,i,j;
    char a;
    string strr;
    cin>>n>>m;
    cin>>strr;
    while(cin>>a)
    {
        if (a=='q')
            cout<<getmax(strr)<<endl;
        else
        {
            cin>>x>>y;
            for (j=x-1;j<y;j++){
                if (strr[j]=='0')
                {
                    strr[j]='1';
                }
                else
                {
                    strr[j]='0';
                }     
            }
        }
        n--;
        if (!n)
        {
            break;
        }
        
    }
    return 0;
}
