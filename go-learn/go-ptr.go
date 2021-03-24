package main
import "fmt"

func changevalue(str *string) **string{
	*str = "changed"
	return &str

}

func changevalue2(str string) string {
	str = "changed"
	return str
}



func main() {
	x := 8
	y := &x
	*y = 111
	var p **string
	fmt.Println(&x,x,y,*y)
	tochange := "hello"
    p = changevalue(&tochange)

	fmt.Println(tochange,*p,p,**p)


}