#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
vector<int> a,b;
int main(){
    string line,line2;
    int x,ap=0,bp=0;
    getline(cin,line);
    getline(cin,line2);
    stringstream ss(line);
    while (ss>>x)
    {
        a.push_back(x);
    }
    ss=stringstream(line2);
    while (ss>>x)
    {
        b.push_back(x);
    }
    while (ap<(int)a.size() && bp<(int)b.size())
    {
        if (a[ap] >= b[bp])
        {
            cout<<b[bp]<<" ";
            bp++;
        }
        else
        {
            cout<<a[ap]<<" ";
            ap++;
        }        
    }
    if (ap < (int)a.size())
    {
        for (int i = ap; i <  (int)a.size(); i++)
        {
            if (i==(int)a.size()-1)
                cout<<a[i];
            else
                cout<<a[i]<<" ";
        }
        
    }
    
    if (bp < (int)b.size())
    {
        for (int i = bp; i <  (int)b.size(); i++)
        {
            if (i==(int)b.size()-1)
                cout<<b[i];
            else            
                cout<<b[i]<<" ";
        }
        
    }
}
