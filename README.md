# CPD-LAB1
Laboratorio 1 - Computación Paralela y Distribuida

Construir Docker para compilacion:

' docker build -t cpp-openmp-env . '
' docker run -it --name cpp_openmp_container -v C:{PWD}\CPD-LAB1\app:/usr/src/app cpp-openmp-env  '