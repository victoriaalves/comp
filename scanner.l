%{

#include "hash.c"
#include "tokens.h"

int lineNumber = 1;
int running = 1;

char buf[1000];
char *c;

%}

%x COMMENT
%x STRING

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
[0-9]*\.[0-9]+ 								{hashInsert(yytext); return LIT_FLOAT;}
[0-9]+\.[0-9]* 								{hashInsert(yytext); return LIT_FLOAT;}
'.'                           {hashInsert(yytext); return LIT_CHAR;}
"\""                          {BEGIN(STRING); c = buf; *c++ = *yytext; return LIT_STRING;}

[,;:\(\)[\]{\}+\-*/<>=v.~&$#]	return yytext[0];

[ \t]
"\n" 													++lineNumber;
"//".*
"###"													BEGIN(COMMENT);
.															return TOKEN_ERROR;

<COMMENT>"###"								BEGIN(INITIAL);
<COMMENT>"\n"									++lineNumber;
<COMMENT>.

<STRING>"\""            			{*c++ = *yytext; *c = 0; hashInsert(buf); BEGIN(INITIAL);}
<STRING>\\n             			{*c++ = '\\'; *c++ = 'n';}
<STRING>\\t             			{*c++ = '\\'; *c++ = 't'; }
<STRING>.               			{*c++ = *yytext;}
<STRING>\n              			{++lineNumber; *c++ = '\n';}

%%


int getLineNumber(void){
  return lineNumber;
}

int isRunning(void){
  return running;
}

int yywrap()
{
  running = 0;
  return 1;
}

void initMe(void){
  lineNumber = 1;
  running = 1;
  hashInit();
}

