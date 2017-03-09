# Reverse-Polish-notation
### Removing unnecessary parentheses with Bison

Создать управляемое синтаксическое удаление лишних скобок для языка, заданный грамматикой:

1.	S::=E 
2.	E::=E+T 
3.	E::=T 
4.	T::=T*F 
5.	T::=F 
6.	F::=a 
7.	F::=b 
8.	F::=(E)

S – axiom
 
|  in   | out   |
|---|:-:|
| ((a))  | a   |
| ((a))+((b))  |  a+b |
| ((a)+a)\*(b+b)\*((a))  |  (a+a)\*(b+b)\*a  |
| a)  | syntax error   |
