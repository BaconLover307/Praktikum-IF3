/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 11-09-2019 */
/* Program      : arraydin.c */
/* Deskripsi    : Definisi ADT Array Dinamis */

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel) {
    // ALGORITMA
    if (maxel >= 0) {
        TI(*T) = (int *)malloc((maxel + 1) * sizeof(int));
        Neff(*T) = 0;
        MaxEl(*T) = maxel + 1;
    }
}
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */

void Dealokasi(TabInt *T) {
    free(TI(*T));
}
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T) {
    return T.Neff;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxElement(TabInt T) {
    return MaxEl(T);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T) {
    return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */

IdxType GetLastIdx(TabInt T) {
    return Neff(T);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i) {
    return ((i>=GetFirstIdx(T)) && (i<=MaxElement(T)));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean IsIdxEff(TabInt T, IdxType i) {
    return ((i>=GetFirstIdx(T)) && (i<=GetLastIdx(T)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T) {
    return(NbElmt(T)==0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T) {
    return(NbElmt(T)==MaxElement(T));
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T) {
    // KAMUS LOKAL
    int n, i;
    boolean valid = false;
    // ALGORITMA
    do {
        scanf("%d", &n);
        if (n >= 0 && n <= MaxElement(*T)) {
            valid = true;
        }
    } while (valid == false);

    if (n == 0) {
        Dealokasi(T);
    } else {
        (*T).Neff = n;
        for (i = 1; i <= n; i++) {
            scanf("%d", &(*T).TI[i]);
        }
    }
}
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */

void TulisIsiTab(TabInt T) {
    // KAMUS LOKAL
    int i = 1; //counter
    // ALGORITMA
    printf("[");
    while (i <= T.Neff) {
        printf("%d", T.TI[i]);
        if (i != T.Neff) {
            printf(",");
        }
        i += 1;
    }
    printf("]");
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus) {
    // KAMUS LOKAL
    TabInt Thasil;
    int i; //counter
    MakeEmpty(&Thasil,MaxEl(T1));
    // ALGORITMA
    if (plus) {
        for (i = 1; i <= T1.Neff; i++) {
            Thasil.TI[i] = T1.TI[i] + T2.TI[i];
        }
        Thasil.Neff = T1.Neff;
        return Thasil;
    } else {
        for (i = 1; i <= T1.Neff; i++) {
            Thasil.TI[i] = T1.TI[i] - T2.TI[i];
        }
        Thasil.Neff = T1.Neff;
        return Thasil;
    }
}
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2) {
    // KAMUS LOKAL
    IdxType i = GetFirstIdx(T1);
    IdxType j = GetLastIdx(T1);
    boolean eq = true;
    // ALGORITMA
    if ((T1.Neff == T2.Neff) && (T1.Neff == 0)) {
        eq = true;
    } else if (T1.Neff == T2.Neff) {
        while ((i <= j) && (eq == true)) {
            if (Elmt(T1, i) != Elmt(T2, i)) {
                eq = false;
                i++;
            } else {i++;}
        }
    } else {eq = false;}
    return eq;
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */


/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X) {
    // KAMUS
    IdxType i; // Counter
    // ALGORITMA
    if (IsEmpty(T)) {
        return IdxUndef;
    } else {
        i = IdxMin;
        while ((Elmt(T, i) != X) && (i <= Neff(T))) {
            if (Elmt(T, i) != X) {i++;}
        }
        if (i > Neff(T)) {
            return IdxUndef;
        } else {
            return i;
        }
    }
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */

boolean SearchB(TabInt T, ElType X) {
    // KAMUS LOKAL
    boolean Found = false; // Inisialisasi
    IdxType i=GetFirstIdx(T);
    // ALGORITMA
    if (IsEmpty(T)) {Found = false;} else {
        while (!Found && i<=GetLastIdx(T)) {
            if (Elmt(T, i) == X) {
                Found = true;
            }
            else {i++;}
        }
    }
    return Found;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */


/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min) {
    // KAMUS LOKAL
    ElType maks; // Temporary maximum value
    ElType mins; // Temporary minimum value
    IdxType i; // Counter
    // ALGORITMA
    maks = T.TI[1];
    mins = T.TI[1];
    if (NbElmt(T) > 1) {
        for (i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++) {
            if (maks < Elmt(T, i)) {maks = Elmt(T, i);}
            if (mins > Elmt(T, i)) {mins = Elmt(T, i);}
        }
    }
    *Max = maks;
    *Min = mins;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */


/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout) {
    // KAMUS LOKAL
    IdxType i;
    ElType isi;

    // ALGORITMA
    if(!IsEmpty(Tin)) {
        MakeEmpty(Tout,MaxEl(Tin));
        for (i=GetFirstIdx(Tin); i<=GetLastIdx(Tin); i++) {
            Elmt(*Tout,i) = Elmt(Tin,i);
        }
    }
    Neff(*Tout) = Neff(Tin);
}
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */

ElType SumTab(TabInt T) {
    // KAMUS
    int hasil = 0; // Stores summed value
    int i; // Counter
    // ALGORITMA
    if (NbElmt(T)==0) {
        hasil = 0;
    } else {
        for (i=1;i<=GetLastIdx(T);i++) {
            hasil += Elmt(T,i);
        }
    }
    return hasil;
}
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */

int CountX(TabInt T, ElType X) {
    // KAMUS
    int i; // Iterator
    int n = 0; // Counter
    // ALGORITMA
    if (NbElmt(T)==0) {
        n = 0;
    } else {
        for (i=1;i<=GetLastIdx(T);i++) {
            if (Elmt(T,i)==X) {n++;}
        }
    }
    return n;   
}
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */

boolean IsAllGenap(TabInt T) {
    // KAMUS
    boolean genap = true; // Validator
    int i; // Iterator
    // ALGORITMA
    if (NbElmt(T)==0) {
        genap == false;
    } else {
        for (i=1;i<=GetLastIdx(T);i++) {
            if ((Elmt(T,i)%2) == 1) {genap = false;}
        }
    }
    return genap;   
}
/* Menghasilkan true jika semua elemen T genap. T boleh kosong */

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc) {
    // KAMUS LOKAL
    IdxType i,IMax,IMin; // Index untuk transversal
    IdxType Pass;   // Tahapan pengurutan
    ElType Temp;    // Memorasi untu pertukaran harga
    IdxType FirstIdx = GetFirstIdx(*T);
    IdxType LastIdx = GetLastIdx(*T);

    // ALGORITMA
    if (asc) {
        if ((*T).Neff > 1) {
            for (Pass=FirstIdx;Pass<LastIdx;Pass++) {
                IMax = Pass;
                for (i = Pass+1; i<=LastIdx; i++) {
                    if (Elmt(*T,IMax) < Elmt(*T,i)) {
                        IMax = i;
                    }
                }
                Temp = Elmt(*T, Pass);
                Elmt(*T, Pass) = Elmt(*T, IMax);
                Elmt(*T, IMax) = Temp;
            }
        }
    } else {
        if ((*T).Neff > 1) {
            for (Pass=FirstIdx;Pass<LastIdx;Pass++) {
                IMin = Pass;
                for (i = Pass+1; i<=LastIdx; i++) {
                    if (Elmt(*T,IMin) > Elmt(*T,i)) {
                        IMin = i;
                    }
                }
                Temp = Elmt(*T, Pass);
                Elmt(*T, Pass) = Elmt(*T, IMin);
                Elmt(*T, IMin) = Temp;
            }
        }
    }    
}
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X) {
    // ALGORITMA
    Elmt(*T,(*T).Neff+1) = X;
    (*T).Neff++;
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X) {
    // ALGORITMA
    (*X) = Elmt(*T,GetLastIdx(*T));
    (*T).Neff--;
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num);
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTab(TabInt *T, int num);
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTab(TabInt *T);
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */