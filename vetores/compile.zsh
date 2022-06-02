files=(
vetor100
multiplos5
quadradoimpar
atletaalturas
fibonacci
sen
temperaturas
abcd
organizar
mercadoria
eleicoes
estatistica
prova
produto_escalar
circunferencia
repeticao
soma_maxima
)

for i in "${files[@]}"
do
  gcc -Wall ./src/$i.c -o ./bin/$i.o -lm
done
