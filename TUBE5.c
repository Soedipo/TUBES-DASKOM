#include <stdio.h>
struct{
	char mhs[50], kelas[20];
	int nim;
}a;
FILE *list;
int i, n;
void output(FILE *x);
void input(FILE *x);
int main()
{
	printf("===PENDATAAN MAHASISWA===\n");
	input (list);
	system ("cls");
	output (list);
	return 0;
}


void output(FILE *x){
int i = 1;
	x = fopen("Daftar Mahasiswa.dat", "rb"); 
	while (fread (&a, sizeof(a), 1, x) == 1){
		printf ("%d. Nama Mahasiswa\t: %s\n", i, a.mhs); 
		printf ("   NIM\t\t\t: %d\n", a.mhs);
		printf ("   Kelas\t\t: %s\n", a.kelas);
		printf ("\n");
		i++;
		}
	fclose(x); 
}


void input(FILE *x){
	x = fopen("Daftar Mahasiswa.dat","wb"); 
	printf("Banyak Mahasiswa : "); scanf("%d",&n); getchar();
	for(i = 1 ; i <= n ; i++){
		printf("%d. Nama Mahasiswa\t: ",i); gets(a.mhs);
		printf("   NIM\t\t\t: "); scanf("%d",&a.nim);
		getchar();
		printf("   Kelas\t\t: "); gets(a.kelas);
		fwrite(&a, sizeof(a), 1, x); 
		printf("\n");
	}
	fclose(x); 
}
