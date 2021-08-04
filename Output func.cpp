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

