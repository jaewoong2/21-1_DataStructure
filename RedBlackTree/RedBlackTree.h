#include <iostream>
#include <string>

enum Color { RED, BLACK };

struct node {
    int key;
    node *left = nullptr;
    node *right = nullptr;
    node *parent = nullptr;
    Color color = BLACK;
};

class RedBlackTree {
private:
    node* root;
    node* leafNode;
private:
    node* IsKey(const int &item);
    void Insert(const int &item);
    void InsertFixUp(node *z);
    void RotateLeft(node *x);
    void RotateRight(node *x);
    void print_helper(node *root, std::string indent, bool last);
    void Inorder(node *target);
    void postOrder(node *target);
    void preOrder(node *target);

public:
    RedBlackTree();
    void DisplayMenuBoard();
    void SelectMenu();
    void Insert_helper();
    void Order_helper();
};


node * RedBlackTree::IsKey(const int &item) {
    node *temp = root;
    node *parent = nullptr;

    while (temp != nullptr && temp->key != item) {
        parent = temp;
        temp = (item < parent->key) ? parent->left : parent->right;
    }

    return temp;
}

void RedBlackTree::Insert(const int &item) {
    node *searchNode = this->root;
    node *parentNode = nullptr;
    node *newNode = new node();

    // 새로운 노드 설정
    newNode->key = item;
    newNode->color = RED;
    newNode->parent = nullptr;
    newNode->left = leafNode;
    newNode->right = leafNode;

    // 반복문 결과 ---> searchNode: 삽입할 곳, parentNode: 삽입할 곳의 부모 노드
    while (searchNode != leafNode) {
        parentNode = searchNode;
        searchNode = (item < searchNode->key) ? searchNode->left : searchNode->right;
    }

    newNode->parent = parentNode;

    // 부모노드가 없으면, 새로운 노드가 Root Node 이다.
    if(parentNode == nullptr) {
        root = newNode;
    } else if(newNode->key > parentNode->key) {
        parentNode->right = newNode;
    } else {
        parentNode->left = newNode;
    }

    // 새로운 노드가 root 노드 일 때,
    if(newNode->parent == nullptr) {
        newNode->color = BLACK;
        return;
    }

    // z의 부모노드가 Root 노드 일때, Color 는 red
    if(newNode->parent->parent == nullptr) {
        return;
    }

    InsertFixUp(newNode);
}

void RedBlackTree::InsertFixUp(node *newNode) {
    // newNode 를 계속해서 바꾸면서 (부모 or 조부모 노드로 올라감) newNode 가 rootNode 될 때까지 반복한다.
    while (newNode != root && newNode->parent->color == RED) {
        node *grandparent = newNode->parent->parent;
        node *uncle = newNode->parent == grandparent->left ? grandparent->right : grandparent->left;
        bool side = newNode->parent == grandparent->left;

        // 1. ReColoring: ParentNode, UncleNode == RED // GrandParent == Black 일 때,
        // Parent, Uncle => Black, GrandParent => Red 로 색상을 바꾼다.
        // newNode 를 GrandParent 로 바꾸고 검사(반복문)를 다시 한다.
        if(uncle && uncle->color == RED) {
            newNode->parent->color = BLACK;
            uncle->color = BLACK;
            grandparent->color = RED;
            newNode = grandparent;
        } else {
            // 2. ReConstruct: ParentNode.Color == Red, UncleNode.Color == Black
            // 2.1 GrandParent, Parent, newNode 가 일진선상에 있지 않을 때,
            // newNode 를 parentNode 로 변경하고 변경한 newNode 를 기준으로 Rotate 시킨다.
            // Rotate 는 parentNode(newNode) 가 GrandParent 의 왼쪽 에 있을 때 RotateLeft
            // parentNode(newNode) 가 GrandParent 의 오른쪽 에 있을 때 RotateRight
            // Rotate 후, GrandParent, newNode(변경전), parentNode(변경전) 이 일직선이 된다.
            // newNode(변경전) 이 parentNode(변경전) 의 부모 노드가 된다
            if (newNode == (side ? newNode->parent->right : newNode->parent->left)) {
                newNode = newNode->parent;
                side ? RotateLeft(newNode) : RotateRight(newNode);
            }
            // 2.2 GrandParent, Parent, newNode 가 일진선상에 있을 때,
            // 2.1 이 진행 된 후 이거나, 원래부터 일직선상에 있을 때 grandParent 를 기준으로 Rotate 를 한다.
            // Rotate 는 parentNode 가 GrandParent 의 왼쪽 에 있을 때 RotateRight
            // parentNode(newNode) 가 GrandParent 의 오른쪽 에 있을 때 RotateLeft
            // Rotate 후, GrandParent 의 색을 Red, Parent 의 색상을 Black 으로 변경한다.
            // parentNode 는 grandParentNode 의 부모노드가 된다.
            newNode->parent->color = BLACK;
            grandparent->color = RED;
            side ? RotateRight(grandparent) : RotateLeft(grandparent);
        }
    }

    // 만약, root 가 recoloring 이 되면 Red 가 될 수 있기 때문에 root 를 Black 으로 고정시킨다.
    root->color = BLACK;
}

