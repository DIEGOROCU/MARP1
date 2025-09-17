# Makefile para compilar presentación Beamer

# Variables
MAIN = presentacion
TEXFILE = $(MAIN).tex
PDFFILE = $(MAIN).pdf

# Compilador LaTeX
LATEX = pdflatex
BIBTEX = bibtex

# Opciones del compilador
LATEXOPTS = -interaction=nonstopmode -halt-on-error

# Regla principal
all: $(PDFFILE)

# Compilación del PDF
$(PDFFILE): $(TEXFILE)
	$(LATEX) $(LATEXOPTS) $(TEXFILE)
	$(LATEX) $(LATEXOPTS) $(TEXFILE)

# Compilación con bibliografía
bib: $(TEXFILE) referencias.bib
	$(LATEX) $(LATEXOPTS) $(TEXFILE)
	$(BIBTEX) $(MAIN)
	$(LATEX) $(LATEXOPTS) $(TEXFILE)
	$(LATEX) $(LATEXOPTS) $(TEXFILE)

# Limpiar archivos auxiliares
clean:
	rm -f *.aux *.log *.nav *.out *.snm *.toc *.vrb *.fls *.fdb_latexmk *.synctex.gz

# Limpiar todo incluyendo PDF
cleanall: clean
	rm -f $(PDFFILE)

# Recompilar desde cero
rebuild: cleanall all

# Abrir el PDF (Linux)
view: $(PDFFILE)
	xdg-open $(PDFFILE) 2>/dev/null || echo "No se pudo abrir el PDF automáticamente"

# Ayuda
help:
	@echo "Comandos disponibles:"
	@echo "  make         - Compilar la presentación"
	@echo "  make bib     - Compilar con bibliografía"
	@echo "  make clean   - Limpiar archivos auxiliares"
	@echo "  make cleanall- Limpiar todo incluyendo PDF"
	@echo "  make rebuild - Recompilar desde cero"
	@echo "  make view    - Abrir el PDF"
	@echo "  make help    - Mostrar esta ayuda"

.PHONY: all clean cleanall rebuild view help bib