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

if [ -e 'verticles.txt' ] && [ -e 'spanningTree.txt' ]
then
  echo "Do you want to see your exported spanning tree?";
  echo "0) No";
  echo "1) Yes";

  read option;

  if [ "$option" == 1 ]
  then
    python3.11 print_spanning_tree.py
  fi;
fi;

if [ -e 'verticles.txt' ]
then
  rm -r verticles.txt
fi;
if [ -e 'edges.txt' ]
then
  rm -r edges.txt
fi;
if [ -e 'spanningTree.txt' ]
then
  rm -r spanningTree.txt
fi;
if [ -e 'main.exe' ]
then
  rm -r main.exe
fi;
