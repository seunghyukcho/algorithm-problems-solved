#include<iostream>
#include<set>

using namespace std;

struct Node{
    int val;
    Node* left, right;
};

int main(){
    int n, k, ans = 0;
    set<string> s;

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        string ss;
        Node node[25];

        for(int i = 0; i < k; i++){
            int num;
            cin >> num;

            Node newnode;
            newnode.val = num;
            newnode.left = NULL;
            newnode.right = NULL;

            node[i] = newnode;
            if(!i){
                here = &node[0];
                while(1){
                    if(here->val < num){
                        if(here->right == NULL){
                            here->right = &node[i];
                            break;
                        }
                        else
                            here = here->right;
                    }
                    else{
                        if(here->left = NULL){
                            here->left = &node[i];
                            break;
                        }
                        else
                            here = here->left;
                    }
                }
            }


