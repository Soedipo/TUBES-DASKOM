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
