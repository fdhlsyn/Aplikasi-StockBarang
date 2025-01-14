#include <stdio.h>
#include <string.h> 
 #define MAX_BARANG 100
 typedef struct {
    char nama[50];
    int jumlah;
 }Barang;

 Barang daftarBarang[MAX_BARANG];
 int totalBarang = 0;
 void tambahBarang(){
    if (totalBarang >= MAX_BARANG);
        printf("Kapasitas Penyimpanan Penuh!\n");
        return;
 }
 