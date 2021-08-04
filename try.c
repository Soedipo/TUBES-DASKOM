#include <stdio.h>
struct{
	char mhs[50], kelas[20];
	int nim;
}a;
FILE *list;
int i, n;
int main()
{

int i = 1;
	list = fopen("Daftar Mahasiswa.dat", "rb"); 
	while (fread (&a, sizeof(a), 1, list) == 1){
		printf ("%d. Nama Mahasiswa\t: %s\n", i, a.mhs); 
		printf ("   NIM\t\t\t: %d\n", a.mhs);
		printf ("   Kelas\t\t: %s\n", a.kelas);
		printf ("\n");
		i++;
		}
	fclose(list); 

}
