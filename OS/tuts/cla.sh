#! /bin/bash

echo "No of args passed:  $#"
echo "filename: $0"

# Print all Command Line Arguments

for i in $@ # Try $*
    do
        echo $i
    done
