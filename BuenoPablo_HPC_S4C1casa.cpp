#include <iostream>
#include <cmath>
#include <fstream>

double forward_difference(double x, double h)
{
    return (sin(x + h) - sin(x)) / h;
}

double central_difference(double x, double h)
{
    return (sin(x + h/2) - sin(x - h/2)) / h;
}

int main()
{
    double h = 0.01;
    double x, exact, fd, cd, fd_error, cd_error;

    // Abrir archivo para guardar los resultados de los errores
    std::ofstream fd_error_file("forward_difference_error.txt");
    std::ofstream cd_error_file("central_difference_error.txt");

    // Calcular la derivada y el error para cada punto
    for (x = -M_PI/2 + h; x < M_PI/2; x += h)
    {
        exact = cos(x);
        fd = forward_difference(x, h);
        cd = central_difference(x, h);

        fd_error = std::abs((fd - exact) / exact) * 100;
        cd_error = std::abs((cd - exact) / exact) * 100;

        fd_error_file << x << " " << fd_error << std::endl;
        cd_error_file << x << " " << cd_error << std::endl;
    }

    fd_error_file.close();
    cd_error_file.close();

    // Calcular la derivada de sin(x) en pi/3 para diferentes valores de h
    std::ofstream cd_error_h_file("central_difference_error_h.txt");
    double h_values[] = {0.1, 0.01, 0.001, 0.0001};

    for (int i = 0; i < sizeof(h_values)/sizeof(h_values[0]); i++)
    {
        h = h_values[i];
        cd = central_difference(M_PI/3, h);
        cd_error = std::abs((cd - 0.5) / 0.5) * 100;

        cd_error_h_file << h << " " << cd_error << std::endl;
    }

    cd_error_h_file.close();

    return 0;
}
