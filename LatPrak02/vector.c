/* Nama         : Gregorius Jovan Kresnadi */
/* NIM          : 13518135 */
/* Tanggal      : 05-09-2019 */
/* Program      : vector.c */
/* Deskripsi    : Driver ADT Vector */

#include <stdio.h>
#include <math.h>
#include "vector.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
VECTOR MakeVector(float x, float y) {
   // KAMUS LOKAL
   VECTOR V1;
   // ALGORITMA
   AbsisComponent(V1) = x;
   OrdinatComponent(V1) = y;
   return V1;
}
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v) {
	// ALGORITMA
	printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
}
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v) {
	// ALGORITMA
	return sqrtf(AbsisComponent(v) * AbsisComponent(v) + OrdinatComponent(v) * OrdinatComponent(v));
}
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */

VECTOR Add(VECTOR a, VECTOR b) {
	// ALGORITMA
   return MakeVector(AbsisComponent(a) + AbsisComponent(b), OrdinatComponent(a) + OrdinatComponent(b));
}
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */

VECTOR Substract(VECTOR a, VECTOR b) {
   // ALGORITMA
   return MakeVector(AbsisComponent(a) - AbsisComponent(b), OrdinatComponent(a) - OrdinatComponent(b));
}
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */

float Dot(VECTOR a, VECTOR b) {
	// ALGORITMA
	return AbsisComponent(a) * AbsisComponent(b) + OrdinatComponent(a) * OrdinatComponent(b);
}
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */

VECTOR Multiply(VECTOR v, float s) {
   // ALGORITMA
   return MakeVector(AbsisComponent(v) * s , OrdinatComponent(v) * s);
}
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * a.x, s * a.y) */
