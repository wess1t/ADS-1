// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  bool result = true;
  if (value <= 1) return false;
  else if (value <= 3) return true;
  for (uint64_t i = 2; i < value; i++){
    if (value % 2 == 0){
      result = false;
      break;
    }
  }
  if (result == true) return true;
  else return false;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0, a = 1;
  while (count < a) {
    a++;
    if(checkPrime(a)) count++;
  }
  return a;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t k = value + 1;
  if (k % 2 == 0 && k != 2) ++k;
  while (!chekPrime(k))
    k += (k == 2) ? 1 : 2;
  return k;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t s = 2;
  for (uint64_t i = 3; i < hbound; i += 2)
    if (chekPrime(s)) s += i;
  return s;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t cnt_pair = 0;
  for (uint64_t i = lbound; i < hbound - 2; ++i)
    if (chekPrime(i) && chekPrime(i + 2)) ++cnt_pair;
  return cnt_pair;
}
