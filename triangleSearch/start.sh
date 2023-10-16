g++ main.cpp -o main.exe;
./main.exe;

if [ -e 'verticles.txt' ] && [ -e 'edges.txt' ]
then
  echo "Do you want to see your exported graph?";
  echo "0) No";
  echo "1) Yes";

  read option;

  if [ "$option" == 1 ]
  then
    python3.11 print_graph.py
  fi;
fi;
