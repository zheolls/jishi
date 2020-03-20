#include<iostream>
#include<string>
using namespace std;
int *  next(string str){
    int i=0,j=-1;
    int * pmt = new int [str.length()];
    pmt[0]=-1;
    while(i < str.length()) {
        if (j == -1 || str[i] == str[j]){
            j++;
            i++;
            pmt[i]=j;
        }
        else
            j=pmt[j];
    }
    return pmt;
}

int  kmp(string str1,string str2){
    int * nextl=next(str2);
    int i=0,j=0;
    while (i < (int)str1.size() && j < (int)str2.size())
    {
        if (j==-1 || str1[i]==str2[j] ){
            i++;
            j++;
        }
        else
        {
            j=nextl[j];
        }
    }
    return j == (int)str2.size() ? i-j : -1;
}
int main(){
    cout<<kmp("jmffababababca","abababca");
    return 0;
}