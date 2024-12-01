//Functions
// Entry Point
// an function / variables should be written in snake case
// snake case: hello_world
// kebab case: hello-world
fn main() {
    hello_world();
    tell_height(182);
    human_id("Tyler", 21, 182.88);
    let _x = {
        let price = 5;
        let qty = 10;
        price * qty
    };
    println!("Result is: {}", _x);
    // add(4,6);
    let y = add(4,6);
    println!("Value of y is: {}", y);
    println!("Value from function 'add' is: {}.", add(4,6));

    // Calling the BMI Function
    let weight: f64 = 70.0;
    let height: f64 = 1.82;
    let bmi = calculate_bmi(weight, height);
    println!("Your BMI is: {:.2}", bmi);
}

// Hoisting - can call function anywhere in your code
fn hello_world() {
    println!("Hello, Rust!");
}

// you can insert input values
fn tell_height(height: i32) {
    println!("My height is {} cm.", height);
}

// you can insert more than one value
fn human_id(name: &str, age: u32, height: f32) {
    println!("My name is {}, I am {} years old, and my height is {} cm.", name, age, height);
}

// functions returning values
fn add(a: i32, b:i32) -> i32{
    a + b
}

// Expressions and Statements

// Statement: Anything that does not return a value
//-------------
// Almost all statements in Rust end with ;
// let y = let x = 10;
// 1 Variable declarations: let x = 5;
// 2 Function definitions: fn foo() {}
// 3 Control flow statements: if condition { /* code */ } else { /* code */ }, while condition { /* code */ }, etc.



// Expression: Anything that returns a value
// ------------
// 5
// true & false
// add(3,4)
// if condition {value1} else {value2}
// ({code})

//Final Example
//BMI = height(kg)/height(m)^2

fn calculate_bmi(weight_kg: f64, height_m: f64) -> f64{
    weight_kg / (height_m * height_m)
}