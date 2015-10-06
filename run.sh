cc main.c -o main

for i in {1..50}
do
   #echo "learning $i "
   ./main | tail -n 1
done
