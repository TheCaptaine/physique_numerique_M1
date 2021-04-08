import numpy as np
import matplotlib.pyplot as plt

# Variable a modifier avant execution
#nomfichier = "carre.txt"                     # <== fichier de donnees
nomfichier = "data.res"                     # <== fichier de donnees

# Choix du nom du fichier de sortie : idem fic. entree avec extension .pdf
nomgraph = nomfichier[ : nomfichier.rfind(".")]+".pdf"

try:      # ouverture du fichier de donnees
  fich  = open(nomfichier, "r")
except:
  print(" ! Impossible d'ouvrir le fichier %s."%nomfichier )
  print(" ! Verifier le chemin.\n")
  exit()

# Lecture des lignes d'entete
ligne = fich.readline().replace("\n","") # sans caractere de fin de ligne
entete= [ ]
while( ligne[0] == "#" ):
   entete.append( ligne[1:] )
   ligne =  fich.readline().replace("\n","")
fich.close()
print( " > fichier %s : %d lignes d'entete"%( nomfichier, len(entete) ) )

# concatenation des entetes en une seule ligne de titre :
titre = " ".join(entete)

# Lecture des donnees du fichier :
tab = np.loadtxt( nomfichier, dtype="float").T

# Creation des listes d'abscisses/ordonnees : 1ere et 2eme colonnes
x = tab[0]
y = tab[1]
z = tab[2]
t = tab[3]

# Creation du graphique
plt.figure( figsize=(11.69, 8.27) ) # taille en inches : A4 paysage
plt.title( titre, fontsize=8)
plt.grid()

plt.subplot(311)
plt.loglog(x, y)                # <== choix de la legende
plt.xlabel("x")                                   # <== variable d'abscisse
plt.ylabel("y")                                   # <== variable d'ordonnee

plt.subplot(312)
plt.loglog(x, z)
plt.xlabel("x")
plt.ylabel("z")

plt.subplot(313)
plt.loglog(x, t)
plt.xlabel("x")
plt.ylabel("t")

fig = plt.gcf()
fig.savefig(nomgraph) # sauvegarde du graphique au format pdf

#print(" < Le graphique %s a ete cree."%(nomgraph) )
#print("   \tVisualiser avec :  evince %s"%(nomgraph))

plt.show()
plt.clf() # nettoyage ('clear figure')
