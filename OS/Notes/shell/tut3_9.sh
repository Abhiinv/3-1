#! /bin/bash

# total_time=0

time {
    for i in {1..1000}; do
        ./fact $i
    done
}