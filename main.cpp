#include <iomanip>
#include <iostream>
#include <string>

using std::boolalpha;
using std::cout;
using std::max;
using std::string;

void print(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int factorial(int n) {
  if (n == 1) {
    return 1;
  }
  return factorial(n - 1) * n;
}

void printTriangle(int level) {
  if (level == 0) {
    return;
  }

  for (int i = 0; i < level; i++) {
    cout << " * ";
  }
  cout << "\n";

  printTriangle(level - 1);
}

void printUpperTriangle(int level) {
  if (level == 0) {
    return;
  }

  printUpperTriangle(level - 1);

  for (int i = 0; i < level; i++) {
    cout << " * ";
  }
  cout << "\n";
}

void print3Plus1Sequence(int n) {
  cout << n << " ";

  if (n == 1) {
    return;
  }

  return n % 2 == 0 ? print3Plus1Sequence(n / 2) : print3Plus1Sequence(3 * n + 1);
}

int myPow(int value, int pow) {
  if (pow == 0) {
    return 1;
  }

  return myPow(value, pow - 1) * value;
}

int arrMax(int arr[], int len) {
  if (len == 1) {
    return arr[0];
  }

  int subResult = arrMax(arr, len - 1);

  return max(subResult, arr[len - 1]);
}

int arrSum(int arr[], int len) {
  if (len == 1) {
    return arr[0];
  }

  int subResult = arrSum(arr, len - 1);

  return (subResult + arr[len - 1]);
}

double arrAverage(int arr[], int len) {
  if (len == 1) {
    return arr[0];
  }

  double subResult = arrAverage(arr, len - 1);
  subResult *= len - 1;

  return (subResult + arr[len - 1]) / len;
}

void arrIncByIndex(int arr[], int len) {
  if (len == 1) {
    return;
  }

  arrIncByIndex(arr, len - 1);
  cout << arr[len - 1] + len - 1 << " ";
}

int arrAcc(int arr[], int len) {
  if (len == 1) {
    return arr[0];
  }

  int subResult = arrAcc(arr, len - 1);
  return subResult + arr[len - 1];
}

// 1, 2, 3, 7, 4, 5
void leftMax(int arr[], int len) {
  if (len == 1) {
    return;
  }

  leftMax(arr, len - 1);
  arr[len - 1] = max(arr[len - 1], arr[len - 2]);
}

void rightMaxV1(int arr[], int len, int startPosition = 0) {
  if (startPosition == len - 1) return;

  rightMaxV1(arr, len, startPosition + 1);
  arr[startPosition] = max(arr[startPosition], arr[startPosition + 1]);
}

void rightMaxV2(int arr[], int len) {
  if (len == 1) return;

  rightMaxV2(arr + 1, len - 1);  // arr+1 is the a new array shifted. E.g. { 1, 8, 2, 10, 3 } => {8, 2, 10, 3 }
  arr[0] = max(arr[0], arr[1]);  // Then we only need to think about arr (0)
}

int suffixSum(int arr[], int len, int limit) {
  if (limit == 0) {
    return 0;
  }

  int subResult = suffixSum(arr, len - 1, limit - 1);

  return subResult + arr[len - 1];
}

int prefixSumV1(int arr[], int len, int limit) {
  if (limit == 0) {
    return 0;
  }

  int subResult = prefixSumV1(arr, len, limit - 1);

  return subResult + arr[limit - 1];
}

int prefixSumV2(int arr[], int len, int limit) {
  if (limit == 0) return 0;

  int subResult = prefixSumV2(arr + 1, len, limit - 1);

  return arr[0] + subResult;
}

bool isPalindromeV1(int arr[], int start, int end) {
  if (start >= end) {
    return true;
  }

  if (arr[start] != arr[end]) {
    return false;
  }

  return isPalindromeV1(arr, start + 1, end - 1);
}

bool isPalindromeV2(int arr[], int end) {
  if (end <= 0) {
    return true;
  }

  if (arr[0] != arr[end]) {
    return false;
  }

  return isPalindromeV2(arr + 1, end - 2);
}

bool isPrefix(string main, string prefix, int startPosition = 0) {
  if (startPosition == prefix.size()) {
    return true;
  }

  if (main[startPosition] != prefix[startPosition]) {
    return false;
  }

  return isPrefix(main, prefix, startPosition + 1);
}

// 123456
void doSomething(int n) {
  if (n) {
    cout << n % 10 << " ";  // 6 5 4 3 2 1
    doSomething(n / 10);
  }
}

// 123456
void doSomething2(int n) {
  if (n) {
    doSomething2(n / 10);
    cout << n % 10 << " ";  // 1 2 3 4 5 6
  }
}

bool isPrime(int num, int currentTestNum = 3) {
  if (num == 2) return true;

  if (num <= 1 || num % 2 == 0) return false;

  if (num % currentTestNum == 0) return false;

  if (num == currentTestNum) return true;

  return isPrime(num, currentTestNum + 1);
}

int countPrimes(int start, int end) {
  if (start > end) return 0;

  int result = countPrimes(start + 1, end);

  if (isPrime(start)) result += 1;

  return result;
}

int main() {
  // printTriangle(5);

  // printUpperTriangle(5);

  // print3Plus1Sequence(5);

  // cout << myPow(7, 3);

  int arr[] = {1, 8, 2, 8, 3};

  // cout << arrMax(arr, 5);

  // cout << arrSum(arr, 5);

  // cout << arrAverage(arr, 5);

  // arrIncByIndex(arr, 5);

  // leftMax(arr, 5);

  // rightMaxV1(arr, 5);

  // rightMaxV2(arr, 5);

  // cout << suffixSum(arr, 5, 3);

  // cout << prefixSumV2(arr, 5, 3);

  // cout << boolalpha << isPalindromeV1(arr, 0, 4);

  // cout << boolalpha << isPrefix("abcdefg", "abc");

  // arrAcc(arr, 5);

  // doSomething(123456);

  // cout << countPrimes(10, 200);

  // print(arr, 5);

  return 0;
}