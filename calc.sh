echo "enter a num"
read a
echo "read another num"
read b
echo "different options"
echo "1)add"
echo "2)sub"
echo "3)mul"
echo "4)div"
echo "enter you option(number only)"
read c
case $c in
    1) echo "add = "$((a+b));;
	2) echo "sub = "$((a-b));;
	3) echo "mul = "$((a*b));;
	4) echo "div = "$((a/b));;
	*) echo "invalid opt";;
esac
