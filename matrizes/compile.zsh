declare -a files=(
determinante
2x2
minmax
6x3minmax
4x4diagprinc
4x4diagsec
4x4diagexprin
4x4diagexsec
3x5vetor_soma
produto_a_b
inversa
magica
90graus
inversa
simetrica
anti-simetrica
180graus
270graus
vendas
alunos
)

for i in "${files[@]}"
do
	gcc ./src/$i.c -o ./bin/$i.o -lm
done
