TEXFILE = workshop_slides.tex

all: pdf

pdf:
	lualatex --shell-escape $(TEXFILE)
	@if ( grep -q "Rerun to get" $(TEXFILE:.tex=.log) ); then \
		echo "Rerunning LaTeX..."; \
		lualatex --shell-escape $(TEXFILE); \
	fi

clean:
	rm -f $(TEXFILE:.tex=.aux) $(TEXFILE:.tex=.log) $(TEXFILE:.tex=.nav) $(TEXFILE:.tex=.out) $(TEXFILE:.tex=.snm) $(TEXFILE:.tex=.toc) $(TEXFILE:.tex=.vrb)

cleanall: clean
	rm -f $(TEXFILE:.tex=.pdf)

.PHONY: all pdf clean cleanall
