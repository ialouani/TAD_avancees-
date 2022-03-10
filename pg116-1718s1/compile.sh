#!/bin/bash
cd ~/
if [ -e ~/examen_session2 ];then
    sudo rm -rf examen_session2
fi
mkdir examen_session2
cd ~/examen_session2/
git clone https://github.com/ialouani/Archive-de-tests-unitaires-automatiques
git clone https://github.com/ialouani/TAD_avancees-
cd ~/examen_session2/Archive-de-tests-unitaires-automatiques
tar -xvf pg116-1718s1.tar
cp -r ~/examen_session2/Archive-de-tests-unitaires-automatiques/pg116-1718s1 ~/examen_session2
cd ~/examen_session2/
var1=$(find ./ -name ex1.c | head -n1 )
var2=$(find ./ -name ex2.c | head -n1 )
mv $var1 ./  && mv $var2 .
cp ./TAD_avancees-/pg116-1718s1/ex_test1.c ./
cp ./TAD_avancees-/pg116-1718s1/ex_test2.c ./
cp ./TAD_avancees-/pg116-1718s1/ex1.h ./
cp ./TAD_avancees-/pg116-1718s1/link.h ./
cp ./TAD_avancees-/pg116-1718s1/link.c ./
cp ./TAD_avancees-/pg116-1718s1/Makefile ./pg116-1718s1.c
mv *.h ./pg116-1718s1
mv *.c ./pg116-1718s1
cd ~/examen_session2/TAD_avancees-/pg116-1718s1

