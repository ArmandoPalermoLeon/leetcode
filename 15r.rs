fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut answer = Vec::new();

    // 1. Ordenar es necesario para el algoritmo de dos punteros
    nums.sort();

    let n = nums.len();
    if n < 3 {
        return answer;
    }

    // 2. Iteramos usando un rango. n-2 porque necesitamos espacio para left y right
    for i in 0..n - 2 {
        // Evitar duplicados para el primer elemento
        if i > 0 && nums[i] == nums[i - 1] {
            continue;
        }

        let mut left = i + 1;
        let mut right = n - 1;

        while left < right {
            let suma = nums[i] + nums[left] + nums[right];

            if suma > 0 {
                right -= 1;
            } else if suma < 0 {
                left += 1;
            } else {
                // Encontrado un triplete
                answer.push(vec![nums[i], nums[left], nums[right]]);

                // Evitar duplicados para el segundo y tercer elemento
                while left < right && nums[left] == nums[left + 1] {
                    left += 1;
                }
                while left < right && nums[right] == nums[right - 1] {
                    right -= 1;
                }

                left += 1;
                right -= 1;
            }
        }
    }
    answer
}

fn main() {
    let numbers = vec![-1, 0, 1, 2, -1, -4];
    let result = three_sum(numbers);

    // Rust imprime vectores con el formateador de debug {:?}
    println!("{:?}", result);
}
