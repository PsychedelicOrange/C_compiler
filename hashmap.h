#include<stddef.h>
#include"stringstruct.h"
enum MULTITOKEN{
	// KEYWORKDS
	NULL_DEBUG = 128,
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
struct Keyword{
	enum MULTITOKEN token; // 4 bytes
	struct string str;
};
struct Hashmap{
	struct Keyword* hash;
	struct Keyword* array;
	size_t size;
};
// functions forward declaration
void hash_init(struct Hashmap* hashmap,size_t size);
int hash_insert(struct Hashmap* hashmap,enum MULTITOKEN token, char* word,size_t size);
int hash_contains(struct Hashmap* hashmap,char* word, size_t size);
int hash_getToken(struct Hashmap* hashmap,char* word, size_t size);
void hash_insert_all_tokens(struct Hashmap* hashmap);
struct string hash_getString(struct Hashmap hashmap, enum MULTITOKEN mtoken);
