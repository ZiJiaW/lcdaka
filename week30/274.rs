use std::cmp;
impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let slice = &mut citations.clone()[..];
        slice.sort();
        slice.iter().rev().enumerate().fold(0 as i32, |acc, x| {
            let m = cmp::min((x.0 + 1) as i32, *x.1);
            cmp::max(m, acc)
        })
    }
}