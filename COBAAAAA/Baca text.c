#include <stdio.h>
#include <string.h>

FILE *fp;
char string[250];
void main(){
	fp = fopen("soal 1_1.txt", "r");
			while (fgets(string, sizeof(string), fp) != NULL)
				printf("%s", string);
				fclose (fp);
			
}

