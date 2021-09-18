import numpy as np
import matplotlib.pyplot as plt
import sys

# Variable a modifier avant execution (ou passer le nom du fichier en argument)
nomfichier = "euler.txt"                     # <== fichier de donnees
if len(sys.argv) > 1:
    nomfichier = sys.argv[1]

# Choix du nom du fichier de sortie : idem fic. entree avec extension .pdf
nomgraph = nomfichier[ : nomfichier.rfind(".")]+".pdf"

try:      # ouverture du fichier de donnees
  fich  = open(nomfichier, "r")
except:
  print(" ! Impossible d'ouvrir le fichier %s."%nomfichier )
  print(" ! Verifier le chemin.\n")
  sys.exit()

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
tab = np.loadtxt( nomfichier, dtype="float")

# Creation des listes d'abscisses/ordonnees : 1ere et 2eme colonnes
t = tab[:,0]
s = tab[:,1]
i = tab[:,2]
r = tab[:,3]

# Creation du graphique
plt.figure( figsize=(11.69, 8.27) ) # taille en inches : A4 paysage
plt.title( titre, fontsize=8)
plt.grid()

plt.plot(t, s,'b', label="susceptibles")
plt.plot(t, i,'r', label="infectieux")
plt.plot(t, r,'g', label="gueris")
plt.xlabel("t")                                   # <== variable d'abscisse
plt.ylabel("y")                                   # <== variable d'ordonnee

plt.legend()
fig = plt.gcf()
fig.savefig(nomgraph) # sauvegarde du fichier.
print(" < Le graphique %s a ete cree."%(nomgraph) )
print("   \tVisualiser avec : okular %s"%(nomgraph))

plt.show()
plt.clf() # nettoyage ('clear figure')
