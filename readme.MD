# Tugas Kecil 1 IF2211 Strategi Algoritma

## Deskripsi
_Word Search Puzzle_ merupakan sebuah permainan yang bertujuan untuk menemukan berbagai kata di dalam rangkaian huruf yang disusun secara acak. Program dalam repository ini bertujuan untuk menyelesaikan _Word Search Puzzle_ dengan metode bruteforce. Program menerima masukan berupa nama file yang berisikan Puzzle beserta kata kuncinya. Apabila file tidak ditemukan, pengguna diharapkan memasukkan kembali nama file yang benar. Apabila file ditemukan, program akan mencari kemunculan dari semua kata kunci yang dimasukkan. Hasil akhir dari program berupa Puzzle yang telah ditandai kemunculan setiap kata dengan berbagai warna.

## Fitur
- Menerima input nama file untuk melakukan test dan meminta input nama file kembali apabila nama file sebelumnya tidak ditemukan
- Melakukan pencarian untuk setiap kata kunci dan menampilkan output berupa puzzle yang telah ditandai dengan pewarnaan untuk setiap kata
- Menampilkan total perbandingan dan lama waktu pencarian untuk setiap test

## Persyaratan
Program _Word Search Puzzle_ ini dibuat dengan bahasa C++ dan compiler **GNU C++ (G++) versi 8.1.0**. Program ini dibuat dan diuji dalam _Operating System_ Windows 11. Apabila ingin menjalankan program ini di environment lain, hendaknya melakukan _compile_ ulang pada program `main.cpp`

## Cara Menjalankan Program
Sebelum menjalankan program, _clone repository_ ini ke dalam folder lokal.

Apabila berada di lingkungan yang berbeda dengan pembuatan program ini, saya sarankan untuk melakukan `compile` ulang pada program `main.cpp`, yaitu dengan perintah `g++ -o bin/main.exe src/main.cpp`

### Menjalankan executable file
1. Buka folder di dalam terminal, bisa di dalam VS Code atau terminal seperti shell dan cmd
2. Masuk ke dalam folder bin dengan perintah `cd bin`
3. Jalankan file `main.exe` dengan perintah `main.exe`
4. Masukkan nama file dengan didahului `../test/`, contohnya `../test/1.txt`


### Status 
Program ini telah selesai dibuat dan dikembangkan untuk memenuhi spesifikasi Tugas Kecil 1 IF2211 Strategi Algoritma

| Poin | Ya | Tidak |
|---|---|---|
| Program berhasil dikompilasi tanpa kesalahan (no syntax error) | v | |
| Program berhasil running | v | |
| Program dapat membaca file masukan dan menuliskan luaran | v | |
| Program berhasil menemukan semua kata di dalam puzzle | v | |

## Pembuat
Nama   : Hafidz Nur Rahman Ghozali\
NIM    : 13520117\
Kelas  : K03