#ifndef PST_H
#define PST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include<conio.h>

//ADT BUKU
typedef struct{
	long ISBN;
	char Pengarang[100];
	char Judul[100];
	long Tahun;
	int Jumlah; //jumlah buku
	int jumlahcharjudul;
	int jumlahcharpengarang;
}Buku;
//ADT RAK BUKU
typedef struct{
	Buku Rak[100];
	int Neff;
}Rak;
//ADT PEMINJAM
typedef struct{
	long ID;
	char NIM[20];
	char Nama[100];
	int Jurusan;
	int jumlahchar;
}Peminjam;
//ADT KEANGGOTAAN
typedef struct{
	Peminjam Daftar[100];
	int Neff;
}Anggota;
//ADT TANGGAL
typedef struct{
	int DD;
	int MM;
	int YY;
}Tanggal;
//ADT PEMINJAMAN
typedef struct{
	Buku B;
	Peminjam P;
	Tanggal T1; //Waktu peminjaman
	Tanggal T2; //Waktu pengembaliannya
	long long denda;
	long ID;
}Peminjaman;
//ADT TABEL PEMINJAMAN
typedef struct{
	Peminjaman List[100];
	int Neff;
}TabelPeminjaman;

//PROSEDUR DAN FUNGSI
//Buku
void MakeBook(Buku *Book);
void ReadBook(Buku Book);
void ISBNUpdate(Buku *Book);
void PengarangUpdate(Buku *Book);
void JudulUpdate(Buku *Book);
void TahunUpdate(Buku *Book);
long GetISBN(Buku Book);
char* GetPengarang(Buku *Book);
char* GetJudul(Buku *Book);
int GetTahun(Buku Book);
//PEMINJAM
void MakePeminjam(Peminjam *P);
void ReadPeminjam(Peminjam P);
void IDUpdate(Peminjam *P);
void NamaUpdate(Peminjam *P);
long GetID(Peminjam P);
char* GetNama(Peminjam *P);
//TANGGAL
boolean IsDateValid(int x,int y,int z);
void MakeDate(Tanggal *T);
int HitungDate(Tanggal T1, Tanggal T2);
void ReadDate(Tanggal T);
void UpdateDay(Tanggal *T, int x);
void UpdateMonth(Tanggal *T, int x);
void UpdateYear(Tanggal *T, int x);
int GetDay(Tanggal T);
int GetMonth(Tanggal T);
int GetYear(Tanggal T);
void NextDay(Tanggal *T,TabelPeminjaman *A);
void NextNDay(Tanggal *T,TabelPeminjaman *A);
//PEMINJAMAN
void TanggalPengembalian(Peminjaman *A,Tanggal *T,Rak *R);
void MakePeminjaman(Peminjaman *A,Anggota *X,Rak *R,Tanggal *T);
void ReadPeminjaman(Peminjaman A,Tanggal T);
//TABEL PEMINJAMAN
void MakeEmptyTabelPeminjaman(TabelPeminjaman *A);
void InputPeminjaman(TabelPeminjaman *A, Anggota *B, Rak *R, Tanggal *T);
void PrintTabel(TabelPeminjaman A, Tanggal T);
void InputPengembalian(TabelPeminjaman *A,Tanggal *T, Rak *R);
void DeletePeminjaman(TabelPeminjaman *A);
void SearchTanggalPeminjaman(TabelPeminjaman *A);
void LihatPeminjamankei(TabelPeminjaman A);
//RAK
void MakeEmpty(Rak *R);
void InputBook(Rak *R);
void LihatRak(Rak R);
void DeleteRak(Rak *R);
void LihatRakKei(Rak R);
void SearchTahunPembuatan(Rak *R);
void ReStock(Rak *R);
//Anggota
void MakeEmptyK(Anggota *A);
void InputAnggota(Anggota *A);
void DeleteAnggota(Anggota *A);
void LihatAnggota(Anggota A);
void LihatAnggotakei(Anggota A);
void SearchKodeJurusan(Anggota *A);
#endif
