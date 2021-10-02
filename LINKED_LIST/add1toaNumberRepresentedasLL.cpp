#include <iostream>
using namespace std;

class Listnode{
    public: 
    int data;
    Listnode* next;
    Listnode(int val){
        data = val;
        next = NULL;
    }
};
void insertAtTail(Listnode* &head, int val){
    Listnode* n = new Listnode(val);

    if(head == NULL){
        head = n;
        return;
    }

    Listnode* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;

}
void display(Listnode* head){
    Listnode* temp = head;
    while(temp != NULL){
        cout<<temp->data;
        cout<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

Listnode *rev(Listnode *head){
    Listnode * prev   = NULL;
    Listnode * current = head;
    Listnode * next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
Listnode *addOne(Listnode *head){
   head=rev(head);
   Listnode *ptr=head,*prev;
   int carry=1,sum=0;
   while(ptr!=NULL){
       sum=(ptr->data)+carry;
       carry=sum/10;
       if(sum>=10){
           sum=sum%10;
       }
       ptr->data=sum;
       prev=ptr;
       ptr=ptr->next;
   }
   if(carry){
       Listnode *newNode=(Listnode*)malloc(sizeof(Listnode));
       newNode->data=carry;
       prev->next=newNode;
       newNode->next=NULL;
   }
   
   head=rev(head);
   return head;
}

int main(){
    Listnode* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 9);
    insertAtTail(head, 9);
    display(head);
    cout<<endl;
    Listnode* newhead=addOne(head);
    display(newhead);

return 0;
}