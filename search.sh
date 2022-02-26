echo "enter size"
read n
echo "enter elements"
i=1
while [ $i -le $n ]
do
    read a[$i]
    i=$((i+1))
done    
echo "enter a target num"
read t
f=0
i=1
index=1
while [ $i -le $n ]
do
	if [ $((a[i])) -eq $t ]
	then
		f=1
		index=$i
	fi
	i=$((i+1 ))
done

if [ $f -eq 1 ]
then
	echo "target is found at "$index
else
	echo "not found"
fi
    
# echo "enter array size = "
# read n
# echo "enter array values - "
# i=1
# while [ $i -le $n ]
# do
#     read a[ $i ]
#     i=$((i+1))
# done
# echo "enter a value to search in array = "
# read v

# i=1
# f="given value not found"
# while [ $i -le $n ]
# do
#     if [ $((a[i])) -eq $v ]
#     then
#     f="given value found at location "$i
#     fi
#     i=$((i+1))
# done 
# echo $f