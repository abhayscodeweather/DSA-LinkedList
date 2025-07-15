#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;

    public:       // You define a Node class that represents an element in the linked list. It contains:
    Node(int data1, Node* next1,Node* back1){    // allows setting both data and pointer

        back = back1;
        data = data1;
        next = next1;
        
    }

    public:       
    Node(int data1){    // initializes next to nullptr (used for end of the list)
        data = data1;
        next = nullptr;   
    }
};

Node* Covert_to_DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}
int main(){
    vector <int> arr = {12, 5, 8, 7};
    Node* head = Covert_to_DLL(arr);
    print (head);
    return 0;
}
