// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) {
   if (value <= 1) return false;
   else if (value == 2 || value == 3) return true;
   if (value % 2 == 0) return false;
   for (uint64_t i = 3; i * i <= value; i += 2)
      if (value % i == 0) return false;
   return true;
}

uint64_t nPrime(uint64_t n) {
   if (n == 0) return 0;
   uint64_t cnt = 0, s = 1;
   while (cnt < n) {
      s++;
      if (checkPrime(s)) cnt++;
   }
   return s;
}

uint64_t nextPrime(uint64_t value) {
   uint64_t k = value + 1;
   if (k % 2 == 0 && k != 2) ++k;
   while (!checkPrime(k))
      k += (k == 2) ? 1 : 2;
   return k;
}

uint64_t sumPrime(uint64_t hbound) {
   if (hbound <= 2) return 0;
   uint64_t a = 2;
   for (uint64_t i = 3; i < hbound; i += 2)
      if (checkPrime(i)) a += i;
   return a;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
   if (hbound - lbound < 2) return 0;
   uint64_t cnt_pair = 0;
   for (uint64_t b = lbound; b < hbound - 2; ++b)
      if (checkPrime(b) && checkPrime(b + 2)) ++cnt_pair;
   return cnt_pair;
}
