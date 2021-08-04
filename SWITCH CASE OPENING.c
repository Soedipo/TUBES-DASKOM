#include <stdio.h>
int main()
{
    int menu;
    float a, b, hasil;
    printf("\n");
    printf("Selamat Datang di Ruang Daskom\n");
    printf("\n\n");
    printf("\tAkun :\n");
    printf("\t1. Admin\n");
    printf("\t2. Premium\n");
    printf("\t3. Beta User\n");
    printf("Pilih akun : ");
    scanf("%d",&menu);
    printf("\n");
    switch (menu){
      case 1:
      	printf ("Choose: \n\n");
        printf("Login       ||     Register");
        printf("\nLogin: \n");
		printf("\tUsername :\n");
        printf("\tPassword :");
        printf("\nMenu: ");
        printf("\n\t1. Tambah Modul: ");
        printf("\n\t2. Hapus akun");
        printf("\nPilih Menu: 2");
        printf("\nMasukkan nama yang akan dihapus: Dono");
        printf("\n\n Penghapusan Berhasil!!!");
        break;
    case 2:
        printf("\nPengurangan :\n");
        printf("Masukan angka pertama : ");
        scanf("%f", &a);
        printf("Masukan angka kedua   : ");
        scanf("%f", &b);
        hasil = a - b;
        printf("\n");
        printf("Hasil dari %.2f - %.2f = %.2f\n", a, b, hasil);
        break;
    case 3:
        printf("\nPerkalian :\n");
        printf("Masukkan angka pertama : ");
        scanf("%f", &a);
        printf("Masukkan angka kedua   : ");
        scanf("%f", &b);
        hasil = a * b;
        printf("\n");
        printf("Hasil dari %.2f x %.2f = %.2f\n", a, b, hasil);
        break;
    case 4:
        printf("\nPembagian :\n");
        printf("Masukkan angka pertama : ");
        scanf("%f", &a);
        printf("Masukkan angka kedua   : ");
        scanf("%f", &b);
        hasil = a / b;
        printf("\n");
        printf("Hasil dari %.2f / %.2f = %.2f\n", a, b, hasil);
        break;
      default:
        printf("Anda salah memilih menu.");
        break;
    }
    return 0;
}
