#include <iostream>
#include<Windows.h>
#include"BinarySearchTree.hpp"
using namespace std;
int a[1000];
void showFunction(bool isBST);
void BinarySearchTreeOperation(BinarySearchTree<int>& T, int op);
void BinaryTreeOperation(BinaryTree<int>&T,int op);

int main()
{
    int TreeChoice;
    cout << "Choose your choice" << endl;
    cout << "[1]Binary Tree\n[2]Binary Search Tree\n[3]Exit\n";
    cin >> TreeChoice;
    cout << "#############################################" << endl;

    int choice;
    if (TreeChoice == 1)
    {

        cout << "Your Choice:1\nThen initialize the tree" << endl;
        cout << "Please input the preorder sequence list with zero of the tree" << endl;
        BinaryTree<int>T;
   //     system("cls");
        T.CreateTreeByPreOrder();
       showFunction(0);
        while (1)
        {
           
            cout << "Input your choice" << endl;
            cin >> choice;
            BinaryTreeOperation(T,choice);
            showFunction(0);
        }

    }
    else if (TreeChoice == 2)
    {
        cout << "Your Choice:2\nThen initialize the tree" << endl;
        int numbers;
        cout << "Please input the nodes of trees" << endl;
        cin >> numbers;
        cout << "Input "<<numbers<<" datas in the Binary Search Tree" << endl;
        for (int i = 0; i < numbers; i++)
            cin >> a[i];
        BinarySearchTree<int>T(a,numbers);
        showFunction(1);
        while (1)
        {
            
            cout << "Input your choice" << endl;
            cin >> choice;
            BinarySearchTreeOperation(T, choice);

        }

    }
    else
    {
        cout << "Invalid Choice" << endl;

        return 0;
    }
    return 0;
}
void showFunction(bool isBST)
{
    cout << "###Function of Tree###" << endl;
    cout << "[0]Show Function meun\n[1]Preorder traversal\n[2]Inorder traversal\n[3]Postorder traversal\n[4]Levelorder traversal\n[5]Height of the tree\n[6]Width of the tree\n[7]Number of node with degree n\n[8]Exit\n";
    if (isBST)
    {
        cout << "[9]Insert an element\n[10]Remove an element\n[11]Search an element\n";
    }
}

void BinarySearchTreeOperation(BinarySearchTree<int>& T, int op)
{   
   // system("cls");
    
    switch (op)
    {
    case 0:
    {
        showFunction(1); 
        break;
    }
    case 1:
    {
        T.PreOrder();
        break;
    }
    case 2:
    {
        T.InOrder();
        break;
    }
    case 3:
    {
        T.PostOrder();
        break;
    }
    case 4:
    {
        T.LevelOrder();
        break;
    }
    case 5:
    {
        cout << "The height of the tree is " << T.GetDepth() << endl;
        break;
    }
    case 6:
    {
        cout << "The width of the tree is " << T.GetWidth() << endl;
        break;
    }
    case 7:
    {
        cout << "Input the degree of nodes" << endl;
        int k;
        cin >> k;
        cout << "Number of node with degree " << k << " is " << T.CalcDegree(k) << endl;
        break;
    }
    case 8:
    {
        exit(0);
    }
    case 9:
    {
        cout << "Input the number to be inserted" << endl;
        int number;
        cin >> number;
        if (T.InsertBST(number))
            cout << "Insert completed!" << endl;
        else
            cout << "Insert failed,the element has already exists in the tree" << endl;
        break;
    }
    case 10:
    {
        cout << "Input the number to be removed in the tree" << endl;
        int number;
        cin >> number;
        if (T.Remove(number))
            cout << "Remove completed!" << endl;
        else
            cout << "Remove failed,the element does not exists in the tree" << endl;
        break;
    }
    case 11:
    {
        cout << "Input the number to be searched" << endl;
        int number;
        cin >> number;
        auto p = T.SearchBST(number);
        if (p == NULL)
        {
            cout << "The number does not exist in the tree" << endl;
        }
        else
        {
            cout << "The number exists in the tree" << endl;
        }
        break;
    }
    default:
    {
        cout << "Invalid choice" << endl;
        break;
    }

    }
    cout << "--------------------------------------------" << endl;
}
void BinaryTreeOperation(BinaryTree<int>& T, int op)
{
//system("cls");
   
    switch (op)
    {
    case 0:
    {
        showFunction(1);
        break;
    }
    case 1:
    {
        T.PreOrder();
        break;
    }
    case 2:
    {
        T.InOrder();
        break;
    }
    case 3:
    {
        T.PostOrder();
        break;
    }
    case 4:
    {
        T.LevelOrder();
        break;
    }
    case 5:
    {
        cout << "The height of the tree is " << T.GetDepth() << endl;
        break;
    }
    case 6:
    {
        cout << "The width of the tree is " << T.GetWidth() << endl;
        break;
    }
    case 7:
    {
        cout << "Input the degree of nodes" << endl;
        int k;
        cin >> k;
        cout << "Number of node with degree " << k << " is " << T.CalcDegree(k) << endl;
        break;
    }
    default:
    {
        cout << "Invalid choice" << endl;
        break;
    }

    }
    cout << "--------------------------------------------" << endl;
}