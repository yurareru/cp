// https://cses.fi/problemset/task/1643
// kadane's algorithm
use std::io::stdin;

fn take_int() -> usize {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    input.trim().parse().unwrap()
}

fn take_vector() -> Vec<isize> {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let arr: Vec<isize> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    arr
}

fn main() {
    let n: usize = take_int();
    let arr = take_vector();
    let mut cur = arr[0];
    let mut ans = cur;
    for i in 1..n {
        cur = arr[i].max(arr[i] + cur);
        ans = cur.max(ans);
    }
    println!("{}", ans);
}
