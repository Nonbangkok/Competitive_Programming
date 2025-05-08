#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "penguin.h"
#include "penguin.cpp"

int coooo = 0;
std::vector<std::pair<int, int>> vpii;
bool ask(int l1, int r1, int l2, int r2) {
  coooo++;
  for (auto a : vpii)
    if ((l1 <= a.first && a.first <= r1 && l2 <= a.second && a.second <= r2) ||
        (l1 <= a.second && a.second <= r1 && l2 <= a.first && a.first <= r2))
      return true;
  return false;
}

signed main(int argc, char** argv) {
  int n, m;
  std::cin >> n >> m;

  vpii.resize(m);
  for (auto& a : vpii) std::cin >> a.first >> a.second;

  auto res = find_couples(n);

  auto normalize = [&](std::vector<std::pair<int, int>>& foo) {
    for (auto& a : foo)
      if (a.first > a.second) std::swap(a.first, a.second);
    std::sort(foo.begin(), foo.end());
  };

  normalize(vpii), normalize(res);

  if (vpii == res) {
    std::cout << "Correct. Used " << coooo << " queries." << std::endl;
  } else {
    std::cout << "Incorrect" << std::endl;
  }
}
