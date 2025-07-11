#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:       // You define a Node class that represents an element in the linked list. It contains:
    Node(int data1, Node* next1){    // allows setting both data and pointer


        data = data1;
        next = next1;
    }

    public:       
    Node(int data1){    // initializes next to nullptr (used for end of the list)
        data = data1;
        next = nullptr;   
    }
};

Node* covertArrtoLL (vector<int> &arr){
    Node* head = new Node(arr[0]);   //we should only focus on the head
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data<<" ";
        head = head->next;
    }
}

Node* insertTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = covertArrtoLL(arr);
    head  = insertTail(head, 20);
    print (head);
}
