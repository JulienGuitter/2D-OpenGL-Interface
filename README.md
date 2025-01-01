

# Information

Ce dossier contient ce qu'il faut pour pouvoir effectuer l'étape 4 du projet morpion. Dans ce dossier il y a ce qu'il faut pour afficher une interface basic avec OpenGL (Peut de fonction a utiliser pour que le jeux soit fonctionnel)

Dans le fichier `demo.c` vous trouverez toute les fonctions et comment les utiliser.

`demo.c` est juste un exemple que vous pouvez lancer. Mais n'est en aucun cas utile dans le projet

Deplus, les fichier `window.c` et `window.h` peuvent être utilisé dans d'autre projet 2D.

# Mise en place

Dans le dossier vous trouverez c'est fichier :
- `window.h`
- `window.c`
- `stb_image.c`
- `stb_image.h`
- `player_manager_opengl.c`
- `board_view_opengl.c`

C'est 6 fichier sont à glisser dans votre projet.

Pour le dossier `resources`, il faut le mettre dans le même dossier que l'executable final. Ce fichier ne sera pas utilisé lors de la compilation, mais accèder lors de l'execution.

exemple : 

```
- build
    - resources
        - background.png
        - ...
    - main.exe
- ...
```

<br><br>

il vous faudra aussi modifier votre ligne de compilation.

### Pour GCC : 

Remplace les argument `-DCONFIG_PLAYER_MANAGER_SCANF` et `-DCONFIG_TEXTUI` de l'étape 3 par `-DCONFIG_PLAYER_MANAGER_OPENGL -DCONFIG_OPENGLUI`

### Pour Visual Studio : 

Dans le menu ou vous avez mis :
- `CONFIG_PLAYER_MANAGER_SCANF`
- `CONFIG_TEXTUI`

Remplacez les simplement par :
- `CONFIG_PLAYER_MANAGER_OPENGL`
- `CONFIG_OPENGLUI`

# Installation necessaire :

Il y a 3 librairie qu'il faudra installer pour pouvoir utiliser ce code.

- GLFW
- GLEW
- OpenGL

Pour ce faire voici des commande a executer pour les installer :

## Pour linux : 

### Ubuntu/Debian (testé):

```
sudo apt-get update
sudo apt-get install libglfw3-dev libglew-dev libgl1-mesa-dev
```

### Fedora (Non testé):
```
sudo dnf install glfw-devel glew-devel mesa-libGL-devel
```

### Arch Linux (Non testé):
```
sudo pacman -S glfw-x11 glew mesa
```

## Pour Mac OS (Non testé):
```
brew update
brew install glfw glew
```


## Pour Windows (Non testé): 
Pour windows il faut télécharger les librairie et les installer manuellement.

- GLFW : Téléchargez depuis [glfw.org](https://www.glfw.org/download.html) et suivez les instructions d'installation.
- GLEW : Téléchargez depuis [glew.sourceforge.net](https://glew.sourceforge.net/) et suivez les instructions d'installation.
- OpenGL : Généralement, OpenGL est inclus avec les pilotes de votre carte graphique. Assurez-vous que vos pilotes sont à jour.

Ensuite, configurez votre environnement de développement (comme Visual Studio) pour inclure les bibliothèques et les fichiers d'en-tête appropriés.

# Configuration

Avant de lancer le programme, vous devez ajouter les definition de compilation

### Avec GCC

Dans la ligne de compilation ajouter les arguments `-lglfw`, `-lGL`, `-lGLEW`, `-lm -Wno-implicit-function-declaration`.

Noubliez pas d'ajouter les .c dans la ligne de compilation `stb_image.c window.c`

Comme par exemple : 
```
gcc demo.c stb_image.c window.c -o demo -lglfw -lGL -lGLEW -lm -Wno-implicit-function-declaration
```

### Avec Visual Studio (Non testé):

1. Ouvrez votre projet dans Visual Studio.
2. Cliquez avec le bouton droit sur votre projet dans l'Explorateur de solutions et sélectionnez "Propriétés".
3. Dans la fenêtre des propriétés du projet, allez à "Configuration Properties" > "Linker" > "Input".
4. Dans le champ "Additional Dependencies", ajoutez les bibliothèques suivantes : ```glfw3.lib; opengl32.lib; glew32.lib; %(AdditionalDependencies)```
5. Cliquez sur "OK" pour enregistrer les modifications.

Assurez-vous également que les chemins d'accès aux bibliothèques et aux fichiers d'en-tête sont correctement configurés :

1. Allez à "Configuration Properties" > "VC++ Directories".
2. Ajoutez les chemins d'accès aux bibliothèques dans "Library Directories".
3. Ajoutez les chemins d'accès aux fichiers d'en-tête dans "Include Directories".


Cela devrait configurer votre projet pour lier correctement les bibliothèques GLFW, OpenGL, GLEW et mathématiques.



# Build the programme :

### Pour GCC : 

Si vous souhaitez lancer le programme de demo, vous pouvez entre la commande suivante.

```
gcc demo.c stb_image.c window.c -o demo -lglfw -lGL -lGLEW -lm -Wno-implicit-function-declaration
```

Si vous souhaitez lancer le projet. Voici un exemple de à quoi peut ressemblé la ligne de compilation : 

```
gcc main.c game.c board.c board_view_opengl.c player_manager_opengl.c window.c stb_image.c -o tictacto -DCONFIG_PLAYER_MANAGER_OPENGL -DCONFIG_OPENGLUI  -lglfw -lGL -lGLEW -lm -Wno-implicit-function-declaration
```

### Pour Visual Studio :

il vous suffit d'appuyer sur le bouton build && run