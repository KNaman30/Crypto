#include <iostream>
#include <string.h>
#include <bitset>

using namespace std;

string encryptMessage(string msg) {
  for (int i = 0; msg[i] != '\0'; i++) {
    if (msg[i] >= 'a' && msg[i] <= 'z') {
      msg[i] = msg[i] + 3;
      if (msg[i] > 'z') {
        msg[i] = msg[i]%26 +'a';
      }        
      bitset<8> binary(msg[i]);
      cout << binary << " ";
    }

    else if (msg[i] >= 'A' && msg[i] <= 'Z') {
      msg[i] = msg[i] + 3;
      if (msg[i] > 'Z') {
        msg[i] = msg[i]%26 + 'A';
      }        
      bitset<8> binary(msg[i]);
      cout << binary << " ";
    }
  }
  cout<<endl;
  return msg;
}

string decryptMessage(string msg) {
  for (int i = 0; msg[i] != '\0'; i++) {

    if (msg[i] >= 'a' && msg[i] <= 'z') {
      msg[i] = msg[i] - 3;
      if (msg[i] < 'a') {
        msg[i] = msg[i]%26 +'a';
      }        
      bitset<8> binary(msg[i]);
      cout << binary << " ";
    }

    else if (msg[i] >= 'A' && msg[i] <= 'Z') {
      msg[i] = msg[i] - 3;
      if (msg[i] < 'A') {
        msg[i] = msg[i]%26 + 'A';
      }        
      bitset<8> binary(msg[i]);
      cout << binary << " ";
    }
  }
  cout<<endl;
  return msg;
}

int main() {
  cout << "Enter the message" << endl;
  char msg[100];
  cin.getline(msg, 100);
  
  cout<<endl;
  string cipherText = encryptMessage(msg);
  cout << "Encrypted Message is : " << cipherText << endl;
  string originalText = decryptMessage(cipherText);
  cout << "Decrypted Message is: " << originalText << endl;
}
