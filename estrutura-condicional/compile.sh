declare -a arquivos=(
"operacoes"
"reajuste"
"saldo"
"produto"
"investimento"
"altura"
"nadador"
"risco"
"raizes"
"multiplo_tres"
"multiplo_cinco"
"divisivel"
"triangulo_existe"
"triangulo_tipo"
"triangulo_angulo"
"triangulo_angulos"
"funcao"
)

for i in ${arquivos[@]}
do
    gcc -Wall src/$i.c -o bin/$i.o -lm
done
