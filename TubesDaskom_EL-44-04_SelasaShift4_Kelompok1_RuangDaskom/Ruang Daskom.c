#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void login();
void reg();
//ADMIN
void adminlog();
void adminmenu();
void tambahakun ();
void daftarakun();
void userdelete();
void betadelete();
void tambahmodul ();
//PREMIUM
void userlog();
void userreg();
void usermenu();
void usertemp();
void usergantipass();
void usermodul();
void usersoal();
void usermodultambah();
//BETA
void betalog();
void betareg();
void betamenu();
void betatemp();
void betamodul();
void betasoal();
//MISC
void sort();
void sortuser();
void sortbeta();
void milih();

struct{
	char id[20], pass[20], name[25];
}user, beta, temp[100], temp2;

struct{
	char judul[100000], isi[100000];
}Modul;

FILE *reg_txt;
FILE *user_file;
FILE *modul;
FILE *soal;

char jwb, pilih;
int j = 0, i = 0, l;
int x, USER;
int n, loop = 0;
int looplog = 0;
char string[10000];

int main()
{
	FILE *cover;
	cover = fopen("cover.txt", "r");
	while (fgets(string, sizeof(string), cover) != NULL)
	printf("%s",string);
	fclose (cover);
	system ("pause");
	system ("cls");
	menu();
}

void menu(){
	printf ("\t========================================="
			"\n\t||||||||||||| RUANG DASKOM ||||||||||||||\n");
	printf ("\t=========================================\n"
			"\t\t       MAIN MENU\t\t\n"
			"\t-----------------------------------------\n\n");
	printf ("\t  <1> Login\n"
			"\t  <2> Register\n"
			"\t  <3> Exit\n\n");
	printf ("\tPilih menu: ");
	scanf ("%d", &n); system ("cls");
	switch(n)
	{
		case 1:
			login();			
			break;
		case 2:
			reg();
			break;
		case 3:
			system("cls");			
			printf ("\n\n\n\t\t************* Terima Kasih telah menggunakan layanan RUANG DASKOM ^_^ **************\n\n");
			system("pause");
			exit(0);				
			break;
		default:
			system ("cls");
			printf ("Menu tidak tersedia, silahkan ulangi\n\n");
			system ("pause");
			system ("cls"); getchar();
			menu();
	}
}

void login (){
	printf ("\n\t\tSelamat datang di halaman login\n"
			"\t===============================================\n"
			"Daftar akun: \n");
			printf (
			"\n\t<1> Admin\n"
			"\t<2> User Premium\n"
			"\t<3> User Beta\n"
			"\t<4> Kembali\n\n");
			printf("Pilih menu: ");
			scanf("%d", &n);
			getchar();
			switch(n)
			{
				case 1:
					USER = 2;
					adminlog();					
					adminmenu();
					break;
				case 2:
					system ("cls");
					USER = 2;
					userlog (user_file);
					usermenu();
					break;
				case 3:
					system ("cls");
					USER = 2;
					betalog();
					betamenu();
					break;
				case 4:
					system ("cls");
					menu();									
				default:					
					printf ("\n");
					printf ("Pilihan tidak tersedia, silahkan ulangi\n\n");
					system("pause");
					system ("cls");
					login();
			}
		}

void reg(){
	printf ("\n\t\tSelamat datang di halaman register\n"
			"\t===============================================\n"
			"\tSilahkan pilih akun: \n\n");
	printf ("\t<1> Premium\n"
			"\t<2> Beta\n"
			"\t<3> Kembali\n");
	printf ("\n\tPilih: ");
			scanf ("%d", &n);
			switch(n)
		{
			case 1:
				system ("cls");
				userreg (user_file);
				looplog++;
				break;
			case 2:
				system ("cls");
				betareg ();
				looplog++;
				break;
			case 3:
				system("cls");
				menu();
				break;
			default:
				printf ("\n");
				printf ("Pilihan tidak tersedia, silahkan ulangi\n\n");
				system("pause");
				system ("cls");
				reg();
				break;
		}
}

void adminlog(){
	system("cls");
	char adminid[8], adminpass[8];
	printf ("\n");
	printf ("-----------------ADMIN-----------------"
	"\n================ LOGIN =====================\n\n");
	printf ("\tUsername\t: ");
	gets(adminid);
	printf ("\tPassword\t: ");
	gets(adminpass);
	if (strcmp(adminid, "admin")==0 && strcmp(adminpass, "admin")==0){
		printf ("\n"); printf ("\n============LOGIN BERHASIL=============\n\n"); system ("pause"); system ("cls");}
	
	else if(USER > 0){
		printf ("\n*Username atau Password tidak sesuai, kesempatan login %d kali lagi\n\n", USER); USER--; system ("pause"); system("cls"); adminlog();}

	else {
		printf ("\n*Kesempatan login habis!!!\n\n"); system("pause"); system ("cls"); login();
		}
}

