%{

#include "hash.c"
#include "token.h"

int lineNumber = 1;

%}

%x COMMENT

%%

"byte"												return KW_BYTE;
"int"													return KW_INT;
"long"												return KW_LONG;
"float"												return KW_FLOAT;
"bool"												return KW_BOOL;

"if"													return KW_IF;
"then"												return KW_THEN;
"else"												return KW_ELSE;
"while"												return KW_WHILE;
"for"													return KW_FOR;
"read"												return KW_READ;
"print"												return KW_PRINT;
"return"											return KW_RETURN;
"break"												return KW_BREAK;

"<="													return OPERATOR_LE;
">="													return OPERATOR_GE;
"=="													return OPERATOR_EQ;
"!="													return OPERATOR_DIF;

"TRUE"												return LIT_TRUE;
"FALSE"												return LIT_FALSE;

[A-Za-z_][A-Za-z_0-9]*				{hashInsert(yytext); return TK_IDENTIFIER;}
[0-9]+ 												{hashInsert(yytext); return LIT_INTEGER;}
[0-9]+\.[0-9]+ 								{hashInsert(yytext); return LIT_FLOAT;}
'.'                           {hashInsert(yytext); return LIT_CHAR;}

[,;:\(\)[\]{\}+\-*/<>=v.~&$#]	return yytext[0];

[ \t]
"\n" 													++lineNumber;
"//".*
.
"###"													BEGIN(COMMENT);
<COMMENT>"###"								BEGIN(INITIAL);
<COMMENT>"\n"									++lineNumber;
<COMMENT>.


%%

int running = 1;

int yywrap()
{
	running = 0;
	return 1;
}

void initMe(void){
	hashInit();
}

#include "main.c"
