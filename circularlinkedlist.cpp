#include<iostream>
using namespace std;
class node{
    public:
    int key,data;
    node *next;
    node (){
        key=0;data=0;next=NULL;
    }
    node(int k,int d){
        data=d;key=k;
    }
};
class circularlinkedlist{
    public:
    node *head;
    circularlinkedlist(){
        head=NULL;
    }
    circularlinkedlist(node *n){
        head=n;
    }
    node* nodeexist(int k){
        node* ptr=head;
        node *temp=NULL;
        if(ptr==NULL){
            return temp;
        }
        else{
       do{
            if(ptr->key==k){
               temp=ptr;
           }
           ptr=ptr->next;
        }
       while(ptr!=head);
       return temp;
        }
    }
    void appendnode(node *n){
        
        if(nodeexist(n->key)!=NULL){
            cout<<"node already exits in the circular linklist\ninsert some other key\n";
        }
        else{
              if(head==NULL){
            head=n;
              n->next=head;
             cout<<"node is successfully apppended at the start \n";
        }
            
            
             else{node *ptr =head;
             while (ptr->next!=head){
                 ptr=ptr->next;
             }
                n->next=ptr->next;
                ptr->next=n;
                cout<<"node is successfully apppended\n";
             }                 
        }
    }
    void prepandnode(node *n){
        
        if(nodeexist(n->key)!=NULL){
            cout<<"node already exits in the circular linklist\ninsert some other key\n";
        }
        else
        {   node *ptr=head;
             while(ptr->next!=head){
                 ptr=ptr->next;
             }
                  ptr->next=n;
                  n->next=head;
                  head=n;
                  cout<<"node is sucessfully propand\n";
             
        }
        
    }
    void insertnodeafter(int k,node *n){
         node *ptr=nodeexist(k);
        if(ptr==NULL){
            cout<<"no such node exist with the key you enter \n";
        } 
        else {
            if(nodeexist(n->key)!=NULL){
                cout<<"node already exists with that key value\n";
            }
            else{
                 if(ptr->next==head){
                 n->next=ptr->next;
                 ptr->next=n;
                 cout<<"node is sucessfully inserted \n";
            }
            else {
                n->next=ptr->next;
                ptr->next=n;
                 cout<<"node is sucessfully inserted \n";
            }
        }
        }
    }

    
    void deletenode(int k){
         node *ptr=nodeexist(k);
        if(ptr==NULL){
            cout<<"no such node exist with the key you enter \n";
        } 
        else {
            if(ptr==head)
            {
                if(head->next==head){
                     head=NULL;
                     cout<<"not is deleted only one element was present\n";
                }
                else {
                       node *ptr1=head ;
                       while (ptr1->next!=head)
                       {
                           ptr1=ptr1->next;
                       }
                       ptr1->next=head->next;
                       head=head->next;
                       cout<<"node deleted\n";
                }
            }
            else{
                node *temp=NULL;
                node *previousnode=head;
                node *currentnode=head->next;
                while (currentnode!=NULL){
                if (currentnode->key==k){
                    temp=currentnode;
                    currentnode=NULL;
                }
                else {
                    previousnode=previousnode->next;currentnode=currentnode->next; 
                }
            }
            previousnode->next=currentnode->next;
            cout<<"node is deleted successfully\n";
            }
        }
    }
    
    void updatenode(int k,int d){
         node *ptr=nodeexist(k);
          if(ptr==NULL){
            cout<<"no such node exist with the key you enter \n";
        } else{
            ptr->data=d;
            cout<<"nodee is updated successfullly\n";
        }
    }
    void displayvalue(){
        if(head==NULL){
            cout<<"list is empty \n";
        }
        else 
        {    
             cout<<"the value in list is \n";
             node *ptr=head;
            do {
                
                cout<<ptr->key<<" "<<ptr->data<<" "<<ptr->next<<"\n";
                ptr=ptr->next; 
            } while(ptr!=head);
        }
    }
};
int main(){
    circularlinkedlist s;
    int k1,key1,data,option; 
      
    do{
        cout<<"enter the operation to performed:\n";
        cout<<"1.for appendnode\n";
        cout<<"2.for prepandnode\n";
        cout<<"3.for insertnode after\n";
        cout<<"4.for insertnodebefore\n";
        cout<<"5.for deletenode by key\n"; 
        cout<<"6.for display value\n";
        cout<<"7 , for clear screen\n";
        cout<<"8.for updatenode by key\n"; 
        cout<<"enter zero for exit \n";
        cin>>option;
         node   *n1=new node();
    switch(option){
        case 0: break;
        case 1:
              cout<<"appendnode operation \n enter the key and the data to be append";
              cin>>key1;
              cin>>data;
              n1->key=key1;
              n1->data=data;
              s.appendnode(n1);
              break;
        case 2:
            cout<<"prepandnode is operated:\n";
            cin>>key1;
              cin>>data;
              n1->key=key1;
              n1->data=data;
              s.prepandnode(n1);
            break;
        case 3:
          cout<<"enter the after which you want to insert the node \n";
            cin>>k1;
            cout<<"insert a node after the key \n";
            cin>>key1;
            cin>>data;
             n1->key=key1;
              n1->data=data;
              s.insertnodeafter(k1,n1);

            break;
        case 4: cout<<"enter the after which you want to insert the node \n";
            cin>>k1;
            cout<<"insert a node after the key \n";
            cin>>key1;
            cin>>data;
             n1->key=key1;
              n1->data=data;
             // s.insertnodebefore(k1,n1);
            break;
        case 5:
            cout<<"delete operation is selected \n enter the key which should be deleted\n";
            cin>>k1;
            s.deletenode(k1);
           break;
        case 6:
           s.displayvalue();
           break;
        case 7:
        system("cls");
        break;
        case 8:
             cout<<"update node is operated\nenter the data and the key which should be update\n";
             cin>>data;
             cin>>key1;
             s.updatenode(key1,data);
             break;
        default:
        cout<<"please enter the proper option\n";


    }    

    }while (option!=0);
}

