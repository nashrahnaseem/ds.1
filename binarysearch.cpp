#include<iostream>
using namespace std;
int main (){

     int size ;
    cout<<"enter the size of array\n";
    cin>>size;
    int *ptr=new int[size];
    cout<<"enter the element in the array\n";
    for(int i=0;i<size;i++){
        cin>>ptr[i];
    
    }
    cout<<"enter the element to be search \n";
    int n;
    cin>>n;int p=0;
    int left=0;int right=size-1;int mid=0;
    while (left<=right){
        mid=left+(right-left)/2;
        if(ptr[mid]==n){
            cout<<"the number "<<n<<"is match with the index value :"<<mid;p++;break;
        }
        else if (ptr[mid]<n)
        {
            left=mid+1;
        }
        else {
            right=mid-1;
        }
    }
    if (p==0){
        cout<<"the number "<<n<<"is not present in the sorrted array\n";
    }
}