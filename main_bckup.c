// https://edu.anarcho-copy.org/Programming%20Languages/Go/writing%20an%20INTERPRETER%20in%20go.pdf
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringstruct.h"
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
void tokens_add_singletoken(struct TOKENS* tokens,size_t* token_index,enum SINGLETOKEN singletoken)
{
	printf("\nadd single token called ");
	struct TOKEN token;
	token.utoken.single_token = singletoken;
	token.tokentype = SINGLETOKEN;
	tokens->array[(*token_index)++] = token;
	printf("\ntoken_index after : %i ",(int)*token_index);
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
void checkWordAndAddToken(struct Hashmap hashmap, struct TOKENS* tokens,size_t* index,char* tempword, size_t temp_index){
	enum MULTITOKEN mtoken = hash_getToken(&hashmap,tempword,temp_index);
	if(mtoken == NULL_DEBUG)
	{
		// add identifier
		struct TOKEN token;
		token.utoken.identifier = string_copy_c_style(tempword, temp_index);	
		token.tokentype = INDENTIFIER;
		tokens->array[(*index)++] = token;  
		printf("IDENTIFIER ADDED: ");
		string_print(token.utoken.identifier);
		printf("\n");
	}else{
		// add multitoken
		struct TOKEN token;
		token.tokentype = MULTITOKEN;
		token.utoken.multi_token = mtoken;
		tokens->array[(*index)++] = token;
	}
	printf("\ntoken_index after: %i ",(int)*index);
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

		struct Hashmap hashmap;
		hash_init(&hashmap,10000);
		hash_insert_all_tokens(&hashmap);

		int word_started = 0;

		size_t token_index = 0;

		char temp[100];
		size_t temp_index = 0;	

		char c;
		FILE *file = fopen(args[1], "r");
		if(file){
			while((c = getc(file)) != EOF)
			{
				printf("\ncharacter : %c\n",c);
				printf("%i",(int)token_index);
				switch (c) {
					case COMMA:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,COMMA);
						}
						break;
					case EQUAL:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,EQUAL);
						}
						break;
					case PLUS:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,PLUS);
						}
						break;
					case HYPHEN:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,HYPHEN);
						}
						break;
					case ASTERISK:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,ASTERISK);
						}
						break;
					case FSLASH:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,FSLASH);
						}
						break;
					case BSLASH:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,BSLASH);
						}
						break;
					case LPAREN:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,LPAREN);
						}
						break;
					case RPAREN:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,RPAREN);
						}
						break;
					case LBRACE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,LBRACE);
						}
						break;
					case RBRACE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,RBRACE);
						}
						break;
					case LSQUARE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,LSQUARE);
						}
						break;
					case RSQUARE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,RSQUARE);
						}
						break;
					case LANKLE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,LANKLE);
						}
						break;
					case RANKLE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,RANKLE);
						}
						break;
					case HASH:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,HASH);
						}
						break;
					case COLON:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,COLON);
						}
						break;
					case SEMICOLON:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,SEMICOLON);
						}
						break;
					case QUOTE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,QUOTE);
						}
						break;
					case DQUOTE:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,DQUOTE);
						}
						break;
					case QUESTION:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,QUESTION);
						}
						break;
					case EXCLAMATION:
						if(word_started){
							ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}else{
							tokens_add_singletoken(&tokens,&token_index,EXCLAMATION);
						}
						break;
					case ' ':
						if(word_started){
							//ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}
						break;
					case '\0':
						if(word_started){
							//ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}
						break;
					case '\n':
						if(word_started){
							//ungetc(c, file);
							checkWordAndAddToken(hashmap,&tokens,&token_index,temp,temp_index);
							word_started = 0;
						}
						break;
					default:
						if(!word_started)
						{
							temp_index= 0;
							word_started = 1;
						}
						temp[temp_index++] = c;

						//printf(" abcd ");
						break;
				}
			}
			fclose(file);
		}else{
			printf("file not found.");
		}
		printf("token_index: %i\n",(int)token_index);
		for(int i = 0; i < token_index; i++){
			if(tokens.array[i].tokentype == SINGLETOKEN)
			{
				printf("%c",tokens.array[i].utoken.single_token);
			}
			else if(tokens.array[i].tokentype == MULTITOKEN){
				string_print(hash_getString(hashmap,tokens.array[i].utoken.multi_token));
			}else{
				string_print(tokens.array[i].utoken.identifier);
			}
		}
	}
}
