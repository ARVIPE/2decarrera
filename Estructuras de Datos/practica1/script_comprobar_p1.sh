#!/bin/bash

#Autor ACADEMIA MAIN()

if [ $# -ne 1 ]
then
    echo "ERROR, debes introducir tu nombre de usuario."
    exit -1
fi

fichero=$1".zip"
nombrePractica="packet_processor"

if [ ! -e $fichero ]
then
    echo "ERROR, no existe el fichero $fichero"
    exit -1
fi

if [ -e $nombrePractica ]
then
    echo "ERROR, ya existe una carpeta llamada $nombrePractica, te aconsejo que pruebes el script en un directorio donde no se encuentre la práctica ya descomprimida."
    exit -1
fi

salida=$(unzip $fichero)

if [ ! -e $nombrePractica ]
then
    echo "ERROR, no has comprimido bien la práctica, debería haber una carpeta llamada $nombrePractica al descomprimir $fichero"
    exit -1
fi

cd "$nombrePractica/"

salida=$(md5sum -c DO_NOT_MODIFY.TXT)

for x in $salida
do
    empareja=$(echo $x | grep -E 'La suma coincide')
    if [ ! -n $empareja ]
    then
        echo "ERROR, algo ha fallado en el comando md5sum, revisa que tengas la última versión de la práctica y que no hayas tocado ningún fichero que no debas."
        exit -1
    fi
done

salida=$(cmake -S . -B ./build)
salida=$(cmake --build ./build)

echo "COMPILANDO LA PRÁCTICA"
cd build
make
cd ..
echo ""

echo "PROCEDEMOS A EJECUTAR LOS TESTS"
echo ""
bash ./run_tests.sh ./build/test_slist ./tests_slist_simple
echo ""
bash ./run_tests.sh ./build/test_slist ./tests_slist_cursor
echo ""
bash ./run_tests.sh ./build/test_slist ./tests_slist_fold_unfold
echo ""
bash ./run_tests.sh ./build/test_stack ./tests_stack
echo ""
bash ./run_tests.sh ./build/test_queue ./tests_queue
echo ""
bash ./run_tests.sh ./build/test_packet_processor ./tests_packet_processor
echo ""