impl Solution {
    pub fn multiply(num1: String, num2: String) -> String {
        if num1 == "0" || num2 == "0" {
            return "0".to_string();
        }

        use std::collections::BTreeMap;

        let mut res = vec![] as Vec<char>;
        let mut num1: Vec<char> = num1.chars().collect::<Vec<char>>();
        num1.reverse();
        let mut num2: Vec<char> = num2.chars().collect::<Vec<char>>();
        num2.reverse();
        let mut carries: BTreeMap<u8, u8> = BTreeMap::new();
        for i in 0..num1.len() {
            for j in 0..num2.len() {
                let product = (num1[i] as u8 - '0' as u8) * (num2[j] as u8 - '0' as u8);
                let p1 = (i + j) as u8;
                let p2 = (i + j + 1) as u8;
                let mut sum = 0;
                match carries.get_mut(&p1) {
                    Some(value) => {
                        sum = product + *value;
                        *value = sum % 10;
                    }
                    None => {
                        sum = product;
                        carries.insert(p1, sum % 10);
                    }
                }
                match carries.get_mut(&p2) {
                    Some(value) => {
                        *value += sum / 10;
                    }
                    None => {
                        carries.insert(p2, sum / 10);
                    }
                }
            }
        }
        for i in 0..carries.len() {
            let idx = carries.len() as u8 - i as u8 - 1;
            let digit = *carries.get(&idx as &u8).unwrap() as u8 + '0' as u8;
            if (i == 0 && digit == '0' as u8) {
                continue;
            }
            res.push((digit) as char);
        }
        res.iter().collect()
    }
}