void daftarakun(){
	FILE *user_file2;
	int m, n;
	
	sortuser();
	sortbeta();
	
	i=1;
	printf ("\n\t====================== PREMIUM =======================\n\n");
	user_file = fopen("User Premium.dat", "rb"); 
	while (fread (&user, sizeof(user), 1, user_file) == 1){
		printf ("\t%d.  Nama\t: %s\n", i, user.name); 
		printf ("\t    Username\t: %s\n", user.id);
		printf ("\t    Password\t: %s\n", user.pass);
		printf ("\n");
		i++;
		}
	fclose(user_file); 

	i = 1;
	printf ("\n\t========================= BETA =========================\n\n");
	user_file = fopen("User Beta.dat", "rb"); 
	while (fread (&beta, sizeof(beta), 1, user_file) == 1){
		printf ("\t%d.  Nama\t: %s\n", i, beta.name); 
		printf ("\t    Username\t: %s\n", beta.id);
		printf ("\t    Password\t: %s\n", beta.pass);
		printf ("\n");
		i++;
		}
	fclose(user_file); 
	
	printf("-------------------------------------------------------------------\n\n"
		   "Menu: "
		   "\t<1> Kembali\n"
		   "\t<2> Hapus Akun Premium\n"
		   "\t<3> Hapus Akun Beta"
		   "\n\n    Pilih: ");
	scanf("%d", &n);
	switch(n){
		case 1:
			system("cls");
			adminmenu();
			break;
		case 2:
			system("cls");
			userdelete();
			break;
		case 3:
			system("cls");
			betadelete();
			break;			
		default:
			system ("cls");
			printf ("Menu tidak tersedia, silahkan ulangi\n\n");
			system ("pause");
			system ("cls");
			daftarakun();			
	}
}

void adminmenu(){
	char pilih;
		printf ("Apa yang ingin kamu lakukan?\n\n");
		printf ("\t<1> Tambah akun\n"
				"\t<2> Tampilkan daftar akun + hapus akun\n"
				"\t<3> Tambah modul\n"
				"\t<4> Logout"
				"\n\n");
		printf ("Pilih: ");
		scanf ("%d", &n);
		switch (n){
			case 1:
				getchar();
				tambahakun();
				system ("cls");
				break;
			case 2:
				getchar();
				system ("cls");
				daftarakun();
				break;				
			case 3:
				getchar();
				tambahmodul();
				system("pause");
				system("cls");
				adminmenu();
				break;
			case 4:
				printf("\nApakah anda yakin? (Y/N)\n"
			   		   "Pilih: ");
			   		   getchar();
			   	scanf("%c", &pilih);
				if(pilih == 'Y' || pilih == 'y'){
					system("cls");
					printf("------------------- LOGOUT BERHASIL ------------------\n\n");
					system("pause");
					system("cls");
					menu();
				}
				else if(pilih == 'N' || pilih == 'n'){
					printf("*Logout dibatalkan\n\n");
					system("pause");
					system("cls");
					adminmenu();
				}
				else {
					system ("cls");
					printf ("Menu tidak tersedia, kembali ke menu\n\n");
					system ("pause");
					system ("cls");
					adminmenu();
				}
				break;
			default:
				system ("cls");
				printf ("Menu tidak tersedia, silahkan ulangi\n\n");
				system ("pause");
				system ("cls");
				adminmenu();
		}
	}
	


void userdelete(){
	fflush(stdin);
	FILE *user_file2;
	char usernama[20], pilih;
	j = 0;
	printf ("\n");
	printf ("------------- HAPUS AKUN ---------------\n\n");

	user_file = fopen("User Premium.dat", "rb");
	user_file2 = fopen("User Premium2.dat", "wb");
	printf("Masukkan nama pemilik akun yang ingin dihapus: ");
	gets (usernama);
	while (fread(&user,sizeof (user), 1, user_file)==1){
			if (strcmp(usernama, user.name)==0){
				j++;	
			}
	}fclose(user_file);
	
	if (j == 0) {
		printf ("\n*Nama tidak tersedia, kembali ke menu\n");
		fclose(user_file);
		fclose(user_file2);
		system("pause"); system("cls"); daftarakun();
	}
	else {
		printf("Apakah anda yakin? (Y/N)\n"
			   "Pilih: "); fflush(stdin);
		scanf("%c", &pilih);
		if(pilih == 'Y' || pilih == 'y'){
			printf("*Hapus akun dilanjutkan\n\n");
			system("pause");
			user_file = fopen("User Premium.dat", "rb");
			while (fread(&user, sizeof (user),1, user_file)==1){
				if (strcmp(usernama, user.name)!=0){
					fwrite(&user, sizeof(user), 1, user_file2);
				}	
			}
	
			fclose(user_file);
			fclose(user_file2);
	
			remove("User Premium.dat");
			rename("User Premium2.dat","User Premium.dat");
	
			printf("\n================= HAPUS AKUN BERHASIL!!! ====================\n\n");
			system("pause"); system("cls");
			daftarakun();
		}
		else if(pilih == 'N' || pilih == 'n'){
			printf("*Hapus akun dibatalkan\n\n");
			fclose(user_file);
			fclose(user_file2);
			system("pause");
			system("cls");
			getchar();
			daftarakun();
		}
		else{
			printf("*Menu tidak tersedia, kembali ke menu\n\n");
			fclose(user_file);
			fclose(user_file2);
			system("pause");
			system("cls");
			getchar();
			daftarakun();
		}		
	}
}

