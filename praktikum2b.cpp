#include <bits/stdc++.h>
using namespace std;

const int N = 8;
int board[N][N];   // Papan Catur 8 x 8
int moveCount = 0; // Langkah yang diambil

// Fungsi untuk mendapatkan langkah-langkah posisi
vector<pair<int, int>> validMoves(int row, int col)
{

    vector<pair<int, int>> moves; // Inisialisasi langkah
    int rowMoves[] = {-2, -1, 1, 2, 2, 1, -1, -2}; // Pergeseran baris untuk 8 langkah
    // misal -2 = geser 2 ke atas
    int colMoves[] = {1, 2, 2, 1, -1, -2, -2, -1}; // Pergerseran kolom untuk 8 langkah
    // misal 1 = geser 1 ke kanan

    // Iterasi langkah
    for (int i = 0; i < 8; i++)
    {
        // posisi baru
        int newRow = row + rowMoves[i];
        int newCol = col + colMoves[i];

        // Cek apakah langkah valid (ada di papan dan belum dikunjungi)
        if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N && board[newRow][newCol] == 0)
        {
            moves.push_back(make_pair(newRow, newCol)); // menambahkan langkah
        }
    }
    return moves; // mengembalikan langkah valid
}

// Fungsi menyelesaikan Knights Tour 
bool solve(int row, int col, int moveNum)
{

    board[row][col] = moveNum; // Menandai langkah (angka) yang diambil pada papan
    moveCount++;

    // Jika semua langkah telah diambil, permainan selesai
    if (moveNum == N * N)
    {
        return true;
    }

    // Mendapatkan langkah-langkah valid
    vector<pair<int, int>> moves = validMoves(row, col);

    // Iterasi untuk setiap langkah valid
    for (pair<int, int> move : moves)
    {
        int newRow = move.first;
        int newCol = move.second;

        // Rekursif untuk mencoba langkah selanjutnya
        if (solve(newRow, newCol, moveNum + 1))
        {
            return true;
        }
    }

    // Jika langkah tidak berhasil, kembalikan keadaan papan sebelumnya / backtrack
    board[row][col] = 0;
    moveCount--;
    return false;
}

int main()
{
    int startRow = 0, startCol = 0; // Posisi awal 0,0
    solve(startRow, startCol, 1); // Solve dari posisi awal

    cout << "Number of moves: " << moveCount << endl; // Menampilkan jumlah total langkah yang diambil
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " "; // Menampilkan langkah-langkah pada papan N X N
        }
        cout << endl;
    }
    return 0;
}