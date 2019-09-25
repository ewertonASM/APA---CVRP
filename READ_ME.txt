Grupo: Lucas Moreira e Silva Alves
       Ewerton André de Souza Moura

[ CVRP ]

 * Explicação das funções e headers do projeto:

- 	Construção Gulosa - Pega o vizinho mais próximo e randomiza o primeiro termo de cada nova rota

- 	Funções de Vizinhança - Swap, TwoOpt e Inverter (cada uma foi implementada com uma porcetagem aletória do tamanho da função em que será aplicada a função) 

-	VND - Seleção das melhores rotas

-	Meta-Heurística - ILS, função de perturbação (aleatoriamente escolher uma das funções de vizinhança para perturbar a solução)

-	cup_matrix - Transpor os pontos X e Y para uma matriz de adjacência

* Para rodar o arquivo

No terminal:
	./cvrp k i c ./instancias-teste/cvrp1.txt

Onde: 

-k é a chave para selecionar entre instâncias-teste(k=1) ou cvrp-cup(k=0).
-i são as iterações do ils.
-c iterações do código.
-Por último coloca-se o caminho para o arquivo.