void betadelete(){
	fflush(stdin);
	FILE *user_file2;
	char usernama[20], pilih;
	j = 0;
	printf ("\n");
	printf ("------------- HAPUS AKUN ---------------\n\n");

	user_file = fopen("User Beta.dat", "rb");
	user_file2 = fopen("User Beta2.dat", "wb");
	printf("Masukkan nama pemilik akun yang ingin dihapus: ");
	gets (usernama);
	while (fread(&beta,sizeof (beta), 1, user_file)==1){
			if (strcmp(usernama, beta.name)==0){
				j++;	
			}
	}fclose(user_file);
	
	if (j == 0) {
		printf ("\n*Nama tidak tersedia, kembali ke menu\n");
		fclose(user_file);
		fclose(user_file2);
		system("pause"); system("cls"); daftarakun();
	}
	else {
		printf("Apakah anda yakin? (Y/N)\n"
			   "Pilih: "); fflush(stdin);
		scanf("%c", &pilih);
		if(pilih == 'Y' || pilih == 'y'){
			printf("*Hapus akun dilanjutkan\n\n");
			system("pause");
			user_file = fopen("User Beta.dat", "rb");
			while (fread(&beta,sizeof (beta),1, user_file)==1){
				if (strcmp(usernama, beta.name)!=0){
					fwrite(&beta, sizeof(beta), 1, user_file2);
				}	
			}
	
			fclose(user_file);
			fclose(user_file2);
	
			remove("User Beta.dat");
			rename("User Beta2.dat","User Beta.dat");
	
			printf("\n================= HAPUS AKUN BERHASIL!!! ====================\n\n");
			system("pause"); system("cls");
			daftarakun();
		}
		else if(pilih == 'N' || pilih == 'n'){
			printf("*Hapus akun dibatalkan\n\n");
			fclose(user_file);
			fclose(user_file2);
			system("pause");
			system("cls");
			getchar();
			daftarakun();
		}
		else{
			printf("*Menu tidak tersedia, kembali ke menu\n\n");
			fclose(user_file);
			fclose(user_file2);
			system("pause");
			system("cls");
			getchar();
			daftarakun();
		}		
	}
}

void tambahakun(){
	user_file = fopen("User Premium.dat","ab"); 
	printf("Banyak Mahasiswa: "); 
	scanf("%d", &n); getchar(); 
	for (i=0; i<=n-1; i++){ 
		printf ("-Akun ke-%d \n",i+1);
		printf ("Username: "); fflush(stdin);
		gets (user.id);
		printf("Password: "); fflush(stdin);
		gets (user.pass);
		printf ("Nama: "); fflush(stdin);
		gets (user.name);						
		printf ("\n\n");
		fwrite(&user, sizeof(user), 1, user_file); 
	} 
	fclose(user_file); 	
	system("cls");
	daftarakun();				
}

void tambahmodul(){
	user_file = fopen("Modul Tambahan.dat","ab"); 
	printf("Judul modul: ");
	gets(Modul.judul);
	printf("Isi: ");
	gets(Modul.isi);				
	fwrite(&Modul, sizeof(Modul), 1, user_file); 
	
	fclose(user_file); 					
}

void userlog(){
	char userid[20], userpass[20], j = 0;
	printf ("\n");
	printf ("------------- HELLO USER ^_^ ---------------"
	"\n================ LOGIN =====================\n\n");
	user_file = fopen("User Premium.dat", "rb");
	printf ("\tUsername\t: "); fflush(stdin);
	gets(userid);
	printf ("\tPassword\t: "); fflush(stdin);
	gets(userpass);
	while (fread(&user, sizeof(user), 1, user_file) == 1){
	if (strcmp(user.id, userid) == 0 && strcmp(user.pass, userpass) == 0){
		printf ("\n============LOGIN BERHASIL=============\n\n"); j++; fclose(user_file); system ("pause"); system ("cls");} 
		}
	if(j == 0){
		if(USER > 0){
			printf ("\n*Username atau Password tidak sesuai, kesempatan login %d kali lagi\n\n", USER); USER--; fclose(user_file); system ("pause"); system("cls"); userlog();}
		else {
			printf ("\n*Kesempatan login habis!!!\n\n"); fclose(user_file); system("pause"); system ("cls"); login();
		}
	}
}

void userreg(){
	getchar();
	printf ("\n");
	printf ("------------- HELLO USER ^_^ ---------------"
	"\n================ REGISTER ===================\n\n");
	user_file = fopen("User Premium.dat", "ab"); 
	printf ("Username: ");
	gets (user.id);
	printf("Password: ");
	gets (user.pass);
	printf ("Nama: ");
	gets (user.name);
	fwrite(&user, sizeof(user), 1, user_file); 
	fclose(user_file);
	printf("\n================= REGISTRASI BERHASIL!!! ===================\n\n");
	system("pause");
	system("cls");
	main();
}

