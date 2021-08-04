#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void login ();
void reg ();
void adminlog ();
/*void adminreg ();
void tambahakun ();
void daftarakun();
void akundelete ();
void tambahmodul ();*/
void userlog ();
/*void userreg ();
void usergantipass ();
void betalog();
void betareg();*/


 int main(){
 	userlog();
 }
void userlog(){
	struct{
	char id[20], pass[20];
}user[100];
	int a = 0, i;
	char userid[20], userpass[20];
	printf ("\n");
	printf ("------------- HELLO USER ^_^ ---------------"
	"\n*************Silahkan Login************\n\n");
	printf ("\tUsername\t: ");
	gets(userid);
	printf ("\tPassword\t: ");
	gets(userpass);
	for (i = 0 ; i < 100 ; i++){
	if (strcmp(userid, user[i].id)==0 && strcmp(userpass, user[i].pass)==0){
	printf ("\n"); printf ("============LOGIN BERHASIL=============\n\n"); system ("pause"); system ("cls"); a++;}
	}
	if (a = 1)
	printf ("\n*Username atau Password tidak sesuai, silahkan login kembali!\n\n"); system ("pause"); system("cls"); userlog();
}

