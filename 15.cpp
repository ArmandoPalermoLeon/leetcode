// The selling point here is to get we need to have a 2 pointer approach
// but that's hard because we're dealing with 3 variables, that complicates
// things. So O(n) is out of the question for the 2 pointer apprach, but a
// O(n^2) where we have fixed values. We know a+b+c=0, where a != b, a!=c, b!=c
// Therefore, let's have that a be a fixed value inside a for loop, let's set
// the 2 pointer approach to the b and c values

#include <algorithm>
#include <print>
#include <vector>
std::vector<std::vector<int>> threesum(std::vector<int> &nums) {
  std::vector<std::vector<int>> answer;
  std::sort(nums.begin(), nums.end());
  for (int i{0}; i < nums.size(); i++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    int left{i + 1};
    unsigned long right{nums.size() - 1};
    while (left < right) {
      int suma{nums[i] + nums[left] + nums[right]};
      if (suma > 0) {
        right--;
      } else if (suma < 0) {
        left++;
      } else {
        answer.push_back({nums[i], nums[left], nums[right]});
        while (left < right && nums[left] == nums[left + 1]) {
          left++;
        }
        while (left < right && nums[right] == nums[right - 1]) {
          right--;
        }
        left++;
        right--;
      }
    }
  }
  return answer;
}

int main() {
  std::vector<int> numbers = {-1, 0, 1, 2, -1, -4};
  std::println("{}", threesum(numbers));
}
