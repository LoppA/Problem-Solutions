- Lis:

    Problema: https://www.spoj.com/EPU/problems/LIS/  Input: n na primeira linha (1 <= n <= 30000), dps n numeros descrevendo a sequencia (que cabem em um inteiro de 32 bits). Output: imprimir o valor da LIS.

    Seg: https://github.com/LoppA/Problem-Solutions/blob/master/LIS_Completinha/LIS_1D_Seg.cpp

    Binary Search: https://github.com/LoppA/Problem-Solutions/blob/master/LIS_Completinha/LIS_1D_BinarySearch.cpp
    
    Problema: vetor com n pares (x,y). De todas permutacoes escolher subsequencia maxima tal que se i < j entao xi < xj and yi < yj. Ordena por x, entao resolver lis 1d i < j e yi < yj. 
    
    Variacao: pessoa comeco no ponto (0,0) e quer chegar no (N,M), pode parar em lojas na posicao (x,y) tais que xi < xj and yi < yj, qual o numero maximo de lojas em que a pessoa pode passar?

--------------------

- Merge Tree:

    https://www.spoj.com/problems/KQUERYO/       versao do https://www.spoj.com/problems/KQUERY/ (da p resolver offline com seg normal) online

    KQUERYO Solution: https://github.com/LoppA/Problem-Solutions/blob/master/LIS_Completinha/KQUERYO.cpp
    
    https://www.spoj.com/problems/MKTHNUM/

    MKTHNUM Solution: https://github.com/LoppA/Problem-Solutions/blob/master/LIS_Completinha/MKTHNUM.cpp

--------------------

- Lis2:
    X, Y, Z, Sort Z, then i < j and xi < xj and yi < yj

    Problema: http://codeforces.com/gym/101055/problem/D

    Mesmo problema mais restrito: https://www.spoj.com/problems/LIS2/
    
    Seg2D: https://github.com/LoppA/Problem-Solutions/blob/master/LIS_Completinha/LIS2_Seg2D.cpp

    Binary Search with Chain: https://github.com/LoppA/Problem-Solutions/blob/master/LIS_Completinha/SPOJ_LIS2_chain.cpp

--------------------

- Mais seg2d: 

    Points and Rectangles: https://codeforces.com/gym/101964/problem/K

    Solution: https://github.com/LoppA/Problem-Solutions/blob/master/LIS_Completinha/SEERC_2018_K.cpp
