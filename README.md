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
- **Any capital letter**: Move forward
- **Any lowercase letter**: used as variable
- **+**: Increase angle by specified amount
- **-**: Decrease angle
- **[**: push to stack (position, angle)
- **]**: pop from stack
