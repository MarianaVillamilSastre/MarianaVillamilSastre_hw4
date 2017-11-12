cuerda= Cuerda_fija.png Cuerda_perturbada.png
erase=rm -r -f *.dat a.out *.png *.aux *.log



Resultados_hw4.pdf : Resultados_hw4.tex $(cuerda)
	pdflatex $<


$(cuerda): *.dat Plots.py
	python Plots.py

*.dat: Ondas.x cond_ini_cuerda.dat
	./Ondas.x 

Ondas.x: Ondas.c
	gcc -lm Ondas.c

clean:
	$(erase) *.pdf *.wav

