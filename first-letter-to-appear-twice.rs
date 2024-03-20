impl Solution {
    pub fn repeated_character(s: String) -> char {
        let mut arr: [u8; 26] = [0; 26];
        for (i, c) in s.chars().enumerate() {
            let id = c as usize - 'a' as usize;
            arr[id] += 1;
            if (arr[id] > 1) {
                return c;
            }
        }
        return 'a';
    }
}
