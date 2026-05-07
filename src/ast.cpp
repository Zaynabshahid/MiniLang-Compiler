#include <iostream>
#include "ast.h"

using namespace std;

void printAST(ASTNode* node, int level = 0)
{
    if(node == nullptr) return;

    for(int i = 0; i < level; i++)
        cout << "  ";

    cout << node->type;

    if(node->value != "")
        cout << " : " << node->value;

    cout << endl;

    for(auto child : node->children)
        printAST(child, level + 1);
}