# Reverse-Polish-notation
### Removing unnecessary parentheses with Bison

*Create Syntax-directed translation of delete extra parentheses,  for the language specified by the grammar:*
```
1.	S::=E 
2.	E::=E+T 
3.	E::=T 
4.	T::=T*F 
5.	T::=F 
6.	F::=a 
7.	F::=b 
8.	F::=(E)
```
> S – axiom
 
 
## How does it work? 
|  in   | out   |
|---|:-:|
| ((a))  | a   |
| ((a))+((b))  |  a+b |
| ((a)+a)\*(b+b)\*((a))  |  (a+a)\*(b+b)\*a  |
| a)  | syntax error   |


* [Flex description (lexer.l)](https://github.com/zhilyaev/Reverse-Polish-notation/blob/master/lexer.l)
* [Bison description (parser.y)](https://github.com/zhilyaev/Reverse-Polish-notation/blob/master/parser.y)
* [.EXE](https://github.com/zhilyaev/Reverse-Polish-notation/blob/master/ReversePolish.exe)
