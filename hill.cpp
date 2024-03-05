#include <cmath>
#include <iostream>
using namespace std;

int modInverse(int a, int m) {
  a = a % m;
  for (int x = 1; x < m; x++) {
    if ((a * x) % m == 1) {
      return x;
    }
  }
  return -1;
}

void getKeyMatrix(string key, int keyMatrix[][3]) {
  int k = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      keyMatrix[i][j] = (key[k]) % 65;
      k++;
    }
  }
}

void encrypt(int cipherMatrix[3][1], int keyMatrix[3][3], int messageVector[3][1]) {
  int x, i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 1; j++) {
      cipherMatrix[i][j] = 0;

      for (x = 0; x < 3; x++) {
        cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
      }

      cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
    }
  }
}

void decrypt(int cipherMatrix[][1], int keyMatrix[][3],
             int messageVector[][1]) {
  int keyInverse[3][3];
  int det = 0;

  // Calculate the determinant of the key matrix
  for (int i = 0; i < 3; i++) {
    det += (keyMatrix[0][i] *
            (keyMatrix[1][(i + 1) % 3] * keyMatrix[2][(i + 2) % 3] -
             keyMatrix[1][(i + 2) % 3] * keyMatrix[2][(i + 1) % 3]));
  }

  det = (det % 26 + 26) % 26; // Ensure the determinant is positive

  int detInverse = modInverse(det, 26);

  // Calculate the adjugate of the key matrix
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      keyInverse[i][j] = (((keyMatrix[(j + 1) % 3][(i + 1) % 3] *
                            keyMatrix[(j + 2) % 3][(i + 2) % 3]) -
                           (keyMatrix[(j + 1) % 3][(i + 2) % 3] *
                            keyMatrix[(j + 2) % 3][(i + 1) % 3])) *
                          detInverse) %
                         26;
      keyInverse[i][j] =
          (keyInverse[i][j] + 26) % 26; // Ensure the result is positive
    }
  }

  // Decrypt the message vector
  int x, i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 1; j++) {
      messageVector[i][j] = 0;

      for (x = 0; x < 3; x++) {
        messageVector[i][j] += keyInverse[i][x] * cipherMatrix[x][j];
      }

      messageVector[i][j] =
          (messageVector[i][j] % 26 + 26) % 26; // Ensure the result is positive
    }
  }
}

void HillCipherEncrypt(string message, string key) {
  int keyMatrix[3][3];
  getKeyMatrix(key, keyMatrix);

  int messageVector[3][1];
  for (int i = 0; i < 3; i++) {
    messageVector[i][0] = (message[i]) % 65;
  }

  int cipherMatrix[3][1];
  encrypt(cipherMatrix, keyMatrix, messageVector);

  string ciphertext;
  for (int i = 0; i < 3; i++) {
    ciphertext += cipherMatrix[i][0] + 65;
  }
  cout << "Cipher Text: " << ciphertext << endl;

  decrypt(cipherMatrix, keyMatrix, messageVector);
  string decryptedMessage;
  for (int i = 0; i < 3; i++) {
    decryptedMessage += messageVector[i][0] + 65;
  }
  cout << "Decrypted Text: " << decryptedMessage << endl;
}

int main() {
  cout << "Enter the message" << endl;
  string msg;
  getline(cin, msg);

  cout << "Enter the key" << endl;
  string key;
  getline(cin, key);

  HillCipherEncrypt(msg, key);

  return 0;
}
