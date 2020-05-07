// Question - cousins in Binary Tree

/*

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.



Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false


Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.

*/


// SOlution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL) {
            return false;
        }

        map <int , pair<int,int>> m;  // node  parent,depth
        TreeNode* temp = root;
        int depth = 0;
        queue<pair<TreeNode *,int>> q;  // TreeNode,depth
        q.push(make_pair(root,0));
        m[root -> val] = make_pair(NULL , 0);

        while(!q.empty()) {
            temp = q.front().first;
            int currDepth = q.front().second;
            q.pop();
            if(temp -> left) {
                m[temp -> left -> val] = make_pair(temp -> val , currDepth + 1);
                q.push(make_pair(temp -> left , currDepth + 1));
            }

            if(temp -> right) {
                m[temp -> right -> val] = make_pair(temp -> val , currDepth + 1);
                q.push(make_pair(temp -> right , currDepth + 1 ));
            }
        }

         map <int , pair<int,int>> :: iterator it;

        // for(it = m.begin() ; it != m.end() ; it++) {
        //     cout << it -> first << " " << it -> second.first << " " << it -> second.second << endl;
        // }

         if(m[x].first != m[y].first && m[x].second == m[y].second) {
             return true;
         }

        return false;

    }
};
