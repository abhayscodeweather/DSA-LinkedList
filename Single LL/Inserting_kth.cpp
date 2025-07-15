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

Node* insertKth(Node* head, int val, int k){
    if(head == NULL){
        if(k == 1){
            return new Node(val);
        }
        else {
            return head;
        }
    }
    if(k==1){
        return new Node(val, head);
    }
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count ++;
        if(count == (k-1)){
            Node* x = new Node(val, temp->next);
            temp-> next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
   
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = covertArrtoLL(arr);
    head  = insertKth(head, 20, 2);
    print (head);
}
