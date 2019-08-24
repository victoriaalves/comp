int main()
{
	int tok;
	hashInit();
	while(running)
	{
		tok = yylex();

		if (!running)
			break;

		switch(tok)
		{
			case KW_BYTE:
				fprintf(stderr, "Found keyword 'byte'.\n"); break;
			case KW_INT:
				fprintf(stderr, "Found keyword 'int'.\n"); break;
			case KW_LONG:
				fprintf(stderr, "Found keyword 'long'.\n"); break;
			case KW_FLOAT:
				fprintf(stderr, "Found keyword 'float'.\n"); break;
			case KW_BOOL:
				fprintf(stderr, "Found keyword 'bool'.\n"); break;
			case KW_IF:
				fprintf(stderr, "Found keyword 'byte'.\n"); break;
			case KW_THEN:
				fprintf(stderr, "Found keyword 'then'.\n"); break;
			case KW_ELSE:
				fprintf(stderr, "Found keyword 'else'.\n"); break;
			case KW_WHILE:
				fprintf(stderr, "Found keyword 'while'.\n"); break;
			case KW_FOR:
				fprintf(stderr, "Found keyword 'for'.\n"); break;
			case KW_READ:
				fprintf(stderr, "Found keyword 'read'.\n"); break;
			case KW_PRINT:
				fprintf(stderr, "Found keyword 'print'.\n"); break;
			case KW_RETURN:
				fprintf(stderr, "Found keyword 'return'.\n"); break;
			case KW_BREAK:
				fprintf(stderr, "Found keyword 'break'.\n"); break;

			case OPERATOR_LE:
				fprintf(stderr, "<=.\n"); break;
			case OPERATOR_GE:
				fprintf(stderr, ">=.\n"); break;
			case OPERATOR_EQ:
				fprintf(stderr, "==.\n"); break;
			case OPERATOR_DIF:
				fprintf(stderr, "!=.\n"); break;

			case LIT_TRUE:
				fprintf(stderr, "Literal TRUE.\n"); break;
			case LIT_FALSE:
				fprintf(stderr, "Literal FALSE.\n"); break;
			case TK_IDENTIFIER:
				fprintf(stderr, "Identifier.\n"); break;
			case LIT_INTEGER:
				fprintf(stderr, "Literal Integer.\n"); break;
			case LIT_FLOAT:
				fprintf(stderr, "Literal Float.\n"); break;

			/*case LIT_CHAR:
				fprintf(stderr, "Literal Char.\n"); break;
			case LIT_SRING:
				fprintf(stderr, "Literal String.\n"); break;
			case LIT_ERROR:
				fprintf(stderr, "Error.\n"); break;
			*/

			default:
				fprintf(stderr, "Token ascii %c\n", tok); break;
		}

	}
	hashPrint();
}

