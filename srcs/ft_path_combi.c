
exp
Comb1 : P1 (length 3)
	P2 len 3)
	P3 (len 2)


Comb2 : P1 (length 4)
	P2 len 4)
	P3 (len 4)
	P4 (len 4)

si moins de 16 fourmis C1 est meilleur sinon C2


si meme nb de chemin prendre somme des length
(id est P1 len 1 P2 len 7 et p3 len 3 idem que P1 len 2 P2 len 4 et P3 len 5)
attention depend nb fourmis si 2 fourmis le premier est meilleur 

sinon on balance vite algo a chaque Combinaison et on donne le nm de cycles pr le nb de fourmis en option. en gros on rajoute 1 par chemin au bout de longeur et on voit quand on est > ANT No


on peut partir de i = min len P pour chaque combinaison (comme ca si 100k fourmis et pmin = 1000 on incremente pas de 1 1000 fois


donc on a 
liste de combi de chemins exclusifs  avec
liste de chemins
longueur de chaque chemin
index des path? 
nb de cycle pr arriver a la fin

et ds info on met t_sol *solminimum ver la combi la plus optimum


