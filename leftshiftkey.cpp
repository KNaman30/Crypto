#include <iostream>

int main() {
   int numericKey;

   std::cout << "Enter the numeric key: ";
   std::cin >> numericKey;

   // Isolate the last digit
   int lastDigit = numericKey % 10;

   // Perform a logical left shift by 1 bit
   lastDigit = lastDigit << 1;

   // Preserve the other digits and replace the last digit with the shifted value
   int shiftedKey = (numericKey / 10) * 10 + lastDigit;

   std::cout << "Shifted key: " << shiftedKey << std::endl;

   return 0;
}
