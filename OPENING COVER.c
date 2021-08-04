#include <stdio.h>
char string[255];
int main(){
FILE *cover;
cover = fopen("contoh.txt", "r");
while (fgets(string, sizeof(string), cover) != NULL)
printf("%s",string);
fclose (cover);
return 0;
} 
