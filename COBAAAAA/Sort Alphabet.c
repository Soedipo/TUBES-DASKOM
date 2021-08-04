#include<stdio.h>
#include<string.h>
struct data
{
char nama[50], kls[20], nim[20], jur[20], TEMP[99], TEMP2[99];
}a[100], temp; int i, j, n;

int main()
{
printf("Banyak mahasiswa : ");
scanf("%d",&n);
 for (i=0;i<=n-1;i++)
 {
 getchar();
 printf("Mahasiswa ke-%d \n",i+1);
 printf("Nama : ");   gets(a[i].nama);
 printf("NIM :");   gets (a[i].nim);
 printf ("Kelas :"); gets (a[i].kls);
 printf ("Jurusan :"); gets (a[i].jur);
 }
 
    for (i=0;i<n-1;i++){
        for (j=0;j<=n-1-j;j++)
  		{
        	if (strcmp(a[j].nama, a[j+1].nama) > 0){
                temp=a[j];
    			a[j]=a[j+1];
    			a[j+1]=temp;
            }
  		}
    }
    
   for(i=0;i<=n-1;i++)
    {
        printf("Mahasiswa %d \n", i+1);
        printf("Nama\t: %s \n",a[i].nama);
        printf("Nim\t: %s \n",a[i].nim);
        printf("Kelas\t: %s \n",a[i].kls);
        printf("Jurusan\t: %.2f \n",a[i].jur);
        printf("\n");
    }
}
