#include <bits/stdc++.h>
#include "combo.h"

const int MAX_N = 2000;
const int MAX_NUM_MOVES = 8000;

int N;
std::string S;

int num_moves;

int press(std::string p) {
  if (++num_moves > MAX_NUM_MOVES) {
    printf("too many moves");
  }
  int len = p.length();
  if (len > 4 * N) {
    printf("invalid press");
  }
  for (int i = 0; i < len; ++i) {
    if (p[i] != 'A' && p[i] != 'B' && p[i] != 'X' && p[i] != 'Y') {
      printf("invalid press");
    }
  }
  int coins = 0;
  for (int i = 0, j = 0; i < len; ++i) {
    if (j < N && S[j] == p[i]) {
      ++j;
    } else if (S[0] == p[i]) {
      j = 1;
    } else {
      j = 0;
    }
    coins = std::max(coins, j);
  }
  return coins;
}

int main() {
  char buffer[MAX_N + 1];
  scanf("%s", buffer);
  S = buffer;
  N = S.length();

  num_moves = 0;
  std::string answer = guess_sequence(N);
  if (answer != S) {
    printf("wrong guess");
    exit(0);
  }
  printf("Accepted: %d\n", num_moves);
  return 0;
}
