// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < (len - 1); i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j]) == value) {
        cnt++;
      }
    }
  }
  return cnt;
}
int countPairs2(int *arr, int len, int value) {
  int cnt = 0, k = 0, j = 0;
  for (int i = 0; i < (len - 1); i++) {
    if ((arr[i] + arr[i + 1]) >= value) {
      k = i;
      break;
    }
  }
  for (int i = 0; i < (len - 1); i++) {
    if (arr[i] > value) {
      break;
    }
    if (k <= i) {
      j = i + 1;
    }
    else {
      j = k;
    }
    for (; j < len; j++) {
      if ((arr[i] + arr[j]) == value) {
        cnt++;
      }
      if (arr[j] > value) {
        break;
      }
    }
  }
  return cnt;
}
int countPairs3(int *arr, int len, int value) {
  int cnt = 0, k = 0, min = 0, max = 0;
  for (int i = 0; i < (len - 1); i++) {
    if (arr[i] > value) {
      break;
    }
    min = i;
    max = len - 1;
    while (min < max) {
      k = min + ((max - min) / 2);
      if (min == max) {
        break;
      }
      if ((arr[i] + arr[k]) > value) {
        for (int n = (k - 1); n >= min; n--) {
          max = n + 1;
          if (arr[k] != arr[n]) {
            break;
          }
        }
        if (max - min == 1) {
          break;
        }
      }
      if ((arr[i] + arr[k]) < value) {
        for (int n = (k + 1); n <= max; n++) {
          min = n - 1;
          if (arr[k] != arr[n]) {
            break;
          }
        }
        if (max - min == 1) {
          break;
        }
      }
      if ((arr[i] + arr[k]) == value) {
        int t = max;
        for (int n = (k + 1); n <= t; n++) {
          max = n - 1;
          if (arr[k] != arr[n]) {
            break;
          }
        }
        t = min;
        for (int n = (k - 1); n >= t; n--) {
          min = n + 1;
          if (arr[k] != arr[n]) {
            break;
          }
        }
        break;
      }
    }
    for (int j = min; j <= max; j++) {
      if (((arr[i] + arr[j]) == value) && (i != j)) {
        cnt++;
      }
    }
  }
  return cnt;
}
