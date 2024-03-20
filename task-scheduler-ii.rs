impl Solution {
    pub fn task_scheduler_ii(tasks: Vec<i32>, space: i32) -> i64 {
        use std::collections::HashMap;
        let mut task_time = HashMap::new();
        let mut curr_time: i64 = 1;
        for task in &tasks {
            match task_time.get_mut(task) {
                Some(prev_time) => {
                    if (*prev_time + (space as i64) >= curr_time) {
                        let diff = *prev_time + (space as i64) - curr_time + 1;
                        curr_time += diff;
                    }
                    *prev_time = curr_time;
                }
                None => {
                    task_time.insert(task, curr_time);
                }
            }
            curr_time += 1;
        }
        return curr_time - 1;
    }
}
