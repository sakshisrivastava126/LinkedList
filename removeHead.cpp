#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int value){
            data = value;
            next = NULL;
        }
};

Node* constructLL(vector<int>& arr) {
    Node *head = new Node(arr[0]);
    Node *mover = head;

for(int i=1; i<arr.size(); i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
}
return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl; 
}

Node* removesHead(Node* head){
    if(head == NULL) return head;
    Node * temp = head;
    head = head->next;
    delete temp;
    return head;
}
