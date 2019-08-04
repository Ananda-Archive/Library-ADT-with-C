#include "pst.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////Buku///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
COORD coord = {0,0}; //Untuk membuat list menyamping
void koorxy(int x, int y){
	coord.X = x;
	coord.Y	= y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void MakeBook(Buku *Book){ //Membuat Buku
	char P[100];
	char J[100];
	int Tahun,Jumlah;
	long ISBN;
	fflush(stdin);
	printf("Judul Buku: ");
	gets(J);
	printf("\nPengarang: ");
	gets(P);
	printf("\nISBN: ");
	scanf("%ld",&ISBN);
	printf("\nTahun Penerbit: ");
	scanf("%ld",&Tahun);
	printf("\nJumlah Buku: ");
	scanf("%d",&Jumlah);
	strcpy((*Book).Judul,J);strcpy((*Book).Pengarang,P);
	(*Book).ISBN = ISBN;
	(*Book).Tahun = Tahun;
	(*Book).Jumlah = Jumlah;
	(*Book).jumlahcharjudul=strlen(J);
	(*Book).jumlahcharpengarang=strlen(P);
}
void ReadBook(Buku Book){ //Membaca Buku
	printf("Info Buku:\n");
	printf("Judul Buku\t: %s\n",Book.Judul);
	printf("Pengarang\t: %s\n",Book.Pengarang);
	printf("ISBN\t\t: %ld\n",Book.ISBN);
	printf("Tahun Terbit:\t: %ld\n",Book.Tahun);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////Peminjam///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MakePeminjam(Peminjam *P){ //Membuat Peminjam, ID peminjam dibuat saat di fungsi InputAnggota dan juga ID dibuat random
	char Nama[100];
	char NIM[20];
	int Jurusan;
	fflush(stdin);
	printf("\nMasukkan NIM : ");
	gets(NIM);
	fflush(stdin);
	printf("Masukkan Nama Peminjam: ");
	gets(Nama);
	Jurusan:
	printf("Masukkan Jurusan Anda berasal : ");
	scanf("%d",&Jurusan);
	if(Jurusan<0 || Jurusan>6){
		printf("Kode Jurusan Salah");
		getch();
		goto Jurusan;
	}
	else{
		(*P).Jurusan=Jurusan;
	}
	strcpy((*P).NIM,NIM);
	strcpy((*P).Nama,Nama);
	(*P).jumlahchar=strlen(Nama);
}
void ReadPeminjam(Peminjam P){ //Menampilkan Peminjam
	printf("Info Peminjam:\n");
	printf("ID\t\t: %ld\n",P.ID);
	printf("Nama\t\t: %s\n",P.Nama);
	printf("NIM\t\t: %s\n",P.NIM);
	switch(P.Jurusan){
		case 1:
			printf("Jurusan\t\t: Informatika\n");
			break;
		case 2:
			printf("Jurusan\t\t: Matematika\n");
			break;
		case 3:
			printf("Jurusan\t\t: Statistika\n");
			break;
		case 4:
			printf("Jurusan\t\t: Biologi\n");
			break;
		case 5:
			printf("Jurusan\t\t: Kimia\n");
			break;
		case 6:
			printf("Jurusan\t\t: Fisika\n");
			break;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////tanggal///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
boolean IsDateValid(int x,int y,int z){
    int month;
    {
		switch(y){
			case 1: 	month=31; break; //January
			case 2: 	if (z % 4 == 0){
                            month=29;
                        }else{
                        month=28;
                        }
                        break; //February
			case 3: 	month=31; break; //March
			case 4: 	month=30; break; //April
			case 5: 	month=31; break; //May
			case 6: 	month=30; break; //June
			case 7: 	month=31; break; //July
			case 8: 	month=31; break; //August
			case 9: 	month=30; break; //September
			case 10: 	month=31; break; //October
			case 11: 	month=30; break; //November
			case 12: 	month=31; break; //December
			default : return FALSE;
		}
	}
	if (y<1 || y>12){
        return FALSE;
	}
	if ((x<1)||(x>month)){
        return FALSE;
	}
	if (z<1){
        return FALSE;
	}
	return TRUE;
}
int HitungDate(Tanggal T1, Tanggal T2){ //Menghitung Berapa hari dari T1 sampai T2, berguna untuk menghitung denda
	int month[12];
	int i,j;
	int jumlah = 0;
	for(i=0;i<=12;i++){
		switch(i){
			case 0:		month[i]=0; break;
			case 1: 	month[i]=31; break; //January
			case 2: 	month[i]=28; break; //February
			case 3: 	month[i]=31; break; //March
			case 4: 	month[i]=30; break; //April
			case 5: 	month[i]=31; break; //May
			case 6: 	month[i]=30; break; //June
			case 7: 	month[i]=31; break; //July
			case 8: 	month[i]=31; break; //August
			case 9: 	month[i]=30; break; //September
			case 10: 	month[i]=31; break; //October
			case 11: 	month[i]=30; break; //November
			case 12: 	month[i]=31; break; //December
		}
	}
	//Menghitung Jumlah hari di Tahun Yang sama
	if (T1.YY == T2.YY){
		if (T2.MM-T1.MM>=2){
			for(j=T1.MM+1;j<T2.MM;j++){
				jumlah=jumlah+month[j];
			}
			jumlah=jumlah+(month[T1.MM]-T1.DD)+(T2.DD);
		}
		else{
			if (T2.MM-T1.MM==1){
				jumlah=(month[T1.MM]-T1.DD)+(T2.DD);
			}
			else{
				jumlah=T2.DD-T1.DD;
			}
		}
		if (T1.YY%4==0&&T1.MM<=2 || T1.YY%4==0&&T2.MM>=2){ //Kalau Tahunnya Kabisat
			return jumlah+1;
		}
		else{ //Kalau Tahunnya tidak kabisat
			return jumlah;
		}
	}
	//Menghitung Jumlah hari di Tahun yang berbeda
	else{
		if (T1.MM!=12 && T2.MM!=1){
			for(j=T1.MM+1;j<=12;j++){
				jumlah=jumlah+month[j];
			}
			for(j=1;j<T2.MM;j++){
				jumlah=jumlah+month[j];
			}
			jumlah=jumlah+(month[T1.MM]-T1.DD)+T2.DD;
		}
		else{
			if (T1.MM==12 && T2.MM!=1){
				for(j=1;j<T2.MM;j++){
					jumlah=jumlah+month[j];
				}
				jumlah=jumlah+(month[T1.MM]-T1.DD)+T2.DD;
			}
			else{
				if (T1.MM!=12 && T2.MM==1){
					for(j=T1.MM+1;j<=12;j++){
						jumlah=jumlah+month[j];
					}
					jumlah=jumlah+(month[T1.MM]-T1.DD)+T2.DD;
				}
				else{
					jumlah=(month[T1.MM]-T1.DD)+(T2.DD);
				}
			}
		}
		//Jika perbedaan hanya 1 tahun
		if (T2.YY-T1.YY==1){
			if ((T1.YY%4==0&&T1.MM<=2)||(T1.YY%4==0&&T2.MM>2)||(T2.YY%4==0&&T1.MM<=2)||(T2.YY%4==0&&T2.MM>2)){
				return jumlah+1;
			}
			else{
				return jumlah;
			}
		}
		//Jika perbedaan lebih dari 1 tahun
		else{
			for(j=T1.YY+1;j<T2.YY;j++){
				if (j%4==0){
					jumlah=jumlah+366;
				}
				else{
					jumlah=jumlah+365;
				}
			}
			if (T1.YY%4==0 && T1.MM<=2){
				jumlah=jumlah+1;
			}
			if (T2.YY%4==0 && T2.MM>2){
				jumlah=jumlah+1;
			}
			return jumlah;
		}
	}
}
void MakeDate(Tanggal *T){
	int x,y,z;
	do{
        printf("\nMasukkan Hari: ");
        scanf("%d",&x);
        printf("\nMasukkan Bulan: ");
        scanf("%d",&y);
        printf("\nMasukkan Tahun: ");
        scanf("%d",&z);
        (*T).DD=x;
        (*T).MM=y;
        (*T).YY=z;
	}while(!IsDateValid(x,y,z));

}
void ReadDate(Tanggal T){
    printf("%02d-%02d-%04d",T.DD,T.MM,T.YY);
}
void NextDay(Tanggal *T,TabelPeminjaman *A){ //Selain menambah 1 hari, fungsi nextday juga mengkalkulasikan denda setiap peminjaman yang belum mengembalikan buku
	int month;
	int i;
	switch((*T).MM){
		case 1: 	month=31; break; //January
		case 2: 	if ((*T).YY % 4 == 0){
                        month=29;
                    }else{
                    month=28;
                    }
                    break; //February
		case 3: 	month=31; break; //March
		case 4: 	month=30; break; //April
		case 5: 	month=31; break; //May
		case 6: 	month=30; break; //June
		case 7: 	month=31; break; //July
		case 8: 	month=31; break; //August
		case 9: 	month=30; break; //September
		case 10: 	month=31; break; //October
		case 11: 	month=30; break; //November
		case 12: 	month=31; break; //December
    }
    (*T).DD=(*T).DD+1;
    if ((*T).DD>month){
        (*T).DD= 1;
        (*T).MM= (*T).MM + 1;
    }
    if ((*T).MM>12){
        (*T).MM= 1;
        (*T).YY= (*T).YY + 1;
    }
    //Kalulasi denda
    for(i=0;i<(*A).Neff;i++){
    	if (((*A).List[i].T2.DD==0)&&(HitungDate((*A).List[i].T1,(*T))>7)){ //Mengecek apakah T2 masih belum ada dan juga mengecek apakah sudah lebih dari 7 hari
    		(*A).List[i].denda=(*A).List[i].denda+1000;
    	}
    }
}
void NextNDay(Tanggal *T,TabelPeminjaman *A){
	int N;
	int i;
	printf("Ingin Lompat berapa hari?");
	scanf("%d",&N);
	for (i=1;i<=N;i++){
		NextDay(T,A);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////Rak///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void MakeEmpty(Rak *R){
	(*R).Neff=0;
}
void InputBook(Rak *R){
	Buku B;
	back:
	system("cls");
	MakeBook(&B);
	long x = B.ISBN;
	int y;
	y=0;
	if ((*R).Neff==0){
		(*R).Rak[(*R).Neff]=B;
		(*R).Neff++;
	}
	else{
		while(y!=(*R).Neff){
			if (x==(*R).Rak[y].ISBN){
				system("cls");
				printf("\nISBN Sudah terdaftar\n");
				getch();
				goto back; //Menemukan ISBN yang sama, user harus mengulang penulisan buku dengan ISBN yang berbeda
			}
			else{
				y++;
			}
		}
		//Jika tidak ada ISBN yang sama maka buku akan terdaftar
		(*R).Rak[(*R).Neff]=B;
		(*R).Neff++;
	}
}
void LihatRak(Rak R){
	int i=0;
	int j=0;
	system("cls");
	koorxy(0,0);
	printf("Index");
	koorxy(10,0);
	printf("ISBN Buku");
	koorxy(30,0);
	printf("Judul Buku");
	koorxy(60,0);
	printf("Pengarang Buku");
	koorxy(90,0);
	printf("Tahun Produksi");
	koorxy(109,0);
	printf("Jumlah Buku");
	for(i=0;i<R.Neff;i++){
		koorxy(0,i+1);
		printf("%d",i);
		koorxy(10,i+1);
		printf("%ld",R.Rak[i].ISBN);
		koorxy(30,i+1);
		//Berguna jika Pengarang namanya panjang, maka akan ditampilkan hanya 21 karakter, dan 3 tanda titik
		if(R.Rak[i].jumlahcharjudul>20){
			for(j=0;j<=20;j++){
				printf("%c",R.Rak[i].Judul[j]);
			}
			printf("...");
		}
		else{
			printf("%s",R.Rak[i].Judul);
		}
		koorxy(60,i+1);
		//Berguna jika Pengarang namanya panjang, maka akan ditampilkan hanya 18 karakter, dan 3 tanda titik
		if(R.Rak[i].jumlahcharpengarang>20){
			for(j=0;j<=17;j++){
				printf("%c",R.Rak[i].Pengarang[j]);
			}
			printf("...");
		}
		else{
			printf("%s",R.Rak[i].Pengarang);
		}
		koorxy(90,i+1);
		printf("%ld",R.Rak[i].Tahun);
		koorxy(109,i+1);
		printf("%d",R.Rak[i].Jumlah);
	}
}
void DeleteRak(Rak *R){
    int i,j,k;
    printf("Masukkan indeks rak : ");
    scanf("%d",&i);
    if((*R).Neff==0){
        printf("Rak Buku Kosong");
    }else{
    for(j=0;j<(*R).Neff;j++){
        if (i==j){
            for(k=j+1;k<(*R).Neff;k++){
                (*R).Rak[k-1]=(*R).Rak[k];
            }
            (*R).Neff=(*R).Neff-2;
            (*R).Neff++;
        }
    }
    }

}
void LihatRakKei(Rak R){ //Lihat rak dengan memasukkan ISBN buku
	int i=0;
	long ISBN;
	printf("Masukkan ISBN buku untuk melihat Info buku!\n");
	scanf("%ld",&ISBN);
	while(i<R.Neff){
		if(R.Rak[i].ISBN==ISBN){
			printf("\n");
			ReadBook(R.Rak[i]);
			break;
		}
		else{
			i++;
		}
	}
	if(i==R.Neff){
		printf("\nBuku tidak ditemukan!!!");
	}
}
void SearchTahunPembuatan(Rak *R){ //Mem-filter rak dengan tahun pembuatan ke....
	Tanggal TT;
	int y;
	printf("Masukkan Tahun yang ingin anda cari: ");
	scanf("%d",&y);
	TT.YY=y;
	int i=0;
	int j=0;
	int k=0;
	system("cls");
	koorxy(0,0);
	printf("Index");
	koorxy(10,0);
	printf("ISBN Buku");
	koorxy(30,0);
	printf("Judul Buku");
	koorxy(60,0);
	printf("Pengarang Buku");
	koorxy(90,0);
	printf("Tahun Produksi");
	koorxy(109,0);
	printf("Jumlah Buku");
	while(k<(*R).Neff){
		if(TT.YY==(*R).Rak[k].Tahun){
			koorxy(0,i+1);
			printf("%d",k);
			koorxy(10,i+1);
			printf("%ld",(*R).Rak[k].ISBN);
			koorxy(30,i+1);
			if((*R).Rak[k].jumlahcharjudul>11){
				for(j=0;j<=11;j++){
					printf("%c",(*R).Rak[k].Judul[j]);
				}
				printf("...");
			}
			else{
				printf("%s",(*R).Rak[k].Judul);
			}
			koorxy(60,i+1);
			if((*R).Rak[k].jumlahcharpengarang>20){
				for(j=0;j<=17;j++){
					printf("%c",(*R).Rak[k].Pengarang[j]);
				}
				printf("...");
			}
			else{
				printf("%s",(*R).Rak[k].Pengarang);
			}
			koorxy(90,i+1);
			printf("%ld",(*R).Rak[k].Tahun);
			koorxy(109,i+1);
			printf("%d",(*R).Rak[k].Jumlah);
			k++;
			i++;
		}
		else{
			k++;
		}
	}
}
void ReStock(Rak *R){ //Restock jumlah buku dengan mencari ISBNnya
	long x;
	int y;
	printf("Ingin Re-Stock Buku dengan ISBN nomor berapa?\n");
	scanf("%ld",&x);
	int k=0;
	while(k!=(*R).Neff){
		if((*R).Rak[k].ISBN==x){
			printf("\nIngin Menambah Berapa buku?\n");
			scanf("%d",&y);
			(*R).Rak[k].Jumlah=(*R).Rak[k].Jumlah+y;
			break;
		}
		else{
			k++;
		}
	}
	if(k==(*R).Neff){
		printf("\nISBN tidak terdaftar!");
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////Keanggotaan///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MakeEmptyK(Anggota *A){
	(*A).Neff=0;
}
void InputAnggota(Anggota *A){
	Peminjam P;
	menu:
	MakePeminjam(&P);
	long ID;
	back:
	ID=rand() %102; //ID anggota dibuat random, dan dicek setiap buat apakah sudah ada, jika ada kembali random hingga tidak ada yang sama
	int i=0;
	//While untuk mengecek apakah ID yang dirandom ada yang sama di list anggota, jika sama, kembali ke <back:>
	while(i<(*A).Neff){
		if(ID==(*A).Daftar[i].ID){
			goto back;
		}
		else{
			i++;
		}
	}
	if(i==(*A).Neff){
		P.ID=ID;
	}
	int j=0;
	while(j<(*A).Neff){
		if(strcmp((*A).Daftar[j].NIM,P.NIM)==0){
			printf("\nNIM SUDAH TERDAFTAR!!");
			getch();
			goto menu;
		}
		else{
			j++;
		}
	}
	(*A).Daftar[(*A).Neff]=P;
	(*A).Neff++;
}
void DeleteAnggota(Anggota *A){ //Delete anggota berdasarkan indeks
    int i,j,k;
    printf("Masukkan indeks anggota : ");
    scanf("%d",&i);
    if((*A).Neff==0){
        printf("Daftar Anggota Kosong");
    }else{
    for(j=0;j<(*A).Neff;j++){
        if (i==j){
            for(k=j+1;k<(*A).Neff;k++){
                (*A).Daftar[k-1]=(*A).Daftar[k];
            }
            (*A).Neff=(*A).Neff-2;
            (*A).Neff++;
        }
    }
    }
}
void LihatAnggota(Anggota A){
	int i=0;
	int  j;
	system("cls");
	koorxy(0,0);
	printf("Index");
	koorxy(10,0);
	printf("ID Anggota");
	koorxy(30,0);
	printf("NIM");
	koorxy(50,0);
	printf("Nama Anggota");
	koorxy(70,0);
	printf("Jurusan");
	for(i=0;i<A.Neff;i++){
		koorxy(0,i+1);
		printf("%d",i);
		koorxy(10,i+1);
		printf("%ld",A.Daftar[i].ID);
		koorxy(30,i+1);
        printf("%s",A.Daftar[i].NIM);
		koorxy(50,i+1);
		if(A.Daftar[i].jumlahchar>20){
			for(j=0;j<=20;j++){
				printf("%c",A.Daftar[i].Nama);
			}
			printf("...");
		}
		else{
			printf("%s",A.Daftar[i].Nama);
		}
		koorxy(70,i+1);
        printf("%d",A.Daftar[i].Jurusan);
	}
	koorxy(100,0);
		printf("|INFO JURUSAN");
	koorxy(100,1);
		printf("|1 - Informatika");
	koorxy(100,2);
		printf("|2 - Matematika");
	koorxy(100,3);
		printf("|3 - Statistika");
	koorxy(100,4);
		printf("|4 - Biologi");
	koorxy(100,5);
		printf("|5 - Kimia");
	koorxy(100,6);
		printf("|6 - Fisika");
}
void LihatAnggotakei(Anggota A){ //lihat anggota dengan inputan ID
	long ID;
	int i=0;
	printf("Masukkan ID anggota: ");
	scanf("%ld",&ID);
	while(i<A.Neff){
		if(A.Daftar[i].ID==ID){
			printf("\n");
			ReadPeminjam(A.Daftar[i]);
			break;
		}
		else{
			i++;
		}
	}
	if(i==A.Neff){
		printf("\nID tidak ditemukan!!!");
	}
}
void SearchKodeJurusan(Anggota *A){
	int y;
	printf("\nMasukkan Kode jurusan yang ingin anda cari: ");
	scanf("%d",&y);
	int i=0;
	int j=0;
	int k=0;
	system("cls");
	koorxy(0,0);
	printf("Index");
	koorxy(10,0);
	printf("ID Anggota");
	koorxy(30,0);
	printf("NIM");
	koorxy(50,0);
	printf("Nama Anggota");
	koorxy(70,0);
	printf("Jurusan");
	while(k<(*A).Neff){
		if(y==(*A).Daftar[k].Jurusan){
			koorxy(0,i+1);
			printf("%d",k);
			koorxy(10,i+1);
			printf("%ld",(*A).Daftar[k].ID);
			koorxy(30,i+1);
			printf("%s",(*A).Daftar[k].NIM);
			koorxy(50,i+1);
			if((*A).Daftar[k].jumlahchar>20){
				for(j=0;j<=17;j++){
					printf("%c",(*A).Daftar[k].Nama[j]);
				}
				printf("...");
			}
			else{
				printf("%s",(*A).Daftar[k].Nama);
			}
			koorxy(70,i+1);
			printf("%d",(*A).Daftar[k].Jurusan);
			k++;
			i++;
		}
		else{
			k++;
		}
	}
	koorxy(100,0);
		printf("|INFO JURUSAN");
	koorxy(100,1);
		printf("|1 - Informatika");
	koorxy(100,2);
		printf("|2 - Matematika");
	koorxy(100,3);
		printf("|3 - Statistika");
	koorxy(100,4);
		printf("|4 - Biologi");
	koorxy(100,5);
		printf("|5 - Kimia");
	koorxy(100,6);
		printf("|6 - Fisika");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////Peminjaman///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MakePeminjaman(Peminjaman *A, Anggota *X, Rak *R, Tanggal *T){ //Parameter Tanggal T untuk menginput tanggal hari ini;
	char pil;
	long x;
	long y;
	int j;
	int k;
	//Membuat denda menjadi 0 dan Tanggal pengembalian menjadi NULL
	(*A).denda=0;
	(*A).T2.DD='\0';
	(*A).T2.MM='\0';
	(*A).T2.YY='\0';
	awal:
	fflush(stdin);
	printf("\nApakah Anda sudah terdaftar menjadi anggota (Y/N)?");
	scanf(" %c",&pil);
	switch(pil){
		case 'n':
		case 'N':
			printf("\nMohon Maaf, Anda Harus Mendaftar terlebih dahulu\n");
			getch();
			break;
		case 'y':
		case 'Y':
			j=0;
			printf("\nMasukkan ID Kenggotaan Anda: ");
			scanf("%ld",&y);
			while(j!=(*X).Neff){
				if((*X).Daftar[j].ID==y){
					(*A).P=(*X).Daftar[j];
					break;
				}
				else{
					j++;
				}
			}
			if (j==(*X).Neff && (*X).Daftar[j].ID!=y || y==0){
				printf("\nID tidak terdaftar");
				goto awal;
			}
			k=0;
			printf("\nISBN Buku: ");
			scanf("%d",&x);
			while(k!=(*R).Neff){
				if((*R).Rak[k].ISBN==x){
					if((*R).Rak[k].Jumlah>0){
						(*R).Rak[k].Jumlah--;
						(*A).B=(*R).Rak[k];
						break;
					}
					else{
						printf("\nJumlah Buku 0\n");
						goto awal;
					}
				}
				else{
					k++;
				}
			}
			if(k==(*R).Neff && (*R).Rak[k].ISBN!=x || x==0){
				printf("\nISBN tidak Terdaftar");
				goto awal;
			}
			(*A).T1=(*T); //Tidak mungkin menginput orang yang meminjam kemarin atau besok, karena saat meminjam langsung didaftarkan ke list peminjaman
			break;
		default:
			printf("\nInputan Salah\n");
			goto awal;
	}
}
void ReadPeminjaman(Peminjaman A,Tanggal T){
	printf("\n%d\t%s\t%lld\t",A.B.jumlahcharjudul,A.P.Nama,A.denda);
	ReadDate(T);
	ReadDate(A.T2);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////Tabel Peminjaman///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MakeEmptyTabelPeminjaman(TabelPeminjaman *A){
	(*A).Neff=0;
}
void InputPeminjaman(TabelPeminjaman *A, Anggota *B, Rak *R, Tanggal *T){
	Peminjaman X;
	long x;
	MakePeminjaman(&X,B,R,T);
	if(X.P.ID==0){
		exit;
	}
	else{
		back:
		x=rand() %102;
		int i=0;
		while(i<(*A).Neff){
			if(x==(*A).List[i].ID){
				goto back;
			}
			else{
				i++;
			}
		}
		if(i==(*A).Neff){
			X.ID=x;
		}
		(*A).List[(*A).Neff]=X;
		(*A).Neff++;
	}
}
void PrintTabel(TabelPeminjaman A, Tanggal T){
	int i=0;
	int j=0;
	int k;
	system("cls");
	koorxy(0,0);
	printf("ID Peminjaman");
	koorxy(20,0);
	printf("ID Peminjam");
	koorxy(40,0);
	printf("Judul Buku");
	koorxy(60,0);
	printf("Tanggal Peminjaman");
	koorxy(80,0);
	printf("Tanggal Pengembalian");
	koorxy(110,0);
	printf("Denda");
	for(i=0;i<A.Neff;i++){
		koorxy(0,i+1);
		printf("%ld",A.List[i].ID);
		koorxy(20,i+1);
		printf("%ld",A.List[i].P.ID);
		koorxy(40,i+1);
		if((A).List[i].B.jumlahcharjudul>11){
			for(j=0;j<=11;j++){
				printf("%c",(A).List[i].B.Judul[j]);
			}
			printf("...");
		}
		else{
			printf("%s",(A).List[i].B.Judul);
		}
		koorxy(60,i+1);
		ReadDate(A.List[i].T1);
		koorxy(80,i+1);
		ReadDate(A.List[i].T2);
		koorxy(110,i+1);
		printf("Rp%lld",A.List[i].denda);
	}
}
void InputPengembalian(TabelPeminjaman *A,Tanggal *T, Rak *R){
	//Mengimput T2
	//Jumlah buku pada rak bertambah lagi
	int i,k,j;
	long a;
	k=0;
	j=0;
	printf("\nMasukkan ID Peminjaman\n");
	scanf("%d",&i);
	while(j<(*A).Neff){
		if((*A).List[j].ID!=i){
			j++;
		}
		else{
			break;
		}
	}
	if(j==(*A).Neff){
		printf("ID Peminjaman Tidak Valid!");
		getch();
	}
	else{
		//Mengecek apakah buku sudah dikembalikan atau belum
		if(!IsDateValid((*A).List[j].T2.DD,(*A).List[j].T2.MM,(*A).List[j].T2.YY)){
			(*A).List[j].T2.DD=(*T).DD;
			(*A).List[j].T2.MM=(*T).MM;
			(*A).List[j].T2.YY=(*T).YY;
			a=(*A).List[j].B.ISBN;
			while(k!=(*R).Neff){
				if ((*R).Rak[k].ISBN==a){
					(*R).Rak[k].Jumlah++;
					break;
				}else{
					k++;
				}
			}
		}
		else{
			printf("Buku sudah dikembalikan");
			getch();
		}
	}
}
void DeletePeminjaman(TabelPeminjaman *A){
    int i,j,k;
    printf("Masukkan indeks Peminjam : ");
    scanf("%d",&i);
    if((*A).Neff==0){
        printf("Daftar Peminjam Kosong");
    }else{
	    for(j=0;j<(*A).Neff;j++){
	        if (i==j){
	            for(k=j+1;k<(*A).Neff;k++){
	                (*A).List[k-1]=(*A).List[k];
	            }
	            (*A).Neff=(*A).Neff-2;
	            (*A).Neff++;
	        }
	    }
    }
}
//Mem-filter peminjaman dengan bulan x dan tahun y
void SearchTanggalPeminjaman(TabelPeminjaman *A){
	Tanggal TT;
	int x,y;
	printf("Masukkan Bulan yang ingin anda cari: ");
	scanf("%d",&x);
	printf("Masukkan Tahun yang ingin anda cari: ");
	scanf("%d",&y);
	TT.MM=x;
	TT.YY=y;
	int i=0;
	int j=0;
	int k=0;
	system("cls");
	koorxy(0,0);
	printf("ID Peminjaman");
	koorxy(20,0);
	printf("ID Peminjam");
	koorxy(40,0);
	printf("ISBN Buku");
	koorxy(60,0);
	printf("Tanggal Peminjaman");
	koorxy(80,0);
	printf("Tanggal Pengembalian");
	koorxy(110,0);
	printf("Denda");
	while(k<(*A).Neff){
		if(TT.MM==(*A).List[k].T1.MM && TT.YY==(*A).List[k].T1.YY){
			koorxy(0,i+1);
			printf("%ld",(*A).List[k].ID);
			koorxy(20,i+1);
			printf("%ld",(*A).List[k].P.ID);
			koorxy(40,i+1);
			if((*A).List[k].B.jumlahcharjudul>11){
				for(j=0;j<=11;j++){
					printf("%c",(*A).List[k].B.Judul[j]);
				}
				printf("...");
			}
			else{
				printf("%s",(*A).List[k].B.Judul);
			}
			koorxy(60,i+1);
			ReadDate((*A).List[k].T1);
			koorxy(80,i+1);
			ReadDate((*A).List[k].T2);
			koorxy(110,i+1);
			printf("Rp%lld",(*A).List[k].denda);
			k++;
			i++;
		}
		else{
			k++;
		}
	}
}
//Lihat peminjaman dengan menggunakan ID peminjaman
void LihatPeminjamankei(TabelPeminjaman A){
	long ID;
	int i=0;
	printf("Masukkan ID Peminjaman: ");
	scanf("%ld",&ID);
	while(i<A.Neff){
		if(A.List[i].ID==ID){
			printf("\n");
			ReadBook(A.List[i].B);
			printf("\n");
			ReadPeminjam(A.List[i].P);
			break;
		}
		else{
			i++;
		}
	}
	if(i==A.Neff){
		printf("\nID tidak ditemukan!!!");
	}
}
