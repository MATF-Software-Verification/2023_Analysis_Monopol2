name="test_results.txt"

if [ $# -eq 1 ]; then
   name="$1"
fi

qmake
make
chmod +x UnitTestsForMonopol

./UnitTestsForMonopol > "$name"

echo -e "\e[1;32m Tests executed and results of tests are written in file 
with name $name \e[0m" 
