void Appending(FILE *x){
	x = fopen("List Buku.dat", "ab"); 
	printf("Banyak buku yang ditambahkan: "); scanf("%d", &n); getchar();
	for(i = 1 ; i <= n ; i++){
		printf("%d. Judul buku\t: ", i); gets(a.judul);
		printf("   Harga buku\t: "); scanf("%d", &a.harga);
		getchar();
		fwrite(&a, sizeof(a), 1, x); 
	}
	fclose(x);
}
