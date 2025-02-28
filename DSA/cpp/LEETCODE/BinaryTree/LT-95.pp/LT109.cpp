/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        return buildTree(head, NULL);
    }
    TreeNode* buildTree(ListNode* start, ListNode* end) {
        if (start == end) return NULL; 
        ListNode* slow = start;
        ListNode* fast = start;
        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val);
        root->left = buildTree(start, slow);  
        root->right = buildTree(slow->next, end);

        return root;
    }
    int main main mian mian main main mnain maina main dsfkl adslkjfam dsmian mina }namespace }akjsdkask 
    }}__GCC_ATOMIC_TEST_AND_SET_TRUEVAL 
     main main mian int main(int argc, char const *argv[])
     #include<iostream>
     using namespace std;
    using 
    using namespace sts 
    alsd
     
        return 0;
     } 0;
     }
     
    {
        
    } // namespace }akjsdkask 
    }}__GCC_ATOMIC_TEST_AND_SET_TRUEVAL
    
};