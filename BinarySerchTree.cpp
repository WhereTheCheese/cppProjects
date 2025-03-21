#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; 

//BTW BST stand for Binary Serch Tree
class BST {
private:
    TreeNode* root;

    //helper function to insert a number into the tree
    TreeNode* insertHelper(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->data) {
            node->left = insertHelper(node->left, val);
        } else {
            node->right = insertHelper(node->right, val);
        }
        return node;
    }

    //helper function to find the smallest number in a subtree
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    //Helper function to remove a number from the tree
    TreeNode* removeHelper(TreeNode* node, int val) {
        if (node == nullptr) return nullptr;

        if (val < node->data) {
            node->left = removeHelper(node->left, val);
        } else if (val > node->data) {
            node->right = removeHelper(node->right, val);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            //Moves around the nodes in the subtrees
            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeHelper(node->right, temp->data);
        }
        return node;
    }

    //Serches for values in the tree
    bool searchHelper(TreeNode* node, int val) {
        if (node == nullptr) return false;
        if (node->data == val) return true;
        if (val < node->data) return searchHelper(node->left, val);
        return searchHelper(node->right, val);
    }

    //printing the tree
    void printTreeHelper(TreeNode* node, int space) {
        if (node == nullptr) return;

        space += 10;
        printTreeHelper(node->right, space);

        cout << endl;
        for (int i = 10; i < space; i++) cout << " ";
        cout << node->data << "\n";

        printTreeHelper(node->left, space);
    }

public:
    BST() {
        root = nullptr;
    }

    //Adds numbers
    void insert(int val) {
        root = insertHelper(root, val);
    }

    //public function to remove a number
    void remove(int val) {
        root = removeHelper(root, val);
    }

    //Public function to search for a num
    bool search(int val) {
        return searchHelper(root, val);
    }

    // print tree
    void printTree() {
        printTreeHelper(root, 0);
    }
};


int main() {
    BST tree;
    int choice, num;
    string filename;

    while (true) {
        cout << "\n1. Add numbers from console\n2. Add numbers from file\n3. Remove a number\n4. Search for a number\n5. Print the tree\n6. Exit\n";
        cout << "Enter your choice of number: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter numbers between 1 and 999 (enter -1 to stop, also push enter in between numbers): ";
                while (true) {
                    cin >> num;
                    if (num == -1) break;
                    if (num < 1 || num > 999) {
                        cout << "Invalid and wrong number. Please enter a number between 1 and 999.\n";
                        continue;
                    }
                    tree.insert(num);
                }
                break;

            case 2: {
                cout << "Enter the filename: ";
                cin >> filename;
                ifstream file(filename);
                if (!file) {
                    cout << "File not found! oh no! This is not good! \n";
                    break;
                }
                while (file >> num) {
                    if (num < 1 || num > 999) {
                        cout << "The number in the file is INVALID! Oh No!" << num << "." << endl;
                        continue;
                    }
                    tree.insert(num);
                }
                file.close();
                break;
            }

            case 3:
                cout << "Enter the number you would like to remove: ";
                cin >> num;
                tree.remove(num);
                break;

            case 4:
                cout << "Enter the number to search: ";
                cin >> num;
                if (tree.search(num)) {
                    cout << num << " is in the tree :)" << endl;
                } else {
                    cout << num << " is not in the tree :(" << endl;
                }
                break;

            case 5:
                cout << "Tree structure:\n";
                tree.printTree();
                break;

            case 6:
                cout << "Goodby. I hope you liked looking at binary tree. we should plant more trees tbh\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
