#include <iostream>
#include <list>
#include <string>
#include "lex.yy.c"
#include "parser.tab.c"

using namespace std;
string optimus(string postfix){
    list<string>  infix ;// Здесь будет ответ
	list<int>  oprior; // приоритет операции
	int p = 1;
	for(int i=0;i<postfix.length();i++){
	   string c = postfix.substr(i,1);// c = postfix[i]
       // Операнд?
	   if(c=="+"|| c=="*"){

				// Верхушка выражения
				string arg1 =  infix.back();
				infix.pop_back();
				string arg2 =  infix.back();
				infix.pop_back();

					// Вверхушка приоритета
					int p2 = oprior.back();
					oprior.pop_back();
					int p1 = oprior.back();
					oprior.pop_back();

                    //printf("PRIOR : { %d | %d } \n",p1,p2);

				int prior = (c=="+") ? 1 : 2; // Текущий приоритет
                string exp1 ,exp2 = "";

                // Если приоритет выше , то в скобки
				if(p2<prior && p2!=0 && arg2.length()>1){
				  exp2+="("+arg2+")";
				}else  exp2=arg2;
                if(p1<prior && p1!=0 && arg1.length()>1){
                  exp1 +="("+arg1+")";
				}else  exp1=arg1;

                // Создали новую Верхушку выражения
				infix.push_back(exp2+c+exp1);
				// Создали новую Верхушку приоритета
				oprior.push_back(prior);

				printf("%d NEW PEEK -> %s\n",p++,infix.back().c_str());
	   }
	   else{
		infix.push_back(c);
        oprior.push_back(0);// Кладем нули на это
		//printf("ADD CHAR -> %s\n",infix.back().c_str());
	   }


	}

	printf("ANSWER -> %s\n",infix.front().c_str());
	return infix.front();
}
void main () {
string input;
printf ("Input -> ");
getline(cin, input);
// Лайфхак
YY_BUFFER_STATE bufferState = yy_scan_string(input.c_str());
if (yyparse()==0) {
	printf ("PARSER -> Ok\nPOLSKA -> %s \n", postfix.c_str());

    // Нужна ли оптимизация?
	if(Snoop){
       optimus(postfix);
	}
	else{
        // Если оптимизация не требуеться, то сразу ответ
       printf("ANSWER -> %s\n",input.c_str());
	}
}// Сообщение об ошибке заранее прописано в parser
system("pause");
}
