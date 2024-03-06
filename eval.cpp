#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

char matrix[6][6] = {
  {'a', 'b', 'c', 'd', 'e', 'f'},
  {'g', 'h', 'i', 'j', 'k', 'l'},
  {'m', 'n', 'o', 'p', 'q', 'r'},
  {'s', 't', 'u', 'v', 'w', 'x'},
  {'y', 'z', '0', '1', '2', '3'},
  {'4', '5', '6', '7', '8', '9'}
};

vector<int> findPosition(char c) {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (matrix[i][j] == tolower(c)) {
        return {i, j};
      }
    }
  }
  return {-1, -1}; // Error handling for invalid characters
}

string encrypt(string plain_text) {
  string cipher_text;
  for (int i = 0; i < plain_text.length(); i += 2) {
    char c1, c2;
    if (i + 1 < plain_text.length()) {
      c1 = plain_text[i];
      c2 = plain_text[i + 1];
    } else {
      c1 = plain_text[i];
      c2 = 'x'; // Add a padding character if odd length
    }

    if (c1 == c2) {
      c2 = 'x'; // Handle repeated characters
    }

    vector<int> pos1 = findPosition(c1);
    vector<int> pos2 = findPosition(c2);

    if (pos1[0] == pos2[0]) { // Same row
      cipher_text += matrix[(pos1[0] + 1) % 6][pos1[1]];
      cipher_text += matrix[pos2[0]][(pos2[1] + 1) % 6];
    } else if (pos1[1] == pos2[1]) { // Same column
      cipher_text += matrix[pos1[0]][(pos1[1] + 1) % 6];
      cipher_text += matrix[(pos2[0] + 1) % 6][pos2[1]];
    } else {
      cipher_text += matrix[pos1[0]][pos2[1]];
      cipher_text += matrix[pos2[0]][pos1[1]];
    }
  }
  return cipher_text;
}

int main() {
  string plain_text;
  cout << "Enter the plain text: ";
  getline(cin, plain_text);

  string cipher_text = encrypt(plain_text);
  cout << "Cipher text: " << cipher_text << endl;

  return 0;
}
