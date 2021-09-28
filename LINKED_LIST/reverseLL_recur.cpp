#include <iostream>
using namespace std;

class node{
    public: 
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
void insertAtTail(node* &head, int val){
    node* n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;

}
void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data;
        cout<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
node* reverseLL_recursive(node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* n = reverseLL_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return n;
}
int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    display(head);
    cout<<endl;
    node* newhead = reverseLL_recursive(head);
    display(newhead);

return 0;
}