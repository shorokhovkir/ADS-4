// Copyright 2021 NNTU-CS
#include <alg.h>
#include <iostream>
#include <cstdint>

int countPairs1(int *arr, int len, int val) {
  int cnt = 0;
  int i = 0;
  while (i < len) {
    int j = i + 1;
    while (j < len) {
      if ((arr[i] + arr[j]) == val) {
        cnt++;
      }
      j++;
    }
    i++;
  }
  return cnt;
}

int countPairs2(int *arr, int len, int val) {
  int cnt = 0;
  int end = len - 1;
  do {
    end = end - 1;
  } while (arr[end] > val);
  int i = 0;
  while (i < end) {
    int j = end;
    while (j > i) {
      if (arr[j] + arr[i] == val) {
        cnt++;
      }
      j--;
    }
    i++;
  }
  return cnt;
}

int cbinsearch(int *arr, int size, int val) {
  int cnt = 0;
  int left = 0;
  int right = size - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2;
    if (arr[middle] == val) {
      cnt++;
      int i = middle + 1;
      while (i < size && arr[i] == val) {
        cnt++;
        i++;
      }
      i = middle - 1;
      while (i >= 0 && arr[i] == val) {
        cnt++;
        i--;
      }
      return cnt;
    } else if (arr[middle] < val) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return cnt;
}

int countPairs3(int *arr, int len, int val) {
  int cnt = 0;
  int i = 0;
  while (i < len) {
    int num = val - arr[i];
    cnt = cnt + cbinsearch(&arr[i + 1], len - i - 1, num);
    i++;
  }
  return cnt;
}
