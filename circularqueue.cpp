#include<iostream>
using namespace std;
class circularqueue{
    private:
    int arr[5],rear,front,itemcount;
    public:
    circularqueue(){
        rear=-1;front=-1;itemcount=0;
        for(int i=0;i<5;i++){
            arr[i]=0;
        }
    } 
    bool isempty(){
        if(rear==-1 && front==-1){
            return true;
        }
        else {
            return false;
        }
    }
    bool isfull(){
        if((rear+1)%5==front){
            return true ;
        }
        else {
            return false;
        }
    }
    void enqueue(int x){
        if(isfull()){
            cout<<"the queue is full \n";
        }
        else if (isempty()){
            rear=0; front=0;
             arr[rear]=x;
        
        }
        else
        {
            rear=(rear+1)%5;
             arr[rear]=x;
        
        }
        itemcount++;
         
    }
    int dequeue(){
        int x=0;
            if(isempty()){
                cout<<"the queue is empty \n";
                return 0;  
            }
            else if (front==rear){
                //means only one element is present in the queue 
                x=arr[front];
                arr[front]=0;
                front=-1;rear=-1;
                itemcount--;
                return x;
                
            }
            else {
                x=arr[front];
                 arr[front]=0;
                front=(front+1)%5;
                itemcount--;
                return x;
            }
    }
    int count(){
        return(itemcount);
    }
    void displayvalue(){//no need as dequeue performed the display memeber bur this is for complete representation
        for(int i=0;i<5;i++){
            cout<<arr[i]<<"\n";
        }
    }

};
int main(){
    circularqueue obj;int option,value;
    do{
        cout<<"enter the operation to performed:\n";
        cout<<"1.for isempty\n";
        cout<<"2.for isfull\n";
        cout<<"3.for enqueue\n";
        cout<<"4.for dequeue\n";
        cout<<"5.for count\n";
        cout<<"6.for display value\n";
        cout<<"7 , for clear screen\n";
        cout<<"enter zero for exit \n";
        cin>>option;
    switch(option){
        case 0: break;
        case 1:
              if( obj.isempty())
              cout<<"the queue is empty\n";
              else 
              cout<<"the queue is not empty\n";
              break;
        case 2:
            if(obj.isfull())
            cout<<"the queue is full \n";
            else 
            cout<<"the queue is not full \n";
            break;
        case 3:
            cout<<"enter the value:\n";
            cin>>value;
            obj.enqueue(value);
            break;
        case 4:
            int y ;
            y=obj.dequeue();
            cout<<"the value is "<<y<<"\n";
            break;
        case 5:
           int z;
           z=obj.count();
           break;
        case 6:
           obj.displayvalue();
        case 7:
        system("cls");
        break;
        default:
        cout<<"please enter the proper option\n";

    }    

    }while (option!=0);
}