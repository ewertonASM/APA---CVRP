Grupo: Lucas Moreira e Silva Alves
       Ewerton Andr� de Souza Moura

[ CVRP ]

 * Explica��o das fun��es e headers do projeto:

- 	Constru��o Gulosa - Pega o vizinho mais pr�ximo e randomiza o primeiro termo de cada nova rota

- 	Fun��es de Vizinhan�a - Swap, TwoOpt e Inverter (cada uma foi implementada com uma porcetagem alet�ria do tamanho da fun��o em que ser� aplicada a fun��o) 

-	VND - Sele��o das melhores rotas

-	Meta-Heur�stica - ILS, fun��o de perturba��o (aleatoriamente escolher uma das fun��es de vizinhan�a para perturbar a solu��o)

-	cup_matrix - Transpor os pontos X e Y para uma matriz de adjac�ncia

* Para rodar o arquivo

No terminal:
	./cvrp k i c ./instancias-teste/cvrp1.txt

Onde: 

-k � a chave para selecionar entre inst�ncias-teste(k=1) ou cvrp-cup(k=0).
-i s�o as itera��es do ils.
-c itera��es do c�digo.
-Por �ltimo coloca-se o caminho para o arquivo.







