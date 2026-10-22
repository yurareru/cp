// https://cses.fi/problemset/task/1660/
// two pointer
#![allow(dead_code)]
use std::io::stdin;

fn take_int() -> usize {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    input.trim().parse().unwrap()
}

fn take_vector() -> Vec<isize> {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect()
}

fn main() {
    let header = take_vector();
    let n = header[0] as usize;
    let x = header[1];
    let arr = take_vector();

    let mut sum = 0;
    let mut count = 0;
    let mut l = 0;
    for r in 0..n {
        sum += arr[r];
        while l <= r && sum > x {
            sum -= arr[l];
            l += 1;
        }
        if sum == x {
            count += 1;
        }
    }
    println!("{}", count);
}
