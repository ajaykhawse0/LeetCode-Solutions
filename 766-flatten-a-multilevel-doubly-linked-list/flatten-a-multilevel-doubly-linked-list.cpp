/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*>st;

        Node*temp = head;
        while(temp){
            if(temp->child){
                if(temp->next)st.push(temp->next);
                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = nullptr;}
            else if(!temp->next && !st.empty()){
                Node* curr = st.top();
                st.pop();
                temp->next = curr;
                curr->prev = temp;
            }    
            temp = temp->next;
        }

    return head;}
};