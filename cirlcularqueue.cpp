#include<iostream>
using namespace std;
class node {
  public:
  int key ,data;
  node *next;
  node(){
      key=0;data=0;next=NULL;
  }
  node(int k,int d){
      key=k;data=d;
      next=NULL;
  }
};
class queueusinglinkedlist {
    public:
    node *rear;
    node  *front;
    queueusinglinkedlist(){
        rear=NULL,front=NULL;
    }
    queueusinglinkedlist(node *n){
        rear=n;front=n;
    }
    bool isempty(){
        if(rear==NULL && front==NULL){
            return true;
        }
        else return false;
    }
    bool nodeexist(node *n){
      node *temp=front;
      bool exist =false;
        do{
            if(temp->key==n->key){
                exist =true;   
            }
            else temp=temp->next;
        } while(temp!=front);
        return exist;
    }
    void enqueue(node *n){
        if(isempty()){
            rear=n ;front=n; cout<<"node is successfully enqueue\n";
        }

        else {
            if(nodeexist(n)){
                cout<<"node with that key is already exist please enter another key \n";
            }
            else{
            rear->next=n;
            rear=n;
            n->next=front;
            cout<<"node is successfully enqueue\n";
            }
        }
    }
    node* dequeue(){
        if(isempty()){
            cout<<"queue is empty \n";
        }
        else if(front==rear){
           node *temp=rear;
           rear=NULL;front=NULL;
            return temp;
        }
        else{
            node *temp;
            temp=front;
            front=front->next;
            rear->next=front;
            return temp;
        }
    }
    int count(){
        int count=0;
        if(isempty()){
            return 0;
        }

        else { 
            node *temp =front;
         do {
                count++;
                temp=temp->next;
            }  
             while(front!=front);
        }return count;
    }
    void display(){
        if(isempty()){
            cout<<"the queue is empty\n";
        }
        else { node *temp=front;
            do {
               cout<<"("<<temp->key<<","<<temp->data<<")\n";
               temp=temp->next;
            }
            while(temp!=front);
        }
    }

};
int main(){
    queueusinglinkedlist s;
 int option,key ,data,count;

   do{
       cout<<"enter the option for the operation to be performed ,enter 0 for exit :\n";
       cout<<"enter 1 . for enqueue operation "<<"\n";
        cout<<"enter 2 . for dequeue operation "<<"\n";
        cout<<"enter 3 . for isempty  operation "<<"\n";
        cout<<"enter 4 . for  operation "<<"\n";
        cout<<"enter 5 . for   operation "<<"\n";
        cout<<"enter 6. for count  operation "<<"\n";
        cout<<"enter 7 . for   change  operation "<<"\n";
        cout<<"enter 8 . for display  operation "<<"\n";
        cout<<"enter 9. for clear  operation "<<"\n";
        cin>>option;
        node *n1 = new node();
        switch(option)
        {
            case 0:
            break;
            case 1:
            cout<<"enter the key and the value of the data to be enter in the stack \n";
            cin>>key;
            cin>>data;
            n1->key=key;
            n1->data=data;
            s.enqueue(n1);break;
            case 2:
            cout<<"the pop value of the function is \n";
            n1=s.dequeue();
            cout<<"the key value of the pop value is "<<n1->key<<"and the data is:"<<n1->data<<"\n";
            cout<<"the top of the stack is : ("<<n1->key<<","<<n1->data<<")";
            delete n1;break;
            case 3:
            if(s.isempty()){
                cout<<"the stack is empty\n";
            }
            else cout<<"the stack is not empty";break;
            case 4:
            if(s.isempty()){
                cout<<"the stack is empty\n";
            }
            else{
                cout<<"peek function is called \n";
                n1=s.dequeue();
                cout<<"the top of the stack is : ("<<n1->key<<","<<n1->data<<")";
            }break;
            case 6:
            cout<<"count fuction is called \n";
            count=s.count();
            cout<<count;break;
            case 8:
            s.display();break;
            default:
            cout<<"please enter the valid number \n";
            break;


        }
        }while(option!=0);
}
