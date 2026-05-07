@echo off
cd /d "%~dp0"

echo Building MiniLang Compiler...
echo.

echo Generating parser...
win_bison -d parser.y

echo Generating lexer...
win_flex lexer.l

echo Compiling...
g++ -std=c++11 -Wall lex.yy.c parser.tab.c main.cpp ast.cpp semantic.cpp tac.cpp optimizer.cpp codegen.cpp -o compiler.exe

if %errorlevel% equ 0 (
    echo.
    echo Build successful!
    echo.
    echo Testing with test.src...
    compiler.exe < ..\tests\test.src
) else (
    echo Build failed!
    exit /b 1
)

pause