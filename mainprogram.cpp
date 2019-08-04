#include "pst.c"

int main(){
	Rak R;
	int pil,pil1;
	Anggota A;
	Peminjaman B;
	TabelPeminjaman C;
	Tanggal T,T1,T2;
	MakeDate(&T);
	MakeEmptyK(&A);
	MakeEmpty(&R);
	MakeEmptyTabelPeminjaman(&C);
	menu:
		system("cls");
	    	printf(" \n");
	    	printf("  +==========================================================+\n");
		    printf("  |                    T U G A S   A K H I R                 |\n");
			printf("  |                 S T R U K T U R   D A T A                |\n"); 
	    	printf("  |               A D T   P E R P U S T A K A A N            |\n");
		    printf("  |          Dosen Pengampu : Rismiyati, B. Eng., M.Cs.      |\n");
	    	printf("  +==========================================================+\n");
	    	printf("  |                         ");ReadDate(T);printf("                       |\n");
	    	printf("  +--------------------Tentukan Pilihan Anda-----------------+\n");
	    	printf("  |                                                          |\n");
	   		printf("  | (1) Next Day                                             |\n");
	   		printf("  | (2) Next N Day                                           |\n");
	   		printf("  | (3) Menu Rak                                             |\n");
	    	printf("  | (4) Menu Keanggotaan                                     |\n");
	    	printf("  | (5) Menu Peminjaman                                      |\n");	    	
	    	printf("  | (0) Keluar                                               |\n");
	    	printf("  |----------------------------------------------------------|\n");
	    	printf("  +==========================================================+\n");
	   		printf("\n\n   Masukkan menu yang Anda pilih: ");
			scanf("%d", &pil);
			printf("\n");
			switch(pil){
				case 1:
					system("cls");
					NextDay(&T,&C);
					goto menu;
				case 2:
					system("cls");
					NextNDay(&T,&C);
					goto menu;
				case 3:
				menu1:
					system("cls");
						printf("   +=====================================+\n");
	    				printf("   |              Menu Rak               |\n");
						printf("   +=====================================+\n");
						printf("   |                                     |\n");
						printf("   +--------Tentukan Pilihan Anda--------+\n");
						printf("   |                                     |\n");
						printf("   | (1) Lihat Rak                       |\n");
						printf("   | (2) Input Buku                      |\n");
						printf("   | (3) Hapus Buku                      |\n");
						printf("   | (4) Cari Buku ke-i                  |\n");
						printf("   | (5) Cari Buku Tahun pembuatan ke-i  |\n");
						printf("   | (6) Re-Stock Buku                   |\n");
						printf("   | (0) Kembali                         |\n");
	    				printf("   |-------------------------------------|\n");
	    				printf("   +=====================================+\n");
						printf("\n\n   Masukkan nomor pilihan menu rak: ");
						scanf("%d", &pil1);
						switch(pil1){
							case 1:
								system("cls");
								LihatRak(R);
								getch();
								goto menu1;
							case 2:
								system("cls");
								InputBook(&R);
								getch();
								goto menu1;
							case 3:
								system("cls");
								DeleteRak(&R);
								getch();
								goto menu1;
							case 4:
								system("cls");
								LihatRakKei(R);
								getch();
								goto menu1;
							case 5:
								system("cls");
								SearchTahunPembuatan(&R);
								getch();
								goto menu1;
							case 6:
								system("cls");
								ReStock(&R);
								getch();
								goto menu1;
							case 0:
								goto menu;
							default:
								system("cls");
								printf("Inputan salah");
								getch();
								goto menu;
						break;
						}
					printf("\n\n\n\npress any key to continue . . .");
					getch();
					goto menu;
				case 4:
				menu2:
					system("cls");
						printf("   +=======================================+\n");
						printf("   |           Menu Keanggotaan            |\n");
						printf("   +=======================================+\n");
						printf("   |                                       |\n");
						printf("   +--------Tentukan Pilihan Anda----------+\n");
						printf("   |                                       |\n");
						printf("   | (1) Lihat List Anggota                |\n");
						printf("   | (2) Input Anggota                     |\n");
						printf("   | (3) Hapus Anggota                     |\n");
						printf("   | (4) Cari Anggota berdasarkan ID       |\n");
						printf("   | (5) Cari Anggota berdasarkan Jurusan  |\n");
						printf("   | (0) Kembali                           |\n");
						printf("   |---------------------------------------|\n");
						printf("   +=======================================+\n");
						printf("\n\n   Masukkan nomor pilihan menu keanggotaan: ");
						scanf("%d", &pil1);
						switch(pil1){
							case 1:
								system("cls");
								LihatAnggota(A);
								getch();
								goto menu2;
							case 2:
								system("cls");
								InputAnggota(&A);
								getch();
								goto menu2;
							case 3:
								system("cls");
								DeleteAnggota(&A);
								getch();
								goto menu2;
							case 4:
								system("cls");
								LihatAnggotakei(A);
								getch();
								goto menu2;
							case 5:
								system("cls");
								SearchKodeJurusan(&A);
								getch();
								goto menu2;
							case 0:
								goto menu;
							default:
								printf("Inputan salah");
								getch();
								goto menu;
						break;
						}
					printf("\n\n\n\npress any key to continue . . .");
					getch();
					goto menu;
				case 5:
				menu3:
					system("cls");
						printf("   +=====================================+\n");
						printf("   |           Menu Peminjaman           |\n");
						printf("   +=====================================+\n");
						printf("   |                                     |\n");
						printf("   +--------Tentukan Pilihan Anda--------+\n");
						printf("   |                                     |\n");
						printf("   | (1) Lihat List Peminjaman           |\n");
						printf("   | (2) Make Peminjaman                 |\n");
						printf("   | (3) Hapus Peminjaman ke-i           |\n");
						printf("   | (4) Pengembalian                    |\n");
						printf("   | (5) Cari Tanggal Peminjaman         |\n");
						printf("   | (6) Lihat Peminjaman ke-i           |\n");
						printf("   | (0) Kembali                         |\n");
						printf("   |-------------------------------------|\n");
						printf("   +=====================================+\n");
						printf("\n\n   Masukkan nomor pilihan menu peminjaman: ");
						scanf("%d", &pil1);
						switch(pil1){
							case 1:
								system("cls");
								PrintTabel(C,T);
								getch();
								goto menu3;
							case 2:
								system("cls");
								InputPeminjaman(&C,&A,&R,&T);
								getch();
								goto menu3;
							case 3:
								system("cls");
								DeletePeminjaman(&C);
								getch();
								goto menu3;
							case 4:
								system("cls");
								InputPengembalian(&C, &T, &R);
								getch();
								goto menu3;
							case 5:
								system("cls");
								SearchTanggalPeminjaman(&C);
								getch();
								getch();
								goto menu3;
							case 6:
								system("cls");
								LihatPeminjamankei(C);
								getch();
								goto menu3;
							case 0:
								goto menu;
							default:
								printf("Inputan salah");
								getch();
								goto menu;	
						break;
						}
					printf("\n\n\n\npress any key to continue . . .");
					getch();
					goto menu;
				case 0: 
					system("cls");
					printf("   +=====================================================================+\n");
					printf("   |                           T H A N K   Y O U                         |\n");
					printf("   +=====================================================================+\n");
		    		printf("   | Anggota Kelompok  : 1. Gizka Olivia Septika Putri (24060117120043)  |\n");
		    		printf("   |                     2. Ananda Prabu Tritya Vijaya (24060117130048)  |\n");
		    		printf("   |                     3. Angga Dharma Iswara        (24060117130051)  |\n");
		    		printf("   |                     4. Taufiqurrahman Al Hammamy  (24060117130056)  |\n");
		    		printf("   |                     5. Agni Wiguna                (24060117130067)  |\n");
		    		printf("   |                     6. Wahyu Nugroho              (24060117130073)  |\n");
		    		printf("   |                     7. Prayoga Dwi Saputro        (24060117130077)  |\n");
		    		printf("   |                     8. Gagah Aryasamba            (24060117140049)  |\n");
		    		printf("   |                     9. Achmad Zakiyyudin          (24060117140051)  |\n");
		    		printf("   |                    10. Almaas Retiani Amita       (24060117140059)  |\n");
		    		printf("   |                    11. Muhammad Syahrul Wirawan   (24060117140090)  |\n");
	    			printf("   |---------------------------------------------------------------------|\n");
	    			printf("   +=====================================================================+\n");
		        	printf("\n\n\n\npress any key to exit . . .");
		        	getch();
        		break;
        		default:
					printf("Inputan salah");getch();goto menu;
				}
}
