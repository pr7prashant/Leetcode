// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

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

class Solution
{
    public:
    Node* reverse(Node* head) {
        if (!head) return head;
        
        Node* prev = nullptr, *curr = head;
        while (head) {
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }
        
        return prev;
    }
    
    Node* addOne(Node *head) {
        if (!head) return head;
        
        head = reverse(head);
        
        int carry = 1;
        Node* it = head;
        while (it) {
            int n = it->data;
            it->data = (n + carry) % 10;
            carry = (n + carry) / 10;
            it = it->next;
        }
        
        head = reverse(head);
        
        if (carry > 0) {
            Node* c = new Node(carry);
            c->next = head;
            return c;
        }
        
        return head;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends