#include <iostream>
#include <string>

using namespace std;

string encrypt(string plainText, string key) {
  string encryptedText = "";
  int keyLength = key.length();

  for (int i = 0; i < plainText.length(); i++) {
    encryptedText += plainText[i] ^ key[i % keyLength];
  }

  return encryptedText;
}

string decrypt(string encryptedText, string key) {
  string decryptedText = "";
  int keyLength = key.length();

  for (int i = 0; i < encryptedText.length(); i++) {
    decryptedText += encryptedText[i] ^ key[i % keyLength];
  }

  return decryptedText;
}

int main() {
  string plainText, key;

  cout << "Enter plain text: ";
  getline(cin, plainText);

  cout << "Enter key: ";
  getline(cin, key);

  string encryptedText = encrypt(plainText, key);
  string decryptedText = decrypt(encryptedText, key);

  cout << "Encrypted text: " << encryptedText << endl;
  cout << "Decrypted text: " << decryptedText << endl;

  return 0;
}
