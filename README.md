# doom_parser

- Guide d'utilisation:
  - Le main1 n'est bien entendu pas à prendre en compte, mais pour vos tests vous pouvez utilisé le main2
  - J'ai mes propres fonctions de gestion de liste que vous pouvez ré-utilisez ou pas.
  - Dans un premier temps créer votre liste de polygones avec la structure t_mypolygon (voir Cbilga pour plus de détails).
  - Envoyez cette dernière à la fonction: void sauvegarde(char *filename, t_mypolygon **list) (filename étant le nom du fichier et list l'adresse du premier maillon de la liste chainée, exemple: sauvegarde("toto.save", &start);)
  - Si vous utilisez le main2 pour vos tests lancer simplement l'executable "charge_tester" générer par le Makefile de la manière suivante: ./charge_tester [NOM DU FICHIER]
  - Vérifiez la sortie, les informations affichées sont:
    - Le nombre de vertex dans chaque polygon
    - Les vertex correspondants.

Voila pour les détails, s'il vous manque des précisions sur l'utilisation je reste à disposition.

naali
