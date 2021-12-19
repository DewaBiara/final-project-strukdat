#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
#define MAX_TRUCK 3
#define TRUCK_SIZE 7

void BuatAkun();
int  Login();
void Profil();
void UpdateAkun();
void tambah_item();
void daftar_item();
void Menu();
void Cari();
void Pembelian();
int isEmpty();
void push();
void pop();
void display_stack();
void initialize();
int isempty();
void enqueue();
int dequeue();
void display();
void swap();
void bubble_sort();
void display_sort();
void search();
void hasEulerPath();
int pengiriman();


bool eulerPath = true;
bool eulerCircuit = true;
bool directed = false;
int start, finish, vertex, startNode, finishNode;

typedef struct{
	char nama[50];
	char username[20];
	int  umur;
	char telepon[13];
	char pendidikan[50];
	char password[20];
}Biodata;

typedef struct{
	char nama_barang[25];
	char supplier[30];
	char merk[20];
	int  no;
	int  jmlh;
    int  harga;
}Barang;

typedef struct barang_queue
{
    int data;
    char pengirim[50], penerima[50], alamat[50];
    struct barang_queue *next;
} barang_queue;

typedef struct barang_stack
{
    int data;
    char pengirim[50], penerima[50], alamat[50];
    struct barang_stack *next;
    struct barang_stack *prev;
} barang_stack;
barang_stack *top = NULL;

typedef struct queue
{
    int count;
    barang_queue *front;
    barang_queue *rear;
} queue;

FILE*PEMBELI;
FILE*BARANG;
FILE*PEMBELIAN;

int main(){
	system("cls");
	char pilihan, pilihan2;
	char ulangi = 'y';
	int login, loginA;
	int kode;
	do{
		printf("==================================================================\n");
		printf("============================TOKO PEDEI============================\n");
		printf("==================================================================\n");
		printf("Pilih Opsi :\n");
		printf("1. Masuk sebagai Pembeli \n2. Pengiriman Barang \n");
		printf("Masukkan Pilihan : ");
		scanf("%c", &pilihan); fflush(stdin);
		system("cls");
		switch (pilihan) {
			case '1':
				printf("________________________________________________________________________\n");
				printf("|                     Anda masuk sebagai Pembeli                       |\n");
				printf("|______________________________________________________________________|\n");
				printf("1. Login \n2. Register \n");
				printf("Masukkan Pilihan : ");
				scanf("%c", &pilihan2); fflush(stdin);
				system("cls");
				switch (pilihan2) {
					case '1':
						printf("________________________________________________________________________\n");
						printf("|                                 Login                                |\n");
						printf("|______________________________________________________________________|\n");
						login = Login();
						if(login == 1){
							Menu();
						}
						else{
      					  	printf("Username atau Password salah! \n");
      					  	system("pause");
      						exit(0);
   						} 
						break;
					case '2':
						printf("________________________________________________________________________\n");
						printf("|                                Register                              |\n");
						printf("|______________________________________________________________________|\n");
						BuatAkun();
						break;
					default:
						printf("~Pilihan yang anda masukkan salah~\n");
				}
				break;
			case '2':
				pengiriman();
            break;
			default:
				printf("~Pilihan yang anda masukkan salah~\n");	
		}
	printf("Apakah anda ingin mengulang? (y/t) :"); 
	scanf("%c",&ulangi); fflush(stdin);
	} while(ulangi == 'y');
}

void BuatAkun(){
	Biodata Pembeli;
	PEMBELI=fopen("pembeli.txt","a+");
	printf("Nama \t\t\t: "); scanf("%[^\n]",&Pembeli.nama); fflush(stdin);
	printf("Username \t\t: "); scanf("%[^\n]",&Pembeli.username); fflush(stdin);
	printf("Umur \t\t\t: "); scanf("%i",&Pembeli.umur); fflush(stdin);
	printf("No Telepon \t\t: "); scanf("%[^\n]",&Pembeli.telepon); fflush(stdin);
	printf("Nama Sekolah/Instansi \t: "); scanf("%[^\n]",&Pembeli.pendidikan); fflush(stdin);
	printf("Password \t\t: "); scanf("%[^\n]",&Pembeli.password); fflush(stdin);
	printf("Tunggu Sebentar...\n");
	fprintf(PEMBELI,"%s_%s_%i_%s_%s_%s\n", Pembeli.nama, Pembeli.username, Pembeli.umur, Pembeli.telepon, Pembeli.pendidikan, Pembeli.password);
	printf("Selamat! Akun Anda sudah berhasil dibuat.\n");
	fclose(PEMBELI);
}

