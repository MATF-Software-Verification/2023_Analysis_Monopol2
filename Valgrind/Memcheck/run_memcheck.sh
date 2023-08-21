name="memcheck-output.txt"

if [ $# == 1 ]; then
   name=$1
fi

valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all --log-file=$name ../../RS019-monopol/RS019-monopol 


echo -e "\e[1;32m == Memcheck executed profiling. Results of Memcheck profiling are saved in file with name $name. \e[0m"
