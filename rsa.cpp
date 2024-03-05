#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int modpow(int a, int b, int m) {
  int result = 1;
  while (b > 0) {
    if (b & 1) {
      result = (result * a) % m;
    }
    a = (a * a) % m;
    b >>= 1;
  }
  return result;
}

int main() {
  int p = 5;
  int q = 11;
  int n = p * q;
  int phiN = (p - 1) * (q - 1);
  int e = 2;
  while (e < phiN) {
    if (gcd(e, phiN) == 1  )
      break;
    else
      e++;
  }
  int d = 0;
  while ((d * e) % phiN != 1) {
    d++;
  }
  cout << "Public key: {" << e << ", " << n << "}" << endl;
  cout << "Private key: {" << d << ", " << n << "}" << endl;
  
  int m = 30;
  int c = modpow(m, e, n);
  int decrypted = modpow(c, d, n);
  cout << "Original message: " << m << endl;
  cout << "Encrypted message: " << c << endl;
  cout << "Decrypted message: " << decrypted << endl;
  
  return 0;
}
