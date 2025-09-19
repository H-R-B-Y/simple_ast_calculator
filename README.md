# Simple AST Calculator

An example of recursive descent parsing to evaluate simple arithmetic expressions using an Abstract Syntax Tree (AST).

## Notes

This was a practice project written as a refresher for myself on recursive descent parsing and ASTs.

This example only covers addition and multiplication, and parentheses for grouping.

## Usage
Compile the code using `gcc`:

```bash
gcc -o calculator main.c node.c evaluate.c
```
Run the calculator:

```bash
./calculator <expression>
```
