'''
Меняем поток вывода на windows
'''
file = open("lex.yy.c", 'r')
text = file.read() 
file.close() 
file = open("lex.yy.c", 'w') 
file.write(text.replace("#include <unistd.h>","#include <io.h>")) 
file.close() 
