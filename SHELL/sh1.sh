j=0
for i in $*
do
x[$j]=$i
j=`expr $j + 1`
done

j=`expr $# - 1`
for i in $*
do
echo ${x[$j]}
j=`expr $j - 1`
done
