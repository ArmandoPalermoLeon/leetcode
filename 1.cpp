class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> mapa; // Guardamos {valor: índice}

    for (int i = 0; i < nums.size(); i++) {
      int complemento = target - nums[i];

      if (mapa.count(complemento)) {
        return {mapa[complemento], i};
      }

      mapa[nums[i]] = i;
    }

    return {};
  }
};
