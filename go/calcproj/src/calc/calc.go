package main

import "os"
import "fmt"
import "simplemath"
import "strconv"

var Usage = func(){
    fmt.Println("请输入参数.....")
}

func main(){
    args := os.Args
    if args == nil || len(args) < 2 {
        Usage()
        return
    }
    switch args[1]{
        case "add":
            if len(args) != 4{
                fmt.Println("用法 calc add 1 2")
                return
            }
            v1, err1 := strconv.Atoi(args[2]);
            v2, err2 := strconv.Atoi(args[3]);
            if err1 != nil || err2 != nil{ 
                fmt.Println("用法 calc add 1 2")
                return
            }
            ret := simplemath.Add(v1, v2)
            fmt.Println("Result: ", ret)
        case "sqrt":
            if len(args) != 3{
                fmt.Println("用法：calc sqrr 4")
                return
            }
            v, err := strconv.Atoi(args[2])
            if err != nil{ 
                fmt.Println("用法：calc sqrr 4")
                return
            }
            ret := simplemath.Sqrt(v)
            fmt.Println("Result: ", ret)
        default :
            Usage()

    }
}
