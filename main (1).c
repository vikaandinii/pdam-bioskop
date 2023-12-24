#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define hpopcorn    25
#define hmamigor    30
#define hhotdog     35
#define hcola       15
#define havocado    20


//variabel global untuk fungsi pemesanan
float jam1[6]= {0,12.00, 14.20, 16.40, 19.00, 23.40};
float jam2[6]= {0,12.40, 14.40, 15.50, 17.50, 19.00};
int hari, film, jamtayang, tiket, h, i, angka_kursi[50];
int kursi_terpilih[10][20] = {0};
float harga_tiket, total_harga, total_harga1, harga_makanan;
char daerah[3][30]={"Level 21", "Living World", "Transtudio"};
char Zona[2][30]={"Denpasar", "Badung"};
char teater[3][30] = {"TEATER PHOENIX", "CINEMA ELECTRIC", "RIVERSIDE STUDIOS"};
char judul [5][50]= {"Error", "Sweet Home", "Hellbound", "Night Has Come", "All Of Us Are Dead"};
char seat[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
char huruf_kursi, cetak, pesan;


void main();
void menu_customer();
void regis_customer();
void login_customer();
void admin_panel();
void login_adm();
void mainpage();
void close();
void header_data_pesanan();
void data_pesanan();
void menu_aplikasi();
void pemesanan();
void data_customer();
void riwayat_transaksi();
void selesai();
float makanan();



void close(){
    fflush(stdin);
    printf("\n\tTekan Enter untuk Melanjutkan...");
    getchar();
    system("cls");
}

struct customer{
	char nama_cust[50];
	int pin_cust;
};

struct customer registrasi;
struct customer login;

void main(){
    system("color 0B");
    mainpage();

}

//menu awal program
void mainpage(){
    printf("\n\t==========================================================");
    printf("\n\t|                                                        |");
    printf("\n\t|  |-------------------------------------|------------|  |");
    printf("\n\t|  | Bunga Alyssa                        | 2305551002 |  |");
    printf("\n\t|  |-------------------------------------|------------|  |");
    printf("\n\t|  | Ni Luh Made Tika Kurniasari         | 2305551034 |  |");
    printf("\n\t|  |-------------------------------------|------------|  |");
    printf("\n\t|  | Ni Nyoman Vika Andini               | 2305551125 |  |");
    printf("\n\t|  |-------------------------------------|------------|  |");
    printf("\n\t|                                                        |");
    printf("\n\t==========================================================\n");
    system("pause");
    system("cls");
    int pilih=0;
	while (pilih!=4)
	{

	printf("\n\t==============================================================");
    printf("\n\t||                            X X I                         ||");
    printf("\n\t||----------------------------------------------------------||");
    printf("\n\t||                    BOOKING TIKET BIOSKOP                 ||");
    printf("\n\t||==========================================================||");
    printf("\n\t||  [1] Masuk sebagai admin                                 ||");
    printf("\n\t||----------------------------------------------------------||");
    printf("\n\t||  [2] Masuk sebagai customer                              ||");
    printf("\n\t||----------------------------------------------------------||");
    printf("\n\t||  [3] Exit                                                ||");
    printf("\n\t==============================================================");
    printf("\n\t Masukkan pilihan Anda : ");
    scanf("%d", &pilih);
    system("cls");
    switch (pilih){
    	case 1:{
    		login_adm();
    		break;
	}
		case 2:{
			menu_customer();
			break;
		}
		case 3:{
			selesai();
			break;
		}
	default:{
	printf("menu tidak tersedia");
	break;
	}
}
}
}

//tampilan log in admin
void login_adm(){
	char username [15];
	char password [15];
	printf("\n=======PROGRAM PEMESANAN TIKET BIOSKOP=======\n");
	printf("\n                    X X I                    \n");
	printf("\n``````\n");
	printf("\nMasukkan username: ");
	scanf("%s", &username);
	printf("\nMasukkan password: ");
	fflush(stdin);
	scanf("%s", &password);
    if ((strcmp(username, "lovelove") == 0) && (strcmp(password, "123456") ==0)){ //untuk meng-set username dan password
        getchar();
        system ("cls");
        printf("\n\t============================================================\n");
        printf("\t  ||                                                          ||");
        printf("\n\t||                            X X I                         ||");
        printf("\n\t||                                                          ||");
        printf("\n\t============================================================\n");
        printf("\n\t`````````````````````````````````````````````````````````````");
        printf("\n\t||                      Selamat Datang                      ||");
        printf("\n\t============================================================\n");
        printf("\n\n\tTekan Enter untuk melanjutkan...");
        getchar();
        system ("cls");
        admin_panel();
        //validasi
	}else {
        printf("\n--------------------------------");
		printf("\nPassword atau Username Salah!\n");
        getchar();
        printf("\nTEKAN ENTER UNTUK KEMBALI");
        printf("\n-------------------------------");
        getchar();
        system ("cls");
        main();
	}
}

//tampilan menu admin
void admin_panel(){
	int choice;
	while (choice!=4){
	system("cls");
	printf("\n\t==============================================================");
    printf("\n\t||                            X X I                         ||");
    printf("\n\t||``````````````````````````````````````````````````````````||");
    printf("\n\t||                   Tampilan Menu Admin                    ||");
    printf("\n\t||==========================================================||");
    printf("\n\t||  [1] Menampilkan riwayat transaksi                       ||");
    printf("\n\t||----------------------------------------------------------||");
    printf("\n\t||  [2] Menampilkan data customer                           ||");
    printf("\n\t||----------------------------------------------------------||");
    printf("\n\t||  [3] Log out                                             ||");
    printf("\n\t==============================================================");
    printf("\n\tMasukkan pilihan Anda [1][2][3] : ");
    scanf("%d", &choice);
    switch(choice){
    	case 1:
    		{
    			riwayat_transaksi();
    			break;
			}
		case 2:
			{
				data_customer();
				break;
			}
			case 3:{
                mainpage();
                break;
			}
		default:
			{
				printf("Menu tidak tersedia!");
				break;
			}
	}


	}
}


void menu_customer(){//Menampilkan pilihan menu awal yang dapat dipilih customer untuk masuk ke program
    int menu;
    printf("\n\t==============================================================");
    printf("\n\t||                           X X I                          ||");
    printf("\n\t||----------------------------------------------------------||");
    printf("\n\t||                        SELAMAT DATANG                    ||");
    printf("\n\t||==========================================================||");
    printf("\n\t||  [1] Registrasi                                          ||");
    printf("\n\t||----------------------------------------------------------||");
    printf("\n\t||  [2] Login                                               ||");
    printf("\n\t||----------------------------------------------------------||");
    printf("\n\t||  [3] Exit                                                ||");
    printf("\n\t==============================================================");
    printf("\n\tMasukkan Pilihan Anda : ");
	while(scanf("%d", &menu)==0 || menu < 1 || menu > 3){
        printf("\t--------------------------------------------------------------");
        printf("\n\tAngka yang Anda inputkan salah!");
        printf("\n\tMohon inputkan pilihan yang benar...");
        printf("\n\t--------------------------------------------------------------");
        printf("\n\tMasukkan pilihan Anda: ");
        while((getchar())!='\n');
    }
	close();
    if (menu==1){
        regis_customer(); // menuju bagian registrasi (apabila customer belum terdaftar)
    }else if(menu==2){
        login_customer(); // menuju bagian login customer(apabila customer sudah pernah mendaftarkan PIN dan usernamenya)
    }else{
        mainpage(); //kembali ke menu awal
    }
}

void regis_customer(){
    int i;
    struct customer cust01;
	FILE *regis = fopen("DataCustomer.txt", "a+");

	printf("\n\t=========================::::::::::::::::=====================\n");
    printf("\n\t||                    -- MENU REGISTRASI --                 ||\n");
    printf("\n\t=========================::::::::::::::::=====================\n");
    printf("\n\tMasukkan username : ");
    scanf("%[^\n]", registrasi.nama_cust);
	fflush(stdin);

	//Mengecek data customer dalam file DataCustomer.txt
	while (!feof(regis)){
		//membaca data customer dalam file DataCustomer.txt
		fscanf(regis, "%[^#]#%d\n", &cust01.nama_cust, &cust01.pin_cust);
		fflush(stdin);

		//mengecek apakah username yang diinputkan sudah pernah terdaftar sebelumnya. Apabila sudah, customer akan diminta menginputkan username baru.
		if (strcmp(cust01.nama_cust, registrasi.nama_cust)==0){
            printf("\n\t -- username sudah terdaftar. Coba gunakan username lainnya -- ");
            printf("\n\t==============================================================\n");
            fclose(regis);
			close();
			regis_customer();
			break;
		}
	}
	//ketika username yang diinputkan belum pernah terdaftar, maka program akan lanjut meminta inputan PIN
    fflush(stdin);
    printf("\n\tMasukkan PIN : ");
	while(scanf("%d", &registrasi.pin_cust)==0 || registrasi.pin_cust < 0){
        printf("\t--------------------------------------------------------------");
        printf("\n\tAngka yang Anda inputkan salah!");
        printf("\n\tMohon inputkan angka yang benar...");
        printf("\n\t--------------------------------------------------------------");
        printf("\n\tMasukkan PIN : ");
        while((getchar())!='\n');
    }
    fprintf(regis, "%s#%d\n", registrasi.nama_cust, registrasi.pin_cust);
    fclose(regis);

    printf("\n\t\tRegistrasi dengan username %s berhasil!", registrasi.nama_cust);
    printf("\n\t --------------------------------------------------------------\n");
    close();
    login_customer(); //setelah registrasi berhasil, customer akan diminta untuk login
}

void login_customer(){
	int i;
	int kode;
	struct customer cust01;
	FILE *regis = fopen("DataCustomer.txt", "a+");

    printf("\n\t=========================::::::::::::::::=====================\n");
    printf("\n\t||                       -- MENU LOGIN --                   ||\n");
    printf("\n\t=========================::::::::::::::::=====================\n");
	printf("\n\tMasukkan PIN : ");
	while(scanf("%d", &kode)==0 || kode < 0){
        printf("\t--------------------------------------------------------------");
        printf("\n\tAngka yang Anda inputkan salah!");
        printf("\n\tMohon inputkan angka yang benar...");
        printf("\n\t--------------------------------------------------------------");
        printf("\n\tMasukkan PIN : ");
        while((getchar())!='\n');
    }

	// mengecek data customer dalam file DataCustomer.txt
	while (!feof(regis)){
		//membaca data customer dalam file DataCustomer.txt
		fscanf(regis, "%[^#]#%d\n", &cust01.nama_cust, &cust01.pin_cust);
		fflush(stdin);

		//mengecek apakah PIN yang diinputkan telah terdaftar
		if (cust01.pin_cust == kode){
			// jika PIN telah terdaftar maka  akan ditampilkan username customer
			printf("\n\t==============================================================");
			printf("\n\t\t\t\t LOGIN BERHASIL");
			printf("\n\t--------------------------------------------------------------");
			printf("\n\tHello, %s !", cust01.nama_cust);
			printf("\n\t==============================================================");
			strcpy(login.nama_cust, cust01.nama_cust);
			fclose(regis);
			close();
			menu_aplikasi();
			break;
		}
	}
	fclose(regis);
    //Jika PIN yang diinputkan belum terdaftar, program akan kembali ke fungsi menu_customer()
    printf("\n\t------------------- PIN tidak Terdaftar ---------------------");
    printf("\n\t Silahkan Periksa Ulang PIN atau Registrasi Terlebih Dahulu!");
    printf("\n\t==============================================================\n");
    close();
    menu_customer();
}


void menu_aplikasi(){
    int menu;
    printf("\n\t============================================================\n");
    printf("\n\t  -----------------------   X X I ------------------------- \n");
    printf("\n\t==============================================================");
    printf("\n\t||                 P I L I H A N  M E N U                   ||");
    printf("\n\t==============================================================");
    printf("\n\t||  [1] PEMESANAN TIKET                                     ||");
    printf("\n\t||----------------------------------------------------------||");
    printf("\n\t||  [2] LOGOUT                                              ||");
    printf("\n\t==============================================================\n");
    printf("\n\tMasukkan Pilihan Anda : ");
	while(scanf("%d", &menu)==0 || menu < 1 || menu > 2){
        printf("\t--------------------------------------------------------------");
        printf("\n\tAngka yang Anda inputkan salah!");
        printf("\n\tMohon inputkan pilihan yang benar...");
        printf("\n\t--------------------------------------------------------------");
        printf("\n\tMasukkan pilihan Anda: ");
        while((getchar())!='\n');
    }
	close();
    if (menu==1){
        header_data_pesanan();
        pemesanan();
    }else{
        mainpage();
    }

}

float makanan() {
    system("cls");


    printf("\n\t|======================================|");
    printf("\n\t|                 M-Food               |");
    printf("\n\t|======================================|");
    printf("\n\t|1. Popcorn Caramel                    |");
    printf("\n\t|2. Mamigor                            |");
    printf("\n\t|3. Hot Dog                            |");
    printf("\n\t|4. Iced Avocado                       |");
    printf("\n\t|5. Coca cola                          |");
    printf("\n\t|--------------------------------------|");
    printf("\n\tMasukkan Pilihan Anda : ");
    int pilihan;
    scanf("%d", &pilihan);
    float harga_makanan = 0;
    if (pilihan==1){
        harga_makanan = hpopcorn;
    }
    else if (pilihan==2){
        harga_makanan = hmamigor;
    }
    else if (pilihan==3){
        harga_makanan = hhotdog;
    }
    else if (pilihan==4){
        harga_makanan = havocado;
    }
    else if (pilihan==5){
        harga_makanan = hcola;
    }
    else {
        printf("\n Pilihan Tidak Valid!");
    }
    return harga_makanan;
}

void pemesanan(){
    struct tm *local;
    time_t now;
    now = time (NULL);
    local = localtime(&now);
    int pilih;
    // tampilan daftar film dan transaksi
    printf("\n\t|=======================================================================================|");
    printf("\n\t|                                PILIH DAERAH TUJUAN                                    |");
    printf("\n\t|=======================================================================================|");
    printf("\n\t|    1    | DENPASAR                                                                    |");
    printf("\n\t|    2    | BADUNG                                                                      |");
    printf("\n\t========================================================================================|");
    printf("\n\t Masukkan pilihan daerah anda: ");
    scanf("%d", &pilih);
    switch(pilih){
        case 1:
        printf("%s\n", Zona[0]);
        break;

        case 2:
        printf("%s\n", Zona[1]);
        break;

        default:
        printf("Masukkan Pilihan yang Valid");
        break;
    }
    system("cls");


    int pilihan_daerah;
    printf("\n\t|=======================================================================================|");
    printf("\n\t|                                PILIH LOKASI BIOSKOP                                   |");
    printf("\n\t|=======================================================================================|");
    printf("\n\t|    1    | LEVEL 21                                                                    |");
    printf("\n\t|    2    | LIVING WORLD                                                                |");
    printf("\n\t|    3    | TRANSTUDIO                                                                  |");
    printf("\n\t|=======================================================================================|");
    printf("\n\tMasukkan Pilihan Lokasi Bioskop Anda: ");
    scanf("%d", &pilihan_daerah);

if (pilihan_daerah == 1) {
    printf("%s\n", daerah[0]);
} else if (pilihan_daerah == 2) {
    printf("%s\n", daerah[1]);
} else if (pilihan_daerah == 3) {
    printf("%s\n", daerah[2]);
} else {
    printf("Pilihan tidak valid\n");
}

    system("cls");

    int pilihan_teater;
    printf("\n\t|=======================================================================================|");
    printf("\n\t|                                PILIH GEDUNG TEATHER                                   |");
    printf("\n\t|=======================================================================================|");
    printf("\n\t|    1    | TEATER PHOENIX                                                              |");
    printf("\n\t|    2    | CINEMA ELECTIRC                                                             |");
    printf("\n\t|    3    | RIVERSIDE STUDIOS                                                           |");
    printf("\n\t|=======================================================================================|");
    printf("\n\t Masukkan pilihan teather: ");
    scanf("%d", &pilihan_teater);
    if (pilihan_teater == 1) {
    printf("%s\n", teater[0]);
} else if (pilihan_teater == 2) {
    printf("%s\n", teater[1]);
} else if (pilihan_teater == 3) {
    printf("%s\n", teater[2]);
} else {
    printf("Pilihan tidak valid.\n");
}


    system("cls");

    printf("\t==========================================================================================\n");
    printf("\t                                          X X I                                           \n");
    printf("\t==========================================================================================\n");
    printf("\t|                                      DAFTAR FILM                                       |\n");
    printf("\t|----------------------------------------------------------------------------------------|\n");
    printf("\t| Studio  |              Film                   |           Jam Tayang Tersedia          |\n");
    printf("\t|----------------------------------------------------------------------------------------|\n");
    printf("\t|                                               |   1   |   2   |   3   |   4   |   5    |\n");
    printf("\t|----------------------------------------------------------------------------------------|\n");
    printf("\t|    1    | Sweet Home                          | 12.00 | 14.20 | 16.40 | 19.00 | 22.20  |\n");
    printf("\t|    2    | Hellbound                           | 12.40 | 14.40 | 15.50 | 17.50 | 19.00  |\n");
    printf("\t|    3    | Night Has Come                      | 12.40 | 14.40 | 15.50 | 17.50 | 19.00  |\n");
    printf("\t|    4    | All Of Us Are Dead                  | 12.00 | 14.20 | 16.40 | 19.00 | 21.20  |\n");
    printf("\t-----------------------------------------------------------------------------------------\n");
    printf("\tHARGA TIKET :\n\n\t [1] Senin-Jumat\t Rp. 50.000\n\t [2] Sabtu-Minggu\t Rp. 75.000\n");
    printf("\t-----------------------------------------------------------------------------------------\n");

    hari = local->tm_wday;
    if(hari==0){
        printf("\tSekarang hari Minggu");
    }else if(hari==1){
        printf("\tSekarang hari Senin");
    }else if(hari==2){
        printf("\tSekarang hari Selasa");
    }else if(hari==3){
        printf("\tSekarang hari Rabu");
    }else if(hari==4){
        printf("\tSekarang hari Kamis");
    }else if(hari==5){
        printf("\tSekarang hari Jumat");
    }else {
        printf("\tSekarang hari Sabtu");
    } printf(",%d/%d/%d.\n",local->tm_mday, local->tm_mon+1, local->tm_year+1900);

    switch(hari)
    {
        case 0 : harga_tiket=75.000; break;
        case 6 : harga_tiket=75.000; break;
        default : harga_tiket=50.000; break;
    }
    printf("\tHarga Tiket = Rp. %.3f\n", harga_tiket);
    printf("\t=========================================================================================\n");
    printf("\n\tPilih Film (1/2/3/4): ");
    while (1) {
    if (scanf("%d", &film) == 1 && film >= 1 && film <= 4) {
        break;
    } else {
        printf("\t--------------------------------------------------------------------------");
        printf("\n\tAngka yang Anda inputkan salah!");
        printf("\n\tMasukkan ulang pilihan Anda");  // Validasi apabila menginputkan pilihan film yang salah
        printf("\n\t------------------------------------------------------------------------");
        printf("\n\tPilih Film (1/2/3/4): ");
        while (getchar() != '\n');
    }
}


    // Validasi jam sesuai dengan waktu pada sistem
    int valid = 0;
    while (!valid) {
        printf("\n\tPilih Jam Tayang (1/2/3/4/5): ");
        while (1) {
            if (scanf("%d", &jamtayang) == 1 && jamtayang >= 1 && jamtayang <= 5) {
                break;
            } else {
                printf("\t------------------------------------------------------------------");
                printf("\n\tAngka yang Anda inputkan salah!");
                printf("\n\tMasukkan ulang pilihan Anda");  // Validasi apabila menginputkan pilihan jam tayang yang salah
                printf("\n\t----------------------------------------------------------------");
                printf("\n\tPilih Jam Tayang (1/2/3/4/5): ");
                while (getchar() != '\n');
            }
        }

        // Mendapatkan waktu saat ini
        time_t rawtime;
        struct tm *currentTime;
        time(&rawtime);
        currentTime = localtime(&rawtime);

        // Menghitung waktu jam tayang pada sistem
        float currentHour = currentTime->tm_hour + (currentTime->tm_min / 60.0);

        // Membandingkan waktu jam tayang dengan jam pada sistem
        if (currentHour < jam1[jamtayang]) {
            valid = 1;
        } else {
            printf("\n\t--------------------------------------------------------------");
            printf("\n\tMaaf, jam tayang telah berlalu. Silakan pilih jam tayang lain.");
            printf("\n\t--------------------------------------------------------------");
        }
    }

    //menampilkan film dan jam tayang yang dipesan
    system("cls");
    printf("\n\t----------------------------------------------------------------------");
    printf("\n\t                        TIKET FILM YANG DIPESAN");
    printf("\n\t----------------------------------------------------------------------");
    printf("\n\t FILM : %s", judul[film]);
    if(film==1 || film==4){
        printf("\n\t JAM  : %.2f",jam1[jamtayang]);
    }else if(film==2 || film==3){
        printf("\n\t JAM  : %.2f",jam2[jamtayang]);
    }
    printf("\n\tJumlah tiket yang dipesan : ");
    while (scanf("%d", &tiket)==0 || tiket < 0){
        printf("\t------------------------------------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan angka yang benar...");
        printf("\n\t------------------------------------------------------------------------");
        printf("\n\tJumlah tiket yang dipesan : ");
     	while((getchar())!='\n');
    }

    //memilih row dan seat di dalam bioskop
    printf("\n\tPilih Seat Yang Tersedia!");
    printf("\n\t========================================================================");
    printf("\n\t                         ----------------------");
    printf("\n\t                         ||                  ||");
    printf("\n\t                         ||                  ||");
    printf("\n\t                         ||      SCREEN      ||");
    printf("\n\t                         ||                  ||");
    printf("\n\t                         ||                  ||");
    printf("\n\t                         ----------------------");
    printf("\n\t========================================================================\n");

	for(int i=0; i<10; i++){
        printf("\t");
        for(h=1; h<=20; h++){
            printf("%c%d ", seat[i], h);//menampilkan daftar pilihan row dan seat
        }
        printf("\n\t------------------------------------------------------------------------\n");
    }
    printf("\t========================================================================");
    printf("\n\tPilih Seat (A-J) : ");
           do {
                fflush(stdin);
                scanf("%c", &huruf_kursi);
                if (huruf_kursi < 'A' || huruf_kursi > 'J') {
                    printf("\n\tHuruf kursi tidak valid! Silahkan masukkan huruf antara A-J: ");
                }
            } while (huruf_kursi < 'A' || huruf_kursi > 'J');
    printf("\n\tAnda memilih seat %c, Selanjutnya silahkan pilih nomor kursi!", huruf_kursi);
    for(h=0; h<tiket; h++){
        cekkursi:
        printf("\n\tPilih Nomor kursi ke-%d : ", h+1);
        while(scanf("%d", &angka_kursi[h])==0 || angka_kursi[h] < 1 || angka_kursi[h] > 20){
            printf("\t------------------------------------------------------------------------");
            printf("\n\tNomor Kursi Tidak Tersedia!");
            printf("\n\tMohon masukkan ulang pilihan");
            printf("\n\t------------------------------------------------------------------------");
            printf("\n\tMasukkan Pilihan Anda : ");
            while((getchar())!='\n');
        }
        kursi_terpilih[huruf_kursi - 'A'][angka_kursi[h] - 1] = 1;

        for(int i=0; i<h; i++){
            if(angka_kursi[h]==angka_kursi[i]){
                printf("\t--------------------------------------------------------------");
                printf("\n\tMaaf, Kursi %c-%d telah terisi, silahkan pilih kembali",huruf_kursi, angka_kursi[i]);
                printf("\n\t--------------------------------------------------------------");
                goto cekkursi;
            }
        }
    }

    //tampilan transaksi pembelian tiket
    close();
    printf("\t================================================================\n");
    printf("\t| NO |    FILM        |  SEAT  |  Harga                        |\n");
    printf("\t================================================================\n");
    for (i=0; i<tiket; i++){
    printf("\t| %d  |%s      |%c-%d     |%.3f                         |", i+1, judul[film], huruf_kursi, angka_kursi[i], harga_tiket);
    }
    printf("\n\t================================================================\n");

    printf("\n\tIngin Memesan M-Food? (Y/N) : ");
    fflush(stdin);
    scanf("%c", &pesan);

     if (pesan == 'y' || pesan == 'Y') {
        harga_makanan = makanan();
    }

    total_harga = harga_makanan;
    total_harga1 = total_harga + (harga_tiket*tiket);
    printf("\tTotal Harga M-Food \t\t\t\t\t Rp. %.3f", total_harga);
    printf("\n\tSimpan Tiket (Y/N)?  ");
    fflush(stdin);
    scanf("%c", &cetak );
    //menampilkan tiket yang dipesan
    close();

// Buat file DataPesanan.txt jika belum ada
        FILE *check = fopen("DataPesanan.txt", "r");
        if (check == NULL) {
        FILE *create = fopen("DataPesanan.txt", "w");
        fclose(create);
}

        // Baca bilangan random dari file
        FILE *baca = fopen("DataPesanan.txt", "r");
        srand(time(NULL));
        int rand_val=rand();
        printf("\tMasukkan kode ini untuk print tiket: %d\n", rand_val);

        if(cetak=='y' | cetak=='Y'){
        for(i=0; i<tiket; i++){
            // Untuk menyimpan di DataPesanan.txt
            FILE *insert = fopen("DataPesanan.txt", "a");
            fprintf(insert, "\n\t|============================================================|");
            fprintf(insert, "\n\t|                              XXI                           |");
            fprintf(insert, "\n\n\t|============================================================");
            fprintf(insert, "\n\t| %s\t\t\t\t\t\t\t|", judul[film]);
            fprintf(insert, "\n\t| Date  : %d/%d/%d\t\t\t\t\t\t|", local->tm_mday, local->tm_mon + 1, local->tm_year + 1900);
            if (film == 1 || film == 4) {
                fprintf(insert, "\n\t| Time  : %.2f\t\t\t\t\t\t\t|", jam1[jamtayang]);
            } else if (film == 2 || film == 3) {
                fprintf(insert, "\n\t| Time  : %.2f\t\t\t\t\t\t\t|", jam2[jamtayang]);
            }

            fprintf(insert, "\n\t| Bioskop: ");
            if (pilihan_daerah == 1) {
                fprintf(insert, "%s\t\t\t\t\t\t\t|", daerah[0]);
            } else if (pilihan_daerah == 2) {
                fprintf(insert, "%s\t\t\t\t\t\t\t|", daerah[1]);
            } else if (pilihan_daerah == 3) {
                fprintf(insert, "%s\t\t\t\t\t\t\t|", daerah[2]);
            } else {
                fprintf(insert, "Pilihan Tidak Valid");
            }

            fprintf(insert, "\n\t| Teater : ");
            if (pilihan_teater == 1) {
                fprintf(insert, "%s\t\t\t\t\t\t\t\t|", teater[0]);
            } else if (pilihan_teater == 2) {
                fprintf(insert, "%s\t\t\t\t\t\t\t\t|", teater[1]);
            } else if (pilihan_teater == 3) {
                fprintf(insert, "%s\t\t\t\t\t\t\t\t|", teater[2]);
            } else {
                fprintf(insert, "Pilihan tidak valid");
            }

            fprintf(insert, "\n\t| Row   : %c  Seat : %d\t\t\t\t\t\t|", huruf_kursi, angka_kursi[i]);
            fprintf(insert, "\n\t| Price : %.3f\t\t\t\t\t|", total_harga1);
            fprintf(insert, "\n\t|                                                           |");
            fprintf(insert, "\n\t=============================================================");

            fclose(insert);

            // Untuk menyimpan di RiwayatTransaksi.txt
            FILE *file = fopen("RiwayatTransaksi.txt", "a");
            fprintf(file,"\n\t|=================================");
            fprintf(file,"\n\t|               XXI              |");
            fprintf(file,"\n\t|=================================");
            fprintf(file,"\n\t|\t%s\t|", judul[film]);
            fprintf(file,"\n\t| studio: %d\t\t\t|",film);
            fprintf(file,"\n\t| date  : %d/%d/%d \t\t|",local->tm_mday, local->tm_mon+1, local->tm_year+1900);
            if(film==1 || film==4){
                fprintf(file,"\n\t| time  : %.2f\t\t\t|",jam1[jamtayang]);
            }else if(film==2 || film==3){
                fprintf(file,"\n\t| time  : %.2f\t\t\t|",jam2[jamtayang]);
            }
            fprintf(file,"\n\t| row   : %c  seat : %d\t\t|", huruf_kursi, angka_kursi[i]);
            fprintf(file,"\n\t| price : %.3f \t\t|", total_harga1);
            fprintf(file,"\n\t=================================");
            fclose(file);
        }
        data_pesanan();
        printf("\n\tIngin memesan lagi? (Y/N) : ");
        scanf("%s", &pesan);
        if (pesan=='y' || pesan=='Y'){
            close();
            pemesanan();
        }else if(pesan=='n' || pesan=='N'){
            close();
            selesai();
        }
    }else if(cetak=='n' || cetak=='N' ){
        printf("\n\tIngin memesan lagi? (Y/N) : ");
        scanf("%c", &pesan);
        if (pesan=='y' || pesan=='Y'){
            close();
            pemesanan();
        }else if(pesan=='n' || pesan=='N'){
            close();
            selesai();
        }
    }
}

void header_data_pesanan(){
    FILE *update = fopen("DataPesanan.txt", "w");
    fprintf(update, "\n\t==============================================================");
    fprintf(update, "\n\t||                      Data Pesanan                        ||");
    fprintf(update, "\n\t==============================================================");
    fclose(update);
}

void data_pesanan(){
    char buff[255];
    FILE *baca;
    printf("\n\t==============================================================");
    printf("\n\t-----------------------------XXI------------------------------");
    if ((baca = fopen("DataPesanan.txt","r")) == NULL){
        printf("\n\tError: File tidak ada!");
    }

    while(fgets(buff, sizeof(buff), baca)){
        printf("%s", buff);
    }

    fclose(baca);
}

void riwayat_transaksi(){
    system("cls");
    char buff[255];
    FILE *header;
    printf("\n\t==============================================================\n");
    printf("\n\t  -----------------------   X X I --------------------------- \n");
    printf("\n\t||============================================================||");
    printf("\n\t||                    Riwayat Transaksi                       ||");
    printf("\n\t||============================================================||");
    if ((header = fopen("RiwayatTransaksi.txt","r")) == NULL){
        printf("\n\tError: File tidak ada!");
    }

    while(fgets(buff, sizeof(buff), header)){
        printf("%s", buff);
    }

    fclose(header);
    close();
    admin_panel();
}

void data_customer(){
    system("cls");
    FILE *regis = fopen("DataCustomer.txt", "r");
    printf("\n\t============================================================\n");
    printf("\n\t  ------------------------   X X I ------------------------ \n");
    printf("\n\t||==========================================================||");
    printf("\n\t||                      Data Customer                       ||");
    printf("\n\t||==========================================================||");

    while (!feof(regis)){
        struct customer cust01;

        //membaca data dalam file DataCustomer.txt
        fscanf(regis, "%[^#]#%d\n", &cust01.nama_cust, &cust01.pin_cust);
        fflush(stdin);
        printf("\n\tUsername Customer  : %s", cust01.nama_cust);
        printf("\n\tPIN Customer       : %d", cust01.pin_cust);
        printf("\n\t--------------------------------------------------------------");
    }
    fclose(regis);
    close();
    admin_panel();
}


void selesai(){
    printf("\t\t __________________________________________________________________  \n");
    printf("\t\t   ______________________________________________________________  \n");
	printf("\t\t| |                                                             | |\n");
	printf("\t\t| |                                                             | |\n");
	printf("\t\t| |    Terima Kasih Telah Menggunakan Program Ini yaaaaaa!!!    | |\n");
    printf("\t\t| |                                                             | |\n");
	printf("\t\t| |                                                             | |\n");
    printf("\t\t| |        \\||||||||||||||||||||   ||||||||||||||||||\\          | |\n");
    printf("\t\t| |         \\|||||||||||||||||||   |||||||||||||||||||\\         | |\n");
    printf("\t\t| |          \\||||||||||||||||||   ||||||||||||||||||||\\        | |\n");
    printf("\t\t| |                   ||||||||||                                | |\n");
    printf("\t\t| |                   ||||||||||   ||||||||||||||||||||/        | |\n");
    printf("\t\t| |                   ||||||||||   |||||||||||||||||||/         | |\n");
    printf("\t\t| |                   ||||||||||   ||||||||||||||||||/          | |\n");
    printf("\t\t| |                   ||||||||||   |||||||||                    | |\n");
    printf("\t\t| |                   ||||||||||   |||||||||                    | |\n");
    printf("\t\t| |                   ||||||||||   |||||||||                    | |\n");
    printf("\t\t| |                   ||||||||||   |||||||||                    | |\n");
    printf("\t\t| |                    \\||||||||   |||||||/                     | |\n");
    printf("\t\t| |                     \\|||||||   ||||||/                      | |\n");
    printf("\t\t| |                      \\||||||   |||||/                       | |\n");
    printf("\t\t| |                       \\|||||   ||||/                        | |\n");
    printf("\t\t| |                        \\||||   |||/                         | |\n");
	printf("\t\t| |_____________________________________________________________| |\n");
	printf("\t\t____________________________________________________________________ \n");

    printf("\n\t\t==========================================================");
    printf("\n\t\t|                                                        |");
    printf("\n\t\t|                T E R I M A   K A S I H                 |");
    printf("\n\t\t|                            &                           |");
    printf("\n\t\t|         ----------SELAMAT MENONTON----------           |");
    printf("\n\t\t|                                                        |");
    printf("\n\t\t==========================================================\n\n");
    exit(0);
}
