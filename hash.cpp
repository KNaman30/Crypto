#include <iostream>
#include <string>
using namespace std;

// Basic custom hash function
unsigned int customHash(const std::string &input) {
  unsigned int hash = 0;
  for (char c : input) {
    hash =(hash * 31) + static_cast<unsigned int>(c); // A simple mixing function
  }
  return hash;
}

int main() {
  string input = "Hello, World!";
  unsigned int hash = customHash(input);

  cout << "Input: " << input << endl;
  cout << "Hash Code: " << hash << endl;

  return 0;
}
