#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void login ();
void reg ();
/*void adminlog (int variabel);
void adminreg (int variabel);
void akundelete (int variabel);
void tambahmodul (int variabel);
void userlog (int variabel);
void userreg (int variabel);
void usergantipass (int variabel);
void betalog(int variabel);
void betareg(int variabel);*/

FILE *reg_txt;
int x;
int n, loop = 0;
int looplog = 0;
char string[100];
//char string[];
int main()
{
	FILE *cover;
	cover = fopen("cover.txt", "r");
	while (fgets(string, sizeof(string), cover) != NULL)
	printf("%s",string);
	fclose (cover);
	system ("pause");
	system ("cls");
	while (loop == 0)
	{
		printf ("\n\t||||||||||||| RUANG DASKOM ||||||||||||||\n");
		printf ("\t=========================================\n"
				"\t\t\t  MENU\t\t\n"
				"\t=========================================\n\n");
		printf ("\t  <1> Login\n"
				"\t  <2> Register\n"
				"\t  <3> Exit\n\n");
		printf ("\tPilih menu: ");
		scanf ("%d", &n); system ("cls");
		switch(n)
		{
			case 1:
				while (looplog == 0)
				{
					login();
				}	
				loop++;			
				break;
			case 2:
				while (looplog == 0)
				{
					reg();
				}	
				if (looplog == 2)
				loop;
				else loop++;			
				break;
		}
	}
}
	
/*	printf ("Selamat datang di Ruang Daskom\n"
	"Silahkan pilih menu:\n\n");
	printf ("\t1. Login         ||\t2. Register\n");
	scanf ("%d", n);
	switch (n)
	{
	case 1:
		while (loop == 0)
		{
			printf ("Selamat datang di halaman login\n"
			"Ingin login sebagai apa?");
			printf ("\t1. Admin\n"
			"\t2. User Premium\n"
			"\t3. User Beta\n");
			scanf("%d", n);
			switch(n)
			{
			case 1:
				void adminlog(int variabel);
				loop++
				break;
			case 2:
				void userlog (int variabel);
				loop++
				break;
			case 3:
				void betalog(int variabel);
				loop++
				break;
			default:
				printf ("Menu tidak tersedia, silahkan ulangi\n");
			}
			break;
		case 2:
			printf ("Selamat datang di halaman register\n"
			"Ingin register akun apa?");	
			reg_txt = fopen("Registercover.txt", "r");
			while (fgets(string, sizeof(string), reg_txt) != NULL)
			printf("%s",string);
			fclose (reg_text);
			printf ("\n");
			scanf ("%d", n);
			switch(n)
		{
			case 1:
				
		}
	}
}*/

void login (){
	printf ("Selamat datang di halaman login\n"
			"Ingin login sebagai apa?");
			printf ("\n\t<1> Admin\n"
			"\t<2> User Premium\n"
			"\t<3> User Beta\n");
			scanf("%d", &n);
			switch(n)
			{
				case 1:
					system ("cls");
				//	void adminlog(int variabel);
					printf ("Test 1");
					looplog++;
					break;
				case 2:
					system ("cls");
				//	void userlog (int variabel);
					printf ("Test 2");
					looplog++;
					break;
				case 3:
					system ("cls");
				//	void betalog(int variabel);
					printf ("Test 3");
					looplog++;
					break;
				default:					
					system ("cls");
					printf ("Menu tidak tersedia, silahkan ulangi\n\n");
			}
}


void reg(){
	printf ("Selamat datang di halaman register\n"
			"Silahkan pilih akun: \n\n");
	
			reg_txt = fopen("Registercover.txt", "r");
			while (fgets(string, sizeof(string), reg_txt) != NULL)
			printf("%s",string);
			fclose (reg_txt);
			
			printf ("\n\nKembali tekan 3\n");
			scanf ("%d", &n);
			switch(n)
		{
			case 1:
				system ("cls");
				printf ("Premium yeah");
				looplog++;
				break;
			case 2:
				system ("cls");
				printf ("Beta Hehe");
				looplog++;
				break;
			case 3:
				looplog = 2;
			default:
				system ("cls");
				printf("Pilihan tidak tersedia, silahkan ulangi");	
		}
}
