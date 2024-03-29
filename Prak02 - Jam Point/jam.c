/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 29-08-2019 */
/* Program      : jam.c */
/* Deskripsi    : Definisi ADT Jam */

#include "jam.h"
#include <stdio.h>

/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S) {
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    if ( H>=0 &&  H<=23 && M>=0 && M<=59 && S>=0 && S<=59) 
    {return true;} else {return false;}
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS) {
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
    // KAMUS LOKAL
    JAM J1;
    //ALGORITMA
    if (IsJAMValid(HH,MM,SS)) {
        J1.HH = HH;
        J1.MM = MM;
        J1.SS = SS;
        return J1;
    }
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J) {
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
    // KAMUS LOKAL
    int hh, mm, ss;
    boolean valid;
    valid = false;
    // ALGORITMA
    do {
        scanf("%d %d %d", &hh, &mm, &ss);
        if (IsJAMValid(hh,mm,ss)) {
            valid = true;
            *J = MakeJAM(hh,mm,ss);
        } else {
            valid = false;
            printf("Jam tidak valid\n");
        }
    } while (!valid);
}

void TulisJAM (JAM J) {
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */
    printf("%d:%d:%d",J.HH,J.MM,J.SS);
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J) {
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
    // ALGORITMA
    return(3600*J.HH + 60*J.MM + J.SS);
}

JAM DetikToJAM (long N) {
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
    // KAMUS LOKAL
    int hh,mm,ss;
    JAM J2;
    while (N<0) {
        N += 86400;
    }
    N = N % 86400;
    // ALOGRITMA
    hh = N / 3600;
    mm = (N % 3600) / 60;
    ss = (N % 3600) % 60;
    J2 = MakeJAM(hh,mm,ss);
    return(J2);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2) {
/* Mengirimkan true jika J1=J2, false jika tidak */
    // ALGORITMA
    if(J1.HH == J2.HH && J1.MM == J2.MM && J1.SS == J2.SS)
    {return(true);} else {return(false);}
}

boolean JNEQ (JAM J1, JAM J2) {
/* Mengirimkan true jika J1 tidak sama dengan J2 */
    // ALGORITMA
    if(J1.HH != J2.HH || J1.MM != J2.MM || J1.SS != J2.SS)
    {return(true);} else {return(false);}
}

boolean JLT (JAM J1, JAM J2) {
/* Mengirimkan true jika J1<J2, false jika tidak */
    // KAMUS LOKAL
    long jam1 = JAMToDetik(J1);
    long jam2 = JAMToDetik(J2);
    // ALGORITMA
    if (jam1<jam2) {return (true);}
    else {return (false);}

}

boolean JGT (JAM J1, JAM J2) {
/* Mengirimkan true jika J1>J2, false jika tidak */
        // KAMUS LOKAL
    long jam1 = JAMToDetik(J1);
    long jam2 = JAMToDetik(J2);
    // ALGORITMA
    if (jam1>jam2) {return (true);}
    else {return (false);}

}

/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J) {
/* Mengirim 1 detik setelah J dalam bentuk JAM */
    // KAMUS LOKAL
    long s = JAMToDetik(J);
    // ALGORITMA
    s += 1;
    return(DetikToJAM(s));
}

JAM NextNDetik (JAM J, int N) {
/* Mengirim N detik setelah J dalam bentuk JAM */
    // KAMUS LOKAL
    long s = JAMToDetik(J);
    // ALGORITMA
    s += N;
    return(DetikToJAM(s));
}

JAM PrevDetik (JAM J) {
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
    // KAMUS LOKAL
    long s = JAMToDetik(J);
    // ALGORITMA
    s -= 1;
    return(DetikToJAM(s));
}

JAM PrevNDetik (JAM J, int N) {
/* Mengirim N detik sebelum J dalam bentuk JAM */
    // KAMUS LOKAL
    long s = JAMToDetik(J);
    // ALGORITMA
    s -= N;
    return(DetikToJAM(s));
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh) {
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
    // KAMUS LOKAL
    long x = JAMToDetik(JAw);
    long y = JAMToDetik(JAkh);
    // ALGORITMA
    if (x>y) {
        y += 86400;
    }
    return(y-x);
}