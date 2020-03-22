#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<string> ss=vector<string>();
int main(){

    string s;
    cin>>s;
    int i,j,k,temp=0,flag=0;
    for (i = 1; i <= (int)s.length(); i++)
    {
        for (j=0 ; j + i <= (int)s.length(); j++)
        {
            for (k=temp; k < (int)ss.size(); k++)
            {
                if (ss[k]==s.substr(j,i))
                {
                    flag=1;break;
                }
                
            }
            if (!flag)
            {
                ss.push_back(s.substr(j,i));
            }

            flag=0;
            
        }
        temp=ss.size()-1;
        
    }
    cout<<ss.size()<<endl;

}