void usermenu(){
	char pilih;
		printf ("Apa yang ingin kamu lakukan?\n\n");
		printf (
				"\t<1> Modul\n"
				"\t<2> Modul++\n"
				"\t<3> Ganti Password\n"
				"\t<4> Logout"
				"\n\n");
		printf ("Pilih: ");
		scanf ("%d", &n);
		switch(n){
			case 1:
				system("cls");
				usermodul();
				break;
			case 2:
				usermodultambah();
				break;
			case 3:
				system("cls");				
				getchar();
				usergantipass();
				printf ("Ganti Password");
				break;
			case 4:
				printf("\nApakah anda yakin? (Y/N)\n"
				   		   "Pilih: ");
				getchar();
				scanf("%c", &pilih);
				if(pilih == 'Y' || pilih == 'y'){
					system("cls");
					printf("------------------- LOGOUT BERHASIL ------------------\n\n");
					system("pause");
					system("cls");
					menu();
				}
				else if(pilih == 'N' || pilih == 'n'){
					printf("*Logout dibatalkan\n\n");
					system("pause");
					system("cls");
					usermenu();
				}
				else {
					system ("cls");
					printf ("Menu tidak tersedia, kembali ke menu\n\n");
					system ("pause");
					system ("cls");
					usermenu();
				}
				break;
		default:					
			printf ("\n\nPilihan tidak tersedia, silahkan ulangi\n\n");
			system ("pause");
			system ("cls");
			usermenu();
		}
	}


void usergantipass(){
	j = 0;
	FILE *user_file2;
	char userid[20], userpass[20], userpass2[20];
	printf ("\n");
	printf ("------------- GANTI PASSWORD ---------------\n\n");
	usertemp();
	l = i-1;
	user_file = fopen("User Premium.dat", "rb");
	user_file2 = fopen("User Premium2.dat", "wb");
	printf("Username: "); fflush(stdin);
	gets (userid);
	printf("Password: "); fflush(stdin);
	gets (userpass);
	while (fread(&user,sizeof (user),1, user_file)==1){
			if (strcmp(userpass, user.pass)==0 && strcmp(userid, user.id)==0){
			j++;
			}
	}

	if (j == 0) {
		printf ("\n*Username atau Password tidak sesuai, silahkan ulangi!!!"); fclose(user_file); fclose(user_file2); system("pause"); system("cls"); usergantipass();
		}
		
		printf ("\nMasukkan password baru: "); fflush(stdin);
		gets(userpass2); 
		
	for(i = 0 ; i <= l ; i++){
		if(strcmp(temp[i].pass, userpass)==0){
			strcpy(temp[i].pass, userpass2);
		}
	}
		
	for(i = 0 ; i <= l ; i++){
		strcpy(user.id, temp[i].id);			
		strcpy(user.pass, temp[i].pass);
		strcpy(user.name, temp[i].name);
		fwrite(&user, sizeof(user), 1, user_file2); 
	}
	
	fclose(user_file);
	fclose(user_file2);
	
	remove("User Premium.dat");
	rename("User Premium2.dat","User Premium.dat");
	printf("\n\n\tGanti password berhasil, kembali ke menu...\n");
	system("pause");
	system("cls");
	menu(); 
}

