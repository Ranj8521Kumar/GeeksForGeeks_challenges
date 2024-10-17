//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        if(head->next==NULL) return {head,NULL};
        if(head->next->next==NULL){
            Node *head1=head;
            Node *head2=head->next;
            head1->next=NULL;
            return {head1,head2};
        }
        Node *head1,*head2,*curr1,*curr2;
        head1=head;
        head2=head->next;
        curr1=head1;
        curr2=head2;
        while(curr2&&curr2->next){
            curr1->next=curr2->next;
            curr1=curr1->next;
            if(curr2->next){
                curr2->next=curr2->next->next;
                curr2=curr2->next;
            }
            if(curr2&&curr2->next==NULL){
                curr1->next=NULL;
            }
        }
        return {head1,head2};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends