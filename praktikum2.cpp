#include <bits/stdc++.h>
using namespace std;


#define N 8 // Ukuran papan catur 8x8


// Fungsi untuk mengecek apakah koordinat (x, y) valid di papan catur
int isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}


// Fungsi untuk mencetak solusi atau langkah pergerakan kuda pada papan catur
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " "; // Menampilkan langkah pergerakan kuda
        cout << endl;
    }
}


// Fungsi rekursif untuk menyelesaikan permasalahan Knight Tour
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[], int yMove[])
{
    int k, next_x, next_y;
    if (movei == N * N) // Jika jumlah langkah mencapai ukuran papan catur (8x8)
        return 1; // Mengembalikan 1 menandakan perjalanan kuda selesai


    // Mencoba semua kemungkinan langkah kuda dari koordinat saat ini (x, y)
    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)) { // Jika langkah berikutnya valid
            sol[next_x][next_y] = movei; // Menandai langkah kuda pada koordinat berikutnya
            if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove) == 1)
                return 1; // Jika rekursi berhasil, kembalikan 1
            else
                sol[next_x][next_y] = -1; // Jika tidak, hapus langkah dan coba langkah lainnya (backtracking)
        }
    }
    return 0; // Kembalikan 0 menandakan tidak ada solusi yang memenuhi syarat
}


// Fungsi utama untuk menyelesaikan permasalahan Knight Tour
int solveKT()
{
    int sol[N][N];


    // Inisialisasi papan catur dengan nilai -1
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;


    // Array untuk kemungkinan langkah kuda
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };


    // Kuda berada pada koordinat awal (0, 0)
    sol[0][0] = 0;


    // Mulai dari koordinat (0, 0) dan jelajahi semua tur menggunakan solveKTUtil()
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
        cout << "Solusi tidak ada"; // Jika tidak ada solusi
        return 0;
    }
    else
        printSolution(sol); // Jika ada solusi, cetak solusinya


    return 1;
}


// Fungsi utama (main function)
int main()
{
    // Panggil fungsi untuk menyelesaikan permasalahan Knight Tour
    solveKT();
    return 0;
}
