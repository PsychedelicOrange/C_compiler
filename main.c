#include"hashmap.h"
int main(){
	struct Hashmap hashmap;
	hash_init(&hashmap,10000);
	hash_insert_all_tokens(&hashmap);
	char* wordpointer;
	{
	char word[100];
	word[0] = 'i';
	word[1] = 'n';
	word[2] = 't';
	word[3] = '0';
	wordpointer = word;
	}
	printf("getToken(): %i",hash_getToken(&hashmap,wordpointer,3));
	printf("\n");
	printf("contains(): %i",hash_contains(&hashmap,wordpointer,3));
}
