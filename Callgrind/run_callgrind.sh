name="callgrind-output.txt"

if [ $# -eq 0 ]; then
   echo "Usage: ./run_callgrind.sh -k|-c [file_output_name]"
   exit
fi

if [ $1 != "-k" ] && [ $1 != "-c" ]; then
   echo "Usage: ./run_callgrind.sh -k|-c [file_output_name]"
   exit
fi

if [ $# == 2 ]; then
   name=$2
fi

valgrind --tool=callgrind --callgrind-out-file=$name ../../RS019-monopol/RS019-monopol 

if [ $1 == '-k' ]; then
   kcachegrind callgrind-output.txt 
   echo -e "\e[1;32m == Callgrind executed profiling and Kcachegrind executed. Results of Callgrind profiling are saved in file with name $name \n \e[0m"
else
   echo -e "\e[1;32m == Callgrind executed profiling. Results of Callgrind profiling are saved in file with name $name. \n \e[0m"
fi
