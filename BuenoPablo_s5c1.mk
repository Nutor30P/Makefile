all: resultados.pdf

resultados.pdf: ApellidoNombre_HPC_S4C1Casa.py err_derF.pdf err_derC.pdf err_der_h.pdf
    pdflatex resultados.tex

err_derF.pdf: err_derF.dat plot_err_derF.py
    python plot_err_derF.py

err_derC.pdf: err_derC.dat plot_err_derC.py
    python plot_err_derC.py

err_der_h.pdf: err_der_h.dat plot_err_der_h.py
    python plot_err_der_h.py




