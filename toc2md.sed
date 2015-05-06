s/.*{chapter}{\\numberline {\(.*\)\\hspace.*}}\(.*\)}{[0-9].*/\
# \1 \2/p
s/.*{section}{\\numberline {[0-9.]*}\(.*\)}{[0-9].*/* \1/p
s/.*{subsection}{\\numberline {[0-9.]*}\(.*\)}{[0-9].*/	* \1/p
s/.*{subsubsection}{\\numberline {[0-9.]*}\(.*\)}{[0-9].*/		* \1/p
