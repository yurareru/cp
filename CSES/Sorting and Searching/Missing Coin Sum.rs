// https://cses.fi/problemset/task/2183
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
    let n = take_int();
    let mut arr = take_vector();
    arr.sort();
    let mut missing = 1;
    for i in 0..n {
        if arr[i] > missing {
            break;
        }
        missing += arr[i];
    }
    println!("{}", missing);
}
