//Luke 1113541 2024/11/28

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<int>& levelOrder) {
    if (levelOrder.empty() || levelOrder[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(levelOrder[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;

    while (i < levelOrder.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (levelOrder[i] != -1) {
            current->left = new TreeNode(levelOrder[i]);
            q.push(current->left);
        }
        i++;

        if (i < levelOrder.size() && levelOrder[i] != -1) {
            current->right = new TreeNode(levelOrder[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int calculateDiameter(TreeNode* root, int& diameter) {
    if (!root) return 0;

    int leftHeight = calculateDiameter(root->left, diameter);
    int rightHeight = calculateDiameter(root->right, diameter);

    // Update the diameter to count the number of nodes in the longest path
    diameter = max(diameter, leftHeight + rightHeight + 1);

    return max(leftHeight, rightHeight) + 1;
}

int getDiameter(TreeNode* root) {
    int diameter = 0;
    calculateDiameter(root, diameter);
    return diameter;
}

int main() {
    vector<int> levelOrder;
    int val;
    while (cin >> val) {
        levelOrder.push_back(val);
        if (cin.peek() == ',') cin.ignore();
    }

    TreeNode* root = buildTree(levelOrder);
    cout << getDiameter(root) << endl;

    return 0;
}