// 매개변수로 들어온 중심 노드를 기준으로 왼쪽으로 회전한다.
// 중심 노드의 오른쪽 노드가 중심 노드의 위치로 올라가고 (중심노드의 오른쪽노드가 중심노드의 부모노드가 된다)
// 오른쪽 노드의 왼쪽노드로 중심노드가 내려간다. 또한, 오른쪽노드의 원래있던 왼쪽노드는 중심 노드의 오른쪽 노드로 간다.
void RedBlackTree::RotateLeft(node *centerNode) {
    node* rightNode;
    rightNode = centerNode->right;
    centerNode->right = rightNode->left;
    if(rightNode->left != leafNode) {
        rightNode->left->parent = centerNode;
    }
    rightNode->parent = centerNode->parent;
    if(!centerNode->parent) {
        root = rightNode;
    } else if(centerNode == centerNode->parent->left) {
        centerNode->parent->left = rightNode;
    } else {
        centerNode->parent->right = rightNode;
    }
    centerNode->parent = rightNode;
    rightNode->left = centerNode;
}

// 매개변수로 들어온 중심 노드를 기준으로 오른쪽으로 회전한다.
// 중심 노드의 왼쪽 노드가 중심 노드의 위치로 올라가고 (중심노드의 왼쪽노드가 중심노드의 부모노드가 된다)
// 왼쪽 노드의 오른쪽노드로 중심노드가 내려간다. 또한, 왼쪽노드의 원래있던 오른쪽노드는 중심 노드의 왼쪽 노드로 간다.
void RedBlackTree::RotateRight(node *centerNode) {
    node* leftNode;
    leftNode = centerNode->left;
    centerNode->left = leftNode->right;
    if(leftNode->right != leafNode) {
        leftNode->right->parent = centerNode;
    }
    leftNode->parent = centerNode->parent;
    if(!centerNode->parent) {
        root = leftNode;
    } else if(centerNode == centerNode->parent->left) {
        centerNode->parent->left = leftNode;
    } else {
        centerNode->parent->right = leftNode;
    }
    centerNode->parent = leftNode;
    leftNode->right = centerNode;
}

void RedBlackTree::print_helper(node *root_, std::string indent, bool last) {

    // print the tree structure on the screen
    if (root_ != leafNode) {
        std::cout << indent;
        if (last) {
            std::cout << "R----";
            indent += "     ";
        }
        else {
            std::cout << "L----";
            indent += "|    ";
        }

        std::string sColor = (root_->color == RED) ? "RED" : "BLACK";
        std::cout << root_->key << "(" << sColor << ")" << std::endl;
        print_helper(root_->left, indent, false);
        print_helper(root_->right, indent, true);
    }
}

/*중위순회*/
void RedBlackTree::Inorder(node* target)
{
    if (target == leafNode)
        return;
    Inorder(target->left);
    std::cout << target->key << " ";
    Inorder(target->right);
}
/*후위순회*/
void RedBlackTree::postOrder(node* target)
{
    if (target == leafNode)
        return;
    postOrder(target->left);
    postOrder(target->right);
    std::cout << target->key << " ";
}
/*전위순회*/
void RedBlackTree::preOrder(node* target)
{
    if (target == leafNode)
        return;
    std::cout << target->key << " ";
    preOrder(target->left);
    preOrder(target->right);
}

RedBlackTree::RedBlackTree() {
    leafNode = new node;
    leafNode->color = BLACK;
    leafNode->left = nullptr;
    leafNode->right = nullptr;
    leafNode->parent = nullptr;
    root = leafNode;
}

void RedBlackTree::DisplayMenuBoard()
{
    std::cout << "               Menu " << std::endl;
    std::cout << "          1. Insert Key     " << std::endl;
    std::cout << "          3. Show Tree      " << std::endl;
    std::cout << "          4. choose order   " << std::endl;
    std::cout << "          5. show Menu      " << std::endl;
    std::cout << "          6. clear Display  " << std::endl;
    std::cout << "          7. exit           " << std::endl;
    std::cout << std::endl;
}
void RedBlackTree::SelectMenu()
{
    DisplayMenuBoard();
    int i = -1;

    while (i != 8)
    {
        std::cout << "--> select   :   ";
        std::cin >> i;
        switch (i)
        {
            case 1:
                Insert_helper();
                break;
            case 3:
                print_helper(root, "", true);
                break;
            case 4:
                Order_helper();
                break;
            case 5:
                DisplayMenuBoard();
                break;
            case 6:
                system("cls");
                DisplayMenuBoard();
                break;
            case 7:
                return;
            default:
                std::cout << " !!! Wrong entered !!!\n"
                          << std::endl;
        }
    }
}

void RedBlackTree::Insert_helper()
{
    int item;
    std::cout << "Key to insert  :  ";
    std::cin >> item;
    if (IsKey(item))
    {
        std::cout << "!!! " << item << " is already exists !!!\n";
        return;
    }
    Insert(item);
}

void RedBlackTree::Order_helper()
{
    int i;
    std::cout << "         == Order Menu ==" << std::endl;
    std::cout << "          1. PreOrder" << std::endl;
    std::cout << "          2. InOrder" << std::endl;
    std::cout << "          3. PostOrder" << std::endl;
    std::cout << "          4. exit" << std::endl;
    std::cout << " --> select  :  ";

    std::cin >> i;
    switch (i)
    {
        case 1:
            preOrder(this->root);
            std::cout << std::endl;
            break;
        case 2:
            Inorder(this->root);
            std::cout << std::endl;
            break;
        case 3:
            preOrder(this->root);
            std::cout << std::endl;
            break;
        case 4:
            return;
        default:
            std::cout << " !!! Wrong enter !!!\n"
                      << std::endl;
            break;
    }
    return;
}
