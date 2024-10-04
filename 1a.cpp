#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// Fungsi untuk menemukan LIS (Longest Increasing Subsequence)
vector<int> LIS(const vector<int> &arr, vector<int> &path, int val, int x, int n) {

// Jika mencapai akhir array, kembalikan path

    if (x == n) { // n itu array size
        return path;
    }
    

    // inisialisasi path terpanjang
    vector<int> maxPath = path; 
    

    // Iterasi indeks saat ini hingga akhir array
    for (int i = x; i < n; i++) {

        //Jika angka saat ini > sebelumnya
        if (arr[i] > val) {
            //Angka ditambahkan ke path
            path.push_back(arr[i]);

            // Mencari hasil LIS berikutnya
            vector<int> result = LIS(arr, path, arr[i], i + 1, n);
            
            // Bandingkan ukuran LIS hasil rekursif dengan LIS terpanjang
            if (result.size() > maxPath.size()) {
                maxPath = result;  // hasil -> LIS terpanjang
            }

            // Hapus elemen terakhir untuk mencoba LIS lain / backtrack
            path.pop_back();
        }
    }
    
    // Kembalikan LIS terpanjang
    return maxPath;
}

int main() {

    // Inisialisasi array sesuai soal
    vector<int> arr = {4, 1, 13, 7, 0, 2, 8, 11, 3}; 
    int n = arr.size(); // ukuran array

    // Inisialisasi path
    vector<int> path;
    path = LIS(arr, path, -1, 0, n); // panggil fungsi LIS

    // Cetak hasil LIS
    for (int i = 0; i < path.size(); i++) {
        printf("%d ", path[i]);
    }

    printf("\n");
    return 0;
}
