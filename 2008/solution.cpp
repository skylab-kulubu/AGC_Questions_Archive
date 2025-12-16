#include <bits/stdc++.h>

using namespace std;

struct CDO {
  vector<uint64_t> mbs;
  bool firstUsed; // Is once spending is paid or not?
  uint64_t once; // Once spending
};

/**
 * @brief Calculates value of MBS
 *
 * @param uint64_t
 * @param uint64_t
 * @param double
 * @return uint64_t
 */
uint64_t calculate_mbs(uint64_t value, uint64_t maturity, double chance) {
  return floor(value * ((double) maturity / 12.0) * chance);
}

/**
 * @brief Takes input and calculating MBS values
 *
 * @return pair<vector<CDO>, uint64_t> - MBS values, total money
 */
void take_input(vector<CDO>& cdos, uint64_t& money) {
  uint64_t n;
  cin >> n >> money;

  money *= 1000; // $M => $K
  cdos.resize(n);

  for (uint64_t i = 0; i < n; ++i) {
    CDO& cdo = cdos[i];
    uint64_t k;
    cin >> k >> cdo.once;
    cdo.firstUsed = false;

    cdo.mbs.resize(k);

    for (uint64_t j = 0; j < k; ++j) {
      uint64_t value, maturity;
      double chance;
      cin >> value >> maturity >> chance;
      cdo.mbs[j] = calculate_mbs(value, maturity, chance);
    }
  }
}

/**
 * @brief Calculates buyable maximum MBS count
 *
 * @param vector<CDO>
 * @param uint64_t&
 * @return pair<double, uint64_t> - remaining money, maximum buyable MBS count
 */
pair<double, uint64_t> find_count_of_mbs(vector<CDO> cdos, uint64_t& money) {
  for (auto& cdo : cdos) {
    sort(cdo.mbs.begin(), cdo.mbs.end(), greater<uint64_t>());
    cdo.mbs.back() += cdo.once;
  }

  uint64_t count = 0;

  while (money != 0) {
    CDO *selected = nullptr;
    uint64_t min_value = ULONG_MAX;

    for (auto& cdo : cdos) {
      if (!cdo.mbs.empty()) {
        uint64_t value = cdo.mbs.back();

        if (!cdo.firstUsed && cdo.mbs.size() > 2) {
          value += cdo.mbs[cdo.mbs.size() - 2];
        }

        if (min_value > value) {
          selected = &cdo;
          min_value = value;
        }
      }
    }

    if (selected == nullptr) break;
    const uint64_t spending = selected->mbs.back();

    if (money < spending) {
      break;
    }

    money -= spending;
    selected->mbs.pop_back();
    selected->firstUsed = true;
    count += 1;
  }

  // For $K => $M
  return make_pair((double) money / 1000, count);
}

int main() {
  vector<CDO> cdos;
  uint64_t money;
  take_input(cdos, money);

  auto [remaining_money, count] = find_count_of_mbs(cdos, money);

  cout << remaining_money << " " << count << endl;
  return 0;
}
