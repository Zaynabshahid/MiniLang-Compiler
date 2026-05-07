# MiniLang Compiler

MiniLang is a small compiler project built with Flex, Bison, and C++. It parses a simple language, builds an AST, performs semantic checks, generates three-address code, applies basic optimizations, and emits Python code.

## Pipeline

1. Lexical analysis
2. Syntax analysis
3. AST generation
4. Symbol table construction
5. Semantic analysis
6. TAC generation
7. Optimization
8. Python code generation

## Features

Supported language features include:

- `int` and `float` declarations
- Assignment
- Arithmetic operators: `+`, `-`, `*`, `/`, `%`
- Relational operators: `<`, `>`, `<=`, `>=`, `==`, `!=`
- `print(...)`
- `if` / `else`
- `while`
- Functions
- `return`

The optimizer currently performs constant folding and a few small algebraic simplifications.

## Repository Layout

```text
lab13/
├── src/
├── tests/
├── output/
└── README.md
```

## Source Files

| File | Purpose |
| --- | --- |
| `src/lexer.l` | Tokenizer |
| `src/parser.y` | Grammar and AST construction |
| `src/ast.h` / `src/ast.cpp` | AST data structure and printing |
| `src/symbol_table.h` | Symbol table implementation |
| `src/semantic.cpp` | Semantic analysis |
| `src/tac.cpp` | TAC generation |
| `src/optimizer.cpp` | AST/TAC optimizations |
| `src/codegen.cpp` | Python code generation |
| `src/main.cpp` | Compiler driver |

## Build

Use PowerShell or CMD from `d:\lab13\src`.

```powershell
Set-Location D:\lab13\src
.\build.bat
```

If you want to run the toolchain manually:

```powershell
win_bison -d parser.y
win_flex lexer.l
g++ -std=c++11 -Wall lex.yy.c parser.tab.c main.cpp ast.cpp semantic.cpp tac.cpp optimizer.cpp codegen.cpp -o compiler.exe
```

## Run

The compiler reads a source file from standard input. In PowerShell, use `Get-Content -Raw`:

```powershell
Get-Content -Raw ..\tests\test.src | & .\compiler.exe
```

To save the console output to a file:

```powershell
Get-Content -Raw ..\tests\test.src | & .\compiler.exe > ..\output\tac\test.console.txt
```

## Test Programs

The repository includes five required lab tests in `tests/`:

- `fibonacci_recursive.src`
- `factorial_iterative.src`
- `type_mismatch.src`
- `loop_optimization.src`
- `showcase.src`

## Output Folders

The compiler workflow uses these output locations:

- `output/tac/` for captured console output, including TAC and optimized TAC
- `output/ast/` for saved AST output
- `output/python/` for generated Python code

## Example

Input:

```c
x = 5 + 3;
print(x);
```

Example Python output:

```python
x = 8
print(x)
```

## Notes

- The build script is `src/build.bat`.
- The compiler creates `output/` subfolders automatically when it runs.
- Because the project is Windows-oriented, the PowerShell pipeline above is the most reliable way to run tests and capture output.

## Authors

Zaynab Shahid, Laiba Riaz, and Rameen Arshad

BSCS Compiler Construction Lab Project