void usermodul(){
	printf("\n\t======================= MODUL ======================\n");
	printf ("Menu: \n\n");
	printf (
			"\t<1> Modul 1: IDE DAN PENGANTAR ALGORITMA\n"
			"\t<2> Modul 2: TIPE DATA DAN KOMPONEN\n"
			"\t<3> Modul 3: PERCABANGAN\n"
			"\t<4> Modul 4: PERULANGAN\n"
			"\t<5> Modul 5: FUNGSI\n"
			"\t<6> Modul 6: ARRAY\n"
			"\t<7> Modul 7: SORTING\n"
			"\t<8> Modul 8: SEARCHING\n"
			"\t<9> Kembali\n"
			"\n\n");
	printf ("Pilih modul: ");
	scanf ("%d", &n);
	switch(n){
		case 1:
			system("cls");
			modul = fopen("modul 1.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			usersoal();
			break;
		case 2:
			system("cls");
			modul = fopen("modul 2.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			usersoal();
			break;
		case 3:
			system("cls");
			modul = fopen("modul 3.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			usersoal();
			break;
		case 4:
			system("cls");
			modul = fopen("modul 4.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			usersoal();
			break;
		case 5:
			system("cls");
			modul = fopen("modul 5.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			usersoal();
			break;
		case 6:
			system("cls");
			modul = fopen("modul 6.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			usersoal();
			break;
		case 7:
			system("cls");
			modul = fopen("modul 7.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			usersoal();
			break;
		case 8:
			system("cls");
			modul = fopen("modul 8.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			usersoal();
			break;
		case 9:
			system("cls");
			usermenu();
			break;
		default:					
			printf("\n\n");
			printf ("Pilihan tidak tersedia, silahkan ulangi\n\n");
			system("pause");
			system("cls");
			usermodul();
	}
}

void usersoal(){
	getchar();
	printf("=========================== SOAL ==============================\n");
	switch(n){
		case 1:{
			soal = fopen("soal 1_1.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'C' || jwb == 'c'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********");
			}
			else{
				printf("\n*********Jawaban Salah*********");
			}
			printf("\n\nLanjut? (Y/N)\n"
				   "Pilih: "); getchar();
			scanf("%c", &pilih);
			if(pilih == 'Y' || pilih == 'y'){
				soal = fopen("soal 1_2.txt", "r");
				while (fgets(string, sizeof(string), soal) != NULL)
					printf("%s",string);
					fclose (soal);
				
					printf("\nJawab: "); getchar();
					scanf("%c", &jwb); 
				if(jwb == 'B' || jwb == 'b'){		//JAWABAN 2
					printf("\n\n*********Jawaban Benar*********");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
				else{
					printf("\n\n*********Jawaban Salah*********\n");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
			}
			else if(pilih == 'N' || pilih == 'n'){
				system("cls");
				usermodul();
			}
			else {
				system ("cls");
				printf ("Menu tidak tersedia, kembali ke modul\n\n");
				system ("pause");
				system ("cls");
				usermodul();
			}
		}
			break;
		case 2:{
			soal = fopen("soal 2_1.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'D' || jwb == 'd'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********");
			}
			else{
				printf("\n*********Jawaban Salah*********");
			}
			printf("\n\nLanjut? (Y/N)\n"
				   "Pilih: "); getchar();
			scanf("%c", &pilih);
			if(pilih == 'Y' || pilih == 'y'){
				soal = fopen("soal 2_2.txt", "r");
				while (fgets(string, sizeof(string), soal) != NULL)
					printf("%s",string);
					fclose (soal);
				
					printf("\nJawab: "); getchar();
					scanf("%c", &jwb); 
				if(jwb == 'D' || jwb == 'd'){		//JAWABAN 2
					printf("\n\n*********Jawaban Benar*********");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
				else{
					printf("\n\n*********Jawaban Salah*********\n");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
			}
			else if(pilih == 'N' || pilih == 'n'){
				system("cls");
				usermodul();
			}
			else {
				system ("cls");
				printf ("Menu tidak tersedia, kembali ke modul\n\n");
				system ("pause");
				system ("cls");
				usermodul();
			}
		}
			break;	
		case 3:{
			soal = fopen("soal 3_1.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'A' || jwb == 'a'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********");
			}
			else{
				printf("\n*********Jawaban Salah*********");
			}
			printf("\n\nLanjut? (Y/N)\n"
				   "Pilih: "); getchar();
			scanf("%c", &pilih);
			if(pilih == 'Y' || pilih == 'y'){
				soal = fopen("soal 3_2.txt", "r");
				while (fgets(string, sizeof(string), soal) != NULL)
					printf("%s",string);
					fclose (soal);
				
					printf("\nJawab: "); getchar();
					scanf("%c", &jwb); 
				if(jwb == 'C' || jwb == 'c'){		//JAWABAN 2
					printf("\n\n*********Jawaban Benar*********");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
				else{
					printf("\n\n*********Jawaban Salah*********\n");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
			}
			else if(pilih == 'N' || pilih == 'n'){
				system("cls");
				usermodul();
			}
			else {
				system ("cls");
				printf ("Menu tidak tersedia, kembali ke modul\n\n");
				system ("pause");
				system ("cls");
				usermodul();
			}
		}
			break;		
		case 4:{
			soal = fopen("soal 4_1.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'A' || jwb == 'a'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********");
			}
			else{
				printf("\n*********Jawaban Salah*********");
			}
			printf("\n\nLanjut? (Y/N)\n"
				   "Pilih: "); getchar();
			scanf("%c", &pilih);
			if(pilih == 'Y' || pilih == 'y'){
				soal = fopen("soal 4_2.txt", "r");
				while (fgets(string, sizeof(string), soal) != NULL)
					printf("%s",string);
					fclose (soal);
				
					printf("\nJawab: "); getchar();
					scanf("%c", &jwb); 
				if(jwb == 'C' || jwb == 'c'){		//JAWABAN 2
					printf("\n\n*********Jawaban Benar*********");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
				else{
					printf("\n\n*********Jawaban Salah*********\n");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
			}
			else if(pilih == 'N' || pilih == 'n'){
				system("cls");
				usermodul();
			}
			else {
				system ("cls");
				printf ("Menu tidak tersedia, kembali ke modul\n\n");
				system ("pause");
				system ("cls");
				usermodul();
			}
		}
			break;	
		case 5:{
			soal = fopen("soal 5_1.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'A' || jwb == 'a'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********");
			}
			else{
				printf("\n*********Jawaban Salah*********");
			}
			printf("\n\nLanjut? (Y/N)\n"
				   "Pilih: "); getchar();
			scanf("%c", &pilih);
			if(pilih == 'Y' || pilih == 'y'){
				soal = fopen("soal 5_2.txt", "r");
				while (fgets(string, sizeof(string), soal) != NULL)
					printf("%s",string);
					fclose (soal);
				
					printf("\nJawab: "); getchar();
					scanf("%c", &jwb); 
				if(jwb == 'D' || jwb == 'd'){		//JAWABAN 2
					printf("\n\n*********Jawaban Benar*********");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
				else{
					printf("\n\n*********Jawaban Salah*********\n");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
			}
			else if(pilih == 'N' || pilih == 'n'){
				system("cls");
				usermodul();
			}
			else {
				system ("cls");
				printf ("Menu tidak tersedia, kembali ke modul\n\n");
				system ("pause");
				system ("cls");
				usermodul();
			}
		}
			break;	
		case 6:{
			soal = fopen("soal 6_1.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'B' || jwb == 'b'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********");
			}
			else{
				printf("\n*********Jawaban Salah*********");
			}
			printf("\n\nLanjut? (Y/N)\n"
				   "Pilih: "); getchar();
			scanf("%c", &pilih);
			if(pilih == 'Y' || pilih == 'y'){
				soal = fopen("soal 6_2.txt", "r");
				while (fgets(string, sizeof(string), soal) != NULL)
					printf("%s",string);
					fclose (soal);
				
					printf("\nJawab: "); getchar();
					scanf("%c", &jwb); 
				if(jwb == 'C' || jwb == 'c'){		//JAWABAN 2
					printf("\n\n*********Jawaban Benar*********");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
				else{
					printf("\n\n*********Jawaban Salah*********\n");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
			}
			else if(pilih == 'N' || pilih == 'n'){
				system("cls");
				usermodul();
			}
			else {
				system ("cls");
				printf ("Menu tidak tersedia, kembali ke modul\n\n");
				system ("pause");
				system ("cls");
				usermodul();
			}
		}
			break;	
		case 7:{
			soal = fopen("soal 7_1.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'B' || jwb == 'b'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********");
			}
			else{
				printf("\n*********Jawaban Salah*********");
			}
			printf("\n\nLanjut? (Y/N)\n"
				   "Pilih: "); getchar();
			scanf("%c", &pilih);
			if(pilih == 'Y' || pilih == 'y'){
				soal = fopen("soal 7_2.txt", "r");
				while (fgets(string, sizeof(string), soal) != NULL)
					printf("%s",string);
					fclose (soal);
				
					printf("\nJawab: "); getchar();
					scanf("%c", &jwb); 
				if(jwb == 'B' || jwb == 'b'){		//JAWABAN 2
					printf("\n\n*********Jawaban Benar*********");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
				else{
					printf("\n\n*********Jawaban Salah*********\n");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
			}
			else if(pilih == 'N' || pilih == 'n'){
				system("cls");
				usermodul();
			}
			else {
				system ("cls");
				printf ("Menu tidak tersedia, kembali ke modul\n\n");
				system ("pause");
				system ("cls");
				usermodul();
			}
		}
			break;		
		case 8:{
			soal = fopen("soal 8_1.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'A' || jwb == 'a'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********");
			}
			else{
				printf("\n*********Jawaban Salah*********");
			}
			printf("\n\nLanjut? (Y/N)\n"
				   "Pilih: "); getchar();
			scanf("%c", &pilih);
			if(pilih == 'Y' || pilih == 'y'){
				soal = fopen("soal 8_2.txt", "r");
				while (fgets(string, sizeof(string), soal) != NULL)
					printf("%s",string);
					fclose (soal);
				
					printf("\nJawab: "); getchar();
					scanf("%c", &jwb); 
				if(jwb == 'B' || jwb == 'b'){		//JAWABAN 2
					printf("\n\n*********Jawaban Benar*********");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
				else{
					printf("\n\n*********Jawaban Salah*********\n");
					printf("\n\nUlangi? (Y/N)\n" //ULANGI?
				  		   "Pilih: "); getchar();
					scanf("%c", &pilih);
					if(pilih == 'Y' || pilih == 'y'){
						system("cls");
						usersoal();
					}
					else if(pilih == 'N' || pilih == 'n'){
						system("cls");
						usermodul();
					}
					else {
						system ("cls");
						printf ("Menu tidak tersedia, kembali ke modul\n\n");
						system ("pause");
						system ("cls");
						usermodul();
					}
				}
			}
			else if(pilih == 'N' || pilih == 'n'){
				system("cls");
				usermodul();
			}
			else {
				system ("cls");
				printf ("Menu tidak tersedia, kembali ke modul\n\n");
				system ("pause");
				system ("cls");
				usermodul();
			}
			}
			break;												
		}
	}


void usermodultambah(){
	user_file = fopen("Modul Tambahan.dat", "rb"); 
	while (fread (&Modul, sizeof(Modul), 1, user_file) == 1)
		printf ("Judul: %s\n\n", Modul.judul); 
		printf ("Materi: \n\n%s\n", Modul.isi);
		
	fclose(user_file); 	
	
	printf("\n\n-------------------------------------------------------------------\n\n"
		   "Menu: "
		   "\t<1> Kembali\n"
		   "\t<2> Logout"
		   "\n\n    Pilih: ");
	scanf("%d", &n);
	switch(n){
		case 1:
			system("cls");
			usermenu();
			break;
		case 2:
			printf("\nApakah anda yakin? (Y/N)\n"
			   		   "Pilih: ");
			getchar();
			scanf("%c", &pilih);
			if(pilih == 'Y' || pilih == 'y'){
				system("cls");
				printf("------------------- LOGOUT BERHASIL ------------------\n\n");
				system("pause");
				system("cls");
				menu();
			}
			else if(pilih == 'N' || pilih == 'n'){
				printf("*Logout dibatalkan\n\n");
				system("pause");
				system("cls");
				usermodultambah();
			}
			else {
				system ("cls");
				printf ("Menu tidak tersedia, kembali ke menu\n\n");
				system ("pause");
				system ("cls");
				usermenu();
			}
			break;
		default:
			system ("cls");
			printf ("Menu tidak tersedia, silahkan ulangi\n\n");
			system ("pause");
			system ("cls");
			usermenu();			
	}
}

void betalog(){
	int i;
	char betaid[20], betapass[20], j = 0;
	printf ("\n");
	printf ("------------- HELLO BETA ^_^ ---------------"
	"\n================ LOGIN =====================\n\n");
	user_file = fopen("User Beta.dat", "rb"); 
	printf ("\tUsername\t: "); fflush(stdin);
	gets(betaid); 
	printf ("\tPassword\t: "); fflush(stdin);
	gets(betapass);
	while (fread(&beta, sizeof(beta), 1, user_file) == 1){
	if (strcmp(beta.id, betaid) == 0 && strcmp(beta.pass, betapass) == 0){
		printf ("\n============LOGIN BERHASIL=============\n\n"); j++; fclose(user_file); system ("pause"); system ("cls");} 
		}
	if(j == 0){
		if(USER > 0){
			printf ("\n*Username atau Password tidak sesuai, kesempatan login %d kali lagi\n\n", USER); USER--; fclose(user_file); system ("pause"); system("cls"); betalog(x);
			}

		else {
			printf ("\n*Kesempatan login habis!!!\n\n"); fclose(user_file); system("pause"); system ("cls"); login();
		}
	}
}

void betareg(){
	getchar();
	printf ("\n");
	printf ("------------- HELLO BETA ^_^ ---------------"
	"\n================ REGISTER ===================\n\n");
	user_file = fopen("User Beta.dat", "ab"); 
	printf ("Username: ");
	gets (beta.id);
	printf("Password: ");
	gets (beta.pass);
	printf ("Nama: ");
	gets (beta.name);
	fwrite(&beta, sizeof(beta), 1, user_file); 
	fclose(user_file);
	
	printf("Register Berhasil\n");
	system("pause");
	system("cls");
	menu();
}

void betamenu(){
	char pilih;
	printf ("Apa yang ingin kamu lakukan?\n\n");
	printf (
			"\t<1> Modul\n"
			"\t<2> Modul++\n"
			"\t<3> Logout"
			"\n\n");
	printf ("Pilih: ");
	scanf ("%d", &n);
	switch(n){
		case 1:
			betamodul();
			break;
		case 2:
			printf("Fitur Terkunci\n\n");
			system("pause");
			system("cls");
			betamenu();
			break;
		case 3:
			printf("\nApakah anda yakin? (Y/N)\n"
			   		   "Pilih: ");
			getchar();
			scanf("%c", &pilih);
			if(pilih == 'Y' || pilih == 'y'){
				system("cls");
				printf("------------------- LOGOUT BERHASIL ------------------\n\n");
				system("pause");
				system("cls");
				menu();
			}
			else if(pilih == 'N' || pilih == 'n'){
				printf("*Logout dibatalkan\n\n");
				system("pause");
				system("cls");
				betamenu();
			}
			else {
				system ("cls");
				printf ("Menu tidak tersedia, kembali ke menu\n\n");
				system ("pause");
				system ("cls");
				betamenu();
			}
			break;
		default:					
			printf ("\n\nPilihan tidak tersedia, silahkan ulangi\n\n");
			system ("pause");
			system ("cls");
			betamenu();
		}
}

void betamodul(){
	printf("\n\t======================= MODUL ======================\n");
	printf ("Menu: \n\n");
	printf (
			"\t<1> Modul 1: IDE DAN PENGANTAR ALGORITMA\n"
			"\t<2> Modul 2: TIPE DATA DAN KOMPONEN\n"
			"\t<3> Modul 3: PERCABANGAN\n"
			"\t<4> Modul 4: PERULANGAN\n"
			"\t<5> Modul 5: FUNGSI\n"
			"\t<6> Modul 6: ARRAY\n"
			"\t<7> Modul 7: SORTING\n"
			"\t<8> Modul 8: SEARCHING\n"
			"\t<9> Kembali\n"
			"\n\n");
	printf ("Pilih modul: ");
	scanf ("%d", &n);
	switch(n){
		case 1:
			system("cls");
			modul = fopen("modul 1.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			betasoal();
			break;
		case 2:
			system("cls");
			modul = fopen("modul 2.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			betasoal();
			break;
		case 3:
			system("cls");
			modul = fopen("modul 3.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			betasoal();
			break;
		case 4:
			system("cls");
			modul = fopen("modul 4.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			betasoal();
			break;
		case 5:
			system("cls");
			modul = fopen("modul 5.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			betasoal();
			break;
		case 6:
			system("cls");
			modul = fopen("modul 6.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			betasoal();
			break;
		case 7:
			system("cls");
			modul = fopen("modul 7.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			betasoal();
			break;
		case 8:
			system("cls");
			modul = fopen("modul 8.txt", "r");
			while (fgets(string, sizeof(string), modul) != NULL)
			printf("%s",string);
			fclose (modul);
			system("pause");
			system("cls");
			betasoal();
			break;
		case 9:
			system("cls");
			betamenu();
			break;
		default:					
			printf("\n\n");
			printf ("Pilihan tidak tersedia, silahkan ulangi\n\n");
			system("pause");
			system("cls");
			betamodul();
	}
}

void betasoal(){
	getchar();
	printf("=========================== SOAL ==============================\n");
	switch(n){
		case 1:{
			soal = fopen("soal 1_1.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'C' || jwb == 'c'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********\n");
				system("pause");
				system("cls");
				main();
			}
			else{
				printf("\n*********Jawaban Salah*********\n");
				system("pause");
				system("cls");
				main();
			}
		}
			break;
		case 2:{
			soal = fopen("soal 2_1.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'D' || jwb == 'd'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********\n");
				system("pause");
				system("cls");
				main();
			}
			else{
				printf("\n*********Jawaban Salah*********\n");
				system("pause");
				system("cls");
				main();
			}
		}
			break;	
		case 3:{
			soal = fopen("soal 3_2.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'C' || jwb == 'c'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********\n");
				system("pause");
				system("cls");
				main();
			}
			else{
				printf("\n*********Jawaban Salah*********\n");
				system("pause");
				system("cls");
				main();
			}
		}
			break;	
		case 4:{
			soal = fopen("soal 4_2.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'C' || jwb == 'c'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********\n");
				system("pause");
				system("cls");
				main();
			}
			else{
				printf("\n*********Jawaban Salah*********\n");
				system("pause");
				system("cls");
				main();
			}
		}
			break;	
		case 5:{
			soal = fopen("soal 5_1.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'A' || jwb == 'a'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********\n");
				system("pause");
				system("cls");
				main();
			}
			else{
				printf("\n*********Jawaban Salah*********\n");
				system("pause");
				system("cls");
				main();
			}
		}
			break;		
		case 6:{
			soal = fopen("soal 6_2.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'C' || jwb == 'c'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********\n");
				system("pause");
				system("cls");
				main();
			}
			else{
				printf("\n*********Jawaban Salah*********\n");
				system("pause");
				system("cls");
				main();
			}
		}
			break;	
		case 7:{
			soal = fopen("soal 7_1.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'B' || jwb == 'b'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********\n");
				system("pause");
				system("cls");
				main();
			}
			else{
				printf("\n*********Jawaban Salah*********\n");
				system("pause");
				system("cls");
				main();
			}
		}
			break;		
		case 8:{
			soal = fopen("soal 8_1.txt", "r");
			while (fgets(string, sizeof(string), soal) != NULL)
				printf("%s",string);
				fclose (soal);
			
				printf("\nJawab: "); 			
				scanf("%c", &jwb);
			if(jwb == 'A' || jwb == 'a'){		//JAWABAN 1
				printf("\n*********Jawaban Benar*********\n");
				system("pause");
				system("cls");
				main();
			}
			else{
				printf("\n*********Jawaban Salah*********\n");
				system("pause");
				system("cls");
				main();
			}
			}
			break;												
		}
}

void usertemp(){
	i=0;
	user_file = fopen("User Premium.dat", "rb");
	while (fread(&user,sizeof (user),1, user_file)==1){
			strcpy(temp[i].id, user.id); strcpy(temp[i].name, user.name); strcpy(temp[i].pass, user.pass);
			i++;
	}
	fclose(user_file);
}

void betatemp(){
	i=0;
	user_file = fopen("User Beta.dat", "rb");
	while (fread(&beta, sizeof (beta),1, user_file)==1){
			strcpy(temp[i].id, beta.id); strcpy(temp[i].name, beta.name); strcpy(temp[i].pass, beta.pass);
			i++;
	}
	fclose(user_file);
}

void sort(int i, int j){
	for (i=0;i<l+1;i++){
        for (j=0;j<=l+1-j;j++)
  		{
        	if (strcmp(temp[j].name, temp[j+1].name) > 0){
                temp2=temp[j];
    			temp[j]=temp[j+1];
    			temp[j+1]=temp2;
            }
  		}
    }
}
void sortuser(){
	fflush(stdin);
	FILE *user_file2;
	int m, n;	
	usertemp();
	l = i - 1;
	sort(m, n);
	user_file = fopen("User Premium.dat", "rb");
	user_file2 = fopen("User Premium2.dat", "wb");
	for(i = 0 ; i <= l ; i++){
		strcpy(user.id, temp[i].id);			
		strcpy(user.pass, temp[i].pass);
		strcpy(user.name, temp[i].name);
		fwrite(&user, sizeof(user), 1, user_file2); 
	}
	
	fclose(user_file);
	fclose(user_file2);
	remove("User Premium.dat");
	rename("User Premium2.dat","User Premium.dat");
}

void sortbeta(){
	fflush(stdin);
	FILE *user_file2;
	int m, n;	
	betatemp();
	l = i - 1;
	sort(m, n);
	user_file = fopen("User Beta.dat", "rb");
	user_file2 = fopen("User Beta2.dat", "wb");
	for(i = 0 ; i <= l ; i++){
		strcpy(beta.id, temp[i].id);			
		strcpy(beta.pass, temp[i].pass);
		strcpy(beta.name, temp[i].name);
		fwrite(&beta, sizeof(beta), 1, user_file2); 
	}
	
	fclose(user_file);
	fclose(user_file2);
	remove("User Beta.dat");
	rename("User Beta2.dat","User Beta.dat");
}
