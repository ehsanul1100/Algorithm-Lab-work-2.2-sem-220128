#include <iostream>
using namespace std;

void clear()
{
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

// Node structure
struct Node
{
    int data;
    Node *lchild;
    Node *rchild;
};

// Binary Search Tree class
struct Binary_search_tree
{
    Node *head = nullptr;

    // Add a node to the BST
    void addNode(int value)
    {
        Node *nptr = new Node;
        nptr->data = value;
        nptr->lchild = nptr->rchild = nullptr;

        if (head == nullptr)
        {
            head = nptr;
        }
        else
        {
            Node *temp = head;
            while (true)
            {
                if (temp->data >= value)
                {
                    if (temp->lchild == nullptr)
                    {
                        temp->lchild = nptr;
                        break;
                    }
                    else
                    {
                        temp = temp->lchild;
                    }
                }
                else
                {
                    if (temp->rchild == nullptr)
                    {
                        temp->rchild = nptr;
                        break;
                    }
                    else
                    {
                        temp = temp->rchild;
                    }
                }
            }
        }
    }

    // Pre-order traversal
    void preorder(Node *node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
            preorder(node->lchild);
            preorder(node->rchild);
        }
    }

    // In-order traversal
    void inorder(Node *node)
    {
        if (node != nullptr)
        {
            inorder(node->lchild);
            cout << node->data << " ";
            inorder(node->rchild);
        }
    }

    // Post-order traversal
    void postorder(Node *node)
    {
        if (node != nullptr)
        {
            postorder(node->lchild);
            postorder(node->rchild);
            cout << node->data << " ";
        }
    }

    // Display pre-order traversal
    void display_pre_order()
    {
        cout << "Pre-order: ";
        preorder(head);
        cout << endl;
    }

    // Display in-order traversal
    void display_in_order()
    {
        cout << "In-order: ";
        inorder(head);
        cout << endl;
    }

    // Display post-order traversal
    void display_post_order()
    {
        cout << "Post-order: ";
        postorder(head);
        cout << endl;
    }
};

int main()
{
    Binary_search_tree binary_search_tree;
    int a = 0;

    while (true)
    {
        cout << "\n1. Insert\n2. Pre-order\n3. In-order\n4. Post-order\n5. Exit\nChoose an option: ";
        cin >> a;

        if (a == 1)
        {
            int v;
            cout << "Enter value: ";
            cin >> v;
            binary_search_tree.addNode(v);
            clear();
        }
        else if (a == 2)
        {
            clear();
            binary_search_tree.display_pre_order();
        }
        else if (a == 3)
        {
            clear();
            binary_search_tree.display_in_order();
        }
        else if (a == 4)
        {
            clear();
            binary_search_tree.display_post_order();
        }
        else if (a == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid option! Please try again." << endl;
        }
    }

    return 0;
}