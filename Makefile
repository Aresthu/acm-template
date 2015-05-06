TEXFLAGS=-synctex=1 -interaction=nonstopmode

all:
	xelatex $(TEXFLAGS) main.tex
	xelatex $(TEXFLAGS) main.tex
	sed -nf toc2md.sed main.toc > 目录.md

clean:
	-rm main.aux main.log main.out main.pdf main.synctex.gz main.toc missfont.log
