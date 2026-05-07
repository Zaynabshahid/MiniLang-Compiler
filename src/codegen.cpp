#include <iostream>
#include <string>
#include "ast.h"

using namespace std;

string generateExpr(ASTNode* node)
{
    if(!node) return "";
    
    if(node->type == "NUMBER" || node->type == "FLOATNUM" || node->type == "ID")
    {
        return node->value;
    }

    if(node->type == "ADD")
    {
        return generateExpr(node->children[0]) + " + " + generateExpr(node->children[1]);
    }

    if(node->type == "SUB")
    {
        return generateExpr(node->children[0]) + " - " + generateExpr(node->children[1]);
    }

    if(node->type == "MUL")
    {
        return generateExpr(node->children[0]) + " * " + generateExpr(node->children[1]);
    }

    if(node->type == "DIV")
    {
        return generateExpr(node->children[0]) + " / " + generateExpr(node->children[1]);
    }

    if(node->type == "MOD")
    {
        return generateExpr(node->children[0]) + " % " + generateExpr(node->children[1]);
    }

    if(node->type == "LT")
    {
        return generateExpr(node->children[0]) + " < " + generateExpr(node->children[1]);
    }

    if(node->type == "GT")
    {
        return generateExpr(node->children[0]) + " > " + generateExpr(node->children[1]);
    }

    if(node->type == "LTE")
    {
        return generateExpr(node->children[0]) + " <= " + generateExpr(node->children[1]);
    }

    if(node->type == "GTE")
    {
        return generateExpr(node->children[0]) + " >= " + generateExpr(node->children[1]);
    }

    if(node->type == "EQ")
    {
        return generateExpr(node->children[0]) + " == " + generateExpr(node->children[1]);
    }

    if(node->type == "NEQ")
    {
        return generateExpr(node->children[0]) + " != " + generateExpr(node->children[1]);
    }

    if(node->type == "FUNC_CALL")
    {
        string result = node->children[0]->value + "(";
        if(node->children.size() > 1 && node->children[1]->type == "ARGS")
        {
            for(size_t i = 0; i < node->children[1]->children.size(); i++)
            {
                if(i > 0) result += ", ";
                result += generateExpr(node->children[1]->children[i]);
            }
        }
        result += ")";
        return result;
    }

    return "";
}

void generatePython(ASTNode* node, int indent = 0)
{
    if(node == nullptr)
        return;

    string indentStr(indent, ' ');

    if(node->type == "DECL_INT" || node->type == "DECL_FLOAT")
    {
        string varName = node->children[0]->value;
        
        if(node->children.size() > 1)
        {
            cout << indentStr << varName << " = " << generateExpr(node->children[1]) << endl;
        }
        else
        {
            cout << indentStr << varName << " = 0" << endl;
        }
    }
    else if(node->type == "ASSIGN")
    {
        cout << indentStr << node->children[0]->value << " = " << generateExpr(node->children[1]) << endl;
    }
    else if(node->type == "PRINT")
    {
        cout << indentStr << "print(" << generateExpr(node->children[0]) << ")" << endl;
    }
    else if(node->type == "IF")
    {
        cout << indentStr << "if " << generateExpr(node->children[0]) << ":" << endl;
        
        if(node->children[1]->type == "BLOCK")
        {
            generatePython(node->children[1], indent + 4);
        }
        else
        {
            generatePython(node->children[1], indent + 4);
        }

        if(node->children.size() > 2 && node->children[2])
        {
            generatePython(node->children[2], indent);
        }
    }
    else if(node->type == "ELSE")
    {
        cout << indentStr << "else:" << endl;
        if(node->children[0]->type == "BLOCK")
        {
            generatePython(node->children[0], indent + 4);
        }
        else
        {
            generatePython(node->children[0], indent + 4);
        }
    }
    else if(node->type == "WHILE")
    {
        cout << indentStr << "while " << generateExpr(node->children[0]) << ":" << endl;
        
        if(node->children[1]->type == "BLOCK")
        {
            generatePython(node->children[1], indent + 4);
        }
        else
        {
            generatePython(node->children[1], indent + 4);
        }
    }
    else if(node->type == "FUNC_DECL")
    {
        string funcName = node->children[0]->value;
        cout << indentStr << "def " << funcName << "(";
        
        if(node->children.size() > 2 && node->children[1]->type == "PARAMS")
        {
            for(size_t i = 0; i < node->children[1]->children.size(); i++)
            {
                if(i > 0) cout << ", ";
                cout << node->children[1]->children[i]->children[0]->value;
            }
        }
        
        cout << "):" << endl;
        
        int blockIdx = node->children.size() - 1;
        generatePython(node->children[blockIdx], indent + 4);
    }
    else if(node->type == "RETURN")
    {
        if(node->children.size() > 0)
        {
            cout << indentStr << "return " << generateExpr(node->children[0]) << endl;
        }
        else
        {
            cout << indentStr << "return" << endl;
        }
    }
    else if(node->type == "BLOCK")
    {
        if(node->children.size() > 0)
        {
            generatePython(node->children[0], indent);
        }
    }

    if(node->type != "IF" && node->type != "ELSE" && node->type != "WHILE" && 
       node->type != "FUNC_DECL" && node->type != "BLOCK")
    {
        for(auto child : node->children)
        {
            generatePython(child, indent);
        }
    }
}