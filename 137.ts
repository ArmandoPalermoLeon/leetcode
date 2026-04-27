function twoSum(numbers: number[], target: number): number[] {
  let i: number = 0;
  let k: number = numbers.length - 1;
  let suma: number = 0;
  while (i != k) {
    suma = numbers[i] + numbers[k];
    if (suma > target) {
      k--;
    }
    if (suma < target) {
      i++;
    }
    if (suma === target) {
      return [i + 1, k + 1];
    }
  }
  return;
};
