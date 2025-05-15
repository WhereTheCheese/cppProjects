#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

enum Color { RED, BLACK };

//you see its RB insted of BST becase it is red black tree
class RBNode {
public:
    int data;
    Color color;
    RBNode* left, *right, *parent;

    RBNode(int val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBTree {
private:
    RBNode* root;
    RBNode* NIL;

    //x around righth child
    void leftRotate(RBNode* x) {
        RBNode* y = x->right;
        x->right = y->left;
        if (y->left != NIL)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

  //y around other child
    void rightRotate(RBNode* y) {
        RBNode* x = y->left;
        y->left = x->right;
        if (x->right != NIL)
            x->right->parent = y;
        x->parent = y->parent;
        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->right)
            y->parent->right = x;
        else
            y->parent->left = x;
        x->right = y;
        y->parent = x;
    }

   //fix if its red or black aftet he insertion happens
    void fixInsert(RBNode* z) {
        while (z->parent != nullptr && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                RBNode* y = z->parent->parent->right; //Unlce (or anunt)
                if (y->color == RED) {
                     //Case 1 uncle (or aunt, idc) is red
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                      //Case 2 triangle
                        z = z->parent;
                        leftRotate(z);
                    }
                    //Case 3 line
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                RBNode* y = z->parent->parent->left; //Uncle (or, again, aunt) on other side
                if (y->color == RED) {
                   //Case 1 uncle (or, again, aunt) is red
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                       //Case 2 triangle
                        z = z->parent;
                        rightRotate(z);
                    }
                    //Case 3 line
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }
  //recursive helper to print the tree
    void transplant(RBNode* u, RBNode* v) {
        if (u->parent == nullptr) root = v;
        else if (u == u->parent->left) u->parent->left = v;
        else u->parent->right = v;
        v->parent = u->parent;
    }

    RBNode* treeMinimum(RBNode* x) {
        while (x->left != NIL)
            x = x->left;
        return x;
    }
//helper to do the delteion (I doint think this is the helper, this is what acctully does it)
    void fixDelete(RBNode* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                RBNode* w = x->parent->right;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        rightRotate(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                RBNode* w = x->parent->left;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        leftRotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }
//node deleation 
    void deleteNode(RBNode* z) {
        RBNode* y = z;
        RBNode* x;
        Color y_original_color = y->color;

        if (z->left == NIL) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == NIL) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = treeMinimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == BLACK)
            fixDelete(x);
    }
    //searches the tree for a node
    RBNode* searchTree(RBNode* node, int key) const {
        if (node == NIL || key == node->data)
            return node;
        if (key < node->data)
            return searchTree(node->left, key);
        return searchTree(node->right, key);
    }
    //recursive helper to print the tree
    void printHelper(RBNode* root, int space) const {
        if (root == NIL) return;
        space += 10;
        printHelper(root->right, space);
        cout << endl;
        for (int i = 10; i < space; i++) cout << " ";
        cout << root->data << (root->color == RED ? "(R)" : "(B)")
             << " [Parent: " << (root->parent && root->parent != NIL ? to_string(root->parent->data) : "None") << "]" << endl;
        printHelper(root->left, space);
    }

public:
    //Constructor that initialize NIL adn the root
    RBTree() {
        NIL = new RBNode(0);
        NIL->color = BLACK;
        NIL->left = NIL->right = NIL;
        NIL->parent = nullptr;
        root = NIL;
    }
    //public insert function
    void insert(int val) {
        RBNode* z = new RBNode(val);
        RBNode* y = nullptr;
        RBNode* x = root;

      //standard BST insert
        while (x != NIL) {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        z->parent = y;
        if (y == nullptr)
            root = z;
        else if (z->data < y->data)
            y->left = z;
        else
            y->right = z;

        z->left = NIL;
        z->right = NIL;
        z->color = RED;

        fixInsert(z);  //Maintain RB properties
    }

  //remover function
    void remove(int val) {
        RBNode* z = searchTree(root, val);
        if (z == NIL) {
            cout << "Value " << val << " not found in the tree." << endl;
            return;
        }
        deleteNode(z);
    }
  //serch
    bool search(int val) const {
        return searchTree(root, val) != NIL;
    }

     //insert values from a file
    void insertFromFile(const string& filename) {
        ifstream file(filename);
        int num;
        if (!file) {
            cout << "Error: File could not be opened!" << endl;
            return;
        }
        while (file >> num) {
            if (num < 1 || num > 999) {
                cout << "Invalid number " << num << ", must be between 1 and 999." << endl;
                continue;
            }
            insert(num);
        }
        file.close();
    }

    //print tree in rotated format
    void printTree() const {
        printHelper(root, 0);
    }
};

int main() {
    RBTree tree;
    int choice, num;
    string filename;

    while (true) {
        cout << "\n1. Add numbers from console\n2. Add numbers from file\n3. Print the tree\n4. Search for a number\n5. Remove a number\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter numbers between 1 and 999 (-1 to stop): ";
                while (true) {
                    cin >> num;
                    if (num == -1) break;
                    if (num < 1 || num > 999) {
                        cout << "Invalid number, try again." << endl;
                        continue;
                    }
                    tree.insert(num);
                }
                break;
            case 2:
                cout << "Enter filename: ";
                cin >> filename;
                tree.insertFromFile(filename);
                break;
            case 3:
                tree.printTree();
                break;
            case 4:
                cout << "Enter number to search: ";
                cin >> num;
                cout << (tree.search(num) ? "Found" : "Not found") << endl;
                break;
            case 5:
                cout << "Enter number to remove: ";
                cin >> num;
                tree.remove(num);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
}
