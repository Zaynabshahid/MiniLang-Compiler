#include "ast.h"
#include <string>

using namespace std;

ASTNode* optimize(ASTNode* node)
{
    if(!node) return nullptr;

    // optimize children first
    for(auto &child : node->children)
        child = optimize(child);

    // constant folding
    if(node->type == "ADD")
    {
        if(node->children[0]->type == "NUMBER" &&
           node->children[1]->type == "NUMBER")
        {
            int a = stoi(node->children[0]->value);
            int b = stoi(node->children[1]->value);
            return new ASTNode("NUMBER", to_string(a + b));
        }
    }
    else if(node->type == "SUB")
    {
        if(node->children[0]->type == "NUMBER" &&
           node->children[1]->type == "NUMBER")
        {
            int a = stoi(node->children[0]->value);
            int b = stoi(node->children[1]->value);
            return new ASTNode("NUMBER", to_string(a - b));
        }
    }
    else if(node->type == "MUL")
    {
        if(node->children[0]->type == "NUMBER" &&
           node->children[1]->type == "NUMBER")
        {
            int a = stoi(node->children[0]->value);
            int b = stoi(node->children[1]->value);
            return new ASTNode("NUMBER", to_string(a * b));
        }
        // Multiplication by 0
        if(node->children[0]->type == "NUMBER" && stoi(node->children[0]->value) == 0)
            return new ASTNode("NUMBER", "0");
        if(node->children[1]->type == "NUMBER" && stoi(node->children[1]->value) == 0)
            return new ASTNode("NUMBER", "0");
        // Multiplication by 1
        if(node->children[0]->type == "NUMBER" && stoi(node->children[0]->value) == 1)
            return node->children[1];
        if(node->children[1]->type == "NUMBER" && stoi(node->children[1]->value) == 1)
            return node->children[0];
    }
    else if(node->type == "DIV")
    {
        if(node->children[0]->type == "NUMBER" &&
           node->children[1]->type == "NUMBER")
        {
            int a = stoi(node->children[0]->value);
            int b = stoi(node->children[1]->value);
            if(b != 0)
                return new ASTNode("NUMBER", to_string(a / b));
        }
        // Division by 1
        if(node->children[1]->type == "NUMBER" && stoi(node->children[1]->value) == 1)
            return node->children[0];
    }
    else if(node->type == "MOD")
    {
        if(node->children[0]->type == "NUMBER" &&
           node->children[1]->type == "NUMBER")
        {
            int a = stoi(node->children[0]->value);
            int b = stoi(node->children[1]->value);
            if(b != 0)
                return new ASTNode("NUMBER", to_string(a % b));
        }
    }
    // Handle comparisons with constant folding
    else if(node->type == "LT" || node->type == "GT" || 
            node->type == "LTE" || node->type == "GTE" ||
            node->type == "EQ" || node->type == "NEQ")
    {
        if(node->children[0]->type == "NUMBER" &&
           node->children[1]->type == "NUMBER")
        {
            int a = stoi(node->children[0]->value);
            int b = stoi(node->children[1]->value);
            
            bool result = false;
            if(node->type == "LT") result = (a < b);
            else if(node->type == "GT") result = (a > b);
            else if(node->type == "LTE") result = (a <= b);
            else if(node->type == "GTE") result = (a >= b);
            else if(node->type == "EQ") result = (a == b);
            else if(node->type == "NEQ") result = (a != b);
            
            return new ASTNode("NUMBER", result ? "1" : "0");
        }
    }

    return node;
}