# (python 3)
import numpy as np
import matplotlib.pyplot as plt
import sys

#
#------ PARAMETRES a EDITER -------------------------#
# nom du fichier de donnees (ayant 1 ligne d'en-tete)
fichier = "step-crank-nicolson.txt"
#fichier = "implicite.dat"
#fichier = "cranknic.dat"
nech   = 10              # nombre d'instants affiches (echantillonnage regulier)
#----------------------------------------------------#

# Récupération du nom de fichier transmis en argument (s'il est présent)
if len(sys.argv) > 1:
    fichier = sys.argv[1]

titre  = 'Diffusion : fichier "%s" '%fichier

# Lecture de la ligne d'entete : nx+2 nt dx dt alpha
try:
    fp=open(fichier,"r")
except:
    print( " Erreur d'ouverture du fichier '%s' ."%fichier)
    exit(1)
params = fp.readline().strip().replace("#","").split()
fp.close()

try:
    nx = int( params[0] ) # nbr de points, bords inclus
    nt = int( params[1] ) # nbr d'instants attendus
    dx = float( params[2] ) # pas en espace
    dt = float( params[3] ) # pas en temps
    alpha = float( params[4] ) # parametre alpha
except:
    print (" ! La ligne d'en-tete n'est pas au format attendu :")
    print(" (nx+2 nt dx dt alpha) : ", params)
    dx = 1.
    dt = -1.
    alpha = -1.

# Lecture des donnees : apres la 1ere ligne
data = np.loadtxt( fichier, skiprows=1)
# nombre effectif d'instants et de points
nt = data.shape[0]
nx = data.shape[1]
print(" Nx=%d , Nt=%d"%(nx,nt))
params= "$\\alpha = %g , \delta t=%g , \delta x=%g$"%(alpha,dt,dx)

# Axe des X :
x = dx*np.linspace(0,nx-1,nx)
# pas d'echantillonnage en temps : nombre d'instants sautes
pech = max(1, int((nt-1)/(nech-1)) )

# Affichage :
plt.rc('text', usetex=True)
plt.figure( figsize=(11.69,8.27) )
plt.plot(x, data[0], '-', label='t=0')
for k in range(1,nech-1):
    plt.plot(x, data[pech*k], '-')
plt.plot(x, data[nt-1], '-', label='t=%g'%(dt*(nt-1)))
plt.xlabel("position $x$")
plt.ylabel("u(x,t)")
plt.title( r"%s $\quad$ %s"%(titre, params) )
plt.legend()
plt.grid(True)

# Nom du graphique : identique a celui du fichier
graphname = fichier[ : fichier.rfind(".")] + ".pdf"
plt.savefig( graphname, format="pdf")
print( " Le graphique '%s' a ete cree."%graphname )
print( "\n Fermer la figure pour terminer.\n" )
plt.show()
