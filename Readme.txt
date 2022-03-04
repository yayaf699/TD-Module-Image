Yanisse FERHAOUI - 11909519 | Jounaid BOUDEFAR - 11909916

MODULE IMAGE

Présentation du module:
    Ce module contient 2 classes qui ont été crées à cet effet, la classe "Pixel" et la classe "Image".
    Ces 2 classes nous permettent de pouvoir inclure dans notre code une ou plusieurs images qui ont un format et qui peuvent être colorées pixels par pixels.
    Une fois que ces classes ont été correctement inplémentées et testées à l'aide d'un programme principal "test", nous avons crées deux autres programmes:
        -"exemple" qui une fois éxécuté, va générer deux images et les sauvegarder dans le dossier data.
        -"affichage" qui une fois éxécuté, va afficher une fenêtre SDL2 avec à l'intérieur une image, 
         que nous pouvons faire agrandir et réduire. Pour ce programme, il a fallu au préalable implémenter la
         librairie SDL2 dans notre classe Image.

En plus de ce fichier Readme.txt, cette archive contient:
    -Le Makefile qui contient toutes les dépendances et commandes pour pouvoir compiler tout le module, supprimer les fichiers objets et éxécutables, et générer la documentation.
    -Un dossier src contenant tous les fichiers sources .h et .cpp.
    -Un dossier doc contenant le fichier de configuration doxygen ainsi que la page html de la documentation.
    -Un dossier obj contenant tous les fichier objets .o des fichiers .cpp après avoir tout compilé grâce au Makefile.
    -Un dossier bin contenant les 3 fichiers éxécutables du module, également crées après avoir tout compilé grâce au Makefile, juste après la compilation des fichiers .o.
    -Un dossier data contenant les images générées par les éxécutables.

Comment compiler le module:
    -Prérequis: avoir installé le compilateur gcc.
    1) Ouvrir un terminal et se situer sur le répertoire de l'archive une fois celle-ci décompressée.
    2) Taper la commande "make", le Makefile va se charger de tout compiler en fonction des fichiers, la compilation ne se fera pas sur les fichiers déjà à jour.

Comment l'éxécuter:
    -Une fois le module complètement compilé, il faudra rester au même endroit où nous nous trouvons sur le terminal, puis taper la commande "bin/*" avec "*" correspondant au nom de l'exécutable que l'on veut lancer ("test", "exemple" ou "affichage")