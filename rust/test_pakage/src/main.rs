fn main(){
    test();
}

fn test() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
}

// 定义整型变量 a=10、b=20，打印两个变量的值，并打印两数之和。
fn test1(){
    let a = 10;
    let b = 20;
    println!("a = {}", a);
    println!("b = {}", b);
    println!("a + b = {}", a+b);
}

// 定义常量 PI = 3.14159，输入半径 r=5，计算并打印圆的面积 S=πr²。
fn test2(){
    const PI:f64 = 3.14159;
    let r = 5_f64;
    println!("S=πr^2({})", PI*r*r);
}

// 给定数字 n=27，用 if else 判断并打印：是奇数 还是 偶数。
fn test3() {
    let n = 27;
    if n % 2 == 0{
        println!("{}是偶数", n);
    }else{
        println!("{}是奇数", n);
    }
}

// for 循环打印 1~10
fn test4(){
    for i in 1..=10{
        print!("{}",i);
    }
}

// 计算 1~100 累加和
fn test5(){
    let mut sum = 0;
    for i in 1..=100{
        sum += i;
    }
    println!("sum = {}", sum);
}

// 定义整型数组 [11,22,33,44,55]，循环打印数组每一个元素
fn test6(){
    let l : [u8;5] = [11,22,33,44,55];
    for i in l.iter(){
        print!("{}", i);
    }
}

// 创建空 Vec<i32>，依次推入 1、2、3、4，再删除最后一个元素，最后遍历打印所有元素。
fn test7(){
    let mut n = Vec::new();
    for _ in 1..=4{
        n.push("123".to_string());
    }

    n.pop();
    // for i in n{    n所有权会移动
    for i in n.iter(){  // 相当于&n
        print!("{}", i);
    }

    println!("{:?}",n);

}

// 定义字符串 s = "Hello Rust"，打印字符串长度、拼接另一个字符串 ", I love it" 并输出。
fn test8(){
    let mut s = "Hello Rust".to_string();
    println!("{} len = {}", s, s.len());    // 借用

    s.push_str("I love it");
    println!("{}", s);
}