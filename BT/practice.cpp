#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
    int data;
    Node*right;
    Node*left;

    Node(int data){
        this->data  = data;
        this->right  = NULL;
        this->left  = NULL;

    }
};


vector<int>inOrderTraversal(Node* root){
    vector<int>inOrder;
    if(root == nullptr){
        return inOrder;
    }
    Node*curr  = root;
    stack<Node*>st;


    while(curr || !st.empty()){
        while(curr){
            inOrder.push_back(curr->data);
            curr = curr->left;
        }

        Node* node  = st.top();
        st.pop();

        inOrder.push_back(node->data);

        curr = node->right;


    }
    return inOrder;
}



int main(){

}