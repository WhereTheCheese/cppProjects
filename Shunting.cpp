#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;
    Node* next;

    Node(string val) : data(val), left(nullptr), right(nullptr), next(nullptr) {}
};

//Creates a new node and puts it on the top
void push(Node*& top, string val) {
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}
//Returns the value of the top node the has it go swimming with the fishes if you know what i mean 
string pop(Node*& top) {
    if (top == nullptr) return "";
    Node* temp = top;
    string val = temp->data;
    top = top->next;
    delete temp;
    return val;
}
//just shows the top value (less fun)
string peek(Node* top) {
    if (top == nullptr) return "";
    return top->data;
}

//I thought this was a fancy french word for much longer than I would like to admit smh
void enqueue(Node*& front, Node*& rear, string val) {
    //adds a node
    Node* newNode = new Node(val);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}
//I also thoguht this was a fancy french word and I googled it and relised how dumb I was being
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return "";
    Node* temp = front;
    string val = temp->data;
    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete temp;
    return val;
}
//I decided to use my own big word this time
int precedence(string op) {
    if (op == "^") return 4;
    if (op == "*" || op == "/") return 3;
    if (op == "+" || op == "-") return 2;
    return 0; 
}

bool isRight(string op) {
    return op == "^";
}
//if it is an operator (the like train cars is how i vusulize it)
bool isOperator(string token) {
    return token == "+" || token == "-" || token == "*" || token == "/" || token == "^";
}
//THE SHUNTING YARD like THE SHUNTING YARD
vector<string> shuntingYard(vector<string>& tokens) {
    Node* opStack = nullptr;
    Node* outputFront = nullptr;
    Node* outputRear = nullptr;
    for (string token : tokens) {
        //if it is a number it goes to the output
        if (isdigit(token[0])) {
            enqueue(outputFront, outputRear, token);
        } else if (token == "(") {
            push(opStack, token);
        } else if (token == ")") {
            while (peek(opStack) != "(") {
                string op = pop(opStack);
                if (op == "") {
                    cerr << "Error: Mismatched parentheses." << endl;
                    exit(1);
                }
                enqueue(outputFront, outputRear, op);
            }
            pop(opStack); 
        } else if (isOperator(token)) {
            while (opStack != nullptr && peek(opStack) != "(" &&
                   ((precedence(peek(opStack)) > precedence(token)) ||
                   (precedence(peek(opStack)) == precedence(token) && !isRight(token)))) {
                enqueue(outputFront, outputRear, pop(opStack));
            }
            push(opStack, token);
        } else {
            cerr << "Invalid token: " << token << endl;
            exit(1);
        }
    }

 //if there are still operators in the stack they go to the output
    while (opStack != nullptr) {
        string op = pop(opStack);
        if (op == "(" || op == ")") {
            cerr << "Error: Mismatched parentheses." << endl;
            exit(1);
        }
        enqueue(outputFront, outputRear, op);
    }
    //puts the output in a vector
    vector<string> postfix;
    while (outputFront != nullptr) {
        postfix.push_back(dequeue(outputFront, outputRear));
    }
    return postfix;
}

//grows the tree (well it builts the tree, but like it is a tree so it grows)
Node* buildTree(vector<string>& postfix) {
    Node* treeStack = nullptr;
//if it is a number it goes to the stack
    for (string token : postfix) {
        if (isdigit(token[0])) {
            Node* newNode = new Node(token);
            newNode->next = treeStack;
            treeStack = newNode;
        } else {
            Node* right = nullptr;
            Node* left = nullptr;
            if (treeStack != nullptr) {
                right = treeStack;
                treeStack = treeStack->next;
                right->next = nullptr;
            }
            if (treeStack != nullptr) {
                left = treeStack;
                treeStack = treeStack->next;
                left->next = nullptr;
            }
            if (left == nullptr || right == nullptr) {
                cerr << "Invalid expression." << endl;
                exit(1);
            }
            Node* newNode = new Node(token);
            newNode->left = left;
            newNode->right = right;
            newNode->next = treeStack;
            treeStack = newNode;
        }
    }

    if (treeStack == nullptr) {
        cerr << "Error building expression tree." << endl;
        exit(1);
    }

    return treeStack;
}

//Print out the stuff
void printPrefix(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    printPrefix(node->left);
    printPrefix(node->right);
}

void printPostfix(Node* node) {
    if (node == nullptr) return;
    printPostfix(node->left);
    printPostfix(node->right);
    cout << node->data << " ";
}

bool isOperatorNode(Node* node) {
    return node != nullptr && node->left != nullptr && node->right != nullptr;
}
//prints the infix
void printInfix(Node* node) {
    if (node == nullptr) return;
//if it is an operator it prints the left side and the right side
    if (isOperatorNode(node)) {
        bool needLeftParen = false;
        if (isOperatorNode(node->left)) {
            int currentPrec = precedence(node->data);
            int leftPrec = precedence(node->left->data);
            if (leftPrec < currentPrec || (leftPrec == currentPrec && isRight(node->data))) {
                needLeftParen = true;
            }
        }
        if (needLeftParen) {
            cout << "( ";
            printInfix(node->left);
            cout << ") ";
        } else {
            printInfix(node->left);
        }

        cout << node->data << " ";

        bool needRightParen = false;
        if (isOperatorNode(node->right)) {
            int currentPrec = precedence(node->data);
            int rightPrec = precedence(node->right->data);
            if (rightPrec < currentPrec || (rightPrec == currentPrec && !isRight(node->data))) {
                needRightParen = true;
            }
        }
        if (needRightParen) {
            cout << "( ";
            printInfix(node->right);
            cout << ") ";
        } else {
            printInfix(node->right);
        }
    } else {
        cout << node->data << " ";
    }
}
//the main function (said in the narrorator voice from shreak)
int main() {
    string input;
    cout << "Enter the first string of numbers (space separated): ";
    getline(cin, input);

    vector<string> tokens;
    stringstream ss(input);
    string token;
    while (getline(ss, token, ' ')) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }

    vector<string> postfix = shuntingYard(tokens);

    cout << "Postfix expression: ";
    for (string s : postfix) {
        cout << s << " ";
    }
    cout << endl;

    Node* root = buildTree(postfix);

    string command;
    while (true) {
        cout << "Enter command (prefix, infix, postfix, exit): ";
        getline(cin, command);
        if (command == "exit") {
            break;
        } else if (command == "prefix") {
            printPrefix(root);
            cout << endl;
        } else if (command == "infix") {
            printInfix(root);
            cout << endl;
        } else if (command == "postfix") {
            printPostfix(root);
            cout << endl;
        } else {
            cout << "Invalid command." << endl;
        }
    }

    return 0;
}
