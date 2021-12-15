#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#define TRUE 1
#define FALSE 0
#define MAX_TRUCK 3
#define TRUCK_SIZE 7

void BuatAkun();
int  Login();
void Profil();
void UpdateAkun();
void tambah_buku_beli();
void daftar_buku_beli();
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
		printf("Anda ingin masuk sebagai?\n");
		printf("1. Pembeli \n2. Admin \n");
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
	PEMBELI=fopen("pengunjung.txt","a+");
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
		printf("1. Profil \n2. Daftar Buku \n3. Cari Buku \n4. Peminjaman Buku \n5. Pengembalian Buku \n6. Pembelian Buku \n7. Keluar \n");
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
				printf("|                              Daftar Buku                             |\n");
				printf("|______________________________________________________________________|\n");
				daftar_buku_pinjam();
				break;
			case '3':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                               Cari Buku                              |\n");
				printf("|______________________________________________________________________|\n");
				Cari();
				break;
			case '4':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                            Peminjaman Buku                           |\n");
				printf("|______________________________________________________________________|\n");
				Peminjaman();
				break;
			case '5':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                           Pengembalian Buku                          |\n");
				printf("|______________________________________________________________________|\n");
				Pengembalian();
				break;
			case '6':
				system("cls");
				printf("________________________________________________________________________\n");
				printf("|                            Pembelian Buku                            |\n");
				printf("|______________________________________________________________________|\n");
				Pembelian();
				break;
			case '7':
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

