#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct t1
{
    string src;
    vector<string>  dst=vector<string>();
};
vector<t1> ti=vector<t1>();
bool cmp(string a,string b){
    return a+b<b+a;
}
int getindex(string str){
    for (int a=0;a<(int)ti.size();a++){
        if (ti[a].src==str){
            return a;
        }
    }
    return -1;
}


int main(){
    int n;
    cin>>n;

    string str1,str2;
    while (n--)
    {
        cin>>str1>>str2;
        int a=getindex(str2);
        int flag=1;
        if (a>=0){                
            for ( auto i = ti[a].dst.begin();i < ti[a].dst.end() ; i++)
            {
                if ((*i)==str1){
                    flag=0;
                    break; 
                }
            }
            if (flag){
                    ti[a].dst.push_back(str1);
                }
        }
        else
        {
            t1 temp;
            temp.src=str2;
            temp.dst.push_back(str1);
            ti.push_back(temp);
        }
        
    }
    for (auto i = ti.begin(); i < ti.end(); i++)
    {
        cout<<(*i).src;
        sort((*i).dst.begin(),(*i).dst.end(),cmp);
        for (auto j = (*i).dst.begin(); j < (*i).dst.end(); j++)
        {
            cout<<" "<<(*j);
        }
        cout<<endl;
        
    }
    

    
}