int Login(){
	char user[20], pass[20];
	Biodata Pembeli;
	PEMBELI=fopen("pembeli.txt","r");
    printf("Username : "); scanf("%s",&user); fflush(stdin);
    printf("Password : "); scanf("%s",&pass); fflush(stdin);
	while (!feof(PEMBELI)){
		fscanf(PEMBELI,"%[^_]_%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Pembeli.nama, &Pembeli.username, &Pembeli.umur, &Pembeli.telepon, &Pembeli.pendidikan, &Pembeli.password);
		fflush(stdin);
		if(strcmp(user,Pembeli.username)==0 && strcmp(pass,Pembeli.password)== 0) {
			system("cls");
			return 1;;
		}
	}
}

void Menu(){
	char pilihan, ulangi;
	printf("________________________________________________________________________\n");
	printf("|                       Anda sudah berhasil Login                      |\n");
	printf("|______________________________________________________________________|\n");
	do {
		printf("~MENU~ \t: \n");
		printf("1. Profil \n2. Daftar Item \n3. Cari Item \n4. Pembelian Item \n5. Keluar \n");
		printf("Masukkan Pilihan :");
		scanf("%c", &pilihan); fflush(stdin);
		system("cls");
		switch (pilihan){
			case '1':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                                Profil                                |\n");
				printf("|______________________________________________________________________|\n");
				Profil();
				break;
			case '2':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                              Daftar Item                             |\n");
				printf("|______________________________________________________________________|\n");
				daftar_barang();
				break;
			case '3':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                               Cari Item                              |\n");
				printf("|______________________________________________________________________|\n");
				Cari();
				break;
			case '4':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                            Pembelian Item                            |\n");
				printf("|______________________________________________________________________|\n");
				Pembelian();
				break;
			case '5':
				system("pause");
      			exit(0);
				break;
			default:
				printf("~Pilihan yang anda masukkan salah~\n");
		}
	printf("Kembali ke menu ? (y/t) :"); 
	scanf("%c",&ulangi); fflush(stdin);
	system("cls");
	} while(ulangi == 'y');
}

void Profil(){
	Biodata Pembeli;
	char id[20], pilihan;
	PEMBELI=fopen("pembeli.txt","r");
	printf("Masukan Username sekali lagi \t: ");scanf("%s",&id);fflush(stdin);
	while (!feof(PEMBELI)){
		fscanf(PEMBELI,"%[^_]_%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Pembeli.nama, &Pembeli.username, &Pembeli.umur, &Pembeli.telepon, &Pembeli.pendidikan, &Pembeli.password);
		fflush(stdin);
		if(strcmp(id,Pembeli.username)==0){
			printf("Nama \t\t\t: %s\n", Pembeli.nama);
			printf("Umur \t\t\t: %i\n", Pembeli.umur);
			printf("No Telepon \t\t: %s\n", Pembeli.telepon);
			printf("Nama Sekolah/Instansi \t: %s\n", Pembeli.pendidikan);
		}
	}
	fclose(PEMBELI);
	printf("Apakah anda ingin update akun?\n");
	printf("Masukkan Pilihan (y/n): ");
	scanf("%c", &pilihan); fflush(stdin);
	if(pilihan == 'y' || pilihan == 'Y'){
			system("cls");
			printf("________________________________________________________________________\n");
			printf("|                             Update Akun                              |\n");
			printf("|______________________________________________________________________|\n");
			UpdateAkun();
	}
}