while [ $# -gt 0 ]
do
	kill $1
	shift
done 
