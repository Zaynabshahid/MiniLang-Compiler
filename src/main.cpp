#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "ast.h"
#include "symbol_table.h"

using namespace std;

extern int yyparse();
extern ASTNode* root;
extern void semanticCheck(ASTNode* node, int scope);
extern void generateTAC(ASTNode* node);
extern ASTNode* optimize(ASTNode* node);
extern void generatePython(ASTNode* node, int indent);

extern SymbolTable symtab;

void printAST(ASTNode* node, int level);
void captureAndSaveTokens();
void saveAST(ASTNode* node, const string& filename);
void saveTAC(const string& filename);

// Function to create output directories
void createOutputDirs()
{
    system("mkdir output 2>nul");
    system("mkdir output\\tokens 2>nul");
    system("mkdir output\\ast 2>nul");
    system("mkdir output\\tac 2>nul");
    system("mkdir output\\optimized_tac 2>nul");
    system("mkdir output\\python 2>nul");
}

int main()
{
    createOutputDirs();
    
    cout << "MiniLang Compiler Started\n";

    yyparse();

    cout << "\n--- AST ---\n";
    printAST(root, 0);
    
    // Save AST to file
    ofstream astFile("output/ast/ast.txt");
    streambuf* oldCout = cout.rdbuf(astFile.rdbuf());
    printAST(root, 0);
    cout.rdbuf(oldCout);
    astFile.close();

    // Semantic check and symbol table
    semanticCheck(root, 0);
    symtab.print();
    
    // Save symbol table
    ofstream symFile("output/ast/symbol_table.txt");
    oldCout = cout.rdbuf(symFile.rdbuf());
    symtab.print();
    cout.rdbuf(oldCout);
    symFile.close();

    // TAC Generation
    cout << "\n--- TAC ---\n";
    generateTAC(root);

    // Optimization
    root = optimize(root);
    
    cout << "\n--- OPTIMIZED TAC ---\n";
    generateTAC(root);

    // Python Code Generation
    cout << "\n--- PYTHON CODE ---\n";
    ofstream pyFile("output/python/output.py");
    oldCout = cout.rdbuf(pyFile.rdbuf());
    generatePython(root, 0);
    cout.rdbuf(oldCout);
    pyFile.close();
    
    // Also print to console
    generatePython(root, 0);

    cout << "\nParsing Finished\n";
    cout << "Output files saved to output/ directory\n";

    return 0;
}