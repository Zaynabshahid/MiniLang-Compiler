#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

using namespace std;

class ASTNode
{
public:
    string type;
    string value;
    vector<ASTNode*> children;

    ASTNode(string t, string v = "")
    {
        type = t;
        value = v;
    }

    void addChild(ASTNode* node)
    {
        children.push_back(node);
    }
};

#endif