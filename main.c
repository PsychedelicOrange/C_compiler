// https://edu.anarcho-copy.org/Programming%20Languages/Go/writing%20an%20INTERPRETER%20in%20go.pdf
#include <stdio.h>
#include <stdlib.h>
enum TOKEN{
	EQUAL = '=',
	PLUS = '+',
	HYPHEN = '-',
	ASTERISK = '*',
	FSLASH = '/',
	BSLASH = '\\',
	LPAREN = '(',
	RPAREN = ')',
	LBRACE = '{',
	RBRACE = '}',
	LSQUARE = '[',
	RSQUARE = ']',
	LANKLE = '<',
	RANKLE = '>',
	HASH = '#',
	COLON = ':',
	SEMICOLON = ';',
	QUOTE = '\'',
	DQUOTE = '"',
	QUESTION = '?',
	COMMA = ','
};
enum MTOKEN{
	// DOUBLE CHARACTER TOKENS
	GTE = 128,
	LTE,
	EQ,
	NOTEQ,
	// IDENTIFIERS
	IDEN,
	// KEYWORKDS
	FUNCTION,
	AUTO,
	ELSE,
	LONG,
	SWITCH,
	BREAK,
	ENUM,
	REGISTER,
	TYPEDEF,
	CASE,
	EXTERN,
	RETURN,
	UNION,
	CHAR,
	FLOAT,
	SHORT,
	UNSIGNED,
	CONST,
	FOR,
	SIGNED,
	VOID,
	CONTINUE,
	GOTO,
	SIZEOF,
	VOLATILE,
	DEFAULT,
	IF,
	STATIC,
	WHILE,
	DO,
	INT,
	STRUCT,
	PACKED,
	DOUBLE
};
int main(int argv, char* args[])
{
	if(argv <= 1)
	{
		printf("No file provided. \n");
		exit(-1);
	}
	int* tokens = malloc(sizeof(int)*1000);
	{
		int index = 0;
			char c;
		FILE *file = fopen(args[1], "r");
		if(file){
			while((c = getc(file)) != EOF)
			{
				switch (c) {
					case COMMA:
						tokens[index++] = COMMA;
						break;
					case QUESTION:
						tokens[index++] = QUESTION;
						break;
					case DQUOTE:
						tokens[index++] = DQUOTE;
						break;
					case QUOTE:
						tokens[index++] = QUOTE;
						break;
					case SEMICOLON:
						tokens[index++] = SEMICOLON;
						break;
					case COLON:
						tokens[index++] = COLON;
						break;
					case HASH:
						tokens[index++] = HASH;
						break;
					case RANKLE:
						tokens[index++] = RANKLE;
						break;
					case LANKLE:
						tokens[index++] = LANKLE;
						break;
					case LSQUARE:
						tokens[index++] = LSQUARE;
						break;
					case RSQUARE:
						tokens[index++] = RSQUARE;
						break;
					case RBRACE:
						tokens[index++] = RBRACE;
						break;
					case LBRACE:
						tokens[index++] = LBRACE;
						break;
					case LPAREN:
						tokens[index++] = LPAREN;
						break;
					case RPAREN:
						tokens[index++] = RPAREN;
						break;
					case BSLASH:
						tokens[index++] = BSLASH;
						break;
					case FSLASH:
						tokens[index++] = FSLASH;
						break;
					case ASTERISK:
						tokens[index++] = ASTERISK;
						break;
					case HYPHEN:
						tokens[index++] = HYPHEN;
						break;
					case PLUS:
						tokens[index++] = PLUS;
						break;
					case EQUAL:
						tokens[index++] = EQUAL;
						break;
				}
			}
			fclose(file);
		}else{
			printf("file not found.");
		}
		for(int i = 0; i < index; i++){
			printf("%c",tokens[i]);
		}
	}
}
