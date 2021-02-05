#include<iostream>
using namespace std;
int main(){
    int size ;
    cout<<"enter the size of array\n";
    cin>>size;
    int *ptr=new int[size];
    cout<<"enter the element in the array\n";
    for(int i=0;i<size;i++){
        cin>>ptr[i];
    
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(ptr[j]>ptr[j+1]){
                int temp=0;
                temp=ptr[j];
                ptr[j]=ptr[j+1];
                ptr[j+1]=temp;
            }
        }

    }cout<<"the sorted array is \n";
    for(int i=0;i<size;i++){
        cout<<ptr[i]<<"\n";
    
    }
}