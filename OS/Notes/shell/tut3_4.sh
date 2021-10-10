#! /bin/bash

echo 'Enter Number:'
read num

if [[ $[num % 2] -eq 1 ]]; then
    echo 'Odd Number'
else
    echo 'Even Number'
fi