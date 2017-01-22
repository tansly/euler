#!/bin/bash

for i in {1..99}
do
    echo $(echo "scale=99; sqrt($i);" | bc -l)
done
