    
Assignment name  : rpn_calc<br />
Expected files   : *.c, *.h <br />
Allowed functions: atoi, printf, write, malloc, free<br />
--------------------------------------------------------------------------------<br />
<br />
Write a program that takes a string which contains an equation written in<br />
Reverse Polish notation (RPN) as its first argument, evaluates the equation, and<br />
prints the result on the standard output followed by a newline. <br />
<br />
Reverse Polish Notation is a mathematical notation in which every operator<br />
follows all of its operands. In RPN, every operator encountered evaluates the<br />
previous 2 operands, and the result of this operation then becomes the first of<br />
the two operands for the subsequent operator. Operands and operators must be<br />
spaced by at least one space.<br />
<br />
You must implement the following operators : "+", "-", "*", "/", and "%".<br />
<br />
If the string isn't valid or there isn't exactly one argument, you must print<br />
"Error" on the standard output followed by a newline.<br />
<br />
All the given operands must fit in a "int".<br />
<br />
Examples of formulas converted in RPN:<br />
<br />
3 + 4                   >>    3 4 +<br />
((1 * 2) * 3) - 4       >>    1 2 * 3 * 4 -  ou  3 1 2 * * 4 -<br />
50 * (5 - (10 / 9))     >>    5 10 9 / - 50 *<br />
<br />
Here's how to evaluate a formula in RPN:<br />
<br />
1 2 * 3 * 4 -<br />
2 3 * 4 -<br />
6 4 -<br />
2<br />
<br />
Or:<br />
<br />
3 1 2 * * 4 -<br />
3 2 * 4 -<br />
6 4 -<br />
2<br />
<br />
Examples:<br />
<br />
$> ./rpn_calc "1 2 * 3 * 4 +" | cat -e<br />
10$<br />
$> ./rpn_calc "1 2 3 4 +" | cat -e<br />
Error$<br />
$> ./rpn_calc |cat -e<br />
Error$<br />
