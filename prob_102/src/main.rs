use std::env;
use std::fs;

struct Point(i32, i32);

fn cross_product_z(a: &Point, b: &Point) -> i32 {
    a.0 * b.1 - a.1 * b.0
}

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        panic!("give input filename");
    }
    let filename = &args[1];
    let contents = fs::read_to_string(filename).expect("something went wrong reading the file");

    let mut count_inner = 0;
    for line in contents.lines() {
        let coords: Vec<i32> = line.split(',').map(|n| n.parse().unwrap()).collect();
        let a = Point(coords[0], coords[1]);
        let b = Point(coords[2], coords[3]);
        let c = Point(coords[4], coords[5]);
        let a_b = cross_product_z(&a, &b);
        let b_c = cross_product_z(&b, &c);
        let c_a = cross_product_z(&c, &a);
        let all_neg = a_b < 0 && b_c < 0 && c_a < 0;
        let all_pos = a_b > 0 && b_c > 0 && c_a > 0;
        if all_neg || all_pos {
            count_inner += 1;
        }
    }

    println!("{}", count_inner);
}
