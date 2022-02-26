echo -n "enter size"
read m
echo "enter elements"
i=1
while [ $i -le $m ]
do
    read a[$i]
    i=$((i+1))
done

i=1
while [ $i -le $m ]
do
    j=$((i+1))
    while [ $j -le $m ]
    do 
        if [ $((a[i])) -gt $((a[j]))]
        then 
            temp=$((a[j]))
            a[$j]=$((a[i]))
            a[$i]=$temp
        fi
        j=$((j+1))
    done
    i=$((i+1))
done

echo "sorted array"
i=1
while [ $i -le $m ]
do
    echo $((a[i]))
    i=$((i+1))
done        

