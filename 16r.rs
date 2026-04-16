fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32 {
    let mut nums = nums;
    nums.sort();

    let mut temp = 1000000;
    let mut temp1 = 0;

    for i in 0..nums.len() {
        if i > 0 && nums[i] == nums[i - 1] {
            continue;
        }

        let mut left = i + 1;
        let mut right = nums.len() - 1;

        while left < right {
            let suma = nums[i] + nums[left] + nums[right];
            let diferencia = (suma - target).abs();

            if diferencia < temp {
                temp = diferencia;
                temp1 = suma;
            }

            if suma > target {
                right -= 1;
            } else if suma < target {
                left += 1;
            } else {
                return temp1;
            }
        }
    }

    temp1
}

fn main() {
    let numbers = vec![4, 0, 5, -5, 3, 3, 0, -4, -5];
    let target = 1;

    let result = three_sum_closest(numbers, target);
    println!("El resultado más cercano a {} es: {}", target, result);
}
