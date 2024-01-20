#include"stringstruct.h"
#include <string.h>

struct string string_malloc(size_t size) {
	struct string str; 
	str.array = malloc(size);
	str.size = size;
	return str;
}
void string_free(struct string str){
	free(str.array);
}
void string_print(struct string str){
	fwrite(str.array,sizeof(char),str.size,stdout);
}
struct string string_copy(struct string src){
	struct string str = string_malloc(src.size);
	memcpy(str.array,src.array,src.size);
	str.size = src.size;
	return str;
}
struct string string_copy_c_style(char* src,size_t size){
	struct string str = string_malloc(size);
	memcpy(str.array,src,size);
	str.size = size;
	return str;
}
