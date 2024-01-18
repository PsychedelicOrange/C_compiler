#include<stddef.h>
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
	char* string; // 4 bytes
	size_t size; // 8 or 16 bytes
};
struct Hashmap{
	struct Keyword* hash;
	size_t size;
};
// functions forward declaration
void hash_init(struct Hashmap* hashmap,size_t size);
int hash_insert(struct Hashmap* hashmap,enum MULTITOKEN token, char* word,size_t size);
int hash_contains(struct Hashmap* hashmap,char* word, size_t size);
int hash_getToken(struct Hashmap* hashmap,char* word, size_t size);
