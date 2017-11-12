import numpy as np
import scipy.io.wavfile as wav
import matplotlib.pyplot as plt

condiciones_iniciales=np.genfromtxt("cond_ini_cuerda.dat")
datos_cuerda=np.genfromtxt("datos.dat")
x=condiciones_iniciales[:,0]
y=condiciones_iniciales[:,1]
t1=datos_cuerda[0]
t2=datos_cuerda[1]
t3=datos_cuerda[2]

perturbado=np.genfromtxt("sen.dat")
per1=perturbado[0]
per2=perturbado[1]
per3=perturbado[2]


plt.plot(x,y,c="orange",label="t=0")
plt.plot(x,t1,c="purple",label="t=T/2")
plt.plot(x,t2,c="red",label="t=T/4")
plt.plot(x,t3,c="blue",label="t=T/8")
plt.title("Ecuacion de onda para una cuerda con extremos fijos ")
plt.ylabel("U(x)")
plt.xlabel("x")
plt.legend(loc=0)
plt.tight_layout()
plt.savefig("Cuerda_fija.png")
plt.close()

plt.plot(x,per1,c="purple",label="t=T/2")
plt.plot(x,per2,c="orange",label="t=T/4")
plt.plot(x,per3,c="blue",label="t=T/8")
plt.title("Ecuacion de onda para una cuerda con perturbacion ")
plt.ylabel("U(x)")
plt.xlabel("x")
plt.legend(loc=0)
plt.tight_layout()

plt.savefig("Cuerda_perturbada.png")
plt.close()

audios=np.genfromtxt("audios.dat")
wav.write("sonido.wav",50000,audios)


fig=plt.figure(3)
ax=plt.axes(xlim=(0,0.64),ylim=(-5,5))
line, =ax.plot([],[],lw=2)

def init():
	line.set_data([],[])
	return line,

def animate(i):
	x=perturbado[:,0]
	y=perturbado[:,(10*i+1)]
	line.set_data(x,y)
	return line,

anim=animation.FuncAnimation(fig,animate, init_func=init,frames=(per2/10),interval=20,blit=True)

#TOCA DESCARGAR LSO PAQUETES DE FFMEPG
anim.save('animacion.mp4',fps=30,extra_args=['-vcodec','libx264'])






