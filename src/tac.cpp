#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ast.h"

using namespace std;

int tempCount = 0;
int labelCount = 0;
vector<string> tacLines;

string newTemp()
{
    return "t" + to_string(++tempCount);
}

string newLabel()
{
    return "L" + to_string(++labelCount);
}

string getOperand(ASTNode* node)
{
    if(!node) return "";
    if(node->type == "NUMBER" || node->type == "FLOATNUM" || node->type == "ID")
        return node->value;
    return "";
}

void generateTACRec(ASTNode* node, string &lastTemp)
{
    if(node == nullptr)
        return;

    if(node->type == "ADD")
    {
        string left = getOperand(node->children[0]);
        string right = getOperand(node->children[1]);
        string t = newTemp();
        lastTemp = t;
        
        cout << t << " = " << left << " + " << right << endl;
        tacLines.push_back(t + " = " + left + " + " + right);
    }
    else if(node->type == "SUB")
    {
        string left = getOperand(node->children[0]);
        string right = getOperand(node->children[1]);
        string t = newTemp();
        lastTemp = t;
        
        cout << t << " = " << left << " - " << right << endl;
        tacLines.push_back(t + " = " + left + " - " + right);
    }
    else if(node->type == "MUL")
    {
        string left = getOperand(node->children[0]);
        string right = getOperand(node->children[1]);
        string t = newTemp();
        lastTemp = t;
        
        cout << t << " = " << left << " * " << right << endl;
        tacLines.push_back(t + " = " + left + " * " + right);
    }
    else if(node->type == "DIV")
    {
        string left = getOperand(node->children[0]);
        string right = getOperand(node->children[1]);
        string t = newTemp();
        lastTemp = t;
        
        cout << t << " = " << left << " / " << right << endl;
        tacLines.push_back(t + " = " + left + " / " + right);
    }
    else if(node->type == "MOD")
    {
        string left = getOperand(node->children[0]);
        string right = getOperand(node->children[1]);
        string t = newTemp();
        lastTemp = t;
        
        cout << t << " = " << left << " % " << right << endl;
        tacLines.push_back(t + " = " + left + " % " + right);
    }
    else if(node->type == "LT")
    {
        string left = getOperand(node->children[0]);
        string right = getOperand(node->children[1]);
        string t = newTemp();
        lastTemp = t;
        
        cout << t << " = " << left << " < " << right << endl;
        tacLines.push_back(t + " = " + left + " < " + right);
    }
    else if(node->type == "GT")
    {
        string left = getOperand(node->children[0]);
        string right = getOperand(node->children[1]);
        string t = newTemp();
        lastTemp = t;
        
        cout << t << " = " << left << " > " << right << endl;
        tacLines.push_back(t + " = " + left + " > " + right);
    }
    else if(node->type == "LTE")
    {
        string left = getOperand(node->children[0]);
        string right = getOperand(node->children[1]);
        string t = newTemp();
        lastTemp = t;
        
        cout << t << " = " << left << " <= " << right << endl;
        tacLines.push_back(t + " = " + left + " <= " + right);
    }
    else if(node->type == "GTE")
    {
        string left = getOperand(node->children[0]);
        string right = getOperand(node->children[1]);
        string t = newTemp();
        lastTemp = t;
        
        cout << t << " = " << left << " >= " << right << endl;
        tacLines.push_back(t + " = " + left + " >= " + right);
    }
    else if(node->type == "EQ")
    {
        string left = getOperand(node->children[0]);
        string right = getOperand(node->children[1]);
        string t = newTemp();
        lastTemp = t;
        
        cout << t << " = " << left << " == " << right << endl;
        tacLines.push_back(t + " = " + left + " == " + right);
    }
    else if(node->type == "NEQ")
    {
        string left = getOperand(node->children[0]);
        string right = getOperand(node->children[1]);
        string t = newTemp();
        lastTemp = t;
        
        cout << t << " = " << left << " != " << right << endl;
        tacLines.push_back(t + " = " + left + " != " + right);
    }
    else if(node->type == "ASSIGN")
    {
        string lhs = node->children[0]->value;
        string rhs = getOperand(node->children[1]);
        
        cout << lhs << " = " << rhs << endl;
        tacLines.push_back(lhs + " = " + rhs);
    }
    else if(node->type == "DECL_INT" || node->type == "DECL_FLOAT")
    {
        string varName = node->children[0]->value;
        cout << "decl " << varName << endl;
        tacLines.push_back("decl " + varName);
        
        if(node->children.size() > 1)
        {
            string rhs = getOperand(node->children[1]);
            cout << varName << " = " << rhs << endl;
            tacLines.push_back(varName + " = " + rhs);
        }
    }
    else if(node->type == "PRINT")
    {
        string arg = getOperand(node->children[0]);
        cout << "print " << arg << endl;
        tacLines.push_back("print " + arg);
    }
    else if(node->type == "IF")
    {
        string condLabel = newLabel();
        string endLabel = newLabel();
        
        cout << "ifz " << lastTemp << " goto " << endLabel << endl;
        tacLines.push_back("ifz " + lastTemp + " goto " + endLabel);
        
        generateTACRec(node->children[1], lastTemp);
        
        cout << "goto " << condLabel << endl;
        tacLines.push_back("goto " + condLabel);
        
        cout << endLabel << ":" << endl;
        tacLines.push_back(endLabel + ":");
    }
    else if(node->type == "WHILE")
    {
        string loopLabel = newLabel();
        string endLabel = newLabel();
        
        cout << loopLabel << ":" << endl;
        tacLines.push_back(loopLabel + ":");
        
        cout << "ifz " << lastTemp << " goto " << endLabel << endl;
        tacLines.push_back("ifz " + lastTemp + " goto " + endLabel);
        
        generateTACRec(node->children[1], lastTemp);
        
        cout << "goto " << loopLabel << endl;
        tacLines.push_back("goto " + loopLabel);
        
        cout << endLabel << ":" << endl;
        tacLines.push_back(endLabel + ":");
    }
    else if(node->type == "FUNC_CALL")
    {
        string funcName = node->children[0]->value;
        cout << "call " << funcName << endl;
        tacLines.push_back("call " + funcName);
    }
    else if(node->type == "RETURN")
    {
        if(node->children.size() > 0)
        {
            string retVal = getOperand(node->children[0]);
            cout << "return " << retVal << endl;
            tacLines.push_back("return " + retVal);
        }
        else
        {
            cout << "return" << endl;
            tacLines.push_back("return");
        }
    }

    for(auto child : node->children)
    {
        generateTACRec(child, lastTemp);
    }
}

void generateTAC(ASTNode* node)
{
    tacLines.clear();
    tempCount = 0;
    labelCount = 0;
    
    string lastTemp = "";
    generateTACRec(node, lastTemp);
    
    cout << "\n--- TAC Generated: " << tacLines.size() << " lines ---\n";
}