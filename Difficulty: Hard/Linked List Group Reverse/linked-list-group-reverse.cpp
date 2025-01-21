//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
public:
    // Function to reverse every k nodes in the linked list
    Node* reverseKGroup(Node* head, int k) {
        // Base cases:
        if (k == 1 || head == nullptr || head->next == nullptr) 
            return head; // No reversal needed if k=1 or list is too short
        
        // Reverse the first k nodes
        Node* curr = head;    // Current node being processed
        Node* prev = nullptr; // Previous node for link reversal
        Node* next = nullptr; // Next node to process
        
        int count = 0;
        
        // Reverse k nodes or stop if list ends
        while (curr != nullptr && count < k) {
            next = curr->next; // Store next node
            curr->next = prev; // Reverse current node's pointer
            prev = curr;       // Move `prev` to current node
            curr = next;       // Move to the next node
            count++;
        }
        
        // Process remaining nodes recursively
        if (curr != nullptr) { // There are more nodes left
            head->next = reverseKGroup(curr, k); // Connect tail to next reversed group
        }
        
        // Return the new head of the reversed list
        return prev; // The new head of this k-group
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

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
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends