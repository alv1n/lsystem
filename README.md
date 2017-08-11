# lsystem
A C l-system


# Usage
Syntax of rules.txt:

Axiom  
Rules  
Angle  

E.G.

A  
(B>A)(A>AB)  
45.00  

# Grammar
- **Any letter**: Move forward
- **+**: Increase angle by specified amount
- **-**: Decrease angle
- **[**: push to stack (position, angle)
- **]**: pop from stack
