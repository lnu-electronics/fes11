#include <iostream>

typedef int datatype;

struct Node
{
datatype key; // Інформаційне поле (ключ) вузла
Node* parent; // Вказівник на батьківський вузол
Node* left; // Вказівник на лівого сина
Node* right; // Вказівник на правого сина
};

void CreateTree(Node** pNode, int n)
{
    datatype data;

    if (n == 0)
    {
        *pNode = nullptr;
        return;
    }
    else
    {
        *pNode = new Node;
        std::cout << "Input key: ";
        std::cin >> data;
        (*pNode)->key = data;
        (*pNode)->left = (*pNode)->right =  nullptr;
        //std::cout << "n = " << n << '\n';
        CreateTree(&((*pNode)->left), n/2);
        CreateTree(&((*pNode)->right), n - n/2 - 1);
    }
}
void ShowTree(Node* pNode, int L);
////////////////////////////////////
void PostfixOrder(Node* pNode)
{
    if (pNode == nullptr) return;
    PostfixOrder(pNode->left);
    PostfixOrder(pNode->right);
    std::cout << pNode->key << '\n';
}
//-------------------------------------
void InfixOrder(Node* pNode)
{
    if (pNode == nullptr) return;
    PostfixOrder(pNode->left);
    std::cout << pNode->key << '\n';
    PostfixOrder(pNode->right);   
}
void PrefixOrder(Node* pNode)
{
    if (pNode == nullptr) return;
    std::cout << pNode->key << '\n';
    PostfixOrder(pNode->left);
    PostfixOrder(pNode->right);   
}

int main()
{
    Node *root = nullptr;
    int n = 5;

    CreateTree(&root, n);
    ShowTree(root, 0);
    std::cout << "---------------------\n";
    PrefixOrder(root);
    std::cout << "---------------------\n";
    InfixOrder(root);
    std::cout << "---------------------\n";
    PostfixOrder(root);
    std::cout << "---------------------\n";


}
//////////////////////////////////////////
void ShowTree(Node* pNode, int L)
{
    int w = 3;
    if (pNode == nullptr) return;
    ShowTree(pNode->right, L+w);
    for (int i = 0; i < L; ++i) std::cout << ' ';
    std:: cout << pNode->key << '\n';
    ShowTree(pNode->left, L+w);
}