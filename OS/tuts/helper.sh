#! /bin/sh

totaltime=0

for i in {1..10}
do
    time=$(/usr/bin/time -f "%e" ./cla $i)
    totaltime=$($totaltime + $time)
done


 echo "Total time taken: $totaltime"
