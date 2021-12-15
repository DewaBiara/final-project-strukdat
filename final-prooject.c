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
