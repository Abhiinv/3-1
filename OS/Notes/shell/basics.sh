#! /bin/sh

# sum=(( 5+7 )) # Arithmetic Expansion
# sum2=$[ 5+7 ] # Also Arithmetic Expansion
# echo $sum
# echo $sum2


# unset sum
# unset sum2

((sum=5+7))
((sum+=5))
echo $sum
