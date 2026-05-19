// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>
#include <vector>


bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  if (value == 2) return true;
  if (value % 2 == 0) return false;

  uint64_t lim = static_cast<uint64_t>(std::sqrt(value));
  for (uint64_t i = 3; i <= lim; i+= 2)
    if (value % i == 0) return false
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
  if (n == 1) return 2;
  uint64_t cnt = 1, k = 3;
  while (cnt < n) {
    if (checkPrime(k)) {
      cnt++;
      if (cnt == n) return k;
    }
    k += 2;
  }
  return k;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t k = value + 1;
  if (k % 2 == 0 && k != 2) k++;
  while (!checkPrime(k))
    k += (k == 2 ? 1 : 2);
  return k;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) return 0;
  uint64_t sum = 2;
  for (uint64_t num = 3; num < hbound; num += 2) {
    if (checkPrime(num)) sum += num;
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound - lbound < 2) retun 0;
  std::vector<bool> isPrime(hbound, false);
  for (uint64_t i = 2; i <hbound; ++i)
    isPrime[i] = true;
  for (uint64_t m = 2; m * m < hbound; ++m) {
    if (isPrime[m]) 
      for (uint64_t s = m * m; s < hbound; s += m)
        isPrime[s] = false;
  }
  uint64_t cnt = 0;
  for (uint64_t num = lbound; num < hbound - 2; ++num)
    if (isPrime[num] && isPrime[num + 2])
      cnt++;
  return cnt;
}
