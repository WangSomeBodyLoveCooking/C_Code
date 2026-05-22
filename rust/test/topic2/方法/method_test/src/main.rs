// 基础1. 多个方法组合调用
// 学生结构体Student{name:String, score:i32}
// 实现：
// 构造 new
// 修改分数 set_score (&mut self, s:i32)
// 判断是否及格 is_pass (&self)->bool

struct Student{
    name:String,
    score:i32
}

impl Student{
    fn new(name:String, score:i32)->Self{
        Self{name,score}
    }

    fn set_score(&mut self, mod_score:i32){
        self.score = mod_score;
    }

    fn is_pass(&self) -> bool{
        if self.score > 60{
            true
        }else{
            false
        }
    }
}

fn test1(){
    let mut s1 = Student::new("xiaoming".into(), 90);
    println!("{} {}分是否及格？{}", s1.name, s1.score,s1.is_pass());
    s1.set_score(59);
    println!("{} {}分是否及格？{}", s1.name, s1.score, s1.is_pass());
}

// 进阶1：方法返回自身所有权
// 定义计数器Counter{num:i32}
// 实现方法inc(mut self) -> Self 自增并返回所有权
struct Counter{
    num:u32
}

impl Counter{
    fn new()->Self{
        Self{num:0}
    }
    fn inc(mut self) -> Self{
        self.num += 1;
        self
    }
}

fn test_top_1(){
    let c1 = Counter::new().inc().inc();
    println!("{}", c1.num);
}

// 进阶2：枚举实现方法
// 枚举Shape{Rect(u32,u32),Circle(f64)}
// 实现方法calc_area(&self) -> f64 计算对应图形面积
#[derive(Debug)]
enum Shape{
    Rect(u32,u32),
    Circle(f64)
}

impl Shape{
    fn calc_area(&self) -> f64 {
        match self{
            Self::Rect(x, y) => (x*y) as f64,
            Self::Circle(r) => std::f64::consts::PI * r * r
        }
    }
}

fn test_top_2(){
    let s1 = Shape::Rect(20, 10);
    let s2 = Shape::Circle(2.0);
    println!("{:?}的面积为{}", s1, s1.calc_area());
    println!("{:?}的面积为{}", s2, s2.calc_area());
}

// 进阶4:关联函数重载风格多构造器
// Point{x:i32,y:i32}
// 写多个不同名关联函数：
// origin () 原点
// new (x,y) 普通点
// x_only (x) y 固定 0
struct Point{
    x:i32,
    y:i32
}

impl Point{
    fn origin() -> Self{
        Point{x:0,y:0}
    }

    fn new(x:i32,y:i32)->Self{
        Point{x,y}
    }

    fn x_only(x:i32)->Self{
        Self{x,y:0}
    }
}

fn test_top_4(){
    let p1 = Point::origin();
    let p2 = Point::x_only(10);
    println!("{},{}", p1.x,p1.y);
    println!("{},{}", p2.x,p2.y);
}

// 进阶5: 方法调用链式调用
// 构建User，实现链式：设置名字 -> 设置年龄 -> 打印信息
#[derive(Debug)]
struct User{
    name:String,
    age:u8
}

impl User{
    fn new()->Self{
        Self{name:String::new(),age:0}
    }

    fn name(mut self, name:&str)->Self{
        self.name = name.to_string();
        self
    }

    fn age(mut self, age:u8)->Self{
        self.age = age;
        self
    }

    fn show(self) -> Self{
        println!("name = {:?}", self.name);
        println!("age = {}", self.age);
        self
    }
}

// 高阶1：

fn test_top_5(){
    User::new().name("rust").age(20).show();
}

fn main() {
    test1();

    test_top_1();
    test_top_2();
    test_top_4();
    test_top_5();
}

