#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//字符串匹配-BF算法
/*
* 1 2 3 4 5 6 7 8 9 A B C D
* a b a b c a b c a c b a b
*           a b c a c
*/
int mate(char* main_str, char* key_str);

//匹配两个字符串,并返回匹配的开始下标(不存在返回-1)
int mate(char* main_str, char* key_str)
{
	int key_len = strlen(key_str);
	int i = 0, j = 0;
	int idx = -1;
	while (main_str[i] && key_str[j]) {
		if (main_str[i] == key_str[j]) {
			i++;
			j++;
		}
		else {
			j = 0;
			i++;
		}
	}
	idx = i - key_len + 1;
	return idx;
}
int main()
{
	char* main_str = "ababcabcacbab";
	char* key_str = "abcac";

	int idx = mate(main_str, key_str);
	printf("idx = %d", idx);

	return 0;
}