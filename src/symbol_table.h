#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <map>
#include <string>
#include <iostream>

using namespace std;

struct Symbol
{
    string name;
    string type;
    int scope;
};

class SymbolTable
{
public:
    map<string, Symbol> table;
    int currentScope = 0;

    void insert(string name, string type, int scope = 0)
    {
        Symbol s;
        s.name = name;
        s.type = type;
        s.scope = scope;

        table[name] = s;
    }

    bool exists(string name)
    {
        return table.find(name) != table.end();
    }

    string getType(string name)
    {
        if(table.find(name) != table.end())
            return table[name].type;
        return "unknown";
    }

    void print()
    {
        cout << "\n--- SYMBOL TABLE ---\n";
        for(auto &p : table)
        {
            cout << p.second.name << " | "
                 << p.second.type << " | scope "
                 << p.second.scope << endl;
        }
    }
};

#endif