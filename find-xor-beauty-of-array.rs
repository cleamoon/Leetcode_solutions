impl Solution {
    pub fn xor_beauty(nums: Vec<i32>) -> i32 {
        let mut ans = nums[0];
        for i in 1..nums.len() {
            ans ^= nums[i];
        }
        ans
    }
}
