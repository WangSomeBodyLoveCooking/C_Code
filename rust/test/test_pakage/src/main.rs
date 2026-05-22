fn main(){
    // test();
    up_test();
    let Some(x) = Some(5) else {todo!()};
}


// 基础综合
fn up_test(){
    up_test1();
    up_test2();
    up_test3();
    up_test3_v2();
    up_test4();
    up_test5();

}

// 遍历 1 到 100，打印出所有素数（只能被 1 和自身整除）。
fn up_test1(){
    for i in (1..=100).rev(){
        if i <= 1{
            continue;
        }

        let mut flag = false;

        for j in 2..i{
            if i%j == 0{
                flag = true;
                break;
            }
        }

        if !flag{
            print!("{i}");
            print!("\t");
        }
    }

}

// 给定字符串 "I love Rust programming"，统计有多少个单词（按空格分割）。
fn up_test2(){
    let s = String::from("I love Rust programming");

    let sum = s.split_whitespace().count();

    // let mut sum = 0;
    // for i in s.chars(){
    //     if i == ' '{
    //         sum += 1;
    //     }
    // }
    // sum += 1;

    println!("有{sum}个单词");
}

// 数组 [12, 35, 1, 10, 34, 1]，输出第二大数字（不重复）。
fn up_test3(){
    let mut a = [12, 35, 1, 10, 34, 1];
    let mut max: i32 = a[0];
    let mut second = a[0];
    for i in a{
        if i > max{
            second = max;
            max = i;
        }else if i > second && i != max{
            second = i;
        }
    }

    println!("{max},{second}");
}

fn up_test3_v2(){
    let mut a = [12, 35, 1, 10, 34, 1];
    let l = a.len();
    
    let mut i = 0;
    let mut j = 0;

    for i in 0..(l-1){
        let mut switch = false;
        for j in 0..(l-1-i){
            if a[j] > a[j+1]{
                (a[j], a[j+1]) = (a[j+1], a[j]);
                switch = true;
            }
        }

        if !switch{
            break;
        }
    }

    println!("{:?}", a);

    println!("{},{}", a[l-1], a[l-2]);
}

// 输入 "Rust123Hello"，输出 "rUST123hELLO"。
fn up_test4(){
    let mut s = "Rust123Hello".to_string();
    let mut result = String::new();
    for c in s.chars(){
        let r : char = match c{
            'a'..='z' => (c as u8 - 32) as char,
            'A'..='Z' => (c as u8 + 32) as char,
            _ => c
        };
        result.push(r);
    }

    println!("resutl = {}", result);

    println!("{}", swap_case(&result));
}

fn swap_case(s: &str) -> String {
    s.chars()
        .map(|c| {
            if c.is_uppercase() {
                c.to_ascii_lowercase()
            } else if c.is_lowercase() {
                c.to_ascii_uppercase()
            } else {
                c
            }
        })
        .collect()
}

// [2, 4, 6, 8]，求平均值（保留 2 位小数）。
fn up_test5(){
    let arr = [2.0, 4.0, 6.0, 8.0];
    let sum: f64 = arr.iter().sum();
    let a = sum / arr.len() as f64;
    println!("{}", a);
}








// 基础
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