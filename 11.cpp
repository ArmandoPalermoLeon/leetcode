#include <algorithm>
#include <print>
#include <vector>
// The problem ask us to find the maximum area, thats the thing we need to
// understand It could be deceiving to think of it as water, we just need the
// biggest possible area within the columns (represented by the values of the
// vector) For this, the first brute force idea is to treat it in an O(n^2)
// solution, this is correct. but gives a time limit exceeding, for the amount
// of calculations it needs to be done

int brute_force(std::vector<int> &height) {
  int64_t base{0};
  int64_t hei{0};
  int64_t result{0};
  int64_t area{0};
  for (int i{0}; i < height.size(); i++) {
    for (int j{i + 1}; j < height.size() - 1; j++) {
      base = j - i;
      hei = std::min(height[i], height[j]);
      area = base * hei;
      if (area > result) {
        result = area;
      }
    }
  }
  return result;
}

int two_pointers(std::vector<int> &height) {
  int64_t left{0};
  unsigned long right{height.size() - 1};
  int64_t result{0};
  int64_t area{0};
  while (left < right) {
    area = std::min(height[left], height[right]) * (right - left);
    if (area > result) {
      result = area;
    }
    if (height[left] < height[right]) {
      left++;
    } else {
      right--;
    }
  }
  return result;
}

int main() {
  std::vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
  std::println("{}", two_pointers(height));
}
// The optimal way of thinking about this is Two Pointers
//
