fn another_function(x: i32) -> i32 {
    println!("Another function,the value  of x is {}", x);
    x + 1
}

fn test_branches(x: i32) {
    if x > 10 {
        println!("x greater than 10");
    } else {
        println!("x less than 10");
    }

    let mut counter = 0;
    loop {
        counter += 1;
        if counter == 10{
            break;
        }
        println!("loop again");
    }


    while counter != 0 {
        println!("{}!",counter);
        counter = counter - 1;
    }

    for number in (1..10){
        println!("{}!", number);
    }
}

fn main() {
    println!("Hello, world!");

    let guess: u32 = "42".parse().expect("Not a number");

    let y = 100;

    let b: bool = false;

    println!("{}", b);

    let tup = (500, 1.0, -1);
    let (x, y, z) = tup;
    println!("{}", z);

    let a = [1, 2, 3, 4, 5];
    let index = 4;
    let a10 = a[index];
    println!("{}", a10);

    another_function(100);

    test_branches(10);
}
