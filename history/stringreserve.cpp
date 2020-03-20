#include<iostream>
int f(int x, int y) { return x ? f(x / 10, y * 10 + x % 10) : y; }

int main(){
    std::string s;
    std::cin >> s;
    auto p = --s.end();
    if (*s.begin()=='-') std::cout<<'-';  
    for (; p > s.begin() && *p=='0' ; p--);
    for (; p - s.begin() >= (int)(*s.begin()=='-'); std::cout << *p--);
    // int a=100000000000000000;
    // std::cout<<f(a,0);
}