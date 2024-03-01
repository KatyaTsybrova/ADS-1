// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1) {
    return false;
  }
  for (uint64_t i = 2; i * i <= value; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  int count = 0;
  uint64_t num = 1;
  while (count < n) {
    num++;
    if (checkPrime(num)) {
      count++;
    }
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  while (true) {
    bool isPrime = true;
    value++;
    for (uint64_t i = 2; i * i <= value; i++) {
      if (value % i == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      return value;
    }
  }  
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t num = 2; num < hbound; ++num) {
    bool isPrime = true;
    for (uint64_t i = 2; i <= num / 2; ++i) {
      if (num % i == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      sum += sum;
    }
  }
  return sum;
}
