#include <algorithm>
#include <print>
#include <vector>

int threeSumClosest(std::vector<int> &nums, int target) {
  std::sort(nums.begin(), nums.end());
  int temp{1000000};
  int temp1{0};

  for (int i{0}; i < nums.size(); i++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    int left{i + 1};
    unsigned long right{nums.size() - 1};

    while (left < right) {
      int suma{nums[i] + nums[left] + nums[right]};
      int diferencia{std::abs(suma - target)};

      if (diferencia < temp) {
        temp = diferencia;
        temp1 = suma;
      }

      if (suma > target) {
        right--;
      } else if (suma < target) {
        left++;
      } else {
        return temp1;
      }
    }
  }
  return temp1;
}

int main() {
  std::vector<int> numbers = {4, 0, 5, -5, 3, 3, 0, -4, -5};
  int target = 1;
  int result = threeSumClosest(numbers, target);
  std::println("El resultado más cercano a {} es: {}", target, result);

  return 0;
}
