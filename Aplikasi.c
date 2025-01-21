#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

// Struktur untuk barang
typedef struct {
    int id;
    char nama[50];
    int stok;
} Barang;

// Deklarasi array barang dan jumlah barang
Barang daftarBarang[MAX_ITEMS];
int jumlahBarang = 0;

// Fungsi untuk menambah barang baru
void tambahBarang() {
    if (jumlahBarang >= MAX_ITEMS) {
        printf("\nTidak dapat menambah barang baru, kapasitas penuh.\n");
        return;
    }

    Barang baru;
    printf("\nMasukkan ID Barang: ");
    scanf("%d", &baru.id);
    getchar(); // Menghilangkan newline di buffer
    printf("Masukkan Nama Barang: ");
    fgets(baru.nama, sizeof(baru.nama), stdin);
    baru.nama[strcspn(baru.nama, "\n")] = 0; // Menghapus newline
    printf("Masukkan Jumlah Stok: ");
    scanf("%d", &baru.stok);

    daftarBarang[jumlahBarang++] = baru;
    printf("\nBarang berhasil ditambahkan.\n");
}

// Fungsi untuk mencetak daftar barang
void cetakBarang() {
    printf("\nDaftar Stok Barang:\n");
    printf("===============================\n");
    printf("ID\tNama\t\tStok\n");
    printf("-------------------------------\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("%d\t%s\t\t%d\n", daftarBarang[i].id, daftarBarang[i].nama, daftarBarang[i].stok);
    }
    printf("===============================\n");
}

// Fungsi untuk mengurangi stok barang
void kurangiStok() {
    int id, jumlah;
    printf("\nMasukkan ID Barang yang akan dikurangi: ");
    scanf("%d", &id);
    printf("Masukkan jumlah pengurangan stok: ");
    scanf("%d", &jumlah);

    for (int i = 0; i < jumlahBarang; i++) {
        if (daftarBarang[i].id == id) {
            if (daftarBarang[i].stok >= jumlah) {
                daftarBarang[i].stok -= jumlah;
                printf("\nStok berhasil dikurangi.\n");
            } else {
                printf("\nStok tidak mencukupi untuk dikurangi.\n");
            }
            return;
        }
    }
    printf("\nBarang dengan ID %d tidak ditemukan.\n", id);
}

// Fungsi untuk menampilkan laporan barang
void laporanBarang() {
    printf("\nLaporan Barang:\n");
    printf("===============================\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("ID: %d\nNama: %s\nStok: %d\n\n", daftarBarang[i].id, daftarBarang[i].nama, daftarBarang[i].stok);
    }
    printf("===============================\n");
}

// Fungsi utama
int main() {
    int pilihan;

    do {
        printf("\nAplikasi Pengelola Stok Barang\n");
        printf("===============================\n");
        printf("1. Tambah Barang Baru\n");
        printf("2. Cetak Daftar Barang\n");
        printf("3. Kurangi Stok Barang\n");
        printf("4. Tampilkan Laporan Barang\n");
        printf("5. Keluar\n");
        printf("===============================\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahBarang();
                break;
            case 2:
                cetakBarang();
                break;
            case 3:
                kurangiStok();
                break;
            case 4:
                laporanBarang();
                break;
            case 5:
                printf("\nTerima kasih telah menggunakan aplikasi ini.\n");
                break;
            default:
                printf("\nPilihan tidak valid, silakan coba lagi.\n");
        }
    } while (pilihan != 5);

    return 0;
}
