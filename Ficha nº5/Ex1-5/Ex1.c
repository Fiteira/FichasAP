#include <stdio.h>
#include <ctype.h> 

int isdigit1(char c){

	return (c >= '0' && c <= '9');

}

int isalpha1(char c) {

	return (c >= 'a' && c <= 'z' && c>='A' && c<='Z');

}

int isalnum1(char c) {
	return (isdigit1(c)||isalpha1(c));
}
char tolower1(char c){
	if(c>='A' && c<='Z')
		return c + 'a'-'A';
	else	
		return c;
}
char tolouper1(char c){
	if(c>='a' && c<='z')
		return c + 'A'-'a';
	else
		return c;	
}

