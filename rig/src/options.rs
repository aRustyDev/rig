enum Operand {
    None,
    Int,
    Float,
    String,
    Bool,
}

#[derive(Debug)]
struct OptionData {
    opt: char,
    optype: Operand,
}