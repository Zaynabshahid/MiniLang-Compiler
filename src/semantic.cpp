#include <iostream>
#include <string>
#include <set>
#include "ast.h"
#include "symbol_table.h"

using namespace std;

SymbolTable symtab;
set<string> declaredVars;

string getCurrentType(ASTNode* node)
{
    if(!node) return "unknown";
    
    if(node->type == "NUMBER") return "int";
    if(node->type == "FLOATNUM") return "float";
    if(node->type == "ID")
    {
        if(symtab.exists(node->value))
            return symtab.getType(node->value);
        return "unknown";
    }
    if(node->type == "ADD" || node->type == "SUB") return "int";
    if(node->type == "MUL" || node->type == "DIV" || node->type == "MOD") return "int";
    if(node->type == "LT" || node->type == "GT" || node->type == "LTE" || 
       node->type == "GTE" || node->type == "EQ" || node->type == "NEQ") return "bool";
    
    return "unknown";
}

void semanticCheck(ASTNode* node, int scope = 0)
{
    if(!node) return;

    if(node->type == "DECL_INT")
    {
        string varName = node->children[0]->value;
        
        if(symtab.exists(varName))
        {
            cout << "ERROR: Variable '" << varName << "' already declared\n";
        }
        else
        {
            symtab.insert(varName, "int", scope);
            if(node->children.size() > 1)
            {
                string exprType = getCurrentType(node->children[1]);
                if(exprType != "int" && exprType != "unknown")
                {
                    cout << "WARNING: Type mismatch in declaration: expected int, got " << exprType << "\n";
                }
            }
        }
    }
    else if(node->type == "DECL_FLOAT")
    {
        string varName = node->children[0]->value;
        
        if(symtab.exists(varName))
        {
            cout << "ERROR: Variable '" << varName << "' already declared\n";
        }
        else
        {
            symtab.insert(varName, "float", scope);
            if(node->children.size() > 1)
            {
                string exprType = getCurrentType(node->children[1]);
                if(exprType != "float" && exprType != "int" && exprType != "unknown")
                {
                    cout << "WARNING: Type mismatch in declaration: expected float, got " << exprType << "\n";
                }
            }
        }
    }
    else if(node->type == "ASSIGN")
    {
        string varName = node->children[0]->value;
        
        if(!symtab.exists(varName))
        {
            symtab.insert(varName, "int", scope);
        }
    }
    else if(node->type == "IF")
    {
        semanticCheck(node->children[0], scope);
        semanticCheck(node->children[1], scope + 1);
        if(node->children.size() > 2)
            semanticCheck(node->children[2], scope + 1);
    }
    else if(node->type == "WHILE")
    {
        semanticCheck(node->children[0], scope);
        semanticCheck(node->children[1], scope + 1);
    }
    else if(node->type == "FUNC_DECL")
    {
        string funcName = node->children[0]->value;
        symtab.insert(funcName, "function", scope);
        
        int blockIdx = node->children.size() - 1;
        if(node->children[blockIdx])
            semanticCheck(node->children[blockIdx], scope + 1);
    }

    for(auto child : node->children)
    {
        if(child && node->type != "IF" && node->type != "WHILE" && node->type != "FUNC_DECL")
            semanticCheck(child, scope);
    }
}