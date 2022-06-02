declare -a arquivos=(
"funcionario"
"peso"
"produto"
"prova"
"trapezio"
"quadrado"
"salario"
"tabuada"
"idade"
"temperatura"
"potencia"
"calculaSalario"
"cotacao"
)

for i in ${arquivos[@]}
do
    gcc src/$i.c -o bin/$i.o
done

