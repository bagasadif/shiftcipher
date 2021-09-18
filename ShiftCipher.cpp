/*
Nama            : Bagas Adi Firdaus
NPM             : 140810190037
Kelas           : A
Tanggal Buat    : 18 September 2021
Deskripsi       : Program Enskripsi dan Deksripsi Shift Cipher
*/

#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
using std::cin;
using std::cout;
using std::string;


string enskripsi(string input, int kunci) {
string output = "";
for (int i = 0; i < input.size(); i++) {
  char encrypted;
  if (input[i] > 96) {
    encrypted = ((input[i] - 97 + kunci) % 26) + 97;
  }
  if (input[i] < 96) {
    encrypted = ((input[i] - 65 + kunci) % 26) + 65;
  }
  if (input[i] == ' ')
    encrypted = ' ';
  output.push_back(encrypted);
}
return output;
}

string deskripsi(string input, int kunci) {
  string output = "";
  for (int i = 0; i < input.size(); i++) {
    char decrypted;
    if (input[i] > 96) {
      int x = input[i] - 97 - kunci;
      if ((x > 0) || ((x % 26) == 0))
        decrypted = (x % 26) + 97;
      else
        decrypted = 26 - (abs(x) % 26) + 97;
    }
    if (input[i] < 96) {
      int x = input[i] - 65 - kunci;
      if ((x > 0) || ((x % 26) == 0))
        decrypted = (x % 26) + 65;
      else
        decrypted = 26 - (abs(x) % 26) + 65;
    }
    if (input[i] == ' ')
      decrypted = ' ';
    output.push_back(decrypted);
  }
  return output;
}

main() {
  while (1) {
    // string input("Bagas Adi Firdaus");
    string input;
    int kunci;
    int pilihan = 3;
    char loop = 'n';

    cout << "\n==== Program Shift Cipher ====\n"
         << "\n"
         << "Pilih yang ingin dilakukan:\n"
         << "1. Enskripsi\n"
         << "2. Deskripsi\n"
         << "\nPilihan : ";
    while (pilihan != 1 && pilihan != 2) {
      cin >> pilihan;
      if (pilihan != 1 && pilihan != 2)
        cout << "Masukkan angka 1 atau 2 : ";
    }

    cout << "\nInput : ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(cin, input);
    // cout << input << '\n';

    cout << "Kunci : ";
    cin >> kunci;

    if (pilihan == 1)
      cout << "\nHasil Enskripsi : " << enskripsi(input, kunci);
    else
      cout << "\nHasil Deskripsi : " << deskripsi(input, kunci);

    while (loop != 'Y' && loop != 'y') {
      cout << "\n\nApakah akan diulang (Y/N) : ";
      cin >> loop;
      if (loop == 'N' || loop == 'n') {
        cout << "\n==== Program Berakhir ====";
        return 0;
      }
      if (loop != 'Y' & loop != 'y') {
        cout << "Input salah, masukkan 'Y' atau 'N' \n";
      }
    }
  }
}