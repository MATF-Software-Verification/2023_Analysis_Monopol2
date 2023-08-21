name1="massif-output.txt"
name2="ms-massif-output.txt"

if [ $# -eq 0 ]; then
   echo "Usage: ./run_massif.sh -m|-c [ms_file_output_name]"
   exit
fi

if [ $1 != "-m" ] && [ $1 != "-c" ]; then
   echo "Usage: ./run_massif.sh -m|-c [ms_file_output_name]"
   exit
fi

if [ $# == 2 ]; then
   name2=$2
fi

valgrind --tool=massif --main-stacksize=4000000000 --massif-out-file=$name1 ../../RS019-monopol/RS019-monopol 

if [ $1 == '-m' ]; then
   ms_print $name1 > $name2 
   echo -e "\e[1;32m == Massif executed profiling and ms_print created report. Results of Massif profiling are saved in file with name $name1 and report of ms_print is in file with name $name2. \e[0m"
else
   echo -e "\e[1;32m == Massif executed profiling. Results of Massif profiling are saved in file with name $name1. \e[0m"
fi
