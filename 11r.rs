use std::cmp;

/// Brute force approach - O(n^2)
fn brute_force(height: &[i32]) -> i64 {
    let mut result: i64 = 0;
    let n = height.len();

    for i in 0..n {
        for j in (i + 1)..n {
            let base = (j - i) as i64;
            let hei = cmp::min(height[i], height[j]) as i64;
            let area = base * hei;

            if area > result {
                result = area;
            }
        }
    }
    result
}

/// Two pointers approach - O(n)
/// The optimized solution that passes the time constraints.
fn two_pointers(height: &[i32]) -> i64 {
    let mut left = 0;
    let mut right = height.len() - 1;
    let mut result: i64 = 0;

    while left < right {
        let base = (right - left) as i64;
        let hei = cmp::min(height[left], height[right]) as i64;
        let area = base * hei;

        if area > result {
            result = area;
        }

        if height[left] < height[right] {
            left += 1;
        } else {
            right -= 1;
        }
    }
    result
}

fn main() {
    let height = vec![1, 8, 6, 2, 5, 4, 8, 3, 7];

    println!("Max Area (Two Pointers): {}", two_pointers(&height));
    println!("Max Area (Brute Force): {}", brute_force(&height));
}
