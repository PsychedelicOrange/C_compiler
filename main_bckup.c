// https://edu.anarcho-copy.org/Programming%20Languages/Go/writing%20an%20INTERPRETER%20in%20go.pdf
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"
enum SINGLETOKEN{
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
	EXCLAMATION = '!',
	GTE = 71,
	LTE = 76,
	EQ = 69,
	NOTEQ = 78
};
struct string{
	char* array;
	size_t size;
};
struct string string_malloc(size_t size) {
	struct string str; 
	str.array = malloc(size);
	str.size = size;
	return str;
}
void string_free(struct string str){
	free(str.array);
}

union UTOKEN{
	enum MULTITOKEN multi_token;
	enum SINGLETOKEN single_token;
	struct string identifier;
};

enum TOKEN_TYPE{
	SINGLETOKEN,MULTITOKEN,INDENTIFIER
};

struct TOKEN{
	union UTOKEN utoken;
	enum TOKEN_TYPE tokentype;
};
struct TOKENS{
	struct TOKEN* array;
	size_t size;
};
void tokens_init(struct TOKENS* tokens, size_t size)
{
	tokens->size = size;
	tokens->array =  malloc(size* sizeof(struct TOKEN));
}
void tokens_add_singletoken(struct TOKENS* tokens,size_t token_index,enum SINGLETOKEN singletoken)
{
	struct TOKEN token;
	union UTOKEN utoken;
	utoken.single_token = singletoken;
	token.utoken = utoken;
	token.tokentype = SINGLETOKEN;
	tokens->array[token_index++] = token;
}
/*
   TOKEN tokens[]; // symbols 
   ' ' and '\n' are terminators
RESERVED rTokens[];
bool wordStarted;
char tempWord[];

while file is not end.
case : if character is a symbol or terminator
			if word is started
				end word
				if word is reserved
					add word as token
				else if word is not reserved
					add word as identifier
			else if word is not started
				add symbol as token
	   else if character is not a symbol or terminator
			if word is started
				append to word
			if word is not started
				start word and append
 */
void checkWordAndAddToken(struct TOKENS tokens,size_t index,char* tempword, size_t temp_index){
	struct Hashmap hashmap;
	hash_init(&hashmap,10000);
	enum MULTITOKEN mtoken = hash_getToken(&hashmap,tempword,temp_index);
	if(mtoken == NULL_DEBUG)
	{
		// add identifier
		struct TOKEN token;
		union UTOKEN utoken;
		
		utoken.identifier = string_malloc(temp_index);
		memcpy(tempword,utoken.identifier.array ,temp_index);
		
		token.tokentype = INDENTIFIER;
		token.utoken = utoken;
		tokens.array[index++] = token;  
	}else{

		// add multitoken
		struct TOKEN token;
		token.tokentype = MULTITOKEN;
		union UTOKEN utoken;
		utoken.multi_token = mtoken;
		token.utoken = utoken;
		tokens.array[index++] = token;
	}
}
int main(int argv, char* args[])
{
	if(argv <= 1)
	{
		printf("No file provided. \n");
		exit(-1);
	}
	struct TOKENS tokens;
	tokens_init(&tokens,10000);	
	{
		int word_started=0;

		size_t token_index = 0;

		char temp[100];
		size_t temp_index = 0;	

		char c;
		FILE *file = fopen(args[1], "r");
		if(file){
			while((c = getc(file)) != EOF)
			{
				switch (c) {
					case COMMA:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,COMMA);
						}
						break;
					case EQUAL:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,EQUAL);
						}
						break;
					case PLUS:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,PLUS);
						}
						break;
					case HYPHEN:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,HYPHEN);
						}
						break;
					case ASTERISK:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,ASTERISK);
						}
						break;
					case FSLASH:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,FSLASH);
						}
						break;
					case BSLASH:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,BSLASH);
						}
						break;
					case LPAREN:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,LPAREN);
						}
						break;
					case RPAREN:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,RPAREN);
						}
						break;
					case LBRACE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,LBRACE);
						}
						break;
					case RBRACE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,RBRACE);
						}
						break;
					case LSQUARE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,LSQUARE);
						}
						break;
					case RSQUARE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,RSQUARE);
						}
						break;
					case LANKLE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,LANKLE);
						}
						break;
					case RANKLE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,RANKLE);
						}
						break;
					case HASH:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,HASH);
						}
						break;
					case COLON:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,COLON);
						}
						break;
					case SEMICOLON:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,SEMICOLON);
						}
						break;
					case QUOTE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,QUOTE);
						}
						break;
					case DQUOTE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,DQUOTE);
						}
						break;
					case QUESTION:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,QUESTION);
						}
						break;
					case EXCLAMATION:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,token_index,EXCLAMATION);
						}
						break;
					case ' ':
						if(word_started){
							//ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}
						break;
					case '\0':
						if(word_started){
							//ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}
						break;
					case '\n':
						if(word_started){
							//ungetc(c, file);
							checkWordAndAddToken(tokens,token_index,temp,temp_index);
							word_started = 0;
						}
						break;
					default:
						printf("not a symbol or terminators\n");
						break;
				}
			}
			fclose(file);
		}else{
			printf("file not found.");
		}
		for(int i = 0; i < token_index; i++){
			//printf("Token : %i\n",tokens.array[i].tokentype);
		}
	}
}
