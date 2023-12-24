/* PROGRAM REKENING AIR

DEFINE:
        DENDA_TELAT_PEMBAYARAN 5000
        DENDA_100M3 2000
        BPM 2000
        BIAYA_ADMINISTRASI 5000
        MAX_GOLONGAN 12

DEKLARASI: 
        tanggal_input[20]                       : char
        tanggal_pembayaran[20]                  : char
        golongan[5]                             : char
        pemakaian_bulan_lalu                    : int
        pemakaian_bulan_ini                     : int
        tarif                                   : int
        denda_telat_pembayaran                  : int
        denda_100m3                             : int
        total_denda                             : int
        total_tagihan                           : int
        golonganArray[MAX_GOLONGAN][5]          : char

        tarifRumahTangga[][3]                   : int
        tarifRumahTanggaTanpa[][3]              : int
        tarifNiaga[][3]                         : int
        tarifNiagaSedang[][3]                   : int
        tarifNiagaBesar[][3]                    : int

ALGORITMA :
            FUNCTION hitungTarif(pemakaian, tarifArray)
                DECLARE index
                FOR index = 0 TO 2
                    DECLARE batasAtas = (index + 1) * 10
                    IF pemakaian <= batasAtas
                        RETURN tarifArray[0][index]
                    ENDIF
                ENDFOR
                RETURN 0
            END FUNCTION

            FUNCTION hitungDenda(tanggalPembayaran, pemakaian)
                DECLARE dayOfMonth
                PARSE dayOfMonth FROM tanggalPembayaran USING "%*[^-]-%*[^-]-%d"
                
                DECLARE kondisi[2] = {dayOfMonth > 15, pemakaian > 100}
                DECLARE denda[2] = {0, 0}
                DECLARE nilaiDenda[2] = {DENDA_TELAT_PEMBAYARAN, DENDA_100M3}

                FOR i = 0 TO 1
                    IF kondisi[i]
                        denda[i] = nilaiDenda[i]
                    ELSE
                        denda[i] = 0
                    ENDIF
                ENDFOR
            END FUNCTION

            FUNCTION hitungTotalTagihan(jenisPelanggan, golonganIndex, pemakaian_bulan_ini)
            DECLARE tarifPerM3 = 0

            SWITCH jenisPelanggan
                CASE 1
                    tarifPerM3 = hitungTarif(pemakaian_bulan_ini, tarifRumahTangga)
                CASE 2
                    tarifPerM3 = hitungTarif(pemakaian_bulan_ini, tarifRumahTanggaTanpa)
                CASE 3
                    tarifPerM3 = hitungTarif(pemakaian_bulan_ini, tarifNiaga)
                CASE 4
                    tarifPerM3 = hitungTarif(pemakaian_bulan_ini, tarifNiagaSedang)
                CASE 5
                    tarifPerM3 = hitungTarif(pemakaian_bulan_ini, tarifNiagaBesar)
                DEFAULT
                    PRINT "Masukkan Pilihan yang Valid (1-5)"
            END SWITCH

            PROCEDURE main()
                DECLARE jenisPelanggan, golonganIndex, total_denda = 0

                    SWITCH jenisPelanggan
                        CASE 1
                        INPUT golonganIndex
                        FOR (;;)
                            IF golonganIndex >= 1 AND golonganIndex <= 8
                                golongan = golonganArray[golonganIndex - 1]
                                BREAK 
                            ELSE
                                PRINT "Pilihan tidak valid. Harap masukkan nomor golongan yang valid (1-8)."
                            ENDIF
                        END FOR

                        CASE 2
                        INPUT golonganIndex
                        FOR (;;)
                            IF golonganIndex >= 1 AND golonganIndex <= MAX_GOLONGAN
                                golongan = golonganArray[golonganIndex - 1]
                                BREAK 
                            ELSE
                                PRINT "Pilihan tidak valid. Harap masukkan nomor golongan yang valid (1-12)."
                            ENDIF
                        END FOR

                        CASE 3:
                        INPUT golonganIndex
                        FOR (;;)
                            IF golonganIndex >= 1 AND golonganIndex <= 4
                                golongan = golonganArray[golonganIndex - 1]
                                BREAK 
                            ELSE
                                PRINT "Pilihan tidak valid. Harap masukkan nomor golongan yang valid (1-4)."
                            ENDIF
                        END FOR

                        CASE 4:
                        INPUT golonganIndex
                        FOR (;;)
                            IF golonganIndex >= 1 AND golonganIndex <= 4
                                golongan = golonganArray[golonganIndex - 1]
                                BREAK 
                            ELSE
                                PRINT "Pilihan tidak valid. Harap masukkan nomor golongan yang valid (1-4): "
                            ENDIF
                        END FOR

                        CASE 5:
                        INPUT golonganIndex
                        FOR (;;)
                            IF golonganIndex >= 1 AND golonganIndex <= 4
                                golongan = golonganArray[golonganIndex - 1]
                                BREAK 
                            ELSE
                                PRINT "Pilihan tidak valid. Harap masukkan nomor golongan yang valid (1-4)."
                            ENDIF
                        END FOR

                            DEFAULT
                            PRINT "Pilihan jenis pelanggan tidak valid. Masukkan hanya kelompok yang valid (1-5)."
                            INPUT jenisPelanggan
                    END SWITCH

            INPUT pemakaian_bulan_lalu
            INPUT pemakaian_bulan_ini

            pemakaian_bulan_ini -= pemakaian_bulan_lalu
            hitungDenda(tanggal_pembayaran, pemakaian_bulan_ini)
            hitungTotalTagihan(jenisPelanggan, golonganIndex, pemakaian_bulan_ini)
            tampilkanData()

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DENDA_TELAT_PEMBAYARAN 5000
#define DENDA_100M3 2000
#define BPM 2000
#define BIAYA_ADMINISTRASI 5000

#define MAX_GOLONGAN 12

char tanggal_input[20];
char tanggal_pembayaran[20];
char golongan[5];
int pemakaian_bulan_lalu;
int pemakaian_bulan_ini;
int tarif;
int denda_telat_pembayaran;
int denda_100m3;
int total_denda;
int total_tagihan;

char golonganArray[MAX_GOLONGAN][5];

int tarifRumahTangga[][3] = {
    {1780, 2060, 5880}, //D1-1
    {2340, 2340, 5940}, //D1-2
    {2060, 2340, 5940}, //D2-1
    {2620, 2900, 6060}, //D2-2
    {2900, 3180, 6120}, //D3-1
    {3180, 3460, 6180}, //D3-2
    {3460, 3740, 6240}, //D4-1
    {3740, 4020, 6300} //D4-2
};

int tarifRumahTanggaTanpa[][3] = {
    {6340, 9200, 9600}, //D1-3
    {6420, 9350, 9650}, //D1-4
    {6490, 9500, 9800}, //D2-3
    {6570, 9650, 9950}, //D2-4,
    {6640, 9800, 10100}, //D3-3
    {6720, 9950, 10250}, //D3-4
    {6790, 10100, 10400}, //D4-3
    {6870, 10250, 10550}, //D4-4
    {6940, 10400, 10700}, //D5-1
    {7020, 10550, 10850}, //D5-2
    {7090, 10700, 11000}, //D5-3
    {7170, 10850, 11150} //D5-4
};

int tarifNiaga[][3] = {
    {9200, 9850, 10950}, //E1-1
    {9500, 10150, 11250}, //E1-2
    {9800, 10450, 11550}, //E1-3
    {10100, 10750, 11850} //E1-4
};

int tarifNiagaSedang[][3] = {
    {10400, 11050, 12150}, //E2-1
    {10700, 11350, 12550}, //E2-2
    {11000, 11650, 13150}, //E2-3
    {11300, 11950, 13950} //E2-4
};

int tarifNiagaBesar[][3] = {
    {11600, 12250, 14750}, //E3-1
    {11900, 12550, 15050}, //E3-2
    {12200, 12850, 15850}, //E3-3
    {12500, 13150, 16650} //E3-4
};

int hitungTarif(int pemakaian, int tarifArray[][3]) {
    int index;

    for (index = 0; index < 3; ++index) {
        int batasAtas = (index + 1) * 10;

        if (pemakaian <= batasAtas) {
            return tarifArray[0][index];
        }
    }

    return 0;
}


void hitungDenda(char *tanggalPembayaran, int pemakaian) {
    int dayOfMonth;
    sscanf(tanggalPembayaran, "%*[^-]-%*[^-]-%d", &dayOfMonth);

    int kondisi[2] = {dayOfMonth > 15, pemakaian > 100};
    int *denda[2] = {&denda_telat_pembayaran, &denda_100m3};
    int nilaiDenda[2] = {DENDA_TELAT_PEMBAYARAN, DENDA_100M3};

    for (int i = 0; i < 2; i++) {
        *denda[i] = (kondisi[i]) ? nilaiDenda[i] : 0;
    }

    int total_denda = 0;
    for (int i = 0; i < 2; i++) {
        total_denda += *denda[i];
    }
}


void hitungTotalTagihan(int jenisPelanggan, int golonganIndex, int pemakaian_bulan_ini) {
    int tarifPerM3 = 0;


    switch (jenisPelanggan) {
        case 1:
            tarifPerM3 = hitungTarif(pemakaian_bulan_ini, tarifRumahTangga);
            break;
        case 2:
            tarifPerM3 = hitungTarif(pemakaian_bulan_ini, tarifRumahTanggaTanpa);
            break;
        case 3:
            tarifPerM3 = hitungTarif(pemakaian_bulan_ini, tarifNiaga);
            break;
        case 4:
            tarifPerM3 = hitungTarif(pemakaian_bulan_ini, tarifNiagaSedang);
            break;
        case 5:
            tarifPerM3 = hitungTarif(pemakaian_bulan_ini, tarifNiagaBesar);
            break;
        default:
            printf("Masukkan Pilihan yang Valid (1-5)\n");
            break;
    }

    tarif = pemakaian_bulan_ini * tarifPerM3;
    total_tagihan = tarif + total_denda + BPM + BIAYA_ADMINISTRASI;
}




void tampilkanData() {
    FILE *fp;
    fp = fopen("Rekening04.txt", "w+");

    fprintf(fp, "||========================================================================||\n");
    fprintf(fp, "||                                                                        ||\n");
	fprintf(fp, "||                             PROGRAM REKENING AIR                       ||\n");
	fprintf(fp, "||                                                                        ||\n");
	fprintf(fp, "||========================================================================||\n\n\n");

    fprintf(fp, "   =========================== Data Rekening Air ===========================\n");
    fprintf(fp, "                Tanggal Input Data: %s\n", tanggal_input);
    fprintf(fp, "                Tanggal Pembayaran: %s\n", tanggal_pembayaran);
    fprintf(fp, "                Golongan Pelanggan: %s\n", golongan);
    fprintf(fp, "                Pemakaian Bulan Lalu: %d m3\n", pemakaian_bulan_lalu);
    fprintf(fp, "                Pemakaian Bulan Ini: %d m3\n", pemakaian_bulan_ini);
    fprintf(fp, "                Tarif: Rp %d\n", tarif);
    fprintf(fp, "                Denda Telat Pembayaran: Rp %d\n", denda_telat_pembayaran);
    fprintf(fp, "                Denda >100m3: Rp %d\n", denda_100m3);
    fprintf(fp, "                Biaya Pemeliharaan Meter (BPM): Rp %d\n", BPM);
    fprintf(fp, "                Biaya Administrasi: Rp %d\n", BIAYA_ADMINISTRASI);
    fprintf(fp, "                Total Denda: Rp %d\n", total_denda);
    fprintf(fp, "                Total Tagihan: Rp %d\n", total_tagihan);
    fprintf(fp, "  ==========================================================================\n\n\n");

    fprintf(fp, "||===========================================================================||\n");
    fprintf(fp, "||                 Terimakasih Sudah Menggunakan Program Ini                 ||\n");
    fprintf(fp, "||                        Sampai Jumpa dilain Waktu                          ||\n");
    fprintf(fp, "||===========================================================================||\n");

    fclose(fp);
}

int main() {
    int jenisPelanggan;
    int golonganIndex;
    int total_denda = 0;  

    printf("||=====================================================================||\n");
	printf("||                           PROGRAM REKENING AIR                      ||\n");
	printf("||                                                                     ||\n");
	printf("||=====================================================================||\n");
	printf("||                    Tekan Enter Untuk Melanjutkan!                   ||\n");
	printf("||=====================================================================||\n");
    getchar();
    system("cls");

    printf("||=====================================================================||\n");
    printf("||          Masukkan Tanggal Input dan Tanggal Pembayaran              ||\n");
    printf("||=====================================================================||\n");

    printf("                                                        _______________\n");
    printf("_______________Masukkan Tanggal Input Data (YYYY-MM-DD):");
    scanf("%s", tanggal_input);
    printf("                                                        ________________\n");
    printf("_______________Masukkan Tanggal Pembayaran (YYYY-MM-DD):");
    scanf("%s", tanggal_pembayaran);
    system("cls");

    printf("     ======================================================================\n");
    printf("   ||                           Menu Jenis Pelanggan                       ||\n");
    printf("   || ==================================================================== ||\n");
    printf("   ||                       1. Rumah Tangga Bersubsidi                     ||\n");
    printf("   ||                       2. Rumah Tangga Tanpa Subsidi                  ||\n");
    printf("   ||                       3. Niaga Kecil                                 ||\n");
    printf("   ||                       4. Niaga Sedang                                ||\n");
    printf("   ||                       5. Niaga Besar                                 ||\n");
    printf("    =======================================================================\n");
    printf("                                                   ________________________\n");
    printf("    _____________________Pilih jenis pelanggan (1-3): ");
    scanf("%d", &jenisPelanggan);
    system("cls");

    switch (jenisPelanggan) {
        case 1:
            printf("  ===============================================================\n");
            printf(" ||       Menu Golongan Rumah Tangga (Non Niaga Bersubsidi)       ||\n");
            printf(" || ============================================================ ||\n");
            printf(" ||                     1. D1-1 (450VA)                          ||\n");
            printf(" ||                     2. D1-2 (900VA)                          ||\n");
            printf(" ||                     3. D2-1 (450VA)                          ||\n");
            printf(" ||                     4. D2-2 (900VA)                          ||\n");
            printf(" ||                     5. D3-1 (450VA)                          ||\n");
            printf(" ||                     6. D3-2 (900VA)                          ||\n");
            printf(" ||                     7. D4-1 (450VA)                          ||\n");
            printf(" ||                     8. D4-2 (900VA)                          ||\n");
            printf("  ===============================================================\n");
            printf("                                               ___________________\n");
            printf("________________Pilih golongan pelanggan (1-8): ");
            scanf("%d", &golonganIndex);
            system("cls");

            for (;;) {
                if (golonganIndex >= 1 && golonganIndex <= 8) {
                    strcpy(golongan, golonganArray[golonganIndex - 1]);
                    break; 
                } else {
                    printf("Pilihan tidak valid. Harap masukkan nomor golongan yang valid (1-8).\n");
                }
            }
        break;

        case 2:
        
            printf("  ==========================================================================\n");
            printf("||          Menu Golongan Rumah Tangga ( Non Niaga Tanpa Subsidi)           ||\n");
            printf("|| ======================================================================== ||\n");
            printf("||                          1. D1-3 (1300VA)                                ||\n");
            printf("||                          2. D1-4 (>1300VA)                               ||\n");
            printf("||                          3. D2-3 (1300VA)                                ||\n");
            printf("||                          4. D2-4 (>1300VA)                               ||\n");
            printf("||                          5. D3-3 (1300VA)                                ||\n");
            printf("||                          6. D3-4 (>1300VA)                               ||\n");
            printf("||                          7. D4-3 (1300VA)                                ||\n");
            printf("||                          8. D4-4 (>1300VA)                               ||\n");
            printf("||                          9. D5-1 (450VA)                                 ||\n");
            printf("||                          10. D5-2 (900VA)                                ||\n");
            printf("||                          11. D5-3 (1300VA)                               ||\n");
            printf("||                          12. D5-4 (>1300VA)                              ||\n");
            printf("  =========================================================================\n");
            printf("                                                    _______________________\n");
            printf("____________________Pilih golongan pelanggan (1-12): ");
            scanf("%d", &golonganIndex);
            system("cls");

            for (;;) {
                if (golonganIndex >= 1 && golonganIndex <= MAX_GOLONGAN) {
                    strcpy(golongan, golonganArray[golonganIndex - 1]);
                    break; 
                } else {
                    printf("Pilihan tidak valid. Harap masukkan nomor golongan yang valid (1-12).\n");
                }
            }
        break;

        case 3:
            if (jenisPelanggan == 3) {
                printf(" ====================================================================\n");
                printf("||                   Menu Golongan Niaga Kecil                       ||\n");
                printf("|| ================================================================= ||\n");
                printf("||                       1. E1-1 (450VA)                             ||\n");
                printf("||                       2. E1-2 (900VA)                             ||\n");
                printf("||                       3. E1-3 (1300VA)                            ||\n");
                printf("||                       4. E1-4 (>1300VA)                           ||\n");
                printf(" ====================================================================\n");
                printf("                                                  ____________________\n");
                printf("___________________Pilih golongan pelanggan (1-4): ");
                scanf("%d", &golonganIndex);
                system("cls");

                for (;;) {
                    if (golonganIndex >= 1 && golonganIndex <= 4) {
                        strcpy(golongan, golonganArray[golonganIndex - 1]);
                        break; 
                    } else {
                        printf("Pilihan tidak valid. Harap masukkan nomor golongan yang valid (1-4).\n");
                    }
                }
            }
        break;

        case 4:
            if (jenisPelanggan >= 1 && jenisPelanggan <= 4) {
                printf("  ====================================================================\n");
                printf("||                      Menu Golongan Niaga Sedang                    ||\n");
                printf("|| ================================================================== ||\n");
                printf("||                          1. E2-1 (450VA)                           ||\n");
                printf("||                          2. E2-2 (900VA)                           ||\n");
                printf("||                          3. E2-3 (1300VA)                          ||\n");
                printf("||                          4. E2-4 (>1300VA)                         ||\n");
                printf(" ===================================================================== \n");
                printf("                                                   ____________________\n");
                printf("____________________Pilih golongan pelanggan (1-4): ");
                scanf("%d", &golonganIndex);
                system("cls");
                
                for (;;) {
                    if (golonganIndex >= 1 && golonganIndex <= 4) {
                        strcpy(golongan, golonganArray[golonganIndex - 1]);
                        break; 
                    } else {
                        printf("Pilihan tidak valid. Harap masukkan nomor golongan yang valid (1-4): ");
                    }
                }

                system("cls");
            }
        break;
    

        case 5:
            printf("  ====================================================================\n");
            printf("||                   Menu Golongan Niaga Besar                        ||\n");
            printf("|| ================================================================== ||\n");
            printf("||                          1. E3-1 (450VA)                           ||\n");
            printf("||                          2. E3-2 (900VA)                           ||\n");
            printf("||                          3. E3-3 (1300VA)                          ||\n");
            printf("||                          4. E3-4 (>1300VA)                         ||\n");
            printf("  ====================================================================\n");
            printf("                                                 ______________________\n");
            printf("__________________Pilih golongan pelanggan (1-4): ");
            scanf("%d", &golonganIndex);
            system("cls");

            for (;;) {
                if (golonganIndex >= 1 && golonganIndex <= 4) {
                    strcpy(golongan, golonganArray[golonganIndex - 1]);
                    break; 
                } else {
                    printf("Pilihan tidak valid. Harap masukkan nomor golongan yang valid (1-4).\n");
                }
            }
        break;

        default:
            printf("Pilihan jenis pelanggan tidak valid. Masukkan hanya kelompok yang valid (1-5).\n");
            scanf("%d", &jenisPelanggan);
        break;
    }

    printf("||=====================================================================||\n");
    printf("||             Masukkan Meteran Bulan Lalu dan Bulan Ini               ||\n");
    printf("||=====================================================================||\n");

    printf("                                                 ______________________\n");
    printf("____________________Masukkan Meteran Bulan Lalu: ");
    scanf("%d", &pemakaian_bulan_lalu);

    printf("                                                ______________________\n");
    printf("____________________Masukkan Meteran Bulan Ini: ");
    scanf("%d", &pemakaian_bulan_ini);
    system("cls");

    pemakaian_bulan_ini -= pemakaian_bulan_lalu;
    hitungDenda(tanggal_pembayaran, pemakaian_bulan_ini);
    hitungTotalTagihan(jenisPelanggan, golonganIndex, pemakaian_bulan_ini);
    tampilkanData();

    return 0;
}
