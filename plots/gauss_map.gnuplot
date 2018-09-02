file='gauss.png'

set terminal epslatex standalone size 15cm,10cm color colortext font 'Helvetica,12' header "\\usepackage{amsmath} \n   \\usepackage{siunitx} \n \\sisetup{ \n  locale = DE , \n  output-decimal-marker = {.},\n  per-mode = symbol \n }"

set output "gaussmap.tex"

set xrange [-1:1]
set yrange [-1:1.2]
set x2range [*:*]
set y2range [*:*]

set xlabel 'r'
set ylabel 'x' rotate by 0

set xtics .5 mirror out
set mxtics 2
set ytics .5 mirror out
set mytics 2

unset key

set title 'Gauss map, $\alpha = 4.9$'

xmin = 3.4
xmax =3.75
ymin =.7
ymax = .95

#set object 1 rectangle from xmin,ymin to xmax,ymax fs empty border rgb "black" lw 1 dt 2 front

plot file binary filetype=png with rgbimage axes x2y2,\

# Run in terminal: latex gaussmap.tex && dvips -o gaussmap.eps gaussmap.dvi && open gaussmap.eps
