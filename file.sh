echo "enter a file name"
read name
if [ ! -f $name ]
then
	echo "file not found"
else
	echo "file found"
fi
