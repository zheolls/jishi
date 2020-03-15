#include<iostream>
#include<string>
using namespace std;
void quicksort(int * arr,int low, int high){
    int temp=arr[low];
    int lo=low;
    int hi=high;
    if (lo>=hi) return;
    while (lo != hi)
    {
        while (lo < hi && arr[hi] >= temp) hi--;
        arr[lo]=arr[hi];
        while (lo < hi && arr[lo] <= temp) lo++;
        arr[hi]=arr[lo];
    }
    arr[hi]=temp;
    quicksort(arr,low,--lo);
    quicksort(arr,++hi,high);
}
int main(){
    int arr[]={1,2,3,1,5,2,1};
    quicksort(arr,0,6);
    for (int i=0;i<7;i++){
        cout<<arr[i]<<' ';
    }
}