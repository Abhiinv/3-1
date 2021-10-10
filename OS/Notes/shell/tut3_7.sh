#! /bin/bash

echo "In File: $0"
echo "Number of Command Line Args: $#"

for i in "$@"; do # Or use $*
    echo $i
done