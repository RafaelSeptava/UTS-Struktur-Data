Asesmen	Praktikum	Sub	CLO	3 Struktur	Data	Linear

Identitas Pengumpul

Nama: Rafael Putra Septava

NIM: 103122400015

Kelas: SE-08-01

1. Kode Program

Berikut adalah kode program untuk menunjukan jumlah data postingan menggunakan struktur data linked list.

(Silakan ganti bahasa dan kode di bawah ini sesuai tugas Anda)

```File: main.cpp
 * Author: [Nama Anda]
 * NIM: [NIM Anda]
 * Deskripsi: Program untuk menentukan apakah sebuah bilangan
 * yang diinput oleh user adalah ganjil atau genap.
 */

#include <iostream>

using namespace std;

// Fungsi untuk mengecek ganjil/genap
void cekGanjilGenap(int angka) {
    // Mengecek sisa bagi (modulus) dengan 2
    if (angka % 2 == 0) {
        cout << angka << " adalah bilangan GENAP." << endl;
    } else {
        cout << angka << " adalah bilangan GANJIL." << endl;
    }
}

int main() {
    int inputAngka;

    // Meminta input dari user
    cout << "===== Program Pengecek Ganjil/Genap =====" << endl;
    cout << "Masukkan sebuah bilangan bulat: ";
    cin >> inputAngka;

    // Memanggil fungsi pengecekan
    cekGanjilGenap(inputAngka);

    return 0;
}
```

2. Penjelasan Kode

Berikut adalah penjelasan alur logika dari kode program di atas:

Header & Namespace: Program mengimpor library iostream untuk operasi input/output (seperti cout dan cin) dan menggunakan std namespace.

Fungsi cekGanjilGenap(int angka):

Fungsi ini menerima satu parameter integer bernama angka.

Logika utamanya menggunakan operator modulus (%).

if (angka % 2 == 0): Jika sisa bagi angka dengan 2 adalah 0, maka bilangan tersebut adalah genap.

else: Jika sisa baginya bukan 0 (yaitu 1), maka bilangan tersebut adalah ganjil.

Fungsi ini akan langsung mencetak hasilnya ke konsol.

Fungsi main():

Ini adalah fungsi utama tempat program dieksekusi.

Mendeklarasikan variabel inputAngka untuk menyimpan data dari user.

Menampilkan judul program dan meminta user memasukkan sebuah bilangan.

cin >> inputAngka;: Menyimpan nilai yang diketik user ke dalam variabel inputAngka.

Memanggil fungsi cekGanjilGenap() dan mengirimkan inputAngka sebagai argumennya.

3. Output Program

Berikut adalah hasil eksekusi program (output) ketika dijalankan.
```
Contoh Output 1 (Input Bilangan Genap):

===== Program Pengecek Ganjil/Genap =====
Masukkan sebuah bilangan bulat: 42
42 adalah bilangan GENAP.


Contoh Output 2 (Input Bilangan Ganjil):

===== Program Pengecek Ganjil/Genap =====
Masukkan sebuah bilangan bulat: 77
77 adalah bilangan GANJIL.


(Tips: Anda juga bisa menyertakan screenshot/gambar output di bagian ini jika diperlukan, seperti ini:)
```

4. Penjelasan Lanjutan (Analisis Output)

Sesuai permintaan Anda ("Penjelasan Lagi"), bagian ini menganalisis mengapa output yang dihasilkan sudah benar:

Pada Output 1: User memasukkan 42. Ketika 42 dibagi 2, sisa baginya adalah 0 ($42 \div 2 = 21$ sisa $0$). Karena sisa baginya 0, kondisi if (angka % 2 == 0) terpenuhi (True), sehingga program mencetak "adalah bilangan GENAP".

Pada Output 2: User memasukkan 77. Ketika 77 dibagi 2, sisa baginya adalah 1 ($77 \div 2 = 38$ sisa $1$). Karena sisa baginya bukan 0, kondisi if tidak terpenuhi, dan program menjalankan blok else, sehingga mencetak "adalah bilangan GANJIL".

Kedua kasus uji (test case) tersebut menunjukkan bahwa logika operator modulus (%) telah diimplementasikan dengan benar untuk membedakan bilangan ganjil dan genap.

5. Kesimpulan

Berdasarkan implementasi dan pengujian kode di atas, dapat disimpulkan bahwa:

Konsep percabangan (selection) menggunakan if-else sangat fundamental untuk membuat program yang dapat mengambil keputusan berdasarkan kondisi tertentu.

Operator Aritmetika Modulus (%) adalah alat yang efektif untuk menentukan keterbagian, yang dalam kasus ini digunakan untuk memvalidasi apakah suatu bilangan ganjil atau genap berdasarkan sisa baginya dengan 2.

Program telah berhasil memenuhi spesifikasi tugas, yaitu menerima input dari user dan memberikan output yang benar sesuai dengan status ganjil/genap dari input tersebut.
