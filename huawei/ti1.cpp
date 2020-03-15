#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
string *s;
struct ti1
{
    string dst="";
    string src="";
    int flag=-1;
}*ti;
 string getstr(string str){
    int i=0;
    for (;i<n;i++) if (str==ti[i].src) break;
    if (!ti[i].flag) return ti[i].dst;
    else{
        int j = (ti[i].flag==-1 ? 0 : ti[i].flag);
        while (j < (int)ti[i].dst.size()){
            for (int k = 0; k < (int)ti[i].dst.size()-1; k++)
                if (ti[i].dst[k]=='$' && ti[i].dst[k+1]=='{'){
                    ti[i].flag=k+2;
                    break;
                }
            if (ti[i].flag==-1) break;
            string temp;
            for (;j<(int)ti[i].dst.size();j++){
                if(ti[i].dst[j]=='}'){
                    cout<<ti[i].dst.substr(ti[i].flag,j-ti[i].flag)<<endl;
                    temp= getstr(ti[i].dst.substr(ti[i].flag,j-ti[i].flag));
                    break;
                }
            }
            ti[i].dst=ti[i].dst.substr(0,ti[i].flag-2)+temp+ti[i].dst.substr(j+1,ti[i].dst.size()-j-1);
            cout<<ti[i].dst<<endl;
        }
        ti[i].flag=0;
        return ti[i].dst;
    }
 }
 
int main(){
    cin>>n;
    ti = new ti1[n];
    s=new string[n];
    for (int i=0;i<n;i++){
        cin>>s[i];
        int j=0;
        for (;j<(int)s[i].length()-1;j++){
            if (s[i][j]=='='){
                ti[i].src=s[i].substr(0,j);
                ti[i].dst=s[i].substr(j+1,s[i].size()-j-1);
                break;
            }
            ti[i].flag=-1;
        }
    }
    for (int i=0;i<n;i++){
        cout<<ti[i].src<<"="<<getstr(ti[i].src)<<endl;
    }
}