#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include"hashmap.h"
void hash_init(struct Hashmap* hashmap,size_t size)
{
	assert(hashmap != NULL);
	hashmap->hash = malloc(size * sizeof(struct Keyword));
	hashmap->size = size;
	for(size_t i =0;i < hashmap->size;i++)
	{
		hashmap->hash[i].token = NULL_DEBUG;
		hashmap->hash[i].string = NULL;
		hashmap->hash[i].size = 0;
	}
}
int hash_insert(struct Hashmap* hashmap,enum TOKEN token, char* word,size_t size){	
	int sum = 0;
	for(size_t i =0;i < size; i++)
	{
		sum += word[i];
	}
	fprintf(stderr,"while inserting %s... hashIndex is %i\n",word,sum);
	int hashindex = sum%hashmap->size;
	assert(hashindex < hashmap->size);
	if (hashmap->hash[hashindex].token == NULL_DEBUG)
	{
		hashmap->hash[hashindex].size = size;
		hashmap->hash[hashindex].string = malloc(sizeof(char)*size);
		hashmap->hash[hashindex].token = token;
		return 1;
	}else if(hashmap->hash[hashindex].token != token){//collision
		hashindex++;
		while(hashindex < hashmap->size) {
			if (hashmap->hash[hashindex].token == NULL_DEBUG){
				hashmap->hash[hashindex].size = size;
				hashmap->hash[hashindex].string = (char*)malloc(size*sizeof(char));
				hashmap->hash[hashindex].token = token;
				memcpy(hashmap->hash[hashindex].string,word,size);
				return 1;
			}else if(hashmap->hash[hashindex].token == token){
				return 0;
			}
		}
		return 0;
	}
	return 0;
}
int hash_contains(struct Hashmap* hashmap,char* word, size_t size){
	int sum = 0;
	for(size_t i =0;i < size; i++)
	{
		sum += word[i];
	}
	int hashindex = sum%hashmap->size;
	while(hashindex < hashmap->size)
	{
		if(size == hashmap->hash[hashindex].size && !strcmp(hashmap->hash[hashindex].string, word)){
			return 1;
		}else if(hashmap->hash[hashindex].token == NULL_DEBUG){
			return 0;
		}else{
			hashindex++;
		}
	}
	return 0;
}
int hash_getToken(struct Hashmap* hashmap,char* word, size_t size){
	int sum = 0;
	for(size_t i =0;i < size; i++)
	{
		sum += word[i];
	}
	int hashindex = sum%hashmap->size;
	while(hashindex < hashmap->size)
	{
		if(size == hashmap->hash[hashindex].size && !strcmp(hashmap->hash[hashindex].string, word)){
			return hashmap->hash[hashindex].token;
		}else if(hashmap->hash[hashindex].token == NULL_DEBUG){
			return hashmap->hash[hashindex].token;
		}else{
			hashindex++;
		}
	}
	return NULL_DEBUG;
}
int main(){
	struct Hashmap hashmap;
	hash_init(&hashmap,10000);
	fprintf(stderr,"init complete.\n");
	fprintf(stderr,"%i \n",hash_insert(&hashmap,IF,"if\0",2));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,DO,"do\0",2));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,FOR,"for\0",3));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,INT,"int\0",3));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,AUTO,"auto\0",4));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,ELSE,"else\0",4));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,LONG,"long\0",4));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,ENUM,"enum\0",4));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,CASE,"case\0",4));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,CHAR,"char\0",4));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,VOID,"void\0",4));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,GOTO,"goto\0",4));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,WHILE,"while\0",5));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,UNION,"union\0",5));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,FLOAT,"float\0",5));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,SHORT,"short\0",5));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,CONST,"const\0",5));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,SWITCH,"switch\0",6));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,EXTERN,"extern\0",6));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,RETURN,"return\0",6));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,SIGNED,"signed\0",6));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,SIZEOF,"sizeof\0",6));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,STATIC,"static\0",6));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,STRUCT,"struct\0",6));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,DOUBLE,"double\0",6));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,TYPEDEF,"typedef\0",7));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,DEFAULT,"default\0",7));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,PACKED,"_Packed\0",7));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,REGISTER,"register\0",8));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,UNSIGNED,"unsigned\0",8));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,CONTINUE,"continue\0",8));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,VOLATILE,"volatile\0",8));
	fprintf(stderr,"%i \n",hash_insert(&hashmap,VOLATILE,"volatile\0",8));
	
	fprintf(stderr,"%i \n",hash_contains(&hashmap,"goto\0",4));
}
