use std::vec::Vec;
use std::collections::HashMap;
use std::convert::TryInto;

impl Solution {
  pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut diff_map: HashMap<i32, usize> = HashMap::new();
    let mut indicies: Vec<i32> = Vec::new();
    indicies.reserve(2);
    for i in 0..nums.len() {
      if diff_map.contains_key(&nums[i]) {
        indicies.push(diff_map[&nums[i]].try_into().unwrap());
        indicies.push(i.try_into().unwrap());
        break;
      } else {
        let diff: i32 = target - nums[i];
        diff_map.insert(diff, i);
      }
    }
    return indicies;
  }
}