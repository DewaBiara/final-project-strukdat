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

void UpdateAkun(){
	Biodata Pembeli[20];
	char id[20];
	int index,i;
	index=0;
	PEMBELI=fopen("pembeli.txt","r");
	printf("Masukan Username sekali lagi \t: ");scanf("%s",&id);fflush(stdin);
	while (!feof(PEMBELI)){
		fscanf(PEMBELI,"%[^_]_%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Pembeli[index].nama, &Pembeli[index].username, &Pembeli[index].umur, &Pembeli[index].telepon, &Pembeli[index].pendidikan, &Pembeli[index].password);
		fflush(stdin);
		if(strcmp(id,Pembeli[index].username)==0){
			printf("Nama baru \t\t\t: "); scanf("%[^\n]",&Pembeli[index].nama); fflush(stdin);
			printf("Umur baru \t\t\t: "); scanf("%i",&Pembeli[index].umur); fflush(stdin);
			printf("No Telepon baru \t\t: "); scanf("%[^\n]",&Pembeli[index].telepon); fflush(stdin);
			printf("Nama Sekolah/Instansi baru \t: "); scanf("%[^\n]",&Pembeli[index].pendidikan); fflush(stdin);
		}
		index++;
	}
	fclose(PEMBELI);
	PEMBELI=fopen("pembeli.txt","w");
	fclose(PEMBELI);
	PEMBELI=fopen("pembeli.txt","a");
	for(i=0; i<index; i++){
		fprintf(PEMBELI,"%s_%s_%i_%s_%s_%s\n", Pembeli[i].nama, Pembeli[i].username, Pembeli[i].umur, Pembeli[i].telepon, Pembeli[i].pendidikan, Pembeli[i].password);
	}
	printf("Selamat! Akun Anda sudah berhasil diupdate.\n");
	fclose(PEMBELI);
}

void daftar_pengiriman(){
	Biodata Pembeli;
	Barang Barang;
	PEMBELI=fopen("pembelian.txt","r");
	while (!feof(PEMBELI)){
		fscanf(PEMBELI,"%[^_]_%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Barang.nama_barang, &Barang.no, &Barang.harga, &Pembeli.nama, &Pembeli.username, &Pembeli.telepon);
		fflush(stdin);
			printf("Nama Barang \t\t: %s\n", Barang.nama_barang);
			printf("No Barang \t\t\t: %s\n", Barang.no);
        printf("Harga Barang \t\t; %i\n", Barang.harga);
			printf("Nama \t\t\t: %s\n", Pembeli.nama);
			printf("Nama Sekolah/Instansi \t: %s\n", Pembeli.username);
			printf("No Telepon \t\t: %s\n\n", Pembeli.telepon);
	}
	fclose(PEMBELI);
}

void tambah_barang() {
	Barang Barang;
	BARANG = fopen("buku.txt", "a+");
	printf("Nama Barang \t\t: "); scanf("%[^\n]",&Barang.nama_barang); fflush(stdin);
	printf("Merk \t\t: "); scanf("%[^\n]",&Barang.merk); fflush(stdin);
	printf("Supplier \t\t: "); scanf("%[^\n]",&Barang.supplier); fflush(stdin);
	printf("No Barang \t\t: "); scanf("%i",&Barang.no); fflush(stdin);
	printf("Jumlah Barang \t\t: "); scanf("%i", &Barang.jmlh); fflush(stdin);
    printf("Harga Barang \t\t: "); scanf("%i", &Barang.harga); fflush(stdin);
	printf("Tunggu Sebentar...\n");
	fprintf(BARANG,"%s_%s_%s_%s_%i_%i_%i\n", Barang.nama_barang, Barang.merk, Barang.supplier, Barang.no, Barang.jmlh, Barang.harga);
	printf("Selamat! Barang sudah berhasil ditambahkan.\n");
	fclose(BARANG);
}

void Pembelian(){
	Biodata Pembeli;
	Barang Barang[20];
    time_t now;
    time (&now);
	int no, id[20], c;
	int index,i;
	index=0;
	daftar_barang();
	BARANG=fopen("barang.txt", "r+");
	printf("\nMau membeli barang yang mana ?\n");
	printf("Masukkan no barang yang ingin dibeli : \n");
	scanf("%d",&no); fflush(stdin);
	while (!feof(BARANG)){
		fscanf(BARANG,"%[^_]_%[^_]_%[^_]_%i_%i_%i\n", &Barang[index].nama_barang, &Barang[index].merk, &Barang[index].supplier, &Barang[index].no, &Barang[index].jmlh, &Barang[index].harga);
		fflush(stdin);
		if(no == Barang[index].no){
			if(Barang[index].jmlh > 0){
				printf("======================Barang Berhasil Dibeli===============\n");
				Barang[index].jmlh -= 1;
				PEMBELI=fopen("pembeli.txt","r");
				printf("Masukan Username sekali lagi \t: "); scanf("%s",&id); fflush(stdin);
				while (!feof(PEMBELI)){
					fscanf(PEMBELI,"%[^_]_%[^_]_%i_%[^_]_%[^_]_%[^\n]\n",&Pembeli.nama, &Pembeli.username, &Pembeli.umur, &Pembeli.telepon, &Pembeli.pendidikan, &Pembeli.password);
					fflush(stdin);
					if(strcmp(id,Pembeli.username)==0){
						PEMBELI=fopen("pembelian.txt", "a");
						fprintf(PEMBELI,"%s_%i_%i_%s_%s_%s\n", Barang[index].nama_barang, Barang[index].no, Barang[index].harga, Pembeli.nama, Pembeli.username, Pembeli.telepon);
						fclose(PEMBELI);
						printf("Anda ingin mencetak struk?(y/n)");
                   		scanf("%c", &c);
						if(c == 'y' || c == 'Y'){
                    	   	system("cls");
                   	    	PEMBELIAN=fopen("pembelian.txt", "r");
                  	 	    printf("Tanggal pembelian : %s", ctime(&now));
                  	 	    printf("======================Struk Bukti Pembelian===============\n");
                  			printf("Nama Barang \t\t: %s\n", Barang[index].nama_barang);
							printf("No Barang \t\t: %i\n", Barang[index].no);
							printf("Harga Barang \t\t; %i\n", Barang[index].harga);
							printf("Nama \t\t\t: %s\n", Pembeli.nama);
                        printf("Nama Sekolah/Instansi \t: %s\n", Pembeli.username);
							printf("No Telepon \t\t: %s\n\n", Pembeli.telepon);
              	          	printf("Terima Kasih telah berbelanja.\n");
             	          	printf("===========================================================\n");
                	    	  
                    	}
					}
				}
				fclose(PEMBELI);
			}
			else {
				printf("======================Barang Tidak Dapat Dibeli===============\n");
			}
		}
		index++;
	}
	fclose(BARANG);
	BARANG=fopen("barang.txt","w");
	fclose(BARANG);
	BARANG=fopen("barang.txt","a");
	for(i=0; i<index; i++){
		fprintf(BARANG,"%s_%s_%s_%s_%i_%i_%i\n", Barang[i].nama_barang, Barang[i].merk, Barang[i].supplier, Barang[i].no, Barang[i].jmlh, Barang[i].harga);
	}
	fclose(BARANG);
}

void daftar_barang(){
    Barang Barang;
    BARANG = fopen("barang.txt", "r");
	printf("==========================================================================================================================\n");
    printf("No Barang \t"); 
	printf("Nama Barang \t\t\t");
    printf("Merk \t\t\t");
    printf("Supplier \t"); 
    printf("Jumlah Barang \t");
    printf("Harga \t");
    printf("\n=========================================================================================================================\n");
    while (!feof(BARANG)){
    fscanf(BARANG,"%[^_]_%[^_]_%[^_]_%i_%i_%i\n", &Barang.nama_barang, &Barang.merk, &Barang.supplier, &Barang.no, &Barang.jmlh, &Barang.harga);
		fflush(stdin);
			printf("|%-2i| \t", Barang.no); 
			printf("|%-30s|", Barang.nama_barang);
			printf("|%-25s|", Barang.merk);
			printf("|%-25s|", Barang.supplier); 
			printf("|%-4i|\t", Barang.jmlh);
			printf("|%-10i|\n", Barang.harga);
	}
    fclose(BARANG);
}

void Cari(){
	Barang Barang;
    BARANG = fopen("barang.txt", "r");
	int id;
	printf("Masukan NO Item yang ingin dicari \t: "); scanf("%i",&id); fflush(stdin);
	while (!feof(BARANG)){
    	fscanf(BARANG,"%[^_]_%[^_]_%[^_]_%i_%i_%i\n", &Barang.nama_barang, &Barang.merk, &Barang.supplier, &Barang.no, &Barang.jmlh, &Barang.harga);
		fflush(stdin);
		if(id == Barang.no){
			printf("No Barang \t: %i\n", Barang.no);
			printf("Nama Barang \t: %s\n", Barang.nama_barang);
            printf("Merk \t\t: %s\n", Barang.merk);
            printf("Supplier \t: %s\n", Barang.supplier); 
            printf("Jumlah Barang \t: %i\n", Barang.jmlh); 
            printf("Harga \t\t: %i\n\n", Barang.harga);
        }
    }
    fclose(BARANG);
}

int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

void push(int berat, char kirim[], char terima[], char alamat[])
{
    barang_stack *temp = (barang_stack *)malloc(sizeof(barang_stack));
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = berat;
    strcpy(temp->pengirim, kirim);
    strcpy(temp->penerima, terima);
    strcpy(temp->alamat, alamat);
    if (isEmpty() == 1)
    {
        top = temp;
    }
    else
    {
        top->next = temp;
        temp->prev = top;
        top = temp;
    }
}

void pop()
{
    barang_stack *hapus;
    hapus = top;
    if (isEmpty() == 1)
    {
        printf("Tidak ada barang\n");
    }
    else
    {
        top = top->prev;
        free(hapus);
    }
}

void display_stack()
{
    barang_stack *bantu;
    bantu = top;
    printf("\t Barang : \n");
    if (isEmpty() == 1)
    {
        printf("\t --KOSONG--\n");
    }
    else
    {
        while (bantu != NULL)
        {
            printf("\t ===================================\n");
            printf("\t Nama Pengirim :  %s\n", bantu->pengirim);
            printf("\t Nama Penerima :  %s\n", bantu->penerima);
            printf("\t Alamat Penerima :  %s\n", bantu->alamat);
            printf("\t Berat Barang :  %d\n", bantu->data);
            printf("\t ===================================\n");
            bantu = bantu->prev;
        }
    }
}

void initialize(queue *q)
{
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int isempty(queue *q)
{
    return (q->rear == NULL);
}

void enqueue(queue *q)
{
    if (q->count < TRUCK_SIZE)
    {
        barang_queue *tmp;
        tmp = malloc(sizeof(barang_queue));
        printf("\t Masukkan nama pengirim : ");
        fflush(stdin);
        scanf("%[^\n]s", tmp->pengirim);
        printf("\t Masukkan nama penerima : ");
        fflush(stdin);
        scanf("%[^\n]s", tmp->penerima);
        printf("\t Masukkan alamat penerima : ");
        fflush(stdin);
        scanf("%[^\n]s", tmp->alamat);
        printf("\t Masukkan berat : ");
        scanf("%d", &(tmp->data));
        tmp->next = NULL;
        if (!isempty(q))
        {
            q->rear->next = tmp;
            q->rear = tmp;
        }
        else
        {
            q->front = q->rear = tmp;
        }
        q->count++;
    }
    else
    {
        printf("\t Antrian sudah full!\n");
    }
}

int dequeue(queue *q)
{
    barang_queue *tmp;
    int n = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return (n);
}

void display(barang_queue *head)
{
    if (head == NULL)
    {
        printf("\t Tidak Ada Barang Lagi\n");
    }
    else
    {
        printf("\t DATA PENGIRIM DAN PENERIMA\n");
        printf("\t NAMA PENGIRIM : %s\n", head->pengirim);
        printf("\t NAMA PENERIMA : %s\n", head->penerima);
        printf("\t ALAMAT PENERIMA : %s\n", head->alamat);
        printf("\t BERAT BARANG : %d\n", head->data);
        printf("\t ===================================\n");
        display(head->next);
    }
}

void swap(barang_queue *a, barang_queue *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubble_sort(barang_queue *start)
{
    int swapped, i;
    barang_queue *ptr1;
    barang_queue *lptr = NULL;

    if (start == NULL)
    {
        return;
    }
    do
    {
        swapped = 0;
        ptr1 = start;
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void display_sort(barang_queue *head)
{
    if (head == NULL)
    {
        printf(" ");
    }
    else
    {
        printf("\t --%d\n", head->data);
        display_sort(head->next);
    }
}

void search(barang_queue *start, char *dicari)
{
    barang_queue *p;
    int pos = 1;
    p = start;
    while (p != NULL)
    {
        if (strcmp(p->pengirim, dicari) == 0)
        {
            printf("\t Barang yang dikirim oleh %s ditemukan diposisi %d\n", dicari, pos);
            return;
        }
        p = p->next;
        pos++;
    }
    printf("\t Barang yang dikirim oleh %s tidak ditemukan\n", dicari);
}

void hasEulerPath(int node[vertex][vertex], int in[vertex], int out[vertex])
{
    int odd = 0;
    int even = 0;
    if (vertex < 2)
    {
        eulerCircuit = false;
        eulerPath = false;
    }
    else if (vertex == 2 && (node[0][1] == 1 || node[1][0] == 1))
    {
        eulerCircuit = false;
        eulerPath = true;
        if (node[0][1] == 1 && node[1][0] == 0)
            startNode = 0;
        else
            startNode = 1;
    }
    else
    {
        if (directed == false)
        {
            for (int i = 0; i < vertex; i++)
            {
                if (in[i] % 2 != 0)
                {
                    odd++;
                    if (odd == 1)
                        startNode = i;
                    if (odd == 2)
                        finishNode = i;
                    if (odd > 2)
                    {
                        eulerCircuit = false;
                        eulerPath = false;
                        break;
                    }
                }
            }
            if (odd == 0)
            {
                startNode = 0;
                finishNode = 0;
            }
            if (odd > 2 || odd == 1)
                eulerPath = false;
            if (odd > 0)
                eulerCircuit = false;
        }

        else
        {
            for (int i = 0; i < vertex; i++)
            {
                if (out[i] - in[i] == 1)
                {
                    start++;
                    if (start = 1)
                        startNode = i;

                    if (start > 1)
                    {
                        eulerPath = false;
                        eulerCircuit = false;
                        break;
                    }
                }
                if (in[i] - out[i] == 1)
                {
                    finish++;
                    if (finish == 1)
                        finishNode = i;

                    if (finish > 1)
                    {
                        eulerPath = false;
                        eulerCircuit = false;
                        break;
                    }
                }
                if (in[i] == out[i])
                    even++;
                if (even != vertex && start == 1)
                    eulerCircuit = false;
            }
        }
    }
    if (eulerPath == true)
    {
        printf("\t Jalur Euler Ditemukan\n");
        printf("\t Start Node : %d\n", startNode + 1);
        printf("\t Finish Node: %d\n", finishNode + 1);
    }
    else
        printf("\t Jalur Euler Tidak Ditemukan\n");
    if (eulerCircuit == true)
        printf("\t Sirkuit Euler Ditemukan\n");
    else
        printf("\t Sirkuit Euler Tidak Ditemukan\n");
}

int pengiriman()
{
    int ch, choice, pos, i, j;
    int banyak_truk = 1;
    int banyak_barang = 1;
    char item[50];
    queue *q;
    q = malloc(sizeof(queue));
    initialize(q);
    while (banyak_truk <= MAX_TRUCK)
    {
        printf("\t=================================\n");
        printf("\t           GUDANG BALI           \n");
        printf("\t=================================\n");
        printf("\t 1. Input barang ke gudang\n");
        printf("\t 2. Hapus barang dari antrian\n");
        printf("\t 3. Masukkan barang ke truck\n");
        printf("\t 4. Lihat barang di antrian\n");
        printf("\t 5. Lihat barang di truk\n");
        printf("\t 6. Kirim barang ke cabang tujuan\n");
        printf("\t 7. Cari barang\n");
        printf("\t 8. Keluar\n");
        printf("\t=================================\n");
        printf("\t Input : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            while (banyak_barang <= TRUCK_SIZE)
            {
                printf("\t Masukkan data dari barang\n");
                enqueue(q);
                banyak_barang++;
                printf("\t=================================\n");
            }
        }
        else if (ch == 2)
        {
            dequeue(q);
        }
        else if (ch == 3)
        {
            barang_queue *bantu;
            bantu = q->front;
            do
            {
                push(bantu->data, bantu->pengirim, bantu->penerima, bantu->alamat);
                bantu = bantu->next;
            } while (bantu != NULL);
            printf("\t Barang berhasil dimasukan ke truk\n");
        }
        else if (ch == 4)
        {
            printf("\t ===================================\n");
            display(q->front);
        }
        else if (ch == 5)
        {
            display_stack();
        }
        else if (ch == 6)
        {
            if ((banyak_barang = TRUCK_SIZE) && (banyak_truk <= 3))
            {
                printf("\t BARANG TELAH DIKIRIM KE BALI\n");
                banyak_truk++;
                while (1)
                {
                    printf("\t=================================\n");
                    printf("\t          GUDANG Cabang          \n");
                    printf("\t=================================\n");
                    printf("\t 1. Cek barang di truk\n");
                    printf("\t 2. Urutkan barang\n");
                    printf("\t 3. Kirim barang ke pelanggan\n");
                    printf("\t 4. Keluar\n");
                    printf("\t Input : ");
                    scanf("%d", &choice);
                    if (choice == 1)
                    {
                        display_stack();
                    }
                    else if (choice == 2)
                    {
                        bubble_sort(q->front);
                        printf("\t Sort Barang Berdasarkan Berat\n");
                        display_sort(q->front);
                    }
                    else if (choice == 3)
                    {
                        int allVisited = 0;
                        vertex = TRUCK_SIZE;
                        int node[vertex][vertex];
                        printf("\t Masukkan 1 apabila terhubung \n");
                        printf("\t Masukkan 0 jika tidak terhubung \n");
                        for (i = 0; i < vertex; i++)
                        {
                            for (j = 0; j < vertex; j++)
                            {
                                if (i != j)
                                {
                                    printf("\t Alamat ke-%d dan alamat ke-%d: ", i + 1, j + 1);
                                    scanf("%d", &node[i][j]);
                                }
                                else
                                {
                                    node[i][j] = 0;
                                }
                            }
                        }
                        printf("\t Tampilan Matriks : \n");
                        for (i = 0; i < vertex; i++)
                        {
                            for (j = 0; j < vertex; j++)
                            {
                                printf("\t %d ", node[i][j]);
                            }
                            printf("\n");
                        }
                        if (vertex < 2)
                            printf("\t Tidak Ada Graph yang terbentuk!\n");
                        else
                        {
                            int outdegree[vertex];
                            for (i = 0; i < vertex; i++)
                            {
                                outdegree[i] = 0;
                                for (j = 0; j < vertex; j++)
                                {
                                    if (node[i][j] == 1)
                                    {
                                        outdegree[i]++;
                                    }
                                }
                            }
                            int indegree[vertex];
                            for (j = 0; j < vertex; j++)
                            {
                                indegree[j] = 0;
                                for (i = 0; i < vertex; i++)
                                {
                                    if (node[i][j] == 1)
                                    {
                                        indegree[j]++;
                                    }
                                }
                            }
                            if (directed == true)
                                printf("\t Berarah!\n");
                            else
                                printf("\t Tidak Berarah!\n");
                            hasEulerPath(node, indegree, outdegree);
                            if (eulerPath == true)
                            {
                                printf("\n\t Rute Euler:\n");
                                j = startNode;
                                while (allVisited != 1)
                                {
                                    for (i = vertex - 1; i >= 0; i--)
                                    {
                                        if (node[j][i] == 1)
                                        {
                                            if (startNode > -1)
                                            {
                                                printf("\t %d -> %d\n", j + 1, i + 1);
                                                startNode = -1;
                                            }
                                            else
                                                printf("\t %d -> %d\n", j + 1, i + 1);
                                            node[j][i] = 0;
                                            node[i][j] = 0;
                                            j = i;
                                            break;
                                        }
                                        else if (j == finishNode && i == 0 && node[j][i] == 0)
                                        {
                                            allVisited = 1;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else if (choice == 4)
                    {
                        exit(1);
                    }
                }
            }
        }
        else if (ch == 7)
        {
            printf("\t Masukkan nama pengirim : ");
            fflush(stdin);
            scanf("%[^\n]s", &item);
            search(q->front, item);
        }
        else if (ch == 8)
        {
            break;
        }
    }
    return 0;
}