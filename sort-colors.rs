impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let mut start = 0;
        let mut pivot = 0;
        let mut end = nums.len() - 1;
        while pivot <= end {
            if nums[pivot] == 0 {
                nums.swap(start, pivot);
                start += 1;
                pivot += 1;
            } else if nums[pivot] == 2 {
                nums.swap(pivot, end);
                end -= 1;
            } else {
                pivot += 1;
            }
        }
    }
}
