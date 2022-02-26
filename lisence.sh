echo "enter your age"
read age
if [ $age -ge 16 ] && [ $age -lt 18 ]
then
    echo "apply for learner lisence"
elif [ $age -ge 18 ]
then 
	echo "do you have learner lisence?(yes=1/no=0)"
	read a
	if [ $a -eq 0 ]
	then
		echo "first appply for learner lisence"
	else
		echo "how many has it been you have received your learner lisence?"
		read days
		if [ $days -lt 30 ]
		then 
			echo "wait for"$(( 30-$days ))"before applying for permanent lisence"
		else
			echo "you can apply for permanent lisence"
		fi
	fi
else
	echo "you are less than 16"
fi
