// https://edu.anarcho-copy.org/Programming%20Languages/Go/writing%20an%20INTERPRETER%20in%20go.pdf
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
	COMMA = ',',
	EXCLAMATION = '!'
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
	int* tokens = calloc(10000,sizeof(int));
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
						if((c = getc(file)) != EOF)
						{
							switch(c){
								case EQUAL:
									tokens[index-1]=GTE;
							}
						}else{
							ungetc(c,file);
						}
						break;
					case LANKLE:
						tokens[index++] = LANKLE;
						if((c = getc(file)) != EOF)
						{
							switch(c){
								case EQUAL:
									tokens[index-1]=LTE;
							}
						}else{
							ungetc(c,file);
						}
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
						if((c = getc(file)) != EOF)
						{
							switch(c){
								case EQUAL:
									tokens[index-1]=EQ;
							}
						}else{
							ungetc(c,file);
						}
						break;
					case EXCLAMATION:
						tokens[index++] = EXCLAMATION;
						if((c = getc(file)) != EOF)
						{
							switch(c){
								case EQUAL:
									tokens[index-1]=NOTEQ;
							}
						}else{
							ungetc(c,file);
						}
						break;
					case ' ':
						break;
					default:
						{
							char vk[100];
							int vkindex = 0;
							while((c = getc(file)) != EOF && vkindex < 100){
								//printf("vkindex: %i\n",vkindex);
									if(c == ' '){
										// compare with reserved keywords
										if(!strcmp(vk, "auto")){
											tokens[index++] = AUTO;
											break;
										}
										else if(!strcmp(vk,"long")){
											tokens[index++] = LONG;	
											break;
										}
										else if(!strcmp(vk,"switch")){
											tokens[index++] = SWITCH;	
											break;
										}
										else if(!strcmp(vk,"break")){
											tokens[index++] = BREAK;	
											break;
										}
										else if(!strcmp(vk,"enum")){
											tokens[index++] = ENUM;	
											break;
										}
										else if(!strcmp(vk,"register")){
											tokens[index++] = REGISTER;	
											break;
										}
										else if(!strcmp(vk,"typedef")){
											tokens[index++] = TYPEDEF;	
											break;
										}
										else if(!strcmp(vk,"case")){
											tokens[index++] = CASE;	
											break;
										}
										else if(!strcmp(vk,"extern")){
											tokens[index++] = EXTERN;	
											break;
										}
										else if(!strcmp(vk,"return")){
											tokens[index++] = RETURN;	
											break;
										}
										else if(!strcmp(vk,"union")){
											tokens[index++] = UNION;	
											break;
										}
										else if(!strcmp(vk,"char")){
											tokens[index++] = CHAR;	
											break;
										}
										else if(!strcmp(vk,"float")){
											tokens[index++] = FLOAT;	
											break;
										}
										else if(!strcmp(vk,"short")){
											tokens[index++] = SHORT;	
											break;
										}
										else if(!strcmp(vk,"unsigned")){
											tokens[index++] = UNSIGNED;	
											break;
										}
										else if(!strcmp(vk,"const")){
											tokens[index++] = CONST;	
											break;
										}
										else if(!strcmp(vk,"for")){
											tokens[index++] = FOR;	
											break;
										}
										else if(!strcmp(vk,"signed")){
											tokens[index++] = SIGNED;	
											break;
										}
										else if(!strcmp(vk,"void")){
											tokens[index++] = VOID;	
											break;
										}
										else if(!strcmp(vk,"continue")){
											tokens[index++] = CONTINUE;	
											break;
										}
										else if(!strcmp(vk,"goto")){
											tokens[index++] = GOTO;	
											break;
										}
										else if(!strcmp(vk,"sizeof")){
											tokens[index++] = SIZEOF;	
											break;
										}
										else if(!strcmp(vk,"volatile")){
											tokens[index++] = VOLATILE;	
											break;
										}
										else if(!strcmp(vk,"default")){
											tokens[index++] = DEFAULT;	
											break;
										}
										else if(!strcmp(vk,"if")){
											tokens[index++] = IF;	
											break;
										}
										else if(!strcmp(vk,"static")){
											tokens[index++] = STATIC;	
											break;
										}
										else if(!strcmp(vk,"while")){
											tokens[index++] = WHILE;	
											break;
										}
										else if(!strcmp(vk,"do")){
											tokens[index++] = DO;	
											break;
										}
										else if(!strcmp(vk,"int")){
											tokens[index++] = INT;	
											break;
										}
										else if(!strcmp(vk,"struct")){
											tokens[index++] = STRUCT;	
											break;
										}
										else if(!strcmp(vk,"_Packed")){
											tokens[index++] = PACKED;	
											break;
										}
										else if(!strcmp(vk,"double")){
											tokens[index++] = DOUBLE;	
											break;
										}
										else{
											printf("%s\n",vk);
										}
									}else{
										vk[vkindex++] = c;
									}
							}
						}
					
				}
			}
			fclose(file);
		}else{
			printf("file not found.");
		}
		for(int i = 0; i < index; i++){
			printf("%i\n",tokens[i]);
		}
	}
}
